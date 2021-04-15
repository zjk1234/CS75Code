/* Include files */

#include <stddef.h>
#include "blas.h"
#include "VCU_CS75_10_9_SteeringTorque_sfun.h"
#include "c19_VCU_CS75_10_9_SteeringTorque.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "VCU_CS75_10_9_SteeringTorque_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c19_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

/* Function Declarations */
static void initialize_c19_VCU_CS75_10_9_SteeringTorque
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance);
static void initialize_params_c19_VCU_CS75_10_9_SteeringTorque
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance);
static void enable_c19_VCU_CS75_10_9_SteeringTorque
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance);
static void disable_c19_VCU_CS75_10_9_SteeringTorque
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance);
static void c19_update_debugger_state_c19_VCU_CS75_10_9_SteeringTorque
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c19_VCU_CS75_10_9_SteeringTorque
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance);
static void set_sim_state_c19_VCU_CS75_10_9_SteeringTorque
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance, const
   mxArray *c19_st);
static void finalize_c19_VCU_CS75_10_9_SteeringTorque
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance);
static void sf_gateway_c19_VCU_CS75_10_9_SteeringTorque
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance);
static void initSimStructsc19_VCU_CS75_10_9_SteeringTorque
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber, uint32_T c19_instanceNumber);
static const mxArray *c19_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static real_T c19_emlrt_marshallIn
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance, const
   mxArray *c19_y, const char_T *c19_identifier);
static real_T c19_b_emlrt_marshallIn
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_b_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static int32_T c19_c_emlrt_marshallIn
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static uint8_T c19_d_emlrt_marshallIn
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance, const
   mxArray *c19_b_is_active_c19_VCU_CS75_10_9_SteeringTorque, const char_T
   *c19_identifier);
static uint8_T c19_e_emlrt_marshallIn
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void init_dsm_address_info
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c19_VCU_CS75_10_9_SteeringTorque
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance)
{
  chartInstance->c19_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c19_is_active_c19_VCU_CS75_10_9_SteeringTorque = 0U;
}

static void initialize_params_c19_VCU_CS75_10_9_SteeringTorque
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c19_VCU_CS75_10_9_SteeringTorque
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c19_VCU_CS75_10_9_SteeringTorque
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c19_update_debugger_state_c19_VCU_CS75_10_9_SteeringTorque
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c19_VCU_CS75_10_9_SteeringTorque
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance)
{
  const mxArray *c19_st;
  const mxArray *c19_y = NULL;
  real_T c19_hoistedGlobal;
  real_T c19_u;
  const mxArray *c19_b_y = NULL;
  uint8_T c19_b_hoistedGlobal;
  uint8_T c19_b_u;
  const mxArray *c19_c_y = NULL;
  real_T *c19_d_y;
  c19_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c19_st = NULL;
  c19_st = NULL;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_createcellmatrix(2, 1), false);
  c19_hoistedGlobal = *c19_d_y;
  c19_u = c19_hoistedGlobal;
  c19_b_y = NULL;
  sf_mex_assign(&c19_b_y, sf_mex_create("y", &c19_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c19_y, 0, c19_b_y);
  c19_b_hoistedGlobal =
    chartInstance->c19_is_active_c19_VCU_CS75_10_9_SteeringTorque;
  c19_b_u = c19_b_hoistedGlobal;
  c19_c_y = NULL;
  sf_mex_assign(&c19_c_y, sf_mex_create("y", &c19_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c19_y, 1, c19_c_y);
  sf_mex_assign(&c19_st, c19_y, false);
  return c19_st;
}

static void set_sim_state_c19_VCU_CS75_10_9_SteeringTorque
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance, const
   mxArray *c19_st)
{
  const mxArray *c19_u;
  real_T *c19_y;
  c19_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c19_doneDoubleBufferReInit = true;
  c19_u = sf_mex_dup(c19_st);
  *c19_y = c19_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c19_u,
    0)), "y");
  chartInstance->c19_is_active_c19_VCU_CS75_10_9_SteeringTorque =
    c19_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c19_u, 1)),
    "is_active_c19_VCU_CS75_10_9_SteeringTorque");
  sf_mex_destroy(&c19_u);
  c19_update_debugger_state_c19_VCU_CS75_10_9_SteeringTorque(chartInstance);
  sf_mex_destroy(&c19_st);
}

