/* Include files */

#include <stddef.h>
#include "blas.h"
#include "VCU_CS75_12_27_test_sfun.h"
#include "c30_VCU_CS75_12_27_test.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "VCU_CS75_12_27_test_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c30_debug_family_names[5] = { "nargin", "nargout", "T",
  "Tmax", "y" };

/* Function Declarations */
static void initialize_c30_VCU_CS75_12_27_test
  (SFc30_VCU_CS75_12_27_testInstanceStruct *chartInstance);
static void initialize_params_c30_VCU_CS75_12_27_test
  (SFc30_VCU_CS75_12_27_testInstanceStruct *chartInstance);
static void enable_c30_VCU_CS75_12_27_test
  (SFc30_VCU_CS75_12_27_testInstanceStruct *chartInstance);
static void disable_c30_VCU_CS75_12_27_test
  (SFc30_VCU_CS75_12_27_testInstanceStruct *chartInstance);
static void c30_update_debugger_state_c30_VCU_CS75_12_27_test
  (SFc30_VCU_CS75_12_27_testInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c30_VCU_CS75_12_27_test
  (SFc30_VCU_CS75_12_27_testInstanceStruct *chartInstance);
static void set_sim_state_c30_VCU_CS75_12_27_test
  (SFc30_VCU_CS75_12_27_testInstanceStruct *chartInstance, const mxArray *c30_st);
static void finalize_c30_VCU_CS75_12_27_test
  (SFc30_VCU_CS75_12_27_testInstanceStruct *chartInstance);
static void sf_gateway_c30_VCU_CS75_12_27_test
  (SFc30_VCU_CS75_12_27_testInstanceStruct *chartInstance);
static void initSimStructsc30_VCU_CS75_12_27_test
  (SFc30_VCU_CS75_12_27_testInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c30_machineNumber, uint32_T
  c30_chartNumber, uint32_T c30_instanceNumber);
static const mxArray *c30_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData);
static real_T c30_emlrt_marshallIn(SFc30_VCU_CS75_12_27_testInstanceStruct
  *chartInstance, const mxArray *c30_y, const char_T *c30_identifier);
static real_T c30_b_emlrt_marshallIn(SFc30_VCU_CS75_12_27_testInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId);
static void c30_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData);
static const mxArray *c30_b_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData);
static int32_T c30_c_emlrt_marshallIn(SFc30_VCU_CS75_12_27_testInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId);
static void c30_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData);
static uint8_T c30_d_emlrt_marshallIn(SFc30_VCU_CS75_12_27_testInstanceStruct
  *chartInstance, const mxArray *c30_b_is_active_c30_VCU_CS75_12_27_test, const
  char_T *c30_identifier);
static uint8_T c30_e_emlrt_marshallIn(SFc30_VCU_CS75_12_27_testInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId);
static void init_dsm_address_info(SFc30_VCU_CS75_12_27_testInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c30_VCU_CS75_12_27_test
  (SFc30_VCU_CS75_12_27_testInstanceStruct *chartInstance)
{
  chartInstance->c30_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c30_is_active_c30_VCU_CS75_12_27_test = 0U;
}

static void initialize_params_c30_VCU_CS75_12_27_test
  (SFc30_VCU_CS75_12_27_testInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c30_VCU_CS75_12_27_test
  (SFc30_VCU_CS75_12_27_testInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c30_VCU_CS75_12_27_test
  (SFc30_VCU_CS75_12_27_testInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c30_update_debugger_state_c30_VCU_CS75_12_27_test
  (SFc30_VCU_CS75_12_27_testInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c30_VCU_CS75_12_27_test
  (SFc30_VCU_CS75_12_27_testInstanceStruct *chartInstance)
{
  const mxArray *c30_st;
  const mxArray *c30_y = NULL;
  real_T c30_hoistedGlobal;
  real_T c30_u;
  const mxArray *c30_b_y = NULL;
  uint8_T c30_b_hoistedGlobal;
  uint8_T c30_b_u;
  const mxArray *c30_c_y = NULL;
  real_T *c30_d_y;
  c30_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c30_st = NULL;
  c30_st = NULL;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_createcellmatrix(2, 1), false);
  c30_hoistedGlobal = *c30_d_y;
  c30_u = c30_hoistedGlobal;
  c30_b_y = NULL;
  sf_mex_assign(&c30_b_y, sf_mex_create("y", &c30_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c30_y, 0, c30_b_y);
  c30_b_hoistedGlobal = chartInstance->c30_is_active_c30_VCU_CS75_12_27_test;
  c30_b_u = c30_b_hoistedGlobal;
  c30_c_y = NULL;
  sf_mex_assign(&c30_c_y, sf_mex_create("y", &c30_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c30_y, 1, c30_c_y);
  sf_mex_assign(&c30_st, c30_y, false);
  return c30_st;
}

static void set_sim_state_c30_VCU_CS75_12_27_test
  (SFc30_VCU_CS75_12_27_testInstanceStruct *chartInstance, const mxArray *c30_st)
{
  const mxArray *c30_u;
  real_T *c30_y;
  c30_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c30_doneDoubleBufferReInit = true;
  c30_u = sf_mex_dup(c30_st);
  *c30_y = c30_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c30_u,
    0)), "y");
  chartInstance->c30_is_active_c30_VCU_CS75_12_27_test = c30_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c30_u, 1)),
     "is_active_c30_VCU_CS75_12_27_test");
  sf_mex_destroy(&c30_u);
  c30_update_debugger_state_c30_VCU_CS75_12_27_test(chartInstance);
  sf_mex_destroy(&c30_st);
}

