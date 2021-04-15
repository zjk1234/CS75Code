/* Include files */

#include <stddef.h>
#include "blas.h"
#include "VCU_CS75_9_30_sfun.h"
#include "c25_VCU_CS75_9_30.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "VCU_CS75_9_30_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c25_debug_family_names[5] = { "nargin", "nargout", "u", "y1",
  "y2" };

/* Function Declarations */
static void initialize_c25_VCU_CS75_9_30(SFc25_VCU_CS75_9_30InstanceStruct
  *chartInstance);
static void initialize_params_c25_VCU_CS75_9_30
  (SFc25_VCU_CS75_9_30InstanceStruct *chartInstance);
static void enable_c25_VCU_CS75_9_30(SFc25_VCU_CS75_9_30InstanceStruct
  *chartInstance);
static void disable_c25_VCU_CS75_9_30(SFc25_VCU_CS75_9_30InstanceStruct
  *chartInstance);
static void c25_update_debugger_state_c25_VCU_CS75_9_30
  (SFc25_VCU_CS75_9_30InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c25_VCU_CS75_9_30
  (SFc25_VCU_CS75_9_30InstanceStruct *chartInstance);
static void set_sim_state_c25_VCU_CS75_9_30(SFc25_VCU_CS75_9_30InstanceStruct
  *chartInstance, const mxArray *c25_st);
static void finalize_c25_VCU_CS75_9_30(SFc25_VCU_CS75_9_30InstanceStruct
  *chartInstance);
static void sf_gateway_c25_VCU_CS75_9_30(SFc25_VCU_CS75_9_30InstanceStruct
  *chartInstance);
static void initSimStructsc25_VCU_CS75_9_30(SFc25_VCU_CS75_9_30InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c25_machineNumber, uint32_T
  c25_chartNumber, uint32_T c25_instanceNumber);
static const mxArray *c25_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static real_T c25_emlrt_marshallIn(SFc25_VCU_CS75_9_30InstanceStruct
  *chartInstance, const mxArray *c25_y2, const char_T *c25_identifier);
static real_T c25_b_emlrt_marshallIn(SFc25_VCU_CS75_9_30InstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId);
static void c25_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static const mxArray *c25_b_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static int32_T c25_c_emlrt_marshallIn(SFc25_VCU_CS75_9_30InstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId);
static void c25_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static uint8_T c25_d_emlrt_marshallIn(SFc25_VCU_CS75_9_30InstanceStruct
  *chartInstance, const mxArray *c25_b_is_active_c25_VCU_CS75_9_30, const char_T
  *c25_identifier);
static uint8_T c25_e_emlrt_marshallIn(SFc25_VCU_CS75_9_30InstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId);
static void init_dsm_address_info(SFc25_VCU_CS75_9_30InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c25_VCU_CS75_9_30(SFc25_VCU_CS75_9_30InstanceStruct
  *chartInstance)
{
  chartInstance->c25_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c25_is_active_c25_VCU_CS75_9_30 = 0U;
}

static void initialize_params_c25_VCU_CS75_9_30
  (SFc25_VCU_CS75_9_30InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c25_VCU_CS75_9_30(SFc25_VCU_CS75_9_30InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c25_VCU_CS75_9_30(SFc25_VCU_CS75_9_30InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c25_update_debugger_state_c25_VCU_CS75_9_30
  (SFc25_VCU_CS75_9_30InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c25_VCU_CS75_9_30
  (SFc25_VCU_CS75_9_30InstanceStruct *chartInstance)
{
  const mxArray *c25_st;
  const mxArray *c25_y = NULL;
  real_T c25_hoistedGlobal;
  real_T c25_u;
  const mxArray *c25_b_y = NULL;
  real_T c25_b_hoistedGlobal;
  real_T c25_b_u;
  const mxArray *c25_c_y = NULL;
  uint8_T c25_c_hoistedGlobal;
  uint8_T c25_c_u;
  const mxArray *c25_d_y = NULL;
  real_T *c25_y1;
  real_T *c25_y2;
  c25_y2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c25_y1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c25_st = NULL;
  c25_st = NULL;
  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_createcellmatrix(3, 1), false);
  c25_hoistedGlobal = *c25_y1;
  c25_u = c25_hoistedGlobal;
  c25_b_y = NULL;
  sf_mex_assign(&c25_b_y, sf_mex_create("y", &c25_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c25_y, 0, c25_b_y);
  c25_b_hoistedGlobal = *c25_y2;
  c25_b_u = c25_b_hoistedGlobal;
  c25_c_y = NULL;
  sf_mex_assign(&c25_c_y, sf_mex_create("y", &c25_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c25_y, 1, c25_c_y);
  c25_c_hoistedGlobal = chartInstance->c25_is_active_c25_VCU_CS75_9_30;
  c25_c_u = c25_c_hoistedGlobal;
  c25_d_y = NULL;
  sf_mex_assign(&c25_d_y, sf_mex_create("y", &c25_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c25_y, 2, c25_d_y);
  sf_mex_assign(&c25_st, c25_y, false);
  return c25_st;
}

static void set_sim_state_c25_VCU_CS75_9_30(SFc25_VCU_CS75_9_30InstanceStruct
  *chartInstance, const mxArray *c25_st)
{
  const mxArray *c25_u;
  real_T *c25_y1;
  real_T *c25_y2;
  c25_y2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c25_y1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c25_doneDoubleBufferReInit = true;
  c25_u = sf_mex_dup(c25_st);
  *c25_y1 = c25_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c25_u,
    0)), "y1");
  *c25_y2 = c25_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c25_u,
    1)), "y2");
  chartInstance->c25_is_active_c25_VCU_CS75_9_30 = c25_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c25_u, 2)),
     "is_active_c25_VCU_CS75_9_30");
  sf_mex_destroy(&c25_u);
  c25_update_debugger_state_c25_VCU_CS75_9_30(chartInstance);
  sf_mex_destroy(&c25_st);
}

