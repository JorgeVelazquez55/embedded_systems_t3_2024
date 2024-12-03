#include "dma.h"

static sXdmad dmad;
static sXdmadCfg xdmadCfg;

static uint32_t i2sDmaTxChannel;

/*----------------------------------------------------------------------------
 *        Local functions
 *----------------------------------------------------------------------------*/

static void callBack(uint32_t Channel)
{
}
/**
 * \brief Configure the DMA Channels: 0 RX.
 * Channels are disabled after configure.
 * \returns 0 if the dma channel configuration successfully; otherwise returns
 * DAC_ERROR_XXX.
 */
static uint8_t _DacConfigureDmaChannels( sXdmad* pi2sd )
{

	/* Driver initialize */
	XDMAD_Initialize( pi2sd->pXdmad, 0 );

	XDMAD_FreeChannel( pi2sd->pXdmad, i2sDmaTxChannel);
    	/* Configure TWI interrupts */
	NVIC_ClearPendingIRQ(XDMAC_IRQn);
	NVIC_EnableIRQ(XDMAC_IRQn);

	/* Allocate a DMA channel for DAC0/1 TX. */
	i2sDmaTxChannel = XDMAD_AllocateChannel( pi2sd->pXdmad, ID_SSC, XDMAD_TRANSFER_MEMORY);
	if ( i2sDmaTxChannel == XDMAD_ALLOC_FAILED ) {
		printf("xDMA channel allocation error\n\r");
        return DAC_ERROR;
	}
    i2sDmaTxChannel = XDMAD_PrepareChannel( pi2sd->pXdmad, i2sDmaTxChannel );
	if ( i2sDmaTxChannel == (XDMAD_DONE ||  XDMAD_BUSY || XDMAD_ERROR || XDMAD_CANCELED ))
    {
        printf("xDMA prepare channel error\n\r");
		return DAC_ERROR;
    } 
    i2sDmaTxChannel == XDMAD_SetCallback(pi2sd->pXdmad, i2sDmaTxChannel, callBack, 0);

    if ( i2sDmaTxChannel == (XDMAD_DONE ||  XDMAD_BUSY || XDMAD_ERROR || XDMAD_CANCELED ))
    {
        printf("xDMA callback error\n\r");
        return DAC_ERROR;
        while(1);
    }
	return DAC_OK;
}