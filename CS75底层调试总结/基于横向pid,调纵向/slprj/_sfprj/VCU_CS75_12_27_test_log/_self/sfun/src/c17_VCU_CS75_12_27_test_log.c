/* Include files */

#include <stddef.h>
#include "blas.h"
#include "VCU_CS75_12_27_test_log_sfun.h"
#include "c17_VCU_CS75_12_27_test_log.h"
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
static const char * c17_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

/* Function Declarations */
static void initialize_c17_VCU_CS75_12_27_test_log
  (SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void initialize_params_c17_VCU_CS75_12_27_test_log
  (SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void enable_c17_VCU_CS75_12_27_test_log
  (SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void disable_c17_VCU_CS75_12_27_test_log
  (SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void c17_update_debugger_state_c17_VCU_CS75_12_27_test_log
  (SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c17_VCU_CS75_12_27_test_log
  (SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void set_sim_state_c17_VCU_CS75_12_27_test_log
  (SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c17_st);
static void finalize_c17_VCU_CS75_12_27_test_log
  (SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void sf_gateway_c17_VCU_CS75_12_27_test_log
  (SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void initSimStructsc17_VCU_CS75_12_27_test_log
  (SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c17_machineNumber, uint32_T
  c17_chartNumber, uint32_T c17_instanceNumber);
static const mxArray *c17_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static real_T c17_emlrt_marshallIn(SFc17_VCU_CS75_12_27_test_logInstanceStruct
  *chartInstance, const mxArray *c17_y, const char_T *c17_identifier);
static real_T c17_b_emlrt_marshallIn(SFc17_VCU_CS75_12_27_test_logInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void c17_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static const mxArray *c17_b_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static int32_T c17_c_emlrt_marshallIn
  (SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void c17_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static uint8_T c17_d_emlrt_marshallIn
  (SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c17_b_is_active_c17_VCU_CS75_12_27_test_log, const char_T *c17_identifier);
static uint8_T c17_e_emlrt_marshallIn
  (SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void init_dsm_address_info(SFc17_VCU_CS75_12_27_test_logInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c17_VCU_CS75_12_27_test_log
  (SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  chartInstance->c17_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c17_is_active_c17_VCU_CS75_12_27_test_log = 0U;
}

static void initialize_params_c17_VCU_CS75_12_27_test_log
  (SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c17_VCU_CS75_12_27_test_log
  (SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c17_VCU_CS75_12_27_test_log
  (SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c17_update_debugger_state_c17_VCU_CS75_12_27_test_log
  (SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c17_VCU_CS75_12_27_test_log
  (SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  const mxArray *c17_st;
  const mxArray *c17_y = NULL;
  real_T c17_hoistedGlobal;
  real_T c17_u;
  const mxArray *c17_b_y = NULL;
  uint8_T c17_b_hoistedGlobal;
  uint8_T c17_b_u;
  const mxArray *c17_c_y = NULL;
  real_T *c17_d_y;
  c17_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c17_st = NULL;
  c17_st = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_createcellmatrix(2, 1), false);
  c17_hoistedGlobal = *c17_d_y;
  c17_u = c17_hoistedGlobal;
  c17_b_y = NULL;
  sf_mex_assign(&c17_b_y, sf_mex_create("y", &c17_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c17_y, 0, c17_b_y);
  c17_b_hoistedGlobal = chartInstance->c17_is_active_c17_VCU_CS75_12_27_test_log;
  c17_b_u = c17_b_hoistedGlobal;
  c17_c_y = NULL;
  sf_mex_assign(&c17_c_y, sf_mex_create("y", &c17_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c17_y, 1, c17_c_y);
  sf_mex_assign(&c17_st, c17_y, false);
  return c17_st;
}

static void set_sim_state_c17_VCU_CS75_12_27_test_log
  (SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c17_st)
{
  const mxArray *c17_u;
  real_T *c17_y;
  c17_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c17_doneDoubleBufferReInit = true;
  c17_u = sf_mex_dup(c17_st);
  *c17_y = c17_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c17_u,
    0)), "y");
  chartInstance->c17_is_active_c17_VCU_CS75_12_27_test_log =
    c17_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c17_u, 1)),
    "is_active_c17_VCU_CS75_12_27_test_log");
  sf_mex_destroy(&c17_u);
  c17_update_debugger_state_c17_VCU_CS75_12_27_test_log(chartInstance);
  sf_mex_destroy(&c17_st);
}

static void finalize_c17_VCU_CS75_12_27_test_log
  (SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c17_VCU_CS75_12_27_test_log
  (SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  real_T c17_hoistedGlobal;
  real_T c17_u;
  uint32_T c17_debug_family_var_map[4];
  real_T c17_nargin = 1.0;
  real_T c17_nargout = 1.0;
  real_T c17_y;
  real_T *c17_b_u;
  real_T *c17_b_y;
  c17_b_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c17_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 14U, chartInstance->c17_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c17_b_u, 0U);
  chartInstance->c17_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 14U, chartInstance->c17_sfEvent);
  c17_hoistedGlobal = *c17_b_u;
  c17_u = c17_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c17_debug_family_names,
    c17_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_nargin, 0U, c17_sf_marshallOut,
    c17_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_nargout, 1U, c17_sf_marshallOut,
    c17_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_u, 2U, c17_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_y, 3U, c17_sf_marshallOut,
    c17_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 2);
  if (CV_EML_IF(0, 1, 0, c17_u == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 3);
    c17_y = 1.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 5);
    c17_y = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, -5);
  _SFD_SYMBOL_SCOPE_POP();
  *c17_b_y = c17_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c17_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_VCU_CS75_12_27_test_logMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c17_b_y, 1U);
}

static void initSimStructsc17_VCU_CS75_12_27_test_log
  (SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c17_machineNumber, uint32_T
  c17_chartNumber, uint32_T c17_instanceNumber)
{
  (void)c17_machineNumber;
  (void)c17_chartNumber;
  (void)c17_instanceNumber;
}

static const mxArray *c17_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  real_T c17_u;
  const mxArray *c17_y = NULL;
  SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
  chartInstance = (SFc17_VCU_CS75_12_27_test_logInstanceStruct *)
    chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_u = *(real_T *)c17_inData;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static real_T c17_emlrt_marshallIn(SFc17_VCU_CS75_12_27_test_logInstanceStruct
  *chartInstance, const mxArray *c17_y, const char_T *c17_identifier)
{
  real_T c17_b_y;
  emlrtMsgIdentifier c17_thisId;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_b_y = c17_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_y), &c17_thisId);
  sf_mex_destroy(&c17_y);
  return c17_b_y;
}

static real_T c17_b_emlrt_marshallIn(SFc17_VCU_CS75_12_27_test_logInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  real_T c17_y;
  real_T c17_d0;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_d0, 1, 0, 0U, 0, 0U, 0);
  c17_y = c17_d0;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void c17_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_y;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  real_T c17_b_y;
  SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
  chartInstance = (SFc17_VCU_CS75_12_27_test_logInstanceStruct *)
    chartInstanceVoid;
  c17_y = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_b_y = c17_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_y), &c17_thisId);
  sf_mex_destroy(&c17_y);
  *(real_T *)c17_outData = c17_b_y;
  sf_mex_destroy(&c17_mxArrayInData);
}

const mxArray *sf_c17_VCU_CS75_12_27_test_log_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c17_nameCaptureInfo = NULL;
  c17_nameCaptureInfo = NULL;
  sf_mex_assign(&c17_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c17_nameCaptureInfo;
}

static const mxArray *c17_b_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_u;
  const mxArray *c17_y = NULL;
  SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
  chartInstance = (SFc17_VCU_CS75_12_27_test_logInstanceStruct *)
    chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_u = *(int32_T *)c17_inData;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static int32_T c17_c_emlrt_marshallIn
  (SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  int32_T c17_y;
  int32_T c17_i0;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_i0, 1, 6, 0U, 0, 0U, 0);
  c17_y = c17_i0;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void c17_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_b_sfEvent;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  int32_T c17_y;
  SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
  chartInstance = (SFc17_VCU_CS75_12_27_test_logInstanceStruct *)
    chartInstanceVoid;
  c17_b_sfEvent = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_b_sfEvent),
    &c17_thisId);
  sf_mex_destroy(&c17_b_sfEvent);
  *(int32_T *)c17_outData = c17_y;
  sf_mex_destroy(&c17_mxArrayInData);
}

