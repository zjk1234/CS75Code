/* Include files */

#include <stddef.h>
#include "blas.h"
#include "VCU_CS75_12_30_test_sfun.h"
#include "c3_VCU_CS75_12_30_test.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "VCU_CS75_12_30_test_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[8] = { "nargin", "nargout",
  "TimeThreshold", "RollingCounter", "LastRollingCounter", "LastCounter",
  "EPS_CommunicationStatus", "Counter" };

/* Function Declarations */
static void initialize_c3_VCU_CS75_12_30_test
  (SFc3_VCU_CS75_12_30_testInstanceStruct *chartInstance);
static void initialize_params_c3_VCU_CS75_12_30_test
  (SFc3_VCU_CS75_12_30_testInstanceStruct *chartInstance);
static void enable_c3_VCU_CS75_12_30_test(SFc3_VCU_CS75_12_30_testInstanceStruct
  *chartInstance);
static void disable_c3_VCU_CS75_12_30_test
  (SFc3_VCU_CS75_12_30_testInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_VCU_CS75_12_30_test
  (SFc3_VCU_CS75_12_30_testInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_VCU_CS75_12_30_test
  (SFc3_VCU_CS75_12_30_testInstanceStruct *chartInstance);
static void set_sim_state_c3_VCU_CS75_12_30_test
  (SFc3_VCU_CS75_12_30_testInstanceStruct *chartInstance, const mxArray *c3_st);
static void finalize_c3_VCU_CS75_12_30_test
  (SFc3_VCU_CS75_12_30_testInstanceStruct *chartInstance);
static void sf_gateway_c3_VCU_CS75_12_30_test
  (SFc3_VCU_CS75_12_30_testInstanceStruct *chartInstance);
static void initSimStructsc3_VCU_CS75_12_30_test
  (SFc3_VCU_CS75_12_30_testInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_VCU_CS75_12_30_testInstanceStruct
  *chartInstance, const mxArray *c3_Counter, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_VCU_CS75_12_30_testInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_c_emlrt_marshallIn(SFc3_VCU_CS75_12_30_testInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_d_emlrt_marshallIn(SFc3_VCU_CS75_12_30_testInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_VCU_CS75_12_30_test, const
  char_T *c3_identifier);
static uint8_T c3_e_emlrt_marshallIn(SFc3_VCU_CS75_12_30_testInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_VCU_CS75_12_30_testInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_VCU_CS75_12_30_test
  (SFc3_VCU_CS75_12_30_testInstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_is_active_c3_VCU_CS75_12_30_test = 0U;
}

static void initialize_params_c3_VCU_CS75_12_30_test
  (SFc3_VCU_CS75_12_30_testInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_VCU_CS75_12_30_test(SFc3_VCU_CS75_12_30_testInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_VCU_CS75_12_30_test
  (SFc3_VCU_CS75_12_30_testInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_VCU_CS75_12_30_test
  (SFc3_VCU_CS75_12_30_testInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c3_VCU_CS75_12_30_test
  (SFc3_VCU_CS75_12_30_testInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  uint8_T c3_c_hoistedGlobal;
  uint8_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T *c3_Counter;
  real_T *c3_EPS_CommunicationStatus;
  c3_Counter = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_EPS_CommunicationStatus = (real_T *)ssGetOutputPortSignal(chartInstance->S,
    1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(3, 1), false);
  c3_hoistedGlobal = *c3_Counter;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *c3_EPS_CommunicationStatus;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = chartInstance->c3_is_active_c3_VCU_CS75_12_30_test;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_VCU_CS75_12_30_test
  (SFc3_VCU_CS75_12_30_testInstanceStruct *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T *c3_Counter;
  real_T *c3_EPS_CommunicationStatus;
  c3_Counter = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_EPS_CommunicationStatus = (real_T *)ssGetOutputPortSignal(chartInstance->S,
    1);
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  *c3_Counter = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 0)), "Counter");
  *c3_EPS_CommunicationStatus = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 1)), "EPS_CommunicationStatus");
  chartInstance->c3_is_active_c3_VCU_CS75_12_30_test = c3_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 2)),
     "is_active_c3_VCU_CS75_12_30_test");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_VCU_CS75_12_30_test(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_VCU_CS75_12_30_test
  (SFc3_VCU_CS75_12_30_testInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c3_VCU_CS75_12_30_test
  (SFc3_VCU_CS75_12_30_testInstanceStruct *chartInstance)
{
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  real_T c3_d_hoistedGlobal;
  real_T c3_TimeThreshold;
  real_T c3_RollingCounter;
  real_T c3_LastRollingCounter;
  real_T c3_LastCounter;
  uint32_T c3_debug_family_var_map[8];
  real_T c3_nargin = 4.0;
  real_T c3_nargout = 2.0;
  real_T c3_EPS_CommunicationStatus;
  real_T c3_Counter;
  real_T *c3_b_TimeThreshold;
  real_T *c3_b_EPS_CommunicationStatus;
  real_T *c3_b_RollingCounter;
  real_T *c3_b_LastRollingCounter;
  real_T *c3_b_LastCounter;
  real_T *c3_b_Counter;
  c3_b_Counter = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_b_LastCounter = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_b_LastRollingCounter = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_RollingCounter = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_EPS_CommunicationStatus = (real_T *)ssGetOutputPortSignal
    (chartInstance->S, 1);
  c3_b_TimeThreshold = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_b_TimeThreshold, 0U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *c3_b_TimeThreshold;
  c3_b_hoistedGlobal = *c3_b_RollingCounter;
  c3_c_hoistedGlobal = *c3_b_LastRollingCounter;
  c3_d_hoistedGlobal = *c3_b_LastCounter;
  c3_TimeThreshold = c3_hoistedGlobal;
  c3_RollingCounter = c3_b_hoistedGlobal;
  c3_LastRollingCounter = c3_c_hoistedGlobal;
  c3_LastCounter = c3_d_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_TimeThreshold, 2U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_RollingCounter, 3U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_LastRollingCounter, 4U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_LastCounter, 5U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_EPS_CommunicationStatus, 6U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_Counter, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 2);
  if (CV_EML_IF(0, 1, 0, c3_RollingCounter == c3_LastRollingCounter)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 3);
    c3_Counter = c3_LastCounter + 1.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
    c3_Counter = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
  if (CV_EML_IF(0, 1, 1, c3_Counter * 20.0 > c3_TimeThreshold)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
    c3_EPS_CommunicationStatus = 0.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 10);
    c3_EPS_CommunicationStatus = 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -10);
  _SFD_SYMBOL_SCOPE_POP();
  *c3_b_EPS_CommunicationStatus = c3_EPS_CommunicationStatus;
  *c3_b_Counter = c3_Counter;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_VCU_CS75_12_30_testMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c3_b_EPS_CommunicationStatus, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_b_RollingCounter, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_b_LastRollingCounter, 3U);
  _SFD_DATA_RANGE_CHECK(*c3_b_LastCounter, 4U);
  _SFD_DATA_RANGE_CHECK(*c3_b_Counter, 5U);
}

static void initSimStructsc3_VCU_CS75_12_30_test
  (SFc3_VCU_CS75_12_30_testInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  (void)c3_chartNumber;
  (void)c3_instanceNumber;
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_VCU_CS75_12_30_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_VCU_CS75_12_30_testInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_VCU_CS75_12_30_testInstanceStruct
  *chartInstance, const mxArray *c3_Counter, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_Counter), &c3_thisId);
  sf_mex_destroy(&c3_Counter);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_VCU_CS75_12_30_testInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_Counter;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_VCU_CS75_12_30_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_VCU_CS75_12_30_testInstanceStruct *)chartInstanceVoid;
  c3_Counter = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_Counter), &c3_thisId);
  sf_mex_destroy(&c3_Counter);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_VCU_CS75_12_30_test_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_VCU_CS75_12_30_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_VCU_CS75_12_30_testInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_c_emlrt_marshallIn(SFc3_VCU_CS75_12_30_testInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i0, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_VCU_CS75_12_30_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_VCU_CS75_12_30_testInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_d_emlrt_marshallIn(SFc3_VCU_CS75_12_30_testInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_VCU_CS75_12_30_test, const
  char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_VCU_CS75_12_30_test), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_VCU_CS75_12_30_test);
  return c3_y;
}

