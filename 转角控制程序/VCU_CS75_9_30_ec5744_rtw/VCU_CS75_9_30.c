/*
 * Code generated for Simulink model VCU_CS75_9_30.
 *
 * FILE    : VCU_CS75_9_30.c
 *
 * VERSION : 1.2543
 *
 * DATE    : Wed Jan 06 13:56:02 2021
 *
 * Copyright 2011-2017 ECUCoder. All Rights Reserved.
 */

#include "VCU_CS75_9_30.h"
#include "VCU_CS75_9_30_private.h"

/* #include "myinclude.h" */

/* Named constants for Chart: '<S29>/Chart' */
#define VCU_CS75_9_30_IN_AutoDriving   ((uint8_T)1U)
#define VCU_CS75_9_30_IN_Error         ((uint8_T)2U)
#define VCU_CS75_9_30_IN_System_State  ((uint8_T)1U)
#define VCU_CS75_9_30_IN_TakeOver      ((uint8_T)4U)
#define VCU_CS75__IN_INIT_ManualDriving ((uint8_T)3U)

/* Exported block parameters */
real_T LDW = 0.0;                      /* Variable: LDW
                                        * Referenced by: '<S30>/ECCalVar'
                                        */
real_T ST_comd = 0.0;                  /* Variable: ST_comd
                                        * Referenced by: '<S32>/ECCalVar'
                                        */

/* Exported data definition */

/* Definition for custom storage class: Default */
real_T A1counter;
real_T ACC_ACCTargetAcceleration;
real_T ACC_AccTorqueReq;
real_T ACC_CDDAxEnable;
real_T ACC_Driveoff_Request;
real_T ACC_RollingCounter_id2E4;
real_T ACC_RollingCounter_id2E5;
real_T ACC_TrqEnable;
real_T APA_RollingCounter;
real_T EMS_BrakePedalStatus;
real_T EMS_FrictionalTroq;
real_T EMS_FullLoadIndicatedTroq;
real_T EMS_IndicatedRealTroq;
real_T EMS_TorqueConstant;
real_T EPB_RollingCounter_id256;
real_T EPS_AvailabilityStatus;
real_T LAS_LDWStatus;
real_T LAS_LDWVibrationWarning;
real_T P6_Value;
real_T SAS_SteeringAngle;
real32_T SCS_out;
real_T Server_CommunicationStatus;
real_T System_State;
real_T VehicleCommunicationStatus;
real_T VehicleFaultStatus;
real32_T Vx_out;
real32_T cones_count_actual_out;
real32_T cones_count_all_out;
real_T counter1;
real_T counter3;
real32_T finish_out;
real32_T mission_out;
real_T mubiao_zhuanjiao;
real32_T tap_out;

/* Block signals (auto storage) */
B_VCU_CS75_9_30_T VCU_CS75_9_30_B;

/* Block states (auto storage) */
DW_VCU_CS75_9_30_T VCU_CS75_9_30_DW;

/* Real-time model */
RT_MODEL_VCU_CS75_9_30_T VCU_CS75_9_30_M_;
RT_MODEL_VCU_CS75_9_30_T *const VCU_CS75_9_30_M = &VCU_CS75_9_30_M_;
static void rate_monotonic_scheduler(void);
void ISR_PIT_CH3(void)
{
  PIT_0.TIMER[3].TFLG.R = 1;
  ECUCoderModelBaseCounter++;
  rate_monotonic_scheduler();
}

