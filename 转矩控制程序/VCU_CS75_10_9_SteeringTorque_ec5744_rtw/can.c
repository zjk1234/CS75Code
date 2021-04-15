/*
 * Code generated for Simulink model VCU_CS75_10_9_SteeringTorque.
 *
 * FILE    : can.c
 *
 * VERSION : 1.2647
 *
 * DATE    : Mon Nov 02 10:46:06 2020
 *
 * Copyright 2011-2017 ECUCoder. All Rights Reserved.
 */

#include "can.h"
#if 1

/**************************************************************************
 * FUNCTION :    ec_can0_init                                              *
 *                                                                         *
 * DESCRIPTION : Initialize FlexCAN0 module                                *
 *                                                                         *
 * PARAMETERS :  -*caninit: pointer to configuration set                   *
 *                                                                         *
 * RETURN:       None                                                      *
 ***************************************************************************/
void ec_can0_init(CAN_Initialization* caninit)
{
  uint8 i,j;
  CAN_0.MCR.R = 0x5000003F;            /* 64 message buffers in use */
  while (!CAN_0.MCR.B.FRZACK) ;
  FLEXCAN(0).CTRL1.B.PRESDIV = 4;      /* Prescaler division factor */
  FLEXCAN(0).CTRL1.B.RJW = 1;          /* Synchronization jump width */
  FLEXCAN(0).CTRL1.B.PSEG1 = 3;        /* Phase segment 1 */
  FLEXCAN(0).CTRL1.B.PSEG2 = 3;        /* Phase segment 2 */
  FLEXCAN(0).CTRL1.B.BOFFMSK = 0;      /* 1: Bus off interrupt enabled; 0: Bus off interrupt disabled */
  FLEXCAN(0).CTRL1.B.ERRMSK = 0;       /* 1: Error interrupt enabled; 0: Error interrupt disabled */
  FLEXCAN(0).CTRL1.B.CLKSRC = 0;       /* CAN engine clock source. 0: oscillator clock; 1: system clock */
  FLEXCAN(0).CTRL1.B.LPB = 0;          /* Loop back disabled */
  FLEXCAN(0).CTRL1.B.SMP = 0;          /* Number of samples */
  FLEXCAN(0).CTRL1.B.BOFFREC = 0;      /* 0: Automatic recovering from bus off state enabled;1: disable */
  FLEXCAN(0).CTRL1.B.TSYN = 0;         /* 0: Timer sync feature disabled;1: enable */
  FLEXCAN(0).CTRL1.B.LBUF = 0;         /* 0: Buffer with lowest ID is transmitted first
                                          1: Lowest number buffer is transmitted first */
  FLEXCAN(0).CTRL1.B.LOM = 0;          /* Listen-only mode disable */
  FLEXCAN(0).CTRL1.B.PROPSEG = 6;      /* Defines the length of the propagation segment in the bit time */
  for (i=0; i<NumCanMaxMB; i++)        /* Initialize message buffer for receive or transmit */
  {
    FLEXCAN(0).MB[i].CS.R = caninit->MBCS[i];
    for (j=0; j<8; j++) {
      FLEXCAN(0).MB[i].DATA.B[j] = 0;
    }
  }

  FLEXCAN(0).MB[14].ID.R = 0;
  FLEXCAN(0).RXMGMASK.R = 0xFFFFFFFF;
  FLEXCAN(0).RX14MASK.R = 0xFFFFFFFF;
  FLEXCAN(0).RX15MASK.R = 0xFFFFFFFF;
  FLEXCAN(0).RXFGMASK.R = 0xFFFFFFFF;
  FLEXCAN(0).ECR.R = 0;
  FLEXCAN(0).IMASK2.R = 0;
  FLEXCAN(0).IFLAG2.R = 0xFFFFFFFF;    /* Clear interruput flag */
  FLEXCAN(0).IFLAG1.R = 0xFFFFFFFF;    /* Clear interruput flag */
  FLEXCAN(0).ESR1.R = CAN_ERRINT|CAN_BOFFINT;/* Error interrupt flag & Bus off interrupt flag */
  FLEXCAN(0).MCR.R = CAN_NORMAL_MODE|NUM_OF_ENABLED_MB;/* Normal mode */
  FLEXCAN(0).MCR.B.HALT = 0;           /* FlexCAN0 attempts to synchronize with the CAN bus */
}

#endif

#if 1