static uint8_T c3_e_emlrt_marshallIn(SFc3_VCU_CS75_12_30_testInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_VCU_CS75_12_30_testInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c3_VCU_CS75_12_30_test_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2859030961U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3929814649U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(977846781U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2509740421U);
}

mxArray *sf_c3_VCU_CS75_12_30_test_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("dgPZWB9YTemnZSj2OP8I8D");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_VCU_CS75_12_30_test_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_VCU_CS75_12_30_test_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_VCU_CS75_12_30_test(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[9],T\"Counter\",},{M[1],M[5],T\"EPS_CommunicationStatus\",},{M[8],M[0],T\"is_active_c3_VCU_CS75_12_30_test\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_VCU_CS75_12_30_test_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_VCU_CS75_12_30_testInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_VCU_CS75_12_30_testInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _VCU_CS75_12_30_testMachineNumber_,
           3,
           1,
           1,
           0,
           6,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_VCU_CS75_12_30_testMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_VCU_CS75_12_30_testMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _VCU_CS75_12_30_testMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"TimeThreshold");
          _SFD_SET_DATA_PROPS(1,2,0,1,"EPS_CommunicationStatus");
          _SFD_SET_DATA_PROPS(2,1,1,0,"RollingCounter");
          _SFD_SET_DATA_PROPS(3,1,1,0,"LastRollingCounter");
          _SFD_SET_DATA_PROPS(4,1,1,0,"LastCounter");
          _SFD_SET_DATA_PROPS(5,2,0,1,"Counter");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,320);
        _SFD_CV_INIT_EML_IF(0,1,0,111,150,182,207);
        _SFD_CV_INIT_EML_IF(0,1,1,208,241,275,316);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          real_T *c3_TimeThreshold;
          real_T *c3_EPS_CommunicationStatus;
          real_T *c3_RollingCounter;
          real_T *c3_LastRollingCounter;
          real_T *c3_LastCounter;
          real_T *c3_Counter;
          c3_Counter = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c3_LastCounter = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c3_LastRollingCounter = (real_T *)ssGetInputPortSignal
            (chartInstance->S, 2);
          c3_RollingCounter = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_EPS_CommunicationStatus = (real_T *)ssGetOutputPortSignal
            (chartInstance->S, 1);
          c3_TimeThreshold = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_TimeThreshold);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_EPS_CommunicationStatus);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_RollingCounter);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_LastRollingCounter);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_LastCounter);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_Counter);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _VCU_CS75_12_30_testMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "GZHpmzMvz5KOlU6xekq9KH";
}

