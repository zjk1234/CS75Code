/*
 * Code generated for Simulink model VCU_CS75_10_9_SteeringTorque.
 *
 * FILE    : VCU_CS75_10_9_SteeringTorque.c
 *
 * VERSION : 1.2714
 *
 * DATE    : Wed Dec 16 11:38:52 2020
 *
 * Copyright 2011-2017 ECUCoder. All Rights Reserved.
 */

#include "VCU_CS75_10_9_SteeringTorque.h"
#include "VCU_CS75_10_9_SteeringTorque_private.h"

/* #include "myinclude.h" */

/* Named constants for Chart: '<S29>/Chart' */
#define VCU_CS75_10_9_S_IN_System_State ((uint8_T)1U)
#define VCU_CS75_10_9_St_IN_AutoDriving ((uint8_T)1U)
#define VCU_CS75_10_9_Steer_IN_TakeOver ((uint8_T)4U)
#define VCU_CS75_10_9_Steering_IN_Error ((uint8_T)2U)
#define VCU_CS75__IN_INIT_ManualDriving ((uint8_T)3U)

/* Exported block parameters */
real_T LDW = 0.0;                      /* Variable: LDW
                                        * Referenced by: '<S30>/ECCalVar'
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
real_T ErrorSum;
real_T LAS_LDWStatus;
real_T LAS_LDWVibrationWarning;
real_T LAS_LKSStatus;
real_T LAS_RollingCounter;
real_T LAS_SteeringTorque;
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
B_VCU_CS75_10_9_SteeringTorqu_T VCU_CS75_10_9_SteeringTorque_B;

/* Block states (auto storage) */
DW_VCU_CS75_10_9_SteeringTorq_T VCU_CS75_10_9_SteeringTorque_DW;

/* Real-time model */
RT_MODEL_VCU_CS75_10_9_Steeri_T VCU_CS75_10_9_SteeringTorque_M_;
RT_MODEL_VCU_CS75_10_9_Steeri_T *const VCU_CS75_10_9_SteeringTorque_M =
  &VCU_CS75_10_9_SteeringTorque_M_;
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
      VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3= 256;
      VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5= 8;
      VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2= ec_can_receive(2,0,
        CAN2BUF0RX);
      VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4[0]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4[1]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4[2]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4[3]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4[4]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4[5]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4[6]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4[7]= CAN2BUF0RX[can2buf0looprx];
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
void VCU_CS75_10_9_SteeringTorque_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(VCU_CS75_10_9_SteeringTorque_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(VCU_CS75_10_9_SteeringTorque_M, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(VCU_CS75_10_9_SteeringTorque_M, 3));
  eventFlags[4] = ((boolean_T)rtmStepTask(VCU_CS75_10_9_SteeringTorque_M, 4));
  eventFlags[5] = ((boolean_T)rtmStepTask(VCU_CS75_10_9_SteeringTorque_M, 5));
  eventFlags[6] = ((boolean_T)rtmStepTask(VCU_CS75_10_9_SteeringTorque_M, 6));
  eventFlags[7] = ((boolean_T)rtmStepTask(VCU_CS75_10_9_SteeringTorque_M, 7));
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
  (VCU_CS75_10_9_SteeringTorque_M->Timing.TaskCounters.TID[1])++;
  if ((VCU_CS75_10_9_SteeringTorque_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.001s, 0.0s] */
    VCU_CS75_10_9_SteeringTorque_M->Timing.TaskCounters.TID[1] = 0;
  }

  (VCU_CS75_10_9_SteeringTorque_M->Timing.TaskCounters.TID[2])++;
  if ((VCU_CS75_10_9_SteeringTorque_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.005s, 0.0s] */
    VCU_CS75_10_9_SteeringTorque_M->Timing.TaskCounters.TID[2] = 0;
  }

  (VCU_CS75_10_9_SteeringTorque_M->Timing.TaskCounters.TID[3])++;
  if ((VCU_CS75_10_9_SteeringTorque_M->Timing.TaskCounters.TID[3]) > 19) {/* Sample time: [0.01s, 0.0s] */
    VCU_CS75_10_9_SteeringTorque_M->Timing.TaskCounters.TID[3] = 0;
  }

  (VCU_CS75_10_9_SteeringTorque_M->Timing.TaskCounters.TID[4])++;
  if ((VCU_CS75_10_9_SteeringTorque_M->Timing.TaskCounters.TID[4]) > 39) {/* Sample time: [0.02s, 0.0s] */
    VCU_CS75_10_9_SteeringTorque_M->Timing.TaskCounters.TID[4] = 0;
  }

  (VCU_CS75_10_9_SteeringTorque_M->Timing.TaskCounters.TID[5])++;
  if ((VCU_CS75_10_9_SteeringTorque_M->Timing.TaskCounters.TID[5]) > 99) {/* Sample time: [0.05s, 0.0s] */
    VCU_CS75_10_9_SteeringTorque_M->Timing.TaskCounters.TID[5] = 0;
  }

  (VCU_CS75_10_9_SteeringTorque_M->Timing.TaskCounters.TID[6])++;
  if ((VCU_CS75_10_9_SteeringTorque_M->Timing.TaskCounters.TID[6]) > 199) {/* Sample time: [0.1s, 0.0s] */
    VCU_CS75_10_9_SteeringTorque_M->Timing.TaskCounters.TID[6] = 0;
  }

  (VCU_CS75_10_9_SteeringTorque_M->Timing.TaskCounters.TID[7])++;
  if ((VCU_CS75_10_9_SteeringTorque_M->Timing.TaskCounters.TID[7]) > 999) {/* Sample time: [0.5s, 0.0s] */
    VCU_CS75_10_9_SteeringTorque_M->Timing.TaskCounters.TID[7] = 0;
  }
}

/*
 * Output and update for atomic system:
 *    '<S30>/MATLAB Function2'
 *    '<S32>/MATLAB Function7'
 *    '<S33>/MATLAB Function7'
 */
void VCU_CS75_10_MATLABFunction2(real_T rtu_u, B_MATLABFunction2_VCU_CS75_10_T
  *localB)
{
  /* MATLAB Function '����CS75���̳���20msһ��/APP/Controller/Accesories/MATLAB Function2': '<S36>:1' */
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
void VCU_CS75_10_9_SteeringTorque_step0(void) /* Sample time: [0.0005s, 0.0s] */
{
  {                                    /* Sample time: [0.0005s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void VCU_CS75_10_9_SteeringTorque_step1(void) /* Sample time: [0.001s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S6>/Function-Call Generator' incorporates:
   *  SubSystem: '<S6>/CCPBackground'
   */

  /* S-Function (ec5744_ccpslb): '<S21>/CCPBackground' */
  ccpBackground();
}

/* Model step function for TID2 */
void VCU_CS75_10_9_SteeringTorque_step2(void) /* Sample time: [0.005s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S4>/5ms' incorporates:
   *  SubSystem: '<S4>/daq5ms'
   */

  /* S-Function (ec5744_ccpslb1): '<S19>/CCPDAQ' */
  ccpDaq(0);
}

/* Model step function for TID3 */
void VCU_CS75_10_9_SteeringTorque_step3(void) /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S4>/10ms' incorporates:
   *  SubSystem: '<S4>/daq10ms'
   */

  /* S-Function (ec5744_ccpslb1): '<S16>/CCPDAQ' */
  ccpDaq(1);
}

