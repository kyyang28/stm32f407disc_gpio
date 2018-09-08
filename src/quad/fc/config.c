
#include "configMaster.h"
#include "led.h"
#include "target.h"

/* master config structure with data independent from profiles */
master_t masterConfig;

void ResetLedStatusConfig(LedStatusConfig_t *ledStatusConfig)
{
	for (int i = 0; i < LED_NUMBER; i++) {
		ledStatusConfig->ledTags[i] = IO_TAG_NONE;
	}
	
#ifdef LED3
	ledStatusConfig->ledTags[0] = IO_TAG(LED3);	// LED3 = PD13 ==> DEFIO_TAG__PD13 ==> 4D
#endif

#ifdef LED4
	ledStatusConfig->ledTags[1] = IO_TAG(LED4);	// LED4 = PD12 ==> DEFIO_TAG__PD12 ==> 4C
#endif

#ifdef LED5
	ledStatusConfig->ledTags[2] = IO_TAG(LED5);	// LED5 = PD14 ==> DEFIO_TAG__PD14 ==> 4E
#endif

#ifdef LED6
	ledStatusConfig->ledTags[3] = IO_TAG(LED6);	// LED6 = PD15 ==> DEFIO_TAG__PD15 ==> 4F
#endif
	
	ledStatusConfig->polarity = 0;
}

void CreateDefaultConfig(master_t *config)
{
	ResetLedStatusConfig(&config->ledStatusConfig);
}

static void ResetConfig(void)
{
	CreateDefaultConfig(&masterConfig);
}

void ResetEEPROM(void)
{
	ResetConfig();
}

void CheckEEPROMContainsValidData(void)
{
#if 0
	if (isEEPROMContentValid()) {
		return;
	}
#endif
	
	ResetEEPROM();
}
