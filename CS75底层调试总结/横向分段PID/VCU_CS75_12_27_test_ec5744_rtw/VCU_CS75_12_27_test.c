/*
 * Code generated for Simulink model VCU_CS75_12_27_test.
 *
 * FILE    : VCU_CS75_12_27_test.c
 *
 * VERSION : 1.2768
 *
 * DATE    : Wed Dec 30 13:20:36 2020
 *
 * Copyright 2011-2017 ECUCoder. All Rights Reserved.
 */

#include "VCU_CS75_12_27_test.h"
#include "VCU_CS75_12_27_test_private.h"

/* #include "myinclude.h" */

/* Named constants for Chart: '<S29>/Chart' */
#define VCU_CS75_12_27__IN_System_State ((uint8_T)1U)
#define VCU_CS75_12_27_t_IN_AutoDriving ((uint8_T)1U)
#define VCU_CS75_12_27_test_IN_Error   ((uint8_T)2U)
#define VCU_CS75_12_27_test_IN_TakeOver ((uint8_T)4U)
#define VCU_CS75__IN_INIT_ManualDriving ((uint8_T)3U)

/* Exported block parameters */
real_T D1 = 0.0;                       /* Variable: D1
                                        * Referenced by: '<S32>/ECCalVar9'
                                        */
real_T D2 = 0.0;                       /* Variable: D2
                                        * Referenced by: '<S32>/ECCalVar10'
                                        */
real_T D3 = 0.0;                       /* Variable: D3
                                        * Referenced by: '<S32>/ECCalVar11'
                                        */
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
real_T P1 = 0.0;                       /* Variable: P1
                                        * Referenced by: '<S32>/ECCalVar'
                                        */
real_T P2 = 0.0;                       /* Variable: P2
                                        * Referenced by: '<S32>/ECCalVar2'
                                        */
real_T P3 = 0.0;                       /* Variable: P3
                                        * Referenced by: '<S32>/ECCalVar4'
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
B_VCU_CS75_12_27_test_T VCU_CS75_12_27_test_B;

/* Block states (auto storage) */
DW_VCU_CS75_12_27_test_T VCU_CS75_12_27_test_DW;

