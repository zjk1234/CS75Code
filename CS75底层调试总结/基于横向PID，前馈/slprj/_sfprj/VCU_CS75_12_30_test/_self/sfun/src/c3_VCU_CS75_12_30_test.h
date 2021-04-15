#ifndef __c3_VCU_CS75_12_30_test_h__
#define __c3_VCU_CS75_12_30_test_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_VCU_CS75_12_30_testInstanceStruct
#define typedef_SFc3_VCU_CS75_12_30_testInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  boolean_T c3_isStable;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_VCU_CS75_12_30_test;
} SFc3_VCU_CS75_12_30_testInstanceStruct;

#endif                                 /*typedef_SFc3_VCU_CS75_12_30_testInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_VCU_CS75_12_30_test_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c3_VCU_CS75_12_30_test_get_check_sum(mxArray *plhs[]);
extern void c3_VCU_CS75_12_30_test_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
