/*
 * Code generated for Simulink model VCU_CS75_12_16_Test.
 *
 * FILE    : lin.c
 *
 * VERSION : 1.2745
 *
 * DATE    : Fri Dec 25 15:08:48 2020
 *
 * Copyright 2011-2017 ECUCoder. All Rights Reserved.
 */

#include "lin.h"
#if 1

void ec_lin_delay(uint32 us)
{
  uint32 i,j;
  for (i=0; i<us; i++) {
    for (j=0; j<20; j++) {
      if (1 == LINFlexD_0.LINSR.B.DRF) {
        i = us+1;
        j = 21;
      }
    }
  }
}

void ec_lin_init(void)
{
  LINFlexD_0.LINCR1.R = 0x0081;        /* SLEEP=0, INIT=1 */
  while (0x1000 != (LINFlexD_0.LINSR.R & 0xF000)) {
  }

  LINFlexD_0.LINFBRR.R = 6;
  LINFlexD_0.LINIBRR.R = 260;
  LINFlexD_0.LINCR2.R = 0x40;          /* IOBE=1, Bit error resets LIN state machine */
  LINFlexD_0.LINTCSR.R = 0;            /* LIN timeout mode, no idle on timeout */
  LINFlexD_0.LINCR1.R = 0x0390;
}

void ec_lin_transmit(uint8 Tx_ID, uint8 Datalength, uint8 Tx_Data[], boolean
                     Checksum_Type)
{
  /* store the data in the message buffer BDR */
  switch (Datalength)
  {
   case 1:
    LINFlexD_0.BDRL.B.DATA0 = Tx_Data[0];
    break;

   case 2:
    LINFlexD_0.BDRL.B.DATA0 = Tx_Data[0];
    LINFlexD_0.BDRL.B.DATA1 = Tx_Data[1];
    break;

   case 3:
    LINFlexD_0.BDRL.B.DATA0 = Tx_Data[0];
    LINFlexD_0.BDRL.B.DATA1 = Tx_Data[1];
    LINFlexD_0.BDRL.B.DATA2 = Tx_Data[2];
    break;

   case 4:
    LINFlexD_0.BDRL.B.DATA0 = Tx_Data[0];
    LINFlexD_0.BDRL.B.DATA1 = Tx_Data[1];
    LINFlexD_0.BDRL.B.DATA2 = Tx_Data[2];
    LINFlexD_0.BDRL.B.DATA3 = Tx_Data[3];
    break;

   case 5:
    LINFlexD_0.BDRL.B.DATA0 = Tx_Data[0];
    LINFlexD_0.BDRL.B.DATA1 = Tx_Data[1];
    LINFlexD_0.BDRL.B.DATA2 = Tx_Data[2];
    LINFlexD_0.BDRL.B.DATA3 = Tx_Data[3];
    LINFlexD_0.BDRM.B.DATA4 = Tx_Data[4];
    break;

   case 6:
    LINFlexD_0.BDRL.B.DATA0 = Tx_Data[0];
    LINFlexD_0.BDRL.B.DATA1 = Tx_Data[1];
    LINFlexD_0.BDRL.B.DATA2 = Tx_Data[2];
    LINFlexD_0.BDRL.B.DATA3 = Tx_Data[3];
    LINFlexD_0.BDRM.B.DATA4 = Tx_Data[4];
    LINFlexD_0.BDRM.B.DATA5 = Tx_Data[5];
    break;

   case 7:
    LINFlexD_0.BDRL.B.DATA0 = Tx_Data[0];
    LINFlexD_0.BDRL.B.DATA1 = Tx_Data[1];
    LINFlexD_0.BDRL.B.DATA2 = Tx_Data[2];
    LINFlexD_0.BDRL.B.DATA3 = Tx_Data[3];
    LINFlexD_0.BDRM.B.DATA4 = Tx_Data[4];
    LINFlexD_0.BDRM.B.DATA5 = Tx_Data[5];
    LINFlexD_0.BDRM.B.DATA6 = Tx_Data[6];
    break;

   case 8:
    LINFlexD_0.BDRL.B.DATA0 = Tx_Data[0];
    LINFlexD_0.BDRL.B.DATA1 = Tx_Data[1];
    LINFlexD_0.BDRL.B.DATA2 = Tx_Data[2];
    LINFlexD_0.BDRL.B.DATA3 = Tx_Data[3];
    LINFlexD_0.BDRM.B.DATA4 = Tx_Data[4];
    LINFlexD_0.BDRM.B.DATA5 = Tx_Data[5];
    LINFlexD_0.BDRM.B.DATA6 = Tx_Data[6];
    LINFlexD_0.BDRM.B.DATA7 = Tx_Data[7];
    break;

   default :
    break;
  }

  LINFlexD_0.BIDR.B.DFL = Datalength - 1;/* DFL = Number of data bytes - 1 */
  LINFlexD_0.BIDR.B.DIR = 1;           /* LINFlexD transmits the data from the BDR registers */
  LINFlexD_0.BIDR.B.CCS = Checksum_Type;/* 0: Enhanced Checksum ; 1: Classic Checksum */
  LINFlexD_0.BIDR.B.ID = Tx_ID;        /* 0: Enhanced Checksum ; 1: Classic Checksum */
  LINFlexD_0.LINCR2.B.HTRQ = 1;        /* Trigger Frame transmission */

  /* wait until Master response to the LIN header has been sent successfully */
  while (0 == LINFlexD_0.LINSR.B.DTF) {
    /* track LIN Status for errors */
  }

  LINFlexD_0.LINSR.R = 0x0002;         /* clear the DTF bit */
}

