/*
 * Code generated for Simulink model VCU_CS75_10_9_SteeringTorque.
 *
 * FILE    : VCU_CS75_10_9_SteeringTorque_private.h
 *
 * VERSION : 1.2714
 *
 * DATE    : Wed Dec 16 11:38:52 2020
 *
 * Copyright 2011-2017 ECUCoder. All Rights Reserved.
 */

#ifndef RTW_HEADER_VCU_CS75_10_9_SteeringTorque_private_h_
#define RTW_HEADER_VCU_CS75_10_9_SteeringTorque_private_h_
#include "rtwtypes.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 /* __RTWTYPES_H__ */

/* #define mydefine 100.0 */
extern real_T rt_roundd_snf(real_T u);
extern real_T look1_binlx(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern void VCU_CS75_10_MATLABFunction2(real_T rtu_u,
  B_MATLABFunction2_VCU_CS75_10_T *localB);
extern void VCU_CS75_10_9_SteeringTorque_step0(void);
extern void VCU_CS75_10_9_SteeringTorque_step1(void);
extern void VCU_CS75_10_9_SteeringTorque_step2(void);
extern void VCU_CS75_10_9_SteeringTorque_step3(void);
extern void VCU_CS75_10_9_SteeringTorque_step4(void);
extern void VCU_CS75_10_9_SteeringTorque_step5(void);
extern void VCU_CS75_10_9_SteeringTorque_step6(void);
extern void VCU_CS75_10_9_SteeringTorque_step7(void);

#endif                                 /* RTW_HEADER_VCU_CS75_10_9_SteeringTorque_private_h_ */

/* File trailer for ECUCoder generated file VCU_CS75_10_9_SteeringTorque_private.h.
 *
 * [EOF]
 */