static void sf_opaque_initialize_c3_VCU_CS75_12_30_test(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_VCU_CS75_12_30_testInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_VCU_CS75_12_30_test
    ((SFc3_VCU_CS75_12_30_testInstanceStruct*) chartInstanceVar);
  initialize_c3_VCU_CS75_12_30_test((SFc3_VCU_CS75_12_30_testInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_VCU_CS75_12_30_test(void *chartInstanceVar)
{
  enable_c3_VCU_CS75_12_30_test((SFc3_VCU_CS75_12_30_testInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_VCU_CS75_12_30_test(void *chartInstanceVar)
{
  disable_c3_VCU_CS75_12_30_test((SFc3_VCU_CS75_12_30_testInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_VCU_CS75_12_30_test(void *chartInstanceVar)
{
  sf_gateway_c3_VCU_CS75_12_30_test((SFc3_VCU_CS75_12_30_testInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_VCU_CS75_12_30_test(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_VCU_CS75_12_30_test
    ((SFc3_VCU_CS75_12_30_testInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_VCU_CS75_12_30_test();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c3_VCU_CS75_12_30_test(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c3_VCU_CS75_12_30_test();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_VCU_CS75_12_30_test((SFc3_VCU_CS75_12_30_testInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_VCU_CS75_12_30_test(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c3_VCU_CS75_12_30_test(S);
}

static void sf_opaque_set_sim_state_c3_VCU_CS75_12_30_test(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c3_VCU_CS75_12_30_test(S, st);
}

static void sf_opaque_terminate_c3_VCU_CS75_12_30_test(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_VCU_CS75_12_30_testInstanceStruct*) chartInstanceVar
      )->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_VCU_CS75_12_30_test_optimization_info();
    }

    finalize_c3_VCU_CS75_12_30_test((SFc3_VCU_CS75_12_30_testInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_VCU_CS75_12_30_test((SFc3_VCU_CS75_12_30_testInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_VCU_CS75_12_30_test(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c3_VCU_CS75_12_30_test
      ((SFc3_VCU_CS75_12_30_testInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_VCU_CS75_12_30_test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_VCU_CS75_12_30_test_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(995624213U));
  ssSetChecksum1(S,(2026604727U));
  ssSetChecksum2(S,(2463074723U));
  ssSetChecksum3(S,(3715641030U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_VCU_CS75_12_30_test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_VCU_CS75_12_30_test(SimStruct *S)
{
  SFc3_VCU_CS75_12_30_testInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_VCU_CS75_12_30_testInstanceStruct *)utMalloc(sizeof
    (SFc3_VCU_CS75_12_30_testInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_VCU_CS75_12_30_testInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_VCU_CS75_12_30_test;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_VCU_CS75_12_30_test;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_VCU_CS75_12_30_test;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_VCU_CS75_12_30_test;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_VCU_CS75_12_30_test;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_VCU_CS75_12_30_test;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_VCU_CS75_12_30_test;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_VCU_CS75_12_30_test;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_VCU_CS75_12_30_test;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_VCU_CS75_12_30_test;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_VCU_CS75_12_30_test;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c3_VCU_CS75_12_30_test_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_VCU_CS75_12_30_test(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_VCU_CS75_12_30_test(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_VCU_CS75_12_30_test(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_VCU_CS75_12_30_test_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