/* Model step function for TID4 */
void VCU_CS75_10_9_SteeringTorque_step4(void) /* Sample time: [0.02s, 0.0s] */
{
  boolean_T out;
  uint32_T rtb_LAS_SteeringTorqueReq_L;
  uint32_T rtb_ACC_RollingCounter_L;
  uint8_T rtb_ACC_CDDAxEnable_Convert;
  uint32_T rtb_ACC_RollingCounter_Convert1;
  uint8_T rtb_ACC_ACCTargetAcceleration_C;
  uint8_T rtb_ACC_AccTrqReqEnable_Convert;
  uint8_T rtb_ACC_AccTorqueReqBitCov;
  real_T rtb_P6_Value;
  real_T rtb_Memory2;
  real_T rtb_APP_Input_idx_99;
  real_T rtb_APP_Input_idx_2;
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
  real_T rtb_APP_Input_idx_79;
  real_T rtb_APP_Input_idx_29;

  /* S-Function (fcncallgen): '<Root>/20ms' incorporates:
   *  SubSystem: '<Root>/����CS75���̳���20msһ��'
   */
  /* Outputs for Atomic SubSystem: '<S2>/Input' */

  /* S-Function (ec5744_swislbu3): '<S59>/SwitchInput' */

  /* Read the the value of the specified switch input */
  VCU_CS75_10_9_SteeringTorque_B.P6_Value_h= ec_gpio_read(92);

  /* DataTypeConversion: '<S59>/Data Type Conversion' */
  rtb_P6_Value = (real_T)VCU_CS75_10_9_SteeringTorque_B.P6_Value_h;

  /* MATLAB Function: '<S59>/MATLAB Function' */
  /* MATLAB Function '����CS75���̳���20msһ��/Input/ADC_Input/MATLAB Function': '<S64>:1' */
  if (rtb_P6_Value == 1.0) {
    /* '<S64>:1:2' */
    /* '<S64>:1:3' */
    P6_Value = 0.0;
  } else {
    /* '<S64>:1:5' */
    P6_Value = 1.0;
  }

  /* End of MATLAB Function: '<S59>/MATLAB Function' */

  /* S-Function (ec5744_canreceiveslb): '<S65>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF0RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can0buf0looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_o= 529;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_o= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_a4= ec_can_receive(0,0,
      CAN0BUF0RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_d[0]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_d[1]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_d[2]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_d[3]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_d[4]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_d[5]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_d[6]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_d[7]= CAN0BUF0RX[can0buf0looprx];
    can0buf0looprx++;
  }

  /* Call the system: <S65>/ReceiveMessages */

  /* Output and update for function-call system: '<S65>/ReceiveMessages' */
  {
    real_T rtb_target_steering_sat;
    int32_T rtb_target_steering_L;
    real32_T rtb_throttlevbrake_position_sat;

    /* Outputs for Enabled SubSystem: '<S66>/Subsystem' incorporates:
     *  EnablePort: '<S67>/Enable'
     */
    if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_a4 > 0) {
      /* Product: '<S69>/Vxinput8_P' incorporates:
       *  Constant: '<S69>/Vxinput8_C'
       */
      rtb_target_steering_sat = (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_d[7] * 256.0;

      /* Sum: '<S69>/Vxinput8_Ad' */
      rtb_target_steering_sat += (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_d[6];

      /* DataTypeConversion: '<S69>/Vx_Convert' */
      rtb_target_steering_L = (int32_T)rtb_target_steering_sat;

      /* DataTypeConversion: '<S69>/Vxcv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* Gain: '<S69>/Vx_F' */
      rtb_throttlevbrake_position_sat *= 0.00610360876F;

      /* Sum: '<S69>/Vx_Ad' incorporates:
       *  Constant: '<S69>/Vx_O'
       */
      rtb_throttlevbrake_position_sat += -200.0F;

      /* Saturate: '<S69>/Vx_sat' */
      if (rtb_throttlevbrake_position_sat > 200.0F) {
        rtb_throttlevbrake_position_sat = 200.0F;
      }

      /* End of Saturate: '<S69>/Vx_sat' */

      /* DataStoreWrite: '<S67>/Data Store Write' */
      Vx_out = rtb_throttlevbrake_position_sat;

      /* DataTypeConversion: '<S69>/mission_Convert' */
      rtb_target_steering_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_d[5];

      /* S-Function (sfix_bitop): '<S69>/mission_L' */
      rtb_target_steering_L &= 240U;

      /* ArithShift: '<S69>/mission_S' */
      rtb_target_steering_L = (int32_T)((uint32_T)rtb_target_steering_L >> 4);

      /* DataTypeConversion: '<S69>/missioncv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* Saturate: '<S69>/mission_sat' */
      if (rtb_throttlevbrake_position_sat > 7.0F) {
        rtb_throttlevbrake_position_sat = 7.0F;
      }

      /* End of Saturate: '<S69>/mission_sat' */

      /* DataStoreWrite: '<S67>/Data Store Write1' */
      mission_out = rtb_throttlevbrake_position_sat;

      /* DataTypeConversion: '<S69>/SCS_Convert' */
      rtb_target_steering_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_d[5];

      /* S-Function (sfix_bitop): '<S69>/SCS_L' */
      rtb_target_steering_L &= 8U;

      /* ArithShift: '<S69>/SCS_S' */
      rtb_target_steering_L = (int32_T)((uint32_T)rtb_target_steering_L >> 3);

      /* DataTypeConversion: '<S69>/SCScv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* DataStoreWrite: '<S67>/Data Store Write2' */
      SCS_out = rtb_throttlevbrake_position_sat;

      /* DataTypeConversion: '<S69>/finish_Convert' */
      rtb_target_steering_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_d[5];

      /* S-Function (sfix_bitop): '<S69>/finish_L' */
      rtb_target_steering_L &= 4U;

      /* ArithShift: '<S69>/finish_S' */
      rtb_target_steering_L = (int32_T)((uint32_T)rtb_target_steering_L >> 2);

      /* DataTypeConversion: '<S69>/finishcv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* DataStoreWrite: '<S67>/Data Store Write3' */
      finish_out = rtb_throttlevbrake_position_sat;

      /* DataTypeConversion: '<S69>/tap_Convert' */
      rtb_target_steering_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_d[5];

      /* S-Function (sfix_bitop): '<S69>/tap_L' */
      rtb_target_steering_L &= 3U;

      /* DataTypeConversion: '<S69>/tapcv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* DataStoreWrite: '<S67>/Data Store Write4' */
      tap_out = rtb_throttlevbrake_position_sat;

      /* DataTypeConversion: '<S69>/cones_count_all_Convert' */
      rtb_target_steering_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_d[4];

      /* DataTypeConversion: '<S69>/cones_count_allcv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* DataStoreWrite: '<S67>/Data Store Write5' */
      cones_count_all_out = rtb_throttlevbrake_position_sat;

      /* DataTypeConversion: '<S69>/cones_count_actual_Convert' */
      rtb_target_steering_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_d[3];

      /* DataTypeConversion: '<S69>/cones_count_actualcv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* DataStoreWrite: '<S67>/Data Store Write6' */
      cones_count_actual_out = rtb_throttlevbrake_position_sat;

      /* Product: '<S69>/throttlevbrake_positioninput3_P' incorporates:
       *  Constant: '<S69>/throttlevbrake_positioninput3_C'
       */
      rtb_target_steering_sat = (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_d[2] * 256.0;

      /* Sum: '<S69>/throttlevbrake_positioninput3_Ad' */
      rtb_target_steering_sat += (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_d[1];

      /* DataTypeConversion: '<S69>/throttlevbrake_position_Convert' */
      rtb_target_steering_L = (int32_T)rtb_target_steering_sat;

      /* S-Function (sfix_bitop): '<S69>/throttlevbrake_position_L' */
      rtb_target_steering_L &= 65520U;

      /* ArithShift: '<S69>/throttlevbrake_position_S' */
      rtb_target_steering_L = (int32_T)((uint32_T)rtb_target_steering_L >> 4);

      /* DataTypeConversion: '<S69>/throttlevbrake_positioncv' */
      rtb_throttlevbrake_position_sat = (real32_T)rtb_target_steering_L;

      /* Gain: '<S69>/throttlevbrake_position_F' */
      rtb_throttlevbrake_position_sat *= 0.0488400497F;

      /* Sum: '<S69>/throttlevbrake_position_Ad' incorporates:
       *  Constant: '<S69>/throttlevbrake_position_O'
       */
      rtb_throttlevbrake_position_sat += -100.0F;

      /* Saturate: '<S69>/throttlevbrake_position_sat' */
      if (rtb_throttlevbrake_position_sat > 100.0F) {
        rtb_throttlevbrake_position_sat = 100.0F;
      }

      /* End of Saturate: '<S69>/throttlevbrake_position_sat' */

      /* DataTypeConversion: '<S67>/Data Type Conversion' */
      rtb_target_steering_sat = rtb_throttlevbrake_position_sat;

      /* MATLAB Function: '<S67>/MATLAB Function1' */
      /* MATLAB Function '����CS75���̳���20msһ��/Input/CAN0_Rx/a1_211/ReceiveMessages/Subsystem/MATLAB Function1': '<S68>:1' */
      /* '<S68>:1:2' */
      if (rtb_target_steering_sat < 0.0) {
        /* '<S68>:1:3' */
        /* '<S68>:1:4' */
        rtb_target_steering_sat /= 20.0;
      }

      /* End of MATLAB Function: '<S67>/MATLAB Function1' */

      /* SignalConversion: '<S67>/Signal Conversion' incorporates:
       *  Constant: '<S67>/Constant2'
       */
      VCU_CS75_10_9_SteeringTorque_B.AutoDrivingReady = 0.0;

      /* SignalConversion: '<S67>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.RemoteAcclPosition =
        rtb_target_steering_sat;

      /* Product: '<S69>/target_steeringinput2_P' incorporates:
       *  Constant: '<S69>/target_steeringinput2_C'
       */
      rtb_target_steering_sat = (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_d[1] * 256.0;

      /* Sum: '<S69>/target_steeringinput2_Ad' */
      rtb_target_steering_sat += (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_d[0];

      /* DataTypeConversion: '<S69>/target_steering_Convert' */
      rtb_target_steering_L = (int32_T)rtb_target_steering_sat;

      /* S-Function (sfix_bitop): '<S69>/target_steering_L' */
      rtb_target_steering_L &= 4095U;

      /* DataTypeConversion: '<S69>/target_steeringcv' */
      rtb_target_steering_sat = rtb_target_steering_L;

      /* Gain: '<S69>/target_steering_F' */
      rtb_target_steering_sat *= 0.0488400488400488;

      /* Sum: '<S69>/target_steering_Ad' incorporates:
       *  Constant: '<S69>/target_steering_O'
       */
      rtb_target_steering_sat += -100.0;

      /* Saturate: '<S69>/target_steering_sat' */
      if (rtb_target_steering_sat > 99.9999999999998) {
        rtb_target_steering_sat = 99.9999999999998;
      }

      /* End of Saturate: '<S69>/target_steering_sat' */

      /* SignalConversion: '<S67>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.LaterlAngleCommand =
        rtb_target_steering_sat;

      /* SignalConversion: '<S67>/Signal Conversion' incorporates:
       *  Constant: '<S67>/Constant'
       */
      VCU_CS75_10_9_SteeringTorque_B.A1_Message_Counter = 0.0;

      /* SignalConversion: '<S67>/Signal Conversion' incorporates:
       *  Constant: '<S67>/Constant1'
       */
      VCU_CS75_10_9_SteeringTorque_B.A1_Checksum = 0.0;
    }

    /* End of Outputs for SubSystem: '<S66>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S79>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF23RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf23looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_ik= 648;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_ox= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_i= ec_can_receive(1,23,
      CAN1BUF23RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[0]=
      CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[1]=
      CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[2]=
      CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[3]=
      CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[4]=
      CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[5]=
      CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[6]=
      CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[7]=
      CAN1BUF23RX[can1buf23looprx];
    can1buf23looprx++;
  }

  /* Call the system: <S79>/ReceiveMessages */

  /* Output and update for function-call system: '<S79>/ReceiveMessages' */
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

    /* Outputs for Enabled SubSystem: '<S106>/Subsystem' incorporates:
     *  EnablePort: '<S107>/Enable'
     */
    if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_i > 0) {
      /* DataTypeConversion: '<S108>/BCM_BuzzerWarningMode_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[7];

      /* S-Function (sfix_bitop): '<S108>/BCM_BuzzerWarningMode_L' */
      rtb_BCM_emergencylightstatus_L &= 31U;

      /* Sum: '<S108>/BCM_BuzzerWarningMode_Ad' */
      rtb_BCM_BuzzerWarningMode_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S108>/BCM_BuzzerWarningMode_sat' */
      u0 = rtb_BCM_BuzzerWarningMode_sat;
      rtb_BCM_BuzzerWarningMode_sat = (int32_T)u0;

      /* DataTypeConversion: '<S108>/BCM_DriverDoorLockStatus_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[5];

      /* S-Function (sfix_bitop): '<S108>/BCM_DriverDoorLockStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 3U;

      /* Sum: '<S108>/BCM_DriverDoorLockStatus_Ad' */
      rtb_BCM_DriverDoorLockStatus_sa = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S108>/BCM_DriverDoorLockStatus_sat' */
      u0 = rtb_BCM_DriverDoorLockStatus_sa;
      rtb_BCM_DriverDoorLockStatus_sa = (int32_T)u0;

      /* DataTypeConversion: '<S108>/BCM_DriverDoorStatus_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[2];

      /* S-Function (sfix_bitop): '<S108>/BCM_DriverDoorStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 128U;

      /* ArithShift: '<S108>/BCM_DriverDoorStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 7);

      /* Sum: '<S108>/BCM_DriverDoorStatus_Ad' */
      rtb_BCM_DriverDoorStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S108>/BCM_DriverDoorStatus_sat' */
      u0 = rtb_BCM_DriverDoorStatus_sat;
      rtb_BCM_DriverDoorStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S108>/BCM_FrontWashStatus_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[1];

      /* S-Function (sfix_bitop): '<S108>/BCM_FrontWashStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 3U;

      /* Sum: '<S108>/BCM_FrontWashStatus_Ad' */
      rtb_BCM_FrontWashStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S108>/BCM_FrontWashStatus_sat' */
      u0 = rtb_BCM_FrontWashStatus_sat;
      rtb_BCM_FrontWashStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S108>/BCM_FrontWiperStatus_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[5];

      /* S-Function (sfix_bitop): '<S108>/BCM_FrontWiperStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 192U;

      /* ArithShift: '<S108>/BCM_FrontWiperStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 6);

      /* Sum: '<S108>/BCM_FrontWiperStatus_Ad' */
      rtb_BCM_FrontWiperStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S108>/BCM_FrontWiperStatus_sat' */
      u0 = rtb_BCM_FrontWiperStatus_sat;
      rtb_BCM_FrontWiperStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S108>/BCM_HoodStatus_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[2];

      /* S-Function (sfix_bitop): '<S108>/BCM_HoodStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 4U;

      /* ArithShift: '<S108>/BCM_HoodStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 2);

      /* Sum: '<S108>/BCM_HoodStatus_Ad' */
      rtb_BCM_HoodStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S108>/BCM_HoodStatus_sat' */
      u0 = rtb_BCM_HoodStatus_sat;
      rtb_BCM_HoodStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S108>/BCM_LatchOverheatProtect_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[7];

      /* S-Function (sfix_bitop): '<S108>/BCM_LatchOverheatProtect_L' */
      rtb_BCM_emergencylightstatus_L &= 64U;

      /* ArithShift: '<S108>/BCM_LatchOverheatProtect_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 6);

      /* Sum: '<S108>/BCM_LatchOverheatProtect_Ad' */
      rtb_BCM_LatchOverheatProtect_sa = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S108>/BCM_LatchOverheatProtect_sat' */
      u0 = rtb_BCM_LatchOverheatProtect_sa;
      rtb_BCM_LatchOverheatProtect_sa = (int32_T)u0;

      /* DataTypeConversion: '<S108>/BCM_LeftRearDoorStatus_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[2];

      /* S-Function (sfix_bitop): '<S108>/BCM_LeftRearDoorStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 32U;

      /* ArithShift: '<S108>/BCM_LeftRearDoorStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 5);

      /* Sum: '<S108>/BCM_LeftRearDoorStatus_Ad' */
      rtb_BCM_LeftRearDoorStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S108>/BCM_LeftRearDoorStatus_sat' */
      u0 = rtb_BCM_LeftRearDoorStatus_sat;
      rtb_BCM_LeftRearDoorStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S108>/BCM_PassengerDoorLockStatus_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[4];

      /* S-Function (sfix_bitop): '<S108>/BCM_PassengerDoorLockStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 12U;

      /* ArithShift: '<S108>/BCM_PassengerDoorLockStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 2);

      /* Sum: '<S108>/BCM_PassengerDoorLockStatus_Ad' */
      rtb_BCM_PassengerDoorLockStatus = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S108>/BCM_PassengerDoorLockStatus_sat' */
      u0 = rtb_BCM_PassengerDoorLockStatus;
      rtb_BCM_PassengerDoorLockStatus = (int32_T)u0;

      /* DataTypeConversion: '<S108>/BCM_PassengerDoorStatus_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[2];

      /* S-Function (sfix_bitop): '<S108>/BCM_PassengerDoorStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 64U;

      /* ArithShift: '<S108>/BCM_PassengerDoorStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 6);

      /* Sum: '<S108>/BCM_PassengerDoorStatus_Ad' */
      rtb_BCM_PassengerDoorStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S108>/BCM_PassengerDoorStatus_sat' */
      u0 = rtb_BCM_PassengerDoorStatus_sat;
      rtb_BCM_PassengerDoorStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S108>/BCM_PowerStatusFeedback_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[5];

      /* S-Function (sfix_bitop): '<S108>/BCM_PowerStatusFeedback_L' */
      rtb_BCM_emergencylightstatus_L &= 12U;

      /* ArithShift: '<S108>/BCM_PowerStatusFeedback_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 2);

      /* Sum: '<S108>/BCM_PowerStatusFeedback_Ad' */
      rtb_BCM_PowerStatusFeedback_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S108>/BCM_PowerStatusFeedback_sat' */
      u0 = rtb_BCM_PowerStatusFeedback_sat;
      rtb_BCM_PowerStatusFeedback_sat = (int32_T)u0;

      /* DataTypeConversion: '<S108>/BCM_RearWiperStatus_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[5];

      /* S-Function (sfix_bitop): '<S108>/BCM_RearWiperStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 16U;

      /* ArithShift: '<S108>/BCM_RearWiperStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 4);

      /* Sum: '<S108>/BCM_RearWiperStatus_Ad' */
      rtb_BCM_RearWiperStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S108>/BCM_RearWiperStatus_sat' */
      u0 = rtb_BCM_RearWiperStatus_sat;
      rtb_BCM_RearWiperStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S108>/BCM_ReversePosition_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[6];

      /* S-Function (sfix_bitop): '<S108>/BCM_ReversePosition_L' */
      rtb_BCM_emergencylightstatus_L &= 1U;

      /* Sum: '<S108>/BCM_ReversePosition_Ad' */
      rtb_BCM_ReversePosition_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S108>/BCM_ReversePosition_sat' */
      u0 = rtb_BCM_ReversePosition_sat;
      rtb_BCM_ReversePosition_sat = (int32_T)u0;

      /* DataTypeConversion: '<S108>/BCM_RightRearDoorStatus_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[2];

      /* S-Function (sfix_bitop): '<S108>/BCM_RightRearDoorStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 16U;

      /* ArithShift: '<S108>/BCM_RightRearDoorStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 4);

      /* Sum: '<S108>/BCM_RightRearDoorStatus_Ad' */
      rtb_BCM_RightRearDoorStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S108>/BCM_RightRearDoorStatus_sat' */
      u0 = rtb_BCM_RightRearDoorStatus_sat;
      rtb_BCM_RightRearDoorStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S108>/BCM_SystemFailureFlag_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[7];

      /* S-Function (sfix_bitop): '<S108>/BCM_SystemFailureFlag_L' */
      rtb_BCM_emergencylightstatus_L &= 32U;

      /* ArithShift: '<S108>/BCM_SystemFailureFlag_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 5);

      /* Sum: '<S108>/BCM_SystemFailureFlag_Ad' */
      rtb_BCM_SystemFailureFlag_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S108>/BCM_SystemFailureFlag_sat' */
      u0 = rtb_BCM_SystemFailureFlag_sat;
      rtb_BCM_SystemFailureFlag_sat = (int32_T)u0;

      /* DataTypeConversion: '<S108>/BCM_TrunkDoorStatus_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[2];

      /* S-Function (sfix_bitop): '<S108>/BCM_TrunkDoorStatus_L' */
      rtb_BCM_emergencylightstatus_L &= 8U;

      /* ArithShift: '<S108>/BCM_TrunkDoorStatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 3);

      /* Sum: '<S108>/BCM_TrunkDoorStatus_Ad' */
      rtb_BCM_TrunkDoorStatus_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S108>/BCM_TrunkDoorStatus_sat' */
      u0 = rtb_BCM_TrunkDoorStatus_sat;
      rtb_BCM_TrunkDoorStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S108>/BCM_TurnIndicatorLeft_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[1];

      /* S-Function (sfix_bitop): '<S108>/BCM_TurnIndicatorLeft_L' */
      rtb_BCM_emergencylightstatus_L &= 192U;

      /* ArithShift: '<S108>/BCM_TurnIndicatorLeft_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 6);

      /* Sum: '<S108>/BCM_TurnIndicatorLeft_Ad' */
      rtb_BCM_TurnIndicatorLeft_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S108>/BCM_TurnIndicatorLeft_sat' */
      u0 = rtb_BCM_TurnIndicatorLeft_sat;
      rtb_BCM_TurnIndicatorLeft_sat = (int32_T)u0;

      /* DataTypeConversion: '<S108>/BCM_TurnIndicatorRight_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[1];

      /* S-Function (sfix_bitop): '<S108>/BCM_TurnIndicatorRight_L' */
      rtb_BCM_emergencylightstatus_L &= 48U;

      /* ArithShift: '<S108>/BCM_TurnIndicatorRight_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 4);

      /* Sum: '<S108>/BCM_TurnIndicatorRight_Ad' */
      rtb_BCM_TurnIndicatorRight_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S108>/BCM_TurnIndicatorRight_sat' */
      u0 = rtb_BCM_TurnIndicatorRight_sat;
      rtb_BCM_TurnIndicatorRight_sat = (int32_T)u0;

      /* DataTypeConversion: '<S108>/BCM_TurnLightSwitchSts_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[6];

      /* S-Function (sfix_bitop): '<S108>/BCM_TurnLightSwitchSts_L' */
      rtb_BCM_emergencylightstatus_L &= 12U;

      /* ArithShift: '<S108>/BCM_TurnLightSwitchSts_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 2);

      /* Sum: '<S108>/BCM_TurnLightSwitchSts_Ad' */
      rtb_BCM_TurnLightSwitchSts_sat = rtb_BCM_emergencylightstatus_L;

      /* Saturate: '<S108>/BCM_TurnLightSwitchSts_sat' */
      u0 = rtb_BCM_TurnLightSwitchSts_sat;
      rtb_BCM_TurnLightSwitchSts_sat = (int32_T)u0;

      /* DataTypeConversion: '<S108>/BCM_emergencylightstatus_Convert' */
      rtb_BCM_emergencylightstatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_g[4];

      /* S-Function (sfix_bitop): '<S108>/BCM_emergencylightstatus_L' */
      rtb_BCM_emergencylightstatus_L &= 48U;

      /* ArithShift: '<S108>/BCM_emergencylightstatus_S' */
      rtb_BCM_emergencylightstatus_L = (int32_T)((uint32_T)
        rtb_BCM_emergencylightstatus_L >> 4);

      /* Saturate: '<S108>/BCM_emergencylightstatus_sat' */
      u0 = rtb_BCM_emergencylightstatus_L;
      rtb_BCM_emergencylightstatus_L = (int32_T)u0;

      /* SignalConversion: '<S107>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_FrontWashStatus =
        rtb_BCM_FrontWashStatus_sat;

      /* SignalConversion: '<S107>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_PassengerDoorLockStatus =
        rtb_BCM_PassengerDoorLockStatus;

      /* SignalConversion: '<S107>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_emergencylightstatus =
        rtb_BCM_emergencylightstatus_L;

      /* SignalConversion: '<S107>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_DriverDoorLockStatus =
        rtb_BCM_DriverDoorLockStatus_sa;

      /* SignalConversion: '<S107>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_PowerStatusFeedback =
        rtb_BCM_PowerStatusFeedback_sat;

      /* SignalConversion: '<S107>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_RearWiperStatus =
        rtb_BCM_RearWiperStatus_sat;

      /* SignalConversion: '<S107>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_FrontWiperStatus =
        rtb_BCM_FrontWiperStatus_sat;

      /* SignalConversion: '<S107>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_ReversePosition =
        rtb_BCM_ReversePosition_sat;

      /* SignalConversion: '<S107>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_TurnLightSwitchSts =
        rtb_BCM_TurnLightSwitchSts_sat;

      /* SignalConversion: '<S107>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_BuzzerWarningMode =
        rtb_BCM_BuzzerWarningMode_sat;

      /* SignalConversion: '<S107>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_SystemFailureFlag =
        rtb_BCM_SystemFailureFlag_sat;

      /* SignalConversion: '<S107>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_TurnIndicatorRight =
        rtb_BCM_TurnIndicatorRight_sat;

      /* SignalConversion: '<S107>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_LatchOverheatProtect =
        rtb_BCM_LatchOverheatProtect_sa;

      /* SignalConversion: '<S107>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_TurnIndicatorLeft =
        rtb_BCM_TurnIndicatorLeft_sat;

      /* SignalConversion: '<S107>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_HoodStatus = rtb_BCM_HoodStatus_sat;

      /* SignalConversion: '<S107>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_TrunkDoorStatus =
        rtb_BCM_TrunkDoorStatus_sat;

      /* SignalConversion: '<S107>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_RightRearDoorStatus =
        rtb_BCM_RightRearDoorStatus_sat;

      /* SignalConversion: '<S107>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_LeftRearDoorStatus =
        rtb_BCM_LeftRearDoorStatus_sat;

      /* SignalConversion: '<S107>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_PassengerDoorStatus =
        rtb_BCM_PassengerDoorStatus_sat;

      /* SignalConversion: '<S107>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_DriverDoorStatus =
        rtb_BCM_DriverDoorStatus_sat;
    }

    /* End of Outputs for SubSystem: '<S106>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S80>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF24RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf24looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_oa= 808;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_k= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_b= ec_can_receive(1,24,
      CAN1BUF24RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_f[0]=
      CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_f[1]=
      CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_f[2]=
      CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_f[3]=
      CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_f[4]=
      CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_f[5]=
      CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_f[6]=
      CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_f[7]=
      CAN1BUF24RX[can1buf24looprx];
    can1buf24looprx++;
  }

  /* Call the system: <S80>/ReceiveMessages */

  /* Output and update for function-call system: '<S80>/ReceiveMessages' */
  {
    int32_T rtb_LCM_ReverseLightSts_L;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S129>/Subsystem' incorporates:
     *  EnablePort: '<S130>/Enable'
     */
    if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_b > 0) {
      /* DataTypeConversion: '<S131>/LCM_LASSwitch_Convert' */
      rtb_LCM_ReverseLightSts_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_f[2];

      /* S-Function (sfix_bitop): '<S131>/LCM_LASSwitch_L' */
      rtb_LCM_ReverseLightSts_L &= 3U;

      /* Saturate: '<S131>/LCM_LASSwitch_sat' */
      u0 = rtb_LCM_ReverseLightSts_L;
      rtb_LCM_ReverseLightSts_L = (int32_T)u0;

      /* SignalConversion: '<S130>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.LCM_DriveMode = 0.0;

      /* SignalConversion: '<S130>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.LCM_DRLSts = 0.0;

      /* SignalConversion: '<S130>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.LCM_LASSwitch = rtb_LCM_ReverseLightSts_L;

      /* SignalConversion: '<S130>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.LCM_RearRightTuningLightFaultSt = 0.0;

      /* SignalConversion: '<S130>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.LCM_RearLeftTuningLightFaultSts = 0.0;

      /* SignalConversion: '<S130>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.LCM_ReverseLightSts = 0.0;
    }

    /* End of Outputs for SubSystem: '<S129>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S81>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF25RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf25looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_g= 840;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_op= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_h= ec_can_receive(1,25,
      CAN1BUF25RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_k[0]=
      CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_k[1]=
      CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_k[2]=
      CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_k[3]=
      CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_k[4]=
      CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_k[5]=
      CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_k[6]=
      CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_k[7]=
      CAN1BUF25RX[can1buf25looprx];
    can1buf25looprx++;
  }

  /* Call the system: <S81>/ReceiveMessages */

  /* Output and update for function-call system: '<S81>/ReceiveMessages' */
  {
    int32_T rtb_BCM_UnlockSignal_L;
    int32_T rtb_BCM_DriveMode_sat;
    int32_T rtb_BCM_LockSignal_sat;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S138>/Subsystem' incorporates:
     *  EnablePort: '<S139>/Enable'
     */
    if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_h > 0) {
      /* DataTypeConversion: '<S140>/BCM_DriveMode_Convert' */
      rtb_BCM_UnlockSignal_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_k[5];

      /* S-Function (sfix_bitop): '<S140>/BCM_DriveMode_L' */
      rtb_BCM_UnlockSignal_L &= 6U;

      /* ArithShift: '<S140>/BCM_DriveMode_S' */
      rtb_BCM_UnlockSignal_L = (int32_T)((uint32_T)rtb_BCM_UnlockSignal_L >> 1);

      /* Sum: '<S140>/BCM_DriveMode_Ad' */
      rtb_BCM_DriveMode_sat = rtb_BCM_UnlockSignal_L;

      /* Saturate: '<S140>/BCM_DriveMode_sat' */
      u0 = rtb_BCM_DriveMode_sat;
      rtb_BCM_DriveMode_sat = (int32_T)u0;

      /* DataTypeConversion: '<S140>/BCM_LockSignal_Convert' */
      rtb_BCM_UnlockSignal_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_k[5];

      /* S-Function (sfix_bitop): '<S140>/BCM_LockSignal_L' */
      rtb_BCM_UnlockSignal_L &= 24U;

      /* ArithShift: '<S140>/BCM_LockSignal_S' */
      rtb_BCM_UnlockSignal_L = (int32_T)((uint32_T)rtb_BCM_UnlockSignal_L >> 3);

      /* Sum: '<S140>/BCM_LockSignal_Ad' */
      rtb_BCM_LockSignal_sat = rtb_BCM_UnlockSignal_L;

      /* Saturate: '<S140>/BCM_LockSignal_sat' */
      u0 = rtb_BCM_LockSignal_sat;
      rtb_BCM_LockSignal_sat = (int32_T)u0;

      /* DataTypeConversion: '<S140>/BCM_UnlockSignal_Convert' */
      rtb_BCM_UnlockSignal_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_k[5];

      /* S-Function (sfix_bitop): '<S140>/BCM_UnlockSignal_L' */
      rtb_BCM_UnlockSignal_L &= 96U;

      /* ArithShift: '<S140>/BCM_UnlockSignal_S' */
      rtb_BCM_UnlockSignal_L = (int32_T)((uint32_T)rtb_BCM_UnlockSignal_L >> 5);

      /* Saturate: '<S140>/BCM_UnlockSignal_sat' */
      u0 = rtb_BCM_UnlockSignal_L;
      rtb_BCM_UnlockSignal_L = (int32_T)u0;

      /* SignalConversion: '<S139>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_DriveMode_f = rtb_BCM_DriveMode_sat;

      /* SignalConversion: '<S139>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_LockSignal = rtb_BCM_LockSignal_sat;

      /* SignalConversion: '<S139>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_UnlockSignal = rtb_BCM_UnlockSignal_L;
    }

    /* End of Outputs for SubSystem: '<S138>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S82>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF26RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf26looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_n= 991;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_p= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_m= ec_can_receive(1,26,
      CAN1BUF26RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_i[0]=
      CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_i[1]=
      CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_i[2]=
      CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_i[3]=
      CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_i[4]=
      CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_i[5]=
      CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_i[6]=
      CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_i[7]=
      CAN1BUF26RX[can1buf26looprx];
    can1buf26looprx++;
  }

  /* Call the system: <S82>/ReceiveMessages */

  /* Output and update for function-call system: '<S82>/ReceiveMessages' */
  {
    int32_T rtb_BCM_RollingCounter_L;
    int32_T rtb_BCM_AmbientLightColorFeedba;
    int32_T rtb_BCM_DriveModeFeedback_sat;
    int32_T rtb_BCM_DriveModeStatus_sat;
    int32_T rtb_BCM_EPSTorqueModeFeedback_s;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S144>/Subsystem' incorporates:
     *  EnablePort: '<S145>/Enable'
     */
    if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_m > 0) {
      /* DataTypeConversion: '<S146>/BCM_AmbientLightColorFeedback_Convert' */
      rtb_BCM_RollingCounter_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_i
        [3];

      /* Sum: '<S146>/BCM_AmbientLightColorFeedback_Ad' */
      rtb_BCM_AmbientLightColorFeedba = rtb_BCM_RollingCounter_L;

      /* Saturate: '<S146>/BCM_AmbientLightColorFeedback_sat' */
      u0 = rtb_BCM_AmbientLightColorFeedba;
      rtb_BCM_AmbientLightColorFeedba = (int32_T)u0;

      /* DataTypeConversion: '<S146>/BCM_DriveModeFeedback_Convert' */
      rtb_BCM_RollingCounter_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_i
        [2];

      /* S-Function (sfix_bitop): '<S146>/BCM_DriveModeFeedback_L' */
      rtb_BCM_RollingCounter_L &= 48U;

      /* ArithShift: '<S146>/BCM_DriveModeFeedback_S' */
      rtb_BCM_RollingCounter_L = (int32_T)((uint32_T)rtb_BCM_RollingCounter_L >>
        4);

      /* Sum: '<S146>/BCM_DriveModeFeedback_Ad' */
      rtb_BCM_DriveModeFeedback_sat = rtb_BCM_RollingCounter_L;

      /* Saturate: '<S146>/BCM_DriveModeFeedback_sat' */
      u0 = rtb_BCM_DriveModeFeedback_sat;
      rtb_BCM_DriveModeFeedback_sat = (int32_T)u0;

      /* DataTypeConversion: '<S146>/BCM_DriveModeStatus_Convert' */
      rtb_BCM_RollingCounter_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_i
        [2];

      /* S-Function (sfix_bitop): '<S146>/BCM_DriveModeStatus_L' */
      rtb_BCM_RollingCounter_L &= 15U;

      /* Sum: '<S146>/BCM_DriveModeStatus_Ad' */
      rtb_BCM_DriveModeStatus_sat = rtb_BCM_RollingCounter_L;

      /* Saturate: '<S146>/BCM_DriveModeStatus_sat' */
      u0 = rtb_BCM_DriveModeStatus_sat;
      rtb_BCM_DriveModeStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S146>/BCM_EPSTorqueModeFeedback_Convert' */
      rtb_BCM_RollingCounter_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_i
        [2];

      /* S-Function (sfix_bitop): '<S146>/BCM_EPSTorqueModeFeedback_L' */
      rtb_BCM_RollingCounter_L &= 192U;

      /* ArithShift: '<S146>/BCM_EPSTorqueModeFeedback_S' */
      rtb_BCM_RollingCounter_L = (int32_T)((uint32_T)rtb_BCM_RollingCounter_L >>
        6);

      /* Sum: '<S146>/BCM_EPSTorqueModeFeedback_Ad' */
      rtb_BCM_EPSTorqueModeFeedback_s = rtb_BCM_RollingCounter_L;

      /* Saturate: '<S146>/BCM_EPSTorqueModeFeedback_sat' */
      u0 = rtb_BCM_EPSTorqueModeFeedback_s;
      rtb_BCM_EPSTorqueModeFeedback_s = (int32_T)u0;

      /* DataTypeConversion: '<S146>/BCM_EPSTorqueMode_Convert' */
      rtb_BCM_RollingCounter_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_i
        [1];

      /* S-Function (sfix_bitop): '<S146>/BCM_EPSTorqueMode_L' */
      rtb_BCM_RollingCounter_L &= 6U;

      /* ArithShift: '<S146>/BCM_EPSTorqueMode_S' */
      rtb_BCM_RollingCounter_L = (int32_T)((uint32_T)rtb_BCM_RollingCounter_L >>
        1);

      /* Saturate: '<S146>/BCM_EPSTorqueMode_sat' */
      u0 = rtb_BCM_RollingCounter_L;
      rtb_BCM_RollingCounter_L = (int32_T)u0;

      /* SignalConversion: '<S145>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_DriveMode = 0.0;

      /* SignalConversion: '<S145>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_EPSTorqueMode =
        rtb_BCM_RollingCounter_L;

      /* SignalConversion: '<S145>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_DriveModeStatus =
        rtb_BCM_DriveModeStatus_sat;

      /* SignalConversion: '<S145>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_DriveModeFeedback =
        rtb_BCM_DriveModeFeedback_sat;

      /* SignalConversion: '<S145>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_EPSTorqueModeFeedback =
        rtb_BCM_EPSTorqueModeFeedback_s;

      /* SignalConversion: '<S145>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_AmbientLightColorFeedback =
        rtb_BCM_AmbientLightColorFeedba;

      /* SignalConversion: '<S145>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_RollingCounter = 0.0;

      /* SignalConversion: '<S145>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.BCM_CRC_Checksum = 0.0;
    }

    /* End of Outputs for SubSystem: '<S144>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S83>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF0RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf0looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_e= 517;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_h= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_g= ec_can_receive(1,0,
      CAN1BUF0RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_n[0]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_n[1]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_n[2]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_n[3]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_n[4]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_n[5]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_n[6]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_n[7]= CAN1BUF0RX[can1buf0looprx];
    can1buf0looprx++;
  }

  /* Call the system: <S83>/ReceiveMessages */

  /* Output and update for function-call system: '<S83>/ReceiveMessages' */
  {
    int32_T rtb_EMS_TorqFailure_L;
    int32_T rtb_EMS_ESPTorqReuestAvailabili;
    int32_T rtb_EMS_CheckSum_205_sat;
    real_T rtb_EMS_FrictionalTorq_sat;
    real_T rtb_EMS_IndicatedDriverReqTorq_;
    real_T rtb_EMS_IndicatedRealEngTorq_sa;
    real_T rtb_EMS_TorqFailurecv;
    int32_T rtb_EMS_RollingCounter_id205_sa;

    /* Outputs for Enabled SubSystem: '<S155>/Subsystem' incorporates:
     *  EnablePort: '<S156>/Enable'
     */
    if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_g > 0) {
      /* DataTypeConversion: '<S157>/EMS_CheckSum_205_Convert' */
      rtb_EMS_TorqFailure_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_n[7];

      /* S-Function (sfix_bitop): '<S157>/EMS_CheckSum_205_L' */
      rtb_EMS_TorqFailure_L &= 240U;

      /* ArithShift: '<S157>/EMS_CheckSum_205_S' */
      rtb_EMS_TorqFailure_L = (int32_T)((uint32_T)rtb_EMS_TorqFailure_L >> 4);

      /* DataTypeConversion: '<S157>/EMS_CheckSum_205cv' */
      rtb_EMS_ESPTorqReuestAvailabili = rtb_EMS_TorqFailure_L;

      /* Sum: '<S157>/EMS_CheckSum_205_Ad' */
      rtb_EMS_CheckSum_205_sat = rtb_EMS_ESPTorqReuestAvailabili;

      /* Saturate: '<S157>/EMS_CheckSum_205_sat' */
      rtb_EMS_TorqFailurecv = rtb_EMS_CheckSum_205_sat;
      rtb_EMS_CheckSum_205_sat = (int32_T)rtb_EMS_TorqFailurecv;

      /* DataTypeConversion: '<S157>/EMS_ESPTorqReuestAvailability_Convert' */
      rtb_EMS_TorqFailure_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_n[0];

      /* S-Function (sfix_bitop): '<S157>/EMS_ESPTorqReuestAvailability_L' */
      rtb_EMS_TorqFailure_L &= 2U;

      /* ArithShift: '<S157>/EMS_ESPTorqReuestAvailability_S' */
      rtb_EMS_TorqFailure_L = (int32_T)((uint32_T)rtb_EMS_TorqFailure_L >> 1);

      /* Saturate: '<S157>/EMS_ESPTorqReuestAvailability_sat' */
      rtb_EMS_TorqFailurecv = rtb_EMS_TorqFailure_L;
      rtb_EMS_ESPTorqReuestAvailabili = (int32_T)rtb_EMS_TorqFailurecv;

      /* Product: '<S157>/EMS_FrictionalTorqinput4_P' incorporates:
       *  Constant: '<S157>/EMS_FrictionalTorqinput4_C'
       */
      rtb_EMS_FrictionalTorq_sat = (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_n[3] * 256.0;

      /* Sum: '<S157>/EMS_FrictionalTorqinput4_Ad' */
      rtb_EMS_IndicatedDriverReqTorq_ = rtb_EMS_FrictionalTorq_sat + (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_n[4];

      /* DataTypeConversion: '<S157>/EMS_FrictionalTorq_Convert' */
      rtb_EMS_TorqFailure_L = (int32_T)rtb_EMS_IndicatedDriverReqTorq_;

      /* DataTypeConversion: '<S157>/EMS_FrictionalTorqcv' */
      rtb_EMS_IndicatedDriverReqTorq_ = rtb_EMS_TorqFailure_L;

      /* Gain: '<S157>/EMS_FrictionalTorq_F' */
      rtb_EMS_IndicatedDriverReqTorq_ *= 0.001526;

      /* Sum: '<S157>/EMS_FrictionalTorq_Ad' */
      rtb_EMS_FrictionalTorq_sat = rtb_EMS_IndicatedDriverReqTorq_;

      /* Saturate: '<S157>/EMS_FrictionalTorq_sat' */
      if (rtb_EMS_FrictionalTorq_sat > 99.9988) {
        rtb_EMS_FrictionalTorq_sat = 99.9988;
      }

      /* End of Saturate: '<S157>/EMS_FrictionalTorq_sat' */

      /* Product: '<S157>/EMS_IndicatedDriverReqTorqinput2_P' incorporates:
       *  Constant: '<S157>/EMS_IndicatedDriverReqTorqinput2_C'
       */
      rtb_EMS_IndicatedDriverReqTorq_ = (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_n[1] * 256.0;

      /* Sum: '<S157>/EMS_IndicatedDriverReqTorqinput2_Ad' */
      rtb_EMS_IndicatedRealEngTorq_sa = rtb_EMS_IndicatedDriverReqTorq_ +
        (real_T)VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_n[2];

      /* DataTypeConversion: '<S157>/EMS_IndicatedDriverReqTorq_Convert' */
      rtb_EMS_TorqFailure_L = (int32_T)rtb_EMS_IndicatedRealEngTorq_sa;

      /* DataTypeConversion: '<S157>/EMS_IndicatedDriverReqTorqcv' */
      rtb_EMS_IndicatedRealEngTorq_sa = rtb_EMS_TorqFailure_L;

      /* Gain: '<S157>/EMS_IndicatedDriverReqTorq_F' */
      rtb_EMS_IndicatedRealEngTorq_sa *= 0.001526;

      /* Sum: '<S157>/EMS_IndicatedDriverReqTorq_Ad' */
      rtb_EMS_IndicatedDriverReqTorq_ = rtb_EMS_IndicatedRealEngTorq_sa;

      /* Saturate: '<S157>/EMS_IndicatedDriverReqTorq_sat' */
      if (rtb_EMS_IndicatedDriverReqTorq_ > 99.9988) {
        rtb_EMS_IndicatedDriverReqTorq_ = 99.9988;
      }

      /* End of Saturate: '<S157>/EMS_IndicatedDriverReqTorq_sat' */

      /* Product: '<S157>/EMS_IndicatedRealEngTorqinput6_P' incorporates:
       *  Constant: '<S157>/EMS_IndicatedRealEngTorqinput6_C'
       */
      rtb_EMS_IndicatedRealEngTorq_sa = (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_n[5] * 256.0;

      /* Sum: '<S157>/EMS_IndicatedRealEngTorqinput6_Ad' */
      rtb_EMS_TorqFailurecv = rtb_EMS_IndicatedRealEngTorq_sa + (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_n[6];

      /* DataTypeConversion: '<S157>/EMS_IndicatedRealEngTorq_Convert' */
      rtb_EMS_TorqFailure_L = (int32_T)rtb_EMS_TorqFailurecv;

      /* DataTypeConversion: '<S157>/EMS_IndicatedRealEngTorqcv' */
      rtb_EMS_TorqFailurecv = rtb_EMS_TorqFailure_L;

      /* Gain: '<S157>/EMS_IndicatedRealEngTorq_F' */
      rtb_EMS_TorqFailurecv *= 0.001526;

      /* Sum: '<S157>/EMS_IndicatedRealEngTorq_Ad' */
      rtb_EMS_IndicatedRealEngTorq_sa = rtb_EMS_TorqFailurecv;

      /* Saturate: '<S157>/EMS_IndicatedRealEngTorq_sat' */
      if (rtb_EMS_IndicatedRealEngTorq_sa > 99.9988) {
        rtb_EMS_IndicatedRealEngTorq_sa = 99.9988;
      }

      /* End of Saturate: '<S157>/EMS_IndicatedRealEngTorq_sat' */

      /* DataTypeConversion: '<S157>/EMS_RollingCounter_id205_Convert' */
      rtb_EMS_TorqFailure_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_n[7];

      /* S-Function (sfix_bitop): '<S157>/EMS_RollingCounter_id205_L' */
      rtb_EMS_TorqFailure_L &= 15U;

      /* DataTypeConversion: '<S157>/EMS_RollingCounter_id205cv' */
      rtb_EMS_TorqFailurecv = rtb_EMS_TorqFailure_L;

      /* Sum: '<S157>/EMS_RollingCounter_id205_Ad' */
      rtb_EMS_RollingCounter_id205_sa = (int32_T)rtb_EMS_TorqFailurecv;

      /* Saturate: '<S157>/EMS_RollingCounter_id205_sat' */
      rtb_EMS_TorqFailurecv = rtb_EMS_RollingCounter_id205_sa;
      rtb_EMS_RollingCounter_id205_sa = (int32_T)rtb_EMS_TorqFailurecv;

      /* DataTypeConversion: '<S157>/EMS_TorqFailure_Convert' */
      rtb_EMS_TorqFailure_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_n[0];

      /* S-Function (sfix_bitop): '<S157>/EMS_TorqFailure_L' */
      rtb_EMS_TorqFailure_L &= 128U;

      /* ArithShift: '<S157>/EMS_TorqFailure_S' */
      rtb_EMS_TorqFailure_L = (int32_T)((uint32_T)rtb_EMS_TorqFailure_L >> 7);

      /* DataTypeConversion: '<S157>/EMS_TorqFailurecv' */
      rtb_EMS_TorqFailurecv = rtb_EMS_TorqFailure_L;

      /* SignalConversion: '<S156>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_ESPTorqReuestAvailability =
        rtb_EMS_ESPTorqReuestAvailabili;

      /* SignalConversion: '<S156>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_TorqFailure = rtb_EMS_TorqFailurecv;

      /* SignalConversion: '<S156>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_IndicatedDriverReqTorq =
        rtb_EMS_IndicatedDriverReqTorq_;

      /* SignalConversion: '<S156>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_FrictionalTorq_d =
        rtb_EMS_FrictionalTorq_sat;

      /* SignalConversion: '<S156>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_IndicatedRealEngTorq =
        rtb_EMS_IndicatedRealEngTorq_sa;

      /* SignalConversion: '<S156>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_RollingCounter_id205 =
        rtb_EMS_RollingCounter_id205_sa;

      /* SignalConversion: '<S156>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_CheckSum_205 = rtb_EMS_CheckSum_205_sat;
    }

    /* End of Outputs for SubSystem: '<S155>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S84>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF1RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf1looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_oo= 597;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_g= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_j= ec_can_receive(1,1,
      CAN1BUF1RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_j[0]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_j[1]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_j[2]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_j[3]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_j[4]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_j[5]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_j[6]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_j[7]= CAN1BUF1RX[can1buf1looprx];
    can1buf1looprx++;
  }

  /* Call the system: <S84>/ReceiveMessages */

  /* Output and update for function-call system: '<S84>/ReceiveMessages' */
  {
    int32_T rtb_EMS_RollingCounter_id255_L;
    real_T rtb_EMS_CheckSum_255_sat;
    real_T rtb_EMS_AccPedal_sat;
    int32_T rtb_EMS_AccpedelError_sat;
    real_T rtb_EMS_EngineSpeed_sat;
    int32_T rtb_EMS_EngineSpeedError_sat;
    real_T rtb_EMS_RollingCounter_id255cv;

    /* Outputs for Enabled SubSystem: '<S165>/Subsystem' incorporates:
     *  EnablePort: '<S166>/Enable'
     */
    if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_j > 0) {
      /* DataTypeConversion: '<S167>/EMS_AccPedal_Convert' */
      rtb_EMS_RollingCounter_id255_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_j[5];

      /* DataTypeConversion: '<S167>/EMS_AccPedalcv' */
      rtb_EMS_CheckSum_255_sat = rtb_EMS_RollingCounter_id255_L;

      /* Gain: '<S167>/EMS_AccPedal_F' */
      rtb_EMS_CheckSum_255_sat *= 0.392;

      /* Sum: '<S167>/EMS_AccPedal_Ad' */
      rtb_EMS_AccPedal_sat = rtb_EMS_CheckSum_255_sat;

      /* Saturate: '<S167>/EMS_AccPedal_sat' */
      if (rtb_EMS_AccPedal_sat > 99.568) {
        rtb_EMS_AccPedal_sat = 99.568;
      }

      /* End of Saturate: '<S167>/EMS_AccPedal_sat' */

      /* DataTypeConversion: '<S167>/EMS_AccpedelError_Convert' */
      rtb_EMS_RollingCounter_id255_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_j[1];

      /* S-Function (sfix_bitop): '<S167>/EMS_AccpedelError_L' */
      rtb_EMS_RollingCounter_id255_L &= 4U;

      /* ArithShift: '<S167>/EMS_AccpedelError_S' */
      rtb_EMS_RollingCounter_id255_L = (int32_T)((uint32_T)
        rtb_EMS_RollingCounter_id255_L >> 2);

      /* DataTypeConversion: '<S167>/EMS_AccpedelErrorcv' */
      rtb_EMS_CheckSum_255_sat = rtb_EMS_RollingCounter_id255_L;

      /* Sum: '<S167>/EMS_AccpedelError_Ad' */
      rtb_EMS_AccpedelError_sat = (int32_T)rtb_EMS_CheckSum_255_sat;

      /* Saturate: '<S167>/EMS_AccpedelError_sat' */
      rtb_EMS_EngineSpeed_sat = rtb_EMS_AccpedelError_sat;
      rtb_EMS_AccpedelError_sat = (int32_T)rtb_EMS_EngineSpeed_sat;

      /* DataTypeConversion: '<S167>/EMS_BrakePedalStatus_Convert' */
      rtb_EMS_RollingCounter_id255_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_j[0];

      /* S-Function (sfix_bitop): '<S167>/EMS_BrakePedalStatus_L' */
      rtb_EMS_RollingCounter_id255_L &= 192U;

      /* ArithShift: '<S167>/EMS_BrakePedalStatus_S' */
      rtb_EMS_RollingCounter_id255_L = (int32_T)((uint32_T)
        rtb_EMS_RollingCounter_id255_L >> 6);

      /* DataTypeConversion: '<S167>/EMS_BrakePedalStatuscv' */
      rtb_EMS_CheckSum_255_sat = rtb_EMS_RollingCounter_id255_L;

      /* Sum: '<S167>/EMS_BrakePedalStatus_Ad' */
      rtb_EMS_EngineSpeed_sat = rtb_EMS_CheckSum_255_sat;

      /* Saturate: '<S167>/EMS_BrakePedalStatus_sat' */
      EMS_BrakePedalStatus = rtb_EMS_EngineSpeed_sat;

      /* DataTypeConversion: '<S167>/EMS_CheckSum_255_Convert' */
      rtb_EMS_RollingCounter_id255_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_j[7];

      /* S-Function (sfix_bitop): '<S167>/EMS_CheckSum_255_L' */
      rtb_EMS_RollingCounter_id255_L &= 240U;

      /* ArithShift: '<S167>/EMS_CheckSum_255_S' */
      rtb_EMS_RollingCounter_id255_L = (int32_T)((uint32_T)
        rtb_EMS_RollingCounter_id255_L >> 4);

      /* DataTypeConversion: '<S167>/EMS_CheckSum_255cv' */
      rtb_EMS_EngineSpeed_sat = rtb_EMS_RollingCounter_id255_L;

      /* Sum: '<S167>/EMS_CheckSum_255_Ad' */
      rtb_EMS_CheckSum_255_sat = rtb_EMS_EngineSpeed_sat;

      /* DataTypeConversion: '<S167>/EMS_EngineSpeedError_Convert' */
      rtb_EMS_RollingCounter_id255_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_j[1];

      /* S-Function (sfix_bitop): '<S167>/EMS_EngineSpeedError_L' */
      rtb_EMS_RollingCounter_id255_L &= 16U;

      /* ArithShift: '<S167>/EMS_EngineSpeedError_S' */
      rtb_EMS_RollingCounter_id255_L = (int32_T)((uint32_T)
        rtb_EMS_RollingCounter_id255_L >> 4);

      /* DataTypeConversion: '<S167>/EMS_EngineSpeedErrorcv' */
      rtb_EMS_EngineSpeed_sat = rtb_EMS_RollingCounter_id255_L;

      /* Sum: '<S167>/EMS_EngineSpeedError_Ad' */
      rtb_EMS_EngineSpeedError_sat = (int32_T)rtb_EMS_EngineSpeed_sat;

      /* Saturate: '<S167>/EMS_EngineSpeedError_sat' */
      rtb_EMS_EngineSpeed_sat = rtb_EMS_EngineSpeedError_sat;
      rtb_EMS_EngineSpeedError_sat = (int32_T)rtb_EMS_EngineSpeed_sat;

      /* Product: '<S167>/EMS_EngineSpeedinput3_P' incorporates:
       *  Constant: '<S167>/EMS_EngineSpeedinput3_C'
       */
      rtb_EMS_EngineSpeed_sat = (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_j[2] * 256.0;

      /* Sum: '<S167>/EMS_EngineSpeedinput3_Ad' */
      rtb_EMS_RollingCounter_id255cv = rtb_EMS_EngineSpeed_sat + (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_j[3];

      /* DataTypeConversion: '<S167>/EMS_EngineSpeed_Convert' */
      rtb_EMS_RollingCounter_id255_L = (int32_T)rtb_EMS_RollingCounter_id255cv;

      /* DataTypeConversion: '<S167>/EMS_EngineSpeedcv' */
      rtb_EMS_RollingCounter_id255cv = rtb_EMS_RollingCounter_id255_L;

      /* Gain: '<S167>/EMS_EngineSpeed_F' */
      rtb_EMS_RollingCounter_id255cv *= 0.25;

      /* Sum: '<S167>/EMS_EngineSpeed_Ad' */
      rtb_EMS_EngineSpeed_sat = rtb_EMS_RollingCounter_id255cv;

      /* Saturate: '<S167>/EMS_EngineSpeed_sat' */
      if (rtb_EMS_EngineSpeed_sat > 16383.5) {
        rtb_EMS_EngineSpeed_sat = 16383.5;
      }

      /* End of Saturate: '<S167>/EMS_EngineSpeed_sat' */

      /* DataTypeConversion: '<S167>/EMS_RollingCounter_id255_Convert' */
      rtb_EMS_RollingCounter_id255_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_j[7];

      /* S-Function (sfix_bitop): '<S167>/EMS_RollingCounter_id255_L' */
      rtb_EMS_RollingCounter_id255_L &= 15U;

      /* DataTypeConversion: '<S167>/EMS_RollingCounter_id255cv' */
      rtb_EMS_RollingCounter_id255cv = rtb_EMS_RollingCounter_id255_L;

      /* SignalConversion: '<S166>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_BrakePedalStatus_l =
        EMS_BrakePedalStatus;

      /* SignalConversion: '<S166>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_AccpedelError =
        rtb_EMS_AccpedelError_sat;

      /* SignalConversion: '<S166>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_EngineSpeedError =
        rtb_EMS_EngineSpeedError_sat;

      /* SignalConversion: '<S166>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_EngineSpeed_a = rtb_EMS_EngineSpeed_sat;

      /* SignalConversion: '<S166>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_AccPedal = rtb_EMS_AccPedal_sat;

      /* SignalConversion: '<S166>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_RollingCounter_id255 =
        rtb_EMS_RollingCounter_id255cv;

      /* SignalConversion: '<S166>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_CheckSum_255 = rtb_EMS_CheckSum_255_sat;
    }

    /* End of Outputs for SubSystem: '<S165>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S85>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF2RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf2looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_a= 613;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_l= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_n= ec_can_receive(1,2,
      CAN1BUF2RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_a[0]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_a[1]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_a[2]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_a[3]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_a[4]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_a[5]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_a[6]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_a[7]= CAN1BUF2RX[can1buf2looprx];
    can1buf2looprx++;
  }

  /* Call the system: <S85>/ReceiveMessages */

  /* Output and update for function-call system: '<S85>/ReceiveMessages' */
  {
    int32_T rtb_EMS_TorqueConstant_L;
    real_T rtb_EMS_TorqueConstant_F;
    int32_T rtb_EMS_EngineStatus_sat;
    real_T rtb_EMS_FullLoadIndicatedTorq_s;
    int32_T rtb_EMS_RollingCounter_id265_sa;

    /* Outputs for Enabled SubSystem: '<S175>/Subsystem' incorporates:
     *  EnablePort: '<S176>/Enable'
     */
    if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_n > 0) {
      /* DataTypeConversion: '<S177>/EMS_EngineStatus_Convert' */
      rtb_EMS_TorqueConstant_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_a
        [7];

      /* S-Function (sfix_bitop): '<S177>/EMS_EngineStatus_L' */
      rtb_EMS_TorqueConstant_L &= 192U;

      /* ArithShift: '<S177>/EMS_EngineStatus_S' */
      rtb_EMS_TorqueConstant_L = (int32_T)((uint32_T)rtb_EMS_TorqueConstant_L >>
        6);

      /* DataTypeConversion: '<S177>/EMS_EngineStatuscv' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_TorqueConstant_L;

      /* Sum: '<S177>/EMS_EngineStatus_Ad' */
      rtb_EMS_EngineStatus_sat = (int32_T)rtb_EMS_TorqueConstant_F;

      /* Saturate: '<S177>/EMS_EngineStatus_sat' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_EngineStatus_sat;
      rtb_EMS_EngineStatus_sat = (int32_T)rtb_EMS_TorqueConstant_F;

      /* DataTypeConversion: '<S177>/EMS_FullLoadIndicatedTorq_Convert' */
      rtb_EMS_TorqueConstant_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_a
        [2];

      /* DataTypeConversion: '<S177>/EMS_FullLoadIndicatedTorqcv' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_TorqueConstant_L;

      /* Gain: '<S177>/EMS_FullLoadIndicatedTorq_F' */
      rtb_EMS_TorqueConstant_F *= 0.392;

      /* Sum: '<S177>/EMS_FullLoadIndicatedTorq_Ad' */
      rtb_EMS_FullLoadIndicatedTorq_s = rtb_EMS_TorqueConstant_F;

      /* Saturate: '<S177>/EMS_FullLoadIndicatedTorq_sat' */
      if (rtb_EMS_FullLoadIndicatedTorq_s > 99.96) {
        rtb_EMS_FullLoadIndicatedTorq_s = 99.96;
      }

      /* End of Saturate: '<S177>/EMS_FullLoadIndicatedTorq_sat' */

      /* DataTypeConversion: '<S177>/EMS_RollingCounter_id265_Convert' */
      rtb_EMS_TorqueConstant_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_a
        [7];

      /* S-Function (sfix_bitop): '<S177>/EMS_RollingCounter_id265_L' */
      rtb_EMS_TorqueConstant_L &= 15U;

      /* DataTypeConversion: '<S177>/EMS_RollingCounter_id265cv' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_TorqueConstant_L;

      /* Sum: '<S177>/EMS_RollingCounter_id265_Ad' */
      rtb_EMS_RollingCounter_id265_sa = (int32_T)rtb_EMS_TorqueConstant_F;

      /* Saturate: '<S177>/EMS_RollingCounter_id265_sat' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_RollingCounter_id265_sa;
      rtb_EMS_RollingCounter_id265_sa = (int32_T)rtb_EMS_TorqueConstant_F;

      /* DataTypeConversion: '<S177>/EMS_TorqueConstant_Convert' */
      rtb_EMS_TorqueConstant_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_a
        [6];

      /* DataTypeConversion: '<S177>/EMS_TorqueConstantcv' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_TorqueConstant_L;

      /* Gain: '<S177>/EMS_TorqueConstant_F' */
      rtb_EMS_TorqueConstant_F *= 10.0;

      /* Saturate: '<S177>/EMS_TorqueConstant_sat' */
      if (rtb_EMS_TorqueConstant_F > 2540.0) {
        rtb_EMS_TorqueConstant_F = 2540.0;
      }

      /* End of Saturate: '<S177>/EMS_TorqueConstant_sat' */

      /* SignalConversion: '<S176>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_FullLoadIndicatedTorq =
        rtb_EMS_FullLoadIndicatedTorq_s;

      /* SignalConversion: '<S176>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_TorqueConstant_c =
        rtb_EMS_TorqueConstant_F;

      /* SignalConversion: '<S176>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_RollingCounter_id265 =
        rtb_EMS_RollingCounter_id265_sa;

      /* SignalConversion: '<S176>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_EngineStatus_f =
        rtb_EMS_EngineStatus_sat;
    }

    /* End of Outputs for SubSystem: '<S175>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S86>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF3RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf3looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_h= 630;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_b= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_p= ec_can_receive(1,3,
      CAN1BUF3RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ix[0]=
      CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ix[1]=
      CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ix[2]=
      CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ix[3]=
      CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ix[4]=
      CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ix[5]=
      CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ix[6]=
      CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ix[7]=
      CAN1BUF3RX[can1buf3looprx];
    can1buf3looprx++;
  }

  /* Call the system: <S86>/ReceiveMessages */

  /* Output and update for function-call system: '<S86>/ReceiveMessages' */
  {
    int32_T rtb_EMS_RealAccPedal_Convert;
    real_T rtb_EMS_RealAccPedal_F;

    /* Outputs for Enabled SubSystem: '<S182>/Subsystem' incorporates:
     *  EnablePort: '<S183>/Enable'
     */
    if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_p > 0) {
      /* DataTypeConversion: '<S184>/EMS_RealAccPedal_Convert' */
      rtb_EMS_RealAccPedal_Convert =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ix[2];

      /* DataTypeConversion: '<S184>/EMS_RealAccPedalcv' */
      rtb_EMS_RealAccPedal_F = rtb_EMS_RealAccPedal_Convert;

      /* Gain: '<S184>/EMS_RealAccPedal_F' */
      rtb_EMS_RealAccPedal_F *= 0.392;

      /* Saturate: '<S184>/EMS_RealAccPedal_sat' */
      if (rtb_EMS_RealAccPedal_F > 99.96) {
        rtb_EMS_RealAccPedal_F = 99.96;
      }

      /* End of Saturate: '<S184>/EMS_RealAccPedal_sat' */

      /* SignalConversion: '<S183>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_RealAccPedal = rtb_EMS_RealAccPedal_F;
    }

    /* End of Outputs for SubSystem: '<S182>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S87>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF4RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf4looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_ow= 598;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_d= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_c= ec_can_receive(1,4,
      CAN1BUF4RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_e[0]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_e[1]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_e[2]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_e[3]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_e[4]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_e[5]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_e[6]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_e[7]= CAN1BUF4RX[can1buf4looprx];
    can1buf4looprx++;
  }

  /* Call the system: <S87>/ReceiveMessages */

  /* Output and update for function-call system: '<S87>/ReceiveMessages' */
  {
    int32_T rtb_EPB_Status_L;
    int32_T rtb_EPB_Checksum_sat;
    int32_T rtb_EPB_FailStatus_sat;
    int32_T rtb_EPB_FailureLamp_sat;
    int32_T rtb_EPB_FunctionLamp_sat;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S186>/Subsystem' incorporates:
     *  EnablePort: '<S187>/Enable'
     */
    if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_c > 0) {
      /* DataTypeConversion: '<S188>/EPB_Checksum_Convert' */
      rtb_EPB_Status_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_e[7];

      /* Sum: '<S188>/EPB_Checksum_Ad' */
      rtb_EPB_Checksum_sat = rtb_EPB_Status_L;

      /* Saturate: '<S188>/EPB_Checksum_sat' */
      u0 = rtb_EPB_Checksum_sat;
      rtb_EPB_Checksum_sat = (int32_T)u0;

      /* DataTypeConversion: '<S188>/EPB_FailStatus_Convert' */
      rtb_EPB_Status_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_e[0];

      /* S-Function (sfix_bitop): '<S188>/EPB_FailStatus_L' */
      rtb_EPB_Status_L &= 192U;

      /* ArithShift: '<S188>/EPB_FailStatus_S' */
      rtb_EPB_Status_L = (int32_T)((uint32_T)rtb_EPB_Status_L >> 6);

      /* Sum: '<S188>/EPB_FailStatus_Ad' */
      rtb_EPB_FailStatus_sat = rtb_EPB_Status_L;

      /* Saturate: '<S188>/EPB_FailStatus_sat' */
      u0 = rtb_EPB_FailStatus_sat;
      rtb_EPB_FailStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S188>/EPB_FailureLamp_Convert' */
      rtb_EPB_Status_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_e[5];

      /* S-Function (sfix_bitop): '<S188>/EPB_FailureLamp_L' */
      rtb_EPB_Status_L &= 48U;

      /* ArithShift: '<S188>/EPB_FailureLamp_S' */
      rtb_EPB_Status_L = (int32_T)((uint32_T)rtb_EPB_Status_L >> 4);

      /* Sum: '<S188>/EPB_FailureLamp_Ad' */
      rtb_EPB_FailureLamp_sat = rtb_EPB_Status_L;

      /* Saturate: '<S188>/EPB_FailureLamp_sat' */
      u0 = rtb_EPB_FailureLamp_sat;
      rtb_EPB_FailureLamp_sat = (int32_T)u0;

      /* DataTypeConversion: '<S188>/EPB_FunctionLamp_Convert' */
      rtb_EPB_Status_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_e[5];

      /* S-Function (sfix_bitop): '<S188>/EPB_FunctionLamp_L' */
      rtb_EPB_Status_L &= 12U;

      /* ArithShift: '<S188>/EPB_FunctionLamp_S' */
      rtb_EPB_Status_L = (int32_T)((uint32_T)rtb_EPB_Status_L >> 2);

      /* Sum: '<S188>/EPB_FunctionLamp_Ad' */
      rtb_EPB_FunctionLamp_sat = rtb_EPB_Status_L;

      /* Saturate: '<S188>/EPB_FunctionLamp_sat' */
      u0 = rtb_EPB_FunctionLamp_sat;
      rtb_EPB_FunctionLamp_sat = (int32_T)u0;

      /* DataTypeConversion: '<S188>/EPB_RollingCounter_id256_Convert' */
      rtb_EPB_Status_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_e[6];

      /* S-Function (sfix_bitop): '<S188>/EPB_RollingCounter_id256_L' */
      rtb_EPB_Status_L &= 15U;

      /* Saturate: '<S188>/EPB_RollingCounter_id256_sat' */
      u0 = rtb_EPB_Status_L;
      EPB_RollingCounter_id256 = u0;

      /* DataTypeConversion: '<S188>/EPB_Status_Convert' */
      rtb_EPB_Status_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_e[2];

      /* S-Function (sfix_bitop): '<S188>/EPB_Status_L' */
      rtb_EPB_Status_L &= 192U;

      /* ArithShift: '<S188>/EPB_Status_S' */
      rtb_EPB_Status_L = (int32_T)((uint32_T)rtb_EPB_Status_L >> 6);

      /* Saturate: '<S188>/EPB_Status_sat' */
      u0 = rtb_EPB_Status_L;
      rtb_EPB_Status_L = (int32_T)u0;

      /* SignalConversion: '<S187>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPB_FailStatus = rtb_EPB_FailStatus_sat;

      /* SignalConversion: '<S187>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPB_Status_p = rtb_EPB_Status_L;

      /* SignalConversion: '<S187>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPB_FunctionLamp_f =
        rtb_EPB_FunctionLamp_sat;

      /* SignalConversion: '<S187>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPB_FailureLamp = rtb_EPB_FailureLamp_sat;

      /* SignalConversion: '<S187>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPB_RollingCounter_id256_d =
        EPB_RollingCounter_id256;

      /* SignalConversion: '<S187>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPB_Checksum = rtb_EPB_Checksum_sat;
    }

    /* End of Outputs for SubSystem: '<S186>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S88>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF5RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf5looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_n1= 522;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_ir= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_mh= ec_can_receive(1,5,
      CAN1BUF5RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jz[0]=
      CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jz[1]=
      CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jz[2]=
      CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jz[3]=
      CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jz[4]=
      CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jz[5]=
      CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jz[6]=
      CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jz[7]=
      CAN1BUF5RX[can1buf5looprx];
    can1buf5looprx++;
  }

  /* Call the system: <S88>/ReceiveMessages */

  /* Output and update for function-call system: '<S88>/ReceiveMessages' */
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

    /* Outputs for Enabled SubSystem: '<S195>/Subsystem' incorporates:
     *  EnablePort: '<S196>/Enable'
     */
    if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_mh > 0) {
      /* DataTypeConversion: '<S197>/EPS_APA_AbortFeedback_Convert' */
      rtb_EPS_TorqueSensorStatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jz[1];

      /* S-Function (sfix_bitop): '<S197>/EPS_APA_AbortFeedback_L' */
      rtb_EPS_TorqueSensorStatus_L &= 112U;

      /* ArithShift: '<S197>/EPS_APA_AbortFeedback_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 4);

      /* DataTypeConversion: '<S197>/EPS_APA_AbortFeedbackcv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S197>/EPS_APA_AbortFeedback_Ad' */
      rtb_EPS_APA_AbortFeedback_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S197>/EPS_APA_AbortFeedback_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_APA_AbortFeedback_sat;
      rtb_EPS_APA_AbortFeedback_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* DataTypeConversion: '<S197>/EPS_APA_ControlFeedback_Convert' */
      rtb_EPS_TorqueSensorStatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jz[5];

      /* S-Function (sfix_bitop): '<S197>/EPS_APA_ControlFeedback_L' */
      rtb_EPS_TorqueSensorStatus_L &= 64U;

      /* ArithShift: '<S197>/EPS_APA_ControlFeedback_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 6);

      /* DataTypeConversion: '<S197>/EPS_APA_ControlFeedbackcv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S197>/EPS_APA_ControlFeedback_Ad' */
      rtb_EPS_APA_ControlFeedback_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S197>/EPS_APA_ControlFeedback_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_APA_ControlFeedback_sat;
      rtb_EPS_APA_ControlFeedback_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* DataTypeConversion: '<S197>/EPS_APA_EpasFailed_Convert' */
      rtb_EPS_TorqueSensorStatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jz[1];

      /* S-Function (sfix_bitop): '<S197>/EPS_APA_EpasFailed_L' */
      rtb_EPS_TorqueSensorStatus_L &= 2U;

      /* ArithShift: '<S197>/EPS_APA_EpasFailed_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 1);

      /* DataTypeConversion: '<S197>/EPS_APA_EpasFailedcv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S197>/EPS_APA_EpasFailed_Ad' */
      rtb_EPS_APA_EpasFailed_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S197>/EPS_APA_EpasFailed_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_APA_EpasFailed_sat;
      rtb_EPS_APA_EpasFailed_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* DataTypeConversion: '<S197>/EPS_Checksum_Convert' */
      rtb_EPS_TorqueSensorStatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jz[7];

      /* DataTypeConversion: '<S197>/EPS_Checksumcv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S197>/EPS_Checksum_Ad' */
      rtb_EPS_Checksum_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S197>/EPS_Checksum_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_Checksum_sat;
      rtb_EPS_Checksum_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* DataTypeConversion: '<S197>/EPS_ConcussAvailabilityStatus_Convert' */
      rtb_EPS_TorqueSensorStatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jz[6];

      /* S-Function (sfix_bitop): '<S197>/EPS_ConcussAvailabilityStatus_L' */
      rtb_EPS_TorqueSensorStatus_L &= 48U;

      /* ArithShift: '<S197>/EPS_ConcussAvailabilityStatus_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 4);

      /* DataTypeConversion: '<S197>/EPS_ConcussAvailabilityStatuscv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S197>/EPS_ConcussAvailabilityStatus_Ad' */
      rtb_EPS_ConcussAvailabilityStat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S197>/EPS_ConcussAvailabilityStatus_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_ConcussAvailabilityStat;
      rtb_EPS_ConcussAvailabilityStat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* DataTypeConversion: '<S197>/EPS_EPSFailed_Convert' */
      rtb_EPS_TorqueSensorStatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jz[0];

      /* S-Function (sfix_bitop): '<S197>/EPS_EPSFailed_L' */
      rtb_EPS_TorqueSensorStatus_L &= 128U;

      /* ArithShift: '<S197>/EPS_EPSFailed_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 7);

      /* DataTypeConversion: '<S197>/EPS_EPSFailedcv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S197>/EPS_EPSFailed_Ad' */
      rtb_EPS_EPSFailed_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S197>/EPS_EPSFailed_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_EPSFailed_sat;
      rtb_EPS_EPSFailed_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* DataTypeConversion: '<S197>/EPS_RollingCounter_Convert' */
      rtb_EPS_TorqueSensorStatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jz[6];

      /* S-Function (sfix_bitop): '<S197>/EPS_RollingCounter_L' */
      rtb_EPS_TorqueSensorStatus_L &= 15U;

      /* DataTypeConversion: '<S197>/EPS_RollingCountercv' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatus_L;

      /* Sum: '<S197>/EPS_RollingCounter_Ad' */
      rtb_EPS_RollingCounter_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Saturate: '<S197>/EPS_RollingCounter_sat' */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_RollingCounter_sat;
      rtb_EPS_RollingCounter_sat = (int32_T)rtb_EPS_SteeringTorque_sat;

      /* Product: '<S197>/EPS_SteeringTorqueinput3_P' incorporates:
       *  Constant: '<S197>/EPS_SteeringTorqueinput3_C'
       */
      rtb_EPS_SteeringTorque_sat = (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jz[2] * 256.0;

      /* Sum: '<S197>/EPS_SteeringTorqueinput3_Ad' */
      rtb_EPS_TorqueSensorStatuscv = rtb_EPS_SteeringTorque_sat + (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jz[3];

      /* DataTypeConversion: '<S197>/EPS_SteeringTorque_Convert' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)rtb_EPS_TorqueSensorStatuscv;

      /* S-Function (sfix_bitop): '<S197>/EPS_SteeringTorque_L' */
      rtb_EPS_TorqueSensorStatus_L &= 4080U;

      /* ArithShift: '<S197>/EPS_SteeringTorque_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 4);

      /* DataTypeConversion: '<S197>/EPS_SteeringTorquecv' */
      rtb_EPS_TorqueSensorStatuscv = rtb_EPS_TorqueSensorStatus_L;

      /* Gain: '<S197>/EPS_SteeringTorque_F' */
      rtb_EPS_TorqueSensorStatuscv *= 0.1794;

      /* Sum: '<S197>/EPS_SteeringTorque_Ad' incorporates:
       *  Constant: '<S197>/EPS_SteeringTorque_O'
       */
      rtb_EPS_SteeringTorque_sat = rtb_EPS_TorqueSensorStatuscv +
        -22.780000686645508;

      /* Saturate: '<S197>/EPS_SteeringTorque_sat' */
      if (rtb_EPS_SteeringTorque_sat > 22.78) {
        rtb_EPS_SteeringTorque_sat = 22.78;
      } else {
        if (rtb_EPS_SteeringTorque_sat < -22.78) {
          rtb_EPS_SteeringTorque_sat = -22.78;
        }
      }

      /* End of Saturate: '<S197>/EPS_SteeringTorque_sat' */

      /* DataTypeConversion: '<S197>/EPS_TorqueSensorStatus_Convert' */
      rtb_EPS_TorqueSensorStatus_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jz[4];

      /* S-Function (sfix_bitop): '<S197>/EPS_TorqueSensorStatus_L' */
      rtb_EPS_TorqueSensorStatus_L &= 2U;

      /* ArithShift: '<S197>/EPS_TorqueSensorStatus_S' */
      rtb_EPS_TorqueSensorStatus_L = (int32_T)((uint32_T)
        rtb_EPS_TorqueSensorStatus_L >> 1);

      /* DataTypeConversion: '<S197>/EPS_TorqueSensorStatuscv' */
      rtb_EPS_TorqueSensorStatuscv = rtb_EPS_TorqueSensorStatus_L;

      /* SignalConversion: '<S196>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPS_EPSFailed_k = rtb_EPS_EPSFailed_sat;

      /* SignalConversion: '<S196>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPS_APA_EpasFailed =
        rtb_EPS_APA_EpasFailed_sat;

      /* SignalConversion: '<S196>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPS_APA_AbortFeedback =
        rtb_EPS_APA_AbortFeedback_sat;

      /* SignalConversion: '<S196>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPS_SteeringTorque =
        rtb_EPS_SteeringTorque_sat;

      /* SignalConversion: '<S196>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPS_TorqueSensorStatus =
        rtb_EPS_TorqueSensorStatuscv;

      /* SignalConversion: '<S196>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPS_APA_ControlFeedback =
        rtb_EPS_APA_ControlFeedback_sat;

      /* SignalConversion: '<S196>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPS_RollingCounter =
        rtb_EPS_RollingCounter_sat;

      /* SignalConversion: '<S196>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPS_ConcussAvailabilityStatus =
        rtb_EPS_ConcussAvailabilityStat;

      /* SignalConversion: '<S196>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPS_Checksum = rtb_EPS_Checksum_sat;
    }

    /* End of Outputs for SubSystem: '<S195>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S89>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF6RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf6looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_ii= 538;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_kn= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_ip= ec_can_receive(1,6,
      CAN1BUF6RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_o[0]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_o[1]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_o[2]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_o[3]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_o[4]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_o[5]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_o[6]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_o[7]= CAN1BUF6RX[can1buf6looprx];
    can1buf6looprx++;
  }

  /* Call the system: <S89>/ReceiveMessages */

  /* Output and update for function-call system: '<S89>/ReceiveMessages' */
  {
    int32_T rtb_Rollingcounter_L;
    real_T rtb_EPS_MeasuredTosionBatTorque;
    int32_T rtb_EPS_AvailabilityStatus_sat;
    int32_T rtb_EPS_IACC_abortReson_sat;
    int32_T rtb_EPS_MeasTsionBatTorquevalid;
    real_T rtb_Rollingcountercv;

    /* Outputs for Enabled SubSystem: '<S207>/Subsystem' incorporates:
     *  EnablePort: '<S208>/Enable'
     */
    if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_ip > 0) {
      /* DataTypeConversion: '<S209>/EPS_AvailabilityStatus_Convert' */
      rtb_Rollingcounter_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_o[2];

      /* S-Function (sfix_bitop): '<S209>/EPS_AvailabilityStatus_L' */
      rtb_Rollingcounter_L &= 28U;

      /* ArithShift: '<S209>/EPS_AvailabilityStatus_S' */
      rtb_Rollingcounter_L = (int32_T)((uint32_T)rtb_Rollingcounter_L >> 2);

      /* DataTypeConversion: '<S209>/EPS_AvailabilityStatuscv' */
      rtb_EPS_MeasuredTosionBatTorque = rtb_Rollingcounter_L;

      /* Sum: '<S209>/EPS_AvailabilityStatus_Ad' */
      rtb_EPS_AvailabilityStatus_sat = (int32_T)rtb_EPS_MeasuredTosionBatTorque;

      /* Saturate: '<S209>/EPS_AvailabilityStatus_sat' */
      rtb_EPS_MeasuredTosionBatTorque = rtb_EPS_AvailabilityStatus_sat;
      rtb_EPS_AvailabilityStatus_sat = (int32_T)rtb_EPS_MeasuredTosionBatTorque;

      /* DataTypeConversion: '<S209>/EPS_IACC_abortReson_Convert' */
      rtb_Rollingcounter_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_o[5];

      /* S-Function (sfix_bitop): '<S209>/EPS_IACC_abortReson_L' */
      rtb_Rollingcounter_L &= 112U;

      /* ArithShift: '<S209>/EPS_IACC_abortReson_S' */
      rtb_Rollingcounter_L = (int32_T)((uint32_T)rtb_Rollingcounter_L >> 4);

      /* DataTypeConversion: '<S209>/EPS_IACC_abortResoncv' */
      rtb_EPS_MeasuredTosionBatTorque = rtb_Rollingcounter_L;

      /* Sum: '<S209>/EPS_IACC_abortReson_Ad' */
      rtb_EPS_IACC_abortReson_sat = (int32_T)rtb_EPS_MeasuredTosionBatTorque;

      /* Saturate: '<S209>/EPS_IACC_abortReson_sat' */
      rtb_EPS_MeasuredTosionBatTorque = rtb_EPS_IACC_abortReson_sat;
      rtb_EPS_IACC_abortReson_sat = (int32_T)rtb_EPS_MeasuredTosionBatTorque;

      /* DataTypeConversion: '<S209>/EPS_MeasTsionBatTorquevalid_Convert' */
      rtb_Rollingcounter_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_o[4];

      /* S-Function (sfix_bitop): '<S209>/EPS_MeasTsionBatTorquevalid_L' */
      rtb_Rollingcounter_L &= 64U;

      /* ArithShift: '<S209>/EPS_MeasTsionBatTorquevalid_S' */
      rtb_Rollingcounter_L = (int32_T)((uint32_T)rtb_Rollingcounter_L >> 6);

      /* DataTypeConversion: '<S209>/EPS_MeasTsionBatTorquevalidcv' */
      rtb_EPS_MeasuredTosionBatTorque = rtb_Rollingcounter_L;

      /* Sum: '<S209>/EPS_MeasTsionBatTorquevalid_Ad' */
      rtb_EPS_MeasTsionBatTorquevalid = (int32_T)rtb_EPS_MeasuredTosionBatTorque;

      /* Saturate: '<S209>/EPS_MeasTsionBatTorquevalid_sat' */
      rtb_EPS_MeasuredTosionBatTorque = rtb_EPS_MeasTsionBatTorquevalid;
      rtb_EPS_MeasTsionBatTorquevalid = (int32_T)rtb_EPS_MeasuredTosionBatTorque;

      /* Product: '<S209>/EPS_MeasuredTosionBatTorqueinput1_P' incorporates:
       *  Constant: '<S209>/EPS_MeasuredTosionBatTorqueinput1_C'
       */
      rtb_EPS_MeasuredTosionBatTorque = (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_o[0] * 256.0;

      /* Sum: '<S209>/EPS_MeasuredTosionBatTorqueinput1_Ad' */
      rtb_Rollingcountercv = rtb_EPS_MeasuredTosionBatTorque + (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_o[1];

      /* DataTypeConversion: '<S209>/EPS_MeasuredTosionBatTorque_Convert' */
      rtb_Rollingcounter_L = (int32_T)rtb_Rollingcountercv;

      /* S-Function (sfix_bitop): '<S209>/EPS_MeasuredTosionBatTorque_L' */
      rtb_Rollingcounter_L &= 65504U;

      /* ArithShift: '<S209>/EPS_MeasuredTosionBatTorque_S' */
      rtb_Rollingcounter_L = (int32_T)((uint32_T)rtb_Rollingcounter_L >> 5);

      /* DataTypeConversion: '<S209>/EPS_MeasuredTosionBatTorquecv' */
      rtb_Rollingcountercv = rtb_Rollingcounter_L;

      /* Gain: '<S209>/EPS_MeasuredTosionBatTorque_F' */
      rtb_Rollingcountercv *= 0.01;

      /* Sum: '<S209>/EPS_MeasuredTosionBatTorque_Ad' incorporates:
       *  Constant: '<S209>/EPS_MeasuredTosionBatTorque_O'
       */
      rtb_EPS_MeasuredTosionBatTorque = rtb_Rollingcountercv +
        -10.229999542236328;

      /* Saturate: '<S209>/EPS_MeasuredTosionBatTorque_sat' */
      if (rtb_EPS_MeasuredTosionBatTorque > 10.23) {
        rtb_EPS_MeasuredTosionBatTorque = 10.23;
      }

      /* End of Saturate: '<S209>/EPS_MeasuredTosionBatTorque_sat' */

      /* DataTypeConversion: '<S209>/Rollingcounter_Convert' */
      rtb_Rollingcounter_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_o[6];

      /* S-Function (sfix_bitop): '<S209>/Rollingcounter_L' */
      rtb_Rollingcounter_L &= 15U;

      /* DataTypeConversion: '<S209>/Rollingcountercv' */
      rtb_Rollingcountercv = rtb_Rollingcounter_L;

      /* SignalConversion: '<S208>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPS_MeasuredTosionBatTorque =
        rtb_EPS_MeasuredTosionBatTorque;

      /* SignalConversion: '<S208>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPS_AvailabilityStatus_a =
        rtb_EPS_AvailabilityStatus_sat;

      /* SignalConversion: '<S208>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPS_MeasTsionBatTorquevalid =
        rtb_EPS_MeasTsionBatTorquevalid;

      /* SignalConversion: '<S208>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPS_IACC_abortReson =
        rtb_EPS_IACC_abortReson_sat;

      /* SignalConversion: '<S208>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPS_21A_Rollingcounter =
        rtb_Rollingcountercv;

      /* SignalConversion: '<S208>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPS_21A_CheckingSum = 0.0;
    }

    /* End of Outputs for SubSystem: '<S207>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S90>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF7RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf7looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_an= 631;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_py= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_e= ec_can_receive(1,7,
      CAN1BUF7RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_dj[0]=
      CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_dj[1]=
      CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_dj[2]=
      CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_dj[3]=
      CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_dj[4]=
      CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_dj[5]=
      CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_dj[6]=
      CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_dj[7]=
      CAN1BUF7RX[can1buf7looprx];
    can1buf7looprx++;
  }

  /* Call the system: <S90>/ReceiveMessages */

  /* Output and update for function-call system: '<S90>/ReceiveMessages' */
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

    /* Outputs for Enabled SubSystem: '<S216>/Subsystem' incorporates:
     *  EnablePort: '<S217>/Enable'
     */
    if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_e > 0) {
      /* DataTypeConversion: '<S218>/ESP_ABAactive_Convert' */
      rtb_ESP_VehicleStandstill_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_dj[2];

      /* S-Function (sfix_bitop): '<S218>/ESP_ABAactive_L' */
      rtb_ESP_VehicleStandstill_L &= 32U;

      /* ArithShift: '<S218>/ESP_ABAactive_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 5);

      /* Sum: '<S218>/ESP_ABAactive_Ad' */
      rtb_ESP_ABAactive_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S218>/ESP_ABAactive_sat' */
      u0 = rtb_ESP_ABAactive_sat;
      rtb_ESP_ABAactive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S218>/ESP_ABAavailable_Convert' */
      rtb_ESP_VehicleStandstill_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_dj[2];

      /* S-Function (sfix_bitop): '<S218>/ESP_ABAavailable_L' */
      rtb_ESP_VehicleStandstill_L &= 16U;

      /* ArithShift: '<S218>/ESP_ABAavailable_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 4);

      /* Sum: '<S218>/ESP_ABAavailable_Ad' */
      rtb_ESP_ABAavailable_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S218>/ESP_ABAavailable_sat' */
      u0 = rtb_ESP_ABAavailable_sat;
      rtb_ESP_ABAavailable_sat = (int32_T)u0;

      /* DataTypeConversion: '<S218>/ESP_AEBAvailable_Convert' */
      rtb_ESP_VehicleStandstill_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_dj[2];

      /* S-Function (sfix_bitop): '<S218>/ESP_AEBAvailable_L' */
      rtb_ESP_VehicleStandstill_L &= 8U;

      /* ArithShift: '<S218>/ESP_AEBAvailable_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 3);

      /* Sum: '<S218>/ESP_AEBAvailable_Ad' */
      rtb_ESP_AEBAvailable_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S218>/ESP_AEBAvailable_sat' */
      u0 = rtb_ESP_AEBAvailable_sat;
      rtb_ESP_AEBAvailable_sat = (int32_T)u0;

      /* DataTypeConversion: '<S218>/ESP_AEBdecActive_Convert' */
      rtb_ESP_VehicleStandstill_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_dj[2];

      /* S-Function (sfix_bitop): '<S218>/ESP_AEBdecActive_L' */
      rtb_ESP_VehicleStandstill_L &= 4U;

      /* ArithShift: '<S218>/ESP_AEBdecActive_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 2);

      /* Sum: '<S218>/ESP_AEBdecActive_Ad' */
      rtb_ESP_AEBdecActive_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S218>/ESP_AEBdecActive_sat' */
      u0 = rtb_ESP_AEBdecActive_sat;
      rtb_ESP_AEBdecActive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S218>/ESP_AWBactive_Convert' */
      rtb_ESP_VehicleStandstill_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_dj[2];

      /* S-Function (sfix_bitop): '<S218>/ESP_AWBactive_L' */
      rtb_ESP_VehicleStandstill_L &= 2U;

      /* ArithShift: '<S218>/ESP_AWBactive_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 1);

      /* Sum: '<S218>/ESP_AWBactive_Ad' */
      rtb_ESP_AWBactive_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S218>/ESP_AWBactive_sat' */
      u0 = rtb_ESP_AWBactive_sat;
      rtb_ESP_AWBactive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S218>/ESP_AWBavailable_Convert' */
      rtb_ESP_VehicleStandstill_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_dj[2];

      /* S-Function (sfix_bitop): '<S218>/ESP_AWBavailable_L' */
      rtb_ESP_VehicleStandstill_L &= 1U;

      /* Sum: '<S218>/ESP_AWBavailable_Ad' */
      rtb_ESP_AWBavailable_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S218>/ESP_AWBavailable_sat' */
      u0 = rtb_ESP_AWBavailable_sat;
      rtb_ESP_AWBavailable_sat = (int32_T)u0;

      /* DataTypeConversion: '<S218>/ESP_BrakeForce_Convert' */
      rtb_ESP_VehicleStandstill_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_dj[1];

      /* S-Function (sfix_bitop): '<S218>/ESP_BrakeForce_L' */
      rtb_ESP_VehicleStandstill_L &= 16U;

      /* ArithShift: '<S218>/ESP_BrakeForce_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 4);

      /* Sum: '<S218>/ESP_BrakeForce_Ad' */
      rtb_ESP_BrakeForce_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S218>/ESP_BrakeForce_sat' */
      u0 = rtb_ESP_BrakeForce_sat;
      rtb_ESP_BrakeForce_sat = (int32_T)u0;

      /* DataTypeConversion: '<S218>/ESP_BrakeOverHeat_Convert' */
      rtb_ESP_VehicleStandstill_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_dj[3];

      /* S-Function (sfix_bitop): '<S218>/ESP_BrakeOverHeat_L' */
      rtb_ESP_VehicleStandstill_L &= 1U;

      /* Sum: '<S218>/ESP_BrakeOverHeat_Ad' */
      rtb_ESP_BrakeOverHeat_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S218>/ESP_BrakeOverHeat_sat' */
      u0 = rtb_ESP_BrakeOverHeat_sat;
      rtb_ESP_BrakeOverHeat_sat = (int32_T)u0;

      /* DataTypeConversion: '<S218>/ESP_CDD_Active_Convert' */
      rtb_ESP_VehicleStandstill_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_dj[3];

      /* S-Function (sfix_bitop): '<S218>/ESP_CDD_Active_L' */
      rtb_ESP_VehicleStandstill_L &= 8U;

      /* ArithShift: '<S218>/ESP_CDD_Active_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 3);

      /* Sum: '<S218>/ESP_CDD_Active_Ad' */
      rtb_ESP_CDD_Active_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S218>/ESP_CDD_Active_sat' */
      u0 = rtb_ESP_CDD_Active_sat;
      rtb_ESP_CDD_Active_sat = (int32_T)u0;

      /* DataTypeConversion: '<S218>/ESP_CDD_Available_Convert' */
      rtb_ESP_VehicleStandstill_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_dj[3];

      /* S-Function (sfix_bitop): '<S218>/ESP_CDD_Available_L' */
      rtb_ESP_VehicleStandstill_L &= 16U;

      /* ArithShift: '<S218>/ESP_CDD_Available_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 4);

      /* Sum: '<S218>/ESP_CDD_Available_Ad' */
      rtb_ESP_CDD_Available_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S218>/ESP_CDD_Available_sat' */
      u0 = rtb_ESP_CDD_Available_sat;
      rtb_ESP_CDD_Available_sat = (int32_T)u0;

      /* DataTypeConversion: '<S218>/ESP_CheckSum_277_Convert' */
      rtb_ESP_VehicleStandstill_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_dj[7];

      /* Sum: '<S218>/ESP_CheckSum_277_Ad' */
      rtb_ESP_CheckSum_277_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S218>/ESP_CheckSum_277_sat' */
      u0 = rtb_ESP_CheckSum_277_sat;
      rtb_ESP_CheckSum_277_sat = (int32_T)u0;

      /* DataTypeConversion: '<S218>/ESP_PrefillActive_Convert' */
      rtb_ESP_VehicleStandstill_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_dj[2];

      /* S-Function (sfix_bitop): '<S218>/ESP_PrefillActive_L' */
      rtb_ESP_VehicleStandstill_L &= 128U;

      /* ArithShift: '<S218>/ESP_PrefillActive_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 7);

      /* Sum: '<S218>/ESP_PrefillActive_Ad' */
      rtb_ESP_PrefillActive_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S218>/ESP_PrefillActive_sat' */
      u0 = rtb_ESP_PrefillActive_sat;
      rtb_ESP_PrefillActive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S218>/ESP_PrefillAvailable_Convert' */
      rtb_ESP_VehicleStandstill_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_dj[2];

      /* S-Function (sfix_bitop): '<S218>/ESP_PrefillAvailable_L' */
      rtb_ESP_VehicleStandstill_L &= 64U;

      /* ArithShift: '<S218>/ESP_PrefillAvailable_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 6);

      /* Sum: '<S218>/ESP_PrefillAvailable_Ad' */
      rtb_ESP_PrefillAvailable_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S218>/ESP_PrefillAvailable_sat' */
      u0 = rtb_ESP_PrefillAvailable_sat;
      rtb_ESP_PrefillAvailable_sat = (int32_T)u0;

      /* DataTypeConversion: '<S218>/ESP_RollingCounter_277_Convert' */
      rtb_ESP_VehicleStandstill_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_dj[6];

      /* S-Function (sfix_bitop): '<S218>/ESP_RollingCounter_277_L' */
      rtb_ESP_VehicleStandstill_L &= 15U;

      /* Sum: '<S218>/ESP_RollingCounter_277_Ad' */
      rtb_ESP_RollingCounter_277_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S218>/ESP_RollingCounter_277_sat' */
      u0 = rtb_ESP_RollingCounter_277_sat;
      rtb_ESP_RollingCounter_277_sat = (int32_T)u0;

      /* DataTypeConversion: '<S218>/ESP_TCSActive_Convert' */
      rtb_ESP_VehicleStandstill_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_dj[1];

      /* S-Function (sfix_bitop): '<S218>/ESP_TCSActive_L' */
      rtb_ESP_VehicleStandstill_L &= 64U;

      /* ArithShift: '<S218>/ESP_TCSActive_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 6);

      /* Sum: '<S218>/ESP_TCSActive_Ad' */
      rtb_ESP_TCSActive_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S218>/ESP_TCSActive_sat' */
      u0 = rtb_ESP_TCSActive_sat;
      rtb_ESP_TCSActive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S218>/ESP_VDCActive_Convert' */
      rtb_ESP_VehicleStandstill_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_dj[1];

      /* S-Function (sfix_bitop): '<S218>/ESP_VDCActive_L' */
      rtb_ESP_VehicleStandstill_L &= 32U;

      /* ArithShift: '<S218>/ESP_VDCActive_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 5);

      /* Sum: '<S218>/ESP_VDCActive_Ad' */
      rtb_ESP_VDCActive_sat = rtb_ESP_VehicleStandstill_L;

      /* Saturate: '<S218>/ESP_VDCActive_sat' */
      u0 = rtb_ESP_VDCActive_sat;
      rtb_ESP_VDCActive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S218>/ESP_VehicleStandstill_Convert' */
      rtb_ESP_VehicleStandstill_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_dj[3];

      /* S-Function (sfix_bitop): '<S218>/ESP_VehicleStandstill_L' */
      rtb_ESP_VehicleStandstill_L &= 64U;

      /* ArithShift: '<S218>/ESP_VehicleStandstill_S' */
      rtb_ESP_VehicleStandstill_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleStandstill_L >> 6);

      /* Saturate: '<S218>/ESP_VehicleStandstill_sat' */
      u0 = rtb_ESP_VehicleStandstill_L;
      rtb_ESP_VehicleStandstill_L = (int32_T)u0;

      /* SignalConversion: '<S217>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_BrakeForce = rtb_ESP_BrakeForce_sat;

      /* SignalConversion: '<S217>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_PrefillAvailable =
        rtb_ESP_PrefillAvailable_sat;

      /* SignalConversion: '<S217>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_PrefillActive =
        rtb_ESP_PrefillActive_sat;

      /* SignalConversion: '<S217>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_BrakeOverHeat =
        rtb_ESP_BrakeOverHeat_sat;

      /* SignalConversion: '<S217>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_CDD_Active = rtb_ESP_CDD_Active_sat;

      /* SignalConversion: '<S217>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_CDD_Available =
        rtb_ESP_CDD_Available_sat;

      /* SignalConversion: '<S217>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_CDD_Active_APA = 0.0;

      /* SignalConversion: '<S217>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_VehicleStandstill =
        rtb_ESP_VehicleStandstill_L;

      /* SignalConversion: '<S217>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_CDD_Available_APA = 0.0;

      /* SignalConversion: '<S217>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_RollingCounter_277 =
        rtb_ESP_RollingCounter_277_sat;

      /* SignalConversion: '<S217>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_CheckSum_277 = rtb_ESP_CheckSum_277_sat;

      /* SignalConversion: '<S217>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_VDCActive = rtb_ESP_VDCActive_sat;

      /* SignalConversion: '<S217>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_TCSActive = rtb_ESP_TCSActive_sat;

      /* SignalConversion: '<S217>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_AWBavailable = rtb_ESP_AWBavailable_sat;

      /* SignalConversion: '<S217>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_AWBactive = rtb_ESP_AWBactive_sat;

      /* SignalConversion: '<S217>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_AEBdecActive = rtb_ESP_AEBdecActive_sat;

      /* SignalConversion: '<S217>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_AEBAvailable = rtb_ESP_AEBAvailable_sat;

      /* SignalConversion: '<S217>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_ABAavailable = rtb_ESP_ABAavailable_sat;

      /* SignalConversion: '<S217>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_ABAactive = rtb_ESP_ABAactive_sat;
    }

    /* End of Outputs for SubSystem: '<S216>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S91>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF16RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf16looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_iy= 640;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_e= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_ix= ec_can_receive(1,16,
      CAN1BUF16RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_is[0]=
      CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_is[1]=
      CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_is[2]=
      CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_is[3]=
      CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_is[4]=
      CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_is[5]=
      CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_is[6]=
      CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_is[7]=
      CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
  }

  /* Call the system: <S91>/ReceiveMessages */

  /* Output and update for function-call system: '<S91>/ReceiveMessages' */
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

    /* Outputs for Enabled SubSystem: '<S238>/Subsystem' incorporates:
     *  EnablePort: '<S239>/Enable'
     */
    if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_ix > 0) {
      /* Product: '<S240>/Wheel_Speed_FL_Datainput7_P' incorporates:
       *  Constant: '<S240>/Wheel_Speed_FL_Datainput7_C'
       */
      rtb_Wheel_Speed_FL_Data_sat = (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_is[6] * 256.0;

      /* Sum: '<S240>/Wheel_Speed_FL_Datainput7_Ad' */
      rtb_Wheel_Speed_FR_Data_sat = rtb_Wheel_Speed_FL_Data_sat + (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_is[7];

      /* DataTypeConversion: '<S240>/Wheel_Speed_FL_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)rtb_Wheel_Speed_FR_Data_sat;

      /* S-Function (sfix_bitop): '<S240>/Wheel_Speed_FL_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 8191U;

      /* DataTypeConversion: '<S240>/Wheel_Speed_FL_Datacv' */
      rtb_Wheel_Speed_FR_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Gain: '<S240>/Wheel_Speed_FL_Data_F' */
      rtb_Wheel_Speed_FR_Data_sat *= 0.05625;

      /* Sum: '<S240>/Wheel_Speed_FL_Data_Ad' */
      rtb_Wheel_Speed_FL_Data_sat = rtb_Wheel_Speed_FR_Data_sat;

      /* Saturate: '<S240>/Wheel_Speed_FL_Data_sat' */
      if (rtb_Wheel_Speed_FL_Data_sat > 360.0) {
        rtb_Wheel_Speed_FL_Data_sat = 360.0;
      }

      /* End of Saturate: '<S240>/Wheel_Speed_FL_Data_sat' */

      /* DataTypeConversion: '<S240>/Wheel_Speed_FL_Direction_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_is[6];

      /* S-Function (sfix_bitop): '<S240>/Wheel_Speed_FL_Direction_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 96U;

      /* ArithShift: '<S240>/Wheel_Speed_FL_Direction_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 5);

      /* DataTypeConversion: '<S240>/Wheel_Speed_FL_Directioncv' */
      rtb_Wheel_Speed_FR_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S240>/Wheel_Speed_FL_Direction_Ad' */
      rtb_Wheel_Speed_FL_Direction_sa = (int32_T)rtb_Wheel_Speed_FR_Data_sat;

      /* Saturate: '<S240>/Wheel_Speed_FL_Direction_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_FL_Direction_sa;
      rtb_Wheel_Speed_FL_Direction_sa = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* DataTypeConversion: '<S240>/Wheel_Speed_FL_Valid_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_is[6];

      /* S-Function (sfix_bitop): '<S240>/Wheel_Speed_FL_Valid_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 128U;

      /* ArithShift: '<S240>/Wheel_Speed_FL_Valid_Data_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 7);

      /* DataTypeConversion: '<S240>/Wheel_Speed_FL_Valid_Datacv' */
      rtb_Wheel_Speed_FR_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S240>/Wheel_Speed_FL_Valid_Data_Ad' */
      rtb_Wheel_Speed_FL_Valid_Data_s = (int32_T)rtb_Wheel_Speed_FR_Data_sat;

      /* Saturate: '<S240>/Wheel_Speed_FL_Valid_Data_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_FL_Valid_Data_s;
      rtb_Wheel_Speed_FL_Valid_Data_s = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* Product: '<S240>/Wheel_Speed_FR_Datainput5_P' incorporates:
       *  Constant: '<S240>/Wheel_Speed_FR_Datainput5_C'
       */
      rtb_Wheel_Speed_FR_Data_sat = (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_is[4] * 256.0;

      /* Sum: '<S240>/Wheel_Speed_FR_Datainput5_Ad' */
      rtb_Wheel_Speed_RL_Data_sat = rtb_Wheel_Speed_FR_Data_sat + (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_is[5];

      /* DataTypeConversion: '<S240>/Wheel_Speed_FR_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)rtb_Wheel_Speed_RL_Data_sat;

      /* S-Function (sfix_bitop): '<S240>/Wheel_Speed_FR_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 8191U;

      /* DataTypeConversion: '<S240>/Wheel_Speed_FR_Datacv' */
      rtb_Wheel_Speed_RL_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Gain: '<S240>/Wheel_Speed_FR_Data_F' */
      rtb_Wheel_Speed_RL_Data_sat *= 0.05625;

      /* Sum: '<S240>/Wheel_Speed_FR_Data_Ad' */
      rtb_Wheel_Speed_FR_Data_sat = rtb_Wheel_Speed_RL_Data_sat;

      /* Saturate: '<S240>/Wheel_Speed_FR_Data_sat' */
      if (rtb_Wheel_Speed_FR_Data_sat > 360.0) {
        rtb_Wheel_Speed_FR_Data_sat = 360.0;
      }

      /* End of Saturate: '<S240>/Wheel_Speed_FR_Data_sat' */

      /* DataTypeConversion: '<S240>/Wheel_Speed_FR_Direction_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_is[4];

      /* S-Function (sfix_bitop): '<S240>/Wheel_Speed_FR_Direction_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 96U;

      /* ArithShift: '<S240>/Wheel_Speed_FR_Direction_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 5);

      /* DataTypeConversion: '<S240>/Wheel_Speed_FR_Directioncv' */
      rtb_Wheel_Speed_RL_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S240>/Wheel_Speed_FR_Direction_Ad' */
      rtb_Wheel_Speed_FR_Direction_sa = (int32_T)rtb_Wheel_Speed_RL_Data_sat;

      /* Saturate: '<S240>/Wheel_Speed_FR_Direction_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_FR_Direction_sa;
      rtb_Wheel_Speed_FR_Direction_sa = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* DataTypeConversion: '<S240>/Wheel_Speed_FR_Valid_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_is[4];

      /* S-Function (sfix_bitop): '<S240>/Wheel_Speed_FR_Valid_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 128U;

      /* ArithShift: '<S240>/Wheel_Speed_FR_Valid_Data_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 7);

      /* DataTypeConversion: '<S240>/Wheel_Speed_FR_Valid_Datacv' */
      rtb_Wheel_Speed_RL_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S240>/Wheel_Speed_FR_Valid_Data_Ad' */
      rtb_Wheel_Speed_FR_Valid_Data_s = (int32_T)rtb_Wheel_Speed_RL_Data_sat;

      /* Saturate: '<S240>/Wheel_Speed_FR_Valid_Data_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_FR_Valid_Data_s;
      rtb_Wheel_Speed_FR_Valid_Data_s = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* Product: '<S240>/Wheel_Speed_RL_Datainput3_P' incorporates:
       *  Constant: '<S240>/Wheel_Speed_RL_Datainput3_C'
       */
      rtb_Wheel_Speed_RL_Data_sat = (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_is[2] * 256.0;

      /* Sum: '<S240>/Wheel_Speed_RL_Datainput3_Ad' */
      rtb_Wheel_Speed_RR_Data_sat = rtb_Wheel_Speed_RL_Data_sat + (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_is[3];

      /* DataTypeConversion: '<S240>/Wheel_Speed_RL_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)rtb_Wheel_Speed_RR_Data_sat;

      /* S-Function (sfix_bitop): '<S240>/Wheel_Speed_RL_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 8191U;

      /* DataTypeConversion: '<S240>/Wheel_Speed_RL_Datacv' */
      rtb_Wheel_Speed_RR_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Gain: '<S240>/Wheel_Speed_RL_Data_F' */
      rtb_Wheel_Speed_RR_Data_sat *= 0.05625;

      /* Sum: '<S240>/Wheel_Speed_RL_Data_Ad' */
      rtb_Wheel_Speed_RL_Data_sat = rtb_Wheel_Speed_RR_Data_sat;

      /* Saturate: '<S240>/Wheel_Speed_RL_Data_sat' */
      if (rtb_Wheel_Speed_RL_Data_sat > 360.0) {
        rtb_Wheel_Speed_RL_Data_sat = 360.0;
      }

      /* End of Saturate: '<S240>/Wheel_Speed_RL_Data_sat' */

      /* DataTypeConversion: '<S240>/Wheel_Speed_RL_Direction_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_is[2];

      /* S-Function (sfix_bitop): '<S240>/Wheel_Speed_RL_Direction_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 96U;

      /* ArithShift: '<S240>/Wheel_Speed_RL_Direction_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 5);

      /* DataTypeConversion: '<S240>/Wheel_Speed_RL_Directioncv' */
      rtb_Wheel_Speed_RR_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S240>/Wheel_Speed_RL_Direction_Ad' */
      rtb_Wheel_Speed_RL_Direction_sa = (int32_T)rtb_Wheel_Speed_RR_Data_sat;

      /* Saturate: '<S240>/Wheel_Speed_RL_Direction_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RL_Direction_sa;
      rtb_Wheel_Speed_RL_Direction_sa = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* DataTypeConversion: '<S240>/Wheel_Speed_RL_Valid_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_is[2];

      /* S-Function (sfix_bitop): '<S240>/Wheel_Speed_RL_Valid_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 128U;

      /* ArithShift: '<S240>/Wheel_Speed_RL_Valid_Data_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 7);

      /* DataTypeConversion: '<S240>/Wheel_Speed_RL_Valid_Datacv' */
      rtb_Wheel_Speed_RR_Data_sat = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S240>/Wheel_Speed_RL_Valid_Data_Ad' */
      rtb_Wheel_Speed_RL_Valid_Data_s = (int32_T)rtb_Wheel_Speed_RR_Data_sat;

      /* Saturate: '<S240>/Wheel_Speed_RL_Valid_Data_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RL_Valid_Data_s;
      rtb_Wheel_Speed_RL_Valid_Data_s = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* Product: '<S240>/Wheel_Speed_RR_Datainput1_P' incorporates:
       *  Constant: '<S240>/Wheel_Speed_RR_Datainput1_C'
       */
      rtb_Wheel_Speed_RR_Data_sat = (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_is[0] * 256.0;

      /* Sum: '<S240>/Wheel_Speed_RR_Datainput1_Ad' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RR_Data_sat + (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_is[1];

      /* DataTypeConversion: '<S240>/Wheel_Speed_RR_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* S-Function (sfix_bitop): '<S240>/Wheel_Speed_RR_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 8191U;

      /* DataTypeConversion: '<S240>/Wheel_Speed_RR_Datacv' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Gain: '<S240>/Wheel_Speed_RR_Data_F' */
      rtb_Wheel_Speed_RR_Valid_Datacv *= 0.05625;

      /* Sum: '<S240>/Wheel_Speed_RR_Data_Ad' */
      rtb_Wheel_Speed_RR_Data_sat = rtb_Wheel_Speed_RR_Valid_Datacv;

      /* Saturate: '<S240>/Wheel_Speed_RR_Data_sat' */
      if (rtb_Wheel_Speed_RR_Data_sat > 360.0) {
        rtb_Wheel_Speed_RR_Data_sat = 360.0;
      }

      /* End of Saturate: '<S240>/Wheel_Speed_RR_Data_sat' */

      /* DataTypeConversion: '<S240>/Wheel_Speed_RR_Direction_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_is[0];

      /* S-Function (sfix_bitop): '<S240>/Wheel_Speed_RR_Direction_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 96U;

      /* ArithShift: '<S240>/Wheel_Speed_RR_Direction_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 5);

      /* DataTypeConversion: '<S240>/Wheel_Speed_RR_Directioncv' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* Sum: '<S240>/Wheel_Speed_RR_Direction_Ad' */
      rtb_Wheel_Speed_RR_Direction_sa = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* Saturate: '<S240>/Wheel_Speed_RR_Direction_sat' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RR_Direction_sa;
      rtb_Wheel_Speed_RR_Direction_sa = (int32_T)rtb_Wheel_Speed_RR_Valid_Datacv;

      /* DataTypeConversion: '<S240>/Wheel_Speed_RR_Valid_Data_Convert' */
      rtb_Wheel_Speed_RR_Valid_Data_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_is[0];

      /* S-Function (sfix_bitop): '<S240>/Wheel_Speed_RR_Valid_Data_L' */
      rtb_Wheel_Speed_RR_Valid_Data_L &= 128U;

      /* ArithShift: '<S240>/Wheel_Speed_RR_Valid_Data_S' */
      rtb_Wheel_Speed_RR_Valid_Data_L = (int32_T)((uint32_T)
        rtb_Wheel_Speed_RR_Valid_Data_L >> 7);

      /* DataTypeConversion: '<S240>/Wheel_Speed_RR_Valid_Datacv' */
      rtb_Wheel_Speed_RR_Valid_Datacv = rtb_Wheel_Speed_RR_Valid_Data_L;

      /* SignalConversion: '<S239>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.Wheel_Speed_RR =
        rtb_Wheel_Speed_RR_Data_sat;

      /* SignalConversion: '<S239>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.Wheel_Speed_FL =
        rtb_Wheel_Speed_FL_Data_sat;

      /* SignalConversion: '<S239>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.Wheel_Speed_FL_Direction =
        rtb_Wheel_Speed_FL_Direction_sa;

      /* SignalConversion: '<S239>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.Wheel_Speed_FL_Valid =
        rtb_Wheel_Speed_FL_Valid_Data_s;

      /* SignalConversion: '<S239>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.Wheel_Speed_RR_Direction =
        rtb_Wheel_Speed_RR_Direction_sa;

      /* SignalConversion: '<S239>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.Wheel_Speed_RR_Valid =
        rtb_Wheel_Speed_RR_Valid_Datacv;

      /* SignalConversion: '<S239>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.Wheel_Speed_RL =
        rtb_Wheel_Speed_RL_Data_sat;

      /* SignalConversion: '<S239>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.Wheel_Speed_RL_Direction =
        rtb_Wheel_Speed_RL_Direction_sa;

      /* SignalConversion: '<S239>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.Wheel_Speed_RL_Valid =
        rtb_Wheel_Speed_RL_Valid_Data_s;

      /* SignalConversion: '<S239>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.Wheel_Speed_FR =
        rtb_Wheel_Speed_FR_Data_sat;

      /* SignalConversion: '<S239>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.Wheel_Speed_FR_Direction =
        rtb_Wheel_Speed_FR_Direction_sa;

      /* SignalConversion: '<S239>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.Wheel_Speed_FR_Valid =
        rtb_Wheel_Speed_FR_Valid_Data_s;
    }

    /* End of Outputs for SubSystem: '<S238>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S92>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF17RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf17looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_d= 641;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_kr= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_f= ec_can_receive(1,17,
      CAN1BUF17RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jzv[0]=
      CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jzv[1]=
      CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jzv[2]=
      CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jzv[3]=
      CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jzv[4]=
      CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jzv[5]=
      CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jzv[6]=
      CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jzv[7]=
      CAN1BUF17RX[can1buf17looprx];
    can1buf17looprx++;
  }

  /* Call the system: <S92>/ReceiveMessages */

  /* Output and update for function-call system: '<S92>/ReceiveMessages' */
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

    /* Outputs for Enabled SubSystem: '<S253>/Subsystem' incorporates:
     *  EnablePort: '<S254>/Enable'
     */
    if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_f > 0) {
      /* DataTypeConversion: '<S255>/ESP_ABSActiveStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jzv[0];

      /* S-Function (sfix_bitop): '<S255>/ESP_ABSActiveStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 128U;

      /* ArithShift: '<S255>/ESP_ABSActiveStatus_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 7);

      /* DataTypeConversion: '<S255>/ESP_ABSActiveStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S255>/ESP_ABSActiveStatus_Ad' */
      rtb_ESP_ABSActiveStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S255>/ESP_ABSActiveStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_ABSActiveStatus_sat;
      rtb_ESP_ABSActiveStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S255>/ESP_ABSFailStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jzv[0];

      /* S-Function (sfix_bitop): '<S255>/ESP_ABSFailStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 8U;

      /* ArithShift: '<S255>/ESP_ABSFailStatus_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 3);

      /* DataTypeConversion: '<S255>/ESP_ABSFailStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S255>/ESP_ABSFailStatus_Ad' */
      rtb_ESP_ABSFailStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S255>/ESP_ABSFailStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_ABSFailStatus_sat;
      rtb_ESP_ABSFailStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S255>/ESP_BrakePedalStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jzv[6];

      /* S-Function (sfix_bitop): '<S255>/ESP_BrakePedalStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 96U;

      /* ArithShift: '<S255>/ESP_BrakePedalStatus_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 5);

      /* DataTypeConversion: '<S255>/ESP_BrakePedalStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S255>/ESP_BrakePedalStatus_Ad' */
      rtb_ESP_BrakePedalStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S255>/ESP_BrakePedalStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_BrakePedalStatus_sat;
      rtb_ESP_BrakePedalStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S255>/ESP_Checksum_Convert' */
      rtb_ESP_VehicleSpeed_Status_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jzv[7];

      /* DataTypeConversion: '<S255>/ESP_Checksumcv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S255>/ESP_Checksum_Ad' */
      rtb_ESP_Checksum_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S255>/ESP_Checksum_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_Checksum_sat;
      rtb_ESP_Checksum_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S255>/ESP_EBDFailStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jzv[0];

      /* S-Function (sfix_bitop): '<S255>/ESP_EBDFailStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 4U;

      /* ArithShift: '<S255>/ESP_EBDFailStatus_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 2);

      /* DataTypeConversion: '<S255>/ESP_EBDFailStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S255>/ESP_EBDFailStatus_Ad' */
      rtb_ESP_EBDFailStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S255>/ESP_EBDFailStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_EBDFailStatus_sat;
      rtb_ESP_EBDFailStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S255>/ESP_ESPActiveStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jzv[0];

      /* S-Function (sfix_bitop): '<S255>/ESP_ESPActiveStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 1U;

      /* DataTypeConversion: '<S255>/ESP_ESPActiveStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S255>/ESP_ESPActiveStatus_Ad' */
      rtb_ESP_ESPActiveStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S255>/ESP_ESPActiveStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_ESPActiveStatus_sat;
      rtb_ESP_ESPActiveStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S255>/ESP_ESPFailStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jzv[0];

      /* S-Function (sfix_bitop): '<S255>/ESP_ESPFailStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 16U;

      /* ArithShift: '<S255>/ESP_ESPFailStatus_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 4);

      /* DataTypeConversion: '<S255>/ESP_ESPFailStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S255>/ESP_ESPFailStatus_Ad' */
      rtb_ESP_ESPFailStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S255>/ESP_ESPFailStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_ESPFailStatus_sat;
      rtb_ESP_ESPFailStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S255>/ESP_ESPSwitchStatus_Convert' */
      rtb_ESP_VehicleSpeed_Status_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jzv[0];

      /* S-Function (sfix_bitop): '<S255>/ESP_ESPSwitchStatus_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 2U;

      /* ArithShift: '<S255>/ESP_ESPSwitchStatus_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 1);

      /* DataTypeConversion: '<S255>/ESP_ESPSwitchStatuscv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S255>/ESP_ESPSwitchStatus_Ad' */
      rtb_ESP_ESPSwitchStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S255>/ESP_ESPSwitchStatus_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_ESPSwitchStatus_sat;
      rtb_ESP_ESPSwitchStatus_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* DataTypeConversion: '<S255>/ESP_RollingCounter_Convert' */
      rtb_ESP_VehicleSpeed_Status_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jzv[6];

      /* S-Function (sfix_bitop): '<S255>/ESP_RollingCounter_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 15U;

      /* DataTypeConversion: '<S255>/ESP_RollingCountercv' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Status_L;

      /* Sum: '<S255>/ESP_RollingCounter_Ad' */
      rtb_ESP_RollingCounter_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Saturate: '<S255>/ESP_RollingCounter_sat' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_RollingCounter_sat;
      rtb_ESP_RollingCounter_sat = (int32_T)rtb_ESP_VehicleSpeed_sat;

      /* Product: '<S255>/ESP_VehicleSpeedinput5_P' incorporates:
       *  Constant: '<S255>/ESP_VehicleSpeedinput5_C'
       */
      rtb_ESP_VehicleSpeed_sat = (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jzv[4] * 256.0;

      /* Sum: '<S255>/ESP_VehicleSpeedinput5_Ad' */
      rtb_ESP_VehicleSpeed_Statuscv = rtb_ESP_VehicleSpeed_sat + (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jzv[5];

      /* DataTypeConversion: '<S255>/ESP_VehicleSpeed_Convert' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)rtb_ESP_VehicleSpeed_Statuscv;

      /* S-Function (sfix_bitop): '<S255>/ESP_VehicleSpeed_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 8191U;

      /* DataTypeConversion: '<S255>/ESP_VehicleSpeedcv' */
      rtb_ESP_VehicleSpeed_Statuscv = rtb_ESP_VehicleSpeed_Status_L;

      /* Gain: '<S255>/ESP_VehicleSpeed_F' */
      rtb_ESP_VehicleSpeed_Statuscv *= 0.05625;

      /* Sum: '<S255>/ESP_VehicleSpeed_Ad' */
      rtb_ESP_VehicleSpeed_sat = rtb_ESP_VehicleSpeed_Statuscv;

      /* DataTypeConversion: '<S255>/ESP_VehicleSpeed_Status_Convert' */
      rtb_ESP_VehicleSpeed_Status_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_jzv[4];

      /* S-Function (sfix_bitop): '<S255>/ESP_VehicleSpeed_Status_L' */
      rtb_ESP_VehicleSpeed_Status_L &= 32U;

      /* ArithShift: '<S255>/ESP_VehicleSpeed_Status_S' */
      rtb_ESP_VehicleSpeed_Status_L = (int32_T)((uint32_T)
        rtb_ESP_VehicleSpeed_Status_L >> 5);

      /* DataTypeConversion: '<S255>/ESP_VehicleSpeed_Statuscv' */
      rtb_ESP_VehicleSpeed_Statuscv = rtb_ESP_VehicleSpeed_Status_L;

      /* Saturate: '<S255>/ESP_VehicleSpeed_sat' */
      if (rtb_ESP_VehicleSpeed_sat > 360.0) {
        rtb_ESP_VehicleSpeed_sat = 360.0;
      }

      /* End of Saturate: '<S255>/ESP_VehicleSpeed_sat' */

      /* SignalConversion: '<S254>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_ESPActiveStatus_n =
        rtb_ESP_ESPActiveStatus_sat;

      /* SignalConversion: '<S254>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_BrakePedalStatus =
        rtb_ESP_BrakePedalStatus_sat;

      /* SignalConversion: '<S254>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_Checksum = rtb_ESP_Checksum_sat;

      /* SignalConversion: '<S254>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_ESPSwitchStatus =
        rtb_ESP_ESPSwitchStatus_sat;

      /* SignalConversion: '<S254>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_EBDFailStatus_l =
        rtb_ESP_EBDFailStatus_sat;

      /* SignalConversion: '<S254>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_ABSFailStatus =
        rtb_ESP_ABSFailStatus_sat;

      /* SignalConversion: '<S254>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_ESPFailStatus =
        rtb_ESP_ESPFailStatus_sat;

      /* SignalConversion: '<S254>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_ABSActiveStatus =
        rtb_ESP_ABSActiveStatus_sat;

      /* SignalConversion: '<S254>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_VehicleSpeed = rtb_ESP_VehicleSpeed_sat;

      /* SignalConversion: '<S254>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_VehicleSpeed_Status =
        rtb_ESP_VehicleSpeed_Statuscv;

      /* SignalConversion: '<S254>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_RollingCounter_p =
        rtb_ESP_RollingCounter_sat;
    }

    /* End of Outputs for SubSystem: '<S253>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S93>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF18RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf18looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_ex= 647;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_hu= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_m2= ec_can_receive(1,18,
      CAN1BUF18RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_c[0]=
      CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_c[1]=
      CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_c[2]=
      CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_c[3]=
      CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_c[4]=
      CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_c[5]=
      CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_c[6]=
      CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_c[7]=
      CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
  }

  /* Call the system: <S93>/ReceiveMessages */

  /* Output and update for function-call system: '<S93>/ReceiveMessages' */
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

    /* Outputs for Enabled SubSystem: '<S267>/Subsystem' incorporates:
     *  EnablePort: '<S268>/Enable'
     */
    if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_m2 > 0) {
      /* DataTypeConversion: '<S269>/ESP_CheckSum_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_c
        [7];

      /* S-Function (sfix_bitop): '<S269>/ESP_CheckSum_L' */
      rtb_ESP_YawRate_Status_L &= 15U;

      /* DataTypeConversion: '<S269>/ESP_CheckSumcv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S269>/ESP_CheckSum_Ad' */
      rtb_ESP_CheckSum_sat = (int32_T)rtb_ESP_LongAcceleration_sat;

      /* Saturate: '<S269>/ESP_CheckSum_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_CheckSum_sat;
      rtb_ESP_CheckSum_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* DataTypeConversion: '<S269>/ESP_HBBActiveStatus_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_c
        [6];

      /* S-Function (sfix_bitop): '<S269>/ESP_HBBActiveStatus_L' */
      rtb_ESP_YawRate_Status_L &= 8U;

      /* ArithShift: '<S269>/ESP_HBBActiveStatus_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        3);

      /* DataTypeConversion: '<S269>/ESP_HBBActiveStatuscv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S269>/ESP_HBBActiveStatus_Ad' */
      rtb_ESP_HBBActiveStatus_sat = (int32_T)rtb_ESP_LongAcceleration_sat;

      /* Saturate: '<S269>/ESP_HBBActiveStatus_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_HBBActiveStatus_sat;
      rtb_ESP_HBBActiveStatus_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* DataTypeConversion: '<S269>/ESP_HBB_Status_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_c
        [6];

      /* S-Function (sfix_bitop): '<S269>/ESP_HBB_Status_L' */
      rtb_ESP_YawRate_Status_L &= 3U;

      /* DataTypeConversion: '<S269>/ESP_HBB_Statuscv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S269>/ESP_HBB_Status_Ad' */
      rtb_ESP_HBB_Status_sat = (int32_T)rtb_ESP_LongAcceleration_sat;

      /* Saturate: '<S269>/ESP_HBB_Status_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_HBB_Status_sat;
      rtb_ESP_HBB_Status_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* DataTypeConversion: '<S269>/ESP_HDC_Status_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_c
        [0];

      /* S-Function (sfix_bitop): '<S269>/ESP_HDC_Status_L' */
      rtb_ESP_YawRate_Status_L &= 48U;

      /* ArithShift: '<S269>/ESP_HDC_Status_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        4);

      /* DataTypeConversion: '<S269>/ESP_HDC_Statuscv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S269>/ESP_HDC_Status_Ad' */
      rtb_ESP_HDC_Status_sat = (int32_T)rtb_ESP_LongAcceleration_sat;

      /* Saturate: '<S269>/ESP_HDC_Status_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_HDC_Status_sat;
      rtb_ESP_HDC_Status_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* DataTypeConversion: '<S269>/ESP_HHC_Available_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_c
        [6];

      /* S-Function (sfix_bitop): '<S269>/ESP_HHC_Available_L' */
      rtb_ESP_YawRate_Status_L &= 4U;

      /* ArithShift: '<S269>/ESP_HHC_Available_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        2);

      /* DataTypeConversion: '<S269>/ESP_HHC_Availablecv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S269>/ESP_HHC_Available_Ad' */
      rtb_ESP_HHC_Available_sat = (int32_T)rtb_ESP_LongAcceleration_sat;

      /* Saturate: '<S269>/ESP_HHC_Available_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_HHC_Available_sat;
      rtb_ESP_HHC_Available_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* DataTypeConversion: '<S269>/ESP_LatAcceleration_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_c
        [2];

      /* DataTypeConversion: '<S269>/ESP_LatAccelerationcv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Gain: '<S269>/ESP_LatAcceleration_F' */
      rtb_ESP_LongAcceleration_sat *= 0.1;

      /* Sum: '<S269>/ESP_LatAcceleration_Ad' incorporates:
       *  Constant: '<S269>/ESP_LatAcceleration_O'
       */
      rtb_ESP_LatAcceleration_sat = rtb_ESP_LongAcceleration_sat +
        -12.699999809265137;

      /* Saturate: '<S269>/ESP_LatAcceleration_sat' */
      if (rtb_ESP_LatAcceleration_sat > 12.7) {
        rtb_ESP_LatAcceleration_sat = 12.7;
      }

      /* End of Saturate: '<S269>/ESP_LatAcceleration_sat' */

      /* DataTypeConversion: '<S269>/ESP_LongAccelValid_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_c
        [6];

      /* S-Function (sfix_bitop): '<S269>/ESP_LongAccelValid_L' */
      rtb_ESP_YawRate_Status_L &= 64U;

      /* ArithShift: '<S269>/ESP_LongAccelValid_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        6);

      /* DataTypeConversion: '<S269>/ESP_LongAccelValidcv' */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S269>/ESP_LongAccelValid_Ad' */
      rtb_ESP_LongAccelValid_sat = (int32_T)rtb_ESP_LongAcceleration_sat;

      /* Saturate: '<S269>/ESP_LongAccelValid_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_LongAccelValid_sat;
      rtb_ESP_LongAccelValid_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* Product: '<S269>/ESP_LongAccelerationinput4_P' incorporates:
       *  Constant: '<S269>/ESP_LongAccelerationinput4_C'
       */
      rtb_ESP_LongAcceleration_sat = (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_c[3] * 256.0;

      /* Sum: '<S269>/ESP_LongAccelerationinput4_Ad' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_LongAcceleration_sat + (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_c[4];

      /* DataTypeConversion: '<S269>/ESP_LongAcceleration_Convert' */
      rtb_ESP_YawRate_Status_L = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* S-Function (sfix_bitop): '<S269>/ESP_LongAcceleration_L' */
      rtb_ESP_YawRate_Status_L &= 65472U;

      /* ArithShift: '<S269>/ESP_LongAcceleration_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        6);

      /* DataTypeConversion: '<S269>/ESP_LongAccelerationcv' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_YawRate_Status_L;

      /* Gain: '<S269>/ESP_LongAcceleration_F' */
      rtb_ESP_TODTorqueMaxLimit_sat *= 0.03125;

      /* Sum: '<S269>/ESP_LongAcceleration_Ad' incorporates:
       *  Constant: '<S269>/ESP_LongAcceleration_O'
       */
      rtb_ESP_LongAcceleration_sat = rtb_ESP_TODTorqueMaxLimit_sat + -16.0;

      /* DataTypeConversion: '<S269>/ESP_RollingCounter_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_c
        [7];

      /* S-Function (sfix_bitop): '<S269>/ESP_RollingCounter_L' */
      rtb_ESP_YawRate_Status_L &= 240U;

      /* ArithShift: '<S269>/ESP_RollingCounter_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        4);

      /* DataTypeConversion: '<S269>/ESP_RollingCountercv' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S269>/ESP_RollingCounter_Ad' */
      rtb_ESP_RollingCounter_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* Saturate: '<S269>/ESP_RollingCounter_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_RollingCounter_sat;
      rtb_ESP_RollingCounter_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* DataTypeConversion: '<S269>/ESP_TODFastOpenRequest_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_c
        [0];

      /* S-Function (sfix_bitop): '<S269>/ESP_TODFastOpenRequest_L' */
      rtb_ESP_YawRate_Status_L &= 192U;

      /* ArithShift: '<S269>/ESP_TODFastOpenRequest_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        6);

      /* DataTypeConversion: '<S269>/ESP_TODFastOpenRequestcv' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S269>/ESP_TODFastOpenRequest_Ad' */
      rtb_ESP_TODFastOpenRequest_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* Saturate: '<S269>/ESP_TODFastOpenRequest_sat' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_TODFastOpenRequest_sat;
      rtb_ESP_TODFastOpenRequest_sat = (int32_T)rtb_ESP_TODTorqueMaxLimit_sat;

      /* Product: '<S269>/ESP_TODTorqueMaxLimitinput1_P' incorporates:
       *  Constant: '<S269>/ESP_TODTorqueMaxLimitinput1_C'
       */
      rtb_ESP_TODTorqueMaxLimit_sat = (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_c[0] * 256.0;

      /* Sum: '<S269>/ESP_TODTorqueMaxLimitinput1_Ad' */
      rtb_ESP_YawRate_sat = rtb_ESP_TODTorqueMaxLimit_sat + (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_c[1];

      /* DataTypeConversion: '<S269>/ESP_TODTorqueMaxLimit_Convert' */
      rtb_ESP_YawRate_Status_L = (int32_T)rtb_ESP_YawRate_sat;

      /* S-Function (sfix_bitop): '<S269>/ESP_TODTorqueMaxLimit_L' */
      rtb_ESP_YawRate_Status_L &= 4095U;

      /* DataTypeConversion: '<S269>/ESP_TODTorqueMaxLimitcv' */
      rtb_ESP_YawRate_sat = rtb_ESP_YawRate_Status_L;

      /* Sum: '<S269>/ESP_TODTorqueMaxLimit_Ad' */
      rtb_ESP_TODTorqueMaxLimit_sat = rtb_ESP_YawRate_sat;

      /* Product: '<S269>/ESP_YawRateinput5_P' incorporates:
       *  Constant: '<S269>/ESP_YawRateinput5_C'
       */
      rtb_ESP_YawRate_sat = (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_c[4] * 256.0;

      /* Sum: '<S269>/ESP_YawRateinput5_Ad' */
      rtb_ESP_YawRate_Statuscv = rtb_ESP_YawRate_sat + (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_c[5];

      /* DataTypeConversion: '<S269>/ESP_YawRate_Convert' */
      rtb_ESP_YawRate_Status_L = (int32_T)rtb_ESP_YawRate_Statuscv;

      /* S-Function (sfix_bitop): '<S269>/ESP_YawRate_L' */
      rtb_ESP_YawRate_Status_L &= 16383U;

      /* DataTypeConversion: '<S269>/ESP_YawRatecv' */
      rtb_ESP_YawRate_Statuscv = rtb_ESP_YawRate_Status_L;

      /* Gain: '<S269>/ESP_YawRate_F' */
      rtb_ESP_YawRate_Statuscv *= 0.01;

      /* Sum: '<S269>/ESP_YawRate_Ad' incorporates:
       *  Constant: '<S269>/ESP_YawRate_O'
       */
      rtb_ESP_YawRate_sat = rtb_ESP_YawRate_Statuscv + -81.910003662109375;

      /* DataTypeConversion: '<S269>/ESP_YawRate_Status_Convert' */
      rtb_ESP_YawRate_Status_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_c
        [6];

      /* S-Function (sfix_bitop): '<S269>/ESP_YawRate_Status_L' */
      rtb_ESP_YawRate_Status_L &= 128U;

      /* ArithShift: '<S269>/ESP_YawRate_Status_S' */
      rtb_ESP_YawRate_Status_L = (int32_T)((uint32_T)rtb_ESP_YawRate_Status_L >>
        7);

      /* DataTypeConversion: '<S269>/ESP_YawRate_Statuscv' */
      rtb_ESP_YawRate_Statuscv = rtb_ESP_YawRate_Status_L;

      /* Saturate: '<S269>/ESP_YawRate_sat' */
      if (rtb_ESP_YawRate_sat > 81.91) {
        rtb_ESP_YawRate_sat = 81.91;
      } else {
        if (rtb_ESP_YawRate_sat < -81.91) {
          rtb_ESP_YawRate_sat = -81.91;
        }
      }

      /* End of Saturate: '<S269>/ESP_YawRate_sat' */

      /* SignalConversion: '<S268>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_TODTorqueMaxLimit =
        rtb_ESP_TODTorqueMaxLimit_sat;

      /* SignalConversion: '<S268>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_LongAccelValid =
        rtb_ESP_LongAccelValid_sat;

      /* SignalConversion: '<S268>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_YawRate_Status =
        rtb_ESP_YawRate_Statuscv;

      /* SignalConversion: '<S268>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_CheckSum = rtb_ESP_CheckSum_sat;

      /* SignalConversion: '<S268>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_RollingCounter =
        rtb_ESP_RollingCounter_sat;

      /* SignalConversion: '<S268>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_HDC_Status = rtb_ESP_HDC_Status_sat;

      /* SignalConversion: '<S268>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_TODFastOpenRequest =
        rtb_ESP_TODFastOpenRequest_sat;

      /* SignalConversion: '<S268>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_LatAcceleration =
        rtb_ESP_LatAcceleration_sat;

      /* SignalConversion: '<S268>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_LongAcceleration =
        rtb_ESP_LongAcceleration_sat;

      /* SignalConversion: '<S268>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_YawRate = rtb_ESP_YawRate_sat;

      /* SignalConversion: '<S268>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_HBB_Status = rtb_ESP_HBB_Status_sat;

      /* SignalConversion: '<S268>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_HHC_Available_h =
        rtb_ESP_HHC_Available_sat;

      /* SignalConversion: '<S268>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_HBBActiveStatus =
        rtb_ESP_HBBActiveStatus_sat;
    }

    /* End of Outputs for SubSystem: '<S267>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S94>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF27RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf27looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_nd= 523;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_dk= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_k= ec_can_receive(1,27,
      CAN1BUF27RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_og[0]=
      CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_og[1]=
      CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_og[2]=
      CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_og[3]=
      CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_og[4]=
      CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_og[5]=
      CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_og[6]=
      CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_og[7]=
      CAN1BUF27RX[can1buf27looprx];
    can1buf27looprx++;
  }

  /* Call the system: <S94>/ReceiveMessages */

  /* Output and update for function-call system: '<S94>/ReceiveMessages' */
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

    /* Outputs for Enabled SubSystem: '<S283>/Subsystem' incorporates:
     *  EnablePort: '<S284>/Enable'
     */
    if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_k > 0) {
      /* Product: '<S285>/SAS_SteeringAngleinput4_P' incorporates:
       *  Constant: '<S285>/SAS_SteeringAngleinput4_C'
       */
      rtb_SAS_SteeringAngle_sat = (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_og[3] * 256.0;

      /* Sum: '<S285>/SAS_SteeringAngleinput4_Ad' */
      rtb_TCU_ShiftPostionValidcv = rtb_SAS_SteeringAngle_sat + (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_og[4];

      /* DataTypeConversion: '<S285>/SAS_SteeringAngle_Convert' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)rtb_TCU_ShiftPostionValidcv;

      /* DataTypeConversion: '<S285>/SAS_SteeringAnglecv' */
      rtb_SAS_SteeringAnglesubcon = (real32_T)rtb_TCU_ShiftPostionValid_L;

      /* RelationalOperator: '<S285>/SAS_SteeringAngleROP' */
      rtb_SAS_SteeringAngleROP = (rtb_SAS_SteeringAnglesubcon >= 32768.0F);

      /* Switch: '<S285>/SAS_SteeringAngleSW' */
      if (rtb_SAS_SteeringAngleROP) {
        /* Sum: '<S285>/SAS_SteeringAnglesubcon' */
        rtb_SAS_SteeringAnglesubcon = 65536.0F - rtb_SAS_SteeringAnglesubcon;

        /* UnaryMinus: '<S285>/SAS_SteeringAngleMinus' */
        rtb_SAS_SteeringAnglesubcon = -rtb_SAS_SteeringAnglesubcon;
      }

      /* End of Switch: '<S285>/SAS_SteeringAngleSW' */

      /* DataTypeConversion: '<S285>/Data Type Conversion' */
      rtb_TCU_ShiftPostionValidcv = rtb_SAS_SteeringAnglesubcon;

      /* DataTypeConversion: '<S285>/EMS_BrakePedalStatus_Convert' */
      rtb_TCU_ShiftPostionValid_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_og[0];

      /* S-Function (sfix_bitop): '<S285>/EMS_BrakePedalStatus_L' */
      rtb_TCU_ShiftPostionValid_L &= 192U;

      /* ArithShift: '<S285>/EMS_BrakePedalStatus_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 6);

      /* DataTypeConversion: '<S285>/EMS_BrakePedalStatuscv' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S285>/EMS_BrakePedalStatus_Ad' */
      rtb_EMS_BrakePedalStatus_sat = (int32_T)rtb_SAS_SteeringAngle_sat;

      /* Saturate: '<S285>/EMS_BrakePedalStatus_sat' */
      u0 = rtb_EMS_BrakePedalStatus_sat;
      rtb_EMS_BrakePedalStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S285>/EMS_EngineStartupEnd_Convert' */
      rtb_TCU_ShiftPostionValid_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_og[1];

      /* S-Function (sfix_bitop): '<S285>/EMS_EngineStartupEnd_L' */
      rtb_TCU_ShiftPostionValid_L &= 48U;

      /* ArithShift: '<S285>/EMS_EngineStartupEnd_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 4);

      /* DataTypeConversion: '<S285>/EMS_EngineStartupEndcv' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S285>/EMS_EngineStartupEnd_Ad' */
      rtb_EMS_EngineStartupEnd_sat = (int32_T)rtb_SAS_SteeringAngle_sat;

      /* Saturate: '<S285>/EMS_EngineStartupEnd_sat' */
      u0 = rtb_EMS_EngineStartupEnd_sat;
      rtb_EMS_EngineStartupEnd_sat = (int32_T)u0;

      /* DataTypeConversion: '<S285>/EMS_EngineStatus_Convert' */
      rtb_TCU_ShiftPostionValid_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_og[0];

      /* S-Function (sfix_bitop): '<S285>/EMS_EngineStatus_L' */
      rtb_TCU_ShiftPostionValid_L &= 48U;

      /* ArithShift: '<S285>/EMS_EngineStatus_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 4);

      /* DataTypeConversion: '<S285>/EMS_EngineStatuscv' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S285>/EMS_EngineStatus_Ad' */
      rtb_EMS_EngineStatus_sat = (int32_T)rtb_SAS_SteeringAngle_sat;

      /* Saturate: '<S285>/EMS_EngineStatus_sat' */
      u0 = rtb_EMS_EngineStatus_sat;
      rtb_EMS_EngineStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S285>/EPB_BrakeLightOnRequest_Convert' */
      rtb_TCU_ShiftPostionValid_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_og[5];

      /* S-Function (sfix_bitop): '<S285>/EPB_BrakeLightOnRequest_L' */
      rtb_TCU_ShiftPostionValid_L &= 6U;

      /* ArithShift: '<S285>/EPB_BrakeLightOnRequest_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 1);

      /* DataTypeConversion: '<S285>/EPB_BrakeLightOnRequestcv' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S285>/EPB_BrakeLightOnRequest_Ad' */
      rtb_EPB_BrakeLightOnRequest_sat = (int32_T)rtb_SAS_SteeringAngle_sat;

      /* Saturate: '<S285>/EPB_BrakeLightOnRequest_sat' */
      u0 = rtb_EPB_BrakeLightOnRequest_sat;
      rtb_EPB_BrakeLightOnRequest_sat = (int32_T)u0;

      /* DataTypeConversion: '<S285>/EPB_Status_Convert' */
      rtb_TCU_ShiftPostionValid_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_og[6];

      /* S-Function (sfix_bitop): '<S285>/EPB_Status_L' */
      rtb_TCU_ShiftPostionValid_L &= 192U;

      /* ArithShift: '<S285>/EPB_Status_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 6);

      /* DataTypeConversion: '<S285>/EPB_Statuscv' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S285>/EPB_Status_Ad' */
      rtb_EPB_Status_sat_h = (int32_T)rtb_SAS_SteeringAngle_sat;

      /* Saturate: '<S285>/EPB_Status_sat' */
      u0 = rtb_EPB_Status_sat_h;
      rtb_EPB_Status_sat_h = (int32_T)u0;

      /* DataTypeConversion: '<S285>/SAS_SteeringAngleValid_Convert' */
      rtb_TCU_ShiftPostionValid_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_og[0];

      /* S-Function (sfix_bitop): '<S285>/SAS_SteeringAngleValid_L' */
      rtb_TCU_ShiftPostionValid_L &= 1U;

      /* DataTypeConversion: '<S285>/SAS_SteeringAngleValidcv' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S285>/SAS_SteeringAngleValid_Ad' */
      rtb_SAS_SteeringAngleValid_sat = (int32_T)rtb_SAS_SteeringAngle_sat;

      /* Saturate: '<S285>/SAS_SteeringAngleValid_sat' */
      u0 = rtb_SAS_SteeringAngleValid_sat;
      rtb_SAS_SteeringAngleValid_sat = (int32_T)u0;

      /* Gain: '<S285>/SAS_SteeringAngle_F' */
      rtb_TCU_ShiftPostionValidcv *= 0.1;

      /* Sum: '<S285>/SAS_SteeringAngle_Ad' */
      rtb_SAS_SteeringAngle_sat = rtb_TCU_ShiftPostionValidcv;

      /* Saturate: '<S285>/SAS_SteeringAngle_sat' */
      if (rtb_SAS_SteeringAngle_sat > 780.0) {
        rtb_SAS_SteeringAngle_sat = 780.0;
      } else {
        if (rtb_SAS_SteeringAngle_sat < -780.0) {
          rtb_SAS_SteeringAngle_sat = -780.0;
        }
      }

      /* End of Saturate: '<S285>/SAS_SteeringAngle_sat' */

      /* DataTypeConversion: '<S285>/TCU_GearShiftPositon_Convert' */
      rtb_TCU_ShiftPostionValid_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_og[5];

      /* S-Function (sfix_bitop): '<S285>/TCU_GearShiftPositon_L' */
      rtb_TCU_ShiftPostionValid_L &= 120U;

      /* ArithShift: '<S285>/TCU_GearShiftPositon_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 3);

      /* DataTypeConversion: '<S285>/TCU_GearShiftPositoncv' */
      rtb_TCU_ShiftPostionValidcv = rtb_TCU_ShiftPostionValid_L;

      /* Sum: '<S285>/TCU_GearShiftPositon_Ad' */
      rtb_TCU_GearShiftPositon_sat = (int32_T)rtb_TCU_ShiftPostionValidcv;

      /* Saturate: '<S285>/TCU_GearShiftPositon_sat' */
      u0 = rtb_TCU_GearShiftPositon_sat;
      rtb_TCU_GearShiftPositon_sat = (int32_T)u0;

      /* DataTypeConversion: '<S285>/TCU_ShiftPostionValid_Convert' */
      rtb_TCU_ShiftPostionValid_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_og[5];

      /* S-Function (sfix_bitop): '<S285>/TCU_ShiftPostionValid_L' */
      rtb_TCU_ShiftPostionValid_L &= 128U;

      /* ArithShift: '<S285>/TCU_ShiftPostionValid_S' */
      rtb_TCU_ShiftPostionValid_L = (int32_T)((uint32_T)
        rtb_TCU_ShiftPostionValid_L >> 7);

      /* DataTypeConversion: '<S285>/TCU_ShiftPostionValidcv' */
      rtb_TCU_ShiftPostionValidcv = rtb_TCU_ShiftPostionValid_L;

      /* SignalConversion: '<S284>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.SAS_SteeringAngleValid_j =
        rtb_SAS_SteeringAngleValid_sat;

      /* SignalConversion: '<S284>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_EngineStatus = rtb_EMS_EngineStatus_sat;

      /* SignalConversion: '<S284>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_BrakePedalStatus_o =
        rtb_EMS_BrakePedalStatus_sat;

      /* SignalConversion: '<S284>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_EngineStartupEnd =
        rtb_EMS_EngineStartupEnd_sat;

      /* SignalConversion: '<S284>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.SAS_SteeringAngle_h =
        rtb_SAS_SteeringAngle_sat;

      /* SignalConversion: '<S284>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPB_BrakeLightOnRequest =
        rtb_EPB_BrakeLightOnRequest_sat;

      /* SignalConversion: '<S284>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.TCU_GearShiftPositon =
        rtb_TCU_GearShiftPositon_sat;

      /* SignalConversion: '<S284>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.TCU_ShiftPostionValid =
        rtb_TCU_ShiftPostionValidcv;

      /* SignalConversion: '<S284>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPB_Status = rtb_EPB_Status_sat_h;
    }

    /* End of Outputs for SubSystem: '<S283>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S95>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF29RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf29looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_m= 776;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_io= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_em= ec_can_receive(1,29,
      CAN1BUF29RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ga[0]=
      CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ga[1]=
      CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ga[2]=
      CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ga[3]=
      CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ga[4]=
      CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ga[5]=
      CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ga[6]=
      CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ga[7]=
      CAN1BUF29RX[can1buf29looprx];
    can1buf29looprx++;
  }

  /* Call the system: <S95>/ReceiveMessages */

  /* Output and update for function-call system: '<S95>/ReceiveMessages' */
  {
    int32_T rtb_IP_TotalOdometerinput6_Ad;
    real_T rtb_IP_TotalOdometer_sat;
    uint32_T rtb_IP_TotalOdometer_Convert;

    /* Outputs for Enabled SubSystem: '<S295>/Subsystem' incorporates:
     *  EnablePort: '<S296>/Enable'
     */
    if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_em > 0) {
      /* Product: '<S297>/IP_TotalOdometerinput6_P' incorporates:
       *  Constant: '<S297>/IP_TotalOdometerinput6_C'
       */
      rtb_IP_TotalOdometerinput6_Ad =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ga[5] << 8;

      /* Product: '<S297>/IP_TotalOdometerinput5_P' incorporates:
       *  Constant: '<S297>/IP_TotalOdometerinput5_C'
       */
      rtb_IP_TotalOdometer_sat = (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ga[4] * 65536.0;

      /* Sum: '<S297>/IP_TotalOdometerinput5_Ad' */
      rtb_IP_TotalOdometer_sat += (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ga[6];

      /* Sum: '<S297>/IP_TotalOdometerinput6_Ad' */
      rtb_IP_TotalOdometerinput6_Ad += (int32_T)rtb_IP_TotalOdometer_sat;

      /* DataTypeConversion: '<S297>/IP_TotalOdometer_Convert' */
      rtb_IP_TotalOdometer_Convert = (uint32_T)rtb_IP_TotalOdometerinput6_Ad;

      /* DataTypeConversion: '<S297>/IP_TotalOdometercv' */
      rtb_IP_TotalOdometer_sat = rtb_IP_TotalOdometer_Convert;

      /* Gain: '<S297>/IP_TotalOdometer_F' */
      rtb_IP_TotalOdometer_sat *= 0.1;

      /* Saturate: '<S297>/IP_TotalOdometer_sat' */
      if (rtb_IP_TotalOdometer_sat > 999999.0) {
        rtb_IP_TotalOdometer_sat = 999999.0;
      }

      /* End of Saturate: '<S297>/IP_TotalOdometer_sat' */

      /* SignalConversion: '<S296>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.IP_TotalOdometer = rtb_IP_TotalOdometer_sat;
    }

    /* End of Outputs for SubSystem: '<S295>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S96>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF28RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf28looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_l= 818;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_gf= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_kg= ec_can_receive(1,28,
      CAN1BUF28RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_p[0]=
      CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_p[1]=
      CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_p[2]=
      CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_p[3]=
      CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_p[4]=
      CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_p[5]=
      CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_p[6]=
      CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_p[7]=
      CAN1BUF28RX[can1buf28looprx];
    can1buf28looprx++;
  }

  /* Call the system: <S96>/ReceiveMessages */

  /* Output and update for function-call system: '<S96>/ReceiveMessages' */
  {
    real_T rtb_EMS_EngineSpeed_sat;
    real_T rtb_SRS_PassengerBuckleSwitch_h;
    int32_T rtb_SRS_PassengerBuckleSwitch_d;
    int32_T rtb_SAS_SASFailure_sat;
    int32_T rtb_SRS_DriverBuckleSwitchStatu;

    /* Outputs for Enabled SubSystem: '<S299>/Subsystem' incorporates:
     *  EnablePort: '<S300>/Enable'
     */
    if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_kg > 0) {
      /* Product: '<S301>/EMS_EngineSpeedinput6_P' incorporates:
       *  Constant: '<S301>/EMS_EngineSpeedinput6_C'
       */
      rtb_EMS_EngineSpeed_sat = (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_p[5] * 256.0;

      /* Sum: '<S301>/EMS_EngineSpeedinput6_Ad' */
      rtb_SRS_PassengerBuckleSwitch_h = rtb_EMS_EngineSpeed_sat + (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_p[6];

      /* DataTypeConversion: '<S301>/EMS_EngineSpeed_Convert' */
      rtb_SRS_PassengerBuckleSwitch_d = (int32_T)rtb_SRS_PassengerBuckleSwitch_h;

      /* DataTypeConversion: '<S301>/EMS_EngineSpeedcv' */
      rtb_SRS_PassengerBuckleSwitch_h = rtb_SRS_PassengerBuckleSwitch_d;

      /* Gain: '<S301>/EMS_EngineSpeed_F' */
      rtb_SRS_PassengerBuckleSwitch_h *= 0.25;

      /* Sum: '<S301>/EMS_EngineSpeed_Ad' */
      rtb_EMS_EngineSpeed_sat = rtb_SRS_PassengerBuckleSwitch_h;

      /* Saturate: '<S301>/EMS_EngineSpeed_sat' */
      if (rtb_EMS_EngineSpeed_sat > 16383.5) {
        rtb_EMS_EngineSpeed_sat = 16383.5;
      }

      /* End of Saturate: '<S301>/EMS_EngineSpeed_sat' */

      /* DataTypeConversion: '<S301>/SAS_SASFailure_Convert' */
      rtb_SRS_PassengerBuckleSwitch_d =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_p[4];

      /* S-Function (sfix_bitop): '<S301>/SAS_SASFailure_L' */
      rtb_SRS_PassengerBuckleSwitch_d &= 16U;

      /* ArithShift: '<S301>/SAS_SASFailure_S' */
      rtb_SRS_PassengerBuckleSwitch_d = (int32_T)((uint32_T)
        rtb_SRS_PassengerBuckleSwitch_d >> 4);

      /* DataTypeConversion: '<S301>/SAS_SASFailurecv' */
      rtb_SRS_PassengerBuckleSwitch_h = rtb_SRS_PassengerBuckleSwitch_d;

      /* Sum: '<S301>/SAS_SASFailure_Ad' */
      rtb_SAS_SASFailure_sat = (int32_T)rtb_SRS_PassengerBuckleSwitch_h;

      /* Saturate: '<S301>/SAS_SASFailure_sat' */
      rtb_SRS_PassengerBuckleSwitch_h = rtb_SAS_SASFailure_sat;
      rtb_SAS_SASFailure_sat = (int32_T)rtb_SRS_PassengerBuckleSwitch_h;

      /* DataTypeConversion: '<S301>/SRS_DriverBuckleSwitchStatus_Convert' */
      rtb_SRS_PassengerBuckleSwitch_d =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_p[3];

      /* S-Function (sfix_bitop): '<S301>/SRS_DriverBuckleSwitchStatus_L' */
      rtb_SRS_PassengerBuckleSwitch_d &= 192U;

      /* ArithShift: '<S301>/SRS_DriverBuckleSwitchStatus_S' */
      rtb_SRS_PassengerBuckleSwitch_d = (int32_T)((uint32_T)
        rtb_SRS_PassengerBuckleSwitch_d >> 6);

      /* DataTypeConversion: '<S301>/SRS_DriverBuckleSwitchStatuscv' */
      rtb_SRS_PassengerBuckleSwitch_h = rtb_SRS_PassengerBuckleSwitch_d;

      /* Sum: '<S301>/SRS_DriverBuckleSwitchStatus_Ad' */
      rtb_SRS_DriverBuckleSwitchStatu = (int32_T)rtb_SRS_PassengerBuckleSwitch_h;

      /* Saturate: '<S301>/SRS_DriverBuckleSwitchStatus_sat' */
      rtb_SRS_PassengerBuckleSwitch_h = rtb_SRS_DriverBuckleSwitchStatu;
      rtb_SRS_DriverBuckleSwitchStatu = (int32_T)rtb_SRS_PassengerBuckleSwitch_h;

      /* DataTypeConversion: '<S301>/SRS_PassengerBuckleSwitchStatus_Convert' */
      rtb_SRS_PassengerBuckleSwitch_d =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_p[3];

      /* S-Function (sfix_bitop): '<S301>/SRS_PassengerBuckleSwitchStatus_L' */
      rtb_SRS_PassengerBuckleSwitch_d &= 48U;

      /* ArithShift: '<S301>/SRS_PassengerBuckleSwitchStatus_S' */
      rtb_SRS_PassengerBuckleSwitch_d = (int32_T)((uint32_T)
        rtb_SRS_PassengerBuckleSwitch_d >> 4);

      /* DataTypeConversion: '<S301>/SRS_PassengerBuckleSwitchStatuscv' */
      rtb_SRS_PassengerBuckleSwitch_h = rtb_SRS_PassengerBuckleSwitch_d;

      /* SignalConversion: '<S300>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.SRS_PassengerBuckleSwitchStatus =
        rtb_SRS_PassengerBuckleSwitch_h;

      /* SignalConversion: '<S300>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.SRS_DriverBuckleSwitchStatus_a =
        rtb_SRS_DriverBuckleSwitchStatu;

      /* SignalConversion: '<S300>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.SAS_SASFailure_f = rtb_SAS_SASFailure_sat;

      /* SignalConversion: '<S300>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_EngineSpeed = rtb_EMS_EngineSpeed_sat;
    }

    /* End of Outputs for SubSystem: '<S299>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S97>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF30RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf30looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_a1= 886;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_f= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_jb= ec_can_receive(1,30,
      CAN1BUF30RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ef[0]=
      CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ef[1]=
      CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ef[2]=
      CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ef[3]=
      CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ef[4]=
      CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ef[5]=
      CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ef[6]=
      CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ef[7]=
      CAN1BUF30RX[can1buf30looprx];
    can1buf30looprx++;
  }

  /* Call the system: <S97>/ReceiveMessages */

  /* Output and update for function-call system: '<S97>/ReceiveMessages' */
  {
    int32_T rtb_EMS_TorqueConstant_L;
    real_T rtb_EMS_FrictionalTorq_sat;
    int32_T rtb_EMS_ConditionIdle_sat;
    int32_T rtb_EMS_EngineFuelCutOff_sat;
    real_T rtb_EMS_TorqueConstant_F;

    /* Outputs for Enabled SubSystem: '<S306>/Subsystem' incorporates:
     *  EnablePort: '<S307>/Enable'
     */
    if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_jb > 0) {
      /* DataTypeConversion: '<S308>/EMS_ConditionIdle_Convert' */
      rtb_EMS_TorqueConstant_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ef[3];

      /* S-Function (sfix_bitop): '<S308>/EMS_ConditionIdle_L' */
      rtb_EMS_TorqueConstant_L &= 128U;

      /* ArithShift: '<S308>/EMS_ConditionIdle_S' */
      rtb_EMS_TorqueConstant_L = (int32_T)((uint32_T)rtb_EMS_TorqueConstant_L >>
        7);

      /* DataTypeConversion: '<S308>/EMS_ConditionIdlecv' */
      rtb_EMS_FrictionalTorq_sat = rtb_EMS_TorqueConstant_L;

      /* Sum: '<S308>/EMS_ConditionIdle_Ad' */
      rtb_EMS_ConditionIdle_sat = (int32_T)rtb_EMS_FrictionalTorq_sat;

      /* Saturate: '<S308>/EMS_ConditionIdle_sat' */
      rtb_EMS_FrictionalTorq_sat = rtb_EMS_ConditionIdle_sat;
      rtb_EMS_ConditionIdle_sat = (int32_T)rtb_EMS_FrictionalTorq_sat;

      /* DataTypeConversion: '<S308>/EMS_EngineFuelCutOff_Convert' */
      rtb_EMS_TorqueConstant_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ef[3];

      /* S-Function (sfix_bitop): '<S308>/EMS_EngineFuelCutOff_L' */
      rtb_EMS_TorqueConstant_L &= 16U;

      /* ArithShift: '<S308>/EMS_EngineFuelCutOff_S' */
      rtb_EMS_TorqueConstant_L = (int32_T)((uint32_T)rtb_EMS_TorqueConstant_L >>
        4);

      /* DataTypeConversion: '<S308>/EMS_EngineFuelCutOffcv' */
      rtb_EMS_FrictionalTorq_sat = rtb_EMS_TorqueConstant_L;

      /* Sum: '<S308>/EMS_EngineFuelCutOff_Ad' */
      rtb_EMS_EngineFuelCutOff_sat = (int32_T)rtb_EMS_FrictionalTorq_sat;

      /* Saturate: '<S308>/EMS_EngineFuelCutOff_sat' */
      rtb_EMS_FrictionalTorq_sat = rtb_EMS_EngineFuelCutOff_sat;
      rtb_EMS_EngineFuelCutOff_sat = (int32_T)rtb_EMS_FrictionalTorq_sat;

      /* Product: '<S308>/EMS_FrictionalTorqinput2_P' incorporates:
       *  Constant: '<S308>/EMS_FrictionalTorqinput2_C'
       */
      rtb_EMS_FrictionalTorq_sat = (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ef[1] * 256.0;

      /* Sum: '<S308>/EMS_FrictionalTorqinput2_Ad' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_FrictionalTorq_sat + (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ef[2];

      /* DataTypeConversion: '<S308>/EMS_FrictionalTorq_Convert' */
      rtb_EMS_TorqueConstant_L = (int32_T)rtb_EMS_TorqueConstant_F;

      /* DataTypeConversion: '<S308>/EMS_FrictionalTorqcv' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_TorqueConstant_L;

      /* Gain: '<S308>/EMS_FrictionalTorq_F' */
      rtb_EMS_TorqueConstant_F *= 0.001526;

      /* Sum: '<S308>/EMS_FrictionalTorq_Ad' */
      rtb_EMS_FrictionalTorq_sat = rtb_EMS_TorqueConstant_F;

      /* DataTypeConversion: '<S308>/EMS_TorqueConstant_Convert' */
      rtb_EMS_TorqueConstant_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ef[0];

      /* DataTypeConversion: '<S308>/EMS_TorqueConstantcv' */
      rtb_EMS_TorqueConstant_F = rtb_EMS_TorqueConstant_L;

      /* Gain: '<S308>/EMS_TorqueConstant_F' */
      rtb_EMS_TorqueConstant_F *= 10.0;

      /* Saturate: '<S308>/EMS_TorqueConstant_sat' */
      if (rtb_EMS_TorqueConstant_F > 2540.0) {
        rtb_EMS_TorqueConstant_F = 2540.0;
      }

      /* End of Saturate: '<S308>/EMS_TorqueConstant_sat' */

      /* SignalConversion: '<S307>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_TorqueConstant_i =
        rtb_EMS_TorqueConstant_F;

      /* SignalConversion: '<S307>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_FrictionalTorq =
        rtb_EMS_FrictionalTorq_sat;

      /* SignalConversion: '<S307>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_EngineFuelCutOff =
        rtb_EMS_EngineFuelCutOff_sat;

      /* SignalConversion: '<S307>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_ConditionIdle =
        rtb_EMS_ConditionIdle_sat;
    }

    /* End of Outputs for SubSystem: '<S306>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S98>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF31RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf31looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_eu= 930;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_pi= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_mhq= ec_can_receive(1,31,
      CAN1BUF31RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[0]=
      CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[1]=
      CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[2]=
      CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[3]=
      CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[4]=
      CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[5]=
      CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[6]=
      CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[7]=
      CAN1BUF31RX[can1buf31looprx];
    can1buf31looprx++;
  }

  /* Call the system: <S98>/ReceiveMessages */

  /* Output and update for function-call system: '<S98>/ReceiveMessages' */
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

    /* Outputs for Enabled SubSystem: '<S313>/Subsystem' incorporates:
     *  EnablePort: '<S314>/Enable'
     */
    if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_mhq > 0) {
      /* DataTypeConversion: '<S315>/ACC_ACCMode_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[1];

      /* S-Function (sfix_bitop): '<S315>/ACC_ACCMode_L' */
      rtb_TCU_WNTLamp_L &= 7U;

      /* Sum: '<S315>/ACC_ACCMode_Ad' */
      rtb_ACC_ACCMode_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S315>/ACC_ACCMode_sat' */
      u0 = rtb_ACC_ACCMode_sat;
      rtb_ACC_ACCMode_sat = (int32_T)u0;

      /* DataTypeConversion: '<S315>/EMS_RemindGear_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[0];

      /* S-Function (sfix_bitop): '<S315>/EMS_RemindGear_L' */
      rtb_TCU_WNTLamp_L &= 112U;

      /* ArithShift: '<S315>/EMS_RemindGear_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 4);

      /* Sum: '<S315>/EMS_RemindGear_Ad' */
      rtb_EMS_RemindGear_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S315>/EMS_RemindGear_sat' */
      u0 = rtb_EMS_RemindGear_sat;
      rtb_EMS_RemindGear_sat = (int32_T)u0;

      /* DataTypeConversion: '<S315>/EMS_RemindShiftGear_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[7];

      /* S-Function (sfix_bitop): '<S315>/EMS_RemindShiftGear_L' */
      rtb_TCU_WNTLamp_L &= 192U;

      /* ArithShift: '<S315>/EMS_RemindShiftGear_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 6);

      /* Sum: '<S315>/EMS_RemindShiftGear_Ad' */
      rtb_EMS_RemindShiftGear_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S315>/EMS_RemindShiftGear_sat' */
      u0 = rtb_EMS_RemindShiftGear_sat;
      rtb_EMS_RemindShiftGear_sat = (int32_T)u0;

      /* DataTypeConversion: '<S315>/EPB_FunctionLamp_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[4];

      /* S-Function (sfix_bitop): '<S315>/EPB_FunctionLamp_L' */
      rtb_TCU_WNTLamp_L &= 24U;

      /* ArithShift: '<S315>/EPB_FunctionLamp_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 3);

      /* Sum: '<S315>/EPB_FunctionLamp_Ad' */
      rtb_EPB_FunctionLamp_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S315>/EPB_FunctionLamp_sat' */
      u0 = rtb_EPB_FunctionLamp_sat;
      rtb_EPB_FunctionLamp_sat = (int32_T)u0;

      /* DataTypeConversion: '<S315>/EPB_SwitchPositionValid_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[4];

      /* S-Function (sfix_bitop): '<S315>/EPB_SwitchPositionValid_L' */
      rtb_TCU_WNTLamp_L &= 128U;

      /* ArithShift: '<S315>/EPB_SwitchPositionValid_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 7);

      /* Sum: '<S315>/EPB_SwitchPositionValid_Ad' */
      rtb_EPB_SwitchPositionValid_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S315>/EPB_SwitchPositionValid_sat' */
      u0 = rtb_EPB_SwitchPositionValid_sat;
      rtb_EPB_SwitchPositionValid_sat = (int32_T)u0;

      /* DataTypeConversion: '<S315>/EPB_SwitchPosition_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[4];

      /* S-Function (sfix_bitop): '<S315>/EPB_SwitchPosition_L' */
      rtb_TCU_WNTLamp_L &= 96U;

      /* ArithShift: '<S315>/EPB_SwitchPosition_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 5);

      /* Sum: '<S315>/EPB_SwitchPosition_Ad' */
      rtb_EPB_SwitchPosition_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S315>/EPB_SwitchPosition_sat' */
      u0 = rtb_EPB_SwitchPosition_sat;
      rtb_EPB_SwitchPosition_sat = (int32_T)u0;

      /* DataTypeConversion: '<S315>/EPB_TextDisplay_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[3];

      /* S-Function (sfix_bitop): '<S315>/EPB_TextDisplay_L' */
      rtb_TCU_WNTLamp_L &= 15U;

      /* Sum: '<S315>/EPB_TextDisplay_Ad' */
      rtb_EPB_TextDisplay_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S315>/EPB_TextDisplay_sat' */
      u0 = rtb_EPB_TextDisplay_sat;
      rtb_EPB_TextDisplay_sat = (int32_T)u0;

      /* DataTypeConversion: '<S315>/EPS_EPSFailed_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[4];

      /* S-Function (sfix_bitop): '<S315>/EPS_EPSFailed_L' */
      rtb_TCU_WNTLamp_L &= 2U;

      /* ArithShift: '<S315>/EPS_EPSFailed_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 1);

      /* Sum: '<S315>/EPS_EPSFailed_Ad' */
      rtb_EPS_EPSFailed_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S315>/EPS_EPSFailed_sat' */
      u0 = rtb_EPS_EPSFailed_sat;
      rtb_EPS_EPSFailed_sat = (int32_T)u0;

      /* DataTypeConversion: '<S315>/EPS_TorqueAssistMode_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[0];

      /* S-Function (sfix_bitop): '<S315>/EPS_TorqueAssistMode_L' */
      rtb_TCU_WNTLamp_L &= 3U;

      /* Sum: '<S315>/EPS_TorqueAssistMode_Ad' */
      rtb_EPS_TorqueAssistMode_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S315>/EPS_TorqueAssistMode_sat' */
      u0 = rtb_EPS_TorqueAssistMode_sat;
      rtb_EPS_TorqueAssistMode_sat = (int32_T)u0;

      /* DataTypeConversion: '<S315>/ESP_AutoHoldActive_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[6];

      /* S-Function (sfix_bitop): '<S315>/ESP_AutoHoldActive_L' */
      rtb_TCU_WNTLamp_L &= 4U;

      /* ArithShift: '<S315>/ESP_AutoHoldActive_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 2);

      /* Sum: '<S315>/ESP_AutoHoldActive_Ad' */
      rtb_ESP_AutoHoldActive_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S315>/ESP_AutoHoldActive_sat' */
      u0 = rtb_ESP_AutoHoldActive_sat;
      rtb_ESP_AutoHoldActive_sat = (int32_T)u0;

      /* DataTypeConversion: '<S315>/ESP_AutoHoldAvailable_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[6];

      /* S-Function (sfix_bitop): '<S315>/ESP_AutoHoldAvailable_L' */
      rtb_TCU_WNTLamp_L &= 1U;

      /* Sum: '<S315>/ESP_AutoHoldAvailable_Ad' */
      rtb_ESP_AutoHoldAvailable_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S315>/ESP_AutoHoldAvailable_sat' */
      u0 = rtb_ESP_AutoHoldAvailable_sat;
      rtb_ESP_AutoHoldAvailable_sat = (int32_T)u0;

      /* DataTypeConversion: '<S315>/ESP_EBDFailStatus_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[3];

      /* S-Function (sfix_bitop): '<S315>/ESP_EBDFailStatus_L' */
      rtb_TCU_WNTLamp_L &= 128U;

      /* ArithShift: '<S315>/ESP_EBDFailStatus_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 7);

      /* Sum: '<S315>/ESP_EBDFailStatus_Ad' */
      rtb_ESP_EBDFailStatus_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S315>/ESP_EBDFailStatus_sat' */
      u0 = rtb_ESP_EBDFailStatus_sat;
      rtb_ESP_EBDFailStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S315>/ESP_ESPActiveStatus_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[3];

      /* S-Function (sfix_bitop): '<S315>/ESP_ESPActiveStatus_L' */
      rtb_TCU_WNTLamp_L &= 32U;

      /* ArithShift: '<S315>/ESP_ESPActiveStatus_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 5);

      /* Sum: '<S315>/ESP_ESPActiveStatus_Ad' */
      rtb_ESP_ESPActiveStatus_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S315>/ESP_ESPActiveStatus_sat' */
      u0 = rtb_ESP_ESPActiveStatus_sat;
      rtb_ESP_ESPActiveStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S315>/ESP_ESPFunctionStatus_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[3];

      /* S-Function (sfix_bitop): '<S315>/ESP_ESPFunctionStatus_L' */
      rtb_TCU_WNTLamp_L &= 64U;

      /* ArithShift: '<S315>/ESP_ESPFunctionStatus_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 6);

      /* Sum: '<S315>/ESP_ESPFunctionStatus_Ad' */
      rtb_ESP_ESPFunctionStatus_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S315>/ESP_ESPFunctionStatus_sat' */
      u0 = rtb_ESP_ESPFunctionStatus_sat;
      rtb_ESP_ESPFunctionStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S315>/ESP_HBBFunctionStatus_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[7];

      /* S-Function (sfix_bitop): '<S315>/ESP_HBBFunctionStatus_L' */
      rtb_TCU_WNTLamp_L &= 6U;

      /* ArithShift: '<S315>/ESP_HBBFunctionStatus_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 1);

      /* Sum: '<S315>/ESP_HBBFunctionStatus_Ad' */
      rtb_ESP_HBBFunctionStatus_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S315>/ESP_HBBFunctionStatus_sat' */
      u0 = rtb_ESP_HBBFunctionStatus_sat;
      rtb_ESP_HBBFunctionStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S315>/ESP_HDC_STATUS_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[5];

      /* S-Function (sfix_bitop): '<S315>/ESP_HDC_STATUS_L' */
      rtb_TCU_WNTLamp_L &= 3U;

      /* Sum: '<S315>/ESP_HDC_STATUS_Ad' */
      rtb_ESP_HDC_STATUS_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S315>/ESP_HDC_STATUS_sat' */
      u0 = rtb_ESP_HDC_STATUS_sat;
      rtb_ESP_HDC_STATUS_sat = (int32_T)u0;

      /* DataTypeConversion: '<S315>/ESP_HHC_Active_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[6];

      /* S-Function (sfix_bitop): '<S315>/ESP_HHC_Active_L' */
      rtb_TCU_WNTLamp_L &= 2U;

      /* ArithShift: '<S315>/ESP_HHC_Active_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 1);

      /* Sum: '<S315>/ESP_HHC_Active_Ad' */
      rtb_ESP_HHC_Active_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S315>/ESP_HHC_Active_sat' */
      u0 = rtb_ESP_HHC_Active_sat;
      rtb_ESP_HHC_Active_sat = (int32_T)u0;

      /* DataTypeConversion: '<S315>/ESP_HHC_Available_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[6];

      /* S-Function (sfix_bitop): '<S315>/ESP_HHC_Available_L' */
      rtb_TCU_WNTLamp_L &= 8U;

      /* ArithShift: '<S315>/ESP_HHC_Available_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 3);

      /* Sum: '<S315>/ESP_HHC_Available_Ad' */
      rtb_ESP_HHC_Available_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S315>/ESP_HHC_Available_sat' */
      u0 = rtb_ESP_HHC_Available_sat;
      rtb_ESP_HHC_Available_sat = (int32_T)u0;

      /* DataTypeConversion: '<S315>/SRS_LeftRearBuckleSwitchSts_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[2];

      /* S-Function (sfix_bitop): '<S315>/SRS_LeftRearBuckleSwitchSts_L' */
      rtb_TCU_WNTLamp_L &= 12U;

      /* ArithShift: '<S315>/SRS_LeftRearBuckleSwitchSts_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 2);

      /* Sum: '<S315>/SRS_LeftRearBuckleSwitchSts_Ad' */
      rtb_SRS_LeftRearBuckleSwitchSts = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S315>/SRS_LeftRearBuckleSwitchSts_sat' */
      u0 = rtb_SRS_LeftRearBuckleSwitchSts;
      rtb_SRS_LeftRearBuckleSwitchSts = (int32_T)u0;

      /* DataTypeConversion: '<S315>/SRS_MiddleRearBuckleSwitchSts_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[2];

      /* S-Function (sfix_bitop): '<S315>/SRS_MiddleRearBuckleSwitchSts_L' */
      rtb_TCU_WNTLamp_L &= 48U;

      /* ArithShift: '<S315>/SRS_MiddleRearBuckleSwitchSts_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 4);

      /* Sum: '<S315>/SRS_MiddleRearBuckleSwitchSts_Ad' */
      rtb_SRS_MiddleRearBuckleSwitchS = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S315>/SRS_MiddleRearBuckleSwitchSts_sat' */
      u0 = rtb_SRS_MiddleRearBuckleSwitchS;
      rtb_SRS_MiddleRearBuckleSwitchS = (int32_T)u0;

      /* DataTypeConversion: '<S315>/SRS_RightRearBuckleSwitchSts_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[2];

      /* S-Function (sfix_bitop): '<S315>/SRS_RightRearBuckleSwitchSts_L' */
      rtb_TCU_WNTLamp_L &= 192U;

      /* ArithShift: '<S315>/SRS_RightRearBuckleSwitchSts_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 6);

      /* Sum: '<S315>/SRS_RightRearBuckleSwitchSts_Ad' */
      rtb_SRS_RightRearBuckleSwitchSt = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S315>/SRS_RightRearBuckleSwitchSts_sat' */
      u0 = rtb_SRS_RightRearBuckleSwitchSt;
      rtb_SRS_RightRearBuckleSwitchSt = (int32_T)u0;

      /* DataTypeConversion: '<S315>/TCU_FailureLamp_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[0];

      /* S-Function (sfix_bitop): '<S315>/TCU_FailureLamp_L' */
      rtb_TCU_WNTLamp_L &= 128U;

      /* ArithShift: '<S315>/TCU_FailureLamp_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 7);

      /* Sum: '<S315>/TCU_FailureLamp_Ad' */
      rtb_TCU_FailureLamp_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S315>/TCU_FailureLamp_sat' */
      u0 = rtb_TCU_FailureLamp_sat;
      rtb_TCU_FailureLamp_sat = (int32_T)u0;

      /* DataTypeConversion: '<S315>/TCU_GearForDisplay_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[6];

      /* S-Function (sfix_bitop): '<S315>/TCU_GearForDisplay_L' */
      rtb_TCU_WNTLamp_L &= 240U;

      /* ArithShift: '<S315>/TCU_GearForDisplay_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 4);

      /* Sum: '<S315>/TCU_GearForDisplay_Ad' */
      rtb_TCU_GearForDisplay_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S315>/TCU_GearForDisplay_sat' */
      u0 = rtb_TCU_GearForDisplay_sat;
      rtb_TCU_GearForDisplay_sat = (int32_T)u0;

      /* DataTypeConversion: '<S315>/TCU_GearIndication_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[7];

      /* S-Function (sfix_bitop): '<S315>/TCU_GearIndication_L' */
      rtb_TCU_WNTLamp_L &= 8U;

      /* ArithShift: '<S315>/TCU_GearIndication_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 3);

      /* Sum: '<S315>/TCU_GearIndication_Ad' */
      rtb_TCU_GearIndication_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S315>/TCU_GearIndication_sat' */
      u0 = rtb_TCU_GearIndication_sat;
      rtb_TCU_GearIndication_sat = (int32_T)u0;

      /* DataTypeConversion: '<S315>/TCU_PWRLamp_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[1];

      /* S-Function (sfix_bitop): '<S315>/TCU_PWRLamp_L' */
      rtb_TCU_WNTLamp_L &= 64U;

      /* ArithShift: '<S315>/TCU_PWRLamp_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 6);

      /* Sum: '<S315>/TCU_PWRLamp_Ad' */
      rtb_TCU_PWRLamp_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S315>/TCU_PWRLamp_sat' */
      u0 = rtb_TCU_PWRLamp_sat;
      rtb_TCU_PWRLamp_sat = (int32_T)u0;

      /* DataTypeConversion: '<S315>/TCU_ReqTranTempWarning_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[7];

      /* S-Function (sfix_bitop): '<S315>/TCU_ReqTranTempWarning_L' */
      rtb_TCU_WNTLamp_L &= 48U;

      /* ArithShift: '<S315>/TCU_ReqTranTempWarning_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 4);

      /* Sum: '<S315>/TCU_ReqTranTempWarning_Ad' */
      rtb_TCU_ReqTranTempWarning_sat = rtb_TCU_WNTLamp_L;

      /* Saturate: '<S315>/TCU_ReqTranTempWarning_sat' */
      u0 = rtb_TCU_ReqTranTempWarning_sat;
      rtb_TCU_ReqTranTempWarning_sat = (int32_T)u0;

      /* DataTypeConversion: '<S315>/TCU_WNTLamp_Convert' */
      rtb_TCU_WNTLamp_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_it[1];

      /* S-Function (sfix_bitop): '<S315>/TCU_WNTLamp_L' */
      rtb_TCU_WNTLamp_L &= 32U;

      /* ArithShift: '<S315>/TCU_WNTLamp_S' */
      rtb_TCU_WNTLamp_L = (int32_T)((uint32_T)rtb_TCU_WNTLamp_L >> 5);

      /* Saturate: '<S315>/TCU_WNTLamp_sat' */
      u0 = rtb_TCU_WNTLamp_L;
      rtb_TCU_WNTLamp_L = (int32_T)u0;

      /* SignalConversion: '<S314>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPS_TorqueAssistMode =
        rtb_EPS_TorqueAssistMode_sat;

      /* SignalConversion: '<S314>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPB_TextDisplay = rtb_EPB_TextDisplay_sat;

      /* SignalConversion: '<S314>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_ESPActiveStatus =
        rtb_ESP_ESPActiveStatus_sat;

      /* SignalConversion: '<S314>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_ESPFunctionStatus =
        rtb_ESP_ESPFunctionStatus_sat;

      /* SignalConversion: '<S314>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_EBDFailStatus =
        rtb_ESP_EBDFailStatus_sat;

      /* SignalConversion: '<S314>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPS_EPSFailed = rtb_EPS_EPSFailed_sat;

      /* SignalConversion: '<S314>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPB_FunctionLamp = rtb_EPB_FunctionLamp_sat;

      /* SignalConversion: '<S314>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPB_SwitchPosition =
        rtb_EPB_SwitchPosition_sat;

      /* SignalConversion: '<S314>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EPB_SwitchPositionValid =
        rtb_EPB_SwitchPositionValid_sat;

      /* SignalConversion: '<S314>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_HDC_STATUS = rtb_ESP_HDC_STATUS_sat;

      /* SignalConversion: '<S314>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_AutoHoldAvailable =
        rtb_ESP_AutoHoldAvailable_sat;

      /* SignalConversion: '<S314>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_RemindGear = rtb_EMS_RemindGear_sat;

      /* SignalConversion: '<S314>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_HHC_Active = rtb_ESP_HHC_Active_sat;

      /* SignalConversion: '<S314>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_AutoHoldActive =
        rtb_ESP_AutoHoldActive_sat;

      /* SignalConversion: '<S314>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_HHC_Available =
        rtb_ESP_HHC_Available_sat;

      /* SignalConversion: '<S314>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.TCU_GearForDisplay =
        rtb_TCU_GearForDisplay_sat;

      /* SignalConversion: '<S314>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ESP_HBBFunctionStatus =
        rtb_ESP_HBBFunctionStatus_sat;

      /* SignalConversion: '<S314>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.TCU_GearIndication =
        rtb_TCU_GearIndication_sat;

      /* SignalConversion: '<S314>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.TCU_ReqTranTempWarning =
        rtb_TCU_ReqTranTempWarning_sat;

      /* SignalConversion: '<S314>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.EMS_RemindShiftGear =
        rtb_EMS_RemindShiftGear_sat;

      /* SignalConversion: '<S314>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.TCU_FailureLamp = rtb_TCU_FailureLamp_sat;

      /* SignalConversion: '<S314>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.ACC_ACCMode = rtb_ACC_ACCMode_sat;

      /* SignalConversion: '<S314>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.TCU_WNTLamp = rtb_TCU_WNTLamp_L;

      /* SignalConversion: '<S314>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.TCU_PWRLamp = rtb_TCU_PWRLamp_sat;

      /* SignalConversion: '<S314>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.SRS_LeftRearBuckleSwitchSts =
        rtb_SRS_LeftRearBuckleSwitchSts;

      /* SignalConversion: '<S314>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.SRS_MiddleRearBuckleSwitchSts =
        rtb_SRS_MiddleRearBuckleSwitchS;

      /* SignalConversion: '<S314>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.SRS_RightRearBuckleSwitchSts =
        rtb_SRS_RightRearBuckleSwitchSt;
    }

    /* End of Outputs for SubSystem: '<S313>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S99>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF32RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf32looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_a3= 1383;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_hn= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_nj= ec_can_receive(1,32,
      CAN1BUF32RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ao[0]=
      CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ao[1]=
      CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ao[2]=
      CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ao[3]=
      CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ao[4]=
      CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ao[5]=
      CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ao[6]=
      CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ao[7]=
      CAN1BUF32RX[can1buf32looprx];
    can1buf32looprx++;
  }

  /* Call the system: <S99>/ReceiveMessages */

  /* Output and update for function-call system: '<S99>/ReceiveMessages' */
  {
    int32_T rtb_HU_TunnelLength_L;
    int32_T rtb_HU_Byroad_sat;
    int32_T rtb_HU_EnterTunnelInfo_sat;
    int32_T rtb_HU_NavGuiganceStatus_sat;
    int32_T rtb_HU_TunnelDistance_sat;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S343>/Subsystem' incorporates:
     *  EnablePort: '<S344>/Enable'
     */
    if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_nj > 0) {
      /* DataTypeConversion: '<S345>/HU_Byroad_Convert' */
      rtb_HU_TunnelLength_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ao[4];

      /* S-Function (sfix_bitop): '<S345>/HU_Byroad_L' */
      rtb_HU_TunnelLength_L &= 192U;

      /* ArithShift: '<S345>/HU_Byroad_S' */
      rtb_HU_TunnelLength_L = (int32_T)((uint32_T)rtb_HU_TunnelLength_L >> 6);

      /* Sum: '<S345>/HU_Byroad_Ad' */
      rtb_HU_Byroad_sat = rtb_HU_TunnelLength_L;

      /* Saturate: '<S345>/HU_Byroad_sat' */
      u0 = rtb_HU_Byroad_sat;
      rtb_HU_Byroad_sat = (int32_T)u0;

      /* DataTypeConversion: '<S345>/HU_EnterTunnelInfo_Convert' */
      rtb_HU_TunnelLength_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ao[0];

      /* S-Function (sfix_bitop): '<S345>/HU_EnterTunnelInfo_L' */
      rtb_HU_TunnelLength_L &= 12U;

      /* ArithShift: '<S345>/HU_EnterTunnelInfo_S' */
      rtb_HU_TunnelLength_L = (int32_T)((uint32_T)rtb_HU_TunnelLength_L >> 2);

      /* Sum: '<S345>/HU_EnterTunnelInfo_Ad' */
      rtb_HU_EnterTunnelInfo_sat = rtb_HU_TunnelLength_L;

      /* Saturate: '<S345>/HU_EnterTunnelInfo_sat' */
      u0 = rtb_HU_EnterTunnelInfo_sat;
      rtb_HU_EnterTunnelInfo_sat = (int32_T)u0;

      /* DataTypeConversion: '<S345>/HU_NavGuiganceStatus_Convert' */
      rtb_HU_TunnelLength_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ao[5];

      /* S-Function (sfix_bitop): '<S345>/HU_NavGuiganceStatus_L' */
      rtb_HU_TunnelLength_L &= 192U;

      /* ArithShift: '<S345>/HU_NavGuiganceStatus_S' */
      rtb_HU_TunnelLength_L = (int32_T)((uint32_T)rtb_HU_TunnelLength_L >> 6);

      /* Sum: '<S345>/HU_NavGuiganceStatus_Ad' */
      rtb_HU_NavGuiganceStatus_sat = rtb_HU_TunnelLength_L;

      /* Saturate: '<S345>/HU_NavGuiganceStatus_sat' */
      u0 = rtb_HU_NavGuiganceStatus_sat;
      rtb_HU_NavGuiganceStatus_sat = (int32_T)u0;

      /* DataTypeConversion: '<S345>/HU_TunnelDistance_Convert' */
      rtb_HU_TunnelLength_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ao[2];

      /* S-Function (sfix_bitop): '<S345>/HU_TunnelDistance_L' */
      rtb_HU_TunnelLength_L &= 252U;

      /* ArithShift: '<S345>/HU_TunnelDistance_S' */
      rtb_HU_TunnelLength_L = (int32_T)((uint32_T)rtb_HU_TunnelLength_L >> 2);

      /* Gain: '<S345>/HU_TunnelDistance_F' */
      rtb_HU_TunnelLength_L *= 10;

      /* Sum: '<S345>/HU_TunnelDistance_Ad' */
      rtb_HU_TunnelDistance_sat = rtb_HU_TunnelLength_L;

      /* Saturate: '<S345>/HU_TunnelDistance_sat' */
      u0 = rtb_HU_TunnelDistance_sat;
      if (u0 > 600.0) {
        u0 = 600.0;
      }

      rtb_HU_TunnelDistance_sat = (int32_T)u0;

      /* End of Saturate: '<S345>/HU_TunnelDistance_sat' */

      /* DataTypeConversion: '<S345>/HU_TunnelLength_Convert' */
      rtb_HU_TunnelLength_L = VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ao[4];

      /* S-Function (sfix_bitop): '<S345>/HU_TunnelLength_L' */
      rtb_HU_TunnelLength_L &= 63U;

      /* Saturate: '<S345>/HU_TunnelLength_sat' */
      u0 = rtb_HU_TunnelLength_L;
      rtb_HU_TunnelLength_L = (int32_T)u0;

      /* SignalConversion: '<S344>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.HU_EnterTunnelInfo =
        rtb_HU_EnterTunnelInfo_sat;

      /* SignalConversion: '<S344>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.HU_TunnelDistance =
        rtb_HU_TunnelDistance_sat;

      /* SignalConversion: '<S344>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.HU_TunnelLength = rtb_HU_TunnelLength_L;

      /* SignalConversion: '<S344>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.HU_Byroad = rtb_HU_Byroad_sat;

      /* SignalConversion: '<S344>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.HU_NavGuiganceStatus =
        rtb_HU_NavGuiganceStatus_sat;
    }

    /* End of Outputs for SubSystem: '<S343>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S100>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF33RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf33looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_f= 1280;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_fx= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_it= ec_can_receive(1,33,
      CAN1BUF33RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ff[0]=
      CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ff[1]=
      CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ff[2]=
      CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ff[3]=
      CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ff[4]=
      CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ff[5]=
      CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ff[6]=
      CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_ff[7]=
      CAN1BUF33RX[can1buf33looprx];
    can1buf33looprx++;
  }

  /* Call the system: <S100>/ReceiveMessages */

  /* Output and update for function-call system: '<S100>/ReceiveMessages' */

  /* Outputs for Enabled SubSystem: '<S351>/Subsystem' incorporates:
   *  EnablePort: '<S352>/Enable'
   */
  if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_it > 0) {
    /* SignalConversion: '<S352>/Signal Conversion' */
    VCU_CS75_10_9_SteeringTorque_B.GPSCurrentLocationValid = 0.0;
  }

  /* End of Outputs for SubSystem: '<S351>/Subsystem' */

  /* S-Function (ec5744_canreceiveslb): '<S101>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF36RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf36looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_mf= 878;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_pl= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_jj= ec_can_receive(1,36,
      CAN1BUF36RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_as[0]=
      CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_as[1]=
      CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_as[2]=
      CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_as[3]=
      CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_as[4]=
      CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_as[5]=
      CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_as[6]=
      CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_as[7]=
      CAN1BUF36RX[can1buf36looprx];
    can1buf36looprx++;
  }

  /* Call the system: <S101>/ReceiveMessages */

  /* Output and update for function-call system: '<S101>/ReceiveMessages' */
  {
    uint32_T rtb_LAS_RollingCounter_id36E_L;
    int32_T rtb_LAS_LaneEquationStatus_sat;
    int32_T rtb_LAS_CheckSum_id36E_sat;
    real_T rtb_LAS_LaneEquationC1_sat;
    real_T rtb_LAS_LaneEquationC3_sat;
    real_T rtb_LAS_RoadCurvatureFar_sat;
    real_T rtb_LAS_RollingCounter_id36Ecv;
    real_T rtb_LAS_RoadCurvatureNear_sat;

    /* Outputs for Enabled SubSystem: '<S355>/Subsystem' incorporates:
     *  EnablePort: '<S356>/Enable'
     */
    if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_jj > 0) {
      /* DataTypeConversion: '<S357>/LAS_CheckSum_id36E_Convert' */
      rtb_LAS_RollingCounter_id36E_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_as[7];

      /* DataTypeConversion: '<S357>/LAS_CheckSum_id36Ecv' */
      rtb_LAS_LaneEquationStatus_sat = (int32_T)rtb_LAS_RollingCounter_id36E_L;

      /* Sum: '<S357>/LAS_CheckSum_id36E_Ad' */
      rtb_LAS_CheckSum_id36E_sat = rtb_LAS_LaneEquationStatus_sat;

      /* Saturate: '<S357>/LAS_CheckSum_id36E_sat' */
      rtb_LAS_RoadCurvatureFar_sat = rtb_LAS_CheckSum_id36E_sat;
      rtb_LAS_CheckSum_id36E_sat = (int32_T)rtb_LAS_RoadCurvatureFar_sat;

      /* Product: '<S357>/LAS_LaneEquationC1input3_P' incorporates:
       *  Constant: '<S357>/LAS_LaneEquationC1input3_C'
       */
      rtb_LAS_LaneEquationStatus_sat =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_as[2] << 8;

      /* Product: '<S357>/LAS_LaneEquationC1input2_P' incorporates:
       *  Constant: '<S357>/LAS_LaneEquationC1input2_C'
       */
      rtb_LAS_LaneEquationC1_sat = (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_as[1] * 65536.0;

      /* Sum: '<S357>/LAS_LaneEquationC1input2_Ad' */
      rtb_LAS_LaneEquationC3_sat = rtb_LAS_LaneEquationC1_sat + (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_as[3];

      /* Sum: '<S357>/LAS_LaneEquationC1input3_Ad' */
      rtb_LAS_LaneEquationStatus_sat += (int32_T)rtb_LAS_LaneEquationC3_sat;

      /* DataTypeConversion: '<S357>/LAS_LaneEquationC1_Convert' */
      rtb_LAS_RollingCounter_id36E_L = (uint32_T)rtb_LAS_LaneEquationStatus_sat;

      /* S-Function (sfix_bitop): '<S357>/LAS_LaneEquationC1_L' */
      rtb_LAS_RollingCounter_id36E_L &= 262080U;

      /* ArithShift: '<S357>/LAS_LaneEquationC1_S' */
      rtb_LAS_RollingCounter_id36E_L >>= 6;

      /* DataTypeConversion: '<S357>/LAS_LaneEquationC1cv' */
      rtb_LAS_LaneEquationC3_sat = rtb_LAS_RollingCounter_id36E_L;

      /* Gain: '<S357>/LAS_LaneEquationC1_F' */
      rtb_LAS_LaneEquationC3_sat *= 0.00048828125;

      /* Sum: '<S357>/LAS_LaneEquationC1_Ad' incorporates:
       *  Constant: '<S357>/LAS_LaneEquationC1_O'
       */
      rtb_LAS_LaneEquationC1_sat = rtb_LAS_LaneEquationC3_sat + -1.0;

      /* Saturate: '<S357>/LAS_LaneEquationC1_sat' */
      if (rtb_LAS_LaneEquationC1_sat > 0.9990234375) {
        rtb_LAS_LaneEquationC1_sat = 0.9990234375;
      }

      /* End of Saturate: '<S357>/LAS_LaneEquationC1_sat' */

      /* Product: '<S357>/LAS_LaneEquationC3input6_P' incorporates:
       *  Constant: '<S357>/LAS_LaneEquationC3input6_C'
       */
      rtb_LAS_LaneEquationC3_sat = (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_as[5] * 256.0;

      /* Product: '<S357>/LAS_LaneEquationC3input5_P' incorporates:
       *  Constant: '<S357>/LAS_LaneEquationC3input5_C'
       */
      rtb_LAS_LaneEquationStatus_sat =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_as[4] * 65536;

      /* Sum: '<S357>/LAS_LaneEquationC3input5_Ad' */
      rtb_LAS_RoadCurvatureFar_sat = rtb_LAS_LaneEquationStatus_sat +
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_as[6];

      /* Sum: '<S357>/LAS_LaneEquationC3input6_Ad' */
      rtb_LAS_LaneEquationC3_sat += rtb_LAS_RoadCurvatureFar_sat;

      /* DataTypeConversion: '<S357>/LAS_LaneEquationC3_Convert' */
      rtb_LAS_RollingCounter_id36E_L = (uint32_T)rtb_LAS_LaneEquationC3_sat;

      /* S-Function (sfix_bitop): '<S357>/LAS_LaneEquationC3_L' */
      rtb_LAS_RollingCounter_id36E_L &= 262080U;

      /* ArithShift: '<S357>/LAS_LaneEquationC3_S' */
      rtb_LAS_RollingCounter_id36E_L >>= 6;

      /* DataTypeConversion: '<S357>/LAS_LaneEquationC3cv' */
      rtb_LAS_RoadCurvatureFar_sat = rtb_LAS_RollingCounter_id36E_L;

      /* Gain: '<S357>/LAS_LaneEquationC3_F' */
      rtb_LAS_RoadCurvatureFar_sat *= 4.76837158203125;

      /* Sum: '<S357>/LAS_LaneEquationC3_Ad' incorporates:
       *  Constant: '<S357>/LAS_LaneEquationC3_O'
       */
      rtb_LAS_LaneEquationC3_sat = rtb_LAS_RoadCurvatureFar_sat +
        -0.00097608566284179688;

      /* Saturate: '<S357>/LAS_LaneEquationC3_sat' */
      if (rtb_LAS_LaneEquationC3_sat > 0.000976085662841796) {
        rtb_LAS_LaneEquationC3_sat = 0.000976085662841796;
      } else {
        if (rtb_LAS_LaneEquationC3_sat < -0.000976085662841796) {
          rtb_LAS_LaneEquationC3_sat = -0.000976085662841796;
        }
      }

      /* End of Saturate: '<S357>/LAS_LaneEquationC3_sat' */

      /* DataTypeConversion: '<S357>/LAS_LaneEquationStatus_Convert' */
      rtb_LAS_RollingCounter_id36E_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_as[6];

      /* S-Function (sfix_bitop): '<S357>/LAS_LaneEquationStatus_L' */
      rtb_LAS_RollingCounter_id36E_L &= 48U;

      /* ArithShift: '<S357>/LAS_LaneEquationStatus_S' */
      rtb_LAS_RollingCounter_id36E_L >>= 4;

      /* DataTypeConversion: '<S357>/LAS_LaneEquationStatuscv' */
      rtb_LAS_RoadCurvatureFar_sat = rtb_LAS_RollingCounter_id36E_L;

      /* Sum: '<S357>/LAS_LaneEquationStatus_Ad' */
      rtb_LAS_LaneEquationStatus_sat = (int32_T)rtb_LAS_RoadCurvatureFar_sat;

      /* Saturate: '<S357>/LAS_LaneEquationStatus_sat' */
      rtb_LAS_RoadCurvatureFar_sat = rtb_LAS_LaneEquationStatus_sat;
      rtb_LAS_LaneEquationStatus_sat = (int32_T)rtb_LAS_RoadCurvatureFar_sat;

      /* Product: '<S357>/LAS_RoadCurvatureFarinput1_P' incorporates:
       *  Constant: '<S357>/LAS_RoadCurvatureFarinput1_C'
       */
      rtb_LAS_RoadCurvatureFar_sat = (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_as[0] * 256.0;

      /* Sum: '<S357>/LAS_RoadCurvatureFarinput1_Ad' */
      rtb_LAS_RollingCounter_id36Ecv = rtb_LAS_RoadCurvatureFar_sat + (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_as[1];

      /* DataTypeConversion: '<S357>/LAS_RoadCurvatureFar_Convert' */
      rtb_LAS_RollingCounter_id36E_L = (uint32_T)rtb_LAS_RollingCounter_id36Ecv;

      /* S-Function (sfix_bitop): '<S357>/LAS_RoadCurvatureFar_L' */
      rtb_LAS_RollingCounter_id36E_L &= 508U;

      /* ArithShift: '<S357>/LAS_RoadCurvatureFar_S' */
      rtb_LAS_RollingCounter_id36E_L >>= 2;

      /* DataTypeConversion: '<S357>/LAS_RoadCurvatureFarcv' */
      rtb_LAS_RollingCounter_id36Ecv = rtb_LAS_RollingCounter_id36E_L;

      /* Gain: '<S357>/LAS_RoadCurvatureFar_F' */
      rtb_LAS_RollingCounter_id36Ecv *= 0.0005;

      /* Sum: '<S357>/LAS_RoadCurvatureFar_Ad' incorporates:
       *  Constant: '<S357>/LAS_RoadCurvatureFar_O'
       */
      rtb_LAS_RoadCurvatureFar_sat = rtb_LAS_RollingCounter_id36Ecv +
        -0.029999999329447746;

      /* Saturate: '<S357>/LAS_RoadCurvatureFar_sat' */
      if (rtb_LAS_RoadCurvatureFar_sat > 0.03) {
        rtb_LAS_RoadCurvatureFar_sat = 0.03;
      }

      /* End of Saturate: '<S357>/LAS_RoadCurvatureFar_sat' */

      /* DataTypeConversion: '<S357>/LAS_RoadCurvatureNear_Convert' */
      rtb_LAS_RollingCounter_id36E_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_as[0];

      /* S-Function (sfix_bitop): '<S357>/LAS_RoadCurvatureNear_L' */
      rtb_LAS_RollingCounter_id36E_L &= 254U;

      /* ArithShift: '<S357>/LAS_RoadCurvatureNear_S' */
      rtb_LAS_RollingCounter_id36E_L >>= 1;

      /* DataTypeConversion: '<S357>/LAS_RoadCurvatureNearcv' */
      rtb_LAS_RollingCounter_id36Ecv = rtb_LAS_RollingCounter_id36E_L;

      /* Gain: '<S357>/LAS_RoadCurvatureNear_F' */
      rtb_LAS_RollingCounter_id36Ecv *= 0.0005;

      /* Sum: '<S357>/LAS_RoadCurvatureNear_Ad' incorporates:
       *  Constant: '<S357>/LAS_RoadCurvatureNear_O'
       */
      rtb_LAS_RoadCurvatureNear_sat = rtb_LAS_RollingCounter_id36Ecv +
        -0.029999999329447746;

      /* Saturate: '<S357>/LAS_RoadCurvatureNear_sat' */
      if (rtb_LAS_RoadCurvatureNear_sat > 0.03) {
        rtb_LAS_RoadCurvatureNear_sat = 0.03;
      }

      /* End of Saturate: '<S357>/LAS_RoadCurvatureNear_sat' */

      /* DataTypeConversion: '<S357>/LAS_RollingCounter_id36E_Convert' */
      rtb_LAS_RollingCounter_id36E_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_as[6];

      /* S-Function (sfix_bitop): '<S357>/LAS_RollingCounter_id36E_L' */
      rtb_LAS_RollingCounter_id36E_L &= 15U;

      /* DataTypeConversion: '<S357>/LAS_RollingCounter_id36Ecv' */
      rtb_LAS_RollingCounter_id36Ecv = rtb_LAS_RollingCounter_id36E_L;

      /* SignalConversion: '<S356>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.LAS_RoadCurvatureFar =
        rtb_LAS_RoadCurvatureFar_sat;

      /* SignalConversion: '<S356>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.LAS_RoadCurvatureNear =
        rtb_LAS_RoadCurvatureNear_sat;

      /* SignalConversion: '<S356>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.LAS_LaneEquationC1 =
        rtb_LAS_LaneEquationC1_sat;

      /* SignalConversion: '<S356>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.LAS_LaneEquationC3 =
        rtb_LAS_LaneEquationC3_sat;

      /* SignalConversion: '<S356>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.LAS_RollingCounter_id36E =
        rtb_LAS_RollingCounter_id36Ecv;

      /* SignalConversion: '<S356>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.LAS_LaneEquationStatus =
        rtb_LAS_LaneEquationStatus_sat;

      /* SignalConversion: '<S356>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.LAS_CheckSum_id36E =
        rtb_LAS_CheckSum_id36E_sat;
    }

    /* End of Outputs for SubSystem: '<S355>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S102>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF19RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf19looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_ov= 264;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_lw= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_ij= ec_can_receive(1,19,
      CAN1BUF19RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_gv[0]=
      CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_gv[1]=
      CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_gv[2]=
      CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_gv[3]=
      CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_gv[4]=
      CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_gv[5]=
      CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_gv[6]=
      CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_gv[7]=
      CAN1BUF19RX[can1buf19looprx];
    can1buf19looprx++;
  }

  /* Call the system: <S102>/ReceiveMessages */

  /* Output and update for function-call system: '<S102>/ReceiveMessages' */
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

    /* Outputs for Enabled SubSystem: '<S365>/Subsystem' incorporates:
     *  EnablePort: '<S366>/Enable'
     */
    if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_ij > 0) {
      /* Product: '<S367>/SAS_SteeringAngleinput1_P' incorporates:
       *  Constant: '<S367>/SAS_SteeringAngleinput1_C'
       */
      rtb_SAS_SteeringAngle_Ad = (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_gv[0] * 256.0;

      /* Sum: '<S367>/SAS_SteeringAngleinput1_Ad' */
      rtb_SAS_SteeringAngle_F = rtb_SAS_SteeringAngle_Ad + (real_T)
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_gv[1];

      /* DataTypeConversion: '<S367>/SAS_SteeringAngle_Convert' */
      rtb_SAS_SteeringAngleValid_L = (int32_T)rtb_SAS_SteeringAngle_F;

      /* DataTypeConversion: '<S367>/SAS_SteeringAnglecv' */
      rtb_SAS_SteeringAnglesubcon = (real32_T)rtb_SAS_SteeringAngleValid_L;

      /* RelationalOperator: '<S367>/SAS_SteeringAngleROP' */
      rtb_SAS_SteeringAngleROP = (rtb_SAS_SteeringAnglesubcon >= 32768.0F);

      /* Switch: '<S367>/SAS_SteeringAngleSW' */
      if (rtb_SAS_SteeringAngleROP) {
        /* Sum: '<S367>/SAS_SteeringAnglesubcon' */
        rtb_SAS_SteeringAnglesubcon = 65536.0F - rtb_SAS_SteeringAnglesubcon;

        /* UnaryMinus: '<S367>/SAS_SteeringAngleMinus' */
        rtb_SAS_SteeringAnglesubcon = -rtb_SAS_SteeringAnglesubcon;
      }

      /* End of Switch: '<S367>/SAS_SteeringAngleSW' */

      /* DataTypeConversion: '<S367>/Data Type Conversion' */
      rtb_SAS_SteeringAngle_F = rtb_SAS_SteeringAnglesubcon;

      /* DataTypeConversion: '<S367>/SAS_CRCCheck_Convert' */
      rtb_SAS_SteeringAngleValid_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_gv[7];

      /* DataTypeConversion: '<S367>/SAS_CRCCheckcv' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;

      /* Sum: '<S367>/SAS_CRCCheck_Ad' */
      rtb_SAS_CRCCheck_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Saturate: '<S367>/SAS_CRCCheck_sat' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_CRCCheck_sat;
      rtb_SAS_CRCCheck_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* DataTypeConversion: '<S367>/SAS_Calibrated_Convert' */
      rtb_SAS_SteeringAngleValid_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_gv[3];

      /* S-Function (sfix_bitop): '<S367>/SAS_Calibrated_L' */
      rtb_SAS_SteeringAngleValid_L &= 32U;

      /* ArithShift: '<S367>/SAS_Calibrated_S' */
      rtb_SAS_SteeringAngleValid_L = (int32_T)((uint32_T)
        rtb_SAS_SteeringAngleValid_L >> 5);

      /* DataTypeConversion: '<S367>/SAS_Calibratedcv' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;

      /* Sum: '<S367>/SAS_Calibrated_Ad' */
      rtb_SAS_Calibrated_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Saturate: '<S367>/SAS_Calibrated_sat' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_Calibrated_sat;
      rtb_SAS_Calibrated_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* DataTypeConversion: '<S367>/SAS_RollingCounter_Convert' */
      rtb_SAS_SteeringAngleValid_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_gv[6];

      /* S-Function (sfix_bitop): '<S367>/SAS_RollingCounter_L' */
      rtb_SAS_SteeringAngleValid_L &= 15U;

      /* DataTypeConversion: '<S367>/SAS_RollingCountercv' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;

      /* Sum: '<S367>/SAS_RollingCounter_Ad' */
      rtb_SAS_RollingCounter_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Saturate: '<S367>/SAS_RollingCounter_sat' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_RollingCounter_sat;
      rtb_SAS_RollingCounter_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* DataTypeConversion: '<S367>/SAS_SASFailure_Convert' */
      rtb_SAS_SteeringAngleValid_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_gv[3];

      /* S-Function (sfix_bitop): '<S367>/SAS_SASFailure_L' */
      rtb_SAS_SteeringAngleValid_L &= 64U;

      /* ArithShift: '<S367>/SAS_SASFailure_S' */
      rtb_SAS_SteeringAngleValid_L = (int32_T)((uint32_T)
        rtb_SAS_SteeringAngleValid_L >> 6);

      /* DataTypeConversion: '<S367>/SAS_SASFailurecv' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;

      /* Sum: '<S367>/SAS_SASFailure_Ad' */
      rtb_SAS_SASFailure_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Saturate: '<S367>/SAS_SASFailure_sat' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SASFailure_sat;
      rtb_SAS_SASFailure_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* DataTypeConversion: '<S367>/SAS_SteeringAngleSpeed_Convert' */
      rtb_SAS_SteeringAngleValid_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_gv[2];

      /* DataTypeConversion: '<S367>/SAS_SteeringAngleSpeedcv' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;

      /* Gain: '<S367>/SAS_SteeringAngleSpeed_F' */
      rtb_SAS_SteeringAngle_Ad *= 4.0;

      /* Sum: '<S367>/SAS_SteeringAngleSpeed_Ad' */
      rtb_SAS_SteeringAngleSpeed_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Saturate: '<S367>/SAS_SteeringAngleSpeed_sat' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleSpeed_sat;
      rtb_SAS_SteeringAngleSpeed_sat = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* DataTypeConversion: '<S367>/SAS_SteeringAngleValid_Convert' */
      rtb_SAS_SteeringAngleValid_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_gv[3];

      /* S-Function (sfix_bitop): '<S367>/SAS_SteeringAngleValid_L' */
      rtb_SAS_SteeringAngleValid_L &= 128U;

      /* ArithShift: '<S367>/SAS_SteeringAngleValid_S' */
      rtb_SAS_SteeringAngleValid_L = (int32_T)((uint32_T)
        rtb_SAS_SteeringAngleValid_L >> 7);

      /* DataTypeConversion: '<S367>/SAS_SteeringAngleValidcv' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;

      /* Sum: '<S367>/SAS_SteeringAngleValid_Ad' */
      rtb_SAS_SteeringAngleValid_L = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Saturate: '<S367>/SAS_SteeringAngleValid_sat' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngleValid_L;
      rtb_SAS_SteeringAngleValid_L = (int32_T)rtb_SAS_SteeringAngle_Ad;

      /* Gain: '<S367>/SAS_SteeringAngle_F' */
      rtb_SAS_SteeringAngle_F *= 0.1;

      /* Sum: '<S367>/SAS_SteeringAngle_Ad' */
      rtb_SAS_SteeringAngle_Ad = rtb_SAS_SteeringAngle_F;

      /* Saturate: '<S367>/SAS_SteeringAngle_sat' */
      if (rtb_SAS_SteeringAngle_Ad > 780.0) {
        SAS_SteeringAngle = 780.0;
      } else if (rtb_SAS_SteeringAngle_Ad < -780.0) {
        SAS_SteeringAngle = -780.0;
      } else {
        SAS_SteeringAngle = rtb_SAS_SteeringAngle_Ad;
      }

      /* End of Saturate: '<S367>/SAS_SteeringAngle_sat' */

      /* SignalConversion: '<S366>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.SAS_SteeringAngle_k = SAS_SteeringAngle;

      /* SignalConversion: '<S366>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.SAS_SteeringAngleSpeed =
        rtb_SAS_SteeringAngleSpeed_sat;

      /* SignalConversion: '<S366>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.SAS_Calibrated = rtb_SAS_Calibrated_sat;

      /* SignalConversion: '<S366>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.SAS_SASFailure = rtb_SAS_SASFailure_sat;

      /* SignalConversion: '<S366>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.SAS_SteeringAngleValid =
        rtb_SAS_SteeringAngleValid_L;

      /* SignalConversion: '<S366>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.SAS_RollingCounter =
        rtb_SAS_RollingCounter_sat;

      /* SignalConversion: '<S366>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.SAS_CRCCheck = rtb_SAS_CRCCheck_sat;
    }

    /* End of Outputs for SubSystem: '<S365>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S103>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF20RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf20looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_b= 952;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_or= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_e2= ec_can_receive(1,20,
      CAN1BUF20RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_hb[0]=
      CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_hb[1]=
      CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_hb[2]=
      CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_hb[3]=
      CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_hb[4]=
      CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_hb[5]=
      CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_hb[6]=
      CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_hb[7]=
      CAN1BUF20RX[can1buf20looprx];
    can1buf20looprx++;
  }

  /* Call the system: <S103>/ReceiveMessages */

  /* Output and update for function-call system: '<S103>/ReceiveMessages' */

  /* Outputs for Enabled SubSystem: '<S375>/Subsystem' incorporates:
   *  EnablePort: '<S376>/Enable'
   */
  if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_e2 > 0) {
    /* SignalConversion: '<S376>/Signal Conversion' */
    VCU_CS75_10_9_SteeringTorque_B.SCM_ACCOn = 0.0;

    /* SignalConversion: '<S376>/Signal Conversion' */
    VCU_CS75_10_9_SteeringTorque_B.SCM_ACCCancel = 0.0;

    /* SignalConversion: '<S376>/Signal Conversion' */
    VCU_CS75_10_9_SteeringTorque_B.SCM_Resume = 0.0;

    /* SignalConversion: '<S376>/Signal Conversion' */
    VCU_CS75_10_9_SteeringTorque_B.SCM_Speeddecrease = 0.0;

    /* SignalConversion: '<S376>/Signal Conversion' */
    VCU_CS75_10_9_SteeringTorque_B.SCM_TimeGap = 0.0;

    /* SignalConversion: '<S376>/Signal Conversion' */
    VCU_CS75_10_9_SteeringTorque_B.SCM_IACCOn = 0.0;
  }

  /* End of Outputs for SubSystem: '<S375>/Subsystem' */

  /* S-Function (ec5744_canreceiveslb): '<S104>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF21RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf21looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_hy= 5;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_bt= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_pe= ec_can_receive(1,21,
      CAN1BUF21RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_kv[0]=
      CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_kv[1]=
      CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_kv[2]=
      CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_kv[3]=
      CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_kv[4]=
      CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_kv[5]=
      CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_kv[6]=
      CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_kv[7]=
      CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
  }

  /* Call the system: <S104>/ReceiveMessages */

  /* Output and update for function-call system: '<S104>/ReceiveMessages' */
  {
    int32_T rtb_SRS_RollingCounter_L;
    int32_T rtb_SRS_DriverBuckleSwitchStatu;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S384>/Subsystem' incorporates:
     *  EnablePort: '<S385>/Enable'
     */
    if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_pe > 0) {
      /* DataTypeConversion: '<S386>/SRS_DriverBuckleSwitchStatus_Convert' */
      rtb_SRS_RollingCounter_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_kv[1];

      /* S-Function (sfix_bitop): '<S386>/SRS_DriverBuckleSwitchStatus_L' */
      rtb_SRS_RollingCounter_L &= 192U;

      /* ArithShift: '<S386>/SRS_DriverBuckleSwitchStatus_S' */
      rtb_SRS_RollingCounter_L = (int32_T)((uint32_T)rtb_SRS_RollingCounter_L >>
        6);

      /* Sum: '<S386>/SRS_DriverBuckleSwitchStatus_Ad' */
      rtb_SRS_DriverBuckleSwitchStatu = rtb_SRS_RollingCounter_L;

      /* Saturate: '<S386>/SRS_DriverBuckleSwitchStatus_sat' */
      u0 = rtb_SRS_DriverBuckleSwitchStatu;
      rtb_SRS_DriverBuckleSwitchStatu = (int32_T)u0;

      /* DataTypeConversion: '<S386>/SRS_RollingCounter_Convert' */
      rtb_SRS_RollingCounter_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_kv[3];

      /* S-Function (sfix_bitop): '<S386>/SRS_RollingCounter_L' */
      rtb_SRS_RollingCounter_L &= 15U;

      /* Saturate: '<S386>/SRS_RollingCounter_sat' */
      u0 = rtb_SRS_RollingCounter_L;
      rtb_SRS_RollingCounter_L = (int32_T)u0;

      /* SignalConversion: '<S385>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.SRS_DriverBuckleSwitchStatus =
        rtb_SRS_DriverBuckleSwitchStatu;

      /* SignalConversion: '<S385>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.SRS_RollingCounter =
        rtb_SRS_RollingCounter_L;
    }

    /* End of Outputs for SubSystem: '<S384>/Subsystem' */
  }

  /* S-Function (ec5744_canreceiveslb): '<S105>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF22RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf22looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_i4= 646;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_px= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_bp= ec_can_receive(1,22,
      CAN1BUF22RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_m[0]=
      CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_m[1]=
      CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_m[2]=
      CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_m[3]=
      CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_m[4]=
      CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_m[5]=
      CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_m[6]=
      CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_m[7]=
      CAN1BUF22RX[can1buf22looprx];
    can1buf22looprx++;
  }

  /* Call the system: <S105>/ReceiveMessages */

  /* Output and update for function-call system: '<S105>/ReceiveMessages' */
  {
    int32_T rtb_TCU_GearShiftPosition_L;
    real_T u0;

    /* Outputs for Enabled SubSystem: '<S389>/Subsystem' incorporates:
     *  EnablePort: '<S390>/Enable'
     */
    if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_bp > 0) {
      /* DataTypeConversion: '<S391>/TCU_ActualGear_Convert' */
      rtb_TCU_GearShiftPosition_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_m[1];

      /* S-Function (sfix_bitop): '<S391>/TCU_ActualGear_L' */
      rtb_TCU_GearShiftPosition_L &= 15U;

      /* Saturate: '<S391>/TCU_ActualGear_sat' */
      u0 = rtb_TCU_GearShiftPosition_L;
      rtb_TCU_GearShiftPosition_L = (int32_T)u0;

      /* SignalConversion: '<S390>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.TCU_ActualGear =
        rtb_TCU_GearShiftPosition_L;

      /* DataTypeConversion: '<S391>/TCU_ShiftPositionValid_Convert' */
      rtb_TCU_GearShiftPosition_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_m[1];

      /* S-Function (sfix_bitop): '<S391>/TCU_ShiftPositionValid_L' */
      rtb_TCU_GearShiftPosition_L &= 16U;

      /* ArithShift: '<S391>/TCU_ShiftPositionValid_S' */
      rtb_TCU_GearShiftPosition_L = (int32_T)((uint32_T)
        rtb_TCU_GearShiftPosition_L >> 4);

      /* Saturate: '<S391>/TCU_ShiftPositionValid_sat' */
      u0 = rtb_TCU_GearShiftPosition_L;
      rtb_TCU_GearShiftPosition_L = (int32_T)u0;

      /* SignalConversion: '<S390>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.TCU_ShiftPositionValid =
        rtb_TCU_GearShiftPosition_L;

      /* DataTypeConversion: '<S391>/TCU_ActualGearValid_Convert' */
      rtb_TCU_GearShiftPosition_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_m[1];

      /* S-Function (sfix_bitop): '<S391>/TCU_ActualGearValid_L' */
      rtb_TCU_GearShiftPosition_L &= 32U;

      /* ArithShift: '<S391>/TCU_ActualGearValid_S' */
      rtb_TCU_GearShiftPosition_L = (int32_T)((uint32_T)
        rtb_TCU_GearShiftPosition_L >> 5);

      /* Saturate: '<S391>/TCU_ActualGearValid_sat' */
      u0 = rtb_TCU_GearShiftPosition_L;
      rtb_TCU_GearShiftPosition_L = (int32_T)u0;

      /* SignalConversion: '<S390>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.TCU_ActualGearValid =
        rtb_TCU_GearShiftPosition_L;

      /* DataTypeConversion: '<S391>/TCU_GearShiftPosition_Convert' */
      rtb_TCU_GearShiftPosition_L =
        VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_m[2];

      /* S-Function (sfix_bitop): '<S391>/TCU_GearShiftPosition_L' */
      rtb_TCU_GearShiftPosition_L &= 240U;

      /* ArithShift: '<S391>/TCU_GearShiftPosition_S' */
      rtb_TCU_GearShiftPosition_L = (int32_T)((uint32_T)
        rtb_TCU_GearShiftPosition_L >> 4);

      /* Saturate: '<S391>/TCU_GearShiftPosition_sat' */
      u0 = rtb_TCU_GearShiftPosition_L;
      rtb_TCU_GearShiftPosition_L = (int32_T)u0;

      /* SignalConversion: '<S390>/Signal Conversion' */
      VCU_CS75_10_9_SteeringTorque_B.TCU_GearShiftPosition =
        rtb_TCU_GearShiftPosition_L;
    }

    /* End of Outputs for SubSystem: '<S389>/Subsystem' */
  }

  /* End of Outputs for SubSystem: '<S2>/Input' */

  /* Outputs for Atomic SubSystem: '<S2>/APP' */
  /* Inport: '<S24>/APP_Input' */
  rtb_APP_Input_idx_0 = VCU_CS75_10_9_SteeringTorque_B.AutoDrivingReady;
  rtb_APP_Input_idx_1 = VCU_CS75_10_9_SteeringTorque_B.RemoteAcclPosition;
  rtb_APP_Input_idx_2 = VCU_CS75_10_9_SteeringTorque_B.LaterlAngleCommand;
  rtb_APP_Input_idx_3 = VCU_CS75_10_9_SteeringTorque_B.A1_Message_Counter;
  rtb_APP_Input_idx_8 = VCU_CS75_10_9_SteeringTorque_B.EMS_FrictionalTorq_d;
  rtb_APP_Input_idx_9 = VCU_CS75_10_9_SteeringTorque_B.EMS_IndicatedRealEngTorq;
  rtb_APP_Input_idx_12 = VCU_CS75_10_9_SteeringTorque_B.EMS_BrakePedalStatus_l;
  rtb_APP_Input_idx_17 = VCU_CS75_10_9_SteeringTorque_B.EMS_RollingCounter_id255;
  rtb_APP_Input_idx_19 =
    VCU_CS75_10_9_SteeringTorque_B.EMS_FullLoadIndicatedTorq;
  rtb_APP_Input_idx_20 = VCU_CS75_10_9_SteeringTorque_B.EMS_TorqueConstant_c;
  rtb_APP_Input_idx_29 = VCU_CS75_10_9_SteeringTorque_B.EPS_EPSFailed_k;
  rtb_APP_Input_idx_39 = VCU_CS75_10_9_SteeringTorque_B.EPS_AvailabilityStatus_a;
  rtb_APP_Input_idx_63 = VCU_CS75_10_9_SteeringTorque_B.Wheel_Speed_RR;
  rtb_APP_Input_idx_66 = VCU_CS75_10_9_SteeringTorque_B.Wheel_Speed_RL;
  rtb_APP_Input_idx_79 = VCU_CS75_10_9_SteeringTorque_B.ESP_ESPFailStatus;
  rtb_APP_Input_idx_99 = VCU_CS75_10_9_SteeringTorque_B.SAS_SteeringAngle_k;
  rtb_APP_Input_idx_217 = P6_Value;

  /* MATLAB Function: '<S53>/MATLAB Function2' */
  /* MATLAB Function '����CS75���̳���20msһ��/APP/Monitor/Vehicle_Status/MATLAB Function2': '<S56>:1' */
  if ((rtb_APP_Input_idx_29 == 1.0) || (rtb_APP_Input_idx_79 == 1.0)) {
    /* '<S56>:1:2' */
    /* '<S56>:1:3' */
    VehicleFaultStatus = 1.0;
  } else {
    /* '<S56>:1:5' */
    VehicleFaultStatus = 0.0;
  }

  /* End of MATLAB Function: '<S53>/MATLAB Function2' */

  /* Memory: '<S53>/Memory3' */
  rtb_P6_Value = VCU_CS75_10_9_SteeringTorque_DW.Memory3_PreviousInput;

  /* Memory: '<S53>/Memory2' */
  rtb_Memory2 = VCU_CS75_10_9_SteeringTorque_DW.Memory2_PreviousInput;

  /* MATLAB Function: '<S53>/MATLAB Function4' incorporates:
   *  Constant: '<S53>/1s'
   */
  /* MATLAB Function '����CS75���̳���20msһ��/APP/Monitor/Vehicle_Status/MATLAB Function4': '<S57>:1' */
  if (rtb_APP_Input_idx_17 == rtb_P6_Value) {
    /* '<S57>:1:2' */
    /* '<S57>:1:3' */
    rtb_P6_Value = rtb_Memory2 + 1.0;
  } else {
    /* '<S57>:1:5' */
    rtb_P6_Value = 0.0;
  }

  if (rtb_P6_Value * 20.0 > 1000.0) {
    /* '<S57>:1:7' */
    /* '<S57>:1:8' */
    VehicleCommunicationStatus = 0.0;
  } else {
    /* '<S57>:1:10' */
    VehicleCommunicationStatus = 1.0;
  }

  counter1 = rtb_P6_Value;

  /* End of MATLAB Function: '<S53>/MATLAB Function4' */

  /* DataTypeConversion: '<S53>/Data Type Conversion' */
  EPS_AvailabilityStatus = rtb_APP_Input_idx_39;

  /* Constant: '<S51>/Constant' */
  Server_CommunicationStatus = 1.0;

  /* Chart: '<S29>/Chart' */
  /* Gateway: ����CS75���̳���20msһ��/APP/System_State_Manager/Chart */
  /* During: ����CS75���̳���20msһ��/APP/System_State_Manager/Chart */
  if (VCU_CS75_10_9_SteeringTorque_DW.bitsForTID4.is_active_c4_VCU_CS75_10_9_Stee
      == 0U) {
    /* Entry: ����CS75���̳���20msһ��/APP/System_State_Manager/Chart */
    VCU_CS75_10_9_SteeringTorque_DW.bitsForTID4.is_active_c4_VCU_CS75_10_9_Stee =
      1U;

    /* Entry Internal: ����CS75���̳���20msһ��/APP/System_State_Manager/Chart */
    VCU_CS75_10_9_SteeringTorque_DW.bitsForTID4.is_c4_VCU_CS75_10_9_SteeringTor =
      VCU_CS75_10_9_S_IN_System_State;

    /* Entry Internal 'System_State': '<S58>:16' */
    /* Transition: '<S58>:11' */
    VCU_CS75_10_9_SteeringTorque_DW.bitsForTID4.is_System_State =
      VCU_CS75__IN_INIT_ManualDriving;

    /* Entry 'INIT_ManualDriving': '<S58>:7' */
    /* ��ʻԱ������ʻ */
    System_State = 0.0;
  } else {
    /* During 'System_State': '<S58>:16' */
    switch (VCU_CS75_10_9_SteeringTorque_DW.bitsForTID4.is_System_State) {
     case VCU_CS75_10_9_St_IN_AutoDriving:
      /* During 'AutoDriving': '<S58>:8' */
      out = ((VehicleFaultStatus == 1.0) || (VehicleCommunicationStatus == 0.0) ||
             (Server_CommunicationStatus == 0.0));
      if (out) {
        /* Transition: '<S58>:27' */
        VCU_CS75_10_9_SteeringTorque_DW.bitsForTID4.is_System_State =
          VCU_CS75_10_9_Steering_IN_Error;

        /* Entry 'Error': '<S58>:10' */
        /* ���ϣ����˹��ӹ� */
        System_State = 3.0;
      } else if (rtb_APP_Input_idx_12 == 1.0) {
        /* Transition: '<S58>:28' */
        VCU_CS75_10_9_SteeringTorque_DW.bitsForTID4.is_System_State =
          VCU_CS75_10_9_Steer_IN_TakeOver;

        /* Entry 'TakeOver': '<S58>:9' */
        /* �˹��ӹ�ģʽ */
        System_State = 2.0;
      } else if (rtb_APP_Input_idx_0 == 0.0) {
        /* Transition: '<S58>:31' */
        /* %&&Switch_P6 == 0 */
        VCU_CS75_10_9_SteeringTorque_DW.bitsForTID4.is_System_State =
          VCU_CS75__IN_INIT_ManualDriving;

        /* Entry 'INIT_ManualDriving': '<S58>:7' */
        /* ��ʻԱ������ʻ */
        System_State = 0.0;
      } else {
        System_State = 1.0;
      }
      break;

     case VCU_CS75_10_9_Steering_IN_Error:
      /* During 'Error': '<S58>:10' */
      out = ((rtb_APP_Input_idx_0 == 0.0) && (rtb_APP_Input_idx_217 == 0.0) &&
             (VehicleCommunicationStatus == 1.0) && (VehicleFaultStatus == 0.0));
      if (out) {
        /* Transition: '<S58>:35' */
        /* %&& Server_CommunicationStatus == 1 */
        VCU_CS75_10_9_SteeringTorque_DW.bitsForTID4.is_System_State =
          VCU_CS75__IN_INIT_ManualDriving;

        /* Entry 'INIT_ManualDriving': '<S58>:7' */
        /* ��ʻԱ������ʻ */
        System_State = 0.0;
      } else {
        System_State = 3.0;
      }
      break;

     case VCU_CS75__IN_INIT_ManualDriving:
      /* During 'INIT_ManualDriving': '<S58>:7' */
      out = ((rtb_APP_Input_idx_0 == 1.0) && (Server_CommunicationStatus == 1.0)
             && (rtb_APP_Input_idx_12 == 0.0) && (VehicleCommunicationStatus ==
              1.0) && (VehicleFaultStatus == 0.0));
      if (out) {
        /* Transition: '<S58>:18' */
        /* % &&Switch_P6 == 1&&EPS_AvailabilityStatus == 2 */
        VCU_CS75_10_9_SteeringTorque_DW.bitsForTID4.is_System_State =
          VCU_CS75_10_9_St_IN_AutoDriving;

        /* Entry 'AutoDriving': '<S58>:8' */
        /* �Զ���ʻ */
        System_State = 1.0;
      } else {
        System_State = 0.0;
      }
      break;

     default:
      /* During 'TakeOver': '<S58>:9' */
      out = ((rtb_APP_Input_idx_0 == 0.0) && (rtb_APP_Input_idx_217 == 0.0));
      if (out) {
        /* Transition: '<S58>:32' */
        VCU_CS75_10_9_SteeringTorque_DW.bitsForTID4.is_System_State =
          VCU_CS75__IN_INIT_ManualDriving;

        /* Entry 'INIT_ManualDriving': '<S58>:7' */
        /* ��ʻԱ������ʻ */
        System_State = 0.0;
      } else {
        out = ((VehicleFaultStatus == 1.0) || (VehicleCommunicationStatus == 0.0)
               || (Server_CommunicationStatus == 0.0));
        if (out) {
          /* Transition: '<S58>:39' */
          VCU_CS75_10_9_SteeringTorque_DW.bitsForTID4.is_System_State =
            VCU_CS75_10_9_Steering_IN_Error;

          /* Entry 'Error': '<S58>:10' */
          /* ���ϣ����˹��ӹ� */
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
  /* MATLAB Function '����CS75���̳���20msһ��/APP/Controller/Accesories/MATLAB Function': '<S34>:1' */
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
  VCU_CS75_10_MATLABFunction2(System_State,
    &VCU_CS75_10_9_SteeringTorque_B.sf_MATLABFunction2_d);

  /* End of Outputs for SubSystem: '<S27>/Accesories' */

  /* Outputs for Atomic SubSystem: '<S27>/Lateral' */
  /* Lookup_n-D: '<S32>/1-D Lookup Table' */
  /* MATLAB Function '����CS75���̳���20msһ��/APP/Controller/Accesories/MATLAB Function1': '<S35>:1' */
  mubiao_zhuanjiao = look1_binlx(rtb_APP_Input_idx_2,
    VCU_CS75_10_9_SteeringTo_ConstP.DLookupTable_bp01Data,
    VCU_CS75_10_9_SteeringTo_ConstP.pooled3, 1U);

  /* Memory: '<S32>/Memory3' */
  rtb_Memory2 = VCU_CS75_10_9_SteeringTorque_DW.Memory3_PreviousInput_j;

  /* Memory: '<S32>/Memory1' */
  rtb_P6_Value = VCU_CS75_10_9_SteeringTorque_DW.Memory1_PreviousInput_b;

  /* MATLAB Function: '<S32>/MATLAB Function' incorporates:
   *  Constant: '<S32>/Constant2'
   *  Constant: '<S32>/Constant3'
   *  Constant: '<S32>/Constant4'
   *  Constant: '<S32>/Constant5'
   */
  /* MATLAB Function '����CS75���̳���20msһ��/APP/Controller/Lateral/MATLAB Function': '<S38>:1' */
  /* '<S38>:1:3' */
  rtb_APP_Input_idx_0 = mubiao_zhuanjiao - rtb_APP_Input_idx_99;

  /* %%Ŀ��ת��-��ǰת�ǣ��Ƕȣ�-380~380�� */
  if (rtb_APP_Input_idx_217 == 1.0) {
    /* '<S38>:1:5' */
    /* '<S38>:1:6' */
    rtb_P6_Value += rtb_APP_Input_idx_0;

    /* %�ۻ����  */
  } else {
    /* '<S38>:1:8' */
    rtb_P6_Value = 0.0;
  }

  /* %%�������㣻 */
  if (rtb_P6_Value > 1000.0) {
    /* '<S38>:1:12' */
    /* '<S38>:1:13' */
    rtb_P6_Value = 1000.0;
  } else {
    if (rtb_P6_Value < -1000.0) {
      /* '<S38>:1:14' */
      /* '<S38>:1:15' */
      rtb_P6_Value = -1000.0;
    }
  }

  /* %%�����޷� */
  /* '<S38>:1:19' */
  /* %%λ��ʽPID���� */
  /* '<S38>:1:22' */
  PID_SteeringOut = 0.0;
  if (rtb_APP_Input_idx_217 == 1.0) {
    /* '<S38>:1:23' */
    /* '<S38>:1:24' */
    PID_SteeringOut = (3.0 * rtb_APP_Input_idx_0 + 0.15 * rtb_P6_Value) +
      (rtb_APP_Input_idx_0 - rtb_Memory2) * 0.0;
  }

  /* %%ʵ�ʵ�ת����� */
  ErrorSum = rtb_P6_Value;

  /* End of MATLAB Function: '<S32>/MATLAB Function' */

  /* Memory: '<S32>/Memory' */
  rtb_P6_Value = VCU_CS75_10_9_SteeringTorque_DW.Memory_PreviousInput;

  /* MATLAB Function: '<S32>/MATLAB Function10' incorporates:
   *  Constant: '<S32>/Constant6'
   */
  /* MATLAB Function '����CS75���̳���20msһ��/APP/Controller/Lateral/MATLAB Function10': '<S39>:1' */
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

  /* End of MATLAB Function: '<S32>/MATLAB Function10' */

  /* Memory: '<S32>/Memory2' */
  rtb_P6_Value = VCU_CS75_10_9_SteeringTorque_DW.Memory2_PreviousInput_l;

  /* MATLAB Function: '<S32>/MATLAB Function2' */
  /* MATLAB Function '����CS75���̳���20msһ��/APP/Controller/Lateral/MATLAB Function2': '<S40>:1' */
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
  /* MATLAB Function '����CS75���̳���20msһ��/APP/Controller/Lateral/MATLAB Function3': '<S41>:1' */
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

  /* MATLAB Function: '<S32>/MATLAB Function7' */
  VCU_CS75_10_MATLABFunction2(System_State,
    &VCU_CS75_10_9_SteeringTorque_B.sf_MATLABFunction7);

  /* Switch: '<S32>/Switch' incorporates:
   *  Constant: '<S32>/Constant'
   */
  if (rtb_APP_Input_idx_217 > 0.0) {
    /* Gain: '<S32>/Gain' */
    rtb_P6_Value = 0.01 * rtb_Memory2;
  } else {
    rtb_P6_Value = 0.0;
  }

  /* End of Switch: '<S32>/Switch' */

  /* Saturate: '<S32>/Saturation' */
  if (rtb_P6_Value > 3.0) {
    LAS_SteeringTorque = 3.0;
  } else if (rtb_P6_Value < -3.0) {
    LAS_SteeringTorque = -3.0;
  } else {
    LAS_SteeringTorque = rtb_P6_Value;
  }

  /* End of Saturate: '<S32>/Saturation' */

  /* Update for Memory: '<S32>/Memory3' */
  VCU_CS75_10_9_SteeringTorque_DW.Memory3_PreviousInput_j = rtb_APP_Input_idx_0;

  /* Update for Memory: '<S32>/Memory1' */
  VCU_CS75_10_9_SteeringTorque_DW.Memory1_PreviousInput_b = ErrorSum;

  /* Update for Memory: '<S32>/Memory' */
  VCU_CS75_10_9_SteeringTorque_DW.Memory_PreviousInput = rtb_Memory2;

  /* Update for Memory: '<S32>/Memory2' */
  VCU_CS75_10_9_SteeringTorque_DW.Memory2_PreviousInput_l = LAS_RollingCounter;

  /* End of Outputs for SubSystem: '<S27>/Lateral' */

  /* Outputs for Atomic SubSystem: '<S27>/Longitudinal' */
  /* MATLAB Function: '<S33>/MATLAB Function' */
  /* MATLAB Function '����CS75���̳���20msһ��/APP/Controller/Longitudinal/MATLAB Function': '<S43>:1' */
  if (rtb_APP_Input_idx_1 < 0.0) {
    /* '<S43>:1:2' */
    /* '<S43>:1:3' */
    ACC_CDDAxEnable = 1.0;
  } else {
    /* '<S43>:1:5' */
    ACC_CDDAxEnable = 0.0;
  }

  /* End of MATLAB Function: '<S33>/MATLAB Function' */

  /* MATLAB Function: '<S33>/MATLAB Function1' */
  /* MATLAB Function '����CS75���̳���20msһ��/APP/Controller/Longitudinal/MATLAB Function1': '<S44>:1' */
  if (rtb_APP_Input_idx_1 >= 0.0) {
    /* '<S44>:1:2' */
    /* '<S44>:1:3' */
    ACC_Driveoff_Request = 1.0;
  } else {
    /* '<S44>:1:5' */
    ACC_Driveoff_Request = 0.0;
  }

  /* End of MATLAB Function: '<S33>/MATLAB Function1' */

  /* MATLAB Function: '<S33>/MATLAB Function7' */
  VCU_CS75_10_MATLABFunction2(System_State,
    &VCU_CS75_10_9_SteeringTorque_B.sf_MATLABFunction7_g);

  /* MATLAB Function: '<S33>/MATLAB Function2' */
  /* MATLAB Function '����CS75���̳���20msһ��/APP/Controller/Longitudinal/MATLAB Function2': '<S45>:1' */
  if ((rtb_APP_Input_idx_1 <= 0.0) &&
      (VCU_CS75_10_9_SteeringTorque_B.sf_MATLABFunction7_g.y == 1.0)) {
    /* '<S45>:1:2' */
    /* '<S45>:1:3' */
    ACC_ACCTargetAcceleration = rtb_APP_Input_idx_1;
  } else {
    /* '<S45>:1:5' */
    ACC_ACCTargetAcceleration = 0.0;
  }

  /* End of MATLAB Function: '<S33>/MATLAB Function2' */

  /* Memory: '<S33>/Memory1' */
  rtb_P6_Value = VCU_CS75_10_9_SteeringTorque_DW.Memory1_PreviousInput_p;

  /* MATLAB Function: '<S33>/MATLAB Function3' */
  /* MATLAB Function '����CS75���̳���20msһ��/APP/Controller/Longitudinal/MATLAB Function3': '<S46>:1' */
  if (rtb_P6_Value == 15.0) {
    /* '<S46>:1:2' */
    /* '<S46>:1:3' */
    rtb_P6_Value = 0.0;
  } else {
    /* '<S46>:1:5' */
  }

  if (VCU_CS75_10_9_SteeringTorque_B.sf_MATLABFunction7_g.y == 1.0) {
    /* '<S46>:1:8' */
    /* '<S46>:1:9' */
    ACC_RollingCounter_id2E4 = rtb_P6_Value + 1.0;
  } else {
    /* '<S46>:1:11' */
    ACC_RollingCounter_id2E4 = rtb_P6_Value;
  }

  /* End of MATLAB Function: '<S33>/MATLAB Function3' */

  /* Memory: '<S33>/Memory2' */
  rtb_P6_Value = VCU_CS75_10_9_SteeringTorque_DW.Memory2_PreviousInput_b;

  /* MATLAB Function: '<S33>/MATLAB Function4' */
  /* MATLAB Function '����CS75���̳���20msһ��/APP/Controller/Longitudinal/MATLAB Function4': '<S47>:1' */
  if (rtb_P6_Value == 15.0) {
    /* '<S47>:1:2' */
    /* '<S47>:1:3' */
    rtb_P6_Value = 0.0;
  } else {
    /* '<S47>:1:5' */
  }

  if (VCU_CS75_10_9_SteeringTorque_B.sf_MATLABFunction7_g.y == 1.0) {
    /* '<S47>:1:8' */
    /* '<S47>:1:9' */
    ACC_RollingCounter_id2E5 = rtb_P6_Value + 1.0;
  } else {
    /* '<S47>:1:11' */
    ACC_RollingCounter_id2E5 = rtb_P6_Value;
  }

  /* End of MATLAB Function: '<S33>/MATLAB Function4' */

  /* MATLAB Function: '<S33>/MATLAB Function5' */
  /* MATLAB Function '����CS75���̳���20msһ��/APP/Controller/Longitudinal/MATLAB Function5': '<S48>:1' */
  if ((rtb_APP_Input_idx_1 >= 0.0) &&
      (VCU_CS75_10_9_SteeringTorque_B.sf_MATLABFunction7_g.y == 1.0)) {
    /* '<S48>:1:2' */
    /* '<S48>:1:3' */
    ACC_AccTorqueReq = rtb_APP_Input_idx_1;
  } else {
    /* '<S48>:1:5' */
    ACC_AccTorqueReq = 0.0;
  }

  /* End of MATLAB Function: '<S33>/MATLAB Function5' */

  /* MATLAB Function: '<S33>/MATLAB Function6' */
  /* MATLAB Function '����CS75���̳���20msһ��/APP/Controller/Longitudinal/MATLAB Function6': '<S49>:1' */
  if (rtb_APP_Input_idx_1 <= 0.0) {
    /* '<S49>:1:2' */
    /* '<S49>:1:3' */
    ACC_TrqEnable = 0.0;
  } else {
    /* '<S49>:1:5' */
    ACC_TrqEnable = 1.0;
  }

  /* End of MATLAB Function: '<S33>/MATLAB Function6' */

  /* Saturate: '<S33>/Saturation' */
  rtb_APP_Input_idx_79 = ACC_ACCTargetAcceleration;
  if (rtb_APP_Input_idx_79 > 0.0) {
    rtb_APP_Input_idx_79 = 0.0;
  } else {
    if (rtb_APP_Input_idx_79 < -5.0) {
      rtb_APP_Input_idx_79 = -5.0;
    }
  }

  /* End of Saturate: '<S33>/Saturation' */

  /* Saturate: '<S33>/Saturation1' */
  rtb_APP_Input_idx_2 = ACC_AccTorqueReq;
  if (rtb_APP_Input_idx_2 > 10.0) {
    rtb_APP_Input_idx_2 = 10.0;
  } else {
    if (rtb_APP_Input_idx_2 < 0.0) {
      rtb_APP_Input_idx_2 = 0.0;
    }
  }

  /* End of Saturate: '<S33>/Saturation1' */

  /* Update for Memory: '<S33>/Memory1' */
  VCU_CS75_10_9_SteeringTorque_DW.Memory1_PreviousInput_p =
    ACC_RollingCounter_id2E4;

  /* Update for Memory: '<S33>/Memory2' */
  VCU_CS75_10_9_SteeringTorque_DW.Memory2_PreviousInput_b =
    ACC_RollingCounter_id2E5;

  /* End of Outputs for SubSystem: '<S27>/Longitudinal' */

  /* Memory: '<S51>/Memory1' */
  A1counter = VCU_CS75_10_9_SteeringTorque_DW.Memory1_PreviousInput;

  /* Memory: '<S51>/Memory2' */
  rtb_P6_Value = VCU_CS75_10_9_SteeringTorque_DW.Memory2_PreviousInput_c;

  /* MATLAB Function: '<S51>/MATLAB Function1' */
  /* MATLAB Function '����CS75���̳���20msһ��/APP/Monitor/Server_Status/MATLAB Function1': '<S55>:1' */
  if (rtb_APP_Input_idx_3 == A1counter) {
    /* '<S55>:1:2' */
    /* '<S55>:1:3' */
    rtb_P6_Value++;
  } else {
    /* '<S55>:1:5' */
    rtb_P6_Value = 0.0;
  }

  counter3 = rtb_P6_Value;

  /* End of MATLAB Function: '<S51>/MATLAB Function1' */

  /* Update for Memory: '<S53>/Memory3' */
  VCU_CS75_10_9_SteeringTorque_DW.Memory3_PreviousInput = rtb_APP_Input_idx_17;

  /* Update for Memory: '<S53>/Memory2' */
  VCU_CS75_10_9_SteeringTorque_DW.Memory2_PreviousInput = counter1;

  /* Update for Memory: '<S51>/Memory1' */
  VCU_CS75_10_9_SteeringTorque_DW.Memory1_PreviousInput = rtb_APP_Input_idx_3;

  /* Update for Memory: '<S51>/Memory2' */
  VCU_CS75_10_9_SteeringTorque_DW.Memory2_PreviousInput_c = counter3;

  /* End of Outputs for SubSystem: '<S2>/APP' */

  /* Lookup_n-D: '<S695>/1-D Lookup Table' */
  rtb_APP_Input_idx_29 = look1_binlx(rtb_APP_Input_idx_99,
    VCU_CS75_10_9_SteeringTo_ConstP.pooled3,
    VCU_CS75_10_9_SteeringTo_ConstP.DLookupTable_tableDat, 1U);

  /* Abs: '<S695>/Abs' */
  rtb_Memory2 = fabs(rtb_APP_Input_idx_63);

  /* Abs: '<S695>/Abs1' */
  rtb_APP_Input_idx_0 = fabs(rtb_APP_Input_idx_66);

  /* Gain: '<S695>/Gain' */
  rtb_APP_Input_idx_29 *= 0.017453291666666666;

  /* Saturate: '<S704>/Steering_Angle_Feedback_sat' */
  if (rtb_APP_Input_idx_29 > 0.69787) {
    rtb_APP_Input_idx_29 = 0.69787;
  } else {
    if (rtb_APP_Input_idx_29 < -0.698) {
      rtb_APP_Input_idx_29 = -0.698;
    }
  }

  /* End of Saturate: '<S704>/Steering_Angle_Feedback_sat' */

  /* Sum: '<S704>/Steering_Angle_Feedback_st' incorporates:
   *  Constant: '<S704>/Steering_Angle_Feedback_O'
   */
  rtb_P6_Value = rtb_APP_Input_idx_29 - -0.69800001382827759;

  /* Product: '<S704>/Steering_Angle_Feedback_D' */
  rtb_APP_Input_idx_29 = rtb_P6_Value / 0.00547399977222085;

  /* Rounding: '<S704>/Steering_Angle_FeedbackRon' */
  rtb_APP_Input_idx_29 = rt_roundd_snf(rtb_APP_Input_idx_29);

  /* DataTypeConversion: '<S704>/Steering_Angle_Feedback_Convert1' */
  rtb_LAS_SteeringTorqueReq_L = (uint32_T)rtb_APP_Input_idx_29;

  /* S-Function (sfix_bitop): '<S704>/Steering_Angle_Feedback_L' */
  rtb_ACC_RollingCounter_L = rtb_LAS_SteeringTorqueReq_L & 255U;

  /* DataTypeConversion: '<S704>/Steering_Angle_Feedback_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_ACC_RollingCounter_L;

  /* S-Function (sfix_bitop): '<S700>/or1' */
  VCU_CS75_10_9_SteeringTorque_B.or1 = rtb_ACC_CDDAxEnable_Convert;

  /* Gain: '<S695>/Gain1' */
  EMS_IndicatedRealTroq = 0.01 * rtb_APP_Input_idx_9;

  /* Saturate: '<S701>/Engine_Feedback_sat' */
  rtb_P6_Value = EMS_IndicatedRealTroq;
  if (rtb_P6_Value > 1.0) {
    rtb_P6_Value = 1.0;
  } else {
    if (rtb_P6_Value < -1.0) {
      rtb_P6_Value = -1.0;
    }
  }

  /* End of Saturate: '<S701>/Engine_Feedback_sat' */

  /* Sum: '<S701>/Engine_Feedback_st' incorporates:
   *  Constant: '<S701>/Engine_Feedback_O'
   */
  rtb_APP_Input_idx_29 = rtb_P6_Value - -1.0;

  /* Product: '<S701>/Engine_Feedback_D' */
  rtb_P6_Value = rtb_APP_Input_idx_29 / 0.0078431377187371254;

  /* Rounding: '<S701>/Engine_FeedbackRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S701>/Engine_Feedback_Convert1' */
  rtb_ACC_RollingCounter_L = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S701>/Engine_Feedback_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ACC_RollingCounter_L & 255U;

  /* DataTypeConversion: '<S701>/Engine_Feedback_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_LAS_SteeringTorqueReq_L;

  /* S-Function (sfix_bitop): '<S700>/or2' */
  VCU_CS75_10_9_SteeringTorque_B.or2 = rtb_ACC_CDDAxEnable_Convert;

  /* Saturate: '<S702>/Engine_Feedback2_sat' */
  rtb_P6_Value = EMS_IndicatedRealTroq;
  if (rtb_P6_Value > 1.0) {
    rtb_P6_Value = 1.0;
  } else {
    if (rtb_P6_Value < -1.0) {
      rtb_P6_Value = -1.0;
    }
  }

  /* End of Saturate: '<S702>/Engine_Feedback2_sat' */

  /* Sum: '<S702>/Engine_Feedback2_st' incorporates:
   *  Constant: '<S702>/Engine_Feedback2_O'
   */
  rtb_APP_Input_idx_29 = rtb_P6_Value - -1.0;

  /* Product: '<S702>/Engine_Feedback2_D' */
  rtb_P6_Value = rtb_APP_Input_idx_29 / 0.0078431377187371254;

  /* Rounding: '<S702>/Engine_Feedback2Ron' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S702>/Engine_Feedback2_Convert1' */
  rtb_ACC_RollingCounter_L = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S702>/Engine_Feedback2_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ACC_RollingCounter_L & 255U;

  /* DataTypeConversion: '<S702>/Engine_Feedback2_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_LAS_SteeringTorqueReq_L;

  /* S-Function (sfix_bitop): '<S700>/or3' */
  VCU_CS75_10_9_SteeringTorque_B.or3 = rtb_ACC_CDDAxEnable_Convert;

  /* Saturate: '<S706>/Wheel_Speed_RL_Feedback_sat' */
  if (rtb_APP_Input_idx_0 > 200.0) {
    rtb_APP_Input_idx_0 = 200.0;
  }

  /* End of Saturate: '<S706>/Wheel_Speed_RL_Feedback_sat' */

  /* Sum: '<S706>/Wheel_Speed_RL_Feedback_st' */
  rtb_P6_Value = rtb_APP_Input_idx_0;

  /* Product: '<S706>/Wheel_Speed_RL_Feedback_D' */
  rtb_APP_Input_idx_0 = rtb_P6_Value / 0.78431373834609985;

  /* Rounding: '<S706>/Wheel_Speed_RL_FeedbackRon' */
  rtb_APP_Input_idx_0 = rt_roundd_snf(rtb_APP_Input_idx_0);

  /* DataTypeConversion: '<S706>/Wheel_Speed_RL_Feedback_Convert1' */
  rtb_ACC_RollingCounter_L = (uint32_T)rtb_APP_Input_idx_0;

  /* S-Function (sfix_bitop): '<S706>/Wheel_Speed_RL_Feedback_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ACC_RollingCounter_L & 255U;

  /* DataTypeConversion: '<S706>/Wheel_Speed_RL_Feedback_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_LAS_SteeringTorqueReq_L;

  /* S-Function (sfix_bitop): '<S700>/or4' */
  VCU_CS75_10_9_SteeringTorque_B.or4 = rtb_ACC_CDDAxEnable_Convert;

  /* Saturate: '<S707>/Wheel_Speed_RR_Feedback_sat' */
  if (rtb_Memory2 > 200.0) {
    rtb_Memory2 = 200.0;
  }

  /* End of Saturate: '<S707>/Wheel_Speed_RR_Feedback_sat' */

  /* Sum: '<S707>/Wheel_Speed_RR_Feedback_st' */
  rtb_P6_Value = rtb_Memory2;

  /* Product: '<S707>/Wheel_Speed_RR_Feedback_D' */
  rtb_APP_Input_idx_0 = rtb_P6_Value / 0.78431373834609985;

  /* Rounding: '<S707>/Wheel_Speed_RR_FeedbackRon' */
  rtb_APP_Input_idx_0 = rt_roundd_snf(rtb_APP_Input_idx_0);

  /* DataTypeConversion: '<S707>/Wheel_Speed_RR_Feedback_Convert1' */
  rtb_ACC_RollingCounter_L = (uint32_T)rtb_APP_Input_idx_0;

  /* S-Function (sfix_bitop): '<S707>/Wheel_Speed_RR_Feedback_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ACC_RollingCounter_L & 255U;

  /* DataTypeConversion: '<S707>/Wheel_Speed_RR_Feedback_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_LAS_SteeringTorqueReq_L;

  /* S-Function (sfix_bitop): '<S700>/or5' */
  VCU_CS75_10_9_SteeringTorque_B.or5 = rtb_ACC_CDDAxEnable_Convert;

  /* Saturate: '<S703>/Res_go_sat' */
  if (rtb_APP_Input_idx_217 > 1.0) {
    rtb_P6_Value = 1.0;
  } else if (rtb_APP_Input_idx_217 < 0.0) {
    rtb_P6_Value = 0.0;
  } else {
    rtb_P6_Value = rtb_APP_Input_idx_217;
  }

  /* End of Saturate: '<S703>/Res_go_sat' */

  /* Sum: '<S703>/Res_go_st' */
  rtb_APP_Input_idx_0 = rtb_P6_Value;

  /* Rounding: '<S703>/Res_goRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S703>/Res_go_Convert1' */
  rtb_ACC_RollingCounter_L = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S703>/Res_go_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ACC_RollingCounter_L & 255U;

  /* DataTypeConversion: '<S703>/Res_go_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_LAS_SteeringTorqueReq_L;

  /* S-Function (sfix_bitop): '<S700>/or6' */
  VCU_CS75_10_9_SteeringTorque_B.or6 = rtb_ACC_CDDAxEnable_Convert;

  /* Saturate: '<S705>/Steering_feedback_sat' */
  if (rtb_APP_Input_idx_99 > 499.998565) {
    rtb_P6_Value = 499.998565;
  } else if (rtb_APP_Input_idx_99 < -500.0) {
    rtb_P6_Value = -500.0;
  } else {
    rtb_P6_Value = rtb_APP_Input_idx_99;
  }

  /* End of Saturate: '<S705>/Steering_feedback_sat' */

  /* Sum: '<S705>/Steering_feedback_st' incorporates:
   *  Constant: '<S705>/Steering_feedback_O'
   */
  rtb_APP_Input_idx_0 = rtb_P6_Value - -500.0;

  /* Product: '<S705>/Steering_feedback_D' */
  rtb_P6_Value = rtb_APP_Input_idx_0 / 0.015258999541401863;

  /* Rounding: '<S705>/Steering_feedbackRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S705>/Steering_feedback_Convert' */
  rtb_ACC_RollingCounter_L = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S705>/Steering_feedback_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ACC_RollingCounter_L & 65535U;

  /* S-Function (sfix_bitop): '<S705>/Steering_feedback_And' incorporates:
   *  Constant: '<S705>/Steering_feedback_And_C'
   */
  rtb_ACC_RollingCounter_L = rtb_LAS_SteeringTorqueReq_L & 255U;

  /* DataTypeConversion: '<S705>/BitCov' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_ACC_RollingCounter_L;

  /* S-Function (sfix_bitop): '<S700>/or7' */
  VCU_CS75_10_9_SteeringTorque_B.or7 = rtb_ACC_CDDAxEnable_Convert;

  /* Product: '<S705>/Steering_feedback_D1' incorporates:
   *  Constant: '<S705>/Steering_feedbackoutput8_C'
   */
  rtb_P6_Value = (real_T)rtb_LAS_SteeringTorqueReq_L / 256.0;

  /* DataTypeConversion: '<S705>/Steering_feedbackCOV' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S700>/or8' */
  VCU_CS75_10_9_SteeringTorque_B.or8 = rtb_ACC_CDDAxEnable_Convert;

  /* S-Function (ec5744_cantransmitslb): '<S695>/CANTransmit' */

  /*Transmit CAN message*/
  {
    uint8 CAN0BUF8TX[8];
    uint8 can0buf8looptx= 0;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_10_9_SteeringTorque_B.or1;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_10_9_SteeringTorque_B.or2;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_10_9_SteeringTorque_B.or3;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_10_9_SteeringTorque_B.or4;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_10_9_SteeringTorque_B.or5;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_10_9_SteeringTorque_B.or6;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_10_9_SteeringTorque_B.or7;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= VCU_CS75_10_9_SteeringTorque_B.or8;
    can0buf8looptx++;
    VCU_CS75_10_9_SteeringTorque_B.CANTransmit_i= ec_can_transmit(0, 8, 1, 1297U,
      8, CAN0BUF8TX);
  }

  /* DataTypeConversion: '<S695>/Data Type Conversion' */
  EMS_FrictionalTroq = rtb_APP_Input_idx_8;

  /* DataTypeConversion: '<S695>/Data Type Conversion1' */
  EMS_TorqueConstant = rtb_APP_Input_idx_20;

  /* DataTypeConversion: '<S695>/Data Type Conversion2' */
  EMS_FullLoadIndicatedTroq = rtb_APP_Input_idx_19;

  /* Saturate: '<S747>/LAS_LDWStatus_sat' */
  rtb_P6_Value = LAS_LDWStatus;
  if (rtb_P6_Value > 3.0) {
    rtb_P6_Value = 3.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S747>/LAS_LDWStatus_sat' */

  /* Sum: '<S747>/LAS_LDWStatus_st' */
  rtb_APP_Input_idx_0 = rtb_P6_Value;

  /* Rounding: '<S747>/LAS_LDWStatusRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* ArithShift: '<S747>/LAS_LDWStatus_S' */
  rtb_P6_Value = ldexp(rtb_P6_Value, 5);

  /* DataTypeConversion: '<S747>/LAS_LDWStatus_Convert1' */
  rtb_ACC_RollingCounter_L = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S747>/LAS_LDWStatus_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ACC_RollingCounter_L & 96U;

  /* DataTypeConversion: '<S747>/LAS_LDWStatus_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_LAS_SteeringTorqueReq_L;

  /* S-Function (sfix_bitop): '<S740>/or1' */
  VCU_CS75_10_9_SteeringTorque_B.or1_m = rtb_ACC_CDDAxEnable_Convert;

  /* Saturate: '<S748>/LAS_LDWVibrationWarning_sat' */
  rtb_P6_Value = LAS_LDWVibrationWarning;
  if (rtb_P6_Value > 3.0) {
    rtb_P6_Value = 3.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S748>/LAS_LDWVibrationWarning_sat' */

  /* Sum: '<S748>/LAS_LDWVibrationWarning_st' */
  rtb_APP_Input_idx_0 = rtb_P6_Value;

  /* Rounding: '<S748>/LAS_LDWVibrationWarningRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* ArithShift: '<S748>/LAS_LDWVibrationWarning_S' */
  rtb_P6_Value = ldexp(rtb_P6_Value, 5);

  /* DataTypeConversion: '<S748>/LAS_LDWVibrationWarning_Convert1' */
  rtb_ACC_RollingCounter_L = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S748>/LAS_LDWVibrationWarning_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ACC_RollingCounter_L & 96U;

  /* DataTypeConversion: '<S748>/LAS_LDWVibrationWarning_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_LAS_SteeringTorqueReq_L;

  /* S-Function (sfix_bitop): '<S740>/or2' */
  VCU_CS75_10_9_SteeringTorque_B.or2_g = rtb_ACC_CDDAxEnable_Convert;

  /* Saturate: '<S753>/LAS_SteeringTorqueReq_sat' */
  rtb_P6_Value = LAS_SteeringTorque;
  if (rtb_P6_Value > 12.47) {
    rtb_P6_Value = 12.47;
  } else {
    if (rtb_P6_Value < -8.0) {
      rtb_P6_Value = -8.0;
    }
  }

  /* End of Saturate: '<S753>/LAS_SteeringTorqueReq_sat' */

  /* Sum: '<S753>/LAS_SteeringTorqueReq_st' incorporates:
   *  Constant: '<S753>/LAS_SteeringTorqueReq_O'
   */
  rtb_APP_Input_idx_0 = rtb_P6_Value - -8.0;

  /* Product: '<S753>/LAS_SteeringTorqueReq_D' */
  rtb_P6_Value = rtb_APP_Input_idx_0 / 0.0099999997764825821;

  /* Rounding: '<S753>/LAS_SteeringTorqueReqRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* ArithShift: '<S753>/LAS_SteeringTorqueReq_S' */
  rtb_P6_Value = ldexp(rtb_P6_Value, 7);

  /* DataTypeConversion: '<S753>/LAS_SteeringTorqueReq_Convert' */
  rtb_ACC_RollingCounter_L = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S753>/LAS_SteeringTorqueReq_L' */
  rtb_LAS_SteeringTorqueReq_L = rtb_ACC_RollingCounter_L & 262016U;

  /* Product: '<S753>/LAS_SteeringTorqueReq_D1' incorporates:
   *  Constant: '<S753>/LAS_SteeringTorqueReqoutput5_C'
   */
  rtb_P6_Value = (real_T)rtb_LAS_SteeringTorqueReq_L / 65536.0;

  /* DataTypeConversion: '<S753>/LAS_SteeringTorqueReqCOV' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_P6_Value;

  /* Saturate: '<S749>/LAS_LKSStatus_sat' */
  rtb_P6_Value = LAS_LKSStatus;
  if (rtb_P6_Value > 7.0) {
    rtb_P6_Value = 7.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S749>/LAS_LKSStatus_sat' */

  /* Sum: '<S749>/LAS_LKSStatus_st' */
  rtb_APP_Input_idx_0 = rtb_P6_Value;

  /* Rounding: '<S749>/LAS_LKSStatusRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* ArithShift: '<S749>/LAS_LKSStatus_S' */
  rtb_P6_Value = ldexp(rtb_P6_Value, 5);

  /* DataTypeConversion: '<S749>/LAS_LKSStatus_Convert1' */
  rtb_ACC_RollingCounter_L = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S749>/LAS_LKSStatus_L' */
  rtb_ACC_RollingCounter_Convert1 = rtb_ACC_RollingCounter_L & 224U;

  /* DataTypeConversion: '<S749>/LAS_LKSStatus_Convert' */
  rtb_ACC_ACCTargetAcceleration_C = (uint8_T)rtb_ACC_RollingCounter_Convert1;

  /* S-Function (sfix_bitop): '<S740>/or5' */
  VCU_CS75_10_9_SteeringTorque_B.or5_h = (uint8_T)(rtb_ACC_CDDAxEnable_Convert |
    rtb_ACC_ACCTargetAcceleration_C);

  /* S-Function (sfix_bitop): '<S753>/LAS_SteeringTorqueReq_And' */
  rtb_ACC_RollingCounter_Convert1 = rtb_LAS_SteeringTorqueReq_L & 65535U;

  /* Product: '<S753>/LAS_SteeringTorqueReq_D2' incorporates:
   *  Constant: '<S753>/LAS_SteeringTorqueReqoutput6_C'
   */
  rtb_P6_Value = (real_T)rtb_ACC_RollingCounter_Convert1 / 256.0;

  /* DataTypeConversion: '<S753>/LAS_SteeringTorqueReqCOV1' */
  rtb_ACC_ACCTargetAcceleration_C = (uint8_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S740>/or6' */
  VCU_CS75_10_9_SteeringTorque_B.or6_f = rtb_ACC_ACCTargetAcceleration_C;

  /* S-Function (sfix_bitop): '<S753>/LAS_SteeringTorqueReq_And1' incorporates:
   *  Constant: '<S753>/LAS_SteeringTorqueReq_And1_C'
   */
  rtb_ACC_RollingCounter_Convert1 = rtb_LAS_SteeringTorqueReq_L & 255U;

  /* DataTypeConversion: '<S753>/LAS_SteeringTorqueReqBitCov1' */
  rtb_ACC_ACCTargetAcceleration_C = (uint8_T)rtb_ACC_RollingCounter_Convert1;

  /* Saturate: '<S755>/RollingConter_sat' */
  rtb_P6_Value = LAS_RollingCounter;
  if (rtb_P6_Value > 15.0) {
    rtb_P6_Value = 15.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S755>/RollingConter_sat' */

  /* Rounding: '<S755>/RollingConterRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S755>/RollingConter_Convert1' */
  rtb_ACC_RollingCounter_Convert1 = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S755>/RollingConter_L' */
  rtb_ACC_RollingCounter_L = rtb_ACC_RollingCounter_Convert1 & 15U;

  /* DataTypeConversion: '<S755>/RollingConter_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_ACC_RollingCounter_L;

  /* S-Function (sfix_bitop): '<S740>/or7' */
  VCU_CS75_10_9_SteeringTorque_B.or7_h = (uint8_T)
    (rtb_ACC_ACCTargetAcceleration_C | rtb_ACC_CDDAxEnable_Convert);

  /* S-Function (ec5744_cantransmitslb): '<S737>/CANTransmit' */

  /*Transmit CAN message*/
  {
    uint8 CAN1BUF13TX[8];
    uint8 can1buf13looptx= 0;
    CAN1BUF13TX[can1buf13looptx]= VCU_CS75_10_9_SteeringTorque_B.or1_m;
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= VCU_CS75_10_9_SteeringTorque_B.or2_g;
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= VCU_CS75_10_9_SteeringTo_ConstB.or3;
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= VCU_CS75_10_9_SteeringTo_ConstB.or4;
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= VCU_CS75_10_9_SteeringTorque_B.or5_h;
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= VCU_CS75_10_9_SteeringTorque_B.or6_f;
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= VCU_CS75_10_9_SteeringTorque_B.or7_h;
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= VCU_CS75_10_9_SteeringTo_ConstB.or8;
    can1buf13looptx++;
    VCU_CS75_10_9_SteeringTorque_B.CANTransmit_b= ec_can_transmit(1, 13, 0, 653U,
      8, CAN1BUF13TX);
  }

  /* Saturate: '<S757>/ACC_ACCTargetAcceleration_sat' */
  rtb_P6_Value = rtb_APP_Input_idx_79;

  /* Sum: '<S757>/ACC_ACCTargetAcceleration_st' incorporates:
   *  Constant: '<S757>/ACC_ACCTargetAcceleration_O'
   */
  rtb_APP_Input_idx_0 = rtb_P6_Value - -5.0;

  /* Product: '<S757>/ACC_ACCTargetAcceleration_D' */
  rtb_P6_Value = rtb_APP_Input_idx_0 / 0.05000000074505806;

  /* Rounding: '<S757>/ACC_ACCTargetAccelerationRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S757>/ACC_ACCTargetAcceleration_Convert1' */
  rtb_ACC_RollingCounter_Convert1 = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S757>/ACC_ACCTargetAcceleration_L' */
  rtb_ACC_RollingCounter_L = rtb_ACC_RollingCounter_Convert1 & 255U;

  /* DataTypeConversion: '<S757>/ACC_ACCTargetAcceleration_Convert' */
  rtb_ACC_ACCTargetAcceleration_C = (uint8_T)rtb_ACC_RollingCounter_L;

  /* Saturate: '<S758>/ACC_CDDAxEnable_sat' */
  rtb_P6_Value = ACC_CDDAxEnable;
  if (rtb_P6_Value > 1.0) {
    rtb_P6_Value = 1.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S758>/ACC_CDDAxEnable_sat' */

  /* Sum: '<S758>/ACC_CDDAxEnable_st' */
  rtb_APP_Input_idx_0 = rtb_P6_Value;

  /* Rounding: '<S758>/ACC_CDDAxEnableRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S758>/ACC_CDDAxEnable_Convert1' */
  rtb_ACC_RollingCounter_Convert1 = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S758>/ACC_CDDAxEnable_L' */
  rtb_ACC_RollingCounter_L = rtb_ACC_RollingCounter_Convert1 & 1U;

  /* DataTypeConversion: '<S758>/ACC_CDDAxEnable_Convert' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_ACC_RollingCounter_L;

  /* Saturate: '<S760>/ACC_DecToStop_sat' incorporates:
   *  Constant: '<S33>/Constant1'
   */
  rtb_P6_Value = 0.0;

  /* Saturate: '<S761>/ACC_Driveoff_Request_sat' */
  rtb_APP_Input_idx_29 = ACC_Driveoff_Request;
  if (rtb_APP_Input_idx_29 > 1.0) {
    rtb_P6_Value = 1.0;
  } else {
    if (!(rtb_APP_Input_idx_29 < 0.0)) {
      rtb_P6_Value = rtb_APP_Input_idx_29;
    }
  }

  /* End of Saturate: '<S761>/ACC_Driveoff_Request_sat' */

  /* Sum: '<S761>/ACC_Driveoff_Request_st' */
  rtb_APP_Input_idx_0 = rtb_P6_Value;

  /* Rounding: '<S761>/ACC_Driveoff_RequestRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* ArithShift: '<S761>/ACC_Driveoff_Request_S' */
  rtb_P6_Value = ldexp(rtb_P6_Value, 2);

  /* DataTypeConversion: '<S761>/ACC_Driveoff_Request_Convert1' */
  rtb_ACC_RollingCounter_Convert1 = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S761>/ACC_Driveoff_Request_L' */
  rtb_ACC_RollingCounter_L = rtb_ACC_RollingCounter_Convert1 & 4U;

  /* DataTypeConversion: '<S761>/ACC_Driveoff_Request_Convert' */
  rtb_ACC_AccTrqReqEnable_Convert = (uint8_T)rtb_ACC_RollingCounter_L;

  /* Saturate: '<S763>/ACC_RollingCounter_id_sat' */
  rtb_P6_Value = ACC_RollingCounter_id2E4;
  if (rtb_P6_Value > 15.0) {
    rtb_P6_Value = 15.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S763>/ACC_RollingCounter_id_sat' */

  /* Rounding: '<S763>/ACC_RollingCounter_idRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S763>/ACC_RollingCounter_id_Convert1' */
  rtb_ACC_RollingCounter_Convert1 = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S763>/ACC_RollingCounter_id_L' */
  rtb_ACC_RollingCounter_L = rtb_ACC_RollingCounter_Convert1 & 15U;

  /* DataTypeConversion: '<S763>/ACC_RollingCounter_id_Convert' */
  rtb_ACC_AccTorqueReqBitCov = (uint8_T)rtb_ACC_RollingCounter_L;

  /* S-Function (sfix_bitop): '<S756>/or1' */
  VCU_CS75_10_9_SteeringTorque_B.or1_i = (uint8_T)(rtb_ACC_CDDAxEnable_Convert |
    rtb_ACC_AccTrqReqEnable_Convert | 24);

  /* S-Function (sfix_bitop): '<S756>/or2' */
  VCU_CS75_10_9_SteeringTorque_B.or2_b = rtb_ACC_ACCTargetAcceleration_C;

  /* S-Function (sfix_bitop): '<S756>/or7' */
  VCU_CS75_10_9_SteeringTorque_B.or7_g = rtb_ACC_AccTorqueReqBitCov;

  /* S-Function (ec5744_cantransmitslb): '<S738>/CANTransmit' */

  /*Transmit CAN message*/
  {
    uint8 CAN1BUF8TX[8];
    uint8 can1buf8looptx= 0;
    CAN1BUF8TX[can1buf8looptx]= VCU_CS75_10_9_SteeringTorque_B.or1_i;
    can1buf8looptx++;
    CAN1BUF8TX[can1buf8looptx]= VCU_CS75_10_9_SteeringTorque_B.or2_b;
    can1buf8looptx++;
    CAN1BUF8TX[can1buf8looptx]= VCU_CS75_10_9_SteeringTo_ConstB.or3_e;
    can1buf8looptx++;
    CAN1BUF8TX[can1buf8looptx]= VCU_CS75_10_9_SteeringTo_ConstB.or4_n;
    can1buf8looptx++;
    CAN1BUF8TX[can1buf8looptx]= VCU_CS75_10_9_SteeringTo_ConstB.or5;
    can1buf8looptx++;
    CAN1BUF8TX[can1buf8looptx]= VCU_CS75_10_9_SteeringTo_ConstB.or6;
    can1buf8looptx++;
    CAN1BUF8TX[can1buf8looptx]= VCU_CS75_10_9_SteeringTorque_B.or7_g;
    can1buf8looptx++;
    CAN1BUF8TX[can1buf8looptx]= VCU_CS75_10_9_SteeringTo_ConstB.or8_c;
    can1buf8looptx++;
    VCU_CS75_10_9_SteeringTorque_B.CANTransmit_it= ec_can_transmit(1, 8, 0, 740U,
      8, CAN1BUF8TX);
  }

  /* Saturate: '<S772>/ACC_AccTorqueReq_sat' */
  rtb_P6_Value = rtb_APP_Input_idx_2;

  /* Sum: '<S772>/ACC_AccTorqueReq_st' */
  rtb_APP_Input_idx_0 = rtb_P6_Value;

  /* Product: '<S772>/ACC_AccTorqueReq_D' */
  rtb_P6_Value = rtb_APP_Input_idx_0 / 0.097840003669261932;

  /* Rounding: '<S772>/ACC_AccTorqueReqRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* ArithShift: '<S772>/ACC_AccTorqueReq_S' */
  rtb_P6_Value = ldexp(rtb_P6_Value, 2);

  /* DataTypeConversion: '<S772>/ACC_AccTorqueReq_Convert' */
  rtb_ACC_RollingCounter_Convert1 = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S772>/ACC_AccTorqueReq_L' */
  rtb_ACC_RollingCounter_L = rtb_ACC_RollingCounter_Convert1 & 4092U;

  /* S-Function (sfix_bitop): '<S772>/ACC_AccTorqueReq_And' incorporates:
   *  Constant: '<S772>/ACC_AccTorqueReq_And_C'
   */
  rtb_ACC_RollingCounter_Convert1 = rtb_ACC_RollingCounter_L & 255U;

  /* DataTypeConversion: '<S772>/ACC_AccTorqueReqBitCov' */
  rtb_ACC_AccTorqueReqBitCov = (uint8_T)rtb_ACC_RollingCounter_Convert1;

  /* Product: '<S772>/ACC_AccTorqueReq_D1' incorporates:
   *  Constant: '<S772>/ACC_AccTorqueReqoutput5_C'
   */
  rtb_P6_Value = (real_T)rtb_ACC_RollingCounter_L / 256.0;

  /* DataTypeConversion: '<S772>/ACC_AccTorqueReqCOV' */
  rtb_ACC_CDDAxEnable_Convert = (uint8_T)rtb_P6_Value;

  /* Saturate: '<S773>/ACC_AccTrqReqEnable_sat' */
  rtb_P6_Value = ACC_TrqEnable;
  if (rtb_P6_Value > 1.0) {
    rtb_P6_Value = 1.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S773>/ACC_AccTrqReqEnable_sat' */

  /* Sum: '<S773>/ACC_AccTrqReqEnable_st' */
  rtb_APP_Input_idx_0 = rtb_P6_Value;

  /* Rounding: '<S773>/ACC_AccTrqReqEnableRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* ArithShift: '<S773>/ACC_AccTrqReqEnable_S' */
  rtb_P6_Value = ldexp(rtb_P6_Value, 7);

  /* DataTypeConversion: '<S773>/ACC_AccTrqReqEnable_Convert1' */
  rtb_ACC_RollingCounter_Convert1 = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S773>/ACC_AccTrqReqEnable_L' */
  rtb_ACC_RollingCounter_L = rtb_ACC_RollingCounter_Convert1 & 128U;

  /* DataTypeConversion: '<S773>/ACC_AccTrqReqEnable_Convert' */
  rtb_ACC_AccTrqReqEnable_Convert = (uint8_T)rtb_ACC_RollingCounter_L;

  /* Saturate: '<S779>/ACC_RollingCounter_sat' */
  rtb_P6_Value = ACC_RollingCounter_id2E5;
  if (rtb_P6_Value > 15.0) {
    rtb_P6_Value = 15.0;
  } else {
    if (rtb_P6_Value < 0.0) {
      rtb_P6_Value = 0.0;
    }
  }

  /* End of Saturate: '<S779>/ACC_RollingCounter_sat' */

  /* Sum: '<S779>/ACC_RollingCounter_st' */
  rtb_APP_Input_idx_0 = rtb_P6_Value;

  /* Rounding: '<S779>/ACC_RollingCounterRon' */
  rtb_P6_Value = rt_roundd_snf(rtb_P6_Value);

  /* DataTypeConversion: '<S779>/ACC_RollingCounter_Convert1' */
  rtb_ACC_RollingCounter_Convert1 = (uint32_T)rtb_P6_Value;

  /* S-Function (sfix_bitop): '<S779>/ACC_RollingCounter_L' */
  rtb_ACC_RollingCounter_L = rtb_ACC_RollingCounter_Convert1 & 15U;

  /* DataTypeConversion: '<S779>/ACC_RollingCounter_Convert' */
  rtb_ACC_ACCTargetAcceleration_C = (uint8_T)rtb_ACC_RollingCounter_L;

  /* S-Function (sfix_bitop): '<S764>/or1' */
  VCU_CS75_10_9_SteeringTorque_B.or1_e = (uint8_T)
    (rtb_ACC_AccTrqReqEnable_Convert | 15);

  /* S-Function (sfix_bitop): '<S764>/or5' */
  VCU_CS75_10_9_SteeringTorque_B.or5_m = rtb_ACC_CDDAxEnable_Convert;

  /* S-Function (sfix_bitop): '<S764>/or6' */
  VCU_CS75_10_9_SteeringTorque_B.or6_e = rtb_ACC_AccTorqueReqBitCov;

  /* S-Function (sfix_bitop): '<S764>/or7' */
  VCU_CS75_10_9_SteeringTorque_B.or7_l = rtb_ACC_ACCTargetAcceleration_C;

  /* S-Function (ec5744_cantransmitslb): '<S739>/CANTransmit' */

  /*Transmit CAN message*/
  {
    uint8 CAN1BUF9TX[8];
    uint8 can1buf9looptx= 0;
    CAN1BUF9TX[can1buf9looptx]= VCU_CS75_10_9_SteeringTorque_B.or1_e;
    can1buf9looptx++;
    CAN1BUF9TX[can1buf9looptx]= VCU_CS75_10_9_SteeringTo_ConstB.or2;
    can1buf9looptx++;
    CAN1BUF9TX[can1buf9looptx]= VCU_CS75_10_9_SteeringTo_ConstB.or3_ei;
    can1buf9looptx++;
    CAN1BUF9TX[can1buf9looptx]= VCU_CS75_10_9_SteeringTo_ConstB.or4_a;
    can1buf9looptx++;
    CAN1BUF9TX[can1buf9looptx]= VCU_CS75_10_9_SteeringTorque_B.or5_m;
    can1buf9looptx++;
    CAN1BUF9TX[can1buf9looptx]= VCU_CS75_10_9_SteeringTorque_B.or6_e;
    can1buf9looptx++;
    CAN1BUF9TX[can1buf9looptx]= VCU_CS75_10_9_SteeringTorque_B.or7_l;
    can1buf9looptx++;
    CAN1BUF9TX[can1buf9looptx]= VCU_CS75_10_9_SteeringTo_ConstB.or8_n;
    can1buf9looptx++;
    VCU_CS75_10_9_SteeringTorque_B.CANTransmit_k= ec_can_transmit(1, 9, 0, 741U,
      8, CAN1BUF9TX);
  }
}

/* Model step function for TID5 */
void VCU_CS75_10_9_SteeringTorque_step5(void) /* Sample time: [0.05s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S4>/50ms' incorporates:
   *  SubSystem: '<S4>/daq50ms'
   */

  /* S-Function (ec5744_ccpslb1): '<S18>/CCPDAQ' */
  ccpDaq(2);
}

/* Model step function for TID6 */
void VCU_CS75_10_9_SteeringTorque_step6(void) /* Sample time: [0.1s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S3>/100MS' incorporates:
   *  SubSystem: '<S3>/Function-Call Subsystem'
   */

  /* S-Function (ec5744_canreceiveslb): '<S7>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN2BUF1RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can2buf1looprx= 0;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o3_i= 278;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o5_i= 8;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_a= ec_can_receive(2,1,
      CAN2BUF1RX);
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_h[0]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_h[1]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_h[2]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_h[3]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_h[4]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_h[5]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_h[6]= CAN2BUF1RX[can2buf1looprx];
    can2buf1looprx++;
    VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_h[7]= CAN2BUF1RX[can2buf1looprx];
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
    if (VCU_CS75_10_9_SteeringTorque_B.CANReceive_o2_a > 0) {
      /* RelationalOperator: '<S10>/Compare' incorporates:
       *  Constant: '<S10>/Constant'
       */
      rtb_Add = (uint8_T)(VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_h[0] ==
                          83);

      /* RelationalOperator: '<S11>/Compare' incorporates:
       *  Constant: '<S11>/Constant'
       */
      rtb_Compare = (uint8_T)(VCU_CS75_10_9_SteeringTorque_B.CANReceive_o4_h[5] ==
        84);

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
          VCU_CS75_10_9_SteeringTorque_B.CANTransmit= ec_can_transmit(2, 9, 0,
            593U, 1, CAN2BUF9TX);
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
void VCU_CS75_10_9_SteeringTorque_step7(void) /* Sample time: [0.5s, 0.0s] */
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
void VCU_CS75_10_9_SteeringTorque_step(int_T tid)
{
  switch (tid) {
   case 0 :
    VCU_CS75_10_9_SteeringTorque_step0();
    break;

   case 1 :
    VCU_CS75_10_9_SteeringTorque_step1();
    break;

   case 2 :
    VCU_CS75_10_9_SteeringTorque_step2();
    break;

   case 3 :
    VCU_CS75_10_9_SteeringTorque_step3();
    break;

   case 4 :
    VCU_CS75_10_9_SteeringTorque_step4();
    break;

   case 5 :
    VCU_CS75_10_9_SteeringTorque_step5();
    break;

   case 6 :
    VCU_CS75_10_9_SteeringTorque_step6();
    break;

   case 7 :
    VCU_CS75_10_9_SteeringTorque_step7();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void VCU_CS75_10_9_SteeringTorque_initialize(void)
{
  /* Start for S-Function (fcncallgen): '<Root>/20ms' incorporates:
   *  Start for SubSystem: '<Root>/����CS75���̳���20msһ��'
   */

  /* Start for Atomic SubSystem: '<S2>/Input' */

  /* Start for S-Function (ec5744_canreceiveslb): '<S65>/CANReceive' */
  ec_buffer_init(0,0,0,529);

  /* Start for S-Function (ec5744_canreceiveslb): '<S79>/CANReceive' */
  ec_buffer_init(1,23,0,648);

  /* Start for S-Function (ec5744_canreceiveslb): '<S80>/CANReceive' */
  ec_buffer_init(1,24,0,808);

  /* Start for S-Function (ec5744_canreceiveslb): '<S81>/CANReceive' */
  ec_buffer_init(1,25,0,840);

  /* Start for S-Function (ec5744_canreceiveslb): '<S82>/CANReceive' */
  ec_buffer_init(1,26,0,991);

  /* Start for S-Function (ec5744_canreceiveslb): '<S83>/CANReceive' */
  ec_buffer_init(1,0,0,517);

  /* Start for S-Function (ec5744_canreceiveslb): '<S84>/CANReceive' */
  ec_buffer_init(1,1,0,597);

  /* Start for S-Function (ec5744_canreceiveslb): '<S85>/CANReceive' */
  ec_buffer_init(1,2,0,613);

  /* Start for S-Function (ec5744_canreceiveslb): '<S86>/CANReceive' */
  ec_buffer_init(1,3,0,630);

  /* Start for S-Function (ec5744_canreceiveslb): '<S87>/CANReceive' */
  ec_buffer_init(1,4,0,598);

  /* Start for S-Function (ec5744_canreceiveslb): '<S88>/CANReceive' */
  ec_buffer_init(1,5,0,522);

  /* Start for S-Function (ec5744_canreceiveslb): '<S89>/CANReceive' */
  ec_buffer_init(1,6,0,538);

  /* Start for S-Function (ec5744_canreceiveslb): '<S90>/CANReceive' */
  ec_buffer_init(1,7,0,631);

  /* Start for S-Function (ec5744_canreceiveslb): '<S91>/CANReceive' */
  ec_buffer_init(1,16,0,640);

  /* Start for S-Function (ec5744_canreceiveslb): '<S92>/CANReceive' */
  ec_buffer_init(1,17,0,641);

  /* Start for S-Function (ec5744_canreceiveslb): '<S93>/CANReceive' */
  ec_buffer_init(1,18,0,647);

  /* Start for S-Function (ec5744_canreceiveslb): '<S94>/CANReceive' */
  ec_buffer_init(1,27,0,523);

  /* Start for S-Function (ec5744_canreceiveslb): '<S95>/CANReceive' */
  ec_buffer_init(1,29,0,776);

  /* Start for S-Function (ec5744_canreceiveslb): '<S96>/CANReceive' */
  ec_buffer_init(1,28,0,818);

  /* Start for S-Function (ec5744_canreceiveslb): '<S97>/CANReceive' */
  ec_buffer_init(1,30,0,886);

  /* Start for S-Function (ec5744_canreceiveslb): '<S98>/CANReceive' */
  ec_buffer_init(1,31,0,930);

  /* Start for S-Function (ec5744_canreceiveslb): '<S99>/CANReceive' */
  ec_buffer_init(1,32,0,1383);

  /* Start for S-Function (ec5744_canreceiveslb): '<S100>/CANReceive' */
  ec_buffer_init(1,33,0,1280);

  /* Start for S-Function (ec5744_canreceiveslb): '<S101>/CANReceive' */
  ec_buffer_init(1,36,0,878);

  /* Start for S-Function (ec5744_canreceiveslb): '<S102>/CANReceive' */
  ec_buffer_init(1,19,0,264);

  /* Start for S-Function (ec5744_canreceiveslb): '<S103>/CANReceive' */
  ec_buffer_init(1,20,0,952);

  /* Start for S-Function (ec5744_canreceiveslb): '<S104>/CANReceive' */
  ec_buffer_init(1,21,0,5);

  /* Start for S-Function (ec5744_canreceiveslb): '<S105>/CANReceive' */
  ec_buffer_init(1,22,0,646);

  /* End of Start for SubSystem: '<S2>/Input' */

  /* Start for Atomic SubSystem: '<S2>/APP' */
  /* Start for Constant: '<S51>/Constant' */
  Server_CommunicationStatus = 1.0;

  /* End of Start for SubSystem: '<S2>/APP' */
  /* Start for S-Function (ec5744_cantransmitslb): '<S695>/CANTransmit' */
  ec_buffer_init(0,8,1,1297U);

  /* Start for S-Function (ec5744_cantransmitslb): '<S737>/CANTransmit' */
  ec_buffer_init(1,13,0,653U);

  /* Start for S-Function (ec5744_cantransmitslb): '<S738>/CANTransmit' */
  ec_buffer_init(1,8,0,740U);

  /* Start for S-Function (ec5744_cantransmitslb): '<S739>/CANTransmit' */
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

/* File trailer for ECUCoder generated file VCU_CS75_10_9_SteeringTorque.c.
 *
 * [EOF]
 */