/**************************************************************************
 * FUNCTION :    ec_can1_init                                              *
 *                                                                         *
 * DESCRIPTION : Initialize FlexCAN1 module                                *
 *                                                                         *
 * PARAMETERS :  -*caninit: pointer to configuration set                   *
 *                                                                         *
 * RETURN:       None                                                      *
 ***************************************************************************/
void ec_can1_init(CAN_Initialization* caninit)
{
  uint8 i,j;
  CAN_1.MCR.R = 0x5000003F;            /* 64 message buffers in use */
  while (!CAN_1.MCR.B.FRZACK) ;
  FLEXCAN(1).CTRL1.B.PRESDIV = 4;      /* Prescaler division factor */
  FLEXCAN(1).CTRL1.B.RJW = 1;          /* Synchronization jump width */
  FLEXCAN(1).CTRL1.B.PSEG1 = 3;        /* Phase segment 1 */
  FLEXCAN(1).CTRL1.B.PSEG2 = 3;        /* Phase segment 2 */
  FLEXCAN(1).CTRL1.B.BOFFMSK = 0;      /* 1: Bus off interrupt enabled; 0: Bus off interrupt disabled */
  FLEXCAN(1).CTRL1.B.ERRMSK = 0;       /* 1: Error interrupt enabled; 0: Error interrupt disabled */
  FLEXCAN(1).CTRL1.B.CLKSRC = 0;       /* CAN engine clock source. 0: oscillator clock; 1: system clock */
  FLEXCAN(1).CTRL1.B.LPB = 0;          /* 0: Loop back disabled */
  FLEXCAN(1).CTRL1.B.SMP = 0;          /* Number of samples */
  FLEXCAN(1).CTRL1.B.BOFFREC = 0;      /* 0: Automatic recovering from bus off state enabled; 1: disable */
  FLEXCAN(1).CTRL1.B.TSYN = 0;         /* 0: Timer sync feature disabled; 1: enable */
  FLEXCAN(1).CTRL1.B.LBUF = 0;         /* 0: Buffer with lowest ID is transmitted first
                                          1: Lowest number buffer is transmitted first */
  FLEXCAN(1).CTRL1.B.LOM = 0;          /* Listen-only mode disable */
  FLEXCAN(1).CTRL1.B.PROPSEG = 6;      /* Defines the length of the propagation segment in the bit time */
  for (i=0; i<NumCanMaxMB; i++)        /* Initialize message buffer for receive or transmit  */
  {
    FLEXCAN(1).MB[i].CS.R = caninit->MBCS[i];
    for (j=0; j<8; j++) {
      FLEXCAN(1).MB[i].DATA.B[j] = 0;
    }
  }

  FLEXCAN(1).MB[14].ID.R = 0;
  FLEXCAN(1).RXMGMASK.R = 0xFFFFFFFF;
  FLEXCAN(1).RX14MASK.R = 0xFFFFFFFF;
  FLEXCAN(1).RX15MASK.R = 0xFFFFFFFF;
  FLEXCAN(1).RXFGMASK.R = 0xFFFFFFFF;
  FLEXCAN(1).ECR.R = 0;
  FLEXCAN(1).IMASK2.R = 0;
  FLEXCAN(1).IFLAG2.R = 0xFFFFFFFF;    /* Clear interruput flag */
  FLEXCAN(1).IFLAG1.R = 0xFFFFFFFF;    /* Clear interruput flag */
  FLEXCAN(1).ESR1.R = CAN_ERRINT|CAN_BOFFINT;/* Error interrupt flag & Bus off interrupt flag */
  FLEXCAN(1).MCR.R = CAN_NORMAL_MODE|NUM_OF_ENABLED_MB;/* Normal mode */
  FLEXCAN(1).MCR.B.HALT = 0;           /* FlexCAN1 attempts to synchronize with the CAN bus */
}

#endif

#if 1

/**************************************************************************
 * FUNCTION :    ec_can2_init                                              *
 *                                                                         *
 * DESCRIPTION : Initialize FlexCAN2 module                                *
 *                                                                         *
 * PARAMETERS :  -*caninit: pointer to configuration set                   *
 *                                                                         *
 * RETURN :      None                                                      *
 ***************************************************************************/
