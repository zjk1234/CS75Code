/*
 * Code generated for Simulink model VCU_CS75_12_27_test_log.
 *
 * FILE    : VCU_CS75_12_27_test_log.c
 *
 * VERSION : 1.2787
 *
 * DATE    : Sun Dec 27 21:26:42 2020
 *
 * Copyright 2011-2017 ECUCoder. All Rights Reserved.
 */

#include "VCU_CS75_12_27_test_log.h"
#include "VCU_CS75_12_27_test_log_private.h"

/* #include "myinclude.h" */

/* Named constants for Chart: '<S29>/Chart' */
#define VCU_CS75_12_27__IN_System_State ((uint8_T)1U)
#define VCU_CS75_12_27_t_IN_AutoDriving ((uint8_T)1U)
#define VCU_CS75_12_27_test_IN_TakeOver ((uint8_T)4U)
#define VCU_CS75_12_27_test_lo_IN_Error ((uint8_T)2U)
#define VCU_CS75__IN_INIT_ManualDriving ((uint8_T)3U)

/* Exported block parameters */
real_T ErrorSumMax1 = 0.0;             /* Variable: ErrorSumMax1
                                        * Referenced by: '<S32>/ECCalVar6'
                                        */
real_T ErrorSumMax2 = 0.0;             /* Variable: ErrorSumMax2
                                        * Referenced by: '<S32>/ECCalVar7'
                                        */
real_T ErrorSumMax3 = 0.0;             /* Variable: ErrorSumMax3
                                        * Referenced by: '<S32>/ECCalVar8'
                                        */
real_T I1 = 0.0;                       /* Variable: I1
                                        * Referenced by: '<S32>/ECCalVar1'
                                        */
real_T I2 = 0.0;                       /* Variable: I2
                                        * Referenced by: '<S32>/ECCalVar3'
                                        */
real_T I3 = 0.0;                       /* Variable: I3
                                        * Referenced by: '<S32>/ECCalVar5'
                                        */
real_T LDW = 0.0;                      /* Variable: LDW
                                        * Referenced by: '<S30>/ECCalVar'
                                        */
real_T Log_ErrorSumMax1 = 0.0;         /* Variable: Log_ErrorSumMax1
                                        * Referenced by: '<S33>/ECCalVar4'
                                        */
real_T Log_ErrorSumMax2 = 0.0;         /* Variable: Log_ErrorSumMax2
                                        * Referenced by: '<S33>/ECCalVar5'
                                        */
real_T Log_I1 = 0.0;                   /* Variable: Log_I1
                                        * Referenced by: '<S33>/ECCalVar1'
                                        */
real_T Log_I2 = 0.0;                   /* Variable: Log_I2
                                        * Referenced by: '<S33>/ECCalVar3'
                                        */
real_T Log_P1 = 0.0;                   /* Variable: Log_P1
                                        * Referenced by: '<S33>/ECCalVar'
                                        */
real_T Log_P2 = 0.0;                   /* Variable: Log_P2
                                        * Referenced by: '<S33>/ECCalVar2'
                                        */
real_T Log_Takeover = 0.0;             /* Variable: Log_Takeover
                                        * Referenced by: '<S69>/ECCalVar'
                                        */
real_T P1 = 0.0;                       /* Variable: P1
                                        * Referenced by: '<S32>/ECCalVar'
                                        */
real_T P2 = 0.0;                       /* Variable: P2
                                        * Referenced by: '<S32>/ECCalVar2'
                                        */
real_T P3 = 0.0;                       /* Variable: P3
                                        * Referenced by: '<S32>/ECCalVar4'
                                        */
real_T RemoteAcc = 0.0;                /* Variable: RemoteAcc
                                        * Referenced by: '<S69>/ECCalVar1'
                                        */

/* Exported data definition */

/* Definition for custom storage class: Default */
real_T A1counter;
real_T ACC_ACCTargetAcceleration;
real_T ACC_CDDAxEnable;
real_T ACC_Driveoff_Request;
real_T ACC_RollingCounter_id2E4;
real_T ACC_RollingCounter_id2E5;
real_T ACC_TrqEnable;
real_T EMS_BrakePedalStatus;
real_T EMS_FrictionalTroq;
real_T EMS_FullLoadIndicatedTroq;
real_T EMS_IndicatedRealTroq;
real_T EMS_TorqueConstant;
real_T EPB_RollingCounter_id256;
real_T EPS_AvailabilityStatus;
real_T Error;
real_T ErrorSum;
real_T LAS_LDWStatus;
real_T LAS_LDWVibrationWarning;
real_T LAS_LKSStatus;
real_T LAS_RollingCounter;
real_T P6_Value;
real_T PID_SteeringOut;
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
B_VCU_CS75_12_27_test_log_T VCU_CS75_12_27_test_log_B;

/* Block states (auto storage) */
DW_VCU_CS75_12_27_test_log_T VCU_CS75_12_27_test_log_DW;

/* Real-time model */
RT_MODEL_VCU_CS75_12_27_test__T VCU_CS75_12_27_test_log_M_;
RT_MODEL_VCU_CS75_12_27_test__T *const VCU_CS75_12_27_test_log_M =
  &VCU_CS75_12_27_test_log_M_;
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
      VCU_CS75_12_27_test_log_B.CANReceive_o3= 256;
      VCU_CS75_12_27_test_log_B.CANReceive_o5= 8;
      VCU_CS75_12_27_test_log_B.CANReceive_o2= ec_can_receive(2,0, CAN2BUF0RX);
      VCU_CS75_12_27_test_log_B.CANReceive_o4[0]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_12_27_test_log_B.CANReceive_o4[1]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_12_27_test_log_B.CANReceive_o4[2]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_12_27_test_log_B.CANReceive_o4[3]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_12_27_test_log_B.CANReceive_o4[4]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_12_27_test_log_B.CANReceive_o4[5]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_12_27_test_log_B.CANReceive_o4[6]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_12_27_test_log_B.CANReceive_o4[7]= CAN2BUF0RX[can2buf0looprx];
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
void VCU_CS75_12_27_test_log_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(VCU_CS75_12_27_test_log_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(VCU_CS75_12_27_test_log_M, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(VCU_CS75_12_27_test_log_M, 3));
  eventFlags[4] = ((boolean_T)rtmStepTask(VCU_CS75_12_27_test_log_M, 4));
  eventFlags[5] = ((boolean_T)rtmStepTask(VCU_CS75_12_27_test_log_M, 5));
  eventFlags[6] = ((boolean_T)rtmStepTask(VCU_CS75_12_27_test_log_M, 6));
  eventFlags[7] = ((boolean_T)rtmStepTask(VCU_CS75_12_27_test_log_M, 7));
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
  (VCU_CS75_12_27_test_log_M->Timing.TaskCounters.TID[1])++;
  if ((VCU_CS75_12_27_test_log_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.001s, 0.0s] */
    VCU_CS75_12_27_test_log_M->Timing.TaskCounters.TID[1] = 0;
  }

  (VCU_CS75_12_27_test_log_M->Timing.TaskCounters.TID[2])++;
  if ((VCU_CS75_12_27_test_log_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.005s, 0.0s] */
    VCU_CS75_12_27_test_log_M->Timing.TaskCounters.TID[2] = 0;
  }

  (VCU_CS75_12_27_test_log_M->Timing.TaskCounters.TID[3])++;
  if ((VCU_CS75_12_27_test_log_M->Timing.TaskCounters.TID[3]) > 19) {/* Sample time: [0.01s, 0.0s] */
    VCU_CS75_12_27_test_log_M->Timing.TaskCounters.TID[3] = 0;
  }

  (VCU_CS75_12_27_test_log_M->Timing.TaskCounters.TID[4])++;
  if ((VCU_CS75_12_27_test_log_M->Timing.TaskCounters.TID[4]) > 39) {/* Sample time: [0.02s, 0.0s] */
    VCU_CS75_12_27_test_log_M->Timing.TaskCounters.TID[4] = 0;
  }

  (VCU_CS75_12_27_test_log_M->Timing.TaskCounters.TID[5])++;
  if ((VCU_CS75_12_27_test_log_M->Timing.TaskCounters.TID[5]) > 99) {/* Sample time: [0.05s, 0.0s] */
    VCU_CS75_12_27_test_log_M->Timing.TaskCounters.TID[5] = 0;
  }

  (VCU_CS75_12_27_test_log_M->Timing.TaskCounters.TID[6])++;
  if ((VCU_CS75_12_27_test_log_M->Timing.TaskCounters.TID[6]) > 199) {/* Sample time: [0.1s, 0.0s] */
    VCU_CS75_12_27_test_log_M->Timing.TaskCounters.TID[6] = 0;
  }

  (VCU_CS75_12_27_test_log_M->Timing.TaskCounters.TID[7])++;
  if ((VCU_CS75_12_27_test_log_M->Timing.TaskCounters.TID[7]) > 999) {/* Sample time: [0.5s, 0.0s] */
    VCU_CS75_12_27_test_log_M->Timing.TaskCounters.TID[7] = 0;
  }
}

/*
 * Output and update for atomic system:
 *    '<S30>/MATLAB Function2'
 *    '<S32>/MATLAB Function7'
 *    '<S33>/MATLAB Function7'
 */
void VCU_CS75_12_MATLABFunction2(real_T rtu_u, B_MATLABFunction2_VCU_CS75_12_T
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

/*
 * Output and update for atomic system:
 *    '<S32>/MATLAB Function1'
 *    '<S33>/MATLAB Function5'
 */
void VCU_CS75_12_MATLABFunction1(real_T rtu_L1, real_T rtu_u1, real_T rtu_u2,
  B_MATLABFunction1_VCU_CS75_12_T *localB)
{
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Lateral/MATLAB Function1': '<S39>:1' */
  if (rtu_u1 - rtu_u2 > rtu_L1) {
    /* '<S39>:1:2' */
    /* '<S39>:1:3' */
    localB->y = rtu_u2 + rtu_L1;
  } else if (rtu_u1 - rtu_u2 < -rtu_L1) {
    /* '<S39>:1:5' */
    /* '<S39>:1:6' */
    localB->y = rtu_u2 - rtu_L1;
  } else {
    /* '<S39>:1:8' */
    localB->y = rtu_u1;
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

real32_T rt_roundf_snf(real32_T u)
{
  real32_T y;
  if ((real32_T)fabs(u) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = (real32_T)floor(u + 0.5F);
    } else if (u > -0.5F) {
      y = u * 0.0F;
    } else {
      y = (real32_T)ceil(u - 0.5F);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function for TID0 */
void VCU_CS75_12_27_test_log_step0(void) /* Sample time: [0.0005s, 0.0s] */
{
  {                                    /* Sample time: [0.0005s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void VCU_CS75_12_27_test_log_step1(void) /* Sample time: [0.001s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S6>/Function-Call Generator' incorporates:
   *  SubSystem: '<S6>/CCPBackground'
   */

  /* S-Function (ec5744_ccpslb): '<S21>/CCPBackground' */
  ccpBackground();
}

/* Model step function for TID2 */
void VCU_CS75_12_27_test_log_step2(void) /* Sample time: [0.005s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S4>/5ms' incorporates:
   *  SubSystem: '<S4>/daq5ms'
   */

  /* S-Function (ec5744_ccpslb1): '<S19>/CCPDAQ' */
  ccpDaq(0);
}

/* Model step function for TID3 */
void VCU_CS75_12_27_test_log_step3(void) /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S4>/10ms' incorporates:
   *  SubSystem: '<S4>/daq10ms'
   */

  /* S-Function (ec5744_ccpslb1): '<S16>/CCPDAQ' */
  ccpDaq(1);
}

/* Model step function for TID4 */
void VCU_CS75_12_27_test_log_step4(void) /* Sample time: [0.02s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_Memory5;
  real_T rtb_TorqueOut;
  real_T rtb_Memory4_e;
  uint32_T rtb_LAS_SteeringTorqueReq_L;
  uint32_T rtb_ErrorSum_Log_L;
  uint8_T rtb_ACC_CDDAxEnable_Convert;
  boolean_T rtb_ErrorSum_LogROP;
  real32_T rtb_ErrorSum_d;
  real32_T rtb_Error_m;
  uint32_T rtb_ErrorSum_Log_And;
  uint8_T rtb_ACC_ACCTargetAcceleration_C;
  uint8_T rtb_ACC_AccTrqReqEnable_Convert;
  uint8_T rtb_ErrorSum_LogCOV;
  real32_T rtb_ACC_AccTorqueReq;
  real32_T rtb_Error_Log;
  real32_T rtb_ErrorSum_Log;
  real_T rtb_P6_Value;
  real_T rtb_Memory2;
  real32_T rtb_Memory1_e;
  real_T rtb_Switch;
  real_T rtb_APP_Input_idx_99;
  real_T rtb_APP_Input_idx_2;
  real_T rtb_APP_Input_idx_1;
  real_T rtb_APP_Input_idx_19;
  real_T rtb_APP_Input_idx_20;
  real_T rtb_APP_Input_idx_8;
  real_T rtb_APP_Input_idx_217;
  real_T rtb_APP_Input_idx_9;
  real_T rtb_APP_Input_idx_66;
  real_T rtb_APP_Input_idx_63;
  real_T rtb_APP_Input_idx_3;
  real_T rtb_APP_Input_idx_17;
  real_T rtb_APP_Input_idx_90;
  real_T rtb_APP_Input_idx_12;
  real_T rtb_APP_Input_idx_0;
  real_T rtb_APP_Input_idx_39;
  real_T rtb_APP_Input_idx_79;
  real_T rtb_APP_Input_idx_29;

  /* S-Function (fcncallgen): '<Root>/20ms' incorporates:
   *  SubSystem: '<Root>/长安CS75底盘程序，20ms一次'
   */
  /* Outputs for Atomic SubSystem: '<S2>/Input' */

  /* S-Function (ec5744_swislbu3): '<S61>/SwitchInput' */

  /* Read the the value of the specified switch input */
  VCU_CS75_12_27_test_log_B.P6_Value_h= ec_gpio_read(92);

  /* DataTypeConversion: '<S61>/Data Type Conversion' */
  rtb_P6_Value = (real_T)VCU_CS75_12_27_test_log_B.P6_Value_h;

  /* MATLAB Function: '<S61>/MATLAB Function' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/Input/ADC_Input/MATLAB Function': '<S66>:1' */
  if (rtb_P6_Value == 1.0) {
    /* '<S66>:1:2' */
    /* '<S66>:1:3' */
    P6_Value = 0.0;
  } else {
    /* '<S66>:1:5' */
    P6_Value = 1.0;
  }

  /* End of MATLAB Function: '<S61>/MATLAB Function' */

  /* S-Function (ec5744_canreceiveslb): '<S67>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF0RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can0buf0looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_o= 529;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_o= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_a4= ec_can_receive(0,0, CAN0BUF0RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_d[0]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_d[1]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_d[2]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_d[3]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_d[4]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_d[5]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_d[6]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_d[7]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
  }

  /* Call the system: <S67>/ReceiveMessages */

  /* Output and update for function-call system: '<S67>/ReceiveMessages' */
  {
    real_T rtb_target_steering_sat;
    int32_T rtb_target_steering_L;
    real32_T rtb_throttlevbrake_position_sat;

    /* Outputs for Enabled SubSystem: '<S68>/Subsystem' incorporates:
     *  EnablePort: '<S69>/Enable'
     */
    if (VCU_CS75_12_27_test_log_B.CANReceive_o2_a4 > 0) {
      /* Product: '<S71>/Vxinput8_P' incorporates:
       *  Constant: '<S71>/Vxinput8_C'
       */
      rtb_target_steering_sat = (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_d[7] * 256.0;

      /* Sum: '<S71>/Vxinput8_Ad' */
      rtb_target_steering_sat += (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_d[6];

      /* DataTypeConversion: '<S71>/Vx_Convert' */
      rtb_target_steering_L = (int32_T)rtb_target_steering_sat;

      /* DataTypeConversion: '<S71>/Vxcv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* Gain: '<S71>/Vx_F' */
      rtb_throttlevbrake_position_sat *= 0.00610360876F;

      /* Sum: '<S71>/Vx_Ad' incorporates:
       *  Constant: '<S71>/Vx_O'
       */
      rtb_throttlevbrake_position_sat += -200.0F;

      /* Saturate: '<S71>/Vx_sat' */
      if (rtb_throttlevbrake_position_sat > 200.0F) {
        rtb_throttlevbrake_position_sat = 200.0F;
      }

      /* End of Saturate: '<S71>/Vx_sat' */

      /* DataStoreWrite: '<S69>/Data Store Write' */
      Vx_out = rtb_throttlevbrake_position_sat;

      /* DataTypeConversion: '<S71>/mission_Convert' */
      rtb_target_steering_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_d[5];

      /* S-Function (sfix_bitop): '<S71>/mission_L' */
      rtb_target_steering_L &= 240U;

      /* ArithShift: '<S71>/mission_S' */
      rtb_target_steering_L = (int32_T)((uint32_T)rtb_target_steering_L >> 4);

      /* DataTypeConversion: '<S71>/missioncv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* Saturate: '<S71>/mission_sat' */
      if (rtb_throttlevbrake_position_sat > 7.0F) {
        rtb_throttlevbrake_position_sat = 7.0F;
      }

      /* End of Saturate: '<S71>/mission_sat' */

      /* DataStoreWrite: '<S69>/Data Store Write1' */
      mission_out = rtb_throttlevbrake_position_sat;

      /* DataTypeConversion: '<S71>/SCS_Convert' */
      rtb_target_steering_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_d[5];

      /* S-Function (sfix_bitop): '<S71>/SCS_L' */
      rtb_target_steering_L &= 8U;

      /* ArithShift: '<S71>/SCS_S' */
      rtb_target_steering_L = (int32_T)((uint32_T)rtb_target_steering_L >> 3);

      /* DataTypeConversion: '<S71>/SCScv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* DataStoreWrite: '<S69>/Data Store Write2' */
      SCS_out = rtb_throttlevbrake_position_sat;

      /* DataTypeConversion: '<S71>/finish_Convert' */
      rtb_target_steering_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_d[5];

      /* S-Function (sfix_bitop): '<S71>/finish_L' */
      rtb_target_steering_L &= 4U;

      /* ArithShift: '<S71>/finish_S' */
      rtb_target_steering_L = (int32_T)((uint32_T)rtb_target_steering_L >> 2);

      /* DataTypeConversion: '<S71>/finishcv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* DataStoreWrite: '<S69>/Data Store Write3' */
      finish_out = rtb_throttlevbrake_position_sat;

      /* DataTypeConversion: '<S71>/tap_Convert' */
      rtb_target_steering_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_d[5];

      /* S-Function (sfix_bitop): '<S71>/tap_L' */
      rtb_target_steering_L &= 3U;

      /* DataTypeConversion: '<S71>/tapcv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* DataStoreWrite: '<S69>/Data Store Write4' */
      tap_out = rtb_throttlevbrake_position_sat;

      /* DataTypeConversion: '<S71>/cones_count_all_Convert' */
      rtb_target_steering_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_d[4];

      /* DataTypeConversion: '<S71>/cones_count_allcv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* DataStoreWrite: '<S69>/Data Store Write5' */
      cones_count_all_out = rtb_throttlevbrake_position_sat;

      /* DataTypeConversion: '<S71>/cones_count_actual_Convert' */
      rtb_target_steering_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_d[3];

      /* DataTypeConversion: '<S71>/cones_count_actualcv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* DataStoreWrite: '<S69>/Data Store Write6' */
      cones_count_actual_out = rtb_throttlevbrake_position_sat;

      /* SignalConversion: '<S69>/Signal Conversion' incorporates:
       *  Constant: '<S69>/ECCalVar'
       */
      /* MATLAB Function '长安CS75底盘程序，20ms一次/Input/CAN0_Rx/a1_211/ReceiveMessages/Subsystem/MATLAB Function1': '<S70>:1' */
      /* '<S70>:1:2' */
      VCU_CS75_12_27_test_log_B.AutoDrivingReady = Log_Takeover;

      /* SignalConversion: '<S69>/Signal Conversion' incorporates:
       *  Constant: '<S69>/ECCalVar1'
       */
      VCU_CS75_12_27_test_log_B.RemoteAcclPosition = RemoteAcc;

      /* Product: '<S71>/target_steeringinput2_P' incorporates:
       *  Constant: '<S71>/target_steeringinput2_C'
       */
      rtb_target_steering_sat = (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_d[1] * 256.0;

      /* Sum: '<S71>/target_steeringinput2_Ad' */
      rtb_target_steering_sat += (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_d[0];

      /* DataTypeConversion: '<S71>/target_steering_Convert' */
      rtb_target_steering_L = (int32_T)rtb_target_steering_sat;

      /* S-Function (sfix_bitop): '<S71>/target_steering_L' */
      rtb_target_steering_L &= 4095U;

      /* DataTypeConversion: '<S71>/target_steeringcv' */
      rtb_target_steering_sat = rtb_target_steering_L;

      /* Gain: '<S71>/target_steering_F' */
      rtb_target_steering_sat *= 0.0488400488400488;

      /* Sum: '<S71>/target_steering_Ad' incorporates:
       *  Constant: '<S71>/target_steering_O'
       */
      rtb_target_steering_sat += -100.0;

      /* Saturate: '<S71>/target_steering_sat' */
      if (rtb_target_steering_sat > 99.9999999999998) {
        rtb_target_steering_sat = 99.9999999999998;
      }

      /* End of Saturate: '<S71>/target_steering_sat' */

      /* SignalConversion: '<S69>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.LaterlAngleCommand = rtb_target_steering_sat;

      /* SignalConversion: '<S69>/Signal Conversion' incorporates:
       *  Constant: '<S69>/Constant'
       */
      VCU_CS75_12_27_test_log_B.A1_Message_Counter = 0.0;

      /* SignalConversion: '<S69>/Signal Conversion' incorporates:
       *  Constant: '<S69>/Constant1'
       */
      VCU_CS75_12_27_test_log_B.A1_Checksum = 0.0;
    }

    /* End of Outputs for SubSystem: '<S68>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S81>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF23RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf23looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_ik= 648;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_ox= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_i= ec_can_receive(1,23, CAN1BUF23RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_g[0]= CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_g[1]= CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_g[2]= CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_g[3]= CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_g[4]= CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_g[5]= CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_g[6]= CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_g[7]= CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
  }

  /* Call the system: <S81>/ReceiveMessages */

  /* Output and update for function-call system: '<S81>/ReceiveMessages' */
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

    /* Outputs for Enabled SubSystem: '<S108>/Subsystem' incorporates:
     *  EnablePort: '<S109>/Enable'
     */
    if (VCU_CS75_12_27_test_log_B.CANReceive_o2_i > 0) {
      /* DataTypeConversion: '<S110>/BCM_BuzzerWarningMode_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_g[7];

      /* S-Function (sfix_bitop): '<S110>/BCM_BuzzerWarningMode_L' */
      rtb_BCM_emergencylightstatus_L &= 31U;

      /* Sum: '<S110>/BCM_BuzzerWarningMode_Ad' */
      rtb_BCM_BuzzerWarningMode_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S110>/BCM_BuzzerWarningMode_sat' */
      u0 = rtb_BCM_BuzzerWarningMode_sat;
      rtb_BCM_BuzzerWarningMode_sat = (int32_T)u0;

      /* DataTypeConversion: '<S110>/BCM_DriverDoorLockStatus_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_g[5];

      /* S-Function (sfix_bitop): '<S110>/BCM_DriverDoorLockStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 3U;

      /* Sum: '<S110>/BCM_DriverDoorLockStatus_Ad' */
      rtb_BCM_DriverDoorLockStatus_sa = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S110>/BCM_DriverDoorLockStatus_sat' */
      u0 = rtb_BCM_DriverDoorLockStatus_sa;
      rtb_BCM_DriverDoorLockStatus_sa = (int32_T)u0;

      /* DataTypeConversion: '<S110>/BCM_DriverDoorStatus_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_g[2];

      /* S-Function (sfix_bitop): '<S110>/BCM_DriverDoorStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 128U;

      /* ArithShift: '<S110>/BCM_DriverDoorStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 7);

      /* Sum: '<S110>/BCM_DriverDoorStatus_Ad' */
      rtb_BCM_DriverDoorStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S110>/BCM_DriverDoorStatus_sat' */
      u0 = rtb_BCM_DriverDoorStatus_sat;
      rtb_BCM_DriverDoorStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S110>/BCM_FrontWashStatus_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_g[1];

      /* S-Function (sfix_bitop): '<S110>/BCM_FrontWashStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 3U;

      /* Sum: '<S110>/BCM_FrontWashStatus_Ad' */
      rtb_BCM_FrontWashStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S110>/BCM_FrontWashStatus_sat' */
      u0 = rtb_BCM_FrontWashStatus_sat;
      rtb_BCM_FrontWashStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S110>/BCM_FrontWiperStatus_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_g[5];

      /* S-Function (sfix_bitop): '<S110>/BCM_FrontWiperStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 192U;

      /* ArithShift: '<S110>/BCM_FrontWiperStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 6);

      /* Sum: '<S110>/BCM_FrontWiperStatus_Ad' */
      rtb_BCM_FrontWiperStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S110>/BCM_FrontWiperStatus_sat' */
      u0 = rtb_BCM_FrontWiperStatus_sat;
      rtb_BCM_FrontWiperStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S110>/BCM_HoodStatus_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_g[2];

      /* S-Function (sfix_bitop): '<S110>/BCM_HoodStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 4U;

      /* ArithShift: '<S110>/BCM_HoodStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 2);

      /* Sum: '<S110>/BCM_HoodStatus_Ad' */
      rtb_BCM_HoodStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S110>/BCM_HoodStatus_sat' */
      u0 = rtb_BCM_HoodStatus_sat;
      rtb_BCM_HoodStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S110>/BCM_LatchOverheatProtect_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_g[7];

      /* S-Function (sfix_bitop): '<S110>/BCM_LatchOverheatProtect_L' */
      rtb_BCM_emergencylightstatus_L &= 64U;

      /* ArithShift: '<S110>/BCM_LatchOverheatProtect_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 6);

      /* Sum: '<S110>/BCM_LatchOverheatProtect_Ad' */
      rtb_BCM_LatchOverheatProtect_sa = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S110>/BCM_LatchOverheatProtect_sat' */
      u0 = rtb_BCM_LatchOverheatProtect_sa;
      rtb_BCM_LatchOverheatProtect_sa = (int32_T)u0;

      /* DataTypeConversion: '<S110>/BCM_LeftRearDoorStatus_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_g[2];

      /* S-Function (sfix_bitop): '<S110>/BCM_LeftRearDoorStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 32U;

      /* ArithShift: '<S110>/BCM_LeftRearDoorStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 5);

      /* Sum: '<S110>/BCM_LeftRearDoorStatus_Ad' */
      rtb_BCM_LeftRearDoorStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S110>/BCM_LeftRearDoorStatus_sat' */
      u0 = rtb_BCM_LeftRearDoorStatus_sat;
      rtb_BCM_LeftRearDoorStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S110>/BCM_PassengerDoorLockStatus_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_g[4];

      /* S-Function (sfix_bitop): '<S110>/BCM_PassengerDoorLockStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 12U;

      /* ArithShift: '<S110>/BCM_PassengerDoorLockStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 2);

      /* Sum: '<S110>/BCM_PassengerDoorLockStatus_Ad' */
      rtb_BCM_PassengerDoorLockStatus = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S110>/BCM_PassengerDoorLockStatus_sat' */
      u0 = rtb_BCM_PassengerDoorLockStatus;
      rtb_BCM_PassengerDoorLockStatus = (int32_T)u0;

      /* DataTypeConversion: '<S110>/BCM_PassengerDoorStatus_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_g[2];

      /* S-Function (sfix_bitop): '<S110>/BCM_PassengerDoorStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 64U;

      /* ArithShift: '<S110>/BCM_PassengerDoorStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 6);

      /* Sum: '<S110>/BCM_PassengerDoorStatus_Ad' */
      rtb_BCM_PassengerDoorStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S110>/BCM_PassengerDoorStatus_sat' */
      u0 = rtb_BCM_PassengerDoorStatus_sat;
      rtb_BCM_PassengerDoorStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S110>/BCM_PowerStatusFeedback_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_g[5];

      /* S-Function (sfix_bitop): '<S110>/BCM_PowerStatusFeedback_L' */
      rtb_BCM_emergencylightstatus_L &= 12U;

      /* ArithShift: '<S110>/BCM_PowerStatusFeedback_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 2);

      /* Sum: '<S110>/BCM_PowerStatusFeedback_Ad' */
      rtb_BCM_PowerStatusFeedback_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S110>/BCM_PowerStatusFeedback_sat' */
      u0 = rtb_BCM_PowerStatusFeedback_sat;
      rtb_BCM_PowerStatusFeedback_sat = (int32_T)u0;

      /* DataTypeConversion: '<S110>/BCM_RearWiperStatus_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_g[5];

      /* S-Function (sfix_bitop): '<S110>/BCM_RearWiperStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 16U;

      /* ArithShift: '<S110>/BCM_RearWiperStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 4);

      /* Sum: '<S110>/BCM_RearWiperStatus_Ad' */
      rtb_BCM_RearWiperStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S110>/BCM_RearWiperStatus_sat' */
      u0 = rtb_BCM_RearWiperStatus_sat;
      rtb_BCM_RearWiperStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S110>/BCM_ReversePosition_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_g[6];

      /* S-Function (sfix_bitop): '<S110>/BCM_ReversePosition_L' */
      rtb_BCM_emergencylightstatus_L &= 1U;

      /* Sum: '<S110>/BCM_ReversePosition_Ad' */
      rtb_BCM_ReversePosition_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S110>/BCM_ReversePosition_sat' */
      u0 = rtb_BCM_ReversePosition_sat;
      rtb_BCM_ReversePosition_sat = (int32_T)u0;

      /* DataTypeConversion: '<S110>/BCM_RightRearDoorStatus_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_g[2];

      /* S-Function (sfix_bitop): '<S110>/BCM_RightRearDoorStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 16U;

      /* ArithShift: '<S110>/BCM_RightRearDoorStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 4);

      /* Sum: '<S110>/BCM_RightRearDoorStatus_Ad' */
      rtb_BCM_RightRearDoorStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S110>/BCM_RightRearDoorStatus_sat' */
      u0 = rtb_BCM_RightRearDoorStatus_sat;
      rtb_BCM_RightRearDoorStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S110>/BCM_SystemFailureFlag_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_g[7];

      /* S-Function (sfix_bitop): '<S110>/BCM_SystemFailureFlag_L' */
      rtb_BCM_emergencylightstatus_L &= 32U;

      /* ArithShift: '<S110>/BCM_SystemFailureFlag_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 5);

      /* Sum: '<S110>/BCM_SystemFailureFlag_Ad' */
      rtb_BCM_SystemFailureFlag_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S110>/BCM_SystemFailureFlag_sat' */
      u0 = rtb_BCM_SystemFailureFlag_sat;
      rtb_BCM_SystemFailureFlag_sat = (int32_T)u0;

      /* DataTypeConversion: '<S110>/BCM_TrunkDoorStatus_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_g[2];

      /* S-Function (sfix_bitop): '<S110>/BCM_TrunkDoorStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 8U;

      /* ArithShift: '<S110>/BCM_TrunkDoorStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 3);

      /* Sum: '<S110>/BCM_TrunkDoorStatus_Ad' */
      rtb_BCM_TrunkDoorStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S110>/BCM_TrunkDoorStatus_sat' */
      u0 = rtb_BCM_TrunkDoorStatus_sat;
      rtb_BCM_TrunkDoorStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S110>/BCM_TurnIndicatorLeft_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_g[1];

      /* S-Function (sfix_bitop): '<S110>/BCM_TurnIndicatorLeft_L' */
      rtb_BCM_emergencylightstatus_L &= 192U;

      /* ArithShift: '<S110>/BCM_TurnIndicatorLeft_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 6);

      /* Sum: '<S110>/BCM_TurnIndicatorLeft_Ad' */
      rtb_BCM_TurnIndicatorLeft_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S110>/BCM_TurnIndicatorLeft_sat' */
      u0 = rtb_BCM_TurnIndicatorLeft_sat;
      rtb_BCM_TurnIndicatorLeft_sat = (int32_T)u0;

      /* DataTypeConversion: '<S110>/BCM_TurnIndicatorRight_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_g[1];

      /* S-Function (sfix_bitop): '<S110>/BCM_TurnIndicatorRight_L' */
      rtb_BCM_emergencylightstatus_L &= 48U;

      /* ArithShift: '<S110>/BCM_TurnIndicatorRight_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 4);

      /* Sum: '<S110>/BCM_TurnIndicatorRight_Ad' */
      rtb_BCM_TurnIndicatorRight_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S110>/BCM_TurnIndicatorRight_sat' */
      u0 = rtb_BCM_TurnIndicatorRight_sat;
      rtb_BCM_TurnIndicatorRight_sat = (int32_T)u0;

      /* DataTypeConversion: '<S110>/BCM_TurnLightSwitchSts_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_g[6];

      /* S-Function (sfix_bitop): '<S110>/BCM_TurnLightSwitchSts_L' */
      rtb_BCM_emergencylightstatus_L &= 12U;

      /* ArithShift: '<S110>/BCM_TurnLightSwitchSts_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 2);

      /* Sum: '<S110>/BCM_TurnLightSwitchSts_Ad' */
      rtb_BCM_TurnLightSwitchSts_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S110>/BCM_TurnLightSwitchSts_sat' */
      u0 = rtb_BCM_TurnLightSwitchSts_sat;
      rtb_BCM_TurnLightSwitchSts_sat = (int32_T)u0;

      /* DataTypeConversion: '<S110>/BCM_emergencylightstatus_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_g[4];

      /* S-Function (sfix_bitop): '<S110>/BCM_emergencylightstatus_L' */
      rtb_BCM_emergencylightstatus_L &= 48U;

      /* ArithShift: '<S110>/BCM_emergencylightstatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 4);

      /* Saturate: '<S110>/BCM_emergencylightstatus_sat' */
      u0 = rtb_BCM_emergencylightstatus_L;
      rtb_BCM_emergencylightstatus_L = (int32_T)u0;

      /* SignalConversion: '<S109>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_FrontWashStatus =
        rtb_BCM_FrontWashStatus_sat;

      /* SignalConversion: '<S109>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_PassengerDoorLockStatus =
        rtb_BCM_PassengerDoorLockStatus;

      /* SignalConversion: '<S109>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_emergencylightstatus =
        rtb_BCM_emergencylightstatus_L;

      /* SignalConversion: '<S109>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_DriverDoorLockStatus =
        rtb_BCM_DriverDoorLockStatus_sa;

      /* SignalConversion: '<S109>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_PowerStatusFeedback =
        rtb_BCM_PowerStatusFeedback_sat;

      /* SignalConversion: '<S109>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_RearWiperStatus =
        rtb_BCM_RearWiperStatus_sat;

      /* SignalConversion: '<S109>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_FrontWiperStatus =
        rtb_BCM_FrontWiperStatus_sat;

      /* SignalConversion: '<S109>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_ReversePosition =
        rtb_BCM_ReversePosition_sat;

      /* SignalConversion: '<S109>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_TurnLightSwitchSts =
        rtb_BCM_TurnLightSwitchSts_sat;

      /* SignalConversion: '<S109>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_BuzzerWarningMode =
        rtb_BCM_BuzzerWarningMode_sat;

      /* SignalConversion: '<S109>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_SystemFailureFlag =
        rtb_BCM_SystemFailureFlag_sat;

      /* SignalConversion: '<S109>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_TurnIndicatorRight =
        rtb_BCM_TurnIndicatorRight_sat;

      /* SignalConversion: '<S109>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_LatchOverheatProtect =
        rtb_BCM_LatchOverheatProtect_sa;

      /* SignalConversion: '<S109>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_TurnIndicatorLeft =
        rtb_BCM_TurnIndicatorLeft_sat;

      /* SignalConversion: '<S109>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_HoodStatus = rtb_BCM_HoodStatus_sat;

      /* SignalConversion: '<S109>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_TrunkDoorStatus =
        rtb_BCM_TrunkDoorStatus_sat;

      /* SignalConversion: '<S109>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_RightRearDoorStatus =
        rtb_BCM_RightRearDoorStatus_sat;

      /* SignalConversion: '<S109>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_LeftRearDoorStatus =
        rtb_BCM_LeftRearDoorStatus_sat;

      /* SignalConversion: '<S109>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_PassengerDoorStatus =
        rtb_BCM_PassengerDoorStatus_sat;

      /* SignalConversion: '<S109>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_DriverDoorStatus =
        rtb_BCM_DriverDoorStatus_sat;
    }

    /* End of Outputs for SubSystem: '<S108>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S82>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF24RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf24looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_oa= 808;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_k= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_b= ec_can_receive(1,24, CAN1BUF24RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_f[0]= CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_f[1]= CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_f[2]= CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_f[3]= CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_f[4]= CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_f[5]= CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_f[6]= CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_f[7]= CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
  }

  /* Call the system: <S82>/ReceiveMessages */

  /* Output and update for function-call system: '<S82>/ReceiveMessages' */
  {
    int32_T rtb_LCM_ReverseLightSts_L;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S131>/Subsystem' incorporates:
     *  EnablePort: '<S132>/Enable'
     */
    if (VCU_CS75_12_27_test_log_B.CANReceive_o2_b > 0) {
      /* DataTypeConversion: '<S133>/LCM_LASSwitch_Convert' */
      rtb_LCM_ReverseLightSts_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_f[2];

      /* S-Function (sfix_bitop): '<S133>/LCM_LASSwitch_L' */
      rtb_LCM_ReverseLightSts_L &= 3U;

      /* Saturate: '<S133>/LCM_LASSwitch_sat' */
      u0 = rtb_LCM_ReverseLightSts_L;
      rtb_LCM_ReverseLightSts_L = (int32_T)u0;

      /* SignalConversion: '<S132>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.LCM_DriveMode = 0.0;

      /* SignalConversion: '<S132>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.LCM_DRLSts = 0.0;

      /* SignalConversion: '<S132>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.LCM_LASSwitch = rtb_LCM_ReverseLightSts_L;

      /* SignalConversion: '<S132>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.LCM_RearRightTuningLightFaultSt = 0.0;

      /* SignalConversion: '<S132>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.LCM_RearLeftTuningLightFaultSts = 0.0;

      /* SignalConversion: '<S132>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.LCM_ReverseLightSts = 0.0;
    }

    /* End of Outputs for SubSystem: '<S131>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S83>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF25RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf25looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_g= 840;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_op= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_h= ec_can_receive(1,25, CAN1BUF25RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_k[0]= CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_k[1]= CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_k[2]= CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_k[3]= CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_k[4]= CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_k[5]= CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_k[6]= CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_k[7]= CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
  }

  /* Call the system: <S83>/ReceiveMessages */

  /* Output and update for function-call system: '<S83>/ReceiveMessages' */
  {
    int32_T rtb_BCM_UnlockSignal_L;
    int32_T rtb_BCM_DriveMode_sat;
    int32_T rtb_BCM_LockSignal_sat;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S140>/Subsystem' incorporates:
     *  EnablePort: '<S141>/Enable'
     */
    if (VCU_CS75_12_27_test_log_B.CANReceive_o2_h > 0) {
      /* DataTypeConversion: '<S142>/BCM_DriveMode_Convert' */
      rtb_BCM_UnlockSignal_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_k[5];

      /* S-Function (sfix_bitop): '<S142>/BCM_DriveMode_L' */
      rtb_BCM_UnlockSignal_L &= 6U;

      /* ArithShift: '<S142>/BCM_DriveMode_S' */
      rtb_BCM_UnlockSignal_L = (int32_T)((uint32_T)rtb_BCM_UnlockSignal_L >> 1);

      /* Sum: '<S142>/BCM_DriveMode_Ad' */
      rtb_BCM_DriveMode_sat = rtb_BCM_UnlockSignal_L;

      /* Saturate: '<S142>/BCM_DriveMode_sat' */
      u0 = rtb_BCM_DriveMode_sat;
      rtb_BCM_DriveMode_sat = (int32_T)u0;

      /* DataTypeConversion: '<S142>/BCM_LockSignal_Convert' */
      rtb_BCM_UnlockSignal_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_k[5];

      /* S-Function (sfix_bitop): '<S142>/BCM_LockSignal_L' */
      rtb_BCM_UnlockSignal_L &= 24U;

      /* ArithShift: '<S142>/BCM_LockSignal_S' */
      rtb_BCM_UnlockSignal_L = (int32_T)((uint32_T)rtb_BCM_UnlockSignal_L >> 3);

      /* Sum: '<S142>/BCM_LockSignal_Ad' */
      rtb_BCM_LockSignal_sat = rtb_BCM_UnlockSignal_L;

      /* Saturate: '<S142>/BCM_LockSignal_sat' */
      u0 = rtb_BCM_LockSignal_sat;
      rtb_BCM_LockSignal_sat = (int32_T)u0;

      /* DataTypeConversion: '<S142>/BCM_UnlockSignal_Convert' */
      rtb_BCM_UnlockSignal_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_k[5];

      /* S-Function (sfix_bitop): '<S142>/BCM_UnlockSignal_L' */
      rtb_BCM_UnlockSignal_L &= 96U;

      /* ArithShift: '<S142>/BCM_UnlockSignal_S' */
      rtb_BCM_UnlockSignal_L = (int32_T)((uint32_T)rtb_BCM_UnlockSignal_L >> 5);

      /* Saturate: '<S142>/BCM_UnlockSignal_sat' */
      u0 = rtb_BCM_UnlockSignal_L;
      rtb_BCM_UnlockSignal_L = (int32_T)u0;

      /* SignalConversion: '<S141>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_DriveMode_f = rtb_BCM_DriveMode_sat;

      /* SignalConversion: '<S141>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_LockSignal = rtb_BCM_LockSignal_sat;

      /* SignalConversion: '<S141>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_UnlockSignal = rtb_BCM_UnlockSignal_L;
    }

    /* End of Outputs for SubSystem: '<S140>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S84>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF26RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf26looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_n= 991;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_p= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_m= ec_can_receive(1,26, CAN1BUF26RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_i[0]= CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_i[1]= CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_i[2]= CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_i[3]= CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_i[4]= CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_i[5]= CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_i[6]= CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_i[7]= CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
  }

  /* Call the system: <S84>/ReceiveMessages */

  /* Output and update for function-call system: '<S84>/ReceiveMessages' */
  {
    int32_T rtb_BCM_RollingCounter_L;
    int32_T rtb_BCM_AmbientLightColorFeedba;
    int32_T rtb_BCM_DriveModeFeedback_sat;
    int32_T rtb_BCM_DriveModeStatus_sat;
    int32_T rtb_BCM_EPSTorqueModeFeedback_s;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S146>/Subsystem' incorporates:
     *  EnablePort: '<S147>/Enable'
     */
    if (VCU_CS75_12_27_test_log_B.CANReceive_o2_m > 0) {
      /* DataTypeConversion: '<S148>/BCM_AmbientLightColorFeedback_Convert' */
      rtb_BCM_RollingCounter_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_i[3];

      /* Sum: '<S148>/BCM_AmbientLightColorFeedback_Ad' */
      rtb_BCM_AmbientLightColorFeedba = rtb_BCM_RollingCounter_L;

      /* Saturate: '<S148>/BCM_AmbientLightColorFeedback_sat' */
      u0 = rtb_BCM_AmbientLightColorFeedba;
      rtb_BCM_AmbientLightColorFeedba = (int32_T)u0;

      /* DataTypeConversion: '<S148>/BCM_DriveModeFeedback_Convert' */
      rtb_BCM_RollingCounter_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_i[2];

      /* S-Function (sfix_bitop): '<S148>/BCM_DriveModeFeedback_L' */
      rtb_BCM_RollingCounter_L &= 48U;

      /* ArithShift: '<S148>/BCM_DriveModeFeedback_S' */
      rtb_BCM_RollingCounter_L = (int32_T)((uint32_T)rtb_BCM_RollingCounter_L >>
        4);

      /* Sum: '<S148>/BCM_DriveModeFeedback_Ad' */
      rtb_BCM_DriveModeFeedback_sat = rtb_BCM_RollingCounter_L;

      /* Saturate: '<S148>/BCM_DriveModeFeedback_sat' */
      u0 = rtb_BCM_DriveModeFeedback_sat;
      rtb_BCM_DriveModeFeedback_sat = (int32_T)u0;

      /* DataTypeConversion: '<S148>/BCM_DriveModeStatus_Convert' */
      rtb_BCM_RollingCounter_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_i[2];

      /* S-Function (sfix_bitop): '<S148>/BCM_DriveModeStatus_L' */
      rtb_BCM_RollingCounter_L &= 15U;

      /* Sum: '<S148>/BCM_DriveModeStatus_Ad' */
      rtb_BCM_DriveModeStatus_sat = rtb_BCM_RollingCounter_L;

      /* Saturate: '<S148>/BCM_DriveModeStatus_sat' */
      u0 = rtb_BCM_DriveModeStatus_sat;
      rtb_BCM_DriveModeStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S148>/BCM_EPSTorqueModeFeedback_Convert' */
      rtb_BCM_RollingCounter_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_i[2];

      /* S-Function (sfix_bitop): '<S148>/BCM_EPSTorqueModeFeedback_L' */
      rtb_BCM_RollingCounter_L &= 192U;

      /* ArithShift: '<S148>/BCM_EPSTorqueModeFeedback_S' */
      rtb_BCM_RollingCounter_L = (int32_T)((uint32_T)rtb_BCM_RollingCounter_L >>
        6);

      /* Sum: '<S148>/BCM_EPSTorqueModeFeedback_Ad' */
      rtb_BCM_EPSTorqueModeFeedback_s = rtb_BCM_RollingCounter_L;

      /* Saturate: '<S148>/BCM_EPSTorqueModeFeedback_sat' */
      u0 = rtb_BCM_EPSTorqueModeFeedback_s;
      rtb_BCM_EPSTorqueModeFeedback_s = (int32_T)u0;

      /* DataTypeConversion: '<S148>/BCM_EPSTorqueMode_Convert' */
      rtb_BCM_RollingCounter_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_i[1];

      /* S-Function (sfix_bitop): '<S148>/BCM_EPSTorqueMode_L' */
      rtb_BCM_RollingCounter_L &= 6U;

      /* ArithShift: '<S148>/BCM_EPSTorqueMode_S' */
      rtb_BCM_RollingCounter_L = (int32_T)((uint32_T)rtb_BCM_RollingCounter_L >>
        1);

      /* Saturate: '<S148>/BCM_EPSTorqueMode_sat' */
      u0 = rtb_BCM_RollingCounter_L;
      rtb_BCM_RollingCounter_L = (int32_T)u0;

      /* SignalConversion: '<S147>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_DriveMode = 0.0;

      /* SignalConversion: '<S147>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_EPSTorqueMode = rtb_BCM_RollingCounter_L;

      /* SignalConversion: '<S147>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_DriveModeStatus =
        rtb_BCM_DriveModeStatus_sat;

      /* SignalConversion: '<S147>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_DriveModeFeedback =
        rtb_BCM_DriveModeFeedback_sat;

      /* SignalConversion: '<S147>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_EPSTorqueModeFeedback =
        rtb_BCM_EPSTorqueModeFeedback_s;

      /* SignalConversion: '<S147>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_AmbientLightColorFeedback =
        rtb_BCM_AmbientLightColorFeedba;

      /* SignalConversion: '<S147>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_RollingCounter = 0.0;

      /* SignalConversion: '<S147>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.BCM_CRC_Checksum = 0.0;
    }

    /* End of Outputs for SubSystem: '<S146>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S85>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF0RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf0looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_e= 517;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_h= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_g= ec_can_receive(1,0, CAN1BUF0RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_n[0]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_n[1]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_n[2]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_n[3]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_n[4]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_n[5]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_n[6]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_n[7]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
  }

  /* Call the system: <S85>/ReceiveMessages */

  /* Output and update for function-call system: '<S85>/ReceiveMessages' */
  {
    int32_T rtb_EMS_TorqFailure_L;
    int32_T rtb_EMS_ESPTorqReuestAvailabili;
    int32_T rtb_EMS_CheckSum_205_sat;
    real_T rtb_EMS_FrictionalTorq_sat;
    real_T rtb_EMS_IndicatedDriverReqTorq_;
    real_T rtb_EMS_IndicatedRealEngTorq_sa;
    real_T rtb_EMS_TorqFailurecv;
    int32_T rtb_EMS_RollingCounter_id205_sa;

    /* Outputs for Enabled SubSystem: '<S157>/Subsystem' incorporates:
     *  EnablePort: '<S158>/Enable'
     */
    if (VCU_CS75_12_27_test_log_B.CANReceive_o2_g > 0) {
      /* DataTypeConversion: '<S159>/EMS_CheckSum_205_Convert' */
      rtb_EMS_TorqFailure_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_n[7];

      /* S-Function (sfix_bitop): '<S159>/EMS_CheckSum_205_L' */
      rtb_EMS_TorqFailure_L &= 240U;

      /* ArithShift: '<S159>/EMS_CheckSum_205_S' */
      rtb_EMS_TorqFailure_L = (int32_T)((uint32_T)rtb_EMS_TorqFailure_L >> 4);

      /* DataTypeConversion: '<S159>/EMS_CheckSum_205cv' */
      rtb_EMS_ESPTorqReuestAvailabili = rtb_EMS_TorqFailure_L;

      /* Sum: '<S159>/EMS_CheckSum_205_Ad' */
      rtb_EMS_CheckSum_205_sat = rtb_EMS_ESPTorqReuestAvailabili;

      /* Saturate: '<S159>/EMS_CheckSum_205_sat' */
      rtb_EMS_TorqFailurecv = rtb_EMS_CheckSum_205_sat;
      rtb_EMS_CheckSum_205_sat = (int32_T)rtb_EMS_TorqFailurecv;

      /* DataTypeConversion: '<S159>/EMS_ESPTorqReuestAvailability_Convert' */
      rtb_EMS_TorqFailure_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_n[0];

      /* S-Function (sfix_bitop): '<S159>/EMS_ESPTorqReuestAvailability_L' */
      rtb_EMS_TorqFailure_L &= 2U;

      /* ArithShift: '<S159>/EMS_ESPTorqReuestAvailability_S' */
      rtb_EMS_TorqFailure_L = (int32_T)((uint32_T)rtb_EMS_TorqFailure_L >> 1);

      /* Saturate: '<S159>/EMS_ESPTorqReuestAvailability_sat' */
      rtb_EMS_TorqFailurecv = rtb_EMS_TorqFailure_L;
      rtb_EMS_ESPTorqReuestAvailabili = (int32_T)rtb_EMS_TorqFailurecv;

      /* Product: '<S159>/EMS_FrictionalTorqinput4_P' incorporates:
       *  Constant: '<S159>/EMS_FrictionalTorqinput4_C'
       */
      rtb_EMS_FrictionalTorq_sat = (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_n[3] * 256.0;

      /* Sum: '<S159>/EMS_FrictionalTorqinput4_Ad' */
      rtb_EMS_IndicatedDriverReqTorq_ = rtb_EMS_FrictionalTorq_sat + (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_n[4];

      /* DataTypeConversion: '<S159>/EMS_FrictionalTorq_Convert' */
      rtb_EMS_TorqFailure_L = (int32_T)rtb_EMS_IndicatedDriverReqTorq_;

      /* DataTypeConversion: '<S159>/EMS_FrictionalTorqcv' */
      rtb_EMS_IndicatedDriverReqTorq_ = rtb_EMS_TorqFailure_L;

      /* Gain: '<S159>/EMS_FrictionalTorq_F' */
      rtb_EMS_IndicatedDriverReqTorq_ *= 0.001526;

      /* Sum: '<S159>/EMS_FrictionalTorq_Ad' */
      rtb_EMS_FrictionalTorq_sat = rtb_EMS_IndicatedDriverReqTorq_;

      /* Saturate: '<S159>/EMS_FrictionalTorq_sat' */
      if (rtb_EMS_FrictionalTorq_sat > 99.9988) {
        rtb_EMS_FrictionalTorq_sat = 99.9988;
      }

      /* End of Saturate: '<S159>/EMS_FrictionalTorq_sat' */

      /* Product: '<S159>/EMS_IndicatedDriverReqTorqinput2_P' incorporates:
       *  Constant: '<S159>/EMS_IndicatedDriverReqTorqinput2_C'
       */
      rtb_EMS_IndicatedDriverReqTorq_ = (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_n[1] * 256.0;

      /* Sum: '<S159>/EMS_IndicatedDriverReqTorqinput2_Ad' */
      rtb_EMS_IndicatedRealEngTorq_sa = rtb_EMS_IndicatedDriverReqTorq_ +
        (real_T)VCU_CS75_12_27_test_log_B.CANReceive_o4_n[2];

      /* DataTypeConversion: '<S159>/EMS_IndicatedDriverReqTorq_Convert' */
      rtb_EMS_TorqFailure_L = (int32_T)rtb_EMS_IndicatedRealEngTorq_sa;

      /* DataTypeConversion: '<S159>/EMS_IndicatedDriverReqTorqcv' */
      rtb_EMS_IndicatedRealEngTorq_sa = rtb_EMS_TorqFailure_L;

      /* Gain: '<S159>/EMS_IndicatedDriverReqTorq_F' */
      rtb_EMS_IndicatedRealEngTorq_sa *= 0.001526;

      /* Sum: '<S159>/EMS_IndicatedDriverReqTorq_Ad' */
      rtb_EMS_IndicatedDriverReqTorq_ = rtb_EMS_IndicatedRealEngTorq_sa;

      /* Saturate: '<S159>/EMS_IndicatedDriverReqTorq_sat' */
      if (rtb_EMS_IndicatedDriverReqTorq_ > 99.9988) {
        rtb_EMS_IndicatedDriverReqTorq_ = 99.9988;
      }

      /* End of Saturate: '<S159>/EMS_IndicatedDriverReqTorq_sat' */

      /* Product: '<S159>/EMS_IndicatedRealEngTorqinput6_P' incorporates:
       *  Constant: '<S159>/EMS_IndicatedRealEngTorqinput6_C'
       */
      rtb_EMS_IndicatedRealEngTorq_sa = (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_n[5] * 256.0;

      /* Sum: '<S159>/EMS_IndicatedRealEngTorqinput6_Ad' */
      rtb_EMS_TorqFailurecv = rtb_EMS_IndicatedRealEngTorq_sa + (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_n[6];

      /* DataTypeConversion: '<S159>/EMS_IndicatedRealEngTorq_Convert' */
      rtb_EMS_TorqFailure_L = (int32_T)rtb_EMS_TorqFailurecv;

      /* DataTypeConversion: '<S159>/EMS_IndicatedRealEngTorqcv' */
      rtb_EMS_TorqFailurecv = rtb_EMS_TorqFailure_L;

      /* Gain: '<S159>/EMS_IndicatedRealEngTorq_F' */
      rtb_EMS_TorqFailurecv *= 0.001526;

      /* Sum: '<S159>/EMS_IndicatedRealEngTorq_Ad' */
      rtb_EMS_IndicatedRealEngTorq_sa = rtb_EMS_TorqFailurecv;

      /* Saturate: '<S159>/EMS_IndicatedRealEngTorq_sat' */
      if (rtb_EMS_IndicatedRealEngTorq_sa > 99.9988) {
        rtb_EMS_IndicatedRealEngTorq_sa = 99.9988;
      }

      /* End of Saturate: '<S159>/EMS_IndicatedRealEngTorq_sat' */

      /* DataTypeConversion: '<S159>/EMS_RollingCounter_id205_Convert' */
      rtb_EMS_TorqFailure_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_n[7];

      /* S-Function (sfix_bitop): '<S159>/EMS_RollingCounter_id205_L' */
      rtb_EMS_TorqFailure_L &= 15U;

      /* DataTypeConversion: '<S159>/EMS_RollingCounter_id205cv' */
      rtb_EMS_TorqFailurecv = rtb_EMS_TorqFailure_L;

      /* Sum: '<S159>/EMS_RollingCounter_id205_Ad' */
      rtb_EMS_RollingCounter_id205_sa = (int32_T)rtb_EMS_TorqFailurecv;

      /* Saturate: '<S159>/EMS_RollingCounter_id205_sat' */
      rtb_EMS_TorqFailurecv = rtb_EMS_RollingCounter_id205_sa;
      rtb_EMS_RollingCounter_id205_sa = (int32_T)rtb_EMS_TorqFailurecv;

      /* DataTypeConversion: '<S159>/EMS_TorqFailure_Convert' */
      rtb_EMS_TorqFailure_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_n[0];

      /* S-Function (sfix_bitop): '<S159>/EMS_TorqFailure_L' */
      rtb_EMS_TorqFailure_L &= 128U;

      /* ArithShift: '<S159>/EMS_TorqFailure_S' */
      rtb_EMS_TorqFailure_L = (int32_T)((uint32_T)rtb_EMS_TorqFailure_L >> 7);

      /* DataTypeConversion: '<S159>/EMS_TorqFailurecv' */
      rtb_EMS_TorqFailurecv = rtb_EMS_TorqFailure_L;

      /* SignalConversion: '<S158>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_ESPTorqReuestAvailability =
        rtb_EMS_ESPTorqReuestAvailabili;

      /* SignalConversion: '<S158>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_TorqFailure = rtb_EMS_TorqFailurecv;

      /* SignalConversion: '<S158>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_IndicatedDriverReqTorq =
        rtb_EMS_IndicatedDriverReqTorq_;

      /* SignalConversion: '<S158>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_FrictionalTorq_d =
        rtb_EMS_FrictionalTorq_sat;

      /* SignalConversion: '<S158>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_IndicatedRealEngTorq =
        rtb_EMS_IndicatedRealEngTorq_sa;

      /* SignalConversion: '<S158>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_RollingCounter_id205 =
        rtb_EMS_RollingCounter_id205_sa;

      /* SignalConversion: '<S158>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_CheckSum_205 = rtb_EMS_CheckSum_205_sat;
    }

    /* End of Outputs for SubSystem: '<S157>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S86>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF1RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf1looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_oo= 597;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_g= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_j= ec_can_receive(1,1, CAN1BUF1RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_j[0]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_j[1]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_j[2]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_j[3]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_j[4]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_j[5]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_j[6]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_j[7]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
  }

  /* Call the system: <S86>/ReceiveMessages */

  /* Output and update for function-call system: '<S86>/ReceiveMessages' */
  {
    int32_T rtb_EMS_RollingCounter_id255_L;
    real_T rtb_EMS_CheckSum_255_sat;
    real_T rtb_EMS_AccPedal_sat;
    int32_T rtb_EMS_AccpedelError_sat;
    real_T rtb_EMS_EngineSpeed_sat;
    int32_T rtb_EMS_EngineSpeedError_sat;
    real_T rtb_EMS_RollingCounter_id255cv;

    /* Outputs for Enabled SubSystem: '<S167>/Subsystem' incorporates:
     *  EnablePort: '<S168>/Enable'
     */
    if (VCU_CS75_12_27_test_log_B.CANReceive_o2_j > 0) {
      /* DataTypeConversion: '<S169>/EMS_AccPedal_Convert' */
      rtb_EMS_RollingCounter_id255_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_j[5];

      /* DataTypeConversion: '<S169>/EMS_AccPedalcv' */
      rtb_EMS_CheckSum_255_sat = rtb_EMS_RollingCounter_id255_L;

      /* Gain: '<S169>/EMS_AccPedal_F' */
      rtb_EMS_CheckSum_255_sat *= 0.392;

      /* Sum: '<S169>/EMS_AccPedal_Ad' */
      rtb_EMS_AccPedal_sat = rtb_EMS_CheckSum_255_sat;

      /* Saturate: '<S169>/EMS_AccPedal_sat' */
      if (rtb_EMS_AccPedal_sat > 99.568) {
        rtb_EMS_AccPedal_sat = 99.568;
      }

      /* End of Saturate: '<S169>/EMS_AccPedal_sat' */

      /* DataTypeConversion: '<S169>/EMS_AccpedelError_Convert' */
      rtb_EMS_RollingCounter_id255_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_j[1];

      /* S-Function (sfix_bitop): '<S169>/EMS_AccpedelError_L' */
      rtb_EMS_RollingCounter_id255_L &= 4U;

      /* ArithShift: '<S169>/EMS_AccpedelError_S' */
      rtb_EMS_RollingCounter_id255_L = (int32_T)((uint32_T)
        rtb_EMS_RollingCounter_id255_L >> 2);

      /* DataTypeConversion: '<S169>/EMS_AccpedelErrorcv' */
      rtb_EMS_CheckSum_255_sat = rtb_EMS_RollingCounter_id255_L;

      /* Sum: '<S169>/EMS_AccpedelError_Ad' */
      rtb_EMS_AccpedelError_sat = (int32_T)rtb_EMS_CheckSum_255_sat;

      /* Saturate: '<S169>/EMS_AccpedelError_sat' */
      rtb_EMS_EngineSpeed_sat = rtb_EMS_AccpedelError_sat;
      rtb_EMS_AccpedelError_sat = (int32_T)rtb_EMS_EngineSpeed_sat;

      /* DataTypeConversion: '<S169>/EMS_BrakePedalStatus_Convert' */
      rtb_EMS_RollingCounter_id255_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_j[0];

      /* S-Function (sfix_bitop): '<S169>/EMS_BrakePedalStatus_L' */
      rtb_EMS_RollingCounter_id255_L &= 192U;

      /* ArithShift: '<S169>/EMS_BrakePedalStatus_S' */
      rtb_EMS_RollingCounter_id255_L = (int32_T)((uint32_T)
        rtb_EMS_RollingCounter_id255_L >> 6);

      /* DataTypeConversion: '<S169>/EMS_BrakePedalStatuscv' */
      rtb_EMS_CheckSum_255_sat = rtb_EMS_RollingCounter_id255_L;

      /* Sum: '<S169>/EMS_BrakePedalStatus_Ad' */
      rtb_EMS_EngineSpeed_sat = rtb_EMS_CheckSum_255_sat;

      /* Saturate: '<S169>/EMS_BrakePedalStatus_sat' */
      EMS_BrakePedalStatus = rtb_EMS_EngineSpeed_sat;

      /* DataTypeConversion: '<S169>/EMS_CheckSum_255_Convert' */
      rtb_EMS_RollingCounter_id255_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_j[7];

      /* S-Function (sfix_bitop): '<S169>/EMS_CheckSum_255_L' */
      rtb_EMS_RollingCounter_id255_L &= 240U;

      /* ArithShift: '<S169>/EMS_CheckSum_255_S' */
      rtb_EMS_RollingCounter_id255_L = (int32_T)((uint32_T)
        rtb_EMS_RollingCounter_id255_L >> 4);

      /* DataTypeConversion: '<S169>/EMS_CheckSum_255cv' */
      rtb_EMS_EngineSpeed_sat = rtb_EMS_RollingCounter_id255_L;

      /* Sum: '<S169>/EMS_CheckSum_255_Ad' */
      rtb_EMS_CheckSum_255_sat = rtb_EMS_EngineSpeed_sat;

      /* DataTypeConversion: '<S169>/EMS_EngineSpeedError_Convert' */
      rtb_EMS_RollingCounter_id255_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_j[1];

      /* S-Function (sfix_bitop): '<S169>/EMS_EngineSpeedError_L' */
      rtb_EMS_RollingCounter_id255_L &= 16U;

      /* ArithShift: '<S169>/EMS_EngineSpeedError_S' */
      rtb_EMS_RollingCounter_id255_L = (int32_T)((uint32_T)
        rtb_EMS_RollingCounter_id255_L >> 4);

      /* DataTypeConversion: '<S169>/EMS_EngineSpeedErrorcv' */
      rtb_EMS_EngineSpeed_sat = rtb_EMS_RollingCounter_id255_L;

      /* Sum: '<S169>/EMS_EngineSpeedError_Ad' */
      rtb_EMS_EngineSpeedError_sat = (int32_T)rtb_EMS_EngineSpeed_sat;

      /* Saturate: '<S169>/EMS_EngineSpeedError_sat' */
      rtb_EMS_EngineSpeed_sat = rtb_EMS_EngineSpeedError_sat;
      rtb_EMS_EngineSpeedError_sat = (int32_T)rtb_EMS_EngineSpeed_sat;

      /* Product: '<S169>/EMS_EngineSpeedinput3_P' incorporates:
       *  Constant: '<S169>/EMS_EngineSpeedinput3_C'
       */
      rtb_EMS_EngineSpeed_sat = (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_j[2] * 256.0;

      /* Sum: '<S169>/EMS_EngineSpeedinput3_Ad' */
      rtb_EMS_RollingCounter_id255cv = rtb_EMS_EngineSpeed_sat + (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_j[3];

      /* DataTypeConversion: '<S169>/EMS_EngineSpeed_Convert' */
      rtb_EMS_RollingCounter_id255_L = (int32_T)rtb_EMS_RollingCounter_id255cv;

      /* DataTypeConversion: '<S169>/EMS_EngineSpeedcv' */
      rtb_EMS_RollingCounter_id255cv = rtb_EMS_RollingCounter_id255_L;

      /* Gain: '<S169>/EMS_EngineSpeed_F' */
      rtb_EMS_RollingCounter_id255cv *= 0.25;

      /* Sum: '<S169>/EMS_EngineSpeed_Ad' */
      rtb_EMS_EngineSpeed_sat = rtb_EMS_RollingCounter_id255cv;

      /* Saturate: '<S169>/EMS_EngineSpeed_sat' */
      if (rtb_EMS_EngineSpeed_sat > 16383.5) {
        rtb_EMS_EngineSpeed_sat = 16383.5;
      }

      /* End of Saturate: '<S169>/EMS_EngineSpeed_sat' */

      /* DataTypeConversion: '<S169>/EMS_RollingCounter_id255_Convert' */
      rtb_EMS_RollingCounter_id255_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_j[7];

      /* S-Function (sfix_bitop): '<S169>/EMS_RollingCounter_id255_L' */
      rtb_EMS_RollingCounter_id255_L &= 15U;

      /* DataTypeConversion: '<S169>/EMS_RollingCounter_id255cv' */
      rtb_EMS_RollingCounter_id255cv = rtb_EMS_RollingCounter_id255_L;

      /* SignalConversion: '<S168>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_BrakePedalStatus_l = EMS_BrakePedalStatus;

      /* SignalConversion: '<S168>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_AccpedelError = rtb_EMS_AccpedelError_sat;

      /* SignalConversion: '<S168>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_EngineSpeedError =
        rtb_EMS_EngineSpeedError_sat;

      /* SignalConversion: '<S168>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_EngineSpeed_a = rtb_EMS_EngineSpeed_sat;

      /* SignalConversion: '<S168>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_AccPedal = rtb_EMS_AccPedal_sat;

      /* SignalConversion: '<S168>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_RollingCounter_id255 =
        rtb_EMS_RollingCounter_id255cv;

      /* SignalConversion: '<S168>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_CheckSum_255 = rtb_EMS_CheckSum_255_sat;
    }

    /* End of Outputs for SubSystem: '<S167>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S87>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF2RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf2looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_a= 613;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_l= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_n= ec_can_receive(1,2, CAN1BUF2RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_a[0]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_a[1]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_a[2]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_a[3]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_a[4]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_a[5]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_a[6]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_a[7]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
  }

  /* Call the system: <S87>/ReceiveMessages */

  /* Output and update for function-call system: '<S87>/ReceiveMessages' */
  {
    int32_T rtb_EMS_TorqueConstant_L;
    real_T rtb_EMS_TorqueConstant_F;
    int32_T rtb_EMS_EngineStatus_sat;
    real_T rtb_EMS_FullLoadIndicatedTorq_s;
    int32_T rtb_EMS_RollingCounter_id265_sa;

    /* Outputs for Enabled SubSystem: '<S177>/Subsystem' incorporates:
     *  EnablePort: '<S178>/Enable'
     */
    if (VCU_CS75_12_27_test_log_B.CANReceive_o2_n > 0) {
      /* DataTypeConversion: '<S179>/EMS_EngineStatus_Convert' */
      rtb_EMS_TorqueConstant_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_a[7];

      /* S-Function (sfix_bitop): '<S179>/EMS_EngineStatus_L' */
      rtb_EMS_TorqueConstant_L &= 192U;

      /* ArithShift: '<S179>/EMS_EngineStatus_S' */
      rtb_EMS_TorqueConstant_L = (int32_T)((uint32_T)rtb_EMS_TorqueConstant_L >>
        6);

      /* DataTypeConversion: '<S179>/EMS_EngineStatuscv' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_TorqueConstant_L;

      /* Sum: '<S179>/EMS_EngineStatus_Ad' */
      rtb_EMS_EngineStatus_sat = (int32_T)rtb_EMS_TorqueConstant_F;

      /* Saturate: '<S179>/EMS_EngineStatus_sat' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_EngineStatus_sat;
      rtb_EMS_EngineStatus_sat = (int32_T)rtb_EMS_TorqueConstant_F;

      /* DataTypeConversion: '<S179>/EMS_FullLoadIndicatedTorq_Convert' */
      rtb_EMS_TorqueConstant_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_a[2];

      /* DataTypeConversion: '<S179>/EMS_FullLoadIndicatedTorqcv' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_TorqueConstant_L;

      /* Gain: '<S179>/EMS_FullLoadIndicatedTorq_F' */
      rtb_EMS_TorqueConstant_F *= 0.392;

      /* Sum: '<S179>/EMS_FullLoadIndicatedTorq_Ad' */
      rtb_EMS_FullLoadIndicatedTorq_s = rtb_EMS_TorqueConstant_F;

      /* Saturate: '<S179>/EMS_FullLoadIndicatedTorq_sat' */
      if (rtb_EMS_FullLoadIndicatedTorq_s > 99.96) {
        rtb_EMS_FullLoadIndicatedTorq_s = 99.96;
      }

      /* End of Saturate: '<S179>/EMS_FullLoadIndicatedTorq_sat' */

      /* DataTypeConversion: '<S179>/EMS_RollingCounter_id265_Convert' */
      rtb_EMS_TorqueConstant_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_a[7];

      /* S-Function (sfix_bitop): '<S179>/EMS_RollingCounter_id265_L' */
      rtb_EMS_TorqueConstant_L &= 15U;

      /* DataTypeConversion: '<S179>/EMS_RollingCounter_id265cv' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_TorqueConstant_L;

      /* Sum: '<S179>/EMS_RollingCounter_id265_Ad' */
      rtb_EMS_RollingCounter_id265_sa = (int32_T)rtb_EMS_TorqueConstant_F;

      /* Saturate: '<S179>/EMS_RollingCounter_id265_sat' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_RollingCounter_id265_sa;
      rtb_EMS_RollingCounter_id265_sa = (int32_T)rtb_EMS_TorqueConstant_F;

      /* DataTypeConversion: '<S179>/EMS_TorqueConstant_Convert' */
      rtb_EMS_TorqueConstant_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_a[6];

      /* DataTypeConversion: '<S179>/EMS_TorqueConstantcv' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_TorqueConstant_L;

      /* Gain: '<S179>/EMS_TorqueConstant_F' */
      rtb_EMS_TorqueConstant_F *= 10.0;

      /* Saturate: '<S179>/EMS_TorqueConstant_sat' */
      if (rtb_EMS_TorqueConstant_F > 2540.0) {
        rtb_EMS_TorqueConstant_F = 2540.0;
      }

      /* End of Saturate: '<S179>/EMS_TorqueConstant_sat' */

      /* SignalConversion: '<S178>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_FullLoadIndicatedTorq =
        rtb_EMS_FullLoadIndicatedTorq_s;

      /* SignalConversion: '<S178>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_TorqueConstant_c = rtb_EMS_TorqueConstant_F;

      /* SignalConversion: '<S178>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_RollingCounter_id265 =
        rtb_EMS_RollingCounter_id265_sa;

      /* SignalConversion: '<S178>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_EngineStatus_f = rtb_EMS_EngineStatus_sat;
    }

    /* End of Outputs for SubSystem: '<S177>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S88>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF3RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf3looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_h= 630;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_b= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_p= ec_can_receive(1,3, CAN1BUF3RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ix[0]= CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ix[1]= CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ix[2]= CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ix[3]= CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ix[4]= CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ix[5]= CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ix[6]= CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ix[7]= CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
  }

  /* Call the system: <S88>/ReceiveMessages */

  /* Output and update for function-call system: '<S88>/ReceiveMessages' */
  {
    int32_T rtb_EMS_RealAccPedal_Convert;
    real_T rtb_EMS_RealAccPedal_F;

    /* Outputs for Enabled SubSystem: '<S184>/Subsystem' incorporates:
     *  EnablePort: '<S185>/Enable'
     */
    if (VCU_CS75_12_27_test_log_B.CANReceive_o2_p > 0) {
      /* DataTypeConversion: '<S186>/EMS_RealAccPedal_Convert' */
      rtb_EMS_RealAccPedal_Convert = VCU_CS75_12_27_test_log_B.CANReceive_o4_ix
        [2];

      /* DataTypeConversion: '<S186>/EMS_RealAccPedalcv' */
      rtb_EMS_RealAccPedal_F = rtb_EMS_RealAccPedal_Convert;

      /* Gain: '<S186>/EMS_RealAccPedal_F' */
      rtb_EMS_RealAccPedal_F *= 0.392;

      /* Saturate: '<S186>/EMS_RealAccPedal_sat' */
      if (rtb_EMS_RealAccPedal_F > 99.96) {
        rtb_EMS_RealAccPedal_F = 99.96;
      }

      /* End of Saturate: '<S186>/EMS_RealAccPedal_sat' */

      /* SignalConversion: '<S185>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_RealAccPedal = rtb_EMS_RealAccPedal_F;
    }

    /* End of Outputs for SubSystem: '<S184>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S89>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF4RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf4looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_ow= 598;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_d= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_c= ec_can_receive(1,4, CAN1BUF4RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_e[0]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_e[1]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_e[2]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_e[3]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_e[4]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_e[5]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_e[6]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_e[7]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
  }

  /* Call the system: <S89>/ReceiveMessages */

  /* Output and update for function-call system: '<S89>/ReceiveMessages' */
  {
    int32_T rtb_EPB_Status_L;
    int32_T rtb_EPB_Checksum_sat;
    int32_T rtb_EPB_FailStatus_sat;
    int32_T rtb_EPB_FailureLamp_sat;
    int32_T rtb_EPB_FunctionLamp_sat;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S188>/Subsystem' incorporates:
     *  EnablePort: '<S189>/Enable'
     */
    if (VCU_CS75_12_27_test_log_B.CANReceive_o2_c > 0) {
      /* DataTypeConversion: '<S190>/EPB_Checksum_Convert' */
      rtb_EPB_Status_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_e[7];

      /* Sum: '<S190>/EPB_Checksum_Ad' */
      rtb_EPB_Checksum_sat = rtb_EPB_Status_L;

      /* Saturate: '<S190>/EPB_Checksum_sat' */
      u0 = rtb_EPB_Checksum_sat;
      rtb_EPB_Checksum_sat = (int32_T)u0;

      /* DataTypeConversion: '<S190>/EPB_FailStatus_Convert' */
      rtb_EPB_Status_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_e[0];

      /* S-Function (sfix_bitop): '<S190>/EPB_FailStatus_L' */
      rtb_EPB_Status_L &= 192U;

      /* ArithShift: '<S190>/EPB_FailStatus_S' */
      rtb_EPB_Status_L = (int32_T)((uint32_T)rtb_EPB_Status_L >> 6);

      /* Sum: '<S190>/EPB_FailStatus_Ad' */
      rtb_EPB_FailStatus_sat = rtb_EPB_Status_L;

      /* Saturate: '<S190>/EPB_FailStatus_sat' */
      u0 = rtb_EPB_FailStatus_sat;
      rtb_EPB_FailStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S190>/EPB_FailureLamp_Convert' */
      rtb_EPB_Status_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_e[5];

      /* S-Function (sfix_bitop): '<S190>/EPB_FailureLamp_L' */
      rtb_EPB_Status_L &= 48U;

      /* ArithShift: '<S190>/EPB_FailureLamp_S' */
      rtb_EPB_Status_L = (int32_T)((uint32_T)rtb_EPB_Status_L >> 4);

      /* Sum: '<S190>/EPB_FailureLamp_Ad' */
      rtb_EPB_FailureLamp_sat = rtb_EPB_Status_L;

      /* Saturate: '<S190>/EPB_FailureLamp_sat' */
      u0 = rtb_EPB_FailureLamp_sat;
      rtb_EPB_FailureLamp_sat = (int32_T)u0;

      /* DataTypeConversion: '<S190>/EPB_FunctionLamp_Convert' */
      rtb_EPB_Status_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_e[5];

      /* S-Function (sfix_bitop): '<S190>/EPB_FunctionLamp_L' */
      rtb_EPB_Status_L &= 12U;

      /* ArithShift: '<S190>/EPB_FunctionLamp_S' */
      rtb_EPB_Status_L = (int32_T)((uint32_T)rtb_EPB_Status_L >> 2);

      /* Sum: '<S190>/EPB_FunctionLamp_Ad' */
      rtb_EPB_FunctionLamp_sat = rtb_EPB_Status_L;

      /* Saturate: '<S190>/EPB_FunctionLamp_sat' */
      u0 = rtb_EPB_FunctionLamp_sat;
      rtb_EPB_FunctionLamp_sat = (int32_T)u0;

      /* DataTypeConversion: '<S190>/EPB_RollingCounter_id256_Convert' */
      rtb_EPB_Status_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_e[6];

      /* S-Function (sfix_bitop): '<S190>/EPB_RollingCounter_id256_L' */
      rtb_EPB_Status_L &= 15U;

      /* Saturate: '<S190>/EPB_RollingCounter_id256_sat' */
      u0 = rtb_EPB_Status_L;
      EPB_RollingCounter_id256 = u0;

      /* DataTypeConversion: '<S190>/EPB_Status_Convert' */
      rtb_EPB_Status_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_e[2];

      /* S-Function (sfix_bitop): '<S190>/EPB_Status_L' */
      rtb_EPB_Status_L &= 192U;

      /* ArithShift: '<S190>/EPB_Status_S' */
      rtb_EPB_Status_L = (int32_T)((uint32_T)rtb_EPB_Status_L >> 6);

      /* Saturate: '<S190>/EPB_Status_sat' */
      u0 = rtb_EPB_Status_L;
      rtb_EPB_Status_L = (int32_T)u0;

      /* SignalConversion: '<S189>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPB_FailStatus = rtb_EPB_FailStatus_sat;

      /* SignalConversion: '<S189>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPB_Status_p = rtb_EPB_Status_L;

      /* SignalConversion: '<S189>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPB_FunctionLamp_f = rtb_EPB_FunctionLamp_sat;

      /* SignalConversion: '<S189>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPB_FailureLamp = rtb_EPB_FailureLamp_sat;

      /* SignalConversion: '<S189>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPB_RollingCounter_id256_d =
        EPB_RollingCounter_id256;

      /* SignalConversion: '<S189>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPB_Checksum = rtb_EPB_Checksum_sat;
    }

    /* End of Outputs for SubSystem: '<S188>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S90>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF5RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf5looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_n1= 522;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_ir= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_mh= ec_can_receive(1,5, CAN1BUF5RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_jz[0]= CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_jz[1]= CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_jz[2]= CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_jz[3]= CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_jz[4]= CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_jz[5]= CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_jz[6]= CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_jz[7]= CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
  }

  /* Call the system: <S90>/ReceiveMessages */

  /* Output and update for function-call system: '<S90>/ReceiveMessages' */
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

    /* Outputs for Enabled SubSystem: '<S197>/Subsystem' incorporates:
     *  EnablePort: '<S198>/Enable'
     */
    if (VCU_CS75_12_27_test_log_B.CANReceive_o2_mh > 0) {
      /* DataTypeConversion: '<S199>/EPS_APA_AbortFeedback_Convert' */
      rtb_EPS_TorqueSensorStatus_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_jz
        [1];

      /* S-Function (sfix_bitop): '<S199>/EPS_APA_AbortFeedback_L' */
      rtb_EPS_TorqueSensorStatus_L &= 112U;

      /* ArithShift: '<S199>/EPS_APA_AbortFeedback_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 4);

      /* DataTypeConversion: '<S199>/EPS_APA_AbortFeedbackcv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S199>/EPS_APA_AbortFeedback_Ad' */
      rtb_EPS_APA_AbortFeedback_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S199>/EPS_APA_AbortFeedback_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_APA_AbortFeedback_sat;
      rtb_EPS_APA_AbortFeedback_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* DataTypeConversion: '<S199>/EPS_APA_ControlFeedback_Convert' */
      rtb_EPS_TorqueSensorStatus_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_jz
        [5];

      /* S-Function (sfix_bitop): '<S199>/EPS_APA_ControlFeedback_L' */
      rtb_EPS_TorqueSensorStatus_L &= 64U;

      /* ArithShift: '<S199>/EPS_APA_ControlFeedback_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 6);

      /* DataTypeConversion: '<S199>/EPS_APA_ControlFeedbackcv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S199>/EPS_APA_ControlFeedback_Ad' */
      rtb_EPS_APA_ControlFeedback_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S199>/EPS_APA_ControlFeedback_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_APA_ControlFeedback_sat;
      rtb_EPS_APA_ControlFeedback_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* DataTypeConversion: '<S199>/EPS_APA_EpasFailed_Convert' */
      rtb_EPS_TorqueSensorStatus_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_jz
        [1];

      /* S-Function (sfix_bitop): '<S199>/EPS_APA_EpasFailed_L' */
      rtb_EPS_TorqueSensorStatus_L &= 2U;

      /* ArithShift: '<S199>/EPS_APA_EpasFailed_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 1);

      /* DataTypeConversion: '<S199>/EPS_APA_EpasFailedcv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S199>/EPS_APA_EpasFailed_Ad' */
      rtb_EPS_APA_EpasFailed_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S199>/EPS_APA_EpasFailed_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_APA_EpasFailed_sat;
      rtb_EPS_APA_EpasFailed_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* DataTypeConversion: '<S199>/EPS_Checksum_Convert' */
      rtb_EPS_TorqueSensorStatus_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_jz
        [7];

      /* DataTypeConversion: '<S199>/EPS_Checksumcv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S199>/EPS_Checksum_Ad' */
      rtb_EPS_Checksum_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S199>/EPS_Checksum_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_Checksum_sat;
      rtb_EPS_Checksum_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* DataTypeConversion: '<S199>/EPS_ConcussAvailabilityStatus_Convert' */
      rtb_EPS_TorqueSensorStatus_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_jz
        [6];

      /* S-Function (sfix_bitop): '<S199>/EPS_ConcussAvailabilityStatus_L' */
      rtb_EPS_TorqueSensorStatus_L &= 48U;

      /* ArithShift: '<S199>/EPS_ConcussAvailabilityStatus_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 4);

      /* DataTypeConversion: '<S199>/EPS_ConcussAvailabilityStatuscv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S199>/EPS_ConcussAvailabilityStatus_Ad' */
      rtb_EPS_ConcussAvailabilityStat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S199>/EPS_ConcussAvailabilityStatus_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_ConcussAvailabilityStat;
      rtb_EPS_ConcussAvailabilityStat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* DataTypeConversion: '<S199>/EPS_EPSFailed_Convert' */
      rtb_EPS_TorqueSensorStatus_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_jz
        [0];

      /* S-Function (sfix_bitop): '<S199>/EPS_EPSFailed_L' */
      rtb_EPS_TorqueSensorStatus_L &= 128U;

      /* ArithShift: '<S199>/EPS_EPSFailed_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 7);

      /* DataTypeConversion: '<S199>/EPS_EPSFailedcv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S199>/EPS_EPSFailed_Ad' */
      rtb_EPS_EPSFailed_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S199>/EPS_EPSFailed_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_EPSFailed_sat;
      rtb_EPS_EPSFailed_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* DataTypeConversion: '<S199>/EPS_RollingCounter_Convert' */
      rtb_EPS_TorqueSensorStatus_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_jz
        [6];

      /* S-Function (sfix_bitop): '<S199>/EPS_RollingCounter_L' */
      rtb_EPS_TorqueSensorStatus_L &= 15U;

      /* DataTypeConversion: '<S199>/EPS_RollingCountercv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S199>/EPS_RollingCounter_Ad' */
      rtb_EPS_RollingCounter_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S199>/EPS_RollingCounter_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_RollingCounter_sat;
      rtb_EPS_RollingCounter_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Product: '<S199>/EPS_SteeringTorqueinput3_P' incorporates:
       *  Constant: '<S199>/EPS_SteeringTorqueinput3_C'
       */
      rtb_EPS_SteeringTorque_sat = (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_jz[2] * 256.0;

      /* Sum: '<S199>/EPS_SteeringTorqueinput3_Ad' */
      rtb_EPS_TorqueSensorStatuscv = rtb_EPS_SteeringTorque_sat + (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_jz[3];

      /* DataTypeConversion: '<S199>/EPS_SteeringTorque_Convert' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)rtb_EPS_TorqueSensorStatuscv;

      /* S-Function (sfix_bitop): '<S199>/EPS_SteeringTorque_L' */
      rtb_EPS_TorqueSensorStatus_L &= 4080U;

      /* ArithShift: '<S199>/EPS_SteeringTorque_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 4);

      /* DataTypeConversion: '<S199>/EPS_SteeringTorquecv' */
      rtb_EPS_TorqueSensorStatuscv = rtb_EPS_TorqueSensorStatus_L;

      /* Gain: '<S199>/EPS_SteeringTorque_F' */
      rtb_EPS_TorqueSensorStatuscv *= 0.1794;

      /* Sum: '<S199>/EPS_SteeringTorque_Ad' incorporates:
       *  Constant: '<S199>/EPS_SteeringTorque_O'
       */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatuscv +
        -22.780000686645508;

      /* Saturate: '<S199>/EPS_SteeringTorque_sat' */
      if (rtb_EPS_SteeringTorque_sat > 22.78) {
        rtb_EPS_SteeringTorque_sat = 22.78;
      } else {
        if (rtb_EPS_SteeringTorque_sat < -22.78) {
          rtb_EPS_SteeringTorque_sat = -22.78;
        }
      }

      /* End of Saturate: '<S199>/EPS_SteeringTorque_sat' */

      /* DataTypeConversion: '<S199>/EPS_TorqueSensorStatus_Convert' */
      rtb_EPS_TorqueSensorStatus_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_jz
        [4];

      /* S-Function (sfix_bitop): '<S199>/EPS_TorqueSensorStatus_L' */
      rtb_EPS_TorqueSensorStatus_L &= 2U;

      /* ArithShift: '<S199>/EPS_TorqueSensorStatus_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 1);

      /* DataTypeConversion: '<S199>/EPS_TorqueSensorStatuscv' */
      rtb_EPS_TorqueSensorStatuscv = rtb_EPS_TorqueSensorStatus_L;

      /* SignalConversion: '<S198>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPS_EPSFailed_k = rtb_EPS_EPSFailed_sat;

      /* SignalConversion: '<S198>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPS_APA_EpasFailed = rtb_EPS_APA_EpasFailed_sat;

      /* SignalConversion: '<S198>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPS_APA_AbortFeedback =
        rtb_EPS_APA_AbortFeedback_sat;

      /* SignalConversion: '<S198>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPS_SteeringTorque = rtb_EPS_SteeringTorque_sat;

      /* SignalConversion: '<S198>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPS_TorqueSensorStatus =
        rtb_EPS_TorqueSensorStatuscv;

      /* SignalConversion: '<S198>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPS_APA_ControlFeedback =
        rtb_EPS_APA_ControlFeedback_sat;

      /* SignalConversion: '<S198>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPS_RollingCounter = rtb_EPS_RollingCounter_sat;

      /* SignalConversion: '<S198>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPS_ConcussAvailabilityStatus =
        rtb_EPS_ConcussAvailabilityStat;

      /* SignalConversion: '<S198>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPS_Checksum = rtb_EPS_Checksum_sat;
    }

    /* End of Outputs for SubSystem: '<S197>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S91>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF6RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf6looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_ii= 538;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_kn= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_ip= ec_can_receive(1,6, CAN1BUF6RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_o[0]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_o[1]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_o[2]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_o[3]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_o[4]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_o[5]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_o[6]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_o[7]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
  }

  /* Call the system: <S91>/ReceiveMessages */

  /* Output and update for function-call system: '<S91>/ReceiveMessages' */
  {
    int32_T rtb_Rollingcounter_L;
    real_T rtb_EPS_MeasuredTosionBatTorque;
    int32_T rtb_EPS_AvailabilityStatus_sat;
    int32_T rtb_EPS_IACC_abortReson_sat;
    int32_T rtb_EPS_MeasTsionBatTorquevalid;
    real_T rtb_Rollingcountercv;

    /* Outputs for Enabled SubSystem: '<S209>/Subsystem' incorporates:
     *  EnablePort: '<S210>/Enable'
     */
    if (VCU_CS75_12_27_test_log_B.CANReceive_o2_ip > 0) {
      /* DataTypeConversion: '<S211>/EPS_AvailabilityStatus_Convert' */
      rtb_Rollingcounter_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_o[2];

      /* S-Function (sfix_bitop): '<S211>/EPS_AvailabilityStatus_L' */
      rtb_Rollingcounter_L &= 28U;

      /* ArithShift: '<S211>/EPS_AvailabilityStatus_S' */
      rtb_Rollingcounter_L = (int32_T)((uint32_T)rtb_Rollingcounter_L >> 2);

      /* DataTypeConversion: '<S211>/EPS_AvailabilityStatuscv' */
      rtb_EPS_MeasuredTosionBatTorque = rtb_Rollingcounter_L;

      /* Sum: '<S211>/EPS_AvailabilityStatus_Ad' */
      rtb_EPS_AvailabilityStatus_sat = (int32_T)rtb_EPS_MeasuredTosionBatTorque;

      /* Saturate: '<S211>/EPS_AvailabilityStatus_sat' */
      rtb_EPS_MeasuredTosionBatTorque = rtb_EPS_AvailabilityStatus_sat;
      rtb_EPS_AvailabilityStatus_sat = (int32_T)rtb_EPS_MeasuredTosionBatTorque;

      /* DataTypeConversion: '<S211>/EPS_IACC_abortReson_Convert' */
      rtb_Rollingcounter_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_o[5];

      /* S-Function (sfix_bitop): '<S211>/EPS_IACC_abortReson_L' */
      rtb_Rollingcounter_L &= 112U;

      /* ArithShift: '<S211>/EPS_IACC_abortReson_S' */
      rtb_Rollingcounter_L = (int32_T)((uint32_T)rtb_Rollingcounter_L >> 4);

      /* DataTypeConversion: '<S211>/EPS_IACC_abortResoncv' */
      rtb_EPS_MeasuredTosionBatTorque = rtb_Rollingcounter_L;

      /* Sum: '<S211>/EPS_IACC_abortReson_Ad' */
      rtb_EPS_IACC_abortReson_sat = (int32_T)rtb_EPS_MeasuredTosionBatTorque;

      /* Saturate: '<S211>/EPS_IACC_abortReson_sat' */
      rtb_EPS_MeasuredTosionBatTorque = rtb_EPS_IACC_abortReson_sat;
      rtb_EPS_IACC_abortReson_sat = (int32_T)rtb_EPS_MeasuredTosionBatTorque;

      /* DataTypeConversion: '<S211>/EPS_MeasTsionBatTorquevalid_Convert' */
      rtb_Rollingcounter_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_o[4];

      /* S-Function (sfix_bitop): '<S211>/EPS_MeasTsionBatTorquevalid_L' */
      rtb_Rollingcounter_L &= 64U;

      /* ArithShift: '<S211>/EPS_MeasTsionBatTorquevalid_S' */
      rtb_Rollingcounter_L = (int32_T)((uint32_T)rtb_Rollingcounter_L >> 6);

      /* DataTypeConversion: '<S211>/EPS_MeasTsionBatTorquevalidcv' */
      rtb_EPS_MeasuredTosionBatTorque = rtb_Rollingcounter_L;

      /* Sum: '<S211>/EPS_MeasTsionBatTorquevalid_Ad' */
      rtb_EPS_MeasTsionBatTorquevalid = (int32_T)rtb_EPS_MeasuredTosionBatTorque;

      /* Saturate: '<S211>/EPS_MeasTsionBatTorquevalid_sat' */
      rtb_EPS_MeasuredTosionBatTorque = rtb_EPS_MeasTsionBatTorquevalid;
      rtb_EPS_MeasTsionBatTorquevalid = (int32_T)rtb_EPS_MeasuredTosionBatTorque;

      /* Product: '<S211>/EPS_MeasuredTosionBatTorqueinput1_P' incorporates:
       *  Constant: '<S211>/EPS_MeasuredTosionBatTorqueinput1_C'
       */
      rtb_EPS_MeasuredTosionBatTorque = (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_o[0] * 256.0;

      /* Sum: '<S211>/EPS_MeasuredTosionBatTorqueinput1_Ad' */
      rtb_Rollingcountercv = rtb_EPS_MeasuredTosionBatTorque + (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_o[1];

      /* DataTypeConversion: '<S211>/EPS_MeasuredTosionBatTorque_Convert' */
      rtb_Rollingcounter_L = (int32_T)rtb_Rollingcountercv;

      /* S-Function (sfix_bitop): '<S211>/EPS_MeasuredTosionBatTorque_L' */
      rtb_Rollingcounter_L &= 65504U;

      /* ArithShift: '<S211>/EPS_MeasuredTosionBatTorque_S' */
      rtb_Rollingcounter_L = (int32_T)((uint32_T)rtb_Rollingcounter_L >> 5);

      /* DataTypeConversion: '<S211>/EPS_MeasuredTosionBatTorquecv' */
      rtb_Rollingcountercv = rtb_Rollingcounter_L;

      /* Gain: '<S211>/EPS_MeasuredTosionBatTorque_F' */
      rtb_Rollingcountercv *= 0.01;

      /* Sum: '<S211>/EPS_MeasuredTosionBatTorque_Ad' incorporates:
       *  Constant: '<S211>/EPS_MeasuredTosionBatTorque_O'
       */
      rtb_EPS_MeasuredTosionBatTorque = rtb_Rollingcountercv +
        -10.229999542236328;

      /* Saturate: '<S211>/EPS_MeasuredTosionBatTorque_sat' */
      if (rtb_EPS_MeasuredTosionBatTorque > 10.23) {
        rtb_EPS_MeasuredTosionBatTorque = 10.23;
      }

      /* End of Saturate: '<S211>/EPS_MeasuredTosionBatTorque_sat' */

      /* DataTypeConversion: '<S211>/Rollingcounter_Convert' */
      rtb_Rollingcounter_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_o[6];

      /* S-Function (sfix_bitop): '<S211>/Rollingcounter_L' */
      rtb_Rollingcounter_L &= 15U;

      /* DataTypeConversion: '<S211>/Rollingcountercv' */
      rtb_Rollingcountercv = rtb_Rollingcounter_L;

      /* SignalConversion: '<S210>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPS_MeasuredTosionBatTorque =
        rtb_EPS_MeasuredTosionBatTorque;

      /* SignalConversion: '<S210>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPS_AvailabilityStatus_a =
        rtb_EPS_AvailabilityStatus_sat;

      /* SignalConversion: '<S210>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPS_MeasTsionBatTorquevalid =
        rtb_EPS_MeasTsionBatTorquevalid;

      /* SignalConversion: '<S210>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPS_IACC_abortReson =
        rtb_EPS_IACC_abortReson_sat;

      /* SignalConversion: '<S210>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPS_21A_Rollingcounter = rtb_Rollingcountercv;

      /* SignalConversion: '<S210>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPS_21A_CheckingSum = 0.0;
    }

    /* End of Outputs for SubSystem: '<S209>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S92>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF7RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf7looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_an= 631;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_py= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_e= ec_can_receive(1,7, CAN1BUF7RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_dj[0]= CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_dj[1]= CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_dj[2]= CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_dj[3]= CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_dj[4]= CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_dj[5]= CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_dj[6]= CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_dj[7]= CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
  }

  /* Call the system: <S92>/ReceiveMessages */

  /* Output and update for function-call system: '<S92>/ReceiveMessages' */
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

    /* Outputs for Enabled SubSystem: '<S218>/Subsystem' incorporates:
     *  EnablePort: '<S219>/Enable'
     */
    if (VCU_CS75_12_27_test_log_B.CANReceive_o2_e > 0) {
      /* DataTypeConversion: '<S220>/ESP_ABAactive_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_dj[2];

      /* S-Function (sfix_bitop): '<S220>/ESP_ABAactive_L' */
      rtb_ESP_VehicleStandstill_L &= 32U;

      /* ArithShift: '<S220>/ESP_ABAactive_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 5);

      /* Sum: '<S220>/ESP_ABAactive_Ad' */
      rtb_ESP_ABAactive_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S220>/ESP_ABAactive_sat' */
      u0 = rtb_ESP_ABAactive_sat;
      rtb_ESP_ABAactive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S220>/ESP_ABAavailable_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_dj[2];

      /* S-Function (sfix_bitop): '<S220>/ESP_ABAavailable_L' */
      rtb_ESP_VehicleStandstill_L &= 16U;

      /* ArithShift: '<S220>/ESP_ABAavailable_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 4);

      /* Sum: '<S220>/ESP_ABAavailable_Ad' */
      rtb_ESP_ABAavailable_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S220>/ESP_ABAavailable_sat' */
      u0 = rtb_ESP_ABAavailable_sat;
      rtb_ESP_ABAavailable_sat = (int32_T)u0;

      /* DataTypeConversion: '<S220>/ESP_AEBAvailable_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_dj[2];

      /* S-Function (sfix_bitop): '<S220>/ESP_AEBAvailable_L' */
      rtb_ESP_VehicleStandstill_L &= 8U;

      /* ArithShift: '<S220>/ESP_AEBAvailable_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 3);

      /* Sum: '<S220>/ESP_AEBAvailable_Ad' */
      rtb_ESP_AEBAvailable_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S220>/ESP_AEBAvailable_sat' */
      u0 = rtb_ESP_AEBAvailable_sat;
      rtb_ESP_AEBAvailable_sat = (int32_T)u0;

      /* DataTypeConversion: '<S220>/ESP_AEBdecActive_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_dj[2];

      /* S-Function (sfix_bitop): '<S220>/ESP_AEBdecActive_L' */
      rtb_ESP_VehicleStandstill_L &= 4U;

      /* ArithShift: '<S220>/ESP_AEBdecActive_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 2);

      /* Sum: '<S220>/ESP_AEBdecActive_Ad' */
      rtb_ESP_AEBdecActive_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S220>/ESP_AEBdecActive_sat' */
      u0 = rtb_ESP_AEBdecActive_sat;
      rtb_ESP_AEBdecActive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S220>/ESP_AWBactive_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_dj[2];

      /* S-Function (sfix_bitop): '<S220>/ESP_AWBactive_L' */
      rtb_ESP_VehicleStandstill_L &= 2U;

      /* ArithShift: '<S220>/ESP_AWBactive_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 1);

      /* Sum: '<S220>/ESP_AWBactive_Ad' */
      rtb_ESP_AWBactive_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S220>/ESP_AWBactive_sat' */
      u0 = rtb_ESP_AWBactive_sat;
      rtb_ESP_AWBactive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S220>/ESP_AWBavailable_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_dj[2];

      /* S-Function (sfix_bitop): '<S220>/ESP_AWBavailable_L' */
      rtb_ESP_VehicleStandstill_L &= 1U;

      /* Sum: '<S220>/ESP_AWBavailable_Ad' */
      rtb_ESP_AWBavailable_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S220>/ESP_AWBavailable_sat' */
      u0 = rtb_ESP_AWBavailable_sat;
      rtb_ESP_AWBavailable_sat = (int32_T)u0;

      /* DataTypeConversion: '<S220>/ESP_BrakeForce_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_dj[1];

      /* S-Function (sfix_bitop): '<S220>/ESP_BrakeForce_L' */
      rtb_ESP_VehicleStandstill_L &= 16U;

      /* ArithShift: '<S220>/ESP_BrakeForce_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 4);

      /* Sum: '<S220>/ESP_BrakeForce_Ad' */
      rtb_ESP_BrakeForce_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S220>/ESP_BrakeForce_sat' */
      u0 = rtb_ESP_BrakeForce_sat;
      rtb_ESP_BrakeForce_sat = (int32_T)u0;

      /* DataTypeConversion: '<S220>/ESP_BrakeOverHeat_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_dj[3];

      /* S-Function (sfix_bitop): '<S220>/ESP_BrakeOverHeat_L' */
      rtb_ESP_VehicleStandstill_L &= 1U;

      /* Sum: '<S220>/ESP_BrakeOverHeat_Ad' */
      rtb_ESP_BrakeOverHeat_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S220>/ESP_BrakeOverHeat_sat' */
      u0 = rtb_ESP_BrakeOverHeat_sat;
      rtb_ESP_BrakeOverHeat_sat = (int32_T)u0;

      /* DataTypeConversion: '<S220>/ESP_CDD_Active_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_dj[3];

      /* S-Function (sfix_bitop): '<S220>/ESP_CDD_Active_L' */
      rtb_ESP_VehicleStandstill_L &= 8U;

      /* ArithShift: '<S220>/ESP_CDD_Active_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 3);

      /* Sum: '<S220>/ESP_CDD_Active_Ad' */
      rtb_ESP_CDD_Active_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S220>/ESP_CDD_Active_sat' */
      u0 = rtb_ESP_CDD_Active_sat;
      rtb_ESP_CDD_Active_sat = (int32_T)u0;

      /* DataTypeConversion: '<S220>/ESP_CDD_Available_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_dj[3];

      /* S-Function (sfix_bitop): '<S220>/ESP_CDD_Available_L' */
      rtb_ESP_VehicleStandstill_L &= 16U;

      /* ArithShift: '<S220>/ESP_CDD_Available_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 4);

      /* Sum: '<S220>/ESP_CDD_Available_Ad' */
      rtb_ESP_CDD_Available_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S220>/ESP_CDD_Available_sat' */
      u0 = rtb_ESP_CDD_Available_sat;
      rtb_ESP_CDD_Available_sat = (int32_T)u0;

      /* DataTypeConversion: '<S220>/ESP_CheckSum_277_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_dj[7];

      /* Sum: '<S220>/ESP_CheckSum_277_Ad' */
      rtb_ESP_CheckSum_277_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S220>/ESP_CheckSum_277_sat' */
      u0 = rtb_ESP_CheckSum_277_sat;
      rtb_ESP_CheckSum_277_sat = (int32_T)u0;

      /* DataTypeConversion: '<S220>/ESP_PrefillActive_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_dj[2];

      /* S-Function (sfix_bitop): '<S220>/ESP_PrefillActive_L' */
      rtb_ESP_VehicleStandstill_L &= 128U;

      /* ArithShift: '<S220>/ESP_PrefillActive_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 7);

      /* Sum: '<S220>/ESP_PrefillActive_Ad' */
      rtb_ESP_PrefillActive_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S220>/ESP_PrefillActive_sat' */
      u0 = rtb_ESP_PrefillActive_sat;
      rtb_ESP_PrefillActive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S220>/ESP_PrefillAvailable_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_dj[2];

      /* S-Function (sfix_bitop): '<S220>/ESP_PrefillAvailable_L' */
      rtb_ESP_VehicleStandstill_L &= 64U;

      /* ArithShift: '<S220>/ESP_PrefillAvailable_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 6);

      /* Sum: '<S220>/ESP_PrefillAvailable_Ad' */
      rtb_ESP_PrefillAvailable_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S220>/ESP_PrefillAvailable_sat' */
      u0 = rtb_ESP_PrefillAvailable_sat;
      rtb_ESP_PrefillAvailable_sat = (int32_T)u0;

      /* DataTypeConversion: '<S220>/ESP_RollingCounter_277_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_dj[6];

      /* S-Function (sfix_bitop): '<S220>/ESP_RollingCounter_277_L' */
      rtb_ESP_VehicleStandstill_L &= 15U;

      /* Sum: '<S220>/ESP_RollingCounter_277_Ad' */
      rtb_ESP_RollingCounter_277_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S220>/ESP_RollingCounter_277_sat' */
      u0 = rtb_ESP_RollingCounter_277_sat;
      rtb_ESP_RollingCounter_277_sat = (int32_T)u0;

      /* DataTypeConversion: '<S220>/ESP_TCSActive_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_dj[1];

      /* S-Function (sfix_bitop): '<S220>/ESP_TCSActive_L' */
      rtb_ESP_VehicleStandstill_L &= 64U;

      /* ArithShift: '<S220>/ESP_TCSActive_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 6);

      /* Sum: '<S220>/ESP_TCSActive_Ad' */
      rtb_ESP_TCSActive_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S220>/ESP_TCSActive_sat' */
      u0 = rtb_ESP_TCSActive_sat;
      rtb_ESP_TCSActive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S220>/ESP_VDCActive_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_dj[1];

      /* S-Function (sfix_bitop): '<S220>/ESP_VDCActive_L' */
      rtb_ESP_VehicleStandstill_L &= 32U;

      /* ArithShift: '<S220>/ESP_VDCActive_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 5);

      /* Sum: '<S220>/ESP_VDCActive_Ad' */
      rtb_ESP_VDCActive_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S220>/ESP_VDCActive_sat' */
      u0 = rtb_ESP_VDCActive_sat;
      rtb_ESP_VDCActive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S220>/ESP_VehicleStandstill_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_dj[3];

      /* S-Function (sfix_bitop): '<S220>/ESP_VehicleStandstill_L' */
      rtb_ESP_VehicleStandstill_L &= 64U;

      /* ArithShift: '<S220>/ESP_VehicleStandstill_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 6);

      /* Saturate: '<S220>/ESP_VehicleStandstill_sat' */
      u0 = rtb_ESP_VehicleStandstill_L;
      rtb_ESP_VehicleStandstill_L = (int32_T)u0;

      /* SignalConversion: '<S219>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_BrakeForce = rtb_ESP_BrakeForce_sat;

      /* SignalConversion: '<S219>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_PrefillAvailable =
        rtb_ESP_PrefillAvailable_sat;

      /* SignalConversion: '<S219>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_PrefillActive = rtb_ESP_PrefillActive_sat;

      /* SignalConversion: '<S219>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_BrakeOverHeat = rtb_ESP_BrakeOverHeat_sat;

      /* SignalConversion: '<S219>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_CDD_Active = rtb_ESP_CDD_Active_sat;

      /* SignalConversion: '<S219>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_CDD_Available = rtb_ESP_CDD_Available_sat;

      /* SignalConversion: '<S219>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_CDD_Active_APA = 0.0;

      /* SignalConversion: '<S219>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_VehicleStandstill =
        rtb_ESP_VehicleStandstill_L;

      /* SignalConversion: '<S219>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_CDD_Available_APA = 0.0;

      /* SignalConversion: '<S219>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_RollingCounter_277 =
        rtb_ESP_RollingCounter_277_sat;

      /* SignalConversion: '<S219>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_CheckSum_277 = rtb_ESP_CheckSum_277_sat;

      /* SignalConversion: '<S219>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_VDCActive = rtb_ESP_VDCActive_sat;

      /* SignalConversion: '<S219>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_TCSActive = rtb_ESP_TCSActive_sat;

      /* SignalConversion: '<S219>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_AWBavailable = rtb_ESP_AWBavailable_sat;

      /* SignalConversion: '<S219>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_AWBactive = rtb_ESP_AWBactive_sat;

      /* SignalConversion: '<S219>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_AEBdecActive = rtb_ESP_AEBdecActive_sat;

      /* SignalConversion: '<S219>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_AEBAvailable = rtb_ESP_AEBAvailable_sat;

      /* SignalConversion: '<S219>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_ABAavailable = rtb_ESP_ABAavailable_sat;

      /* SignalConversion: '<S219>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_ABAactive = rtb_ESP_ABAactive_sat;
    }

    /* End of Outputs for SubSystem: '<S218>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S93>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF16RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf16looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_iy= 640;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_e= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_ix= ec_can_receive(1,16, CAN1BUF16RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_is[0]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_is[1]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_is[2]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_is[3]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_is[4]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_is[5]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_is[6]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_is[7]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
  }

  /* Call the system: <S93>/ReceiveMessages */

  /* Output and update for function-call system: '<S93>/ReceiveMessages' */
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

    /* Outputs for Enabled SubSystem: '<S240>/Subsystem' incorporates:
     *  EnablePort: '<S241>/Enable'
     */
    if (VCU_CS75_12_27_test_log_B.CANReceive_o2_ix > 0) {
      /* Product: '<S242>/Wheel_Speed_FL_Datainput7_P' incorporates:
       *  Constant: '<S242>/Wheel_Speed_FL_Datainput7_C'
       */
      rtb_Wheel_Speed_FL_Data_sat = (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_is[6] * 256.0;

      /* Sum: '<S242>/Wheel_Speed_FL_Datainput7_Ad' */
      rtb_Wheel_Speed_FR_Data_sat = rtb_Wheel_Speed_FL_Data_sat + (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_is[7];

      /* DataTypeConversion: '<S242>/Wheel_Speed_FL_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)rtb_Wheel_Speed_FR_Data_sat;

      /* S-Function (sfix_bitop): '<S242>/Wheel_Speed_FL_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 8191U;

      /* DataTypeConversion: '<S242>/Wheel_Speed_FL_Datacv' */
      rtb_Wheel_Speed_FR_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Gain: '<S242>/Wheel_Speed_FL_Data_F' */
      rtb_Wheel_Speed_FR_Data_sat *= 0.05625;

      /* Sum: '<S242>/Wheel_Speed_FL_Data_Ad' */
      rtb_Wheel_Speed_FL_Data_sat = rtb_Wheel_Speed_FR_Data_sat;

      /* Saturate: '<S242>/Wheel_Speed_FL_Data_sat' */
      if (rtb_Wheel_Speed_FL_Data_sat > 360.0) {
        rtb_Wheel_Speed_FL_Data_sat = 360.0;
      }

      /* End of Saturate: '<S242>/Wheel_Speed_FL_Data_sat' */

      /* DataTypeConversion: '<S242>/Wheel_Speed_FL_Direction_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_is[6];

      /* S-Function (sfix_bitop): '<S242>/Wheel_Speed_FL_Direction_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 96U;

      /* ArithShift: '<S242>/Wheel_Speed_FL_Direction_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 5);

      /* DataTypeConversion: '<S242>/Wheel_Speed_FL_Directioncv' */
      rtb_Wheel_Speed_FR_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S242>/Wheel_Speed_FL_Direction_Ad' */
      rtb_Wheel_Speed_FL_Direction_sa = (int32_T)rtb_Wheel_Speed_FR_Data_sat;

      /* Saturate: '<S242>/Wheel_Speed_FL_Direction_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_FL_Direction_sa;
      rtb_Wheel_Speed_FL_Direction_sa = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* DataTypeConversion: '<S242>/Wheel_Speed_FL_Valid_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_is[6];

      /* S-Function (sfix_bitop): '<S242>/Wheel_Speed_FL_Valid_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 128U;

      /* ArithShift: '<S242>/Wheel_Speed_FL_Valid_Data_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 7);

      /* DataTypeConversion: '<S242>/Wheel_Speed_FL_Valid_Datacv' */
      rtb_Wheel_Speed_FR_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S242>/Wheel_Speed_FL_Valid_Data_Ad' */
      rtb_Wheel_Speed_FL_Valid_Data_s = (int32_T)rtb_Wheel_Speed_FR_Data_sat;

      /* Saturate: '<S242>/Wheel_Speed_FL_Valid_Data_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_FL_Valid_Data_s;
      rtb_Wheel_Speed_FL_Valid_Data_s = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* Product: '<S242>/Wheel_Speed_FR_Datainput5_P' incorporates:
       *  Constant: '<S242>/Wheel_Speed_FR_Datainput5_C'
       */
      rtb_Wheel_Speed_FR_Data_sat = (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_is[4] * 256.0;

      /* Sum: '<S242>/Wheel_Speed_FR_Datainput5_Ad' */
      rtb_Wheel_Speed_RL_Data_sat = rtb_Wheel_Speed_FR_Data_sat + (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_is[5];

      /* DataTypeConversion: '<S242>/Wheel_Speed_FR_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)rtb_Wheel_Speed_RL_Data_sat;

      /* S-Function (sfix_bitop): '<S242>/Wheel_Speed_FR_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 8191U;

      /* DataTypeConversion: '<S242>/Wheel_Speed_FR_Datacv' */
      rtb_Wheel_Speed_RL_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Gain: '<S242>/Wheel_Speed_FR_Data_F' */
      rtb_Wheel_Speed_RL_Data_sat *= 0.05625;

      /* Sum: '<S242>/Wheel_Speed_FR_Data_Ad' */
      rtb_Wheel_Speed_FR_Data_sat = rtb_Wheel_Speed_RL_Data_sat;

      /* Saturate: '<S242>/Wheel_Speed_FR_Data_sat' */
      if (rtb_Wheel_Speed_FR_Data_sat > 360.0) {
        rtb_Wheel_Speed_FR_Data_sat = 360.0;
      }

      /* End of Saturate: '<S242>/Wheel_Speed_FR_Data_sat' */

      /* DataTypeConversion: '<S242>/Wheel_Speed_FR_Direction_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_is[4];

      /* S-Function (sfix_bitop): '<S242>/Wheel_Speed_FR_Direction_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 96U;

      /* ArithShift: '<S242>/Wheel_Speed_FR_Direction_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 5);

      /* DataTypeConversion: '<S242>/Wheel_Speed_FR_Directioncv' */
      rtb_Wheel_Speed_RL_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S242>/Wheel_Speed_FR_Direction_Ad' */
      rtb_Wheel_Speed_FR_Direction_sa = (int32_T)rtb_Wheel_Speed_RL_Data_sat;

      /* Saturate: '<S242>/Wheel_Speed_FR_Direction_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_FR_Direction_sa;
      rtb_Wheel_Speed_FR_Direction_sa = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* DataTypeConversion: '<S242>/Wheel_Speed_FR_Valid_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_is[4];

      /* S-Function (sfix_bitop): '<S242>/Wheel_Speed_FR_Valid_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 128U;

      /* ArithShift: '<S242>/Wheel_Speed_FR_Valid_Data_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 7);

      /* DataTypeConversion: '<S242>/Wheel_Speed_FR_Valid_Datacv' */
      rtb_Wheel_Speed_RL_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S242>/Wheel_Speed_FR_Valid_Data_Ad' */
      rtb_Wheel_Speed_FR_Valid_Data_s = (int32_T)rtb_Wheel_Speed_RL_Data_sat;

      /* Saturate: '<S242>/Wheel_Speed_FR_Valid_Data_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_FR_Valid_Data_s;
      rtb_Wheel_Speed_FR_Valid_Data_s = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* Product: '<S242>/Wheel_Speed_RL_Datainput3_P' incorporates:
       *  Constant: '<S242>/Wheel_Speed_RL_Datainput3_C'
       */
      rtb_Wheel_Speed_RL_Data_sat = (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_is[2] * 256.0;

      /* Sum: '<S242>/Wheel_Speed_RL_Datainput3_Ad' */
      rtb_Wheel_Speed_RR_Data_sat = rtb_Wheel_Speed_RL_Data_sat + (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_is[3];

      /* DataTypeConversion: '<S242>/Wheel_Speed_RL_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)rtb_Wheel_Speed_RR_Data_sat;

      /* S-Function (sfix_bitop): '<S242>/Wheel_Speed_RL_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 8191U;

      /* DataTypeConversion: '<S242>/Wheel_Speed_RL_Datacv' */
      rtb_Wheel_Speed_RR_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Gain: '<S242>/Wheel_Speed_RL_Data_F' */
      rtb_Wheel_Speed_RR_Data_sat *= 0.05625;

      /* Sum: '<S242>/Wheel_Speed_RL_Data_Ad' */
      rtb_Wheel_Speed_RL_Data_sat = rtb_Wheel_Speed_RR_Data_sat;

      /* Saturate: '<S242>/Wheel_Speed_RL_Data_sat' */
      if (rtb_Wheel_Speed_RL_Data_sat > 360.0) {
        rtb_Wheel_Speed_RL_Data_sat = 360.0;
      }

      /* End of Saturate: '<S242>/Wheel_Speed_RL_Data_sat' */

      /* DataTypeConversion: '<S242>/Wheel_Speed_RL_Direction_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_is[2];

      /* S-Function (sfix_bitop): '<S242>/Wheel_Speed_RL_Direction_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 96U;

      /* ArithShift: '<S242>/Wheel_Speed_RL_Direction_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 5);

      /* DataTypeConversion: '<S242>/Wheel_Speed_RL_Directioncv' */
      rtb_Wheel_Speed_RR_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S242>/Wheel_Speed_RL_Direction_Ad' */
      rtb_Wheel_Speed_RL_Direction_sa = (int32_T)rtb_Wheel_Speed_RR_Data_sat;

      /* Saturate: '<S242>/Wheel_Speed_RL_Direction_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RL_Direction_sa;
      rtb_Wheel_Speed_RL_Direction_sa = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* DataTypeConversion: '<S242>/Wheel_Speed_RL_Valid_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_is[2];

      /* S-Function (sfix_bitop): '<S242>/Wheel_Speed_RL_Valid_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 128U;

      /* ArithShift: '<S242>/Wheel_Speed_RL_Valid_Data_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 7);

      /* DataTypeConversion: '<S242>/Wheel_Speed_RL_Valid_Datacv' */
      rtb_Wheel_Speed_RR_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S242>/Wheel_Speed_RL_Valid_Data_Ad' */
      rtb_Wheel_Speed_RL_Valid_Data_s = (int32_T)rtb_Wheel_Speed_RR_Data_sat;

      /* Saturate: '<S242>/Wheel_Speed_RL_Valid_Data_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RL_Valid_Data_s;
      rtb_Wheel_Speed_RL_Valid_Data_s = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* Product: '<S242>/Wheel_Speed_RR_Datainput1_P' incorporates:
       *  Constant: '<S242>/Wheel_Speed_RR_Datainput1_C'
       */
      rtb_Wheel_Speed_RR_Data_sat = (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_is[0] * 256.0;

      /* Sum: '<S242>/Wheel_Speed_RR_Datainput1_Ad' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RR_Data_sat + (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_is[1];

      /* DataTypeConversion: '<S242>/Wheel_Speed_RR_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* S-Function (sfix_bitop): '<S242>/Wheel_Speed_RR_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 8191U;

      /* DataTypeConversion: '<S242>/Wheel_Speed_RR_Datacv' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Gain: '<S242>/Wheel_Speed_RR_Data_F' */
      rtb_Wheel_Speed_RR_Valid_Datacv *= 0.05625;

      /* Sum: '<S242>/Wheel_Speed_RR_Data_Ad' */
      rtb_Wheel_Speed_RR_Data_sat = rtb_Wheel_Speed_RR_Valid_Datacv;

      /* Saturate: '<S242>/Wheel_Speed_RR_Data_sat' */
      if (rtb_Wheel_Speed_RR_Data_sat > 360.0) {
        rtb_Wheel_Speed_RR_Data_sat = 360.0;
      }

      /* End of Saturate: '<S242>/Wheel_Speed_RR_Data_sat' */

      /* DataTypeConversion: '<S242>/Wheel_Speed_RR_Direction_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_is[0];

      /* S-Function (sfix_bitop): '<S242>/Wheel_Speed_RR_Direction_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 96U;

      /* ArithShift: '<S242>/Wheel_Speed_RR_Direction_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 5);

      /* DataTypeConversion: '<S242>/Wheel_Speed_RR_Directioncv' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S242>/Wheel_Speed_RR_Direction_Ad' */
      rtb_Wheel_Speed_RR_Direction_sa = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* Saturate: '<S242>/Wheel_Speed_RR_Direction_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RR_Direction_sa;
      rtb_Wheel_Speed_RR_Direction_sa = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* DataTypeConversion: '<S242>/Wheel_Speed_RR_Valid_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_is[0];

      /* S-Function (sfix_bitop): '<S242>/Wheel_Speed_RR_Valid_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 128U;

      /* ArithShift: '<S242>/Wheel_Speed_RR_Valid_Data_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 7);

      /* DataTypeConversion: '<S242>/Wheel_Speed_RR_Valid_Datacv' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* SignalConversion: '<S241>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.Wheel_Speed_RR = rtb_Wheel_Speed_RR_Data_sat;

      /* SignalConversion: '<S241>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.Wheel_Speed_FL = rtb_Wheel_Speed_FL_Data_sat;

      /* SignalConversion: '<S241>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.Wheel_Speed_FL_Direction =
        rtb_Wheel_Speed_FL_Direction_sa;

      /* SignalConversion: '<S241>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.Wheel_Speed_FL_Valid =
        rtb_Wheel_Speed_FL_Valid_Data_s;

      /* SignalConversion: '<S241>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.Wheel_Speed_RR_Direction =
        rtb_Wheel_Speed_RR_Direction_sa;

      /* SignalConversion: '<S241>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.Wheel_Speed_RR_Valid =
        rtb_Wheel_Speed_RR_Valid_Datacv;

      /* SignalConversion: '<S241>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.Wheel_Speed_RL = rtb_Wheel_Speed_RL_Data_sat;

      /* SignalConversion: '<S241>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.Wheel_Speed_RL_Direction =
        rtb_Wheel_Speed_RL_Direction_sa;

      /* SignalConversion: '<S241>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.Wheel_Speed_RL_Valid =
        rtb_Wheel_Speed_RL_Valid_Data_s;

      /* SignalConversion: '<S241>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.Wheel_Speed_FR = rtb_Wheel_Speed_FR_Data_sat;

      /* SignalConversion: '<S241>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.Wheel_Speed_FR_Direction =
        rtb_Wheel_Speed_FR_Direction_sa;

      /* SignalConversion: '<S241>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.Wheel_Speed_FR_Valid =
        rtb_Wheel_Speed_FR_Valid_Data_s;
    }

    /* End of Outputs for SubSystem: '<S240>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S94>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF17RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf17looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_d= 641;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_kr= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_f= ec_can_receive(1,17, CAN1BUF17RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_jzv[0]= CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_jzv[1]= CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_jzv[2]= CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_jzv[3]= CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_jzv[4]= CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_jzv[5]= CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_jzv[6]= CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_jzv[7]= CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
  }

  /* Call the system: <S94>/ReceiveMessages */

  /* Output and update for function-call system: '<S94>/ReceiveMessages' */
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

    /* Outputs for Enabled SubSystem: '<S255>/Subsystem' incorporates:
     *  EnablePort: '<S256>/Enable'
     */
    if (VCU_CS75_12_27_test_log_B.CANReceive_o2_f > 0) {
      /* DataTypeConversion: '<S257>/ESP_ABSActiveStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_jzv[0];

      /* S-Function (sfix_bitop): '<S257>/ESP_ABSActiveStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 128U;

      /* ArithShift: '<S257>/ESP_ABSActiveStatus_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 7);

      /* DataTypeConversion: '<S257>/ESP_ABSActiveStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S257>/ESP_ABSActiveStatus_Ad' */
      rtb_ESP_ABSActiveStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S257>/ESP_ABSActiveStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_ABSActiveStatus_sat;
      rtb_ESP_ABSActiveStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S257>/ESP_ABSFailStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_jzv[0];

      /* S-Function (sfix_bitop): '<S257>/ESP_ABSFailStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 8U;

      /* ArithShift: '<S257>/ESP_ABSFailStatus_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 3);

      /* DataTypeConversion: '<S257>/ESP_ABSFailStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S257>/ESP_ABSFailStatus_Ad' */
      rtb_ESP_ABSFailStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S257>/ESP_ABSFailStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_ABSFailStatus_sat;
      rtb_ESP_ABSFailStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S257>/ESP_BrakePedalStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_jzv[6];

      /* S-Function (sfix_bitop): '<S257>/ESP_BrakePedalStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 96U;

      /* ArithShift: '<S257>/ESP_BrakePedalStatus_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 5);

      /* DataTypeConversion: '<S257>/ESP_BrakePedalStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S257>/ESP_BrakePedalStatus_Ad' */
      rtb_ESP_BrakePedalStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S257>/ESP_BrakePedalStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_BrakePedalStatus_sat;
      rtb_ESP_BrakePedalStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S257>/ESP_Checksum_Convert' */
      rtb_ESP_VehicleSpeed_Status_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_jzv[7];

      /* DataTypeConversion: '<S257>/ESP_Checksumcv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S257>/ESP_Checksum_Ad' */
      rtb_ESP_Checksum_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S257>/ESP_Checksum_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_Checksum_sat;
      rtb_ESP_Checksum_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S257>/ESP_EBDFailStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_jzv[0];

      /* S-Function (sfix_bitop): '<S257>/ESP_EBDFailStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 4U;

      /* ArithShift: '<S257>/ESP_EBDFailStatus_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 2);

      /* DataTypeConversion: '<S257>/ESP_EBDFailStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S257>/ESP_EBDFailStatus_Ad' */
      rtb_ESP_EBDFailStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S257>/ESP_EBDFailStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_EBDFailStatus_sat;
      rtb_ESP_EBDFailStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S257>/ESP_ESPActiveStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_jzv[0];

      /* S-Function (sfix_bitop): '<S257>/ESP_ESPActiveStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 1U;

      /* DataTypeConversion: '<S257>/ESP_ESPActiveStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S257>/ESP_ESPActiveStatus_Ad' */
      rtb_ESP_ESPActiveStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S257>/ESP_ESPActiveStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_ESPActiveStatus_sat;
      rtb_ESP_ESPActiveStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S257>/ESP_ESPFailStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_jzv[0];

      /* S-Function (sfix_bitop): '<S257>/ESP_ESPFailStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 16U;

      /* ArithShift: '<S257>/ESP_ESPFailStatus_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 4);

      /* DataTypeConversion: '<S257>/ESP_ESPFailStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S257>/ESP_ESPFailStatus_Ad' */
      rtb_ESP_ESPFailStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S257>/ESP_ESPFailStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_ESPFailStatus_sat;
      rtb_ESP_ESPFailStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S257>/ESP_ESPSwitchStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_jzv[0];

      /* S-Function (sfix_bitop): '<S257>/ESP_ESPSwitchStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 2U;

      /* ArithShift: '<S257>/ESP_ESPSwitchStatus_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 1);

      /* DataTypeConversion: '<S257>/ESP_ESPSwitchStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S257>/ESP_ESPSwitchStatus_Ad' */
      rtb_ESP_ESPSwitchStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S257>/ESP_ESPSwitchStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_ESPSwitchStatus_sat;
      rtb_ESP_ESPSwitchStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S257>/ESP_RollingCounter_Convert' */
      rtb_ESP_VehicleSpeed_Status_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_jzv[6];

      /* S-Function (sfix_bitop): '<S257>/ESP_RollingCounter_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 15U;

      /* DataTypeConversion: '<S257>/ESP_RollingCountercv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S257>/ESP_RollingCounter_Ad' */
      rtb_ESP_RollingCounter_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S257>/ESP_RollingCounter_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_RollingCounter_sat;
      rtb_ESP_RollingCounter_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Product: '<S257>/ESP_VehicleSpeedinput5_P' incorporates:
       *  Constant: '<S257>/ESP_VehicleSpeedinput5_C'
       */
      rtb_ESP_VehicleSpeed_sat = (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_jzv[4] * 256.0;

      /* Sum: '<S257>/ESP_VehicleSpeedinput5_Ad' */
      rtb_ESP_VehicleSpeed_Statuscv = rtb_ESP_VehicleSpeed_sat + (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_jzv[5];

      /* DataTypeConversion: '<S257>/ESP_VehicleSpeed_Convert' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)rtb_ESP_VehicleSpeed_Statuscv;

      /* S-Function (sfix_bitop): '<S257>/ESP_VehicleSpeed_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 8191U;

      /* DataTypeConversion: '<S257>/ESP_VehicleSpeedcv' */
      rtb_ESP_VehicleSpeed_Statuscv = rtb_ESP_VehicleSpeed_Status_L;

      /* Gain: '<S257>/ESP_VehicleSpeed_F' */
      rtb_ESP_VehicleSpeed_Statuscv *= 0.05625;

      /* Sum: '<S257>/ESP_VehicleSpeed_Ad' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Statuscv;

      /* DataTypeConversion: '<S257>/ESP_VehicleSpeed_Status_Convert' */
      rtb_ESP_VehicleSpeed_Status_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_jzv[4];

      /* S-Function (sfix_bitop): '<S257>/ESP_VehicleSpeed_Status_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 32U;

      /* ArithShift: '<S257>/ESP_VehicleSpeed_Status_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 5);

      /* DataTypeConversion: '<S257>/ESP_VehicleSpeed_Statuscv' */
      rtb_ESP_VehicleSpeed_Statuscv = rtb_ESP_VehicleSpeed_Status_L;

      /* Saturate: '<S257>/ESP_VehicleSpeed_sat' */
      if (rtb_ESP_VehicleSpeed_sat > 360.0) {
        rtb_ESP_VehicleSpeed_sat = 360.0;
      }

      /* End of Saturate: '<S257>/ESP_VehicleSpeed_sat' */

      /* SignalConversion: '<S256>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_ESPActiveStatus_n =
        rtb_ESP_ESPActiveStatus_sat;

      /* SignalConversion: '<S256>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_BrakePedalStatus =
        rtb_ESP_BrakePedalStatus_sat;

      /* SignalConversion: '<S256>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_Checksum = rtb_ESP_Checksum_sat;

      /* SignalConversion: '<S256>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_ESPSwitchStatus =
        rtb_ESP_ESPSwitchStatus_sat;

      /* SignalConversion: '<S256>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_EBDFailStatus_l = rtb_ESP_EBDFailStatus_sat;

      /* SignalConversion: '<S256>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_ABSFailStatus = rtb_ESP_ABSFailStatus_sat;

      /* SignalConversion: '<S256>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_ESPFailStatus = rtb_ESP_ESPFailStatus_sat;

      /* SignalConversion: '<S256>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_ABSActiveStatus =
        rtb_ESP_ABSActiveStatus_sat;

      /* SignalConversion: '<S256>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_VehicleSpeed = rtb_ESP_VehicleSpeed_sat;

      /* SignalConversion: '<S256>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_VehicleSpeed_Status =
        rtb_ESP_VehicleSpeed_Statuscv;

      /* SignalConversion: '<S256>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_RollingCounter_p =
        rtb_ESP_RollingCounter_sat;
    }

    /* End of Outputs for SubSystem: '<S255>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S95>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF18RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf18looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_ex= 647;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_hu= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_m2= ec_can_receive(1,18, CAN1BUF18RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_c[0]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_c[1]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_c[2]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_c[3]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_c[4]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_c[5]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_c[6]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_c[7]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
  }

  /* Call the system: <S95>/ReceiveMessages */

  /* Output and update for function-call system: '<S95>/ReceiveMessages' */
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

    /* Outputs for Enabled SubSystem: '<S269>/Subsystem' incorporates:
     *  EnablePort: '<S270>/Enable'
     */
    if (VCU_CS75_12_27_test_log_B.CANReceive_o2_m2 > 0) {
      /* DataTypeConversion: '<S271>/ESP_CheckSum_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_c[7];

      /* S-Function (sfix_bitop): '<S271>/ESP_CheckSum_L' */
      rtb_ESP_YawRate_Status_L &= 15U;

      /* DataTypeConversion: '<S271>/ESP_CheckSumcv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S271>/ESP_CheckSum_Ad' */
      rtb_ESP_CheckSum_sat = (int32_T)rtb_ESP_LongAcceleration_sat;

      /* Saturate: '<S271>/ESP_CheckSum_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_CheckSum_sat;
      rtb_ESP_CheckSum_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* DataTypeConversion: '<S271>/ESP_HBBActiveStatus_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_c[6];

      /* S-Function (sfix_bitop): '<S271>/ESP_HBBActiveStatus_L' */
      rtb_ESP_YawRate_Status_L &= 8U;

      /* ArithShift: '<S271>/ESP_HBBActiveStatus_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        3);

      /* DataTypeConversion: '<S271>/ESP_HBBActiveStatuscv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S271>/ESP_HBBActiveStatus_Ad' */
      rtb_ESP_HBBActiveStatus_sat = (int32_T)rtb_ESP_LongAcceleration_sat;

      /* Saturate: '<S271>/ESP_HBBActiveStatus_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_HBBActiveStatus_sat;
      rtb_ESP_HBBActiveStatus_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* DataTypeConversion: '<S271>/ESP_HBB_Status_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_c[6];

      /* S-Function (sfix_bitop): '<S271>/ESP_HBB_Status_L' */
      rtb_ESP_YawRate_Status_L &= 3U;

      /* DataTypeConversion: '<S271>/ESP_HBB_Statuscv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S271>/ESP_HBB_Status_Ad' */
      rtb_ESP_HBB_Status_sat = (int32_T)rtb_ESP_LongAcceleration_sat;

      /* Saturate: '<S271>/ESP_HBB_Status_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_HBB_Status_sat;
      rtb_ESP_HBB_Status_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* DataTypeConversion: '<S271>/ESP_HDC_Status_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_c[0];

      /* S-Function (sfix_bitop): '<S271>/ESP_HDC_Status_L' */
      rtb_ESP_YawRate_Status_L &= 48U;

      /* ArithShift: '<S271>/ESP_HDC_Status_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        4);

      /* DataTypeConversion: '<S271>/ESP_HDC_Statuscv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S271>/ESP_HDC_Status_Ad' */
      rtb_ESP_HDC_Status_sat = (int32_T)rtb_ESP_LongAcceleration_sat;

      /* Saturate: '<S271>/ESP_HDC_Status_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_HDC_Status_sat;
      rtb_ESP_HDC_Status_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* DataTypeConversion: '<S271>/ESP_HHC_Available_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_c[6];

      /* S-Function (sfix_bitop): '<S271>/ESP_HHC_Available_L' */
      rtb_ESP_YawRate_Status_L &= 4U;

      /* ArithShift: '<S271>/ESP_HHC_Available_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        2);

      /* DataTypeConversion: '<S271>/ESP_HHC_Availablecv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S271>/ESP_HHC_Available_Ad' */
      rtb_ESP_HHC_Available_sat = (int32_T)rtb_ESP_LongAcceleration_sat;

      /* Saturate: '<S271>/ESP_HHC_Available_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_HHC_Available_sat;
      rtb_ESP_HHC_Available_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* DataTypeConversion: '<S271>/ESP_LatAcceleration_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_c[2];

      /* DataTypeConversion: '<S271>/ESP_LatAccelerationcv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Gain: '<S271>/ESP_LatAcceleration_F' */
      rtb_ESP_LongAcceleration_sat *= 0.1;

      /* Sum: '<S271>/ESP_LatAcceleration_Ad' incorporates:
       *  Constant: '<S271>/ESP_LatAcceleration_O'
       */
      rtb_ESP_LatAcceleration_sat = rtb_ESP_LongAcceleration_sat +
        -12.699999809265137;

      /* Saturate: '<S271>/ESP_LatAcceleration_sat' */
      if (rtb_ESP_LatAcceleration_sat > 12.7) {
        rtb_ESP_LatAcceleration_sat = 12.7;
      }

      /* End of Saturate: '<S271>/ESP_LatAcceleration_sat' */

      /* DataTypeConversion: '<S271>/ESP_LongAccelValid_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_c[6];

      /* S-Function (sfix_bitop): '<S271>/ESP_LongAccelValid_L' */
      rtb_ESP_YawRate_Status_L &= 64U;

      /* ArithShift: '<S271>/ESP_LongAccelValid_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        6);

      /* DataTypeConversion: '<S271>/ESP_LongAccelValidcv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S271>/ESP_LongAccelValid_Ad' */
      rtb_ESP_LongAccelValid_sat = (int32_T)rtb_ESP_LongAcceleration_sat;

      /* Saturate: '<S271>/ESP_LongAccelValid_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_LongAccelValid_sat;
      rtb_ESP_LongAccelValid_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* Product: '<S271>/ESP_LongAccelerationinput4_P' incorporates:
       *  Constant: '<S271>/ESP_LongAccelerationinput4_C'
       */
      rtb_ESP_LongAcceleration_sat = (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_c[3] * 256.0;

      /* Sum: '<S271>/ESP_LongAccelerationinput4_Ad' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_LongAcceleration_sat + (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_c[4];

      /* DataTypeConversion: '<S271>/ESP_LongAcceleration_Convert' */
      rtb_ESP_YawRate_Status_L = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* S-Function (sfix_bitop): '<S271>/ESP_LongAcceleration_L' */
      rtb_ESP_YawRate_Status_L &= 65472U;

      /* ArithShift: '<S271>/ESP_LongAcceleration_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        6);

      /* DataTypeConversion: '<S271>/ESP_LongAccelerationcv' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_YawRate_Status_L;

      /* Gain: '<S271>/ESP_LongAcceleration_F' */
      rtb_ESP_TODTorqueMaxLimit_sat *= 0.03125;

      /* Sum: '<S271>/ESP_LongAcceleration_Ad' incorporates:
       *  Constant: '<S271>/ESP_LongAcceleration_O'
       */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_TODTorqueMaxLimit_sat + -16.0;

      /* DataTypeConversion: '<S271>/ESP_RollingCounter_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_c[7];

      /* S-Function (sfix_bitop): '<S271>/ESP_RollingCounter_L' */
      rtb_ESP_YawRate_Status_L &= 240U;

      /* ArithShift: '<S271>/ESP_RollingCounter_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        4);

      /* DataTypeConversion: '<S271>/ESP_RollingCountercv' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S271>/ESP_RollingCounter_Ad' */
      rtb_ESP_RollingCounter_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* Saturate: '<S271>/ESP_RollingCounter_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_RollingCounter_sat;
      rtb_ESP_RollingCounter_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* DataTypeConversion: '<S271>/ESP_TODFastOpenRequest_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_c[0];

      /* S-Function (sfix_bitop): '<S271>/ESP_TODFastOpenRequest_L' */
      rtb_ESP_YawRate_Status_L &= 192U;

      /* ArithShift: '<S271>/ESP_TODFastOpenRequest_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        6);

      /* DataTypeConversion: '<S271>/ESP_TODFastOpenRequestcv' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S271>/ESP_TODFastOpenRequest_Ad' */
      rtb_ESP_TODFastOpenRequest_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* Saturate: '<S271>/ESP_TODFastOpenRequest_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_TODFastOpenRequest_sat;
      rtb_ESP_TODFastOpenRequest_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* Product: '<S271>/ESP_TODTorqueMaxLimitinput1_P' incorporates:
       *  Constant: '<S271>/ESP_TODTorqueMaxLimitinput1_C'
       */
      rtb_ESP_TODTorqueMaxLimit_sat = (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_c[0] * 256.0;

      /* Sum: '<S271>/ESP_TODTorqueMaxLimitinput1_Ad' */
      rtb_ESP_YawRate_sat = rtb_ESP_TODTorqueMaxLimit_sat + (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_c[1];

      /* DataTypeConversion: '<S271>/ESP_TODTorqueMaxLimit_Convert' */
      rtb_ESP_YawRate_Status_L = (int32_T)rtb_ESP_YawRate_sat;

      /* S-Function (sfix_bitop): '<S271>/ESP_TODTorqueMaxLimit_L' */
      rtb_ESP_YawRate_Status_L &= 4095U;

      /* DataTypeConversion: '<S271>/ESP_TODTorqueMaxLimitcv' */
      rtb_ESP_YawRate_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S271>/ESP_TODTorqueMaxLimit_Ad' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_YawRate_sat;

      /* Product: '<S271>/ESP_YawRateinput5_P' incorporates:
       *  Constant: '<S271>/ESP_YawRateinput5_C'
       */
      rtb_ESP_YawRate_sat = (real_T)VCU_CS75_12_27_test_log_B.CANReceive_o4_c[4]
        * 256.0;

      /* Sum: '<S271>/ESP_YawRateinput5_Ad' */
      rtb_ESP_YawRate_Statuscv = rtb_ESP_YawRate_sat + (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_c[5];

      /* DataTypeConversion: '<S271>/ESP_YawRate_Convert' */
      rtb_ESP_YawRate_Status_L = (int32_T)rtb_ESP_YawRate_Statuscv;

      /* S-Function (sfix_bitop): '<S271>/ESP_YawRate_L' */
      rtb_ESP_YawRate_Status_L &= 16383U;

      /* DataTypeConversion: '<S271>/ESP_YawRatecv' */
      rtb_ESP_YawRate_Statuscv = rtb_ESP_YawRate_Status_L;

      /* Gain: '<S271>/ESP_YawRate_F' */
      rtb_ESP_YawRate_Statuscv *= 0.01;

      /* Sum: '<S271>/ESP_YawRate_Ad' incorporates:
       *  Constant: '<S271>/ESP_YawRate_O'
       */
      rtb_ESP_YawRate_sat = rtb_ESP_YawRate_Statuscv + -81.910003662109375;

      /* DataTypeConversion: '<S271>/ESP_YawRate_Status_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_c[6];

      /* S-Function (sfix_bitop): '<S271>/ESP_YawRate_Status_L' */
      rtb_ESP_YawRate_Status_L &= 128U;

      /* ArithShift: '<S271>/ESP_YawRate_Status_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        7);

      /* DataTypeConversion: '<S271>/ESP_YawRate_Statuscv' */
      rtb_ESP_YawRate_Statuscv = rtb_ESP_YawRate_Status_L;

      /* Saturate: '<S271>/ESP_YawRate_sat' */
      if (rtb_ESP_YawRate_sat > 81.91) {
        rtb_ESP_YawRate_sat = 81.91;
      } else {
        if (rtb_ESP_YawRate_sat < -81.91) {
          rtb_ESP_YawRate_sat = -81.91;
        }
      }

      /* End of Saturate: '<S271>/ESP_YawRate_sat' */

      /* SignalConversion: '<S270>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_TODTorqueMaxLimit =
        rtb_ESP_TODTorqueMaxLimit_sat;

      /* SignalConversion: '<S270>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_LongAccelValid = rtb_ESP_LongAccelValid_sat;

      /* SignalConversion: '<S270>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_YawRate_Status = rtb_ESP_YawRate_Statuscv;

      /* SignalConversion: '<S270>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_CheckSum = rtb_ESP_CheckSum_sat;

      /* SignalConversion: '<S270>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_RollingCounter = rtb_ESP_RollingCounter_sat;

      /* SignalConversion: '<S270>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_HDC_Status = rtb_ESP_HDC_Status_sat;

      /* SignalConversion: '<S270>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_TODFastOpenRequest =
        rtb_ESP_TODFastOpenRequest_sat;

      /* SignalConversion: '<S270>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_LatAcceleration =
        rtb_ESP_LatAcceleration_sat;

      /* SignalConversion: '<S270>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_LongAcceleration =
        rtb_ESP_LongAcceleration_sat;

      /* SignalConversion: '<S270>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_YawRate = rtb_ESP_YawRate_sat;

      /* SignalConversion: '<S270>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_HBB_Status = rtb_ESP_HBB_Status_sat;

      /* SignalConversion: '<S270>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_HHC_Available_h = rtb_ESP_HHC_Available_sat;

      /* SignalConversion: '<S270>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_HBBActiveStatus =
        rtb_ESP_HBBActiveStatus_sat;
    }

    /* End of Outputs for SubSystem: '<S269>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S96>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF27RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf27looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_nd= 523;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_dk= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_k= ec_can_receive(1,27, CAN1BUF27RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_og[0]= CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_og[1]= CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_og[2]= CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_og[3]= CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_og[4]= CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_og[5]= CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_og[6]= CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_og[7]= CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
  }

  /* Call the system: <S96>/ReceiveMessages */

  /* Output and update for function-call system: '<S96>/ReceiveMessages' */
  {
    real_T rtb_SAS_SteeringAngle_sat;
    real_T rtb_TCU_ShiftPostionValidcv;
    int32_T rtb_TCU_ShiftPostionValid_L;
    boolean_T rtb_SAS_SteeringAngleROP;
    int32_T rtb_EMS_BrakePedalStatus_sat;
    int32_T rtb_EMS_EngineStartupEnd_sat;
    int32_T rtb_EMS_EngineStatus_sat;
    int32_T rtb_EPB_BrakeLightOnRequest_sat;
    int32_T rtb_EPB_Status_sat_h;
    int32_T rtb_SAS_SteeringAngleValid_sat;
    int32_T rtb_TCU_GearShiftPositon_sat;
    real32_T rtb_SAS_SteeringAnglesubcon;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S285>/Subsystem' incorporates:
     *  EnablePort: '<S286>/Enable'
     */
    if (VCU_CS75_12_27_test_log_B.CANReceive_o2_k > 0) {
      /* Product: '<S287>/SAS_SteeringAngleinput4_P' incorporates:
       *  Constant: '<S287>/SAS_SteeringAngleinput4_C'
       */
      rtb_SAS_SteeringAngle_sat = (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_og[3] * 256.0;

      /* Sum: '<S287>/SAS_SteeringAngleinput4_Ad' */
      rtb_TCU_ShiftPostionValidcv = rtb_SAS_SteeringAngle_sat + (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_og[4];

      /* DataTypeConversion: '<S287>/SAS_SteeringAngle_Convert' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)rtb_TCU_ShiftPostionValidcv;

      /* DataTypeConversion: '<S287>/SAS_SteeringAnglecv' */
      rtb_SAS_SteeringAnglesubcon = (real32_T)rtb_TCU_ShiftPostionValid_L;

      /* RelationalOperator: '<S287>/SAS_SteeringAngleROP' */
      rtb_SAS_SteeringAngleROP = (rtb_SAS_SteeringAnglesubcon >= 32768.0F);

      /* Switch: '<S287>/SAS_SteeringAngleSW' */
      if (rtb_SAS_SteeringAngleROP) {
        /* Sum: '<S287>/SAS_SteeringAnglesubcon' */
        rtb_SAS_SteeringAnglesubcon = 65536.0F - rtb_SAS_SteeringAnglesubcon;

        /* UnaryMinus: '<S287>/SAS_SteeringAngleMinus' */
        rtb_SAS_SteeringAnglesubcon = -rtb_SAS_SteeringAnglesubcon;
      }

      /* End of Switch: '<S287>/SAS_SteeringAngleSW' */

      /* DataTypeConversion: '<S287>/Data Type Conversion' */
      rtb_TCU_ShiftPostionValidcv = rtb_SAS_SteeringAnglesubcon;

      /* DataTypeConversion: '<S287>/EMS_BrakePedalStatus_Convert' */
      rtb_TCU_ShiftPostionValid_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_og[0];

      /* S-Function (sfix_bitop): '<S287>/EMS_BrakePedalStatus_L' */
      rtb_TCU_ShiftPostionValid_L &= 192U;

      /* ArithShift: '<S287>/EMS_BrakePedalStatus_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 6);

      /* DataTypeConversion: '<S287>/EMS_BrakePedalStatuscv' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S287>/EMS_BrakePedalStatus_Ad' */
      rtb_EMS_BrakePedalStatus_sat = (int32_T)rtb_SAS_SteeringAngle_sat;

      /* Saturate: '<S287>/EMS_BrakePedalStatus_sat' */
      u0 = rtb_EMS_BrakePedalStatus_sat;
      rtb_EMS_BrakePedalStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S287>/EMS_EngineStartupEnd_Convert' */
      rtb_TCU_ShiftPostionValid_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_og[1];

      /* S-Function (sfix_bitop): '<S287>/EMS_EngineStartupEnd_L' */
      rtb_TCU_ShiftPostionValid_L &= 48U;

      /* ArithShift: '<S287>/EMS_EngineStartupEnd_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 4);

      /* DataTypeConversion: '<S287>/EMS_EngineStartupEndcv' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S287>/EMS_EngineStartupEnd_Ad' */
      rtb_EMS_EngineStartupEnd_sat = (int32_T)rtb_SAS_SteeringAngle_sat;

      /* Saturate: '<S287>/EMS_EngineStartupEnd_sat' */
      u0 = rtb_EMS_EngineStartupEnd_sat;
      rtb_EMS_EngineStartupEnd_sat = (int32_T)u0;

      /* DataTypeConversion: '<S287>/EMS_EngineStatus_Convert' */
      rtb_TCU_ShiftPostionValid_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_og[0];

      /* S-Function (sfix_bitop): '<S287>/EMS_EngineStatus_L' */
      rtb_TCU_ShiftPostionValid_L &= 48U;

      /* ArithShift: '<S287>/EMS_EngineStatus_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 4);

      /* DataTypeConversion: '<S287>/EMS_EngineStatuscv' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S287>/EMS_EngineStatus_Ad' */
      rtb_EMS_EngineStatus_sat = (int32_T)rtb_SAS_SteeringAngle_sat;

      /* Saturate: '<S287>/EMS_EngineStatus_sat' */
      u0 = rtb_EMS_EngineStatus_sat;
      rtb_EMS_EngineStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S287>/EPB_BrakeLightOnRequest_Convert' */
      rtb_TCU_ShiftPostionValid_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_og[5];

      /* S-Function (sfix_bitop): '<S287>/EPB_BrakeLightOnRequest_L' */
      rtb_TCU_ShiftPostionValid_L &= 6U;

      /* ArithShift: '<S287>/EPB_BrakeLightOnRequest_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 1);

      /* DataTypeConversion: '<S287>/EPB_BrakeLightOnRequestcv' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S287>/EPB_BrakeLightOnRequest_Ad' */
      rtb_EPB_BrakeLightOnRequest_sat = (int32_T)rtb_SAS_SteeringAngle_sat;

      /* Saturate: '<S287>/EPB_BrakeLightOnRequest_sat' */
      u0 = rtb_EPB_BrakeLightOnRequest_sat;
      rtb_EPB_BrakeLightOnRequest_sat = (int32_T)u0;

      /* DataTypeConversion: '<S287>/EPB_Status_Convert' */
      rtb_TCU_ShiftPostionValid_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_og[6];

      /* S-Function (sfix_bitop): '<S287>/EPB_Status_L' */
      rtb_TCU_ShiftPostionValid_L &= 192U;

      /* ArithShift: '<S287>/EPB_Status_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 6);

      /* DataTypeConversion: '<S287>/EPB_Statuscv' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S287>/EPB_Status_Ad' */
      rtb_EPB_Status_sat_h = (int32_T)rtb_SAS_SteeringAngle_sat;

      /* Saturate: '<S287>/EPB_Status_sat' */
      u0 = rtb_EPB_Status_sat_h;
      rtb_EPB_Status_sat_h = (int32_T)u0;

      /* DataTypeConversion: '<S287>/SAS_SteeringAngleValid_Convert' */
      rtb_TCU_ShiftPostionValid_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_og[0];

      /* S-Function (sfix_bitop): '<S287>/SAS_SteeringAngleValid_L' */
      rtb_TCU_ShiftPostionValid_L &= 1U;

      /* DataTypeConversion: '<S287>/SAS_SteeringAngleValidcv' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S287>/SAS_SteeringAngleValid_Ad' */
      rtb_SAS_SteeringAngleValid_sat = (int32_T)rtb_SAS_SteeringAngle_sat;

      /* Saturate: '<S287>/SAS_SteeringAngleValid_sat' */
      u0 = rtb_SAS_SteeringAngleValid_sat;
      rtb_SAS_SteeringAngleValid_sat = (int32_T)u0;

      /* Gain: '<S287>/SAS_SteeringAngle_F' */
      rtb_TCU_ShiftPostionValidcv *= 0.1;

      /* Sum: '<S287>/SAS_SteeringAngle_Ad' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValidcv;

      /* Saturate: '<S287>/SAS_SteeringAngle_sat' */
      if (rtb_SAS_SteeringAngle_sat > 780.0) {
        rtb_SAS_SteeringAngle_sat = 780.0;
      } else {
        if (rtb_SAS_SteeringAngle_sat < -780.0) {
          rtb_SAS_SteeringAngle_sat = -780.0;
        }
      }

      /* End of Saturate: '<S287>/SAS_SteeringAngle_sat' */

      /* DataTypeConversion: '<S287>/TCU_GearShiftPositon_Convert' */
      rtb_TCU_ShiftPostionValid_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_og[5];

      /* S-Function (sfix_bitop): '<S287>/TCU_GearShiftPositon_L' */
      rtb_TCU_ShiftPostionValid_L &= 120U;

      /* ArithShift: '<S287>/TCU_GearShiftPositon_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 3);

      /* DataTypeConversion: '<S287>/TCU_GearShiftPositoncv' */
      rtb_TCU_ShiftPostionValidcv = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S287>/TCU_GearShiftPositon_Ad' */
      rtb_TCU_GearShiftPositon_sat = (int32_T)rtb_TCU_ShiftPostionValidcv;

      /* Saturate: '<S287>/TCU_GearShiftPositon_sat' */
      u0 = rtb_TCU_GearShiftPositon_sat;
      rtb_TCU_GearShiftPositon_sat = (int32_T)u0;

      /* DataTypeConversion: '<S287>/TCU_ShiftPostionValid_Convert' */
      rtb_TCU_ShiftPostionValid_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_og[5];

      /* S-Function (sfix_bitop): '<S287>/TCU_ShiftPostionValid_L' */
      rtb_TCU_ShiftPostionValid_L &= 128U;

      /* ArithShift: '<S287>/TCU_ShiftPostionValid_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 7);

      /* DataTypeConversion: '<S287>/TCU_ShiftPostionValidcv' */
      rtb_TCU_ShiftPostionValidcv = rtb_TCU_ShiftPostionValid_L;

      /* SignalConversion: '<S286>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.SAS_SteeringAngleValid_j =
        rtb_SAS_SteeringAngleValid_sat;

      /* SignalConversion: '<S286>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_EngineStatus = rtb_EMS_EngineStatus_sat;

      /* SignalConversion: '<S286>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_BrakePedalStatus_o =
        rtb_EMS_BrakePedalStatus_sat;

      /* SignalConversion: '<S286>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_EngineStartupEnd =
        rtb_EMS_EngineStartupEnd_sat;

      /* SignalConversion: '<S286>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.SAS_SteeringAngle_h = rtb_SAS_SteeringAngle_sat;

      /* SignalConversion: '<S286>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPB_BrakeLightOnRequest =
        rtb_EPB_BrakeLightOnRequest_sat;

      /* SignalConversion: '<S286>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.TCU_GearShiftPositon =
        rtb_TCU_GearShiftPositon_sat;

      /* SignalConversion: '<S286>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.TCU_ShiftPostionValid =
        rtb_TCU_ShiftPostionValidcv;

      /* SignalConversion: '<S286>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPB_Status = rtb_EPB_Status_sat_h;
    }

    /* End of Outputs for SubSystem: '<S285>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S97>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF29RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf29looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_m= 776;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_io= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_em= ec_can_receive(1,29, CAN1BUF29RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ga[0]= CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ga[1]= CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ga[2]= CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ga[3]= CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ga[4]= CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ga[5]= CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ga[6]= CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ga[7]= CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
  }

  /* Call the system: <S97>/ReceiveMessages */

  /* Output and update for function-call system: '<S97>/ReceiveMessages' */
  {
    int32_T rtb_IP_TotalOdometerinput6_Ad;
    real_T rtb_IP_TotalOdometer_sat;
    uint32_T rtb_IP_TotalOdometer_Convert;

    /* Outputs for Enabled SubSystem: '<S297>/Subsystem' incorporates:
     *  EnablePort: '<S298>/Enable'
     */
    if (VCU_CS75_12_27_test_log_B.CANReceive_o2_em > 0) {
      /* Product: '<S299>/IP_TotalOdometerinput6_P' incorporates:
       *  Constant: '<S299>/IP_TotalOdometerinput6_C'
       */
      rtb_IP_TotalOdometerinput6_Ad =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_ga[5] << 8;

      /* Product: '<S299>/IP_TotalOdometerinput5_P' incorporates:
       *  Constant: '<S299>/IP_TotalOdometerinput5_C'
       */
      rtb_IP_TotalOdometer_sat = (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_ga[4] * 65536.0;

      /* Sum: '<S299>/IP_TotalOdometerinput5_Ad' */
      rtb_IP_TotalOdometer_sat += (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_ga[6];

      /* Sum: '<S299>/IP_TotalOdometerinput6_Ad' */
      rtb_IP_TotalOdometerinput6_Ad += (int32_T)rtb_IP_TotalOdometer_sat;

      /* DataTypeConversion: '<S299>/IP_TotalOdometer_Convert' */
      rtb_IP_TotalOdometer_Convert = (uint32_T)rtb_IP_TotalOdometerinput6_Ad;

      /* DataTypeConversion: '<S299>/IP_TotalOdometercv' */
      rtb_IP_TotalOdometer_sat = rtb_IP_TotalOdometer_Convert;

      /* Gain: '<S299>/IP_TotalOdometer_F' */
      rtb_IP_TotalOdometer_sat *= 0.1;

      /* Saturate: '<S299>/IP_TotalOdometer_sat' */
      if (rtb_IP_TotalOdometer_sat > 999999.0) {
        rtb_IP_TotalOdometer_sat = 999999.0;
      }

      /* End of Saturate: '<S299>/IP_TotalOdometer_sat' */

      /* SignalConversion: '<S298>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.IP_TotalOdometer = rtb_IP_TotalOdometer_sat;
    }

    /* End of Outputs for SubSystem: '<S297>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S98>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF28RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf28looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_l= 818;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_gf= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_kg= ec_can_receive(1,28, CAN1BUF28RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_p[0]= CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_p[1]= CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_p[2]= CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_p[3]= CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_p[4]= CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_p[5]= CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_p[6]= CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_p[7]= CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
  }

  /* Call the system: <S98>/ReceiveMessages */

  /* Output and update for function-call system: '<S98>/ReceiveMessages' */
  {
    real_T rtb_EMS_EngineSpeed_sat;
    real_T rtb_SRS_PassengerBuckleSwitch_h;
    int32_T rtb_SRS_PassengerBuckleSwitch_d;
    int32_T rtb_SAS_SASFailure_sat;
    int32_T rtb_SRS_DriverBuckleSwitchStatu;

    /* Outputs for Enabled SubSystem: '<S301>/Subsystem' incorporates:
     *  EnablePort: '<S302>/Enable'
     */
    if (VCU_CS75_12_27_test_log_B.CANReceive_o2_kg > 0) {
      /* Product: '<S303>/EMS_EngineSpeedinput6_P' incorporates:
       *  Constant: '<S303>/EMS_EngineSpeedinput6_C'
       */
      rtb_EMS_EngineSpeed_sat = (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_p[5] * 256.0;

      /* Sum: '<S303>/EMS_EngineSpeedinput6_Ad' */
      rtb_SRS_PassengerBuckleSwitch_h = rtb_EMS_EngineSpeed_sat + (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_p[6];

      /* DataTypeConversion: '<S303>/EMS_EngineSpeed_Convert' */
      rtb_SRS_PassengerBuckleSwitch_d = (int32_T)rtb_SRS_PassengerBuckleSwitch_h;

      /* DataTypeConversion: '<S303>/EMS_EngineSpeedcv' */
      rtb_SRS_PassengerBuckleSwitch_h = rtb_SRS_PassengerBuckleSwitch_d;

      /* Gain: '<S303>/EMS_EngineSpeed_F' */
      rtb_SRS_PassengerBuckleSwitch_h *= 0.25;

      /* Sum: '<S303>/EMS_EngineSpeed_Ad' */
      rtb_EMS_EngineSpeed_sat = rtb_SRS_PassengerBuckleSwitch_h;

      /* Saturate: '<S303>/EMS_EngineSpeed_sat' */
      if (rtb_EMS_EngineSpeed_sat > 16383.5) {
        rtb_EMS_EngineSpeed_sat = 16383.5;
      }

      /* End of Saturate: '<S303>/EMS_EngineSpeed_sat' */

      /* DataTypeConversion: '<S303>/SAS_SASFailure_Convert' */
      rtb_SRS_PassengerBuckleSwitch_d =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_p[4];

      /* S-Function (sfix_bitop): '<S303>/SAS_SASFailure_L' */
      rtb_SRS_PassengerBuckleSwitch_d &= 16U;

      /* ArithShift: '<S303>/SAS_SASFailure_S' */
      rtb_SRS_PassengerBuckleSwitch_d = (int32_T)((uint32_T)
        rtb_SRS_PassengerBuckleSwitch_d >> 4);

      /* DataTypeConversion: '<S303>/SAS_SASFailurecv' */
      rtb_SRS_PassengerBuckleSwitch_h = rtb_SRS_PassengerBuckleSwitch_d;

      /* Sum: '<S303>/SAS_SASFailure_Ad' */
      rtb_SAS_SASFailure_sat = (int32_T)rtb_SRS_PassengerBuckleSwitch_h;

      /* Saturate: '<S303>/SAS_SASFailure_sat' */
      rtb_SRS_PassengerBuckleSwitch_h = rtb_SAS_SASFailure_sat;
      rtb_SAS_SASFailure_sat = (int32_T)rtb_SRS_PassengerBuckleSwitch_h;

      /* DataTypeConversion: '<S303>/SRS_DriverBuckleSwitchStatus_Convert' */
      rtb_SRS_PassengerBuckleSwitch_d =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_p[3];

      /* S-Function (sfix_bitop): '<S303>/SRS_DriverBuckleSwitchStatus_L' */
      rtb_SRS_PassengerBuckleSwitch_d &= 192U;

      /* ArithShift: '<S303>/SRS_DriverBuckleSwitchStatus_S' */
      rtb_SRS_PassengerBuckleSwitch_d = (int32_T)((uint32_T)
        rtb_SRS_PassengerBuckleSwitch_d >> 6);

      /* DataTypeConversion: '<S303>/SRS_DriverBuckleSwitchStatuscv' */
      rtb_SRS_PassengerBuckleSwitch_h = rtb_SRS_PassengerBuckleSwitch_d;

      /* Sum: '<S303>/SRS_DriverBuckleSwitchStatus_Ad' */
      rtb_SRS_DriverBuckleSwitchStatu = (int32_T)rtb_SRS_PassengerBuckleSwitch_h;

      /* Saturate: '<S303>/SRS_DriverBuckleSwitchStatus_sat' */
      rtb_SRS_PassengerBuckleSwitch_h = rtb_SRS_DriverBuckleSwitchStatu;
      rtb_SRS_DriverBuckleSwitchStatu = (int32_T)rtb_SRS_PassengerBuckleSwitch_h;

      /* DataTypeConversion: '<S303>/SRS_PassengerBuckleSwitchStatus_Convert' */
      rtb_SRS_PassengerBuckleSwitch_d =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_p[3];

      /* S-Function (sfix_bitop): '<S303>/SRS_PassengerBuckleSwitchStatus_L' */
      rtb_SRS_PassengerBuckleSwitch_d &= 48U;

      /* ArithShift: '<S303>/SRS_PassengerBuckleSwitchStatus_S' */
      rtb_SRS_PassengerBuckleSwitch_d = (int32_T)((uint32_T)
        rtb_SRS_PassengerBuckleSwitch_d >> 4);

      /* DataTypeConversion: '<S303>/SRS_PassengerBuckleSwitchStatuscv' */
      rtb_SRS_PassengerBuckleSwitch_h = rtb_SRS_PassengerBuckleSwitch_d;

      /* SignalConversion: '<S302>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.SRS_PassengerBuckleSwitchStatus =
        rtb_SRS_PassengerBuckleSwitch_h;

      /* SignalConversion: '<S302>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.SRS_DriverBuckleSwitchStatus_a =
        rtb_SRS_DriverBuckleSwitchStatu;

      /* SignalConversion: '<S302>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.SAS_SASFailure_f = rtb_SAS_SASFailure_sat;

      /* SignalConversion: '<S302>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_EngineSpeed = rtb_EMS_EngineSpeed_sat;
    }

    /* End of Outputs for SubSystem: '<S301>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S99>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF30RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf30looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_a1= 886;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_f= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_jb= ec_can_receive(1,30, CAN1BUF30RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ef[0]= CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ef[1]= CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ef[2]= CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ef[3]= CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ef[4]= CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ef[5]= CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ef[6]= CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ef[7]= CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
  }

  /* Call the system: <S99>/ReceiveMessages */

  /* Output and update for function-call system: '<S99>/ReceiveMessages' */
  {
    int32_T rtb_EMS_TorqueConstant_L;
    real_T rtb_EMS_FrictionalTorq_sat;
    int32_T rtb_EMS_ConditionIdle_sat;
    int32_T rtb_EMS_EngineFuelCutOff_sat;
    real_T rtb_EMS_TorqueConstant_F;

    /* Outputs for Enabled SubSystem: '<S308>/Subsystem' incorporates:
     *  EnablePort: '<S309>/Enable'
     */
    if (VCU_CS75_12_27_test_log_B.CANReceive_o2_jb > 0) {
      /* DataTypeConversion: '<S310>/EMS_ConditionIdle_Convert' */
      rtb_EMS_TorqueConstant_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_ef[3];

      /* S-Function (sfix_bitop): '<S310>/EMS_ConditionIdle_L' */
      rtb_EMS_TorqueConstant_L &= 128U;

      /* ArithShift: '<S310>/EMS_ConditionIdle_S' */
      rtb_EMS_TorqueConstant_L = (int32_T)((uint32_T)rtb_EMS_TorqueConstant_L >>
        7);

      /* DataTypeConversion: '<S310>/EMS_ConditionIdlecv' */
      rtb_EMS_FrictionalTorq_sat = rtb_EMS_TorqueConstant_L;

      /* Sum: '<S310>/EMS_ConditionIdle_Ad' */
      rtb_EMS_ConditionIdle_sat = (int32_T)rtb_EMS_FrictionalTorq_sat;

      /* Saturate: '<S310>/EMS_ConditionIdle_sat' */
      rtb_EMS_FrictionalTorq_sat = rtb_EMS_ConditionIdle_sat;
      rtb_EMS_ConditionIdle_sat = (int32_T)rtb_EMS_FrictionalTorq_sat;

      /* DataTypeConversion: '<S310>/EMS_EngineFuelCutOff_Convert' */
      rtb_EMS_TorqueConstant_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_ef[3];

      /* S-Function (sfix_bitop): '<S310>/EMS_EngineFuelCutOff_L' */
      rtb_EMS_TorqueConstant_L &= 16U;

      /* ArithShift: '<S310>/EMS_EngineFuelCutOff_S' */
      rtb_EMS_TorqueConstant_L = (int32_T)((uint32_T)rtb_EMS_TorqueConstant_L >>
        4);

      /* DataTypeConversion: '<S310>/EMS_EngineFuelCutOffcv' */
      rtb_EMS_FrictionalTorq_sat = rtb_EMS_TorqueConstant_L;

      /* Sum: '<S310>/EMS_EngineFuelCutOff_Ad' */
      rtb_EMS_EngineFuelCutOff_sat = (int32_T)rtb_EMS_FrictionalTorq_sat;

      /* Saturate: '<S310>/EMS_EngineFuelCutOff_sat' */
      rtb_EMS_FrictionalTorq_sat = rtb_EMS_EngineFuelCutOff_sat;
      rtb_EMS_EngineFuelCutOff_sat = (int32_T)rtb_EMS_FrictionalTorq_sat;

      /* Product: '<S310>/EMS_FrictionalTorqinput2_P' incorporates:
       *  Constant: '<S310>/EMS_FrictionalTorqinput2_C'
       */
      rtb_EMS_FrictionalTorq_sat = (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_ef[1] * 256.0;

      /* Sum: '<S310>/EMS_FrictionalTorqinput2_Ad' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_FrictionalTorq_sat + (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_ef[2];

      /* DataTypeConversion: '<S310>/EMS_FrictionalTorq_Convert' */
      rtb_EMS_TorqueConstant_L = (int32_T)rtb_EMS_TorqueConstant_F;

      /* DataTypeConversion: '<S310>/EMS_FrictionalTorqcv' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_TorqueConstant_L;

      /* Gain: '<S310>/EMS_FrictionalTorq_F' */
      rtb_EMS_TorqueConstant_F *= 0.001526;

      /* Sum: '<S310>/EMS_FrictionalTorq_Ad' */
      rtb_EMS_FrictionalTorq_sat = rtb_EMS_TorqueConstant_F;

      /* DataTypeConversion: '<S310>/EMS_TorqueConstant_Convert' */
      rtb_EMS_TorqueConstant_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_ef[0];

      /* DataTypeConversion: '<S310>/EMS_TorqueConstantcv' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_TorqueConstant_L;

      /* Gain: '<S310>/EMS_TorqueConstant_F' */
      rtb_EMS_TorqueConstant_F *= 10.0;

      /* Saturate: '<S310>/EMS_TorqueConstant_sat' */
      if (rtb_EMS_TorqueConstant_F > 2540.0) {
        rtb_EMS_TorqueConstant_F = 2540.0;
      }

      /* End of Saturate: '<S310>/EMS_TorqueConstant_sat' */

      /* SignalConversion: '<S309>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_TorqueConstant_i = rtb_EMS_TorqueConstant_F;

      /* SignalConversion: '<S309>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_FrictionalTorq = rtb_EMS_FrictionalTorq_sat;

      /* SignalConversion: '<S309>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_EngineFuelCutOff =
        rtb_EMS_EngineFuelCutOff_sat;

      /* SignalConversion: '<S309>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_ConditionIdle = rtb_EMS_ConditionIdle_sat;
    }

    /* End of Outputs for SubSystem: '<S308>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S100>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF31RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf31looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_eu= 930;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_pi= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_mhq= ec_can_receive(1,31,
      CAN1BUF31RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_it[0]= CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_it[1]= CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_it[2]= CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_it[3]= CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_it[4]= CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_it[5]= CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_it[6]= CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_it[7]= CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
  }

  /* Call the system: <S100>/ReceiveMessages */

  /* Output and update for function-call system: '<S100>/ReceiveMessages' */
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

    /* Outputs for Enabled SubSystem: '<S315>/Subsystem' incorporates:
     *  EnablePort: '<S316>/Enable'
     */
    if (VCU_CS75_12_27_test_log_B.CANReceive_o2_mhq > 0) {
      /* DataTypeConversion: '<S317>/ACC_ACCMode_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_it[1];

      /* S-Function (sfix_bitop): '<S317>/ACC_ACCMode_L' */
      rtb_TCU_WNTLamp_L &= 7U;

      /* Sum: '<S317>/ACC_ACCMode_Ad' */
      rtb_ACC_ACCMode_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S317>/ACC_ACCMode_sat' */
      u0 = rtb_ACC_ACCMode_sat;
      rtb_ACC_ACCMode_sat = (int32_T)u0;

      /* DataTypeConversion: '<S317>/EMS_RemindGear_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_it[0];

      /* S-Function (sfix_bitop): '<S317>/EMS_RemindGear_L' */
      rtb_TCU_WNTLamp_L &= 112U;

      /* ArithShift: '<S317>/EMS_RemindGear_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 4);

      /* Sum: '<S317>/EMS_RemindGear_Ad' */
      rtb_EMS_RemindGear_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S317>/EMS_RemindGear_sat' */
      u0 = rtb_EMS_RemindGear_sat;
      rtb_EMS_RemindGear_sat = (int32_T)u0;

      /* DataTypeConversion: '<S317>/EMS_RemindShiftGear_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_it[7];

      /* S-Function (sfix_bitop): '<S317>/EMS_RemindShiftGear_L' */
      rtb_TCU_WNTLamp_L &= 192U;

      /* ArithShift: '<S317>/EMS_RemindShiftGear_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 6);

      /* Sum: '<S317>/EMS_RemindShiftGear_Ad' */
      rtb_EMS_RemindShiftGear_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S317>/EMS_RemindShiftGear_sat' */
      u0 = rtb_EMS_RemindShiftGear_sat;
      rtb_EMS_RemindShiftGear_sat = (int32_T)u0;

      /* DataTypeConversion: '<S317>/EPB_FunctionLamp_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_it[4];

      /* S-Function (sfix_bitop): '<S317>/EPB_FunctionLamp_L' */
      rtb_TCU_WNTLamp_L &= 24U;

      /* ArithShift: '<S317>/EPB_FunctionLamp_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 3);

      /* Sum: '<S317>/EPB_FunctionLamp_Ad' */
      rtb_EPB_FunctionLamp_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S317>/EPB_FunctionLamp_sat' */
      u0 = rtb_EPB_FunctionLamp_sat;
      rtb_EPB_FunctionLamp_sat = (int32_T)u0;

      /* DataTypeConversion: '<S317>/EPB_SwitchPositionValid_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_it[4];

      /* S-Function (sfix_bitop): '<S317>/EPB_SwitchPositionValid_L' */
      rtb_TCU_WNTLamp_L &= 128U;

      /* ArithShift: '<S317>/EPB_SwitchPositionValid_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 7);

      /* Sum: '<S317>/EPB_SwitchPositionValid_Ad' */
      rtb_EPB_SwitchPositionValid_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S317>/EPB_SwitchPositionValid_sat' */
      u0 = rtb_EPB_SwitchPositionValid_sat;
      rtb_EPB_SwitchPositionValid_sat = (int32_T)u0;

      /* DataTypeConversion: '<S317>/EPB_SwitchPosition_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_it[4];

      /* S-Function (sfix_bitop): '<S317>/EPB_SwitchPosition_L' */
      rtb_TCU_WNTLamp_L &= 96U;

      /* ArithShift: '<S317>/EPB_SwitchPosition_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 5);

      /* Sum: '<S317>/EPB_SwitchPosition_Ad' */
      rtb_EPB_SwitchPosition_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S317>/EPB_SwitchPosition_sat' */
      u0 = rtb_EPB_SwitchPosition_sat;
      rtb_EPB_SwitchPosition_sat = (int32_T)u0;

      /* DataTypeConversion: '<S317>/EPB_TextDisplay_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_it[3];

      /* S-Function (sfix_bitop): '<S317>/EPB_TextDisplay_L' */
      rtb_TCU_WNTLamp_L &= 15U;

      /* Sum: '<S317>/EPB_TextDisplay_Ad' */
      rtb_EPB_TextDisplay_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S317>/EPB_TextDisplay_sat' */
      u0 = rtb_EPB_TextDisplay_sat;
      rtb_EPB_TextDisplay_sat = (int32_T)u0;

      /* DataTypeConversion: '<S317>/EPS_EPSFailed_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_it[4];

      /* S-Function (sfix_bitop): '<S317>/EPS_EPSFailed_L' */
      rtb_TCU_WNTLamp_L &= 2U;

      /* ArithShift: '<S317>/EPS_EPSFailed_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 1);

      /* Sum: '<S317>/EPS_EPSFailed_Ad' */
      rtb_EPS_EPSFailed_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S317>/EPS_EPSFailed_sat' */
      u0 = rtb_EPS_EPSFailed_sat;
      rtb_EPS_EPSFailed_sat = (int32_T)u0;

      /* DataTypeConversion: '<S317>/EPS_TorqueAssistMode_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_it[0];

      /* S-Function (sfix_bitop): '<S317>/EPS_TorqueAssistMode_L' */
      rtb_TCU_WNTLamp_L &= 3U;

      /* Sum: '<S317>/EPS_TorqueAssistMode_Ad' */
      rtb_EPS_TorqueAssistMode_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S317>/EPS_TorqueAssistMode_sat' */
      u0 = rtb_EPS_TorqueAssistMode_sat;
      rtb_EPS_TorqueAssistMode_sat = (int32_T)u0;

      /* DataTypeConversion: '<S317>/ESP_AutoHoldActive_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_it[6];

      /* S-Function (sfix_bitop): '<S317>/ESP_AutoHoldActive_L' */
      rtb_TCU_WNTLamp_L &= 4U;

      /* ArithShift: '<S317>/ESP_AutoHoldActive_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 2);

      /* Sum: '<S317>/ESP_AutoHoldActive_Ad' */
      rtb_ESP_AutoHoldActive_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S317>/ESP_AutoHoldActive_sat' */
      u0 = rtb_ESP_AutoHoldActive_sat;
      rtb_ESP_AutoHoldActive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S317>/ESP_AutoHoldAvailable_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_it[6];

      /* S-Function (sfix_bitop): '<S317>/ESP_AutoHoldAvailable_L' */
      rtb_TCU_WNTLamp_L &= 1U;

      /* Sum: '<S317>/ESP_AutoHoldAvailable_Ad' */
      rtb_ESP_AutoHoldAvailable_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S317>/ESP_AutoHoldAvailable_sat' */
      u0 = rtb_ESP_AutoHoldAvailable_sat;
      rtb_ESP_AutoHoldAvailable_sat = (int32_T)u0;

      /* DataTypeConversion: '<S317>/ESP_EBDFailStatus_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_it[3];

      /* S-Function (sfix_bitop): '<S317>/ESP_EBDFailStatus_L' */
      rtb_TCU_WNTLamp_L &= 128U;

      /* ArithShift: '<S317>/ESP_EBDFailStatus_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 7);

      /* Sum: '<S317>/ESP_EBDFailStatus_Ad' */
      rtb_ESP_EBDFailStatus_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S317>/ESP_EBDFailStatus_sat' */
      u0 = rtb_ESP_EBDFailStatus_sat;
      rtb_ESP_EBDFailStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S317>/ESP_ESPActiveStatus_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_it[3];

      /* S-Function (sfix_bitop): '<S317>/ESP_ESPActiveStatus_L' */
      rtb_TCU_WNTLamp_L &= 32U;

      /* ArithShift: '<S317>/ESP_ESPActiveStatus_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 5);

      /* Sum: '<S317>/ESP_ESPActiveStatus_Ad' */
      rtb_ESP_ESPActiveStatus_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S317>/ESP_ESPActiveStatus_sat' */
      u0 = rtb_ESP_ESPActiveStatus_sat;
      rtb_ESP_ESPActiveStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S317>/ESP_ESPFunctionStatus_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_it[3];

      /* S-Function (sfix_bitop): '<S317>/ESP_ESPFunctionStatus_L' */
      rtb_TCU_WNTLamp_L &= 64U;

      /* ArithShift: '<S317>/ESP_ESPFunctionStatus_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 6);

      /* Sum: '<S317>/ESP_ESPFunctionStatus_Ad' */
      rtb_ESP_ESPFunctionStatus_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S317>/ESP_ESPFunctionStatus_sat' */
      u0 = rtb_ESP_ESPFunctionStatus_sat;
      rtb_ESP_ESPFunctionStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S317>/ESP_HBBFunctionStatus_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_it[7];

      /* S-Function (sfix_bitop): '<S317>/ESP_HBBFunctionStatus_L' */
      rtb_TCU_WNTLamp_L &= 6U;

      /* ArithShift: '<S317>/ESP_HBBFunctionStatus_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 1);

      /* Sum: '<S317>/ESP_HBBFunctionStatus_Ad' */
      rtb_ESP_HBBFunctionStatus_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S317>/ESP_HBBFunctionStatus_sat' */
      u0 = rtb_ESP_HBBFunctionStatus_sat;
      rtb_ESP_HBBFunctionStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S317>/ESP_HDC_STATUS_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_it[5];

      /* S-Function (sfix_bitop): '<S317>/ESP_HDC_STATUS_L' */
      rtb_TCU_WNTLamp_L &= 3U;

      /* Sum: '<S317>/ESP_HDC_STATUS_Ad' */
      rtb_ESP_HDC_STATUS_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S317>/ESP_HDC_STATUS_sat' */
      u0 = rtb_ESP_HDC_STATUS_sat;
      rtb_ESP_HDC_STATUS_sat = (int32_T)u0;

      /* DataTypeConversion: '<S317>/ESP_HHC_Active_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_it[6];

      /* S-Function (sfix_bitop): '<S317>/ESP_HHC_Active_L' */
      rtb_TCU_WNTLamp_L &= 2U;

      /* ArithShift: '<S317>/ESP_HHC_Active_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 1);

      /* Sum: '<S317>/ESP_HHC_Active_Ad' */
      rtb_ESP_HHC_Active_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S317>/ESP_HHC_Active_sat' */
      u0 = rtb_ESP_HHC_Active_sat;
      rtb_ESP_HHC_Active_sat = (int32_T)u0;

      /* DataTypeConversion: '<S317>/ESP_HHC_Available_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_it[6];

      /* S-Function (sfix_bitop): '<S317>/ESP_HHC_Available_L' */
      rtb_TCU_WNTLamp_L &= 8U;

      /* ArithShift: '<S317>/ESP_HHC_Available_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 3);

      /* Sum: '<S317>/ESP_HHC_Available_Ad' */
      rtb_ESP_HHC_Available_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S317>/ESP_HHC_Available_sat' */
      u0 = rtb_ESP_HHC_Available_sat;
      rtb_ESP_HHC_Available_sat = (int32_T)u0;

      /* DataTypeConversion: '<S317>/SRS_LeftRearBuckleSwitchSts_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_it[2];

      /* S-Function (sfix_bitop): '<S317>/SRS_LeftRearBuckleSwitchSts_L' */
      rtb_TCU_WNTLamp_L &= 12U;

      /* ArithShift: '<S317>/SRS_LeftRearBuckleSwitchSts_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 2);

      /* Sum: '<S317>/SRS_LeftRearBuckleSwitchSts_Ad' */
      rtb_SRS_LeftRearBuckleSwitchSts = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S317>/SRS_LeftRearBuckleSwitchSts_sat' */
      u0 = rtb_SRS_LeftRearBuckleSwitchSts;
      rtb_SRS_LeftRearBuckleSwitchSts = (int32_T)u0;

      /* DataTypeConversion: '<S317>/SRS_MiddleRearBuckleSwitchSts_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_it[2];

      /* S-Function (sfix_bitop): '<S317>/SRS_MiddleRearBuckleSwitchSts_L' */
      rtb_TCU_WNTLamp_L &= 48U;

      /* ArithShift: '<S317>/SRS_MiddleRearBuckleSwitchSts_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 4);

      /* Sum: '<S317>/SRS_MiddleRearBuckleSwitchSts_Ad' */
      rtb_SRS_MiddleRearBuckleSwitchS = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S317>/SRS_MiddleRearBuckleSwitchSts_sat' */
      u0 = rtb_SRS_MiddleRearBuckleSwitchS;
      rtb_SRS_MiddleRearBuckleSwitchS = (int32_T)u0;

      /* DataTypeConversion: '<S317>/SRS_RightRearBuckleSwitchSts_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_it[2];

      /* S-Function (sfix_bitop): '<S317>/SRS_RightRearBuckleSwitchSts_L' */
      rtb_TCU_WNTLamp_L &= 192U;

      /* ArithShift: '<S317>/SRS_RightRearBuckleSwitchSts_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 6);

      /* Sum: '<S317>/SRS_RightRearBuckleSwitchSts_Ad' */
      rtb_SRS_RightRearBuckleSwitchSt = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S317>/SRS_RightRearBuckleSwitchSts_sat' */
      u0 = rtb_SRS_RightRearBuckleSwitchSt;
      rtb_SRS_RightRearBuckleSwitchSt = (int32_T)u0;

      /* DataTypeConversion: '<S317>/TCU_FailureLamp_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_it[0];

      /* S-Function (sfix_bitop): '<S317>/TCU_FailureLamp_L' */
      rtb_TCU_WNTLamp_L &= 128U;

      /* ArithShift: '<S317>/TCU_FailureLamp_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 7);

      /* Sum: '<S317>/TCU_FailureLamp_Ad' */
      rtb_TCU_FailureLamp_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S317>/TCU_FailureLamp_sat' */
      u0 = rtb_TCU_FailureLamp_sat;
      rtb_TCU_FailureLamp_sat = (int32_T)u0;

      /* DataTypeConversion: '<S317>/TCU_GearForDisplay_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_it[6];

      /* S-Function (sfix_bitop): '<S317>/TCU_GearForDisplay_L' */
      rtb_TCU_WNTLamp_L &= 240U;

      /* ArithShift: '<S317>/TCU_GearForDisplay_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 4);

      /* Sum: '<S317>/TCU_GearForDisplay_Ad' */
      rtb_TCU_GearForDisplay_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S317>/TCU_GearForDisplay_sat' */
      u0 = rtb_TCU_GearForDisplay_sat;
      rtb_TCU_GearForDisplay_sat = (int32_T)u0;

      /* DataTypeConversion: '<S317>/TCU_GearIndication_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_it[7];

      /* S-Function (sfix_bitop): '<S317>/TCU_GearIndication_L' */
      rtb_TCU_WNTLamp_L &= 8U;

      /* ArithShift: '<S317>/TCU_GearIndication_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 3);

      /* Sum: '<S317>/TCU_GearIndication_Ad' */
      rtb_TCU_GearIndication_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S317>/TCU_GearIndication_sat' */
      u0 = rtb_TCU_GearIndication_sat;
      rtb_TCU_GearIndication_sat = (int32_T)u0;

      /* DataTypeConversion: '<S317>/TCU_PWRLamp_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_it[1];

      /* S-Function (sfix_bitop): '<S317>/TCU_PWRLamp_L' */
      rtb_TCU_WNTLamp_L &= 64U;

      /* ArithShift: '<S317>/TCU_PWRLamp_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 6);

      /* Sum: '<S317>/TCU_PWRLamp_Ad' */
      rtb_TCU_PWRLamp_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S317>/TCU_PWRLamp_sat' */
      u0 = rtb_TCU_PWRLamp_sat;
      rtb_TCU_PWRLamp_sat = (int32_T)u0;

      /* DataTypeConversion: '<S317>/TCU_ReqTranTempWarning_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_it[7];

      /* S-Function (sfix_bitop): '<S317>/TCU_ReqTranTempWarning_L' */
      rtb_TCU_WNTLamp_L &= 48U;

      /* ArithShift: '<S317>/TCU_ReqTranTempWarning_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 4);

      /* Sum: '<S317>/TCU_ReqTranTempWarning_Ad' */
      rtb_TCU_ReqTranTempWarning_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S317>/TCU_ReqTranTempWarning_sat' */
      u0 = rtb_TCU_ReqTranTempWarning_sat;
      rtb_TCU_ReqTranTempWarning_sat = (int32_T)u0;

      /* DataTypeConversion: '<S317>/TCU_WNTLamp_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_it[1];

      /* S-Function (sfix_bitop): '<S317>/TCU_WNTLamp_L' */
      rtb_TCU_WNTLamp_L &= 32U;

      /* ArithShift: '<S317>/TCU_WNTLamp_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 5);

      /* Saturate: '<S317>/TCU_WNTLamp_sat' */
      u0 = rtb_TCU_WNTLamp_L;
      rtb_TCU_WNTLamp_L = (int32_T)u0;

      /* SignalConversion: '<S316>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPS_TorqueAssistMode =
        rtb_EPS_TorqueAssistMode_sat;

      /* SignalConversion: '<S316>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPB_TextDisplay = rtb_EPB_TextDisplay_sat;

      /* SignalConversion: '<S316>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_ESPActiveStatus =
        rtb_ESP_ESPActiveStatus_sat;

      /* SignalConversion: '<S316>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_ESPFunctionStatus =
        rtb_ESP_ESPFunctionStatus_sat;

      /* SignalConversion: '<S316>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_EBDFailStatus = rtb_ESP_EBDFailStatus_sat;

      /* SignalConversion: '<S316>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPS_EPSFailed = rtb_EPS_EPSFailed_sat;

      /* SignalConversion: '<S316>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPB_FunctionLamp = rtb_EPB_FunctionLamp_sat;

      /* SignalConversion: '<S316>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPB_SwitchPosition = rtb_EPB_SwitchPosition_sat;

      /* SignalConversion: '<S316>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EPB_SwitchPositionValid =
        rtb_EPB_SwitchPositionValid_sat;

      /* SignalConversion: '<S316>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_HDC_STATUS = rtb_ESP_HDC_STATUS_sat;

      /* SignalConversion: '<S316>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_AutoHoldAvailable =
        rtb_ESP_AutoHoldAvailable_sat;

      /* SignalConversion: '<S316>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_RemindGear = rtb_EMS_RemindGear_sat;

      /* SignalConversion: '<S316>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_HHC_Active = rtb_ESP_HHC_Active_sat;

      /* SignalConversion: '<S316>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_AutoHoldActive = rtb_ESP_AutoHoldActive_sat;

      /* SignalConversion: '<S316>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_HHC_Available = rtb_ESP_HHC_Available_sat;

      /* SignalConversion: '<S316>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.TCU_GearForDisplay = rtb_TCU_GearForDisplay_sat;

      /* SignalConversion: '<S316>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ESP_HBBFunctionStatus =
        rtb_ESP_HBBFunctionStatus_sat;

      /* SignalConversion: '<S316>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.TCU_GearIndication = rtb_TCU_GearIndication_sat;

      /* SignalConversion: '<S316>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.TCU_ReqTranTempWarning =
        rtb_TCU_ReqTranTempWarning_sat;

      /* SignalConversion: '<S316>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.EMS_RemindShiftGear =
        rtb_EMS_RemindShiftGear_sat;

      /* SignalConversion: '<S316>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.TCU_FailureLamp = rtb_TCU_FailureLamp_sat;

      /* SignalConversion: '<S316>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.ACC_ACCMode = rtb_ACC_ACCMode_sat;

      /* SignalConversion: '<S316>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.TCU_WNTLamp = rtb_TCU_WNTLamp_L;

      /* SignalConversion: '<S316>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.TCU_PWRLamp = rtb_TCU_PWRLamp_sat;

      /* SignalConversion: '<S316>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.SRS_LeftRearBuckleSwitchSts =
        rtb_SRS_LeftRearBuckleSwitchSts;

      /* SignalConversion: '<S316>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.SRS_MiddleRearBuckleSwitchSts =
        rtb_SRS_MiddleRearBuckleSwitchS;

      /* SignalConversion: '<S316>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.SRS_RightRearBuckleSwitchSts =
        rtb_SRS_RightRearBuckleSwitchSt;
    }

    /* End of Outputs for SubSystem: '<S315>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S101>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF32RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf32looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_a3= 1383;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_hn= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_nj= ec_can_receive(1,32, CAN1BUF32RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ao[0]= CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ao[1]= CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ao[2]= CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ao[3]= CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ao[4]= CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ao[5]= CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ao[6]= CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ao[7]= CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
  }

  /* Call the system: <S101>/ReceiveMessages */

  /* Output and update for function-call system: '<S101>/ReceiveMessages' */
  {
    int32_T rtb_HU_TunnelLength_L;
    int32_T rtb_HU_Byroad_sat;
    int32_T rtb_HU_EnterTunnelInfo_sat;
    int32_T rtb_HU_NavGuiganceStatus_sat;
    int32_T rtb_HU_TunnelDistance_sat;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S345>/Subsystem' incorporates:
     *  EnablePort: '<S346>/Enable'
     */
    if (VCU_CS75_12_27_test_log_B.CANReceive_o2_nj > 0) {
      /* DataTypeConversion: '<S347>/HU_Byroad_Convert' */
      rtb_HU_TunnelLength_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_ao[4];

      /* S-Function (sfix_bitop): '<S347>/HU_Byroad_L' */
      rtb_HU_TunnelLength_L &= 192U;

      /* ArithShift: '<S347>/HU_Byroad_S' */
      rtb_HU_TunnelLength_L = (int32_T)((uint32_T)rtb_HU_TunnelLength_L >> 6);

      /* Sum: '<S347>/HU_Byroad_Ad' */
      rtb_HU_Byroad_sat = rtb_HU_TunnelLength_L;

      /* Saturate: '<S347>/HU_Byroad_sat' */
      u0 = rtb_HU_Byroad_sat;
      rtb_HU_Byroad_sat = (int32_T)u0;

      /* DataTypeConversion: '<S347>/HU_EnterTunnelInfo_Convert' */
      rtb_HU_TunnelLength_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_ao[0];

      /* S-Function (sfix_bitop): '<S347>/HU_EnterTunnelInfo_L' */
      rtb_HU_TunnelLength_L &= 12U;

      /* ArithShift: '<S347>/HU_EnterTunnelInfo_S' */
      rtb_HU_TunnelLength_L = (int32_T)((uint32_T)rtb_HU_TunnelLength_L >> 2);

      /* Sum: '<S347>/HU_EnterTunnelInfo_Ad' */
      rtb_HU_EnterTunnelInfo_sat = rtb_HU_TunnelLength_L;

      /* Saturate: '<S347>/HU_EnterTunnelInfo_sat' */
      u0 = rtb_HU_EnterTunnelInfo_sat;
      rtb_HU_EnterTunnelInfo_sat = (int32_T)u0;

      /* DataTypeConversion: '<S347>/HU_NavGuiganceStatus_Convert' */
      rtb_HU_TunnelLength_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_ao[5];

      /* S-Function (sfix_bitop): '<S347>/HU_NavGuiganceStatus_L' */
      rtb_HU_TunnelLength_L &= 192U;

      /* ArithShift: '<S347>/HU_NavGuiganceStatus_S' */
      rtb_HU_TunnelLength_L = (int32_T)((uint32_T)rtb_HU_TunnelLength_L >> 6);

      /* Sum: '<S347>/HU_NavGuiganceStatus_Ad' */
      rtb_HU_NavGuiganceStatus_sat = rtb_HU_TunnelLength_L;

      /* Saturate: '<S347>/HU_NavGuiganceStatus_sat' */
      u0 = rtb_HU_NavGuiganceStatus_sat;
      rtb_HU_NavGuiganceStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S347>/HU_TunnelDistance_Convert' */
      rtb_HU_TunnelLength_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_ao[2];

      /* S-Function (sfix_bitop): '<S347>/HU_TunnelDistance_L' */
      rtb_HU_TunnelLength_L &= 252U;

      /* ArithShift: '<S347>/HU_TunnelDistance_S' */
      rtb_HU_TunnelLength_L = (int32_T)((uint32_T)rtb_HU_TunnelLength_L >> 2);

      /* Gain: '<S347>/HU_TunnelDistance_F' */
      rtb_HU_TunnelLength_L *= 10;

      /* Sum: '<S347>/HU_TunnelDistance_Ad' */
      rtb_HU_TunnelDistance_sat = rtb_HU_TunnelLength_L;

      /* Saturate: '<S347>/HU_TunnelDistance_sat' */
      u0 = rtb_HU_TunnelDistance_sat;
      if (u0 > 600.0) {
        u0 = 600.0;
      }

      rtb_HU_TunnelDistance_sat = (int32_T)u0;

      /* End of Saturate: '<S347>/HU_TunnelDistance_sat' */

      /* DataTypeConversion: '<S347>/HU_TunnelLength_Convert' */
      rtb_HU_TunnelLength_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_ao[4];

      /* S-Function (sfix_bitop): '<S347>/HU_TunnelLength_L' */
      rtb_HU_TunnelLength_L &= 63U;

      /* Saturate: '<S347>/HU_TunnelLength_sat' */
      u0 = rtb_HU_TunnelLength_L;
      rtb_HU_TunnelLength_L = (int32_T)u0;

      /* SignalConversion: '<S346>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.HU_EnterTunnelInfo = rtb_HU_EnterTunnelInfo_sat;

      /* SignalConversion: '<S346>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.HU_TunnelDistance = rtb_HU_TunnelDistance_sat;

      /* SignalConversion: '<S346>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.HU_TunnelLength = rtb_HU_TunnelLength_L;

      /* SignalConversion: '<S346>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.HU_Byroad = rtb_HU_Byroad_sat;

      /* SignalConversion: '<S346>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.HU_NavGuiganceStatus =
        rtb_HU_NavGuiganceStatus_sat;
    }

    /* End of Outputs for SubSystem: '<S345>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S102>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF33RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf33looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_f= 1280;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_fx= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_it= ec_can_receive(1,33, CAN1BUF33RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ff[0]= CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ff[1]= CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ff[2]= CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ff[3]= CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ff[4]= CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ff[5]= CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ff[6]= CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_ff[7]= CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
  }

  /* Call the system: <S102>/ReceiveMessages */

  /* Output and update for function-call system: '<S102>/ReceiveMessages' */

  /* Outputs for Enabled SubSystem: '<S353>/Subsystem' incorporates:
   *  EnablePort: '<S354>/Enable'
   */
  if (VCU_CS75_12_27_test_log_B.CANReceive_o2_it > 0) {
    /* SignalConversion: '<S354>/Signal Conversion' */
    VCU_CS75_12_27_test_log_B.GPSCurrentLocationValid = 0.0;
  }

  /* End of Outputs for SubSystem: '<S353>/Subsystem' */

  /* S-Function (ec5744_canreceiveslb): '<S103>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF36RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf36looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_mf= 878;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_pl= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_jj= ec_can_receive(1,36, CAN1BUF36RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_as[0]= CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_as[1]= CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_as[2]= CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_as[3]= CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_as[4]= CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_as[5]= CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_as[6]= CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_as[7]= CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
  }

  /* Call the system: <S103>/ReceiveMessages */

  /* Output and update for function-call system: '<S103>/ReceiveMessages' */
  {
    uint32_T rtb_LAS_RollingCounter_id36E_L;
    int32_T rtb_LAS_LaneEquationStatus_sat;
    int32_T rtb_LAS_CheckSum_id36E_sat;
    real_T rtb_LAS_LaneEquationC1_sat;
    real_T rtb_LAS_LaneEquationC3_sat;
    real_T rtb_LAS_RoadCurvatureFar_sat;
    real_T rtb_LAS_RollingCounter_id36Ecv;
    real_T rtb_LAS_RoadCurvatureNear_sat;

    /* Outputs for Enabled SubSystem: '<S357>/Subsystem' incorporates:
     *  EnablePort: '<S358>/Enable'
     */
    if (VCU_CS75_12_27_test_log_B.CANReceive_o2_jj > 0) {
      /* DataTypeConversion: '<S359>/LAS_CheckSum_id36E_Convert' */
      rtb_LAS_RollingCounter_id36E_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_as[7];

      /* DataTypeConversion: '<S359>/LAS_CheckSum_id36Ecv' */
      rtb_LAS_LaneEquationStatus_sat = (int32_T)rtb_LAS_RollingCounter_id36E_L;

      /* Sum: '<S359>/LAS_CheckSum_id36E_Ad' */
      rtb_LAS_CheckSum_id36E_sat = rtb_LAS_LaneEquationStatus_sat;

      /* Saturate: '<S359>/LAS_CheckSum_id36E_sat' */
      rtb_LAS_RoadCurvatureFar_sat = rtb_LAS_CheckSum_id36E_sat;
      rtb_LAS_CheckSum_id36E_sat = (int32_T)rtb_LAS_RoadCurvatureFar_sat;

      /* Product: '<S359>/LAS_LaneEquationC1input3_P' incorporates:
       *  Constant: '<S359>/LAS_LaneEquationC1input3_C'
       */
      rtb_LAS_LaneEquationStatus_sat =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_as[2] << 8;

      /* Product: '<S359>/LAS_LaneEquationC1input2_P' incorporates:
       *  Constant: '<S359>/LAS_LaneEquationC1input2_C'
       */
      rtb_LAS_LaneEquationC1_sat = (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_as[1] * 65536.0;

      /* Sum: '<S359>/LAS_LaneEquationC1input2_Ad' */
      rtb_LAS_LaneEquationC3_sat = rtb_LAS_LaneEquationC1_sat + (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_as[3];

      /* Sum: '<S359>/LAS_LaneEquationC1input3_Ad' */
      rtb_LAS_LaneEquationStatus_sat += (int32_T)rtb_LAS_LaneEquationC3_sat;

      /* DataTypeConversion: '<S359>/LAS_LaneEquationC1_Convert' */
      rtb_LAS_RollingCounter_id36E_L = (uint32_T)rtb_LAS_LaneEquationStatus_sat;

      /* S-Function (sfix_bitop): '<S359>/LAS_LaneEquationC1_L' */
      rtb_LAS_RollingCounter_id36E_L &= 262080U;

      /* ArithShift: '<S359>/LAS_LaneEquationC1_S' */
      rtb_LAS_RollingCounter_id36E_L >>= 6;

      /* DataTypeConversion: '<S359>/LAS_LaneEquationC1cv' */
      rtb_LAS_LaneEquationC3_sat = rtb_LAS_RollingCounter_id36E_L;

      /* Gain: '<S359>/LAS_LaneEquationC1_F' */
      rtb_LAS_LaneEquationC3_sat *= 0.00048828125;

      /* Sum: '<S359>/LAS_LaneEquationC1_Ad' incorporates:
       *  Constant: '<S359>/LAS_LaneEquationC1_O'
       */
      rtb_LAS_LaneEquationC1_sat = rtb_LAS_LaneEquationC3_sat + -1.0;

      /* Saturate: '<S359>/LAS_LaneEquationC1_sat' */
      if (rtb_LAS_LaneEquationC1_sat > 0.9990234375) {
        rtb_LAS_LaneEquationC1_sat = 0.9990234375;
      }

      /* End of Saturate: '<S359>/LAS_LaneEquationC1_sat' */

      /* Product: '<S359>/LAS_LaneEquationC3input6_P' incorporates:
       *  Constant: '<S359>/LAS_LaneEquationC3input6_C'
       */
      rtb_LAS_LaneEquationC3_sat = (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_as[5] * 256.0;

      /* Product: '<S359>/LAS_LaneEquationC3input5_P' incorporates:
       *  Constant: '<S359>/LAS_LaneEquationC3input5_C'
       */
      rtb_LAS_LaneEquationStatus_sat =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_as[4] * 65536;

      /* Sum: '<S359>/LAS_LaneEquationC3input5_Ad' */
      rtb_LAS_RoadCurvatureFar_sat = rtb_LAS_LaneEquationStatus_sat +
        VCU_CS75_12_27_test_log_B.CANReceive_o4_as[6];

      /* Sum: '<S359>/LAS_LaneEquationC3input6_Ad' */
      rtb_LAS_LaneEquationC3_sat += rtb_LAS_RoadCurvatureFar_sat;

      /* DataTypeConversion: '<S359>/LAS_LaneEquationC3_Convert' */
      rtb_LAS_RollingCounter_id36E_L = (uint32_T)rtb_LAS_LaneEquationC3_sat;

      /* S-Function (sfix_bitop): '<S359>/LAS_LaneEquationC3_L' */
      rtb_LAS_RollingCounter_id36E_L &= 262080U;

      /* ArithShift: '<S359>/LAS_LaneEquationC3_S' */
      rtb_LAS_RollingCounter_id36E_L >>= 6;

      /* DataTypeConversion: '<S359>/LAS_LaneEquationC3cv' */
      rtb_LAS_RoadCurvatureFar_sat = rtb_LAS_RollingCounter_id36E_L;

      /* Gain: '<S359>/LAS_LaneEquationC3_F' */
      rtb_LAS_RoadCurvatureFar_sat *= 4.76837158203125;

      /* Sum: '<S359>/LAS_LaneEquationC3_Ad' incorporates:
       *  Constant: '<S359>/LAS_LaneEquationC3_O'
       */
      rtb_LAS_LaneEquationC3_sat = rtb_LAS_RoadCurvatureFar_sat +
        -0.00097608566284179688;

      /* Saturate: '<S359>/LAS_LaneEquationC3_sat' */
      if (rtb_LAS_LaneEquationC3_sat > 0.000976085662841796) {
        rtb_LAS_LaneEquationC3_sat = 0.000976085662841796;
      } else {
        if (rtb_LAS_LaneEquationC3_sat < -0.000976085662841796) {
          rtb_LAS_LaneEquationC3_sat = -0.000976085662841796;
        }
      }

      /* End of Saturate: '<S359>/LAS_LaneEquationC3_sat' */

      /* DataTypeConversion: '<S359>/LAS_LaneEquationStatus_Convert' */
      rtb_LAS_RollingCounter_id36E_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_as[6];

      /* S-Function (sfix_bitop): '<S359>/LAS_LaneEquationStatus_L' */
      rtb_LAS_RollingCounter_id36E_L &= 48U;

      /* ArithShift: '<S359>/LAS_LaneEquationStatus_S' */
      rtb_LAS_RollingCounter_id36E_L >>= 4;

      /* DataTypeConversion: '<S359>/LAS_LaneEquationStatuscv' */
      rtb_LAS_RoadCurvatureFar_sat = rtb_LAS_RollingCounter_id36E_L;

      /* Sum: '<S359>/LAS_LaneEquationStatus_Ad' */
      rtb_LAS_LaneEquationStatus_sat = (int32_T)rtb_LAS_RoadCurvatureFar_sat;

      /* Saturate: '<S359>/LAS_LaneEquationStatus_sat' */
      rtb_LAS_RoadCurvatureFar_sat = rtb_LAS_LaneEquationStatus_sat;
      rtb_LAS_LaneEquationStatus_sat = (int32_T)rtb_LAS_RoadCurvatureFar_sat;

      /* Product: '<S359>/LAS_RoadCurvatureFarinput1_P' incorporates:
       *  Constant: '<S359>/LAS_RoadCurvatureFarinput1_C'
       */
      rtb_LAS_RoadCurvatureFar_sat = (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_as[0] * 256.0;

      /* Sum: '<S359>/LAS_RoadCurvatureFarinput1_Ad' */
      rtb_LAS_RollingCounter_id36Ecv = rtb_LAS_RoadCurvatureFar_sat + (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_as[1];

      /* DataTypeConversion: '<S359>/LAS_RoadCurvatureFar_Convert' */
      rtb_LAS_RollingCounter_id36E_L = (uint32_T)rtb_LAS_RollingCounter_id36Ecv;

      /* S-Function (sfix_bitop): '<S359>/LAS_RoadCurvatureFar_L' */
      rtb_LAS_RollingCounter_id36E_L &= 508U;

      /* ArithShift: '<S359>/LAS_RoadCurvatureFar_S' */
      rtb_LAS_RollingCounter_id36E_L >>= 2;

      /* DataTypeConversion: '<S359>/LAS_RoadCurvatureFarcv' */
      rtb_LAS_RollingCounter_id36Ecv = rtb_LAS_RollingCounter_id36E_L;

      /* Gain: '<S359>/LAS_RoadCurvatureFar_F' */
      rtb_LAS_RollingCounter_id36Ecv *= 0.0005;

      /* Sum: '<S359>/LAS_RoadCurvatureFar_Ad' incorporates:
       *  Constant: '<S359>/LAS_RoadCurvatureFar_O'
       */
      rtb_LAS_RoadCurvatureFar_sat = rtb_LAS_RollingCounter_id36Ecv +
        -0.029999999329447746;

      /* Saturate: '<S359>/LAS_RoadCurvatureFar_sat' */
      if (rtb_LAS_RoadCurvatureFar_sat > 0.03) {
        rtb_LAS_RoadCurvatureFar_sat = 0.03;
      }

      /* End of Saturate: '<S359>/LAS_RoadCurvatureFar_sat' */

      /* DataTypeConversion: '<S359>/LAS_RoadCurvatureNear_Convert' */
      rtb_LAS_RollingCounter_id36E_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_as[0];

      /* S-Function (sfix_bitop): '<S359>/LAS_RoadCurvatureNear_L' */
      rtb_LAS_RollingCounter_id36E_L &= 254U;

      /* ArithShift: '<S359>/LAS_RoadCurvatureNear_S' */
      rtb_LAS_RollingCounter_id36E_L >>= 1;

      /* DataTypeConversion: '<S359>/LAS_RoadCurvatureNearcv' */
      rtb_LAS_RollingCounter_id36Ecv = rtb_LAS_RollingCounter_id36E_L;

      /* Gain: '<S359>/LAS_RoadCurvatureNear_F' */
      rtb_LAS_RollingCounter_id36Ecv *= 0.0005;

      /* Sum: '<S359>/LAS_RoadCurvatureNear_Ad' incorporates:
       *  Constant: '<S359>/LAS_RoadCurvatureNear_O'
       */
      rtb_LAS_RoadCurvatureNear_sat = rtb_LAS_RollingCounter_id36Ecv +
        -0.029999999329447746;

      /* Saturate: '<S359>/LAS_RoadCurvatureNear_sat' */
      if (rtb_LAS_RoadCurvatureNear_sat > 0.03) {
        rtb_LAS_RoadCurvatureNear_sat = 0.03;
      }

      /* End of Saturate: '<S359>/LAS_RoadCurvatureNear_sat' */

      /* DataTypeConversion: '<S359>/LAS_RollingCounter_id36E_Convert' */
      rtb_LAS_RollingCounter_id36E_L =
        VCU_CS75_12_27_test_log_B.CANReceive_o4_as[6];

      /* S-Function (sfix_bitop): '<S359>/LAS_RollingCounter_id36E_L' */
      rtb_LAS_RollingCounter_id36E_L &= 15U;

      /* DataTypeConversion: '<S359>/LAS_RollingCounter_id36Ecv' */
      rtb_LAS_RollingCounter_id36Ecv = rtb_LAS_RollingCounter_id36E_L;

      /* SignalConversion: '<S358>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.LAS_RoadCurvatureFar =
        rtb_LAS_RoadCurvatureFar_sat;

      /* SignalConversion: '<S358>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.LAS_RoadCurvatureNear =
        rtb_LAS_RoadCurvatureNear_sat;

      /* SignalConversion: '<S358>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.LAS_LaneEquationC1 = rtb_LAS_LaneEquationC1_sat;

      /* SignalConversion: '<S358>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.LAS_LaneEquationC3 = rtb_LAS_LaneEquationC3_sat;

      /* SignalConversion: '<S358>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.LAS_RollingCounter_id36E =
        rtb_LAS_RollingCounter_id36Ecv;

      /* SignalConversion: '<S358>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.LAS_LaneEquationStatus =
        rtb_LAS_LaneEquationStatus_sat;

      /* SignalConversion: '<S358>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.LAS_CheckSum_id36E = rtb_LAS_CheckSum_id36E_sat;
    }

    /* End of Outputs for SubSystem: '<S357>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S104>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF19RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf19looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_ov= 264;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_lw= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_ij= ec_can_receive(1,19, CAN1BUF19RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_gv[0]= CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_gv[1]= CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_gv[2]= CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_gv[3]= CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_gv[4]= CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_gv[5]= CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_gv[6]= CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_gv[7]= CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
  }

  /* Call the system: <S104>/ReceiveMessages */

  /* Output and update for function-call system: '<S104>/ReceiveMessages' */
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

    /* Outputs for Enabled SubSystem: '<S367>/Subsystem' incorporates:
     *  EnablePort: '<S368>/Enable'
     */
    if (VCU_CS75_12_27_test_log_B.CANReceive_o2_ij > 0) {
      /* Product: '<S369>/SAS_SteeringAngleinput1_P' incorporates:
       *  Constant: '<S369>/SAS_SteeringAngleinput1_C'
       */
      rtb_SAS_SteeringAngle_Ad = (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_gv[0] * 256.0;

      /* Sum: '<S369>/SAS_SteeringAngleinput1_Ad' */
      rtb_SAS_SteeringAngle_F = rtb_SAS_SteeringAngle_Ad + (real_T)
        VCU_CS75_12_27_test_log_B.CANReceive_o4_gv[1];

      /* DataTypeConversion: '<S369>/SAS_SteeringAngle_Convert' */
      rtb_SAS_SteeringAngleValid_L = (int32_T)rtb_SAS_SteeringAngle_F;

      /* DataTypeConversion: '<S369>/SAS_SteeringAnglecv' */
      rtb_SAS_SteeringAnglesubcon = (real32_T)rtb_SAS_SteeringAngleValid_L;

      /* RelationalOperator: '<S369>/SAS_SteeringAngleROP' */
      rtb_SAS_SteeringAngleROP = (rtb_SAS_SteeringAnglesubcon >= 32768.0F);

      /* Switch: '<S369>/SAS_SteeringAngleSW' */
      if (rtb_SAS_SteeringAngleROP) {
        /* Sum: '<S369>/SAS_SteeringAnglesubcon' */
        rtb_SAS_SteeringAnglesubcon = 65536.0F - rtb_SAS_SteeringAnglesubcon;

        /* UnaryMinus: '<S369>/SAS_SteeringAngleMinus' */
        rtb_SAS_SteeringAnglesubcon = -rtb_SAS_SteeringAnglesubcon;
      }

      /* End of Switch: '<S369>/SAS_SteeringAngleSW' */

      /* DataTypeConversion: '<S369>/Data Type Conversion' */
      rtb_SAS_SteeringAngle_F = rtb_SAS_SteeringAnglesubcon;

      /* DataTypeConversion: '<S369>/SAS_CRCCheck_Convert' */
      rtb_SAS_SteeringAngleValid_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_gv
        [7];

      /* DataTypeConversion: '<S369>/SAS_CRCCheckcv' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;

      /* Sum: '<S369>/SAS_CRCCheck_Ad' */
      rtb_SAS_CRCCheck_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Saturate: '<S369>/SAS_CRCCheck_sat' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_CRCCheck_sat;
      rtb_SAS_CRCCheck_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* DataTypeConversion: '<S369>/SAS_Calibrated_Convert' */
      rtb_SAS_SteeringAngleValid_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_gv
        [3];

      /* S-Function (sfix_bitop): '<S369>/SAS_Calibrated_L' */
      rtb_SAS_SteeringAngleValid_L &= 32U;

      /* ArithShift: '<S369>/SAS_Calibrated_S' */
      rtb_SAS_SteeringAngleValid_L = (int32_T)((uint32_T)
        rtb_SAS_SteeringAngleValid_L >> 5);

      /* DataTypeConversion: '<S369>/SAS_Calibratedcv' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;

      /* Sum: '<S369>/SAS_Calibrated_Ad' */
      rtb_SAS_Calibrated_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Saturate: '<S369>/SAS_Calibrated_sat' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_Calibrated_sat;
      rtb_SAS_Calibrated_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* DataTypeConversion: '<S369>/SAS_RollingCounter_Convert' */
      rtb_SAS_SteeringAngleValid_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_gv
        [6];

      /* S-Function (sfix_bitop): '<S369>/SAS_RollingCounter_L' */
      rtb_SAS_SteeringAngleValid_L &= 15U;

      /* DataTypeConversion: '<S369>/SAS_RollingCountercv' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;

      /* Sum: '<S369>/SAS_RollingCounter_Ad' */
      rtb_SAS_RollingCounter_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Saturate: '<S369>/SAS_RollingCounter_sat' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_RollingCounter_sat;
      rtb_SAS_RollingCounter_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* DataTypeConversion: '<S369>/SAS_SASFailure_Convert' */
      rtb_SAS_SteeringAngleValid_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_gv
        [3];

      /* S-Function (sfix_bitop): '<S369>/SAS_SASFailure_L' */
      rtb_SAS_SteeringAngleValid_L &= 64U;

      /* ArithShift: '<S369>/SAS_SASFailure_S' */
      rtb_SAS_SteeringAngleValid_L = (int32_T)((uint32_T)
        rtb_SAS_SteeringAngleValid_L >> 6);

      /* DataTypeConversion: '<S369>/SAS_SASFailurecv' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;

      /* Sum: '<S369>/SAS_SASFailure_Ad' */
      rtb_SAS_SASFailure_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Saturate: '<S369>/SAS_SASFailure_sat' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SASFailure_sat;
      rtb_SAS_SASFailure_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* DataTypeConversion: '<S369>/SAS_SteeringAngleSpeed_Convert' */
      rtb_SAS_SteeringAngleValid_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_gv
        [2];

      /* DataTypeConversion: '<S369>/SAS_SteeringAngleSpeedcv' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;

      /* Gain: '<S369>/SAS_SteeringAngleSpeed_F' */
      rtb_SAS_SteeringAngle_Ad *= 4.0;

      /* Sum: '<S369>/SAS_SteeringAngleSpeed_Ad' */
      rtb_SAS_SteeringAngleSpeed_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Saturate: '<S369>/SAS_SteeringAngleSpeed_sat' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleSpeed_sat;
      rtb_SAS_SteeringAngleSpeed_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* DataTypeConversion: '<S369>/SAS_SteeringAngleValid_Convert' */
      rtb_SAS_SteeringAngleValid_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_gv
        [3];

      /* S-Function (sfix_bitop): '<S369>/SAS_SteeringAngleValid_L' */
      rtb_SAS_SteeringAngleValid_L &= 128U;

      /* ArithShift: '<S369>/SAS_SteeringAngleValid_S' */
      rtb_SAS_SteeringAngleValid_L = (int32_T)((uint32_T)
        rtb_SAS_SteeringAngleValid_L >> 7);

      /* DataTypeConversion: '<S369>/SAS_SteeringAngleValidcv' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;

      /* Sum: '<S369>/SAS_SteeringAngleValid_Ad' */
      rtb_SAS_SteeringAngleValid_L = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Saturate: '<S369>/SAS_SteeringAngleValid_sat' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;
      rtb_SAS_SteeringAngleValid_L = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Gain: '<S369>/SAS_SteeringAngle_F' */
      rtb_SAS_SteeringAngle_F *= 0.1;

      /* Sum: '<S369>/SAS_SteeringAngle_Ad' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngle_F;

      /* Saturate: '<S369>/SAS_SteeringAngle_sat' */
      if (rtb_SAS_SteeringAngle_Ad > 780.0) {
        SAS_SteeringAngle = 780.0;
      } else if (rtb_SAS_SteeringAngle_Ad < -780.0) {
        SAS_SteeringAngle = -780.0;
      } else {
        SAS_SteeringAngle = rtb_SAS_SteeringAngle_Ad;
      }

      /* End of Saturate: '<S369>/SAS_SteeringAngle_sat' */

      /* SignalConversion: '<S368>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.SAS_SteeringAngle_k = SAS_SteeringAngle;

      /* SignalConversion: '<S368>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.SAS_SteeringAngleSpeed =
        rtb_SAS_SteeringAngleSpeed_sat;

      /* SignalConversion: '<S368>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.SAS_Calibrated = rtb_SAS_Calibrated_sat;

      /* SignalConversion: '<S368>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.SAS_SASFailure = rtb_SAS_SASFailure_sat;

      /* SignalConversion: '<S368>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.SAS_SteeringAngleValid =
        rtb_SAS_SteeringAngleValid_L;

      /* SignalConversion: '<S368>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.SAS_RollingCounter = rtb_SAS_RollingCounter_sat;

      /* SignalConversion: '<S368>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.SAS_CRCCheck = rtb_SAS_CRCCheck_sat;
    }

    /* End of Outputs for SubSystem: '<S367>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S105>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF20RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf20looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_b= 952;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_or= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_e2= ec_can_receive(1,20, CAN1BUF20RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_hb[0]= CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_hb[1]= CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_hb[2]= CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_hb[3]= CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_hb[4]= CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_hb[5]= CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_hb[6]= CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_hb[7]= CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
  }

  /* Call the system: <S105>/ReceiveMessages */

  /* Output and update for function-call system: '<S105>/ReceiveMessages' */

  /* Outputs for Enabled SubSystem: '<S377>/Subsystem' incorporates:
   *  EnablePort: '<S378>/Enable'
   */
  if (VCU_CS75_12_27_test_log_B.CANReceive_o2_e2 > 0) {
    /* SignalConversion: '<S378>/Signal Conversion' */
    VCU_CS75_12_27_test_log_B.SCM_ACCOn = 0.0;

    /* SignalConversion: '<S378>/Signal Conversion' */
    VCU_CS75_12_27_test_log_B.SCM_ACCCancel = 0.0;

    /* SignalConversion: '<S378>/Signal Conversion' */
    VCU_CS75_12_27_test_log_B.SCM_Resume = 0.0;

    /* SignalConversion: '<S378>/Signal Conversion' */
    VCU_CS75_12_27_test_log_B.SCM_Speeddecrease = 0.0;

    /* SignalConversion: '<S378>/Signal Conversion' */
    VCU_CS75_12_27_test_log_B.SCM_TimeGap = 0.0;

    /* SignalConversion: '<S378>/Signal Conversion' */
    VCU_CS75_12_27_test_log_B.SCM_IACCOn = 0.0;
  }

  /* End of Outputs for SubSystem: '<S377>/Subsystem' */

  /* S-Function (ec5744_canreceiveslb): '<S106>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF21RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf21looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_hy= 5;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_bt= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_pe= ec_can_receive(1,21, CAN1BUF21RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_kv[0]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_kv[1]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_kv[2]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_kv[3]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_kv[4]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_kv[5]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_kv[6]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_kv[7]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
  }

  /* Call the system: <S106>/ReceiveMessages */

  /* Output and update for function-call system: '<S106>/ReceiveMessages' */
  {
    int32_T rtb_SRS_RollingCounter_L;
    int32_T rtb_SRS_DriverBuckleSwitchStatu;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S386>/Subsystem' incorporates:
     *  EnablePort: '<S387>/Enable'
     */
    if (VCU_CS75_12_27_test_log_B.CANReceive_o2_pe > 0) {
      /* DataTypeConversion: '<S388>/SRS_DriverBuckleSwitchStatus_Convert' */
      rtb_SRS_RollingCounter_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_kv[1];

      /* S-Function (sfix_bitop): '<S388>/SRS_DriverBuckleSwitchStatus_L' */
      rtb_SRS_RollingCounter_L &= 192U;

      /* ArithShift: '<S388>/SRS_DriverBuckleSwitchStatus_S' */
      rtb_SRS_RollingCounter_L = (int32_T)((uint32_T)rtb_SRS_RollingCounter_L >>
        6);

      /* Sum: '<S388>/SRS_DriverBuckleSwitchStatus_Ad' */
      rtb_SRS_DriverBuckleSwitchStatu = rtb_SRS_RollingCounter_L;

      /* Saturate: '<S388>/SRS_DriverBuckleSwitchStatus_sat' */
      u0 = rtb_SRS_DriverBuckleSwitchStatu;
      rtb_SRS_DriverBuckleSwitchStatu = (int32_T)u0;

      /* DataTypeConversion: '<S388>/SRS_RollingCounter_Convert' */
      rtb_SRS_RollingCounter_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_kv[3];

      /* S-Function (sfix_bitop): '<S388>/SRS_RollingCounter_L' */
      rtb_SRS_RollingCounter_L &= 15U;

      /* Saturate: '<S388>/SRS_RollingCounter_sat' */
      u0 = rtb_SRS_RollingCounter_L;
      rtb_SRS_RollingCounter_L = (int32_T)u0;

      /* SignalConversion: '<S387>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.SRS_DriverBuckleSwitchStatus =
        rtb_SRS_DriverBuckleSwitchStatu;

      /* SignalConversion: '<S387>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.SRS_RollingCounter = rtb_SRS_RollingCounter_L;
    }

    /* End of Outputs for SubSystem: '<S386>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S107>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF22RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf22looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_i4= 646;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_px= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_bp= ec_can_receive(1,22, CAN1BUF22RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_m[0]= CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_m[1]= CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_m[2]= CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_m[3]= CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_m[4]= CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_m[5]= CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_m[6]= CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_m[7]= CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
  }

  /* Call the system: <S107>/ReceiveMessages */

  /* Output and update for function-call system: '<S107>/ReceiveMessages' */
  {
    int32_T rtb_TCU_GearShiftPosition_L;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S391>/Subsystem' incorporates:
     *  EnablePort: '<S392>/Enable'
     */
    if (VCU_CS75_12_27_test_log_B.CANReceive_o2_bp > 0) {
      /* DataTypeConversion: '<S393>/TCU_ActualGear_Convert' */
      rtb_TCU_GearShiftPosition_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_m[1];

      /* S-Function (sfix_bitop): '<S393>/TCU_ActualGear_L' */
      rtb_TCU_GearShiftPosition_L &= 15U;

      /* Saturate: '<S393>/TCU_ActualGear_sat' */
      u0 = rtb_TCU_GearShiftPosition_L;
      rtb_TCU_GearShiftPosition_L = (int32_T)u0;

      /* SignalConversion: '<S392>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.TCU_ActualGear = rtb_TCU_GearShiftPosition_L;

      /* DataTypeConversion: '<S393>/TCU_ShiftPositionValid_Convert' */
      rtb_TCU_GearShiftPosition_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_m[1];

      /* S-Function (sfix_bitop): '<S393>/TCU_ShiftPositionValid_L' */
      rtb_TCU_GearShiftPosition_L &= 16U;

      /* ArithShift: '<S393>/TCU_ShiftPositionValid_S' */
      rtb_TCU_GearShiftPosition_L = (int32_T)((uint32_T)
        rtb_TCU_GearShiftPosition_L >> 4);

      /* Saturate: '<S393>/TCU_ShiftPositionValid_sat' */
      u0 = rtb_TCU_GearShiftPosition_L;
      rtb_TCU_GearShiftPosition_L = (int32_T)u0;

      /* SignalConversion: '<S392>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.TCU_ShiftPositionValid =
        rtb_TCU_GearShiftPosition_L;

      /* DataTypeConversion: '<S393>/TCU_ActualGearValid_Convert' */
      rtb_TCU_GearShiftPosition_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_m[1];

      /* S-Function (sfix_bitop): '<S393>/TCU_ActualGearValid_L' */
      rtb_TCU_GearShiftPosition_L &= 32U;

      /* ArithShift: '<S393>/TCU_ActualGearValid_S' */
      rtb_TCU_GearShiftPosition_L = (int32_T)((uint32_T)
        rtb_TCU_GearShiftPosition_L >> 5);

      /* Saturate: '<S393>/TCU_ActualGearValid_sat' */
      u0 = rtb_TCU_GearShiftPosition_L;
      rtb_TCU_GearShiftPosition_L = (int32_T)u0;

      /* SignalConversion: '<S392>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.TCU_ActualGearValid =
        rtb_TCU_GearShiftPosition_L;

      /* DataTypeConversion: '<S393>/TCU_GearShiftPosition_Convert' */
      rtb_TCU_GearShiftPosition_L = VCU_CS75_12_27_test_log_B.CANReceive_o4_m[2];

      /* S-Function (sfix_bitop): '<S393>/TCU_GearShiftPosition_L' */
      rtb_TCU_GearShiftPosition_L &= 240U;

      /* ArithShift: '<S393>/TCU_GearShiftPosition_S' */
      rtb_TCU_GearShiftPosition_L = (int32_T)((uint32_T)
        rtb_TCU_GearShiftPosition_L >> 4);

      /* Saturate: '<S393>/TCU_GearShiftPosition_sat' */
      u0 = rtb_TCU_GearShiftPosition_L;
      rtb_TCU_GearShiftPosition_L = (int32_T)u0;

      /* SignalConversion: '<S392>/Signal Conversion' */
      VCU_CS75_12_27_test_log_B.TCU_GearShiftPosition =
        rtb_TCU_GearShiftPosition_L;
    }

    /* End of Outputs for SubSystem: '<S391>/Subsystem' */
  }

  /* End of Outputs for SubSystem: '<S2>/Input' */

  /* Outputs for Atomic SubSystem: '<S2>/APP' */
  /* Inport: '<S24>/APP_Input' */
  rtb_APP_Input_idx_0 = VCU_CS75_12_27_test_log_B.AutoDrivingReady;
  rtb_APP_Input_idx_1 = VCU_CS75_12_27_test_log_B.RemoteAcclPosition;
  rtb_APP_Input_idx_2 = VCU_CS75_12_27_test_log_B.LaterlAngleCommand;
  rtb_APP_Input_idx_3 = VCU_CS75_12_27_test_log_B.A1_Message_Counter;
  rtb_APP_Input_idx_8 = VCU_CS75_12_27_test_log_B.EMS_FrictionalTorq_d;
  rtb_APP_Input_idx_9 = VCU_CS75_12_27_test_log_B.EMS_IndicatedRealEngTorq;
  rtb_APP_Input_idx_12 = VCU_CS75_12_27_test_log_B.EMS_BrakePedalStatus_l;
  rtb_APP_Input_idx_17 = VCU_CS75_12_27_test_log_B.EMS_RollingCounter_id255;
  rtb_APP_Input_idx_19 = VCU_CS75_12_27_test_log_B.EMS_FullLoadIndicatedTorq;
  rtb_APP_Input_idx_20 = VCU_CS75_12_27_test_log_B.EMS_TorqueConstant_c;
  rtb_APP_Input_idx_29 = VCU_CS75_12_27_test_log_B.EPS_EPSFailed_k;
  rtb_APP_Input_idx_39 = VCU_CS75_12_27_test_log_B.EPS_AvailabilityStatus_a;
  rtb_APP_Input_idx_63 = VCU_CS75_12_27_test_log_B.Wheel_Speed_RR;
  rtb_APP_Input_idx_66 = VCU_CS75_12_27_test_log_B.Wheel_Speed_RL;
  rtb_APP_Input_idx_79 = VCU_CS75_12_27_test_log_B.ESP_ESPFailStatus;
  rtb_APP_Input_idx_90 = VCU_CS75_12_27_test_log_B.ESP_LongAcceleration;
  rtb_APP_Input_idx_99 = VCU_CS75_12_27_test_log_B.SAS_SteeringAngle_k;
  rtb_APP_Input_idx_217 = P6_Value;

  /* MATLAB Function: '<S55>/MATLAB Function2' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Monitor/Vehicle_Status/MATLAB Function2': '<S58>:1' */
  if ((rtb_APP_Input_idx_29 == 1.0) || (rtb_APP_Input_idx_79 == 1.0)) {
    /* '<S58>:1:2' */
    /* '<S58>:1:3' */
    VehicleFaultStatus = 1.0;
  } else {
    /* '<S58>:1:5' */
    VehicleFaultStatus = 0.0;
  }

  /* End of MATLAB Function: '<S55>/MATLAB Function2' */

  /* Memory: '<S55>/Memory3' */
  rtb_P6_Value = VCU_CS75_12_27_test_log_DW.Memory3_PreviousInput;

  /* Memory: '<S55>/Memory2' */
  rtb_Memory2 = VCU_CS75_12_27_test_log_DW.Memory2_PreviousInput;

  /* MATLAB Function: '<S55>/MATLAB Function4' incorporates:
   *  Constant: '<S55>/1s'
   */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Monitor/Vehicle_Status/MATLAB Function4': '<S59>:1' */
  if (rtb_APP_Input_idx_17 == rtb_P6_Value) {
    /* '<S59>:1:2' */
    /* '<S59>:1:3' */
    rtb_P6_Value = rtb_Memory2 + 1.0;
  } else {
    /* '<S59>:1:5' */
    rtb_P6_Value = 0.0;
  }

  if (rtb_P6_Value * 20.0 > 1000.0) {
    /* '<S59>:1:7' */
    /* '<S59>:1:8' */
    VehicleCommunicationStatus = 0.0;
  } else {
    /* '<S59>:1:10' */
    VehicleCommunicationStatus = 1.0;
  }

  counter1 = rtb_P6_Value;

  /* End of MATLAB Function: '<S55>/MATLAB Function4' */

  /* DataTypeConversion: '<S55>/Data Type Conversion' */
  EPS_AvailabilityStatus = rtb_APP_Input_idx_39;

  /* Constant: '<S53>/Constant' */
  Server_CommunicationStatus = 1.0;

  /* Chart: '<S29>/Chart' */
  /* Gateway: 长安CS75底盘程序，20ms一次/APP/System_State_Manager/Chart */
  /* During: 长安CS75底盘程序，20ms一次/APP/System_State_Manager/Chart */
  if (VCU_CS75_12_27_test_log_DW.bitsForTID4.is_active_c4_VCU_CS75_12_27_tes ==
      0U) {
    /* Entry: 长安CS75底盘程序，20ms一次/APP/System_State_Manager/Chart */
    VCU_CS75_12_27_test_log_DW.bitsForTID4.is_active_c4_VCU_CS75_12_27_tes = 1U;

    /* Entry Internal: 长安CS75底盘程序，20ms一次/APP/System_State_Manager/Chart */
    VCU_CS75_12_27_test_log_DW.bitsForTID4.is_c4_VCU_CS75_12_27_test_log =
      VCU_CS75_12_27__IN_System_State;

    /* Entry Internal 'System_State': '<S60>:16' */
    /* Transition: '<S60>:11' */
    VCU_CS75_12_27_test_log_DW.bitsForTID4.is_System_State =
      VCU_CS75__IN_INIT_ManualDriving;

    /* Entry 'INIT_ManualDriving': '<S60>:7' */
    /* 驾驶员正常驾驶 */
    System_State = 0.0;
  } else {
    /* During 'System_State': '<S60>:16' */
    switch (VCU_CS75_12_27_test_log_DW.bitsForTID4.is_System_State) {
     case VCU_CS75_12_27_t_IN_AutoDriving:
      /* During 'AutoDriving': '<S60>:8' */
      rtb_ErrorSum_LogROP = ((VehicleFaultStatus == 1.0) ||
        (VehicleCommunicationStatus == 0.0) || (Server_CommunicationStatus ==
        0.0));
      if (rtb_ErrorSum_LogROP) {
        /* Transition: '<S60>:27' */
        VCU_CS75_12_27_test_log_DW.bitsForTID4.is_System_State =
          VCU_CS75_12_27_test_lo_IN_Error;

        /* Entry 'Error': '<S60>:10' */
        /* 故障，需人工接管 */
        System_State = 3.0;
      } else if (rtb_APP_Input_idx_12 == 1.0) {
        /* Transition: '<S60>:28' */
        VCU_CS75_12_27_test_log_DW.bitsForTID4.is_System_State =
          VCU_CS75_12_27_test_IN_TakeOver;

        /* Entry 'TakeOver': '<S60>:9' */
        /* 人工接管模式 */
        System_State = 2.0;
      } else if (rtb_APP_Input_idx_0 == 0.0) {
        /* Transition: '<S60>:31' */
        /* %&&Switch_P6 == 0 */
        VCU_CS75_12_27_test_log_DW.bitsForTID4.is_System_State =
          VCU_CS75__IN_INIT_ManualDriving;

        /* Entry 'INIT_ManualDriving': '<S60>:7' */
        /* 驾驶员正常驾驶 */
        System_State = 0.0;
      } else {
        System_State = 1.0;
      }
      break;

     case VCU_CS75_12_27_test_lo_IN_Error:
      /* During 'Error': '<S60>:10' */
      rtb_ErrorSum_LogROP = ((rtb_APP_Input_idx_0 == 0.0) &&
        (rtb_APP_Input_idx_217 == 0.0) && (VehicleCommunicationStatus == 1.0) &&
                             (VehicleFaultStatus == 0.0));
      if (rtb_ErrorSum_LogROP) {
        /* Transition: '<S60>:35' */
        /* %&& Server_CommunicationStatus == 1 */
        VCU_CS75_12_27_test_log_DW.bitsForTID4.is_System_State =
          VCU_CS75__IN_INIT_ManualDriving;

        /* Entry 'INIT_ManualDriving': '<S60>:7' */
        /* 驾驶员正常驾驶 */
        System_State = 0.0;
      } else {
        System_State = 3.0;
      }
      break;

     case VCU_CS75__IN_INIT_ManualDriving:
      /* During 'INIT_ManualDriving': '<S60>:7' */
      rtb_ErrorSum_LogROP = ((rtb_APP_Input_idx_0 == 1.0) &&
        (Server_CommunicationStatus == 1.0) && (rtb_APP_Input_idx_12 == 0.0) &&
                             (VehicleCommunicationStatus == 1.0) &&
        (VehicleFaultStatus == 0.0));
      if (rtb_ErrorSum_LogROP) {
        /* Transition: '<S60>:18' */
        /* % &&Switch_P6 == 1&&EPS_AvailabilityStatus == 2 */
        VCU_CS75_12_27_test_log_DW.bitsForTID4.is_System_State =
          VCU_CS75_12_27_t_IN_AutoDriving;

        /* Entry 'AutoDriving': '<S60>:8' */
        /* 自动驾驶 */
        System_State = 1.0;
      } else {
        System_State = 0.0;
      }
      break;

     default:
      /* During 'TakeOver': '<S60>:9' */
      rtb_ErrorSum_LogROP = ((rtb_APP_Input_idx_0 == 0.0) &&
        (rtb_APP_Input_idx_217 == 0.0));
      if (rtb_ErrorSum_LogROP) {
        /* Transition: '<S60>:32' */
        VCU_CS75_12_27_test_log_DW.bitsForTID4.is_System_State =
          VCU_CS75__IN_INIT_ManualDriving;

        /* Entry 'INIT_ManualDriving': '<S60>:7' */
        /* 驾驶员正常驾驶 */
        System_State = 0.0;
      } else {
        rtb_ErrorSum_LogROP = ((VehicleFaultStatus == 1.0) ||
          (VehicleCommunicationStatus == 0.0) || (Server_CommunicationStatus ==
          0.0));
        if (rtb_ErrorSum_LogROP) {
          /* Transition: '<S60>:39' */
          VCU_CS75_12_27_test_log_DW.bitsForTID4.is_System_State =
            VCU_CS75_12_27_test_lo_IN_Error;

          /* Entry 'Error': '<S60>:10' */
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
  VCU_CS75_12_MATLABFunction2(System_State,
    &VCU_CS75_12_27_test_log_B.sf_MATLABFunction2_d);

  /* End of Outputs for SubSystem: '<S27>/Accesories' */

  /* Outputs for Atomic SubSystem: '<S27>/Lateral' */
  /* Lookup_n-D: '<S32>/1-D Lookup Table' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Accesories/MATLAB Function1': '<S35>:1' */
  mubiao_zhuanjiao = look1_binlx(rtb_APP_Input_idx_2,
    VCU_CS75_12_27_test_log_ConstP.DLookupTable_bp01Data,
    VCU_CS75_12_27_test_log_ConstP.pooled2, 1U);

  /* Memory: '<S32>/Memory3' */
  rtb_Memory1_e = VCU_CS75_12_27_test_log_DW.Memory3_PreviousInput_j;

  /* DataTypeConversion: '<S32>/Data Type Conversion4' */
  rtb_Memory2 = rtb_Memory1_e;

  /* Memory: '<S32>/Memory1' */
  rtb_Memory1_e = VCU_CS75_12_27_test_log_DW.Memory1_PreviousInput_b;

  /* DataTypeConversion: '<S32>/Data Type Conversion3' */
  rtb_P6_Value = rtb_Memory1_e;

  /* MATLAB Function: '<S32>/MATLAB Function' incorporates:
   *  Constant: '<S32>/Constant4'
   *  Constant: '<S32>/ECCalVar'
   *  Constant: '<S32>/ECCalVar1'
   *  Constant: '<S32>/ECCalVar2'
   *  Constant: '<S32>/ECCalVar3'
   *  Constant: '<S32>/ECCalVar4'
   *  Constant: '<S32>/ECCalVar5'
   *  Constant: '<S32>/ECCalVar6'
   *  Constant: '<S32>/ECCalVar7'
   *  Constant: '<S32>/ECCalVar8'
   */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Lateral/MATLAB Function': '<S38>:1' */
  /* '<S38>:1:3' */
  rtb_APP_Input_idx_12 = mubiao_zhuanjiao - rtb_APP_Input_idx_99;

  /* %%目标转角-当前转角，角度 */
  if (fabs(rtb_APP_Input_idx_12) < 50.0) {
    /* '<S38>:1:4' */
    /* '<S38>:1:5' */
    rtb_APP_Input_idx_29 = P1;

    /* '<S38>:1:6' */
    rtb_APP_Input_idx_79 = I1;

    /* '<S38>:1:7' */
    rtb_APP_Input_idx_0 = ErrorSumMax1;
  } else if (fabs(rtb_APP_Input_idx_12) < 250.0) {
    /* '<S38>:1:8' */
    /* '<S38>:1:9' */
    rtb_APP_Input_idx_29 = P2;

    /* '<S38>:1:10' */
    rtb_APP_Input_idx_79 = I2;

    /* '<S38>:1:11' */
    rtb_APP_Input_idx_0 = ErrorSumMax2;
  } else {
    /* '<S38>:1:13' */
    rtb_APP_Input_idx_29 = P3;

    /* '<S38>:1:14' */
    rtb_APP_Input_idx_79 = I3;

    /* '<S38>:1:15' */
    rtb_APP_Input_idx_0 = ErrorSumMax3;
  }

  if (rtb_APP_Input_idx_217 == 1.0) {
    /* '<S38>:1:18' */
    /* '<S38>:1:19' */
    rtb_P6_Value += rtb_APP_Input_idx_12;

    /* %累积误差  */
  } else {
    /* '<S38>:1:21' */
    rtb_P6_Value = 0.0;
  }

  /* %%积分清零； */
  if (rtb_P6_Value > rtb_APP_Input_idx_0) {
    /* '<S38>:1:25' */
    /* '<S38>:1:26' */
    rtb_P6_Value = rtb_APP_Input_idx_0;
  } else {
    if (rtb_P6_Value < -rtb_APP_Input_idx_0) {
      /* '<S38>:1:27' */
      /* '<S38>:1:28' */
      rtb_P6_Value = -rtb_APP_Input_idx_0;
    }
  }

  /* %%积分限幅 */
  /* '<S38>:1:32' */
  /* %%位置式PID计算 */
  if (rtb_APP_Input_idx_217 == 1.0) {
    /* '<S38>:1:35' */
    /* '<S38>:1:36' */
    PID_SteeringOut = (rtb_APP_Input_idx_29 * rtb_APP_Input_idx_12 +
                       rtb_APP_Input_idx_79 * rtb_P6_Value) +
      (rtb_APP_Input_idx_12 - rtb_Memory2) * 0.0;
  } else {
    /* '<S38>:1:38' */
    PID_SteeringOut = 0.0;
  }

  /* %%实际的转矩输出 */
  Error = rtb_APP_Input_idx_12;
  ErrorSum = rtb_P6_Value;

  /* End of MATLAB Function: '<S32>/MATLAB Function' */

  /* DataTypeConversion: '<S32>/Data Type Conversion1' */
  rtb_ErrorSum_d = (real32_T)ErrorSum;

  /* DataTypeConversion: '<S32>/Data Type Conversion2' */
  rtb_Error_m = (real32_T)Error;

  /* Memory: '<S32>/Memory4' */
  rtb_Memory4_e = VCU_CS75_12_27_test_log_DW.Memory4_PreviousInput_o;

  /* MATLAB Function: '<S32>/MATLAB Function1' incorporates:
   *  Constant: '<S32>/Constant7'
   */
  VCU_CS75_12_MATLABFunction1(20.0, PID_SteeringOut, rtb_Memory4_e,
    &VCU_CS75_12_27_test_log_B.sf_MATLABFunction1_f);

  /* Gain: '<S32>/Gain1' */
  rtb_APP_Input_idx_39 = 0.01 * VCU_CS75_12_27_test_log_B.sf_MATLABFunction1_f.y;

  /* Memory: '<S32>/Memory2' */
  rtb_P6_Value = VCU_CS75_12_27_test_log_DW.Memory2_PreviousInput_l;

  /* MATLAB Function: '<S32>/MATLAB Function2' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Lateral/MATLAB Function2': '<S40>:1' */
  if (rtb_P6_Value == 15.0) {
    /* '<S40>:1:2' */
    /* '<S40>:1:3' */
    LAS_RollingCounter = 0.0;
  } else {
    /* '<S40>:1:5' */
    /* '<S40>:1:6' */
    LAS_RollingCounter = rtb_P6_Value + 1.0;
  }

  /* End of MATLAB Function: '<S32>/MATLAB Function2' */

  /* MATLAB Function: '<S32>/MATLAB Function3' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Lateral/MATLAB Function3': '<S41>:1' */
  if ((rtb_APP_Input_idx_217 == 1.0) && ((System_State == 0.0) || (System_State ==
        1.0))) {
    /* '<S41>:1:2' */
    /* '<S41>:1:3' */
    /* '<S41>:1:4' */
    LAS_LKSStatus = 2.0;
  } else {
    /* '<S41>:1:6' */
    /* '<S41>:1:7' */
    LAS_LKSStatus = 1.0;
  }

  /* End of MATLAB Function: '<S32>/MATLAB Function3' */

  /* Switch: '<S32>/Switch' incorporates:
   *  Constant: '<S32>/Constant'
   */
  if (rtb_APP_Input_idx_217 > 0.0) {
    rtb_Switch = rtb_APP_Input_idx_39;
  } else {
    rtb_Switch = 0.0;
  }

  /* End of Switch: '<S32>/Switch' */

  /* MATLAB Function: '<S32>/MATLAB Function4' incorporates:
   *  Constant: '<S32>/Constant6'
   */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Lateral/MATLAB Function4': '<S42>:1' */
  if (rtb_Switch > 3.0) {
    /* '<S42>:1:2' */
    /* '<S42>:1:3' */
    rtb_Switch = 3.0;
  } else if (rtb_Switch < -3.0) {
    /* '<S42>:1:4' */
    /* '<S42>:1:5' */
    rtb_Switch = -3.0;
  } else {
    /* '<S42>:1:7' */
  }

  /* End of MATLAB Function: '<S32>/MATLAB Function4' */

  /* MATLAB Function: '<S32>/MATLAB Function7' */
  VCU_CS75_12_MATLABFunction2(System_State,
    &VCU_CS75_12_27_test_log_B.sf_MATLABFunction7);

  /* Update for Memory: '<S32>/Memory3' */
  VCU_CS75_12_27_test_log_DW.Memory3_PreviousInput_j = rtb_Error_m;

  /* Update for Memory: '<S32>/Memory1' */
  VCU_CS75_12_27_test_log_DW.Memory1_PreviousInput_b = rtb_ErrorSum_d;

  /* Update for Memory: '<S32>/Memory4' */
  VCU_CS75_12_27_test_log_DW.Memory4_PreviousInput_o =
    VCU_CS75_12_27_test_log_B.sf_MATLABFunction1_f.y;

  /* Update for Memory: '<S32>/Memory2' */
  VCU_CS75_12_27_test_log_DW.Memory2_PreviousInput_l = LAS_RollingCounter;

  /* End of Outputs for SubSystem: '<S27>/Lateral' */

  /* Outputs for Atomic SubSystem: '<S27>/Longitudinal' */
  /* MATLAB Function: '<S33>/MATLAB Function7' */
  VCU_CS75_12_MATLABFunction2(System_State,
    &VCU_CS75_12_27_test_log_B.sf_MATLABFunction7_g);

  /* Gain: '<S33>/Gain' */
  rtb_APP_Input_idx_12 = 100.0 * rtb_APP_Input_idx_1;

  /* Gain: '<S33>/Gain1' */
  rtb_P6_Value = 100.0 * rtb_APP_Input_idx_90;

  /* Memory: '<S33>/Memory3' */
  rtb_Memory2 = VCU_CS75_12_27_test_log_DW.Memory3_PreviousInput_g;

  /* MATLAB Function: '<S33>/MATLAB Function8' incorporates:
   *  Constant: '<S33>/ECCalVar'
   *  Constant: '<S33>/ECCalVar1'
   *  Constant: '<S33>/ECCalVar2'
   *  Constant: '<S33>/ECCalVar3'
   *  Constant: '<S33>/ECCalVar4'
   *  Constant: '<S33>/ECCalVar5'
   */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Longitudinal/MATLAB Function8': '<S52>:1' */
  /* '<S52>:1:3' */
  rtb_APP_Input_idx_2 = rtb_APP_Input_idx_12 - rtb_P6_Value;

  /* %%目标加速度-当前加速度 */
  if (fabs(rtb_APP_Input_idx_2) < 250.0) {
    /* '<S52>:1:4' */
    /* '<S52>:1:5' */
    rtb_APP_Input_idx_29 = Log_P1;

    /* '<S52>:1:6' */
    rtb_APP_Input_idx_79 = Log_I1;

    /* '<S52>:1:7' */
    rtb_APP_Input_idx_0 = Log_ErrorSumMax1;
  } else {
    /* '<S52>:1:9' */
    rtb_APP_Input_idx_29 = Log_P2;

    /* '<S52>:1:10' */
    rtb_APP_Input_idx_79 = Log_I2;

    /* '<S52>:1:11' */
    rtb_APP_Input_idx_0 = Log_ErrorSumMax2;
  }

  if ((VCU_CS75_12_27_test_log_B.sf_MATLABFunction7_g.y == 1.0) &&
      (rtb_APP_Input_idx_12 > 0.0)) {
    /* '<S52>:1:14' */
    /* '<S52>:1:15' */
    rtb_Memory2 += rtb_APP_Input_idx_2;

    /* %累积误差  */
  } else {
    /* '<S52>:1:17' */
    rtb_Memory2 = 0.0;
  }

  /* %%积分清零； */
  if (rtb_Memory2 > rtb_APP_Input_idx_0) {
    /* '<S52>:1:21' */
    /* '<S52>:1:22' */
    rtb_Memory2 = rtb_APP_Input_idx_0;
  } else {
    if (rtb_Memory2 < -rtb_APP_Input_idx_0) {
      /* '<S52>:1:23' */
      /* '<S52>:1:24' */
      rtb_Memory2 = -rtb_APP_Input_idx_0;
    }
  }

  /* %%积分限幅 */
  /* '<S52>:1:28' */
  /* %%位置式PID计算 */
  if ((VCU_CS75_12_27_test_log_B.sf_MATLABFunction7_g.y == 1.0) &&
      (rtb_APP_Input_idx_12 > 0.0)) {
    /* '<S52>:1:31' */
    /* '<S52>:1:32' */
    rtb_TorqueOut = rtb_APP_Input_idx_29 * rtb_APP_Input_idx_2 +
      rtb_APP_Input_idx_79 * rtb_Memory2;
  } else {
    /* '<S52>:1:34' */
    rtb_TorqueOut = 0.0;
  }

  /* End of MATLAB Function: '<S33>/MATLAB Function8' */

  /* Memory: '<S33>/Memory5' */
  /* %%实际的转矩输出 */
  rtb_Memory5 = VCU_CS75_12_27_test_log_DW.Memory5_PreviousInput;

  /* MATLAB Function: '<S33>/MATLAB Function5' incorporates:
   *  Constant: '<S33>/Constant7'
   */
  VCU_CS75_12_MATLABFunction1(10.0, rtb_TorqueOut, rtb_Memory5,
    &VCU_CS75_12_27_test_log_B.sf_MATLABFunction5);

  /* Gain: '<S33>/Gain2' */
  rtb_P6_Value = 0.1 * VCU_CS75_12_27_test_log_B.sf_MATLABFunction5.y;

  /* DataTypeConversion: '<S33>/Data Type Conversion' */
  rtb_Memory1_e = (real32_T)rtb_P6_Value;

  /* DataTypeConversion: '<S33>/Data Type Conversion6' */
  rtb_ErrorSum_Log = (real32_T)rtb_Memory2;

  /* DataTypeConversion: '<S33>/Data Type Conversion1' */
  rtb_Memory2 = rtb_ErrorSum_Log;

  /* DataTypeConversion: '<S33>/Data Type Conversion5' */
  rtb_Error_Log = (real32_T)rtb_APP_Input_idx_2;

  /* MATLAB Function: '<S33>/MATLAB Function' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Longitudinal/MATLAB Function': '<S44>:1' */
  if (rtb_APP_Input_idx_1 < 0.0) {
    /* '<S44>:1:2' */
    /* '<S44>:1:3' */
    ACC_CDDAxEnable = 1.0;
  } else {
    /* '<S44>:1:5' */
    ACC_CDDAxEnable = 0.0;
  }

  /* End of MATLAB Function: '<S33>/MATLAB Function' */

  /* MATLAB Function: '<S33>/MATLAB Function1' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Longitudinal/MATLAB Function1': '<S45>:1' */
  if (rtb_APP_Input_idx_1 >= 0.0) {
    /* '<S45>:1:2' */
    /* '<S45>:1:3' */
    ACC_Driveoff_Request = 1.0;
  } else {
    /* '<S45>:1:5' */
    ACC_Driveoff_Request = 0.0;
  }

  /* End of MATLAB Function: '<S33>/MATLAB Function1' */

  /* MATLAB Function: '<S33>/MATLAB Function2' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Longitudinal/MATLAB Function2': '<S46>:1' */
  if ((rtb_APP_Input_idx_1 < 0.0) &&
      (VCU_CS75_12_27_test_log_B.sf_MATLABFunction7_g.y == 1.0)) {
    /* '<S46>:1:2' */
    /* '<S46>:1:3' */
    ACC_ACCTargetAcceleration = rtb_APP_Input_idx_1;
  } else {
    /* '<S46>:1:5' */
    ACC_ACCTargetAcceleration = 0.0;
  }

  /* End of MATLAB Function: '<S33>/MATLAB Function2' */

  /* Memory: '<S33>/Memory1' */
  rtb_P6_Value = VCU_CS75_12_27_test_log_DW.Memory1_PreviousInput_p;

  /* MATLAB Function: '<S33>/MATLAB Function3' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Longitudinal/MATLAB Function3': '<S47>:1' */
  if (rtb_P6_Value == 15.0) {
    /* '<S47>:1:2' */
    /* '<S47>:1:3' */
    rtb_P6_Value = 0.0;
  } else {
    /* '<S47>:1:5' */
  }

  if (VCU_CS75_12_27_test_log_B.sf_MATLABFunction7_g.y == 1.0) {
    /* '<S47>:1:8' */
    /* '<S47>:1:9' */
    ACC_RollingCounter_id2E4 = rtb_P6_Value + 1.0;
  } else {
    /* '<S47>:1:11' */
    ACC_RollingCounter_id2E4 = rtb_P6_Value;
  }

  /* End of MATLAB Function: '<S33>/MATLAB Function3' */

  /* Memory: '<S33>/Memory2' */
  rtb_P6_Value = VCU_CS75_12_27_test_log_DW.Memory2_PreviousInput_b;

  /* MATLAB Function: '<S33>/MATLAB Function4' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Longitudinal/MATLAB Function4': '<S48>:1' */
  if (rtb_P6_Value == 15.0) {
    /* '<S48>:1:2' */
    /* '<S48>:1:3' */
    rtb_P6_Value = 0.0;
  } else {
    /* '<S48>:1:5' */
  }

  if (VCU_CS75_12_27_test_log_B.sf_MATLABFunction7_g.y == 1.0) {
    /* '<S48>:1:8' */
    /* '<S48>:1:9' */
    ACC_RollingCounter_id2E5 = rtb_P6_Value + 1.0;
  } else {
    /* '<S48>:1:11' */
    ACC_RollingCounter_id2E5 = rtb_P6_Value;
  }

  /* End of MATLAB Function: '<S33>/MATLAB Function4' */

  /* MATLAB Function: '<S33>/MATLAB Function6' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Longitudinal/MATLAB Function6': '<S50>:1' */
  if (rtb_APP_Input_idx_1 <= 0.0) {
    /* '<S50>:1:2' */
    /* '<S50>:1:3' */
    ACC_TrqEnable = 0.0;
  } else {
    /* '<S50>:1:5' */
    ACC_TrqEnable = 1.0;
  }

  /* End of MATLAB Function: '<S33>/MATLAB Function6' */

  /* Saturate: '<S33>/Saturation' */
  rtb_APP_Input_idx_2 = ACC_ACCTargetAcceleration;
  if (rtb_APP_Input_idx_2 > 0.0) {
    rtb_APP_Input_idx_2 = 0.0;
  } else {
    if (rtb_APP_Input_idx_2 < -5.0) {
      rtb_APP_Input_idx_2 = -5.0;
    }
  }

  /* End of Saturate: '<S33>/Saturation' */

  /* Saturate: '<S33>/Saturation1' */
  if (rtb_Memory1_e > 50.0F) {
    rtb_ACC_AccTorqueReq = 50.0F;
  } else if (rtb_Memory1_e < 0.0F) {
    rtb_ACC_AccTorqueReq = 0.0F;
  } else {
    rtb_ACC_AccTorqueReq = rtb_Memory1_e;
  }

  /* End of Saturate: '<S33>/Saturation1' */

  /* Update for Memory: '<S33>/Memory3' */
  VCU_CS75_12_27_test_log_DW.Memory3_PreviousInput_g = rtb_Memory2;

  /* Update for Memory: '<S33>/Memory5' */
  VCU_CS75_12_27_test_log_DW.Memory5_PreviousInput =
    VCU_CS75_12_27_test_log_B.sf_MATLABFunction5.y;

  /* Update for Memory: '<S33>/Memory1' */
  VCU_CS75_12_27_test_log_DW.Memory1_PreviousInput_p = ACC_RollingCounter_id2E4;

  /* Update for Memory: '<S33>/Memory2' */
  VCU_CS75_12_27_test_log_DW.Memory2_PreviousInput_b = ACC_RollingCounter_id2E5;

  /* End of Outputs for SubSystem: '<S27>/Longitudinal' */

  /* Memory: '<S53>/Memory1' */
  A1counter = VCU_CS75_12_27_test_log_DW.Memory1_PreviousInput;

  /* Memory: '<S53>/Memory2' */
  rtb_P6_Value = VCU_CS75_12_27_test_log_DW.Memory2_PreviousInput_c;

  /* MATLAB Function: '<S53>/MATLAB Function1' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Monitor/Server_Status/MATLAB Function1': '<S57>:1' */
  if (rtb_APP_Input_idx_3 == A1counter) {
    /* '<S57>:1:2' */
    /* '<S57>:1:3' */
    rtb_P6_Value++;
  } else {
    /* '<S57>:1:5' */
    rtb_P6_Value = 0.0;
  }

  counter3 = rtb_P6_Value;

  /* End of MATLAB Function: '<S53>/MATLAB Function1' */

  /* Update for Memory: '<S55>/Memory3' */
  VCU_CS75_12_27_test_log_DW.Memory3_PreviousInput = rtb_APP_Input_idx_17;

  /* Update for Memory: '<S55>/Memory2' */
  VCU_CS75_12_27_test_log_DW.Memory2_PreviousInput = counter1;

  /* Update for Memory: '<S53>/Memory1' */
  VCU_CS75_12_27_test_log_DW.Memory1_PreviousInput = rtb_APP_Input_idx_3;

  /* Update for Memory: '<S53>/Memory2' */
  VCU_CS75_12_27_test_log_DW.Memory2_PreviousInput_c = counter3;

  /* End of Outputs for SubSystem: '<S2>/APP' */

  /* Lookup_n-D: '<S697>/1-D Lookup Table' */
  rtb_APP_Input_idx_29 = look1_binlx(rtb_APP_Input_idx_99,
    VCU_CS75_12_27_test_log_ConstP.pooled2,
    VCU_CS75_12_27_test_log_ConstP.DLookupTable_tableDat, 1U);

  /* Abs: '<S697>/Abs' */
  rtb_Memory2 = fabs(rtb_APP_Input_idx_63);

  /* Abs: '<S697>/Abs1' */
  rtb_APP_Input_idx_12 = fabs(rtb_APP_Input_idx_66);

  /* Gain: '<S697>/Gain' */
  rtb_APP_Input_idx_29 *= 0.017453291666666666;

  /* Saturate: '<S707>/Steering_Angle_Feedback_sat' */
  if (rtb_APP_Input_idx_29 > 0.69787) {
    rtb_APP_Input_idx_29 = 0.69787;
  } else {
    if (rtb_APP_Input_idx_29 < -0.698) {
      rtb_APP_Input_idx_29 = -0.698;
    }
  }

  /* End of Saturate: '<S707>/Steering_Angle_Feedback_sat' */

  /* Sum: '<S707>/Steering_Angle_Feedback_st' incorporates:
   *  Constant: '<S707>/Steering_Angle_Feedback_O'
   */
  rtb_P6_Value = rtb_APP_Input_idx_29 - -0.69800001382827759;

  /* Product: '<S707>/Steering_Angle_Feedback_D' */
  rtb_APP_Input_idx_29 = rtb_P6_Value / 0.00547399977222085;

  /* Rounding: '<S707>/Steering_Angle_FeedbackRon' */
  rtb_APP_Input_idx_29 = rt_roundd_snf(rtb_APP_Input_idx_29);

  /* DataTypeConversion: '<S707>/Steering_Angle_Feedback_Convert1' */
  rtb_LAS_SteeringTorqueReq_L = (uint32_T)rtb_APP_Input_idx_29;

  /* S-Function (sfix_bitop): '<S707>/Steering_Angle_Feedback_L' */
  rtb_ErrorSum_Log_L = rtb_LAS_SteeringTorqueReq_L & 255U;

  /* DataTypeConversion: '<S707>/Steering_Angle_Feedback_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_ErrorSum_Log_L;

  /* S-Function (sfix_bitop): '<S703>/or1' */
  VCU_CS75_12_27_test_log_B.or1 = rtb_ACC_CDDAxEnable_Convert;

  /* Gain: '<S697>/Gain1' */
  EMS_IndicatedRealTroq = 0.01 * rtb_APP_Input_idx_9;

  /* Saturate: '<S704>/Engine_Feedback_sat' */
  rtb_P6_Value = EMS_IndicatedRealTroq;
  if (rtb_P6_Value > 1.0) {
    rtb_P6_Value = 1.0;
  } else {
    if (rtb_P6_Value < -1.0) {
      rtb_P6_Value = -1.0;
    }
  }

  /* End of Saturate: '<S704>/Engine_Feedback_sat' */

  /* Sum: '<S704>/Engine_Feedback_st' incorporates:
   *  Constant: '<S704>/Engine_Feedback_O'
   */
  rtb_APP_Input_idx_29 = rtb_P6_Value - -1.0;

  /* Product: '<S704>/Engine_Feedback_D' */
  rtb_P6_Value = rtb_APP_Input_idx_29 / 0.0078431377187371254;

  /* Rounding: '<S704>/Engine_FeedbackRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S704>/Engine_Feedback_Convert1' */
  rtb_ErrorSum_Log_L = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S704>/Engine_Feedback_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ErrorSum_Log_L & 255U;

  /* DataTypeConversion: '<S704>/Engine_Feedback_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_LAS_SteeringTorqueReq_L;

  /* S-Function (sfix_bitop): '<S703>/or2' */
  VCU_CS75_12_27_test_log_B.or2 = rtb_ACC_CDDAxEnable_Convert;

  /* Saturate: '<S705>/Engine_Feedback2_sat' */
  rtb_P6_Value = EMS_IndicatedRealTroq;
  if (rtb_P6_Value > 1.0) {
    rtb_P6_Value = 1.0;
  } else {
    if (rtb_P6_Value < -1.0) {
      rtb_P6_Value = -1.0;
    }
  }

  /* End of Saturate: '<S705>/Engine_Feedback2_sat' */

  /* Sum: '<S705>/Engine_Feedback2_st' incorporates:
   *  Constant: '<S705>/Engine_Feedback2_O'
   */
  rtb_APP_Input_idx_29 = rtb_P6_Value - -1.0;

  /* Product: '<S705>/Engine_Feedback2_D' */
  rtb_P6_Value = rtb_APP_Input_idx_29 / 0.0078431377187371254;

  /* Rounding: '<S705>/Engine_Feedback2Ron' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S705>/Engine_Feedback2_Convert1' */
  rtb_ErrorSum_Log_L = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S705>/Engine_Feedback2_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ErrorSum_Log_L & 255U;

  /* DataTypeConversion: '<S705>/Engine_Feedback2_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_LAS_SteeringTorqueReq_L;

  /* S-Function (sfix_bitop): '<S703>/or3' */
  VCU_CS75_12_27_test_log_B.or3 = rtb_ACC_CDDAxEnable_Convert;

  /* Saturate: '<S709>/Wheel_Speed_RL_Feedback_sat' */
  if (rtb_APP_Input_idx_12 > 200.0) {
    rtb_APP_Input_idx_12 = 200.0;
  }

  /* End of Saturate: '<S709>/Wheel_Speed_RL_Feedback_sat' */

  /* Sum: '<S709>/Wheel_Speed_RL_Feedback_st' */
  rtb_P6_Value = rtb_APP_Input_idx_12;

  /* Product: '<S709>/Wheel_Speed_RL_Feedback_D' */
  rtb_APP_Input_idx_12 = rtb_P6_Value / 0.78431373834609985;

  /* Rounding: '<S709>/Wheel_Speed_RL_FeedbackRon' */
  rtb_APP_Input_idx_12 = rt_roundd_snf(rtb_APP_Input_idx_12);

  /* DataTypeConversion: '<S709>/Wheel_Speed_RL_Feedback_Convert1' */
  rtb_ErrorSum_Log_L = (uint32_T)rtb_APP_Input_idx_12;

  /* S-Function (sfix_bitop): '<S709>/Wheel_Speed_RL_Feedback_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ErrorSum_Log_L & 255U;

  /* DataTypeConversion: '<S709>/Wheel_Speed_RL_Feedback_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_LAS_SteeringTorqueReq_L;

  /* S-Function (sfix_bitop): '<S703>/or4' */
  VCU_CS75_12_27_test_log_B.or4 = rtb_ACC_CDDAxEnable_Convert;

  /* Saturate: '<S710>/Wheel_Speed_RR_Feedback_sat' */
  if (rtb_Memory2 > 200.0) {
    rtb_Memory2 = 200.0;
  }

  /* End of Saturate: '<S710>/Wheel_Speed_RR_Feedback_sat' */

  /* Sum: '<S710>/Wheel_Speed_RR_Feedback_st' */
  rtb_P6_Value = rtb_Memory2;

  /* Product: '<S710>/Wheel_Speed_RR_Feedback_D' */
  rtb_APP_Input_idx_12 = rtb_P6_Value / 0.78431373834609985;

  /* Rounding: '<S710>/Wheel_Speed_RR_FeedbackRon' */
  rtb_APP_Input_idx_12 = rt_roundd_snf(rtb_APP_Input_idx_12);

  /* DataTypeConversion: '<S710>/Wheel_Speed_RR_Feedback_Convert1' */
  rtb_ErrorSum_Log_L = (uint32_T)rtb_APP_Input_idx_12;

  /* S-Function (sfix_bitop): '<S710>/Wheel_Speed_RR_Feedback_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ErrorSum_Log_L & 255U;

  /* DataTypeConversion: '<S710>/Wheel_Speed_RR_Feedback_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_LAS_SteeringTorqueReq_L;

  /* S-Function (sfix_bitop): '<S703>/or5' */
  VCU_CS75_12_27_test_log_B.or5 = rtb_ACC_CDDAxEnable_Convert;

  /* Saturate: '<S706>/Res_go_sat' */
  if (rtb_APP_Input_idx_217 > 1.0) {
    rtb_P6_Value = 1.0;
  } else if (rtb_APP_Input_idx_217 < 0.0) {
    rtb_P6_Value = 0.0;
  } else {
    rtb_P6_Value = rtb_APP_Input_idx_217;
  }

  /* End of Saturate: '<S706>/Res_go_sat' */

  /* Sum: '<S706>/Res_go_st' */
  rtb_APP_Input_idx_12 = rtb_P6_Value;

  /* Rounding: '<S706>/Res_goRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S706>/Res_go_Convert1' */
  rtb_ErrorSum_Log_L = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S706>/Res_go_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ErrorSum_Log_L & 255U;

  /* DataTypeConversion: '<S706>/Res_go_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_LAS_SteeringTorqueReq_L;

  /* S-Function (sfix_bitop): '<S703>/or6' */
  VCU_CS75_12_27_test_log_B.or6 = rtb_ACC_CDDAxEnable_Convert;

  /* Saturate: '<S708>/Steering_feedback_sat' */
  if (rtb_APP_Input_idx_99 > 499.998565) {
    rtb_P6_Value = 499.998565;
  } else if (rtb_APP_Input_idx_99 < -500.0) {
    rtb_P6_Value = -500.0;
  } else {
    rtb_P6_Value = rtb_APP_Input_idx_99;
  }

  /* End of Saturate: '<S708>/Steering_feedback_sat' */

  /* Sum: '<S708>/Steering_feedback_st' incorporates:
   *  Constant: '<S708>/Steering_feedback_O'
   */
  rtb_APP_Input_idx_12 = rtb_P6_Value - -500.0;

  /* Product: '<S708>/Steering_feedback_D' */
  rtb_P6_Value = rtb_APP_Input_idx_12 / 0.015258999541401863;

  /* Rounding: '<S708>/Steering_feedbackRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S708>/Steering_feedback_Convert' */
  rtb_ErrorSum_Log_L = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S708>/Steering_feedback_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ErrorSum_Log_L & 65535U;

  /* S-Function (sfix_bitop): '<S708>/Steering_feedback_And' incorporates:
   *  Constant: '<S708>/Steering_feedback_And_C'
   */
  rtb_ErrorSum_Log_L = rtb_LAS_SteeringTorqueReq_L & 255U;

  /* DataTypeConversion: '<S708>/BitCov' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_ErrorSum_Log_L;

  /* S-Function (sfix_bitop): '<S703>/or7' */
  VCU_CS75_12_27_test_log_B.or7 = rtb_ACC_CDDAxEnable_Convert;

  /* Product: '<S708>/Steering_feedback_D1' incorporates:
   *  Constant: '<S708>/Steering_feedbackoutput8_C'
   */
  rtb_P6_Value = (real_T)rtb_LAS_SteeringTorqueReq_L / 256.0;

  /* DataTypeConversion: '<S708>/Steering_feedbackCOV' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S703>/or8' */
  VCU_CS75_12_27_test_log_B.or8 = rtb_ACC_CDDAxEnable_Convert;

  /* S-Function (ec5744_cantransmitslb): '<S697>/CANTransmit' */

  /*Transmit CAN message*/
  {
    uint8 CAN0BUF8TX[8];
    uint8 can0buf8looptx= 0;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_12_27_test_log_B.or1;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_12_27_test_log_B.or2;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_12_27_test_log_B.or3;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_12_27_test_log_B.or4;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_12_27_test_log_B.or5;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_12_27_test_log_B.or6;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_12_27_test_log_B.or7;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_12_27_test_log_B.or8;
    can0buf8looptx++;
    VCU_CS75_12_27_test_log_B.CANTransmit_i= ec_can_transmit(0, 8, 1, 1297U, 8,
      CAN0BUF8TX);
  }

  /* DataTypeConversion: '<S697>/Data Type Conversion' */
  EMS_FrictionalTroq = rtb_APP_Input_idx_8;

  /* DataTypeConversion: '<S697>/Data Type Conversion1' */
  EMS_TorqueConstant = rtb_APP_Input_idx_20;

  /* DataTypeConversion: '<S697>/Data Type Conversion2' */
  EMS_FullLoadIndicatedTroq = rtb_APP_Input_idx_19;

  /* Saturate: '<S743>/PID_ST_Out_sat' */
  if (rtb_APP_Input_idx_39 > 3.81) {
    rtb_P6_Value = 3.81;
  } else if (rtb_APP_Input_idx_39 < -3.84) {
    rtb_P6_Value = -3.84;
  } else {
    rtb_P6_Value = rtb_APP_Input_idx_39;
  }

  /* End of Saturate: '<S743>/PID_ST_Out_sat' */

  /* Sum: '<S743>/PID_ST_Out_st' */
  rtb_APP_Input_idx_12 = rtb_P6_Value;

  /* Product: '<S743>/PID_ST_Out_D' */
  rtb_P6_Value = rtb_APP_Input_idx_12 / 0.029999999329447746;

  /* Rounding: '<S743>/PID_ST_OutRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* RelationalOperator: '<S743>/PID_ST_OutROP' */
  rtb_ErrorSum_LogROP = (rtb_P6_Value < 0.0);

  /* Switch: '<S743>/PID_ST_OutSW' */
  if (rtb_ErrorSum_LogROP) {
    /* Abs: '<S743>/PID_ST_OutABS' */
    rtb_P6_Value = fabs(rtb_P6_Value);

    /* Sum: '<S743>/PID_ST_Outsubcon' */
    rtb_P6_Value = 256.0 - rtb_P6_Value;
  }

  /* End of Switch: '<S743>/PID_ST_OutSW' */

  /* Saturate: '<S743>/PID_ST_Out_1sat' */
  if (rtb_P6_Value > 255.0) {
    rtb_P6_Value = 255.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S743>/PID_ST_Out_1sat' */

  /* DataTypeConversion: '<S743>/PID_ST_Out_Convert1' */
  rtb_ErrorSum_Log_L = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S743>/PID_ST_Out_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ErrorSum_Log_L & 255U;

  /* DataTypeConversion: '<S743>/PID_ST_Out_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_LAS_SteeringTorqueReq_L;

  /* S-Function (sfix_bitop): '<S740>/or1' */
  VCU_CS75_12_27_test_log_B.or1_e = rtb_ACC_CDDAxEnable_Convert;

  /* Saturate: '<S742>/ErrorSum_sat' */
  if (rtb_ErrorSum_d > 3276.7F) {
    rtb_Memory1_e = 3276.7F;
  } else if (rtb_ErrorSum_d < -3276.8F) {
    rtb_Memory1_e = -3276.8F;
  } else {
    rtb_Memory1_e = rtb_ErrorSum_d;
  }

  /* End of Saturate: '<S742>/ErrorSum_sat' */

  /* Product: '<S742>/ErrorSum_D' incorporates:
   *  Constant: '<S742>/ErrorSum_F'
   */
  rtb_Memory1_e /= 0.1F;

  /* Rounding: '<S742>/ErrorSumRon' */
  rtb_Memory1_e = rt_roundf_snf(rtb_Memory1_e);

  /* RelationalOperator: '<S742>/ErrorSumROP' */
  rtb_ErrorSum_LogROP = (rtb_Memory1_e < 0.0F);

  /* Switch: '<S742>/ErrorSumSW' */
  if (rtb_ErrorSum_LogROP) {
    /* Abs: '<S742>/ErrorSumABS' */
    rtb_Memory1_e = (real32_T)fabs(rtb_Memory1_e);

    /* Sum: '<S742>/ErrorSumsubcon' */
    rtb_Memory1_e = 65536.0F - rtb_Memory1_e;
  }

  /* End of Switch: '<S742>/ErrorSumSW' */

  /* Saturate: '<S742>/ErrorSum_1sat' */
  if (rtb_Memory1_e > 65535.0F) {
    rtb_Memory1_e = 65535.0F;
  } else {
    if (rtb_Memory1_e < 0.0F) {
      rtb_Memory1_e = 0.0F;
    }
  }

  /* End of Saturate: '<S742>/ErrorSum_1sat' */

  /* DataTypeConversion: '<S742>/ErrorSum_Convert' */
  rtb_ErrorSum_Log_L = (uint32_T)rtb_Memory1_e;

  /* S-Function (sfix_bitop): '<S742>/ErrorSum_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ErrorSum_Log_L & 65535U;

  /* S-Function (sfix_bitop): '<S742>/ErrorSum_And' incorporates:
   *  Constant: '<S742>/ErrorSum_And_C'
   */
  rtb_ErrorSum_Log_L = rtb_LAS_SteeringTorqueReq_L & 255U;

  /* DataTypeConversion: '<S742>/BitCov' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_ErrorSum_Log_L;

  /* S-Function (sfix_bitop): '<S740>/or2' */
  VCU_CS75_12_27_test_log_B.or2_a = rtb_ACC_CDDAxEnable_Convert;

  /* Product: '<S742>/ErrorSum_D1' incorporates:
   *  Constant: '<S742>/ErrorSumoutput3_C'
   */
  rtb_P6_Value = (real_T)rtb_LAS_SteeringTorqueReq_L / 256.0;

  /* DataTypeConversion: '<S742>/ErrorSumCOV' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S740>/or3' */
  VCU_CS75_12_27_test_log_B.or3_h = rtb_ACC_CDDAxEnable_Convert;

  /* Saturate: '<S741>/Error_sat' */
  if (rtb_Error_m > 6553.4F) {
    rtb_Memory1_e = 6553.4F;
  } else if (rtb_Error_m < -6553.6F) {
    rtb_Memory1_e = -6553.6F;
  } else {
    rtb_Memory1_e = rtb_Error_m;
  }

  /* End of Saturate: '<S741>/Error_sat' */

  /* Product: '<S741>/Error_D' incorporates:
   *  Constant: '<S741>/Error_F'
   */
  rtb_Memory1_e /= 0.2F;

  /* Rounding: '<S741>/ErrorRon' */
  rtb_Memory1_e = rt_roundf_snf(rtb_Memory1_e);

  /* RelationalOperator: '<S741>/ErrorROP' */
  rtb_ErrorSum_LogROP = (rtb_Memory1_e < 0.0F);

  /* Switch: '<S741>/ErrorSW' */
  if (rtb_ErrorSum_LogROP) {
    /* Abs: '<S741>/ErrorABS' */
    rtb_Memory1_e = (real32_T)fabs(rtb_Memory1_e);

    /* Sum: '<S741>/Errorsubcon' */
    rtb_Memory1_e = 65536.0F - rtb_Memory1_e;
  }

  /* End of Switch: '<S741>/ErrorSW' */

  /* Saturate: '<S741>/Error_1sat' */
  if (rtb_Memory1_e > 65535.0F) {
    rtb_Memory1_e = 65535.0F;
  } else {
    if (rtb_Memory1_e < 0.0F) {
      rtb_Memory1_e = 0.0F;
    }
  }

  /* End of Saturate: '<S741>/Error_1sat' */

  /* DataTypeConversion: '<S741>/Error_Convert' */
  rtb_ErrorSum_Log_L = (uint32_T)rtb_Memory1_e;

  /* S-Function (sfix_bitop): '<S741>/Error_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ErrorSum_Log_L & 65535U;

  /* S-Function (sfix_bitop): '<S741>/Error_And' incorporates:
   *  Constant: '<S741>/Error_And_C'
   */
  rtb_ErrorSum_Log_L = rtb_LAS_SteeringTorqueReq_L & 255U;

  /* DataTypeConversion: '<S741>/BitCov' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_ErrorSum_Log_L;

  /* S-Function (sfix_bitop): '<S740>/or4' */
  VCU_CS75_12_27_test_log_B.or4_o = rtb_ACC_CDDAxEnable_Convert;

  /* Product: '<S741>/Error_D1' incorporates:
   *  Constant: '<S741>/Erroroutput5_C'
   */
  rtb_P6_Value = (real_T)rtb_LAS_SteeringTorqueReq_L / 256.0;

  /* DataTypeConversion: '<S741>/ErrorCOV' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S740>/or5' */
  VCU_CS75_12_27_test_log_B.or5_i = rtb_ACC_CDDAxEnable_Convert;

  /* S-Function (ec5744_cantransmitslb): '<S702>/CANTransmit' */

  /*Transmit CAN message*/
  {
    uint8 CAN0BUF11TX[8];
    uint8 can0buf11looptx= 0;
    CAN0BUF11TX[can0buf11looptx]= VCU_CS75_12_27_test_log_B.or1_e;
    can0buf11looptx++;
    CAN0BUF11TX[can0buf11looptx]= VCU_CS75_12_27_test_log_B.or2_a;
    can0buf11looptx++;
    CAN0BUF11TX[can0buf11looptx]= VCU_CS75_12_27_test_log_B.or3_h;
    can0buf11looptx++;
    CAN0BUF11TX[can0buf11looptx]= VCU_CS75_12_27_test_log_B.or4_o;
    can0buf11looptx++;
    CAN0BUF11TX[can0buf11looptx]= VCU_CS75_12_27_test_log_B.or5_i;
    can0buf11looptx++;
    CAN0BUF11TX[can0buf11looptx]= VCU_CS75_12_27_test_log_ConstB.or6;
    can0buf11looptx++;
    CAN0BUF11TX[can0buf11looptx]= VCU_CS75_12_27_test_log_ConstB.or7;
    can0buf11looptx++;
    CAN0BUF11TX[can0buf11looptx]= VCU_CS75_12_27_test_log_ConstB.or8;
    can0buf11looptx++;
    VCU_CS75_12_27_test_log_B.CANTransmit_l= ec_can_transmit(0, 11, 0, 1537U, 8,
      CAN0BUF11TX);
  }

  /* Saturate: '<S755>/LAS_LDWStatus_sat' */
  rtb_P6_Value = LAS_LDWStatus;
  if (rtb_P6_Value > 3.0) {
    rtb_P6_Value = 3.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S755>/LAS_LDWStatus_sat' */

  /* Sum: '<S755>/LAS_LDWStatus_st' */
  rtb_APP_Input_idx_12 = rtb_P6_Value;

  /* Rounding: '<S755>/LAS_LDWStatusRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* ArithShift: '<S755>/LAS_LDWStatus_S' */
  rtb_P6_Value = ldexp(rtb_P6_Value, 5);

  /* DataTypeConversion: '<S755>/LAS_LDWStatus_Convert1' */
  rtb_ErrorSum_Log_L = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S755>/LAS_LDWStatus_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ErrorSum_Log_L & 96U;

  /* DataTypeConversion: '<S755>/LAS_LDWStatus_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_LAS_SteeringTorqueReq_L;

  /* S-Function (sfix_bitop): '<S748>/or1' */
  VCU_CS75_12_27_test_log_B.or1_m = rtb_ACC_CDDAxEnable_Convert;

  /* Saturate: '<S756>/LAS_LDWVibrationWarning_sat' */
  rtb_P6_Value = LAS_LDWVibrationWarning;
  if (rtb_P6_Value > 3.0) {
    rtb_P6_Value = 3.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S756>/LAS_LDWVibrationWarning_sat' */

  /* Rounding: '<S756>/LAS_LDWVibrationWarningRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* ArithShift: '<S756>/LAS_LDWVibrationWarning_S' */
  rtb_P6_Value = ldexp(rtb_P6_Value, 5);

  /* DataTypeConversion: '<S756>/LAS_LDWVibrationWarning_Convert1' */
  rtb_ErrorSum_Log_L = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S756>/LAS_LDWVibrationWarning_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ErrorSum_Log_L & 96U;

  /* DataTypeConversion: '<S756>/LAS_LDWVibrationWarning_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_LAS_SteeringTorqueReq_L;

  /* S-Function (sfix_bitop): '<S748>/or2' */
  VCU_CS75_12_27_test_log_B.or2_g = rtb_ACC_CDDAxEnable_Convert;

  /* Saturate: '<S761>/LAS_SteeringTorqueReq_sat' */
  rtb_P6_Value = rtb_Switch;

  /* Sum: '<S761>/LAS_SteeringTorqueReq_st' incorporates:
   *  Constant: '<S761>/LAS_SteeringTorqueReq_O'
   */
  rtb_APP_Input_idx_12 = rtb_P6_Value - -8.0;

  /* Product: '<S761>/LAS_SteeringTorqueReq_D' */
  rtb_P6_Value = rtb_APP_Input_idx_12 / 0.0099999997764825821;

  /* Rounding: '<S761>/LAS_SteeringTorqueReqRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* ArithShift: '<S761>/LAS_SteeringTorqueReq_S' */
  rtb_P6_Value = ldexp(rtb_P6_Value, 7);

  /* DataTypeConversion: '<S761>/LAS_SteeringTorqueReq_Convert' */
  rtb_ErrorSum_Log_L = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S761>/LAS_SteeringTorqueReq_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ErrorSum_Log_L & 262016U;

  /* Product: '<S761>/LAS_SteeringTorqueReq_D1' incorporates:
   *  Constant: '<S761>/LAS_SteeringTorqueReqoutput5_C'
   */
  rtb_P6_Value = (real_T)rtb_LAS_SteeringTorqueReq_L / 65536.0;

  /* DataTypeConversion: '<S761>/LAS_SteeringTorqueReqCOV' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_P6_Value;

  /* Saturate: '<S757>/LAS_LKSStatus_sat' */
  rtb_P6_Value = LAS_LKSStatus;
  if (rtb_P6_Value > 7.0) {
    rtb_P6_Value = 7.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S757>/LAS_LKSStatus_sat' */

  /* Sum: '<S757>/LAS_LKSStatus_st' */
  rtb_APP_Input_idx_12 = rtb_P6_Value;

  /* Rounding: '<S757>/LAS_LKSStatusRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* ArithShift: '<S757>/LAS_LKSStatus_S' */
  rtb_P6_Value = ldexp(rtb_P6_Value, 5);

  /* DataTypeConversion: '<S757>/LAS_LKSStatus_Convert1' */
  rtb_ErrorSum_Log_L = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S757>/LAS_LKSStatus_L' */
  rtb_ErrorSum_Log_And = rtb_ErrorSum_Log_L & 224U;

  /* DataTypeConversion: '<S757>/LAS_LKSStatus_Convert' */
  rtb_ACC_ACCTargetAcceleration_C = (uint8_T)rtb_ErrorSum_Log_And;

  /* S-Function (sfix_bitop): '<S748>/or5' */
  VCU_CS75_12_27_test_log_B.or5_h = (uint8_T)(rtb_ACC_CDDAxEnable_Convert |
    rtb_ACC_ACCTargetAcceleration_C);

  /* S-Function (sfix_bitop): '<S761>/LAS_SteeringTorqueReq_And' */
  rtb_ErrorSum_Log_And = rtb_LAS_SteeringTorqueReq_L & 65535U;

  /* Product: '<S761>/LAS_SteeringTorqueReq_D2' incorporates:
   *  Constant: '<S761>/LAS_SteeringTorqueReqoutput6_C'
   */
  rtb_P6_Value = (real_T)rtb_ErrorSum_Log_And / 256.0;

  /* DataTypeConversion: '<S761>/LAS_SteeringTorqueReqCOV1' */
  rtb_ACC_ACCTargetAcceleration_C = (uint8_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S748>/or6' */
  VCU_CS75_12_27_test_log_B.or6_f = rtb_ACC_ACCTargetAcceleration_C;

  /* S-Function (sfix_bitop): '<S761>/LAS_SteeringTorqueReq_And1' incorporates:
   *  Constant: '<S761>/LAS_SteeringTorqueReq_And1_C'
   */
  rtb_ErrorSum_Log_And = rtb_LAS_SteeringTorqueReq_L & 255U;

  /* DataTypeConversion: '<S761>/LAS_SteeringTorqueReqBitCov1' */
  rtb_ACC_ACCTargetAcceleration_C = (uint8_T)rtb_ErrorSum_Log_And;

  /* Saturate: '<S763>/RollingConter_sat' */
  rtb_P6_Value = LAS_RollingCounter;
  if (rtb_P6_Value > 15.0) {
    rtb_P6_Value = 15.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S763>/RollingConter_sat' */

  /* Rounding: '<S763>/RollingConterRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S763>/RollingConter_Convert1' */
  rtb_ErrorSum_Log_And = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S763>/RollingConter_L' */
  rtb_ErrorSum_Log_L = rtb_ErrorSum_Log_And & 15U;

  /* DataTypeConversion: '<S763>/RollingConter_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_ErrorSum_Log_L;

  /* S-Function (sfix_bitop): '<S748>/or7' */
  VCU_CS75_12_27_test_log_B.or7_h = (uint8_T)(rtb_ACC_ACCTargetAcceleration_C |
    rtb_ACC_CDDAxEnable_Convert);

  /* S-Function (ec5744_cantransmitslb): '<S744>/CANTransmit' */

  /*Transmit CAN message*/
  {
    uint8 CAN1BUF13TX[8];
    uint8 can1buf13looptx= 0;
    CAN1BUF13TX[can1buf13looptx]= VCU_CS75_12_27_test_log_B.or1_m;
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= VCU_CS75_12_27_test_log_B.or2_g;
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= VCU_CS75_12_27_test_log_ConstB.or3;
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= VCU_CS75_12_27_test_log_ConstB.or4;
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= VCU_CS75_12_27_test_log_B.or5_h;
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= VCU_CS75_12_27_test_log_B.or6_f;
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= VCU_CS75_12_27_test_log_B.or7_h;
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= VCU_CS75_12_27_test_log_ConstB.or8_j;
    can1buf13looptx++;
    VCU_CS75_12_27_test_log_B.CANTransmit_b= ec_can_transmit(1, 13, 0, 653U, 8,
      CAN1BUF13TX);
  }

  /* Saturate: '<S765>/ACC_ACCTargetAcceleration_sat' */
  rtb_P6_Value = rtb_APP_Input_idx_2;

  /* Sum: '<S765>/ACC_ACCTargetAcceleration_st' incorporates:
   *  Constant: '<S765>/ACC_ACCTargetAcceleration_O'
   */
  rtb_APP_Input_idx_12 = rtb_P6_Value - -5.0;

  /* Product: '<S765>/ACC_ACCTargetAcceleration_D' */
  rtb_P6_Value = rtb_APP_Input_idx_12 / 0.05000000074505806;

  /* Rounding: '<S765>/ACC_ACCTargetAccelerationRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S765>/ACC_ACCTargetAcceleration_Convert1' */
  rtb_ErrorSum_Log_And = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S765>/ACC_ACCTargetAcceleration_L' */
  rtb_ErrorSum_Log_L = rtb_ErrorSum_Log_And & 255U;

  /* DataTypeConversion: '<S765>/ACC_ACCTargetAcceleration_Convert' */
  rtb_ACC_ACCTargetAcceleration_C = (uint8_T)rtb_ErrorSum_Log_L;

  /* Saturate: '<S766>/ACC_CDDAxEnable_sat' */
  rtb_P6_Value = ACC_CDDAxEnable;
  if (rtb_P6_Value > 1.0) {
    rtb_P6_Value = 1.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S766>/ACC_CDDAxEnable_sat' */

  /* Sum: '<S766>/ACC_CDDAxEnable_st' */
  rtb_APP_Input_idx_12 = rtb_P6_Value;

  /* Rounding: '<S766>/ACC_CDDAxEnableRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S766>/ACC_CDDAxEnable_Convert1' */
  rtb_ErrorSum_Log_And = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S766>/ACC_CDDAxEnable_L' */
  rtb_ErrorSum_Log_L = rtb_ErrorSum_Log_And & 1U;

  /* DataTypeConversion: '<S766>/ACC_CDDAxEnable_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_ErrorSum_Log_L;

  /* Saturate: '<S768>/ACC_DecToStop_sat' incorporates:
   *  Constant: '<S33>/Constant1'
   */
  rtb_P6_Value = 0.0;

  /* Saturate: '<S769>/ACC_Driveoff_Request_sat' */
  rtb_APP_Input_idx_29 = ACC_Driveoff_Request;
  if (rtb_APP_Input_idx_29 > 1.0) {
    rtb_P6_Value = 1.0;
  } else {
    if (!(rtb_APP_Input_idx_29 < 0.0)) {
      rtb_P6_Value = rtb_APP_Input_idx_29;
    }
  }

  /* End of Saturate: '<S769>/ACC_Driveoff_Request_sat' */

  /* Sum: '<S769>/ACC_Driveoff_Request_st' */
  rtb_APP_Input_idx_12 = rtb_P6_Value;

  /* Rounding: '<S769>/ACC_Driveoff_RequestRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* ArithShift: '<S769>/ACC_Driveoff_Request_S' */
  rtb_P6_Value = ldexp(rtb_P6_Value, 2);

  /* DataTypeConversion: '<S769>/ACC_Driveoff_Request_Convert1' */
  rtb_ErrorSum_Log_And = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S769>/ACC_Driveoff_Request_L' */
  rtb_ErrorSum_Log_L = rtb_ErrorSum_Log_And & 4U;

  /* DataTypeConversion: '<S769>/ACC_Driveoff_Request_Convert' */
  rtb_ACC_AccTrqReqEnable_Convert = (uint8_T)rtb_ErrorSum_Log_L;

  /* Saturate: '<S771>/ACC_RollingCounter_id_sat' */
  rtb_P6_Value = ACC_RollingCounter_id2E4;
  if (rtb_P6_Value > 15.0) {
    rtb_P6_Value = 15.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S771>/ACC_RollingCounter_id_sat' */

  /* Sum: '<S771>/ACC_RollingCounter_id_st' */
  rtb_APP_Input_idx_12 = rtb_P6_Value;

  /* Rounding: '<S771>/ACC_RollingCounter_idRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S771>/ACC_RollingCounter_id_Convert1' */
  rtb_ErrorSum_Log_And = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S771>/ACC_RollingCounter_id_L' */
  rtb_ErrorSum_Log_L = rtb_ErrorSum_Log_And & 15U;

  /* DataTypeConversion: '<S771>/ACC_RollingCounter_id_Convert' */
  rtb_ErrorSum_LogCOV = (uint8_T)rtb_ErrorSum_Log_L;

  /* S-Function (sfix_bitop): '<S764>/or1' */
  VCU_CS75_12_27_test_log_B.or1_i = (uint8_T)(rtb_ACC_CDDAxEnable_Convert |
    rtb_ACC_AccTrqReqEnable_Convert | 24);

  /* S-Function (sfix_bitop): '<S764>/or2' */
  VCU_CS75_12_27_test_log_B.or2_b = rtb_ACC_ACCTargetAcceleration_C;

  /* S-Function (sfix_bitop): '<S764>/or7' */
  VCU_CS75_12_27_test_log_B.or7_g = rtb_ErrorSum_LogCOV;

  /* S-Function (ec5744_cantransmitslb): '<S745>/CANTransmit' */

  /*Transmit CAN message*/
  {
    uint8 CAN1BUF8TX[8];
    uint8 can1buf8looptx= 0;
    CAN1BUF8TX[can1buf8looptx]= VCU_CS75_12_27_test_log_B.or1_i;
    can1buf8looptx++;
    CAN1BUF8TX[can1buf8looptx]= VCU_CS75_12_27_test_log_B.or2_b;
    can1buf8looptx++;
    CAN1BUF8TX[can1buf8looptx]= VCU_CS75_12_27_test_log_ConstB.or3_e;
    can1buf8looptx++;
    CAN1BUF8TX[can1buf8looptx]= VCU_CS75_12_27_test_log_ConstB.or4_n;
    can1buf8looptx++;
    CAN1BUF8TX[can1buf8looptx]= VCU_CS75_12_27_test_log_ConstB.or5;
    can1buf8looptx++;
    CAN1BUF8TX[can1buf8looptx]= VCU_CS75_12_27_test_log_ConstB.or6_c;
    can1buf8looptx++;
    CAN1BUF8TX[can1buf8looptx]= VCU_CS75_12_27_test_log_B.or7_g;
    can1buf8looptx++;
    CAN1BUF8TX[can1buf8looptx]= VCU_CS75_12_27_test_log_ConstB.or8_c;
    can1buf8looptx++;
    VCU_CS75_12_27_test_log_B.CANTransmit_it= ec_can_transmit(1, 8, 0, 740U, 8,
      CAN1BUF8TX);
  }

  /* Saturate: '<S780>/ACC_AccTorqueReq_sat' */
  rtb_Memory1_e = rtb_ACC_AccTorqueReq;

  /* Product: '<S780>/ACC_AccTorqueReq_D' incorporates:
   *  Constant: '<S780>/ACC_AccTorqueReq_F'
   */
  rtb_Memory1_e /= 0.09784F;

  /* Rounding: '<S780>/ACC_AccTorqueReqRon' */
  rtb_Memory1_e = rt_roundf_snf(rtb_Memory1_e);

  /* ArithShift: '<S780>/ACC_AccTorqueReq_S' */
  rtb_Memory1_e = (real32_T)ldexp(rtb_Memory1_e, 2);

  /* DataTypeConversion: '<S780>/ACC_AccTorqueReq_Convert' */
  rtb_ErrorSum_Log_And = (uint32_T)rtb_Memory1_e;

  /* S-Function (sfix_bitop): '<S780>/ACC_AccTorqueReq_L' */
  rtb_ErrorSum_Log_L = rtb_ErrorSum_Log_And & 4092U;

  /* S-Function (sfix_bitop): '<S780>/ACC_AccTorqueReq_And' incorporates:
   *  Constant: '<S780>/ACC_AccTorqueReq_And_C'
   */
  rtb_ErrorSum_Log_And = rtb_ErrorSum_Log_L & 255U;

  /* DataTypeConversion: '<S780>/ACC_AccTorqueReqBitCov' */
  rtb_ErrorSum_LogCOV = (uint8_T)rtb_ErrorSum_Log_And;

  /* Product: '<S780>/ACC_AccTorqueReq_D1' incorporates:
   *  Constant: '<S780>/ACC_AccTorqueReqoutput5_C'
   */
  rtb_P6_Value = (real_T)rtb_ErrorSum_Log_L / 256.0;

  /* DataTypeConversion: '<S780>/ACC_AccTorqueReqCOV' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_P6_Value;

  /* Saturate: '<S781>/ACC_AccTrqReqEnable_sat' */
  rtb_P6_Value = ACC_TrqEnable;
  if (rtb_P6_Value > 1.0) {
    rtb_P6_Value = 1.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S781>/ACC_AccTrqReqEnable_sat' */

  /* Sum: '<S781>/ACC_AccTrqReqEnable_st' */
  rtb_APP_Input_idx_12 = rtb_P6_Value;

  /* Rounding: '<S781>/ACC_AccTrqReqEnableRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* ArithShift: '<S781>/ACC_AccTrqReqEnable_S' */
  rtb_P6_Value = ldexp(rtb_P6_Value, 7);

  /* DataTypeConversion: '<S781>/ACC_AccTrqReqEnable_Convert1' */
  rtb_ErrorSum_Log_And = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S781>/ACC_AccTrqReqEnable_L' */
  rtb_ErrorSum_Log_L = rtb_ErrorSum_Log_And & 128U;

  /* DataTypeConversion: '<S781>/ACC_AccTrqReqEnable_Convert' */
  rtb_ACC_AccTrqReqEnable_Convert = (uint8_T)rtb_ErrorSum_Log_L;

  /* Saturate: '<S787>/ACC_RollingCounter_sat' */
  rtb_P6_Value = ACC_RollingCounter_id2E5;
  if (rtb_P6_Value > 15.0) {
    rtb_P6_Value = 15.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S787>/ACC_RollingCounter_sat' */

  /* Sum: '<S787>/ACC_RollingCounter_st' */
  rtb_APP_Input_idx_12 = rtb_P6_Value;

  /* Rounding: '<S787>/ACC_RollingCounterRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S787>/ACC_RollingCounter_Convert1' */
  rtb_ErrorSum_Log_And = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S787>/ACC_RollingCounter_L' */
  rtb_ErrorSum_Log_L = rtb_ErrorSum_Log_And & 15U;

  /* DataTypeConversion: '<S787>/ACC_RollingCounter_Convert' */
  rtb_ACC_ACCTargetAcceleration_C = (uint8_T)rtb_ErrorSum_Log_L;

  /* S-Function (sfix_bitop): '<S772>/or1' */
  VCU_CS75_12_27_test_log_B.or1_e1 = (uint8_T)(rtb_ACC_AccTrqReqEnable_Convert |
    15);

  /* S-Function (sfix_bitop): '<S772>/or5' */
  VCU_CS75_12_27_test_log_B.or5_m = rtb_ACC_CDDAxEnable_Convert;

  /* S-Function (sfix_bitop): '<S772>/or6' */
  VCU_CS75_12_27_test_log_B.or6_e = rtb_ErrorSum_LogCOV;

  /* S-Function (sfix_bitop): '<S772>/or7' */
  VCU_CS75_12_27_test_log_B.or7_l = rtb_ACC_ACCTargetAcceleration_C;

  /* S-Function (ec5744_cantransmitslb): '<S746>/CANTransmit' */

  /*Transmit CAN message*/
  {
    uint8 CAN1BUF9TX[8];
    uint8 can1buf9looptx= 0;
    CAN1BUF9TX[can1buf9looptx]= VCU_CS75_12_27_test_log_B.or1_e1;
    can1buf9looptx++;
    CAN1BUF9TX[can1buf9looptx]= VCU_CS75_12_27_test_log_ConstB.or2;
    can1buf9looptx++;
    CAN1BUF9TX[can1buf9looptx]= VCU_CS75_12_27_test_log_ConstB.or3_ei;
    can1buf9looptx++;
    CAN1BUF9TX[can1buf9looptx]= VCU_CS75_12_27_test_log_ConstB.or4_a;
    can1buf9looptx++;
    CAN1BUF9TX[can1buf9looptx]= VCU_CS75_12_27_test_log_B.or5_m;
    can1buf9looptx++;
    CAN1BUF9TX[can1buf9looptx]= VCU_CS75_12_27_test_log_B.or6_e;
    can1buf9looptx++;
    CAN1BUF9TX[can1buf9looptx]= VCU_CS75_12_27_test_log_B.or7_l;
    can1buf9looptx++;
    CAN1BUF9TX[can1buf9looptx]= VCU_CS75_12_27_test_log_ConstB.or8_n;
    can1buf9looptx++;
    VCU_CS75_12_27_test_log_B.CANTransmit_k= ec_can_transmit(1, 9, 0, 741U, 8,
      CAN1BUF9TX);
  }

  /* Saturate: '<S792>/RemoteAcc_sat' */
  if (rtb_APP_Input_idx_1 > 327.67) {
    rtb_P6_Value = 327.67;
  } else if (rtb_APP_Input_idx_1 < -327.68) {
    rtb_P6_Value = -327.68;
  } else {
    rtb_P6_Value = rtb_APP_Input_idx_1;
  }

  /* End of Saturate: '<S792>/RemoteAcc_sat' */

  /* Sum: '<S792>/RemoteAcc_st' */
  rtb_APP_Input_idx_12 = rtb_P6_Value;

  /* Product: '<S792>/RemoteAcc_D' */
  rtb_P6_Value = rtb_APP_Input_idx_12 / 0.0099999997764825821;

  /* Rounding: '<S792>/RemoteAccRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* RelationalOperator: '<S792>/RemoteAccROP' */
  rtb_ErrorSum_LogROP = (rtb_P6_Value < 0.0);

  /* Switch: '<S792>/RemoteAccSW' */
  if (rtb_ErrorSum_LogROP) {
    /* Abs: '<S792>/RemoteAccABS' */
    rtb_P6_Value = fabs(rtb_P6_Value);

    /* Sum: '<S792>/RemoteAccsubcon' */
    rtb_P6_Value = 65536.0 - rtb_P6_Value;
  }

  /* End of Switch: '<S792>/RemoteAccSW' */

  /* Saturate: '<S792>/RemoteAcc_1sat' */
  if (rtb_P6_Value > 65535.0) {
    rtb_P6_Value = 65535.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S792>/RemoteAcc_1sat' */

  /* DataTypeConversion: '<S792>/RemoteAcc_Convert' */
  rtb_ErrorSum_Log_And = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S792>/RemoteAcc_L' */
  rtb_ErrorSum_Log_L = rtb_ErrorSum_Log_And & 65535U;

  /* S-Function (sfix_bitop): '<S792>/RemoteAcc_And' incorporates:
   *  Constant: '<S792>/RemoteAcc_And_C'
   */
  rtb_ErrorSum_Log_And = rtb_ErrorSum_Log_L & 255U;

  /* DataTypeConversion: '<S792>/BitCov' */
  rtb_ErrorSum_LogCOV = (uint8_T)rtb_ErrorSum_Log_And;

  /* S-Function (sfix_bitop): '<S789>/or1' */
  VCU_CS75_12_27_test_log_B.or1_j = rtb_ErrorSum_LogCOV;

  /* Product: '<S792>/RemoteAcc_D1' incorporates:
   *  Constant: '<S792>/RemoteAccoutput2_C'
   */
  rtb_P6_Value = (real_T)rtb_ErrorSum_Log_L / 256.0;

  /* DataTypeConversion: '<S792>/RemoteAccCOV' */
  rtb_ErrorSum_LogCOV = (uint8_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S789>/or2' */
  VCU_CS75_12_27_test_log_B.or2_l = rtb_ErrorSum_LogCOV;

  /* Saturate: '<S791>/Error_Log_sat' */
  if (rtb_Error_Log > 655.34F) {
    rtb_Memory1_e = 655.34F;
  } else if (rtb_Error_Log < -655.36F) {
    rtb_Memory1_e = -655.36F;
  } else {
    rtb_Memory1_e = rtb_Error_Log;
  }

  /* End of Saturate: '<S791>/Error_Log_sat' */

  /* Product: '<S791>/Error_Log_D' incorporates:
   *  Constant: '<S791>/Error_Log_F'
   */
  rtb_Memory1_e /= 0.02F;

  /* Rounding: '<S791>/Error_LogRon' */
  rtb_Memory1_e = rt_roundf_snf(rtb_Memory1_e);

  /* RelationalOperator: '<S791>/Error_LogROP' */
  rtb_ErrorSum_LogROP = (rtb_Memory1_e < 0.0F);

  /* Switch: '<S791>/Error_LogSW' */
  if (rtb_ErrorSum_LogROP) {
    /* Abs: '<S791>/Error_LogABS' */
    rtb_Memory1_e = (real32_T)fabs(rtb_Memory1_e);

    /* Sum: '<S791>/Error_Logsubcon' */
    rtb_Memory1_e = 65536.0F - rtb_Memory1_e;
  }

  /* End of Switch: '<S791>/Error_LogSW' */

  /* Saturate: '<S791>/Error_Log_1sat' */
  if (rtb_Memory1_e > 65535.0F) {
    rtb_Memory1_e = 65535.0F;
  } else {
    if (rtb_Memory1_e < 0.0F) {
      rtb_Memory1_e = 0.0F;
    }
  }

  /* End of Saturate: '<S791>/Error_Log_1sat' */

  /* DataTypeConversion: '<S791>/Error_Log_Convert' */
  rtb_ErrorSum_Log_And = (uint32_T)rtb_Memory1_e;

  /* S-Function (sfix_bitop): '<S791>/Error_Log_L' */
  rtb_ErrorSum_Log_L = rtb_ErrorSum_Log_And & 65535U;

  /* S-Function (sfix_bitop): '<S791>/Error_Log_And' incorporates:
   *  Constant: '<S791>/Error_Log_And_C'
   */
  rtb_ErrorSum_Log_And = rtb_ErrorSum_Log_L & 255U;

  /* DataTypeConversion: '<S791>/BitCov' */
  rtb_ErrorSum_LogCOV = (uint8_T)rtb_ErrorSum_Log_And;

  /* S-Function (sfix_bitop): '<S789>/or3' */
  VCU_CS75_12_27_test_log_B.or3_e = rtb_ErrorSum_LogCOV;

  /* Product: '<S791>/Error_Log_D1' incorporates:
   *  Constant: '<S791>/Error_Logoutput4_C'
   */
  rtb_P6_Value = (real_T)rtb_ErrorSum_Log_L / 256.0;

  /* DataTypeConversion: '<S791>/Error_LogCOV' */
  rtb_ErrorSum_LogCOV = (uint8_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S789>/or4' */
  VCU_CS75_12_27_test_log_B.or4_c = rtb_ErrorSum_LogCOV;

  /* Saturate: '<S790>/ErrorSum_Log_sat' */
  if (rtb_ErrorSum_Log > 3276.7F) {
    rtb_Memory1_e = 3276.7F;
  } else if (rtb_ErrorSum_Log < -3276.8F) {
    rtb_Memory1_e = -3276.8F;
  } else {
    rtb_Memory1_e = rtb_ErrorSum_Log;
  }

  /* End of Saturate: '<S790>/ErrorSum_Log_sat' */

  /* Product: '<S790>/ErrorSum_Log_D' incorporates:
   *  Constant: '<S790>/ErrorSum_Log_F'
   */
  rtb_Memory1_e /= 0.1F;

  /* Rounding: '<S790>/ErrorSum_LogRon' */
  rtb_Memory1_e = rt_roundf_snf(rtb_Memory1_e);

  /* RelationalOperator: '<S790>/ErrorSum_LogROP' */
  rtb_ErrorSum_LogROP = (rtb_Memory1_e < 0.0F);

  /* Switch: '<S790>/ErrorSum_LogSW' */
  if (rtb_ErrorSum_LogROP) {
    /* Abs: '<S790>/ErrorSum_LogABS' */
    rtb_Memory1_e = (real32_T)fabs(rtb_Memory1_e);

    /* Sum: '<S790>/ErrorSum_Logsubcon' */
    rtb_Memory1_e = 65536.0F - rtb_Memory1_e;
  }

  /* End of Switch: '<S790>/ErrorSum_LogSW' */

  /* Saturate: '<S790>/ErrorSum_Log_1sat' */
  if (rtb_Memory1_e > 65535.0F) {
    rtb_Memory1_e = 65535.0F;
  } else {
    if (rtb_Memory1_e < 0.0F) {
      rtb_Memory1_e = 0.0F;
    }
  }

  /* End of Saturate: '<S790>/ErrorSum_Log_1sat' */

  /* DataTypeConversion: '<S790>/ErrorSum_Log_Convert' */
  rtb_ErrorSum_Log_And = (uint32_T)rtb_Memory1_e;

  /* S-Function (sfix_bitop): '<S790>/ErrorSum_Log_L' */
  rtb_ErrorSum_Log_L = rtb_ErrorSum_Log_And & 65535U;

  /* S-Function (sfix_bitop): '<S790>/ErrorSum_Log_And' incorporates:
   *  Constant: '<S790>/ErrorSum_Log_And_C'
   */
  rtb_ErrorSum_Log_And = rtb_ErrorSum_Log_L & 255U;

  /* DataTypeConversion: '<S790>/BitCov' */
  rtb_ErrorSum_LogCOV = (uint8_T)rtb_ErrorSum_Log_And;

  /* S-Function (sfix_bitop): '<S789>/or5' */
  VCU_CS75_12_27_test_log_B.or5_d = rtb_ErrorSum_LogCOV;

  /* Product: '<S790>/ErrorSum_Log_D1' incorporates:
   *  Constant: '<S790>/ErrorSum_Logoutput6_C'
   */
  rtb_P6_Value = (real_T)rtb_ErrorSum_Log_L / 256.0;

  /* DataTypeConversion: '<S790>/ErrorSum_LogCOV' */
  rtb_ErrorSum_LogCOV = (uint8_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S789>/or6' */
  VCU_CS75_12_27_test_log_B.or6_g = rtb_ErrorSum_LogCOV;

  /* S-Function (ec5744_cantransmitslb): '<S747>/CANTransmit' */

  /*Transmit CAN message*/
  {
    uint8 CAN1BUF60TX[8];
    uint8 can1buf60looptx= 0;
    CAN1BUF60TX[can1buf60looptx]= VCU_CS75_12_27_test_log_B.or1_j;
    can1buf60looptx++;
    CAN1BUF60TX[can1buf60looptx]= VCU_CS75_12_27_test_log_B.or2_l;
    can1buf60looptx++;
    CAN1BUF60TX[can1buf60looptx]= VCU_CS75_12_27_test_log_B.or3_e;
    can1buf60looptx++;
    CAN1BUF60TX[can1buf60looptx]= VCU_CS75_12_27_test_log_B.or4_c;
    can1buf60looptx++;
    CAN1BUF60TX[can1buf60looptx]= VCU_CS75_12_27_test_log_B.or5_d;
    can1buf60looptx++;
    CAN1BUF60TX[can1buf60looptx]= VCU_CS75_12_27_test_log_B.or6_g;
    can1buf60looptx++;
    CAN1BUF60TX[can1buf60looptx]= VCU_CS75_12_27_test_log_ConstB.or7_l;
    can1buf60looptx++;
    CAN1BUF60TX[can1buf60looptx]= VCU_CS75_12_27_test_log_ConstB.or8_p;
    can1buf60looptx++;
    VCU_CS75_12_27_test_log_B.CANTransmit_h= ec_can_transmit(1, 60, 0, 1538U, 8,
      CAN1BUF60TX);
  }
}

/* Model step function for TID5 */
void VCU_CS75_12_27_test_log_step5(void) /* Sample time: [0.05s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S4>/50ms' incorporates:
   *  SubSystem: '<S4>/daq50ms'
   */

  /* S-Function (ec5744_ccpslb1): '<S18>/CCPDAQ' */
  ccpDaq(2);
}

/* Model step function for TID6 */
void VCU_CS75_12_27_test_log_step6(void) /* Sample time: [0.1s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S3>/100MS' incorporates:
   *  SubSystem: '<S3>/Function-Call Subsystem'
   */

  /* S-Function (ec5744_canreceiveslb): '<S7>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN2BUF1RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can2buf1looprx= 0;
    VCU_CS75_12_27_test_log_B.CANReceive_o3_i= 278;
    VCU_CS75_12_27_test_log_B.CANReceive_o5_i= 8;
    VCU_CS75_12_27_test_log_B.CANReceive_o2_a= ec_can_receive(2,1, CAN2BUF1RX);
    VCU_CS75_12_27_test_log_B.CANReceive_o4_h[0]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_h[1]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_h[2]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_h[3]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_h[4]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_h[5]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_h[6]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_12_27_test_log_B.CANReceive_o4_h[7]= CAN2BUF1RX[can2buf1looprx];
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
    if (VCU_CS75_12_27_test_log_B.CANReceive_o2_a > 0) {
      /* RelationalOperator: '<S10>/Compare' incorporates:
       *  Constant: '<S10>/Constant'
       */
      rtb_Add = (uint8_T)(VCU_CS75_12_27_test_log_B.CANReceive_o4_h[0] == 83);

      /* RelationalOperator: '<S11>/Compare' incorporates:
       *  Constant: '<S11>/Constant'
       */
      rtb_Compare = (uint8_T)(VCU_CS75_12_27_test_log_B.CANReceive_o4_h[5] == 84);

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
          VCU_CS75_12_27_test_log_B.CANTransmit= ec_can_transmit(2, 9, 0, 593U,
            1, CAN2BUF9TX);
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
void VCU_CS75_12_27_test_log_step7(void) /* Sample time: [0.5s, 0.0s] */
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
void VCU_CS75_12_27_test_log_step(int_T tid)
{
  switch (tid) {
   case 0 :
    VCU_CS75_12_27_test_log_step0();
    break;

   case 1 :
    VCU_CS75_12_27_test_log_step1();
    break;

   case 2 :
    VCU_CS75_12_27_test_log_step2();
    break;

   case 3 :
    VCU_CS75_12_27_test_log_step3();
    break;

   case 4 :
    VCU_CS75_12_27_test_log_step4();
    break;

   case 5 :
    VCU_CS75_12_27_test_log_step5();
    break;

   case 6 :
    VCU_CS75_12_27_test_log_step6();
    break;

   case 7 :
    VCU_CS75_12_27_test_log_step7();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void VCU_CS75_12_27_test_log_initialize(void)
{
  /* Start for S-Function (fcncallgen): '<Root>/20ms' incorporates:
   *  Start for SubSystem: '<Root>/长安CS75底盘程序，20ms一次'
   */

  /* Start for Atomic SubSystem: '<S2>/Input' */

  /* Start for S-Function (ec5744_canreceiveslb): '<S67>/CANReceive' */
  ec_buffer_init(0,0,0,529);

  /* Start for S-Function (ec5744_canreceiveslb): '<S81>/CANReceive' */
  ec_buffer_init(1,23,0,648);

  /* Start for S-Function (ec5744_canreceiveslb): '<S82>/CANReceive' */
  ec_buffer_init(1,24,0,808);

  /* Start for S-Function (ec5744_canreceiveslb): '<S83>/CANReceive' */
  ec_buffer_init(1,25,0,840);

  /* Start for S-Function (ec5744_canreceiveslb): '<S84>/CANReceive' */
  ec_buffer_init(1,26,0,991);

  /* Start for S-Function (ec5744_canreceiveslb): '<S85>/CANReceive' */
  ec_buffer_init(1,0,0,517);

  /* Start for S-Function (ec5744_canreceiveslb): '<S86>/CANReceive' */
  ec_buffer_init(1,1,0,597);

  /* Start for S-Function (ec5744_canreceiveslb): '<S87>/CANReceive' */
  ec_buffer_init(1,2,0,613);

  /* Start for S-Function (ec5744_canreceiveslb): '<S88>/CANReceive' */
  ec_buffer_init(1,3,0,630);

  /* Start for S-Function (ec5744_canreceiveslb): '<S89>/CANReceive' */
  ec_buffer_init(1,4,0,598);

  /* Start for S-Function (ec5744_canreceiveslb): '<S90>/CANReceive' */
  ec_buffer_init(1,5,0,522);

  /* Start for S-Function (ec5744_canreceiveslb): '<S91>/CANReceive' */
  ec_buffer_init(1,6,0,538);

  /* Start for S-Function (ec5744_canreceiveslb): '<S92>/CANReceive' */
  ec_buffer_init(1,7,0,631);

  /* Start for S-Function (ec5744_canreceiveslb): '<S93>/CANReceive' */
  ec_buffer_init(1,16,0,640);

  /* Start for S-Function (ec5744_canreceiveslb): '<S94>/CANReceive' */
  ec_buffer_init(1,17,0,641);

  /* Start for S-Function (ec5744_canreceiveslb): '<S95>/CANReceive' */
  ec_buffer_init(1,18,0,647);

  /* Start for S-Function (ec5744_canreceiveslb): '<S96>/CANReceive' */
  ec_buffer_init(1,27,0,523);

  /* Start for S-Function (ec5744_canreceiveslb): '<S97>/CANReceive' */
  ec_buffer_init(1,29,0,776);

  /* Start for S-Function (ec5744_canreceiveslb): '<S98>/CANReceive' */
  ec_buffer_init(1,28,0,818);

  /* Start for S-Function (ec5744_canreceiveslb): '<S99>/CANReceive' */
  ec_buffer_init(1,30,0,886);

  /* Start for S-Function (ec5744_canreceiveslb): '<S100>/CANReceive' */
  ec_buffer_init(1,31,0,930);

  /* Start for S-Function (ec5744_canreceiveslb): '<S101>/CANReceive' */
  ec_buffer_init(1,32,0,1383);

  /* Start for S-Function (ec5744_canreceiveslb): '<S102>/CANReceive' */
  ec_buffer_init(1,33,0,1280);

  /* Start for S-Function (ec5744_canreceiveslb): '<S103>/CANReceive' */
  ec_buffer_init(1,36,0,878);

  /* Start for S-Function (ec5744_canreceiveslb): '<S104>/CANReceive' */
  ec_buffer_init(1,19,0,264);

  /* Start for S-Function (ec5744_canreceiveslb): '<S105>/CANReceive' */
  ec_buffer_init(1,20,0,952);

  /* Start for S-Function (ec5744_canreceiveslb): '<S106>/CANReceive' */
  ec_buffer_init(1,21,0,5);

  /* Start for S-Function (ec5744_canreceiveslb): '<S107>/CANReceive' */
  ec_buffer_init(1,22,0,646);

  /* End of Start for SubSystem: '<S2>/Input' */

  /* Start for Atomic SubSystem: '<S2>/APP' */
  /* Start for Constant: '<S53>/Constant' */
  Server_CommunicationStatus = 1.0;

  /* End of Start for SubSystem: '<S2>/APP' */
  /* Start for S-Function (ec5744_cantransmitslb): '<S697>/CANTransmit' */
  ec_buffer_init(0,8,1,1297U);

  /* Start for S-Function (ec5744_cantransmitslb): '<S702>/CANTransmit' */
  ec_buffer_init(0,11,0,1537U);

  /* Start for S-Function (ec5744_cantransmitslb): '<S744>/CANTransmit' */
  ec_buffer_init(1,13,0,653U);

  /* Start for S-Function (ec5744_cantransmitslb): '<S745>/CANTransmit' */
  ec_buffer_init(1,8,0,740U);

  /* Start for S-Function (ec5744_cantransmitslb): '<S746>/CANTransmit' */
  ec_buffer_init(1,9,0,741U);

  /* Start for S-Function (ec5744_cantransmitslb): '<S747>/CANTransmit' */
  ec_buffer_init(1,60,0,1538U);

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

/* File trailer for ECUCoder generated file VCU_CS75_12_27_test_log.c.
 *
 * [EOF]
 */
