/****************************************************************************************************/
/**
  \mainpage
  \n 
  \brief        Main application (main module)
  \author       Abraham Tezmol Otero, M.S.E.E
  \project      Tau 
  \version      1.0
  \date         12/Jun/2016
   

/*~~~~~~  Headers ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** Main group of includes for board definitions, chip definitions and type definitions */
#include    "Std_types.h"
/** Task scheduler definitions */
#include    "SchM.h"
/** LED control definitions */ 
#include    "Led_Ctrl.h"
/** Watchdog control function prototypes definitions */
#include    "Wdg.h"
/** Button control operations */
#include    "Button_Ctrl.h"
/** Floating Point Unit */
#include    "Fpu.h"
#include    "i2c.h"
#include    "i2sc.h"
#include    "dma.h"


/*~~~~~~  Local definitions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

  #define SAMP_PER  (50)
  #define BUFF_SIZE (2048)


/** I2C SDA y SCL Pin Definitions */
const Pin pPins[] = { PIN_TWI_TWD0, PIN_TWI_TWCK0, PIN_PCK2 , PIN_SSC_TD, PIN_SSC_TK, PIN_SSC_TF, PIN_SSC_RD, PIN_SSC_RK, PIN_SSC_RF};

static Twid twid;

/*~~~~~~  Global variables ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** Auxiliary input buffer to accomodate data as FFT function expects it */
float       fft_inputData[BUFF_SIZE];
/** Output magnitude data */
float       fft_signalPower[BUFF_SIZE/2];
/** Auxiliary output variable that holds the frequency bin with the highest level of signal power */
uint32_t    u32fft_maxPowerIndex;
/** Auxiliary output variable that holds the maximum level of signal power */
float       fft_maxPower;
/** Output data from codec, input to the FFT **/
uint16_t codecOutputData[SAMPLES];

/*~~~~~~  Local functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void fft_process(void);

pfun pFFT = &fft_process;

/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/
/**
 *  \brief getting-started Application entry point.
 *
 *  \return Unused (ANSI-C compatibility).
 */
extern int main( void )
{
  uint32_t i;
	/* Disable watchdog */
	Wdg_Disable();
	/* Configure LEDs */
	LedCtrl_Configure();
  /* Configure Button */  
  ButtonCtrl_ConfigureSW0Button();
  /* Enable I and D cache */
	SCB_EnableICache();
	SCB_EnableDCache(); 
  /* Enable Floating Point Unit */
  Fpu_Enable();
  /* Congiguracion de pines */
  PIO_Configure(pPins, PIO_LISTSIZE(pPins));
    
  /* Configuracion y habilitacion del SSC */
  SSC_Init_Configuration();
	
  printf( "\n\r-- Scheduler Project %s --\n\r", SOFTPACK_VERSION ) ;
	printf( "-- %s\n\r", BOARD_NAME ) ;
	printf( "-- Compiled: %s %s With %s --\n\r", __DATE__, __TIME__ , COMPILER_NAME);

  /* Scheduler Inititalization */
  printf( "-- Scheduler Initialization --\n\r" ) ;
	SchM_Init(ScheduleConfig);

  /* DMA */
  i2sConfigureDma();

  /*Codec config*/

  /* Scheduler Inititalization */
  printf( "-- I2C configuration --\n\r" ) ;
  /* I2c configuration function */  
  i2c_configure();

	/* Configuración del WM8904, sin inversor de reloj */
  
  WM8904_Write(&twid, WM8904_SLAVE_ADDRESS, 22, 0);
  
  if(WM8904_Read(&twid, WM8904_SLAVE_ADDRESS, 0) != 0x8904){
    
    printf("Communication with WM8904 failed\n");
    
    while(1);
 
  }
  
  WM8904_Init(&twid, WM8904_SLAVE_ADDRESS, PMC_MCKR_CSS_SLOW_CLK);
  
                                                                                                                                                                                                                                               PMC_ConfigurePCK2(PMC_MCKR_CSS_SLOW_CLK, PMC_MCKR_PRES_CLK_1);
  
  /* Start of moving data*/
  i2sconfigureLinkList();

 for(i=0;i<SAMPLES;i++){
  	fft_inputData[i] = (float)codecOutputData[i];
  }
	/* Should never reach this code */
	while(1);
}

void fft_process(void)
{
  /** Perform FFT on the input signal */
  fft(fft_inputData, fft_signalPower, SAMPLES/2, &u32fft_maxPowerIndex, &fft_maxPower);
        
  /* Publish through emulated Serial */
  printf("%5d  %5.4f \r\n", u32fft_maxPowerIndex, fft_maxPower);
}