void ec_lin_receive(uint8 Rx_ID, uint8 Datalength, uint8 Rx_Buffer[], boolean
                    Checksum_Type)
{
  LINFlexD_0.BIDR.B.DFL = Datalength - 1;/* DFL = Number of data bytes - 1 */
  LINFlexD_0.BIDR.B.DIR = 0;           /* LINFlexD receives the data and copy them in the BDR registers */
  LINFlexD_0.BIDR.B.CCS = Checksum_Type;/* 0: Enhanced Checksum ; 1: Classic Checksum */
  LINFlexD_0.BIDR.B.ID = Rx_ID;        /* 0: Enhanced Checksum ; 1: Classic Checksum */
  LINFlexD_0.LINCR2.B.HTRQ = 1;        /* Trigger Frame transmission */

  /* wait until Slave response to the LIN header has been receive successfully */
  ec_lin_delay(1000);

  /* read BDR registers */
  switch (Datalength)
  {
   case 1:
    Rx_Buffer[0] = LINFlexD_0.BDRL.B.DATA0;
    break;

   case 2:
    Rx_Buffer[0] = LINFlexD_0.BDRL.B.DATA0;
    Rx_Buffer[1] = LINFlexD_0.BDRL.B.DATA1;
    break;

   case 3:
    Rx_Buffer[0] = LINFlexD_0.BDRL.B.DATA0;
    Rx_Buffer[1] = LINFlexD_0.BDRL.B.DATA1;
    Rx_Buffer[2] = LINFlexD_0.BDRL.B.DATA2;
    break;

   case 4:
    Rx_Buffer[0] = LINFlexD_0.BDRL.B.DATA0;
    Rx_Buffer[1] = LINFlexD_0.BDRL.B.DATA1;
    Rx_Buffer[2] = LINFlexD_0.BDRL.B.DATA2;
    Rx_Buffer[3] = LINFlexD_0.BDRL.B.DATA3;
    break;

   case 5:
    Rx_Buffer[0] = LINFlexD_0.BDRL.B.DATA0;
    Rx_Buffer[1] = LINFlexD_0.BDRL.B.DATA1;
    Rx_Buffer[2] = LINFlexD_0.BDRL.B.DATA2;
    Rx_Buffer[3] = LINFlexD_0.BDRL.B.DATA3;
    Rx_Buffer[4] = LINFlexD_0.BDRM.B.DATA4;
    break;

   case 6:
    Rx_Buffer[0] = LINFlexD_0.BDRL.B.DATA0;
    Rx_Buffer[1] = LINFlexD_0.BDRL.B.DATA1;
    Rx_Buffer[2] = LINFlexD_0.BDRL.B.DATA2;
    Rx_Buffer[3] = LINFlexD_0.BDRL.B.DATA3;
    Rx_Buffer[4] = LINFlexD_0.BDRM.B.DATA4;
    Rx_Buffer[5] = LINFlexD_0.BDRM.B.DATA5;
    break;

   case 7:
    Rx_Buffer[0] = LINFlexD_0.BDRL.B.DATA0;
    Rx_Buffer[1] = LINFlexD_0.BDRL.B.DATA1;
    Rx_Buffer[2] = LINFlexD_0.BDRL.B.DATA2;
    Rx_Buffer[3] = LINFlexD_0.BDRL.B.DATA3;
    Rx_Buffer[4] = LINFlexD_0.BDRM.B.DATA4;
    Rx_Buffer[5] = LINFlexD_0.BDRM.B.DATA5;
    Rx_Buffer[6] = LINFlexD_0.BDRM.B.DATA6;
    break;

   case 8:
    Rx_Buffer[0] = LINFlexD_0.BDRL.B.DATA0;
    Rx_Buffer[1] = LINFlexD_0.BDRL.B.DATA1;
    Rx_Buffer[2] = LINFlexD_0.BDRL.B.DATA2;
    Rx_Buffer[3] = LINFlexD_0.BDRL.B.DATA3;
    Rx_Buffer[4] = LINFlexD_0.BDRM.B.DATA4;
    Rx_Buffer[5] = LINFlexD_0.BDRM.B.DATA5;
    Rx_Buffer[6] = LINFlexD_0.BDRM.B.DATA6;
    Rx_Buffer[7] = LINFlexD_0.BDRM.B.DATA7;
    break;

   default :
    break;
  }

  LINFlexD_0.LINSR.R = 0x0207;         /* clear RMB, HRF, DRF and DTF flags */
}

#endif

/* File trailer for ECUCoder generated file lin.c.
 *
 * [EOF]
 */