static void finalize_c19_VCU_CS75_10_9_SteeringTorque
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c19_VCU_CS75_10_9_SteeringTorque
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance)
{
  real_T c19_hoistedGlobal;
  real_T c19_u;
  uint32_T c19_debug_family_var_map[4];
  real_T c19_nargin = 1.0;
  real_T c19_nargout = 1.0;
  real_T c19_y;
  real_T *c19_b_u;
  real_T *c19_b_y;
  c19_b_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c19_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 16U, chartInstance->c19_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c19_b_u, 0U);
  chartInstance->c19_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 16U, chartInstance->c19_sfEvent);
  c19_hoistedGlobal = *c19_b_u;
  c19_u = c19_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c19_debug_family_names,
    c19_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_nargin, 0U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_nargout, 1U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c19_u, 2U, c19_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_y, 3U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 2);
  if (CV_EML_IF(0, 1, 0, c19_u == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 3);
    c19_y = 1.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 5);
    c19_y = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, -5);
  _SFD_SYMBOL_SCOPE_POP();
  *c19_b_y = c19_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c19_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_VCU_CS75_10_9_SteeringTorqueMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c19_b_y, 1U);
}

static void initSimStructsc19_VCU_CS75_10_9_SteeringTorque
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber, uint32_T c19_instanceNumber)
{
  (void)c19_machineNumber;
  (void)c19_chartNumber;
  (void)c19_instanceNumber;
}

static const mxArray *c19_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  real_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance;
  chartInstance = (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *)
    chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(real_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static real_T c19_emlrt_marshallIn
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance, const
   mxArray *c19_y, const char_T *c19_identifier)
{
  real_T c19_b_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_b_y = c19_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_y), &c19_thisId);
  sf_mex_destroy(&c19_y);
  return c19_b_y;
}

static real_T c19_b_emlrt_marshallIn
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  real_T c19_y;
  real_T c19_d0;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_d0, 1, 0, 0U, 0, 0U, 0);
  c19_y = c19_d0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_y;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_b_y;
  SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance;
  chartInstance = (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *)
    chartInstanceVoid;
  c19_y = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_b_y = c19_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_y), &c19_thisId);
  sf_mex_destroy(&c19_y);
  *(real_T *)c19_outData = c19_b_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

const mxArray
  *sf_c19_VCU_CS75_10_9_SteeringTorque_get_eml_resolved_functions_info(void)
{
  const mxArray *c19_nameCaptureInfo = NULL;
  c19_nameCaptureInfo = NULL;
  sf_mex_assign(&c19_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c19_nameCaptureInfo;
}

static const mxArray *c19_b_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance;
  chartInstance = (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *)
    chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(int32_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static int32_T c19_c_emlrt_marshallIn
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  int32_T c19_y;
  int32_T c19_i0;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_i0, 1, 6, 0U, 0, 0U, 0);
  c19_y = c19_i0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_b_sfEvent;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  int32_T c19_y;
  SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance;
  chartInstance = (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *)
    chartInstanceVoid;
  c19_b_sfEvent = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_sfEvent),
    &c19_thisId);
  sf_mex_destroy(&c19_b_sfEvent);
  *(int32_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static uint8_T c19_d_emlrt_marshallIn
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance, const
   mxArray *c19_b_is_active_c19_VCU_CS75_10_9_SteeringTorque, const char_T
   *c19_identifier)
{
  uint8_T c19_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c19_b_is_active_c19_VCU_CS75_10_9_SteeringTorque), &c19_thisId);
  sf_mex_destroy(&c19_b_is_active_c19_VCU_CS75_10_9_SteeringTorque);
  return c19_y;
}

static uint8_T c19_e_emlrt_marshallIn
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  uint8_T c19_y;
  uint8_T c19_u0;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_u0, 1, 3, 0U, 0, 0U, 0);
  c19_y = c19_u0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void init_dsm_address_info
  (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance)
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

void sf_c19_VCU_CS75_10_9_SteeringTorque_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1709782013U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3544122858U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1598336378U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4264599315U);
}

mxArray *sf_c19_VCU_CS75_10_9_SteeringTorque_get_autoinheritance_info(void)
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