real_T look1_binlx(real_T u0, const real_T bp0[], const real_T table[], uint32_T
                   maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

void ISR_FlexCAN_2_MB0(void)
{
  /* Call the system: <S6>/CCPReceive */
  {
    /* Output and update for function-call system: '<S6>/CCPReceive' */

    /* S-Function (ec5744_canreceiveslb): '<S22>/CANReceive' */

    /* Receive CAN message */
    {
      uint8 CAN2BUF0RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

      uint8 can2buf0looprx= 0;
      VCU_CS75_9_30_B.CANReceive_o3= 256;
      VCU_CS75_9_30_B.CANReceive_o5= 8;
      VCU_CS75_9_30_B.CANReceive_o2= ec_can_receive(2,0, CAN2BUF0RX);
      VCU_CS75_9_30_B.CANReceive_o4[0]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_9_30_B.CANReceive_o4[1]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_9_30_B.CANReceive_o4[2]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_9_30_B.CANReceive_o4[3]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_9_30_B.CANReceive_o4[4]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_9_30_B.CANReceive_o4[5]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_9_30_B.CANReceive_o4[6]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_9_30_B.CANReceive_o4[7]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
    }

    /* Nothing to do for system: <S22>/Nothing */
  }

  FLEXCAN(2).IFLAG1.B.BUF0I = 1;       /* Clear CAN interrupt flag by writing it to 1 */
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void VCU_CS75_9_30_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(VCU_CS75_9_30_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(VCU_CS75_9_30_M, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(VCU_CS75_9_30_M, 3));
  eventFlags[4] = ((boolean_T)rtmStepTask(VCU_CS75_9_30_M, 4));
  eventFlags[5] = ((boolean_T)rtmStepTask(VCU_CS75_9_30_M, 5));
  eventFlags[6] = ((boolean_T)rtmStepTask(VCU_CS75_9_30_M, 6));
  eventFlags[7] = ((boolean_T)rtmStepTask(VCU_CS75_9_30_M, 7));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (VCU_CS75_9_30_M->Timing.TaskCounters.TID[1])++;
  if ((VCU_CS75_9_30_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.001s, 0.0s] */
    VCU_CS75_9_30_M->Timing.TaskCounters.TID[1] = 0;
  }

  (VCU_CS75_9_30_M->Timing.TaskCounters.TID[2])++;
  if ((VCU_CS75_9_30_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.005s, 0.0s] */
    VCU_CS75_9_30_M->Timing.TaskCounters.TID[2] = 0;
  }

  (VCU_CS75_9_30_M->Timing.TaskCounters.TID[3])++;
  if ((VCU_CS75_9_30_M->Timing.TaskCounters.TID[3]) > 19) {/* Sample time: [0.01s, 0.0s] */
    VCU_CS75_9_30_M->Timing.TaskCounters.TID[3] = 0;
  }

  (VCU_CS75_9_30_M->Timing.TaskCounters.TID[4])++;
  if ((VCU_CS75_9_30_M->Timing.TaskCounters.TID[4]) > 39) {/* Sample time: [0.02s, 0.0s] */
    VCU_CS75_9_30_M->Timing.TaskCounters.TID[4] = 0;
  }

  (VCU_CS75_9_30_M->Timing.TaskCounters.TID[5])++;
  if ((VCU_CS75_9_30_M->Timing.TaskCounters.TID[5]) > 99) {/* Sample time: [0.05s, 0.0s] */
    VCU_CS75_9_30_M->Timing.TaskCounters.TID[5] = 0;
  }

  (VCU_CS75_9_30_M->Timing.TaskCounters.TID[6])++;
  if ((VCU_CS75_9_30_M->Timing.TaskCounters.TID[6]) > 199) {/* Sample time: [0.1s, 0.0s] */
    VCU_CS75_9_30_M->Timing.TaskCounters.TID[6] = 0;
  }

  (VCU_CS75_9_30_M->Timing.TaskCounters.TID[7])++;
  if ((VCU_CS75_9_30_M->Timing.TaskCounters.TID[7]) > 999) {/* Sample time: [0.5s, 0.0s] */
    VCU_CS75_9_30_M->Timing.TaskCounters.TID[7] = 0;
  }
}

/*
 * Output and update for atomic system:
 *    '<S30>/MATLAB Function2'
 *    '<S32>/MATLAB Function7'
 *    '<S33>/MATLAB Function7'
 */
void VCU_CS75_9__MATLABFunction2(real_T rtu_u, B_MATLABFunction2_VCU_CS75_9__T
  *localB)
{
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Accesories/MATLAB Function2': '<S36>:1' */
  if (rtu_u == 1.0) {
    /* '<S36>:1:2' */
    /* '<S36>:1:3' */
    localB->y = 1.0;
  } else {
    /* '<S36>:1:5' */
    localB->y = 0.0;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function for TID0 */
void VCU_CS75_9_30_step0(void)         /* Sample time: [0.0005s, 0.0s] */
{
  {                                    /* Sample time: [0.0005s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void VCU_CS75_9_30_step1(void)         /* Sample time: [0.001s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S6>/Function-Call Generator' incorporates:
   *  SubSystem: '<S6>/CCPBackground'
   */

  /* S-Function (ec5744_ccpslb): '<S21>/CCPBackground' */
  ccpBackground();
}

/* Model step function for TID2 */
void VCU_CS75_9_30_step2(void)         /* Sample time: [0.005s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S4>/5ms' incorporates:
   *  SubSystem: '<S4>/daq5ms'
   */

  /* S-Function (ec5744_ccpslb1): '<S19>/CCPDAQ' */
  ccpDaq(0);
}

/* Model step function for TID3 */
void VCU_CS75_9_30_step3(void)         /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S4>/10ms' incorporates:
   *  SubSystem: '<S4>/daq10ms'
   */

  /* S-Function (ec5744_ccpslb1): '<S16>/CCPDAQ' */
  ccpDaq(1);
}

/* Model step function for TID4 */
void VCU_CS75_9_30_step4(void)         /* Sample time: [0.02s, 0.0s] */
{
  uint32_T rtb_APA_SteeringAngleReqProte_h;
  uint32_T rtb_APA_SteeringAngleReqProte_n;
  uint8_T rtb_APA_CheckSum_Convert;
  boolean_T rtb_APA_EPSAngleReqROP;
  uint8_T rtb_APA_EPSAngleReqCOV;
  uint8_T rtb_APA_EPSAngleReqCOV1;
  uint8_T rtb_APA_RollingCounter_Convert;
  int32_T rtb_LateralTakeover;
  uint8_T rtb_APA_SteeringAngleReqProt_au;
  real_T rtb_P6_Value;
  real_T rtb_Memory2;
  real_T rtb_APP_Input_idx_99;
  real_T rtb_APP_Input_idx_19;
  real_T rtb_APP_Input_idx_20;
  real_T rtb_APP_Input_idx_8;
  real_T rtb_APP_Input_idx_217;
  real_T rtb_APP_Input_idx_9;
  real_T rtb_APP_Input_idx_66;
  real_T rtb_APP_Input_idx_63;
  real_T rtb_APP_Input_idx_3;
  real_T rtb_APP_Input_idx_17;
  real_T rtb_APP_Input_idx_1;
  real_T rtb_APP_Input_idx_12;
  real_T rtb_APP_Input_idx_0;
  real_T rtb_APP_Input_idx_39;
  real_T rtb_APP_Input_idx_29;

  /* S-Function (fcncallgen): '<Root>/20ms' incorporates:
   *  SubSystem: '<Root>/长安CS75底盘程序，20ms一次'
   */
  /* Outputs for Atomic SubSystem: '<S2>/BSW_Input' */

  /* S-Function (ec5744_swislbu3): '<S57>/SwitchInput' */

  /* Read the the value of the specified switch input */
  VCU_CS75_9_30_B.P6_Value_h= ec_gpio_read(92);

  /* DataTypeConversion: '<S57>/Data Type Conversion' */
  rtb_P6_Value = (real_T)VCU_CS75_9_30_B.P6_Value_h;

  /* MATLAB Function: '<S57>/MATLAB Function' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/BSW_Input/ADC_Input/MATLAB Function': '<S62>:1' */
  if (rtb_P6_Value == 1.0) {
    /* '<S62>:1:2' */
    /* '<S62>:1:3' */
    P6_Value = 0.0;
  } else {
    /* '<S62>:1:5' */
    P6_Value = 1.0;
  }

  /* End of MATLAB Function: '<S57>/MATLAB Function' */

  /* S-Function (ec5744_canreceiveslb): '<S63>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF0RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can0buf0looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_o= 529;
    VCU_CS75_9_30_B.CANReceive_o5_l= 8;
    VCU_CS75_9_30_B.CANReceive_o2_d= ec_can_receive(0,0, CAN0BUF0RX);
    VCU_CS75_9_30_B.CANReceive_o4_e[0]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_e[1]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_e[2]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_e[3]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_e[4]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_e[5]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_e[6]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_e[7]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
  }

  /* Call the system: <S63>/ReceiveMessages */

  /* Output and update for function-call system: '<S63>/ReceiveMessages' */
  {
    real_T rtb_target_steering_sat;
    int32_T rtb_target_steering_L;
    real32_T rtb_throttlevbrake_position_sat;

    /* Outputs for Enabled SubSystem: '<S64>/Subsystem' incorporates:
     *  EnablePort: '<S65>/Enable'
     */
    if (VCU_CS75_9_30_B.CANReceive_o2_d > 0) {
      /* Product: '<S67>/Vxinput8_P' incorporates:
       *  Constant: '<S67>/Vxinput8_C'
       */
      rtb_target_steering_sat = (real_T)VCU_CS75_9_30_B.CANReceive_o4_e[7] *
        256.0;

      /* Sum: '<S67>/Vxinput8_Ad' */
      rtb_target_steering_sat += (real_T)VCU_CS75_9_30_B.CANReceive_o4_e[6];

      /* DataTypeConversion: '<S67>/Vx_Convert' */
      rtb_target_steering_L = (int32_T)rtb_target_steering_sat;

      /* DataTypeConversion: '<S67>/Vxcv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* Gain: '<S67>/Vx_F' */
      rtb_throttlevbrake_position_sat *= 0.00610360876F;

      /* Sum: '<S67>/Vx_Ad' incorporates:
       *  Constant: '<S67>/Vx_O'
       */
      rtb_throttlevbrake_position_sat += -200.0F;

      /* Saturate: '<S67>/Vx_sat' */
      if (rtb_throttlevbrake_position_sat > 200.0F) {
        rtb_throttlevbrake_position_sat = 200.0F;
      }

      /* End of Saturate: '<S67>/Vx_sat' */

      /* DataStoreWrite: '<S65>/Data Store Write' */
      Vx_out = rtb_throttlevbrake_position_sat;

      /* DataTypeConversion: '<S67>/mission_Convert' */
      rtb_target_steering_L = VCU_CS75_9_30_B.CANReceive_o4_e[5];

      /* S-Function (sfix_bitop): '<S67>/mission_L' */
      rtb_target_steering_L &= 240U;

      /* ArithShift: '<S67>/mission_S' */
      rtb_target_steering_L = (int32_T)((uint32_T)rtb_target_steering_L >> 4);

      /* DataTypeConversion: '<S67>/missioncv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* Saturate: '<S67>/mission_sat' */
      if (rtb_throttlevbrake_position_sat > 7.0F) {
        rtb_throttlevbrake_position_sat = 7.0F;
      }

      /* End of Saturate: '<S67>/mission_sat' */

      /* DataStoreWrite: '<S65>/Data Store Write1' */
      mission_out = rtb_throttlevbrake_position_sat;

      /* DataTypeConversion: '<S67>/SCS_Convert' */
      rtb_target_steering_L = VCU_CS75_9_30_B.CANReceive_o4_e[5];

      /* S-Function (sfix_bitop): '<S67>/SCS_L' */
      rtb_target_steering_L &= 8U;

      /* ArithShift: '<S67>/SCS_S' */
      rtb_target_steering_L = (int32_T)((uint32_T)rtb_target_steering_L >> 3);

      /* DataTypeConversion: '<S67>/SCScv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* DataStoreWrite: '<S65>/Data Store Write2' */
      SCS_out = rtb_throttlevbrake_position_sat;

      /* DataTypeConversion: '<S67>/finish_Convert' */
      rtb_target_steering_L = VCU_CS75_9_30_B.CANReceive_o4_e[5];

      /* S-Function (sfix_bitop): '<S67>/finish_L' */
      rtb_target_steering_L &= 4U;

      /* ArithShift: '<S67>/finish_S' */
      rtb_target_steering_L = (int32_T)((uint32_T)rtb_target_steering_L >> 2);

      /* DataTypeConversion: '<S67>/finishcv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* DataStoreWrite: '<S65>/Data Store Write3' */
      finish_out = rtb_throttlevbrake_position_sat;

      /* DataTypeConversion: '<S67>/tap_Convert' */
      rtb_target_steering_L = VCU_CS75_9_30_B.CANReceive_o4_e[5];

      /* S-Function (sfix_bitop): '<S67>/tap_L' */
      rtb_target_steering_L &= 3U;

      /* DataTypeConversion: '<S67>/tapcv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* DataStoreWrite: '<S65>/Data Store Write4' */
      tap_out = rtb_throttlevbrake_position_sat;

      /* DataTypeConversion: '<S67>/cones_count_all_Convert' */
      rtb_target_steering_L = VCU_CS75_9_30_B.CANReceive_o4_e[4];

      /* DataTypeConversion: '<S67>/cones_count_allcv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* DataStoreWrite: '<S65>/Data Store Write5' */
      cones_count_all_out = rtb_throttlevbrake_position_sat;

      /* DataTypeConversion: '<S67>/cones_count_actual_Convert' */
      rtb_target_steering_L = VCU_CS75_9_30_B.CANReceive_o4_e[3];

      /* DataTypeConversion: '<S67>/cones_count_actualcv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* DataStoreWrite: '<S65>/Data Store Write6' */
      cones_count_actual_out = rtb_throttlevbrake_position_sat;

      /* Product: '<S67>/throttlevbrake_positioninput3_P' incorporates:
       *  Constant: '<S67>/throttlevbrake_positioninput3_C'
       */
      rtb_target_steering_sat = (real_T)VCU_CS75_9_30_B.CANReceive_o4_e[2] *
        256.0;

      /* Sum: '<S67>/throttlevbrake_positioninput3_Ad' */
      rtb_target_steering_sat += (real_T)VCU_CS75_9_30_B.CANReceive_o4_e[1];

      /* DataTypeConversion: '<S67>/throttlevbrake_position_Convert' */
      rtb_target_steering_L = (int32_T)rtb_target_steering_sat;

      /* S-Function (sfix_bitop): '<S67>/throttlevbrake_position_L' */
      rtb_target_steering_L &= 65520U;

      /* ArithShift: '<S67>/throttlevbrake_position_S' */
      rtb_target_steering_L = (int32_T)((uint32_T)rtb_target_steering_L >> 4);

      /* DataTypeConversion: '<S67>/throttlevbrake_positioncv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* Gain: '<S67>/throttlevbrake_position_F' */
      rtb_throttlevbrake_position_sat *= 0.0488400497F;

      /* Sum: '<S67>/throttlevbrake_position_Ad' incorporates:
       *  Constant: '<S67>/throttlevbrake_position_O'
       */
      rtb_throttlevbrake_position_sat += -100.0F;

      /* Saturate: '<S67>/throttlevbrake_position_sat' */
      if (rtb_throttlevbrake_position_sat > 100.0F) {
        rtb_throttlevbrake_position_sat = 100.0F;
      }

      /* End of Saturate: '<S67>/throttlevbrake_position_sat' */

      /* DataTypeConversion: '<S65>/Data Type Conversion' */
      rtb_target_steering_sat = rtb_throttlevbrake_position_sat;

      /* MATLAB Function: '<S65>/MATLAB Function1' */
      /* MATLAB Function '长安CS75底盘程序，20ms一次/BSW_Input/CAN0_Rx/a1_211/ReceiveMessages/Subsystem/MATLAB Function1': '<S66>:1' */
      /* '<S66>:1:2' */
      if (rtb_target_steering_sat < 0.0) {
        /* '<S66>:1:3' */
        /* '<S66>:1:4' */
        rtb_target_steering_sat /= 20.0;
      }

      /* End of MATLAB Function: '<S65>/MATLAB Function1' */

      /* SignalConversion: '<S65>/Signal Conversion' incorporates:
       *  Constant: '<S65>/Constant2'
       */
      VCU_CS75_9_30_B.AutoDrivingReady = 0.0;

      /* SignalConversion: '<S65>/Signal Conversion' */
      VCU_CS75_9_30_B.RemoteAcclPosition = rtb_target_steering_sat;

      /* Product: '<S67>/target_steeringinput2_P' incorporates:
       *  Constant: '<S67>/target_steeringinput2_C'
       */
      rtb_target_steering_sat = (real_T)VCU_CS75_9_30_B.CANReceive_o4_e[1] *
        256.0;

      /* Sum: '<S67>/target_steeringinput2_Ad' */
      rtb_target_steering_sat += (real_T)VCU_CS75_9_30_B.CANReceive_o4_e[0];

      /* DataTypeConversion: '<S67>/target_steering_Convert' */
      rtb_target_steering_L = (int32_T)rtb_target_steering_sat;

      /* S-Function (sfix_bitop): '<S67>/target_steering_L' */
      rtb_target_steering_L &= 4095U;

      /* DataTypeConversion: '<S67>/target_steeringcv' */
      rtb_target_steering_sat = rtb_target_steering_L;

      /* Gain: '<S67>/target_steering_F' */
      rtb_target_steering_sat *= 0.0488400488400488;

      /* Sum: '<S67>/target_steering_Ad' incorporates:
       *  Constant: '<S67>/target_steering_O'
       */
      rtb_target_steering_sat += -100.0;

      /* Saturate: '<S67>/target_steering_sat' */
      if (rtb_target_steering_sat > 99.9999999999998) {
        rtb_target_steering_sat = 99.9999999999998;
      }

      /* End of Saturate: '<S67>/target_steering_sat' */

      /* SignalConversion: '<S65>/Signal Conversion' */
      VCU_CS75_9_30_B.LaterlAngleCommand = rtb_target_steering_sat;

      /* SignalConversion: '<S65>/Signal Conversion' incorporates:
       *  Constant: '<S65>/Constant'
       */
      VCU_CS75_9_30_B.A1_Message_Counter = 0.0;

      /* SignalConversion: '<S65>/Signal Conversion' incorporates:
       *  Constant: '<S65>/Constant1'
       */
      VCU_CS75_9_30_B.A1_Checksum = 0.0;
    }

    /* End of Outputs for SubSystem: '<S64>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S77>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF23RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf23looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_l= 648;
    VCU_CS75_9_30_B.CANReceive_o5_h= 8;
    VCU_CS75_9_30_B.CANReceive_o2_do= ec_can_receive(1,23, CAN1BUF23RX);
    VCU_CS75_9_30_B.CANReceive_o4_c[0]= CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_c[1]= CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_c[2]= CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_c[3]= CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_c[4]= CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_c[5]= CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_c[6]= CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_c[7]= CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
  }

  /* Call the system: <S77>/ReceiveMessages */

  /* Output and update for function-call system: '<S77>/ReceiveMessages' */
  {
    int32_T rtb_BCM_emergencylightstatus_L;
    int32_T rtb_BCM_BuzzerWarningMode_sat;
    int32_T rtb_BCM_DriverDoorLockStatus_sa;
    int32_T rtb_BCM_DriverDoorStatus_sat;
    int32_T rtb_BCM_FrontWashStatus_sat;
    int32_T rtb_BCM_FrontWiperStatus_sat;
    int32_T rtb_BCM_HoodStatus_sat;
    int32_T rtb_BCM_LatchOverheatProtect_sa;
    int32_T rtb_BCM_LeftRearDoorStatus_sat;
    int32_T rtb_BCM_PassengerDoorLockStatus;
    int32_T rtb_BCM_PassengerDoorStatus_sat;
    int32_T rtb_BCM_PowerStatusFeedback_sat;
    int32_T rtb_BCM_RearWiperStatus_sat;
    int32_T rtb_BCM_ReversePosition_sat;
    int32_T rtb_BCM_RightRearDoorStatus_sat;
    int32_T rtb_BCM_SystemFailureFlag_sat;
    int32_T rtb_BCM_TrunkDoorStatus_sat;
    int32_T rtb_BCM_TurnIndicatorLeft_sat;
    int32_T rtb_BCM_TurnIndicatorRight_sat;
    int32_T rtb_BCM_TurnLightSwitchSts_sat;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S104>/Subsystem' incorporates:
     *  EnablePort: '<S105>/Enable'
     */
    if (VCU_CS75_9_30_B.CANReceive_o2_do > 0) {
      /* DataTypeConversion: '<S106>/BCM_BuzzerWarningMode_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_9_30_B.CANReceive_o4_c[7];

      /* S-Function (sfix_bitop): '<S106>/BCM_BuzzerWarningMode_L' */
      rtb_BCM_emergencylightstatus_L &= 31U;

      /* Sum: '<S106>/BCM_BuzzerWarningMode_Ad' */
      rtb_BCM_BuzzerWarningMode_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S106>/BCM_BuzzerWarningMode_sat' */
      u0 = rtb_BCM_BuzzerWarningMode_sat;
      rtb_BCM_BuzzerWarningMode_sat = (int32_T)u0;

      /* DataTypeConversion: '<S106>/BCM_DriverDoorLockStatus_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_9_30_B.CANReceive_o4_c[5];

      /* S-Function (sfix_bitop): '<S106>/BCM_DriverDoorLockStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 3U;

      /* Sum: '<S106>/BCM_DriverDoorLockStatus_Ad' */
      rtb_BCM_DriverDoorLockStatus_sa = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S106>/BCM_DriverDoorLockStatus_sat' */
      u0 = rtb_BCM_DriverDoorLockStatus_sa;
      rtb_BCM_DriverDoorLockStatus_sa = (int32_T)u0;

      /* DataTypeConversion: '<S106>/BCM_DriverDoorStatus_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_9_30_B.CANReceive_o4_c[2];

      /* S-Function (sfix_bitop): '<S106>/BCM_DriverDoorStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 128U;

      /* ArithShift: '<S106>/BCM_DriverDoorStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 7);

      /* Sum: '<S106>/BCM_DriverDoorStatus_Ad' */
      rtb_BCM_DriverDoorStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S106>/BCM_DriverDoorStatus_sat' */
      u0 = rtb_BCM_DriverDoorStatus_sat;
      rtb_BCM_DriverDoorStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S106>/BCM_FrontWashStatus_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_9_30_B.CANReceive_o4_c[1];

      /* S-Function (sfix_bitop): '<S106>/BCM_FrontWashStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 3U;

      /* Sum: '<S106>/BCM_FrontWashStatus_Ad' */
      rtb_BCM_FrontWashStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S106>/BCM_FrontWashStatus_sat' */
      u0 = rtb_BCM_FrontWashStatus_sat;
      rtb_BCM_FrontWashStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S106>/BCM_FrontWiperStatus_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_9_30_B.CANReceive_o4_c[5];

      /* S-Function (sfix_bitop): '<S106>/BCM_FrontWiperStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 192U;

      /* ArithShift: '<S106>/BCM_FrontWiperStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 6);

      /* Sum: '<S106>/BCM_FrontWiperStatus_Ad' */
      rtb_BCM_FrontWiperStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S106>/BCM_FrontWiperStatus_sat' */
      u0 = rtb_BCM_FrontWiperStatus_sat;
      rtb_BCM_FrontWiperStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S106>/BCM_HoodStatus_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_9_30_B.CANReceive_o4_c[2];

      /* S-Function (sfix_bitop): '<S106>/BCM_HoodStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 4U;

      /* ArithShift: '<S106>/BCM_HoodStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 2);

      /* Sum: '<S106>/BCM_HoodStatus_Ad' */
      rtb_BCM_HoodStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S106>/BCM_HoodStatus_sat' */
      u0 = rtb_BCM_HoodStatus_sat;
      rtb_BCM_HoodStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S106>/BCM_LatchOverheatProtect_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_9_30_B.CANReceive_o4_c[7];

      /* S-Function (sfix_bitop): '<S106>/BCM_LatchOverheatProtect_L' */
      rtb_BCM_emergencylightstatus_L &= 64U;

      /* ArithShift: '<S106>/BCM_LatchOverheatProtect_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 6);

      /* Sum: '<S106>/BCM_LatchOverheatProtect_Ad' */
      rtb_BCM_LatchOverheatProtect_sa = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S106>/BCM_LatchOverheatProtect_sat' */
      u0 = rtb_BCM_LatchOverheatProtect_sa;
      rtb_BCM_LatchOverheatProtect_sa = (int32_T)u0;

      /* DataTypeConversion: '<S106>/BCM_LeftRearDoorStatus_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_9_30_B.CANReceive_o4_c[2];

      /* S-Function (sfix_bitop): '<S106>/BCM_LeftRearDoorStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 32U;

      /* ArithShift: '<S106>/BCM_LeftRearDoorStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 5);

      /* Sum: '<S106>/BCM_LeftRearDoorStatus_Ad' */
      rtb_BCM_LeftRearDoorStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S106>/BCM_LeftRearDoorStatus_sat' */
      u0 = rtb_BCM_LeftRearDoorStatus_sat;
      rtb_BCM_LeftRearDoorStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S106>/BCM_PassengerDoorLockStatus_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_9_30_B.CANReceive_o4_c[4];

      /* S-Function (sfix_bitop): '<S106>/BCM_PassengerDoorLockStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 12U;

      /* ArithShift: '<S106>/BCM_PassengerDoorLockStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 2);

      /* Sum: '<S106>/BCM_PassengerDoorLockStatus_Ad' */
      rtb_BCM_PassengerDoorLockStatus = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S106>/BCM_PassengerDoorLockStatus_sat' */
      u0 = rtb_BCM_PassengerDoorLockStatus;
      rtb_BCM_PassengerDoorLockStatus = (int32_T)u0;

      /* DataTypeConversion: '<S106>/BCM_PassengerDoorStatus_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_9_30_B.CANReceive_o4_c[2];

      /* S-Function (sfix_bitop): '<S106>/BCM_PassengerDoorStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 64U;

      /* ArithShift: '<S106>/BCM_PassengerDoorStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 6);

      /* Sum: '<S106>/BCM_PassengerDoorStatus_Ad' */
      rtb_BCM_PassengerDoorStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S106>/BCM_PassengerDoorStatus_sat' */
      u0 = rtb_BCM_PassengerDoorStatus_sat;
      rtb_BCM_PassengerDoorStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S106>/BCM_PowerStatusFeedback_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_9_30_B.CANReceive_o4_c[5];

      /* S-Function (sfix_bitop): '<S106>/BCM_PowerStatusFeedback_L' */
      rtb_BCM_emergencylightstatus_L &= 12U;

      /* ArithShift: '<S106>/BCM_PowerStatusFeedback_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 2);

      /* Sum: '<S106>/BCM_PowerStatusFeedback_Ad' */
      rtb_BCM_PowerStatusFeedback_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S106>/BCM_PowerStatusFeedback_sat' */
      u0 = rtb_BCM_PowerStatusFeedback_sat;
      rtb_BCM_PowerStatusFeedback_sat = (int32_T)u0;

      /* DataTypeConversion: '<S106>/BCM_RearWiperStatus_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_9_30_B.CANReceive_o4_c[5];

      /* S-Function (sfix_bitop): '<S106>/BCM_RearWiperStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 16U;

      /* ArithShift: '<S106>/BCM_RearWiperStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 4);

      /* Sum: '<S106>/BCM_RearWiperStatus_Ad' */
      rtb_BCM_RearWiperStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S106>/BCM_RearWiperStatus_sat' */
      u0 = rtb_BCM_RearWiperStatus_sat;
      rtb_BCM_RearWiperStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S106>/BCM_ReversePosition_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_9_30_B.CANReceive_o4_c[6];

      /* S-Function (sfix_bitop): '<S106>/BCM_ReversePosition_L' */
      rtb_BCM_emergencylightstatus_L &= 1U;

      /* Sum: '<S106>/BCM_ReversePosition_Ad' */
      rtb_BCM_ReversePosition_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S106>/BCM_ReversePosition_sat' */
      u0 = rtb_BCM_ReversePosition_sat;
      rtb_BCM_ReversePosition_sat = (int32_T)u0;

      /* DataTypeConversion: '<S106>/BCM_RightRearDoorStatus_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_9_30_B.CANReceive_o4_c[2];

      /* S-Function (sfix_bitop): '<S106>/BCM_RightRearDoorStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 16U;

      /* ArithShift: '<S106>/BCM_RightRearDoorStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 4);

      /* Sum: '<S106>/BCM_RightRearDoorStatus_Ad' */
      rtb_BCM_RightRearDoorStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S106>/BCM_RightRearDoorStatus_sat' */
      u0 = rtb_BCM_RightRearDoorStatus_sat;
      rtb_BCM_RightRearDoorStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S106>/BCM_SystemFailureFlag_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_9_30_B.CANReceive_o4_c[7];

      /* S-Function (sfix_bitop): '<S106>/BCM_SystemFailureFlag_L' */
      rtb_BCM_emergencylightstatus_L &= 32U;

      /* ArithShift: '<S106>/BCM_SystemFailureFlag_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 5);

      /* Sum: '<S106>/BCM_SystemFailureFlag_Ad' */
      rtb_BCM_SystemFailureFlag_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S106>/BCM_SystemFailureFlag_sat' */
      u0 = rtb_BCM_SystemFailureFlag_sat;
      rtb_BCM_SystemFailureFlag_sat = (int32_T)u0;

      /* DataTypeConversion: '<S106>/BCM_TrunkDoorStatus_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_9_30_B.CANReceive_o4_c[2];

      /* S-Function (sfix_bitop): '<S106>/BCM_TrunkDoorStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 8U;

      /* ArithShift: '<S106>/BCM_TrunkDoorStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 3);

      /* Sum: '<S106>/BCM_TrunkDoorStatus_Ad' */
      rtb_BCM_TrunkDoorStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S106>/BCM_TrunkDoorStatus_sat' */
      u0 = rtb_BCM_TrunkDoorStatus_sat;
      rtb_BCM_TrunkDoorStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S106>/BCM_TurnIndicatorLeft_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_9_30_B.CANReceive_o4_c[1];

      /* S-Function (sfix_bitop): '<S106>/BCM_TurnIndicatorLeft_L' */
      rtb_BCM_emergencylightstatus_L &= 192U;

      /* ArithShift: '<S106>/BCM_TurnIndicatorLeft_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 6);

      /* Sum: '<S106>/BCM_TurnIndicatorLeft_Ad' */
      rtb_BCM_TurnIndicatorLeft_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S106>/BCM_TurnIndicatorLeft_sat' */
      u0 = rtb_BCM_TurnIndicatorLeft_sat;
      rtb_BCM_TurnIndicatorLeft_sat = (int32_T)u0;

      /* DataTypeConversion: '<S106>/BCM_TurnIndicatorRight_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_9_30_B.CANReceive_o4_c[1];

      /* S-Function (sfix_bitop): '<S106>/BCM_TurnIndicatorRight_L' */
      rtb_BCM_emergencylightstatus_L &= 48U;

      /* ArithShift: '<S106>/BCM_TurnIndicatorRight_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 4);

      /* Sum: '<S106>/BCM_TurnIndicatorRight_Ad' */
      rtb_BCM_TurnIndicatorRight_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S106>/BCM_TurnIndicatorRight_sat' */
      u0 = rtb_BCM_TurnIndicatorRight_sat;
      rtb_BCM_TurnIndicatorRight_sat = (int32_T)u0;

      /* DataTypeConversion: '<S106>/BCM_TurnLightSwitchSts_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_9_30_B.CANReceive_o4_c[6];

      /* S-Function (sfix_bitop): '<S106>/BCM_TurnLightSwitchSts_L' */
      rtb_BCM_emergencylightstatus_L &= 12U;

      /* ArithShift: '<S106>/BCM_TurnLightSwitchSts_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 2);

      /* Sum: '<S106>/BCM_TurnLightSwitchSts_Ad' */
      rtb_BCM_TurnLightSwitchSts_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S106>/BCM_TurnLightSwitchSts_sat' */
      u0 = rtb_BCM_TurnLightSwitchSts_sat;
      rtb_BCM_TurnLightSwitchSts_sat = (int32_T)u0;

      /* DataTypeConversion: '<S106>/BCM_emergencylightstatus_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_9_30_B.CANReceive_o4_c[4];

      /* S-Function (sfix_bitop): '<S106>/BCM_emergencylightstatus_L' */
      rtb_BCM_emergencylightstatus_L &= 48U;

      /* ArithShift: '<S106>/BCM_emergencylightstatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 4);

      /* Saturate: '<S106>/BCM_emergencylightstatus_sat' */
      u0 = rtb_BCM_emergencylightstatus_L;
      rtb_BCM_emergencylightstatus_L = (int32_T)u0;

      /* SignalConversion: '<S105>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_FrontWashStatus = rtb_BCM_FrontWashStatus_sat;

      /* SignalConversion: '<S105>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_PassengerDoorLockStatus =
        rtb_BCM_PassengerDoorLockStatus;

      /* SignalConversion: '<S105>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_emergencylightstatus = rtb_BCM_emergencylightstatus_L;

      /* SignalConversion: '<S105>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_DriverDoorLockStatus = rtb_BCM_DriverDoorLockStatus_sa;

      /* SignalConversion: '<S105>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_PowerStatusFeedback = rtb_BCM_PowerStatusFeedback_sat;

      /* SignalConversion: '<S105>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_RearWiperStatus = rtb_BCM_RearWiperStatus_sat;

      /* SignalConversion: '<S105>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_FrontWiperStatus = rtb_BCM_FrontWiperStatus_sat;

      /* SignalConversion: '<S105>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_ReversePosition = rtb_BCM_ReversePosition_sat;

      /* SignalConversion: '<S105>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_TurnLightSwitchSts = rtb_BCM_TurnLightSwitchSts_sat;

      /* SignalConversion: '<S105>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_BuzzerWarningMode = rtb_BCM_BuzzerWarningMode_sat;

      /* SignalConversion: '<S105>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_SystemFailureFlag = rtb_BCM_SystemFailureFlag_sat;

      /* SignalConversion: '<S105>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_TurnIndicatorRight = rtb_BCM_TurnIndicatorRight_sat;

      /* SignalConversion: '<S105>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_LatchOverheatProtect = rtb_BCM_LatchOverheatProtect_sa;

      /* SignalConversion: '<S105>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_TurnIndicatorLeft = rtb_BCM_TurnIndicatorLeft_sat;

      /* SignalConversion: '<S105>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_HoodStatus = rtb_BCM_HoodStatus_sat;

      /* SignalConversion: '<S105>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_TrunkDoorStatus = rtb_BCM_TrunkDoorStatus_sat;

      /* SignalConversion: '<S105>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_RightRearDoorStatus = rtb_BCM_RightRearDoorStatus_sat;

      /* SignalConversion: '<S105>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_LeftRearDoorStatus = rtb_BCM_LeftRearDoorStatus_sat;

      /* SignalConversion: '<S105>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_PassengerDoorStatus = rtb_BCM_PassengerDoorStatus_sat;

      /* SignalConversion: '<S105>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_DriverDoorStatus = rtb_BCM_DriverDoorStatus_sat;
    }

    /* End of Outputs for SubSystem: '<S104>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S78>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF24RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf24looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_lw= 808;
    VCU_CS75_9_30_B.CANReceive_o5_m= 8;
    VCU_CS75_9_30_B.CANReceive_o2_m= ec_can_receive(1,24, CAN1BUF24RX);
    VCU_CS75_9_30_B.CANReceive_o4_a[0]= CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_a[1]= CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_a[2]= CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_a[3]= CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_a[4]= CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_a[5]= CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_a[6]= CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_a[7]= CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
  }

  /* Call the system: <S78>/ReceiveMessages */

  /* Output and update for function-call system: '<S78>/ReceiveMessages' */
  {
    int32_T rtb_LCM_ReverseLightSts_L;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S127>/Subsystem' incorporates:
     *  EnablePort: '<S128>/Enable'
     */
    if (VCU_CS75_9_30_B.CANReceive_o2_m > 0) {
      /* DataTypeConversion: '<S129>/LCM_LASSwitch_Convert' */
      rtb_LCM_ReverseLightSts_L = VCU_CS75_9_30_B.CANReceive_o4_a[2];

      /* S-Function (sfix_bitop): '<S129>/LCM_LASSwitch_L' */
      rtb_LCM_ReverseLightSts_L &= 3U;

      /* Saturate: '<S129>/LCM_LASSwitch_sat' */
      u0 = rtb_LCM_ReverseLightSts_L;
      rtb_LCM_ReverseLightSts_L = (int32_T)u0;

      /* SignalConversion: '<S128>/Signal Conversion' */
      VCU_CS75_9_30_B.LCM_DriveMode = 0.0;

      /* SignalConversion: '<S128>/Signal Conversion' */
      VCU_CS75_9_30_B.LCM_DRLSts = 0.0;

      /* SignalConversion: '<S128>/Signal Conversion' */
      VCU_CS75_9_30_B.LCM_LASSwitch = rtb_LCM_ReverseLightSts_L;

      /* SignalConversion: '<S128>/Signal Conversion' */
      VCU_CS75_9_30_B.LCM_RearRightTuningLightFaultSt = 0.0;

      /* SignalConversion: '<S128>/Signal Conversion' */
      VCU_CS75_9_30_B.LCM_RearLeftTuningLightFaultSts = 0.0;

      /* SignalConversion: '<S128>/Signal Conversion' */
      VCU_CS75_9_30_B.LCM_ReverseLightSts = 0.0;
    }

    /* End of Outputs for SubSystem: '<S127>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S79>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF25RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf25looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_h= 840;
    VCU_CS75_9_30_B.CANReceive_o5_a= 8;
    VCU_CS75_9_30_B.CANReceive_o2_j= ec_can_receive(1,25, CAN1BUF25RX);
    VCU_CS75_9_30_B.CANReceive_o4_o[0]= CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_o[1]= CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_o[2]= CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_o[3]= CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_o[4]= CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_o[5]= CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_o[6]= CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_o[7]= CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
  }

  /* Call the system: <S79>/ReceiveMessages */

  /* Output and update for function-call system: '<S79>/ReceiveMessages' */
  {
    int32_T rtb_BCM_UnlockSignal_L;
    int32_T rtb_BCM_DriveMode_sat;
    int32_T rtb_BCM_LockSignal_sat;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S136>/Subsystem' incorporates:
     *  EnablePort: '<S137>/Enable'
     */
    if (VCU_CS75_9_30_B.CANReceive_o2_j > 0) {
      /* DataTypeConversion: '<S138>/BCM_DriveMode_Convert' */
      rtb_BCM_UnlockSignal_L = VCU_CS75_9_30_B.CANReceive_o4_o[5];

      /* S-Function (sfix_bitop): '<S138>/BCM_DriveMode_L' */
      rtb_BCM_UnlockSignal_L &= 6U;

      /* ArithShift: '<S138>/BCM_DriveMode_S' */
      rtb_BCM_UnlockSignal_L = (int32_T)((uint32_T)rtb_BCM_UnlockSignal_L >> 1);

      /* Sum: '<S138>/BCM_DriveMode_Ad' */
      rtb_BCM_DriveMode_sat = rtb_BCM_UnlockSignal_L;

      /* Saturate: '<S138>/BCM_DriveMode_sat' */
      u0 = rtb_BCM_DriveMode_sat;
      rtb_BCM_DriveMode_sat = (int32_T)u0;

      /* DataTypeConversion: '<S138>/BCM_LockSignal_Convert' */
      rtb_BCM_UnlockSignal_L = VCU_CS75_9_30_B.CANReceive_o4_o[5];

      /* S-Function (sfix_bitop): '<S138>/BCM_LockSignal_L' */
      rtb_BCM_UnlockSignal_L &= 24U;

      /* ArithShift: '<S138>/BCM_LockSignal_S' */
      rtb_BCM_UnlockSignal_L = (int32_T)((uint32_T)rtb_BCM_UnlockSignal_L >> 3);

      /* Sum: '<S138>/BCM_LockSignal_Ad' */
      rtb_BCM_LockSignal_sat = rtb_BCM_UnlockSignal_L;

      /* Saturate: '<S138>/BCM_LockSignal_sat' */
      u0 = rtb_BCM_LockSignal_sat;
      rtb_BCM_LockSignal_sat = (int32_T)u0;

      /* DataTypeConversion: '<S138>/BCM_UnlockSignal_Convert' */
      rtb_BCM_UnlockSignal_L = VCU_CS75_9_30_B.CANReceive_o4_o[5];

      /* S-Function (sfix_bitop): '<S138>/BCM_UnlockSignal_L' */
      rtb_BCM_UnlockSignal_L &= 96U;

      /* ArithShift: '<S138>/BCM_UnlockSignal_S' */
      rtb_BCM_UnlockSignal_L = (int32_T)((uint32_T)rtb_BCM_UnlockSignal_L >> 5);

      /* Saturate: '<S138>/BCM_UnlockSignal_sat' */
      u0 = rtb_BCM_UnlockSignal_L;
      rtb_BCM_UnlockSignal_L = (int32_T)u0;

      /* SignalConversion: '<S137>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_DriveMode_a = rtb_BCM_DriveMode_sat;

      /* SignalConversion: '<S137>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_LockSignal = rtb_BCM_LockSignal_sat;

      /* SignalConversion: '<S137>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_UnlockSignal = rtb_BCM_UnlockSignal_L;
    }

    /* End of Outputs for SubSystem: '<S136>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S80>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF26RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf26looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_g= 991;
    VCU_CS75_9_30_B.CANReceive_o5_c= 8;
    VCU_CS75_9_30_B.CANReceive_o2_p= ec_can_receive(1,26, CAN1BUF26RX);
    VCU_CS75_9_30_B.CANReceive_o4_hm[0]= CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_hm[1]= CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_hm[2]= CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_hm[3]= CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_hm[4]= CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_hm[5]= CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_hm[6]= CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_hm[7]= CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
  }

  /* Call the system: <S80>/ReceiveMessages */

  /* Output and update for function-call system: '<S80>/ReceiveMessages' */
  {
    int32_T rtb_BCM_RollingCounter_L;
    int32_T rtb_BCM_AmbientLightColorFeedba;
    int32_T rtb_BCM_DriveModeFeedback_sat;
    int32_T rtb_BCM_DriveModeStatus_sat;
    int32_T rtb_BCM_EPSTorqueModeFeedback_s;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S142>/Subsystem' incorporates:
     *  EnablePort: '<S143>/Enable'
     */
    if (VCU_CS75_9_30_B.CANReceive_o2_p > 0) {
      /* DataTypeConversion: '<S144>/BCM_AmbientLightColorFeedback_Convert' */
      rtb_BCM_RollingCounter_L = VCU_CS75_9_30_B.CANReceive_o4_hm[3];

      /* Sum: '<S144>/BCM_AmbientLightColorFeedback_Ad' */
      rtb_BCM_AmbientLightColorFeedba = rtb_BCM_RollingCounter_L;

      /* Saturate: '<S144>/BCM_AmbientLightColorFeedback_sat' */
      u0 = rtb_BCM_AmbientLightColorFeedba;
      rtb_BCM_AmbientLightColorFeedba = (int32_T)u0;

      /* DataTypeConversion: '<S144>/BCM_DriveModeFeedback_Convert' */
      rtb_BCM_RollingCounter_L = VCU_CS75_9_30_B.CANReceive_o4_hm[2];

      /* S-Function (sfix_bitop): '<S144>/BCM_DriveModeFeedback_L' */
      rtb_BCM_RollingCounter_L &= 48U;

      /* ArithShift: '<S144>/BCM_DriveModeFeedback_S' */
      rtb_BCM_RollingCounter_L = (int32_T)((uint32_T)rtb_BCM_RollingCounter_L >>
        4);

      /* Sum: '<S144>/BCM_DriveModeFeedback_Ad' */
      rtb_BCM_DriveModeFeedback_sat = rtb_BCM_RollingCounter_L;

      /* Saturate: '<S144>/BCM_DriveModeFeedback_sat' */
      u0 = rtb_BCM_DriveModeFeedback_sat;
      rtb_BCM_DriveModeFeedback_sat = (int32_T)u0;

      /* DataTypeConversion: '<S144>/BCM_DriveModeStatus_Convert' */
      rtb_BCM_RollingCounter_L = VCU_CS75_9_30_B.CANReceive_o4_hm[2];

      /* S-Function (sfix_bitop): '<S144>/BCM_DriveModeStatus_L' */
      rtb_BCM_RollingCounter_L &= 15U;

      /* Sum: '<S144>/BCM_DriveModeStatus_Ad' */
      rtb_BCM_DriveModeStatus_sat = rtb_BCM_RollingCounter_L;

      /* Saturate: '<S144>/BCM_DriveModeStatus_sat' */
      u0 = rtb_BCM_DriveModeStatus_sat;
      rtb_BCM_DriveModeStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S144>/BCM_EPSTorqueModeFeedback_Convert' */
      rtb_BCM_RollingCounter_L = VCU_CS75_9_30_B.CANReceive_o4_hm[2];

      /* S-Function (sfix_bitop): '<S144>/BCM_EPSTorqueModeFeedback_L' */
      rtb_BCM_RollingCounter_L &= 192U;

      /* ArithShift: '<S144>/BCM_EPSTorqueModeFeedback_S' */
      rtb_BCM_RollingCounter_L = (int32_T)((uint32_T)rtb_BCM_RollingCounter_L >>
        6);

      /* Sum: '<S144>/BCM_EPSTorqueModeFeedback_Ad' */
      rtb_BCM_EPSTorqueModeFeedback_s = rtb_BCM_RollingCounter_L;

      /* Saturate: '<S144>/BCM_EPSTorqueModeFeedback_sat' */
      u0 = rtb_BCM_EPSTorqueModeFeedback_s;
      rtb_BCM_EPSTorqueModeFeedback_s = (int32_T)u0;

      /* DataTypeConversion: '<S144>/BCM_EPSTorqueMode_Convert' */
      rtb_BCM_RollingCounter_L = VCU_CS75_9_30_B.CANReceive_o4_hm[1];

      /* S-Function (sfix_bitop): '<S144>/BCM_EPSTorqueMode_L' */
      rtb_BCM_RollingCounter_L &= 6U;

      /* ArithShift: '<S144>/BCM_EPSTorqueMode_S' */
      rtb_BCM_RollingCounter_L = (int32_T)((uint32_T)rtb_BCM_RollingCounter_L >>
        1);

      /* Saturate: '<S144>/BCM_EPSTorqueMode_sat' */
      u0 = rtb_BCM_RollingCounter_L;
      rtb_BCM_RollingCounter_L = (int32_T)u0;

      /* SignalConversion: '<S143>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_DriveMode = 0.0;

      /* SignalConversion: '<S143>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_EPSTorqueMode = rtb_BCM_RollingCounter_L;

      /* SignalConversion: '<S143>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_DriveModeStatus = rtb_BCM_DriveModeStatus_sat;

      /* SignalConversion: '<S143>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_DriveModeFeedback = rtb_BCM_DriveModeFeedback_sat;

      /* SignalConversion: '<S143>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_EPSTorqueModeFeedback =
        rtb_BCM_EPSTorqueModeFeedback_s;

      /* SignalConversion: '<S143>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_AmbientLightColorFeedback =
        rtb_BCM_AmbientLightColorFeedba;

      /* SignalConversion: '<S143>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_RollingCounter = 0.0;

      /* SignalConversion: '<S143>/Signal Conversion' */
      VCU_CS75_9_30_B.BCM_CRC_Checksum = 0.0;
    }

    /* End of Outputs for SubSystem: '<S142>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S81>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF0RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf0looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_j= 517;
    VCU_CS75_9_30_B.CANReceive_o5_im= 8;
    VCU_CS75_9_30_B.CANReceive_o2_g= ec_can_receive(1,0, CAN1BUF0RX);
    VCU_CS75_9_30_B.CANReceive_o4_f[0]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_f[1]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_f[2]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_f[3]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_f[4]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_f[5]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_f[6]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_f[7]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
  }

  /* Call the system: <S81>/ReceiveMessages */

  /* Output and update for function-call system: '<S81>/ReceiveMessages' */
  {
    int32_T rtb_EMS_TorqFailure_L;
    int32_T rtb_EMS_ESPTorqReuestAvailabili;
    int32_T rtb_EMS_CheckSum_205_sat;
    real_T rtb_EMS_FrictionalTorq_sat;
    real_T rtb_EMS_IndicatedDriverReqTorq_;
    real_T rtb_EMS_IndicatedRealEngTorq_sa;
    real_T rtb_EMS_TorqFailurecv;
    int32_T rtb_EMS_RollingCounter_id205_sa;

    /* Outputs for Enabled SubSystem: '<S153>/Subsystem' incorporates:
     *  EnablePort: '<S154>/Enable'
     */
    if (VCU_CS75_9_30_B.CANReceive_o2_g > 0) {
      /* DataTypeConversion: '<S155>/EMS_CheckSum_205_Convert' */
      rtb_EMS_TorqFailure_L = VCU_CS75_9_30_B.CANReceive_o4_f[7];

      /* S-Function (sfix_bitop): '<S155>/EMS_CheckSum_205_L' */
      rtb_EMS_TorqFailure_L &= 240U;

      /* ArithShift: '<S155>/EMS_CheckSum_205_S' */
      rtb_EMS_TorqFailure_L = (int32_T)((uint32_T)rtb_EMS_TorqFailure_L >> 4);

      /* DataTypeConversion: '<S155>/EMS_CheckSum_205cv' */
      rtb_EMS_ESPTorqReuestAvailabili = rtb_EMS_TorqFailure_L;

      /* Sum: '<S155>/EMS_CheckSum_205_Ad' */
      rtb_EMS_CheckSum_205_sat = rtb_EMS_ESPTorqReuestAvailabili;

      /* Saturate: '<S155>/EMS_CheckSum_205_sat' */
      rtb_EMS_TorqFailurecv = rtb_EMS_CheckSum_205_sat;
      rtb_EMS_CheckSum_205_sat = (int32_T)rtb_EMS_TorqFailurecv;

      /* DataTypeConversion: '<S155>/EMS_ESPTorqReuestAvailability_Convert' */
      rtb_EMS_TorqFailure_L = VCU_CS75_9_30_B.CANReceive_o4_f[0];

      /* S-Function (sfix_bitop): '<S155>/EMS_ESPTorqReuestAvailability_L' */
      rtb_EMS_TorqFailure_L &= 2U;

      /* ArithShift: '<S155>/EMS_ESPTorqReuestAvailability_S' */
      rtb_EMS_TorqFailure_L = (int32_T)((uint32_T)rtb_EMS_TorqFailure_L >> 1);

      /* Saturate: '<S155>/EMS_ESPTorqReuestAvailability_sat' */
      rtb_EMS_TorqFailurecv = rtb_EMS_TorqFailure_L;
      rtb_EMS_ESPTorqReuestAvailabili = (int32_T)rtb_EMS_TorqFailurecv;

      /* Product: '<S155>/EMS_FrictionalTorqinput4_P' incorporates:
       *  Constant: '<S155>/EMS_FrictionalTorqinput4_C'
       */
      rtb_EMS_FrictionalTorq_sat = (real_T)VCU_CS75_9_30_B.CANReceive_o4_f[3] *
        256.0;

      /* Sum: '<S155>/EMS_FrictionalTorqinput4_Ad' */
      rtb_EMS_IndicatedDriverReqTorq_ = rtb_EMS_FrictionalTorq_sat + (real_T)
        VCU_CS75_9_30_B.CANReceive_o4_f[4];

      /* DataTypeConversion: '<S155>/EMS_FrictionalTorq_Convert' */
      rtb_EMS_TorqFailure_L = (int32_T)rtb_EMS_IndicatedDriverReqTorq_;

      /* DataTypeConversion: '<S155>/EMS_FrictionalTorqcv' */
      rtb_EMS_IndicatedDriverReqTorq_ = rtb_EMS_TorqFailure_L;

      /* Gain: '<S155>/EMS_FrictionalTorq_F' */
      rtb_EMS_IndicatedDriverReqTorq_ *= 0.001526;

      /* Sum: '<S155>/EMS_FrictionalTorq_Ad' */
      rtb_EMS_FrictionalTorq_sat = rtb_EMS_IndicatedDriverReqTorq_;

      /* Saturate: '<S155>/EMS_FrictionalTorq_sat' */
      if (rtb_EMS_FrictionalTorq_sat > 99.9988) {
        rtb_EMS_FrictionalTorq_sat = 99.9988;
      }

      /* End of Saturate: '<S155>/EMS_FrictionalTorq_sat' */

      /* Product: '<S155>/EMS_IndicatedDriverReqTorqinput2_P' incorporates:
       *  Constant: '<S155>/EMS_IndicatedDriverReqTorqinput2_C'
       */
      rtb_EMS_IndicatedDriverReqTorq_ = (real_T)VCU_CS75_9_30_B.CANReceive_o4_f
        [1] * 256.0;

      /* Sum: '<S155>/EMS_IndicatedDriverReqTorqinput2_Ad' */
      rtb_EMS_IndicatedRealEngTorq_sa = rtb_EMS_IndicatedDriverReqTorq_ +
        (real_T)VCU_CS75_9_30_B.CANReceive_o4_f[2];

      /* DataTypeConversion: '<S155>/EMS_IndicatedDriverReqTorq_Convert' */
      rtb_EMS_TorqFailure_L = (int32_T)rtb_EMS_IndicatedRealEngTorq_sa;

      /* DataTypeConversion: '<S155>/EMS_IndicatedDriverReqTorqcv' */
      rtb_EMS_IndicatedRealEngTorq_sa = rtb_EMS_TorqFailure_L;

      /* Gain: '<S155>/EMS_IndicatedDriverReqTorq_F' */
      rtb_EMS_IndicatedRealEngTorq_sa *= 0.001526;

      /* Sum: '<S155>/EMS_IndicatedDriverReqTorq_Ad' */
      rtb_EMS_IndicatedDriverReqTorq_ = rtb_EMS_IndicatedRealEngTorq_sa;

      /* Saturate: '<S155>/EMS_IndicatedDriverReqTorq_sat' */
      if (rtb_EMS_IndicatedDriverReqTorq_ > 99.9988) {
        rtb_EMS_IndicatedDriverReqTorq_ = 99.9988;
      }

      /* End of Saturate: '<S155>/EMS_IndicatedDriverReqTorq_sat' */

      /* Product: '<S155>/EMS_IndicatedRealEngTorqinput6_P' incorporates:
       *  Constant: '<S155>/EMS_IndicatedRealEngTorqinput6_C'
       */
      rtb_EMS_IndicatedRealEngTorq_sa = (real_T)VCU_CS75_9_30_B.CANReceive_o4_f
        [5] * 256.0;

      /* Sum: '<S155>/EMS_IndicatedRealEngTorqinput6_Ad' */
      rtb_EMS_TorqFailurecv = rtb_EMS_IndicatedRealEngTorq_sa + (real_T)
        VCU_CS75_9_30_B.CANReceive_o4_f[6];

      /* DataTypeConversion: '<S155>/EMS_IndicatedRealEngTorq_Convert' */
      rtb_EMS_TorqFailure_L = (int32_T)rtb_EMS_TorqFailurecv;

      /* DataTypeConversion: '<S155>/EMS_IndicatedRealEngTorqcv' */
      rtb_EMS_TorqFailurecv = rtb_EMS_TorqFailure_L;

      /* Gain: '<S155>/EMS_IndicatedRealEngTorq_F' */
      rtb_EMS_TorqFailurecv *= 0.001526;

      /* Sum: '<S155>/EMS_IndicatedRealEngTorq_Ad' */
      rtb_EMS_IndicatedRealEngTorq_sa = rtb_EMS_TorqFailurecv;

      /* Saturate: '<S155>/EMS_IndicatedRealEngTorq_sat' */
      if (rtb_EMS_IndicatedRealEngTorq_sa > 99.9988) {
        rtb_EMS_IndicatedRealEngTorq_sa = 99.9988;
      }

      /* End of Saturate: '<S155>/EMS_IndicatedRealEngTorq_sat' */

      /* DataTypeConversion: '<S155>/EMS_RollingCounter_id205_Convert' */
      rtb_EMS_TorqFailure_L = VCU_CS75_9_30_B.CANReceive_o4_f[7];

      /* S-Function (sfix_bitop): '<S155>/EMS_RollingCounter_id205_L' */
      rtb_EMS_TorqFailure_L &= 15U;

      /* DataTypeConversion: '<S155>/EMS_RollingCounter_id205cv' */
      rtb_EMS_TorqFailurecv = rtb_EMS_TorqFailure_L;

      /* Sum: '<S155>/EMS_RollingCounter_id205_Ad' */
      rtb_EMS_RollingCounter_id205_sa = (int32_T)rtb_EMS_TorqFailurecv;

      /* Saturate: '<S155>/EMS_RollingCounter_id205_sat' */
      rtb_EMS_TorqFailurecv = rtb_EMS_RollingCounter_id205_sa;
      rtb_EMS_RollingCounter_id205_sa = (int32_T)rtb_EMS_TorqFailurecv;

      /* DataTypeConversion: '<S155>/EMS_TorqFailure_Convert' */
      rtb_EMS_TorqFailure_L = VCU_CS75_9_30_B.CANReceive_o4_f[0];

      /* S-Function (sfix_bitop): '<S155>/EMS_TorqFailure_L' */
      rtb_EMS_TorqFailure_L &= 128U;

      /* ArithShift: '<S155>/EMS_TorqFailure_S' */
      rtb_EMS_TorqFailure_L = (int32_T)((uint32_T)rtb_EMS_TorqFailure_L >> 7);

      /* DataTypeConversion: '<S155>/EMS_TorqFailurecv' */
      rtb_EMS_TorqFailurecv = rtb_EMS_TorqFailure_L;

      /* SignalConversion: '<S154>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_ESPTorqReuestAvailability =
        rtb_EMS_ESPTorqReuestAvailabili;

      /* SignalConversion: '<S154>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_TorqFailure = rtb_EMS_TorqFailurecv;

      /* SignalConversion: '<S154>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_IndicatedDriverReqTorq =
        rtb_EMS_IndicatedDriverReqTorq_;

      /* SignalConversion: '<S154>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_FrictionalTorq_n = rtb_EMS_FrictionalTorq_sat;

      /* SignalConversion: '<S154>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_IndicatedRealEngTorq = rtb_EMS_IndicatedRealEngTorq_sa;

      /* SignalConversion: '<S154>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_RollingCounter_id205 = rtb_EMS_RollingCounter_id205_sa;

      /* SignalConversion: '<S154>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_CheckSum_205 = rtb_EMS_CheckSum_205_sat;
    }

    /* End of Outputs for SubSystem: '<S153>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S82>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF1RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf1looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_e= 597;
    VCU_CS75_9_30_B.CANReceive_o5_k= 8;
    VCU_CS75_9_30_B.CANReceive_o2_l= ec_can_receive(1,1, CAN1BUF1RX);
    VCU_CS75_9_30_B.CANReceive_o4_j[0]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_j[1]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_j[2]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_j[3]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_j[4]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_j[5]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_j[6]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_j[7]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
  }

  /* Call the system: <S82>/ReceiveMessages */

  /* Output and update for function-call system: '<S82>/ReceiveMessages' */
  {
    int32_T rtb_EMS_RollingCounter_id255_L;
    real_T rtb_EMS_CheckSum_255_sat;
    real_T rtb_EMS_AccPedal_sat;
    int32_T rtb_EMS_AccpedelError_sat;
    real_T rtb_EMS_EngineSpeed_sat;
    int32_T rtb_EMS_EngineSpeedError_sat;
    real_T rtb_EMS_RollingCounter_id255cv;

    /* Outputs for Enabled SubSystem: '<S163>/Subsystem' incorporates:
     *  EnablePort: '<S164>/Enable'
     */
    if (VCU_CS75_9_30_B.CANReceive_o2_l > 0) {
      /* DataTypeConversion: '<S165>/EMS_AccPedal_Convert' */
      rtb_EMS_RollingCounter_id255_L = VCU_CS75_9_30_B.CANReceive_o4_j[5];

      /* DataTypeConversion: '<S165>/EMS_AccPedalcv' */
      rtb_EMS_CheckSum_255_sat = rtb_EMS_RollingCounter_id255_L;

      /* Gain: '<S165>/EMS_AccPedal_F' */
      rtb_EMS_CheckSum_255_sat *= 0.392;

      /* Sum: '<S165>/EMS_AccPedal_Ad' */
      rtb_EMS_AccPedal_sat = rtb_EMS_CheckSum_255_sat;

      /* Saturate: '<S165>/EMS_AccPedal_sat' */
      if (rtb_EMS_AccPedal_sat > 99.568) {
        rtb_EMS_AccPedal_sat = 99.568;
      }

      /* End of Saturate: '<S165>/EMS_AccPedal_sat' */

      /* DataTypeConversion: '<S165>/EMS_AccpedelError_Convert' */
      rtb_EMS_RollingCounter_id255_L = VCU_CS75_9_30_B.CANReceive_o4_j[1];

      /* S-Function (sfix_bitop): '<S165>/EMS_AccpedelError_L' */
      rtb_EMS_RollingCounter_id255_L &= 4U;

      /* ArithShift: '<S165>/EMS_AccpedelError_S' */
      rtb_EMS_RollingCounter_id255_L = (int32_T)((uint32_T)
        rtb_EMS_RollingCounter_id255_L >> 2);

      /* DataTypeConversion: '<S165>/EMS_AccpedelErrorcv' */
      rtb_EMS_CheckSum_255_sat = rtb_EMS_RollingCounter_id255_L;

      /* Sum: '<S165>/EMS_AccpedelError_Ad' */
      rtb_EMS_AccpedelError_sat = (int32_T)rtb_EMS_CheckSum_255_sat;

      /* Saturate: '<S165>/EMS_AccpedelError_sat' */
      rtb_EMS_EngineSpeed_sat = rtb_EMS_AccpedelError_sat;
      rtb_EMS_AccpedelError_sat = (int32_T)rtb_EMS_EngineSpeed_sat;

      /* DataTypeConversion: '<S165>/EMS_BrakePedalStatus_Convert' */
      rtb_EMS_RollingCounter_id255_L = VCU_CS75_9_30_B.CANReceive_o4_j[0];

      /* S-Function (sfix_bitop): '<S165>/EMS_BrakePedalStatus_L' */
      rtb_EMS_RollingCounter_id255_L &= 192U;

      /* ArithShift: '<S165>/EMS_BrakePedalStatus_S' */
      rtb_EMS_RollingCounter_id255_L = (int32_T)((uint32_T)
        rtb_EMS_RollingCounter_id255_L >> 6);

      /* DataTypeConversion: '<S165>/EMS_BrakePedalStatuscv' */
      rtb_EMS_CheckSum_255_sat = rtb_EMS_RollingCounter_id255_L;

      /* Sum: '<S165>/EMS_BrakePedalStatus_Ad' */
      rtb_EMS_EngineSpeed_sat = rtb_EMS_CheckSum_255_sat;

      /* Saturate: '<S165>/EMS_BrakePedalStatus_sat' */
      EMS_BrakePedalStatus = rtb_EMS_EngineSpeed_sat;

      /* DataTypeConversion: '<S165>/EMS_CheckSum_255_Convert' */
      rtb_EMS_RollingCounter_id255_L = VCU_CS75_9_30_B.CANReceive_o4_j[7];

      /* S-Function (sfix_bitop): '<S165>/EMS_CheckSum_255_L' */
      rtb_EMS_RollingCounter_id255_L &= 240U;

      /* ArithShift: '<S165>/EMS_CheckSum_255_S' */
      rtb_EMS_RollingCounter_id255_L = (int32_T)((uint32_T)
        rtb_EMS_RollingCounter_id255_L >> 4);

      /* DataTypeConversion: '<S165>/EMS_CheckSum_255cv' */
      rtb_EMS_EngineSpeed_sat = rtb_EMS_RollingCounter_id255_L;

      /* Sum: '<S165>/EMS_CheckSum_255_Ad' */
      rtb_EMS_CheckSum_255_sat = rtb_EMS_EngineSpeed_sat;

      /* DataTypeConversion: '<S165>/EMS_EngineSpeedError_Convert' */
      rtb_EMS_RollingCounter_id255_L = VCU_CS75_9_30_B.CANReceive_o4_j[1];

      /* S-Function (sfix_bitop): '<S165>/EMS_EngineSpeedError_L' */
      rtb_EMS_RollingCounter_id255_L &= 16U;

      /* ArithShift: '<S165>/EMS_EngineSpeedError_S' */
      rtb_EMS_RollingCounter_id255_L = (int32_T)((uint32_T)
        rtb_EMS_RollingCounter_id255_L >> 4);

      /* DataTypeConversion: '<S165>/EMS_EngineSpeedErrorcv' */
      rtb_EMS_EngineSpeed_sat = rtb_EMS_RollingCounter_id255_L;

      /* Sum: '<S165>/EMS_EngineSpeedError_Ad' */
      rtb_EMS_EngineSpeedError_sat = (int32_T)rtb_EMS_EngineSpeed_sat;

      /* Saturate: '<S165>/EMS_EngineSpeedError_sat' */
      rtb_EMS_EngineSpeed_sat = rtb_EMS_EngineSpeedError_sat;
      rtb_EMS_EngineSpeedError_sat = (int32_T)rtb_EMS_EngineSpeed_sat;

      /* Product: '<S165>/EMS_EngineSpeedinput3_P' incorporates:
       *  Constant: '<S165>/EMS_EngineSpeedinput3_C'
       */
      rtb_EMS_EngineSpeed_sat = (real_T)VCU_CS75_9_30_B.CANReceive_o4_j[2] *
        256.0;

      /* Sum: '<S165>/EMS_EngineSpeedinput3_Ad' */
      rtb_EMS_RollingCounter_id255cv = rtb_EMS_EngineSpeed_sat + (real_T)
        VCU_CS75_9_30_B.CANReceive_o4_j[3];

      /* DataTypeConversion: '<S165>/EMS_EngineSpeed_Convert' */
      rtb_EMS_RollingCounter_id255_L = (int32_T)rtb_EMS_RollingCounter_id255cv;

      /* DataTypeConversion: '<S165>/EMS_EngineSpeedcv' */
      rtb_EMS_RollingCounter_id255cv = rtb_EMS_RollingCounter_id255_L;

      /* Gain: '<S165>/EMS_EngineSpeed_F' */
      rtb_EMS_RollingCounter_id255cv *= 0.25;

      /* Sum: '<S165>/EMS_EngineSpeed_Ad' */
      rtb_EMS_EngineSpeed_sat = rtb_EMS_RollingCounter_id255cv;

      /* Saturate: '<S165>/EMS_EngineSpeed_sat' */
      if (rtb_EMS_EngineSpeed_sat > 16383.5) {
        rtb_EMS_EngineSpeed_sat = 16383.5;
      }

      /* End of Saturate: '<S165>/EMS_EngineSpeed_sat' */

      /* DataTypeConversion: '<S165>/EMS_RollingCounter_id255_Convert' */
      rtb_EMS_RollingCounter_id255_L = VCU_CS75_9_30_B.CANReceive_o4_j[7];

      /* S-Function (sfix_bitop): '<S165>/EMS_RollingCounter_id255_L' */
      rtb_EMS_RollingCounter_id255_L &= 15U;

      /* DataTypeConversion: '<S165>/EMS_RollingCounter_id255cv' */
      rtb_EMS_RollingCounter_id255cv = rtb_EMS_RollingCounter_id255_L;

      /* SignalConversion: '<S164>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_BrakePedalStatus_h = EMS_BrakePedalStatus;

      /* SignalConversion: '<S164>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_AccpedelError = rtb_EMS_AccpedelError_sat;

      /* SignalConversion: '<S164>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_EngineSpeedError = rtb_EMS_EngineSpeedError_sat;

      /* SignalConversion: '<S164>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_EngineSpeed_c = rtb_EMS_EngineSpeed_sat;

      /* SignalConversion: '<S164>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_AccPedal = rtb_EMS_AccPedal_sat;

      /* SignalConversion: '<S164>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_RollingCounter_id255 = rtb_EMS_RollingCounter_id255cv;

      /* SignalConversion: '<S164>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_CheckSum_255 = rtb_EMS_CheckSum_255_sat;
    }

    /* End of Outputs for SubSystem: '<S163>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S83>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF2RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf2looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_k= 613;
    VCU_CS75_9_30_B.CANReceive_o5_n= 8;
    VCU_CS75_9_30_B.CANReceive_o2_f= ec_can_receive(1,2, CAN1BUF2RX);
    VCU_CS75_9_30_B.CANReceive_o4_fw[0]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_fw[1]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_fw[2]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_fw[3]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_fw[4]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_fw[5]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_fw[6]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_fw[7]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
  }

  /* Call the system: <S83>/ReceiveMessages */

  /* Output and update for function-call system: '<S83>/ReceiveMessages' */
  {
    int32_T rtb_EMS_TorqueConstant_L;
    real_T rtb_EMS_TorqueConstant_F;
    int32_T rtb_EMS_EngineStatus_sat;
    real_T rtb_EMS_FullLoadIndicatedTorq_s;
    int32_T rtb_EMS_RollingCounter_id265_sa;

    /* Outputs for Enabled SubSystem: '<S173>/Subsystem' incorporates:
     *  EnablePort: '<S174>/Enable'
     */
    if (VCU_CS75_9_30_B.CANReceive_o2_f > 0) {
      /* DataTypeConversion: '<S175>/EMS_EngineStatus_Convert' */
      rtb_EMS_TorqueConstant_L = VCU_CS75_9_30_B.CANReceive_o4_fw[7];

      /* S-Function (sfix_bitop): '<S175>/EMS_EngineStatus_L' */
      rtb_EMS_TorqueConstant_L &= 192U;

      /* ArithShift: '<S175>/EMS_EngineStatus_S' */
      rtb_EMS_TorqueConstant_L = (int32_T)((uint32_T)rtb_EMS_TorqueConstant_L >>
        6);

      /* DataTypeConversion: '<S175>/EMS_EngineStatuscv' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_TorqueConstant_L;

      /* Sum: '<S175>/EMS_EngineStatus_Ad' */
      rtb_EMS_EngineStatus_sat = (int32_T)rtb_EMS_TorqueConstant_F;

      /* Saturate: '<S175>/EMS_EngineStatus_sat' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_EngineStatus_sat;
      rtb_EMS_EngineStatus_sat = (int32_T)rtb_EMS_TorqueConstant_F;

      /* DataTypeConversion: '<S175>/EMS_FullLoadIndicatedTorq_Convert' */
      rtb_EMS_TorqueConstant_L = VCU_CS75_9_30_B.CANReceive_o4_fw[2];

      /* DataTypeConversion: '<S175>/EMS_FullLoadIndicatedTorqcv' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_TorqueConstant_L;

      /* Gain: '<S175>/EMS_FullLoadIndicatedTorq_F' */
      rtb_EMS_TorqueConstant_F *= 0.392;

      /* Sum: '<S175>/EMS_FullLoadIndicatedTorq_Ad' */
      rtb_EMS_FullLoadIndicatedTorq_s = rtb_EMS_TorqueConstant_F;

      /* Saturate: '<S175>/EMS_FullLoadIndicatedTorq_sat' */
      if (rtb_EMS_FullLoadIndicatedTorq_s > 99.96) {
        rtb_EMS_FullLoadIndicatedTorq_s = 99.96;
      }

      /* End of Saturate: '<S175>/EMS_FullLoadIndicatedTorq_sat' */

      /* DataTypeConversion: '<S175>/EMS_RollingCounter_id265_Convert' */
      rtb_EMS_TorqueConstant_L = VCU_CS75_9_30_B.CANReceive_o4_fw[7];

      /* S-Function (sfix_bitop): '<S175>/EMS_RollingCounter_id265_L' */
      rtb_EMS_TorqueConstant_L &= 15U;

      /* DataTypeConversion: '<S175>/EMS_RollingCounter_id265cv' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_TorqueConstant_L;

      /* Sum: '<S175>/EMS_RollingCounter_id265_Ad' */
      rtb_EMS_RollingCounter_id265_sa = (int32_T)rtb_EMS_TorqueConstant_F;

      /* Saturate: '<S175>/EMS_RollingCounter_id265_sat' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_RollingCounter_id265_sa;
      rtb_EMS_RollingCounter_id265_sa = (int32_T)rtb_EMS_TorqueConstant_F;

      /* DataTypeConversion: '<S175>/EMS_TorqueConstant_Convert' */
      rtb_EMS_TorqueConstant_L = VCU_CS75_9_30_B.CANReceive_o4_fw[6];

      /* DataTypeConversion: '<S175>/EMS_TorqueConstantcv' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_TorqueConstant_L;

      /* Gain: '<S175>/EMS_TorqueConstant_F' */
      rtb_EMS_TorqueConstant_F *= 10.0;

      /* Saturate: '<S175>/EMS_TorqueConstant_sat' */
      if (rtb_EMS_TorqueConstant_F > 2540.0) {
        rtb_EMS_TorqueConstant_F = 2540.0;
      }

      /* End of Saturate: '<S175>/EMS_TorqueConstant_sat' */

      /* SignalConversion: '<S174>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_FullLoadIndicatedTorq =
        rtb_EMS_FullLoadIndicatedTorq_s;

      /* SignalConversion: '<S174>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_TorqueConstant_l = rtb_EMS_TorqueConstant_F;

      /* SignalConversion: '<S174>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_RollingCounter_id265 = rtb_EMS_RollingCounter_id265_sa;

      /* SignalConversion: '<S174>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_EngineStatus_j = rtb_EMS_EngineStatus_sat;
    }

    /* End of Outputs for SubSystem: '<S173>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S84>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF3RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf3looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_kw= 630;
    VCU_CS75_9_30_B.CANReceive_o5_al= 8;
    VCU_CS75_9_30_B.CANReceive_o2_i= ec_can_receive(1,3, CAN1BUF3RX);
    VCU_CS75_9_30_B.CANReceive_o4_jj[0]= CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_jj[1]= CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_jj[2]= CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_jj[3]= CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_jj[4]= CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_jj[5]= CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_jj[6]= CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_jj[7]= CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
  }

  /* Call the system: <S84>/ReceiveMessages */

  /* Output and update for function-call system: '<S84>/ReceiveMessages' */
  {
    int32_T rtb_EMS_RealAccPedal_Convert;
    real_T rtb_EMS_RealAccPedal_F;

    /* Outputs for Enabled SubSystem: '<S180>/Subsystem' incorporates:
     *  EnablePort: '<S181>/Enable'
     */
    if (VCU_CS75_9_30_B.CANReceive_o2_i > 0) {
      /* DataTypeConversion: '<S182>/EMS_RealAccPedal_Convert' */
      rtb_EMS_RealAccPedal_Convert = VCU_CS75_9_30_B.CANReceive_o4_jj[2];

      /* DataTypeConversion: '<S182>/EMS_RealAccPedalcv' */
      rtb_EMS_RealAccPedal_F = rtb_EMS_RealAccPedal_Convert;

      /* Gain: '<S182>/EMS_RealAccPedal_F' */
      rtb_EMS_RealAccPedal_F *= 0.392;

      /* Saturate: '<S182>/EMS_RealAccPedal_sat' */
      if (rtb_EMS_RealAccPedal_F > 99.96) {
        rtb_EMS_RealAccPedal_F = 99.96;
      }

      /* End of Saturate: '<S182>/EMS_RealAccPedal_sat' */

      /* SignalConversion: '<S181>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_RealAccPedal = rtb_EMS_RealAccPedal_F;
    }

    /* End of Outputs for SubSystem: '<S180>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S85>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF4RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf4looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_c= 598;
    VCU_CS75_9_30_B.CANReceive_o5_j= 8;
    VCU_CS75_9_30_B.CANReceive_o2_n= ec_can_receive(1,4, CAN1BUF4RX);
    VCU_CS75_9_30_B.CANReceive_o4_om[0]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_om[1]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_om[2]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_om[3]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_om[4]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_om[5]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_om[6]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_om[7]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
  }

  /* Call the system: <S85>/ReceiveMessages */

  /* Output and update for function-call system: '<S85>/ReceiveMessages' */
  {
    int32_T rtb_EPB_Status_L;
    int32_T rtb_EPB_Checksum_sat;
    int32_T rtb_EPB_FailStatus_sat;
    int32_T rtb_EPB_FailureLamp_sat;
    int32_T rtb_EPB_FunctionLamp_sat;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S184>/Subsystem' incorporates:
     *  EnablePort: '<S185>/Enable'
     */
    if (VCU_CS75_9_30_B.CANReceive_o2_n > 0) {
      /* DataTypeConversion: '<S186>/EPB_Checksum_Convert' */
      rtb_EPB_Status_L = VCU_CS75_9_30_B.CANReceive_o4_om[7];

      /* Sum: '<S186>/EPB_Checksum_Ad' */
      rtb_EPB_Checksum_sat = rtb_EPB_Status_L;

      /* Saturate: '<S186>/EPB_Checksum_sat' */
      u0 = rtb_EPB_Checksum_sat;
      rtb_EPB_Checksum_sat = (int32_T)u0;

      /* DataTypeConversion: '<S186>/EPB_FailStatus_Convert' */
      rtb_EPB_Status_L = VCU_CS75_9_30_B.CANReceive_o4_om[0];

      /* S-Function (sfix_bitop): '<S186>/EPB_FailStatus_L' */
      rtb_EPB_Status_L &= 192U;

      /* ArithShift: '<S186>/EPB_FailStatus_S' */
      rtb_EPB_Status_L = (int32_T)((uint32_T)rtb_EPB_Status_L >> 6);

      /* Sum: '<S186>/EPB_FailStatus_Ad' */
      rtb_EPB_FailStatus_sat = rtb_EPB_Status_L;

      /* Saturate: '<S186>/EPB_FailStatus_sat' */
      u0 = rtb_EPB_FailStatus_sat;
      rtb_EPB_FailStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S186>/EPB_FailureLamp_Convert' */
      rtb_EPB_Status_L = VCU_CS75_9_30_B.CANReceive_o4_om[5];

      /* S-Function (sfix_bitop): '<S186>/EPB_FailureLamp_L' */
      rtb_EPB_Status_L &= 48U;

      /* ArithShift: '<S186>/EPB_FailureLamp_S' */
      rtb_EPB_Status_L = (int32_T)((uint32_T)rtb_EPB_Status_L >> 4);

      /* Sum: '<S186>/EPB_FailureLamp_Ad' */
      rtb_EPB_FailureLamp_sat = rtb_EPB_Status_L;

      /* Saturate: '<S186>/EPB_FailureLamp_sat' */
      u0 = rtb_EPB_FailureLamp_sat;
      rtb_EPB_FailureLamp_sat = (int32_T)u0;

      /* DataTypeConversion: '<S186>/EPB_FunctionLamp_Convert' */
      rtb_EPB_Status_L = VCU_CS75_9_30_B.CANReceive_o4_om[5];

      /* S-Function (sfix_bitop): '<S186>/EPB_FunctionLamp_L' */
      rtb_EPB_Status_L &= 12U;

      /* ArithShift: '<S186>/EPB_FunctionLamp_S' */
      rtb_EPB_Status_L = (int32_T)((uint32_T)rtb_EPB_Status_L >> 2);

      /* Sum: '<S186>/EPB_FunctionLamp_Ad' */
      rtb_EPB_FunctionLamp_sat = rtb_EPB_Status_L;

      /* Saturate: '<S186>/EPB_FunctionLamp_sat' */
      u0 = rtb_EPB_FunctionLamp_sat;
      rtb_EPB_FunctionLamp_sat = (int32_T)u0;

      /* DataTypeConversion: '<S186>/EPB_RollingCounter_id256_Convert' */
      rtb_EPB_Status_L = VCU_CS75_9_30_B.CANReceive_o4_om[6];

      /* S-Function (sfix_bitop): '<S186>/EPB_RollingCounter_id256_L' */
      rtb_EPB_Status_L &= 15U;

      /* Saturate: '<S186>/EPB_RollingCounter_id256_sat' */
      u0 = rtb_EPB_Status_L;
      EPB_RollingCounter_id256 = u0;

      /* DataTypeConversion: '<S186>/EPB_Status_Convert' */
      rtb_EPB_Status_L = VCU_CS75_9_30_B.CANReceive_o4_om[2];

      /* S-Function (sfix_bitop): '<S186>/EPB_Status_L' */
      rtb_EPB_Status_L &= 192U;

      /* ArithShift: '<S186>/EPB_Status_S' */
      rtb_EPB_Status_L = (int32_T)((uint32_T)rtb_EPB_Status_L >> 6);

      /* Saturate: '<S186>/EPB_Status_sat' */
      u0 = rtb_EPB_Status_L;
      rtb_EPB_Status_L = (int32_T)u0;

      /* SignalConversion: '<S185>/Signal Conversion' */
      VCU_CS75_9_30_B.EPB_FailStatus = rtb_EPB_FailStatus_sat;

      /* SignalConversion: '<S185>/Signal Conversion' */
      VCU_CS75_9_30_B.EPB_Status_e = rtb_EPB_Status_L;

      /* SignalConversion: '<S185>/Signal Conversion' */
      VCU_CS75_9_30_B.EPB_FunctionLamp_e = rtb_EPB_FunctionLamp_sat;

      /* SignalConversion: '<S185>/Signal Conversion' */
      VCU_CS75_9_30_B.EPB_FailureLamp = rtb_EPB_FailureLamp_sat;

      /* SignalConversion: '<S185>/Signal Conversion' */
      VCU_CS75_9_30_B.EPB_RollingCounter_id256_b = EPB_RollingCounter_id256;

      /* SignalConversion: '<S185>/Signal Conversion' */
      VCU_CS75_9_30_B.EPB_Checksum = rtb_EPB_Checksum_sat;
    }

    /* End of Outputs for SubSystem: '<S184>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S86>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF5RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf5looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_ix= 522;
    VCU_CS75_9_30_B.CANReceive_o5_ap= 8;
    VCU_CS75_9_30_B.CANReceive_o2_pj= ec_can_receive(1,5, CAN1BUF5RX);
    VCU_CS75_9_30_B.CANReceive_o4_hj[0]= CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_hj[1]= CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_hj[2]= CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_hj[3]= CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_hj[4]= CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_hj[5]= CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_hj[6]= CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_hj[7]= CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
  }

  /* Call the system: <S86>/ReceiveMessages */

  /* Output and update for function-call system: '<S86>/ReceiveMessages' */
  {
    int32_T rtb_EPS_TorqueSensorStatus_L;
    real_T rtb_EPS_SteeringTorque_sat;
    int32_T rtb_EPS_APA_AbortFeedback_sat;
    int32_T rtb_EPS_APA_ControlFeedback_sat;
    int32_T rtb_EPS_APA_EpasFailed_sat;
    int32_T rtb_EPS_Checksum_sat;
    int32_T rtb_EPS_ConcussAvailabilityStat;
    int32_T rtb_EPS_EPSFailed_sat;
    int32_T rtb_EPS_RollingCounter_sat;
    real_T rtb_EPS_TorqueSensorStatuscv;

    /* Outputs for Enabled SubSystem: '<S193>/Subsystem' incorporates:
     *  EnablePort: '<S194>/Enable'
     */
    if (VCU_CS75_9_30_B.CANReceive_o2_pj > 0) {
      /* DataTypeConversion: '<S195>/EPS_APA_AbortFeedback_Convert' */
      rtb_EPS_TorqueSensorStatus_L = VCU_CS75_9_30_B.CANReceive_o4_hj[1];

      /* S-Function (sfix_bitop): '<S195>/EPS_APA_AbortFeedback_L' */
      rtb_EPS_TorqueSensorStatus_L &= 112U;

      /* ArithShift: '<S195>/EPS_APA_AbortFeedback_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 4);

      /* DataTypeConversion: '<S195>/EPS_APA_AbortFeedbackcv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S195>/EPS_APA_AbortFeedback_Ad' */
      rtb_EPS_APA_AbortFeedback_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S195>/EPS_APA_AbortFeedback_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_APA_AbortFeedback_sat;
      rtb_EPS_APA_AbortFeedback_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* DataTypeConversion: '<S195>/EPS_APA_ControlFeedback_Convert' */
      rtb_EPS_TorqueSensorStatus_L = VCU_CS75_9_30_B.CANReceive_o4_hj[5];

      /* S-Function (sfix_bitop): '<S195>/EPS_APA_ControlFeedback_L' */
      rtb_EPS_TorqueSensorStatus_L &= 64U;

      /* ArithShift: '<S195>/EPS_APA_ControlFeedback_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 6);

      /* DataTypeConversion: '<S195>/EPS_APA_ControlFeedbackcv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S195>/EPS_APA_ControlFeedback_Ad' */
      rtb_EPS_APA_ControlFeedback_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S195>/EPS_APA_ControlFeedback_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_APA_ControlFeedback_sat;
      rtb_EPS_APA_ControlFeedback_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* DataTypeConversion: '<S195>/EPS_APA_EpasFailed_Convert' */
      rtb_EPS_TorqueSensorStatus_L = VCU_CS75_9_30_B.CANReceive_o4_hj[1];

      /* S-Function (sfix_bitop): '<S195>/EPS_APA_EpasFailed_L' */
      rtb_EPS_TorqueSensorStatus_L &= 2U;

      /* ArithShift: '<S195>/EPS_APA_EpasFailed_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 1);

      /* DataTypeConversion: '<S195>/EPS_APA_EpasFailedcv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S195>/EPS_APA_EpasFailed_Ad' */
      rtb_EPS_APA_EpasFailed_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S195>/EPS_APA_EpasFailed_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_APA_EpasFailed_sat;
      rtb_EPS_APA_EpasFailed_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* DataTypeConversion: '<S195>/EPS_Checksum_Convert' */
      rtb_EPS_TorqueSensorStatus_L = VCU_CS75_9_30_B.CANReceive_o4_hj[7];

      /* DataTypeConversion: '<S195>/EPS_Checksumcv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S195>/EPS_Checksum_Ad' */
      rtb_EPS_Checksum_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S195>/EPS_Checksum_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_Checksum_sat;
      rtb_EPS_Checksum_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* DataTypeConversion: '<S195>/EPS_ConcussAvailabilityStatus_Convert' */
      rtb_EPS_TorqueSensorStatus_L = VCU_CS75_9_30_B.CANReceive_o4_hj[6];

      /* S-Function (sfix_bitop): '<S195>/EPS_ConcussAvailabilityStatus_L' */
      rtb_EPS_TorqueSensorStatus_L &= 48U;

      /* ArithShift: '<S195>/EPS_ConcussAvailabilityStatus_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 4);

      /* DataTypeConversion: '<S195>/EPS_ConcussAvailabilityStatuscv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S195>/EPS_ConcussAvailabilityStatus_Ad' */
      rtb_EPS_ConcussAvailabilityStat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S195>/EPS_ConcussAvailabilityStatus_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_ConcussAvailabilityStat;
      rtb_EPS_ConcussAvailabilityStat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* DataTypeConversion: '<S195>/EPS_EPSFailed_Convert' */
      rtb_EPS_TorqueSensorStatus_L = VCU_CS75_9_30_B.CANReceive_o4_hj[0];

      /* S-Function (sfix_bitop): '<S195>/EPS_EPSFailed_L' */
      rtb_EPS_TorqueSensorStatus_L &= 128U;

      /* ArithShift: '<S195>/EPS_EPSFailed_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 7);

      /* DataTypeConversion: '<S195>/EPS_EPSFailedcv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S195>/EPS_EPSFailed_Ad' */
      rtb_EPS_EPSFailed_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S195>/EPS_EPSFailed_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_EPSFailed_sat;
      rtb_EPS_EPSFailed_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* DataTypeConversion: '<S195>/EPS_RollingCounter_Convert' */
      rtb_EPS_TorqueSensorStatus_L = VCU_CS75_9_30_B.CANReceive_o4_hj[6];

      /* S-Function (sfix_bitop): '<S195>/EPS_RollingCounter_L' */
      rtb_EPS_TorqueSensorStatus_L &= 15U;

      /* DataTypeConversion: '<S195>/EPS_RollingCountercv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S195>/EPS_RollingCounter_Ad' */
      rtb_EPS_RollingCounter_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S195>/EPS_RollingCounter_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_RollingCounter_sat;
      rtb_EPS_RollingCounter_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Product: '<S195>/EPS_SteeringTorqueinput3_P' incorporates:
       *  Constant: '<S195>/EPS_SteeringTorqueinput3_C'
       */
      rtb_EPS_SteeringTorque_sat = (real_T)VCU_CS75_9_30_B.CANReceive_o4_hj[2] *
        256.0;

      /* Sum: '<S195>/EPS_SteeringTorqueinput3_Ad' */
      rtb_EPS_TorqueSensorStatuscv = rtb_EPS_SteeringTorque_sat + (real_T)
        VCU_CS75_9_30_B.CANReceive_o4_hj[3];

      /* DataTypeConversion: '<S195>/EPS_SteeringTorque_Convert' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)rtb_EPS_TorqueSensorStatuscv;

      /* S-Function (sfix_bitop): '<S195>/EPS_SteeringTorque_L' */
      rtb_EPS_TorqueSensorStatus_L &= 4080U;

      /* ArithShift: '<S195>/EPS_SteeringTorque_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 4);

      /* DataTypeConversion: '<S195>/EPS_SteeringTorquecv' */
      rtb_EPS_TorqueSensorStatuscv = rtb_EPS_TorqueSensorStatus_L;

      /* Gain: '<S195>/EPS_SteeringTorque_F' */
      rtb_EPS_TorqueSensorStatuscv *= 0.1794;

      /* Sum: '<S195>/EPS_SteeringTorque_Ad' incorporates:
       *  Constant: '<S195>/EPS_SteeringTorque_O'
       */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatuscv +
        -22.780000686645508;

      /* Saturate: '<S195>/EPS_SteeringTorque_sat' */
      if (rtb_EPS_SteeringTorque_sat > 22.78) {
        rtb_EPS_SteeringTorque_sat = 22.78;
      } else {
        if (rtb_EPS_SteeringTorque_sat < -22.78) {
          rtb_EPS_SteeringTorque_sat = -22.78;
        }
      }

      /* End of Saturate: '<S195>/EPS_SteeringTorque_sat' */

      /* DataTypeConversion: '<S195>/EPS_TorqueSensorStatus_Convert' */
      rtb_EPS_TorqueSensorStatus_L = VCU_CS75_9_30_B.CANReceive_o4_hj[4];

      /* S-Function (sfix_bitop): '<S195>/EPS_TorqueSensorStatus_L' */
      rtb_EPS_TorqueSensorStatus_L &= 2U;

      /* ArithShift: '<S195>/EPS_TorqueSensorStatus_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 1);

      /* DataTypeConversion: '<S195>/EPS_TorqueSensorStatuscv' */
      rtb_EPS_TorqueSensorStatuscv = rtb_EPS_TorqueSensorStatus_L;

      /* SignalConversion: '<S194>/Signal Conversion' */
      VCU_CS75_9_30_B.EPS_EPSFailed_m = rtb_EPS_EPSFailed_sat;

      /* SignalConversion: '<S194>/Signal Conversion' */
      VCU_CS75_9_30_B.EPS_APA_EpasFailed = rtb_EPS_APA_EpasFailed_sat;

      /* SignalConversion: '<S194>/Signal Conversion' */
      VCU_CS75_9_30_B.EPS_APA_AbortFeedback = rtb_EPS_APA_AbortFeedback_sat;

      /* SignalConversion: '<S194>/Signal Conversion' */
      VCU_CS75_9_30_B.EPS_SteeringTorque = rtb_EPS_SteeringTorque_sat;

      /* SignalConversion: '<S194>/Signal Conversion' */
      VCU_CS75_9_30_B.EPS_TorqueSensorStatus = rtb_EPS_TorqueSensorStatuscv;

      /* SignalConversion: '<S194>/Signal Conversion' */
      VCU_CS75_9_30_B.EPS_APA_ControlFeedback = rtb_EPS_APA_ControlFeedback_sat;

      /* SignalConversion: '<S194>/Signal Conversion' */
      VCU_CS75_9_30_B.EPS_RollingCounter = rtb_EPS_RollingCounter_sat;

      /* SignalConversion: '<S194>/Signal Conversion' */
      VCU_CS75_9_30_B.EPS_ConcussAvailabilityStatus =
        rtb_EPS_ConcussAvailabilityStat;

      /* SignalConversion: '<S194>/Signal Conversion' */
      VCU_CS75_9_30_B.EPS_Checksum = rtb_EPS_Checksum_sat;
    }

    /* End of Outputs for SubSystem: '<S193>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S87>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF6RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf6looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_hs= 538;
    VCU_CS75_9_30_B.CANReceive_o5_hk= 8;
    VCU_CS75_9_30_B.CANReceive_o2_jj= ec_can_receive(1,6, CAN1BUF6RX);
    VCU_CS75_9_30_B.CANReceive_o4_b[0]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_b[1]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_b[2]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_b[3]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_b[4]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_b[5]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_b[6]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_b[7]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
  }

  /* Call the system: <S87>/ReceiveMessages */

  /* Output and update for function-call system: '<S87>/ReceiveMessages' */
  {
    int32_T rtb_Rollingcounter_L;
    real_T rtb_EPS_MeasuredTosionBatTorque;
    int32_T rtb_EPS_AvailabilityStatus_sat;
    int32_T rtb_EPS_IACC_abortReson_sat;
    int32_T rtb_EPS_MeasTsionBatTorquevalid;
    real_T rtb_Rollingcountercv;

    /* Outputs for Enabled SubSystem: '<S205>/Subsystem' incorporates:
     *  EnablePort: '<S206>/Enable'
     */
    if (VCU_CS75_9_30_B.CANReceive_o2_jj > 0) {
      /* DataTypeConversion: '<S207>/EPS_AvailabilityStatus_Convert' */
      rtb_Rollingcounter_L = VCU_CS75_9_30_B.CANReceive_o4_b[2];

      /* S-Function (sfix_bitop): '<S207>/EPS_AvailabilityStatus_L' */
      rtb_Rollingcounter_L &= 28U;

      /* ArithShift: '<S207>/EPS_AvailabilityStatus_S' */
      rtb_Rollingcounter_L = (int32_T)((uint32_T)rtb_Rollingcounter_L >> 2);

      /* DataTypeConversion: '<S207>/EPS_AvailabilityStatuscv' */
      rtb_EPS_MeasuredTosionBatTorque = rtb_Rollingcounter_L;

      /* Sum: '<S207>/EPS_AvailabilityStatus_Ad' */
      rtb_EPS_AvailabilityStatus_sat = (int32_T)rtb_EPS_MeasuredTosionBatTorque;

      /* Saturate: '<S207>/EPS_AvailabilityStatus_sat' */
      rtb_EPS_MeasuredTosionBatTorque = rtb_EPS_AvailabilityStatus_sat;
      rtb_EPS_AvailabilityStatus_sat = (int32_T)rtb_EPS_MeasuredTosionBatTorque;

      /* DataTypeConversion: '<S207>/EPS_IACC_abortReson_Convert' */
      rtb_Rollingcounter_L = VCU_CS75_9_30_B.CANReceive_o4_b[5];

      /* S-Function (sfix_bitop): '<S207>/EPS_IACC_abortReson_L' */
      rtb_Rollingcounter_L &= 112U;

      /* ArithShift: '<S207>/EPS_IACC_abortReson_S' */
      rtb_Rollingcounter_L = (int32_T)((uint32_T)rtb_Rollingcounter_L >> 4);

      /* DataTypeConversion: '<S207>/EPS_IACC_abortResoncv' */
      rtb_EPS_MeasuredTosionBatTorque = rtb_Rollingcounter_L;

      /* Sum: '<S207>/EPS_IACC_abortReson_Ad' */
      rtb_EPS_IACC_abortReson_sat = (int32_T)rtb_EPS_MeasuredTosionBatTorque;

      /* Saturate: '<S207>/EPS_IACC_abortReson_sat' */
      rtb_EPS_MeasuredTosionBatTorque = rtb_EPS_IACC_abortReson_sat;
      rtb_EPS_IACC_abortReson_sat = (int32_T)rtb_EPS_MeasuredTosionBatTorque;

      /* DataTypeConversion: '<S207>/EPS_MeasTsionBatTorquevalid_Convert' */
      rtb_Rollingcounter_L = VCU_CS75_9_30_B.CANReceive_o4_b[4];

      /* S-Function (sfix_bitop): '<S207>/EPS_MeasTsionBatTorquevalid_L' */
      rtb_Rollingcounter_L &= 64U;

      /* ArithShift: '<S207>/EPS_MeasTsionBatTorquevalid_S' */
      rtb_Rollingcounter_L = (int32_T)((uint32_T)rtb_Rollingcounter_L >> 6);

      /* DataTypeConversion: '<S207>/EPS_MeasTsionBatTorquevalidcv' */
      rtb_EPS_MeasuredTosionBatTorque = rtb_Rollingcounter_L;

      /* Sum: '<S207>/EPS_MeasTsionBatTorquevalid_Ad' */
      rtb_EPS_MeasTsionBatTorquevalid = (int32_T)rtb_EPS_MeasuredTosionBatTorque;

      /* Saturate: '<S207>/EPS_MeasTsionBatTorquevalid_sat' */
      rtb_EPS_MeasuredTosionBatTorque = rtb_EPS_MeasTsionBatTorquevalid;
      rtb_EPS_MeasTsionBatTorquevalid = (int32_T)rtb_EPS_MeasuredTosionBatTorque;

      /* Product: '<S207>/EPS_MeasuredTosionBatTorqueinput1_P' incorporates:
       *  Constant: '<S207>/EPS_MeasuredTosionBatTorqueinput1_C'
       */
      rtb_EPS_MeasuredTosionBatTorque = (real_T)VCU_CS75_9_30_B.CANReceive_o4_b
        [0] * 256.0;

      /* Sum: '<S207>/EPS_MeasuredTosionBatTorqueinput1_Ad' */
      rtb_Rollingcountercv = rtb_EPS_MeasuredTosionBatTorque + (real_T)
        VCU_CS75_9_30_B.CANReceive_o4_b[1];

      /* DataTypeConversion: '<S207>/EPS_MeasuredTosionBatTorque_Convert' */
      rtb_Rollingcounter_L = (int32_T)rtb_Rollingcountercv;

      /* S-Function (sfix_bitop): '<S207>/EPS_MeasuredTosionBatTorque_L' */
      rtb_Rollingcounter_L &= 65504U;

      /* ArithShift: '<S207>/EPS_MeasuredTosionBatTorque_S' */
      rtb_Rollingcounter_L = (int32_T)((uint32_T)rtb_Rollingcounter_L >> 5);

      /* DataTypeConversion: '<S207>/EPS_MeasuredTosionBatTorquecv' */
      rtb_Rollingcountercv = rtb_Rollingcounter_L;

      /* Gain: '<S207>/EPS_MeasuredTosionBatTorque_F' */
      rtb_Rollingcountercv *= 0.01;

      /* Sum: '<S207>/EPS_MeasuredTosionBatTorque_Ad' incorporates:
       *  Constant: '<S207>/EPS_MeasuredTosionBatTorque_O'
       */
      rtb_EPS_MeasuredTosionBatTorque = rtb_Rollingcountercv +
        -10.229999542236328;

      /* Saturate: '<S207>/EPS_MeasuredTosionBatTorque_sat' */
      if (rtb_EPS_MeasuredTosionBatTorque > 10.23) {
        rtb_EPS_MeasuredTosionBatTorque = 10.23;
      }

      /* End of Saturate: '<S207>/EPS_MeasuredTosionBatTorque_sat' */

      /* DataTypeConversion: '<S207>/Rollingcounter_Convert' */
      rtb_Rollingcounter_L = VCU_CS75_9_30_B.CANReceive_o4_b[6];

      /* S-Function (sfix_bitop): '<S207>/Rollingcounter_L' */
      rtb_Rollingcounter_L &= 15U;

      /* DataTypeConversion: '<S207>/Rollingcountercv' */
      rtb_Rollingcountercv = rtb_Rollingcounter_L;

      /* SignalConversion: '<S206>/Signal Conversion' */
      VCU_CS75_9_30_B.EPS_MeasuredTosionBatTorque =
        rtb_EPS_MeasuredTosionBatTorque;

      /* SignalConversion: '<S206>/Signal Conversion' */
      VCU_CS75_9_30_B.EPS_AvailabilityStatus_g = rtb_EPS_AvailabilityStatus_sat;

      /* SignalConversion: '<S206>/Signal Conversion' */
      VCU_CS75_9_30_B.EPS_MeasTsionBatTorquevalid =
        rtb_EPS_MeasTsionBatTorquevalid;

      /* SignalConversion: '<S206>/Signal Conversion' */
      VCU_CS75_9_30_B.EPS_IACC_abortReson = rtb_EPS_IACC_abortReson_sat;

      /* SignalConversion: '<S206>/Signal Conversion' */
      VCU_CS75_9_30_B.EPS_21A_Rollingcounter = rtb_Rollingcountercv;

      /* SignalConversion: '<S206>/Signal Conversion' */
      VCU_CS75_9_30_B.EPS_21A_CheckingSum = 0.0;
    }

    /* End of Outputs for SubSystem: '<S205>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S88>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF7RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf7looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_ou= 631;
    VCU_CS75_9_30_B.CANReceive_o5_in= 8;
    VCU_CS75_9_30_B.CANReceive_o2_p5= ec_can_receive(1,7, CAN1BUF7RX);
    VCU_CS75_9_30_B.CANReceive_o4_fo[0]= CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_fo[1]= CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_fo[2]= CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_fo[3]= CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_fo[4]= CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_fo[5]= CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_fo[6]= CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_fo[7]= CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
  }

  /* Call the system: <S88>/ReceiveMessages */

  /* Output and update for function-call system: '<S88>/ReceiveMessages' */
  {
    int32_T rtb_ESP_VehicleStandstill_L;
    int32_T rtb_ESP_ABAactive_sat;
    int32_T rtb_ESP_ABAavailable_sat;
    int32_T rtb_ESP_AEBAvailable_sat;
    int32_T rtb_ESP_AEBdecActive_sat;
    int32_T rtb_ESP_AWBactive_sat;
    int32_T rtb_ESP_AWBavailable_sat;
    int32_T rtb_ESP_BrakeForce_sat;
    int32_T rtb_ESP_BrakeOverHeat_sat;
    int32_T rtb_ESP_CDD_Active_sat;
    int32_T rtb_ESP_CDD_Available_sat;
    int32_T rtb_ESP_CheckSum_277_sat;
    int32_T rtb_ESP_PrefillActive_sat;
    int32_T rtb_ESP_PrefillAvailable_sat;
    int32_T rtb_ESP_RollingCounter_277_sat;
    int32_T rtb_ESP_TCSActive_sat;
    int32_T rtb_ESP_VDCActive_sat;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S214>/Subsystem' incorporates:
     *  EnablePort: '<S215>/Enable'
     */
    if (VCU_CS75_9_30_B.CANReceive_o2_p5 > 0) {
      /* DataTypeConversion: '<S216>/ESP_ABAactive_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_9_30_B.CANReceive_o4_fo[2];

      /* S-Function (sfix_bitop): '<S216>/ESP_ABAactive_L' */
      rtb_ESP_VehicleStandstill_L &= 32U;

      /* ArithShift: '<S216>/ESP_ABAactive_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 5);

      /* Sum: '<S216>/ESP_ABAactive_Ad' */
      rtb_ESP_ABAactive_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S216>/ESP_ABAactive_sat' */
      u0 = rtb_ESP_ABAactive_sat;
      rtb_ESP_ABAactive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S216>/ESP_ABAavailable_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_9_30_B.CANReceive_o4_fo[2];

      /* S-Function (sfix_bitop): '<S216>/ESP_ABAavailable_L' */
      rtb_ESP_VehicleStandstill_L &= 16U;

      /* ArithShift: '<S216>/ESP_ABAavailable_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 4);

      /* Sum: '<S216>/ESP_ABAavailable_Ad' */
      rtb_ESP_ABAavailable_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S216>/ESP_ABAavailable_sat' */
      u0 = rtb_ESP_ABAavailable_sat;
      rtb_ESP_ABAavailable_sat = (int32_T)u0;

      /* DataTypeConversion: '<S216>/ESP_AEBAvailable_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_9_30_B.CANReceive_o4_fo[2];

      /* S-Function (sfix_bitop): '<S216>/ESP_AEBAvailable_L' */
      rtb_ESP_VehicleStandstill_L &= 8U;

      /* ArithShift: '<S216>/ESP_AEBAvailable_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 3);

      /* Sum: '<S216>/ESP_AEBAvailable_Ad' */
      rtb_ESP_AEBAvailable_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S216>/ESP_AEBAvailable_sat' */
      u0 = rtb_ESP_AEBAvailable_sat;
      rtb_ESP_AEBAvailable_sat = (int32_T)u0;

      /* DataTypeConversion: '<S216>/ESP_AEBdecActive_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_9_30_B.CANReceive_o4_fo[2];

      /* S-Function (sfix_bitop): '<S216>/ESP_AEBdecActive_L' */
      rtb_ESP_VehicleStandstill_L &= 4U;

      /* ArithShift: '<S216>/ESP_AEBdecActive_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 2);

      /* Sum: '<S216>/ESP_AEBdecActive_Ad' */
      rtb_ESP_AEBdecActive_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S216>/ESP_AEBdecActive_sat' */
      u0 = rtb_ESP_AEBdecActive_sat;
      rtb_ESP_AEBdecActive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S216>/ESP_AWBactive_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_9_30_B.CANReceive_o4_fo[2];

      /* S-Function (sfix_bitop): '<S216>/ESP_AWBactive_L' */
      rtb_ESP_VehicleStandstill_L &= 2U;

      /* ArithShift: '<S216>/ESP_AWBactive_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 1);

      /* Sum: '<S216>/ESP_AWBactive_Ad' */
      rtb_ESP_AWBactive_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S216>/ESP_AWBactive_sat' */
      u0 = rtb_ESP_AWBactive_sat;
      rtb_ESP_AWBactive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S216>/ESP_AWBavailable_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_9_30_B.CANReceive_o4_fo[2];

      /* S-Function (sfix_bitop): '<S216>/ESP_AWBavailable_L' */
      rtb_ESP_VehicleStandstill_L &= 1U;

      /* Sum: '<S216>/ESP_AWBavailable_Ad' */
      rtb_ESP_AWBavailable_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S216>/ESP_AWBavailable_sat' */
      u0 = rtb_ESP_AWBavailable_sat;
      rtb_ESP_AWBavailable_sat = (int32_T)u0;

      /* DataTypeConversion: '<S216>/ESP_BrakeForce_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_9_30_B.CANReceive_o4_fo[1];

      /* S-Function (sfix_bitop): '<S216>/ESP_BrakeForce_L' */
      rtb_ESP_VehicleStandstill_L &= 16U;

      /* ArithShift: '<S216>/ESP_BrakeForce_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 4);

      /* Sum: '<S216>/ESP_BrakeForce_Ad' */
      rtb_ESP_BrakeForce_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S216>/ESP_BrakeForce_sat' */
      u0 = rtb_ESP_BrakeForce_sat;
      rtb_ESP_BrakeForce_sat = (int32_T)u0;

      /* DataTypeConversion: '<S216>/ESP_BrakeOverHeat_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_9_30_B.CANReceive_o4_fo[3];

      /* S-Function (sfix_bitop): '<S216>/ESP_BrakeOverHeat_L' */
      rtb_ESP_VehicleStandstill_L &= 1U;

      /* Sum: '<S216>/ESP_BrakeOverHeat_Ad' */
      rtb_ESP_BrakeOverHeat_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S216>/ESP_BrakeOverHeat_sat' */
      u0 = rtb_ESP_BrakeOverHeat_sat;
      rtb_ESP_BrakeOverHeat_sat = (int32_T)u0;

      /* DataTypeConversion: '<S216>/ESP_CDD_Active_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_9_30_B.CANReceive_o4_fo[3];

      /* S-Function (sfix_bitop): '<S216>/ESP_CDD_Active_L' */
      rtb_ESP_VehicleStandstill_L &= 8U;

      /* ArithShift: '<S216>/ESP_CDD_Active_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 3);

      /* Sum: '<S216>/ESP_CDD_Active_Ad' */
      rtb_ESP_CDD_Active_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S216>/ESP_CDD_Active_sat' */
      u0 = rtb_ESP_CDD_Active_sat;
      rtb_ESP_CDD_Active_sat = (int32_T)u0;

      /* DataTypeConversion: '<S216>/ESP_CDD_Available_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_9_30_B.CANReceive_o4_fo[3];

      /* S-Function (sfix_bitop): '<S216>/ESP_CDD_Available_L' */
      rtb_ESP_VehicleStandstill_L &= 16U;

      /* ArithShift: '<S216>/ESP_CDD_Available_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 4);

      /* Sum: '<S216>/ESP_CDD_Available_Ad' */
      rtb_ESP_CDD_Available_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S216>/ESP_CDD_Available_sat' */
      u0 = rtb_ESP_CDD_Available_sat;
      rtb_ESP_CDD_Available_sat = (int32_T)u0;

      /* DataTypeConversion: '<S216>/ESP_CheckSum_277_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_9_30_B.CANReceive_o4_fo[7];

      /* Sum: '<S216>/ESP_CheckSum_277_Ad' */
      rtb_ESP_CheckSum_277_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S216>/ESP_CheckSum_277_sat' */
      u0 = rtb_ESP_CheckSum_277_sat;
      rtb_ESP_CheckSum_277_sat = (int32_T)u0;

      /* DataTypeConversion: '<S216>/ESP_PrefillActive_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_9_30_B.CANReceive_o4_fo[2];

      /* S-Function (sfix_bitop): '<S216>/ESP_PrefillActive_L' */
      rtb_ESP_VehicleStandstill_L &= 128U;

      /* ArithShift: '<S216>/ESP_PrefillActive_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 7);

      /* Sum: '<S216>/ESP_PrefillActive_Ad' */
      rtb_ESP_PrefillActive_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S216>/ESP_PrefillActive_sat' */
      u0 = rtb_ESP_PrefillActive_sat;
      rtb_ESP_PrefillActive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S216>/ESP_PrefillAvailable_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_9_30_B.CANReceive_o4_fo[2];

      /* S-Function (sfix_bitop): '<S216>/ESP_PrefillAvailable_L' */
      rtb_ESP_VehicleStandstill_L &= 64U;

      /* ArithShift: '<S216>/ESP_PrefillAvailable_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 6);

      /* Sum: '<S216>/ESP_PrefillAvailable_Ad' */
      rtb_ESP_PrefillAvailable_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S216>/ESP_PrefillAvailable_sat' */
      u0 = rtb_ESP_PrefillAvailable_sat;
      rtb_ESP_PrefillAvailable_sat = (int32_T)u0;

      /* DataTypeConversion: '<S216>/ESP_RollingCounter_277_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_9_30_B.CANReceive_o4_fo[6];

      /* S-Function (sfix_bitop): '<S216>/ESP_RollingCounter_277_L' */
      rtb_ESP_VehicleStandstill_L &= 15U;

      /* Sum: '<S216>/ESP_RollingCounter_277_Ad' */
      rtb_ESP_RollingCounter_277_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S216>/ESP_RollingCounter_277_sat' */
      u0 = rtb_ESP_RollingCounter_277_sat;
      rtb_ESP_RollingCounter_277_sat = (int32_T)u0;

      /* DataTypeConversion: '<S216>/ESP_TCSActive_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_9_30_B.CANReceive_o4_fo[1];

      /* S-Function (sfix_bitop): '<S216>/ESP_TCSActive_L' */
      rtb_ESP_VehicleStandstill_L &= 64U;

      /* ArithShift: '<S216>/ESP_TCSActive_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 6);

      /* Sum: '<S216>/ESP_TCSActive_Ad' */
      rtb_ESP_TCSActive_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S216>/ESP_TCSActive_sat' */
      u0 = rtb_ESP_TCSActive_sat;
      rtb_ESP_TCSActive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S216>/ESP_VDCActive_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_9_30_B.CANReceive_o4_fo[1];

      /* S-Function (sfix_bitop): '<S216>/ESP_VDCActive_L' */
      rtb_ESP_VehicleStandstill_L &= 32U;

      /* ArithShift: '<S216>/ESP_VDCActive_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 5);

      /* Sum: '<S216>/ESP_VDCActive_Ad' */
      rtb_ESP_VDCActive_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S216>/ESP_VDCActive_sat' */
      u0 = rtb_ESP_VDCActive_sat;
      rtb_ESP_VDCActive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S216>/ESP_VehicleStandstill_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_9_30_B.CANReceive_o4_fo[3];

      /* S-Function (sfix_bitop): '<S216>/ESP_VehicleStandstill_L' */
      rtb_ESP_VehicleStandstill_L &= 64U;

      /* ArithShift: '<S216>/ESP_VehicleStandstill_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 6);

      /* Saturate: '<S216>/ESP_VehicleStandstill_sat' */
      u0 = rtb_ESP_VehicleStandstill_L;
      rtb_ESP_VehicleStandstill_L = (int32_T)u0;

      /* SignalConversion: '<S215>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_BrakeForce = rtb_ESP_BrakeForce_sat;

      /* SignalConversion: '<S215>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_PrefillAvailable = rtb_ESP_PrefillAvailable_sat;

      /* SignalConversion: '<S215>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_PrefillActive = rtb_ESP_PrefillActive_sat;

      /* SignalConversion: '<S215>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_BrakeOverHeat = rtb_ESP_BrakeOverHeat_sat;

      /* SignalConversion: '<S215>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_CDD_Active = rtb_ESP_CDD_Active_sat;

      /* SignalConversion: '<S215>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_CDD_Available = rtb_ESP_CDD_Available_sat;

      /* SignalConversion: '<S215>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_CDD_Active_APA = 0.0;

      /* SignalConversion: '<S215>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_VehicleStandstill = rtb_ESP_VehicleStandstill_L;

      /* SignalConversion: '<S215>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_CDD_Available_APA = 0.0;

      /* SignalConversion: '<S215>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_RollingCounter_277 = rtb_ESP_RollingCounter_277_sat;

      /* SignalConversion: '<S215>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_CheckSum_277 = rtb_ESP_CheckSum_277_sat;

      /* SignalConversion: '<S215>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_VDCActive = rtb_ESP_VDCActive_sat;

      /* SignalConversion: '<S215>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_TCSActive = rtb_ESP_TCSActive_sat;

      /* SignalConversion: '<S215>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_AWBavailable = rtb_ESP_AWBavailable_sat;

      /* SignalConversion: '<S215>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_AWBactive = rtb_ESP_AWBactive_sat;

      /* SignalConversion: '<S215>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_AEBdecActive = rtb_ESP_AEBdecActive_sat;

      /* SignalConversion: '<S215>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_AEBAvailable = rtb_ESP_AEBAvailable_sat;

      /* SignalConversion: '<S215>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_ABAavailable = rtb_ESP_ABAavailable_sat;

      /* SignalConversion: '<S215>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_ABAactive = rtb_ESP_ABAactive_sat;
    }

    /* End of Outputs for SubSystem: '<S214>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S89>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF16RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf16looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_n= 640;
    VCU_CS75_9_30_B.CANReceive_o5_lo= 8;
    VCU_CS75_9_30_B.CANReceive_o2_ff= ec_can_receive(1,16, CAN1BUF16RX);
    VCU_CS75_9_30_B.CANReceive_o4_op[0]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_op[1]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_op[2]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_op[3]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_op[4]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_op[5]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_op[6]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_op[7]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
  }

  /* Call the system: <S89>/ReceiveMessages */

  /* Output and update for function-call system: '<S89>/ReceiveMessages' */
  {
    real_T rtb_Wheel_Speed_FL_Data_sat;
    real_T rtb_Wheel_Speed_FR_Data_sat;
    int32_T rtb_Wheel_Speed_RR_Valid_Data_L;
    int32_T rtb_Wheel_Speed_FL_Direction_sa;
    int32_T rtb_Wheel_Speed_FL_Valid_Data_s;
    real_T rtb_Wheel_Speed_RL_Data_sat;
    int32_T rtb_Wheel_Speed_FR_Direction_sa;
    int32_T rtb_Wheel_Speed_FR_Valid_Data_s;
    real_T rtb_Wheel_Speed_RR_Data_sat;
    int32_T rtb_Wheel_Speed_RL_Direction_sa;
    int32_T rtb_Wheel_Speed_RL_Valid_Data_s;
    real_T rtb_Wheel_Speed_RR_Valid_Datacv;
    int32_T rtb_Wheel_Speed_RR_Direction_sa;

    /* Outputs for Enabled SubSystem: '<S236>/Subsystem' incorporates:
     *  EnablePort: '<S237>/Enable'
     */
    if (VCU_CS75_9_30_B.CANReceive_o2_ff > 0) {
      /* Product: '<S238>/Wheel_Speed_FL_Datainput7_P' incorporates:
       *  Constant: '<S238>/Wheel_Speed_FL_Datainput7_C'
       */
      rtb_Wheel_Speed_FL_Data_sat = (real_T)VCU_CS75_9_30_B.CANReceive_o4_op[6] *
        256.0;

      /* Sum: '<S238>/Wheel_Speed_FL_Datainput7_Ad' */
      rtb_Wheel_Speed_FR_Data_sat = rtb_Wheel_Speed_FL_Data_sat + (real_T)
        VCU_CS75_9_30_B.CANReceive_o4_op[7];

      /* DataTypeConversion: '<S238>/Wheel_Speed_FL_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)rtb_Wheel_Speed_FR_Data_sat;

      /* S-Function (sfix_bitop): '<S238>/Wheel_Speed_FL_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 8191U;

      /* DataTypeConversion: '<S238>/Wheel_Speed_FL_Datacv' */
      rtb_Wheel_Speed_FR_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Gain: '<S238>/Wheel_Speed_FL_Data_F' */
      rtb_Wheel_Speed_FR_Data_sat *= 0.05625;

      /* Sum: '<S238>/Wheel_Speed_FL_Data_Ad' */
      rtb_Wheel_Speed_FL_Data_sat = rtb_Wheel_Speed_FR_Data_sat;

      /* Saturate: '<S238>/Wheel_Speed_FL_Data_sat' */
      if (rtb_Wheel_Speed_FL_Data_sat > 360.0) {
        rtb_Wheel_Speed_FL_Data_sat = 360.0;
      }

      /* End of Saturate: '<S238>/Wheel_Speed_FL_Data_sat' */

      /* DataTypeConversion: '<S238>/Wheel_Speed_FL_Direction_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = VCU_CS75_9_30_B.CANReceive_o4_op[6];

      /* S-Function (sfix_bitop): '<S238>/Wheel_Speed_FL_Direction_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 96U;

      /* ArithShift: '<S238>/Wheel_Speed_FL_Direction_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 5);

      /* DataTypeConversion: '<S238>/Wheel_Speed_FL_Directioncv' */
      rtb_Wheel_Speed_FR_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S238>/Wheel_Speed_FL_Direction_Ad' */
      rtb_Wheel_Speed_FL_Direction_sa = (int32_T)rtb_Wheel_Speed_FR_Data_sat;

      /* Saturate: '<S238>/Wheel_Speed_FL_Direction_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_FL_Direction_sa;
      rtb_Wheel_Speed_FL_Direction_sa = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* DataTypeConversion: '<S238>/Wheel_Speed_FL_Valid_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = VCU_CS75_9_30_B.CANReceive_o4_op[6];

      /* S-Function (sfix_bitop): '<S238>/Wheel_Speed_FL_Valid_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 128U;

      /* ArithShift: '<S238>/Wheel_Speed_FL_Valid_Data_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 7);

      /* DataTypeConversion: '<S238>/Wheel_Speed_FL_Valid_Datacv' */
      rtb_Wheel_Speed_FR_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S238>/Wheel_Speed_FL_Valid_Data_Ad' */
      rtb_Wheel_Speed_FL_Valid_Data_s = (int32_T)rtb_Wheel_Speed_FR_Data_sat;

      /* Saturate: '<S238>/Wheel_Speed_FL_Valid_Data_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_FL_Valid_Data_s;
      rtb_Wheel_Speed_FL_Valid_Data_s = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* Product: '<S238>/Wheel_Speed_FR_Datainput5_P' incorporates:
       *  Constant: '<S238>/Wheel_Speed_FR_Datainput5_C'
       */
      rtb_Wheel_Speed_FR_Data_sat = (real_T)VCU_CS75_9_30_B.CANReceive_o4_op[4] *
        256.0;

      /* Sum: '<S238>/Wheel_Speed_FR_Datainput5_Ad' */
      rtb_Wheel_Speed_RL_Data_sat = rtb_Wheel_Speed_FR_Data_sat + (real_T)
        VCU_CS75_9_30_B.CANReceive_o4_op[5];

      /* DataTypeConversion: '<S238>/Wheel_Speed_FR_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)rtb_Wheel_Speed_RL_Data_sat;

      /* S-Function (sfix_bitop): '<S238>/Wheel_Speed_FR_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 8191U;

      /* DataTypeConversion: '<S238>/Wheel_Speed_FR_Datacv' */
      rtb_Wheel_Speed_RL_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Gain: '<S238>/Wheel_Speed_FR_Data_F' */
      rtb_Wheel_Speed_RL_Data_sat *= 0.05625;

      /* Sum: '<S238>/Wheel_Speed_FR_Data_Ad' */
      rtb_Wheel_Speed_FR_Data_sat = rtb_Wheel_Speed_RL_Data_sat;

      /* Saturate: '<S238>/Wheel_Speed_FR_Data_sat' */
      if (rtb_Wheel_Speed_FR_Data_sat > 360.0) {
        rtb_Wheel_Speed_FR_Data_sat = 360.0;
      }

      /* End of Saturate: '<S238>/Wheel_Speed_FR_Data_sat' */

      /* DataTypeConversion: '<S238>/Wheel_Speed_FR_Direction_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = VCU_CS75_9_30_B.CANReceive_o4_op[4];

      /* S-Function (sfix_bitop): '<S238>/Wheel_Speed_FR_Direction_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 96U;

      /* ArithShift: '<S238>/Wheel_Speed_FR_Direction_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 5);

      /* DataTypeConversion: '<S238>/Wheel_Speed_FR_Directioncv' */
      rtb_Wheel_Speed_RL_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S238>/Wheel_Speed_FR_Direction_Ad' */
      rtb_Wheel_Speed_FR_Direction_sa = (int32_T)rtb_Wheel_Speed_RL_Data_sat;

      /* Saturate: '<S238>/Wheel_Speed_FR_Direction_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_FR_Direction_sa;
      rtb_Wheel_Speed_FR_Direction_sa = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* DataTypeConversion: '<S238>/Wheel_Speed_FR_Valid_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = VCU_CS75_9_30_B.CANReceive_o4_op[4];

      /* S-Function (sfix_bitop): '<S238>/Wheel_Speed_FR_Valid_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 128U;

      /* ArithShift: '<S238>/Wheel_Speed_FR_Valid_Data_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 7);

      /* DataTypeConversion: '<S238>/Wheel_Speed_FR_Valid_Datacv' */
      rtb_Wheel_Speed_RL_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S238>/Wheel_Speed_FR_Valid_Data_Ad' */
      rtb_Wheel_Speed_FR_Valid_Data_s = (int32_T)rtb_Wheel_Speed_RL_Data_sat;

      /* Saturate: '<S238>/Wheel_Speed_FR_Valid_Data_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_FR_Valid_Data_s;
      rtb_Wheel_Speed_FR_Valid_Data_s = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* Product: '<S238>/Wheel_Speed_RL_Datainput3_P' incorporates:
       *  Constant: '<S238>/Wheel_Speed_RL_Datainput3_C'
       */
      rtb_Wheel_Speed_RL_Data_sat = (real_T)VCU_CS75_9_30_B.CANReceive_o4_op[2] *
        256.0;

      /* Sum: '<S238>/Wheel_Speed_RL_Datainput3_Ad' */
      rtb_Wheel_Speed_RR_Data_sat = rtb_Wheel_Speed_RL_Data_sat + (real_T)
        VCU_CS75_9_30_B.CANReceive_o4_op[3];

      /* DataTypeConversion: '<S238>/Wheel_Speed_RL_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)rtb_Wheel_Speed_RR_Data_sat;

      /* S-Function (sfix_bitop): '<S238>/Wheel_Speed_RL_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 8191U;

      /* DataTypeConversion: '<S238>/Wheel_Speed_RL_Datacv' */
      rtb_Wheel_Speed_RR_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Gain: '<S238>/Wheel_Speed_RL_Data_F' */
      rtb_Wheel_Speed_RR_Data_sat *= 0.05625;

      /* Sum: '<S238>/Wheel_Speed_RL_Data_Ad' */
      rtb_Wheel_Speed_RL_Data_sat = rtb_Wheel_Speed_RR_Data_sat;

      /* Saturate: '<S238>/Wheel_Speed_RL_Data_sat' */
      if (rtb_Wheel_Speed_RL_Data_sat > 360.0) {
        rtb_Wheel_Speed_RL_Data_sat = 360.0;
      }

      /* End of Saturate: '<S238>/Wheel_Speed_RL_Data_sat' */

      /* DataTypeConversion: '<S238>/Wheel_Speed_RL_Direction_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = VCU_CS75_9_30_B.CANReceive_o4_op[2];

      /* S-Function (sfix_bitop): '<S238>/Wheel_Speed_RL_Direction_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 96U;

      /* ArithShift: '<S238>/Wheel_Speed_RL_Direction_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 5);

      /* DataTypeConversion: '<S238>/Wheel_Speed_RL_Directioncv' */
      rtb_Wheel_Speed_RR_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S238>/Wheel_Speed_RL_Direction_Ad' */
      rtb_Wheel_Speed_RL_Direction_sa = (int32_T)rtb_Wheel_Speed_RR_Data_sat;

      /* Saturate: '<S238>/Wheel_Speed_RL_Direction_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RL_Direction_sa;
      rtb_Wheel_Speed_RL_Direction_sa = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* DataTypeConversion: '<S238>/Wheel_Speed_RL_Valid_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = VCU_CS75_9_30_B.CANReceive_o4_op[2];

      /* S-Function (sfix_bitop): '<S238>/Wheel_Speed_RL_Valid_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 128U;

      /* ArithShift: '<S238>/Wheel_Speed_RL_Valid_Data_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 7);

      /* DataTypeConversion: '<S238>/Wheel_Speed_RL_Valid_Datacv' */
      rtb_Wheel_Speed_RR_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S238>/Wheel_Speed_RL_Valid_Data_Ad' */
      rtb_Wheel_Speed_RL_Valid_Data_s = (int32_T)rtb_Wheel_Speed_RR_Data_sat;

      /* Saturate: '<S238>/Wheel_Speed_RL_Valid_Data_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RL_Valid_Data_s;
      rtb_Wheel_Speed_RL_Valid_Data_s = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* Product: '<S238>/Wheel_Speed_RR_Datainput1_P' incorporates:
       *  Constant: '<S238>/Wheel_Speed_RR_Datainput1_C'
       */
      rtb_Wheel_Speed_RR_Data_sat = (real_T)VCU_CS75_9_30_B.CANReceive_o4_op[0] *
        256.0;

      /* Sum: '<S238>/Wheel_Speed_RR_Datainput1_Ad' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RR_Data_sat + (real_T)
        VCU_CS75_9_30_B.CANReceive_o4_op[1];

      /* DataTypeConversion: '<S238>/Wheel_Speed_RR_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* S-Function (sfix_bitop): '<S238>/Wheel_Speed_RR_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 8191U;

      /* DataTypeConversion: '<S238>/Wheel_Speed_RR_Datacv' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Gain: '<S238>/Wheel_Speed_RR_Data_F' */
      rtb_Wheel_Speed_RR_Valid_Datacv *= 0.05625;

      /* Sum: '<S238>/Wheel_Speed_RR_Data_Ad' */
      rtb_Wheel_Speed_RR_Data_sat = rtb_Wheel_Speed_RR_Valid_Datacv;

      /* Saturate: '<S238>/Wheel_Speed_RR_Data_sat' */
      if (rtb_Wheel_Speed_RR_Data_sat > 360.0) {
        rtb_Wheel_Speed_RR_Data_sat = 360.0;
      }

      /* End of Saturate: '<S238>/Wheel_Speed_RR_Data_sat' */

      /* DataTypeConversion: '<S238>/Wheel_Speed_RR_Direction_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = VCU_CS75_9_30_B.CANReceive_o4_op[0];

      /* S-Function (sfix_bitop): '<S238>/Wheel_Speed_RR_Direction_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 96U;

      /* ArithShift: '<S238>/Wheel_Speed_RR_Direction_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 5);

      /* DataTypeConversion: '<S238>/Wheel_Speed_RR_Directioncv' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S238>/Wheel_Speed_RR_Direction_Ad' */
      rtb_Wheel_Speed_RR_Direction_sa = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* Saturate: '<S238>/Wheel_Speed_RR_Direction_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RR_Direction_sa;
      rtb_Wheel_Speed_RR_Direction_sa = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* DataTypeConversion: '<S238>/Wheel_Speed_RR_Valid_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = VCU_CS75_9_30_B.CANReceive_o4_op[0];

      /* S-Function (sfix_bitop): '<S238>/Wheel_Speed_RR_Valid_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 128U;

      /* ArithShift: '<S238>/Wheel_Speed_RR_Valid_Data_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 7);

      /* DataTypeConversion: '<S238>/Wheel_Speed_RR_Valid_Datacv' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* SignalConversion: '<S237>/Signal Conversion' */
      VCU_CS75_9_30_B.Wheel_Speed_RR = rtb_Wheel_Speed_RR_Data_sat;

      /* SignalConversion: '<S237>/Signal Conversion' */
      VCU_CS75_9_30_B.Wheel_Speed_FL = rtb_Wheel_Speed_FL_Data_sat;

      /* SignalConversion: '<S237>/Signal Conversion' */
      VCU_CS75_9_30_B.Wheel_Speed_FL_Direction = rtb_Wheel_Speed_FL_Direction_sa;

      /* SignalConversion: '<S237>/Signal Conversion' */
      VCU_CS75_9_30_B.Wheel_Speed_FL_Valid = rtb_Wheel_Speed_FL_Valid_Data_s;

      /* SignalConversion: '<S237>/Signal Conversion' */
      VCU_CS75_9_30_B.Wheel_Speed_RR_Direction = rtb_Wheel_Speed_RR_Direction_sa;

      /* SignalConversion: '<S237>/Signal Conversion' */
      VCU_CS75_9_30_B.Wheel_Speed_RR_Valid = rtb_Wheel_Speed_RR_Valid_Datacv;

      /* SignalConversion: '<S237>/Signal Conversion' */
      VCU_CS75_9_30_B.Wheel_Speed_RL = rtb_Wheel_Speed_RL_Data_sat;

      /* SignalConversion: '<S237>/Signal Conversion' */
      VCU_CS75_9_30_B.Wheel_Speed_RL_Direction = rtb_Wheel_Speed_RL_Direction_sa;

      /* SignalConversion: '<S237>/Signal Conversion' */
      VCU_CS75_9_30_B.Wheel_Speed_RL_Valid = rtb_Wheel_Speed_RL_Valid_Data_s;

      /* SignalConversion: '<S237>/Signal Conversion' */
      VCU_CS75_9_30_B.Wheel_Speed_FR = rtb_Wheel_Speed_FR_Data_sat;

      /* SignalConversion: '<S237>/Signal Conversion' */
      VCU_CS75_9_30_B.Wheel_Speed_FR_Direction = rtb_Wheel_Speed_FR_Direction_sa;

      /* SignalConversion: '<S237>/Signal Conversion' */
      VCU_CS75_9_30_B.Wheel_Speed_FR_Valid = rtb_Wheel_Speed_FR_Valid_Data_s;
    }

    /* End of Outputs for SubSystem: '<S236>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S90>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF17RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf17looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_nu= 641;
    VCU_CS75_9_30_B.CANReceive_o5_g= 8;
    VCU_CS75_9_30_B.CANReceive_o2_lw= ec_can_receive(1,17, CAN1BUF17RX);
    VCU_CS75_9_30_B.CANReceive_o4_jq[0]= CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_jq[1]= CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_jq[2]= CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_jq[3]= CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_jq[4]= CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_jq[5]= CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_jq[6]= CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_jq[7]= CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
  }

  /* Call the system: <S90>/ReceiveMessages */

  /* Output and update for function-call system: '<S90>/ReceiveMessages' */
  {
    int32_T rtb_ESP_VehicleSpeed_Status_L;
    real_T rtb_ESP_VehicleSpeed_sat;
    int32_T rtb_ESP_ABSActiveStatus_sat;
    int32_T rtb_ESP_ABSFailStatus_sat;
    int32_T rtb_ESP_BrakePedalStatus_sat;
    int32_T rtb_ESP_Checksum_sat;
    int32_T rtb_ESP_EBDFailStatus_sat;
    int32_T rtb_ESP_ESPActiveStatus_sat;
    int32_T rtb_ESP_ESPFailStatus_sat;
    int32_T rtb_ESP_ESPSwitchStatus_sat;
    int32_T rtb_ESP_RollingCounter_sat;
    real_T rtb_ESP_VehicleSpeed_Statuscv;

    /* Outputs for Enabled SubSystem: '<S251>/Subsystem' incorporates:
     *  EnablePort: '<S252>/Enable'
     */
    if (VCU_CS75_9_30_B.CANReceive_o2_lw > 0) {
      /* DataTypeConversion: '<S253>/ESP_ABSActiveStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L = VCU_CS75_9_30_B.CANReceive_o4_jq[0];

      /* S-Function (sfix_bitop): '<S253>/ESP_ABSActiveStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 128U;

      /* ArithShift: '<S253>/ESP_ABSActiveStatus_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 7);

      /* DataTypeConversion: '<S253>/ESP_ABSActiveStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S253>/ESP_ABSActiveStatus_Ad' */
      rtb_ESP_ABSActiveStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S253>/ESP_ABSActiveStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_ABSActiveStatus_sat;
      rtb_ESP_ABSActiveStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S253>/ESP_ABSFailStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L = VCU_CS75_9_30_B.CANReceive_o4_jq[0];

      /* S-Function (sfix_bitop): '<S253>/ESP_ABSFailStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 8U;

      /* ArithShift: '<S253>/ESP_ABSFailStatus_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 3);

      /* DataTypeConversion: '<S253>/ESP_ABSFailStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S253>/ESP_ABSFailStatus_Ad' */
      rtb_ESP_ABSFailStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S253>/ESP_ABSFailStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_ABSFailStatus_sat;
      rtb_ESP_ABSFailStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S253>/ESP_BrakePedalStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L = VCU_CS75_9_30_B.CANReceive_o4_jq[6];

      /* S-Function (sfix_bitop): '<S253>/ESP_BrakePedalStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 96U;

      /* ArithShift: '<S253>/ESP_BrakePedalStatus_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 5);

      /* DataTypeConversion: '<S253>/ESP_BrakePedalStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S253>/ESP_BrakePedalStatus_Ad' */
      rtb_ESP_BrakePedalStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S253>/ESP_BrakePedalStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_BrakePedalStatus_sat;
      rtb_ESP_BrakePedalStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S253>/ESP_Checksum_Convert' */
      rtb_ESP_VehicleSpeed_Status_L = VCU_CS75_9_30_B.CANReceive_o4_jq[7];

      /* DataTypeConversion: '<S253>/ESP_Checksumcv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S253>/ESP_Checksum_Ad' */
      rtb_ESP_Checksum_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S253>/ESP_Checksum_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_Checksum_sat;
      rtb_ESP_Checksum_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S253>/ESP_EBDFailStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L = VCU_CS75_9_30_B.CANReceive_o4_jq[0];

      /* S-Function (sfix_bitop): '<S253>/ESP_EBDFailStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 4U;

      /* ArithShift: '<S253>/ESP_EBDFailStatus_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 2);

      /* DataTypeConversion: '<S253>/ESP_EBDFailStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S253>/ESP_EBDFailStatus_Ad' */
      rtb_ESP_EBDFailStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S253>/ESP_EBDFailStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_EBDFailStatus_sat;
      rtb_ESP_EBDFailStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S253>/ESP_ESPActiveStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L = VCU_CS75_9_30_B.CANReceive_o4_jq[0];

      /* S-Function (sfix_bitop): '<S253>/ESP_ESPActiveStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 1U;

      /* DataTypeConversion: '<S253>/ESP_ESPActiveStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S253>/ESP_ESPActiveStatus_Ad' */
      rtb_ESP_ESPActiveStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S253>/ESP_ESPActiveStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_ESPActiveStatus_sat;
      rtb_ESP_ESPActiveStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S253>/ESP_ESPFailStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L = VCU_CS75_9_30_B.CANReceive_o4_jq[0];

      /* S-Function (sfix_bitop): '<S253>/ESP_ESPFailStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 16U;

      /* ArithShift: '<S253>/ESP_ESPFailStatus_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 4);

      /* DataTypeConversion: '<S253>/ESP_ESPFailStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S253>/ESP_ESPFailStatus_Ad' */
      rtb_ESP_ESPFailStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S253>/ESP_ESPFailStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_ESPFailStatus_sat;
      rtb_ESP_ESPFailStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S253>/ESP_ESPSwitchStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L = VCU_CS75_9_30_B.CANReceive_o4_jq[0];

      /* S-Function (sfix_bitop): '<S253>/ESP_ESPSwitchStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 2U;

      /* ArithShift: '<S253>/ESP_ESPSwitchStatus_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 1);

      /* DataTypeConversion: '<S253>/ESP_ESPSwitchStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S253>/ESP_ESPSwitchStatus_Ad' */
      rtb_ESP_ESPSwitchStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S253>/ESP_ESPSwitchStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_ESPSwitchStatus_sat;
      rtb_ESP_ESPSwitchStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S253>/ESP_RollingCounter_Convert' */
      rtb_ESP_VehicleSpeed_Status_L = VCU_CS75_9_30_B.CANReceive_o4_jq[6];

      /* S-Function (sfix_bitop): '<S253>/ESP_RollingCounter_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 15U;

      /* DataTypeConversion: '<S253>/ESP_RollingCountercv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S253>/ESP_RollingCounter_Ad' */
      rtb_ESP_RollingCounter_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S253>/ESP_RollingCounter_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_RollingCounter_sat;
      rtb_ESP_RollingCounter_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Product: '<S253>/ESP_VehicleSpeedinput5_P' incorporates:
       *  Constant: '<S253>/ESP_VehicleSpeedinput5_C'
       */
      rtb_ESP_VehicleSpeed_sat = (real_T)VCU_CS75_9_30_B.CANReceive_o4_jq[4] *
        256.0;

      /* Sum: '<S253>/ESP_VehicleSpeedinput5_Ad' */
      rtb_ESP_VehicleSpeed_Statuscv = rtb_ESP_VehicleSpeed_sat + (real_T)
        VCU_CS75_9_30_B.CANReceive_o4_jq[5];

      /* DataTypeConversion: '<S253>/ESP_VehicleSpeed_Convert' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)rtb_ESP_VehicleSpeed_Statuscv;

      /* S-Function (sfix_bitop): '<S253>/ESP_VehicleSpeed_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 8191U;

      /* DataTypeConversion: '<S253>/ESP_VehicleSpeedcv' */
      rtb_ESP_VehicleSpeed_Statuscv = rtb_ESP_VehicleSpeed_Status_L;

      /* Gain: '<S253>/ESP_VehicleSpeed_F' */
      rtb_ESP_VehicleSpeed_Statuscv *= 0.05625;

      /* Sum: '<S253>/ESP_VehicleSpeed_Ad' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Statuscv;

      /* DataTypeConversion: '<S253>/ESP_VehicleSpeed_Status_Convert' */
      rtb_ESP_VehicleSpeed_Status_L = VCU_CS75_9_30_B.CANReceive_o4_jq[4];

      /* S-Function (sfix_bitop): '<S253>/ESP_VehicleSpeed_Status_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 32U;

      /* ArithShift: '<S253>/ESP_VehicleSpeed_Status_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 5);

      /* DataTypeConversion: '<S253>/ESP_VehicleSpeed_Statuscv' */
      rtb_ESP_VehicleSpeed_Statuscv = rtb_ESP_VehicleSpeed_Status_L;

      /* Saturate: '<S253>/ESP_VehicleSpeed_sat' */
      if (rtb_ESP_VehicleSpeed_sat > 360.0) {
        rtb_ESP_VehicleSpeed_sat = 360.0;
      }

      /* End of Saturate: '<S253>/ESP_VehicleSpeed_sat' */

      /* SignalConversion: '<S252>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_ESPActiveStatus_n = rtb_ESP_ESPActiveStatus_sat;

      /* SignalConversion: '<S252>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_BrakePedalStatus = rtb_ESP_BrakePedalStatus_sat;

      /* SignalConversion: '<S252>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_Checksum = rtb_ESP_Checksum_sat;

      /* SignalConversion: '<S252>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_ESPSwitchStatus = rtb_ESP_ESPSwitchStatus_sat;

      /* SignalConversion: '<S252>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_EBDFailStatus_n = rtb_ESP_EBDFailStatus_sat;

      /* SignalConversion: '<S252>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_ABSFailStatus = rtb_ESP_ABSFailStatus_sat;

      /* SignalConversion: '<S252>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_ESPFailStatus = rtb_ESP_ESPFailStatus_sat;

      /* SignalConversion: '<S252>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_ABSActiveStatus = rtb_ESP_ABSActiveStatus_sat;

      /* SignalConversion: '<S252>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_VehicleSpeed = rtb_ESP_VehicleSpeed_sat;

      /* SignalConversion: '<S252>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_VehicleSpeed_Status = rtb_ESP_VehicleSpeed_Statuscv;

      /* SignalConversion: '<S252>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_RollingCounter_j = rtb_ESP_RollingCounter_sat;
    }

    /* End of Outputs for SubSystem: '<S251>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S91>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF18RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf18looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_g0= 647;
    VCU_CS75_9_30_B.CANReceive_o5_cm= 8;
    VCU_CS75_9_30_B.CANReceive_o2_ij= ec_can_receive(1,18, CAN1BUF18RX);
    VCU_CS75_9_30_B.CANReceive_o4_p[0]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_p[1]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_p[2]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_p[3]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_p[4]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_p[5]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_p[6]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_p[7]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
  }

  /* Call the system: <S91>/ReceiveMessages */

  /* Output and update for function-call system: '<S91>/ReceiveMessages' */
  {
    int32_T rtb_ESP_YawRate_Status_L;
    real_T rtb_ESP_LongAcceleration_sat;
    int32_T rtb_ESP_CheckSum_sat;
    int32_T rtb_ESP_HBBActiveStatus_sat;
    int32_T rtb_ESP_HBB_Status_sat;
    int32_T rtb_ESP_HDC_Status_sat;
    int32_T rtb_ESP_HHC_Available_sat;
    real_T rtb_ESP_LatAcceleration_sat;
    int32_T rtb_ESP_LongAccelValid_sat;
    real_T rtb_ESP_TODTorqueMaxLimit_sat;
    int32_T rtb_ESP_RollingCounter_sat;
    int32_T rtb_ESP_TODFastOpenRequest_sat;
    real_T rtb_ESP_YawRate_sat;
    real_T rtb_ESP_YawRate_Statuscv;

    /* Outputs for Enabled SubSystem: '<S265>/Subsystem' incorporates:
     *  EnablePort: '<S266>/Enable'
     */
    if (VCU_CS75_9_30_B.CANReceive_o2_ij > 0) {
      /* DataTypeConversion: '<S267>/ESP_CheckSum_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_9_30_B.CANReceive_o4_p[7];

      /* S-Function (sfix_bitop): '<S267>/ESP_CheckSum_L' */
      rtb_ESP_YawRate_Status_L &= 15U;

      /* DataTypeConversion: '<S267>/ESP_CheckSumcv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S267>/ESP_CheckSum_Ad' */
      rtb_ESP_CheckSum_sat = (int32_T)rtb_ESP_LongAcceleration_sat;

      /* Saturate: '<S267>/ESP_CheckSum_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_CheckSum_sat;
      rtb_ESP_CheckSum_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* DataTypeConversion: '<S267>/ESP_HBBActiveStatus_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_9_30_B.CANReceive_o4_p[6];

      /* S-Function (sfix_bitop): '<S267>/ESP_HBBActiveStatus_L' */
      rtb_ESP_YawRate_Status_L &= 8U;

      /* ArithShift: '<S267>/ESP_HBBActiveStatus_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        3);

      /* DataTypeConversion: '<S267>/ESP_HBBActiveStatuscv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S267>/ESP_HBBActiveStatus_Ad' */
      rtb_ESP_HBBActiveStatus_sat = (int32_T)rtb_ESP_LongAcceleration_sat;

      /* Saturate: '<S267>/ESP_HBBActiveStatus_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_HBBActiveStatus_sat;
      rtb_ESP_HBBActiveStatus_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* DataTypeConversion: '<S267>/ESP_HBB_Status_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_9_30_B.CANReceive_o4_p[6];

      /* S-Function (sfix_bitop): '<S267>/ESP_HBB_Status_L' */
      rtb_ESP_YawRate_Status_L &= 3U;

      /* DataTypeConversion: '<S267>/ESP_HBB_Statuscv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S267>/ESP_HBB_Status_Ad' */
      rtb_ESP_HBB_Status_sat = (int32_T)rtb_ESP_LongAcceleration_sat;

      /* Saturate: '<S267>/ESP_HBB_Status_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_HBB_Status_sat;
      rtb_ESP_HBB_Status_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* DataTypeConversion: '<S267>/ESP_HDC_Status_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_9_30_B.CANReceive_o4_p[0];

      /* S-Function (sfix_bitop): '<S267>/ESP_HDC_Status_L' */
      rtb_ESP_YawRate_Status_L &= 48U;

      /* ArithShift: '<S267>/ESP_HDC_Status_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        4);

      /* DataTypeConversion: '<S267>/ESP_HDC_Statuscv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S267>/ESP_HDC_Status_Ad' */
      rtb_ESP_HDC_Status_sat = (int32_T)rtb_ESP_LongAcceleration_sat;

      /* Saturate: '<S267>/ESP_HDC_Status_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_HDC_Status_sat;
      rtb_ESP_HDC_Status_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* DataTypeConversion: '<S267>/ESP_HHC_Available_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_9_30_B.CANReceive_o4_p[6];

      /* S-Function (sfix_bitop): '<S267>/ESP_HHC_Available_L' */
      rtb_ESP_YawRate_Status_L &= 4U;

      /* ArithShift: '<S267>/ESP_HHC_Available_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        2);

      /* DataTypeConversion: '<S267>/ESP_HHC_Availablecv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S267>/ESP_HHC_Available_Ad' */
      rtb_ESP_HHC_Available_sat = (int32_T)rtb_ESP_LongAcceleration_sat;

      /* Saturate: '<S267>/ESP_HHC_Available_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_HHC_Available_sat;
      rtb_ESP_HHC_Available_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* DataTypeConversion: '<S267>/ESP_LatAcceleration_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_9_30_B.CANReceive_o4_p[2];

      /* DataTypeConversion: '<S267>/ESP_LatAccelerationcv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Gain: '<S267>/ESP_LatAcceleration_F' */
      rtb_ESP_LongAcceleration_sat *= 0.1;

      /* Sum: '<S267>/ESP_LatAcceleration_Ad' incorporates:
       *  Constant: '<S267>/ESP_LatAcceleration_O'
       */
      rtb_ESP_LatAcceleration_sat = rtb_ESP_LongAcceleration_sat +
        -12.699999809265137;

      /* Saturate: '<S267>/ESP_LatAcceleration_sat' */
      if (rtb_ESP_LatAcceleration_sat > 12.7) {
        rtb_ESP_LatAcceleration_sat = 12.7;
      }

      /* End of Saturate: '<S267>/ESP_LatAcceleration_sat' */

      /* DataTypeConversion: '<S267>/ESP_LongAccelValid_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_9_30_B.CANReceive_o4_p[6];

      /* S-Function (sfix_bitop): '<S267>/ESP_LongAccelValid_L' */
      rtb_ESP_YawRate_Status_L &= 64U;

      /* ArithShift: '<S267>/ESP_LongAccelValid_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        6);

      /* DataTypeConversion: '<S267>/ESP_LongAccelValidcv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S267>/ESP_LongAccelValid_Ad' */
      rtb_ESP_LongAccelValid_sat = (int32_T)rtb_ESP_LongAcceleration_sat;

      /* Saturate: '<S267>/ESP_LongAccelValid_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_LongAccelValid_sat;
      rtb_ESP_LongAccelValid_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* Product: '<S267>/ESP_LongAccelerationinput4_P' incorporates:
       *  Constant: '<S267>/ESP_LongAccelerationinput4_C'
       */
      rtb_ESP_LongAcceleration_sat = (real_T)VCU_CS75_9_30_B.CANReceive_o4_p[3] *
        256.0;

      /* Sum: '<S267>/ESP_LongAccelerationinput4_Ad' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_LongAcceleration_sat + (real_T)
        VCU_CS75_9_30_B.CANReceive_o4_p[4];

      /* DataTypeConversion: '<S267>/ESP_LongAcceleration_Convert' */
      rtb_ESP_YawRate_Status_L = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* S-Function (sfix_bitop): '<S267>/ESP_LongAcceleration_L' */
      rtb_ESP_YawRate_Status_L &= 65472U;

      /* ArithShift: '<S267>/ESP_LongAcceleration_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        6);

      /* DataTypeConversion: '<S267>/ESP_LongAccelerationcv' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_YawRate_Status_L;

      /* Gain: '<S267>/ESP_LongAcceleration_F' */
      rtb_ESP_TODTorqueMaxLimit_sat *= 0.03125;

      /* Sum: '<S267>/ESP_LongAcceleration_Ad' incorporates:
       *  Constant: '<S267>/ESP_LongAcceleration_O'
       */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_TODTorqueMaxLimit_sat + -16.0;

      /* DataTypeConversion: '<S267>/ESP_RollingCounter_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_9_30_B.CANReceive_o4_p[7];

      /* S-Function (sfix_bitop): '<S267>/ESP_RollingCounter_L' */
      rtb_ESP_YawRate_Status_L &= 240U;

      /* ArithShift: '<S267>/ESP_RollingCounter_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        4);

      /* DataTypeConversion: '<S267>/ESP_RollingCountercv' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S267>/ESP_RollingCounter_Ad' */
      rtb_ESP_RollingCounter_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* Saturate: '<S267>/ESP_RollingCounter_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_RollingCounter_sat;
      rtb_ESP_RollingCounter_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* DataTypeConversion: '<S267>/ESP_TODFastOpenRequest_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_9_30_B.CANReceive_o4_p[0];

      /* S-Function (sfix_bitop): '<S267>/ESP_TODFastOpenRequest_L' */
      rtb_ESP_YawRate_Status_L &= 192U;

      /* ArithShift: '<S267>/ESP_TODFastOpenRequest_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        6);

      /* DataTypeConversion: '<S267>/ESP_TODFastOpenRequestcv' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S267>/ESP_TODFastOpenRequest_Ad' */
      rtb_ESP_TODFastOpenRequest_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* Saturate: '<S267>/ESP_TODFastOpenRequest_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_TODFastOpenRequest_sat;
      rtb_ESP_TODFastOpenRequest_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* Product: '<S267>/ESP_TODTorqueMaxLimitinput1_P' incorporates:
       *  Constant: '<S267>/ESP_TODTorqueMaxLimitinput1_C'
       */
      rtb_ESP_TODTorqueMaxLimit_sat = (real_T)VCU_CS75_9_30_B.CANReceive_o4_p[0]
        * 256.0;

      /* Sum: '<S267>/ESP_TODTorqueMaxLimitinput1_Ad' */
      rtb_ESP_YawRate_sat = rtb_ESP_TODTorqueMaxLimit_sat + (real_T)
        VCU_CS75_9_30_B.CANReceive_o4_p[1];

      /* DataTypeConversion: '<S267>/ESP_TODTorqueMaxLimit_Convert' */
      rtb_ESP_YawRate_Status_L = (int32_T)rtb_ESP_YawRate_sat;

      /* S-Function (sfix_bitop): '<S267>/ESP_TODTorqueMaxLimit_L' */
      rtb_ESP_YawRate_Status_L &= 4095U;

      /* DataTypeConversion: '<S267>/ESP_TODTorqueMaxLimitcv' */
      rtb_ESP_YawRate_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S267>/ESP_TODTorqueMaxLimit_Ad' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_YawRate_sat;

      /* Product: '<S267>/ESP_YawRateinput5_P' incorporates:
       *  Constant: '<S267>/ESP_YawRateinput5_C'
       */
      rtb_ESP_YawRate_sat = (real_T)VCU_CS75_9_30_B.CANReceive_o4_p[4] * 256.0;

      /* Sum: '<S267>/ESP_YawRateinput5_Ad' */
      rtb_ESP_YawRate_Statuscv = rtb_ESP_YawRate_sat + (real_T)
        VCU_CS75_9_30_B.CANReceive_o4_p[5];

      /* DataTypeConversion: '<S267>/ESP_YawRate_Convert' */
      rtb_ESP_YawRate_Status_L = (int32_T)rtb_ESP_YawRate_Statuscv;

      /* S-Function (sfix_bitop): '<S267>/ESP_YawRate_L' */
      rtb_ESP_YawRate_Status_L &= 16383U;

      /* DataTypeConversion: '<S267>/ESP_YawRatecv' */
      rtb_ESP_YawRate_Statuscv = rtb_ESP_YawRate_Status_L;

      /* Gain: '<S267>/ESP_YawRate_F' */
      rtb_ESP_YawRate_Statuscv *= 0.01;

      /* Sum: '<S267>/ESP_YawRate_Ad' incorporates:
       *  Constant: '<S267>/ESP_YawRate_O'
       */
      rtb_ESP_YawRate_sat = rtb_ESP_YawRate_Statuscv + -81.910003662109375;

      /* DataTypeConversion: '<S267>/ESP_YawRate_Status_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_9_30_B.CANReceive_o4_p[6];

      /* S-Function (sfix_bitop): '<S267>/ESP_YawRate_Status_L' */
      rtb_ESP_YawRate_Status_L &= 128U;

      /* ArithShift: '<S267>/ESP_YawRate_Status_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        7);

      /* DataTypeConversion: '<S267>/ESP_YawRate_Statuscv' */
      rtb_ESP_YawRate_Statuscv = rtb_ESP_YawRate_Status_L;

      /* Saturate: '<S267>/ESP_YawRate_sat' */
      if (rtb_ESP_YawRate_sat > 81.91) {
        rtb_ESP_YawRate_sat = 81.91;
      } else {
        if (rtb_ESP_YawRate_sat < -81.91) {
          rtb_ESP_YawRate_sat = -81.91;
        }
      }

      /* End of Saturate: '<S267>/ESP_YawRate_sat' */

      /* SignalConversion: '<S266>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_TODTorqueMaxLimit = rtb_ESP_TODTorqueMaxLimit_sat;

      /* SignalConversion: '<S266>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_LongAccelValid = rtb_ESP_LongAccelValid_sat;

      /* SignalConversion: '<S266>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_YawRate_Status = rtb_ESP_YawRate_Statuscv;

      /* SignalConversion: '<S266>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_CheckSum = rtb_ESP_CheckSum_sat;

      /* SignalConversion: '<S266>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_RollingCounter = rtb_ESP_RollingCounter_sat;

      /* SignalConversion: '<S266>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_HDC_Status = rtb_ESP_HDC_Status_sat;

      /* SignalConversion: '<S266>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_TODFastOpenRequest = rtb_ESP_TODFastOpenRequest_sat;

      /* SignalConversion: '<S266>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_LatAcceleration = rtb_ESP_LatAcceleration_sat;

      /* SignalConversion: '<S266>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_LongAcceleration = rtb_ESP_LongAcceleration_sat;

      /* SignalConversion: '<S266>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_YawRate = rtb_ESP_YawRate_sat;

      /* SignalConversion: '<S266>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_HBB_Status = rtb_ESP_HBB_Status_sat;

      /* SignalConversion: '<S266>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_HHC_Available_n = rtb_ESP_HHC_Available_sat;

      /* SignalConversion: '<S266>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_HBBActiveStatus = rtb_ESP_HBBActiveStatus_sat;
    }

    /* End of Outputs for SubSystem: '<S265>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S92>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF27RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf27looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_p= 523;
    VCU_CS75_9_30_B.CANReceive_o5_gj= 8;
    VCU_CS75_9_30_B.CANReceive_o2_k= ec_can_receive(1,27, CAN1BUF27RX);
    VCU_CS75_9_30_B.CANReceive_o4_hx[0]= CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_hx[1]= CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_hx[2]= CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_hx[3]= CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_hx[4]= CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_hx[5]= CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_hx[6]= CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_hx[7]= CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
  }

  /* Call the system: <S92>/ReceiveMessages */

  /* Output and update for function-call system: '<S92>/ReceiveMessages' */
  {
    real_T rtb_SAS_SteeringAngle_sat;
    real_T rtb_TCU_ShiftPostionValidcv;
    int32_T rtb_TCU_ShiftPostionValid_L;
    boolean_T rtb_SAS_SteeringAngleROP;
    int32_T rtb_EMS_BrakePedalStatus_sat;
    int32_T rtb_EMS_EngineStartupEnd_sat;
    int32_T rtb_EMS_EngineStatus_sat;
    int32_T rtb_EPB_BrakeLightOnRequest_sat;
    int32_T rtb_EPB_Status_sat_b;
    int32_T rtb_SAS_SteeringAngleValid_sat;
    int32_T rtb_TCU_GearShiftPositon_sat;
    real32_T rtb_SAS_SteeringAnglesubcon;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S281>/Subsystem' incorporates:
     *  EnablePort: '<S282>/Enable'
     */
    if (VCU_CS75_9_30_B.CANReceive_o2_k > 0) {
      /* Product: '<S283>/SAS_SteeringAngleinput4_P' incorporates:
       *  Constant: '<S283>/SAS_SteeringAngleinput4_C'
       */
      rtb_SAS_SteeringAngle_sat = (real_T)VCU_CS75_9_30_B.CANReceive_o4_hx[3] *
        256.0;

      /* Sum: '<S283>/SAS_SteeringAngleinput4_Ad' */
      rtb_TCU_ShiftPostionValidcv = rtb_SAS_SteeringAngle_sat + (real_T)
        VCU_CS75_9_30_B.CANReceive_o4_hx[4];

      /* DataTypeConversion: '<S283>/SAS_SteeringAngle_Convert' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)rtb_TCU_ShiftPostionValidcv;

      /* DataTypeConversion: '<S283>/SAS_SteeringAnglecv' */
      rtb_SAS_SteeringAnglesubcon = (real32_T)rtb_TCU_ShiftPostionValid_L;

      /* RelationalOperator: '<S283>/SAS_SteeringAngleROP' */
      rtb_SAS_SteeringAngleROP = (rtb_SAS_SteeringAnglesubcon >= 32768.0F);

      /* Switch: '<S283>/SAS_SteeringAngleSW' */
      if (rtb_SAS_SteeringAngleROP) {
        /* Sum: '<S283>/SAS_SteeringAnglesubcon' */
        rtb_SAS_SteeringAnglesubcon = 65536.0F - rtb_SAS_SteeringAnglesubcon;

        /* UnaryMinus: '<S283>/SAS_SteeringAngleMinus' */
        rtb_SAS_SteeringAnglesubcon = -rtb_SAS_SteeringAnglesubcon;
      }

      /* End of Switch: '<S283>/SAS_SteeringAngleSW' */

      /* DataTypeConversion: '<S283>/Data Type Conversion' */
      rtb_TCU_ShiftPostionValidcv = rtb_SAS_SteeringAnglesubcon;

      /* DataTypeConversion: '<S283>/EMS_BrakePedalStatus_Convert' */
      rtb_TCU_ShiftPostionValid_L = VCU_CS75_9_30_B.CANReceive_o4_hx[0];

      /* S-Function (sfix_bitop): '<S283>/EMS_BrakePedalStatus_L' */
      rtb_TCU_ShiftPostionValid_L &= 192U;

      /* ArithShift: '<S283>/EMS_BrakePedalStatus_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 6);

      /* DataTypeConversion: '<S283>/EMS_BrakePedalStatuscv' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S283>/EMS_BrakePedalStatus_Ad' */
      rtb_EMS_BrakePedalStatus_sat = (int32_T)rtb_SAS_SteeringAngle_sat;

      /* Saturate: '<S283>/EMS_BrakePedalStatus_sat' */
      u0 = rtb_EMS_BrakePedalStatus_sat;
      rtb_EMS_BrakePedalStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S283>/EMS_EngineStartupEnd_Convert' */
      rtb_TCU_ShiftPostionValid_L = VCU_CS75_9_30_B.CANReceive_o4_hx[1];

      /* S-Function (sfix_bitop): '<S283>/EMS_EngineStartupEnd_L' */
      rtb_TCU_ShiftPostionValid_L &= 48U;

      /* ArithShift: '<S283>/EMS_EngineStartupEnd_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 4);

      /* DataTypeConversion: '<S283>/EMS_EngineStartupEndcv' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S283>/EMS_EngineStartupEnd_Ad' */
      rtb_EMS_EngineStartupEnd_sat = (int32_T)rtb_SAS_SteeringAngle_sat;

      /* Saturate: '<S283>/EMS_EngineStartupEnd_sat' */
      u0 = rtb_EMS_EngineStartupEnd_sat;
      rtb_EMS_EngineStartupEnd_sat = (int32_T)u0;

      /* DataTypeConversion: '<S283>/EMS_EngineStatus_Convert' */
      rtb_TCU_ShiftPostionValid_L = VCU_CS75_9_30_B.CANReceive_o4_hx[0];

      /* S-Function (sfix_bitop): '<S283>/EMS_EngineStatus_L' */
      rtb_TCU_ShiftPostionValid_L &= 48U;

      /* ArithShift: '<S283>/EMS_EngineStatus_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 4);

      /* DataTypeConversion: '<S283>/EMS_EngineStatuscv' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S283>/EMS_EngineStatus_Ad' */
      rtb_EMS_EngineStatus_sat = (int32_T)rtb_SAS_SteeringAngle_sat;

      /* Saturate: '<S283>/EMS_EngineStatus_sat' */
      u0 = rtb_EMS_EngineStatus_sat;
      rtb_EMS_EngineStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S283>/EPB_BrakeLightOnRequest_Convert' */
      rtb_TCU_ShiftPostionValid_L = VCU_CS75_9_30_B.CANReceive_o4_hx[5];

      /* S-Function (sfix_bitop): '<S283>/EPB_BrakeLightOnRequest_L' */
      rtb_TCU_ShiftPostionValid_L &= 6U;

      /* ArithShift: '<S283>/EPB_BrakeLightOnRequest_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 1);

      /* DataTypeConversion: '<S283>/EPB_BrakeLightOnRequestcv' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S283>/EPB_BrakeLightOnRequest_Ad' */
      rtb_EPB_BrakeLightOnRequest_sat = (int32_T)rtb_SAS_SteeringAngle_sat;

      /* Saturate: '<S283>/EPB_BrakeLightOnRequest_sat' */
      u0 = rtb_EPB_BrakeLightOnRequest_sat;
      rtb_EPB_BrakeLightOnRequest_sat = (int32_T)u0;

      /* DataTypeConversion: '<S283>/EPB_Status_Convert' */
      rtb_TCU_ShiftPostionValid_L = VCU_CS75_9_30_B.CANReceive_o4_hx[6];

      /* S-Function (sfix_bitop): '<S283>/EPB_Status_L' */
      rtb_TCU_ShiftPostionValid_L &= 192U;

      /* ArithShift: '<S283>/EPB_Status_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 6);

      /* DataTypeConversion: '<S283>/EPB_Statuscv' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S283>/EPB_Status_Ad' */
      rtb_EPB_Status_sat_b = (int32_T)rtb_SAS_SteeringAngle_sat;

      /* Saturate: '<S283>/EPB_Status_sat' */
      u0 = rtb_EPB_Status_sat_b;
      rtb_EPB_Status_sat_b = (int32_T)u0;

      /* DataTypeConversion: '<S283>/SAS_SteeringAngleValid_Convert' */
      rtb_TCU_ShiftPostionValid_L = VCU_CS75_9_30_B.CANReceive_o4_hx[0];

      /* S-Function (sfix_bitop): '<S283>/SAS_SteeringAngleValid_L' */
      rtb_TCU_ShiftPostionValid_L &= 1U;

      /* DataTypeConversion: '<S283>/SAS_SteeringAngleValidcv' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S283>/SAS_SteeringAngleValid_Ad' */
      rtb_SAS_SteeringAngleValid_sat = (int32_T)rtb_SAS_SteeringAngle_sat;

      /* Saturate: '<S283>/SAS_SteeringAngleValid_sat' */
      u0 = rtb_SAS_SteeringAngleValid_sat;
      rtb_SAS_SteeringAngleValid_sat = (int32_T)u0;

      /* Gain: '<S283>/SAS_SteeringAngle_F' */
      rtb_TCU_ShiftPostionValidcv *= 0.1;

      /* Sum: '<S283>/SAS_SteeringAngle_Ad' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValidcv;

      /* Saturate: '<S283>/SAS_SteeringAngle_sat' */
      if (rtb_SAS_SteeringAngle_sat > 780.0) {
        rtb_SAS_SteeringAngle_sat = 780.0;
      } else {
        if (rtb_SAS_SteeringAngle_sat < -780.0) {
          rtb_SAS_SteeringAngle_sat = -780.0;
        }
      }

      /* End of Saturate: '<S283>/SAS_SteeringAngle_sat' */

      /* DataTypeConversion: '<S283>/TCU_GearShiftPositon_Convert' */
      rtb_TCU_ShiftPostionValid_L = VCU_CS75_9_30_B.CANReceive_o4_hx[5];

      /* S-Function (sfix_bitop): '<S283>/TCU_GearShiftPositon_L' */
      rtb_TCU_ShiftPostionValid_L &= 120U;

      /* ArithShift: '<S283>/TCU_GearShiftPositon_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 3);

      /* DataTypeConversion: '<S283>/TCU_GearShiftPositoncv' */
      rtb_TCU_ShiftPostionValidcv = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S283>/TCU_GearShiftPositon_Ad' */
      rtb_TCU_GearShiftPositon_sat = (int32_T)rtb_TCU_ShiftPostionValidcv;

      /* Saturate: '<S283>/TCU_GearShiftPositon_sat' */
      u0 = rtb_TCU_GearShiftPositon_sat;
      rtb_TCU_GearShiftPositon_sat = (int32_T)u0;

      /* DataTypeConversion: '<S283>/TCU_ShiftPostionValid_Convert' */
      rtb_TCU_ShiftPostionValid_L = VCU_CS75_9_30_B.CANReceive_o4_hx[5];

      /* S-Function (sfix_bitop): '<S283>/TCU_ShiftPostionValid_L' */
      rtb_TCU_ShiftPostionValid_L &= 128U;

      /* ArithShift: '<S283>/TCU_ShiftPostionValid_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 7);

      /* DataTypeConversion: '<S283>/TCU_ShiftPostionValidcv' */
      rtb_TCU_ShiftPostionValidcv = rtb_TCU_ShiftPostionValid_L;

      /* SignalConversion: '<S282>/Signal Conversion' */
      VCU_CS75_9_30_B.SAS_SteeringAngleValid_c = rtb_SAS_SteeringAngleValid_sat;

      /* SignalConversion: '<S282>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_EngineStatus = rtb_EMS_EngineStatus_sat;

      /* SignalConversion: '<S282>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_BrakePedalStatus_o = rtb_EMS_BrakePedalStatus_sat;

      /* SignalConversion: '<S282>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_EngineStartupEnd = rtb_EMS_EngineStartupEnd_sat;

      /* SignalConversion: '<S282>/Signal Conversion' */
      VCU_CS75_9_30_B.SAS_SteeringAngle_i = rtb_SAS_SteeringAngle_sat;

      /* SignalConversion: '<S282>/Signal Conversion' */
      VCU_CS75_9_30_B.EPB_BrakeLightOnRequest = rtb_EPB_BrakeLightOnRequest_sat;

      /* SignalConversion: '<S282>/Signal Conversion' */
      VCU_CS75_9_30_B.TCU_GearShiftPositon = rtb_TCU_GearShiftPositon_sat;

      /* SignalConversion: '<S282>/Signal Conversion' */
      VCU_CS75_9_30_B.TCU_ShiftPostionValid = rtb_TCU_ShiftPostionValidcv;

      /* SignalConversion: '<S282>/Signal Conversion' */
      VCU_CS75_9_30_B.EPB_Status = rtb_EPB_Status_sat_b;
    }

    /* End of Outputs for SubSystem: '<S281>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S93>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF29RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf29looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_ju= 776;
    VCU_CS75_9_30_B.CANReceive_o5_d= 8;
    VCU_CS75_9_30_B.CANReceive_o2_jv= ec_can_receive(1,29, CAN1BUF29RX);
    VCU_CS75_9_30_B.CANReceive_o4_cg[0]= CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_cg[1]= CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_cg[2]= CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_cg[3]= CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_cg[4]= CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_cg[5]= CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_cg[6]= CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_cg[7]= CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
  }

  /* Call the system: <S93>/ReceiveMessages */

  /* Output and update for function-call system: '<S93>/ReceiveMessages' */
  {
    int32_T rtb_IP_TotalOdometerinput6_Ad;
    real_T rtb_IP_TotalOdometer_sat;
    uint32_T rtb_IP_TotalOdometer_Convert;

    /* Outputs for Enabled SubSystem: '<S293>/Subsystem' incorporates:
     *  EnablePort: '<S294>/Enable'
     */
    if (VCU_CS75_9_30_B.CANReceive_o2_jv > 0) {
      /* Product: '<S295>/IP_TotalOdometerinput6_P' incorporates:
       *  Constant: '<S295>/IP_TotalOdometerinput6_C'
       */
      rtb_IP_TotalOdometerinput6_Ad = VCU_CS75_9_30_B.CANReceive_o4_cg[5] << 8;

      /* Product: '<S295>/IP_TotalOdometerinput5_P' incorporates:
       *  Constant: '<S295>/IP_TotalOdometerinput5_C'
       */
      rtb_IP_TotalOdometer_sat = (real_T)VCU_CS75_9_30_B.CANReceive_o4_cg[4] *
        65536.0;

      /* Sum: '<S295>/IP_TotalOdometerinput5_Ad' */
      rtb_IP_TotalOdometer_sat += (real_T)VCU_CS75_9_30_B.CANReceive_o4_cg[6];

      /* Sum: '<S295>/IP_TotalOdometerinput6_Ad' */
      rtb_IP_TotalOdometerinput6_Ad += (int32_T)rtb_IP_TotalOdometer_sat;

      /* DataTypeConversion: '<S295>/IP_TotalOdometer_Convert' */
      rtb_IP_TotalOdometer_Convert = (uint32_T)rtb_IP_TotalOdometerinput6_Ad;

      /* DataTypeConversion: '<S295>/IP_TotalOdometercv' */
      rtb_IP_TotalOdometer_sat = rtb_IP_TotalOdometer_Convert;

      /* Gain: '<S295>/IP_TotalOdometer_F' */
      rtb_IP_TotalOdometer_sat *= 0.1;

      /* Saturate: '<S295>/IP_TotalOdometer_sat' */
      if (rtb_IP_TotalOdometer_sat > 999999.0) {
        rtb_IP_TotalOdometer_sat = 999999.0;
      }

      /* End of Saturate: '<S295>/IP_TotalOdometer_sat' */

      /* SignalConversion: '<S294>/Signal Conversion' */
      VCU_CS75_9_30_B.IP_TotalOdometer = rtb_IP_TotalOdometer_sat;
    }

    /* End of Outputs for SubSystem: '<S293>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S94>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF28RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf28looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_ie= 818;
    VCU_CS75_9_30_B.CANReceive_o5_jk= 8;
    VCU_CS75_9_30_B.CANReceive_o2_b= ec_can_receive(1,28, CAN1BUF28RX);
    VCU_CS75_9_30_B.CANReceive_o4_g[0]= CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_g[1]= CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_g[2]= CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_g[3]= CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_g[4]= CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_g[5]= CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_g[6]= CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_g[7]= CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
  }

  /* Call the system: <S94>/ReceiveMessages */

  /* Output and update for function-call system: '<S94>/ReceiveMessages' */
  {
    real_T rtb_EMS_EngineSpeed_sat;
    real_T rtb_SRS_PassengerBuckleSwitch_j;
    int32_T rtb_SRS_PassengerBuckleSwitch_p;
    int32_T rtb_SAS_SASFailure_sat;
    int32_T rtb_SRS_DriverBuckleSwitchStatu;

    /* Outputs for Enabled SubSystem: '<S297>/Subsystem' incorporates:
     *  EnablePort: '<S298>/Enable'
     */
    if (VCU_CS75_9_30_B.CANReceive_o2_b > 0) {
      /* Product: '<S299>/EMS_EngineSpeedinput6_P' incorporates:
       *  Constant: '<S299>/EMS_EngineSpeedinput6_C'
       */
      rtb_EMS_EngineSpeed_sat = (real_T)VCU_CS75_9_30_B.CANReceive_o4_g[5] *
        256.0;

      /* Sum: '<S299>/EMS_EngineSpeedinput6_Ad' */
      rtb_SRS_PassengerBuckleSwitch_j = rtb_EMS_EngineSpeed_sat + (real_T)
        VCU_CS75_9_30_B.CANReceive_o4_g[6];

      /* DataTypeConversion: '<S299>/EMS_EngineSpeed_Convert' */
      rtb_SRS_PassengerBuckleSwitch_p = (int32_T)rtb_SRS_PassengerBuckleSwitch_j;

      /* DataTypeConversion: '<S299>/EMS_EngineSpeedcv' */
      rtb_SRS_PassengerBuckleSwitch_j = rtb_SRS_PassengerBuckleSwitch_p;

      /* Gain: '<S299>/EMS_EngineSpeed_F' */
      rtb_SRS_PassengerBuckleSwitch_j *= 0.25;

      /* Sum: '<S299>/EMS_EngineSpeed_Ad' */
      rtb_EMS_EngineSpeed_sat = rtb_SRS_PassengerBuckleSwitch_j;

      /* Saturate: '<S299>/EMS_EngineSpeed_sat' */
      if (rtb_EMS_EngineSpeed_sat > 16383.5) {
        rtb_EMS_EngineSpeed_sat = 16383.5;
      }

      /* End of Saturate: '<S299>/EMS_EngineSpeed_sat' */

      /* DataTypeConversion: '<S299>/SAS_SASFailure_Convert' */
      rtb_SRS_PassengerBuckleSwitch_p = VCU_CS75_9_30_B.CANReceive_o4_g[4];

      /* S-Function (sfix_bitop): '<S299>/SAS_SASFailure_L' */
      rtb_SRS_PassengerBuckleSwitch_p &= 16U;

      /* ArithShift: '<S299>/SAS_SASFailure_S' */
      rtb_SRS_PassengerBuckleSwitch_p = (int32_T)((uint32_T)
        rtb_SRS_PassengerBuckleSwitch_p >> 4);

      /* DataTypeConversion: '<S299>/SAS_SASFailurecv' */
      rtb_SRS_PassengerBuckleSwitch_j = rtb_SRS_PassengerBuckleSwitch_p;

      /* Sum: '<S299>/SAS_SASFailure_Ad' */
      rtb_SAS_SASFailure_sat = (int32_T)rtb_SRS_PassengerBuckleSwitch_j;

      /* Saturate: '<S299>/SAS_SASFailure_sat' */
      rtb_SRS_PassengerBuckleSwitch_j = rtb_SAS_SASFailure_sat;
      rtb_SAS_SASFailure_sat = (int32_T)rtb_SRS_PassengerBuckleSwitch_j;

      /* DataTypeConversion: '<S299>/SRS_DriverBuckleSwitchStatus_Convert' */
      rtb_SRS_PassengerBuckleSwitch_p = VCU_CS75_9_30_B.CANReceive_o4_g[3];

      /* S-Function (sfix_bitop): '<S299>/SRS_DriverBuckleSwitchStatus_L' */
      rtb_SRS_PassengerBuckleSwitch_p &= 192U;

      /* ArithShift: '<S299>/SRS_DriverBuckleSwitchStatus_S' */
      rtb_SRS_PassengerBuckleSwitch_p = (int32_T)((uint32_T)
        rtb_SRS_PassengerBuckleSwitch_p >> 6);

      /* DataTypeConversion: '<S299>/SRS_DriverBuckleSwitchStatuscv' */
      rtb_SRS_PassengerBuckleSwitch_j = rtb_SRS_PassengerBuckleSwitch_p;

      /* Sum: '<S299>/SRS_DriverBuckleSwitchStatus_Ad' */
      rtb_SRS_DriverBuckleSwitchStatu = (int32_T)rtb_SRS_PassengerBuckleSwitch_j;

      /* Saturate: '<S299>/SRS_DriverBuckleSwitchStatus_sat' */
      rtb_SRS_PassengerBuckleSwitch_j = rtb_SRS_DriverBuckleSwitchStatu;
      rtb_SRS_DriverBuckleSwitchStatu = (int32_T)rtb_SRS_PassengerBuckleSwitch_j;

      /* DataTypeConversion: '<S299>/SRS_PassengerBuckleSwitchStatus_Convert' */
      rtb_SRS_PassengerBuckleSwitch_p = VCU_CS75_9_30_B.CANReceive_o4_g[3];

      /* S-Function (sfix_bitop): '<S299>/SRS_PassengerBuckleSwitchStatus_L' */
      rtb_SRS_PassengerBuckleSwitch_p &= 48U;

      /* ArithShift: '<S299>/SRS_PassengerBuckleSwitchStatus_S' */
      rtb_SRS_PassengerBuckleSwitch_p = (int32_T)((uint32_T)
        rtb_SRS_PassengerBuckleSwitch_p >> 4);

      /* DataTypeConversion: '<S299>/SRS_PassengerBuckleSwitchStatuscv' */
      rtb_SRS_PassengerBuckleSwitch_j = rtb_SRS_PassengerBuckleSwitch_p;

      /* SignalConversion: '<S298>/Signal Conversion' */
      VCU_CS75_9_30_B.SRS_PassengerBuckleSwitchStatus =
        rtb_SRS_PassengerBuckleSwitch_j;

      /* SignalConversion: '<S298>/Signal Conversion' */
      VCU_CS75_9_30_B.SRS_DriverBuckleSwitchStatus_e =
        rtb_SRS_DriverBuckleSwitchStatu;

      /* SignalConversion: '<S298>/Signal Conversion' */
      VCU_CS75_9_30_B.SAS_SASFailure_h = rtb_SAS_SASFailure_sat;

      /* SignalConversion: '<S298>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_EngineSpeed = rtb_EMS_EngineSpeed_sat;
    }

    /* End of Outputs for SubSystem: '<S297>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S95>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF30RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf30looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_b= 886;
    VCU_CS75_9_30_B.CANReceive_o5_o= 8;
    VCU_CS75_9_30_B.CANReceive_o2_fr= ec_can_receive(1,30, CAN1BUF30RX);
    VCU_CS75_9_30_B.CANReceive_o4_au[0]= CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_au[1]= CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_au[2]= CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_au[3]= CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_au[4]= CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_au[5]= CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_au[6]= CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_au[7]= CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
  }

  /* Call the system: <S95>/ReceiveMessages */

  /* Output and update for function-call system: '<S95>/ReceiveMessages' */
  {
    int32_T rtb_EMS_TorqueConstant_L;
    real_T rtb_EMS_FrictionalTorq_sat;
    int32_T rtb_EMS_ConditionIdle_sat;
    int32_T rtb_EMS_EngineFuelCutOff_sat;
    real_T rtb_EMS_TorqueConstant_F;

    /* Outputs for Enabled SubSystem: '<S304>/Subsystem' incorporates:
     *  EnablePort: '<S305>/Enable'
     */
    if (VCU_CS75_9_30_B.CANReceive_o2_fr > 0) {
      /* DataTypeConversion: '<S306>/EMS_ConditionIdle_Convert' */
      rtb_EMS_TorqueConstant_L = VCU_CS75_9_30_B.CANReceive_o4_au[3];

      /* S-Function (sfix_bitop): '<S306>/EMS_ConditionIdle_L' */
      rtb_EMS_TorqueConstant_L &= 128U;

      /* ArithShift: '<S306>/EMS_ConditionIdle_S' */
      rtb_EMS_TorqueConstant_L = (int32_T)((uint32_T)rtb_EMS_TorqueConstant_L >>
        7);

      /* DataTypeConversion: '<S306>/EMS_ConditionIdlecv' */
      rtb_EMS_FrictionalTorq_sat = rtb_EMS_TorqueConstant_L;

      /* Sum: '<S306>/EMS_ConditionIdle_Ad' */
      rtb_EMS_ConditionIdle_sat = (int32_T)rtb_EMS_FrictionalTorq_sat;

      /* Saturate: '<S306>/EMS_ConditionIdle_sat' */
      rtb_EMS_FrictionalTorq_sat = rtb_EMS_ConditionIdle_sat;
      rtb_EMS_ConditionIdle_sat = (int32_T)rtb_EMS_FrictionalTorq_sat;

      /* DataTypeConversion: '<S306>/EMS_EngineFuelCutOff_Convert' */
      rtb_EMS_TorqueConstant_L = VCU_CS75_9_30_B.CANReceive_o4_au[3];

      /* S-Function (sfix_bitop): '<S306>/EMS_EngineFuelCutOff_L' */
      rtb_EMS_TorqueConstant_L &= 16U;

      /* ArithShift: '<S306>/EMS_EngineFuelCutOff_S' */
      rtb_EMS_TorqueConstant_L = (int32_T)((uint32_T)rtb_EMS_TorqueConstant_L >>
        4);

      /* DataTypeConversion: '<S306>/EMS_EngineFuelCutOffcv' */
      rtb_EMS_FrictionalTorq_sat = rtb_EMS_TorqueConstant_L;

      /* Sum: '<S306>/EMS_EngineFuelCutOff_Ad' */
      rtb_EMS_EngineFuelCutOff_sat = (int32_T)rtb_EMS_FrictionalTorq_sat;

      /* Saturate: '<S306>/EMS_EngineFuelCutOff_sat' */
      rtb_EMS_FrictionalTorq_sat = rtb_EMS_EngineFuelCutOff_sat;
      rtb_EMS_EngineFuelCutOff_sat = (int32_T)rtb_EMS_FrictionalTorq_sat;

      /* Product: '<S306>/EMS_FrictionalTorqinput2_P' incorporates:
       *  Constant: '<S306>/EMS_FrictionalTorqinput2_C'
       */
      rtb_EMS_FrictionalTorq_sat = (real_T)VCU_CS75_9_30_B.CANReceive_o4_au[1] *
        256.0;

      /* Sum: '<S306>/EMS_FrictionalTorqinput2_Ad' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_FrictionalTorq_sat + (real_T)
        VCU_CS75_9_30_B.CANReceive_o4_au[2];

      /* DataTypeConversion: '<S306>/EMS_FrictionalTorq_Convert' */
      rtb_EMS_TorqueConstant_L = (int32_T)rtb_EMS_TorqueConstant_F;

      /* DataTypeConversion: '<S306>/EMS_FrictionalTorqcv' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_TorqueConstant_L;

      /* Gain: '<S306>/EMS_FrictionalTorq_F' */
      rtb_EMS_TorqueConstant_F *= 0.001526;

      /* Sum: '<S306>/EMS_FrictionalTorq_Ad' */
      rtb_EMS_FrictionalTorq_sat = rtb_EMS_TorqueConstant_F;

      /* DataTypeConversion: '<S306>/EMS_TorqueConstant_Convert' */
      rtb_EMS_TorqueConstant_L = VCU_CS75_9_30_B.CANReceive_o4_au[0];

      /* DataTypeConversion: '<S306>/EMS_TorqueConstantcv' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_TorqueConstant_L;

      /* Gain: '<S306>/EMS_TorqueConstant_F' */
      rtb_EMS_TorqueConstant_F *= 10.0;

      /* Saturate: '<S306>/EMS_TorqueConstant_sat' */
      if (rtb_EMS_TorqueConstant_F > 2540.0) {
        rtb_EMS_TorqueConstant_F = 2540.0;
      }

      /* End of Saturate: '<S306>/EMS_TorqueConstant_sat' */

      /* SignalConversion: '<S305>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_TorqueConstant_o = rtb_EMS_TorqueConstant_F;

      /* SignalConversion: '<S305>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_FrictionalTorq = rtb_EMS_FrictionalTorq_sat;

      /* SignalConversion: '<S305>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_EngineFuelCutOff = rtb_EMS_EngineFuelCutOff_sat;

      /* SignalConversion: '<S305>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_ConditionIdle = rtb_EMS_ConditionIdle_sat;
    }

    /* End of Outputs for SubSystem: '<S304>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S96>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF31RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf31looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_lv= 930;
    VCU_CS75_9_30_B.CANReceive_o5_a0= 8;
    VCU_CS75_9_30_B.CANReceive_o2_dx= ec_can_receive(1,31, CAN1BUF31RX);
    VCU_CS75_9_30_B.CANReceive_o4_l[0]= CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_l[1]= CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_l[2]= CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_l[3]= CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_l[4]= CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_l[5]= CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_l[6]= CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_l[7]= CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
  }

  /* Call the system: <S96>/ReceiveMessages */

  /* Output and update for function-call system: '<S96>/ReceiveMessages' */
  {
    int32_T rtb_TCU_WNTLamp_L;
    int32_T rtb_ACC_ACCMode_sat;
    int32_T rtb_EMS_RemindGear_sat;
    int32_T rtb_EMS_RemindShiftGear_sat;
    int32_T rtb_EPB_FunctionLamp_sat;
    int32_T rtb_EPB_SwitchPositionValid_sat;
    int32_T rtb_EPB_SwitchPosition_sat;
    int32_T rtb_EPB_TextDisplay_sat;
    int32_T rtb_EPS_EPSFailed_sat;
    int32_T rtb_EPS_TorqueAssistMode_sat;
    int32_T rtb_ESP_AutoHoldActive_sat;
    int32_T rtb_ESP_AutoHoldAvailable_sat;
    int32_T rtb_ESP_EBDFailStatus_sat;
    int32_T rtb_ESP_ESPActiveStatus_sat;
    int32_T rtb_ESP_ESPFunctionStatus_sat;
    int32_T rtb_ESP_HBBFunctionStatus_sat;
    int32_T rtb_ESP_HDC_STATUS_sat;
    int32_T rtb_ESP_HHC_Active_sat;
    int32_T rtb_ESP_HHC_Available_sat;
    int32_T rtb_SRS_LeftRearBuckleSwitchSts;
    int32_T rtb_SRS_MiddleRearBuckleSwitchS;
    int32_T rtb_SRS_RightRearBuckleSwitchSt;
    int32_T rtb_TCU_FailureLamp_sat;
    int32_T rtb_TCU_GearForDisplay_sat;
    int32_T rtb_TCU_GearIndication_sat;
    int32_T rtb_TCU_PWRLamp_sat;
    int32_T rtb_TCU_ReqTranTempWarning_sat;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S311>/Subsystem' incorporates:
     *  EnablePort: '<S312>/Enable'
     */
    if (VCU_CS75_9_30_B.CANReceive_o2_dx > 0) {
      /* DataTypeConversion: '<S313>/ACC_ACCMode_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_9_30_B.CANReceive_o4_l[1];

      /* S-Function (sfix_bitop): '<S313>/ACC_ACCMode_L' */
      rtb_TCU_WNTLamp_L &= 7U;

      /* Sum: '<S313>/ACC_ACCMode_Ad' */
      rtb_ACC_ACCMode_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S313>/ACC_ACCMode_sat' */
      u0 = rtb_ACC_ACCMode_sat;
      rtb_ACC_ACCMode_sat = (int32_T)u0;

      /* DataTypeConversion: '<S313>/EMS_RemindGear_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_9_30_B.CANReceive_o4_l[0];

      /* S-Function (sfix_bitop): '<S313>/EMS_RemindGear_L' */
      rtb_TCU_WNTLamp_L &= 112U;

      /* ArithShift: '<S313>/EMS_RemindGear_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 4);

      /* Sum: '<S313>/EMS_RemindGear_Ad' */
      rtb_EMS_RemindGear_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S313>/EMS_RemindGear_sat' */
      u0 = rtb_EMS_RemindGear_sat;
      rtb_EMS_RemindGear_sat = (int32_T)u0;

      /* DataTypeConversion: '<S313>/EMS_RemindShiftGear_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_9_30_B.CANReceive_o4_l[7];

      /* S-Function (sfix_bitop): '<S313>/EMS_RemindShiftGear_L' */
      rtb_TCU_WNTLamp_L &= 192U;

      /* ArithShift: '<S313>/EMS_RemindShiftGear_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 6);

      /* Sum: '<S313>/EMS_RemindShiftGear_Ad' */
      rtb_EMS_RemindShiftGear_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S313>/EMS_RemindShiftGear_sat' */
      u0 = rtb_EMS_RemindShiftGear_sat;
      rtb_EMS_RemindShiftGear_sat = (int32_T)u0;

      /* DataTypeConversion: '<S313>/EPB_FunctionLamp_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_9_30_B.CANReceive_o4_l[4];

      /* S-Function (sfix_bitop): '<S313>/EPB_FunctionLamp_L' */
      rtb_TCU_WNTLamp_L &= 24U;

      /* ArithShift: '<S313>/EPB_FunctionLamp_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 3);

      /* Sum: '<S313>/EPB_FunctionLamp_Ad' */
      rtb_EPB_FunctionLamp_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S313>/EPB_FunctionLamp_sat' */
      u0 = rtb_EPB_FunctionLamp_sat;
      rtb_EPB_FunctionLamp_sat = (int32_T)u0;

      /* DataTypeConversion: '<S313>/EPB_SwitchPositionValid_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_9_30_B.CANReceive_o4_l[4];

      /* S-Function (sfix_bitop): '<S313>/EPB_SwitchPositionValid_L' */
      rtb_TCU_WNTLamp_L &= 128U;

      /* ArithShift: '<S313>/EPB_SwitchPositionValid_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 7);

      /* Sum: '<S313>/EPB_SwitchPositionValid_Ad' */
      rtb_EPB_SwitchPositionValid_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S313>/EPB_SwitchPositionValid_sat' */
      u0 = rtb_EPB_SwitchPositionValid_sat;
      rtb_EPB_SwitchPositionValid_sat = (int32_T)u0;

      /* DataTypeConversion: '<S313>/EPB_SwitchPosition_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_9_30_B.CANReceive_o4_l[4];

      /* S-Function (sfix_bitop): '<S313>/EPB_SwitchPosition_L' */
      rtb_TCU_WNTLamp_L &= 96U;

      /* ArithShift: '<S313>/EPB_SwitchPosition_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 5);

      /* Sum: '<S313>/EPB_SwitchPosition_Ad' */
      rtb_EPB_SwitchPosition_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S313>/EPB_SwitchPosition_sat' */
      u0 = rtb_EPB_SwitchPosition_sat;
      rtb_EPB_SwitchPosition_sat = (int32_T)u0;

      /* DataTypeConversion: '<S313>/EPB_TextDisplay_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_9_30_B.CANReceive_o4_l[3];

      /* S-Function (sfix_bitop): '<S313>/EPB_TextDisplay_L' */
      rtb_TCU_WNTLamp_L &= 15U;

      /* Sum: '<S313>/EPB_TextDisplay_Ad' */
      rtb_EPB_TextDisplay_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S313>/EPB_TextDisplay_sat' */
      u0 = rtb_EPB_TextDisplay_sat;
      rtb_EPB_TextDisplay_sat = (int32_T)u0;

      /* DataTypeConversion: '<S313>/EPS_EPSFailed_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_9_30_B.CANReceive_o4_l[4];

      /* S-Function (sfix_bitop): '<S313>/EPS_EPSFailed_L' */
      rtb_TCU_WNTLamp_L &= 2U;

      /* ArithShift: '<S313>/EPS_EPSFailed_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 1);

      /* Sum: '<S313>/EPS_EPSFailed_Ad' */
      rtb_EPS_EPSFailed_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S313>/EPS_EPSFailed_sat' */
      u0 = rtb_EPS_EPSFailed_sat;
      rtb_EPS_EPSFailed_sat = (int32_T)u0;

      /* DataTypeConversion: '<S313>/EPS_TorqueAssistMode_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_9_30_B.CANReceive_o4_l[0];

      /* S-Function (sfix_bitop): '<S313>/EPS_TorqueAssistMode_L' */
      rtb_TCU_WNTLamp_L &= 3U;

      /* Sum: '<S313>/EPS_TorqueAssistMode_Ad' */
      rtb_EPS_TorqueAssistMode_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S313>/EPS_TorqueAssistMode_sat' */
      u0 = rtb_EPS_TorqueAssistMode_sat;
      rtb_EPS_TorqueAssistMode_sat = (int32_T)u0;

      /* DataTypeConversion: '<S313>/ESP_AutoHoldActive_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_9_30_B.CANReceive_o4_l[6];

      /* S-Function (sfix_bitop): '<S313>/ESP_AutoHoldActive_L' */
      rtb_TCU_WNTLamp_L &= 4U;

      /* ArithShift: '<S313>/ESP_AutoHoldActive_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 2);

      /* Sum: '<S313>/ESP_AutoHoldActive_Ad' */
      rtb_ESP_AutoHoldActive_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S313>/ESP_AutoHoldActive_sat' */
      u0 = rtb_ESP_AutoHoldActive_sat;
      rtb_ESP_AutoHoldActive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S313>/ESP_AutoHoldAvailable_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_9_30_B.CANReceive_o4_l[6];

      /* S-Function (sfix_bitop): '<S313>/ESP_AutoHoldAvailable_L' */
      rtb_TCU_WNTLamp_L &= 1U;

      /* Sum: '<S313>/ESP_AutoHoldAvailable_Ad' */
      rtb_ESP_AutoHoldAvailable_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S313>/ESP_AutoHoldAvailable_sat' */
      u0 = rtb_ESP_AutoHoldAvailable_sat;
      rtb_ESP_AutoHoldAvailable_sat = (int32_T)u0;

      /* DataTypeConversion: '<S313>/ESP_EBDFailStatus_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_9_30_B.CANReceive_o4_l[3];

      /* S-Function (sfix_bitop): '<S313>/ESP_EBDFailStatus_L' */
      rtb_TCU_WNTLamp_L &= 128U;

      /* ArithShift: '<S313>/ESP_EBDFailStatus_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 7);

      /* Sum: '<S313>/ESP_EBDFailStatus_Ad' */
      rtb_ESP_EBDFailStatus_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S313>/ESP_EBDFailStatus_sat' */
      u0 = rtb_ESP_EBDFailStatus_sat;
      rtb_ESP_EBDFailStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S313>/ESP_ESPActiveStatus_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_9_30_B.CANReceive_o4_l[3];

      /* S-Function (sfix_bitop): '<S313>/ESP_ESPActiveStatus_L' */
      rtb_TCU_WNTLamp_L &= 32U;

      /* ArithShift: '<S313>/ESP_ESPActiveStatus_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 5);

      /* Sum: '<S313>/ESP_ESPActiveStatus_Ad' */
      rtb_ESP_ESPActiveStatus_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S313>/ESP_ESPActiveStatus_sat' */
      u0 = rtb_ESP_ESPActiveStatus_sat;
      rtb_ESP_ESPActiveStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S313>/ESP_ESPFunctionStatus_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_9_30_B.CANReceive_o4_l[3];

      /* S-Function (sfix_bitop): '<S313>/ESP_ESPFunctionStatus_L' */
      rtb_TCU_WNTLamp_L &= 64U;

      /* ArithShift: '<S313>/ESP_ESPFunctionStatus_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 6);

      /* Sum: '<S313>/ESP_ESPFunctionStatus_Ad' */
      rtb_ESP_ESPFunctionStatus_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S313>/ESP_ESPFunctionStatus_sat' */
      u0 = rtb_ESP_ESPFunctionStatus_sat;
      rtb_ESP_ESPFunctionStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S313>/ESP_HBBFunctionStatus_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_9_30_B.CANReceive_o4_l[7];

      /* S-Function (sfix_bitop): '<S313>/ESP_HBBFunctionStatus_L' */
      rtb_TCU_WNTLamp_L &= 6U;

      /* ArithShift: '<S313>/ESP_HBBFunctionStatus_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 1);

      /* Sum: '<S313>/ESP_HBBFunctionStatus_Ad' */
      rtb_ESP_HBBFunctionStatus_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S313>/ESP_HBBFunctionStatus_sat' */
      u0 = rtb_ESP_HBBFunctionStatus_sat;
      rtb_ESP_HBBFunctionStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S313>/ESP_HDC_STATUS_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_9_30_B.CANReceive_o4_l[5];

      /* S-Function (sfix_bitop): '<S313>/ESP_HDC_STATUS_L' */
      rtb_TCU_WNTLamp_L &= 3U;

      /* Sum: '<S313>/ESP_HDC_STATUS_Ad' */
      rtb_ESP_HDC_STATUS_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S313>/ESP_HDC_STATUS_sat' */
      u0 = rtb_ESP_HDC_STATUS_sat;
      rtb_ESP_HDC_STATUS_sat = (int32_T)u0;

      /* DataTypeConversion: '<S313>/ESP_HHC_Active_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_9_30_B.CANReceive_o4_l[6];

      /* S-Function (sfix_bitop): '<S313>/ESP_HHC_Active_L' */
      rtb_TCU_WNTLamp_L &= 2U;

      /* ArithShift: '<S313>/ESP_HHC_Active_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 1);

      /* Sum: '<S313>/ESP_HHC_Active_Ad' */
      rtb_ESP_HHC_Active_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S313>/ESP_HHC_Active_sat' */
      u0 = rtb_ESP_HHC_Active_sat;
      rtb_ESP_HHC_Active_sat = (int32_T)u0;

      /* DataTypeConversion: '<S313>/ESP_HHC_Available_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_9_30_B.CANReceive_o4_l[6];

      /* S-Function (sfix_bitop): '<S313>/ESP_HHC_Available_L' */
      rtb_TCU_WNTLamp_L &= 8U;

      /* ArithShift: '<S313>/ESP_HHC_Available_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 3);

      /* Sum: '<S313>/ESP_HHC_Available_Ad' */
      rtb_ESP_HHC_Available_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S313>/ESP_HHC_Available_sat' */
      u0 = rtb_ESP_HHC_Available_sat;
      rtb_ESP_HHC_Available_sat = (int32_T)u0;

      /* DataTypeConversion: '<S313>/SRS_LeftRearBuckleSwitchSts_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_9_30_B.CANReceive_o4_l[2];

      /* S-Function (sfix_bitop): '<S313>/SRS_LeftRearBuckleSwitchSts_L' */
      rtb_TCU_WNTLamp_L &= 12U;

      /* ArithShift: '<S313>/SRS_LeftRearBuckleSwitchSts_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 2);

      /* Sum: '<S313>/SRS_LeftRearBuckleSwitchSts_Ad' */
      rtb_SRS_LeftRearBuckleSwitchSts = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S313>/SRS_LeftRearBuckleSwitchSts_sat' */
      u0 = rtb_SRS_LeftRearBuckleSwitchSts;
      rtb_SRS_LeftRearBuckleSwitchSts = (int32_T)u0;

      /* DataTypeConversion: '<S313>/SRS_MiddleRearBuckleSwitchSts_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_9_30_B.CANReceive_o4_l[2];

      /* S-Function (sfix_bitop): '<S313>/SRS_MiddleRearBuckleSwitchSts_L' */
      rtb_TCU_WNTLamp_L &= 48U;

      /* ArithShift: '<S313>/SRS_MiddleRearBuckleSwitchSts_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 4);

      /* Sum: '<S313>/SRS_MiddleRearBuckleSwitchSts_Ad' */
      rtb_SRS_MiddleRearBuckleSwitchS = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S313>/SRS_MiddleRearBuckleSwitchSts_sat' */
      u0 = rtb_SRS_MiddleRearBuckleSwitchS;
      rtb_SRS_MiddleRearBuckleSwitchS = (int32_T)u0;

      /* DataTypeConversion: '<S313>/SRS_RightRearBuckleSwitchSts_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_9_30_B.CANReceive_o4_l[2];

      /* S-Function (sfix_bitop): '<S313>/SRS_RightRearBuckleSwitchSts_L' */
      rtb_TCU_WNTLamp_L &= 192U;

      /* ArithShift: '<S313>/SRS_RightRearBuckleSwitchSts_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 6);

      /* Sum: '<S313>/SRS_RightRearBuckleSwitchSts_Ad' */
      rtb_SRS_RightRearBuckleSwitchSt = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S313>/SRS_RightRearBuckleSwitchSts_sat' */
      u0 = rtb_SRS_RightRearBuckleSwitchSt;
      rtb_SRS_RightRearBuckleSwitchSt = (int32_T)u0;

      /* DataTypeConversion: '<S313>/TCU_FailureLamp_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_9_30_B.CANReceive_o4_l[0];

      /* S-Function (sfix_bitop): '<S313>/TCU_FailureLamp_L' */
      rtb_TCU_WNTLamp_L &= 128U;

      /* ArithShift: '<S313>/TCU_FailureLamp_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 7);

      /* Sum: '<S313>/TCU_FailureLamp_Ad' */
      rtb_TCU_FailureLamp_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S313>/TCU_FailureLamp_sat' */
      u0 = rtb_TCU_FailureLamp_sat;
      rtb_TCU_FailureLamp_sat = (int32_T)u0;

      /* DataTypeConversion: '<S313>/TCU_GearForDisplay_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_9_30_B.CANReceive_o4_l[6];

      /* S-Function (sfix_bitop): '<S313>/TCU_GearForDisplay_L' */
      rtb_TCU_WNTLamp_L &= 240U;

      /* ArithShift: '<S313>/TCU_GearForDisplay_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 4);

      /* Sum: '<S313>/TCU_GearForDisplay_Ad' */
      rtb_TCU_GearForDisplay_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S313>/TCU_GearForDisplay_sat' */
      u0 = rtb_TCU_GearForDisplay_sat;
      rtb_TCU_GearForDisplay_sat = (int32_T)u0;

      /* DataTypeConversion: '<S313>/TCU_GearIndication_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_9_30_B.CANReceive_o4_l[7];

      /* S-Function (sfix_bitop): '<S313>/TCU_GearIndication_L' */
      rtb_TCU_WNTLamp_L &= 8U;

      /* ArithShift: '<S313>/TCU_GearIndication_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 3);

      /* Sum: '<S313>/TCU_GearIndication_Ad' */
      rtb_TCU_GearIndication_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S313>/TCU_GearIndication_sat' */
      u0 = rtb_TCU_GearIndication_sat;
      rtb_TCU_GearIndication_sat = (int32_T)u0;

      /* DataTypeConversion: '<S313>/TCU_PWRLamp_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_9_30_B.CANReceive_o4_l[1];

      /* S-Function (sfix_bitop): '<S313>/TCU_PWRLamp_L' */
      rtb_TCU_WNTLamp_L &= 64U;

      /* ArithShift: '<S313>/TCU_PWRLamp_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 6);

      /* Sum: '<S313>/TCU_PWRLamp_Ad' */
      rtb_TCU_PWRLamp_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S313>/TCU_PWRLamp_sat' */
      u0 = rtb_TCU_PWRLamp_sat;
      rtb_TCU_PWRLamp_sat = (int32_T)u0;

      /* DataTypeConversion: '<S313>/TCU_ReqTranTempWarning_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_9_30_B.CANReceive_o4_l[7];

      /* S-Function (sfix_bitop): '<S313>/TCU_ReqTranTempWarning_L' */
      rtb_TCU_WNTLamp_L &= 48U;

      /* ArithShift: '<S313>/TCU_ReqTranTempWarning_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 4);

      /* Sum: '<S313>/TCU_ReqTranTempWarning_Ad' */
      rtb_TCU_ReqTranTempWarning_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S313>/TCU_ReqTranTempWarning_sat' */
      u0 = rtb_TCU_ReqTranTempWarning_sat;
      rtb_TCU_ReqTranTempWarning_sat = (int32_T)u0;

      /* DataTypeConversion: '<S313>/TCU_WNTLamp_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_9_30_B.CANReceive_o4_l[1];

      /* S-Function (sfix_bitop): '<S313>/TCU_WNTLamp_L' */
      rtb_TCU_WNTLamp_L &= 32U;

      /* ArithShift: '<S313>/TCU_WNTLamp_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 5);

      /* Saturate: '<S313>/TCU_WNTLamp_sat' */
      u0 = rtb_TCU_WNTLamp_L;
      rtb_TCU_WNTLamp_L = (int32_T)u0;

      /* SignalConversion: '<S312>/Signal Conversion' */
      VCU_CS75_9_30_B.EPS_TorqueAssistMode = rtb_EPS_TorqueAssistMode_sat;

      /* SignalConversion: '<S312>/Signal Conversion' */
      VCU_CS75_9_30_B.EPB_TextDisplay = rtb_EPB_TextDisplay_sat;

      /* SignalConversion: '<S312>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_ESPActiveStatus = rtb_ESP_ESPActiveStatus_sat;

      /* SignalConversion: '<S312>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_ESPFunctionStatus = rtb_ESP_ESPFunctionStatus_sat;

      /* SignalConversion: '<S312>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_EBDFailStatus = rtb_ESP_EBDFailStatus_sat;

      /* SignalConversion: '<S312>/Signal Conversion' */
      VCU_CS75_9_30_B.EPS_EPSFailed = rtb_EPS_EPSFailed_sat;

      /* SignalConversion: '<S312>/Signal Conversion' */
      VCU_CS75_9_30_B.EPB_FunctionLamp = rtb_EPB_FunctionLamp_sat;

      /* SignalConversion: '<S312>/Signal Conversion' */
      VCU_CS75_9_30_B.EPB_SwitchPosition = rtb_EPB_SwitchPosition_sat;

      /* SignalConversion: '<S312>/Signal Conversion' */
      VCU_CS75_9_30_B.EPB_SwitchPositionValid = rtb_EPB_SwitchPositionValid_sat;

      /* SignalConversion: '<S312>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_HDC_STATUS = rtb_ESP_HDC_STATUS_sat;

      /* SignalConversion: '<S312>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_AutoHoldAvailable = rtb_ESP_AutoHoldAvailable_sat;

      /* SignalConversion: '<S312>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_RemindGear = rtb_EMS_RemindGear_sat;

      /* SignalConversion: '<S312>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_HHC_Active = rtb_ESP_HHC_Active_sat;

      /* SignalConversion: '<S312>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_AutoHoldActive = rtb_ESP_AutoHoldActive_sat;

      /* SignalConversion: '<S312>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_HHC_Available = rtb_ESP_HHC_Available_sat;

      /* SignalConversion: '<S312>/Signal Conversion' */
      VCU_CS75_9_30_B.TCU_GearForDisplay = rtb_TCU_GearForDisplay_sat;

      /* SignalConversion: '<S312>/Signal Conversion' */
      VCU_CS75_9_30_B.ESP_HBBFunctionStatus = rtb_ESP_HBBFunctionStatus_sat;

      /* SignalConversion: '<S312>/Signal Conversion' */
      VCU_CS75_9_30_B.TCU_GearIndication = rtb_TCU_GearIndication_sat;

      /* SignalConversion: '<S312>/Signal Conversion' */
      VCU_CS75_9_30_B.TCU_ReqTranTempWarning = rtb_TCU_ReqTranTempWarning_sat;

      /* SignalConversion: '<S312>/Signal Conversion' */
      VCU_CS75_9_30_B.EMS_RemindShiftGear = rtb_EMS_RemindShiftGear_sat;

      /* SignalConversion: '<S312>/Signal Conversion' */
      VCU_CS75_9_30_B.TCU_FailureLamp = rtb_TCU_FailureLamp_sat;

      /* SignalConversion: '<S312>/Signal Conversion' */
      VCU_CS75_9_30_B.ACC_ACCMode = rtb_ACC_ACCMode_sat;

      /* SignalConversion: '<S312>/Signal Conversion' */
      VCU_CS75_9_30_B.TCU_WNTLamp = rtb_TCU_WNTLamp_L;

      /* SignalConversion: '<S312>/Signal Conversion' */
      VCU_CS75_9_30_B.TCU_PWRLamp = rtb_TCU_PWRLamp_sat;

      /* SignalConversion: '<S312>/Signal Conversion' */
      VCU_CS75_9_30_B.SRS_LeftRearBuckleSwitchSts =
        rtb_SRS_LeftRearBuckleSwitchSts;

      /* SignalConversion: '<S312>/Signal Conversion' */
      VCU_CS75_9_30_B.SRS_MiddleRearBuckleSwitchSts =
        rtb_SRS_MiddleRearBuckleSwitchS;

      /* SignalConversion: '<S312>/Signal Conversion' */
      VCU_CS75_9_30_B.SRS_RightRearBuckleSwitchSts =
        rtb_SRS_RightRearBuckleSwitchSt;
    }

    /* End of Outputs for SubSystem: '<S311>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S97>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF32RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf32looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_i4= 1383;
    VCU_CS75_9_30_B.CANReceive_o5_f= 8;
    VCU_CS75_9_30_B.CANReceive_o2_in= ec_can_receive(1,32, CAN1BUF32RX);
    VCU_CS75_9_30_B.CANReceive_o4_m[0]= CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_m[1]= CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_m[2]= CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_m[3]= CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_m[4]= CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_m[5]= CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_m[6]= CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_m[7]= CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
  }

  /* Call the system: <S97>/ReceiveMessages */

  /* Output and update for function-call system: '<S97>/ReceiveMessages' */
  {
    int32_T rtb_HU_TunnelLength_L;
    int32_T rtb_HU_Byroad_sat;
    int32_T rtb_HU_EnterTunnelInfo_sat;
    int32_T rtb_HU_NavGuiganceStatus_sat;
    int32_T rtb_HU_TunnelDistance_sat;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S341>/Subsystem' incorporates:
     *  EnablePort: '<S342>/Enable'
     */
    if (VCU_CS75_9_30_B.CANReceive_o2_in > 0) {
      /* DataTypeConversion: '<S343>/HU_Byroad_Convert' */
      rtb_HU_TunnelLength_L = VCU_CS75_9_30_B.CANReceive_o4_m[4];

      /* S-Function (sfix_bitop): '<S343>/HU_Byroad_L' */
      rtb_HU_TunnelLength_L &= 192U;

      /* ArithShift: '<S343>/HU_Byroad_S' */
      rtb_HU_TunnelLength_L = (int32_T)((uint32_T)rtb_HU_TunnelLength_L >> 6);

      /* Sum: '<S343>/HU_Byroad_Ad' */
      rtb_HU_Byroad_sat = rtb_HU_TunnelLength_L;

      /* Saturate: '<S343>/HU_Byroad_sat' */
      u0 = rtb_HU_Byroad_sat;
      rtb_HU_Byroad_sat = (int32_T)u0;

      /* DataTypeConversion: '<S343>/HU_EnterTunnelInfo_Convert' */
      rtb_HU_TunnelLength_L = VCU_CS75_9_30_B.CANReceive_o4_m[0];

      /* S-Function (sfix_bitop): '<S343>/HU_EnterTunnelInfo_L' */
      rtb_HU_TunnelLength_L &= 12U;

      /* ArithShift: '<S343>/HU_EnterTunnelInfo_S' */
      rtb_HU_TunnelLength_L = (int32_T)((uint32_T)rtb_HU_TunnelLength_L >> 2);

      /* Sum: '<S343>/HU_EnterTunnelInfo_Ad' */
      rtb_HU_EnterTunnelInfo_sat = rtb_HU_TunnelLength_L;

      /* Saturate: '<S343>/HU_EnterTunnelInfo_sat' */
      u0 = rtb_HU_EnterTunnelInfo_sat;
      rtb_HU_EnterTunnelInfo_sat = (int32_T)u0;

      /* DataTypeConversion: '<S343>/HU_NavGuiganceStatus_Convert' */
      rtb_HU_TunnelLength_L = VCU_CS75_9_30_B.CANReceive_o4_m[5];

      /* S-Function (sfix_bitop): '<S343>/HU_NavGuiganceStatus_L' */
      rtb_HU_TunnelLength_L &= 192U;

      /* ArithShift: '<S343>/HU_NavGuiganceStatus_S' */
      rtb_HU_TunnelLength_L = (int32_T)((uint32_T)rtb_HU_TunnelLength_L >> 6);

      /* Sum: '<S343>/HU_NavGuiganceStatus_Ad' */
      rtb_HU_NavGuiganceStatus_sat = rtb_HU_TunnelLength_L;

      /* Saturate: '<S343>/HU_NavGuiganceStatus_sat' */
      u0 = rtb_HU_NavGuiganceStatus_sat;
      rtb_HU_NavGuiganceStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S343>/HU_TunnelDistance_Convert' */
      rtb_HU_TunnelLength_L = VCU_CS75_9_30_B.CANReceive_o4_m[2];

      /* S-Function (sfix_bitop): '<S343>/HU_TunnelDistance_L' */
      rtb_HU_TunnelLength_L &= 252U;

      /* ArithShift: '<S343>/HU_TunnelDistance_S' */
      rtb_HU_TunnelLength_L = (int32_T)((uint32_T)rtb_HU_TunnelLength_L >> 2);

      /* Gain: '<S343>/HU_TunnelDistance_F' */
      rtb_HU_TunnelLength_L *= 10;

      /* Sum: '<S343>/HU_TunnelDistance_Ad' */
      rtb_HU_TunnelDistance_sat = rtb_HU_TunnelLength_L;

      /* Saturate: '<S343>/HU_TunnelDistance_sat' */
      u0 = rtb_HU_TunnelDistance_sat;
      if (u0 > 600.0) {
        u0 = 600.0;
      }

      rtb_HU_TunnelDistance_sat = (int32_T)u0;

      /* End of Saturate: '<S343>/HU_TunnelDistance_sat' */

      /* DataTypeConversion: '<S343>/HU_TunnelLength_Convert' */
      rtb_HU_TunnelLength_L = VCU_CS75_9_30_B.CANReceive_o4_m[4];

      /* S-Function (sfix_bitop): '<S343>/HU_TunnelLength_L' */
      rtb_HU_TunnelLength_L &= 63U;

      /* Saturate: '<S343>/HU_TunnelLength_sat' */
      u0 = rtb_HU_TunnelLength_L;
      rtb_HU_TunnelLength_L = (int32_T)u0;

      /* SignalConversion: '<S342>/Signal Conversion' */
      VCU_CS75_9_30_B.HU_EnterTunnelInfo = rtb_HU_EnterTunnelInfo_sat;

      /* SignalConversion: '<S342>/Signal Conversion' */
      VCU_CS75_9_30_B.HU_TunnelDistance = rtb_HU_TunnelDistance_sat;

      /* SignalConversion: '<S342>/Signal Conversion' */
      VCU_CS75_9_30_B.HU_TunnelLength = rtb_HU_TunnelLength_L;

      /* SignalConversion: '<S342>/Signal Conversion' */
      VCU_CS75_9_30_B.HU_Byroad = rtb_HU_Byroad_sat;

      /* SignalConversion: '<S342>/Signal Conversion' */
      VCU_CS75_9_30_B.HU_NavGuiganceStatus = rtb_HU_NavGuiganceStatus_sat;
    }

    /* End of Outputs for SubSystem: '<S341>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S98>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF33RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf33looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_pp= 1280;
    VCU_CS75_9_30_B.CANReceive_o5_l4= 8;
    VCU_CS75_9_30_B.CANReceive_o2_h= ec_can_receive(1,33, CAN1BUF33RX);
    VCU_CS75_9_30_B.CANReceive_o4_e4[0]= CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_e4[1]= CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_e4[2]= CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_e4[3]= CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_e4[4]= CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_e4[5]= CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_e4[6]= CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_e4[7]= CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
  }

  /* Call the system: <S98>/ReceiveMessages */

  /* Output and update for function-call system: '<S98>/ReceiveMessages' */

  /* Outputs for Enabled SubSystem: '<S349>/Subsystem' incorporates:
   *  EnablePort: '<S350>/Enable'
   */
  if (VCU_CS75_9_30_B.CANReceive_o2_h > 0) {
    /* SignalConversion: '<S350>/Signal Conversion' */
    VCU_CS75_9_30_B.GPSCurrentLocationValid = 0.0;
  }

  /* End of Outputs for SubSystem: '<S349>/Subsystem' */

  /* S-Function (ec5744_canreceiveslb): '<S99>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF36RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf36looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_kl= 878;
    VCU_CS75_9_30_B.CANReceive_o5_hd= 8;
    VCU_CS75_9_30_B.CANReceive_o2_h5= ec_can_receive(1,36, CAN1BUF36RX);
    VCU_CS75_9_30_B.CANReceive_o4_bw[0]= CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_bw[1]= CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_bw[2]= CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_bw[3]= CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_bw[4]= CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_bw[5]= CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_bw[6]= CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_bw[7]= CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
  }

  /* Call the system: <S99>/ReceiveMessages */

  /* Output and update for function-call system: '<S99>/ReceiveMessages' */
  {
    uint32_T rtb_LAS_RollingCounter_id36E_L;
    int32_T rtb_LAS_LaneEquationStatus_sat;
    int32_T rtb_LAS_CheckSum_id36E_sat;
    real_T rtb_LAS_LaneEquationC1_sat;
    real_T rtb_LAS_LaneEquationC3_sat;
    real_T rtb_LAS_RoadCurvatureFar_sat;
    real_T rtb_LAS_RollingCounter_id36Ecv;
    real_T rtb_LAS_RoadCurvatureNear_sat;

    /* Outputs for Enabled SubSystem: '<S353>/Subsystem' incorporates:
     *  EnablePort: '<S354>/Enable'
     */
    if (VCU_CS75_9_30_B.CANReceive_o2_h5 > 0) {
      /* DataTypeConversion: '<S355>/LAS_CheckSum_id36E_Convert' */
      rtb_LAS_RollingCounter_id36E_L = VCU_CS75_9_30_B.CANReceive_o4_bw[7];

      /* DataTypeConversion: '<S355>/LAS_CheckSum_id36Ecv' */
      rtb_LAS_LaneEquationStatus_sat = (int32_T)rtb_LAS_RollingCounter_id36E_L;

      /* Sum: '<S355>/LAS_CheckSum_id36E_Ad' */
      rtb_LAS_CheckSum_id36E_sat = rtb_LAS_LaneEquationStatus_sat;

      /* Saturate: '<S355>/LAS_CheckSum_id36E_sat' */
      rtb_LAS_RoadCurvatureFar_sat = rtb_LAS_CheckSum_id36E_sat;
      rtb_LAS_CheckSum_id36E_sat = (int32_T)rtb_LAS_RoadCurvatureFar_sat;

      /* Product: '<S355>/LAS_LaneEquationC1input3_P' incorporates:
       *  Constant: '<S355>/LAS_LaneEquationC1input3_C'
       */
      rtb_LAS_LaneEquationStatus_sat = VCU_CS75_9_30_B.CANReceive_o4_bw[2] << 8;

      /* Product: '<S355>/LAS_LaneEquationC1input2_P' incorporates:
       *  Constant: '<S355>/LAS_LaneEquationC1input2_C'
       */
      rtb_LAS_LaneEquationC1_sat = (real_T)VCU_CS75_9_30_B.CANReceive_o4_bw[1] *
        65536.0;

      /* Sum: '<S355>/LAS_LaneEquationC1input2_Ad' */
      rtb_LAS_LaneEquationC3_sat = rtb_LAS_LaneEquationC1_sat + (real_T)
        VCU_CS75_9_30_B.CANReceive_o4_bw[3];

      /* Sum: '<S355>/LAS_LaneEquationC1input3_Ad' */
      rtb_LAS_LaneEquationStatus_sat += (int32_T)rtb_LAS_LaneEquationC3_sat;

      /* DataTypeConversion: '<S355>/LAS_LaneEquationC1_Convert' */
      rtb_LAS_RollingCounter_id36E_L = (uint32_T)rtb_LAS_LaneEquationStatus_sat;

      /* S-Function (sfix_bitop): '<S355>/LAS_LaneEquationC1_L' */
      rtb_LAS_RollingCounter_id36E_L &= 262080U;

      /* ArithShift: '<S355>/LAS_LaneEquationC1_S' */
      rtb_LAS_RollingCounter_id36E_L >>= 6;

      /* DataTypeConversion: '<S355>/LAS_LaneEquationC1cv' */
      rtb_LAS_LaneEquationC3_sat = rtb_LAS_RollingCounter_id36E_L;

      /* Gain: '<S355>/LAS_LaneEquationC1_F' */
      rtb_LAS_LaneEquationC3_sat *= 0.00048828125;

      /* Sum: '<S355>/LAS_LaneEquationC1_Ad' incorporates:
       *  Constant: '<S355>/LAS_LaneEquationC1_O'
       */
      rtb_LAS_LaneEquationC1_sat = rtb_LAS_LaneEquationC3_sat + -1.0;

      /* Saturate: '<S355>/LAS_LaneEquationC1_sat' */
      if (rtb_LAS_LaneEquationC1_sat > 0.9990234375) {
        rtb_LAS_LaneEquationC1_sat = 0.9990234375;
      }

      /* End of Saturate: '<S355>/LAS_LaneEquationC1_sat' */

      /* Product: '<S355>/LAS_LaneEquationC3input6_P' incorporates:
       *  Constant: '<S355>/LAS_LaneEquationC3input6_C'
       */
      rtb_LAS_LaneEquationC3_sat = (real_T)VCU_CS75_9_30_B.CANReceive_o4_bw[5] *
        256.0;

      /* Product: '<S355>/LAS_LaneEquationC3input5_P' incorporates:
       *  Constant: '<S355>/LAS_LaneEquationC3input5_C'
       */
      rtb_LAS_LaneEquationStatus_sat = VCU_CS75_9_30_B.CANReceive_o4_bw[4] *
        65536;

      /* Sum: '<S355>/LAS_LaneEquationC3input5_Ad' */
      rtb_LAS_RoadCurvatureFar_sat = rtb_LAS_LaneEquationStatus_sat +
        VCU_CS75_9_30_B.CANReceive_o4_bw[6];

      /* Sum: '<S355>/LAS_LaneEquationC3input6_Ad' */
      rtb_LAS_LaneEquationC3_sat += rtb_LAS_RoadCurvatureFar_sat;

      /* DataTypeConversion: '<S355>/LAS_LaneEquationC3_Convert' */
      rtb_LAS_RollingCounter_id36E_L = (uint32_T)rtb_LAS_LaneEquationC3_sat;

      /* S-Function (sfix_bitop): '<S355>/LAS_LaneEquationC3_L' */
      rtb_LAS_RollingCounter_id36E_L &= 262080U;

      /* ArithShift: '<S355>/LAS_LaneEquationC3_S' */
      rtb_LAS_RollingCounter_id36E_L >>= 6;

      /* DataTypeConversion: '<S355>/LAS_LaneEquationC3cv' */
      rtb_LAS_RoadCurvatureFar_sat = rtb_LAS_RollingCounter_id36E_L;

      /* Gain: '<S355>/LAS_LaneEquationC3_F' */
      rtb_LAS_RoadCurvatureFar_sat *= 4.76837158203125;

      /* Sum: '<S355>/LAS_LaneEquationC3_Ad' incorporates:
       *  Constant: '<S355>/LAS_LaneEquationC3_O'
       */
      rtb_LAS_LaneEquationC3_sat = rtb_LAS_RoadCurvatureFar_sat +
        -0.00097608566284179688;

      /* Saturate: '<S355>/LAS_LaneEquationC3_sat' */
      if (rtb_LAS_LaneEquationC3_sat > 0.000976085662841796) {
        rtb_LAS_LaneEquationC3_sat = 0.000976085662841796;
      } else {
        if (rtb_LAS_LaneEquationC3_sat < -0.000976085662841796) {
          rtb_LAS_LaneEquationC3_sat = -0.000976085662841796;
        }
      }

      /* End of Saturate: '<S355>/LAS_LaneEquationC3_sat' */

      /* DataTypeConversion: '<S355>/LAS_LaneEquationStatus_Convert' */
      rtb_LAS_RollingCounter_id36E_L = VCU_CS75_9_30_B.CANReceive_o4_bw[6];

      /* S-Function (sfix_bitop): '<S355>/LAS_LaneEquationStatus_L' */
      rtb_LAS_RollingCounter_id36E_L &= 48U;

      /* ArithShift: '<S355>/LAS_LaneEquationStatus_S' */
      rtb_LAS_RollingCounter_id36E_L >>= 4;

      /* DataTypeConversion: '<S355>/LAS_LaneEquationStatuscv' */
      rtb_LAS_RoadCurvatureFar_sat = rtb_LAS_RollingCounter_id36E_L;

      /* Sum: '<S355>/LAS_LaneEquationStatus_Ad' */
      rtb_LAS_LaneEquationStatus_sat = (int32_T)rtb_LAS_RoadCurvatureFar_sat;

      /* Saturate: '<S355>/LAS_LaneEquationStatus_sat' */
      rtb_LAS_RoadCurvatureFar_sat = rtb_LAS_LaneEquationStatus_sat;
      rtb_LAS_LaneEquationStatus_sat = (int32_T)rtb_LAS_RoadCurvatureFar_sat;

      /* Product: '<S355>/LAS_RoadCurvatureFarinput1_P' incorporates:
       *  Constant: '<S355>/LAS_RoadCurvatureFarinput1_C'
       */
      rtb_LAS_RoadCurvatureFar_sat = (real_T)VCU_CS75_9_30_B.CANReceive_o4_bw[0]
        * 256.0;

      /* Sum: '<S355>/LAS_RoadCurvatureFarinput1_Ad' */
      rtb_LAS_RollingCounter_id36Ecv = rtb_LAS_RoadCurvatureFar_sat + (real_T)
        VCU_CS75_9_30_B.CANReceive_o4_bw[1];

      /* DataTypeConversion: '<S355>/LAS_RoadCurvatureFar_Convert' */
      rtb_LAS_RollingCounter_id36E_L = (uint32_T)rtb_LAS_RollingCounter_id36Ecv;

      /* S-Function (sfix_bitop): '<S355>/LAS_RoadCurvatureFar_L' */
      rtb_LAS_RollingCounter_id36E_L &= 508U;

      /* ArithShift: '<S355>/LAS_RoadCurvatureFar_S' */
      rtb_LAS_RollingCounter_id36E_L >>= 2;

      /* DataTypeConversion: '<S355>/LAS_RoadCurvatureFarcv' */
      rtb_LAS_RollingCounter_id36Ecv = rtb_LAS_RollingCounter_id36E_L;

      /* Gain: '<S355>/LAS_RoadCurvatureFar_F' */
      rtb_LAS_RollingCounter_id36Ecv *= 0.0005;

      /* Sum: '<S355>/LAS_RoadCurvatureFar_Ad' incorporates:
       *  Constant: '<S355>/LAS_RoadCurvatureFar_O'
       */
      rtb_LAS_RoadCurvatureFar_sat = rtb_LAS_RollingCounter_id36Ecv +
        -0.029999999329447746;

      /* Saturate: '<S355>/LAS_RoadCurvatureFar_sat' */
      if (rtb_LAS_RoadCurvatureFar_sat > 0.03) {
        rtb_LAS_RoadCurvatureFar_sat = 0.03;
      }

      /* End of Saturate: '<S355>/LAS_RoadCurvatureFar_sat' */

      /* DataTypeConversion: '<S355>/LAS_RoadCurvatureNear_Convert' */
      rtb_LAS_RollingCounter_id36E_L = VCU_CS75_9_30_B.CANReceive_o4_bw[0];

      /* S-Function (sfix_bitop): '<S355>/LAS_RoadCurvatureNear_L' */
      rtb_LAS_RollingCounter_id36E_L &= 254U;

      /* ArithShift: '<S355>/LAS_RoadCurvatureNear_S' */
      rtb_LAS_RollingCounter_id36E_L >>= 1;

      /* DataTypeConversion: '<S355>/LAS_RoadCurvatureNearcv' */
      rtb_LAS_RollingCounter_id36Ecv = rtb_LAS_RollingCounter_id36E_L;

      /* Gain: '<S355>/LAS_RoadCurvatureNear_F' */
      rtb_LAS_RollingCounter_id36Ecv *= 0.0005;

      /* Sum: '<S355>/LAS_RoadCurvatureNear_Ad' incorporates:
       *  Constant: '<S355>/LAS_RoadCurvatureNear_O'
       */
      rtb_LAS_RoadCurvatureNear_sat = rtb_LAS_RollingCounter_id36Ecv +
        -0.029999999329447746;

      /* Saturate: '<S355>/LAS_RoadCurvatureNear_sat' */
      if (rtb_LAS_RoadCurvatureNear_sat > 0.03) {
        rtb_LAS_RoadCurvatureNear_sat = 0.03;
      }

      /* End of Saturate: '<S355>/LAS_RoadCurvatureNear_sat' */

      /* DataTypeConversion: '<S355>/LAS_RollingCounter_id36E_Convert' */
      rtb_LAS_RollingCounter_id36E_L = VCU_CS75_9_30_B.CANReceive_o4_bw[6];

      /* S-Function (sfix_bitop): '<S355>/LAS_RollingCounter_id36E_L' */
      rtb_LAS_RollingCounter_id36E_L &= 15U;

      /* DataTypeConversion: '<S355>/LAS_RollingCounter_id36Ecv' */
      rtb_LAS_RollingCounter_id36Ecv = rtb_LAS_RollingCounter_id36E_L;

      /* SignalConversion: '<S354>/Signal Conversion' */
      VCU_CS75_9_30_B.LAS_RoadCurvatureFar = rtb_LAS_RoadCurvatureFar_sat;

      /* SignalConversion: '<S354>/Signal Conversion' */
      VCU_CS75_9_30_B.LAS_RoadCurvatureNear = rtb_LAS_RoadCurvatureNear_sat;

      /* SignalConversion: '<S354>/Signal Conversion' */
      VCU_CS75_9_30_B.LAS_LaneEquationC1 = rtb_LAS_LaneEquationC1_sat;

      /* SignalConversion: '<S354>/Signal Conversion' */
      VCU_CS75_9_30_B.LAS_LaneEquationC3 = rtb_LAS_LaneEquationC3_sat;

      /* SignalConversion: '<S354>/Signal Conversion' */
      VCU_CS75_9_30_B.LAS_RollingCounter_id36E = rtb_LAS_RollingCounter_id36Ecv;

      /* SignalConversion: '<S354>/Signal Conversion' */
      VCU_CS75_9_30_B.LAS_LaneEquationStatus = rtb_LAS_LaneEquationStatus_sat;

      /* SignalConversion: '<S354>/Signal Conversion' */
      VCU_CS75_9_30_B.LAS_CheckSum_id36E = rtb_LAS_CheckSum_id36E_sat;
    }

    /* End of Outputs for SubSystem: '<S353>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S100>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF19RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf19looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_g1= 264;
    VCU_CS75_9_30_B.CANReceive_o5_gw= 8;
    VCU_CS75_9_30_B.CANReceive_o2_gw= ec_can_receive(1,19, CAN1BUF19RX);
    VCU_CS75_9_30_B.CANReceive_o4_ge[0]= CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_ge[1]= CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_ge[2]= CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_ge[3]= CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_ge[4]= CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_ge[5]= CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_ge[6]= CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_ge[7]= CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
  }

  /* Call the system: <S100>/ReceiveMessages */

  /* Output and update for function-call system: '<S100>/ReceiveMessages' */
  {
    real_T rtb_SAS_SteeringAngle_Ad;
    real_T rtb_SAS_SteeringAngle_F;
    int32_T rtb_SAS_SteeringAngleValid_L;
    boolean_T rtb_SAS_SteeringAngleROP;
    int32_T rtb_SAS_CRCCheck_sat;
    int32_T rtb_SAS_Calibrated_sat;
    int32_T rtb_SAS_RollingCounter_sat;
    int32_T rtb_SAS_SASFailure_sat;
    int32_T rtb_SAS_SteeringAngleSpeed_sat;
    real32_T rtb_SAS_SteeringAnglesubcon;

    /* Outputs for Enabled SubSystem: '<S363>/Subsystem' incorporates:
     *  EnablePort: '<S364>/Enable'
     */
    if (VCU_CS75_9_30_B.CANReceive_o2_gw > 0) {
      /* Product: '<S365>/SAS_SteeringAngleinput1_P' incorporates:
       *  Constant: '<S365>/SAS_SteeringAngleinput1_C'
       */
      rtb_SAS_SteeringAngle_Ad = (real_T)VCU_CS75_9_30_B.CANReceive_o4_ge[0] *
        256.0;

      /* Sum: '<S365>/SAS_SteeringAngleinput1_Ad' */
      rtb_SAS_SteeringAngle_F = rtb_SAS_SteeringAngle_Ad + (real_T)
        VCU_CS75_9_30_B.CANReceive_o4_ge[1];

      /* DataTypeConversion: '<S365>/SAS_SteeringAngle_Convert' */
      rtb_SAS_SteeringAngleValid_L = (int32_T)rtb_SAS_SteeringAngle_F;

      /* DataTypeConversion: '<S365>/SAS_SteeringAnglecv' */
      rtb_SAS_SteeringAnglesubcon = (real32_T)rtb_SAS_SteeringAngleValid_L;

      /* RelationalOperator: '<S365>/SAS_SteeringAngleROP' */
      rtb_SAS_SteeringAngleROP = (rtb_SAS_SteeringAnglesubcon >= 32768.0F);

      /* Switch: '<S365>/SAS_SteeringAngleSW' */
      if (rtb_SAS_SteeringAngleROP) {
        /* Sum: '<S365>/SAS_SteeringAnglesubcon' */
        rtb_SAS_SteeringAnglesubcon = 65536.0F - rtb_SAS_SteeringAnglesubcon;

        /* UnaryMinus: '<S365>/SAS_SteeringAngleMinus' */
        rtb_SAS_SteeringAnglesubcon = -rtb_SAS_SteeringAnglesubcon;
      }

      /* End of Switch: '<S365>/SAS_SteeringAngleSW' */

      /* DataTypeConversion: '<S365>/Data Type Conversion' */
      rtb_SAS_SteeringAngle_F = rtb_SAS_SteeringAnglesubcon;

      /* DataTypeConversion: '<S365>/SAS_CRCCheck_Convert' */
      rtb_SAS_SteeringAngleValid_L = VCU_CS75_9_30_B.CANReceive_o4_ge[7];

      /* DataTypeConversion: '<S365>/SAS_CRCCheckcv' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;

      /* Sum: '<S365>/SAS_CRCCheck_Ad' */
      rtb_SAS_CRCCheck_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Saturate: '<S365>/SAS_CRCCheck_sat' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_CRCCheck_sat;
      rtb_SAS_CRCCheck_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* DataTypeConversion: '<S365>/SAS_Calibrated_Convert' */
      rtb_SAS_SteeringAngleValid_L = VCU_CS75_9_30_B.CANReceive_o4_ge[3];

      /* S-Function (sfix_bitop): '<S365>/SAS_Calibrated_L' */
      rtb_SAS_SteeringAngleValid_L &= 32U;

      /* ArithShift: '<S365>/SAS_Calibrated_S' */
      rtb_SAS_SteeringAngleValid_L = (int32_T)((uint32_T)
        rtb_SAS_SteeringAngleValid_L >> 5);

      /* DataTypeConversion: '<S365>/SAS_Calibratedcv' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;

      /* Sum: '<S365>/SAS_Calibrated_Ad' */
      rtb_SAS_Calibrated_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Saturate: '<S365>/SAS_Calibrated_sat' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_Calibrated_sat;
      rtb_SAS_Calibrated_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* DataTypeConversion: '<S365>/SAS_RollingCounter_Convert' */
      rtb_SAS_SteeringAngleValid_L = VCU_CS75_9_30_B.CANReceive_o4_ge[6];

      /* S-Function (sfix_bitop): '<S365>/SAS_RollingCounter_L' */
      rtb_SAS_SteeringAngleValid_L &= 15U;

      /* DataTypeConversion: '<S365>/SAS_RollingCountercv' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;

      /* Sum: '<S365>/SAS_RollingCounter_Ad' */
      rtb_SAS_RollingCounter_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Saturate: '<S365>/SAS_RollingCounter_sat' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_RollingCounter_sat;
      rtb_SAS_RollingCounter_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* DataTypeConversion: '<S365>/SAS_SASFailure_Convert' */
      rtb_SAS_SteeringAngleValid_L = VCU_CS75_9_30_B.CANReceive_o4_ge[3];

      /* S-Function (sfix_bitop): '<S365>/SAS_SASFailure_L' */
      rtb_SAS_SteeringAngleValid_L &= 64U;

      /* ArithShift: '<S365>/SAS_SASFailure_S' */
      rtb_SAS_SteeringAngleValid_L = (int32_T)((uint32_T)
        rtb_SAS_SteeringAngleValid_L >> 6);

      /* DataTypeConversion: '<S365>/SAS_SASFailurecv' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;

      /* Sum: '<S365>/SAS_SASFailure_Ad' */
      rtb_SAS_SASFailure_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Saturate: '<S365>/SAS_SASFailure_sat' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SASFailure_sat;
      rtb_SAS_SASFailure_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* DataTypeConversion: '<S365>/SAS_SteeringAngleSpeed_Convert' */
      rtb_SAS_SteeringAngleValid_L = VCU_CS75_9_30_B.CANReceive_o4_ge[2];

      /* DataTypeConversion: '<S365>/SAS_SteeringAngleSpeedcv' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;

      /* Gain: '<S365>/SAS_SteeringAngleSpeed_F' */
      rtb_SAS_SteeringAngle_Ad *= 4.0;

      /* Sum: '<S365>/SAS_SteeringAngleSpeed_Ad' */
      rtb_SAS_SteeringAngleSpeed_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Saturate: '<S365>/SAS_SteeringAngleSpeed_sat' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleSpeed_sat;
      rtb_SAS_SteeringAngleSpeed_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* DataTypeConversion: '<S365>/SAS_SteeringAngleValid_Convert' */
      rtb_SAS_SteeringAngleValid_L = VCU_CS75_9_30_B.CANReceive_o4_ge[3];

      /* S-Function (sfix_bitop): '<S365>/SAS_SteeringAngleValid_L' */
      rtb_SAS_SteeringAngleValid_L &= 128U;

      /* ArithShift: '<S365>/SAS_SteeringAngleValid_S' */
      rtb_SAS_SteeringAngleValid_L = (int32_T)((uint32_T)
        rtb_SAS_SteeringAngleValid_L >> 7);

      /* DataTypeConversion: '<S365>/SAS_SteeringAngleValidcv' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;

      /* Sum: '<S365>/SAS_SteeringAngleValid_Ad' */
      rtb_SAS_SteeringAngleValid_L = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Saturate: '<S365>/SAS_SteeringAngleValid_sat' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;
      rtb_SAS_SteeringAngleValid_L = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Gain: '<S365>/SAS_SteeringAngle_F' */
      rtb_SAS_SteeringAngle_F *= 0.1;

      /* Sum: '<S365>/SAS_SteeringAngle_Ad' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngle_F;

      /* Saturate: '<S365>/SAS_SteeringAngle_sat' */
      if (rtb_SAS_SteeringAngle_Ad > 780.0) {
        SAS_SteeringAngle = 780.0;
      } else if (rtb_SAS_SteeringAngle_Ad < -780.0) {
        SAS_SteeringAngle = -780.0;
      } else {
        SAS_SteeringAngle = rtb_SAS_SteeringAngle_Ad;
      }

      /* End of Saturate: '<S365>/SAS_SteeringAngle_sat' */

      /* SignalConversion: '<S364>/Signal Conversion' */
      VCU_CS75_9_30_B.SAS_SteeringAngle_a = SAS_SteeringAngle;

      /* SignalConversion: '<S364>/Signal Conversion' */
      VCU_CS75_9_30_B.SAS_SteeringAngleSpeed = rtb_SAS_SteeringAngleSpeed_sat;

      /* SignalConversion: '<S364>/Signal Conversion' */
      VCU_CS75_9_30_B.SAS_Calibrated = rtb_SAS_Calibrated_sat;

      /* SignalConversion: '<S364>/Signal Conversion' */
      VCU_CS75_9_30_B.SAS_SASFailure = rtb_SAS_SASFailure_sat;

      /* SignalConversion: '<S364>/Signal Conversion' */
      VCU_CS75_9_30_B.SAS_SteeringAngleValid = rtb_SAS_SteeringAngleValid_L;

      /* SignalConversion: '<S364>/Signal Conversion' */
      VCU_CS75_9_30_B.SAS_RollingCounter = rtb_SAS_RollingCounter_sat;

      /* SignalConversion: '<S364>/Signal Conversion' */
      VCU_CS75_9_30_B.SAS_CRCCheck = rtb_SAS_CRCCheck_sat;
    }

    /* End of Outputs for SubSystem: '<S363>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S101>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF20RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf20looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_jl= 952;
    VCU_CS75_9_30_B.CANReceive_o5_a1= 8;
    VCU_CS75_9_30_B.CANReceive_o2_o= ec_can_receive(1,20, CAN1BUF20RX);
    VCU_CS75_9_30_B.CANReceive_o4_i[0]= CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_i[1]= CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_i[2]= CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_i[3]= CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_i[4]= CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_i[5]= CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_i[6]= CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_i[7]= CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
  }

  /* Call the system: <S101>/ReceiveMessages */

  /* Output and update for function-call system: '<S101>/ReceiveMessages' */

  /* Outputs for Enabled SubSystem: '<S373>/Subsystem' incorporates:
   *  EnablePort: '<S374>/Enable'
   */
  if (VCU_CS75_9_30_B.CANReceive_o2_o > 0) {
    /* SignalConversion: '<S374>/Signal Conversion' */
    VCU_CS75_9_30_B.SCM_ACCOn = 0.0;

    /* SignalConversion: '<S374>/Signal Conversion' */
    VCU_CS75_9_30_B.SCM_ACCCancel = 0.0;

    /* SignalConversion: '<S374>/Signal Conversion' */
    VCU_CS75_9_30_B.SCM_Resume = 0.0;

    /* SignalConversion: '<S374>/Signal Conversion' */
    VCU_CS75_9_30_B.SCM_Speeddecrease = 0.0;

    /* SignalConversion: '<S374>/Signal Conversion' */
    VCU_CS75_9_30_B.SCM_TimeGap = 0.0;

    /* SignalConversion: '<S374>/Signal Conversion' */
    VCU_CS75_9_30_B.SCM_IACCOn = 0.0;
  }

  /* End of Outputs for SubSystem: '<S373>/Subsystem' */

  /* S-Function (ec5744_canreceiveslb): '<S102>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF21RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf21looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_hl= 5;
    VCU_CS75_9_30_B.CANReceive_o5_dv= 8;
    VCU_CS75_9_30_B.CANReceive_o2_hh= ec_can_receive(1,21, CAN1BUF21RX);
    VCU_CS75_9_30_B.CANReceive_o4_bt[0]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_bt[1]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_bt[2]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_bt[3]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_bt[4]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_bt[5]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_bt[6]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_bt[7]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
  }

  /* Call the system: <S102>/ReceiveMessages */

  /* Output and update for function-call system: '<S102>/ReceiveMessages' */
  {
    int32_T rtb_SRS_RollingCounter_L;
    int32_T rtb_SRS_DriverBuckleSwitchStatu;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S382>/Subsystem' incorporates:
     *  EnablePort: '<S383>/Enable'
     */
    if (VCU_CS75_9_30_B.CANReceive_o2_hh > 0) {
      /* DataTypeConversion: '<S384>/SRS_DriverBuckleSwitchStatus_Convert' */
      rtb_SRS_RollingCounter_L = VCU_CS75_9_30_B.CANReceive_o4_bt[1];

      /* S-Function (sfix_bitop): '<S384>/SRS_DriverBuckleSwitchStatus_L' */
      rtb_SRS_RollingCounter_L &= 192U;

      /* ArithShift: '<S384>/SRS_DriverBuckleSwitchStatus_S' */
      rtb_SRS_RollingCounter_L = (int32_T)((uint32_T)rtb_SRS_RollingCounter_L >>
        6);

      /* Sum: '<S384>/SRS_DriverBuckleSwitchStatus_Ad' */
      rtb_SRS_DriverBuckleSwitchStatu = rtb_SRS_RollingCounter_L;

      /* Saturate: '<S384>/SRS_DriverBuckleSwitchStatus_sat' */
      u0 = rtb_SRS_DriverBuckleSwitchStatu;
      rtb_SRS_DriverBuckleSwitchStatu = (int32_T)u0;

      /* DataTypeConversion: '<S384>/SRS_RollingCounter_Convert' */
      rtb_SRS_RollingCounter_L = VCU_CS75_9_30_B.CANReceive_o4_bt[3];

      /* S-Function (sfix_bitop): '<S384>/SRS_RollingCounter_L' */
      rtb_SRS_RollingCounter_L &= 15U;

      /* Saturate: '<S384>/SRS_RollingCounter_sat' */
      u0 = rtb_SRS_RollingCounter_L;
      rtb_SRS_RollingCounter_L = (int32_T)u0;

      /* SignalConversion: '<S383>/Signal Conversion' */
      VCU_CS75_9_30_B.SRS_DriverBuckleSwitchStatus =
        rtb_SRS_DriverBuckleSwitchStatu;

      /* SignalConversion: '<S383>/Signal Conversion' */
      VCU_CS75_9_30_B.SRS_RollingCounter = rtb_SRS_RollingCounter_L;
    }

    /* End of Outputs for SubSystem: '<S382>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S103>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF22RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf22looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_n4= 646;
    VCU_CS75_9_30_B.CANReceive_o5_ot= 8;
    VCU_CS75_9_30_B.CANReceive_o2_d5= ec_can_receive(1,22, CAN1BUF22RX);
    VCU_CS75_9_30_B.CANReceive_o4_bs[0]= CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_bs[1]= CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_bs[2]= CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_bs[3]= CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_bs[4]= CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_bs[5]= CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_bs[6]= CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_bs[7]= CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
  }

  /* Call the system: <S103>/ReceiveMessages */

  /* Output and update for function-call system: '<S103>/ReceiveMessages' */
  {
    int32_T rtb_TCU_GearShiftPosition_L;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S387>/Subsystem' incorporates:
     *  EnablePort: '<S388>/Enable'
     */
    if (VCU_CS75_9_30_B.CANReceive_o2_d5 > 0) {
      /* DataTypeConversion: '<S389>/TCU_ActualGear_Convert' */
      rtb_TCU_GearShiftPosition_L = VCU_CS75_9_30_B.CANReceive_o4_bs[1];

      /* S-Function (sfix_bitop): '<S389>/TCU_ActualGear_L' */
      rtb_TCU_GearShiftPosition_L &= 15U;

      /* Saturate: '<S389>/TCU_ActualGear_sat' */
      u0 = rtb_TCU_GearShiftPosition_L;
      rtb_TCU_GearShiftPosition_L = (int32_T)u0;

      /* SignalConversion: '<S388>/Signal Conversion' */
      VCU_CS75_9_30_B.TCU_ActualGear = rtb_TCU_GearShiftPosition_L;

      /* DataTypeConversion: '<S389>/TCU_ShiftPositionValid_Convert' */
      rtb_TCU_GearShiftPosition_L = VCU_CS75_9_30_B.CANReceive_o4_bs[1];

      /* S-Function (sfix_bitop): '<S389>/TCU_ShiftPositionValid_L' */
      rtb_TCU_GearShiftPosition_L &= 16U;

      /* ArithShift: '<S389>/TCU_ShiftPositionValid_S' */
      rtb_TCU_GearShiftPosition_L = (int32_T)((uint32_T)
        rtb_TCU_GearShiftPosition_L >> 4);

      /* Saturate: '<S389>/TCU_ShiftPositionValid_sat' */
      u0 = rtb_TCU_GearShiftPosition_L;
      rtb_TCU_GearShiftPosition_L = (int32_T)u0;

      /* SignalConversion: '<S388>/Signal Conversion' */
      VCU_CS75_9_30_B.TCU_ShiftPositionValid = rtb_TCU_GearShiftPosition_L;

      /* DataTypeConversion: '<S389>/TCU_ActualGearValid_Convert' */
      rtb_TCU_GearShiftPosition_L = VCU_CS75_9_30_B.CANReceive_o4_bs[1];

      /* S-Function (sfix_bitop): '<S389>/TCU_ActualGearValid_L' */
      rtb_TCU_GearShiftPosition_L &= 32U;

      /* ArithShift: '<S389>/TCU_ActualGearValid_S' */
      rtb_TCU_GearShiftPosition_L = (int32_T)((uint32_T)
        rtb_TCU_GearShiftPosition_L >> 5);

      /* Saturate: '<S389>/TCU_ActualGearValid_sat' */
      u0 = rtb_TCU_GearShiftPosition_L;
      rtb_TCU_GearShiftPosition_L = (int32_T)u0;

      /* SignalConversion: '<S388>/Signal Conversion' */
      VCU_CS75_9_30_B.TCU_ActualGearValid = rtb_TCU_GearShiftPosition_L;

      /* DataTypeConversion: '<S389>/TCU_GearShiftPosition_Convert' */
      rtb_TCU_GearShiftPosition_L = VCU_CS75_9_30_B.CANReceive_o4_bs[2];

      /* S-Function (sfix_bitop): '<S389>/TCU_GearShiftPosition_L' */
      rtb_TCU_GearShiftPosition_L &= 240U;

      /* ArithShift: '<S389>/TCU_GearShiftPosition_S' */
      rtb_TCU_GearShiftPosition_L = (int32_T)((uint32_T)
        rtb_TCU_GearShiftPosition_L >> 4);

      /* Saturate: '<S389>/TCU_GearShiftPosition_sat' */
      u0 = rtb_TCU_GearShiftPosition_L;
      rtb_TCU_GearShiftPosition_L = (int32_T)u0;

      /* SignalConversion: '<S388>/Signal Conversion' */
      VCU_CS75_9_30_B.TCU_GearShiftPosition = rtb_TCU_GearShiftPosition_L;
    }

    /* End of Outputs for SubSystem: '<S387>/Subsystem' */
  }

  /* End of Outputs for SubSystem: '<S2>/BSW_Input' */

  /* Outputs for Atomic SubSystem: '<S2>/APP' */
  /* Inport: '<S24>/APP_Input' */
  rtb_APP_Input_idx_0 = VCU_CS75_9_30_B.AutoDrivingReady;
  rtb_APP_Input_idx_1 = VCU_CS75_9_30_B.RemoteAcclPosition;
  rtb_APP_Input_idx_3 = VCU_CS75_9_30_B.A1_Message_Counter;
  rtb_APP_Input_idx_8 = VCU_CS75_9_30_B.EMS_FrictionalTorq_n;
  rtb_APP_Input_idx_9 = VCU_CS75_9_30_B.EMS_IndicatedRealEngTorq;
  rtb_APP_Input_idx_12 = VCU_CS75_9_30_B.EMS_BrakePedalStatus_h;
  rtb_APP_Input_idx_17 = VCU_CS75_9_30_B.EMS_RollingCounter_id255;
  rtb_APP_Input_idx_19 = VCU_CS75_9_30_B.EMS_FullLoadIndicatedTorq;
  rtb_APP_Input_idx_20 = VCU_CS75_9_30_B.EMS_TorqueConstant_l;
  rtb_APP_Input_idx_29 = VCU_CS75_9_30_B.EPS_EPSFailed_m;
  rtb_APP_Input_idx_39 = VCU_CS75_9_30_B.EPS_AvailabilityStatus_g;
  rtb_APP_Input_idx_63 = VCU_CS75_9_30_B.Wheel_Speed_RR;
  rtb_APP_Input_idx_66 = VCU_CS75_9_30_B.Wheel_Speed_RL;
  rtb_P6_Value = VCU_CS75_9_30_B.ESP_ESPFailStatus;
  rtb_APP_Input_idx_99 = VCU_CS75_9_30_B.SAS_SteeringAngle_a;
  rtb_APP_Input_idx_217 = P6_Value;

  /* MATLAB Function: '<S51>/MATLAB Function2' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Monitor/Vehicle_Status/MATLAB Function2': '<S54>:1' */
  if ((rtb_APP_Input_idx_29 == 1.0) || (rtb_P6_Value == 1.0)) {
    /* '<S54>:1:2' */
    /* '<S54>:1:3' */
    VehicleFaultStatus = 1.0;
  } else {
    /* '<S54>:1:5' */
    VehicleFaultStatus = 0.0;
  }

  /* End of MATLAB Function: '<S51>/MATLAB Function2' */

  /* Memory: '<S51>/Memory3' */
  rtb_P6_Value = VCU_CS75_9_30_DW.Memory3_PreviousInput;

  /* Memory: '<S51>/Memory2' */
  rtb_Memory2 = VCU_CS75_9_30_DW.Memory2_PreviousInput;

  /* MATLAB Function: '<S51>/MATLAB Function4' incorporates:
   *  Constant: '<S51>/1s'
   */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Monitor/Vehicle_Status/MATLAB Function4': '<S55>:1' */
  if (rtb_APP_Input_idx_17 == rtb_P6_Value) {
    /* '<S55>:1:2' */
    /* '<S55>:1:3' */
    rtb_P6_Value = rtb_Memory2 + 1.0;
  } else {
    /* '<S55>:1:5' */
    rtb_P6_Value = 0.0;
  }

  if (rtb_P6_Value * 20.0 > 1000.0) {
    /* '<S55>:1:7' */
    /* '<S55>:1:8' */
    VehicleCommunicationStatus = 0.0;
  } else {
    /* '<S55>:1:10' */
    VehicleCommunicationStatus = 1.0;
  }

  counter1 = rtb_P6_Value;

  /* End of MATLAB Function: '<S51>/MATLAB Function4' */

  /* DataTypeConversion: '<S51>/Data Type Conversion' */
  EPS_AvailabilityStatus = rtb_APP_Input_idx_39;

  /* Constant: '<S49>/Constant' */
  Server_CommunicationStatus = 1.0;

  /* Chart: '<S29>/Chart' */
  /* Gateway: 长安CS75底盘程序，20ms一次/APP/System_State_Manager/Chart */
  /* During: 长安CS75底盘程序，20ms一次/APP/System_State_Manager/Chart */
  if (VCU_CS75_9_30_DW.bitsForTID4.is_active_c4_VCU_CS75_9_30 == 0U) {
    /* Entry: 长安CS75底盘程序，20ms一次/APP/System_State_Manager/Chart */
    VCU_CS75_9_30_DW.bitsForTID4.is_active_c4_VCU_CS75_9_30 = 1U;

    /* Entry Internal: 长安CS75底盘程序，20ms一次/APP/System_State_Manager/Chart */
    VCU_CS75_9_30_DW.bitsForTID4.is_c4_VCU_CS75_9_30 =
      VCU_CS75_9_30_IN_System_State;

    /* Entry Internal 'System_State': '<S56>:16' */
    /* Transition: '<S56>:11' */
    VCU_CS75_9_30_DW.bitsForTID4.is_System_State =
      VCU_CS75__IN_INIT_ManualDriving;

    /* Entry 'INIT_ManualDriving': '<S56>:7' */
    /* 驾驶员正常驾驶 */
    System_State = 0.0;
  } else {
    /* During 'System_State': '<S56>:16' */
    switch (VCU_CS75_9_30_DW.bitsForTID4.is_System_State) {
     case VCU_CS75_9_30_IN_AutoDriving:
      /* During 'AutoDriving': '<S56>:8' */
      rtb_APA_EPSAngleReqROP = ((VehicleFaultStatus == 1.0) ||
        (VehicleCommunicationStatus == 0.0) || (Server_CommunicationStatus ==
        0.0));
      if (rtb_APA_EPSAngleReqROP) {
        /* Transition: '<S56>:27' */
        VCU_CS75_9_30_DW.bitsForTID4.is_System_State = VCU_CS75_9_30_IN_Error;

        /* Entry 'Error': '<S56>:10' */
        /* 故障，需人工接管 */
        System_State = 3.0;
      } else if (rtb_APP_Input_idx_12 == 1.0) {
        /* Transition: '<S56>:28' */
        VCU_CS75_9_30_DW.bitsForTID4.is_System_State = VCU_CS75_9_30_IN_TakeOver;

        /* Entry 'TakeOver': '<S56>:9' */
        /* 人工接管模式 */
        System_State = 2.0;
      } else if (rtb_APP_Input_idx_0 == 0.0) {
        /* Transition: '<S56>:31' */
        /* %&&Switch_P6 == 0 */
        VCU_CS75_9_30_DW.bitsForTID4.is_System_State =
          VCU_CS75__IN_INIT_ManualDriving;

        /* Entry 'INIT_ManualDriving': '<S56>:7' */
        /* 驾驶员正常驾驶 */
        System_State = 0.0;
      } else {
        System_State = 1.0;
      }
      break;

     case VCU_CS75_9_30_IN_Error:
      /* During 'Error': '<S56>:10' */
      rtb_APA_EPSAngleReqROP = ((rtb_APP_Input_idx_0 == 0.0) &&
        (rtb_APP_Input_idx_217 == 0.0) && (VehicleCommunicationStatus == 1.0) &&
                                (VehicleFaultStatus == 0.0));
      if (rtb_APA_EPSAngleReqROP) {
        /* Transition: '<S56>:35' */
        /* %&& Server_CommunicationStatus == 1 */
        VCU_CS75_9_30_DW.bitsForTID4.is_System_State =
          VCU_CS75__IN_INIT_ManualDriving;

        /* Entry 'INIT_ManualDriving': '<S56>:7' */
        /* 驾驶员正常驾驶 */
        System_State = 0.0;
      } else {
        System_State = 3.0;
      }
      break;

     case VCU_CS75__IN_INIT_ManualDriving:
      /* During 'INIT_ManualDriving': '<S56>:7' */
      rtb_APA_EPSAngleReqROP = ((rtb_APP_Input_idx_0 == 1.0) &&
        (Server_CommunicationStatus == 1.0) && (rtb_APP_Input_idx_12 == 0.0) &&
                                (VehicleCommunicationStatus == 1.0) &&
        (VehicleFaultStatus == 0.0));
      if (rtb_APA_EPSAngleReqROP) {
        /* Transition: '<S56>:18' */
        /* % &&Switch_P6 == 1&&EPS_AvailabilityStatus == 2 */
        VCU_CS75_9_30_DW.bitsForTID4.is_System_State =
          VCU_CS75_9_30_IN_AutoDriving;

        /* Entry 'AutoDriving': '<S56>:8' */
        /* 自动驾驶 */
        System_State = 1.0;
      } else {
        System_State = 0.0;
      }
      break;

     default:
      /* During 'TakeOver': '<S56>:9' */
      rtb_APA_EPSAngleReqROP = ((rtb_APP_Input_idx_0 == 0.0) &&
        (rtb_APP_Input_idx_217 == 0.0));
      if (rtb_APA_EPSAngleReqROP) {
        /* Transition: '<S56>:32' */
        VCU_CS75_9_30_DW.bitsForTID4.is_System_State =
          VCU_CS75__IN_INIT_ManualDriving;

        /* Entry 'INIT_ManualDriving': '<S56>:7' */
        /* 驾驶员正常驾驶 */
        System_State = 0.0;
      } else {
        rtb_APA_EPSAngleReqROP = ((VehicleFaultStatus == 1.0) ||
          (VehicleCommunicationStatus == 0.0) || (Server_CommunicationStatus ==
          0.0));
        if (rtb_APA_EPSAngleReqROP) {
          /* Transition: '<S56>:39' */
          VCU_CS75_9_30_DW.bitsForTID4.is_System_State = VCU_CS75_9_30_IN_Error;

          /* Entry 'Error': '<S56>:10' */
          /* 故障，需人工接管 */
          System_State = 3.0;
        } else {
          System_State = 2.0;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S29>/Chart' */

  /* Outputs for Atomic SubSystem: '<S27>/Accesories' */
  /* MATLAB Function: '<S30>/MATLAB Function' incorporates:
   *  Constant: '<S30>/ECCalVar'
   */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Accesories/MATLAB Function': '<S34>:1' */
  if (LDW == 1.0) {
    /* '<S34>:1:2' */
    /* '<S34>:1:3' */
    LAS_LDWVibrationWarning = 2.0;

    /* '<S34>:1:4' */
    LAS_LDWStatus = 2.0;
  } else {
    /* '<S34>:1:6' */
    LAS_LDWVibrationWarning = 0.0;

    /* '<S34>:1:7' */
    LAS_LDWStatus = 0.0;
  }

  /* End of MATLAB Function: '<S30>/MATLAB Function' */

  /* MATLAB Function: '<S30>/MATLAB Function2' */
  VCU_CS75_9__MATLABFunction2(System_State,
    &VCU_CS75_9_30_B.sf_MATLABFunction2_d);

  /* End of Outputs for SubSystem: '<S27>/Accesories' */

  /* Outputs for Atomic SubSystem: '<S27>/Lateral' */
  /* Lookup_n-D: '<S32>/1-D Lookup Table' incorporates:
   *  Constant: '<S32>/ECCalVar'
   */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Accesories/MATLAB Function1': '<S35>:1' */
  mubiao_zhuanjiao = look1_binlx(ST_comd,
    VCU_CS75_9_30_ConstP.DLookupTable_bp01Data, VCU_CS75_9_30_ConstP.pooled2, 1U);

  /* Memory: '<S32>/Memory2' */
  rtb_P6_Value = VCU_CS75_9_30_DW.Memory2_PreviousInput_l;

  /* MATLAB Function: '<S32>/MATLAB Function2' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Lateral/MATLAB Function2': '<S38>:1' */
  if (rtb_P6_Value == 15.0) {
    /* '<S38>:1:2' */
    /* '<S38>:1:3' */
    APA_RollingCounter = 0.0;
  } else {
    /* '<S38>:1:5' */
    /* '<S38>:1:6' */
    APA_RollingCounter = rtb_P6_Value + 1.0;
  }

  /* End of MATLAB Function: '<S32>/MATLAB Function2' */

  /* MATLAB Function: '<S32>/MATLAB Function3' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Lateral/MATLAB Function3': '<S39>:1' */
  if ((rtb_APP_Input_idx_217 == 1.0) && ((System_State == 0.0) || (System_State ==
        1.0))) {
    /* '<S39>:1:2' */
    /* '<S39>:1:3' */
    rtb_LateralTakeover = 1;
  } else {
    /* '<S39>:1:5' */
    rtb_LateralTakeover = 0;
  }

  /* End of MATLAB Function: '<S32>/MATLAB Function3' */

  /* MATLAB Function: '<S32>/MATLAB Function7' */
  VCU_CS75_9__MATLABFunction2(System_State, &VCU_CS75_9_30_B.sf_MATLABFunction7);

  /* Switch: '<S32>/Switch' incorporates:
   *  Constant: '<S32>/Constant1'
   */
  if (rtb_APP_Input_idx_217 > 0.0) {
    rtb_P6_Value = mubiao_zhuanjiao;
  } else {
    rtb_P6_Value = 0.0;
  }

  /* End of Switch: '<S32>/Switch' */

  /* Saturate: '<S32>/Saturation' */
  if (rtb_P6_Value > 300.0) {
    rtb_APP_Input_idx_0 = 300.0;
  } else if (rtb_P6_Value < -300.0) {
    rtb_APP_Input_idx_0 = -300.0;
  } else {
    rtb_APP_Input_idx_0 = rtb_P6_Value;
  }

  /* End of Saturate: '<S32>/Saturation' */

  /* Update for Memory: '<S32>/Memory2' */
  VCU_CS75_9_30_DW.Memory2_PreviousInput_l = APA_RollingCounter;

  /* End of Outputs for SubSystem: '<S27>/Lateral' */

  /* Outputs for Atomic SubSystem: '<S27>/Longitudinal' */
  /* MATLAB Function: '<S33>/MATLAB Function' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Longitudinal/MATLAB Function': '<S41>:1' */
  if (rtb_APP_Input_idx_1 < 0.0) {
    /* '<S41>:1:2' */
    /* '<S41>:1:3' */
    ACC_CDDAxEnable = 1.0;
  } else {
    /* '<S41>:1:5' */
    ACC_CDDAxEnable = 0.0;
  }

  /* End of MATLAB Function: '<S33>/MATLAB Function' */

  /* MATLAB Function: '<S33>/MATLAB Function1' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Longitudinal/MATLAB Function1': '<S42>:1' */
  if (rtb_APP_Input_idx_1 >= 0.0) {
    /* '<S42>:1:2' */
    /* '<S42>:1:3' */
    ACC_Driveoff_Request = 1.0;
  } else {
    /* '<S42>:1:5' */
    ACC_Driveoff_Request = 0.0;
  }

  /* End of MATLAB Function: '<S33>/MATLAB Function1' */

  /* MATLAB Function: '<S33>/MATLAB Function7' */
  VCU_CS75_9__MATLABFunction2(System_State,
    &VCU_CS75_9_30_B.sf_MATLABFunction7_g);

  /* MATLAB Function: '<S33>/MATLAB Function2' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Longitudinal/MATLAB Function2': '<S43>:1' */
  if ((rtb_APP_Input_idx_1 <= 0.0) && (VCU_CS75_9_30_B.sf_MATLABFunction7_g.y ==
       1.0)) {
    /* '<S43>:1:2' */
    /* '<S43>:1:3' */
    ACC_ACCTargetAcceleration = rtb_APP_Input_idx_1;
  } else {
    /* '<S43>:1:5' */
    ACC_ACCTargetAcceleration = 0.0;
  }

  /* End of MATLAB Function: '<S33>/MATLAB Function2' */

  /* Memory: '<S33>/Memory1' */
  rtb_P6_Value = VCU_CS75_9_30_DW.Memory1_PreviousInput_p;

  /* MATLAB Function: '<S33>/MATLAB Function3' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Longitudinal/MATLAB Function3': '<S44>:1' */
  if (rtb_P6_Value == 15.0) {
    /* '<S44>:1:2' */
    /* '<S44>:1:3' */
    rtb_P6_Value = 0.0;
  } else {
    /* '<S44>:1:5' */
  }

  if (VCU_CS75_9_30_B.sf_MATLABFunction7_g.y == 1.0) {
    /* '<S44>:1:8' */
    /* '<S44>:1:9' */
    ACC_RollingCounter_id2E4 = rtb_P6_Value + 1.0;
  } else {
    /* '<S44>:1:11' */
    ACC_RollingCounter_id2E4 = rtb_P6_Value;
  }

  /* End of MATLAB Function: '<S33>/MATLAB Function3' */

  /* Memory: '<S33>/Memory2' */
  rtb_P6_Value = VCU_CS75_9_30_DW.Memory2_PreviousInput_b;

  /* MATLAB Function: '<S33>/MATLAB Function4' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Longitudinal/MATLAB Function4': '<S45>:1' */
  if (rtb_P6_Value == 15.0) {
    /* '<S45>:1:2' */
    /* '<S45>:1:3' */
    rtb_P6_Value = 0.0;
  } else {
    /* '<S45>:1:5' */
  }

  if (VCU_CS75_9_30_B.sf_MATLABFunction7_g.y == 1.0) {
    /* '<S45>:1:8' */
    /* '<S45>:1:9' */
    ACC_RollingCounter_id2E5 = rtb_P6_Value + 1.0;
  } else {
    /* '<S45>:1:11' */
    ACC_RollingCounter_id2E5 = rtb_P6_Value;
  }

  /* End of MATLAB Function: '<S33>/MATLAB Function4' */

  /* MATLAB Function: '<S33>/MATLAB Function5' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Longitudinal/MATLAB Function5': '<S46>:1' */
  if ((rtb_APP_Input_idx_1 >= 0.0) && (VCU_CS75_9_30_B.sf_MATLABFunction7_g.y ==
       1.0)) {
    /* '<S46>:1:2' */
    /* '<S46>:1:3' */
    ACC_AccTorqueReq = rtb_APP_Input_idx_1;
  } else {
    /* '<S46>:1:5' */
    ACC_AccTorqueReq = 0.0;
  }

  /* End of MATLAB Function: '<S33>/MATLAB Function5' */

  /* MATLAB Function: '<S33>/MATLAB Function6' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Longitudinal/MATLAB Function6': '<S47>:1' */
  if (rtb_APP_Input_idx_1 <= 0.0) {
    /* '<S47>:1:2' */
    /* '<S47>:1:3' */
    ACC_TrqEnable = 0.0;
  } else {
    /* '<S47>:1:5' */
    ACC_TrqEnable = 1.0;
  }

  /* End of MATLAB Function: '<S33>/MATLAB Function6' */

  /* Update for Memory: '<S33>/Memory1' */
  VCU_CS75_9_30_DW.Memory1_PreviousInput_p = ACC_RollingCounter_id2E4;

  /* Update for Memory: '<S33>/Memory2' */
  VCU_CS75_9_30_DW.Memory2_PreviousInput_b = ACC_RollingCounter_id2E5;

  /* End of Outputs for SubSystem: '<S27>/Longitudinal' */

  /* Memory: '<S49>/Memory1' */
  A1counter = VCU_CS75_9_30_DW.Memory1_PreviousInput;

  /* Memory: '<S49>/Memory2' */
  rtb_P6_Value = VCU_CS75_9_30_DW.Memory2_PreviousInput_g;

  /* MATLAB Function: '<S49>/MATLAB Function1' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Monitor/Server_Status/MATLAB Function1': '<S53>:1' */
  if (rtb_APP_Input_idx_3 == A1counter) {
    /* '<S53>:1:2' */
    /* '<S53>:1:3' */
    rtb_P6_Value++;
  } else {
    /* '<S53>:1:5' */
    rtb_P6_Value = 0.0;
  }

  counter3 = rtb_P6_Value;

  /* End of MATLAB Function: '<S49>/MATLAB Function1' */

  /* Update for Memory: '<S51>/Memory3' */
  VCU_CS75_9_30_DW.Memory3_PreviousInput = rtb_APP_Input_idx_17;

  /* Update for Memory: '<S51>/Memory2' */
  VCU_CS75_9_30_DW.Memory2_PreviousInput = counter1;

  /* Update for Memory: '<S49>/Memory1' */
  VCU_CS75_9_30_DW.Memory1_PreviousInput = rtb_APP_Input_idx_3;

  /* Update for Memory: '<S49>/Memory2' */
  VCU_CS75_9_30_DW.Memory2_PreviousInput_g = counter3;

  /* End of Outputs for SubSystem: '<S2>/APP' */

  /* Lookup_n-D: '<S693>/1-D Lookup Table' */
  rtb_P6_Value = look1_binlx(rtb_APP_Input_idx_99, VCU_CS75_9_30_ConstP.pooled2,
    VCU_CS75_9_30_ConstP.DLookupTable_tableDat, 1U);

  /* Abs: '<S693>/Abs' */
  rtb_Memory2 = fabs(rtb_APP_Input_idx_63);

  /* Abs: '<S693>/Abs1' */
  rtb_APP_Input_idx_29 = fabs(rtb_APP_Input_idx_66);

  /* Gain: '<S693>/Gain' */
  rtb_P6_Value *= 0.017453291666666666;

  /* Saturate: '<S699>/Steering_Angle_Feedback_sat' */
  if (rtb_P6_Value > 0.69787) {
    rtb_P6_Value = 0.69787;
  } else {
    if (rtb_P6_Value < -0.698) {
      rtb_P6_Value = -0.698;
    }
  }

  /* End of Saturate: '<S699>/Steering_Angle_Feedback_sat' */

  /* Sum: '<S699>/Steering_Angle_Feedback_st' incorporates:
   *  Constant: '<S699>/Steering_Angle_Feedback_O'
   */
  rtb_P6_Value -= -0.69800001382827759;

  /* Product: '<S699>/Steering_Angle_Feedback_D' */
  rtb_P6_Value /= 0.00547399977222085;

  /* Rounding: '<S699>/Steering_Angle_FeedbackRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S699>/Steering_Angle_Feedback_Convert1' */
  rtb_APA_SteeringAngleReqProte_h = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S699>/Steering_Angle_Feedback_L' */
  rtb_APA_SteeringAngleReqProte_n = rtb_APA_SteeringAngleReqProte_h & 255U;

  /* DataTypeConversion: '<S699>/Steering_Angle_Feedback_Convert' */
  rtb_APA_CheckSum_Convert = (uint8_T)rtb_APA_SteeringAngleReqProte_n;

  /* S-Function (sfix_bitop): '<S695>/or1' */
  VCU_CS75_9_30_B.or1 = rtb_APA_CheckSum_Convert;

  /* Gain: '<S693>/Gain1' */
  EMS_IndicatedRealTroq = 0.01 * rtb_APP_Input_idx_9;

  /* Saturate: '<S696>/Engine_Feedback_sat' */
  rtb_P6_Value = EMS_IndicatedRealTroq;
  if (rtb_P6_Value > 1.0) {
    rtb_P6_Value = 1.0;
  } else {
    if (rtb_P6_Value < -1.0) {
      rtb_P6_Value = -1.0;
    }
  }

  /* End of Saturate: '<S696>/Engine_Feedback_sat' */

  /* Sum: '<S696>/Engine_Feedback_st' incorporates:
   *  Constant: '<S696>/Engine_Feedback_O'
   */
  rtb_P6_Value -= -1.0;

  /* Product: '<S696>/Engine_Feedback_D' */
  rtb_P6_Value /= 0.0078431377187371254;

  /* Rounding: '<S696>/Engine_FeedbackRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S696>/Engine_Feedback_Convert1' */
  rtb_APA_SteeringAngleReqProte_n = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S696>/Engine_Feedback_L' */
  rtb_APA_SteeringAngleReqProte_h = rtb_APA_SteeringAngleReqProte_n & 255U;

  /* DataTypeConversion: '<S696>/Engine_Feedback_Convert' */
  rtb_APA_CheckSum_Convert = (uint8_T)rtb_APA_SteeringAngleReqProte_h;

  /* S-Function (sfix_bitop): '<S695>/or2' */
  VCU_CS75_9_30_B.or2 = rtb_APA_CheckSum_Convert;

  /* Saturate: '<S697>/Engine_Feedback2_sat' */
  rtb_P6_Value = EMS_IndicatedRealTroq;
  if (rtb_P6_Value > 1.0) {
    rtb_P6_Value = 1.0;
  } else {
    if (rtb_P6_Value < -1.0) {
      rtb_P6_Value = -1.0;
    }
  }

  /* End of Saturate: '<S697>/Engine_Feedback2_sat' */

  /* Sum: '<S697>/Engine_Feedback2_st' incorporates:
   *  Constant: '<S697>/Engine_Feedback2_O'
   */
  rtb_P6_Value -= -1.0;

  /* Product: '<S697>/Engine_Feedback2_D' */
  rtb_P6_Value /= 0.0078431377187371254;

  /* Rounding: '<S697>/Engine_Feedback2Ron' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S697>/Engine_Feedback2_Convert1' */
  rtb_APA_SteeringAngleReqProte_n = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S697>/Engine_Feedback2_L' */
  rtb_APA_SteeringAngleReqProte_h = rtb_APA_SteeringAngleReqProte_n & 255U;

  /* DataTypeConversion: '<S697>/Engine_Feedback2_Convert' */
  rtb_APA_CheckSum_Convert = (uint8_T)rtb_APA_SteeringAngleReqProte_h;

  /* S-Function (sfix_bitop): '<S695>/or3' */
  VCU_CS75_9_30_B.or3 = rtb_APA_CheckSum_Convert;

  /* Saturate: '<S701>/Wheel_Speed_RL_Feedback_sat' */
  if (rtb_APP_Input_idx_29 > 200.0) {
    rtb_APP_Input_idx_29 = 200.0;
  }

  /* End of Saturate: '<S701>/Wheel_Speed_RL_Feedback_sat' */

  /* Sum: '<S701>/Wheel_Speed_RL_Feedback_st' */
  rtb_P6_Value = rtb_APP_Input_idx_29;

  /* Product: '<S701>/Wheel_Speed_RL_Feedback_D' */
  rtb_APP_Input_idx_29 = rtb_P6_Value / 0.78431373834609985;

  /* Rounding: '<S701>/Wheel_Speed_RL_FeedbackRon' */
  rtb_APP_Input_idx_29 = rt_roundd_snf(rtb_APP_Input_idx_29);

  /* DataTypeConversion: '<S701>/Wheel_Speed_RL_Feedback_Convert1' */
  rtb_APA_SteeringAngleReqProte_n = (uint32_T)rtb_APP_Input_idx_29;

  /* S-Function (sfix_bitop): '<S701>/Wheel_Speed_RL_Feedback_L' */
  rtb_APA_SteeringAngleReqProte_h = rtb_APA_SteeringAngleReqProte_n & 255U;

  /* DataTypeConversion: '<S701>/Wheel_Speed_RL_Feedback_Convert' */
  rtb_APA_CheckSum_Convert = (uint8_T)rtb_APA_SteeringAngleReqProte_h;

  /* S-Function (sfix_bitop): '<S695>/or4' */
  VCU_CS75_9_30_B.or4 = rtb_APA_CheckSum_Convert;

  /* Saturate: '<S702>/Wheel_Speed_RR_Feedback_sat' */
  if (rtb_Memory2 > 200.0) {
    rtb_Memory2 = 200.0;
  }

  /* End of Saturate: '<S702>/Wheel_Speed_RR_Feedback_sat' */

  /* Sum: '<S702>/Wheel_Speed_RR_Feedback_st' */
  rtb_P6_Value = rtb_Memory2;

  /* Product: '<S702>/Wheel_Speed_RR_Feedback_D' */
  rtb_APP_Input_idx_29 = rtb_P6_Value / 0.78431373834609985;

  /* Rounding: '<S702>/Wheel_Speed_RR_FeedbackRon' */
  rtb_APP_Input_idx_29 = rt_roundd_snf(rtb_APP_Input_idx_29);

  /* DataTypeConversion: '<S702>/Wheel_Speed_RR_Feedback_Convert1' */
  rtb_APA_SteeringAngleReqProte_n = (uint32_T)rtb_APP_Input_idx_29;

  /* S-Function (sfix_bitop): '<S702>/Wheel_Speed_RR_Feedback_L' */
  rtb_APA_SteeringAngleReqProte_h = rtb_APA_SteeringAngleReqProte_n & 255U;

  /* DataTypeConversion: '<S702>/Wheel_Speed_RR_Feedback_Convert' */
  rtb_APA_CheckSum_Convert = (uint8_T)rtb_APA_SteeringAngleReqProte_h;

  /* S-Function (sfix_bitop): '<S695>/or5' */
  VCU_CS75_9_30_B.or5 = rtb_APA_CheckSum_Convert;

  /* Saturate: '<S698>/Res_go_sat' */
  if (rtb_APP_Input_idx_217 > 1.0) {
    rtb_P6_Value = 1.0;
  } else if (rtb_APP_Input_idx_217 < 0.0) {
    rtb_P6_Value = 0.0;
  } else {
    rtb_P6_Value = rtb_APP_Input_idx_217;
  }

  /* End of Saturate: '<S698>/Res_go_sat' */

  /* Sum: '<S698>/Res_go_st' */
  rtb_APP_Input_idx_29 = rtb_P6_Value;

  /* Rounding: '<S698>/Res_goRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S698>/Res_go_Convert1' */
  rtb_APA_SteeringAngleReqProte_n = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S698>/Res_go_L' */
  rtb_APA_SteeringAngleReqProte_h = rtb_APA_SteeringAngleReqProte_n & 255U;

  /* DataTypeConversion: '<S698>/Res_go_Convert' */
  rtb_APA_CheckSum_Convert = (uint8_T)rtb_APA_SteeringAngleReqProte_h;

  /* S-Function (sfix_bitop): '<S695>/or6' */
  VCU_CS75_9_30_B.or6 = rtb_APA_CheckSum_Convert;

  /* Saturate: '<S700>/Steering_feedback_sat' */
  if (rtb_APP_Input_idx_99 > 499.998565) {
    rtb_P6_Value = 499.998565;
  } else if (rtb_APP_Input_idx_99 < -500.0) {
    rtb_P6_Value = -500.0;
  } else {
    rtb_P6_Value = rtb_APP_Input_idx_99;
  }

  /* End of Saturate: '<S700>/Steering_feedback_sat' */

  /* Sum: '<S700>/Steering_feedback_st' incorporates:
   *  Constant: '<S700>/Steering_feedback_O'
   */
  rtb_APP_Input_idx_29 = rtb_P6_Value - -500.0;

  /* Product: '<S700>/Steering_feedback_D' */
  rtb_P6_Value = rtb_APP_Input_idx_29 / 0.015258999541401863;

  /* Rounding: '<S700>/Steering_feedbackRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S700>/Steering_feedback_Convert' */
  rtb_APA_SteeringAngleReqProte_n = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S700>/Steering_feedback_L' */
  rtb_APA_SteeringAngleReqProte_h = rtb_APA_SteeringAngleReqProte_n & 65535U;

  /* S-Function (sfix_bitop): '<S700>/Steering_feedback_And' incorporates:
   *  Constant: '<S700>/Steering_feedback_And_C'
   */
  rtb_APA_SteeringAngleReqProte_n = rtb_APA_SteeringAngleReqProte_h & 255U;

  /* DataTypeConversion: '<S700>/BitCov' */
  rtb_APA_CheckSum_Convert = (uint8_T)rtb_APA_SteeringAngleReqProte_n;

  /* S-Function (sfix_bitop): '<S695>/or7' */
  VCU_CS75_9_30_B.or7 = rtb_APA_CheckSum_Convert;

  /* Product: '<S700>/Steering_feedback_D1' incorporates:
   *  Constant: '<S700>/Steering_feedbackoutput8_C'
   */
  rtb_P6_Value = (real_T)rtb_APA_SteeringAngleReqProte_h / 256.0;

  /* DataTypeConversion: '<S700>/Steering_feedbackCOV' */
  rtb_APA_CheckSum_Convert = (uint8_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S695>/or8' */
  VCU_CS75_9_30_B.or8 = rtb_APA_CheckSum_Convert;

  /* S-Function (ec5744_cantransmitslb): '<S693>/CANTransmit' */

  /*Transmit CAN message*/
  {
    uint8 CAN0BUF8TX[8];
    uint8 can0buf8looptx= 0;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_9_30_B.or1;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_9_30_B.or2;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_9_30_B.or3;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_9_30_B.or4;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_9_30_B.or5;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_9_30_B.or6;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_9_30_B.or7;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_9_30_B.or8;
    can0buf8looptx++;
    VCU_CS75_9_30_B.CANTransmit_n= ec_can_transmit(0, 8, 1, 1297U, 8, CAN0BUF8TX);
  }

  /* DataTypeConversion: '<S693>/Data Type Conversion' */
  EMS_FrictionalTroq = rtb_APP_Input_idx_8;

  /* DataTypeConversion: '<S693>/Data Type Conversion1' */
  EMS_TorqueConstant = rtb_APP_Input_idx_20;

  /* DataTypeConversion: '<S693>/Data Type Conversion2' */
  EMS_FullLoadIndicatedTroq = rtb_APP_Input_idx_19;

  /* Saturate: '<S715>/APA_EPSAngleReq_sat' */
  rtb_P6_Value = rtb_APP_Input_idx_0;

  /* Sum: '<S715>/APA_EPSAngleReq_st' */
  rtb_APP_Input_idx_29 = rtb_P6_Value;

  /* Product: '<S715>/APA_EPSAngleReq_D' */
  rtb_P6_Value = rtb_APP_Input_idx_29 / 0.10000000149011612;

  /* Rounding: '<S715>/APA_EPSAngleReqRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* RelationalOperator: '<S715>/APA_EPSAngleReqROP' */
  rtb_APA_EPSAngleReqROP = (rtb_P6_Value < 0.0);

  /* Switch: '<S715>/APA_EPSAngleReqSW' */
  if (rtb_APA_EPSAngleReqROP) {
    /* Abs: '<S715>/APA_EPSAngleReqABS' */
    rtb_P6_Value = fabs(rtb_P6_Value);

    /* Sum: '<S715>/APA_EPSAngleReqsubcon' */
    rtb_P6_Value = 65536.0 - rtb_P6_Value;
  }

  /* End of Switch: '<S715>/APA_EPSAngleReqSW' */

  /* ArithShift: '<S715>/APA_EPSAngleReq_S' */
  rtb_P6_Value = ldexp(rtb_P6_Value, 4);

  /* Saturate: '<S715>/APA_EPSAngleReq_1sat' */
  if (rtb_P6_Value > 1.04856E+6) {
    rtb_P6_Value = 1.04856E+6;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S715>/APA_EPSAngleReq_1sat' */

  /* DataTypeConversion: '<S715>/APA_EPSAngleReq_Convert' */
  rtb_APA_SteeringAngleReqProte_n = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S715>/APA_EPSAngleReq_L' */
  rtb_APA_SteeringAngleReqProte_h = rtb_APA_SteeringAngleReqProte_n & 1048560U;

  /* S-Function (sfix_bitop): '<S715>/APA_EPSAngleReq_And1' incorporates:
   *  Constant: '<S715>/APA_EPSAngleReq_And1_C'
   */
  rtb_APA_SteeringAngleReqProte_n = rtb_APA_SteeringAngleReqProte_h & 255U;

  /* DataTypeConversion: '<S715>/APA_EPSAngleReqBitCov1' */
  rtb_APA_CheckSum_Convert = (uint8_T)rtb_APA_SteeringAngleReqProte_n;

  /* Product: '<S715>/APA_EPSAngleReq_D1' incorporates:
   *  Constant: '<S715>/APA_EPSAngleReqoutput2_C'
   */
  rtb_P6_Value = (real_T)rtb_APA_SteeringAngleReqProte_h / 65536.0;

  /* DataTypeConversion: '<S715>/APA_EPSAngleReqCOV' */
  rtb_APA_EPSAngleReqCOV = (uint8_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S715>/APA_EPSAngleReq_And' */
  rtb_APA_SteeringAngleReqProte_n = rtb_APA_SteeringAngleReqProte_h & 65535U;

  /* Product: '<S715>/APA_EPSAngleReq_D2' incorporates:
   *  Constant: '<S715>/APA_EPSAngleReqoutput3_C'
   */
  rtb_P6_Value = (real_T)rtb_APA_SteeringAngleReqProte_n / 256.0;

  /* DataTypeConversion: '<S715>/APA_EPSAngleReqCOV1' */
  rtb_APA_EPSAngleReqCOV1 = (uint8_T)rtb_P6_Value;

  /* Saturate: '<S716>/APA_IncreasePressureReq_sat' incorporates:
   *  Constant: '<S712>/Constant2'
   */
  rtb_P6_Value = 0.0;

  /* Saturate: '<S719>/APA_RollingCounter_sat' */
  rtb_APP_Input_idx_29 = APA_RollingCounter;
  if (rtb_APP_Input_idx_29 > 15.0) {
    rtb_P6_Value = 15.0;
  } else {
    if (!(rtb_APP_Input_idx_29 < 0.0)) {
      rtb_P6_Value = rtb_APP_Input_idx_29;
    }
  }

  /* End of Saturate: '<S719>/APA_RollingCounter_sat' */

  /* Rounding: '<S719>/APA_RollingCounterRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S719>/APA_RollingCounter_Convert1' */
  rtb_APA_SteeringAngleReqProte_n = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S719>/APA_RollingCounter_L' */
  rtb_APA_SteeringAngleReqProte_h = rtb_APA_SteeringAngleReqProte_n & 15U;

  /* DataTypeConversion: '<S719>/APA_RollingCounter_Convert' */
  rtb_APA_RollingCounter_Convert = (uint8_T)rtb_APA_SteeringAngleReqProte_h;

  /* Saturate: '<S720>/APA_SteeringAngleReqProtection_sat' */
  rtb_P6_Value = rtb_LateralTakeover;

  /* Sum: '<S720>/APA_SteeringAngleReqProtection_st' */
  rtb_APP_Input_idx_29 = rtb_P6_Value;

  /* Rounding: '<S720>/APA_SteeringAngleReqProtectionRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S720>/APA_SteeringAngleReqProtection_Convert1' */
  rtb_APA_SteeringAngleReqProte_n = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S720>/APA_SteeringAngleReqProtection_L' */
  rtb_APA_SteeringAngleReqProte_h = rtb_APA_SteeringAngleReqProte_n;

  /* DataTypeConversion: '<S720>/APA_SteeringAngleReqProtection_Convert' */
  rtb_APA_SteeringAngleReqProt_au = (uint8_T)rtb_APA_SteeringAngleReqProte_h;

  /* S-Function (sfix_bitop): '<S713>/or1' */
  VCU_CS75_9_30_B.or1_a = 0U;

  /* S-Function (sfix_bitop): '<S713>/or2' */
  VCU_CS75_9_30_B.or2_l = rtb_APA_EPSAngleReqCOV;

  /* S-Function (sfix_bitop): '<S713>/or3' */
  VCU_CS75_9_30_B.or3_d = rtb_APA_EPSAngleReqCOV1;

  /* S-Function (sfix_bitop): '<S713>/or4' */
  VCU_CS75_9_30_B.or4_k = rtb_APA_CheckSum_Convert;

  /* S-Function (sfix_bitop): '<S713>/or5' */
  VCU_CS75_9_30_B.or5_e = rtb_APA_SteeringAngleReqProt_au;

  /* S-Function (sfix_bitop): '<S713>/or7' */
  VCU_CS75_9_30_B.or7_a = rtb_APA_RollingCounter_Convert;

  /* S-Function (sfix_bitop): '<S713>/or8' */
  VCU_CS75_9_30_B.or8_l = 0U;

  /* S-Function (ec5744_cantransmitslb): '<S712>/CANTransmit' */

  /*Transmit CAN message*/
  {
    uint8 CAN1BUF10TX[8];
    uint8 can1buf10looptx= 0;
    CAN1BUF10TX[can1buf10looptx]= VCU_CS75_9_30_B.or1_a;
    can1buf10looptx++;
    CAN1BUF10TX[can1buf10looptx]= VCU_CS75_9_30_B.or2_l;
    can1buf10looptx++;
    CAN1BUF10TX[can1buf10looptx]= VCU_CS75_9_30_B.or3_d;
    can1buf10looptx++;
    CAN1BUF10TX[can1buf10looptx]= VCU_CS75_9_30_B.or4_k;
    can1buf10looptx++;
    CAN1BUF10TX[can1buf10looptx]= VCU_CS75_9_30_B.or5_e;
    can1buf10looptx++;
    CAN1BUF10TX[can1buf10looptx]= VCU_CS75_9_30_ConstB.or6;
    can1buf10looptx++;
    CAN1BUF10TX[can1buf10looptx]= VCU_CS75_9_30_B.or7_a;
    can1buf10looptx++;
    CAN1BUF10TX[can1buf10looptx]= VCU_CS75_9_30_B.or8_l;
    can1buf10looptx++;
    VCU_CS75_9_30_B.CANTransmit_j= ec_can_transmit(1, 10, 0, 650U, 8,
      CAN1BUF10TX);
  }
}

/* Model step function for TID5 */
void VCU_CS75_9_30_step5(void)         /* Sample time: [0.05s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S4>/50ms' incorporates:
   *  SubSystem: '<S4>/daq50ms'
   */

  /* S-Function (ec5744_ccpslb1): '<S18>/CCPDAQ' */
  ccpDaq(2);
}

/* Model step function for TID6 */
void VCU_CS75_9_30_step6(void)         /* Sample time: [0.1s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S3>/100MS' incorporates:
   *  SubSystem: '<S3>/Function-Call Subsystem'
   */

  /* S-Function (ec5744_canreceiveslb): '<S7>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN2BUF1RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can2buf1looprx= 0;
    VCU_CS75_9_30_B.CANReceive_o3_i= 278;
    VCU_CS75_9_30_B.CANReceive_o5_i= 8;
    VCU_CS75_9_30_B.CANReceive_o2_a= ec_can_receive(2,1, CAN2BUF1RX);
    VCU_CS75_9_30_B.CANReceive_o4_h[0]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_h[1]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_h[2]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_h[3]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_h[4]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_h[5]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_h[6]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_9_30_B.CANReceive_o4_h[7]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
  }

  /* Call the system: <S7>/Function-Call Subsystem */

  /* Output and update for function-call system: '<S7>/Function-Call Subsystem' */
  {
    uint8_T rtb_Add;
    uint8_T rtb_Compare;

    /* Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S9>/Enable'
     */
    if (VCU_CS75_9_30_B.CANReceive_o2_a > 0) {
      /* RelationalOperator: '<S10>/Compare' incorporates:
       *  Constant: '<S10>/Constant'
       */
      rtb_Add = (uint8_T)(VCU_CS75_9_30_B.CANReceive_o4_h[0] == 83);

      /* RelationalOperator: '<S11>/Compare' incorporates:
       *  Constant: '<S11>/Constant'
       */
      rtb_Compare = (uint8_T)(VCU_CS75_9_30_B.CANReceive_o4_h[5] == 84);

      /* Sum: '<S9>/Add' */
      rtb_Add = (uint8_T)((uint32_T)rtb_Add + rtb_Compare);

      /* RelationalOperator: '<S12>/Compare' incorporates:
       *  Constant: '<S12>/Constant'
       */
      rtb_Compare = (uint8_T)(rtb_Add == 2);

      /* If: '<S9>/If' incorporates:
       *  Constant: '<S14>/Constant'
       */
      if (rtb_Compare > 0) {
        /* Outputs for IfAction SubSystem: '<S9>/If Action Subsystem' incorporates:
         *  ActionPort: '<S13>/Action Port'
         */

        /* S-Function (ec5744_bootloaderslb): '<S13>/BootLoader' */
        {
          uint16 i= 0;
          N256K_BLOCK_SEL n256KBlockSelect;
          CONTEXT_DATA pgmCtxData;
          n256KBlockSelect.first256KBlockSelect = 0x00000080;
          n256KBlockSelect.second256KBlockSelect = 0x00000000;
          pgmCtxData.pReqCompletionFn = pFlashProgram;
          uint8 CAN2BUF9TX[]= { 11, 12, 12, 13 };

          uint8 returnCode1= 0;
          uint8 bootflag[]= { 1, 0, 0, 0, 0, 0, 0, 0 };

          DisableInterrupts();
          SIUL2.GPDO[22].R = 1;
          App_FlashErase( &ssdConfig, 0, 0x00000000, 0x00000000, 0x00000000,
                         n256KBlockSelect );
          App_FlashProgram( &ssdConfig, 0, 0x011FFFF0, 8, (uint32)bootflag,
                           &pgmCtxData );
          i= 1000;
          while (i--) {
            ;
          }

          ec_can_transmit(2, 9, 0, 593, 4, CAN2BUF9TX);
          i= 10000;
          while (i--) {
            ;
          }
        }

        /* S-Function (ec5744_cpuresetslb): '<S13>/CPUReset' */

        /* Perform a microcontroller reset */
        MC_ME.MCTL.R = 0X00005AF0;
        MC_ME.MCTL.R = 0X0000A50F;

        /* End of Outputs for SubSystem: '<S9>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S9>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S14>/Action Port'
         */

        /* S-Function (ec5744_cantransmitslb): '<S14>/CANTransmit' */

        /*Transmit CAN message*/
        {
          uint8 CAN2BUF9TX[1];
          uint8 can2buf9looptx= 0;
          CAN2BUF9TX[can2buf9looptx]= ((uint8_T)1U);
          can2buf9looptx++;
          VCU_CS75_9_30_B.CANTransmit= ec_can_transmit(2, 9, 0, 593U, 1,
            CAN2BUF9TX);
        }

        /* End of Outputs for SubSystem: '<S9>/If Action Subsystem1' */
      }

      /* End of If: '<S9>/If' */
    }

    /* End of Outputs for SubSystem: '<S8>/Enabled Subsystem' */
  }

  /* S-Function (fcncallgen): '<S4>/100ms' incorporates:
   *  SubSystem: '<S4>/daq100ms'
   */

  /* S-Function (ec5744_ccpslb1): '<S15>/CCPDAQ' */
  ccpDaq(3);
}

/* Model step function for TID7 */
void VCU_CS75_9_30_step7(void)         /* Sample time: [0.5s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S4>/500ms' incorporates:
   *  SubSystem: '<S4>/daq500ms'
   */

  /* S-Function (ec5744_ccpslb1): '<S17>/CCPDAQ' */
  ccpDaq(4);

  /* S-Function (fcncallgen): '<S5>/500ms' incorporates:
   *  SubSystem: '<S5>/EEPROMOperation'
   */

  /* S-Function (ec5744_eepromoslb): '<S20>/EEPROMOperatin' */
#if defined EC_EEPROM_ENABLE

  /* Operate the EEPROM module on the MPC5744 */
  ec_flash_operation();

#endif

}

/* Model step wrapper function for compatibility with a static main program */
void VCU_CS75_9_30_step(int_T tid)
{
  switch (tid) {
   case 0 :
    VCU_CS75_9_30_step0();
    break;

   case 1 :
    VCU_CS75_9_30_step1();
    break;

   case 2 :
    VCU_CS75_9_30_step2();
    break;

   case 3 :
    VCU_CS75_9_30_step3();
    break;

   case 4 :
    VCU_CS75_9_30_step4();
    break;

   case 5 :
    VCU_CS75_9_30_step5();
    break;

   case 6 :
    VCU_CS75_9_30_step6();
    break;

   case 7 :
    VCU_CS75_9_30_step7();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void VCU_CS75_9_30_initialize(void)
{
  /* Start for S-Function (fcncallgen): '<Root>/20ms' incorporates:
   *  Start for SubSystem: '<Root>/长安CS75底盘程序，20ms一次'
   */

  /* Start for Atomic SubSystem: '<S2>/BSW_Input' */

  /* Start for S-Function (ec5744_canreceiveslb): '<S63>/CANReceive' */
  ec_buffer_init(0,0,0,529);

  /* Start for S-Function (ec5744_canreceiveslb): '<S77>/CANReceive' */
  ec_buffer_init(1,23,0,648);

  /* Start for S-Function (ec5744_canreceiveslb): '<S78>/CANReceive' */
  ec_buffer_init(1,24,0,808);

  /* Start for S-Function (ec5744_canreceiveslb): '<S79>/CANReceive' */
  ec_buffer_init(1,25,0,840);

  /* Start for S-Function (ec5744_canreceiveslb): '<S80>/CANReceive' */
  ec_buffer_init(1,26,0,991);

  /* Start for S-Function (ec5744_canreceiveslb): '<S81>/CANReceive' */
  ec_buffer_init(1,0,0,517);

  /* Start for S-Function (ec5744_canreceiveslb): '<S82>/CANReceive' */
  ec_buffer_init(1,1,0,597);

  /* Start for S-Function (ec5744_canreceiveslb): '<S83>/CANReceive' */
  ec_buffer_init(1,2,0,613);

  /* Start for S-Function (ec5744_canreceiveslb): '<S84>/CANReceive' */
  ec_buffer_init(1,3,0,630);

  /* Start for S-Function (ec5744_canreceiveslb): '<S85>/CANReceive' */
  ec_buffer_init(1,4,0,598);

  /* Start for S-Function (ec5744_canreceiveslb): '<S86>/CANReceive' */
  ec_buffer_init(1,5,0,522);

  /* Start for S-Function (ec5744_canreceiveslb): '<S87>/CANReceive' */
  ec_buffer_init(1,6,0,538);

  /* Start for S-Function (ec5744_canreceiveslb): '<S88>/CANReceive' */
  ec_buffer_init(1,7,0,631);

  /* Start for S-Function (ec5744_canreceiveslb): '<S89>/CANReceive' */
  ec_buffer_init(1,16,0,640);

  /* Start for S-Function (ec5744_canreceiveslb): '<S90>/CANReceive' */
  ec_buffer_init(1,17,0,641);

  /* Start for S-Function (ec5744_canreceiveslb): '<S91>/CANReceive' */
  ec_buffer_init(1,18,0,647);

  /* Start for S-Function (ec5744_canreceiveslb): '<S92>/CANReceive' */
  ec_buffer_init(1,27,0,523);

  /* Start for S-Function (ec5744_canreceiveslb): '<S93>/CANReceive' */
  ec_buffer_init(1,29,0,776);

  /* Start for S-Function (ec5744_canreceiveslb): '<S94>/CANReceive' */
  ec_buffer_init(1,28,0,818);

  /* Start for S-Function (ec5744_canreceiveslb): '<S95>/CANReceive' */
  ec_buffer_init(1,30,0,886);

  /* Start for S-Function (ec5744_canreceiveslb): '<S96>/CANReceive' */
  ec_buffer_init(1,31,0,930);

  /* Start for S-Function (ec5744_canreceiveslb): '<S97>/CANReceive' */
  ec_buffer_init(1,32,0,1383);

  /* Start for S-Function (ec5744_canreceiveslb): '<S98>/CANReceive' */
  ec_buffer_init(1,33,0,1280);

  /* Start for S-Function (ec5744_canreceiveslb): '<S99>/CANReceive' */
  ec_buffer_init(1,36,0,878);

  /* Start for S-Function (ec5744_canreceiveslb): '<S100>/CANReceive' */
  ec_buffer_init(1,19,0,264);

  /* Start for S-Function (ec5744_canreceiveslb): '<S101>/CANReceive' */
  ec_buffer_init(1,20,0,952);

  /* Start for S-Function (ec5744_canreceiveslb): '<S102>/CANReceive' */
  ec_buffer_init(1,21,0,5);

  /* Start for S-Function (ec5744_canreceiveslb): '<S103>/CANReceive' */
  ec_buffer_init(1,22,0,646);

  /* End of Start for SubSystem: '<S2>/BSW_Input' */

  /* Start for Atomic SubSystem: '<S2>/APP' */
  /* Start for Constant: '<S49>/Constant' */
  Server_CommunicationStatus = 1.0;

  /* End of Start for SubSystem: '<S2>/APP' */
  /* Start for S-Function (ec5744_cantransmitslb): '<S693>/CANTransmit' */
  ec_buffer_init(0,8,1,1297U);

  /* Start for S-Function (ec5744_cantransmitslb): '<S712>/CANTransmit' */
  ec_buffer_init(1,10,0,650U);

  /* Start for S-Function (fcncallgen): '<S3>/100MS' incorporates:
   *  Start for SubSystem: '<S3>/Function-Call Subsystem'
   */
  /* Start for S-Function (ec5744_canreceiveslb): '<S7>/CANReceive' incorporates:
   *  Start for SubSystem: '<S7>/Function-Call Subsystem'
   */
  /* Start for function-call system: '<S7>/Function-Call Subsystem' */

  /* Start for Enabled SubSystem: '<S8>/Enabled Subsystem' */

  /* Start for IfAction SubSystem: '<S9>/If Action Subsystem1' */

  /* Start for S-Function (ec5744_cantransmitslb): '<S14>/CANTransmit' */
  ec_buffer_init(2,9,0,593U);

  /* End of Start for SubSystem: '<S9>/If Action Subsystem1' */

  /* End of Start for SubSystem: '<S8>/Enabled Subsystem' */

  /* Start for S-Function (ec5744_canreceiveslb): '<S7>/CANReceive' */
  ec_buffer_init(2,1,0,278);

  /* Start for S-Function (fcncallgen): '<S6>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S6>/CCPBackground'
   */
  /* Start for S-Function (ec5744_ccpslb): '<S21>/CCPBackground' */
  ccpInit();

  /* Start for S-Function (ec5744_caninterruptslb1): '<S6>/ReceiveandTransmitInterrupt' incorporates:
   *  Start for SubSystem: '<S6>/CCPReceive'
   */
  /* Start for function-call system: '<S6>/CCPReceive' */

  /* Start for S-Function (ec5744_canreceiveslb): '<S22>/CANReceive' */
  ec_buffer_init(2,0,0,CCP_CRO_ID);

  /* Start for S-Function (ec5744_caninterruptslb1): '<S6>/ReceiveandTransmitInterrupt' */
  ec_bufint_init(2,0);
  INTC_0.PSR[548].B.PRIN = 12;
  IntcIsrVectorTable[548] = (uint32_t)&ISR_FlexCAN_2_MB0;
}

/* File trailer for ECUCoder generated file VCU_CS75_9_30.c.
 *
 * [EOF]
 */
