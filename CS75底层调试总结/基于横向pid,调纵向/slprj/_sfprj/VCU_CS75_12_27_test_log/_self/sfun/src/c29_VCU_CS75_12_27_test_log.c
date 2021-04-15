/* Include files */

#include <stddef.h>
#include "blas.h"
#include "VCU_CS75_12_27_test_log_sfun.h"
#include "c29_VCU_CS75_12_27_test_log.h"
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
static const char * c29_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

/* Function Declarations */
static void initialize_c29_VCU_CS75_12_27_test_log
  (SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void initialize_params_c29_VCU_CS75_12_27_test_log
  (SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void enable_c29_VCU_CS75_12_27_test_log
  (SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void disable_c29_VCU_CS75_12_27_test_log
  (SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void c29_update_debugger_state_c29_VCU_CS75_12_27_test_log
  (SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c29_VCU_CS75_12_27_test_log
  (SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void set_sim_state_c29_VCU_CS75_12_27_test_log
  (SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c29_st);
static void finalize_c29_VCU_CS75_12_27_test_log
  (SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void sf_gateway_c29_VCU_CS75_12_27_test_log
  (SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void initSimStructsc29_VCU_CS75_12_27_test_log
  (SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c29_machineNumber, uint32_T
  c29_chartNumber, uint32_T c29_instanceNumber);
static const mxArray *c29_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData);
static real_T c29_emlrt_marshallIn(SFc29_VCU_CS75_12_27_test_logInstanceStruct
  *chartInstance, const mxArray *c29_y, const char_T *c29_identifier);
static real_T c29_b_emlrt_marshallIn(SFc29_VCU_CS75_12_27_test_logInstanceStruct
  *chartInstance, const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId);
static void c29_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData);
static const mxArray *c29_b_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData);
static int32_T c29_c_emlrt_marshallIn
  (SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c29_u, const emlrtMsgIdentifier *c29_parentId);
static void c29_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData);
static uint8_T c29_d_emlrt_marshallIn
  (SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c29_b_is_active_c29_VCU_CS75_12_27_test_log, const char_T *c29_identifier);
static uint8_T c29_e_emlrt_marshallIn
  (SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c29_u, const emlrtMsgIdentifier *c29_parentId);
static void init_dsm_address_info(SFc29_VCU_CS75_12_27_test_logInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c29_VCU_CS75_12_27_test_log
  (SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  chartInstance->c29_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c29_is_active_c29_VCU_CS75_12_27_test_log = 0U;
}

static void initialize_params_c29_VCU_CS75_12_27_test_log
  (SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c29_VCU_CS75_12_27_test_log
  (SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c29_VCU_CS75_12_27_test_log
  (SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c29_update_debugger_state_c29_VCU_CS75_12_27_test_log
  (SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c29_VCU_CS75_12_27_test_log
  (SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  const mxArray *c29_st;
  const mxArray *c29_y = NULL;
  real_T c29_hoistedGlobal;
  real_T c29_u;
  const mxArray *c29_b_y = NULL;
  uint8_T c29_b_hoistedGlobal;
  uint8_T c29_b_u;
  const mxArray *c29_c_y = NULL;
  real_T *c29_d_y;
  c29_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c29_st = NULL;
  c29_st = NULL;
  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_createcellmatrix(2, 1), false);
  c29_hoistedGlobal = *c29_d_y;
  c29_u = c29_hoistedGlobal;
  c29_b_y = NULL;
  sf_mex_assign(&c29_b_y, sf_mex_create("y", &c29_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c29_y, 0, c29_b_y);
  c29_b_hoistedGlobal = chartInstance->c29_is_active_c29_VCU_CS75_12_27_test_log;
  c29_b_u = c29_b_hoistedGlobal;
  c29_c_y = NULL;
  sf_mex_assign(&c29_c_y, sf_mex_create("y", &c29_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c29_y, 1, c29_c_y);
  sf_mex_assign(&c29_st, c29_y, false);
  return c29_st;
}

static void set_sim_state_c29_VCU_CS75_12_27_test_log
  (SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c29_st)
{
  const mxArray *c29_u;
  real_T *c29_y;
  c29_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c29_doneDoubleBufferReInit = true;
  c29_u = sf_mex_dup(c29_st);
  *c29_y = c29_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c29_u,
    0)), "y");
  chartInstance->c29_is_active_c29_VCU_CS75_12_27_test_log =
    c29_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c29_u, 1)),
    "is_active_c29_VCU_CS75_12_27_test_log");
  sf_mex_destroy(&c29_u);
  c29_update_debugger_state_c29_VCU_CS75_12_27_test_log(chartInstance);
  sf_mex_destroy(&c29_st);
}

static void finalize_c29_VCU_CS75_12_27_test_log
  (SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c29_VCU_CS75_12_27_test_log
  (SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  real_T c29_hoistedGlobal;
  real_T c29_u;
  uint32_T c29_debug_family_var_map[4];
  real_T c29_nargin = 1.0;
  real_T c29_nargout = 1.0;
  real_T c29_y;
  real_T *c29_b_u;
  real_T *c29_b_y;
  c29_b_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c29_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 21U, chartInstance->c29_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c29_b_u, 0U);
  chartInstance->c29_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 21U, chartInstance->c29_sfEvent);
  c29_hoistedGlobal = *c29_b_u;
  c29_u = c29_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c29_debug_family_names,
    c29_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c29_nargin, 0U, c29_sf_marshallOut,
    c29_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c29_nargout, 1U, c29_sf_marshallOut,
    c29_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c29_u, 2U, c29_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c29_y, 3U, c29_sf_marshallOut,
    c29_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c29_sfEvent, 2);
  if (CV_EML_IF(0, 1, 0, c29_u == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c29_sfEvent, 3);
    c29_y = 0.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c29_sfEvent, 5);
    c29_y = 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c29_sfEvent, -5);
  _SFD_SYMBOL_SCOPE_POP();
  *c29_b_y = c29_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, chartInstance->c29_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_VCU_CS75_12_27_test_logMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c29_b_y, 1U);
}