void ec_can2_init(CAN_Initialization* caninit)
{
  uint8 i,j;
  CAN_2.MCR.R = 0x5000003F;            /* 64 message buffers in use */
  while (!CAN_2.MCR.B.FRZACK) ;
  FLEXCAN(2).CTRL1.B.PRESDIV = 4;      /* Prescaler division factor */
  FLEXCAN(2).CTRL1.B.RJW = 1;          /* Synchronization jump width */
  FLEXCAN(2).CTRL1.B.PSEG1 = 3;        /* Phase segment 1 */
  FLEXCAN(2).CTRL1.B.PSEG2 = 3;        /* Phase segment 2 */
  FLEXCAN(2).CTRL1.B.BOFFMSK = 0;      /* 1: Bus off interrupt enabled; 0: Bus off interrupt disabled */
  FLEXCAN(2).CTRL1.B.ERRMSK = 0;       /* 1: Error interrupt enabled; 0: Error interrupt disabled */
  FLEXCAN(2).CTRL1.B.CLKSRC = 0;       /* CAN engine clock source. 0: oscillator clock; 1: system clock */
  FLEXCAN(2).CTRL1.B.LPB = 0;          /* 0: Loop back disabled */
  FLEXCAN(2).CTRL1.B.SMP = 0;          /* Number of samples */
  FLEXCAN(2).CTRL1.B.BOFFREC = 0;      /* 0: Automatic recovering from bus off state enabled; 1: disable */
  FLEXCAN(2).CTRL1.B.TSYN = 0;         /* 0: Timer sync feature disabled; 1: enable */
  FLEXCAN(2).CTRL1.B.LBUF = 0;         /* 0: Buffer with lowest ID is transmitted first
                                          1: Lowest number buffer is transmitted first */
  FLEXCAN(2).CTRL1.B.LOM = 0;          /* Listen-only mode disable */
  FLEXCAN(2).CTRL1.B.PROPSEG = 6;      /* Defines the length of the propagation segment in the bit time */
  for (i=0; i<NumCanMaxMB; i++)        /* Initialize message buffer for receive or transmit */
  {
    FLEXCAN(2).MB[i].CS.R = caninit->MBCS[i];
    for (j=0; j<8; j++) {
      FLEXCAN(2).MB[i].DATA.B[j] = 0;
    }
  }

  FLEXCAN(2).MB[14].ID.R = 0;
  FLEXCAN(2).RXMGMASK.R = 0xFFFFFFFF;
  FLEXCAN(2).RX14MASK.R = 0xFFFFFFFF;
  FLEXCAN(2).RX15MASK.R = 0xFFFFFFFF;
  FLEXCAN(2).RXFGMASK.R = 0xFFFFFFFF;
  FLEXCAN(2).ECR.R = 0;
  FLEXCAN(2).IMASK2.R = 0;
  FLEXCAN(2).IFLAG2.R = 0xFFFFFFFF;    /* Clear interruput flag */
  FLEXCAN(2).IFLAG1.R = 0xFFFFFFFF;    /* Clear interruput flag */
  FLEXCAN(2).ESR1.R = CAN_ERRINT|CAN_BOFFINT;/* Error interrupt flag & Bus off interrupt flag */
  FLEXCAN(2).MCR.R = CAN_NORMAL_MODE|NUM_OF_ENABLED_MB;/* Normal mode */
  FLEXCAN(2).MCR.B.HALT = 0;           /* FlexCAN2 attempts to synchronize with the CAN bus */
}

#endif

#if CANAENABLE||CANBENABLE||CANCENABLE

/**************************************************************************
 * FUNCTION :    ec_buffer_init                                            *
 *                                                                         *
 * DESCRIPTION : Initializes CAN buffer for CAN Controller                 *
 *                                                                         *
 * PARAMETERS :  -Module: FLEXCAN_A, FLEXCAN_B or FLEXCAN_C                *
 *               -BufNum: buffer number                                    *
 *               -IdType: standard or extended ID type                     *
 *               -Id: CAN message ID                                       *
 *                                                                         *
 * RETURN :      None                                                      *
 ***************************************************************************/
