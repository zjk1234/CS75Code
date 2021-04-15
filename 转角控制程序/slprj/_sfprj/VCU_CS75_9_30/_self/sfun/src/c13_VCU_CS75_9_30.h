#ifndef __c13_VCU_CS75_9_30_h__
#define __c13_VCU_CS75_9_30_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc13_VCU_CS75_9_30InstanceStruct
#define typedef_SFc13_VCU_CS75_9_30InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c13_sfEvent;
  boolean_T c13_isStable;
  boolean_T c13_doneDoubleBufferReInit;
  uint8_T c13_is_active_c13_VCU_CS75_9_30;
} SFc13_VCU_CS75_9_30InstanceStruct;

#endif                                 /*typedef_SFc13_VCU_CS75_9_30InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c13_VCU_CS75_9_30_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c13_VCU_CS75_9_30_get_check_sum(mxArray *plhs[]);
extern void c13_VCU_CS75_9_30_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
