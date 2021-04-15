#ifndef __c11_VCU_CS75_12_30_test_h__
#define __c11_VCU_CS75_12_30_test_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc11_VCU_CS75_12_30_testInstanceStruct
#define typedef_SFc11_VCU_CS75_12_30_testInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c11_sfEvent;
  boolean_T c11_isStable;
  boolean_T c11_doneDoubleBufferReInit;
  uint8_T c11_is_active_c11_VCU_CS75_12_30_test;
} SFc11_VCU_CS75_12_30_testInstanceStruct;

#endif                                 /*typedef_SFc11_VCU_CS75_12_30_testInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c11_VCU_CS75_12_30_test_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c11_VCU_CS75_12_30_test_get_check_sum(mxArray *plhs[]);
extern void c11_VCU_CS75_12_30_test_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