void ec_buffer_init(uint8 Module,uint8 BufNum,uint8 IdType,uint32 Id)
{
  FLEXCAN(Module).MCR.R = 0x5000003F;  /* 64 message buffers in use */
  if ((BufNum < 8)||(BufNum > 15)) {
    if (IdType == 0) {
      FLEXCAN(Module).MB[BufNum].ID.B.ID_STD = Id;
      FLEXCAN(Module).MB[BufNum].CS.B.IDE = MB_IDType_ST;
    } else {
      FLEXCAN(Module).MB[BufNum].ID.R = Id;
      FLEXCAN(Module).MB[BufNum].CS.B.IDE = MB_IDType_EX;
    }
  } else {
  }

  if (BufNum == 14) {
    FLEXCAN(Module).RX14MASK.R = 0x10000000;
  } else {
  }

  FLEXCAN(Module).MCR.R = CAN_NORMAL_MODE|NUM_OF_ENABLED_MB;/* Normal mode */
  FLEXCAN(Module).MCR.B.HALT= 0;       /* FlexCAN attempts to synchronize with the CAN bus */
}

/**************************************************************************
 * FUNCTION :    ec_bufint_init                                            *
 *                                                                         *
 * DESCRIPTION : Initializes CAN buffer interrupts for CAN Controller      *
 *                                                                         *
 * PARAMETERS :  -Module: FLEXCAN_A, FLEXCAN_B or FLEXCAN_C                *
 *               -BufNum: buffer number                                    *
 *                                                                         *
 * RETURN :      None                                                      *
 ***************************************************************************/
void ec_bufint_init(uint8 Module,uint8 BufNum)
{
  FLEXCAN(Module).MCR.R = 0x5000003F;  /* 64 message buffers in use */
  FLEXCAN(Module).IMASK1.R |= (0x1U << BufNum);
  FLEXCAN(Module).MCR.R = CAN_NORMAL_MODE|NUM_OF_ENABLED_MB;/* Normal mode */
  FLEXCAN(Module).MCR.B.HALT = 0;      /* FlexCAN attempts to synchronize with the CAN bus */
}

/**************************************************************************
 * FUNCTION :    ec_can_receive                                            *
 *                                                                         *
 * DESCRIPTION : Receive CAN message and copy message to Rx_Buffer[]       *
 *                                                                         *
 * PARAMETERS :  -Module: FLEXCAN_0, FLEXCAN_1 or FLEXCAN_2                *
 *               -BufNum: buffer number for receive                        *
 *               -Rx_Buffer: a pointer pointing to the buffer used to      *
 *                save the data received by CAN                            *
 *                                                                         *
 * RETURN :      -result: CAN_NOT_OK or CAN_OK                             *
 ***************************************************************************/
CAN_Return ec_can_receive(uint8 Module,uint8 BufNum,uint8 Rx_Buffer[])
{
  uint8 DataNum,Code,Length;
  uint16 FrameTime;
  uint32 i;
  CAN_Return result = CAN_NOT_OK;
  if (BufNum<32) {
    if (((FLEXCAN(Module).IFLAG1.R>>BufNum)&0x01) == 0x01) {
      Code = (uint8)FLEXCAN(Module).MB[BufNum].CS.B.CODE;
      Length = (uint8)FLEXCAN(Module).MB[BufNum].CS.B.DLC;
      FrameTime = (uint16)FLEXCAN(Module).MB[BufNum].CS.B.TIMESTAMP;
      for (DataNum=0; DataNum<FLEXCAN(Module).MB[BufNum].CS.B.DLC; DataNum++) {
        Rx_Buffer[DataNum] = (uint8)FLEXCAN(Module).MB[BufNum].DATA.B[DataNum];
      }

      ec_can_applrxindication(Module,BufNum,Rx_Buffer);
      i = FLEXCAN(Module).TIMER.R;
      FLEXCAN(Module).IFLAG1.R = (uint32)0x01<<BufNum;
      result = CAN_OK;
    }
  } else {
    if (((FLEXCAN(Module).IFLAG2.R>>(BufNum-32))&0x01) == 0x01) {
      Code = (uint8)FLEXCAN(Module).MB[BufNum].CS.B.CODE;
      Length = (uint8)FLEXCAN(Module).MB[BufNum].CS.B.DLC;
      FrameTime = (uint16)FLEXCAN(Module).MB[BufNum].CS.B.TIMESTAMP;
      for (DataNum=0; DataNum<FLEXCAN(Module).MB[BufNum].CS.B.DLC; DataNum++) {
        Rx_Buffer[DataNum] = (uint8)FLEXCAN(Module).MB[BufNum].DATA.B[DataNum];
      }

      ec_can_applrxindication(Module,BufNum,Rx_Buffer);
      i = FLEXCAN(Module).TIMER.R;
      FLEXCAN(Module).IFLAG2.R = (uint32)0x01<<(BufNum-32);
      result = CAN_OK;
    }
  }

  return result;
}

