/* Include files */

#include <stddef.h>
#include "blas.h"
#include "VCU_CS75_12_27_test_log_sfun.h"
#include "c9_VCU_CS75_12_27_test_log.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "VCU_CS75_12_27_test_log_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c9_debug_family_names[6] = { "RealCounter", "nargin",
  "nargout", "Ready", "LastCounter", "RollingCounter" };

/* Function Declarations */
static void initialize_c9_VCU_CS75_12_27_test_log
  (SFc9_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void initialize_params_c9_VCU_CS75_12_27_test_log
  (SFc9_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void enable_c9_VCU_CS75_12_27_test_log
  (SFc9_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void disable_c9_VCU_CS75_12_27_test_log
  (SFc9_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void c9_update_debugger_state_c9_VCU_CS75_12_27_test_log
  (SFc9_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_VCU_CS75_12_27_test_log
  (SFc9_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void set_sim_state_c9_VCU_CS75_12_27_test_log
  (SFc9_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c9_st);
static void finalize_c9_VCU_CS75_12_27_test_log
  (SFc9_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void sf_gateway_c9_VCU_CS75_12_27_test_log
  (SFc9_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void initSimStructsc9_VCU_CS75_12_27_test_log
  (SFc9_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static real_T c9_emlrt_marshallIn(SFc9_VCU_CS75_12_27_test_logInstanceStruct
  *chartInstance, const mxArray *c9_RollingCounter, const char_T *c9_identifier);
static real_T c9_b_emlrt_marshallIn(SFc9_VCU_CS75_12_27_test_logInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_c_emlrt_marshallIn(SFc9_VCU_CS75_12_27_test_logInstanceStruct *
  chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint8_T c9_d_emlrt_marshallIn(SFc9_VCU_CS75_12_27_test_logInstanceStruct *
  chartInstance, const mxArray *c9_b_is_active_c9_VCU_CS75_12_27_test_log, const
  char_T *c9_identifier);
static uint8_T c9_e_emlrt_marshallIn(SFc9_VCU_CS75_12_27_test_logInstanceStruct *
  chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void init_dsm_address_info(SFc9_VCU_CS75_12_27_test_logInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c9_VCU_CS75_12_27_test_log
  (SFc9_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c9_is_active_c9_VCU_CS75_12_27_test_log = 0U;
}

static void initialize_params_c9_VCU_CS75_12_27_test_log
  (SFc9_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c9_VCU_CS75_12_27_test_log
  (SFc9_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c9_VCU_CS75_12_27_test_log
  (SFc9_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c9_update_debugger_state_c9_VCU_CS75_12_27_test_log
  (SFc9_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c9_VCU_CS75_12_27_test_log
  (SFc9_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  real_T c9_hoistedGlobal;
  real_T c9_u;
  const mxArray *c9_b_y = NULL;
  uint8_T c9_b_hoistedGlobal;
  uint8_T c9_b_u;
  const mxArray *c9_c_y = NULL;
  real_T *c9_RollingCounter;
  c9_RollingCounter = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellmatrix(2, 1), false);
  c9_hoistedGlobal = *c9_RollingCounter;
  c9_u = c9_hoistedGlobal;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_b_hoistedGlobal = chartInstance->c9_is_active_c9_VCU_CS75_12_27_test_log;
  c9_b_u = c9_b_hoistedGlobal;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  sf_mex_assign(&c9_st, c9_y, false);
  return c9_st;
}

static void set_sim_state_c9_VCU_CS75_12_27_test_log
  (SFc9_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c9_st)
{
  const mxArray *c9_u;
  real_T *c9_RollingCounter;
  c9_RollingCounter = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c9_doneDoubleBufferReInit = true;
  c9_u = sf_mex_dup(c9_st);
  *c9_RollingCounter = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 0)), "RollingCounter");
  chartInstance->c9_is_active_c9_VCU_CS75_12_27_test_log = c9_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 1)),
     "is_active_c9_VCU_CS75_12_27_test_log");
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_VCU_CS75_12_27_test_log(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_VCU_CS75_12_27_test_log
  (SFc9_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c9_VCU_CS75_12_27_test_log
  (SFc9_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  real_T c9_hoistedGlobal;
  real_T c9_b_hoistedGlobal;
  real_T c9_Ready;
  real_T c9_LastCounter;
  uint32_T c9_debug_family_var_map[6];
  real_T c9_RealCounter;
  real_T c9_nargin = 2.0;
  real_T c9_nargout = 1.0;
  real_T c9_RollingCounter;
  real_T *c9_b_Ready;
  real_T *c9_b_RollingCounter;
  real_T *c9_b_LastCounter;
  c9_b_LastCounter = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c9_b_RollingCounter = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_b_Ready = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c9_b_Ready, 0U);
  chartInstance->c9_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
  c9_hoistedGlobal = *c9_b_Ready;
  c9_b_hoistedGlobal = *c9_b_LastCounter;
  c9_Ready = c9_hoistedGlobal;
  c9_LastCounter = c9_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c9_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_RealCounter, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 2U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_Ready, 3U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_LastCounter, 4U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_RollingCounter, 5U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 2);
  if (CV_EML_IF(0, 1, 0, c9_LastCounter == 15.0)) {
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 3);
    c9_RealCounter = 0.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 5);
    c9_RealCounter = c9_LastCounter;
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 8);
  if (CV_EML_IF(0, 1, 1, c9_Ready == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 9);
    c9_RollingCounter = c9_RealCounter + 1.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 11);
    c9_RollingCounter = c9_RealCounter;
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  *c9_b_RollingCounter = c9_RollingCounter;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_VCU_CS75_12_27_test_logMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c9_b_RollingCounter, 1U);
  _SFD_DATA_RANGE_CHECK(*c9_b_LastCounter, 2U);
}

static void initSimStructsc9_VCU_CS75_12_27_test_log
  (SFc9_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber)
{
  (void)c9_machineNumber;
  (void)c9_chartNumber;
  (void)c9_instanceNumber;
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
  chartInstance = (SFc9_VCU_CS75_12_27_test_logInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static real_T c9_emlrt_marshallIn(SFc9_VCU_CS75_12_27_test_logInstanceStruct
  *chartInstance, const mxArray *c9_RollingCounter, const char_T *c9_identifier)
{
  real_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_RollingCounter),
    &c9_thisId);
  sf_mex_destroy(&c9_RollingCounter);
  return c9_y;
}

static real_T c9_b_emlrt_marshallIn(SFc9_VCU_CS75_12_27_test_logInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d0, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_RollingCounter;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
  chartInstance = (SFc9_VCU_CS75_12_27_test_logInstanceStruct *)
    chartInstanceVoid;
  c9_RollingCounter = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_RollingCounter),
    &c9_thisId);
  sf_mex_destroy(&c9_RollingCounter);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

const mxArray *sf_c9_VCU_CS75_12_27_test_log_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  sf_mex_assign(&c9_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c9_nameCaptureInfo;
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
  chartInstance = (SFc9_VCU_CS75_12_27_test_logInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static int32_T c9_c_emlrt_marshallIn(SFc9_VCU_CS75_12_27_test_logInstanceStruct *
  chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i0, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
  chartInstance = (SFc9_VCU_CS75_12_27_test_logInstanceStruct *)
    chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint8_T c9_d_emlrt_marshallIn(SFc9_VCU_CS75_12_27_test_logInstanceStruct *
  chartInstance, const mxArray *c9_b_is_active_c9_VCU_CS75_12_27_test_log, const
  char_T *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_is_active_c9_VCU_CS75_12_27_test_log), &c9_thisId);
  sf_mex_destroy(&c9_b_is_active_c9_VCU_CS75_12_27_test_log);
  return c9_y;
}

static uint8_T c9_e_emlrt_marshallIn(SFc9_VCU_CS75_12_27_test_logInstanceStruct *
  chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void init_dsm_address_info(SFc9_VCU_CS75_12_27_test_logInstanceStruct
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

void sf_c9_VCU_CS75_12_27_test_log_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1010995897U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3345237801U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3692530906U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3303941067U);
}

mxArray *sf_c9_VCU_CS75_12_27_test_log_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("vt47hj4ZFxWD8c6pmwYLNG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c9_VCU_CS75_12_27_test_log_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c9_VCU_CS75_12_27_test_log_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c9_VCU_CS75_12_27_test_log(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[6],T\"RollingCounter\",},{M[8],M[0],T\"is_active_c9_VCU_CS75_12_27_test_log\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_VCU_CS75_12_27_test_log_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc9_VCU_CS75_12_27_test_logInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _VCU_CS75_12_27_test_logMachineNumber_,
           9,
           1,
           1,
           0,
           3,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_VCU_CS75_12_27_test_logMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_VCU_CS75_12_27_test_logMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _VCU_CS75_12_27_test_logMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Ready");
          _SFD_SET_DATA_PROPS(1,2,0,1,"RollingCounter");
          _SFD_SET_DATA_PROPS(2,1,1,0,"LastCounter");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,230);
        _SFD_CV_INIT_EML_IF(0,1,0,51,71,92,131);
        _SFD_CV_INIT_EML_IF(0,1,1,133,146,185,226);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c9_Ready;
          real_T *c9_RollingCounter;
          real_T *c9_LastCounter;
          c9_LastCounter = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c9_RollingCounter = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            1);
          c9_Ready = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c9_Ready);
          _SFD_SET_DATA_VALUE_PTR(1U, c9_RollingCounter);
          _SFD_SET_DATA_VALUE_PTR(2U, c9_LastCounter);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _VCU_CS75_12_27_test_logMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "mrLKnHPx6vCjrMJEUHqyTF";
}

static void sf_opaque_initialize_c9_VCU_CS75_12_27_test_log(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_VCU_CS75_12_27_test_logInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c9_VCU_CS75_12_27_test_log
    ((SFc9_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
  initialize_c9_VCU_CS75_12_27_test_log
    ((SFc9_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c9_VCU_CS75_12_27_test_log(void *chartInstanceVar)
{
  enable_c9_VCU_CS75_12_27_test_log((SFc9_VCU_CS75_12_27_test_logInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c9_VCU_CS75_12_27_test_log(void *chartInstanceVar)
{
  disable_c9_VCU_CS75_12_27_test_log((SFc9_VCU_CS75_12_27_test_logInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c9_VCU_CS75_12_27_test_log(void *chartInstanceVar)
{
  sf_gateway_c9_VCU_CS75_12_27_test_log
    ((SFc9_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c9_VCU_CS75_12_27_test_log
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c9_VCU_CS75_12_27_test_log
    ((SFc9_VCU_CS75_12_27_test_logInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_VCU_CS75_12_27_test_log();/* state var info */
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

extern void sf_internal_set_sim_state_c9_VCU_CS75_12_27_test_log(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c9_VCU_CS75_12_27_test_log();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_VCU_CS75_12_27_test_log
    ((SFc9_VCU_CS75_12_27_test_logInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c9_VCU_CS75_12_27_test_log
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c9_VCU_CS75_12_27_test_log(S);
}

static void sf_opaque_set_sim_state_c9_VCU_CS75_12_27_test_log(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c9_VCU_CS75_12_27_test_log(S, st);
}

static void sf_opaque_terminate_c9_VCU_CS75_12_27_test_log(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_VCU_CS75_12_27_test_logInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_VCU_CS75_12_27_test_log_optimization_info();
    }

    finalize_c9_VCU_CS75_12_27_test_log
      ((SFc9_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_VCU_CS75_12_27_test_log
    ((SFc9_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_VCU_CS75_12_27_test_log(SimStruct *S)
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
    initialize_params_c9_VCU_CS75_12_27_test_log
      ((SFc9_VCU_CS75_12_27_test_logInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_VCU_CS75_12_27_test_log(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_VCU_CS75_12_27_test_log_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,9,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,9);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,9,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(611676636U));
  ssSetChecksum1(S,(378079220U));
  ssSetChecksum2(S,(926557446U));
  ssSetChecksum3(S,(3861624963U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c9_VCU_CS75_12_27_test_log(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_VCU_CS75_12_27_test_log(SimStruct *S)
{
  SFc9_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc9_VCU_CS75_12_27_test_logInstanceStruct *)utMalloc(sizeof
    (SFc9_VCU_CS75_12_27_test_logInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_VCU_CS75_12_27_test_logInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c9_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c9_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_VCU_CS75_12_27_test_log;
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

void c9_VCU_CS75_12_27_test_log_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_VCU_CS75_12_27_test_log(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_VCU_CS75_12_27_test_log(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_VCU_CS75_12_27_test_log(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_VCU_CS75_12_27_test_log_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