mxArray *sf_c19_VCU_CS75_10_9_SteeringTorque_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c19_VCU_CS75_10_9_SteeringTorque_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c19_VCU_CS75_10_9_SteeringTorque
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c19_VCU_CS75_10_9_SteeringTorque\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c19_VCU_CS75_10_9_SteeringTorque_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _VCU_CS75_10_9_SteeringTorqueMachineNumber_,
           19,
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
        init_script_number_translation
          (_VCU_CS75_10_9_SteeringTorqueMachineNumber_,
           chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _VCU_CS75_10_9_SteeringTorqueMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _VCU_CS75_10_9_SteeringTorqueMachineNumber_,
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
          (MexFcnForType)c19_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_sf_marshallOut,(MexInFcnForType)c19_sf_marshallIn);

        {
          real_T *c19_u;
          real_T *c19_y;
          c19_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c19_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c19_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c19_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _VCU_CS75_10_9_SteeringTorqueMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "AQ1dQUWiBRYO4e7E4sW2TB";
}

static void sf_opaque_initialize_c19_VCU_CS75_10_9_SteeringTorque(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c19_VCU_CS75_10_9_SteeringTorque
    ((SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct*) chartInstanceVar);
  initialize_c19_VCU_CS75_10_9_SteeringTorque
    ((SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c19_VCU_CS75_10_9_SteeringTorque(void
  *chartInstanceVar)
{
  enable_c19_VCU_CS75_10_9_SteeringTorque
    ((SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c19_VCU_CS75_10_9_SteeringTorque(void
  *chartInstanceVar)
{
  disable_c19_VCU_CS75_10_9_SteeringTorque
    ((SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c19_VCU_CS75_10_9_SteeringTorque(void
  *chartInstanceVar)
{
  sf_gateway_c19_VCU_CS75_10_9_SteeringTorque
    ((SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c19_VCU_CS75_10_9_SteeringTorque
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c19_VCU_CS75_10_9_SteeringTorque
    ((SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c19_VCU_CS75_10_9_SteeringTorque();/* state var info */
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

extern void sf_internal_set_sim_state_c19_VCU_CS75_10_9_SteeringTorque(SimStruct*
  S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c19_VCU_CS75_10_9_SteeringTorque();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c19_VCU_CS75_10_9_SteeringTorque
    ((SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c19_VCU_CS75_10_9_SteeringTorque
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c19_VCU_CS75_10_9_SteeringTorque(S);
}

static void sf_opaque_set_sim_state_c19_VCU_CS75_10_9_SteeringTorque(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c19_VCU_CS75_10_9_SteeringTorque(S, st);
}

static void sf_opaque_terminate_c19_VCU_CS75_10_9_SteeringTorque(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_VCU_CS75_10_9_SteeringTorque_optimization_info();
    }

    finalize_c19_VCU_CS75_10_9_SteeringTorque
      ((SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc19_VCU_CS75_10_9_SteeringTorque
    ((SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c19_VCU_CS75_10_9_SteeringTorque(SimStruct *S)
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
    initialize_params_c19_VCU_CS75_10_9_SteeringTorque
      ((SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c19_VCU_CS75_10_9_SteeringTorque(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_VCU_CS75_10_9_SteeringTorque_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      19);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,19,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,19,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,19);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,19,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,19,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,19);
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

static void mdlRTW_c19_VCU_CS75_10_9_SteeringTorque(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c19_VCU_CS75_10_9_SteeringTorque(SimStruct *S)
{
  SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct *)utMalloc
    (sizeof(SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc19_VCU_CS75_10_9_SteeringTorqueInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c19_VCU_CS75_10_9_SteeringTorque;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c19_VCU_CS75_10_9_SteeringTorque;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c19_VCU_CS75_10_9_SteeringTorque;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c19_VCU_CS75_10_9_SteeringTorque;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c19_VCU_CS75_10_9_SteeringTorque;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c19_VCU_CS75_10_9_SteeringTorque;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c19_VCU_CS75_10_9_SteeringTorque;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c19_VCU_CS75_10_9_SteeringTorque;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c19_VCU_CS75_10_9_SteeringTorque;
  chartInstance->chartInfo.mdlStart = mdlStart_c19_VCU_CS75_10_9_SteeringTorque;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c19_VCU_CS75_10_9_SteeringTorque;
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

void c19_VCU_CS75_10_9_SteeringTorque_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c19_VCU_CS75_10_9_SteeringTorque(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c19_VCU_CS75_10_9_SteeringTorque(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c19_VCU_CS75_10_9_SteeringTorque(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c19_VCU_CS75_10_9_SteeringTorque_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
