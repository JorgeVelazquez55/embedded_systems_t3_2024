/**
\file       i2c.c
\brief      MCAL abstraction level - dma configuration
\author     Jorge V, Gustavo S, Roberto V
\version    1.0
\project    
\date       01/12/2024
*/
/****************************************************************************************************/

#include "dma.h"

static sXdmad dmad;
static sXdmadCfg xdmadCfg;

static uint32_t i2sDmaTxChannel;

extern uint16_t codecOutputData[SAMPLES];


static uint32_t nextData[BUFFERS] = { 0 };
static uint8_t flag = 1;
static bool cpuBusy = false;

COMPILER_ALIGNED(32) static LinkedListDescriporView1 dmaWriteLinkList[BUFFERS];

/*----------------------------------------------------------------------------
 *        Local functions
 *----------------------------------------------------------------------------*/
void XDMAC_Handler(void)
{
	XDMAD_Handler(&dmad);
}

static void callBack(uint32_t Channel, void* pArg)
{
	Channel = Channel;
	pArg = pArg;

	if (cpuBusy) {
		if (nextData[flag] == 0)
			nextData[flag] = (dmad.pXdmacs->XDMAC_CHID[i2sDmaTxChannel].XDMAC_CNDA);
		else {
			TRACE_WARNING("DMA is faster than CPU-%d\n\r",flag);
			nextData[flag] = (dmad.pXdmacs->XDMAC_CHID[i2sDmaTxChannel].XDMAC_CNDA);
		}
	}
	flag++;
	if (flag == BUFFERS) {
		flag = 0;
		/*CPU starts to handle nextData, the first data are abandoned*/
		cpuBusy = true;
	}
}
/**
 * \brief Configure the DMA Channels: 0 RX.
 * Channels are disabled after configure.
 * \returns 0 if the dma channel configuration successfully; otherwise returns
 * DAC_ERROR_XXX.
 */
void i2sConfigureDma(void)
{
    sXdmad* pi2sd = &dmad;
	/* Driver initialize */
	XDMAD_Initialize( pi2sd, 0 );

	//XDMAD_FreeChannel( pi2sd, i2sDmaTxChannel);
    	/* Configure TWI interrupts */
	NVIC_ClearPendingIRQ(XDMAC_IRQn);
	NVIC_EnableIRQ(XDMAC_IRQn);

	/* Allocate a DMA channel for DAC0/1 TX. */
	i2sDmaTxChannel = XDMAD_AllocateChannel( pi2sd, ID_SSC, XDMAD_TRANSFER_MEMORY);
	if ( i2sDmaTxChannel == XDMAD_ALLOC_FAILED ) {
		printf("xDMA channel allocation error\n\r");
       // return DAC_ERROR;
	}
    XDMAD_SetCallback(pi2sd, i2sDmaTxChannel, callBack, 0);
    XDMAD_PrepareChannel( pi2sd, i2sDmaTxChannel );

	//return DAC_OK;
}

/**
 * \brief Configure the DMA source and destination with Linker List mode.
 *
 * \param pBuffer Pointer to dac buffer
 * \param size length of buffer
 */

void i2sconfigureLinkList(void)
{
	uint32_t xdmaCndc;
	uint32_t i;		
  uint16_t* src = &codecOutputData[0];
	for(i = 0; i < BUFFERS; i++){
		dmaWriteLinkList[i].mbr_ubc = XDMA_UBC_NVIEW_NDV1 
									| XDMA_UBC_NDE_FETCH_EN
									| XDMA_UBC_NSEN_UPDATED
									| XDMAC_CUBC_UBLEN(UBLEN_SIZE);
		dmaWriteLinkList[i].mbr_sa = (uint32_t) & (SSC->SSC_RHR);
		dmaWriteLinkList[i].mbr_da = (uint32_t)(src);
		if ( i == (BUFFERS - 1 )) 
        {
            dmaWriteLinkList[i].mbr_nda = (uint32_t)&dmaWriteLinkList[0];
		} 
        else 
        {
			dmaWriteLinkList[i].mbr_nda = (uint32_t)&dmaWriteLinkList[i+1];
		}
		src += UBLEN_SIZE;
	}
  
	xdmadCfg.mbr_cfg = XDMAC_CC_TYPE_PER_TRAN
		| XDMAC_CC_MBSIZE_SINGLE
		| XDMAC_CC_DSYNC_PER2MEM
		| XDMAC_CC_CSIZE_CHK_1
		| XDMAC_CC_DWIDTH_HALFWORD
		| XDMAC_CC_SIF_AHB_IF1
		| XDMAC_CC_DIF_AHB_IF1
		| XDMAC_CC_SAM_FIXED_AM
		| XDMAC_CC_DAM_INCREMENTED_AM
		| XDMAC_CC_PERID(XDMAIF_Get_ChannelNumber(ID_SSC, XDMAD_TRANSFER_RX));
	xdmaCndc = XDMAC_CNDC_NDVIEW_NDV1
		| XDMAC_CNDC_NDE_DSCR_FETCH_EN
		| XDMAC_CNDC_NDSUP_SRC_PARAMS_UPDATED
		| XDMAC_CNDC_NDDUP_DST_PARAMS_UPDATED;

    SCB_CleanInvalidateDCache();

	XDMAD_ConfigureTransfer(&dmad, i2sDmaTxChannel, &xdmadCfg, xdmaCndc,
		(uint32_t)&dmaWriteLinkList[0], XDMAC_CIE_BIE);

	SSC_EnableReceiver(SSC);
	XDMAD_StartTransfer(&dmad, i2sDmaTxChannel);

	Wait(1000);

	XDMAD_StopTransfer(&dmad, i2sDmaTxChannel);
  	SCB_CleanInvalidateDCache();
	//return DAC_OK;
}