static void initSimStructsc29_VCU_CS75_12_27_test_log
  (SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c29_machineNumber, uint32_T
  c29_chartNumber, uint32_T c29_instanceNumber)
{
  (void)c29_machineNumber;
  (void)c29_chartNumber;
  (void)c29_instanceNumber;
}

static const mxArray *c29_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData)
{
  const mxArray *c29_mxArrayOutData = NULL;
  real_T c29_u;
  const mxArray *c29_y = NULL;
  SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
  chartInstance = (SFc29_VCU_CS75_12_27_test_logInstanceStruct *)
    chartInstanceVoid;
  c29_mxArrayOutData = NULL;
  c29_u = *(real_T *)c29_inData;
  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", &c29_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c29_mxArrayOutData, c29_y, false);
  return c29_mxArrayOutData;
}

static real_T c29_emlrt_marshallIn(SFc29_VCU_CS75_12_27_test_logInstanceStruct
  *chartInstance, const mxArray *c29_y, const char_T *c29_identifier)
{
  real_T c29_b_y;
  emlrtMsgIdentifier c29_thisId;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_b_y = c29_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_y), &c29_thisId);
  sf_mex_destroy(&c29_y);
  return c29_b_y;
}

static real_T c29_b_emlrt_marshallIn(SFc29_VCU_CS75_12_27_test_logInstanceStruct
  *chartInstance, const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId)
{
  real_T c29_y;
  real_T c29_d0;
  (void)chartInstance;
  sf_mex_import(c29_parentId, sf_mex_dup(c29_u), &c29_d0, 1, 0, 0U, 0, 0U, 0);
  c29_y = c29_d0;
  sf_mex_destroy(&c29_u);
  return c29_y;
}