static void finalize_c30_VCU_CS75_12_27_test
  (SFc30_VCU_CS75_12_27_testInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c30_VCU_CS75_12_27_test
  (SFc30_VCU_CS75_12_27_testInstanceStruct *chartInstance)
{
  real_T c30_hoistedGlobal;
  real_T c30_b_hoistedGlobal;
  real_T c30_T;
  real_T c30_Tmax;
  uint32_T c30_debug_family_var_map[5];
  real_T c30_nargin = 2.0;
  real_T c30_nargout = 1.0;
  real_T c30_y;
  real_T *c30_b_T;
  real_T *c30_b_Tmax;
  real_T *c30_b_y;
  c30_b_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c30_b_Tmax = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c30_b_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 22U, chartInstance->c30_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c30_b_T, 0U);
  _SFD_DATA_RANGE_CHECK(*c30_b_Tmax, 1U);
  chartInstance->c30_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 22U, chartInstance->c30_sfEvent);
  c30_hoistedGlobal = *c30_b_T;
  c30_b_hoistedGlobal = *c30_b_Tmax;
  c30_T = c30_hoistedGlobal;
  c30_Tmax = c30_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c30_debug_family_names,
    c30_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_nargin, 0U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_nargout, 1U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c30_T, 2U, c30_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c30_Tmax, 3U, c30_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_y, 4U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 2);
  if (CV_EML_IF(0, 1, 0, c30_T > c30_Tmax)) {
    _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 3);
    c30_y = c30_Tmax;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 4);
    if (CV_EML_IF(0, 1, 1, c30_T < -c30_Tmax)) {
      _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 5);
      c30_y = -c30_Tmax;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 7);
      c30_y = c30_T;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, -7);
  _SFD_SYMBOL_SCOPE_POP();
  *c30_b_y = c30_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c30_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_VCU_CS75_12_27_testMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c30_b_y, 2U);
}

static void initSimStructsc30_VCU_CS75_12_27_test
  (SFc30_VCU_CS75_12_27_testInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c30_machineNumber, uint32_T
  c30_chartNumber, uint32_T c30_instanceNumber)
{
  (void)c30_machineNumber;
  (void)c30_chartNumber;
  (void)c30_instanceNumber;
}

static const mxArray *c30_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData)
{
  const mxArray *c30_mxArrayOutData = NULL;
  real_T c30_u;
  const mxArray *c30_y = NULL;
  SFc30_VCU_CS75_12_27_testInstanceStruct *chartInstance;
  chartInstance = (SFc30_VCU_CS75_12_27_testInstanceStruct *)chartInstanceVoid;
  c30_mxArrayOutData = NULL;
  c30_u = *(real_T *)c30_inData;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", &c30_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c30_mxArrayOutData, c30_y, false);
  return c30_mxArrayOutData;
}

static real_T c30_emlrt_marshallIn(SFc30_VCU_CS75_12_27_testInstanceStruct
  *chartInstance, const mxArray *c30_y, const char_T *c30_identifier)
{
  real_T c30_b_y;
  emlrtMsgIdentifier c30_thisId;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_b_y = c30_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_y), &c30_thisId);
  sf_mex_destroy(&c30_y);
  return c30_b_y;
}

static real_T c30_b_emlrt_marshallIn(SFc30_VCU_CS75_12_27_testInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId)
{
  real_T c30_y;
  real_T c30_d0;
  (void)chartInstance;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), &c30_d0, 1, 0, 0U, 0, 0U, 0);
  c30_y = c30_d0;
  sf_mex_destroy(&c30_u);
  return c30_y;
}