static void finalize_c25_VCU_CS75_9_30(SFc25_VCU_CS75_9_30InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c25_VCU_CS75_9_30(SFc25_VCU_CS75_9_30InstanceStruct
  *chartInstance)
{
  real_T c25_hoistedGlobal;
  real_T c25_u;
  uint32_T c25_debug_family_var_map[5];
  real_T c25_nargin = 1.0;
  real_T c25_nargout = 2.0;
  real_T c25_y1;
  real_T c25_y2;
  real_T *c25_b_u;
  real_T *c25_b_y1;
  real_T *c25_b_y2;
  c25_b_y2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c25_b_y1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c25_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 22U, chartInstance->c25_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c25_b_u, 0U);
  chartInstance->c25_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 22U, chartInstance->c25_sfEvent);
  c25_hoistedGlobal = *c25_b_u;
  c25_u = c25_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c25_debug_family_names,
    c25_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_nargin, 0U, c25_sf_marshallOut,
    c25_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_nargout, 1U, c25_sf_marshallOut,
    c25_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c25_u, 2U, c25_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_y1, 3U, c25_sf_marshallOut,
    c25_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_y2, 4U, c25_sf_marshallOut,
    c25_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 2);
  if (CV_EML_IF(0, 1, 0, c25_u <= 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 3);
    c25_y1 = c25_u;
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 4);
    c25_y2 = 0.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 6);
    c25_y1 = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 7);
    c25_y2 = c25_u;
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, -7);
  _SFD_SYMBOL_SCOPE_POP();
  *c25_b_y1 = c25_y1;
  *c25_b_y2 = c25_y2;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c25_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_VCU_CS75_9_30MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c25_b_y1, 1U);
  _SFD_DATA_RANGE_CHECK(*c25_b_y2, 2U);
}

static void initSimStructsc25_VCU_CS75_9_30(SFc25_VCU_CS75_9_30InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c25_machineNumber, uint32_T
  c25_chartNumber, uint32_T c25_instanceNumber)
{
  (void)c25_machineNumber;
  (void)c25_chartNumber;
  (void)c25_instanceNumber;
}

static const mxArray *c25_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  real_T c25_u;
  const mxArray *c25_y = NULL;
  SFc25_VCU_CS75_9_30InstanceStruct *chartInstance;
  chartInstance = (SFc25_VCU_CS75_9_30InstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_u = *(real_T *)c25_inData;
  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", &c25_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static real_T c25_emlrt_marshallIn(SFc25_VCU_CS75_9_30InstanceStruct
  *chartInstance, const mxArray *c25_y2, const char_T *c25_identifier)
{
  real_T c25_y;
  emlrtMsgIdentifier c25_thisId;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_y2), &c25_thisId);
  sf_mex_destroy(&c25_y2);
  return c25_y;
}

