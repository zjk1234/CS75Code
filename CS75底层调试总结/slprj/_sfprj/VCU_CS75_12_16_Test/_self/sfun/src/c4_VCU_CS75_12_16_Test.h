#ifndef __c4_VCU_CS75_12_16_Test_h__
#define __c4_VCU_CS75_12_16_Test_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_VCU_CS75_12_16_TestInstanceStruct
#define typedef_SFc4_VCU_CS75_12_16_TestInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  uint8_T c4_tp_System_State;
  uint8_T c4_tp_INIT_ManualDriving;
  uint8_T c4_tp_TakeOver;
  uint8_T c4_tp_AutoDriving;
  uint8_T c4_tp_Error;
  boolean_T c4_isStable;
  uint8_T c4_is_active_c4_VCU_CS75_12_16_Test;
  uint8_T c4_is_c4_VCU_CS75_12_16_Test;
  uint8_T c4_is_System_State;
  uint8_T c4_doSetSimStateSideEffects;
  const mxArray *c4_setSimStateSideEffectsInfo;
} SFc4_VCU_CS75_12_16_TestInstanceStruct;

#endif                                 /*typedef_SFc4_VCU_CS75_12_16_TestInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_VCU_CS75_12_16_Test_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c4_VCU_CS75_12_16_Test_get_check_sum(mxArray *plhs[]);
extern void c4_VCU_CS75_12_16_Test_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