static void c30_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData)
{
  const mxArray *c30_y;
  const char_T *c30_identifier;
  emlrtMsgIdentifier c30_thisId;
  real_T c30_b_y;
  SFc30_VCU_CS75_12_27_testInstanceStruct *chartInstance;
  chartInstance = (SFc30_VCU_CS75_12_27_testInstanceStruct *)chartInstanceVoid;
  c30_y = sf_mex_dup(c30_mxArrayInData);
  c30_identifier = c30_varName;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_b_y = c30_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_y), &c30_thisId);
  sf_mex_destroy(&c30_y);
  *(real_T *)c30_outData = c30_b_y;
  sf_mex_destroy(&c30_mxArrayInData);
}

const mxArray *sf_c30_VCU_CS75_12_27_test_get_eml_resolved_functions_info(void)
{
  const mxArray *c30_nameCaptureInfo = NULL;
  c30_nameCaptureInfo = NULL;
  sf_mex_assign(&c30_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c30_nameCaptureInfo;
}

static const mxArray *c30_b_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData)
{
  const mxArray *c30_mxArrayOutData = NULL;
  int32_T c30_u;
  const mxArray *c30_y = NULL;
  SFc30_VCU_CS75_12_27_testInstanceStruct *chartInstance;
  chartInstance = (SFc30_VCU_CS75_12_27_testInstanceStruct *)chartInstanceVoid;
  c30_mxArrayOutData = NULL;
  c30_u = *(int32_T *)c30_inData;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", &c30_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c30_mxArrayOutData, c30_y, false);
  return c30_mxArrayOutData;
}

static int32_T c30_c_emlrt_marshallIn(SFc30_VCU_CS75_12_27_testInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId)
{
  int32_T c30_y;
  int32_T c30_i0;
  (void)chartInstance;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), &c30_i0, 1, 6, 0U, 0, 0U, 0);
  c30_y = c30_i0;
  sf_mex_destroy(&c30_u);
  return c30_y;
}

static void c30_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData)
{
  const mxArray *c30_b_sfEvent;
  const char_T *c30_identifier;
  emlrtMsgIdentifier c30_thisId;
  int32_T c30_y;
  SFc30_VCU_CS75_12_27_testInstanceStruct *chartInstance;
  chartInstance = (SFc30_VCU_CS75_12_27_testInstanceStruct *)chartInstanceVoid;
  c30_b_sfEvent = sf_mex_dup(c30_mxArrayInData);
  c30_identifier = c30_varName;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_y = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_b_sfEvent),
    &c30_thisId);
  sf_mex_destroy(&c30_b_sfEvent);
  *(int32_T *)c30_outData = c30_y;
  sf_mex_destroy(&c30_mxArrayInData);
}

static uint8_T c30_d_emlrt_marshallIn(SFc30_VCU_CS75_12_27_testInstanceStruct
  *chartInstance, const mxArray *c30_b_is_active_c30_VCU_CS75_12_27_test, const
  char_T *c30_identifier)
{
  uint8_T c30_y;
  emlrtMsgIdentifier c30_thisId;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_y = c30_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c30_b_is_active_c30_VCU_CS75_12_27_test), &c30_thisId);
  sf_mex_destroy(&c30_b_is_active_c30_VCU_CS75_12_27_test);
  return c30_y;
}

static uint8_T c30_e_emlrt_marshallIn(SFc30_VCU_CS75_12_27_testInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId)
{
  uint8_T c30_y;
  uint8_T c30_u0;
  (void)chartInstance;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), &c30_u0, 1, 3, 0U, 0, 0U, 0);
  c30_y = c30_u0;
  sf_mex_destroy(&c30_u);
  return c30_y;
}

static void init_dsm_address_info(SFc30_VCU_CS75_12_27_testInstanceStruct
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

void sf_c30_VCU_CS75_12_27_test_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1357596349U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1058786217U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4004389009U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(203226634U);
}

mxArray *sf_c30_VCU_CS75_12_27_test_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("RhTitUELKXbsEqHGk3CGqE");
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