static real_T c25_b_emlrt_marshallIn(SFc25_VCU_CS75_9_30InstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId)
{
  real_T c25_y;
  real_T c25_d0;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), &c25_d0, 1, 0, 0U, 0, 0U, 0);
  c25_y = c25_d0;
  sf_mex_destroy(&c25_u);
  return c25_y;
}

static void c25_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_y2;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  real_T c25_y;
  SFc25_VCU_CS75_9_30InstanceStruct *chartInstance;
  chartInstance = (SFc25_VCU_CS75_9_30InstanceStruct *)chartInstanceVoid;
  c25_y2 = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_y2), &c25_thisId);
  sf_mex_destroy(&c25_y2);
  *(real_T *)c25_outData = c25_y;
  sf_mex_destroy(&c25_mxArrayInData);
}

const mxArray *sf_c25_VCU_CS75_9_30_get_eml_resolved_functions_info(void)
{
  const mxArray *c25_nameCaptureInfo = NULL;
  c25_nameCaptureInfo = NULL;
  sf_mex_assign(&c25_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c25_nameCaptureInfo;
}

static const mxArray *c25_b_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_u;
  const mxArray *c25_y = NULL;
  SFc25_VCU_CS75_9_30InstanceStruct *chartInstance;
  chartInstance = (SFc25_VCU_CS75_9_30InstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_u = *(int32_T *)c25_inData;
  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", &c25_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static int32_T c25_c_emlrt_marshallIn(SFc25_VCU_CS75_9_30InstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId)
{
  int32_T c25_y;
  int32_T c25_i0;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), &c25_i0, 1, 6, 0U, 0, 0U, 0);
  c25_y = c25_i0;
  sf_mex_destroy(&c25_u);
  return c25_y;
}

static void c25_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_b_sfEvent;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  int32_T c25_y;
  SFc25_VCU_CS75_9_30InstanceStruct *chartInstance;
  chartInstance = (SFc25_VCU_CS75_9_30InstanceStruct *)chartInstanceVoid;
  c25_b_sfEvent = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_b_sfEvent),
    &c25_thisId);
  sf_mex_destroy(&c25_b_sfEvent);
  *(int32_T *)c25_outData = c25_y;
  sf_mex_destroy(&c25_mxArrayInData);
}

static uint8_T c25_d_emlrt_marshallIn(SFc25_VCU_CS75_9_30InstanceStruct
  *chartInstance, const mxArray *c25_b_is_active_c25_VCU_CS75_9_30, const char_T
  *c25_identifier)
{
  uint8_T c25_y;
  emlrtMsgIdentifier c25_thisId;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c25_b_is_active_c25_VCU_CS75_9_30), &c25_thisId);
  sf_mex_destroy(&c25_b_is_active_c25_VCU_CS75_9_30);
  return c25_y;
}

static uint8_T c25_e_emlrt_marshallIn(SFc25_VCU_CS75_9_30InstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId)
{
  uint8_T c25_y;
  uint8_T c25_u0;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), &c25_u0, 1, 3, 0U, 0, 0U, 0);
  c25_y = c25_u0;
  sf_mex_destroy(&c25_u);
  return c25_y;
}

static void init_dsm_address_info(SFc25_VCU_CS75_9_30InstanceStruct
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

void sf_c25_VCU_CS75_9_30_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(129555706U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1180231715U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3713530880U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2310689876U);
}

mxArray *sf_c25_VCU_CS75_9_30_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("dqj1M25rLSyXBXLrOOFFdF");
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