static void c29_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData)
{
  const mxArray *c29_y;
  const char_T *c29_identifier;
  emlrtMsgIdentifier c29_thisId;
  real_T c29_b_y;
  SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
  chartInstance = (SFc29_VCU_CS75_12_27_test_logInstanceStruct *)
    chartInstanceVoid;
  c29_y = sf_mex_dup(c29_mxArrayInData);
  c29_identifier = c29_varName;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_b_y = c29_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_y), &c29_thisId);
  sf_mex_destroy(&c29_y);
  *(real_T *)c29_outData = c29_b_y;
  sf_mex_destroy(&c29_mxArrayInData);
}

const mxArray *sf_c29_VCU_CS75_12_27_test_log_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c29_nameCaptureInfo = NULL;
  c29_nameCaptureInfo = NULL;
  sf_mex_assign(&c29_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c29_nameCaptureInfo;
}

static const mxArray *c29_b_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData)
{
  const mxArray *c29_mxArrayOutData = NULL;
  int32_T c29_u;
  const mxArray *c29_y = NULL;
  SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
  chartInstance = (SFc29_VCU_CS75_12_27_test_logInstanceStruct *)
    chartInstanceVoid;
  c29_mxArrayOutData = NULL;
  c29_u = *(int32_T *)c29_inData;
  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", &c29_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c29_mxArrayOutData, c29_y, false);
  return c29_mxArrayOutData;
}

static int32_T c29_c_emlrt_marshallIn
  (SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c29_u, const emlrtMsgIdentifier *c29_parentId)
{
  int32_T c29_y;
  int32_T c29_i0;
  (void)chartInstance;
  sf_mex_import(c29_parentId, sf_mex_dup(c29_u), &c29_i0, 1, 6, 0U, 0, 0U, 0);
  c29_y = c29_i0;
  sf_mex_destroy(&c29_u);
  return c29_y;
}

static void c29_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData)
{
  const mxArray *c29_b_sfEvent;
  const char_T *c29_identifier;
  emlrtMsgIdentifier c29_thisId;
  int32_T c29_y;
  SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
  chartInstance = (SFc29_VCU_CS75_12_27_test_logInstanceStruct *)
    chartInstanceVoid;
  c29_b_sfEvent = sf_mex_dup(c29_mxArrayInData);
  c29_identifier = c29_varName;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_y = c29_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_b_sfEvent),
    &c29_thisId);
  sf_mex_destroy(&c29_b_sfEvent);
  *(int32_T *)c29_outData = c29_y;
  sf_mex_destroy(&c29_mxArrayInData);
}

static uint8_T c29_d_emlrt_marshallIn
  (SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c29_b_is_active_c29_VCU_CS75_12_27_test_log, const char_T *c29_identifier)
{
  uint8_T c29_y;
  emlrtMsgIdentifier c29_thisId;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_y = c29_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c29_b_is_active_c29_VCU_CS75_12_27_test_log), &c29_thisId);
  sf_mex_destroy(&c29_b_is_active_c29_VCU_CS75_12_27_test_log);
  return c29_y;
}

static uint8_T c29_e_emlrt_marshallIn
  (SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c29_u, const emlrtMsgIdentifier *c29_parentId)
{
  uint8_T c29_y;
  uint8_T c29_u0;
  (void)chartInstance;
  sf_mex_import(c29_parentId, sf_mex_dup(c29_u), &c29_u0, 1, 3, 0U, 0, 0U, 0);
  c29_y = c29_u0;
  sf_mex_destroy(&c29_u);
  return c29_y;
}

static void init_dsm_address_info(SFc29_VCU_CS75_12_27_test_logInstanceStruct
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

void sf_c29_VCU_CS75_12_27_test_log_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2902362256U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2291987780U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2947378102U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3537051661U);
}

