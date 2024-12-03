#ifndef CODEC_DMA_H_
#define CODEC_DMA_H_

#include "Std_Types.h"
#include "xdmad.h"

/*------------------------------------------------------------------------------
 *         Definitions
 *------------------------------------------------------------------------------*/
#define DAC_OK          0
#define DAC_ERROR       1
#define DAC_ERROR_LOCK  2

#define DACC_CHANNEL_0 0
#define DACC_CHANNEL_1 1
#define BUFFERS 	2
#define UBLEN_SIZE	0x1000

void XDMAC_Handler(void);
uint8_t i2sConfigureDma();
uint8_t i2sconfigureLinkList();

#endif