CAN_Return ec_can_receive_UDS(uint8 Module,uint8 BufNum,uint8 Rx_Buffer[], uint8
  *DLC)
{
  uint8 DataNum,Code,Length;
  uint16 FrameTime;
  uint32 i;
  CAN_Return result = CAN_NOT_OK;
  if (BufNum<32) {
    if (((FLEXCAN(Module).IFLAG1.R>>BufNum)&0x01) == 0x01) {
      Code = (uint8)FLEXCAN(Module).MB[BufNum].CS.B.CODE;
      *DLC = (uint8)FLEXCAN(Module).MB[BufNum].CS.B.DLC;
      FrameTime = (uint16)FLEXCAN(Module).MB[BufNum].CS.B.TIMESTAMP;
      for (DataNum=0; DataNum<FLEXCAN(Module).MB[BufNum].CS.B.DLC; DataNum++) {
        Rx_Buffer[DataNum] = (uint8)FLEXCAN(Module).MB[BufNum].DATA.B[DataNum];
      }

      ec_can_applrxindication(Module,BufNum,Rx_Buffer);
      i = FLEXCAN(Module).TIMER.R;
      FLEXCAN(Module).IFLAG1.R = (uint32)0x01<<BufNum;
      result = CAN_OK;
    }
  } else {
    if (((FLEXCAN(Module).IFLAG2.R>>(BufNum-32))&0x01) == 0x01) {
      Code = (uint8)FLEXCAN(Module).MB[BufNum].CS.B.CODE;
      *DLC = (uint8)FLEXCAN(Module).MB[BufNum].CS.B.DLC;
      FrameTime = (uint16)FLEXCAN(Module).MB[BufNum].CS.B.TIMESTAMP;
      for (DataNum=0; DataNum<FLEXCAN(Module).MB[BufNum].CS.B.DLC; DataNum++) {
        Rx_Buffer[DataNum] = (uint8)FLEXCAN(Module).MB[BufNum].DATA.B[DataNum];
      }

      ec_can_applrxindication(Module,BufNum,Rx_Buffer);
      i = FLEXCAN(Module).TIMER.R;
      FLEXCAN(Module).IFLAG2.R = (uint32)0x01<<(BufNum-32);
      result = CAN_OK;
    }
  }

  return result;
}

/**************************************************************************
 * FUNCTION :    ec_can_receiveall                                         *
 *                                                                         *
 * DESCRIPTION : Receive CAN message and copy message to Rx_Buffer[]       *
 *                                                                         *
 * PARAMETERS :  -Module: FLEXCAN_0, FLEXCAN_1 or FLEXCAN_2                *
 *               -*Id: CAN message ID                                      *
 *               -*Dlc: CAN message length                                 *
 *               -Rx_Buffer: a pointer pointing to the buffer used to      *
 *                save the data received by CAN                            *
 *                                                                         *
 * RETURN :      -result: CAN_NOT_OK or CAN_OK                             *
 ***************************************************************************/
CAN_Return ec_can_receiveall(uint8 Module,uint32 *Id,uint8 *Dlc,uint8 Rx_Buffer[])
{
  uint8 DataNum,Code;
  uint16 FrameTime;
  uint32 i;
  CAN_Return result = CAN_NOT_OK;
  if (((FLEXCAN(Module).IFLAG1.R>>14)&0x01) == 0x01) {
    Code = (uint8)FLEXCAN(Module).MB[14].CS.B.CODE;
    *Dlc = (uint8)FLEXCAN(Module).MB[14].CS.B.DLC;
    if (FLEXCAN(Module).MB[14].CS.B.IDE == MB_IDType_EX) {
      *Id = (uint32)FLEXCAN(Module).MB[14].ID.R;
    } else {
      *Id = (uint32)FLEXCAN(Module).MB[14].ID.B.ID_STD;
    }

    FrameTime = (uint16)FLEXCAN(Module).MB[14].CS.B.TIMESTAMP;
    for (DataNum=0; DataNum<FLEXCAN(Module).MB[14].CS.B.DLC; DataNum++) {
      Rx_Buffer[DataNum] = (uint8)FLEXCAN(Module).MB[14].DATA.B[DataNum];
    }

    i = FLEXCAN(Module).TIMER.R;
    FLEXCAN(Module).IFLAG1.R = (uint32)0x01<<14;
    result = CAN_OK;
  }

  return result;
}