mxArray *sf_c29_VCU_CS75_12_27_test_log_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("WZPS98KmE6e2QatP0FqeeC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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

mxArray *sf_c29_VCU_CS75_12_27_test_log_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c29_VCU_CS75_12_27_test_log_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c29_VCU_CS75_12_27_test_log(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c29_VCU_CS75_12_27_test_log\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c29_VCU_CS75_12_27_test_log_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc29_VCU_CS75_12_27_test_logInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _VCU_CS75_12_27_test_logMachineNumber_,
           29,
           1,
           1,
           0,
           2,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,64);
        _SFD_CV_INIT_EML_IF(0,1,0,20,29,41,60);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c29_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c29_sf_marshallOut,(MexInFcnForType)c29_sf_marshallIn);

        {
          real_T *c29_u;
          real_T *c29_y;
          c29_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c29_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c29_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c29_y);
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
  return "mOkD9o5ArYnsJU3k17caTG";
}

static void sf_opaque_initialize_c29_VCU_CS75_12_27_test_log(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc29_VCU_CS75_12_27_test_logInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c29_VCU_CS75_12_27_test_log
    ((SFc29_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
  initialize_c29_VCU_CS75_12_27_test_log
    ((SFc29_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c29_VCU_CS75_12_27_test_log(void *chartInstanceVar)
{
  enable_c29_VCU_CS75_12_27_test_log
    ((SFc29_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c29_VCU_CS75_12_27_test_log(void *chartInstanceVar)
{
  disable_c29_VCU_CS75_12_27_test_log
    ((SFc29_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c29_VCU_CS75_12_27_test_log(void *chartInstanceVar)
{
  sf_gateway_c29_VCU_CS75_12_27_test_log
    ((SFc29_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c29_VCU_CS75_12_27_test_log
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c29_VCU_CS75_12_27_test_log
    ((SFc29_VCU_CS75_12_27_test_logInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c29_VCU_CS75_12_27_test_log();/* state var info */
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

extern void sf_internal_set_sim_state_c29_VCU_CS75_12_27_test_log(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c29_VCU_CS75_12_27_test_log();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c29_VCU_CS75_12_27_test_log
    ((SFc29_VCU_CS75_12_27_test_logInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c29_VCU_CS75_12_27_test_log
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c29_VCU_CS75_12_27_test_log(S);
}

static void sf_opaque_set_sim_state_c29_VCU_CS75_12_27_test_log(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c29_VCU_CS75_12_27_test_log(S, st);
}

static void sf_opaque_terminate_c29_VCU_CS75_12_27_test_log(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc29_VCU_CS75_12_27_test_logInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_VCU_CS75_12_27_test_log_optimization_info();
    }

    finalize_c29_VCU_CS75_12_27_test_log
      ((SFc29_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc29_VCU_CS75_12_27_test_log
    ((SFc29_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c29_VCU_CS75_12_27_test_log(SimStruct *S)
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
    initialize_params_c29_VCU_CS75_12_27_test_log
      ((SFc29_VCU_CS75_12_27_test_logInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c29_VCU_CS75_12_27_test_log(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_VCU_CS75_12_27_test_log_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      29);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,29,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,29,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,29);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,29,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,29,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,29);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1196403577U));
  ssSetChecksum1(S,(3426480511U));
  ssSetChecksum2(S,(21634404U));
  ssSetChecksum3(S,(4269796212U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c29_VCU_CS75_12_27_test_log(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c29_VCU_CS75_12_27_test_log(SimStruct *S)
{
  SFc29_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc29_VCU_CS75_12_27_test_logInstanceStruct *)utMalloc(sizeof
    (SFc29_VCU_CS75_12_27_test_logInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc29_VCU_CS75_12_27_test_logInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c29_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c29_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c29_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c29_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c29_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c29_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c29_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c29_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c29_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.mdlStart = mdlStart_c29_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c29_VCU_CS75_12_27_test_log;
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

void c29_VCU_CS75_12_27_test_log_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c29_VCU_CS75_12_27_test_log(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c29_VCU_CS75_12_27_test_log(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c29_VCU_CS75_12_27_test_log(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c29_VCU_CS75_12_27_test_log_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