static uint8_T c17_d_emlrt_marshallIn
  (SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c17_b_is_active_c17_VCU_CS75_12_27_test_log, const char_T *c17_identifier)
{
  uint8_T c17_y;
  emlrtMsgIdentifier c17_thisId;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c17_b_is_active_c17_VCU_CS75_12_27_test_log), &c17_thisId);
  sf_mex_destroy(&c17_b_is_active_c17_VCU_CS75_12_27_test_log);
  return c17_y;
}

static uint8_T c17_e_emlrt_marshallIn
  (SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  uint8_T c17_y;
  uint8_T c17_u0;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_u0, 1, 3, 0U, 0, 0U, 0);
  c17_y = c17_u0;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void init_dsm_address_info(SFc17_VCU_CS75_12_27_test_logInstanceStruct
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

void sf_c17_VCU_CS75_12_27_test_log_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1709782013U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3544122858U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1598336378U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4264599315U);
}

mxArray *sf_c17_VCU_CS75_12_27_test_log_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("tB9QEFyO439iPy1lPBVBRH");
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

mxArray *sf_c17_VCU_CS75_12_27_test_log_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c17_VCU_CS75_12_27_test_log_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c17_VCU_CS75_12_27_test_log(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c17_VCU_CS75_12_27_test_log\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c17_VCU_CS75_12_27_test_log_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc17_VCU_CS75_12_27_test_logInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _VCU_CS75_12_27_test_logMachineNumber_,
           17,
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
          (MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)c17_sf_marshallIn);

        {
          real_T *c17_u;
          real_T *c17_y;
          c17_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c17_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c17_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c17_y);
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
  return "AQ1dQUWiBRYO4e7E4sW2TB";
}