mxArray *sf_c30_VCU_CS75_12_27_test_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c30_VCU_CS75_12_27_test_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c30_VCU_CS75_12_27_test(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c30_VCU_CS75_12_27_test\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c30_VCU_CS75_12_27_test_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc30_VCU_CS75_12_27_testInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc30_VCU_CS75_12_27_testInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _VCU_CS75_12_27_testMachineNumber_,
           30,
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
        init_script_number_translation(_VCU_CS75_12_27_testMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_VCU_CS75_12_27_testMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _VCU_CS75_12_27_testMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"T");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Tmax");
          _SFD_SET_DATA_PROPS(2,2,0,1,"y");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,106);
        _SFD_CV_INIT_EML_IF(0,1,0,25,36,51,102);
        _SFD_CV_INIT_EML_IF(0,1,1,51,67,83,102);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)c30_sf_marshallIn);

        {
          real_T *c30_T;
          real_T *c30_Tmax;
          real_T *c30_y;
          c30_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c30_Tmax = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c30_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c30_T);
          _SFD_SET_DATA_VALUE_PTR(1U, c30_Tmax);
          _SFD_SET_DATA_VALUE_PTR(2U, c30_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _VCU_CS75_12_27_testMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "KTukSecwGy2iGiUMHNhyBH";
}

static void sf_opaque_initialize_c30_VCU_CS75_12_27_test(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc30_VCU_CS75_12_27_testInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c30_VCU_CS75_12_27_test
    ((SFc30_VCU_CS75_12_27_testInstanceStruct*) chartInstanceVar);
  initialize_c30_VCU_CS75_12_27_test((SFc30_VCU_CS75_12_27_testInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c30_VCU_CS75_12_27_test(void *chartInstanceVar)
{
  enable_c30_VCU_CS75_12_27_test((SFc30_VCU_CS75_12_27_testInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c30_VCU_CS75_12_27_test(void *chartInstanceVar)
{
  disable_c30_VCU_CS75_12_27_test((SFc30_VCU_CS75_12_27_testInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c30_VCU_CS75_12_27_test(void *chartInstanceVar)
{
  sf_gateway_c30_VCU_CS75_12_27_test((SFc30_VCU_CS75_12_27_testInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c30_VCU_CS75_12_27_test
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c30_VCU_CS75_12_27_test
    ((SFc30_VCU_CS75_12_27_testInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c30_VCU_CS75_12_27_test();/* state var info */
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

extern void sf_internal_set_sim_state_c30_VCU_CS75_12_27_test(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c30_VCU_CS75_12_27_test();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c30_VCU_CS75_12_27_test((SFc30_VCU_CS75_12_27_testInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c30_VCU_CS75_12_27_test(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c30_VCU_CS75_12_27_test(S);
}

static void sf_opaque_set_sim_state_c30_VCU_CS75_12_27_test(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c30_VCU_CS75_12_27_test(S, st);
}

static void sf_opaque_terminate_c30_VCU_CS75_12_27_test(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc30_VCU_CS75_12_27_testInstanceStruct*) chartInstanceVar
      )->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_VCU_CS75_12_27_test_optimization_info();
    }

    finalize_c30_VCU_CS75_12_27_test((SFc30_VCU_CS75_12_27_testInstanceStruct*)
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
  initSimStructsc30_VCU_CS75_12_27_test((SFc30_VCU_CS75_12_27_testInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c30_VCU_CS75_12_27_test(SimStruct *S)
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
    initialize_params_c30_VCU_CS75_12_27_test
      ((SFc30_VCU_CS75_12_27_testInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c30_VCU_CS75_12_27_test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_VCU_CS75_12_27_test_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      30);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,30,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,30,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,30);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,30,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,30,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,30);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2611129730U));
  ssSetChecksum1(S,(2003822314U));
  ssSetChecksum2(S,(109821468U));
  ssSetChecksum3(S,(1218487116U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c30_VCU_CS75_12_27_test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c30_VCU_CS75_12_27_test(SimStruct *S)
{
  SFc30_VCU_CS75_12_27_testInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc30_VCU_CS75_12_27_testInstanceStruct *)utMalloc(sizeof
    (SFc30_VCU_CS75_12_27_testInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc30_VCU_CS75_12_27_testInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c30_VCU_CS75_12_27_test;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c30_VCU_CS75_12_27_test;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c30_VCU_CS75_12_27_test;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c30_VCU_CS75_12_27_test;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c30_VCU_CS75_12_27_test;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c30_VCU_CS75_12_27_test;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c30_VCU_CS75_12_27_test;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c30_VCU_CS75_12_27_test;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c30_VCU_CS75_12_27_test;
  chartInstance->chartInfo.mdlStart = mdlStart_c30_VCU_CS75_12_27_test;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c30_VCU_CS75_12_27_test;
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

void c30_VCU_CS75_12_27_test_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c30_VCU_CS75_12_27_test(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c30_VCU_CS75_12_27_test(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c30_VCU_CS75_12_27_test(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c30_VCU_CS75_12_27_test_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
