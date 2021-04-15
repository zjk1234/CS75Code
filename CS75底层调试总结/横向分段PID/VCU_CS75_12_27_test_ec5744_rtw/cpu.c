/*
 * Code generated for Simulink model VCU_CS75_12_27_test.
 *
 * FILE    : cpu.c
 *
 * VERSION : 1.2768
 *
 * DATE    : Wed Dec 30 13:20:36 2020
 *
 * Copyright 2011-2017 ECUCoder. All Rights Reserved.
 */

#include "cpu.h"

/**************************************************************************
 * FUNCTION :    ec_cpu_init                                               *
 *                                                                         *
 * DESCRIPTION : Initialize the CPU module                                 *
 *                                                                         *
 *                                                                         *
 * PARAMETERS :  None                   *
 *                                                                         *
 * RETURN :      None                                                      *
 ***************************************************************************/
void ec_cpu_init(void)
{
  //ʹ������ģʽ�������������裬ʹ��DRUNģʽ���ⲿʱ��
  MC_ME.ME.R = 0x000005FF;
  MC_ME.RUN_PC[0].R = 0x000000FE;
  XOSC.CTL.B.OSCM = 1;
  XOSC.CTL.B.EOCV = 0x80;
  MC_ME.DRUN_MC.B.XOSCON = 1;
  PMC.PMCCR.B.PMCCR_EN = 1;
  PMC.PMCCR.B.INT_AUX_REG_BYPASS = 0;
  PMC.PMCCR.B.PMCCR_EN = 0;

  //����AC0������ADC��SGEN��MOTC��ʱ��Դѡ��PLL0��160MHz��
  //����ADCʱ��10MHz������SGENʱ��20MHz������MOTCʱ��20MHz
  MC_CGM_AC0_SC = 0X02000000;
  MC_CGM.AC0_DC2.R = 0x800F0000;
  MC_CGM.AC0_DC1.R = 0x80070000;
  MC_CGM.AC0_DC0.R = 0x80050000;

  //����SC������ϵͳʱ�ӣ�������ʱ��
  //MC_CGM.SC_DC0.R = 0x00010000;

  //����PLL0�����ģ�飬XOSC�������룬160MHz
  MC_CGM_AC3_SC = 0X01000000;
  PLLDIG.PLL0DV.B.PREDIV = 4;
  PLLDIG.PLL0DV.B.RFDPHI1 = 1;
  PLLDIG.PLL0DV.B.MFD = 12;
  PLLDIG.PLL0DV.B.RFDPHI = 1;

  //����PLL1�����ģ�飬XOSC�������룬160MHz
  MC_CGM_AC4_SC = 0X01000000;
  PLLDIG.PLL1DV.B.RFDPHI = 2;
  PLLDIG.PLL1DV.B.MFD = 12;

  //��XOSC,PLL0��PLL1
  MC_ME.DRUN_MC.B.XOSCON = 1;
  MC_ME.DRUN_MC.B.PLL0ON = 1;
  MC_ME.DRUN_MC.B.PLL1ON = 1;
  MC_ME.DRUN_MC.B.SYSCLK = 4;
  MC_ME.MCTL.R = 0x30005AF0;
  MC_ME.MCTL.R = 0x3000A50F;

  //�ȴ�ģʽת�����
  while (MC_ME.GS.B.S_MTRANS == 1 ) ;
  while (MC_ME.GS.B.S_CURRENT_MODE != 0x3 ) ;
  while (MC_ME.GS.B.S_SYSCLK != 4 ) ;
}

void ec_cpu_lpme(void)
{
  //��XOSC,PLL0��PLL1
  MC_ME.DRUN_MC.B.XOSCON = 1;
  MC_ME.DRUN_MC.B.PLL0ON = 1;
  MC_ME.DRUN_MC.B.PLL1ON = 1;
  MC_ME.DRUN_MC.B.SYSCLK = 0;
  MC_ME.MCTL.R = 0x30005AF0;
  MC_ME.MCTL.R = 0x3000A50F;

  //�ȴ�ģʽת�����
  while (MC_ME.GS.B.S_MTRANS == 1 ) ;
  while (MC_ME.GS.B.S_CURRENT_MODE != 0x3 ) ;
  while (MC_ME.GS.B.S_SYSCLK != 0 ) ;
}

/* File trailer for ECUCoder generated file cpu.c.
 *
 * [EOF]
 */