static void sf_opaque_initialize_c17_VCU_CS75_12_27_test_log(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc17_VCU_CS75_12_27_test_logInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c17_VCU_CS75_12_27_test_log
    ((SFc17_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
  initialize_c17_VCU_CS75_12_27_test_log
    ((SFc17_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c17_VCU_CS75_12_27_test_log(void *chartInstanceVar)
{
  enable_c17_VCU_CS75_12_27_test_log
    ((SFc17_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c17_VCU_CS75_12_27_test_log(void *chartInstanceVar)
{
  disable_c17_VCU_CS75_12_27_test_log
    ((SFc17_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c17_VCU_CS75_12_27_test_log(void *chartInstanceVar)
{
  sf_gateway_c17_VCU_CS75_12_27_test_log
    ((SFc17_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c17_VCU_CS75_12_27_test_log
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c17_VCU_CS75_12_27_test_log
    ((SFc17_VCU_CS75_12_27_test_logInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c17_VCU_CS75_12_27_test_log();/* state var info */
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

extern void sf_internal_set_sim_state_c17_VCU_CS75_12_27_test_log(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c17_VCU_CS75_12_27_test_log();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c17_VCU_CS75_12_27_test_log
    ((SFc17_VCU_CS75_12_27_test_logInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c17_VCU_CS75_12_27_test_log
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c17_VCU_CS75_12_27_test_log(S);
}

static void sf_opaque_set_sim_state_c17_VCU_CS75_12_27_test_log(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c17_VCU_CS75_12_27_test_log(S, st);
}

static void sf_opaque_terminate_c17_VCU_CS75_12_27_test_log(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc17_VCU_CS75_12_27_test_logInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_VCU_CS75_12_27_test_log_optimization_info();
    }

    finalize_c17_VCU_CS75_12_27_test_log
      ((SFc17_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc17_VCU_CS75_12_27_test_log
    ((SFc17_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c17_VCU_CS75_12_27_test_log(SimStruct *S)
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
    initialize_params_c17_VCU_CS75_12_27_test_log
      ((SFc17_VCU_CS75_12_27_test_logInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c17_VCU_CS75_12_27_test_log(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_VCU_CS75_12_27_test_log_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      17);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,17,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,17,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,17);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,17,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,17,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,17);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1674254153U));
  ssSetChecksum1(S,(3016725801U));
  ssSetChecksum2(S,(1950381217U));
  ssSetChecksum3(S,(3838348870U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c17_VCU_CS75_12_27_test_log(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c17_VCU_CS75_12_27_test_log(SimStruct *S)
{
  SFc17_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc17_VCU_CS75_12_27_test_logInstanceStruct *)utMalloc(sizeof
    (SFc17_VCU_CS75_12_27_test_logInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc17_VCU_CS75_12_27_test_logInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c17_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c17_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c17_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c17_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c17_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c17_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c17_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c17_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c17_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.mdlStart = mdlStart_c17_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c17_VCU_CS75_12_27_test_log;
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

void c17_VCU_CS75_12_27_test_log_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c17_VCU_CS75_12_27_test_log(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c17_VCU_CS75_12_27_test_log(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c17_VCU_CS75_12_27_test_log(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c17_VCU_CS75_12_27_test_log_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
