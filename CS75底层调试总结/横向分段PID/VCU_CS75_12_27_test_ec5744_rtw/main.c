/*
 * Code generated for Simulink model VCU_CS75_12_27_test.
 *
 * FILE    : main.c
 *
 * VERSION : 1.2768
 *
 * DATE    : Wed Dec 30 13:20:36 2020
 *
 * Copyright 2011-2017 ECUCoder. All Rights Reserved.
 */

#include "VCU_CS75_12_27_test.h"

uint8_T ECUCoderModelBaseCounter = 0;
uint8_T AfterRunFlags[2] = { 0, 0 };

static boolean_T ECUCoderOverrunFlags[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

void rt_OneStep(void)
{
  boolean_T ECUCodereventFlags[8];     /* Model has 8 rates */
  int_T i;

  /* Check base rate for overrun */
  if (ECUCoderOverrunFlags[0]++) {
    ((void) 0);
    return;
  }

  VCU_CS75_12_27_test_SetEventsForThisBaseStep(ECUCodereventFlags);

  /* Set model inputs associated with base rate here */
  ECUCoderOverrunFlags[0]--;

  /* Check subrates for overrun */
  for (i = 1; i < 8; i++) {
    if (ECUCodereventFlags[i]) {
      if (ECUCoderOverrunFlags[i]++) {
        ((void) 0);
        return;
      }

      VCU_CS75_12_27_test_step(i);

      /* Get model outputs here */
      ECUCoderOverrunFlags[i]--;
    }
  }
}

main()
{
  /* Interrupt management */
  xcptn_xmpl();
  __asm__(" wrteei 0");

  /* Initialize CPU */
  ec_cpu_init();

  /* Initialize SIU */
  ec_siu_init();

  /* Initialize ADC */
  ec_adc_init();

  /* Initialize CAN */
  ec_can0_init(&(CANINIT[0]));
  ec_can1_init(&(CANINIT[1]));
  ec_can2_init(&(CANINIT[2]));

  /* Initialize SPI */
  ec_spi0_init();
  ec_spi1_init();

  /* Initialize LIN */
  ec_lin_init();

  /* Initialize PWM */
  ec_pwm_init();

  /* Initialize eTimer */
  //ec_etimer_init();

  /* Initialize model */
  VCU_CS75_12_27_test_initialize();

  /* Initialize Flash */
  ec_flash_init();

  /* Initialize FCCU */
  ec_fccu_init();

  /* Enable all timebases */
  ec_pit_init(3, 30000);
  IntcIsrVectorTable[229] = (uint32_t)&ISR_PIT_CH3;
  __asm__(" wrteei 1");
  while (((void*) 0) == 0) {
    if (ECUCoderModelBaseCounter >0 ) {
      ECUCoderModelBaseCounter = 0;
      rt_OneStep();
    }
  }

  return 0;
}

/* File trailer for ECUCoder generated file main.c.
 *
 * [EOF]
 */