mxArray *sf_c25_VCU_CS75_9_30_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c25_VCU_CS75_9_30_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c25_VCU_CS75_9_30(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"y1\",},{M[1],M[6],T\"y2\",},{M[8],M[0],T\"is_active_c25_VCU_CS75_9_30\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c25_VCU_CS75_9_30_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc25_VCU_CS75_9_30InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc25_VCU_CS75_9_30InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _VCU_CS75_9_30MachineNumber_,
           25,
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
        init_script_number_translation(_VCU_CS75_9_30MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_VCU_CS75_9_30MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _VCU_CS75_9_30MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y1");
          _SFD_SET_DATA_PROPS(2,2,0,1,"y2");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,95);
        _SFD_CV_INIT_EML_IF(0,1,0,26,34,59,91);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c25_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c25_sf_marshallOut,(MexInFcnForType)c25_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c25_sf_marshallOut,(MexInFcnForType)c25_sf_marshallIn);

        {
          real_T *c25_u;
          real_T *c25_y1;
          real_T *c25_y2;
          c25_y2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c25_y1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c25_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c25_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c25_y1);
          _SFD_SET_DATA_VALUE_PTR(2U, c25_y2);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _VCU_CS75_9_30MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "FakMG2kTSRlE8HAaJ1vH1F";
}

static void sf_opaque_initialize_c25_VCU_CS75_9_30(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc25_VCU_CS75_9_30InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c25_VCU_CS75_9_30((SFc25_VCU_CS75_9_30InstanceStruct*)
    chartInstanceVar);
  initialize_c25_VCU_CS75_9_30((SFc25_VCU_CS75_9_30InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c25_VCU_CS75_9_30(void *chartInstanceVar)
{
  enable_c25_VCU_CS75_9_30((SFc25_VCU_CS75_9_30InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c25_VCU_CS75_9_30(void *chartInstanceVar)
{
  disable_c25_VCU_CS75_9_30((SFc25_VCU_CS75_9_30InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c25_VCU_CS75_9_30(void *chartInstanceVar)
{
  sf_gateway_c25_VCU_CS75_9_30((SFc25_VCU_CS75_9_30InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c25_VCU_CS75_9_30(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c25_VCU_CS75_9_30
    ((SFc25_VCU_CS75_9_30InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c25_VCU_CS75_9_30();/* state var info */
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

extern void sf_internal_set_sim_state_c25_VCU_CS75_9_30(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c25_VCU_CS75_9_30();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c25_VCU_CS75_9_30((SFc25_VCU_CS75_9_30InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c25_VCU_CS75_9_30(SimStruct* S)
{
  return sf_internal_get_sim_state_c25_VCU_CS75_9_30(S);
}

static void sf_opaque_set_sim_state_c25_VCU_CS75_9_30(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c25_VCU_CS75_9_30(S, st);
}

static void sf_opaque_terminate_c25_VCU_CS75_9_30(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc25_VCU_CS75_9_30InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_VCU_CS75_9_30_optimization_info();
    }

    finalize_c25_VCU_CS75_9_30((SFc25_VCU_CS75_9_30InstanceStruct*)
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
  initSimStructsc25_VCU_CS75_9_30((SFc25_VCU_CS75_9_30InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c25_VCU_CS75_9_30(SimStruct *S)
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
    initialize_params_c25_VCU_CS75_9_30((SFc25_VCU_CS75_9_30InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c25_VCU_CS75_9_30(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_VCU_CS75_9_30_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      25);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,25,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,25,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,25);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,25,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,25,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,25);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1903973166U));
  ssSetChecksum1(S,(1333388339U));
  ssSetChecksum2(S,(2136690655U));
  ssSetChecksum3(S,(1376718518U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c25_VCU_CS75_9_30(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c25_VCU_CS75_9_30(SimStruct *S)
{
  SFc25_VCU_CS75_9_30InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc25_VCU_CS75_9_30InstanceStruct *)utMalloc(sizeof
    (SFc25_VCU_CS75_9_30InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc25_VCU_CS75_9_30InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c25_VCU_CS75_9_30;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c25_VCU_CS75_9_30;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c25_VCU_CS75_9_30;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c25_VCU_CS75_9_30;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c25_VCU_CS75_9_30;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c25_VCU_CS75_9_30;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c25_VCU_CS75_9_30;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c25_VCU_CS75_9_30;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c25_VCU_CS75_9_30;
  chartInstance->chartInfo.mdlStart = mdlStart_c25_VCU_CS75_9_30;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c25_VCU_CS75_9_30;
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

void c25_VCU_CS75_9_30_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c25_VCU_CS75_9_30(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c25_VCU_CS75_9_30(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c25_VCU_CS75_9_30(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c25_VCU_CS75_9_30_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