/* Real-time model */
RT_MODEL_VCU_CS75_12_27_test_T VCU_CS75_12_27_test_M_;
RT_MODEL_VCU_CS75_12_27_test_T *const VCU_CS75_12_27_test_M =
  &VCU_CS75_12_27_test_M_;
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
      VCU_CS75_12_27_test_B.CANReceive_o3= 256;
      VCU_CS75_12_27_test_B.CANReceive_o5= 8;
      VCU_CS75_12_27_test_B.CANReceive_o2= ec_can_receive(2,0, CAN2BUF0RX);
      VCU_CS75_12_27_test_B.CANReceive_o4[0]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_12_27_test_B.CANReceive_o4[1]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_12_27_test_B.CANReceive_o4[2]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_12_27_test_B.CANReceive_o4[3]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_12_27_test_B.CANReceive_o4[4]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_12_27_test_B.CANReceive_o4[5]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_12_27_test_B.CANReceive_o4[6]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_12_27_test_B.CANReceive_o4[7]= CAN2BUF0RX[can2buf0looprx];
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
void VCU_CS75_12_27_test_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(VCU_CS75_12_27_test_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(VCU_CS75_12_27_test_M, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(VCU_CS75_12_27_test_M, 3));
  eventFlags[4] = ((boolean_T)rtmStepTask(VCU_CS75_12_27_test_M, 4));
  eventFlags[5] = ((boolean_T)rtmStepTask(VCU_CS75_12_27_test_M, 5));
  eventFlags[6] = ((boolean_T)rtmStepTask(VCU_CS75_12_27_test_M, 6));
  eventFlags[7] = ((boolean_T)rtmStepTask(VCU_CS75_12_27_test_M, 7));
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
  (VCU_CS75_12_27_test_M->Timing.TaskCounters.TID[1])++;
  if ((VCU_CS75_12_27_test_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.001s, 0.0s] */
    VCU_CS75_12_27_test_M->Timing.TaskCounters.TID[1] = 0;
  }

  (VCU_CS75_12_27_test_M->Timing.TaskCounters.TID[2])++;
  if ((VCU_CS75_12_27_test_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.005s, 0.0s] */
    VCU_CS75_12_27_test_M->Timing.TaskCounters.TID[2] = 0;
  }

  (VCU_CS75_12_27_test_M->Timing.TaskCounters.TID[3])++;
  if ((VCU_CS75_12_27_test_M->Timing.TaskCounters.TID[3]) > 19) {/* Sample time: [0.01s, 0.0s] */
    VCU_CS75_12_27_test_M->Timing.TaskCounters.TID[3] = 0;
  }

  (VCU_CS75_12_27_test_M->Timing.TaskCounters.TID[4])++;
  if ((VCU_CS75_12_27_test_M->Timing.TaskCounters.TID[4]) > 39) {/* Sample time: [0.02s, 0.0s] */
    VCU_CS75_12_27_test_M->Timing.TaskCounters.TID[4] = 0;
  }

  (VCU_CS75_12_27_test_M->Timing.TaskCounters.TID[5])++;
  if ((VCU_CS75_12_27_test_M->Timing.TaskCounters.TID[5]) > 99) {/* Sample time: [0.05s, 0.0s] */
    VCU_CS75_12_27_test_M->Timing.TaskCounters.TID[5] = 0;
  }

  (VCU_CS75_12_27_test_M->Timing.TaskCounters.TID[6])++;
  if ((VCU_CS75_12_27_test_M->Timing.TaskCounters.TID[6]) > 199) {/* Sample time: [0.1s, 0.0s] */
    VCU_CS75_12_27_test_M->Timing.TaskCounters.TID[6] = 0;
  }

  (VCU_CS75_12_27_test_M->Timing.TaskCounters.TID[7])++;
  if ((VCU_CS75_12_27_test_M->Timing.TaskCounters.TID[7]) > 999) {/* Sample time: [0.5s, 0.0s] */
    VCU_CS75_12_27_test_M->Timing.TaskCounters.TID[7] = 0;
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
void VCU_CS75_12_27_test_step0(void)   /* Sample time: [0.0005s, 0.0s] */
{
  {                                    /* Sample time: [0.0005s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void VCU_CS75_12_27_test_step1(void)   /* Sample time: [0.001s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S6>/Function-Call Generator' incorporates:
   *  SubSystem: '<S6>/CCPBackground'
   */

  /* S-Function (ec5744_ccpslb): '<S21>/CCPBackground' */
  ccpBackground();
}

/* Model step function for TID2 */
void VCU_CS75_12_27_test_step2(void)   /* Sample time: [0.005s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S4>/5ms' incorporates:
   *  SubSystem: '<S4>/daq5ms'
   */

  /* S-Function (ec5744_ccpslb1): '<S19>/CCPDAQ' */
  ccpDaq(0);
}

/* Model step function for TID3 */
void VCU_CS75_12_27_test_step3(void)   /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S4>/10ms' incorporates:
   *  SubSystem: '<S4>/daq10ms'
   */

  /* S-Function (ec5744_ccpslb1): '<S16>/CCPDAQ' */
  ccpDaq(1);
}

/* Model step function for TID4 */
void VCU_CS75_12_27_test_step4(void)   /* Sample time: [0.02s, 0.0s] */
{
  int_T idxDelay;
  uint32_T rtb_LAS_SteeringTorqueReq_L;
  uint32_T rtb_ACC_RollingCounter_L;
  uint8_T rtb_ACC_CDDAxEnable_Convert;
  boolean_T rtb_ErrorROP;
  real32_T rtb_Error;
  uint32_T rtb_ACC_RollingCounter_Convert1;
  uint8_T rtb_ACC_ACCTargetAcceleration_C;
  uint8_T rtb_ACC_AccTrqReqEnable_Convert;
  uint8_T rtb_ACC_AccTorqueReqBitCov;
  real_T rtb_P6_Value;
  real_T rtb_Memory2;
  real32_T rtb_Memory1_e;
  real_T rtb_APP_Input_idx_99;
  real_T rtb_APP_Input_idx_2;
  real_T rtb_APP_Input_idx_217;
  real_T rtb_APP_Input_idx_19;
  real_T rtb_APP_Input_idx_20;
  real_T rtb_APP_Input_idx_8;
  real_T rtb_APP_Input_idx_9;
  real_T rtb_APP_Input_idx_66;
  real_T rtb_APP_Input_idx_63;
  real_T rtb_APP_Input_idx_3;
  real_T rtb_APP_Input_idx_17;
  real_T rtb_APP_Input_idx_1;
  real_T rtb_APP_Input_idx_12;
  real_T rtb_APP_Input_idx_0;
  real_T rtb_APP_Input_idx_39;
  real_T rtb_APP_Input_idx_79;
  real_T rtb_APP_Input_idx_29;

  /* S-Function (fcncallgen): '<Root>/20ms' incorporates:
   *  SubSystem: '<Root>/长安CS75底盘程序，20ms一次'
   */
  /* Outputs for Atomic SubSystem: '<S2>/Input' */

  /* S-Function (ec5744_swislbu3): '<S60>/SwitchInput' */

  /* Read the the value of the specified switch input */
  VCU_CS75_12_27_test_B.P6_Value_h= ec_gpio_read(92);

  /* DataTypeConversion: '<S60>/Data Type Conversion' */
  rtb_P6_Value = (real_T)VCU_CS75_12_27_test_B.P6_Value_h;

  /* MATLAB Function: '<S60>/MATLAB Function' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/Input/ADC_Input/MATLAB Function': '<S65>:1' */
  if (rtb_P6_Value == 1.0) {
    /* '<S65>:1:2' */
    /* '<S65>:1:3' */
    P6_Value = 0.0;
  } else {
    /* '<S65>:1:5' */
    P6_Value = 1.0;
  }

  /* End of MATLAB Function: '<S60>/MATLAB Function' */

  /* S-Function (ec5744_canreceiveslb): '<S66>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF0RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can0buf0looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_o= 529;
    VCU_CS75_12_27_test_B.CANReceive_o5_o= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_a4= ec_can_receive(0,0, CAN0BUF0RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_d[0]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_d[1]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_d[2]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_d[3]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_d[4]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_d[5]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_d[6]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_d[7]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
  }

  /* Call the system: <S66>/ReceiveMessages */

  /* Output and update for function-call system: '<S66>/ReceiveMessages' */
  {
    real_T rtb_target_steering_sat;
    int32_T rtb_target_steering_L;
    real32_T rtb_throttlevbrake_position_sat;

    /* Outputs for Enabled SubSystem: '<S67>/Subsystem' incorporates:
     *  EnablePort: '<S68>/Enable'
     */
    if (VCU_CS75_12_27_test_B.CANReceive_o2_a4 > 0) {
      /* Product: '<S70>/Vxinput8_P' incorporates:
       *  Constant: '<S70>/Vxinput8_C'
       */
      rtb_target_steering_sat = (real_T)VCU_CS75_12_27_test_B.CANReceive_o4_d[7]
        * 256.0;

      /* Sum: '<S70>/Vxinput8_Ad' */
      rtb_target_steering_sat += (real_T)VCU_CS75_12_27_test_B.CANReceive_o4_d[6];

      /* DataTypeConversion: '<S70>/Vx_Convert' */
      rtb_target_steering_L = (int32_T)rtb_target_steering_sat;

      /* DataTypeConversion: '<S70>/Vxcv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* Gain: '<S70>/Vx_F' */
      rtb_throttlevbrake_position_sat *= 0.00610360876F;

      /* Sum: '<S70>/Vx_Ad' incorporates:
       *  Constant: '<S70>/Vx_O'
       */
      rtb_throttlevbrake_position_sat += -200.0F;

      /* Saturate: '<S70>/Vx_sat' */
      if (rtb_throttlevbrake_position_sat > 200.0F) {
        rtb_throttlevbrake_position_sat = 200.0F;
      }

      /* End of Saturate: '<S70>/Vx_sat' */

      /* DataStoreWrite: '<S68>/Data Store Write' */
      Vx_out = rtb_throttlevbrake_position_sat;

      /* DataTypeConversion: '<S70>/mission_Convert' */
      rtb_target_steering_L = VCU_CS75_12_27_test_B.CANReceive_o4_d[5];

      /* S-Function (sfix_bitop): '<S70>/mission_L' */
      rtb_target_steering_L &= 240U;

      /* ArithShift: '<S70>/mission_S' */
      rtb_target_steering_L = (int32_T)((uint32_T)rtb_target_steering_L >> 4);

      /* DataTypeConversion: '<S70>/missioncv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* Saturate: '<S70>/mission_sat' */
      if (rtb_throttlevbrake_position_sat > 7.0F) {
        rtb_throttlevbrake_position_sat = 7.0F;
      }

      /* End of Saturate: '<S70>/mission_sat' */

      /* DataStoreWrite: '<S68>/Data Store Write1' */
      mission_out = rtb_throttlevbrake_position_sat;

      /* DataTypeConversion: '<S70>/SCS_Convert' */
      rtb_target_steering_L = VCU_CS75_12_27_test_B.CANReceive_o4_d[5];

      /* S-Function (sfix_bitop): '<S70>/SCS_L' */
      rtb_target_steering_L &= 8U;

      /* ArithShift: '<S70>/SCS_S' */
      rtb_target_steering_L = (int32_T)((uint32_T)rtb_target_steering_L >> 3);

      /* DataTypeConversion: '<S70>/SCScv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* DataStoreWrite: '<S68>/Data Store Write2' */
      SCS_out = rtb_throttlevbrake_position_sat;

      /* DataTypeConversion: '<S70>/finish_Convert' */
      rtb_target_steering_L = VCU_CS75_12_27_test_B.CANReceive_o4_d[5];

      /* S-Function (sfix_bitop): '<S70>/finish_L' */
      rtb_target_steering_L &= 4U;

      /* ArithShift: '<S70>/finish_S' */
      rtb_target_steering_L = (int32_T)((uint32_T)rtb_target_steering_L >> 2);

      /* DataTypeConversion: '<S70>/finishcv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* DataStoreWrite: '<S68>/Data Store Write3' */
      finish_out = rtb_throttlevbrake_position_sat;

      /* DataTypeConversion: '<S70>/tap_Convert' */
      rtb_target_steering_L = VCU_CS75_12_27_test_B.CANReceive_o4_d[5];

      /* S-Function (sfix_bitop): '<S70>/tap_L' */
      rtb_target_steering_L &= 3U;

      /* DataTypeConversion: '<S70>/tapcv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* DataStoreWrite: '<S68>/Data Store Write4' */
      tap_out = rtb_throttlevbrake_position_sat;

      /* DataTypeConversion: '<S70>/cones_count_all_Convert' */
      rtb_target_steering_L = VCU_CS75_12_27_test_B.CANReceive_o4_d[4];

      /* DataTypeConversion: '<S70>/cones_count_allcv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* DataStoreWrite: '<S68>/Data Store Write5' */
      cones_count_all_out = rtb_throttlevbrake_position_sat;

      /* DataTypeConversion: '<S70>/cones_count_actual_Convert' */
      rtb_target_steering_L = VCU_CS75_12_27_test_B.CANReceive_o4_d[3];

      /* DataTypeConversion: '<S70>/cones_count_actualcv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* DataStoreWrite: '<S68>/Data Store Write6' */
      cones_count_actual_out = rtb_throttlevbrake_position_sat;

      /* Product: '<S70>/throttlevbrake_positioninput3_P' incorporates:
       *  Constant: '<S70>/throttlevbrake_positioninput3_C'
       */
      rtb_target_steering_sat = (real_T)VCU_CS75_12_27_test_B.CANReceive_o4_d[2]
        * 256.0;

      /* Sum: '<S70>/throttlevbrake_positioninput3_Ad' */
      rtb_target_steering_sat += (real_T)VCU_CS75_12_27_test_B.CANReceive_o4_d[1];

      /* DataTypeConversion: '<S70>/throttlevbrake_position_Convert' */
      rtb_target_steering_L = (int32_T)rtb_target_steering_sat;

      /* S-Function (sfix_bitop): '<S70>/throttlevbrake_position_L' */
      rtb_target_steering_L &= 65520U;

      /* ArithShift: '<S70>/throttlevbrake_position_S' */
      rtb_target_steering_L = (int32_T)((uint32_T)rtb_target_steering_L >> 4);

      /* DataTypeConversion: '<S70>/throttlevbrake_positioncv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* Gain: '<S70>/throttlevbrake_position_F' */
      rtb_throttlevbrake_position_sat *= 0.0488400497F;

      /* Sum: '<S70>/throttlevbrake_position_Ad' incorporates:
       *  Constant: '<S70>/throttlevbrake_position_O'
       */
      rtb_throttlevbrake_position_sat += -100.0F;

      /* Saturate: '<S70>/throttlevbrake_position_sat' */
      if (rtb_throttlevbrake_position_sat > 100.0F) {
        rtb_throttlevbrake_position_sat = 100.0F;
      }

      /* End of Saturate: '<S70>/throttlevbrake_position_sat' */

      /* DataTypeConversion: '<S68>/Data Type Conversion' */
      rtb_target_steering_sat = rtb_throttlevbrake_position_sat;

      /* MATLAB Function: '<S68>/MATLAB Function1' */
      /* MATLAB Function '长安CS75底盘程序，20ms一次/Input/CAN0_Rx/a1_211/ReceiveMessages/Subsystem/MATLAB Function1': '<S69>:1' */
      /* '<S69>:1:2' */
      if (rtb_target_steering_sat < 0.0) {
        /* '<S69>:1:3' */
        /* '<S69>:1:4' */
        rtb_target_steering_sat /= 20.0;
      }

      /* End of MATLAB Function: '<S68>/MATLAB Function1' */

      /* SignalConversion: '<S68>/Signal Conversion' incorporates:
       *  Constant: '<S68>/Constant2'
       */
      VCU_CS75_12_27_test_B.AutoDrivingReady = 0.0;

      /* SignalConversion: '<S68>/Signal Conversion' */
      VCU_CS75_12_27_test_B.RemoteAcclPosition = rtb_target_steering_sat;

      /* Product: '<S70>/target_steeringinput2_P' incorporates:
       *  Constant: '<S70>/target_steeringinput2_C'
       */
      rtb_target_steering_sat = (real_T)VCU_CS75_12_27_test_B.CANReceive_o4_d[1]
        * 256.0;

      /* Sum: '<S70>/target_steeringinput2_Ad' */
      rtb_target_steering_sat += (real_T)VCU_CS75_12_27_test_B.CANReceive_o4_d[0];

      /* DataTypeConversion: '<S70>/target_steering_Convert' */
      rtb_target_steering_L = (int32_T)rtb_target_steering_sat;

      /* S-Function (sfix_bitop): '<S70>/target_steering_L' */
      rtb_target_steering_L &= 4095U;

      /* DataTypeConversion: '<S70>/target_steeringcv' */
      rtb_target_steering_sat = rtb_target_steering_L;

      /* Gain: '<S70>/target_steering_F' */
      rtb_target_steering_sat *= 0.0488400488400488;

      /* Sum: '<S70>/target_steering_Ad' incorporates:
       *  Constant: '<S70>/target_steering_O'
       */
      rtb_target_steering_sat += -100.0;

      /* Saturate: '<S70>/target_steering_sat' */
      if (rtb_target_steering_sat > 99.9999999999998) {
        rtb_target_steering_sat = 99.9999999999998;
      }

      /* End of Saturate: '<S70>/target_steering_sat' */

      /* SignalConversion: '<S68>/Signal Conversion' */
      VCU_CS75_12_27_test_B.LaterlAngleCommand = rtb_target_steering_sat;

      /* SignalConversion: '<S68>/Signal Conversion' incorporates:
       *  Constant: '<S68>/Constant'
       */
      VCU_CS75_12_27_test_B.A1_Message_Counter = 0.0;

      /* SignalConversion: '<S68>/Signal Conversion' incorporates:
       *  Constant: '<S68>/Constant1'
       */
      VCU_CS75_12_27_test_B.A1_Checksum = 0.0;
    }

    /* End of Outputs for SubSystem: '<S67>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S80>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF23RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf23looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_ik= 648;
    VCU_CS75_12_27_test_B.CANReceive_o5_ox= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_i= ec_can_receive(1,23, CAN1BUF23RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_g[0]= CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_g[1]= CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_g[2]= CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_g[3]= CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_g[4]= CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_g[5]= CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_g[6]= CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_g[7]= CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
  }

  /* Call the system: <S80>/ReceiveMessages */

  /* Output and update for function-call system: '<S80>/ReceiveMessages' */
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

    /* Outputs for Enabled SubSystem: '<S107>/Subsystem' incorporates:
     *  EnablePort: '<S108>/Enable'
     */
    if (VCU_CS75_12_27_test_B.CANReceive_o2_i > 0) {
      /* DataTypeConversion: '<S109>/BCM_BuzzerWarningMode_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_g[7];

      /* S-Function (sfix_bitop): '<S109>/BCM_BuzzerWarningMode_L' */
      rtb_BCM_emergencylightstatus_L &= 31U;

      /* Sum: '<S109>/BCM_BuzzerWarningMode_Ad' */
      rtb_BCM_BuzzerWarningMode_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S109>/BCM_BuzzerWarningMode_sat' */
      u0 = rtb_BCM_BuzzerWarningMode_sat;
      rtb_BCM_BuzzerWarningMode_sat = (int32_T)u0;

      /* DataTypeConversion: '<S109>/BCM_DriverDoorLockStatus_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_g[5];

      /* S-Function (sfix_bitop): '<S109>/BCM_DriverDoorLockStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 3U;

      /* Sum: '<S109>/BCM_DriverDoorLockStatus_Ad' */
      rtb_BCM_DriverDoorLockStatus_sa = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S109>/BCM_DriverDoorLockStatus_sat' */
      u0 = rtb_BCM_DriverDoorLockStatus_sa;
      rtb_BCM_DriverDoorLockStatus_sa = (int32_T)u0;

      /* DataTypeConversion: '<S109>/BCM_DriverDoorStatus_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_g[2];

      /* S-Function (sfix_bitop): '<S109>/BCM_DriverDoorStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 128U;

      /* ArithShift: '<S109>/BCM_DriverDoorStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 7);

      /* Sum: '<S109>/BCM_DriverDoorStatus_Ad' */
      rtb_BCM_DriverDoorStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S109>/BCM_DriverDoorStatus_sat' */
      u0 = rtb_BCM_DriverDoorStatus_sat;
      rtb_BCM_DriverDoorStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S109>/BCM_FrontWashStatus_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_g[1];

      /* S-Function (sfix_bitop): '<S109>/BCM_FrontWashStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 3U;

      /* Sum: '<S109>/BCM_FrontWashStatus_Ad' */
      rtb_BCM_FrontWashStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S109>/BCM_FrontWashStatus_sat' */
      u0 = rtb_BCM_FrontWashStatus_sat;
      rtb_BCM_FrontWashStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S109>/BCM_FrontWiperStatus_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_g[5];

      /* S-Function (sfix_bitop): '<S109>/BCM_FrontWiperStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 192U;

      /* ArithShift: '<S109>/BCM_FrontWiperStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 6);

      /* Sum: '<S109>/BCM_FrontWiperStatus_Ad' */
      rtb_BCM_FrontWiperStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S109>/BCM_FrontWiperStatus_sat' */
      u0 = rtb_BCM_FrontWiperStatus_sat;
      rtb_BCM_FrontWiperStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S109>/BCM_HoodStatus_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_g[2];

      /* S-Function (sfix_bitop): '<S109>/BCM_HoodStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 4U;

      /* ArithShift: '<S109>/BCM_HoodStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 2);

      /* Sum: '<S109>/BCM_HoodStatus_Ad' */
      rtb_BCM_HoodStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S109>/BCM_HoodStatus_sat' */
      u0 = rtb_BCM_HoodStatus_sat;
      rtb_BCM_HoodStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S109>/BCM_LatchOverheatProtect_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_g[7];

      /* S-Function (sfix_bitop): '<S109>/BCM_LatchOverheatProtect_L' */
      rtb_BCM_emergencylightstatus_L &= 64U;

      /* ArithShift: '<S109>/BCM_LatchOverheatProtect_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 6);

      /* Sum: '<S109>/BCM_LatchOverheatProtect_Ad' */
      rtb_BCM_LatchOverheatProtect_sa = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S109>/BCM_LatchOverheatProtect_sat' */
      u0 = rtb_BCM_LatchOverheatProtect_sa;
      rtb_BCM_LatchOverheatProtect_sa = (int32_T)u0;

      /* DataTypeConversion: '<S109>/BCM_LeftRearDoorStatus_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_g[2];

      /* S-Function (sfix_bitop): '<S109>/BCM_LeftRearDoorStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 32U;

      /* ArithShift: '<S109>/BCM_LeftRearDoorStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 5);

      /* Sum: '<S109>/BCM_LeftRearDoorStatus_Ad' */
      rtb_BCM_LeftRearDoorStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S109>/BCM_LeftRearDoorStatus_sat' */
      u0 = rtb_BCM_LeftRearDoorStatus_sat;
      rtb_BCM_LeftRearDoorStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S109>/BCM_PassengerDoorLockStatus_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_g[4];

      /* S-Function (sfix_bitop): '<S109>/BCM_PassengerDoorLockStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 12U;

      /* ArithShift: '<S109>/BCM_PassengerDoorLockStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 2);

      /* Sum: '<S109>/BCM_PassengerDoorLockStatus_Ad' */
      rtb_BCM_PassengerDoorLockStatus = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S109>/BCM_PassengerDoorLockStatus_sat' */
      u0 = rtb_BCM_PassengerDoorLockStatus;
      rtb_BCM_PassengerDoorLockStatus = (int32_T)u0;

      /* DataTypeConversion: '<S109>/BCM_PassengerDoorStatus_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_g[2];

      /* S-Function (sfix_bitop): '<S109>/BCM_PassengerDoorStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 64U;

      /* ArithShift: '<S109>/BCM_PassengerDoorStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 6);

      /* Sum: '<S109>/BCM_PassengerDoorStatus_Ad' */
      rtb_BCM_PassengerDoorStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S109>/BCM_PassengerDoorStatus_sat' */
      u0 = rtb_BCM_PassengerDoorStatus_sat;
      rtb_BCM_PassengerDoorStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S109>/BCM_PowerStatusFeedback_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_g[5];

      /* S-Function (sfix_bitop): '<S109>/BCM_PowerStatusFeedback_L' */
      rtb_BCM_emergencylightstatus_L &= 12U;

      /* ArithShift: '<S109>/BCM_PowerStatusFeedback_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 2);

      /* Sum: '<S109>/BCM_PowerStatusFeedback_Ad' */
      rtb_BCM_PowerStatusFeedback_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S109>/BCM_PowerStatusFeedback_sat' */
      u0 = rtb_BCM_PowerStatusFeedback_sat;
      rtb_BCM_PowerStatusFeedback_sat = (int32_T)u0;

      /* DataTypeConversion: '<S109>/BCM_RearWiperStatus_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_g[5];

      /* S-Function (sfix_bitop): '<S109>/BCM_RearWiperStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 16U;

      /* ArithShift: '<S109>/BCM_RearWiperStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 4);

      /* Sum: '<S109>/BCM_RearWiperStatus_Ad' */
      rtb_BCM_RearWiperStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S109>/BCM_RearWiperStatus_sat' */
      u0 = rtb_BCM_RearWiperStatus_sat;
      rtb_BCM_RearWiperStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S109>/BCM_ReversePosition_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_g[6];

      /* S-Function (sfix_bitop): '<S109>/BCM_ReversePosition_L' */
      rtb_BCM_emergencylightstatus_L &= 1U;

      /* Sum: '<S109>/BCM_ReversePosition_Ad' */
      rtb_BCM_ReversePosition_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S109>/BCM_ReversePosition_sat' */
      u0 = rtb_BCM_ReversePosition_sat;
      rtb_BCM_ReversePosition_sat = (int32_T)u0;

      /* DataTypeConversion: '<S109>/BCM_RightRearDoorStatus_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_g[2];

      /* S-Function (sfix_bitop): '<S109>/BCM_RightRearDoorStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 16U;

      /* ArithShift: '<S109>/BCM_RightRearDoorStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 4);

      /* Sum: '<S109>/BCM_RightRearDoorStatus_Ad' */
      rtb_BCM_RightRearDoorStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S109>/BCM_RightRearDoorStatus_sat' */
      u0 = rtb_BCM_RightRearDoorStatus_sat;
      rtb_BCM_RightRearDoorStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S109>/BCM_SystemFailureFlag_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_g[7];

      /* S-Function (sfix_bitop): '<S109>/BCM_SystemFailureFlag_L' */
      rtb_BCM_emergencylightstatus_L &= 32U;

      /* ArithShift: '<S109>/BCM_SystemFailureFlag_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 5);

      /* Sum: '<S109>/BCM_SystemFailureFlag_Ad' */
      rtb_BCM_SystemFailureFlag_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S109>/BCM_SystemFailureFlag_sat' */
      u0 = rtb_BCM_SystemFailureFlag_sat;
      rtb_BCM_SystemFailureFlag_sat = (int32_T)u0;

      /* DataTypeConversion: '<S109>/BCM_TrunkDoorStatus_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_g[2];

      /* S-Function (sfix_bitop): '<S109>/BCM_TrunkDoorStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 8U;

      /* ArithShift: '<S109>/BCM_TrunkDoorStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 3);

      /* Sum: '<S109>/BCM_TrunkDoorStatus_Ad' */
      rtb_BCM_TrunkDoorStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S109>/BCM_TrunkDoorStatus_sat' */
      u0 = rtb_BCM_TrunkDoorStatus_sat;
      rtb_BCM_TrunkDoorStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S109>/BCM_TurnIndicatorLeft_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_g[1];

      /* S-Function (sfix_bitop): '<S109>/BCM_TurnIndicatorLeft_L' */
      rtb_BCM_emergencylightstatus_L &= 192U;

      /* ArithShift: '<S109>/BCM_TurnIndicatorLeft_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 6);

      /* Sum: '<S109>/BCM_TurnIndicatorLeft_Ad' */
      rtb_BCM_TurnIndicatorLeft_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S109>/BCM_TurnIndicatorLeft_sat' */
      u0 = rtb_BCM_TurnIndicatorLeft_sat;
      rtb_BCM_TurnIndicatorLeft_sat = (int32_T)u0;

      /* DataTypeConversion: '<S109>/BCM_TurnIndicatorRight_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_g[1];

      /* S-Function (sfix_bitop): '<S109>/BCM_TurnIndicatorRight_L' */
      rtb_BCM_emergencylightstatus_L &= 48U;

      /* ArithShift: '<S109>/BCM_TurnIndicatorRight_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 4);

      /* Sum: '<S109>/BCM_TurnIndicatorRight_Ad' */
      rtb_BCM_TurnIndicatorRight_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S109>/BCM_TurnIndicatorRight_sat' */
      u0 = rtb_BCM_TurnIndicatorRight_sat;
      rtb_BCM_TurnIndicatorRight_sat = (int32_T)u0;

      /* DataTypeConversion: '<S109>/BCM_TurnLightSwitchSts_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_g[6];

      /* S-Function (sfix_bitop): '<S109>/BCM_TurnLightSwitchSts_L' */
      rtb_BCM_emergencylightstatus_L &= 12U;

      /* ArithShift: '<S109>/BCM_TurnLightSwitchSts_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 2);

      /* Sum: '<S109>/BCM_TurnLightSwitchSts_Ad' */
      rtb_BCM_TurnLightSwitchSts_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S109>/BCM_TurnLightSwitchSts_sat' */
      u0 = rtb_BCM_TurnLightSwitchSts_sat;
      rtb_BCM_TurnLightSwitchSts_sat = (int32_T)u0;

      /* DataTypeConversion: '<S109>/BCM_emergencylightstatus_Convert' */
      rtb_BCM_emergencylightstatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_g[4];

      /* S-Function (sfix_bitop): '<S109>/BCM_emergencylightstatus_L' */
      rtb_BCM_emergencylightstatus_L &= 48U;

      /* ArithShift: '<S109>/BCM_emergencylightstatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 4);

      /* Saturate: '<S109>/BCM_emergencylightstatus_sat' */
      u0 = rtb_BCM_emergencylightstatus_L;
      rtb_BCM_emergencylightstatus_L = (int32_T)u0;

      /* SignalConversion: '<S108>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_FrontWashStatus = rtb_BCM_FrontWashStatus_sat;

      /* SignalConversion: '<S108>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_PassengerDoorLockStatus =
        rtb_BCM_PassengerDoorLockStatus;

      /* SignalConversion: '<S108>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_emergencylightstatus =
        rtb_BCM_emergencylightstatus_L;

      /* SignalConversion: '<S108>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_DriverDoorLockStatus =
        rtb_BCM_DriverDoorLockStatus_sa;

      /* SignalConversion: '<S108>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_PowerStatusFeedback =
        rtb_BCM_PowerStatusFeedback_sat;

      /* SignalConversion: '<S108>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_RearWiperStatus = rtb_BCM_RearWiperStatus_sat;

      /* SignalConversion: '<S108>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_FrontWiperStatus = rtb_BCM_FrontWiperStatus_sat;

      /* SignalConversion: '<S108>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_ReversePosition = rtb_BCM_ReversePosition_sat;

      /* SignalConversion: '<S108>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_TurnLightSwitchSts =
        rtb_BCM_TurnLightSwitchSts_sat;

      /* SignalConversion: '<S108>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_BuzzerWarningMode =
        rtb_BCM_BuzzerWarningMode_sat;

      /* SignalConversion: '<S108>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_SystemFailureFlag =
        rtb_BCM_SystemFailureFlag_sat;

      /* SignalConversion: '<S108>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_TurnIndicatorRight =
        rtb_BCM_TurnIndicatorRight_sat;

      /* SignalConversion: '<S108>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_LatchOverheatProtect =
        rtb_BCM_LatchOverheatProtect_sa;

      /* SignalConversion: '<S108>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_TurnIndicatorLeft =
        rtb_BCM_TurnIndicatorLeft_sat;

      /* SignalConversion: '<S108>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_HoodStatus = rtb_BCM_HoodStatus_sat;

      /* SignalConversion: '<S108>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_TrunkDoorStatus = rtb_BCM_TrunkDoorStatus_sat;

      /* SignalConversion: '<S108>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_RightRearDoorStatus =
        rtb_BCM_RightRearDoorStatus_sat;

      /* SignalConversion: '<S108>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_LeftRearDoorStatus =
        rtb_BCM_LeftRearDoorStatus_sat;

      /* SignalConversion: '<S108>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_PassengerDoorStatus =
        rtb_BCM_PassengerDoorStatus_sat;

      /* SignalConversion: '<S108>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_DriverDoorStatus = rtb_BCM_DriverDoorStatus_sat;
    }

    /* End of Outputs for SubSystem: '<S107>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S81>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF24RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf24looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_oa= 808;
    VCU_CS75_12_27_test_B.CANReceive_o5_k= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_b= ec_can_receive(1,24, CAN1BUF24RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_f[0]= CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_f[1]= CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_f[2]= CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_f[3]= CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_f[4]= CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_f[5]= CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_f[6]= CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_f[7]= CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
  }

  /* Call the system: <S81>/ReceiveMessages */

  /* Output and update for function-call system: '<S81>/ReceiveMessages' */
  {
    int32_T rtb_LCM_ReverseLightSts_L;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S130>/Subsystem' incorporates:
     *  EnablePort: '<S131>/Enable'
     */
    if (VCU_CS75_12_27_test_B.CANReceive_o2_b > 0) {
      /* DataTypeConversion: '<S132>/LCM_LASSwitch_Convert' */
      rtb_LCM_ReverseLightSts_L = VCU_CS75_12_27_test_B.CANReceive_o4_f[2];

      /* S-Function (sfix_bitop): '<S132>/LCM_LASSwitch_L' */
      rtb_LCM_ReverseLightSts_L &= 3U;

      /* Saturate: '<S132>/LCM_LASSwitch_sat' */
      u0 = rtb_LCM_ReverseLightSts_L;
      rtb_LCM_ReverseLightSts_L = (int32_T)u0;

      /* SignalConversion: '<S131>/Signal Conversion' */
      VCU_CS75_12_27_test_B.LCM_DriveMode = 0.0;

      /* SignalConversion: '<S131>/Signal Conversion' */
      VCU_CS75_12_27_test_B.LCM_DRLSts = 0.0;

      /* SignalConversion: '<S131>/Signal Conversion' */
      VCU_CS75_12_27_test_B.LCM_LASSwitch = rtb_LCM_ReverseLightSts_L;

      /* SignalConversion: '<S131>/Signal Conversion' */
      VCU_CS75_12_27_test_B.LCM_RearRightTuningLightFaultSt = 0.0;

      /* SignalConversion: '<S131>/Signal Conversion' */
      VCU_CS75_12_27_test_B.LCM_RearLeftTuningLightFaultSts = 0.0;

      /* SignalConversion: '<S131>/Signal Conversion' */
      VCU_CS75_12_27_test_B.LCM_ReverseLightSts = 0.0;
    }

    /* End of Outputs for SubSystem: '<S130>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S82>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF25RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf25looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_g= 840;
    VCU_CS75_12_27_test_B.CANReceive_o5_op= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_h= ec_can_receive(1,25, CAN1BUF25RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_k[0]= CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_k[1]= CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_k[2]= CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_k[3]= CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_k[4]= CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_k[5]= CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_k[6]= CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_k[7]= CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
  }

  /* Call the system: <S82>/ReceiveMessages */

  /* Output and update for function-call system: '<S82>/ReceiveMessages' */
  {
    int32_T rtb_BCM_UnlockSignal_L;
    int32_T rtb_BCM_DriveMode_sat;
    int32_T rtb_BCM_LockSignal_sat;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S139>/Subsystem' incorporates:
     *  EnablePort: '<S140>/Enable'
     */
    if (VCU_CS75_12_27_test_B.CANReceive_o2_h > 0) {
      /* DataTypeConversion: '<S141>/BCM_DriveMode_Convert' */
      rtb_BCM_UnlockSignal_L = VCU_CS75_12_27_test_B.CANReceive_o4_k[5];

      /* S-Function (sfix_bitop): '<S141>/BCM_DriveMode_L' */
      rtb_BCM_UnlockSignal_L &= 6U;

      /* ArithShift: '<S141>/BCM_DriveMode_S' */
      rtb_BCM_UnlockSignal_L = (int32_T)((uint32_T)rtb_BCM_UnlockSignal_L >> 1);

      /* Sum: '<S141>/BCM_DriveMode_Ad' */
      rtb_BCM_DriveMode_sat = rtb_BCM_UnlockSignal_L;

      /* Saturate: '<S141>/BCM_DriveMode_sat' */
      u0 = rtb_BCM_DriveMode_sat;
      rtb_BCM_DriveMode_sat = (int32_T)u0;

      /* DataTypeConversion: '<S141>/BCM_LockSignal_Convert' */
      rtb_BCM_UnlockSignal_L = VCU_CS75_12_27_test_B.CANReceive_o4_k[5];

      /* S-Function (sfix_bitop): '<S141>/BCM_LockSignal_L' */
      rtb_BCM_UnlockSignal_L &= 24U;

      /* ArithShift: '<S141>/BCM_LockSignal_S' */
      rtb_BCM_UnlockSignal_L = (int32_T)((uint32_T)rtb_BCM_UnlockSignal_L >> 3);

      /* Sum: '<S141>/BCM_LockSignal_Ad' */
      rtb_BCM_LockSignal_sat = rtb_BCM_UnlockSignal_L;

      /* Saturate: '<S141>/BCM_LockSignal_sat' */
      u0 = rtb_BCM_LockSignal_sat;
      rtb_BCM_LockSignal_sat = (int32_T)u0;

      /* DataTypeConversion: '<S141>/BCM_UnlockSignal_Convert' */
      rtb_BCM_UnlockSignal_L = VCU_CS75_12_27_test_B.CANReceive_o4_k[5];

      /* S-Function (sfix_bitop): '<S141>/BCM_UnlockSignal_L' */
      rtb_BCM_UnlockSignal_L &= 96U;

      /* ArithShift: '<S141>/BCM_UnlockSignal_S' */
      rtb_BCM_UnlockSignal_L = (int32_T)((uint32_T)rtb_BCM_UnlockSignal_L >> 5);

      /* Saturate: '<S141>/BCM_UnlockSignal_sat' */
      u0 = rtb_BCM_UnlockSignal_L;
      rtb_BCM_UnlockSignal_L = (int32_T)u0;

      /* SignalConversion: '<S140>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_DriveMode_f = rtb_BCM_DriveMode_sat;

      /* SignalConversion: '<S140>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_LockSignal = rtb_BCM_LockSignal_sat;

      /* SignalConversion: '<S140>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_UnlockSignal = rtb_BCM_UnlockSignal_L;
    }

    /* End of Outputs for SubSystem: '<S139>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S83>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF26RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf26looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_n= 991;
    VCU_CS75_12_27_test_B.CANReceive_o5_p= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_m= ec_can_receive(1,26, CAN1BUF26RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_i[0]= CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_i[1]= CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_i[2]= CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_i[3]= CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_i[4]= CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_i[5]= CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_i[6]= CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_i[7]= CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
  }

  /* Call the system: <S83>/ReceiveMessages */

  /* Output and update for function-call system: '<S83>/ReceiveMessages' */
  {
    int32_T rtb_BCM_RollingCounter_L;
    int32_T rtb_BCM_AmbientLightColorFeedba;
    int32_T rtb_BCM_DriveModeFeedback_sat;
    int32_T rtb_BCM_DriveModeStatus_sat;
    int32_T rtb_BCM_EPSTorqueModeFeedback_s;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S145>/Subsystem' incorporates:
     *  EnablePort: '<S146>/Enable'
     */
    if (VCU_CS75_12_27_test_B.CANReceive_o2_m > 0) {
      /* DataTypeConversion: '<S147>/BCM_AmbientLightColorFeedback_Convert' */
      rtb_BCM_RollingCounter_L = VCU_CS75_12_27_test_B.CANReceive_o4_i[3];

      /* Sum: '<S147>/BCM_AmbientLightColorFeedback_Ad' */
      rtb_BCM_AmbientLightColorFeedba = rtb_BCM_RollingCounter_L;

      /* Saturate: '<S147>/BCM_AmbientLightColorFeedback_sat' */
      u0 = rtb_BCM_AmbientLightColorFeedba;
      rtb_BCM_AmbientLightColorFeedba = (int32_T)u0;

      /* DataTypeConversion: '<S147>/BCM_DriveModeFeedback_Convert' */
      rtb_BCM_RollingCounter_L = VCU_CS75_12_27_test_B.CANReceive_o4_i[2];

      /* S-Function (sfix_bitop): '<S147>/BCM_DriveModeFeedback_L' */
      rtb_BCM_RollingCounter_L &= 48U;

      /* ArithShift: '<S147>/BCM_DriveModeFeedback_S' */
      rtb_BCM_RollingCounter_L = (int32_T)((uint32_T)rtb_BCM_RollingCounter_L >>
        4);

      /* Sum: '<S147>/BCM_DriveModeFeedback_Ad' */
      rtb_BCM_DriveModeFeedback_sat = rtb_BCM_RollingCounter_L;

      /* Saturate: '<S147>/BCM_DriveModeFeedback_sat' */
      u0 = rtb_BCM_DriveModeFeedback_sat;
      rtb_BCM_DriveModeFeedback_sat = (int32_T)u0;

      /* DataTypeConversion: '<S147>/BCM_DriveModeStatus_Convert' */
      rtb_BCM_RollingCounter_L = VCU_CS75_12_27_test_B.CANReceive_o4_i[2];

      /* S-Function (sfix_bitop): '<S147>/BCM_DriveModeStatus_L' */
      rtb_BCM_RollingCounter_L &= 15U;

      /* Sum: '<S147>/BCM_DriveModeStatus_Ad' */
      rtb_BCM_DriveModeStatus_sat = rtb_BCM_RollingCounter_L;

      /* Saturate: '<S147>/BCM_DriveModeStatus_sat' */
      u0 = rtb_BCM_DriveModeStatus_sat;
      rtb_BCM_DriveModeStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S147>/BCM_EPSTorqueModeFeedback_Convert' */
      rtb_BCM_RollingCounter_L = VCU_CS75_12_27_test_B.CANReceive_o4_i[2];

      /* S-Function (sfix_bitop): '<S147>/BCM_EPSTorqueModeFeedback_L' */
      rtb_BCM_RollingCounter_L &= 192U;

      /* ArithShift: '<S147>/BCM_EPSTorqueModeFeedback_S' */
      rtb_BCM_RollingCounter_L = (int32_T)((uint32_T)rtb_BCM_RollingCounter_L >>
        6);

      /* Sum: '<S147>/BCM_EPSTorqueModeFeedback_Ad' */
      rtb_BCM_EPSTorqueModeFeedback_s = rtb_BCM_RollingCounter_L;

      /* Saturate: '<S147>/BCM_EPSTorqueModeFeedback_sat' */
      u0 = rtb_BCM_EPSTorqueModeFeedback_s;
      rtb_BCM_EPSTorqueModeFeedback_s = (int32_T)u0;

      /* DataTypeConversion: '<S147>/BCM_EPSTorqueMode_Convert' */
      rtb_BCM_RollingCounter_L = VCU_CS75_12_27_test_B.CANReceive_o4_i[1];

      /* S-Function (sfix_bitop): '<S147>/BCM_EPSTorqueMode_L' */
      rtb_BCM_RollingCounter_L &= 6U;

      /* ArithShift: '<S147>/BCM_EPSTorqueMode_S' */
      rtb_BCM_RollingCounter_L = (int32_T)((uint32_T)rtb_BCM_RollingCounter_L >>
        1);

      /* Saturate: '<S147>/BCM_EPSTorqueMode_sat' */
      u0 = rtb_BCM_RollingCounter_L;
      rtb_BCM_RollingCounter_L = (int32_T)u0;

      /* SignalConversion: '<S146>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_DriveMode = 0.0;

      /* SignalConversion: '<S146>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_EPSTorqueMode = rtb_BCM_RollingCounter_L;

      /* SignalConversion: '<S146>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_DriveModeStatus = rtb_BCM_DriveModeStatus_sat;

      /* SignalConversion: '<S146>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_DriveModeFeedback =
        rtb_BCM_DriveModeFeedback_sat;

      /* SignalConversion: '<S146>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_EPSTorqueModeFeedback =
        rtb_BCM_EPSTorqueModeFeedback_s;

      /* SignalConversion: '<S146>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_AmbientLightColorFeedback =
        rtb_BCM_AmbientLightColorFeedba;

      /* SignalConversion: '<S146>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_RollingCounter = 0.0;

      /* SignalConversion: '<S146>/Signal Conversion' */
      VCU_CS75_12_27_test_B.BCM_CRC_Checksum = 0.0;
    }

    /* End of Outputs for SubSystem: '<S145>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S84>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF0RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf0looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_e= 517;
    VCU_CS75_12_27_test_B.CANReceive_o5_h= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_g= ec_can_receive(1,0, CAN1BUF0RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_n[0]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_n[1]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_n[2]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_n[3]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_n[4]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_n[5]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_n[6]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_n[7]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
  }

  /* Call the system: <S84>/ReceiveMessages */

  /* Output and update for function-call system: '<S84>/ReceiveMessages' */
  {
    int32_T rtb_EMS_TorqFailure_L;
    int32_T rtb_EMS_ESPTorqReuestAvailabili;
    int32_T rtb_EMS_CheckSum_205_sat;
    real_T rtb_EMS_FrictionalTorq_sat;
    real_T rtb_EMS_IndicatedDriverReqTorq_;
    real_T rtb_EMS_IndicatedRealEngTorq_sa;
    real_T rtb_EMS_TorqFailurecv;
    int32_T rtb_EMS_RollingCounter_id205_sa;

    /* Outputs for Enabled SubSystem: '<S156>/Subsystem' incorporates:
     *  EnablePort: '<S157>/Enable'
     */
    if (VCU_CS75_12_27_test_B.CANReceive_o2_g > 0) {
      /* DataTypeConversion: '<S158>/EMS_CheckSum_205_Convert' */
      rtb_EMS_TorqFailure_L = VCU_CS75_12_27_test_B.CANReceive_o4_n[7];

      /* S-Function (sfix_bitop): '<S158>/EMS_CheckSum_205_L' */
      rtb_EMS_TorqFailure_L &= 240U;

      /* ArithShift: '<S158>/EMS_CheckSum_205_S' */
      rtb_EMS_TorqFailure_L = (int32_T)((uint32_T)rtb_EMS_TorqFailure_L >> 4);

      /* DataTypeConversion: '<S158>/EMS_CheckSum_205cv' */
      rtb_EMS_ESPTorqReuestAvailabili = rtb_EMS_TorqFailure_L;

      /* Sum: '<S158>/EMS_CheckSum_205_Ad' */
      rtb_EMS_CheckSum_205_sat = rtb_EMS_ESPTorqReuestAvailabili;

      /* Saturate: '<S158>/EMS_CheckSum_205_sat' */
      rtb_EMS_TorqFailurecv = rtb_EMS_CheckSum_205_sat;
      rtb_EMS_CheckSum_205_sat = (int32_T)rtb_EMS_TorqFailurecv;

      /* DataTypeConversion: '<S158>/EMS_ESPTorqReuestAvailability_Convert' */
      rtb_EMS_TorqFailure_L = VCU_CS75_12_27_test_B.CANReceive_o4_n[0];

      /* S-Function (sfix_bitop): '<S158>/EMS_ESPTorqReuestAvailability_L' */
      rtb_EMS_TorqFailure_L &= 2U;

      /* ArithShift: '<S158>/EMS_ESPTorqReuestAvailability_S' */
      rtb_EMS_TorqFailure_L = (int32_T)((uint32_T)rtb_EMS_TorqFailure_L >> 1);

      /* Saturate: '<S158>/EMS_ESPTorqReuestAvailability_sat' */
      rtb_EMS_TorqFailurecv = rtb_EMS_TorqFailure_L;
      rtb_EMS_ESPTorqReuestAvailabili = (int32_T)rtb_EMS_TorqFailurecv;

      /* Product: '<S158>/EMS_FrictionalTorqinput4_P' incorporates:
       *  Constant: '<S158>/EMS_FrictionalTorqinput4_C'
       */
      rtb_EMS_FrictionalTorq_sat = (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_n[3] * 256.0;

      /* Sum: '<S158>/EMS_FrictionalTorqinput4_Ad' */
      rtb_EMS_IndicatedDriverReqTorq_ = rtb_EMS_FrictionalTorq_sat + (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_n[4];

      /* DataTypeConversion: '<S158>/EMS_FrictionalTorq_Convert' */
      rtb_EMS_TorqFailure_L = (int32_T)rtb_EMS_IndicatedDriverReqTorq_;

      /* DataTypeConversion: '<S158>/EMS_FrictionalTorqcv' */
      rtb_EMS_IndicatedDriverReqTorq_ = rtb_EMS_TorqFailure_L;

      /* Gain: '<S158>/EMS_FrictionalTorq_F' */
      rtb_EMS_IndicatedDriverReqTorq_ *= 0.001526;

      /* Sum: '<S158>/EMS_FrictionalTorq_Ad' */
      rtb_EMS_FrictionalTorq_sat = rtb_EMS_IndicatedDriverReqTorq_;

      /* Saturate: '<S158>/EMS_FrictionalTorq_sat' */
      if (rtb_EMS_FrictionalTorq_sat > 99.9988) {
        rtb_EMS_FrictionalTorq_sat = 99.9988;
      }

      /* End of Saturate: '<S158>/EMS_FrictionalTorq_sat' */

      /* Product: '<S158>/EMS_IndicatedDriverReqTorqinput2_P' incorporates:
       *  Constant: '<S158>/EMS_IndicatedDriverReqTorqinput2_C'
       */
      rtb_EMS_IndicatedDriverReqTorq_ = (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_n[1] * 256.0;

      /* Sum: '<S158>/EMS_IndicatedDriverReqTorqinput2_Ad' */
      rtb_EMS_IndicatedRealEngTorq_sa = rtb_EMS_IndicatedDriverReqTorq_ +
        (real_T)VCU_CS75_12_27_test_B.CANReceive_o4_n[2];

      /* DataTypeConversion: '<S158>/EMS_IndicatedDriverReqTorq_Convert' */
      rtb_EMS_TorqFailure_L = (int32_T)rtb_EMS_IndicatedRealEngTorq_sa;

      /* DataTypeConversion: '<S158>/EMS_IndicatedDriverReqTorqcv' */
      rtb_EMS_IndicatedRealEngTorq_sa = rtb_EMS_TorqFailure_L;

      /* Gain: '<S158>/EMS_IndicatedDriverReqTorq_F' */
      rtb_EMS_IndicatedRealEngTorq_sa *= 0.001526;

      /* Sum: '<S158>/EMS_IndicatedDriverReqTorq_Ad' */
      rtb_EMS_IndicatedDriverReqTorq_ = rtb_EMS_IndicatedRealEngTorq_sa;

      /* Saturate: '<S158>/EMS_IndicatedDriverReqTorq_sat' */
      if (rtb_EMS_IndicatedDriverReqTorq_ > 99.9988) {
        rtb_EMS_IndicatedDriverReqTorq_ = 99.9988;
      }

      /* End of Saturate: '<S158>/EMS_IndicatedDriverReqTorq_sat' */

      /* Product: '<S158>/EMS_IndicatedRealEngTorqinput6_P' incorporates:
       *  Constant: '<S158>/EMS_IndicatedRealEngTorqinput6_C'
       */
      rtb_EMS_IndicatedRealEngTorq_sa = (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_n[5] * 256.0;

      /* Sum: '<S158>/EMS_IndicatedRealEngTorqinput6_Ad' */
      rtb_EMS_TorqFailurecv = rtb_EMS_IndicatedRealEngTorq_sa + (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_n[6];

      /* DataTypeConversion: '<S158>/EMS_IndicatedRealEngTorq_Convert' */
      rtb_EMS_TorqFailure_L = (int32_T)rtb_EMS_TorqFailurecv;

      /* DataTypeConversion: '<S158>/EMS_IndicatedRealEngTorqcv' */
      rtb_EMS_TorqFailurecv = rtb_EMS_TorqFailure_L;

      /* Gain: '<S158>/EMS_IndicatedRealEngTorq_F' */
      rtb_EMS_TorqFailurecv *= 0.001526;

      /* Sum: '<S158>/EMS_IndicatedRealEngTorq_Ad' */
      rtb_EMS_IndicatedRealEngTorq_sa = rtb_EMS_TorqFailurecv;

      /* Saturate: '<S158>/EMS_IndicatedRealEngTorq_sat' */
      if (rtb_EMS_IndicatedRealEngTorq_sa > 99.9988) {
        rtb_EMS_IndicatedRealEngTorq_sa = 99.9988;
      }

      /* End of Saturate: '<S158>/EMS_IndicatedRealEngTorq_sat' */

      /* DataTypeConversion: '<S158>/EMS_RollingCounter_id205_Convert' */
      rtb_EMS_TorqFailure_L = VCU_CS75_12_27_test_B.CANReceive_o4_n[7];

      /* S-Function (sfix_bitop): '<S158>/EMS_RollingCounter_id205_L' */
      rtb_EMS_TorqFailure_L &= 15U;

      /* DataTypeConversion: '<S158>/EMS_RollingCounter_id205cv' */
      rtb_EMS_TorqFailurecv = rtb_EMS_TorqFailure_L;

      /* Sum: '<S158>/EMS_RollingCounter_id205_Ad' */
      rtb_EMS_RollingCounter_id205_sa = (int32_T)rtb_EMS_TorqFailurecv;

      /* Saturate: '<S158>/EMS_RollingCounter_id205_sat' */
      rtb_EMS_TorqFailurecv = rtb_EMS_RollingCounter_id205_sa;
      rtb_EMS_RollingCounter_id205_sa = (int32_T)rtb_EMS_TorqFailurecv;

      /* DataTypeConversion: '<S158>/EMS_TorqFailure_Convert' */
      rtb_EMS_TorqFailure_L = VCU_CS75_12_27_test_B.CANReceive_o4_n[0];

      /* S-Function (sfix_bitop): '<S158>/EMS_TorqFailure_L' */
      rtb_EMS_TorqFailure_L &= 128U;

      /* ArithShift: '<S158>/EMS_TorqFailure_S' */
      rtb_EMS_TorqFailure_L = (int32_T)((uint32_T)rtb_EMS_TorqFailure_L >> 7);

      /* DataTypeConversion: '<S158>/EMS_TorqFailurecv' */
      rtb_EMS_TorqFailurecv = rtb_EMS_TorqFailure_L;

      /* SignalConversion: '<S157>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_ESPTorqReuestAvailability =
        rtb_EMS_ESPTorqReuestAvailabili;

      /* SignalConversion: '<S157>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_TorqFailure = rtb_EMS_TorqFailurecv;

      /* SignalConversion: '<S157>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_IndicatedDriverReqTorq =
        rtb_EMS_IndicatedDriverReqTorq_;

      /* SignalConversion: '<S157>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_FrictionalTorq_d = rtb_EMS_FrictionalTorq_sat;

      /* SignalConversion: '<S157>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_IndicatedRealEngTorq =
        rtb_EMS_IndicatedRealEngTorq_sa;

      /* SignalConversion: '<S157>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_RollingCounter_id205 =
        rtb_EMS_RollingCounter_id205_sa;

      /* SignalConversion: '<S157>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_CheckSum_205 = rtb_EMS_CheckSum_205_sat;
    }

    /* End of Outputs for SubSystem: '<S156>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S85>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF1RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf1looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_oo= 597;
    VCU_CS75_12_27_test_B.CANReceive_o5_g= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_j= ec_can_receive(1,1, CAN1BUF1RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_j[0]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_j[1]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_j[2]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_j[3]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_j[4]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_j[5]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_j[6]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_j[7]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
  }

  /* Call the system: <S85>/ReceiveMessages */

  /* Output and update for function-call system: '<S85>/ReceiveMessages' */
  {
    int32_T rtb_EMS_RollingCounter_id255_L;
    real_T rtb_EMS_CheckSum_255_sat;
    real_T rtb_EMS_AccPedal_sat;
    int32_T rtb_EMS_AccpedelError_sat;
    real_T rtb_EMS_EngineSpeed_sat;
    int32_T rtb_EMS_EngineSpeedError_sat;
    real_T rtb_EMS_RollingCounter_id255cv;

    /* Outputs for Enabled SubSystem: '<S166>/Subsystem' incorporates:
     *  EnablePort: '<S167>/Enable'
     */
    if (VCU_CS75_12_27_test_B.CANReceive_o2_j > 0) {
      /* DataTypeConversion: '<S168>/EMS_AccPedal_Convert' */
      rtb_EMS_RollingCounter_id255_L = VCU_CS75_12_27_test_B.CANReceive_o4_j[5];

      /* DataTypeConversion: '<S168>/EMS_AccPedalcv' */
      rtb_EMS_CheckSum_255_sat = rtb_EMS_RollingCounter_id255_L;

      /* Gain: '<S168>/EMS_AccPedal_F' */
      rtb_EMS_CheckSum_255_sat *= 0.392;

      /* Sum: '<S168>/EMS_AccPedal_Ad' */
      rtb_EMS_AccPedal_sat = rtb_EMS_CheckSum_255_sat;

      /* Saturate: '<S168>/EMS_AccPedal_sat' */
      if (rtb_EMS_AccPedal_sat > 99.568) {
        rtb_EMS_AccPedal_sat = 99.568;
      }

      /* End of Saturate: '<S168>/EMS_AccPedal_sat' */

      /* DataTypeConversion: '<S168>/EMS_AccpedelError_Convert' */
      rtb_EMS_RollingCounter_id255_L = VCU_CS75_12_27_test_B.CANReceive_o4_j[1];

      /* S-Function (sfix_bitop): '<S168>/EMS_AccpedelError_L' */
      rtb_EMS_RollingCounter_id255_L &= 4U;

      /* ArithShift: '<S168>/EMS_AccpedelError_S' */
      rtb_EMS_RollingCounter_id255_L = (int32_T)((uint32_T)
        rtb_EMS_RollingCounter_id255_L >> 2);

      /* DataTypeConversion: '<S168>/EMS_AccpedelErrorcv' */
      rtb_EMS_CheckSum_255_sat = rtb_EMS_RollingCounter_id255_L;

      /* Sum: '<S168>/EMS_AccpedelError_Ad' */
      rtb_EMS_AccpedelError_sat = (int32_T)rtb_EMS_CheckSum_255_sat;

      /* Saturate: '<S168>/EMS_AccpedelError_sat' */
      rtb_EMS_EngineSpeed_sat = rtb_EMS_AccpedelError_sat;
      rtb_EMS_AccpedelError_sat = (int32_T)rtb_EMS_EngineSpeed_sat;

      /* DataTypeConversion: '<S168>/EMS_BrakePedalStatus_Convert' */
      rtb_EMS_RollingCounter_id255_L = VCU_CS75_12_27_test_B.CANReceive_o4_j[0];

      /* S-Function (sfix_bitop): '<S168>/EMS_BrakePedalStatus_L' */
      rtb_EMS_RollingCounter_id255_L &= 192U;

      /* ArithShift: '<S168>/EMS_BrakePedalStatus_S' */
      rtb_EMS_RollingCounter_id255_L = (int32_T)((uint32_T)
        rtb_EMS_RollingCounter_id255_L >> 6);

      /* DataTypeConversion: '<S168>/EMS_BrakePedalStatuscv' */
      rtb_EMS_CheckSum_255_sat = rtb_EMS_RollingCounter_id255_L;

      /* Sum: '<S168>/EMS_BrakePedalStatus_Ad' */
      rtb_EMS_EngineSpeed_sat = rtb_EMS_CheckSum_255_sat;

      /* Saturate: '<S168>/EMS_BrakePedalStatus_sat' */
      EMS_BrakePedalStatus = rtb_EMS_EngineSpeed_sat;

      /* DataTypeConversion: '<S168>/EMS_CheckSum_255_Convert' */
      rtb_EMS_RollingCounter_id255_L = VCU_CS75_12_27_test_B.CANReceive_o4_j[7];

      /* S-Function (sfix_bitop): '<S168>/EMS_CheckSum_255_L' */
      rtb_EMS_RollingCounter_id255_L &= 240U;

      /* ArithShift: '<S168>/EMS_CheckSum_255_S' */
      rtb_EMS_RollingCounter_id255_L = (int32_T)((uint32_T)
        rtb_EMS_RollingCounter_id255_L >> 4);

      /* DataTypeConversion: '<S168>/EMS_CheckSum_255cv' */
      rtb_EMS_EngineSpeed_sat = rtb_EMS_RollingCounter_id255_L;

      /* Sum: '<S168>/EMS_CheckSum_255_Ad' */
      rtb_EMS_CheckSum_255_sat = rtb_EMS_EngineSpeed_sat;

      /* DataTypeConversion: '<S168>/EMS_EngineSpeedError_Convert' */
      rtb_EMS_RollingCounter_id255_L = VCU_CS75_12_27_test_B.CANReceive_o4_j[1];

      /* S-Function (sfix_bitop): '<S168>/EMS_EngineSpeedError_L' */
      rtb_EMS_RollingCounter_id255_L &= 16U;

      /* ArithShift: '<S168>/EMS_EngineSpeedError_S' */
      rtb_EMS_RollingCounter_id255_L = (int32_T)((uint32_T)
        rtb_EMS_RollingCounter_id255_L >> 4);

      /* DataTypeConversion: '<S168>/EMS_EngineSpeedErrorcv' */
      rtb_EMS_EngineSpeed_sat = rtb_EMS_RollingCounter_id255_L;

      /* Sum: '<S168>/EMS_EngineSpeedError_Ad' */
      rtb_EMS_EngineSpeedError_sat = (int32_T)rtb_EMS_EngineSpeed_sat;

      /* Saturate: '<S168>/EMS_EngineSpeedError_sat' */
      rtb_EMS_EngineSpeed_sat = rtb_EMS_EngineSpeedError_sat;
      rtb_EMS_EngineSpeedError_sat = (int32_T)rtb_EMS_EngineSpeed_sat;

      /* Product: '<S168>/EMS_EngineSpeedinput3_P' incorporates:
       *  Constant: '<S168>/EMS_EngineSpeedinput3_C'
       */
      rtb_EMS_EngineSpeed_sat = (real_T)VCU_CS75_12_27_test_B.CANReceive_o4_j[2]
        * 256.0;

      /* Sum: '<S168>/EMS_EngineSpeedinput3_Ad' */
      rtb_EMS_RollingCounter_id255cv = rtb_EMS_EngineSpeed_sat + (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_j[3];

      /* DataTypeConversion: '<S168>/EMS_EngineSpeed_Convert' */
      rtb_EMS_RollingCounter_id255_L = (int32_T)rtb_EMS_RollingCounter_id255cv;

      /* DataTypeConversion: '<S168>/EMS_EngineSpeedcv' */
      rtb_EMS_RollingCounter_id255cv = rtb_EMS_RollingCounter_id255_L;

      /* Gain: '<S168>/EMS_EngineSpeed_F' */
      rtb_EMS_RollingCounter_id255cv *= 0.25;

      /* Sum: '<S168>/EMS_EngineSpeed_Ad' */
      rtb_EMS_EngineSpeed_sat = rtb_EMS_RollingCounter_id255cv;

      /* Saturate: '<S168>/EMS_EngineSpeed_sat' */
      if (rtb_EMS_EngineSpeed_sat > 16383.5) {
        rtb_EMS_EngineSpeed_sat = 16383.5;
      }

      /* End of Saturate: '<S168>/EMS_EngineSpeed_sat' */

      /* DataTypeConversion: '<S168>/EMS_RollingCounter_id255_Convert' */
      rtb_EMS_RollingCounter_id255_L = VCU_CS75_12_27_test_B.CANReceive_o4_j[7];

      /* S-Function (sfix_bitop): '<S168>/EMS_RollingCounter_id255_L' */
      rtb_EMS_RollingCounter_id255_L &= 15U;

      /* DataTypeConversion: '<S168>/EMS_RollingCounter_id255cv' */
      rtb_EMS_RollingCounter_id255cv = rtb_EMS_RollingCounter_id255_L;

      /* SignalConversion: '<S167>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_BrakePedalStatus_l = EMS_BrakePedalStatus;

      /* SignalConversion: '<S167>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_AccpedelError = rtb_EMS_AccpedelError_sat;

      /* SignalConversion: '<S167>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_EngineSpeedError = rtb_EMS_EngineSpeedError_sat;

      /* SignalConversion: '<S167>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_EngineSpeed_a = rtb_EMS_EngineSpeed_sat;

      /* SignalConversion: '<S167>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_AccPedal = rtb_EMS_AccPedal_sat;

      /* SignalConversion: '<S167>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_RollingCounter_id255 =
        rtb_EMS_RollingCounter_id255cv;

      /* SignalConversion: '<S167>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_CheckSum_255 = rtb_EMS_CheckSum_255_sat;
    }

    /* End of Outputs for SubSystem: '<S166>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S86>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF2RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf2looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_a= 613;
    VCU_CS75_12_27_test_B.CANReceive_o5_l= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_n= ec_can_receive(1,2, CAN1BUF2RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_a[0]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_a[1]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_a[2]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_a[3]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_a[4]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_a[5]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_a[6]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_a[7]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
  }

  /* Call the system: <S86>/ReceiveMessages */

  /* Output and update for function-call system: '<S86>/ReceiveMessages' */
  {
    int32_T rtb_EMS_TorqueConstant_L;
    real_T rtb_EMS_TorqueConstant_F;
    int32_T rtb_EMS_EngineStatus_sat;
    real_T rtb_EMS_FullLoadIndicatedTorq_s;
    int32_T rtb_EMS_RollingCounter_id265_sa;

    /* Outputs for Enabled SubSystem: '<S176>/Subsystem' incorporates:
     *  EnablePort: '<S177>/Enable'
     */
    if (VCU_CS75_12_27_test_B.CANReceive_o2_n > 0) {
      /* DataTypeConversion: '<S178>/EMS_EngineStatus_Convert' */
      rtb_EMS_TorqueConstant_L = VCU_CS75_12_27_test_B.CANReceive_o4_a[7];

      /* S-Function (sfix_bitop): '<S178>/EMS_EngineStatus_L' */
      rtb_EMS_TorqueConstant_L &= 192U;

      /* ArithShift: '<S178>/EMS_EngineStatus_S' */
      rtb_EMS_TorqueConstant_L = (int32_T)((uint32_T)rtb_EMS_TorqueConstant_L >>
        6);

      /* DataTypeConversion: '<S178>/EMS_EngineStatuscv' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_TorqueConstant_L;

      /* Sum: '<S178>/EMS_EngineStatus_Ad' */
      rtb_EMS_EngineStatus_sat = (int32_T)rtb_EMS_TorqueConstant_F;

      /* Saturate: '<S178>/EMS_EngineStatus_sat' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_EngineStatus_sat;
      rtb_EMS_EngineStatus_sat = (int32_T)rtb_EMS_TorqueConstant_F;

      /* DataTypeConversion: '<S178>/EMS_FullLoadIndicatedTorq_Convert' */
      rtb_EMS_TorqueConstant_L = VCU_CS75_12_27_test_B.CANReceive_o4_a[2];

      /* DataTypeConversion: '<S178>/EMS_FullLoadIndicatedTorqcv' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_TorqueConstant_L;

      /* Gain: '<S178>/EMS_FullLoadIndicatedTorq_F' */
      rtb_EMS_TorqueConstant_F *= 0.392;

      /* Sum: '<S178>/EMS_FullLoadIndicatedTorq_Ad' */
      rtb_EMS_FullLoadIndicatedTorq_s = rtb_EMS_TorqueConstant_F;

      /* Saturate: '<S178>/EMS_FullLoadIndicatedTorq_sat' */
      if (rtb_EMS_FullLoadIndicatedTorq_s > 99.96) {
        rtb_EMS_FullLoadIndicatedTorq_s = 99.96;
      }

      /* End of Saturate: '<S178>/EMS_FullLoadIndicatedTorq_sat' */

      /* DataTypeConversion: '<S178>/EMS_RollingCounter_id265_Convert' */
      rtb_EMS_TorqueConstant_L = VCU_CS75_12_27_test_B.CANReceive_o4_a[7];

      /* S-Function (sfix_bitop): '<S178>/EMS_RollingCounter_id265_L' */
      rtb_EMS_TorqueConstant_L &= 15U;

      /* DataTypeConversion: '<S178>/EMS_RollingCounter_id265cv' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_TorqueConstant_L;

      /* Sum: '<S178>/EMS_RollingCounter_id265_Ad' */
      rtb_EMS_RollingCounter_id265_sa = (int32_T)rtb_EMS_TorqueConstant_F;

      /* Saturate: '<S178>/EMS_RollingCounter_id265_sat' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_RollingCounter_id265_sa;
      rtb_EMS_RollingCounter_id265_sa = (int32_T)rtb_EMS_TorqueConstant_F;

      /* DataTypeConversion: '<S178>/EMS_TorqueConstant_Convert' */
      rtb_EMS_TorqueConstant_L = VCU_CS75_12_27_test_B.CANReceive_o4_a[6];

      /* DataTypeConversion: '<S178>/EMS_TorqueConstantcv' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_TorqueConstant_L;

      /* Gain: '<S178>/EMS_TorqueConstant_F' */
      rtb_EMS_TorqueConstant_F *= 10.0;

      /* Saturate: '<S178>/EMS_TorqueConstant_sat' */
      if (rtb_EMS_TorqueConstant_F > 2540.0) {
        rtb_EMS_TorqueConstant_F = 2540.0;
      }

      /* End of Saturate: '<S178>/EMS_TorqueConstant_sat' */

      /* SignalConversion: '<S177>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_FullLoadIndicatedTorq =
        rtb_EMS_FullLoadIndicatedTorq_s;

      /* SignalConversion: '<S177>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_TorqueConstant_c = rtb_EMS_TorqueConstant_F;

      /* SignalConversion: '<S177>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_RollingCounter_id265 =
        rtb_EMS_RollingCounter_id265_sa;

      /* SignalConversion: '<S177>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_EngineStatus_f = rtb_EMS_EngineStatus_sat;
    }

    /* End of Outputs for SubSystem: '<S176>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S87>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF3RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf3looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_h= 630;
    VCU_CS75_12_27_test_B.CANReceive_o5_b= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_p= ec_can_receive(1,3, CAN1BUF3RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_ix[0]= CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ix[1]= CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ix[2]= CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ix[3]= CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ix[4]= CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ix[5]= CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ix[6]= CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ix[7]= CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
  }

  /* Call the system: <S87>/ReceiveMessages */

  /* Output and update for function-call system: '<S87>/ReceiveMessages' */
  {
    int32_T rtb_EMS_RealAccPedal_Convert;
    real_T rtb_EMS_RealAccPedal_F;

    /* Outputs for Enabled SubSystem: '<S183>/Subsystem' incorporates:
     *  EnablePort: '<S184>/Enable'
     */
    if (VCU_CS75_12_27_test_B.CANReceive_o2_p > 0) {
      /* DataTypeConversion: '<S185>/EMS_RealAccPedal_Convert' */
      rtb_EMS_RealAccPedal_Convert = VCU_CS75_12_27_test_B.CANReceive_o4_ix[2];

      /* DataTypeConversion: '<S185>/EMS_RealAccPedalcv' */
      rtb_EMS_RealAccPedal_F = rtb_EMS_RealAccPedal_Convert;

      /* Gain: '<S185>/EMS_RealAccPedal_F' */
      rtb_EMS_RealAccPedal_F *= 0.392;

      /* Saturate: '<S185>/EMS_RealAccPedal_sat' */
      if (rtb_EMS_RealAccPedal_F > 99.96) {
        rtb_EMS_RealAccPedal_F = 99.96;
      }

      /* End of Saturate: '<S185>/EMS_RealAccPedal_sat' */

      /* SignalConversion: '<S184>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_RealAccPedal = rtb_EMS_RealAccPedal_F;
    }

    /* End of Outputs for SubSystem: '<S183>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S88>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF4RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf4looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_ow= 598;
    VCU_CS75_12_27_test_B.CANReceive_o5_d= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_c= ec_can_receive(1,4, CAN1BUF4RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_e[0]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_e[1]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_e[2]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_e[3]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_e[4]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_e[5]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_e[6]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_e[7]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
  }

  /* Call the system: <S88>/ReceiveMessages */

  /* Output and update for function-call system: '<S88>/ReceiveMessages' */
  {
    int32_T rtb_EPB_Status_L;
    int32_T rtb_EPB_Checksum_sat;
    int32_T rtb_EPB_FailStatus_sat;
    int32_T rtb_EPB_FailureLamp_sat;
    int32_T rtb_EPB_FunctionLamp_sat;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S187>/Subsystem' incorporates:
     *  EnablePort: '<S188>/Enable'
     */
    if (VCU_CS75_12_27_test_B.CANReceive_o2_c > 0) {
      /* DataTypeConversion: '<S189>/EPB_Checksum_Convert' */
      rtb_EPB_Status_L = VCU_CS75_12_27_test_B.CANReceive_o4_e[7];

      /* Sum: '<S189>/EPB_Checksum_Ad' */
      rtb_EPB_Checksum_sat = rtb_EPB_Status_L;

      /* Saturate: '<S189>/EPB_Checksum_sat' */
      u0 = rtb_EPB_Checksum_sat;
      rtb_EPB_Checksum_sat = (int32_T)u0;

      /* DataTypeConversion: '<S189>/EPB_FailStatus_Convert' */
      rtb_EPB_Status_L = VCU_CS75_12_27_test_B.CANReceive_o4_e[0];

      /* S-Function (sfix_bitop): '<S189>/EPB_FailStatus_L' */
      rtb_EPB_Status_L &= 192U;

      /* ArithShift: '<S189>/EPB_FailStatus_S' */
      rtb_EPB_Status_L = (int32_T)((uint32_T)rtb_EPB_Status_L >> 6);

      /* Sum: '<S189>/EPB_FailStatus_Ad' */
      rtb_EPB_FailStatus_sat = rtb_EPB_Status_L;

      /* Saturate: '<S189>/EPB_FailStatus_sat' */
      u0 = rtb_EPB_FailStatus_sat;
      rtb_EPB_FailStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S189>/EPB_FailureLamp_Convert' */
      rtb_EPB_Status_L = VCU_CS75_12_27_test_B.CANReceive_o4_e[5];

      /* S-Function (sfix_bitop): '<S189>/EPB_FailureLamp_L' */
      rtb_EPB_Status_L &= 48U;

      /* ArithShift: '<S189>/EPB_FailureLamp_S' */
      rtb_EPB_Status_L = (int32_T)((uint32_T)rtb_EPB_Status_L >> 4);

      /* Sum: '<S189>/EPB_FailureLamp_Ad' */
      rtb_EPB_FailureLamp_sat = rtb_EPB_Status_L;

      /* Saturate: '<S189>/EPB_FailureLamp_sat' */
      u0 = rtb_EPB_FailureLamp_sat;
      rtb_EPB_FailureLamp_sat = (int32_T)u0;

      /* DataTypeConversion: '<S189>/EPB_FunctionLamp_Convert' */
      rtb_EPB_Status_L = VCU_CS75_12_27_test_B.CANReceive_o4_e[5];

      /* S-Function (sfix_bitop): '<S189>/EPB_FunctionLamp_L' */
      rtb_EPB_Status_L &= 12U;

      /* ArithShift: '<S189>/EPB_FunctionLamp_S' */
      rtb_EPB_Status_L = (int32_T)((uint32_T)rtb_EPB_Status_L >> 2);

      /* Sum: '<S189>/EPB_FunctionLamp_Ad' */
      rtb_EPB_FunctionLamp_sat = rtb_EPB_Status_L;

      /* Saturate: '<S189>/EPB_FunctionLamp_sat' */
      u0 = rtb_EPB_FunctionLamp_sat;
      rtb_EPB_FunctionLamp_sat = (int32_T)u0;

      /* DataTypeConversion: '<S189>/EPB_RollingCounter_id256_Convert' */
      rtb_EPB_Status_L = VCU_CS75_12_27_test_B.CANReceive_o4_e[6];

      /* S-Function (sfix_bitop): '<S189>/EPB_RollingCounter_id256_L' */
      rtb_EPB_Status_L &= 15U;

      /* Saturate: '<S189>/EPB_RollingCounter_id256_sat' */
      u0 = rtb_EPB_Status_L;
      EPB_RollingCounter_id256 = u0;

      /* DataTypeConversion: '<S189>/EPB_Status_Convert' */
      rtb_EPB_Status_L = VCU_CS75_12_27_test_B.CANReceive_o4_e[2];

      /* S-Function (sfix_bitop): '<S189>/EPB_Status_L' */
      rtb_EPB_Status_L &= 192U;

      /* ArithShift: '<S189>/EPB_Status_S' */
      rtb_EPB_Status_L = (int32_T)((uint32_T)rtb_EPB_Status_L >> 6);

      /* Saturate: '<S189>/EPB_Status_sat' */
      u0 = rtb_EPB_Status_L;
      rtb_EPB_Status_L = (int32_T)u0;

      /* SignalConversion: '<S188>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPB_FailStatus = rtb_EPB_FailStatus_sat;

      /* SignalConversion: '<S188>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPB_Status_p = rtb_EPB_Status_L;

      /* SignalConversion: '<S188>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPB_FunctionLamp_f = rtb_EPB_FunctionLamp_sat;

      /* SignalConversion: '<S188>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPB_FailureLamp = rtb_EPB_FailureLamp_sat;

      /* SignalConversion: '<S188>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPB_RollingCounter_id256_d =
        EPB_RollingCounter_id256;

      /* SignalConversion: '<S188>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPB_Checksum = rtb_EPB_Checksum_sat;
    }

    /* End of Outputs for SubSystem: '<S187>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S89>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF5RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf5looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_n1= 522;
    VCU_CS75_12_27_test_B.CANReceive_o5_ir= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_mh= ec_can_receive(1,5, CAN1BUF5RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_jz[0]= CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_jz[1]= CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_jz[2]= CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_jz[3]= CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_jz[4]= CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_jz[5]= CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_jz[6]= CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_jz[7]= CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
  }

  /* Call the system: <S89>/ReceiveMessages */

  /* Output and update for function-call system: '<S89>/ReceiveMessages' */
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

    /* Outputs for Enabled SubSystem: '<S196>/Subsystem' incorporates:
     *  EnablePort: '<S197>/Enable'
     */
    if (VCU_CS75_12_27_test_B.CANReceive_o2_mh > 0) {
      /* DataTypeConversion: '<S198>/EPS_APA_AbortFeedback_Convert' */
      rtb_EPS_TorqueSensorStatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_jz[1];

      /* S-Function (sfix_bitop): '<S198>/EPS_APA_AbortFeedback_L' */
      rtb_EPS_TorqueSensorStatus_L &= 112U;

      /* ArithShift: '<S198>/EPS_APA_AbortFeedback_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 4);

      /* DataTypeConversion: '<S198>/EPS_APA_AbortFeedbackcv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S198>/EPS_APA_AbortFeedback_Ad' */
      rtb_EPS_APA_AbortFeedback_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S198>/EPS_APA_AbortFeedback_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_APA_AbortFeedback_sat;
      rtb_EPS_APA_AbortFeedback_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* DataTypeConversion: '<S198>/EPS_APA_ControlFeedback_Convert' */
      rtb_EPS_TorqueSensorStatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_jz[5];

      /* S-Function (sfix_bitop): '<S198>/EPS_APA_ControlFeedback_L' */
      rtb_EPS_TorqueSensorStatus_L &= 64U;

      /* ArithShift: '<S198>/EPS_APA_ControlFeedback_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 6);

      /* DataTypeConversion: '<S198>/EPS_APA_ControlFeedbackcv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S198>/EPS_APA_ControlFeedback_Ad' */
      rtb_EPS_APA_ControlFeedback_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S198>/EPS_APA_ControlFeedback_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_APA_ControlFeedback_sat;
      rtb_EPS_APA_ControlFeedback_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* DataTypeConversion: '<S198>/EPS_APA_EpasFailed_Convert' */
      rtb_EPS_TorqueSensorStatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_jz[1];

      /* S-Function (sfix_bitop): '<S198>/EPS_APA_EpasFailed_L' */
      rtb_EPS_TorqueSensorStatus_L &= 2U;

      /* ArithShift: '<S198>/EPS_APA_EpasFailed_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 1);

      /* DataTypeConversion: '<S198>/EPS_APA_EpasFailedcv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S198>/EPS_APA_EpasFailed_Ad' */
      rtb_EPS_APA_EpasFailed_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S198>/EPS_APA_EpasFailed_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_APA_EpasFailed_sat;
      rtb_EPS_APA_EpasFailed_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* DataTypeConversion: '<S198>/EPS_Checksum_Convert' */
      rtb_EPS_TorqueSensorStatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_jz[7];

      /* DataTypeConversion: '<S198>/EPS_Checksumcv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S198>/EPS_Checksum_Ad' */
      rtb_EPS_Checksum_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S198>/EPS_Checksum_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_Checksum_sat;
      rtb_EPS_Checksum_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* DataTypeConversion: '<S198>/EPS_ConcussAvailabilityStatus_Convert' */
      rtb_EPS_TorqueSensorStatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_jz[6];

      /* S-Function (sfix_bitop): '<S198>/EPS_ConcussAvailabilityStatus_L' */
      rtb_EPS_TorqueSensorStatus_L &= 48U;

      /* ArithShift: '<S198>/EPS_ConcussAvailabilityStatus_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 4);

      /* DataTypeConversion: '<S198>/EPS_ConcussAvailabilityStatuscv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S198>/EPS_ConcussAvailabilityStatus_Ad' */
      rtb_EPS_ConcussAvailabilityStat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S198>/EPS_ConcussAvailabilityStatus_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_ConcussAvailabilityStat;
      rtb_EPS_ConcussAvailabilityStat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* DataTypeConversion: '<S198>/EPS_EPSFailed_Convert' */
      rtb_EPS_TorqueSensorStatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_jz[0];

      /* S-Function (sfix_bitop): '<S198>/EPS_EPSFailed_L' */
      rtb_EPS_TorqueSensorStatus_L &= 128U;

      /* ArithShift: '<S198>/EPS_EPSFailed_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 7);

      /* DataTypeConversion: '<S198>/EPS_EPSFailedcv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S198>/EPS_EPSFailed_Ad' */
      rtb_EPS_EPSFailed_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S198>/EPS_EPSFailed_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_EPSFailed_sat;
      rtb_EPS_EPSFailed_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* DataTypeConversion: '<S198>/EPS_RollingCounter_Convert' */
      rtb_EPS_TorqueSensorStatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_jz[6];

      /* S-Function (sfix_bitop): '<S198>/EPS_RollingCounter_L' */
      rtb_EPS_TorqueSensorStatus_L &= 15U;

      /* DataTypeConversion: '<S198>/EPS_RollingCountercv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S198>/EPS_RollingCounter_Ad' */
      rtb_EPS_RollingCounter_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S198>/EPS_RollingCounter_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_RollingCounter_sat;
      rtb_EPS_RollingCounter_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Product: '<S198>/EPS_SteeringTorqueinput3_P' incorporates:
       *  Constant: '<S198>/EPS_SteeringTorqueinput3_C'
       */
      rtb_EPS_SteeringTorque_sat = (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_jz[2] * 256.0;

      /* Sum: '<S198>/EPS_SteeringTorqueinput3_Ad' */
      rtb_EPS_TorqueSensorStatuscv = rtb_EPS_SteeringTorque_sat + (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_jz[3];

      /* DataTypeConversion: '<S198>/EPS_SteeringTorque_Convert' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)rtb_EPS_TorqueSensorStatuscv;

      /* S-Function (sfix_bitop): '<S198>/EPS_SteeringTorque_L' */
      rtb_EPS_TorqueSensorStatus_L &= 4080U;

      /* ArithShift: '<S198>/EPS_SteeringTorque_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 4);

      /* DataTypeConversion: '<S198>/EPS_SteeringTorquecv' */
      rtb_EPS_TorqueSensorStatuscv = rtb_EPS_TorqueSensorStatus_L;

      /* Gain: '<S198>/EPS_SteeringTorque_F' */
      rtb_EPS_TorqueSensorStatuscv *= 0.1794;

      /* Sum: '<S198>/EPS_SteeringTorque_Ad' incorporates:
       *  Constant: '<S198>/EPS_SteeringTorque_O'
       */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatuscv +
        -22.780000686645508;

      /* Saturate: '<S198>/EPS_SteeringTorque_sat' */
      if (rtb_EPS_SteeringTorque_sat > 22.78) {
        rtb_EPS_SteeringTorque_sat = 22.78;
      } else {
        if (rtb_EPS_SteeringTorque_sat < -22.78) {
          rtb_EPS_SteeringTorque_sat = -22.78;
        }
      }

      /* End of Saturate: '<S198>/EPS_SteeringTorque_sat' */

      /* DataTypeConversion: '<S198>/EPS_TorqueSensorStatus_Convert' */
      rtb_EPS_TorqueSensorStatus_L = VCU_CS75_12_27_test_B.CANReceive_o4_jz[4];

      /* S-Function (sfix_bitop): '<S198>/EPS_TorqueSensorStatus_L' */
      rtb_EPS_TorqueSensorStatus_L &= 2U;

      /* ArithShift: '<S198>/EPS_TorqueSensorStatus_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 1);

      /* DataTypeConversion: '<S198>/EPS_TorqueSensorStatuscv' */
      rtb_EPS_TorqueSensorStatuscv = rtb_EPS_TorqueSensorStatus_L;

      /* SignalConversion: '<S197>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPS_EPSFailed_k = rtb_EPS_EPSFailed_sat;

      /* SignalConversion: '<S197>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPS_APA_EpasFailed = rtb_EPS_APA_EpasFailed_sat;

      /* SignalConversion: '<S197>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPS_APA_AbortFeedback =
        rtb_EPS_APA_AbortFeedback_sat;

      /* SignalConversion: '<S197>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPS_SteeringTorque = rtb_EPS_SteeringTorque_sat;

      /* SignalConversion: '<S197>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPS_TorqueSensorStatus =
        rtb_EPS_TorqueSensorStatuscv;

      /* SignalConversion: '<S197>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPS_APA_ControlFeedback =
        rtb_EPS_APA_ControlFeedback_sat;

      /* SignalConversion: '<S197>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPS_RollingCounter = rtb_EPS_RollingCounter_sat;

      /* SignalConversion: '<S197>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPS_ConcussAvailabilityStatus =
        rtb_EPS_ConcussAvailabilityStat;

      /* SignalConversion: '<S197>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPS_Checksum = rtb_EPS_Checksum_sat;
    }

    /* End of Outputs for SubSystem: '<S196>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S90>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF6RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf6looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_ii= 538;
    VCU_CS75_12_27_test_B.CANReceive_o5_kn= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_ip= ec_can_receive(1,6, CAN1BUF6RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_o[0]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_o[1]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_o[2]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_o[3]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_o[4]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_o[5]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_o[6]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_o[7]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
  }

  /* Call the system: <S90>/ReceiveMessages */

  /* Output and update for function-call system: '<S90>/ReceiveMessages' */
  {
    int32_T rtb_Rollingcounter_L;
    real_T rtb_EPS_MeasuredTosionBatTorque;
    int32_T rtb_EPS_AvailabilityStatus_sat;
    int32_T rtb_EPS_IACC_abortReson_sat;
    int32_T rtb_EPS_MeasTsionBatTorquevalid;
    real_T rtb_Rollingcountercv;

    /* Outputs for Enabled SubSystem: '<S208>/Subsystem' incorporates:
     *  EnablePort: '<S209>/Enable'
     */
    if (VCU_CS75_12_27_test_B.CANReceive_o2_ip > 0) {
      /* DataTypeConversion: '<S210>/EPS_AvailabilityStatus_Convert' */
      rtb_Rollingcounter_L = VCU_CS75_12_27_test_B.CANReceive_o4_o[2];

      /* S-Function (sfix_bitop): '<S210>/EPS_AvailabilityStatus_L' */
      rtb_Rollingcounter_L &= 28U;

      /* ArithShift: '<S210>/EPS_AvailabilityStatus_S' */
      rtb_Rollingcounter_L = (int32_T)((uint32_T)rtb_Rollingcounter_L >> 2);

      /* DataTypeConversion: '<S210>/EPS_AvailabilityStatuscv' */
      rtb_EPS_MeasuredTosionBatTorque = rtb_Rollingcounter_L;

      /* Sum: '<S210>/EPS_AvailabilityStatus_Ad' */
      rtb_EPS_AvailabilityStatus_sat = (int32_T)rtb_EPS_MeasuredTosionBatTorque;

      /* Saturate: '<S210>/EPS_AvailabilityStatus_sat' */
      rtb_EPS_MeasuredTosionBatTorque = rtb_EPS_AvailabilityStatus_sat;
      rtb_EPS_AvailabilityStatus_sat = (int32_T)rtb_EPS_MeasuredTosionBatTorque;

      /* DataTypeConversion: '<S210>/EPS_IACC_abortReson_Convert' */
      rtb_Rollingcounter_L = VCU_CS75_12_27_test_B.CANReceive_o4_o[5];

      /* S-Function (sfix_bitop): '<S210>/EPS_IACC_abortReson_L' */
      rtb_Rollingcounter_L &= 112U;

      /* ArithShift: '<S210>/EPS_IACC_abortReson_S' */
      rtb_Rollingcounter_L = (int32_T)((uint32_T)rtb_Rollingcounter_L >> 4);

      /* DataTypeConversion: '<S210>/EPS_IACC_abortResoncv' */
      rtb_EPS_MeasuredTosionBatTorque = rtb_Rollingcounter_L;

      /* Sum: '<S210>/EPS_IACC_abortReson_Ad' */
      rtb_EPS_IACC_abortReson_sat = (int32_T)rtb_EPS_MeasuredTosionBatTorque;

      /* Saturate: '<S210>/EPS_IACC_abortReson_sat' */
      rtb_EPS_MeasuredTosionBatTorque = rtb_EPS_IACC_abortReson_sat;
      rtb_EPS_IACC_abortReson_sat = (int32_T)rtb_EPS_MeasuredTosionBatTorque;

      /* DataTypeConversion: '<S210>/EPS_MeasTsionBatTorquevalid_Convert' */
      rtb_Rollingcounter_L = VCU_CS75_12_27_test_B.CANReceive_o4_o[4];

      /* S-Function (sfix_bitop): '<S210>/EPS_MeasTsionBatTorquevalid_L' */
      rtb_Rollingcounter_L &= 64U;

      /* ArithShift: '<S210>/EPS_MeasTsionBatTorquevalid_S' */
      rtb_Rollingcounter_L = (int32_T)((uint32_T)rtb_Rollingcounter_L >> 6);

      /* DataTypeConversion: '<S210>/EPS_MeasTsionBatTorquevalidcv' */
      rtb_EPS_MeasuredTosionBatTorque = rtb_Rollingcounter_L;

      /* Sum: '<S210>/EPS_MeasTsionBatTorquevalid_Ad' */
      rtb_EPS_MeasTsionBatTorquevalid = (int32_T)rtb_EPS_MeasuredTosionBatTorque;

      /* Saturate: '<S210>/EPS_MeasTsionBatTorquevalid_sat' */
      rtb_EPS_MeasuredTosionBatTorque = rtb_EPS_MeasTsionBatTorquevalid;
      rtb_EPS_MeasTsionBatTorquevalid = (int32_T)rtb_EPS_MeasuredTosionBatTorque;

      /* Product: '<S210>/EPS_MeasuredTosionBatTorqueinput1_P' incorporates:
       *  Constant: '<S210>/EPS_MeasuredTosionBatTorqueinput1_C'
       */
      rtb_EPS_MeasuredTosionBatTorque = (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_o[0] * 256.0;

      /* Sum: '<S210>/EPS_MeasuredTosionBatTorqueinput1_Ad' */
      rtb_Rollingcountercv = rtb_EPS_MeasuredTosionBatTorque + (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_o[1];

      /* DataTypeConversion: '<S210>/EPS_MeasuredTosionBatTorque_Convert' */
      rtb_Rollingcounter_L = (int32_T)rtb_Rollingcountercv;

      /* S-Function (sfix_bitop): '<S210>/EPS_MeasuredTosionBatTorque_L' */
      rtb_Rollingcounter_L &= 65504U;

      /* ArithShift: '<S210>/EPS_MeasuredTosionBatTorque_S' */
      rtb_Rollingcounter_L = (int32_T)((uint32_T)rtb_Rollingcounter_L >> 5);

      /* DataTypeConversion: '<S210>/EPS_MeasuredTosionBatTorquecv' */
      rtb_Rollingcountercv = rtb_Rollingcounter_L;

      /* Gain: '<S210>/EPS_MeasuredTosionBatTorque_F' */
      rtb_Rollingcountercv *= 0.01;

      /* Sum: '<S210>/EPS_MeasuredTosionBatTorque_Ad' incorporates:
       *  Constant: '<S210>/EPS_MeasuredTosionBatTorque_O'
       */
      rtb_EPS_MeasuredTosionBatTorque = rtb_Rollingcountercv +
        -10.229999542236328;

      /* Saturate: '<S210>/EPS_MeasuredTosionBatTorque_sat' */
      if (rtb_EPS_MeasuredTosionBatTorque > 10.23) {
        rtb_EPS_MeasuredTosionBatTorque = 10.23;
      }

      /* End of Saturate: '<S210>/EPS_MeasuredTosionBatTorque_sat' */

      /* DataTypeConversion: '<S210>/Rollingcounter_Convert' */
      rtb_Rollingcounter_L = VCU_CS75_12_27_test_B.CANReceive_o4_o[6];

      /* S-Function (sfix_bitop): '<S210>/Rollingcounter_L' */
      rtb_Rollingcounter_L &= 15U;

      /* DataTypeConversion: '<S210>/Rollingcountercv' */
      rtb_Rollingcountercv = rtb_Rollingcounter_L;

      /* SignalConversion: '<S209>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPS_MeasuredTosionBatTorque =
        rtb_EPS_MeasuredTosionBatTorque;

      /* SignalConversion: '<S209>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPS_AvailabilityStatus_a =
        rtb_EPS_AvailabilityStatus_sat;

      /* SignalConversion: '<S209>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPS_MeasTsionBatTorquevalid =
        rtb_EPS_MeasTsionBatTorquevalid;

      /* SignalConversion: '<S209>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPS_IACC_abortReson = rtb_EPS_IACC_abortReson_sat;

      /* SignalConversion: '<S209>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPS_21A_Rollingcounter = rtb_Rollingcountercv;

      /* SignalConversion: '<S209>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPS_21A_CheckingSum = 0.0;
    }

    /* End of Outputs for SubSystem: '<S208>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S91>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF7RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf7looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_an= 631;
    VCU_CS75_12_27_test_B.CANReceive_o5_py= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_e= ec_can_receive(1,7, CAN1BUF7RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_dj[0]= CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_dj[1]= CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_dj[2]= CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_dj[3]= CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_dj[4]= CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_dj[5]= CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_dj[6]= CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_dj[7]= CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
  }

  /* Call the system: <S91>/ReceiveMessages */

  /* Output and update for function-call system: '<S91>/ReceiveMessages' */
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

    /* Outputs for Enabled SubSystem: '<S217>/Subsystem' incorporates:
     *  EnablePort: '<S218>/Enable'
     */
    if (VCU_CS75_12_27_test_B.CANReceive_o2_e > 0) {
      /* DataTypeConversion: '<S219>/ESP_ABAactive_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_B.CANReceive_o4_dj[2];

      /* S-Function (sfix_bitop): '<S219>/ESP_ABAactive_L' */
      rtb_ESP_VehicleStandstill_L &= 32U;

      /* ArithShift: '<S219>/ESP_ABAactive_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 5);

      /* Sum: '<S219>/ESP_ABAactive_Ad' */
      rtb_ESP_ABAactive_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S219>/ESP_ABAactive_sat' */
      u0 = rtb_ESP_ABAactive_sat;
      rtb_ESP_ABAactive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S219>/ESP_ABAavailable_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_B.CANReceive_o4_dj[2];

      /* S-Function (sfix_bitop): '<S219>/ESP_ABAavailable_L' */
      rtb_ESP_VehicleStandstill_L &= 16U;

      /* ArithShift: '<S219>/ESP_ABAavailable_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 4);

      /* Sum: '<S219>/ESP_ABAavailable_Ad' */
      rtb_ESP_ABAavailable_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S219>/ESP_ABAavailable_sat' */
      u0 = rtb_ESP_ABAavailable_sat;
      rtb_ESP_ABAavailable_sat = (int32_T)u0;

      /* DataTypeConversion: '<S219>/ESP_AEBAvailable_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_B.CANReceive_o4_dj[2];

      /* S-Function (sfix_bitop): '<S219>/ESP_AEBAvailable_L' */
      rtb_ESP_VehicleStandstill_L &= 8U;

      /* ArithShift: '<S219>/ESP_AEBAvailable_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 3);

      /* Sum: '<S219>/ESP_AEBAvailable_Ad' */
      rtb_ESP_AEBAvailable_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S219>/ESP_AEBAvailable_sat' */
      u0 = rtb_ESP_AEBAvailable_sat;
      rtb_ESP_AEBAvailable_sat = (int32_T)u0;

      /* DataTypeConversion: '<S219>/ESP_AEBdecActive_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_B.CANReceive_o4_dj[2];

      /* S-Function (sfix_bitop): '<S219>/ESP_AEBdecActive_L' */
      rtb_ESP_VehicleStandstill_L &= 4U;

      /* ArithShift: '<S219>/ESP_AEBdecActive_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 2);

      /* Sum: '<S219>/ESP_AEBdecActive_Ad' */
      rtb_ESP_AEBdecActive_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S219>/ESP_AEBdecActive_sat' */
      u0 = rtb_ESP_AEBdecActive_sat;
      rtb_ESP_AEBdecActive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S219>/ESP_AWBactive_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_B.CANReceive_o4_dj[2];

      /* S-Function (sfix_bitop): '<S219>/ESP_AWBactive_L' */
      rtb_ESP_VehicleStandstill_L &= 2U;

      /* ArithShift: '<S219>/ESP_AWBactive_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 1);

      /* Sum: '<S219>/ESP_AWBactive_Ad' */
      rtb_ESP_AWBactive_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S219>/ESP_AWBactive_sat' */
      u0 = rtb_ESP_AWBactive_sat;
      rtb_ESP_AWBactive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S219>/ESP_AWBavailable_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_B.CANReceive_o4_dj[2];

      /* S-Function (sfix_bitop): '<S219>/ESP_AWBavailable_L' */
      rtb_ESP_VehicleStandstill_L &= 1U;

      /* Sum: '<S219>/ESP_AWBavailable_Ad' */
      rtb_ESP_AWBavailable_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S219>/ESP_AWBavailable_sat' */
      u0 = rtb_ESP_AWBavailable_sat;
      rtb_ESP_AWBavailable_sat = (int32_T)u0;

      /* DataTypeConversion: '<S219>/ESP_BrakeForce_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_B.CANReceive_o4_dj[1];

      /* S-Function (sfix_bitop): '<S219>/ESP_BrakeForce_L' */
      rtb_ESP_VehicleStandstill_L &= 16U;

      /* ArithShift: '<S219>/ESP_BrakeForce_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 4);

      /* Sum: '<S219>/ESP_BrakeForce_Ad' */
      rtb_ESP_BrakeForce_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S219>/ESP_BrakeForce_sat' */
      u0 = rtb_ESP_BrakeForce_sat;
      rtb_ESP_BrakeForce_sat = (int32_T)u0;

      /* DataTypeConversion: '<S219>/ESP_BrakeOverHeat_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_B.CANReceive_o4_dj[3];

      /* S-Function (sfix_bitop): '<S219>/ESP_BrakeOverHeat_L' */
      rtb_ESP_VehicleStandstill_L &= 1U;

      /* Sum: '<S219>/ESP_BrakeOverHeat_Ad' */
      rtb_ESP_BrakeOverHeat_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S219>/ESP_BrakeOverHeat_sat' */
      u0 = rtb_ESP_BrakeOverHeat_sat;
      rtb_ESP_BrakeOverHeat_sat = (int32_T)u0;

      /* DataTypeConversion: '<S219>/ESP_CDD_Active_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_B.CANReceive_o4_dj[3];

      /* S-Function (sfix_bitop): '<S219>/ESP_CDD_Active_L' */
      rtb_ESP_VehicleStandstill_L &= 8U;

      /* ArithShift: '<S219>/ESP_CDD_Active_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 3);

      /* Sum: '<S219>/ESP_CDD_Active_Ad' */
      rtb_ESP_CDD_Active_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S219>/ESP_CDD_Active_sat' */
      u0 = rtb_ESP_CDD_Active_sat;
      rtb_ESP_CDD_Active_sat = (int32_T)u0;

      /* DataTypeConversion: '<S219>/ESP_CDD_Available_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_B.CANReceive_o4_dj[3];

      /* S-Function (sfix_bitop): '<S219>/ESP_CDD_Available_L' */
      rtb_ESP_VehicleStandstill_L &= 16U;

      /* ArithShift: '<S219>/ESP_CDD_Available_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 4);

      /* Sum: '<S219>/ESP_CDD_Available_Ad' */
      rtb_ESP_CDD_Available_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S219>/ESP_CDD_Available_sat' */
      u0 = rtb_ESP_CDD_Available_sat;
      rtb_ESP_CDD_Available_sat = (int32_T)u0;

      /* DataTypeConversion: '<S219>/ESP_CheckSum_277_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_B.CANReceive_o4_dj[7];

      /* Sum: '<S219>/ESP_CheckSum_277_Ad' */
      rtb_ESP_CheckSum_277_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S219>/ESP_CheckSum_277_sat' */
      u0 = rtb_ESP_CheckSum_277_sat;
      rtb_ESP_CheckSum_277_sat = (int32_T)u0;

      /* DataTypeConversion: '<S219>/ESP_PrefillActive_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_B.CANReceive_o4_dj[2];

      /* S-Function (sfix_bitop): '<S219>/ESP_PrefillActive_L' */
      rtb_ESP_VehicleStandstill_L &= 128U;

      /* ArithShift: '<S219>/ESP_PrefillActive_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 7);

      /* Sum: '<S219>/ESP_PrefillActive_Ad' */
      rtb_ESP_PrefillActive_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S219>/ESP_PrefillActive_sat' */
      u0 = rtb_ESP_PrefillActive_sat;
      rtb_ESP_PrefillActive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S219>/ESP_PrefillAvailable_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_B.CANReceive_o4_dj[2];

      /* S-Function (sfix_bitop): '<S219>/ESP_PrefillAvailable_L' */
      rtb_ESP_VehicleStandstill_L &= 64U;

      /* ArithShift: '<S219>/ESP_PrefillAvailable_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 6);

      /* Sum: '<S219>/ESP_PrefillAvailable_Ad' */
      rtb_ESP_PrefillAvailable_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S219>/ESP_PrefillAvailable_sat' */
      u0 = rtb_ESP_PrefillAvailable_sat;
      rtb_ESP_PrefillAvailable_sat = (int32_T)u0;

      /* DataTypeConversion: '<S219>/ESP_RollingCounter_277_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_B.CANReceive_o4_dj[6];

      /* S-Function (sfix_bitop): '<S219>/ESP_RollingCounter_277_L' */
      rtb_ESP_VehicleStandstill_L &= 15U;

      /* Sum: '<S219>/ESP_RollingCounter_277_Ad' */
      rtb_ESP_RollingCounter_277_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S219>/ESP_RollingCounter_277_sat' */
      u0 = rtb_ESP_RollingCounter_277_sat;
      rtb_ESP_RollingCounter_277_sat = (int32_T)u0;

      /* DataTypeConversion: '<S219>/ESP_TCSActive_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_B.CANReceive_o4_dj[1];

      /* S-Function (sfix_bitop): '<S219>/ESP_TCSActive_L' */
      rtb_ESP_VehicleStandstill_L &= 64U;

      /* ArithShift: '<S219>/ESP_TCSActive_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 6);

      /* Sum: '<S219>/ESP_TCSActive_Ad' */
      rtb_ESP_TCSActive_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S219>/ESP_TCSActive_sat' */
      u0 = rtb_ESP_TCSActive_sat;
      rtb_ESP_TCSActive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S219>/ESP_VDCActive_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_B.CANReceive_o4_dj[1];

      /* S-Function (sfix_bitop): '<S219>/ESP_VDCActive_L' */
      rtb_ESP_VehicleStandstill_L &= 32U;

      /* ArithShift: '<S219>/ESP_VDCActive_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 5);

      /* Sum: '<S219>/ESP_VDCActive_Ad' */
      rtb_ESP_VDCActive_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S219>/ESP_VDCActive_sat' */
      u0 = rtb_ESP_VDCActive_sat;
      rtb_ESP_VDCActive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S219>/ESP_VehicleStandstill_Convert' */
      rtb_ESP_VehicleStandstill_L = VCU_CS75_12_27_test_B.CANReceive_o4_dj[3];

      /* S-Function (sfix_bitop): '<S219>/ESP_VehicleStandstill_L' */
      rtb_ESP_VehicleStandstill_L &= 64U;

      /* ArithShift: '<S219>/ESP_VehicleStandstill_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 6);

      /* Saturate: '<S219>/ESP_VehicleStandstill_sat' */
      u0 = rtb_ESP_VehicleStandstill_L;
      rtb_ESP_VehicleStandstill_L = (int32_T)u0;

      /* SignalConversion: '<S218>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_BrakeForce = rtb_ESP_BrakeForce_sat;

      /* SignalConversion: '<S218>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_PrefillAvailable = rtb_ESP_PrefillAvailable_sat;

      /* SignalConversion: '<S218>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_PrefillActive = rtb_ESP_PrefillActive_sat;

      /* SignalConversion: '<S218>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_BrakeOverHeat = rtb_ESP_BrakeOverHeat_sat;

      /* SignalConversion: '<S218>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_CDD_Active = rtb_ESP_CDD_Active_sat;

      /* SignalConversion: '<S218>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_CDD_Available = rtb_ESP_CDD_Available_sat;

      /* SignalConversion: '<S218>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_CDD_Active_APA = 0.0;

      /* SignalConversion: '<S218>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_VehicleStandstill = rtb_ESP_VehicleStandstill_L;

      /* SignalConversion: '<S218>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_CDD_Available_APA = 0.0;

      /* SignalConversion: '<S218>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_RollingCounter_277 =
        rtb_ESP_RollingCounter_277_sat;

      /* SignalConversion: '<S218>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_CheckSum_277 = rtb_ESP_CheckSum_277_sat;

      /* SignalConversion: '<S218>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_VDCActive = rtb_ESP_VDCActive_sat;

      /* SignalConversion: '<S218>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_TCSActive = rtb_ESP_TCSActive_sat;

      /* SignalConversion: '<S218>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_AWBavailable = rtb_ESP_AWBavailable_sat;

      /* SignalConversion: '<S218>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_AWBactive = rtb_ESP_AWBactive_sat;

      /* SignalConversion: '<S218>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_AEBdecActive = rtb_ESP_AEBdecActive_sat;

      /* SignalConversion: '<S218>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_AEBAvailable = rtb_ESP_AEBAvailable_sat;

      /* SignalConversion: '<S218>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_ABAavailable = rtb_ESP_ABAavailable_sat;

      /* SignalConversion: '<S218>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_ABAactive = rtb_ESP_ABAactive_sat;
    }

    /* End of Outputs for SubSystem: '<S217>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S92>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF16RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf16looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_iy= 640;
    VCU_CS75_12_27_test_B.CANReceive_o5_e= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_ix= ec_can_receive(1,16, CAN1BUF16RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_is[0]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_is[1]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_is[2]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_is[3]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_is[4]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_is[5]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_is[6]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_is[7]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
  }

  /* Call the system: <S92>/ReceiveMessages */

  /* Output and update for function-call system: '<S92>/ReceiveMessages' */
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

    /* Outputs for Enabled SubSystem: '<S239>/Subsystem' incorporates:
     *  EnablePort: '<S240>/Enable'
     */
    if (VCU_CS75_12_27_test_B.CANReceive_o2_ix > 0) {
      /* Product: '<S241>/Wheel_Speed_FL_Datainput7_P' incorporates:
       *  Constant: '<S241>/Wheel_Speed_FL_Datainput7_C'
       */
      rtb_Wheel_Speed_FL_Data_sat = (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_is[6] * 256.0;

      /* Sum: '<S241>/Wheel_Speed_FL_Datainput7_Ad' */
      rtb_Wheel_Speed_FR_Data_sat = rtb_Wheel_Speed_FL_Data_sat + (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_is[7];

      /* DataTypeConversion: '<S241>/Wheel_Speed_FL_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)rtb_Wheel_Speed_FR_Data_sat;

      /* S-Function (sfix_bitop): '<S241>/Wheel_Speed_FL_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 8191U;

      /* DataTypeConversion: '<S241>/Wheel_Speed_FL_Datacv' */
      rtb_Wheel_Speed_FR_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Gain: '<S241>/Wheel_Speed_FL_Data_F' */
      rtb_Wheel_Speed_FR_Data_sat *= 0.05625;

      /* Sum: '<S241>/Wheel_Speed_FL_Data_Ad' */
      rtb_Wheel_Speed_FL_Data_sat = rtb_Wheel_Speed_FR_Data_sat;

      /* Saturate: '<S241>/Wheel_Speed_FL_Data_sat' */
      if (rtb_Wheel_Speed_FL_Data_sat > 360.0) {
        rtb_Wheel_Speed_FL_Data_sat = 360.0;
      }

      /* End of Saturate: '<S241>/Wheel_Speed_FL_Data_sat' */

      /* DataTypeConversion: '<S241>/Wheel_Speed_FL_Direction_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = VCU_CS75_12_27_test_B.CANReceive_o4_is[6];

      /* S-Function (sfix_bitop): '<S241>/Wheel_Speed_FL_Direction_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 96U;

      /* ArithShift: '<S241>/Wheel_Speed_FL_Direction_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 5);

      /* DataTypeConversion: '<S241>/Wheel_Speed_FL_Directioncv' */
      rtb_Wheel_Speed_FR_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S241>/Wheel_Speed_FL_Direction_Ad' */
      rtb_Wheel_Speed_FL_Direction_sa = (int32_T)rtb_Wheel_Speed_FR_Data_sat;

      /* Saturate: '<S241>/Wheel_Speed_FL_Direction_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_FL_Direction_sa;
      rtb_Wheel_Speed_FL_Direction_sa = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* DataTypeConversion: '<S241>/Wheel_Speed_FL_Valid_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = VCU_CS75_12_27_test_B.CANReceive_o4_is[6];

      /* S-Function (sfix_bitop): '<S241>/Wheel_Speed_FL_Valid_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 128U;

      /* ArithShift: '<S241>/Wheel_Speed_FL_Valid_Data_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 7);

      /* DataTypeConversion: '<S241>/Wheel_Speed_FL_Valid_Datacv' */
      rtb_Wheel_Speed_FR_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S241>/Wheel_Speed_FL_Valid_Data_Ad' */
      rtb_Wheel_Speed_FL_Valid_Data_s = (int32_T)rtb_Wheel_Speed_FR_Data_sat;

      /* Saturate: '<S241>/Wheel_Speed_FL_Valid_Data_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_FL_Valid_Data_s;
      rtb_Wheel_Speed_FL_Valid_Data_s = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* Product: '<S241>/Wheel_Speed_FR_Datainput5_P' incorporates:
       *  Constant: '<S241>/Wheel_Speed_FR_Datainput5_C'
       */
      rtb_Wheel_Speed_FR_Data_sat = (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_is[4] * 256.0;

      /* Sum: '<S241>/Wheel_Speed_FR_Datainput5_Ad' */
      rtb_Wheel_Speed_RL_Data_sat = rtb_Wheel_Speed_FR_Data_sat + (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_is[5];

      /* DataTypeConversion: '<S241>/Wheel_Speed_FR_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)rtb_Wheel_Speed_RL_Data_sat;

      /* S-Function (sfix_bitop): '<S241>/Wheel_Speed_FR_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 8191U;

      /* DataTypeConversion: '<S241>/Wheel_Speed_FR_Datacv' */
      rtb_Wheel_Speed_RL_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Gain: '<S241>/Wheel_Speed_FR_Data_F' */
      rtb_Wheel_Speed_RL_Data_sat *= 0.05625;

      /* Sum: '<S241>/Wheel_Speed_FR_Data_Ad' */
      rtb_Wheel_Speed_FR_Data_sat = rtb_Wheel_Speed_RL_Data_sat;

      /* Saturate: '<S241>/Wheel_Speed_FR_Data_sat' */
      if (rtb_Wheel_Speed_FR_Data_sat > 360.0) {
        rtb_Wheel_Speed_FR_Data_sat = 360.0;
      }

      /* End of Saturate: '<S241>/Wheel_Speed_FR_Data_sat' */

      /* DataTypeConversion: '<S241>/Wheel_Speed_FR_Direction_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = VCU_CS75_12_27_test_B.CANReceive_o4_is[4];

      /* S-Function (sfix_bitop): '<S241>/Wheel_Speed_FR_Direction_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 96U;

      /* ArithShift: '<S241>/Wheel_Speed_FR_Direction_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 5);

      /* DataTypeConversion: '<S241>/Wheel_Speed_FR_Directioncv' */
      rtb_Wheel_Speed_RL_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S241>/Wheel_Speed_FR_Direction_Ad' */
      rtb_Wheel_Speed_FR_Direction_sa = (int32_T)rtb_Wheel_Speed_RL_Data_sat;

      /* Saturate: '<S241>/Wheel_Speed_FR_Direction_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_FR_Direction_sa;
      rtb_Wheel_Speed_FR_Direction_sa = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* DataTypeConversion: '<S241>/Wheel_Speed_FR_Valid_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = VCU_CS75_12_27_test_B.CANReceive_o4_is[4];

      /* S-Function (sfix_bitop): '<S241>/Wheel_Speed_FR_Valid_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 128U;

      /* ArithShift: '<S241>/Wheel_Speed_FR_Valid_Data_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 7);

      /* DataTypeConversion: '<S241>/Wheel_Speed_FR_Valid_Datacv' */
      rtb_Wheel_Speed_RL_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S241>/Wheel_Speed_FR_Valid_Data_Ad' */
      rtb_Wheel_Speed_FR_Valid_Data_s = (int32_T)rtb_Wheel_Speed_RL_Data_sat;

      /* Saturate: '<S241>/Wheel_Speed_FR_Valid_Data_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_FR_Valid_Data_s;
      rtb_Wheel_Speed_FR_Valid_Data_s = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* Product: '<S241>/Wheel_Speed_RL_Datainput3_P' incorporates:
       *  Constant: '<S241>/Wheel_Speed_RL_Datainput3_C'
       */
      rtb_Wheel_Speed_RL_Data_sat = (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_is[2] * 256.0;

      /* Sum: '<S241>/Wheel_Speed_RL_Datainput3_Ad' */
      rtb_Wheel_Speed_RR_Data_sat = rtb_Wheel_Speed_RL_Data_sat + (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_is[3];

      /* DataTypeConversion: '<S241>/Wheel_Speed_RL_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)rtb_Wheel_Speed_RR_Data_sat;

      /* S-Function (sfix_bitop): '<S241>/Wheel_Speed_RL_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 8191U;

      /* DataTypeConversion: '<S241>/Wheel_Speed_RL_Datacv' */
      rtb_Wheel_Speed_RR_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Gain: '<S241>/Wheel_Speed_RL_Data_F' */
      rtb_Wheel_Speed_RR_Data_sat *= 0.05625;

      /* Sum: '<S241>/Wheel_Speed_RL_Data_Ad' */
      rtb_Wheel_Speed_RL_Data_sat = rtb_Wheel_Speed_RR_Data_sat;

      /* Saturate: '<S241>/Wheel_Speed_RL_Data_sat' */
      if (rtb_Wheel_Speed_RL_Data_sat > 360.0) {
        rtb_Wheel_Speed_RL_Data_sat = 360.0;
      }

      /* End of Saturate: '<S241>/Wheel_Speed_RL_Data_sat' */

      /* DataTypeConversion: '<S241>/Wheel_Speed_RL_Direction_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = VCU_CS75_12_27_test_B.CANReceive_o4_is[2];

      /* S-Function (sfix_bitop): '<S241>/Wheel_Speed_RL_Direction_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 96U;

      /* ArithShift: '<S241>/Wheel_Speed_RL_Direction_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 5);

      /* DataTypeConversion: '<S241>/Wheel_Speed_RL_Directioncv' */
      rtb_Wheel_Speed_RR_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S241>/Wheel_Speed_RL_Direction_Ad' */
      rtb_Wheel_Speed_RL_Direction_sa = (int32_T)rtb_Wheel_Speed_RR_Data_sat;

      /* Saturate: '<S241>/Wheel_Speed_RL_Direction_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RL_Direction_sa;
      rtb_Wheel_Speed_RL_Direction_sa = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* DataTypeConversion: '<S241>/Wheel_Speed_RL_Valid_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = VCU_CS75_12_27_test_B.CANReceive_o4_is[2];

      /* S-Function (sfix_bitop): '<S241>/Wheel_Speed_RL_Valid_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 128U;

      /* ArithShift: '<S241>/Wheel_Speed_RL_Valid_Data_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 7);

      /* DataTypeConversion: '<S241>/Wheel_Speed_RL_Valid_Datacv' */
      rtb_Wheel_Speed_RR_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S241>/Wheel_Speed_RL_Valid_Data_Ad' */
      rtb_Wheel_Speed_RL_Valid_Data_s = (int32_T)rtb_Wheel_Speed_RR_Data_sat;

      /* Saturate: '<S241>/Wheel_Speed_RL_Valid_Data_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RL_Valid_Data_s;
      rtb_Wheel_Speed_RL_Valid_Data_s = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* Product: '<S241>/Wheel_Speed_RR_Datainput1_P' incorporates:
       *  Constant: '<S241>/Wheel_Speed_RR_Datainput1_C'
       */
      rtb_Wheel_Speed_RR_Data_sat = (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_is[0] * 256.0;

      /* Sum: '<S241>/Wheel_Speed_RR_Datainput1_Ad' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RR_Data_sat + (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_is[1];

      /* DataTypeConversion: '<S241>/Wheel_Speed_RR_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* S-Function (sfix_bitop): '<S241>/Wheel_Speed_RR_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 8191U;

      /* DataTypeConversion: '<S241>/Wheel_Speed_RR_Datacv' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Gain: '<S241>/Wheel_Speed_RR_Data_F' */
      rtb_Wheel_Speed_RR_Valid_Datacv *= 0.05625;

      /* Sum: '<S241>/Wheel_Speed_RR_Data_Ad' */
      rtb_Wheel_Speed_RR_Data_sat = rtb_Wheel_Speed_RR_Valid_Datacv;

      /* Saturate: '<S241>/Wheel_Speed_RR_Data_sat' */
      if (rtb_Wheel_Speed_RR_Data_sat > 360.0) {
        rtb_Wheel_Speed_RR_Data_sat = 360.0;
      }

      /* End of Saturate: '<S241>/Wheel_Speed_RR_Data_sat' */

      /* DataTypeConversion: '<S241>/Wheel_Speed_RR_Direction_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = VCU_CS75_12_27_test_B.CANReceive_o4_is[0];

      /* S-Function (sfix_bitop): '<S241>/Wheel_Speed_RR_Direction_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 96U;

      /* ArithShift: '<S241>/Wheel_Speed_RR_Direction_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 5);

      /* DataTypeConversion: '<S241>/Wheel_Speed_RR_Directioncv' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S241>/Wheel_Speed_RR_Direction_Ad' */
      rtb_Wheel_Speed_RR_Direction_sa = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* Saturate: '<S241>/Wheel_Speed_RR_Direction_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RR_Direction_sa;
      rtb_Wheel_Speed_RR_Direction_sa = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* DataTypeConversion: '<S241>/Wheel_Speed_RR_Valid_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = VCU_CS75_12_27_test_B.CANReceive_o4_is[0];

      /* S-Function (sfix_bitop): '<S241>/Wheel_Speed_RR_Valid_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 128U;

      /* ArithShift: '<S241>/Wheel_Speed_RR_Valid_Data_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 7);

      /* DataTypeConversion: '<S241>/Wheel_Speed_RR_Valid_Datacv' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* SignalConversion: '<S240>/Signal Conversion' */
      VCU_CS75_12_27_test_B.Wheel_Speed_RR = rtb_Wheel_Speed_RR_Data_sat;

      /* SignalConversion: '<S240>/Signal Conversion' */
      VCU_CS75_12_27_test_B.Wheel_Speed_FL = rtb_Wheel_Speed_FL_Data_sat;

      /* SignalConversion: '<S240>/Signal Conversion' */
      VCU_CS75_12_27_test_B.Wheel_Speed_FL_Direction =
        rtb_Wheel_Speed_FL_Direction_sa;

      /* SignalConversion: '<S240>/Signal Conversion' */
      VCU_CS75_12_27_test_B.Wheel_Speed_FL_Valid =
        rtb_Wheel_Speed_FL_Valid_Data_s;

      /* SignalConversion: '<S240>/Signal Conversion' */
      VCU_CS75_12_27_test_B.Wheel_Speed_RR_Direction =
        rtb_Wheel_Speed_RR_Direction_sa;

      /* SignalConversion: '<S240>/Signal Conversion' */
      VCU_CS75_12_27_test_B.Wheel_Speed_RR_Valid =
        rtb_Wheel_Speed_RR_Valid_Datacv;

      /* SignalConversion: '<S240>/Signal Conversion' */
      VCU_CS75_12_27_test_B.Wheel_Speed_RL = rtb_Wheel_Speed_RL_Data_sat;

      /* SignalConversion: '<S240>/Signal Conversion' */
      VCU_CS75_12_27_test_B.Wheel_Speed_RL_Direction =
        rtb_Wheel_Speed_RL_Direction_sa;

      /* SignalConversion: '<S240>/Signal Conversion' */
      VCU_CS75_12_27_test_B.Wheel_Speed_RL_Valid =
        rtb_Wheel_Speed_RL_Valid_Data_s;

      /* SignalConversion: '<S240>/Signal Conversion' */
      VCU_CS75_12_27_test_B.Wheel_Speed_FR = rtb_Wheel_Speed_FR_Data_sat;

      /* SignalConversion: '<S240>/Signal Conversion' */
      VCU_CS75_12_27_test_B.Wheel_Speed_FR_Direction =
        rtb_Wheel_Speed_FR_Direction_sa;

      /* SignalConversion: '<S240>/Signal Conversion' */
      VCU_CS75_12_27_test_B.Wheel_Speed_FR_Valid =
        rtb_Wheel_Speed_FR_Valid_Data_s;
    }

    /* End of Outputs for SubSystem: '<S239>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S93>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF17RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf17looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_d= 641;
    VCU_CS75_12_27_test_B.CANReceive_o5_kr= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_f= ec_can_receive(1,17, CAN1BUF17RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_jzv[0]= CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_jzv[1]= CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_jzv[2]= CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_jzv[3]= CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_jzv[4]= CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_jzv[5]= CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_jzv[6]= CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_jzv[7]= CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
  }

  /* Call the system: <S93>/ReceiveMessages */

  /* Output and update for function-call system: '<S93>/ReceiveMessages' */
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

    /* Outputs for Enabled SubSystem: '<S254>/Subsystem' incorporates:
     *  EnablePort: '<S255>/Enable'
     */
    if (VCU_CS75_12_27_test_B.CANReceive_o2_f > 0) {
      /* DataTypeConversion: '<S256>/ESP_ABSActiveStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L = VCU_CS75_12_27_test_B.CANReceive_o4_jzv[0];

      /* S-Function (sfix_bitop): '<S256>/ESP_ABSActiveStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 128U;

      /* ArithShift: '<S256>/ESP_ABSActiveStatus_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 7);

      /* DataTypeConversion: '<S256>/ESP_ABSActiveStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S256>/ESP_ABSActiveStatus_Ad' */
      rtb_ESP_ABSActiveStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S256>/ESP_ABSActiveStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_ABSActiveStatus_sat;
      rtb_ESP_ABSActiveStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S256>/ESP_ABSFailStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L = VCU_CS75_12_27_test_B.CANReceive_o4_jzv[0];

      /* S-Function (sfix_bitop): '<S256>/ESP_ABSFailStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 8U;

      /* ArithShift: '<S256>/ESP_ABSFailStatus_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 3);

      /* DataTypeConversion: '<S256>/ESP_ABSFailStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S256>/ESP_ABSFailStatus_Ad' */
      rtb_ESP_ABSFailStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S256>/ESP_ABSFailStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_ABSFailStatus_sat;
      rtb_ESP_ABSFailStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S256>/ESP_BrakePedalStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L = VCU_CS75_12_27_test_B.CANReceive_o4_jzv[6];

      /* S-Function (sfix_bitop): '<S256>/ESP_BrakePedalStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 96U;

      /* ArithShift: '<S256>/ESP_BrakePedalStatus_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 5);

      /* DataTypeConversion: '<S256>/ESP_BrakePedalStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S256>/ESP_BrakePedalStatus_Ad' */
      rtb_ESP_BrakePedalStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S256>/ESP_BrakePedalStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_BrakePedalStatus_sat;
      rtb_ESP_BrakePedalStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S256>/ESP_Checksum_Convert' */
      rtb_ESP_VehicleSpeed_Status_L = VCU_CS75_12_27_test_B.CANReceive_o4_jzv[7];

      /* DataTypeConversion: '<S256>/ESP_Checksumcv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S256>/ESP_Checksum_Ad' */
      rtb_ESP_Checksum_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S256>/ESP_Checksum_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_Checksum_sat;
      rtb_ESP_Checksum_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S256>/ESP_EBDFailStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L = VCU_CS75_12_27_test_B.CANReceive_o4_jzv[0];

      /* S-Function (sfix_bitop): '<S256>/ESP_EBDFailStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 4U;

      /* ArithShift: '<S256>/ESP_EBDFailStatus_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 2);

      /* DataTypeConversion: '<S256>/ESP_EBDFailStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S256>/ESP_EBDFailStatus_Ad' */
      rtb_ESP_EBDFailStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S256>/ESP_EBDFailStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_EBDFailStatus_sat;
      rtb_ESP_EBDFailStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S256>/ESP_ESPActiveStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L = VCU_CS75_12_27_test_B.CANReceive_o4_jzv[0];

      /* S-Function (sfix_bitop): '<S256>/ESP_ESPActiveStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 1U;

      /* DataTypeConversion: '<S256>/ESP_ESPActiveStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S256>/ESP_ESPActiveStatus_Ad' */
      rtb_ESP_ESPActiveStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S256>/ESP_ESPActiveStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_ESPActiveStatus_sat;
      rtb_ESP_ESPActiveStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S256>/ESP_ESPFailStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L = VCU_CS75_12_27_test_B.CANReceive_o4_jzv[0];

      /* S-Function (sfix_bitop): '<S256>/ESP_ESPFailStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 16U;

      /* ArithShift: '<S256>/ESP_ESPFailStatus_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 4);

      /* DataTypeConversion: '<S256>/ESP_ESPFailStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S256>/ESP_ESPFailStatus_Ad' */
      rtb_ESP_ESPFailStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S256>/ESP_ESPFailStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_ESPFailStatus_sat;
      rtb_ESP_ESPFailStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S256>/ESP_ESPSwitchStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L = VCU_CS75_12_27_test_B.CANReceive_o4_jzv[0];

      /* S-Function (sfix_bitop): '<S256>/ESP_ESPSwitchStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 2U;

      /* ArithShift: '<S256>/ESP_ESPSwitchStatus_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 1);

      /* DataTypeConversion: '<S256>/ESP_ESPSwitchStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S256>/ESP_ESPSwitchStatus_Ad' */
      rtb_ESP_ESPSwitchStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S256>/ESP_ESPSwitchStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_ESPSwitchStatus_sat;
      rtb_ESP_ESPSwitchStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S256>/ESP_RollingCounter_Convert' */
      rtb_ESP_VehicleSpeed_Status_L = VCU_CS75_12_27_test_B.CANReceive_o4_jzv[6];

      /* S-Function (sfix_bitop): '<S256>/ESP_RollingCounter_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 15U;

      /* DataTypeConversion: '<S256>/ESP_RollingCountercv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S256>/ESP_RollingCounter_Ad' */
      rtb_ESP_RollingCounter_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S256>/ESP_RollingCounter_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_RollingCounter_sat;
      rtb_ESP_RollingCounter_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Product: '<S256>/ESP_VehicleSpeedinput5_P' incorporates:
       *  Constant: '<S256>/ESP_VehicleSpeedinput5_C'
       */
      rtb_ESP_VehicleSpeed_sat = (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_jzv[4] * 256.0;

      /* Sum: '<S256>/ESP_VehicleSpeedinput5_Ad' */
      rtb_ESP_VehicleSpeed_Statuscv = rtb_ESP_VehicleSpeed_sat + (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_jzv[5];

      /* DataTypeConversion: '<S256>/ESP_VehicleSpeed_Convert' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)rtb_ESP_VehicleSpeed_Statuscv;

      /* S-Function (sfix_bitop): '<S256>/ESP_VehicleSpeed_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 8191U;

      /* DataTypeConversion: '<S256>/ESP_VehicleSpeedcv' */
      rtb_ESP_VehicleSpeed_Statuscv = rtb_ESP_VehicleSpeed_Status_L;

      /* Gain: '<S256>/ESP_VehicleSpeed_F' */
      rtb_ESP_VehicleSpeed_Statuscv *= 0.05625;

      /* Sum: '<S256>/ESP_VehicleSpeed_Ad' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Statuscv;

      /* DataTypeConversion: '<S256>/ESP_VehicleSpeed_Status_Convert' */
      rtb_ESP_VehicleSpeed_Status_L = VCU_CS75_12_27_test_B.CANReceive_o4_jzv[4];

      /* S-Function (sfix_bitop): '<S256>/ESP_VehicleSpeed_Status_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 32U;

      /* ArithShift: '<S256>/ESP_VehicleSpeed_Status_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 5);

      /* DataTypeConversion: '<S256>/ESP_VehicleSpeed_Statuscv' */
      rtb_ESP_VehicleSpeed_Statuscv = rtb_ESP_VehicleSpeed_Status_L;

      /* Saturate: '<S256>/ESP_VehicleSpeed_sat' */
      if (rtb_ESP_VehicleSpeed_sat > 360.0) {
        rtb_ESP_VehicleSpeed_sat = 360.0;
      }

      /* End of Saturate: '<S256>/ESP_VehicleSpeed_sat' */

      /* SignalConversion: '<S255>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_ESPActiveStatus_n = rtb_ESP_ESPActiveStatus_sat;

      /* SignalConversion: '<S255>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_BrakePedalStatus = rtb_ESP_BrakePedalStatus_sat;

      /* SignalConversion: '<S255>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_Checksum = rtb_ESP_Checksum_sat;

      /* SignalConversion: '<S255>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_ESPSwitchStatus = rtb_ESP_ESPSwitchStatus_sat;

      /* SignalConversion: '<S255>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_EBDFailStatus_l = rtb_ESP_EBDFailStatus_sat;

      /* SignalConversion: '<S255>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_ABSFailStatus = rtb_ESP_ABSFailStatus_sat;

      /* SignalConversion: '<S255>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_ESPFailStatus = rtb_ESP_ESPFailStatus_sat;

      /* SignalConversion: '<S255>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_ABSActiveStatus = rtb_ESP_ABSActiveStatus_sat;

      /* SignalConversion: '<S255>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_VehicleSpeed = rtb_ESP_VehicleSpeed_sat;

      /* SignalConversion: '<S255>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_VehicleSpeed_Status =
        rtb_ESP_VehicleSpeed_Statuscv;

      /* SignalConversion: '<S255>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_RollingCounter_p = rtb_ESP_RollingCounter_sat;
    }

    /* End of Outputs for SubSystem: '<S254>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S94>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF18RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf18looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_ex= 647;
    VCU_CS75_12_27_test_B.CANReceive_o5_hu= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_m2= ec_can_receive(1,18, CAN1BUF18RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_c[0]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_c[1]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_c[2]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_c[3]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_c[4]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_c[5]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_c[6]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_c[7]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
  }

  /* Call the system: <S94>/ReceiveMessages */

  /* Output and update for function-call system: '<S94>/ReceiveMessages' */
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

    /* Outputs for Enabled SubSystem: '<S268>/Subsystem' incorporates:
     *  EnablePort: '<S269>/Enable'
     */
    if (VCU_CS75_12_27_test_B.CANReceive_o2_m2 > 0) {
      /* DataTypeConversion: '<S270>/ESP_CheckSum_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_12_27_test_B.CANReceive_o4_c[7];

      /* S-Function (sfix_bitop): '<S270>/ESP_CheckSum_L' */
      rtb_ESP_YawRate_Status_L &= 15U;

      /* DataTypeConversion: '<S270>/ESP_CheckSumcv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S270>/ESP_CheckSum_Ad' */
      rtb_ESP_CheckSum_sat = (int32_T)rtb_ESP_LongAcceleration_sat;

      /* Saturate: '<S270>/ESP_CheckSum_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_CheckSum_sat;
      rtb_ESP_CheckSum_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* DataTypeConversion: '<S270>/ESP_HBBActiveStatus_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_12_27_test_B.CANReceive_o4_c[6];

      /* S-Function (sfix_bitop): '<S270>/ESP_HBBActiveStatus_L' */
      rtb_ESP_YawRate_Status_L &= 8U;

      /* ArithShift: '<S270>/ESP_HBBActiveStatus_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        3);

      /* DataTypeConversion: '<S270>/ESP_HBBActiveStatuscv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S270>/ESP_HBBActiveStatus_Ad' */
      rtb_ESP_HBBActiveStatus_sat = (int32_T)rtb_ESP_LongAcceleration_sat;

      /* Saturate: '<S270>/ESP_HBBActiveStatus_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_HBBActiveStatus_sat;
      rtb_ESP_HBBActiveStatus_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* DataTypeConversion: '<S270>/ESP_HBB_Status_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_12_27_test_B.CANReceive_o4_c[6];

      /* S-Function (sfix_bitop): '<S270>/ESP_HBB_Status_L' */
      rtb_ESP_YawRate_Status_L &= 3U;

      /* DataTypeConversion: '<S270>/ESP_HBB_Statuscv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S270>/ESP_HBB_Status_Ad' */
      rtb_ESP_HBB_Status_sat = (int32_T)rtb_ESP_LongAcceleration_sat;

      /* Saturate: '<S270>/ESP_HBB_Status_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_HBB_Status_sat;
      rtb_ESP_HBB_Status_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* DataTypeConversion: '<S270>/ESP_HDC_Status_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_12_27_test_B.CANReceive_o4_c[0];

      /* S-Function (sfix_bitop): '<S270>/ESP_HDC_Status_L' */
      rtb_ESP_YawRate_Status_L &= 48U;

      /* ArithShift: '<S270>/ESP_HDC_Status_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        4);

      /* DataTypeConversion: '<S270>/ESP_HDC_Statuscv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S270>/ESP_HDC_Status_Ad' */
      rtb_ESP_HDC_Status_sat = (int32_T)rtb_ESP_LongAcceleration_sat;

      /* Saturate: '<S270>/ESP_HDC_Status_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_HDC_Status_sat;
      rtb_ESP_HDC_Status_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* DataTypeConversion: '<S270>/ESP_HHC_Available_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_12_27_test_B.CANReceive_o4_c[6];

      /* S-Function (sfix_bitop): '<S270>/ESP_HHC_Available_L' */
      rtb_ESP_YawRate_Status_L &= 4U;

      /* ArithShift: '<S270>/ESP_HHC_Available_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        2);

      /* DataTypeConversion: '<S270>/ESP_HHC_Availablecv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S270>/ESP_HHC_Available_Ad' */
      rtb_ESP_HHC_Available_sat = (int32_T)rtb_ESP_LongAcceleration_sat;

      /* Saturate: '<S270>/ESP_HHC_Available_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_HHC_Available_sat;
      rtb_ESP_HHC_Available_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* DataTypeConversion: '<S270>/ESP_LatAcceleration_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_12_27_test_B.CANReceive_o4_c[2];

      /* DataTypeConversion: '<S270>/ESP_LatAccelerationcv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Gain: '<S270>/ESP_LatAcceleration_F' */
      rtb_ESP_LongAcceleration_sat *= 0.1;

      /* Sum: '<S270>/ESP_LatAcceleration_Ad' incorporates:
       *  Constant: '<S270>/ESP_LatAcceleration_O'
       */
      rtb_ESP_LatAcceleration_sat = rtb_ESP_LongAcceleration_sat +
        -12.699999809265137;

      /* Saturate: '<S270>/ESP_LatAcceleration_sat' */
      if (rtb_ESP_LatAcceleration_sat > 12.7) {
        rtb_ESP_LatAcceleration_sat = 12.7;
      }

      /* End of Saturate: '<S270>/ESP_LatAcceleration_sat' */

      /* DataTypeConversion: '<S270>/ESP_LongAccelValid_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_12_27_test_B.CANReceive_o4_c[6];

      /* S-Function (sfix_bitop): '<S270>/ESP_LongAccelValid_L' */
      rtb_ESP_YawRate_Status_L &= 64U;

      /* ArithShift: '<S270>/ESP_LongAccelValid_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        6);

      /* DataTypeConversion: '<S270>/ESP_LongAccelValidcv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S270>/ESP_LongAccelValid_Ad' */
      rtb_ESP_LongAccelValid_sat = (int32_T)rtb_ESP_LongAcceleration_sat;

      /* Saturate: '<S270>/ESP_LongAccelValid_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_LongAccelValid_sat;
      rtb_ESP_LongAccelValid_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* Product: '<S270>/ESP_LongAccelerationinput4_P' incorporates:
       *  Constant: '<S270>/ESP_LongAccelerationinput4_C'
       */
      rtb_ESP_LongAcceleration_sat = (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_c[3] * 256.0;

      /* Sum: '<S270>/ESP_LongAccelerationinput4_Ad' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_LongAcceleration_sat + (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_c[4];

      /* DataTypeConversion: '<S270>/ESP_LongAcceleration_Convert' */
      rtb_ESP_YawRate_Status_L = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* S-Function (sfix_bitop): '<S270>/ESP_LongAcceleration_L' */
      rtb_ESP_YawRate_Status_L &= 65472U;

      /* ArithShift: '<S270>/ESP_LongAcceleration_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        6);

      /* DataTypeConversion: '<S270>/ESP_LongAccelerationcv' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_YawRate_Status_L;

      /* Gain: '<S270>/ESP_LongAcceleration_F' */
      rtb_ESP_TODTorqueMaxLimit_sat *= 0.03125;

      /* Sum: '<S270>/ESP_LongAcceleration_Ad' incorporates:
       *  Constant: '<S270>/ESP_LongAcceleration_O'
       */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_TODTorqueMaxLimit_sat + -16.0;

      /* DataTypeConversion: '<S270>/ESP_RollingCounter_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_12_27_test_B.CANReceive_o4_c[7];

      /* S-Function (sfix_bitop): '<S270>/ESP_RollingCounter_L' */
      rtb_ESP_YawRate_Status_L &= 240U;

      /* ArithShift: '<S270>/ESP_RollingCounter_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        4);

      /* DataTypeConversion: '<S270>/ESP_RollingCountercv' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S270>/ESP_RollingCounter_Ad' */
      rtb_ESP_RollingCounter_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* Saturate: '<S270>/ESP_RollingCounter_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_RollingCounter_sat;
      rtb_ESP_RollingCounter_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* DataTypeConversion: '<S270>/ESP_TODFastOpenRequest_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_12_27_test_B.CANReceive_o4_c[0];

      /* S-Function (sfix_bitop): '<S270>/ESP_TODFastOpenRequest_L' */
      rtb_ESP_YawRate_Status_L &= 192U;

      /* ArithShift: '<S270>/ESP_TODFastOpenRequest_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        6);

      /* DataTypeConversion: '<S270>/ESP_TODFastOpenRequestcv' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S270>/ESP_TODFastOpenRequest_Ad' */
      rtb_ESP_TODFastOpenRequest_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* Saturate: '<S270>/ESP_TODFastOpenRequest_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_TODFastOpenRequest_sat;
      rtb_ESP_TODFastOpenRequest_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* Product: '<S270>/ESP_TODTorqueMaxLimitinput1_P' incorporates:
       *  Constant: '<S270>/ESP_TODTorqueMaxLimitinput1_C'
       */
      rtb_ESP_TODTorqueMaxLimit_sat = (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_c[0] * 256.0;

      /* Sum: '<S270>/ESP_TODTorqueMaxLimitinput1_Ad' */
      rtb_ESP_YawRate_sat = rtb_ESP_TODTorqueMaxLimit_sat + (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_c[1];

      /* DataTypeConversion: '<S270>/ESP_TODTorqueMaxLimit_Convert' */
      rtb_ESP_YawRate_Status_L = (int32_T)rtb_ESP_YawRate_sat;

      /* S-Function (sfix_bitop): '<S270>/ESP_TODTorqueMaxLimit_L' */
      rtb_ESP_YawRate_Status_L &= 4095U;

      /* DataTypeConversion: '<S270>/ESP_TODTorqueMaxLimitcv' */
      rtb_ESP_YawRate_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S270>/ESP_TODTorqueMaxLimit_Ad' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_YawRate_sat;

      /* Product: '<S270>/ESP_YawRateinput5_P' incorporates:
       *  Constant: '<S270>/ESP_YawRateinput5_C'
       */
      rtb_ESP_YawRate_sat = (real_T)VCU_CS75_12_27_test_B.CANReceive_o4_c[4] *
        256.0;

      /* Sum: '<S270>/ESP_YawRateinput5_Ad' */
      rtb_ESP_YawRate_Statuscv = rtb_ESP_YawRate_sat + (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_c[5];

      /* DataTypeConversion: '<S270>/ESP_YawRate_Convert' */
      rtb_ESP_YawRate_Status_L = (int32_T)rtb_ESP_YawRate_Statuscv;

      /* S-Function (sfix_bitop): '<S270>/ESP_YawRate_L' */
      rtb_ESP_YawRate_Status_L &= 16383U;

      /* DataTypeConversion: '<S270>/ESP_YawRatecv' */
      rtb_ESP_YawRate_Statuscv = rtb_ESP_YawRate_Status_L;

      /* Gain: '<S270>/ESP_YawRate_F' */
      rtb_ESP_YawRate_Statuscv *= 0.01;

      /* Sum: '<S270>/ESP_YawRate_Ad' incorporates:
       *  Constant: '<S270>/ESP_YawRate_O'
       */
      rtb_ESP_YawRate_sat = rtb_ESP_YawRate_Statuscv + -81.910003662109375;

      /* DataTypeConversion: '<S270>/ESP_YawRate_Status_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_12_27_test_B.CANReceive_o4_c[6];

      /* S-Function (sfix_bitop): '<S270>/ESP_YawRate_Status_L' */
      rtb_ESP_YawRate_Status_L &= 128U;

      /* ArithShift: '<S270>/ESP_YawRate_Status_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        7);

      /* DataTypeConversion: '<S270>/ESP_YawRate_Statuscv' */
      rtb_ESP_YawRate_Statuscv = rtb_ESP_YawRate_Status_L;

      /* Saturate: '<S270>/ESP_YawRate_sat' */
      if (rtb_ESP_YawRate_sat > 81.91) {
        rtb_ESP_YawRate_sat = 81.91;
      } else {
        if (rtb_ESP_YawRate_sat < -81.91) {
          rtb_ESP_YawRate_sat = -81.91;
        }
      }

      /* End of Saturate: '<S270>/ESP_YawRate_sat' */

      /* SignalConversion: '<S269>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_TODTorqueMaxLimit =
        rtb_ESP_TODTorqueMaxLimit_sat;

      /* SignalConversion: '<S269>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_LongAccelValid = rtb_ESP_LongAccelValid_sat;

      /* SignalConversion: '<S269>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_YawRate_Status = rtb_ESP_YawRate_Statuscv;

      /* SignalConversion: '<S269>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_CheckSum = rtb_ESP_CheckSum_sat;

      /* SignalConversion: '<S269>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_RollingCounter = rtb_ESP_RollingCounter_sat;

      /* SignalConversion: '<S269>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_HDC_Status = rtb_ESP_HDC_Status_sat;

      /* SignalConversion: '<S269>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_TODFastOpenRequest =
        rtb_ESP_TODFastOpenRequest_sat;

      /* SignalConversion: '<S269>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_LatAcceleration = rtb_ESP_LatAcceleration_sat;

      /* SignalConversion: '<S269>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_LongAcceleration = rtb_ESP_LongAcceleration_sat;

      /* SignalConversion: '<S269>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_YawRate = rtb_ESP_YawRate_sat;

      /* SignalConversion: '<S269>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_HBB_Status = rtb_ESP_HBB_Status_sat;

      /* SignalConversion: '<S269>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_HHC_Available_h = rtb_ESP_HHC_Available_sat;

      /* SignalConversion: '<S269>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_HBBActiveStatus = rtb_ESP_HBBActiveStatus_sat;
    }

    /* End of Outputs for SubSystem: '<S268>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S95>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF27RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf27looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_nd= 523;
    VCU_CS75_12_27_test_B.CANReceive_o5_dk= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_k= ec_can_receive(1,27, CAN1BUF27RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_og[0]= CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_og[1]= CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_og[2]= CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_og[3]= CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_og[4]= CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_og[5]= CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_og[6]= CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_og[7]= CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
  }

  /* Call the system: <S95>/ReceiveMessages */

  /* Output and update for function-call system: '<S95>/ReceiveMessages' */
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

    /* Outputs for Enabled SubSystem: '<S284>/Subsystem' incorporates:
     *  EnablePort: '<S285>/Enable'
     */
    if (VCU_CS75_12_27_test_B.CANReceive_o2_k > 0) {
      /* Product: '<S286>/SAS_SteeringAngleinput4_P' incorporates:
       *  Constant: '<S286>/SAS_SteeringAngleinput4_C'
       */
      rtb_SAS_SteeringAngle_sat = (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_og[3] * 256.0;

      /* Sum: '<S286>/SAS_SteeringAngleinput4_Ad' */
      rtb_TCU_ShiftPostionValidcv = rtb_SAS_SteeringAngle_sat + (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_og[4];

      /* DataTypeConversion: '<S286>/SAS_SteeringAngle_Convert' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)rtb_TCU_ShiftPostionValidcv;

      /* DataTypeConversion: '<S286>/SAS_SteeringAnglecv' */
      rtb_SAS_SteeringAnglesubcon = (real32_T)rtb_TCU_ShiftPostionValid_L;

      /* RelationalOperator: '<S286>/SAS_SteeringAngleROP' */
      rtb_SAS_SteeringAngleROP = (rtb_SAS_SteeringAnglesubcon >= 32768.0F);

      /* Switch: '<S286>/SAS_SteeringAngleSW' */
      if (rtb_SAS_SteeringAngleROP) {
        /* Sum: '<S286>/SAS_SteeringAnglesubcon' */
        rtb_SAS_SteeringAnglesubcon = 65536.0F - rtb_SAS_SteeringAnglesubcon;

        /* UnaryMinus: '<S286>/SAS_SteeringAngleMinus' */
        rtb_SAS_SteeringAnglesubcon = -rtb_SAS_SteeringAnglesubcon;
      }

      /* End of Switch: '<S286>/SAS_SteeringAngleSW' */

      /* DataTypeConversion: '<S286>/Data Type Conversion' */
      rtb_TCU_ShiftPostionValidcv = rtb_SAS_SteeringAnglesubcon;

      /* DataTypeConversion: '<S286>/EMS_BrakePedalStatus_Convert' */
      rtb_TCU_ShiftPostionValid_L = VCU_CS75_12_27_test_B.CANReceive_o4_og[0];

      /* S-Function (sfix_bitop): '<S286>/EMS_BrakePedalStatus_L' */
      rtb_TCU_ShiftPostionValid_L &= 192U;

      /* ArithShift: '<S286>/EMS_BrakePedalStatus_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 6);

      /* DataTypeConversion: '<S286>/EMS_BrakePedalStatuscv' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S286>/EMS_BrakePedalStatus_Ad' */
      rtb_EMS_BrakePedalStatus_sat = (int32_T)rtb_SAS_SteeringAngle_sat;

      /* Saturate: '<S286>/EMS_BrakePedalStatus_sat' */
      u0 = rtb_EMS_BrakePedalStatus_sat;
      rtb_EMS_BrakePedalStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S286>/EMS_EngineStartupEnd_Convert' */
      rtb_TCU_ShiftPostionValid_L = VCU_CS75_12_27_test_B.CANReceive_o4_og[1];

      /* S-Function (sfix_bitop): '<S286>/EMS_EngineStartupEnd_L' */
      rtb_TCU_ShiftPostionValid_L &= 48U;

      /* ArithShift: '<S286>/EMS_EngineStartupEnd_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 4);

      /* DataTypeConversion: '<S286>/EMS_EngineStartupEndcv' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S286>/EMS_EngineStartupEnd_Ad' */
      rtb_EMS_EngineStartupEnd_sat = (int32_T)rtb_SAS_SteeringAngle_sat;

      /* Saturate: '<S286>/EMS_EngineStartupEnd_sat' */
      u0 = rtb_EMS_EngineStartupEnd_sat;
      rtb_EMS_EngineStartupEnd_sat = (int32_T)u0;

      /* DataTypeConversion: '<S286>/EMS_EngineStatus_Convert' */
      rtb_TCU_ShiftPostionValid_L = VCU_CS75_12_27_test_B.CANReceive_o4_og[0];

      /* S-Function (sfix_bitop): '<S286>/EMS_EngineStatus_L' */
      rtb_TCU_ShiftPostionValid_L &= 48U;

      /* ArithShift: '<S286>/EMS_EngineStatus_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 4);

      /* DataTypeConversion: '<S286>/EMS_EngineStatuscv' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S286>/EMS_EngineStatus_Ad' */
      rtb_EMS_EngineStatus_sat = (int32_T)rtb_SAS_SteeringAngle_sat;

      /* Saturate: '<S286>/EMS_EngineStatus_sat' */
      u0 = rtb_EMS_EngineStatus_sat;
      rtb_EMS_EngineStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S286>/EPB_BrakeLightOnRequest_Convert' */
      rtb_TCU_ShiftPostionValid_L = VCU_CS75_12_27_test_B.CANReceive_o4_og[5];

      /* S-Function (sfix_bitop): '<S286>/EPB_BrakeLightOnRequest_L' */
      rtb_TCU_ShiftPostionValid_L &= 6U;

      /* ArithShift: '<S286>/EPB_BrakeLightOnRequest_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 1);

      /* DataTypeConversion: '<S286>/EPB_BrakeLightOnRequestcv' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S286>/EPB_BrakeLightOnRequest_Ad' */
      rtb_EPB_BrakeLightOnRequest_sat = (int32_T)rtb_SAS_SteeringAngle_sat;

      /* Saturate: '<S286>/EPB_BrakeLightOnRequest_sat' */
      u0 = rtb_EPB_BrakeLightOnRequest_sat;
      rtb_EPB_BrakeLightOnRequest_sat = (int32_T)u0;

      /* DataTypeConversion: '<S286>/EPB_Status_Convert' */
      rtb_TCU_ShiftPostionValid_L = VCU_CS75_12_27_test_B.CANReceive_o4_og[6];

      /* S-Function (sfix_bitop): '<S286>/EPB_Status_L' */
      rtb_TCU_ShiftPostionValid_L &= 192U;

      /* ArithShift: '<S286>/EPB_Status_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 6);

      /* DataTypeConversion: '<S286>/EPB_Statuscv' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S286>/EPB_Status_Ad' */
      rtb_EPB_Status_sat_h = (int32_T)rtb_SAS_SteeringAngle_sat;

      /* Saturate: '<S286>/EPB_Status_sat' */
      u0 = rtb_EPB_Status_sat_h;
      rtb_EPB_Status_sat_h = (int32_T)u0;

      /* DataTypeConversion: '<S286>/SAS_SteeringAngleValid_Convert' */
      rtb_TCU_ShiftPostionValid_L = VCU_CS75_12_27_test_B.CANReceive_o4_og[0];

      /* S-Function (sfix_bitop): '<S286>/SAS_SteeringAngleValid_L' */
      rtb_TCU_ShiftPostionValid_L &= 1U;

      /* DataTypeConversion: '<S286>/SAS_SteeringAngleValidcv' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S286>/SAS_SteeringAngleValid_Ad' */
      rtb_SAS_SteeringAngleValid_sat = (int32_T)rtb_SAS_SteeringAngle_sat;

      /* Saturate: '<S286>/SAS_SteeringAngleValid_sat' */
      u0 = rtb_SAS_SteeringAngleValid_sat;
      rtb_SAS_SteeringAngleValid_sat = (int32_T)u0;

      /* Gain: '<S286>/SAS_SteeringAngle_F' */
      rtb_TCU_ShiftPostionValidcv *= 0.1;

      /* Sum: '<S286>/SAS_SteeringAngle_Ad' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValidcv;

      /* Saturate: '<S286>/SAS_SteeringAngle_sat' */
      if (rtb_SAS_SteeringAngle_sat > 780.0) {
        rtb_SAS_SteeringAngle_sat = 780.0;
      } else {
        if (rtb_SAS_SteeringAngle_sat < -780.0) {
          rtb_SAS_SteeringAngle_sat = -780.0;
        }
      }

      /* End of Saturate: '<S286>/SAS_SteeringAngle_sat' */

      /* DataTypeConversion: '<S286>/TCU_GearShiftPositon_Convert' */
      rtb_TCU_ShiftPostionValid_L = VCU_CS75_12_27_test_B.CANReceive_o4_og[5];

      /* S-Function (sfix_bitop): '<S286>/TCU_GearShiftPositon_L' */
      rtb_TCU_ShiftPostionValid_L &= 120U;

      /* ArithShift: '<S286>/TCU_GearShiftPositon_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 3);

      /* DataTypeConversion: '<S286>/TCU_GearShiftPositoncv' */
      rtb_TCU_ShiftPostionValidcv = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S286>/TCU_GearShiftPositon_Ad' */
      rtb_TCU_GearShiftPositon_sat = (int32_T)rtb_TCU_ShiftPostionValidcv;

      /* Saturate: '<S286>/TCU_GearShiftPositon_sat' */
      u0 = rtb_TCU_GearShiftPositon_sat;
      rtb_TCU_GearShiftPositon_sat = (int32_T)u0;

      /* DataTypeConversion: '<S286>/TCU_ShiftPostionValid_Convert' */
      rtb_TCU_ShiftPostionValid_L = VCU_CS75_12_27_test_B.CANReceive_o4_og[5];

      /* S-Function (sfix_bitop): '<S286>/TCU_ShiftPostionValid_L' */
      rtb_TCU_ShiftPostionValid_L &= 128U;

      /* ArithShift: '<S286>/TCU_ShiftPostionValid_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 7);

      /* DataTypeConversion: '<S286>/TCU_ShiftPostionValidcv' */
      rtb_TCU_ShiftPostionValidcv = rtb_TCU_ShiftPostionValid_L;

      /* SignalConversion: '<S285>/Signal Conversion' */
      VCU_CS75_12_27_test_B.SAS_SteeringAngleValid_j =
        rtb_SAS_SteeringAngleValid_sat;

      /* SignalConversion: '<S285>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_EngineStatus = rtb_EMS_EngineStatus_sat;

      /* SignalConversion: '<S285>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_BrakePedalStatus_o =
        rtb_EMS_BrakePedalStatus_sat;

      /* SignalConversion: '<S285>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_EngineStartupEnd = rtb_EMS_EngineStartupEnd_sat;

      /* SignalConversion: '<S285>/Signal Conversion' */
      VCU_CS75_12_27_test_B.SAS_SteeringAngle_h = rtb_SAS_SteeringAngle_sat;

      /* SignalConversion: '<S285>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPB_BrakeLightOnRequest =
        rtb_EPB_BrakeLightOnRequest_sat;

      /* SignalConversion: '<S285>/Signal Conversion' */
      VCU_CS75_12_27_test_B.TCU_GearShiftPositon = rtb_TCU_GearShiftPositon_sat;

      /* SignalConversion: '<S285>/Signal Conversion' */
      VCU_CS75_12_27_test_B.TCU_ShiftPostionValid = rtb_TCU_ShiftPostionValidcv;

      /* SignalConversion: '<S285>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPB_Status = rtb_EPB_Status_sat_h;
    }

    /* End of Outputs for SubSystem: '<S284>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S96>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF29RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf29looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_m= 776;
    VCU_CS75_12_27_test_B.CANReceive_o5_io= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_em= ec_can_receive(1,29, CAN1BUF29RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_ga[0]= CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ga[1]= CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ga[2]= CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ga[3]= CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ga[4]= CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ga[5]= CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ga[6]= CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ga[7]= CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
  }

  /* Call the system: <S96>/ReceiveMessages */

  /* Output and update for function-call system: '<S96>/ReceiveMessages' */
  {
    int32_T rtb_IP_TotalOdometerinput6_Ad;
    real_T rtb_IP_TotalOdometer_sat;
    uint32_T rtb_IP_TotalOdometer_Convert;

    /* Outputs for Enabled SubSystem: '<S296>/Subsystem' incorporates:
     *  EnablePort: '<S297>/Enable'
     */
    if (VCU_CS75_12_27_test_B.CANReceive_o2_em > 0) {
      /* Product: '<S298>/IP_TotalOdometerinput6_P' incorporates:
       *  Constant: '<S298>/IP_TotalOdometerinput6_C'
       */
      rtb_IP_TotalOdometerinput6_Ad = VCU_CS75_12_27_test_B.CANReceive_o4_ga[5] <<
        8;

      /* Product: '<S298>/IP_TotalOdometerinput5_P' incorporates:
       *  Constant: '<S298>/IP_TotalOdometerinput5_C'
       */
      rtb_IP_TotalOdometer_sat = (real_T)VCU_CS75_12_27_test_B.CANReceive_o4_ga
        [4] * 65536.0;

      /* Sum: '<S298>/IP_TotalOdometerinput5_Ad' */
      rtb_IP_TotalOdometer_sat += (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_ga[6];

      /* Sum: '<S298>/IP_TotalOdometerinput6_Ad' */
      rtb_IP_TotalOdometerinput6_Ad += (int32_T)rtb_IP_TotalOdometer_sat;

      /* DataTypeConversion: '<S298>/IP_TotalOdometer_Convert' */
      rtb_IP_TotalOdometer_Convert = (uint32_T)rtb_IP_TotalOdometerinput6_Ad;

      /* DataTypeConversion: '<S298>/IP_TotalOdometercv' */
      rtb_IP_TotalOdometer_sat = rtb_IP_TotalOdometer_Convert;

      /* Gain: '<S298>/IP_TotalOdometer_F' */
      rtb_IP_TotalOdometer_sat *= 0.1;

      /* Saturate: '<S298>/IP_TotalOdometer_sat' */
      if (rtb_IP_TotalOdometer_sat > 999999.0) {
        rtb_IP_TotalOdometer_sat = 999999.0;
      }

      /* End of Saturate: '<S298>/IP_TotalOdometer_sat' */

      /* SignalConversion: '<S297>/Signal Conversion' */
      VCU_CS75_12_27_test_B.IP_TotalOdometer = rtb_IP_TotalOdometer_sat;
    }

    /* End of Outputs for SubSystem: '<S296>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S97>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF28RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf28looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_l= 818;
    VCU_CS75_12_27_test_B.CANReceive_o5_gf= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_kg= ec_can_receive(1,28, CAN1BUF28RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_p[0]= CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_p[1]= CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_p[2]= CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_p[3]= CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_p[4]= CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_p[5]= CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_p[6]= CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_p[7]= CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
  }

  /* Call the system: <S97>/ReceiveMessages */

  /* Output and update for function-call system: '<S97>/ReceiveMessages' */
  {
    real_T rtb_EMS_EngineSpeed_sat;
    real_T rtb_SRS_PassengerBuckleSwitch_h;
    int32_T rtb_SRS_PassengerBuckleSwitch_d;
    int32_T rtb_SAS_SASFailure_sat;
    int32_T rtb_SRS_DriverBuckleSwitchStatu;

    /* Outputs for Enabled SubSystem: '<S300>/Subsystem' incorporates:
     *  EnablePort: '<S301>/Enable'
     */
    if (VCU_CS75_12_27_test_B.CANReceive_o2_kg > 0) {
      /* Product: '<S302>/EMS_EngineSpeedinput6_P' incorporates:
       *  Constant: '<S302>/EMS_EngineSpeedinput6_C'
       */
      rtb_EMS_EngineSpeed_sat = (real_T)VCU_CS75_12_27_test_B.CANReceive_o4_p[5]
        * 256.0;

      /* Sum: '<S302>/EMS_EngineSpeedinput6_Ad' */
      rtb_SRS_PassengerBuckleSwitch_h = rtb_EMS_EngineSpeed_sat + (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_p[6];

      /* DataTypeConversion: '<S302>/EMS_EngineSpeed_Convert' */
      rtb_SRS_PassengerBuckleSwitch_d = (int32_T)rtb_SRS_PassengerBuckleSwitch_h;

      /* DataTypeConversion: '<S302>/EMS_EngineSpeedcv' */
      rtb_SRS_PassengerBuckleSwitch_h = rtb_SRS_PassengerBuckleSwitch_d;

      /* Gain: '<S302>/EMS_EngineSpeed_F' */
      rtb_SRS_PassengerBuckleSwitch_h *= 0.25;

      /* Sum: '<S302>/EMS_EngineSpeed_Ad' */
      rtb_EMS_EngineSpeed_sat = rtb_SRS_PassengerBuckleSwitch_h;

      /* Saturate: '<S302>/EMS_EngineSpeed_sat' */
      if (rtb_EMS_EngineSpeed_sat > 16383.5) {
        rtb_EMS_EngineSpeed_sat = 16383.5;
      }

      /* End of Saturate: '<S302>/EMS_EngineSpeed_sat' */

      /* DataTypeConversion: '<S302>/SAS_SASFailure_Convert' */
      rtb_SRS_PassengerBuckleSwitch_d = VCU_CS75_12_27_test_B.CANReceive_o4_p[4];

      /* S-Function (sfix_bitop): '<S302>/SAS_SASFailure_L' */
      rtb_SRS_PassengerBuckleSwitch_d &= 16U;

      /* ArithShift: '<S302>/SAS_SASFailure_S' */
      rtb_SRS_PassengerBuckleSwitch_d = (int32_T)((uint32_T)
        rtb_SRS_PassengerBuckleSwitch_d >> 4);

      /* DataTypeConversion: '<S302>/SAS_SASFailurecv' */
      rtb_SRS_PassengerBuckleSwitch_h = rtb_SRS_PassengerBuckleSwitch_d;

      /* Sum: '<S302>/SAS_SASFailure_Ad' */
      rtb_SAS_SASFailure_sat = (int32_T)rtb_SRS_PassengerBuckleSwitch_h;

      /* Saturate: '<S302>/SAS_SASFailure_sat' */
      rtb_SRS_PassengerBuckleSwitch_h = rtb_SAS_SASFailure_sat;
      rtb_SAS_SASFailure_sat = (int32_T)rtb_SRS_PassengerBuckleSwitch_h;

      /* DataTypeConversion: '<S302>/SRS_DriverBuckleSwitchStatus_Convert' */
      rtb_SRS_PassengerBuckleSwitch_d = VCU_CS75_12_27_test_B.CANReceive_o4_p[3];

      /* S-Function (sfix_bitop): '<S302>/SRS_DriverBuckleSwitchStatus_L' */
      rtb_SRS_PassengerBuckleSwitch_d &= 192U;

      /* ArithShift: '<S302>/SRS_DriverBuckleSwitchStatus_S' */
      rtb_SRS_PassengerBuckleSwitch_d = (int32_T)((uint32_T)
        rtb_SRS_PassengerBuckleSwitch_d >> 6);

      /* DataTypeConversion: '<S302>/SRS_DriverBuckleSwitchStatuscv' */
      rtb_SRS_PassengerBuckleSwitch_h = rtb_SRS_PassengerBuckleSwitch_d;

      /* Sum: '<S302>/SRS_DriverBuckleSwitchStatus_Ad' */
      rtb_SRS_DriverBuckleSwitchStatu = (int32_T)rtb_SRS_PassengerBuckleSwitch_h;

      /* Saturate: '<S302>/SRS_DriverBuckleSwitchStatus_sat' */
      rtb_SRS_PassengerBuckleSwitch_h = rtb_SRS_DriverBuckleSwitchStatu;
      rtb_SRS_DriverBuckleSwitchStatu = (int32_T)rtb_SRS_PassengerBuckleSwitch_h;

      /* DataTypeConversion: '<S302>/SRS_PassengerBuckleSwitchStatus_Convert' */
      rtb_SRS_PassengerBuckleSwitch_d = VCU_CS75_12_27_test_B.CANReceive_o4_p[3];

      /* S-Function (sfix_bitop): '<S302>/SRS_PassengerBuckleSwitchStatus_L' */
      rtb_SRS_PassengerBuckleSwitch_d &= 48U;

      /* ArithShift: '<S302>/SRS_PassengerBuckleSwitchStatus_S' */
      rtb_SRS_PassengerBuckleSwitch_d = (int32_T)((uint32_T)
        rtb_SRS_PassengerBuckleSwitch_d >> 4);

      /* DataTypeConversion: '<S302>/SRS_PassengerBuckleSwitchStatuscv' */
      rtb_SRS_PassengerBuckleSwitch_h = rtb_SRS_PassengerBuckleSwitch_d;

      /* SignalConversion: '<S301>/Signal Conversion' */
      VCU_CS75_12_27_test_B.SRS_PassengerBuckleSwitchStatus =
        rtb_SRS_PassengerBuckleSwitch_h;

      /* SignalConversion: '<S301>/Signal Conversion' */
      VCU_CS75_12_27_test_B.SRS_DriverBuckleSwitchStatus_a =
        rtb_SRS_DriverBuckleSwitchStatu;

      /* SignalConversion: '<S301>/Signal Conversion' */
      VCU_CS75_12_27_test_B.SAS_SASFailure_f = rtb_SAS_SASFailure_sat;

      /* SignalConversion: '<S301>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_EngineSpeed = rtb_EMS_EngineSpeed_sat;
    }

    /* End of Outputs for SubSystem: '<S300>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S98>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF30RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf30looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_a1= 886;
    VCU_CS75_12_27_test_B.CANReceive_o5_f= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_jb= ec_can_receive(1,30, CAN1BUF30RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_ef[0]= CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ef[1]= CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ef[2]= CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ef[3]= CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ef[4]= CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ef[5]= CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ef[6]= CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ef[7]= CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
  }

  /* Call the system: <S98>/ReceiveMessages */

  /* Output and update for function-call system: '<S98>/ReceiveMessages' */
  {
    int32_T rtb_EMS_TorqueConstant_L;
    real_T rtb_EMS_FrictionalTorq_sat;
    int32_T rtb_EMS_ConditionIdle_sat;
    int32_T rtb_EMS_EngineFuelCutOff_sat;
    real_T rtb_EMS_TorqueConstant_F;

    /* Outputs for Enabled SubSystem: '<S307>/Subsystem' incorporates:
     *  EnablePort: '<S308>/Enable'
     */
    if (VCU_CS75_12_27_test_B.CANReceive_o2_jb > 0) {
      /* DataTypeConversion: '<S309>/EMS_ConditionIdle_Convert' */
      rtb_EMS_TorqueConstant_L = VCU_CS75_12_27_test_B.CANReceive_o4_ef[3];

      /* S-Function (sfix_bitop): '<S309>/EMS_ConditionIdle_L' */
      rtb_EMS_TorqueConstant_L &= 128U;

      /* ArithShift: '<S309>/EMS_ConditionIdle_S' */
      rtb_EMS_TorqueConstant_L = (int32_T)((uint32_T)rtb_EMS_TorqueConstant_L >>
        7);

      /* DataTypeConversion: '<S309>/EMS_ConditionIdlecv' */
      rtb_EMS_FrictionalTorq_sat = rtb_EMS_TorqueConstant_L;

      /* Sum: '<S309>/EMS_ConditionIdle_Ad' */
      rtb_EMS_ConditionIdle_sat = (int32_T)rtb_EMS_FrictionalTorq_sat;

      /* Saturate: '<S309>/EMS_ConditionIdle_sat' */
      rtb_EMS_FrictionalTorq_sat = rtb_EMS_ConditionIdle_sat;
      rtb_EMS_ConditionIdle_sat = (int32_T)rtb_EMS_FrictionalTorq_sat;

      /* DataTypeConversion: '<S309>/EMS_EngineFuelCutOff_Convert' */
      rtb_EMS_TorqueConstant_L = VCU_CS75_12_27_test_B.CANReceive_o4_ef[3];

      /* S-Function (sfix_bitop): '<S309>/EMS_EngineFuelCutOff_L' */
      rtb_EMS_TorqueConstant_L &= 16U;

      /* ArithShift: '<S309>/EMS_EngineFuelCutOff_S' */
      rtb_EMS_TorqueConstant_L = (int32_T)((uint32_T)rtb_EMS_TorqueConstant_L >>
        4);

      /* DataTypeConversion: '<S309>/EMS_EngineFuelCutOffcv' */
      rtb_EMS_FrictionalTorq_sat = rtb_EMS_TorqueConstant_L;

      /* Sum: '<S309>/EMS_EngineFuelCutOff_Ad' */
      rtb_EMS_EngineFuelCutOff_sat = (int32_T)rtb_EMS_FrictionalTorq_sat;

      /* Saturate: '<S309>/EMS_EngineFuelCutOff_sat' */
      rtb_EMS_FrictionalTorq_sat = rtb_EMS_EngineFuelCutOff_sat;
      rtb_EMS_EngineFuelCutOff_sat = (int32_T)rtb_EMS_FrictionalTorq_sat;

      /* Product: '<S309>/EMS_FrictionalTorqinput2_P' incorporates:
       *  Constant: '<S309>/EMS_FrictionalTorqinput2_C'
       */
      rtb_EMS_FrictionalTorq_sat = (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_ef[1] * 256.0;

      /* Sum: '<S309>/EMS_FrictionalTorqinput2_Ad' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_FrictionalTorq_sat + (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_ef[2];

      /* DataTypeConversion: '<S309>/EMS_FrictionalTorq_Convert' */
      rtb_EMS_TorqueConstant_L = (int32_T)rtb_EMS_TorqueConstant_F;

      /* DataTypeConversion: '<S309>/EMS_FrictionalTorqcv' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_TorqueConstant_L;

      /* Gain: '<S309>/EMS_FrictionalTorq_F' */
      rtb_EMS_TorqueConstant_F *= 0.001526;

      /* Sum: '<S309>/EMS_FrictionalTorq_Ad' */
      rtb_EMS_FrictionalTorq_sat = rtb_EMS_TorqueConstant_F;

      /* DataTypeConversion: '<S309>/EMS_TorqueConstant_Convert' */
      rtb_EMS_TorqueConstant_L = VCU_CS75_12_27_test_B.CANReceive_o4_ef[0];

      /* DataTypeConversion: '<S309>/EMS_TorqueConstantcv' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_TorqueConstant_L;

      /* Gain: '<S309>/EMS_TorqueConstant_F' */
      rtb_EMS_TorqueConstant_F *= 10.0;

      /* Saturate: '<S309>/EMS_TorqueConstant_sat' */
      if (rtb_EMS_TorqueConstant_F > 2540.0) {
        rtb_EMS_TorqueConstant_F = 2540.0;
      }

      /* End of Saturate: '<S309>/EMS_TorqueConstant_sat' */

      /* SignalConversion: '<S308>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_TorqueConstant_i = rtb_EMS_TorqueConstant_F;

      /* SignalConversion: '<S308>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_FrictionalTorq = rtb_EMS_FrictionalTorq_sat;

      /* SignalConversion: '<S308>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_EngineFuelCutOff = rtb_EMS_EngineFuelCutOff_sat;

      /* SignalConversion: '<S308>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_ConditionIdle = rtb_EMS_ConditionIdle_sat;
    }

    /* End of Outputs for SubSystem: '<S307>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S99>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF31RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf31looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_eu= 930;
    VCU_CS75_12_27_test_B.CANReceive_o5_pi= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_mhq= ec_can_receive(1,31, CAN1BUF31RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_it[0]= CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_it[1]= CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_it[2]= CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_it[3]= CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_it[4]= CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_it[5]= CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_it[6]= CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_it[7]= CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
  }

  /* Call the system: <S99>/ReceiveMessages */

  /* Output and update for function-call system: '<S99>/ReceiveMessages' */
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

    /* Outputs for Enabled SubSystem: '<S314>/Subsystem' incorporates:
     *  EnablePort: '<S315>/Enable'
     */
    if (VCU_CS75_12_27_test_B.CANReceive_o2_mhq > 0) {
      /* DataTypeConversion: '<S316>/ACC_ACCMode_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_B.CANReceive_o4_it[1];

      /* S-Function (sfix_bitop): '<S316>/ACC_ACCMode_L' */
      rtb_TCU_WNTLamp_L &= 7U;

      /* Sum: '<S316>/ACC_ACCMode_Ad' */
      rtb_ACC_ACCMode_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S316>/ACC_ACCMode_sat' */
      u0 = rtb_ACC_ACCMode_sat;
      rtb_ACC_ACCMode_sat = (int32_T)u0;

      /* DataTypeConversion: '<S316>/EMS_RemindGear_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_B.CANReceive_o4_it[0];

      /* S-Function (sfix_bitop): '<S316>/EMS_RemindGear_L' */
      rtb_TCU_WNTLamp_L &= 112U;

      /* ArithShift: '<S316>/EMS_RemindGear_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 4);

      /* Sum: '<S316>/EMS_RemindGear_Ad' */
      rtb_EMS_RemindGear_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S316>/EMS_RemindGear_sat' */
      u0 = rtb_EMS_RemindGear_sat;
      rtb_EMS_RemindGear_sat = (int32_T)u0;

      /* DataTypeConversion: '<S316>/EMS_RemindShiftGear_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_B.CANReceive_o4_it[7];

      /* S-Function (sfix_bitop): '<S316>/EMS_RemindShiftGear_L' */
      rtb_TCU_WNTLamp_L &= 192U;

      /* ArithShift: '<S316>/EMS_RemindShiftGear_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 6);

      /* Sum: '<S316>/EMS_RemindShiftGear_Ad' */
      rtb_EMS_RemindShiftGear_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S316>/EMS_RemindShiftGear_sat' */
      u0 = rtb_EMS_RemindShiftGear_sat;
      rtb_EMS_RemindShiftGear_sat = (int32_T)u0;

      /* DataTypeConversion: '<S316>/EPB_FunctionLamp_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_B.CANReceive_o4_it[4];

      /* S-Function (sfix_bitop): '<S316>/EPB_FunctionLamp_L' */
      rtb_TCU_WNTLamp_L &= 24U;

      /* ArithShift: '<S316>/EPB_FunctionLamp_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 3);

      /* Sum: '<S316>/EPB_FunctionLamp_Ad' */
      rtb_EPB_FunctionLamp_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S316>/EPB_FunctionLamp_sat' */
      u0 = rtb_EPB_FunctionLamp_sat;
      rtb_EPB_FunctionLamp_sat = (int32_T)u0;

      /* DataTypeConversion: '<S316>/EPB_SwitchPositionValid_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_B.CANReceive_o4_it[4];

      /* S-Function (sfix_bitop): '<S316>/EPB_SwitchPositionValid_L' */
      rtb_TCU_WNTLamp_L &= 128U;

      /* ArithShift: '<S316>/EPB_SwitchPositionValid_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 7);

      /* Sum: '<S316>/EPB_SwitchPositionValid_Ad' */
      rtb_EPB_SwitchPositionValid_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S316>/EPB_SwitchPositionValid_sat' */
      u0 = rtb_EPB_SwitchPositionValid_sat;
      rtb_EPB_SwitchPositionValid_sat = (int32_T)u0;

      /* DataTypeConversion: '<S316>/EPB_SwitchPosition_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_B.CANReceive_o4_it[4];

      /* S-Function (sfix_bitop): '<S316>/EPB_SwitchPosition_L' */
      rtb_TCU_WNTLamp_L &= 96U;

      /* ArithShift: '<S316>/EPB_SwitchPosition_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 5);

      /* Sum: '<S316>/EPB_SwitchPosition_Ad' */
      rtb_EPB_SwitchPosition_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S316>/EPB_SwitchPosition_sat' */
      u0 = rtb_EPB_SwitchPosition_sat;
      rtb_EPB_SwitchPosition_sat = (int32_T)u0;

      /* DataTypeConversion: '<S316>/EPB_TextDisplay_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_B.CANReceive_o4_it[3];

      /* S-Function (sfix_bitop): '<S316>/EPB_TextDisplay_L' */
      rtb_TCU_WNTLamp_L &= 15U;

      /* Sum: '<S316>/EPB_TextDisplay_Ad' */
      rtb_EPB_TextDisplay_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S316>/EPB_TextDisplay_sat' */
      u0 = rtb_EPB_TextDisplay_sat;
      rtb_EPB_TextDisplay_sat = (int32_T)u0;

      /* DataTypeConversion: '<S316>/EPS_EPSFailed_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_B.CANReceive_o4_it[4];

      /* S-Function (sfix_bitop): '<S316>/EPS_EPSFailed_L' */
      rtb_TCU_WNTLamp_L &= 2U;

      /* ArithShift: '<S316>/EPS_EPSFailed_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 1);

      /* Sum: '<S316>/EPS_EPSFailed_Ad' */
      rtb_EPS_EPSFailed_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S316>/EPS_EPSFailed_sat' */
      u0 = rtb_EPS_EPSFailed_sat;
      rtb_EPS_EPSFailed_sat = (int32_T)u0;

      /* DataTypeConversion: '<S316>/EPS_TorqueAssistMode_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_B.CANReceive_o4_it[0];

      /* S-Function (sfix_bitop): '<S316>/EPS_TorqueAssistMode_L' */
      rtb_TCU_WNTLamp_L &= 3U;

      /* Sum: '<S316>/EPS_TorqueAssistMode_Ad' */
      rtb_EPS_TorqueAssistMode_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S316>/EPS_TorqueAssistMode_sat' */
      u0 = rtb_EPS_TorqueAssistMode_sat;
      rtb_EPS_TorqueAssistMode_sat = (int32_T)u0;

      /* DataTypeConversion: '<S316>/ESP_AutoHoldActive_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_B.CANReceive_o4_it[6];

      /* S-Function (sfix_bitop): '<S316>/ESP_AutoHoldActive_L' */
      rtb_TCU_WNTLamp_L &= 4U;

      /* ArithShift: '<S316>/ESP_AutoHoldActive_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 2);

      /* Sum: '<S316>/ESP_AutoHoldActive_Ad' */
      rtb_ESP_AutoHoldActive_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S316>/ESP_AutoHoldActive_sat' */
      u0 = rtb_ESP_AutoHoldActive_sat;
      rtb_ESP_AutoHoldActive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S316>/ESP_AutoHoldAvailable_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_B.CANReceive_o4_it[6];

      /* S-Function (sfix_bitop): '<S316>/ESP_AutoHoldAvailable_L' */
      rtb_TCU_WNTLamp_L &= 1U;

      /* Sum: '<S316>/ESP_AutoHoldAvailable_Ad' */
      rtb_ESP_AutoHoldAvailable_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S316>/ESP_AutoHoldAvailable_sat' */
      u0 = rtb_ESP_AutoHoldAvailable_sat;
      rtb_ESP_AutoHoldAvailable_sat = (int32_T)u0;

      /* DataTypeConversion: '<S316>/ESP_EBDFailStatus_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_B.CANReceive_o4_it[3];

      /* S-Function (sfix_bitop): '<S316>/ESP_EBDFailStatus_L' */
      rtb_TCU_WNTLamp_L &= 128U;

      /* ArithShift: '<S316>/ESP_EBDFailStatus_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 7);

      /* Sum: '<S316>/ESP_EBDFailStatus_Ad' */
      rtb_ESP_EBDFailStatus_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S316>/ESP_EBDFailStatus_sat' */
      u0 = rtb_ESP_EBDFailStatus_sat;
      rtb_ESP_EBDFailStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S316>/ESP_ESPActiveStatus_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_B.CANReceive_o4_it[3];

      /* S-Function (sfix_bitop): '<S316>/ESP_ESPActiveStatus_L' */
      rtb_TCU_WNTLamp_L &= 32U;

      /* ArithShift: '<S316>/ESP_ESPActiveStatus_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 5);

      /* Sum: '<S316>/ESP_ESPActiveStatus_Ad' */
      rtb_ESP_ESPActiveStatus_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S316>/ESP_ESPActiveStatus_sat' */
      u0 = rtb_ESP_ESPActiveStatus_sat;
      rtb_ESP_ESPActiveStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S316>/ESP_ESPFunctionStatus_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_B.CANReceive_o4_it[3];

      /* S-Function (sfix_bitop): '<S316>/ESP_ESPFunctionStatus_L' */
      rtb_TCU_WNTLamp_L &= 64U;

      /* ArithShift: '<S316>/ESP_ESPFunctionStatus_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 6);

      /* Sum: '<S316>/ESP_ESPFunctionStatus_Ad' */
      rtb_ESP_ESPFunctionStatus_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S316>/ESP_ESPFunctionStatus_sat' */
      u0 = rtb_ESP_ESPFunctionStatus_sat;
      rtb_ESP_ESPFunctionStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S316>/ESP_HBBFunctionStatus_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_B.CANReceive_o4_it[7];

      /* S-Function (sfix_bitop): '<S316>/ESP_HBBFunctionStatus_L' */
      rtb_TCU_WNTLamp_L &= 6U;

      /* ArithShift: '<S316>/ESP_HBBFunctionStatus_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 1);

      /* Sum: '<S316>/ESP_HBBFunctionStatus_Ad' */
      rtb_ESP_HBBFunctionStatus_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S316>/ESP_HBBFunctionStatus_sat' */
      u0 = rtb_ESP_HBBFunctionStatus_sat;
      rtb_ESP_HBBFunctionStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S316>/ESP_HDC_STATUS_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_B.CANReceive_o4_it[5];

      /* S-Function (sfix_bitop): '<S316>/ESP_HDC_STATUS_L' */
      rtb_TCU_WNTLamp_L &= 3U;

      /* Sum: '<S316>/ESP_HDC_STATUS_Ad' */
      rtb_ESP_HDC_STATUS_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S316>/ESP_HDC_STATUS_sat' */
      u0 = rtb_ESP_HDC_STATUS_sat;
      rtb_ESP_HDC_STATUS_sat = (int32_T)u0;

      /* DataTypeConversion: '<S316>/ESP_HHC_Active_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_B.CANReceive_o4_it[6];

      /* S-Function (sfix_bitop): '<S316>/ESP_HHC_Active_L' */
      rtb_TCU_WNTLamp_L &= 2U;

      /* ArithShift: '<S316>/ESP_HHC_Active_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 1);

      /* Sum: '<S316>/ESP_HHC_Active_Ad' */
      rtb_ESP_HHC_Active_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S316>/ESP_HHC_Active_sat' */
      u0 = rtb_ESP_HHC_Active_sat;
      rtb_ESP_HHC_Active_sat = (int32_T)u0;

      /* DataTypeConversion: '<S316>/ESP_HHC_Available_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_B.CANReceive_o4_it[6];

      /* S-Function (sfix_bitop): '<S316>/ESP_HHC_Available_L' */
      rtb_TCU_WNTLamp_L &= 8U;

      /* ArithShift: '<S316>/ESP_HHC_Available_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 3);

      /* Sum: '<S316>/ESP_HHC_Available_Ad' */
      rtb_ESP_HHC_Available_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S316>/ESP_HHC_Available_sat' */
      u0 = rtb_ESP_HHC_Available_sat;
      rtb_ESP_HHC_Available_sat = (int32_T)u0;

      /* DataTypeConversion: '<S316>/SRS_LeftRearBuckleSwitchSts_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_B.CANReceive_o4_it[2];

      /* S-Function (sfix_bitop): '<S316>/SRS_LeftRearBuckleSwitchSts_L' */
      rtb_TCU_WNTLamp_L &= 12U;

      /* ArithShift: '<S316>/SRS_LeftRearBuckleSwitchSts_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 2);

      /* Sum: '<S316>/SRS_LeftRearBuckleSwitchSts_Ad' */
      rtb_SRS_LeftRearBuckleSwitchSts = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S316>/SRS_LeftRearBuckleSwitchSts_sat' */
      u0 = rtb_SRS_LeftRearBuckleSwitchSts;
      rtb_SRS_LeftRearBuckleSwitchSts = (int32_T)u0;

      /* DataTypeConversion: '<S316>/SRS_MiddleRearBuckleSwitchSts_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_B.CANReceive_o4_it[2];

      /* S-Function (sfix_bitop): '<S316>/SRS_MiddleRearBuckleSwitchSts_L' */
      rtb_TCU_WNTLamp_L &= 48U;

      /* ArithShift: '<S316>/SRS_MiddleRearBuckleSwitchSts_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 4);

      /* Sum: '<S316>/SRS_MiddleRearBuckleSwitchSts_Ad' */
      rtb_SRS_MiddleRearBuckleSwitchS = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S316>/SRS_MiddleRearBuckleSwitchSts_sat' */
      u0 = rtb_SRS_MiddleRearBuckleSwitchS;
      rtb_SRS_MiddleRearBuckleSwitchS = (int32_T)u0;

      /* DataTypeConversion: '<S316>/SRS_RightRearBuckleSwitchSts_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_B.CANReceive_o4_it[2];

      /* S-Function (sfix_bitop): '<S316>/SRS_RightRearBuckleSwitchSts_L' */
      rtb_TCU_WNTLamp_L &= 192U;

      /* ArithShift: '<S316>/SRS_RightRearBuckleSwitchSts_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 6);

      /* Sum: '<S316>/SRS_RightRearBuckleSwitchSts_Ad' */
      rtb_SRS_RightRearBuckleSwitchSt = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S316>/SRS_RightRearBuckleSwitchSts_sat' */
      u0 = rtb_SRS_RightRearBuckleSwitchSt;
      rtb_SRS_RightRearBuckleSwitchSt = (int32_T)u0;

      /* DataTypeConversion: '<S316>/TCU_FailureLamp_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_B.CANReceive_o4_it[0];

      /* S-Function (sfix_bitop): '<S316>/TCU_FailureLamp_L' */
      rtb_TCU_WNTLamp_L &= 128U;

      /* ArithShift: '<S316>/TCU_FailureLamp_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 7);

      /* Sum: '<S316>/TCU_FailureLamp_Ad' */
      rtb_TCU_FailureLamp_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S316>/TCU_FailureLamp_sat' */
      u0 = rtb_TCU_FailureLamp_sat;
      rtb_TCU_FailureLamp_sat = (int32_T)u0;

      /* DataTypeConversion: '<S316>/TCU_GearForDisplay_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_B.CANReceive_o4_it[6];

      /* S-Function (sfix_bitop): '<S316>/TCU_GearForDisplay_L' */
      rtb_TCU_WNTLamp_L &= 240U;

      /* ArithShift: '<S316>/TCU_GearForDisplay_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 4);

      /* Sum: '<S316>/TCU_GearForDisplay_Ad' */
      rtb_TCU_GearForDisplay_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S316>/TCU_GearForDisplay_sat' */
      u0 = rtb_TCU_GearForDisplay_sat;
      rtb_TCU_GearForDisplay_sat = (int32_T)u0;

      /* DataTypeConversion: '<S316>/TCU_GearIndication_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_B.CANReceive_o4_it[7];

      /* S-Function (sfix_bitop): '<S316>/TCU_GearIndication_L' */
      rtb_TCU_WNTLamp_L &= 8U;

      /* ArithShift: '<S316>/TCU_GearIndication_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 3);

      /* Sum: '<S316>/TCU_GearIndication_Ad' */
      rtb_TCU_GearIndication_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S316>/TCU_GearIndication_sat' */
      u0 = rtb_TCU_GearIndication_sat;
      rtb_TCU_GearIndication_sat = (int32_T)u0;

      /* DataTypeConversion: '<S316>/TCU_PWRLamp_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_B.CANReceive_o4_it[1];

      /* S-Function (sfix_bitop): '<S316>/TCU_PWRLamp_L' */
      rtb_TCU_WNTLamp_L &= 64U;

      /* ArithShift: '<S316>/TCU_PWRLamp_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 6);

      /* Sum: '<S316>/TCU_PWRLamp_Ad' */
      rtb_TCU_PWRLamp_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S316>/TCU_PWRLamp_sat' */
      u0 = rtb_TCU_PWRLamp_sat;
      rtb_TCU_PWRLamp_sat = (int32_T)u0;

      /* DataTypeConversion: '<S316>/TCU_ReqTranTempWarning_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_B.CANReceive_o4_it[7];

      /* S-Function (sfix_bitop): '<S316>/TCU_ReqTranTempWarning_L' */
      rtb_TCU_WNTLamp_L &= 48U;

      /* ArithShift: '<S316>/TCU_ReqTranTempWarning_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 4);

      /* Sum: '<S316>/TCU_ReqTranTempWarning_Ad' */
      rtb_TCU_ReqTranTempWarning_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S316>/TCU_ReqTranTempWarning_sat' */
      u0 = rtb_TCU_ReqTranTempWarning_sat;
      rtb_TCU_ReqTranTempWarning_sat = (int32_T)u0;

      /* DataTypeConversion: '<S316>/TCU_WNTLamp_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_12_27_test_B.CANReceive_o4_it[1];

      /* S-Function (sfix_bitop): '<S316>/TCU_WNTLamp_L' */
      rtb_TCU_WNTLamp_L &= 32U;

      /* ArithShift: '<S316>/TCU_WNTLamp_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 5);

      /* Saturate: '<S316>/TCU_WNTLamp_sat' */
      u0 = rtb_TCU_WNTLamp_L;
      rtb_TCU_WNTLamp_L = (int32_T)u0;

      /* SignalConversion: '<S315>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPS_TorqueAssistMode = rtb_EPS_TorqueAssistMode_sat;

      /* SignalConversion: '<S315>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPB_TextDisplay = rtb_EPB_TextDisplay_sat;

      /* SignalConversion: '<S315>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_ESPActiveStatus = rtb_ESP_ESPActiveStatus_sat;

      /* SignalConversion: '<S315>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_ESPFunctionStatus =
        rtb_ESP_ESPFunctionStatus_sat;

      /* SignalConversion: '<S315>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_EBDFailStatus = rtb_ESP_EBDFailStatus_sat;

      /* SignalConversion: '<S315>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPS_EPSFailed = rtb_EPS_EPSFailed_sat;

      /* SignalConversion: '<S315>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPB_FunctionLamp = rtb_EPB_FunctionLamp_sat;

      /* SignalConversion: '<S315>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPB_SwitchPosition = rtb_EPB_SwitchPosition_sat;

      /* SignalConversion: '<S315>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EPB_SwitchPositionValid =
        rtb_EPB_SwitchPositionValid_sat;

      /* SignalConversion: '<S315>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_HDC_STATUS = rtb_ESP_HDC_STATUS_sat;

      /* SignalConversion: '<S315>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_AutoHoldAvailable =
        rtb_ESP_AutoHoldAvailable_sat;

      /* SignalConversion: '<S315>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_RemindGear = rtb_EMS_RemindGear_sat;

      /* SignalConversion: '<S315>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_HHC_Active = rtb_ESP_HHC_Active_sat;

      /* SignalConversion: '<S315>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_AutoHoldActive = rtb_ESP_AutoHoldActive_sat;

      /* SignalConversion: '<S315>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_HHC_Available = rtb_ESP_HHC_Available_sat;

      /* SignalConversion: '<S315>/Signal Conversion' */
      VCU_CS75_12_27_test_B.TCU_GearForDisplay = rtb_TCU_GearForDisplay_sat;

      /* SignalConversion: '<S315>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ESP_HBBFunctionStatus =
        rtb_ESP_HBBFunctionStatus_sat;

      /* SignalConversion: '<S315>/Signal Conversion' */
      VCU_CS75_12_27_test_B.TCU_GearIndication = rtb_TCU_GearIndication_sat;

      /* SignalConversion: '<S315>/Signal Conversion' */
      VCU_CS75_12_27_test_B.TCU_ReqTranTempWarning =
        rtb_TCU_ReqTranTempWarning_sat;

      /* SignalConversion: '<S315>/Signal Conversion' */
      VCU_CS75_12_27_test_B.EMS_RemindShiftGear = rtb_EMS_RemindShiftGear_sat;

      /* SignalConversion: '<S315>/Signal Conversion' */
      VCU_CS75_12_27_test_B.TCU_FailureLamp = rtb_TCU_FailureLamp_sat;

      /* SignalConversion: '<S315>/Signal Conversion' */
      VCU_CS75_12_27_test_B.ACC_ACCMode = rtb_ACC_ACCMode_sat;

      /* SignalConversion: '<S315>/Signal Conversion' */
      VCU_CS75_12_27_test_B.TCU_WNTLamp = rtb_TCU_WNTLamp_L;

      /* SignalConversion: '<S315>/Signal Conversion' */
      VCU_CS75_12_27_test_B.TCU_PWRLamp = rtb_TCU_PWRLamp_sat;

      /* SignalConversion: '<S315>/Signal Conversion' */
      VCU_CS75_12_27_test_B.SRS_LeftRearBuckleSwitchSts =
        rtb_SRS_LeftRearBuckleSwitchSts;

      /* SignalConversion: '<S315>/Signal Conversion' */
      VCU_CS75_12_27_test_B.SRS_MiddleRearBuckleSwitchSts =
        rtb_SRS_MiddleRearBuckleSwitchS;

      /* SignalConversion: '<S315>/Signal Conversion' */
      VCU_CS75_12_27_test_B.SRS_RightRearBuckleSwitchSts =
        rtb_SRS_RightRearBuckleSwitchSt;
    }

    /* End of Outputs for SubSystem: '<S314>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S100>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF32RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf32looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_a3= 1383;
    VCU_CS75_12_27_test_B.CANReceive_o5_hn= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_nj= ec_can_receive(1,32, CAN1BUF32RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_ao[0]= CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ao[1]= CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ao[2]= CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ao[3]= CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ao[4]= CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ao[5]= CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ao[6]= CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ao[7]= CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
  }

  /* Call the system: <S100>/ReceiveMessages */

  /* Output and update for function-call system: '<S100>/ReceiveMessages' */
  {
    int32_T rtb_HU_TunnelLength_L;
    int32_T rtb_HU_Byroad_sat;
    int32_T rtb_HU_EnterTunnelInfo_sat;
    int32_T rtb_HU_NavGuiganceStatus_sat;
    int32_T rtb_HU_TunnelDistance_sat;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S344>/Subsystem' incorporates:
     *  EnablePort: '<S345>/Enable'
     */
    if (VCU_CS75_12_27_test_B.CANReceive_o2_nj > 0) {
      /* DataTypeConversion: '<S346>/HU_Byroad_Convert' */
      rtb_HU_TunnelLength_L = VCU_CS75_12_27_test_B.CANReceive_o4_ao[4];

      /* S-Function (sfix_bitop): '<S346>/HU_Byroad_L' */
      rtb_HU_TunnelLength_L &= 192U;

      /* ArithShift: '<S346>/HU_Byroad_S' */
      rtb_HU_TunnelLength_L = (int32_T)((uint32_T)rtb_HU_TunnelLength_L >> 6);

      /* Sum: '<S346>/HU_Byroad_Ad' */
      rtb_HU_Byroad_sat = rtb_HU_TunnelLength_L;

      /* Saturate: '<S346>/HU_Byroad_sat' */
      u0 = rtb_HU_Byroad_sat;
      rtb_HU_Byroad_sat = (int32_T)u0;

      /* DataTypeConversion: '<S346>/HU_EnterTunnelInfo_Convert' */
      rtb_HU_TunnelLength_L = VCU_CS75_12_27_test_B.CANReceive_o4_ao[0];

      /* S-Function (sfix_bitop): '<S346>/HU_EnterTunnelInfo_L' */
      rtb_HU_TunnelLength_L &= 12U;

      /* ArithShift: '<S346>/HU_EnterTunnelInfo_S' */
      rtb_HU_TunnelLength_L = (int32_T)((uint32_T)rtb_HU_TunnelLength_L >> 2);

      /* Sum: '<S346>/HU_EnterTunnelInfo_Ad' */
      rtb_HU_EnterTunnelInfo_sat = rtb_HU_TunnelLength_L;

      /* Saturate: '<S346>/HU_EnterTunnelInfo_sat' */
      u0 = rtb_HU_EnterTunnelInfo_sat;
      rtb_HU_EnterTunnelInfo_sat = (int32_T)u0;

      /* DataTypeConversion: '<S346>/HU_NavGuiganceStatus_Convert' */
      rtb_HU_TunnelLength_L = VCU_CS75_12_27_test_B.CANReceive_o4_ao[5];

      /* S-Function (sfix_bitop): '<S346>/HU_NavGuiganceStatus_L' */
      rtb_HU_TunnelLength_L &= 192U;

      /* ArithShift: '<S346>/HU_NavGuiganceStatus_S' */
      rtb_HU_TunnelLength_L = (int32_T)((uint32_T)rtb_HU_TunnelLength_L >> 6);

      /* Sum: '<S346>/HU_NavGuiganceStatus_Ad' */
      rtb_HU_NavGuiganceStatus_sat = rtb_HU_TunnelLength_L;

      /* Saturate: '<S346>/HU_NavGuiganceStatus_sat' */
      u0 = rtb_HU_NavGuiganceStatus_sat;
      rtb_HU_NavGuiganceStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S346>/HU_TunnelDistance_Convert' */
      rtb_HU_TunnelLength_L = VCU_CS75_12_27_test_B.CANReceive_o4_ao[2];

      /* S-Function (sfix_bitop): '<S346>/HU_TunnelDistance_L' */
      rtb_HU_TunnelLength_L &= 252U;

      /* ArithShift: '<S346>/HU_TunnelDistance_S' */
      rtb_HU_TunnelLength_L = (int32_T)((uint32_T)rtb_HU_TunnelLength_L >> 2);

      /* Gain: '<S346>/HU_TunnelDistance_F' */
      rtb_HU_TunnelLength_L *= 10;

      /* Sum: '<S346>/HU_TunnelDistance_Ad' */
      rtb_HU_TunnelDistance_sat = rtb_HU_TunnelLength_L;

      /* Saturate: '<S346>/HU_TunnelDistance_sat' */
      u0 = rtb_HU_TunnelDistance_sat;
      if (u0 > 600.0) {
        u0 = 600.0;
      }

      rtb_HU_TunnelDistance_sat = (int32_T)u0;

      /* End of Saturate: '<S346>/HU_TunnelDistance_sat' */

      /* DataTypeConversion: '<S346>/HU_TunnelLength_Convert' */
      rtb_HU_TunnelLength_L = VCU_CS75_12_27_test_B.CANReceive_o4_ao[4];

      /* S-Function (sfix_bitop): '<S346>/HU_TunnelLength_L' */
      rtb_HU_TunnelLength_L &= 63U;

      /* Saturate: '<S346>/HU_TunnelLength_sat' */
      u0 = rtb_HU_TunnelLength_L;
      rtb_HU_TunnelLength_L = (int32_T)u0;

      /* SignalConversion: '<S345>/Signal Conversion' */
      VCU_CS75_12_27_test_B.HU_EnterTunnelInfo = rtb_HU_EnterTunnelInfo_sat;

      /* SignalConversion: '<S345>/Signal Conversion' */
      VCU_CS75_12_27_test_B.HU_TunnelDistance = rtb_HU_TunnelDistance_sat;

      /* SignalConversion: '<S345>/Signal Conversion' */
      VCU_CS75_12_27_test_B.HU_TunnelLength = rtb_HU_TunnelLength_L;

      /* SignalConversion: '<S345>/Signal Conversion' */
      VCU_CS75_12_27_test_B.HU_Byroad = rtb_HU_Byroad_sat;

      /* SignalConversion: '<S345>/Signal Conversion' */
      VCU_CS75_12_27_test_B.HU_NavGuiganceStatus = rtb_HU_NavGuiganceStatus_sat;
    }

    /* End of Outputs for SubSystem: '<S344>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S101>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF33RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf33looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_f= 1280;
    VCU_CS75_12_27_test_B.CANReceive_o5_fx= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_it= ec_can_receive(1,33, CAN1BUF33RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_ff[0]= CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ff[1]= CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ff[2]= CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ff[3]= CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ff[4]= CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ff[5]= CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ff[6]= CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_ff[7]= CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
  }

  /* Call the system: <S101>/ReceiveMessages */

  /* Output and update for function-call system: '<S101>/ReceiveMessages' */

  /* Outputs for Enabled SubSystem: '<S352>/Subsystem' incorporates:
   *  EnablePort: '<S353>/Enable'
   */
  if (VCU_CS75_12_27_test_B.CANReceive_o2_it > 0) {
    /* SignalConversion: '<S353>/Signal Conversion' */
    VCU_CS75_12_27_test_B.GPSCurrentLocationValid = 0.0;
  }

  /* End of Outputs for SubSystem: '<S352>/Subsystem' */

  /* S-Function (ec5744_canreceiveslb): '<S102>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF36RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf36looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_mf= 878;
    VCU_CS75_12_27_test_B.CANReceive_o5_pl= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_jj= ec_can_receive(1,36, CAN1BUF36RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_as[0]= CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_as[1]= CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_as[2]= CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_as[3]= CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_as[4]= CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_as[5]= CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_as[6]= CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_as[7]= CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
  }

  /* Call the system: <S102>/ReceiveMessages */

  /* Output and update for function-call system: '<S102>/ReceiveMessages' */
  {
    uint32_T rtb_LAS_RollingCounter_id36E_L;
    int32_T rtb_LAS_LaneEquationStatus_sat;
    int32_T rtb_LAS_CheckSum_id36E_sat;
    real_T rtb_LAS_LaneEquationC1_sat;
    real_T rtb_LAS_LaneEquationC3_sat;
    real_T rtb_LAS_RoadCurvatureFar_sat;
    real_T rtb_LAS_RollingCounter_id36Ecv;
    real_T rtb_LAS_RoadCurvatureNear_sat;

    /* Outputs for Enabled SubSystem: '<S356>/Subsystem' incorporates:
     *  EnablePort: '<S357>/Enable'
     */
    if (VCU_CS75_12_27_test_B.CANReceive_o2_jj > 0) {
      /* DataTypeConversion: '<S358>/LAS_CheckSum_id36E_Convert' */
      rtb_LAS_RollingCounter_id36E_L = VCU_CS75_12_27_test_B.CANReceive_o4_as[7];

      /* DataTypeConversion: '<S358>/LAS_CheckSum_id36Ecv' */
      rtb_LAS_LaneEquationStatus_sat = (int32_T)rtb_LAS_RollingCounter_id36E_L;

      /* Sum: '<S358>/LAS_CheckSum_id36E_Ad' */
      rtb_LAS_CheckSum_id36E_sat = rtb_LAS_LaneEquationStatus_sat;

      /* Saturate: '<S358>/LAS_CheckSum_id36E_sat' */
      rtb_LAS_RoadCurvatureFar_sat = rtb_LAS_CheckSum_id36E_sat;
      rtb_LAS_CheckSum_id36E_sat = (int32_T)rtb_LAS_RoadCurvatureFar_sat;

      /* Product: '<S358>/LAS_LaneEquationC1input3_P' incorporates:
       *  Constant: '<S358>/LAS_LaneEquationC1input3_C'
       */
      rtb_LAS_LaneEquationStatus_sat = VCU_CS75_12_27_test_B.CANReceive_o4_as[2]
        << 8;

      /* Product: '<S358>/LAS_LaneEquationC1input2_P' incorporates:
       *  Constant: '<S358>/LAS_LaneEquationC1input2_C'
       */
      rtb_LAS_LaneEquationC1_sat = (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_as[1] * 65536.0;

      /* Sum: '<S358>/LAS_LaneEquationC1input2_Ad' */
      rtb_LAS_LaneEquationC3_sat = rtb_LAS_LaneEquationC1_sat + (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_as[3];

      /* Sum: '<S358>/LAS_LaneEquationC1input3_Ad' */
      rtb_LAS_LaneEquationStatus_sat += (int32_T)rtb_LAS_LaneEquationC3_sat;

      /* DataTypeConversion: '<S358>/LAS_LaneEquationC1_Convert' */
      rtb_LAS_RollingCounter_id36E_L = (uint32_T)rtb_LAS_LaneEquationStatus_sat;

      /* S-Function (sfix_bitop): '<S358>/LAS_LaneEquationC1_L' */
      rtb_LAS_RollingCounter_id36E_L &= 262080U;

      /* ArithShift: '<S358>/LAS_LaneEquationC1_S' */
      rtb_LAS_RollingCounter_id36E_L >>= 6;

      /* DataTypeConversion: '<S358>/LAS_LaneEquationC1cv' */
      rtb_LAS_LaneEquationC3_sat = rtb_LAS_RollingCounter_id36E_L;

      /* Gain: '<S358>/LAS_LaneEquationC1_F' */
      rtb_LAS_LaneEquationC3_sat *= 0.00048828125;

      /* Sum: '<S358>/LAS_LaneEquationC1_Ad' incorporates:
       *  Constant: '<S358>/LAS_LaneEquationC1_O'
       */
      rtb_LAS_LaneEquationC1_sat = rtb_LAS_LaneEquationC3_sat + -1.0;

      /* Saturate: '<S358>/LAS_LaneEquationC1_sat' */
      if (rtb_LAS_LaneEquationC1_sat > 0.9990234375) {
        rtb_LAS_LaneEquationC1_sat = 0.9990234375;
      }

      /* End of Saturate: '<S358>/LAS_LaneEquationC1_sat' */

      /* Product: '<S358>/LAS_LaneEquationC3input6_P' incorporates:
       *  Constant: '<S358>/LAS_LaneEquationC3input6_C'
       */
      rtb_LAS_LaneEquationC3_sat = (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_as[5] * 256.0;

      /* Product: '<S358>/LAS_LaneEquationC3input5_P' incorporates:
       *  Constant: '<S358>/LAS_LaneEquationC3input5_C'
       */
      rtb_LAS_LaneEquationStatus_sat = VCU_CS75_12_27_test_B.CANReceive_o4_as[4]
        * 65536;

      /* Sum: '<S358>/LAS_LaneEquationC3input5_Ad' */
      rtb_LAS_RoadCurvatureFar_sat = rtb_LAS_LaneEquationStatus_sat +
        VCU_CS75_12_27_test_B.CANReceive_o4_as[6];

      /* Sum: '<S358>/LAS_LaneEquationC3input6_Ad' */
      rtb_LAS_LaneEquationC3_sat += rtb_LAS_RoadCurvatureFar_sat;

      /* DataTypeConversion: '<S358>/LAS_LaneEquationC3_Convert' */
      rtb_LAS_RollingCounter_id36E_L = (uint32_T)rtb_LAS_LaneEquationC3_sat;

      /* S-Function (sfix_bitop): '<S358>/LAS_LaneEquationC3_L' */
      rtb_LAS_RollingCounter_id36E_L &= 262080U;

      /* ArithShift: '<S358>/LAS_LaneEquationC3_S' */
      rtb_LAS_RollingCounter_id36E_L >>= 6;

      /* DataTypeConversion: '<S358>/LAS_LaneEquationC3cv' */
      rtb_LAS_RoadCurvatureFar_sat = rtb_LAS_RollingCounter_id36E_L;

      /* Gain: '<S358>/LAS_LaneEquationC3_F' */
      rtb_LAS_RoadCurvatureFar_sat *= 4.76837158203125;

      /* Sum: '<S358>/LAS_LaneEquationC3_Ad' incorporates:
       *  Constant: '<S358>/LAS_LaneEquationC3_O'
       */
      rtb_LAS_LaneEquationC3_sat = rtb_LAS_RoadCurvatureFar_sat +
        -0.00097608566284179688;

      /* Saturate: '<S358>/LAS_LaneEquationC3_sat' */
      if (rtb_LAS_LaneEquationC3_sat > 0.000976085662841796) {
        rtb_LAS_LaneEquationC3_sat = 0.000976085662841796;
      } else {
        if (rtb_LAS_LaneEquationC3_sat < -0.000976085662841796) {
          rtb_LAS_LaneEquationC3_sat = -0.000976085662841796;
        }
      }

      /* End of Saturate: '<S358>/LAS_LaneEquationC3_sat' */

      /* DataTypeConversion: '<S358>/LAS_LaneEquationStatus_Convert' */
      rtb_LAS_RollingCounter_id36E_L = VCU_CS75_12_27_test_B.CANReceive_o4_as[6];

      /* S-Function (sfix_bitop): '<S358>/LAS_LaneEquationStatus_L' */
      rtb_LAS_RollingCounter_id36E_L &= 48U;

      /* ArithShift: '<S358>/LAS_LaneEquationStatus_S' */
      rtb_LAS_RollingCounter_id36E_L >>= 4;

      /* DataTypeConversion: '<S358>/LAS_LaneEquationStatuscv' */
      rtb_LAS_RoadCurvatureFar_sat = rtb_LAS_RollingCounter_id36E_L;

      /* Sum: '<S358>/LAS_LaneEquationStatus_Ad' */
      rtb_LAS_LaneEquationStatus_sat = (int32_T)rtb_LAS_RoadCurvatureFar_sat;

      /* Saturate: '<S358>/LAS_LaneEquationStatus_sat' */
      rtb_LAS_RoadCurvatureFar_sat = rtb_LAS_LaneEquationStatus_sat;
      rtb_LAS_LaneEquationStatus_sat = (int32_T)rtb_LAS_RoadCurvatureFar_sat;

      /* Product: '<S358>/LAS_RoadCurvatureFarinput1_P' incorporates:
       *  Constant: '<S358>/LAS_RoadCurvatureFarinput1_C'
       */
      rtb_LAS_RoadCurvatureFar_sat = (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_as[0] * 256.0;

      /* Sum: '<S358>/LAS_RoadCurvatureFarinput1_Ad' */
      rtb_LAS_RollingCounter_id36Ecv = rtb_LAS_RoadCurvatureFar_sat + (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_as[1];

      /* DataTypeConversion: '<S358>/LAS_RoadCurvatureFar_Convert' */
      rtb_LAS_RollingCounter_id36E_L = (uint32_T)rtb_LAS_RollingCounter_id36Ecv;

      /* S-Function (sfix_bitop): '<S358>/LAS_RoadCurvatureFar_L' */
      rtb_LAS_RollingCounter_id36E_L &= 508U;

      /* ArithShift: '<S358>/LAS_RoadCurvatureFar_S' */
      rtb_LAS_RollingCounter_id36E_L >>= 2;

      /* DataTypeConversion: '<S358>/LAS_RoadCurvatureFarcv' */
      rtb_LAS_RollingCounter_id36Ecv = rtb_LAS_RollingCounter_id36E_L;

      /* Gain: '<S358>/LAS_RoadCurvatureFar_F' */
      rtb_LAS_RollingCounter_id36Ecv *= 0.0005;

      /* Sum: '<S358>/LAS_RoadCurvatureFar_Ad' incorporates:
       *  Constant: '<S358>/LAS_RoadCurvatureFar_O'
       */
      rtb_LAS_RoadCurvatureFar_sat = rtb_LAS_RollingCounter_id36Ecv +
        -0.029999999329447746;

      /* Saturate: '<S358>/LAS_RoadCurvatureFar_sat' */
      if (rtb_LAS_RoadCurvatureFar_sat > 0.03) {
        rtb_LAS_RoadCurvatureFar_sat = 0.03;
      }

      /* End of Saturate: '<S358>/LAS_RoadCurvatureFar_sat' */

      /* DataTypeConversion: '<S358>/LAS_RoadCurvatureNear_Convert' */
      rtb_LAS_RollingCounter_id36E_L = VCU_CS75_12_27_test_B.CANReceive_o4_as[0];

      /* S-Function (sfix_bitop): '<S358>/LAS_RoadCurvatureNear_L' */
      rtb_LAS_RollingCounter_id36E_L &= 254U;

      /* ArithShift: '<S358>/LAS_RoadCurvatureNear_S' */
      rtb_LAS_RollingCounter_id36E_L >>= 1;

      /* DataTypeConversion: '<S358>/LAS_RoadCurvatureNearcv' */
      rtb_LAS_RollingCounter_id36Ecv = rtb_LAS_RollingCounter_id36E_L;

      /* Gain: '<S358>/LAS_RoadCurvatureNear_F' */
      rtb_LAS_RollingCounter_id36Ecv *= 0.0005;

      /* Sum: '<S358>/LAS_RoadCurvatureNear_Ad' incorporates:
       *  Constant: '<S358>/LAS_RoadCurvatureNear_O'
       */
      rtb_LAS_RoadCurvatureNear_sat = rtb_LAS_RollingCounter_id36Ecv +
        -0.029999999329447746;

      /* Saturate: '<S358>/LAS_RoadCurvatureNear_sat' */
      if (rtb_LAS_RoadCurvatureNear_sat > 0.03) {
        rtb_LAS_RoadCurvatureNear_sat = 0.03;
      }

      /* End of Saturate: '<S358>/LAS_RoadCurvatureNear_sat' */

      /* DataTypeConversion: '<S358>/LAS_RollingCounter_id36E_Convert' */
      rtb_LAS_RollingCounter_id36E_L = VCU_CS75_12_27_test_B.CANReceive_o4_as[6];

      /* S-Function (sfix_bitop): '<S358>/LAS_RollingCounter_id36E_L' */
      rtb_LAS_RollingCounter_id36E_L &= 15U;

      /* DataTypeConversion: '<S358>/LAS_RollingCounter_id36Ecv' */
      rtb_LAS_RollingCounter_id36Ecv = rtb_LAS_RollingCounter_id36E_L;

      /* SignalConversion: '<S357>/Signal Conversion' */
      VCU_CS75_12_27_test_B.LAS_RoadCurvatureFar = rtb_LAS_RoadCurvatureFar_sat;

      /* SignalConversion: '<S357>/Signal Conversion' */
      VCU_CS75_12_27_test_B.LAS_RoadCurvatureNear =
        rtb_LAS_RoadCurvatureNear_sat;

      /* SignalConversion: '<S357>/Signal Conversion' */
      VCU_CS75_12_27_test_B.LAS_LaneEquationC1 = rtb_LAS_LaneEquationC1_sat;

      /* SignalConversion: '<S357>/Signal Conversion' */
      VCU_CS75_12_27_test_B.LAS_LaneEquationC3 = rtb_LAS_LaneEquationC3_sat;

      /* SignalConversion: '<S357>/Signal Conversion' */
      VCU_CS75_12_27_test_B.LAS_RollingCounter_id36E =
        rtb_LAS_RollingCounter_id36Ecv;

      /* SignalConversion: '<S357>/Signal Conversion' */
      VCU_CS75_12_27_test_B.LAS_LaneEquationStatus =
        rtb_LAS_LaneEquationStatus_sat;

      /* SignalConversion: '<S357>/Signal Conversion' */
      VCU_CS75_12_27_test_B.LAS_CheckSum_id36E = rtb_LAS_CheckSum_id36E_sat;
    }

    /* End of Outputs for SubSystem: '<S356>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S103>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF19RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf19looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_ov= 264;
    VCU_CS75_12_27_test_B.CANReceive_o5_lw= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_ij= ec_can_receive(1,19, CAN1BUF19RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_gv[0]= CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_gv[1]= CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_gv[2]= CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_gv[3]= CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_gv[4]= CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_gv[5]= CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_gv[6]= CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_gv[7]= CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
  }

  /* Call the system: <S103>/ReceiveMessages */

  /* Output and update for function-call system: '<S103>/ReceiveMessages' */
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

    /* Outputs for Enabled SubSystem: '<S366>/Subsystem' incorporates:
     *  EnablePort: '<S367>/Enable'
     */
    if (VCU_CS75_12_27_test_B.CANReceive_o2_ij > 0) {
      /* Product: '<S368>/SAS_SteeringAngleinput1_P' incorporates:
       *  Constant: '<S368>/SAS_SteeringAngleinput1_C'
       */
      rtb_SAS_SteeringAngle_Ad = (real_T)VCU_CS75_12_27_test_B.CANReceive_o4_gv
        [0] * 256.0;

      /* Sum: '<S368>/SAS_SteeringAngleinput1_Ad' */
      rtb_SAS_SteeringAngle_F = rtb_SAS_SteeringAngle_Ad + (real_T)
        VCU_CS75_12_27_test_B.CANReceive_o4_gv[1];

      /* DataTypeConversion: '<S368>/SAS_SteeringAngle_Convert' */
      rtb_SAS_SteeringAngleValid_L = (int32_T)rtb_SAS_SteeringAngle_F;

      /* DataTypeConversion: '<S368>/SAS_SteeringAnglecv' */
      rtb_SAS_SteeringAnglesubcon = (real32_T)rtb_SAS_SteeringAngleValid_L;

      /* RelationalOperator: '<S368>/SAS_SteeringAngleROP' */
      rtb_SAS_SteeringAngleROP = (rtb_SAS_SteeringAnglesubcon >= 32768.0F);

      /* Switch: '<S368>/SAS_SteeringAngleSW' */
      if (rtb_SAS_SteeringAngleROP) {
        /* Sum: '<S368>/SAS_SteeringAnglesubcon' */
        rtb_SAS_SteeringAnglesubcon = 65536.0F - rtb_SAS_SteeringAnglesubcon;

        /* UnaryMinus: '<S368>/SAS_SteeringAngleMinus' */
        rtb_SAS_SteeringAnglesubcon = -rtb_SAS_SteeringAnglesubcon;
      }

      /* End of Switch: '<S368>/SAS_SteeringAngleSW' */

      /* DataTypeConversion: '<S368>/Data Type Conversion' */
      rtb_SAS_SteeringAngle_F = rtb_SAS_SteeringAnglesubcon;

      /* DataTypeConversion: '<S368>/SAS_CRCCheck_Convert' */
      rtb_SAS_SteeringAngleValid_L = VCU_CS75_12_27_test_B.CANReceive_o4_gv[7];

      /* DataTypeConversion: '<S368>/SAS_CRCCheckcv' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;

      /* Sum: '<S368>/SAS_CRCCheck_Ad' */
      rtb_SAS_CRCCheck_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Saturate: '<S368>/SAS_CRCCheck_sat' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_CRCCheck_sat;
      rtb_SAS_CRCCheck_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* DataTypeConversion: '<S368>/SAS_Calibrated_Convert' */
      rtb_SAS_SteeringAngleValid_L = VCU_CS75_12_27_test_B.CANReceive_o4_gv[3];

      /* S-Function (sfix_bitop): '<S368>/SAS_Calibrated_L' */
      rtb_SAS_SteeringAngleValid_L &= 32U;

      /* ArithShift: '<S368>/SAS_Calibrated_S' */
      rtb_SAS_SteeringAngleValid_L = (int32_T)((uint32_T)
        rtb_SAS_SteeringAngleValid_L >> 5);

      /* DataTypeConversion: '<S368>/SAS_Calibratedcv' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;

      /* Sum: '<S368>/SAS_Calibrated_Ad' */
      rtb_SAS_Calibrated_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Saturate: '<S368>/SAS_Calibrated_sat' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_Calibrated_sat;
      rtb_SAS_Calibrated_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* DataTypeConversion: '<S368>/SAS_RollingCounter_Convert' */
      rtb_SAS_SteeringAngleValid_L = VCU_CS75_12_27_test_B.CANReceive_o4_gv[6];

      /* S-Function (sfix_bitop): '<S368>/SAS_RollingCounter_L' */
      rtb_SAS_SteeringAngleValid_L &= 15U;

      /* DataTypeConversion: '<S368>/SAS_RollingCountercv' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;

      /* Sum: '<S368>/SAS_RollingCounter_Ad' */
      rtb_SAS_RollingCounter_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Saturate: '<S368>/SAS_RollingCounter_sat' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_RollingCounter_sat;
      rtb_SAS_RollingCounter_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* DataTypeConversion: '<S368>/SAS_SASFailure_Convert' */
      rtb_SAS_SteeringAngleValid_L = VCU_CS75_12_27_test_B.CANReceive_o4_gv[3];

      /* S-Function (sfix_bitop): '<S368>/SAS_SASFailure_L' */
      rtb_SAS_SteeringAngleValid_L &= 64U;

      /* ArithShift: '<S368>/SAS_SASFailure_S' */
      rtb_SAS_SteeringAngleValid_L = (int32_T)((uint32_T)
        rtb_SAS_SteeringAngleValid_L >> 6);

      /* DataTypeConversion: '<S368>/SAS_SASFailurecv' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;

      /* Sum: '<S368>/SAS_SASFailure_Ad' */
      rtb_SAS_SASFailure_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Saturate: '<S368>/SAS_SASFailure_sat' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SASFailure_sat;
      rtb_SAS_SASFailure_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* DataTypeConversion: '<S368>/SAS_SteeringAngleSpeed_Convert' */
      rtb_SAS_SteeringAngleValid_L = VCU_CS75_12_27_test_B.CANReceive_o4_gv[2];

      /* DataTypeConversion: '<S368>/SAS_SteeringAngleSpeedcv' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;

      /* Gain: '<S368>/SAS_SteeringAngleSpeed_F' */
      rtb_SAS_SteeringAngle_Ad *= 4.0;

      /* Sum: '<S368>/SAS_SteeringAngleSpeed_Ad' */
      rtb_SAS_SteeringAngleSpeed_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Saturate: '<S368>/SAS_SteeringAngleSpeed_sat' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleSpeed_sat;
      rtb_SAS_SteeringAngleSpeed_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* DataTypeConversion: '<S368>/SAS_SteeringAngleValid_Convert' */
      rtb_SAS_SteeringAngleValid_L = VCU_CS75_12_27_test_B.CANReceive_o4_gv[3];

      /* S-Function (sfix_bitop): '<S368>/SAS_SteeringAngleValid_L' */
      rtb_SAS_SteeringAngleValid_L &= 128U;

      /* ArithShift: '<S368>/SAS_SteeringAngleValid_S' */
      rtb_SAS_SteeringAngleValid_L = (int32_T)((uint32_T)
        rtb_SAS_SteeringAngleValid_L >> 7);

      /* DataTypeConversion: '<S368>/SAS_SteeringAngleValidcv' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;

      /* Sum: '<S368>/SAS_SteeringAngleValid_Ad' */
      rtb_SAS_SteeringAngleValid_L = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Saturate: '<S368>/SAS_SteeringAngleValid_sat' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;
      rtb_SAS_SteeringAngleValid_L = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Gain: '<S368>/SAS_SteeringAngle_F' */
      rtb_SAS_SteeringAngle_F *= 0.1;

      /* Sum: '<S368>/SAS_SteeringAngle_Ad' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngle_F;

      /* Saturate: '<S368>/SAS_SteeringAngle_sat' */
      if (rtb_SAS_SteeringAngle_Ad > 780.0) {
        SAS_SteeringAngle = 780.0;
      } else if (rtb_SAS_SteeringAngle_Ad < -780.0) {
        SAS_SteeringAngle = -780.0;
      } else {
        SAS_SteeringAngle = rtb_SAS_SteeringAngle_Ad;
      }

      /* End of Saturate: '<S368>/SAS_SteeringAngle_sat' */

      /* SignalConversion: '<S367>/Signal Conversion' */
      VCU_CS75_12_27_test_B.SAS_SteeringAngle_k = SAS_SteeringAngle;

      /* SignalConversion: '<S367>/Signal Conversion' */
      VCU_CS75_12_27_test_B.SAS_SteeringAngleSpeed =
        rtb_SAS_SteeringAngleSpeed_sat;

      /* SignalConversion: '<S367>/Signal Conversion' */
      VCU_CS75_12_27_test_B.SAS_Calibrated = rtb_SAS_Calibrated_sat;

      /* SignalConversion: '<S367>/Signal Conversion' */
      VCU_CS75_12_27_test_B.SAS_SASFailure = rtb_SAS_SASFailure_sat;

      /* SignalConversion: '<S367>/Signal Conversion' */
      VCU_CS75_12_27_test_B.SAS_SteeringAngleValid =
        rtb_SAS_SteeringAngleValid_L;

      /* SignalConversion: '<S367>/Signal Conversion' */
      VCU_CS75_12_27_test_B.SAS_RollingCounter = rtb_SAS_RollingCounter_sat;

      /* SignalConversion: '<S367>/Signal Conversion' */
      VCU_CS75_12_27_test_B.SAS_CRCCheck = rtb_SAS_CRCCheck_sat;
    }

    /* End of Outputs for SubSystem: '<S366>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S104>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF20RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf20looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_b= 952;
    VCU_CS75_12_27_test_B.CANReceive_o5_or= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_e2= ec_can_receive(1,20, CAN1BUF20RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_hb[0]= CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_hb[1]= CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_hb[2]= CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_hb[3]= CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_hb[4]= CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_hb[5]= CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_hb[6]= CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_hb[7]= CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
  }

  /* Call the system: <S104>/ReceiveMessages */

  /* Output and update for function-call system: '<S104>/ReceiveMessages' */

  /* Outputs for Enabled SubSystem: '<S376>/Subsystem' incorporates:
   *  EnablePort: '<S377>/Enable'
   */
  if (VCU_CS75_12_27_test_B.CANReceive_o2_e2 > 0) {
    /* SignalConversion: '<S377>/Signal Conversion' */
    VCU_CS75_12_27_test_B.SCM_ACCOn = 0.0;

    /* SignalConversion: '<S377>/Signal Conversion' */
    VCU_CS75_12_27_test_B.SCM_ACCCancel = 0.0;

    /* SignalConversion: '<S377>/Signal Conversion' */
    VCU_CS75_12_27_test_B.SCM_Resume = 0.0;

    /* SignalConversion: '<S377>/Signal Conversion' */
    VCU_CS75_12_27_test_B.SCM_Speeddecrease = 0.0;

    /* SignalConversion: '<S377>/Signal Conversion' */
    VCU_CS75_12_27_test_B.SCM_TimeGap = 0.0;

    /* SignalConversion: '<S377>/Signal Conversion' */
    VCU_CS75_12_27_test_B.SCM_IACCOn = 0.0;
  }

  /* End of Outputs for SubSystem: '<S376>/Subsystem' */

  /* S-Function (ec5744_canreceiveslb): '<S105>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF21RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf21looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_hy= 5;
    VCU_CS75_12_27_test_B.CANReceive_o5_bt= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_pe= ec_can_receive(1,21, CAN1BUF21RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_kv[0]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_kv[1]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_kv[2]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_kv[3]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_kv[4]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_kv[5]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_kv[6]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_kv[7]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
  }

  /* Call the system: <S105>/ReceiveMessages */

  /* Output and update for function-call system: '<S105>/ReceiveMessages' */
  {
    int32_T rtb_SRS_RollingCounter_L;
    int32_T rtb_SRS_DriverBuckleSwitchStatu;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S385>/Subsystem' incorporates:
     *  EnablePort: '<S386>/Enable'
     */
    if (VCU_CS75_12_27_test_B.CANReceive_o2_pe > 0) {
      /* DataTypeConversion: '<S387>/SRS_DriverBuckleSwitchStatus_Convert' */
      rtb_SRS_RollingCounter_L = VCU_CS75_12_27_test_B.CANReceive_o4_kv[1];

      /* S-Function (sfix_bitop): '<S387>/SRS_DriverBuckleSwitchStatus_L' */
      rtb_SRS_RollingCounter_L &= 192U;

      /* ArithShift: '<S387>/SRS_DriverBuckleSwitchStatus_S' */
      rtb_SRS_RollingCounter_L = (int32_T)((uint32_T)rtb_SRS_RollingCounter_L >>
        6);

      /* Sum: '<S387>/SRS_DriverBuckleSwitchStatus_Ad' */
      rtb_SRS_DriverBuckleSwitchStatu = rtb_SRS_RollingCounter_L;

      /* Saturate: '<S387>/SRS_DriverBuckleSwitchStatus_sat' */
      u0 = rtb_SRS_DriverBuckleSwitchStatu;
      rtb_SRS_DriverBuckleSwitchStatu = (int32_T)u0;

      /* DataTypeConversion: '<S387>/SRS_RollingCounter_Convert' */
      rtb_SRS_RollingCounter_L = VCU_CS75_12_27_test_B.CANReceive_o4_kv[3];

      /* S-Function (sfix_bitop): '<S387>/SRS_RollingCounter_L' */
      rtb_SRS_RollingCounter_L &= 15U;

      /* Saturate: '<S387>/SRS_RollingCounter_sat' */
      u0 = rtb_SRS_RollingCounter_L;
      rtb_SRS_RollingCounter_L = (int32_T)u0;

      /* SignalConversion: '<S386>/Signal Conversion' */
      VCU_CS75_12_27_test_B.SRS_DriverBuckleSwitchStatus =
        rtb_SRS_DriverBuckleSwitchStatu;

      /* SignalConversion: '<S386>/Signal Conversion' */
      VCU_CS75_12_27_test_B.SRS_RollingCounter = rtb_SRS_RollingCounter_L;
    }

    /* End of Outputs for SubSystem: '<S385>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S106>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF22RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf22looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_i4= 646;
    VCU_CS75_12_27_test_B.CANReceive_o5_px= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_bp= ec_can_receive(1,22, CAN1BUF22RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_m[0]= CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_m[1]= CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_m[2]= CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_m[3]= CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_m[4]= CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_m[5]= CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_m[6]= CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_m[7]= CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
  }

  /* Call the system: <S106>/ReceiveMessages */

  /* Output and update for function-call system: '<S106>/ReceiveMessages' */
  {
    int32_T rtb_TCU_GearShiftPosition_L;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S390>/Subsystem' incorporates:
     *  EnablePort: '<S391>/Enable'
     */
    if (VCU_CS75_12_27_test_B.CANReceive_o2_bp > 0) {
      /* DataTypeConversion: '<S392>/TCU_ActualGear_Convert' */
      rtb_TCU_GearShiftPosition_L = VCU_CS75_12_27_test_B.CANReceive_o4_m[1];

      /* S-Function (sfix_bitop): '<S392>/TCU_ActualGear_L' */
      rtb_TCU_GearShiftPosition_L &= 15U;

      /* Saturate: '<S392>/TCU_ActualGear_sat' */
      u0 = rtb_TCU_GearShiftPosition_L;
      rtb_TCU_GearShiftPosition_L = (int32_T)u0;

      /* SignalConversion: '<S391>/Signal Conversion' */
      VCU_CS75_12_27_test_B.TCU_ActualGear = rtb_TCU_GearShiftPosition_L;

      /* DataTypeConversion: '<S392>/TCU_ShiftPositionValid_Convert' */
      rtb_TCU_GearShiftPosition_L = VCU_CS75_12_27_test_B.CANReceive_o4_m[1];

      /* S-Function (sfix_bitop): '<S392>/TCU_ShiftPositionValid_L' */
      rtb_TCU_GearShiftPosition_L &= 16U;

      /* ArithShift: '<S392>/TCU_ShiftPositionValid_S' */
      rtb_TCU_GearShiftPosition_L = (int32_T)((uint32_T)
        rtb_TCU_GearShiftPosition_L >> 4);

      /* Saturate: '<S392>/TCU_ShiftPositionValid_sat' */
      u0 = rtb_TCU_GearShiftPosition_L;
      rtb_TCU_GearShiftPosition_L = (int32_T)u0;

      /* SignalConversion: '<S391>/Signal Conversion' */
      VCU_CS75_12_27_test_B.TCU_ShiftPositionValid = rtb_TCU_GearShiftPosition_L;

      /* DataTypeConversion: '<S392>/TCU_ActualGearValid_Convert' */
      rtb_TCU_GearShiftPosition_L = VCU_CS75_12_27_test_B.CANReceive_o4_m[1];

      /* S-Function (sfix_bitop): '<S392>/TCU_ActualGearValid_L' */
      rtb_TCU_GearShiftPosition_L &= 32U;

      /* ArithShift: '<S392>/TCU_ActualGearValid_S' */
      rtb_TCU_GearShiftPosition_L = (int32_T)((uint32_T)
        rtb_TCU_GearShiftPosition_L >> 5);

      /* Saturate: '<S392>/TCU_ActualGearValid_sat' */
      u0 = rtb_TCU_GearShiftPosition_L;
      rtb_TCU_GearShiftPosition_L = (int32_T)u0;

      /* SignalConversion: '<S391>/Signal Conversion' */
      VCU_CS75_12_27_test_B.TCU_ActualGearValid = rtb_TCU_GearShiftPosition_L;

      /* DataTypeConversion: '<S392>/TCU_GearShiftPosition_Convert' */
      rtb_TCU_GearShiftPosition_L = VCU_CS75_12_27_test_B.CANReceive_o4_m[2];

      /* S-Function (sfix_bitop): '<S392>/TCU_GearShiftPosition_L' */
      rtb_TCU_GearShiftPosition_L &= 240U;

      /* ArithShift: '<S392>/TCU_GearShiftPosition_S' */
      rtb_TCU_GearShiftPosition_L = (int32_T)((uint32_T)
        rtb_TCU_GearShiftPosition_L >> 4);

      /* Saturate: '<S392>/TCU_GearShiftPosition_sat' */
      u0 = rtb_TCU_GearShiftPosition_L;
      rtb_TCU_GearShiftPosition_L = (int32_T)u0;

      /* SignalConversion: '<S391>/Signal Conversion' */
      VCU_CS75_12_27_test_B.TCU_GearShiftPosition = rtb_TCU_GearShiftPosition_L;
    }

    /* End of Outputs for SubSystem: '<S390>/Subsystem' */
  }

  /* End of Outputs for SubSystem: '<S2>/Input' */

  /* Outputs for Atomic SubSystem: '<S2>/APP' */
  /* Inport: '<S24>/APP_Input' */
  rtb_APP_Input_idx_0 = VCU_CS75_12_27_test_B.AutoDrivingReady;
  rtb_APP_Input_idx_1 = VCU_CS75_12_27_test_B.RemoteAcclPosition;
  rtb_APP_Input_idx_2 = VCU_CS75_12_27_test_B.LaterlAngleCommand;
  rtb_APP_Input_idx_3 = VCU_CS75_12_27_test_B.A1_Message_Counter;
  rtb_APP_Input_idx_8 = VCU_CS75_12_27_test_B.EMS_FrictionalTorq_d;
  rtb_APP_Input_idx_9 = VCU_CS75_12_27_test_B.EMS_IndicatedRealEngTorq;
  rtb_APP_Input_idx_12 = VCU_CS75_12_27_test_B.EMS_BrakePedalStatus_l;
  rtb_APP_Input_idx_17 = VCU_CS75_12_27_test_B.EMS_RollingCounter_id255;
  rtb_APP_Input_idx_19 = VCU_CS75_12_27_test_B.EMS_FullLoadIndicatedTorq;
  rtb_APP_Input_idx_20 = VCU_CS75_12_27_test_B.EMS_TorqueConstant_c;
  rtb_APP_Input_idx_29 = VCU_CS75_12_27_test_B.EPS_EPSFailed_k;
  rtb_APP_Input_idx_39 = VCU_CS75_12_27_test_B.EPS_AvailabilityStatus_a;
  rtb_APP_Input_idx_63 = VCU_CS75_12_27_test_B.Wheel_Speed_RR;
  rtb_APP_Input_idx_66 = VCU_CS75_12_27_test_B.Wheel_Speed_RL;
  rtb_APP_Input_idx_79 = VCU_CS75_12_27_test_B.ESP_ESPFailStatus;
  rtb_APP_Input_idx_99 = VCU_CS75_12_27_test_B.SAS_SteeringAngle_k;
  rtb_APP_Input_idx_217 = P6_Value;

  /* MATLAB Function: '<S54>/MATLAB Function2' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Monitor/Vehicle_Status/MATLAB Function2': '<S57>:1' */
  if ((rtb_APP_Input_idx_29 == 1.0) || (rtb_APP_Input_idx_79 == 1.0)) {
    /* '<S57>:1:2' */
    /* '<S57>:1:3' */
    VehicleFaultStatus = 1.0;
  } else {
    /* '<S57>:1:5' */
    VehicleFaultStatus = 0.0;
  }

  /* End of MATLAB Function: '<S54>/MATLAB Function2' */

  /* Memory: '<S54>/Memory3' */
  rtb_P6_Value = VCU_CS75_12_27_test_DW.Memory3_PreviousInput;

  /* Memory: '<S54>/Memory2' */
  rtb_Memory2 = VCU_CS75_12_27_test_DW.Memory2_PreviousInput;

  /* MATLAB Function: '<S54>/MATLAB Function4' incorporates:
   *  Constant: '<S54>/1s'
   */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Monitor/Vehicle_Status/MATLAB Function4': '<S58>:1' */
  if (rtb_APP_Input_idx_17 == rtb_P6_Value) {
    /* '<S58>:1:2' */
    /* '<S58>:1:3' */
    rtb_P6_Value = rtb_Memory2 + 1.0;
  } else {
    /* '<S58>:1:5' */
    rtb_P6_Value = 0.0;
  }

  if (rtb_P6_Value * 20.0 > 1000.0) {
    /* '<S58>:1:7' */
    /* '<S58>:1:8' */
    VehicleCommunicationStatus = 0.0;
  } else {
    /* '<S58>:1:10' */
    VehicleCommunicationStatus = 1.0;
  }

  counter1 = rtb_P6_Value;

  /* End of MATLAB Function: '<S54>/MATLAB Function4' */

  /* DataTypeConversion: '<S54>/Data Type Conversion' */
  EPS_AvailabilityStatus = rtb_APP_Input_idx_39;

  /* Constant: '<S52>/Constant' */
  Server_CommunicationStatus = 1.0;

  /* Chart: '<S29>/Chart' */
  /* Gateway: 长安CS75底盘程序，20ms一次/APP/System_State_Manager/Chart */
  /* During: 长安CS75底盘程序，20ms一次/APP/System_State_Manager/Chart */
  if (VCU_CS75_12_27_test_DW.bitsForTID4.is_active_c4_VCU_CS75_12_27_tes == 0U)
  {
    /* Entry: 长安CS75底盘程序，20ms一次/APP/System_State_Manager/Chart */
    VCU_CS75_12_27_test_DW.bitsForTID4.is_active_c4_VCU_CS75_12_27_tes = 1U;

    /* Entry Internal: 长安CS75底盘程序，20ms一次/APP/System_State_Manager/Chart */
    VCU_CS75_12_27_test_DW.bitsForTID4.is_c4_VCU_CS75_12_27_test =
      VCU_CS75_12_27__IN_System_State;

    /* Entry Internal 'System_State': '<S59>:16' */
    /* Transition: '<S59>:11' */
    VCU_CS75_12_27_test_DW.bitsForTID4.is_System_State =
      VCU_CS75__IN_INIT_ManualDriving;

    /* Entry 'INIT_ManualDriving': '<S59>:7' */
    /* 驾驶员正常驾驶 */
    System_State = 0.0;
  } else {
    /* During 'System_State': '<S59>:16' */
    switch (VCU_CS75_12_27_test_DW.bitsForTID4.is_System_State) {
     case VCU_CS75_12_27_t_IN_AutoDriving:
      /* During 'AutoDriving': '<S59>:8' */
      rtb_ErrorROP = ((VehicleFaultStatus == 1.0) || (VehicleCommunicationStatus
        == 0.0) || (Server_CommunicationStatus == 0.0));
      if (rtb_ErrorROP) {
        /* Transition: '<S59>:27' */
        VCU_CS75_12_27_test_DW.bitsForTID4.is_System_State =
          VCU_CS75_12_27_test_IN_Error;

        /* Entry 'Error': '<S59>:10' */
        /* 故障，需人工接管 */
        System_State = 3.0;
      } else if (rtb_APP_Input_idx_12 == 1.0) {
        /* Transition: '<S59>:28' */
        VCU_CS75_12_27_test_DW.bitsForTID4.is_System_State =
          VCU_CS75_12_27_test_IN_TakeOver;

        /* Entry 'TakeOver': '<S59>:9' */
        /* 人工接管模式 */
        System_State = 2.0;
      } else if (rtb_APP_Input_idx_0 == 0.0) {
        /* Transition: '<S59>:31' */
        /* %&&Switch_P6 == 0 */
        VCU_CS75_12_27_test_DW.bitsForTID4.is_System_State =
          VCU_CS75__IN_INIT_ManualDriving;

        /* Entry 'INIT_ManualDriving': '<S59>:7' */
        /* 驾驶员正常驾驶 */
        System_State = 0.0;
      } else {
        System_State = 1.0;
      }
      break;

     case VCU_CS75_12_27_test_IN_Error:
      /* During 'Error': '<S59>:10' */
      rtb_ErrorROP = ((rtb_APP_Input_idx_0 == 0.0) && (rtb_APP_Input_idx_217 ==
        0.0) && (VehicleCommunicationStatus == 1.0) && (VehicleFaultStatus ==
        0.0));
      if (rtb_ErrorROP) {
        /* Transition: '<S59>:35' */
        /* %&& Server_CommunicationStatus == 1 */
        VCU_CS75_12_27_test_DW.bitsForTID4.is_System_State =
          VCU_CS75__IN_INIT_ManualDriving;

        /* Entry 'INIT_ManualDriving': '<S59>:7' */
        /* 驾驶员正常驾驶 */
        System_State = 0.0;
      } else {
        System_State = 3.0;
      }
      break;

     case VCU_CS75__IN_INIT_ManualDriving:
      /* During 'INIT_ManualDriving': '<S59>:7' */
      rtb_ErrorROP = ((rtb_APP_Input_idx_0 == 1.0) &&
                      (Server_CommunicationStatus == 1.0) &&
                      (rtb_APP_Input_idx_12 == 0.0) &&
                      (VehicleCommunicationStatus == 1.0) && (VehicleFaultStatus
        == 0.0));
      if (rtb_ErrorROP) {
        /* Transition: '<S59>:18' */
        /* % &&Switch_P6 == 1&&EPS_AvailabilityStatus == 2 */
        VCU_CS75_12_27_test_DW.bitsForTID4.is_System_State =
          VCU_CS75_12_27_t_IN_AutoDriving;

        /* Entry 'AutoDriving': '<S59>:8' */
        /* 自动驾驶 */
        System_State = 1.0;
      } else {
        System_State = 0.0;
      }
      break;

     default:
      /* During 'TakeOver': '<S59>:9' */
      rtb_ErrorROP = ((rtb_APP_Input_idx_0 == 0.0) && (rtb_APP_Input_idx_217 ==
        0.0));
      if (rtb_ErrorROP) {
        /* Transition: '<S59>:32' */
        VCU_CS75_12_27_test_DW.bitsForTID4.is_System_State =
          VCU_CS75__IN_INIT_ManualDriving;

        /* Entry 'INIT_ManualDriving': '<S59>:7' */
        /* 驾驶员正常驾驶 */
        System_State = 0.0;
      } else {
        rtb_ErrorROP = ((VehicleFaultStatus == 1.0) ||
                        (VehicleCommunicationStatus == 0.0) ||
                        (Server_CommunicationStatus == 0.0));
        if (rtb_ErrorROP) {
          /* Transition: '<S59>:39' */
          VCU_CS75_12_27_test_DW.bitsForTID4.is_System_State =
            VCU_CS75_12_27_test_IN_Error;

          /* Entry 'Error': '<S59>:10' */
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
    &VCU_CS75_12_27_test_B.sf_MATLABFunction2_d);

  /* End of Outputs for SubSystem: '<S27>/Accesories' */

  /* Outputs for Atomic SubSystem: '<S27>/Lateral' */
  /* Lookup_n-D: '<S32>/1-D Lookup Table' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Accesories/MATLAB Function1': '<S35>:1' */
  mubiao_zhuanjiao = look1_binlx(rtb_APP_Input_idx_2,
    VCU_CS75_12_27_test_ConstP.DLookupTable_bp01Data,
    VCU_CS75_12_27_test_ConstP.pooled2, 1U);

  /* Memory: '<S32>/Memory3' */
  rtb_Memory1_e = VCU_CS75_12_27_test_DW.Memory3_PreviousInput_j;

  /* DataTypeConversion: '<S32>/Data Type Conversion4' */
  rtb_Memory2 = rtb_Memory1_e;

  /* Memory: '<S32>/Memory1' */
  rtb_Memory1_e = VCU_CS75_12_27_test_DW.Memory1_PreviousInput_b;

  /* DataTypeConversion: '<S32>/Data Type Conversion3' */
  rtb_P6_Value = rtb_Memory1_e;

  /* MATLAB Function: '<S32>/MATLAB Function' incorporates:
   *  Constant: '<S32>/ECCalVar'
   *  Constant: '<S32>/ECCalVar1'
   *  Constant: '<S32>/ECCalVar10'
   *  Constant: '<S32>/ECCalVar11'
   *  Constant: '<S32>/ECCalVar2'
   *  Constant: '<S32>/ECCalVar3'
   *  Constant: '<S32>/ECCalVar4'
   *  Constant: '<S32>/ECCalVar5'
   *  Constant: '<S32>/ECCalVar6'
   *  Constant: '<S32>/ECCalVar7'
   *  Constant: '<S32>/ECCalVar8'
   *  Constant: '<S32>/ECCalVar9'
   */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Lateral/MATLAB Function': '<S38>:1' */
  /* '<S38>:1:3' */
  rtb_APP_Input_idx_79 = mubiao_zhuanjiao - rtb_APP_Input_idx_99;

  /* %%目标转角-当前转角，角度 */
  if (fabs(rtb_APP_Input_idx_79) < 20.0) {
    /* '<S38>:1:4' */
    /* '<S38>:1:5' */
    rtb_APP_Input_idx_0 = P1;

    /* '<S38>:1:6' */
    rtb_APP_Input_idx_39 = I1;

    /* '<S38>:1:7' */
    rtb_APP_Input_idx_2 = D1;

    /* '<S38>:1:8' */
    rtb_APP_Input_idx_12 = ErrorSumMax1;
  } else if (fabs(rtb_APP_Input_idx_79) < 100.0) {
    /* '<S38>:1:9' */
    /* '<S38>:1:10' */
    rtb_APP_Input_idx_0 = P2;

    /* '<S38>:1:11' */
    rtb_APP_Input_idx_39 = I2;

    /* '<S38>:1:12' */
    rtb_APP_Input_idx_2 = D2;

    /* '<S38>:1:13' */
    rtb_APP_Input_idx_12 = ErrorSumMax2;
  } else {
    /* '<S38>:1:15' */
    rtb_APP_Input_idx_0 = P3;

    /* '<S38>:1:16' */
    rtb_APP_Input_idx_39 = I3;

    /* '<S38>:1:17' */
    rtb_APP_Input_idx_2 = D3;

    /* '<S38>:1:18' */
    rtb_APP_Input_idx_12 = ErrorSumMax3;
  }

  if (rtb_APP_Input_idx_217 == 1.0) {
    /* '<S38>:1:21' */
    /* '<S38>:1:22' */
    rtb_P6_Value += rtb_APP_Input_idx_79;

    /* %累积误差  */
  } else {
    /* '<S38>:1:24' */
    rtb_P6_Value = 0.0;
  }

  /* %%积分清零； */
  if (rtb_P6_Value > rtb_APP_Input_idx_12) {
    /* '<S38>:1:28' */
    /* '<S38>:1:29' */
    rtb_P6_Value = rtb_APP_Input_idx_12;
  } else {
    if (rtb_P6_Value < -rtb_APP_Input_idx_12) {
      /* '<S38>:1:30' */
      /* '<S38>:1:31' */
      rtb_P6_Value = -rtb_APP_Input_idx_12;
    }
  }

  /* %%积分限幅 */
  /* '<S38>:1:35' */
  /* %%位置式PID计算 */
  if (rtb_APP_Input_idx_217 == 1.0) {
    /* '<S38>:1:38' */
    /* '<S38>:1:39' */
    PID_SteeringOut = (rtb_APP_Input_idx_0 * rtb_APP_Input_idx_79 +
                       rtb_APP_Input_idx_39 * rtb_P6_Value) +
      (rtb_APP_Input_idx_79 - rtb_Memory2) * rtb_APP_Input_idx_2;
  } else {
    /* '<S38>:1:41' */
    PID_SteeringOut = 0.0;
  }

  /* %%实际的转矩输出 */
  Error = rtb_APP_Input_idx_79;
  ErrorSum = rtb_P6_Value;

  /* End of MATLAB Function: '<S32>/MATLAB Function' */

  /* DataTypeConversion: '<S32>/Data Type Conversion1' */
  rtb_Memory1_e = (real32_T)ErrorSum;

  /* DataTypeConversion: '<S32>/Data Type Conversion2' */
  rtb_Error = (real32_T)Error;

  /* Memory: '<S32>/Memory4' */
  rtb_P6_Value = VCU_CS75_12_27_test_DW.Memory4_PreviousInput;

  /* MATLAB Function: '<S32>/MATLAB Function1' incorporates:
   *  Constant: '<S32>/Constant7'
   */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Lateral/MATLAB Function1': '<S39>:1' */
  if (PID_SteeringOut - rtb_P6_Value > 20.0) {
    /* '<S39>:1:2' */
    /* '<S39>:1:3' */
    rtb_Memory2 = rtb_P6_Value + 20.0;
  } else if (PID_SteeringOut - rtb_P6_Value < -20.0) {
    /* '<S39>:1:5' */
    /* '<S39>:1:6' */
    rtb_Memory2 = rtb_P6_Value - 20.0;
  } else {
    /* '<S39>:1:8' */
    rtb_Memory2 = PID_SteeringOut;
  }

  /* End of MATLAB Function: '<S32>/MATLAB Function1' */

  /* Gain: '<S32>/Gain1' */
  rtb_APP_Input_idx_2 = 0.01 * rtb_Memory2;

  /* Memory: '<S32>/Memory2' */
  rtb_P6_Value = VCU_CS75_12_27_test_DW.Memory2_PreviousInput_l;

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
    rtb_APP_Input_idx_12 = rtb_APP_Input_idx_2;
  } else {
    rtb_APP_Input_idx_12 = 0.0;
  }

  /* End of Switch: '<S32>/Switch' */

  /* MATLAB Function: '<S32>/MATLAB Function4' incorporates:
   *  Constant: '<S32>/Constant6'
   */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Lateral/MATLAB Function4': '<S42>:1' */
  if (rtb_APP_Input_idx_12 > 3.0) {
    /* '<S42>:1:2' */
    /* '<S42>:1:3' */
    rtb_APP_Input_idx_12 = 3.0;
  } else if (rtb_APP_Input_idx_12 < -3.0) {
    /* '<S42>:1:4' */
    /* '<S42>:1:5' */
    rtb_APP_Input_idx_12 = -3.0;
  } else {
    /* '<S42>:1:7' */
  }

  /* End of MATLAB Function: '<S32>/MATLAB Function4' */

  /* MATLAB Function: '<S32>/MATLAB Function7' */
  VCU_CS75_12_MATLABFunction2(System_State,
    &VCU_CS75_12_27_test_B.sf_MATLABFunction7);

  /* Update for Memory: '<S32>/Memory3' */
  VCU_CS75_12_27_test_DW.Memory3_PreviousInput_j = rtb_Error;

  /* Update for Memory: '<S32>/Memory1' */
  VCU_CS75_12_27_test_DW.Memory1_PreviousInput_b = rtb_Memory1_e;

  /* Update for Memory: '<S32>/Memory4' */
  VCU_CS75_12_27_test_DW.Memory4_PreviousInput = rtb_Memory2;

  /* Update for Memory: '<S32>/Memory2' */
  VCU_CS75_12_27_test_DW.Memory2_PreviousInput_l = LAS_RollingCounter;

  /* End of Outputs for SubSystem: '<S27>/Lateral' */

  /* Outputs for Atomic SubSystem: '<S27>/Longitudinal' */
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

  /* MATLAB Function: '<S33>/MATLAB Function7' */
  VCU_CS75_12_MATLABFunction2(System_State,
    &VCU_CS75_12_27_test_B.sf_MATLABFunction7_g);

  /* MATLAB Function: '<S33>/MATLAB Function2' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Longitudinal/MATLAB Function2': '<S46>:1' */
  if ((rtb_APP_Input_idx_1 <= 0.0) &&
      (VCU_CS75_12_27_test_B.sf_MATLABFunction7_g.y == 1.0)) {
    /* '<S46>:1:2' */
    /* '<S46>:1:3' */
    ACC_ACCTargetAcceleration = rtb_APP_Input_idx_1;
  } else {
    /* '<S46>:1:5' */
    ACC_ACCTargetAcceleration = 0.0;
  }

  /* End of MATLAB Function: '<S33>/MATLAB Function2' */

  /* Memory: '<S33>/Memory1' */
  rtb_P6_Value = VCU_CS75_12_27_test_DW.Memory1_PreviousInput_p;

  /* MATLAB Function: '<S33>/MATLAB Function3' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Longitudinal/MATLAB Function3': '<S47>:1' */
  if (rtb_P6_Value == 15.0) {
    /* '<S47>:1:2' */
    /* '<S47>:1:3' */
    rtb_P6_Value = 0.0;
  } else {
    /* '<S47>:1:5' */
  }

  if (VCU_CS75_12_27_test_B.sf_MATLABFunction7_g.y == 1.0) {
    /* '<S47>:1:8' */
    /* '<S47>:1:9' */
    ACC_RollingCounter_id2E4 = rtb_P6_Value + 1.0;
  } else {
    /* '<S47>:1:11' */
    ACC_RollingCounter_id2E4 = rtb_P6_Value;
  }

  /* End of MATLAB Function: '<S33>/MATLAB Function3' */

  /* Memory: '<S33>/Memory2' */
  rtb_P6_Value = VCU_CS75_12_27_test_DW.Memory2_PreviousInput_b;

  /* MATLAB Function: '<S33>/MATLAB Function4' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Longitudinal/MATLAB Function4': '<S48>:1' */
  if (rtb_P6_Value == 15.0) {
    /* '<S48>:1:2' */
    /* '<S48>:1:3' */
    rtb_P6_Value = 0.0;
  } else {
    /* '<S48>:1:5' */
  }

  if (VCU_CS75_12_27_test_B.sf_MATLABFunction7_g.y == 1.0) {
    /* '<S48>:1:8' */
    /* '<S48>:1:9' */
    ACC_RollingCounter_id2E5 = rtb_P6_Value + 1.0;
  } else {
    /* '<S48>:1:11' */
    ACC_RollingCounter_id2E5 = rtb_P6_Value;
  }

  /* End of MATLAB Function: '<S33>/MATLAB Function4' */

  /* MATLAB Function: '<S33>/MATLAB Function5' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Controller/Longitudinal/MATLAB Function5': '<S49>:1' */
  if ((rtb_APP_Input_idx_1 >= 0.0) &&
      (VCU_CS75_12_27_test_B.sf_MATLABFunction7_g.y == 1.0)) {
    /* '<S49>:1:2' */
    /* '<S49>:1:3' */
    ACC_AccTorqueReq = rtb_APP_Input_idx_1;
  } else {
    /* '<S49>:1:5' */
    ACC_AccTorqueReq = 0.0;
  }

  /* End of MATLAB Function: '<S33>/MATLAB Function5' */

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
  rtb_APP_Input_idx_0 = ACC_ACCTargetAcceleration;
  if (rtb_APP_Input_idx_0 > 0.0) {
    rtb_APP_Input_idx_0 = 0.0;
  } else {
    if (rtb_APP_Input_idx_0 < -5.0) {
      rtb_APP_Input_idx_0 = -5.0;
    }
  }

  /* End of Saturate: '<S33>/Saturation' */

  /* Saturate: '<S33>/Saturation1' */
  rtb_APP_Input_idx_39 = ACC_AccTorqueReq;
  if (rtb_APP_Input_idx_39 > 10.0) {
    rtb_APP_Input_idx_39 = 10.0;
  } else {
    if (rtb_APP_Input_idx_39 < 0.0) {
      rtb_APP_Input_idx_39 = 0.0;
    }
  }

  /* End of Saturate: '<S33>/Saturation1' */

  /* Update for Memory: '<S33>/Memory1' */
  VCU_CS75_12_27_test_DW.Memory1_PreviousInput_p = ACC_RollingCounter_id2E4;

  /* Update for Memory: '<S33>/Memory2' */
  VCU_CS75_12_27_test_DW.Memory2_PreviousInput_b = ACC_RollingCounter_id2E5;

  /* End of Outputs for SubSystem: '<S27>/Longitudinal' */

  /* Memory: '<S52>/Memory1' */
  A1counter = VCU_CS75_12_27_test_DW.Memory1_PreviousInput;

  /* Memory: '<S52>/Memory2' */
  rtb_P6_Value = VCU_CS75_12_27_test_DW.Memory2_PreviousInput_c;

  /* MATLAB Function: '<S52>/MATLAB Function1' */
  /* MATLAB Function '长安CS75底盘程序，20ms一次/APP/Monitor/Server_Status/MATLAB Function1': '<S56>:1' */
  if (rtb_APP_Input_idx_3 == A1counter) {
    /* '<S56>:1:2' */
    /* '<S56>:1:3' */
    rtb_P6_Value++;
  } else {
    /* '<S56>:1:5' */
    rtb_P6_Value = 0.0;
  }

  counter3 = rtb_P6_Value;

  /* End of MATLAB Function: '<S52>/MATLAB Function1' */

  /* Update for Memory: '<S54>/Memory3' */
  VCU_CS75_12_27_test_DW.Memory3_PreviousInput = rtb_APP_Input_idx_17;

  /* Update for Memory: '<S54>/Memory2' */
  VCU_CS75_12_27_test_DW.Memory2_PreviousInput = counter1;

  /* Update for Memory: '<S52>/Memory1' */
  VCU_CS75_12_27_test_DW.Memory1_PreviousInput = rtb_APP_Input_idx_3;

  /* Update for Memory: '<S52>/Memory2' */
  VCU_CS75_12_27_test_DW.Memory2_PreviousInput_c = counter3;

  /* End of Outputs for SubSystem: '<S2>/APP' */

  /* Lookup_n-D: '<S696>/1-D Lookup Table' */
  rtb_APP_Input_idx_29 = look1_binlx(rtb_APP_Input_idx_99,
    VCU_CS75_12_27_test_ConstP.pooled2,
    VCU_CS75_12_27_test_ConstP.DLookupTable_tableDat, 1U);

  /* Abs: '<S696>/Abs' */
  rtb_Memory2 = fabs(rtb_APP_Input_idx_63);

  /* Abs: '<S696>/Abs1' */
  rtb_APP_Input_idx_79 = fabs(rtb_APP_Input_idx_66);

  /* Gain: '<S696>/Gain' */
  rtb_APP_Input_idx_29 *= 0.017453291666666666;

  /* Saturate: '<S706>/Steering_Angle_Feedback_sat' */
  if (rtb_APP_Input_idx_29 > 0.69787) {
    rtb_APP_Input_idx_29 = 0.69787;
  } else {
    if (rtb_APP_Input_idx_29 < -0.698) {
      rtb_APP_Input_idx_29 = -0.698;
    }
  }

  /* End of Saturate: '<S706>/Steering_Angle_Feedback_sat' */

  /* Sum: '<S706>/Steering_Angle_Feedback_st' incorporates:
   *  Constant: '<S706>/Steering_Angle_Feedback_O'
   */
  rtb_P6_Value = rtb_APP_Input_idx_29 - -0.69800001382827759;

  /* Product: '<S706>/Steering_Angle_Feedback_D' */
  rtb_APP_Input_idx_29 = rtb_P6_Value / 0.00547399977222085;

  /* Rounding: '<S706>/Steering_Angle_FeedbackRon' */
  rtb_APP_Input_idx_29 = rt_roundd_snf(rtb_APP_Input_idx_29);

  /* DataTypeConversion: '<S706>/Steering_Angle_Feedback_Convert1' */
  rtb_LAS_SteeringTorqueReq_L = (uint32_T)rtb_APP_Input_idx_29;

  /* S-Function (sfix_bitop): '<S706>/Steering_Angle_Feedback_L' */
  rtb_ACC_RollingCounter_L = rtb_LAS_SteeringTorqueReq_L & 255U;

  /* DataTypeConversion: '<S706>/Steering_Angle_Feedback_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_ACC_RollingCounter_L;

  /* S-Function (sfix_bitop): '<S702>/or1' */
  VCU_CS75_12_27_test_B.or1 = rtb_ACC_CDDAxEnable_Convert;

  /* Gain: '<S696>/Gain1' */
  EMS_IndicatedRealTroq = 0.01 * rtb_APP_Input_idx_9;

  /* Saturate: '<S703>/Engine_Feedback_sat' */
  rtb_P6_Value = EMS_IndicatedRealTroq;
  if (rtb_P6_Value > 1.0) {
    rtb_P6_Value = 1.0;
  } else {
    if (rtb_P6_Value < -1.0) {
      rtb_P6_Value = -1.0;
    }
  }

  /* End of Saturate: '<S703>/Engine_Feedback_sat' */

  /* Sum: '<S703>/Engine_Feedback_st' incorporates:
   *  Constant: '<S703>/Engine_Feedback_O'
   */
  rtb_APP_Input_idx_29 = rtb_P6_Value - -1.0;

  /* Product: '<S703>/Engine_Feedback_D' */
  rtb_P6_Value = rtb_APP_Input_idx_29 / 0.0078431377187371254;

  /* Rounding: '<S703>/Engine_FeedbackRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S703>/Engine_Feedback_Convert1' */
  rtb_ACC_RollingCounter_L = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S703>/Engine_Feedback_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ACC_RollingCounter_L & 255U;

  /* DataTypeConversion: '<S703>/Engine_Feedback_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_LAS_SteeringTorqueReq_L;

  /* S-Function (sfix_bitop): '<S702>/or2' */
  VCU_CS75_12_27_test_B.or2 = rtb_ACC_CDDAxEnable_Convert;

  /* Saturate: '<S704>/Engine_Feedback2_sat' */
  rtb_P6_Value = EMS_IndicatedRealTroq;
  if (rtb_P6_Value > 1.0) {
    rtb_P6_Value = 1.0;
  } else {
    if (rtb_P6_Value < -1.0) {
      rtb_P6_Value = -1.0;
    }
  }

  /* End of Saturate: '<S704>/Engine_Feedback2_sat' */

  /* Sum: '<S704>/Engine_Feedback2_st' incorporates:
   *  Constant: '<S704>/Engine_Feedback2_O'
   */
  rtb_APP_Input_idx_29 = rtb_P6_Value - -1.0;

  /* Product: '<S704>/Engine_Feedback2_D' */
  rtb_P6_Value = rtb_APP_Input_idx_29 / 0.0078431377187371254;

  /* Rounding: '<S704>/Engine_Feedback2Ron' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S704>/Engine_Feedback2_Convert1' */
  rtb_ACC_RollingCounter_L = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S704>/Engine_Feedback2_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ACC_RollingCounter_L & 255U;

  /* DataTypeConversion: '<S704>/Engine_Feedback2_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_LAS_SteeringTorqueReq_L;

  /* S-Function (sfix_bitop): '<S702>/or3' */
  VCU_CS75_12_27_test_B.or3 = rtb_ACC_CDDAxEnable_Convert;

  /* Saturate: '<S708>/Wheel_Speed_RL_Feedback_sat' */
  if (rtb_APP_Input_idx_79 > 200.0) {
    rtb_APP_Input_idx_79 = 200.0;
  }

  /* End of Saturate: '<S708>/Wheel_Speed_RL_Feedback_sat' */

  /* Sum: '<S708>/Wheel_Speed_RL_Feedback_st' */
  rtb_P6_Value = rtb_APP_Input_idx_79;

  /* Product: '<S708>/Wheel_Speed_RL_Feedback_D' */
  rtb_APP_Input_idx_79 = rtb_P6_Value / 0.78431373834609985;

  /* Rounding: '<S708>/Wheel_Speed_RL_FeedbackRon' */
  rtb_APP_Input_idx_79 = rt_roundd_snf(rtb_APP_Input_idx_79);

  /* DataTypeConversion: '<S708>/Wheel_Speed_RL_Feedback_Convert1' */
  rtb_ACC_RollingCounter_L = (uint32_T)rtb_APP_Input_idx_79;

  /* S-Function (sfix_bitop): '<S708>/Wheel_Speed_RL_Feedback_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ACC_RollingCounter_L & 255U;

  /* DataTypeConversion: '<S708>/Wheel_Speed_RL_Feedback_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_LAS_SteeringTorqueReq_L;

  /* S-Function (sfix_bitop): '<S702>/or4' */
  VCU_CS75_12_27_test_B.or4 = rtb_ACC_CDDAxEnable_Convert;

  /* Saturate: '<S709>/Wheel_Speed_RR_Feedback_sat' */
  if (rtb_Memory2 > 200.0) {
    rtb_Memory2 = 200.0;
  }

  /* End of Saturate: '<S709>/Wheel_Speed_RR_Feedback_sat' */

  /* Sum: '<S709>/Wheel_Speed_RR_Feedback_st' */
  rtb_P6_Value = rtb_Memory2;

  /* Product: '<S709>/Wheel_Speed_RR_Feedback_D' */
  rtb_APP_Input_idx_79 = rtb_P6_Value / 0.78431373834609985;

  /* Rounding: '<S709>/Wheel_Speed_RR_FeedbackRon' */
  rtb_APP_Input_idx_79 = rt_roundd_snf(rtb_APP_Input_idx_79);

  /* DataTypeConversion: '<S709>/Wheel_Speed_RR_Feedback_Convert1' */
  rtb_ACC_RollingCounter_L = (uint32_T)rtb_APP_Input_idx_79;

  /* S-Function (sfix_bitop): '<S709>/Wheel_Speed_RR_Feedback_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ACC_RollingCounter_L & 255U;

  /* DataTypeConversion: '<S709>/Wheel_Speed_RR_Feedback_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_LAS_SteeringTorqueReq_L;

  /* S-Function (sfix_bitop): '<S702>/or5' */
  VCU_CS75_12_27_test_B.or5 = rtb_ACC_CDDAxEnable_Convert;

  /* Delay: '<S696>/Delay' */
  rtb_P6_Value = VCU_CS75_12_27_test_DW.Delay_DSTATE[0];

  /* Saturate: '<S705>/Res_go_sat' */
  if (rtb_P6_Value > 1.0) {
    rtb_P6_Value = 1.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S705>/Res_go_sat' */

  /* Sum: '<S705>/Res_go_st' */
  rtb_APP_Input_idx_79 = rtb_P6_Value;

  /* Rounding: '<S705>/Res_goRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S705>/Res_go_Convert1' */
  rtb_ACC_RollingCounter_L = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S705>/Res_go_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ACC_RollingCounter_L & 255U;

  /* DataTypeConversion: '<S705>/Res_go_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_LAS_SteeringTorqueReq_L;

  /* S-Function (sfix_bitop): '<S702>/or6' */
  VCU_CS75_12_27_test_B.or6 = rtb_ACC_CDDAxEnable_Convert;

  /* Saturate: '<S707>/Steering_feedback_sat' */
  if (rtb_APP_Input_idx_99 > 499.998565) {
    rtb_P6_Value = 499.998565;
  } else if (rtb_APP_Input_idx_99 < -500.0) {
    rtb_P6_Value = -500.0;
  } else {
    rtb_P6_Value = rtb_APP_Input_idx_99;
  }

  /* End of Saturate: '<S707>/Steering_feedback_sat' */

  /* Sum: '<S707>/Steering_feedback_st' incorporates:
   *  Constant: '<S707>/Steering_feedback_O'
   */
  rtb_APP_Input_idx_79 = rtb_P6_Value - -500.0;

  /* Product: '<S707>/Steering_feedback_D' */
  rtb_P6_Value = rtb_APP_Input_idx_79 / 0.015258999541401863;

  /* Rounding: '<S707>/Steering_feedbackRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S707>/Steering_feedback_Convert' */
  rtb_ACC_RollingCounter_L = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S707>/Steering_feedback_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ACC_RollingCounter_L & 65535U;

  /* S-Function (sfix_bitop): '<S707>/Steering_feedback_And' incorporates:
   *  Constant: '<S707>/Steering_feedback_And_C'
   */
  rtb_ACC_RollingCounter_L = rtb_LAS_SteeringTorqueReq_L & 255U;

  /* DataTypeConversion: '<S707>/BitCov' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_ACC_RollingCounter_L;

  /* S-Function (sfix_bitop): '<S702>/or7' */
  VCU_CS75_12_27_test_B.or7 = rtb_ACC_CDDAxEnable_Convert;

  /* Product: '<S707>/Steering_feedback_D1' incorporates:
   *  Constant: '<S707>/Steering_feedbackoutput8_C'
   */
  rtb_P6_Value = (real_T)rtb_LAS_SteeringTorqueReq_L / 256.0;

  /* DataTypeConversion: '<S707>/Steering_feedbackCOV' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S702>/or8' */
  VCU_CS75_12_27_test_B.or8 = rtb_ACC_CDDAxEnable_Convert;

  /* S-Function (ec5744_cantransmitslb): '<S696>/CANTransmit' */

  /*Transmit CAN message*/
  {
    uint8 CAN0BUF8TX[8];
    uint8 can0buf8looptx= 0;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_12_27_test_B.or1;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_12_27_test_B.or2;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_12_27_test_B.or3;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_12_27_test_B.or4;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_12_27_test_B.or5;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_12_27_test_B.or6;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_12_27_test_B.or7;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_12_27_test_B.or8;
    can0buf8looptx++;
    VCU_CS75_12_27_test_B.CANTransmit_i= ec_can_transmit(0, 8, 1, 1297U, 8,
      CAN0BUF8TX);
  }

  /* DataTypeConversion: '<S696>/Data Type Conversion' */
  EMS_FrictionalTroq = rtb_APP_Input_idx_8;

  /* DataTypeConversion: '<S696>/Data Type Conversion1' */
  EMS_TorqueConstant = rtb_APP_Input_idx_20;

  /* DataTypeConversion: '<S696>/Data Type Conversion2' */
  EMS_FullLoadIndicatedTroq = rtb_APP_Input_idx_19;

  /* Saturate: '<S742>/PID_ST_Out_sat' */
  if (rtb_APP_Input_idx_2 > 3.81) {
    rtb_P6_Value = 3.81;
  } else if (rtb_APP_Input_idx_2 < -3.84) {
    rtb_P6_Value = -3.84;
  } else {
    rtb_P6_Value = rtb_APP_Input_idx_2;
  }

  /* End of Saturate: '<S742>/PID_ST_Out_sat' */

  /* Sum: '<S742>/PID_ST_Out_st' */
  rtb_APP_Input_idx_79 = rtb_P6_Value;

  /* Product: '<S742>/PID_ST_Out_D' */
  rtb_P6_Value = rtb_APP_Input_idx_79 / 0.029999999329447746;

  /* Rounding: '<S742>/PID_ST_OutRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* RelationalOperator: '<S742>/PID_ST_OutROP' */
  rtb_ErrorROP = (rtb_P6_Value < 0.0);

  /* Switch: '<S742>/PID_ST_OutSW' */
  if (rtb_ErrorROP) {
    /* Abs: '<S742>/PID_ST_OutABS' */
    rtb_P6_Value = fabs(rtb_P6_Value);

    /* Sum: '<S742>/PID_ST_Outsubcon' */
    rtb_P6_Value = 256.0 - rtb_P6_Value;
  }

  /* End of Switch: '<S742>/PID_ST_OutSW' */

  /* Saturate: '<S742>/PID_ST_Out_1sat' */
  if (rtb_P6_Value > 255.0) {
    rtb_P6_Value = 255.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S742>/PID_ST_Out_1sat' */

  /* DataTypeConversion: '<S742>/PID_ST_Out_Convert1' */
  rtb_ACC_RollingCounter_L = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S742>/PID_ST_Out_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ACC_RollingCounter_L & 255U;

  /* DataTypeConversion: '<S742>/PID_ST_Out_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_LAS_SteeringTorqueReq_L;

  /* S-Function (sfix_bitop): '<S739>/or1' */
  VCU_CS75_12_27_test_B.or1_e = rtb_ACC_CDDAxEnable_Convert;

  /* Saturate: '<S741>/ErrorSum_sat' */
  if (rtb_Memory1_e > 3276.7F) {
    rtb_Memory1_e = 3276.7F;
  } else {
    if (rtb_Memory1_e < -3276.8F) {
      rtb_Memory1_e = -3276.8F;
    }
  }

  /* End of Saturate: '<S741>/ErrorSum_sat' */

  /* Product: '<S741>/ErrorSum_D' incorporates:
   *  Constant: '<S741>/ErrorSum_F'
   */
  rtb_Memory1_e /= 0.1F;

  /* Rounding: '<S741>/ErrorSumRon' */
  rtb_Memory1_e = rt_roundf_snf(rtb_Memory1_e);

  /* RelationalOperator: '<S741>/ErrorSumROP' */
  rtb_ErrorROP = (rtb_Memory1_e < 0.0F);

  /* Switch: '<S741>/ErrorSumSW' */
  if (rtb_ErrorROP) {
    /* Abs: '<S741>/ErrorSumABS' */
    rtb_Memory1_e = (real32_T)fabs(rtb_Memory1_e);

    /* Sum: '<S741>/ErrorSumsubcon' */
    rtb_Memory1_e = 65536.0F - rtb_Memory1_e;
  }

  /* End of Switch: '<S741>/ErrorSumSW' */

  /* Saturate: '<S741>/ErrorSum_1sat' */
  if (rtb_Memory1_e > 65535.0F) {
    rtb_Memory1_e = 65535.0F;
  } else {
    if (rtb_Memory1_e < 0.0F) {
      rtb_Memory1_e = 0.0F;
    }
  }

  /* End of Saturate: '<S741>/ErrorSum_1sat' */

  /* DataTypeConversion: '<S741>/ErrorSum_Convert' */
  rtb_ACC_RollingCounter_L = (uint32_T)rtb_Memory1_e;

  /* S-Function (sfix_bitop): '<S741>/ErrorSum_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ACC_RollingCounter_L & 65535U;

  /* S-Function (sfix_bitop): '<S741>/ErrorSum_And' incorporates:
   *  Constant: '<S741>/ErrorSum_And_C'
   */
  rtb_ACC_RollingCounter_L = rtb_LAS_SteeringTorqueReq_L & 255U;

  /* DataTypeConversion: '<S741>/BitCov' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_ACC_RollingCounter_L;

  /* S-Function (sfix_bitop): '<S739>/or2' */
  VCU_CS75_12_27_test_B.or2_a = rtb_ACC_CDDAxEnable_Convert;

  /* Product: '<S741>/ErrorSum_D1' incorporates:
   *  Constant: '<S741>/ErrorSumoutput3_C'
   */
  rtb_P6_Value = (real_T)rtb_LAS_SteeringTorqueReq_L / 256.0;

  /* DataTypeConversion: '<S741>/ErrorSumCOV' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S739>/or3' */
  VCU_CS75_12_27_test_B.or3_h = rtb_ACC_CDDAxEnable_Convert;

  /* Saturate: '<S740>/Error_sat' */
  if (rtb_Error > 6553.4F) {
    rtb_Memory1_e = 6553.4F;
  } else if (rtb_Error < -6553.6F) {
    rtb_Memory1_e = -6553.6F;
  } else {
    rtb_Memory1_e = rtb_Error;
  }

  /* End of Saturate: '<S740>/Error_sat' */

  /* Product: '<S740>/Error_D' incorporates:
   *  Constant: '<S740>/Error_F'
   */
  rtb_Memory1_e /= 0.2F;

  /* Rounding: '<S740>/ErrorRon' */
  rtb_Memory1_e = rt_roundf_snf(rtb_Memory1_e);

  /* RelationalOperator: '<S740>/ErrorROP' */
  rtb_ErrorROP = (rtb_Memory1_e < 0.0F);

  /* Switch: '<S740>/ErrorSW' */
  if (rtb_ErrorROP) {
    /* Abs: '<S740>/ErrorABS' */
    rtb_Memory1_e = (real32_T)fabs(rtb_Memory1_e);

    /* Sum: '<S740>/Errorsubcon' */
    rtb_Memory1_e = 65536.0F - rtb_Memory1_e;
  }

  /* End of Switch: '<S740>/ErrorSW' */

  /* Saturate: '<S740>/Error_1sat' */
  if (rtb_Memory1_e > 65535.0F) {
    rtb_Memory1_e = 65535.0F;
  } else {
    if (rtb_Memory1_e < 0.0F) {
      rtb_Memory1_e = 0.0F;
    }
  }

  /* End of Saturate: '<S740>/Error_1sat' */

  /* DataTypeConversion: '<S740>/Error_Convert' */
  rtb_ACC_RollingCounter_L = (uint32_T)rtb_Memory1_e;

  /* S-Function (sfix_bitop): '<S740>/Error_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ACC_RollingCounter_L & 65535U;

  /* S-Function (sfix_bitop): '<S740>/Error_And' incorporates:
   *  Constant: '<S740>/Error_And_C'
   */
  rtb_ACC_RollingCounter_L = rtb_LAS_SteeringTorqueReq_L & 255U;

  /* DataTypeConversion: '<S740>/BitCov' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_ACC_RollingCounter_L;

  /* S-Function (sfix_bitop): '<S739>/or4' */
  VCU_CS75_12_27_test_B.or4_o = rtb_ACC_CDDAxEnable_Convert;

  /* Product: '<S740>/Error_D1' incorporates:
   *  Constant: '<S740>/Erroroutput5_C'
   */
  rtb_P6_Value = (real_T)rtb_LAS_SteeringTorqueReq_L / 256.0;

  /* DataTypeConversion: '<S740>/ErrorCOV' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S739>/or5' */
  VCU_CS75_12_27_test_B.or5_i = rtb_ACC_CDDAxEnable_Convert;

  /* S-Function (ec5744_cantransmitslb): '<S701>/CANTransmit' */

  /*Transmit CAN message*/
  {
    uint8 CAN0BUF11TX[8];
    uint8 can0buf11looptx= 0;
    CAN0BUF11TX[can0buf11looptx]= VCU_CS75_12_27_test_B.or1_e;
    can0buf11looptx++;
    CAN0BUF11TX[can0buf11looptx]= VCU_CS75_12_27_test_B.or2_a;
    can0buf11looptx++;
    CAN0BUF11TX[can0buf11looptx]= VCU_CS75_12_27_test_B.or3_h;
    can0buf11looptx++;
    CAN0BUF11TX[can0buf11looptx]= VCU_CS75_12_27_test_B.or4_o;
    can0buf11looptx++;
    CAN0BUF11TX[can0buf11looptx]= VCU_CS75_12_27_test_B.or5_i;
    can0buf11looptx++;
    CAN0BUF11TX[can0buf11looptx]= VCU_CS75_12_27_test_ConstB.or6;
    can0buf11looptx++;
    CAN0BUF11TX[can0buf11looptx]= VCU_CS75_12_27_test_ConstB.or7;
    can0buf11looptx++;
    CAN0BUF11TX[can0buf11looptx]= VCU_CS75_12_27_test_ConstB.or8;
    can0buf11looptx++;
    VCU_CS75_12_27_test_B.CANTransmit_l= ec_can_transmit(0, 11, 0, 1537U, 8,
      CAN0BUF11TX);
  }

  /* Saturate: '<S753>/LAS_LDWStatus_sat' */
  rtb_P6_Value = LAS_LDWStatus;
  if (rtb_P6_Value > 3.0) {
    rtb_P6_Value = 3.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S753>/LAS_LDWStatus_sat' */

  /* Sum: '<S753>/LAS_LDWStatus_st' */
  rtb_APP_Input_idx_79 = rtb_P6_Value;

  /* Rounding: '<S753>/LAS_LDWStatusRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* ArithShift: '<S753>/LAS_LDWStatus_S' */
  rtb_P6_Value = ldexp(rtb_P6_Value, 5);

  /* DataTypeConversion: '<S753>/LAS_LDWStatus_Convert1' */
  rtb_ACC_RollingCounter_L = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S753>/LAS_LDWStatus_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ACC_RollingCounter_L & 96U;

  /* DataTypeConversion: '<S753>/LAS_LDWStatus_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_LAS_SteeringTorqueReq_L;

  /* S-Function (sfix_bitop): '<S746>/or1' */
  VCU_CS75_12_27_test_B.or1_m = rtb_ACC_CDDAxEnable_Convert;

  /* Saturate: '<S754>/LAS_LDWVibrationWarning_sat' */
  rtb_P6_Value = LAS_LDWVibrationWarning;
  if (rtb_P6_Value > 3.0) {
    rtb_P6_Value = 3.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S754>/LAS_LDWVibrationWarning_sat' */

  /* Rounding: '<S754>/LAS_LDWVibrationWarningRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* ArithShift: '<S754>/LAS_LDWVibrationWarning_S' */
  rtb_P6_Value = ldexp(rtb_P6_Value, 5);

  /* DataTypeConversion: '<S754>/LAS_LDWVibrationWarning_Convert1' */
  rtb_ACC_RollingCounter_L = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S754>/LAS_LDWVibrationWarning_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ACC_RollingCounter_L & 96U;

  /* DataTypeConversion: '<S754>/LAS_LDWVibrationWarning_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_LAS_SteeringTorqueReq_L;

  /* S-Function (sfix_bitop): '<S746>/or2' */
  VCU_CS75_12_27_test_B.or2_g = rtb_ACC_CDDAxEnable_Convert;

  /* Saturate: '<S759>/LAS_SteeringTorqueReq_sat' */
  rtb_P6_Value = rtb_APP_Input_idx_12;

  /* Sum: '<S759>/LAS_SteeringTorqueReq_st' incorporates:
   *  Constant: '<S759>/LAS_SteeringTorqueReq_O'
   */
  rtb_APP_Input_idx_79 = rtb_P6_Value - -8.0;

  /* Product: '<S759>/LAS_SteeringTorqueReq_D' */
  rtb_P6_Value = rtb_APP_Input_idx_79 / 0.0099999997764825821;

  /* Rounding: '<S759>/LAS_SteeringTorqueReqRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* ArithShift: '<S759>/LAS_SteeringTorqueReq_S' */
  rtb_P6_Value = ldexp(rtb_P6_Value, 7);

  /* DataTypeConversion: '<S759>/LAS_SteeringTorqueReq_Convert' */
  rtb_ACC_RollingCounter_L = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S759>/LAS_SteeringTorqueReq_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ACC_RollingCounter_L & 262016U;

  /* Product: '<S759>/LAS_SteeringTorqueReq_D1' incorporates:
   *  Constant: '<S759>/LAS_SteeringTorqueReqoutput5_C'
   */
  rtb_P6_Value = (real_T)rtb_LAS_SteeringTorqueReq_L / 65536.0;

  /* DataTypeConversion: '<S759>/LAS_SteeringTorqueReqCOV' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_P6_Value;

  /* Saturate: '<S755>/LAS_LKSStatus_sat' */
  rtb_P6_Value = LAS_LKSStatus;
  if (rtb_P6_Value > 7.0) {
    rtb_P6_Value = 7.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S755>/LAS_LKSStatus_sat' */

  /* Sum: '<S755>/LAS_LKSStatus_st' */
  rtb_APP_Input_idx_79 = rtb_P6_Value;

  /* Rounding: '<S755>/LAS_LKSStatusRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* ArithShift: '<S755>/LAS_LKSStatus_S' */
  rtb_P6_Value = ldexp(rtb_P6_Value, 5);

  /* DataTypeConversion: '<S755>/LAS_LKSStatus_Convert1' */
  rtb_ACC_RollingCounter_L = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S755>/LAS_LKSStatus_L' */
  rtb_ACC_RollingCounter_Convert1 = rtb_ACC_RollingCounter_L & 224U;

  /* DataTypeConversion: '<S755>/LAS_LKSStatus_Convert' */
  rtb_ACC_ACCTargetAcceleration_C = (uint8_T)rtb_ACC_RollingCounter_Convert1;

  /* S-Function (sfix_bitop): '<S746>/or5' */
  VCU_CS75_12_27_test_B.or5_h = (uint8_T)(rtb_ACC_CDDAxEnable_Convert |
    rtb_ACC_ACCTargetAcceleration_C);

  /* S-Function (sfix_bitop): '<S759>/LAS_SteeringTorqueReq_And' */
  rtb_ACC_RollingCounter_Convert1 = rtb_LAS_SteeringTorqueReq_L & 65535U;

  /* Product: '<S759>/LAS_SteeringTorqueReq_D2' incorporates:
   *  Constant: '<S759>/LAS_SteeringTorqueReqoutput6_C'
   */
  rtb_P6_Value = (real_T)rtb_ACC_RollingCounter_Convert1 / 256.0;

  /* DataTypeConversion: '<S759>/LAS_SteeringTorqueReqCOV1' */
  rtb_ACC_ACCTargetAcceleration_C = (uint8_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S746>/or6' */
  VCU_CS75_12_27_test_B.or6_f = rtb_ACC_ACCTargetAcceleration_C;

  /* S-Function (sfix_bitop): '<S759>/LAS_SteeringTorqueReq_And1' incorporates:
   *  Constant: '<S759>/LAS_SteeringTorqueReq_And1_C'
   */
  rtb_ACC_RollingCounter_Convert1 = rtb_LAS_SteeringTorqueReq_L & 255U;

  /* DataTypeConversion: '<S759>/LAS_SteeringTorqueReqBitCov1' */
  rtb_ACC_ACCTargetAcceleration_C = (uint8_T)rtb_ACC_RollingCounter_Convert1;

  /* Saturate: '<S761>/RollingConter_sat' */
  rtb_P6_Value = LAS_RollingCounter;
  if (rtb_P6_Value > 15.0) {
    rtb_P6_Value = 15.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S761>/RollingConter_sat' */

  /* Rounding: '<S761>/RollingConterRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S761>/RollingConter_Convert1' */
  rtb_ACC_RollingCounter_Convert1 = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S761>/RollingConter_L' */
  rtb_ACC_RollingCounter_L = rtb_ACC_RollingCounter_Convert1 & 15U;

  /* DataTypeConversion: '<S761>/RollingConter_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_ACC_RollingCounter_L;

  /* S-Function (sfix_bitop): '<S746>/or7' */
  VCU_CS75_12_27_test_B.or7_h = (uint8_T)(rtb_ACC_ACCTargetAcceleration_C |
    rtb_ACC_CDDAxEnable_Convert);

  /* S-Function (ec5744_cantransmitslb): '<S743>/CANTransmit' */

  /*Transmit CAN message*/
  {
    uint8 CAN1BUF13TX[8];
    uint8 can1buf13looptx= 0;
    CAN1BUF13TX[can1buf13looptx]= VCU_CS75_12_27_test_B.or1_m;
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= VCU_CS75_12_27_test_B.or2_g;
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= VCU_CS75_12_27_test_ConstB.or3;
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= VCU_CS75_12_27_test_ConstB.or4;
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= VCU_CS75_12_27_test_B.or5_h;
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= VCU_CS75_12_27_test_B.or6_f;
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= VCU_CS75_12_27_test_B.or7_h;
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= VCU_CS75_12_27_test_ConstB.or8_j;
    can1buf13looptx++;
    VCU_CS75_12_27_test_B.CANTransmit_b= ec_can_transmit(1, 13, 0, 653U, 8,
      CAN1BUF13TX);
  }

  /* Saturate: '<S763>/ACC_ACCTargetAcceleration_sat' */
  rtb_P6_Value = rtb_APP_Input_idx_0;

  /* Sum: '<S763>/ACC_ACCTargetAcceleration_st' incorporates:
   *  Constant: '<S763>/ACC_ACCTargetAcceleration_O'
   */
  rtb_APP_Input_idx_79 = rtb_P6_Value - -5.0;

  /* Product: '<S763>/ACC_ACCTargetAcceleration_D' */
  rtb_P6_Value = rtb_APP_Input_idx_79 / 0.05000000074505806;

  /* Rounding: '<S763>/ACC_ACCTargetAccelerationRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S763>/ACC_ACCTargetAcceleration_Convert1' */
  rtb_ACC_RollingCounter_Convert1 = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S763>/ACC_ACCTargetAcceleration_L' */
  rtb_ACC_RollingCounter_L = rtb_ACC_RollingCounter_Convert1 & 255U;

  /* DataTypeConversion: '<S763>/ACC_ACCTargetAcceleration_Convert' */
  rtb_ACC_ACCTargetAcceleration_C = (uint8_T)rtb_ACC_RollingCounter_L;

  /* Saturate: '<S764>/ACC_CDDAxEnable_sat' */
  rtb_P6_Value = ACC_CDDAxEnable;
  if (rtb_P6_Value > 1.0) {
    rtb_P6_Value = 1.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S764>/ACC_CDDAxEnable_sat' */

  /* Sum: '<S764>/ACC_CDDAxEnable_st' */
  rtb_APP_Input_idx_79 = rtb_P6_Value;

  /* Rounding: '<S764>/ACC_CDDAxEnableRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S764>/ACC_CDDAxEnable_Convert1' */
  rtb_ACC_RollingCounter_Convert1 = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S764>/ACC_CDDAxEnable_L' */
  rtb_ACC_RollingCounter_L = rtb_ACC_RollingCounter_Convert1 & 1U;

  /* DataTypeConversion: '<S764>/ACC_CDDAxEnable_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_ACC_RollingCounter_L;

  /* Saturate: '<S766>/ACC_DecToStop_sat' incorporates:
   *  Constant: '<S33>/Constant1'
   */
  rtb_P6_Value = 0.0;

  /* Saturate: '<S767>/ACC_Driveoff_Request_sat' */
  rtb_APP_Input_idx_29 = ACC_Driveoff_Request;
  if (rtb_APP_Input_idx_29 > 1.0) {
    rtb_P6_Value = 1.0;
  } else {
    if (!(rtb_APP_Input_idx_29 < 0.0)) {
      rtb_P6_Value = rtb_APP_Input_idx_29;
    }
  }

  /* End of Saturate: '<S767>/ACC_Driveoff_Request_sat' */

  /* Sum: '<S767>/ACC_Driveoff_Request_st' */
  rtb_APP_Input_idx_79 = rtb_P6_Value;

  /* Rounding: '<S767>/ACC_Driveoff_RequestRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* ArithShift: '<S767>/ACC_Driveoff_Request_S' */
  rtb_P6_Value = ldexp(rtb_P6_Value, 2);

  /* DataTypeConversion: '<S767>/ACC_Driveoff_Request_Convert1' */
  rtb_ACC_RollingCounter_Convert1 = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S767>/ACC_Driveoff_Request_L' */
  rtb_ACC_RollingCounter_L = rtb_ACC_RollingCounter_Convert1 & 4U;

  /* DataTypeConversion: '<S767>/ACC_Driveoff_Request_Convert' */
  rtb_ACC_AccTrqReqEnable_Convert = (uint8_T)rtb_ACC_RollingCounter_L;

  /* Saturate: '<S769>/ACC_RollingCounter_id_sat' */
  rtb_P6_Value = ACC_RollingCounter_id2E4;
  if (rtb_P6_Value > 15.0) {
    rtb_P6_Value = 15.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S769>/ACC_RollingCounter_id_sat' */

  /* Rounding: '<S769>/ACC_RollingCounter_idRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S769>/ACC_RollingCounter_id_Convert1' */
  rtb_ACC_RollingCounter_Convert1 = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S769>/ACC_RollingCounter_id_L' */
  rtb_ACC_RollingCounter_L = rtb_ACC_RollingCounter_Convert1 & 15U;

  /* DataTypeConversion: '<S769>/ACC_RollingCounter_id_Convert' */
  rtb_ACC_AccTorqueReqBitCov = (uint8_T)rtb_ACC_RollingCounter_L;

  /* S-Function (sfix_bitop): '<S762>/or1' */
  VCU_CS75_12_27_test_B.or1_i = (uint8_T)(rtb_ACC_CDDAxEnable_Convert |
    rtb_ACC_AccTrqReqEnable_Convert | 24);

  /* S-Function (sfix_bitop): '<S762>/or2' */
  VCU_CS75_12_27_test_B.or2_b = rtb_ACC_ACCTargetAcceleration_C;

  /* S-Function (sfix_bitop): '<S762>/or7' */
  VCU_CS75_12_27_test_B.or7_g = rtb_ACC_AccTorqueReqBitCov;

  /* S-Function (ec5744_cantransmitslb): '<S744>/CANTransmit' */

  /*Transmit CAN message*/
  {
    uint8 CAN1BUF8TX[8];
    uint8 can1buf8looptx= 0;
    CAN1BUF8TX[can1buf8looptx]= VCU_CS75_12_27_test_B.or1_i;
    can1buf8looptx++;
    CAN1BUF8TX[can1buf8looptx]= VCU_CS75_12_27_test_B.or2_b;
    can1buf8looptx++;
    CAN1BUF8TX[can1buf8looptx]= VCU_CS75_12_27_test_ConstB.or3_e;
    can1buf8looptx++;
    CAN1BUF8TX[can1buf8looptx]= VCU_CS75_12_27_test_ConstB.or4_n;
    can1buf8looptx++;
    CAN1BUF8TX[can1buf8looptx]= VCU_CS75_12_27_test_ConstB.or5;
    can1buf8looptx++;
    CAN1BUF8TX[can1buf8looptx]= VCU_CS75_12_27_test_ConstB.or6_c;
    can1buf8looptx++;
    CAN1BUF8TX[can1buf8looptx]= VCU_CS75_12_27_test_B.or7_g;
    can1buf8looptx++;
    CAN1BUF8TX[can1buf8looptx]= VCU_CS75_12_27_test_ConstB.or8_c;
    can1buf8looptx++;
    VCU_CS75_12_27_test_B.CANTransmit_it= ec_can_transmit(1, 8, 0, 740U, 8,
      CAN1BUF8TX);
  }

  /* Saturate: '<S778>/ACC_AccTorqueReq_sat' */
  rtb_P6_Value = rtb_APP_Input_idx_39;

  /* Sum: '<S778>/ACC_AccTorqueReq_st' */
  rtb_APP_Input_idx_79 = rtb_P6_Value;

  /* Product: '<S778>/ACC_AccTorqueReq_D' */
  rtb_P6_Value = rtb_APP_Input_idx_79 / 0.097840003669261932;

  /* Rounding: '<S778>/ACC_AccTorqueReqRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* ArithShift: '<S778>/ACC_AccTorqueReq_S' */
  rtb_P6_Value = ldexp(rtb_P6_Value, 2);

  /* DataTypeConversion: '<S778>/ACC_AccTorqueReq_Convert' */
  rtb_ACC_RollingCounter_Convert1 = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S778>/ACC_AccTorqueReq_L' */
  rtb_ACC_RollingCounter_L = rtb_ACC_RollingCounter_Convert1 & 4092U;

  /* S-Function (sfix_bitop): '<S778>/ACC_AccTorqueReq_And' incorporates:
   *  Constant: '<S778>/ACC_AccTorqueReq_And_C'
   */
  rtb_ACC_RollingCounter_Convert1 = rtb_ACC_RollingCounter_L & 255U;

  /* DataTypeConversion: '<S778>/ACC_AccTorqueReqBitCov' */
  rtb_ACC_AccTorqueReqBitCov = (uint8_T)rtb_ACC_RollingCounter_Convert1;

  /* Product: '<S778>/ACC_AccTorqueReq_D1' incorporates:
   *  Constant: '<S778>/ACC_AccTorqueReqoutput5_C'
   */
  rtb_P6_Value = (real_T)rtb_ACC_RollingCounter_L / 256.0;

  /* DataTypeConversion: '<S778>/ACC_AccTorqueReqCOV' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_P6_Value;

  /* Saturate: '<S779>/ACC_AccTrqReqEnable_sat' */
  rtb_P6_Value = ACC_TrqEnable;
  if (rtb_P6_Value > 1.0) {
    rtb_P6_Value = 1.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S779>/ACC_AccTrqReqEnable_sat' */

  /* Sum: '<S779>/ACC_AccTrqReqEnable_st' */
  rtb_APP_Input_idx_79 = rtb_P6_Value;

  /* Rounding: '<S779>/ACC_AccTrqReqEnableRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* ArithShift: '<S779>/ACC_AccTrqReqEnable_S' */
  rtb_P6_Value = ldexp(rtb_P6_Value, 7);

  /* DataTypeConversion: '<S779>/ACC_AccTrqReqEnable_Convert1' */
  rtb_ACC_RollingCounter_Convert1 = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S779>/ACC_AccTrqReqEnable_L' */
  rtb_ACC_RollingCounter_L = rtb_ACC_RollingCounter_Convert1 & 128U;

  /* DataTypeConversion: '<S779>/ACC_AccTrqReqEnable_Convert' */
  rtb_ACC_AccTrqReqEnable_Convert = (uint8_T)rtb_ACC_RollingCounter_L;

  /* Saturate: '<S785>/ACC_RollingCounter_sat' */
  rtb_P6_Value = ACC_RollingCounter_id2E5;
  if (rtb_P6_Value > 15.0) {
    rtb_P6_Value = 15.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S785>/ACC_RollingCounter_sat' */

  /* Sum: '<S785>/ACC_RollingCounter_st' */
  rtb_APP_Input_idx_79 = rtb_P6_Value;

  /* Rounding: '<S785>/ACC_RollingCounterRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S785>/ACC_RollingCounter_Convert1' */
  rtb_ACC_RollingCounter_Convert1 = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S785>/ACC_RollingCounter_L' */
  rtb_ACC_RollingCounter_L = rtb_ACC_RollingCounter_Convert1 & 15U;

  /* DataTypeConversion: '<S785>/ACC_RollingCounter_Convert' */
  rtb_ACC_ACCTargetAcceleration_C = (uint8_T)rtb_ACC_RollingCounter_L;

  /* S-Function (sfix_bitop): '<S770>/or1' */
  VCU_CS75_12_27_test_B.or1_e1 = (uint8_T)(rtb_ACC_AccTrqReqEnable_Convert | 15);

  /* S-Function (sfix_bitop): '<S770>/or5' */
  VCU_CS75_12_27_test_B.or5_m = rtb_ACC_CDDAxEnable_Convert;

  /* S-Function (sfix_bitop): '<S770>/or6' */
  VCU_CS75_12_27_test_B.or6_e = rtb_ACC_AccTorqueReqBitCov;

  /* S-Function (sfix_bitop): '<S770>/or7' */
  VCU_CS75_12_27_test_B.or7_l = rtb_ACC_ACCTargetAcceleration_C;

  /* S-Function (ec5744_cantransmitslb): '<S745>/CANTransmit' */

  /*Transmit CAN message*/
  {
    uint8 CAN1BUF9TX[8];
    uint8 can1buf9looptx= 0;
    CAN1BUF9TX[can1buf9looptx]= VCU_CS75_12_27_test_B.or1_e1;
    can1buf9looptx++;
    CAN1BUF9TX[can1buf9looptx]= VCU_CS75_12_27_test_ConstB.or2;
    can1buf9looptx++;
    CAN1BUF9TX[can1buf9looptx]= VCU_CS75_12_27_test_ConstB.or3_ei;
    can1buf9looptx++;
    CAN1BUF9TX[can1buf9looptx]= VCU_CS75_12_27_test_ConstB.or4_a;
    can1buf9looptx++;
    CAN1BUF9TX[can1buf9looptx]= VCU_CS75_12_27_test_B.or5_m;
    can1buf9looptx++;
    CAN1BUF9TX[can1buf9looptx]= VCU_CS75_12_27_test_B.or6_e;
    can1buf9looptx++;
    CAN1BUF9TX[can1buf9looptx]= VCU_CS75_12_27_test_B.or7_l;
    can1buf9looptx++;
    CAN1BUF9TX[can1buf9looptx]= VCU_CS75_12_27_test_ConstB.or8_n;
    can1buf9looptx++;
    VCU_CS75_12_27_test_B.CANTransmit_k= ec_can_transmit(1, 9, 0, 741U, 8,
      CAN1BUF9TX);
  }

  /* Update for Delay: '<S696>/Delay' */
  for (idxDelay = 0; idxDelay < 24; idxDelay++) {
    VCU_CS75_12_27_test_DW.Delay_DSTATE[idxDelay] =
      VCU_CS75_12_27_test_DW.Delay_DSTATE[idxDelay + 1];
  }

  VCU_CS75_12_27_test_DW.Delay_DSTATE[24] = rtb_APP_Input_idx_217;

  /* End of Update for Delay: '<S696>/Delay' */
}

/* Model step function for TID5 */
void VCU_CS75_12_27_test_step5(void)   /* Sample time: [0.05s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S4>/50ms' incorporates:
   *  SubSystem: '<S4>/daq50ms'
   */

  /* S-Function (ec5744_ccpslb1): '<S18>/CCPDAQ' */
  ccpDaq(2);
}

/* Model step function for TID6 */
void VCU_CS75_12_27_test_step6(void)   /* Sample time: [0.1s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S3>/100MS' incorporates:
   *  SubSystem: '<S3>/Function-Call Subsystem'
   */

  /* S-Function (ec5744_canreceiveslb): '<S7>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN2BUF1RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can2buf1looprx= 0;
    VCU_CS75_12_27_test_B.CANReceive_o3_i= 278;
    VCU_CS75_12_27_test_B.CANReceive_o5_i= 8;
    VCU_CS75_12_27_test_B.CANReceive_o2_a= ec_can_receive(2,1, CAN2BUF1RX);
    VCU_CS75_12_27_test_B.CANReceive_o4_h[0]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_h[1]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_h[2]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_h[3]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_h[4]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_h[5]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_h[6]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_12_27_test_B.CANReceive_o4_h[7]= CAN2BUF1RX[can2buf1looprx];
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
    if (VCU_CS75_12_27_test_B.CANReceive_o2_a > 0) {
      /* RelationalOperator: '<S10>/Compare' incorporates:
       *  Constant: '<S10>/Constant'
       */
      rtb_Add = (uint8_T)(VCU_CS75_12_27_test_B.CANReceive_o4_h[0] == 83);

      /* RelationalOperator: '<S11>/Compare' incorporates:
       *  Constant: '<S11>/Constant'
       */
      rtb_Compare = (uint8_T)(VCU_CS75_12_27_test_B.CANReceive_o4_h[5] == 84);

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
          VCU_CS75_12_27_test_B.CANTransmit= ec_can_transmit(2, 9, 0, 593U, 1,
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
void VCU_CS75_12_27_test_step7(void)   /* Sample time: [0.5s, 0.0s] */
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
void VCU_CS75_12_27_test_step(int_T tid)
{
  switch (tid) {
   case 0 :
    VCU_CS75_12_27_test_step0();
    break;

   case 1 :
    VCU_CS75_12_27_test_step1();
    break;

   case 2 :
    VCU_CS75_12_27_test_step2();
    break;

   case 3 :
    VCU_CS75_12_27_test_step3();
    break;

   case 4 :
    VCU_CS75_12_27_test_step4();
    break;

   case 5 :
    VCU_CS75_12_27_test_step5();
    break;

   case 6 :
    VCU_CS75_12_27_test_step6();
    break;

   case 7 :
    VCU_CS75_12_27_test_step7();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void VCU_CS75_12_27_test_initialize(void)
{
  /* Start for S-Function (fcncallgen): '<Root>/20ms' incorporates:
   *  Start for SubSystem: '<Root>/长安CS75底盘程序，20ms一次'
   */

  /* Start for Atomic SubSystem: '<S2>/Input' */

  /* Start for S-Function (ec5744_canreceiveslb): '<S66>/CANReceive' */
  ec_buffer_init(0,0,0,529);

  /* Start for S-Function (ec5744_canreceiveslb): '<S80>/CANReceive' */
  ec_buffer_init(1,23,0,648);

  /* Start for S-Function (ec5744_canreceiveslb): '<S81>/CANReceive' */
  ec_buffer_init(1,24,0,808);

  /* Start for S-Function (ec5744_canreceiveslb): '<S82>/CANReceive' */
  ec_buffer_init(1,25,0,840);

  /* Start for S-Function (ec5744_canreceiveslb): '<S83>/CANReceive' */
  ec_buffer_init(1,26,0,991);

  /* Start for S-Function (ec5744_canreceiveslb): '<S84>/CANReceive' */
  ec_buffer_init(1,0,0,517);

  /* Start for S-Function (ec5744_canreceiveslb): '<S85>/CANReceive' */
  ec_buffer_init(1,1,0,597);

  /* Start for S-Function (ec5744_canreceiveslb): '<S86>/CANReceive' */
  ec_buffer_init(1,2,0,613);

  /* Start for S-Function (ec5744_canreceiveslb): '<S87>/CANReceive' */
  ec_buffer_init(1,3,0,630);

  /* Start for S-Function (ec5744_canreceiveslb): '<S88>/CANReceive' */
  ec_buffer_init(1,4,0,598);

  /* Start for S-Function (ec5744_canreceiveslb): '<S89>/CANReceive' */
  ec_buffer_init(1,5,0,522);

  /* Start for S-Function (ec5744_canreceiveslb): '<S90>/CANReceive' */
  ec_buffer_init(1,6,0,538);

  /* Start for S-Function (ec5744_canreceiveslb): '<S91>/CANReceive' */
  ec_buffer_init(1,7,0,631);

  /* Start for S-Function (ec5744_canreceiveslb): '<S92>/CANReceive' */
  ec_buffer_init(1,16,0,640);

  /* Start for S-Function (ec5744_canreceiveslb): '<S93>/CANReceive' */
  ec_buffer_init(1,17,0,641);

  /* Start for S-Function (ec5744_canreceiveslb): '<S94>/CANReceive' */
  ec_buffer_init(1,18,0,647);

  /* Start for S-Function (ec5744_canreceiveslb): '<S95>/CANReceive' */
  ec_buffer_init(1,27,0,523);

  /* Start for S-Function (ec5744_canreceiveslb): '<S96>/CANReceive' */
  ec_buffer_init(1,29,0,776);

  /* Start for S-Function (ec5744_canreceiveslb): '<S97>/CANReceive' */
  ec_buffer_init(1,28,0,818);

  /* Start for S-Function (ec5744_canreceiveslb): '<S98>/CANReceive' */
  ec_buffer_init(1,30,0,886);

  /* Start for S-Function (ec5744_canreceiveslb): '<S99>/CANReceive' */
  ec_buffer_init(1,31,0,930);

  /* Start for S-Function (ec5744_canreceiveslb): '<S100>/CANReceive' */
  ec_buffer_init(1,32,0,1383);

  /* Start for S-Function (ec5744_canreceiveslb): '<S101>/CANReceive' */
  ec_buffer_init(1,33,0,1280);

  /* Start for S-Function (ec5744_canreceiveslb): '<S102>/CANReceive' */
  ec_buffer_init(1,36,0,878);

  /* Start for S-Function (ec5744_canreceiveslb): '<S103>/CANReceive' */
  ec_buffer_init(1,19,0,264);

  /* Start for S-Function (ec5744_canreceiveslb): '<S104>/CANReceive' */
  ec_buffer_init(1,20,0,952);

  /* Start for S-Function (ec5744_canreceiveslb): '<S105>/CANReceive' */
  ec_buffer_init(1,21,0,5);

  /* Start for S-Function (ec5744_canreceiveslb): '<S106>/CANReceive' */
  ec_buffer_init(1,22,0,646);

  /* End of Start for SubSystem: '<S2>/Input' */

  /* Start for Atomic SubSystem: '<S2>/APP' */
  /* Start for Constant: '<S52>/Constant' */
  Server_CommunicationStatus = 1.0;

  /* End of Start for SubSystem: '<S2>/APP' */
  /* Start for S-Function (ec5744_cantransmitslb): '<S696>/CANTransmit' */
  ec_buffer_init(0,8,1,1297U);

  /* Start for S-Function (ec5744_cantransmitslb): '<S701>/CANTransmit' */
  ec_buffer_init(0,11,0,1537U);

  /* Start for S-Function (ec5744_cantransmitslb): '<S743>/CANTransmit' */
  ec_buffer_init(1,13,0,653U);

  /* Start for S-Function (ec5744_cantransmitslb): '<S744>/CANTransmit' */
  ec_buffer_init(1,8,0,740U);

  /* Start for S-Function (ec5744_cantransmitslb): '<S745>/CANTransmit' */
  ec_buffer_init(1,9,0,741U);

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

/* File trailer for ECUCoder generated file VCU_CS75_12_27_test.c.
 *
 * [EOF]
 */