/**************************************************************************
 * FUNCTION :    ec_can_transmit                                           *
 *                                                                         *
 * DESCRIPTION : Copy CAN Tx_Buffer to CAN Message Buffer and then         *
 *               transmit message to CAN bus                               *
 *                                                                         *
 * PARAMETERS :  -Module: FLEXCAN_0, FLEXCAN_1 or FLEXCAN_2                *
 *               -BufNum: buffer number for transmit                       *
 *               -IdType: 0 means standard format;1 means entend format    *
 *               -Id: the message ID to be transmitted                     *
 *               -DataLength: data length of the frame data                *
 *               -Tx_Buffer: the data array to be transmitted              *
 *                                                                         *
 * RETURN :      -result: CAN_BUSY or CAN_OK.                              *
 ***************************************************************************/
CAN_Return ec_can_transmit(uint8 Module,uint8 BufNum,uint8 IdType,uint32 Id,
  uint8 DataLength,uint8 Tx_Buffer[])
{
  uint8 i;
  CAN_Return result = CAN_BUSY;
  if (BufNum<8)
    BufNum = 8;
  else if ((BufNum>15)&(BufNum<56))
    BufNum = 15;
  else if (BufNum>63)
    BufNum = 63;
  else {
    if (FLEXCAN(Module).MB[BufNum].CS.B.CODE == TX_MB_CODE_TRANSMIT) {
      result = CAN_BUSY;
    } else {
      if (IdType == 0) {
        FLEXCAN(Module).MB[BufNum].CS.B.IDE = MB_IDType_ST;
        FLEXCAN(Module).MB[BufNum].ID.B.ID_STD = Id;
        FLEXCAN(Module).MB[BufNum].CS.B.SRR = 0;
      } else {
        FLEXCAN(Module).MB[BufNum].CS.B.IDE = MB_IDType_EX;
        FLEXCAN(Module).MB[BufNum].ID.R = (uint32)(Id&0x1FFFFFFF);
        FLEXCAN(Module).MB[BufNum].CS.B.SRR = 1;
      }

      FLEXCAN(Module).MB[BufNum].CS.B.RTR = 0;
      for (i=0; i<DataLength; i++) {
        FLEXCAN(Module).MB[BufNum].DATA.B[i] = Tx_Buffer[i];
      }

      FLEXCAN(Module).MB[BufNum].CS.B.DLC = DataLength;
      FLEXCAN(Module).MB[BufNum].CS.B.CODE = TX_MB_CODE_TRANSMIT;
      result = CAN_OK;
      ec_can_appltxconfirmation(Module,BufNum);
    }
  }

  return(result);
}

CAN_Return ec_remote_transmit(uint8 Module,uint8 BufNum,uint8 IdType,uint32 Id)
{
  uint8 i;
  CAN_Return result = CAN_BUSY;
  if (BufNum<8)
    BufNum = 8;
  else if ((BufNum>15)&(BufNum<56))
    BufNum = 15;
  else if (BufNum>63)
    BufNum = 63;
  else {
    if (FLEXCAN(Module).MB[BufNum].CS.B.CODE == TX_MB_CODE_TRANSMIT) {
      result = CAN_BUSY;
    } else {
      if (IdType == 0) {
        FLEXCAN(Module).MB[BufNum].CS.B.IDE = MB_IDType_ST;
        FLEXCAN(Module).MB[BufNum].ID.B.ID_STD = Id;
        FLEXCAN(Module).MB[BufNum].CS.B.SRR = 0;
      } else {
        FLEXCAN(Module).MB[BufNum].CS.B.IDE = MB_IDType_EX;
        FLEXCAN(Module).MB[BufNum].ID.R = (uint32)(Id&0x1FFFFFFF);
        FLEXCAN(Module).MB[BufNum].CS.B.SRR = 1;
      }

      FLEXCAN(Module).MB[BufNum].CS.B.RTR = 1;
      FLEXCAN(Module).MB[BufNum].CS.B.DLC = 8;
      FLEXCAN(Module).MB[BufNum].CS.B.CODE = TX_MB_CODE_TRANSMIT;
      result = CAN_OK;
    }
  }

  return(result);
}

#endif

/* File trailer for ECUCoder generated file can.c.
 *
 * [EOF]
 */
