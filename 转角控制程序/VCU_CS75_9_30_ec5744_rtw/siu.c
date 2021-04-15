/*
 * Code generated for Simulink model VCU_CS75_9_30.
 *
 * FILE    : siu.c
 *
 * VERSION : 1.2543
 *
 * DATE    : Wed Jan 06 13:56:02 2021
 *
 * Copyright 2011-2017 ECUCoder. All Rights Reserved.
 */

#include "siu.h"

/**************************************************************************
 * FUNCTION :    ec_siu_init                                               *
 *                                                                         *
 * DESCRIPTION : Initialize the SIU module                                 *
 *                                                                         *
 *                                                                         *
 * PARAMETERS :  None                   *
 *                                                                         *
 * RETURN :      None                                                      *
 ***************************************************************************/
void ec_siu_init(void)
{
  //CAN0管脚初始化
  SIUL2_MSCR16 = 0X32810001;           //CAN0,TX
  SIUL2_MSCR17 = 0X30080000;           //CAN0,RX
  SIUL2_IMCR32 = 0X00000002;           //CAN0,RX

  //CAN1管脚初始化
  SIUL2_MSCR14 = 0X32810001;           //CAN1,TX
  SIUL2_MSCR15 = 0X30080000;           //CAN1,RX
  SIUL2_IMCR33 = 0X00000001;           //CAN1,RX

  //CAN2管脚初始化
  SIUL2_MSCR94 = 0X32810002;           //CAN0,TX
  SIUL2_MSCR95 = 0X30080000;           //CAN0,RX
  SIUL2_IMCR34 = 0X00000001;           //CAN0,RX

  //LIN0管脚初始化
  SIUL2_MSCR18 = 0X32810001;           //LIN0,TX
  SIUL2_MSCR19 = 0X00080000;           //LIN0,RX
  SIUL2_IMCR165 = 0X00000001;          //LIN0,RX

  //SPI0管脚初始化
  SIUL2_MSCR37 = 0X33800001;           //SPI0,SCK0
  SIUL2_MSCR38 = 0X33800001;           //SPI0,SDO0
  SIUL2_MSCR39 = 0X30080000;           //SPI0,SDI0
  SIUL2_IMCR41 = 0X00000001;           //SPI0,SDI0
  SIUL2_MSCR36 = 0X33800001;           //SPI0,PCS00
  SIUL2_MSCR79 = 0X33800001;           //SPI0,PCS01
  SIUL2_MSCR54 = 0X33800001;           //SPI0,PCS02

  //SPI1管脚初始化
  SIUL2_MSCR6 = 0X32810001;            //SPI1,SCK1
  SIUL2_MSCR7 = 0X32810001;            //SPI1,SDO1
  SIUL2_MSCR8 = 0X30080000;            //SPI1,SDI1
  SIUL2_IMCR44 = 0X00000001;           //SPI1,SDI1
  SIUL2_MSCR5 = 0X32810001;            //SPI1,PCS10
  SIUL2_MSCR98 = 0X32810001;           //SPI1,PCS11
  SIUL2_MSCR56 = 0X32810001;           //SPI1,PCS12

  //PWM管脚初始化
  //SIUL2_MSCR11 = 0X02000002;  //PWM_A0
  //SIUL2_MSCR12 = 0X02000002;  //PWM_A2
  //SIUL2_MSCR42 = 0X02000003;  //PWM_A3
  //eTimer管脚初始化
  SIUL2_MSCR0 = 0X00080000;            //eTimer_Ch0
  SIUL2_IMCR59 = 0X00000002;           //eTimer_Ch0
  SIUL2_MSCR1 = 0X00080000;            //eTimer_Ch1
  SIUL2_IMCR60 = 0X00000002;           //eTimer_Ch1
  SIUL2_MSCR43 = 0X00080000;           //eTimer_Ch4
  SIUL2_IMCR63 = 0X00000004;           //eTimer_Ch4
  SIUL2_MSCR44 = 0X00080000;           //eTimer_Ch5
  SIUL2_IMCR64 = 0X00000003;           //eTimer_Ch5

  //GPI管脚初始化
  SIUL2_MSCR92 = 0X00080000;           //GPIO92      6:I_SW01_L
  SIUL2_MSCR99 = 0X00080000;           //GPIO99      7:I_SW02_L
  SIUL2_MSCR45 = 0X00080000;           //GPIO45      8:I_SW03_L
  SIUL2_MSCR60 = 0X00080000;           //GPIO60      9:I_SW04_L
  SIUL2_MSCR152 = 0X00080000;          //GPIO152 10:I_SW05_L
  SIUL2_MSCR62 = 0X00080000;           //GPIO62      26:I_SW07_L
  SIUL2_MSCR46 = 0X00080000;           //GPIO46      27:I_SW08_L
  SIUL2_MSCR100 = 0X00080000;          //GPIO100  28:I_SW09_L
  SIUL2_MSCR102 = 0X00080000;          //GPIO102  29:I_SW10_L
  SIUL2_MSCR93 = 0X00080000;           //GPIO93      44:I_SW11_H
  SIUL2_MSCR101 = 0X00080000;          //GPIO101  46:I_SW12_H
  SIUL2_MSCR103 = 0X00080000;          //GPIO103   65:I_SW13_H
  SIUL2_MSCR77 = 0X00080000;           //GPIO77       100:I_SW14_H
  SIUL2_MSCR78 = 0X00080000;           //GPIO78       102:I_SW15_H
  SIUL2_MSCR47 = 0X00080000;           //GPIO47       103:I_SW16_H
  SIUL2_MSCR48 = 0X00080000;           //GPIO48       104:I_SW17_H
  SIUL2_MSCR52 = 0X00080000;           //GPIO52       105:I_SW18_H
  SIUL2_MSCR51 = 0X00080000;           //GPIO51       112:I_SW19_H
  SIUL2_MSCR80 = 0X00080000;           //GPIO80       113:I_SW20_H
  SIUL2_MSCR107 = 0X00080000;          //GPIO107   KL15
  SIUL2_MSCR49 = 0X00080000;           //GPIO49       25:I_Bootkey

  //GPO管脚初始化
  SIUL2_MSCR11 = 0X03000000;           //GPIO11  60:O_PWM1_LS0A4  默认值为1
  SIUL2.GPDO[11].R = 1;
  SIUL2_MSCR12 = 0X03000000;           //GPIO12  90:O_PWM2_LS0A4   默认值为1
  SIUL2.GPDO[12].R = 1;
  SIUL2_MSCR22 = 0X02000000;           //GPIO22  看门狗使能   默认值为1
  SIUL2.GPDO[22].R = 1;
  SIUL2_MSCR13 = 0X02000000;           //GPIO12  看门狗喂狗   默认值为1
  SIUL2.GPDO[13].R = 1;
  SIUL2_MSCR58 = 0X02000000;           //GPIO12  AfterRun开关   默认值为0
  SIUL2.GPDO[58].R = 0;
  SIUL2_MSCR50 = 0X02000000;           //GPIO50  114:O_SW12_HS1A   默认值为0 保留对V1.2硬件的兼容性支持
  SIUL2.GPDO[50].R = 0;
  SIUL2_MSCR42 = 0X02000000;           //GPIO42  114:O_SW12_HS1A   默认值为0
  SIUL2.GPDO[42].R = 0;
  SIUL2_MSCR57 = 0X02000000;           //GPIO57  115:O_SW13_HS1A   默认值为0
  SIUL2.GPDO[57].R = 0;
  SIUL2_MSCR83 = 0X02000000;           //GPIO83  117:O_SW14_HS1A   默认值为0
  SIUL2.GPDO[83].R = 0;
  SIUL2_MSCR55 = 0X02000000;           //GPIO55  118:O_SW15_HS1A   默认值为0
  SIUL2.GPDO[55].R = 0;
}

/* File trailer for ECUCoder generated file siu.c.
 *
 * [EOF]
 */
