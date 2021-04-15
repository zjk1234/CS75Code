/* Include files */

#include <stddef.h>
#include "blas.h"
#include "VCU_CS75_12_27_test_log_sfun.h"
#include "c20_VCU_CS75_12_27_test_log.h"
#include "mwmathutil.h"
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
static const char * c20_debug_family_names[24] = { "P", "I", "ErrorSumMax",
  "PID_SteeringTorque", "nargin", "nargout", "LaterlAngleCommand",
  "SAS_SteeringAngle", "Ready", "P1", "I1", "P2", "I2", "P3", "I3", "D",
  "ErrorSumMax1", "ErrorSumMax2", "ErrorSumMax3", "ErrorPre", "ErrorSumPre",
  "SteeringTorqueOut", "Error", "ErrorSum" };

/* Function Declarations */
static void initialize_c20_VCU_CS75_12_27_test_log
  (SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void initialize_params_c20_VCU_CS75_12_27_test_log
  (SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void enable_c20_VCU_CS75_12_27_test_log
  (SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void disable_c20_VCU_CS75_12_27_test_log
  (SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void c20_update_debugger_state_c20_VCU_CS75_12_27_test_log
  (SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c20_VCU_CS75_12_27_test_log
  (SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void set_sim_state_c20_VCU_CS75_12_27_test_log
  (SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c20_st);
static void finalize_c20_VCU_CS75_12_27_test_log
  (SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void sf_gateway_c20_VCU_CS75_12_27_test_log
  (SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void initSimStructsc20_VCU_CS75_12_27_test_log
  (SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber, uint32_T c20_instanceNumber);
static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static real_T c20_emlrt_marshallIn(SFc20_VCU_CS75_12_27_test_logInstanceStruct
  *chartInstance, const mxArray *c20_ErrorSum, const char_T *c20_identifier);
static real_T c20_b_emlrt_marshallIn(SFc20_VCU_CS75_12_27_test_logInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static void c20_info_helper(const mxArray **c20_info);
static const mxArray *c20_emlrt_marshallOut(const char * c20_u);
static const mxArray *c20_b_emlrt_marshallOut(const uint32_T c20_u);
static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static int32_T c20_c_emlrt_marshallIn
  (SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static uint8_T c20_d_emlrt_marshallIn
  (SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c20_b_is_active_c20_VCU_CS75_12_27_test_log, const char_T *c20_identifier);
static uint8_T c20_e_emlrt_marshallIn
  (SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void init_dsm_address_info(SFc20_VCU_CS75_12_27_test_logInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c20_VCU_CS75_12_27_test_log
  (SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  chartInstance->c20_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c20_is_active_c20_VCU_CS75_12_27_test_log = 0U;
}

static void initialize_params_c20_VCU_CS75_12_27_test_log
  (SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c20_VCU_CS75_12_27_test_log
  (SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c20_VCU_CS75_12_27_test_log
  (SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c20_update_debugger_state_c20_VCU_CS75_12_27_test_log
  (SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c20_VCU_CS75_12_27_test_log
  (SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  const mxArray *c20_st;
  const mxArray *c20_y = NULL;
  real_T c20_hoistedGlobal;
  real_T c20_u;
  const mxArray *c20_b_y = NULL;
  real_T c20_b_hoistedGlobal;
  real_T c20_b_u;
  const mxArray *c20_c_y = NULL;
  real_T c20_c_hoistedGlobal;
  real_T c20_c_u;
  const mxArray *c20_d_y = NULL;
  uint8_T c20_d_hoistedGlobal;
  uint8_T c20_d_u;
  const mxArray *c20_e_y = NULL;
  real_T *c20_Error;
  real_T *c20_ErrorSum;
  real_T *c20_SteeringTorqueOut;
  c20_ErrorSum = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c20_Error = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c20_SteeringTorqueOut = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c20_st = NULL;
  c20_st = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_createcellmatrix(4, 1), false);
  c20_hoistedGlobal = *c20_Error;
  c20_u = c20_hoistedGlobal;
  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", &c20_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 0, c20_b_y);
  c20_b_hoistedGlobal = *c20_ErrorSum;
  c20_b_u = c20_b_hoistedGlobal;
  c20_c_y = NULL;
  sf_mex_assign(&c20_c_y, sf_mex_create("y", &c20_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 1, c20_c_y);
  c20_c_hoistedGlobal = *c20_SteeringTorqueOut;
  c20_c_u = c20_c_hoistedGlobal;
  c20_d_y = NULL;
  sf_mex_assign(&c20_d_y, sf_mex_create("y", &c20_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 2, c20_d_y);
  c20_d_hoistedGlobal = chartInstance->c20_is_active_c20_VCU_CS75_12_27_test_log;
  c20_d_u = c20_d_hoistedGlobal;
  c20_e_y = NULL;
  sf_mex_assign(&c20_e_y, sf_mex_create("y", &c20_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 3, c20_e_y);
  sf_mex_assign(&c20_st, c20_y, false);
  return c20_st;
}

static void set_sim_state_c20_VCU_CS75_12_27_test_log
  (SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c20_st)
{
  const mxArray *c20_u;
  real_T *c20_Error;
  real_T *c20_ErrorSum;
  real_T *c20_SteeringTorqueOut;
  c20_ErrorSum = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c20_Error = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c20_SteeringTorqueOut = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c20_doneDoubleBufferReInit = true;
  c20_u = sf_mex_dup(c20_st);
  *c20_Error = c20_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c20_u, 0)), "Error");
  *c20_ErrorSum = c20_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c20_u, 1)), "ErrorSum");
  *c20_SteeringTorqueOut = c20_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c20_u, 2)), "SteeringTorqueOut");
  chartInstance->c20_is_active_c20_VCU_CS75_12_27_test_log =
    c20_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 3)),
    "is_active_c20_VCU_CS75_12_27_test_log");
  sf_mex_destroy(&c20_u);
  c20_update_debugger_state_c20_VCU_CS75_12_27_test_log(chartInstance);
  sf_mex_destroy(&c20_st);
}

static void finalize_c20_VCU_CS75_12_27_test_log
  (SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c20_VCU_CS75_12_27_test_log
  (SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  real_T c20_hoistedGlobal;
  real_T c20_b_hoistedGlobal;
  real_T c20_c_hoistedGlobal;
  real_T c20_d_hoistedGlobal;
  real_T c20_e_hoistedGlobal;
  real_T c20_f_hoistedGlobal;
  real_T c20_g_hoistedGlobal;
  real_T c20_h_hoistedGlobal;
  real_T c20_i_hoistedGlobal;
  real_T c20_j_hoistedGlobal;
  real_T c20_k_hoistedGlobal;
  real_T c20_l_hoistedGlobal;
  real_T c20_m_hoistedGlobal;
  real_T c20_n_hoistedGlobal;
  real_T c20_o_hoistedGlobal;
  real_T c20_LaterlAngleCommand;
  real_T c20_SAS_SteeringAngle;
  real_T c20_Ready;
  real_T c20_P1;
  real_T c20_I1;
  real_T c20_P2;
  real_T c20_I2;
  real_T c20_P3;
  real_T c20_I3;
  real_T c20_D;
  real_T c20_ErrorSumMax1;
  real_T c20_ErrorSumMax2;
  real_T c20_ErrorSumMax3;
  real_T c20_ErrorPre;
  real_T c20_ErrorSumPre;
  uint32_T c20_debug_family_var_map[24];
  real_T c20_P;
  real_T c20_I;
  real_T c20_ErrorSumMax;
  real_T c20_PID_SteeringTorque;
  real_T c20_nargin = 15.0;
  real_T c20_nargout = 3.0;
  real_T c20_SteeringTorqueOut;
  real_T c20_Error;
  real_T c20_ErrorSum;
  real_T c20_x;
  real_T c20_b_x;
  real_T c20_y;
  real_T c20_c_x;
  real_T c20_d_x;
  real_T c20_b_y;
  real_T *c20_b_LaterlAngleCommand;
  real_T *c20_b_SteeringTorqueOut;
  real_T *c20_b_Error;
  real_T *c20_b_SAS_SteeringAngle;
  real_T *c20_b_Ready;
  real_T *c20_b_ErrorSum;
  real_T *c20_b_P1;
  real_T *c20_b_I1;
  real_T *c20_b_P2;
  real_T *c20_b_I2;
  real_T *c20_b_P3;
  real_T *c20_b_I3;
  real_T *c20_b_D;
  real_T *c20_b_ErrorSumMax1;
  real_T *c20_b_ErrorSumMax2;
  real_T *c20_b_ErrorSumMax3;
  real_T *c20_b_ErrorPre;
  real_T *c20_b_ErrorSumPre;
  c20_b_ErrorSumPre = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
  c20_b_ErrorPre = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  c20_b_ErrorSumMax3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c20_b_ErrorSumMax2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c20_b_ErrorSumMax1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c20_b_D = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c20_b_I3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c20_b_P3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c20_b_I2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c20_b_P2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c20_b_I1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c20_b_P1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c20_b_ErrorSum = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c20_b_Ready = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c20_b_SAS_SteeringAngle = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c20_b_Error = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c20_b_SteeringTorqueOut = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c20_b_LaterlAngleCommand = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 17U, chartInstance->c20_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c20_b_LaterlAngleCommand, 0U);
  chartInstance->c20_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 17U, chartInstance->c20_sfEvent);
  c20_hoistedGlobal = *c20_b_LaterlAngleCommand;
  c20_b_hoistedGlobal = *c20_b_SAS_SteeringAngle;
  c20_c_hoistedGlobal = *c20_b_Ready;
  c20_d_hoistedGlobal = *c20_b_P1;
  c20_e_hoistedGlobal = *c20_b_I1;
  c20_f_hoistedGlobal = *c20_b_P2;
  c20_g_hoistedGlobal = *c20_b_I2;
  c20_h_hoistedGlobal = *c20_b_P3;
  c20_i_hoistedGlobal = *c20_b_I3;
  c20_j_hoistedGlobal = *c20_b_D;
  c20_k_hoistedGlobal = *c20_b_ErrorSumMax1;
  c20_l_hoistedGlobal = *c20_b_ErrorSumMax2;
  c20_m_hoistedGlobal = *c20_b_ErrorSumMax3;
  c20_n_hoistedGlobal = *c20_b_ErrorPre;
  c20_o_hoistedGlobal = *c20_b_ErrorSumPre;
  c20_LaterlAngleCommand = c20_hoistedGlobal;
  c20_SAS_SteeringAngle = c20_b_hoistedGlobal;
  c20_Ready = c20_c_hoistedGlobal;
  c20_P1 = c20_d_hoistedGlobal;
  c20_I1 = c20_e_hoistedGlobal;
  c20_P2 = c20_f_hoistedGlobal;
  c20_I2 = c20_g_hoistedGlobal;
  c20_P3 = c20_h_hoistedGlobal;
  c20_I3 = c20_i_hoistedGlobal;
  c20_D = c20_j_hoistedGlobal;
  c20_ErrorSumMax1 = c20_k_hoistedGlobal;
  c20_ErrorSumMax2 = c20_l_hoistedGlobal;
  c20_ErrorSumMax3 = c20_m_hoistedGlobal;
  c20_ErrorPre = c20_n_hoistedGlobal;
  c20_ErrorSumPre = c20_o_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 24U, 24U, c20_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_P, 0U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_I, 1U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_ErrorSumMax, 2U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_PID_SteeringTorque, 3U,
    c20_sf_marshallOut, c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 4U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 5U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_LaterlAngleCommand, 6U, c20_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_SAS_SteeringAngle, 7U, c20_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_Ready, 8U, c20_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_P1, 9U, c20_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_I1, 10U, c20_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_P2, 11U, c20_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_I2, 12U, c20_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_P3, 13U, c20_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_I3, 14U, c20_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_D, 15U, c20_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_ErrorSumMax1, 16U, c20_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_ErrorSumMax2, 17U, c20_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_ErrorSumMax3, 18U, c20_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_ErrorPre, 19U, c20_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_ErrorSumPre, 20U, c20_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_SteeringTorqueOut, 21U,
    c20_sf_marshallOut, c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_Error, 22U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_ErrorSum, 23U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 3);
  c20_Error = c20_LaterlAngleCommand - c20_SAS_SteeringAngle;
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 4);
  c20_x = c20_Error;
  c20_b_x = c20_x;
  c20_y = muDoubleScalarAbs(c20_b_x);
  if (CV_EML_IF(0, 1, 0, c20_y < 50.0)) {
    _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 5);
    c20_P = c20_P1;
    _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 6);
    c20_I = c20_I1;
    _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 7);
    c20_ErrorSumMax = c20_ErrorSumMax1;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 8);
    c20_c_x = c20_Error;
    c20_d_x = c20_c_x;
    c20_b_y = muDoubleScalarAbs(c20_d_x);
    if (CV_EML_IF(0, 1, 1, c20_b_y < 250.0)) {
      _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 9);
      c20_P = c20_P2;
      _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 10);
      c20_I = c20_I2;
      _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 11);
      c20_ErrorSumMax = c20_ErrorSumMax2;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 13);
      c20_P = c20_P3;
      _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 14);
      c20_I = c20_I3;
      _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 15);
      c20_ErrorSumMax = c20_ErrorSumMax3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 18);
  if (CV_EML_IF(0, 1, 2, c20_Ready == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 19);
    c20_ErrorSum = c20_ErrorSumPre + c20_Error;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 21);
    c20_ErrorSum = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 25);
  if (CV_EML_IF(0, 1, 3, c20_ErrorSum > c20_ErrorSumMax)) {
    _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 26);
    c20_ErrorSum = c20_ErrorSumMax;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 27);
    if (CV_EML_IF(0, 1, 4, c20_ErrorSum < -c20_ErrorSumMax)) {
      _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 28);
      c20_ErrorSum = -c20_ErrorSumMax;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 32);
  c20_PID_SteeringTorque = (c20_P * c20_Error + c20_I * c20_ErrorSum) + c20_D *
    (c20_Error - c20_ErrorPre);
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 35);
  if (CV_EML_IF(0, 1, 5, c20_Ready == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 36);
    c20_SteeringTorqueOut = c20_PID_SteeringTorque;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 38);
    c20_SteeringTorqueOut = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, -38);
  _SFD_SYMBOL_SCOPE_POP();
  *c20_b_SteeringTorqueOut = c20_SteeringTorqueOut;
  *c20_b_Error = c20_Error;
  *c20_b_ErrorSum = c20_ErrorSum;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c20_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_VCU_CS75_12_27_test_logMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c20_b_SteeringTorqueOut, 1U);
  _SFD_DATA_RANGE_CHECK(*c20_b_Error, 2U);
  _SFD_DATA_RANGE_CHECK(*c20_b_SAS_SteeringAngle, 3U);
  _SFD_DATA_RANGE_CHECK(*c20_b_Ready, 4U);
  _SFD_DATA_RANGE_CHECK(*c20_b_ErrorSum, 5U);
  _SFD_DATA_RANGE_CHECK(*c20_b_P1, 6U);
  _SFD_DATA_RANGE_CHECK(*c20_b_I1, 7U);
  _SFD_DATA_RANGE_CHECK(*c20_b_P2, 8U);
  _SFD_DATA_RANGE_CHECK(*c20_b_I2, 9U);
  _SFD_DATA_RANGE_CHECK(*c20_b_P3, 10U);
  _SFD_DATA_RANGE_CHECK(*c20_b_I3, 11U);
  _SFD_DATA_RANGE_CHECK(*c20_b_D, 12U);
  _SFD_DATA_RANGE_CHECK(*c20_b_ErrorSumMax1, 13U);
  _SFD_DATA_RANGE_CHECK(*c20_b_ErrorSumMax2, 14U);
  _SFD_DATA_RANGE_CHECK(*c20_b_ErrorSumMax3, 15U);
  _SFD_DATA_RANGE_CHECK(*c20_b_ErrorPre, 16U);
  _SFD_DATA_RANGE_CHECK(*c20_b_ErrorSumPre, 17U);
}

static void initSimStructsc20_VCU_CS75_12_27_test_log
  (SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber, uint32_T c20_instanceNumber)
{
  (void)c20_machineNumber;
  (void)c20_chartNumber;
  (void)c20_instanceNumber;
}

static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  real_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
  chartInstance = (SFc20_VCU_CS75_12_27_test_logInstanceStruct *)
    chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(real_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static real_T c20_emlrt_marshallIn(SFc20_VCU_CS75_12_27_test_logInstanceStruct
  *chartInstance, const mxArray *c20_ErrorSum, const char_T *c20_identifier)
{
  real_T c20_y;
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_ErrorSum),
    &c20_thisId);
  sf_mex_destroy(&c20_ErrorSum);
  return c20_y;
}

static real_T c20_b_emlrt_marshallIn(SFc20_VCU_CS75_12_27_test_logInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  real_T c20_y;
  real_T c20_d0;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_d0, 1, 0, 0U, 0, 0U, 0);
  c20_y = c20_d0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_ErrorSum;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y;
  SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
  chartInstance = (SFc20_VCU_CS75_12_27_test_logInstanceStruct *)
    chartInstanceVoid;
  c20_ErrorSum = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_ErrorSum),
    &c20_thisId);
  sf_mex_destroy(&c20_ErrorSum);
  *(real_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

const mxArray *sf_c20_VCU_CS75_12_27_test_log_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c20_nameCaptureInfo = NULL;
  c20_nameCaptureInfo = NULL;
  sf_mex_assign(&c20_nameCaptureInfo, sf_mex_createstruct("structure", 2, 3, 1),
                false);
  c20_info_helper(&c20_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c20_nameCaptureInfo);
  return c20_nameCaptureInfo;
}

static void c20_info_helper(const mxArray **c20_info)
{
  const mxArray *c20_rhs0 = NULL;
  const mxArray *c20_lhs0 = NULL;
  const mxArray *c20_rhs1 = NULL;
  const mxArray *c20_lhs1 = NULL;
  const mxArray *c20_rhs2 = NULL;
  const mxArray *c20_lhs2 = NULL;
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("abs"), "name", "name", 0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1363717452U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c20_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c20_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 2);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1286825912U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c20_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs2), "lhs", "lhs",
                  2);
  sf_mex_destroy(&c20_rhs0);
  sf_mex_destroy(&c20_lhs0);
  sf_mex_destroy(&c20_rhs1);
  sf_mex_destroy(&c20_lhs1);
  sf_mex_destroy(&c20_rhs2);
  sf_mex_destroy(&c20_lhs2);
}

static const mxArray *c20_emlrt_marshallOut(const char * c20_u)
{
  const mxArray *c20_y = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c20_u)), false);
  return c20_y;
}

static const mxArray *c20_b_emlrt_marshallOut(const uint32_T c20_u)
{
  const mxArray *c20_y = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 7, 0U, 0U, 0U, 0), false);
  return c20_y;
}

static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
  chartInstance = (SFc20_VCU_CS75_12_27_test_logInstanceStruct *)
    chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(int32_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static int32_T c20_c_emlrt_marshallIn
  (SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  int32_T c20_y;
  int32_T c20_i0;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_i0, 1, 6, 0U, 0, 0U, 0);
  c20_y = c20_i0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_sfEvent;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  int32_T c20_y;
  SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
  chartInstance = (SFc20_VCU_CS75_12_27_test_logInstanceStruct *)
    chartInstanceVoid;
  c20_b_sfEvent = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_sfEvent),
    &c20_thisId);
  sf_mex_destroy(&c20_b_sfEvent);
  *(int32_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static uint8_T c20_d_emlrt_marshallIn
  (SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c20_b_is_active_c20_VCU_CS75_12_27_test_log, const char_T *c20_identifier)
{
  uint8_T c20_y;
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c20_b_is_active_c20_VCU_CS75_12_27_test_log), &c20_thisId);
  sf_mex_destroy(&c20_b_is_active_c20_VCU_CS75_12_27_test_log);
  return c20_y;
}

static uint8_T c20_e_emlrt_marshallIn
  (SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  uint8_T c20_y;
  uint8_T c20_u0;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_u0, 1, 3, 0U, 0, 0U, 0);
  c20_y = c20_u0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void init_dsm_address_info(SFc20_VCU_CS75_12_27_test_logInstanceStruct
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

void sf_c20_VCU_CS75_12_27_test_log_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3830681894U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1381555558U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2825946876U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3420518201U);
}

mxArray *sf_c20_VCU_CS75_12_27_test_log_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("BlS7Bbmb5EfuA8HX504v6");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,15,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,14,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,14,"type",mxType);
    }

    mxSetField(mxData,14,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c20_VCU_CS75_12_27_test_log_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c20_VCU_CS75_12_27_test_log_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c20_VCU_CS75_12_27_test_log(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[9],T\"Error\",},{M[1],M[8],T\"ErrorSum\",},{M[1],M[5],T\"SteeringTorqueOut\",},{M[8],M[0],T\"is_active_c20_VCU_CS75_12_27_test_log\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c20_VCU_CS75_12_27_test_log_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc20_VCU_CS75_12_27_test_logInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _VCU_CS75_12_27_test_logMachineNumber_,
           20,
           1,
           1,
           0,
           18,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"LaterlAngleCommand");
          _SFD_SET_DATA_PROPS(1,2,0,1,"SteeringTorqueOut");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Error");
          _SFD_SET_DATA_PROPS(3,1,1,0,"SAS_SteeringAngle");
          _SFD_SET_DATA_PROPS(4,1,1,0,"Ready");
          _SFD_SET_DATA_PROPS(5,2,0,1,"ErrorSum");
          _SFD_SET_DATA_PROPS(6,1,1,0,"P1");
          _SFD_SET_DATA_PROPS(7,1,1,0,"I1");
          _SFD_SET_DATA_PROPS(8,1,1,0,"P2");
          _SFD_SET_DATA_PROPS(9,1,1,0,"I2");
          _SFD_SET_DATA_PROPS(10,1,1,0,"P3");
          _SFD_SET_DATA_PROPS(11,1,1,0,"I3");
          _SFD_SET_DATA_PROPS(12,1,1,0,"D");
          _SFD_SET_DATA_PROPS(13,1,1,0,"ErrorSumMax1");
          _SFD_SET_DATA_PROPS(14,1,1,0,"ErrorSumMax2");
          _SFD_SET_DATA_PROPS(15,1,1,0,"ErrorSumMax3");
          _SFD_SET_DATA_PROPS(16,1,1,0,"ErrorPre");
          _SFD_SET_DATA_PROPS(17,1,1,0,"ErrorSumPre");
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
        _SFD_CV_INIT_EML(0,1,1,6,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,912);
        _SFD_CV_INIT_EML_IF(0,1,0,250,268,325,470);
        _SFD_CV_INIT_EML_IF(0,1,1,325,348,406,470);
        _SFD_CV_INIT_EML_IF(0,1,2,472,485,535,560);
        _SFD_CV_INIT_EML_IF(0,1,3,576,601,630,660);
        _SFD_CV_INIT_EML_IF(0,1,4,630,660,-1,660);
        _SFD_CV_INIT_EML_IF(0,1,5,795,808,854,889);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)c20_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)c20_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)c20_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c20_LaterlAngleCommand;
          real_T *c20_SteeringTorqueOut;
          real_T *c20_Error;
          real_T *c20_SAS_SteeringAngle;
          real_T *c20_Ready;
          real_T *c20_ErrorSum;
          real_T *c20_P1;
          real_T *c20_I1;
          real_T *c20_P2;
          real_T *c20_I2;
          real_T *c20_P3;
          real_T *c20_I3;
          real_T *c20_D;
          real_T *c20_ErrorSumMax1;
          real_T *c20_ErrorSumMax2;
          real_T *c20_ErrorSumMax3;
          real_T *c20_ErrorPre;
          real_T *c20_ErrorSumPre;
          c20_ErrorSumPre = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
          c20_ErrorPre = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
          c20_ErrorSumMax3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
          c20_ErrorSumMax2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
          c20_ErrorSumMax1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
          c20_D = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c20_I3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c20_P3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c20_I2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c20_P2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c20_I1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c20_P1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c20_ErrorSum = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c20_Ready = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c20_SAS_SteeringAngle = (real_T *)ssGetInputPortSignal
            (chartInstance->S, 1);
          c20_Error = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c20_SteeringTorqueOut = (real_T *)ssGetOutputPortSignal
            (chartInstance->S, 1);
          c20_LaterlAngleCommand = (real_T *)ssGetInputPortSignal
            (chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c20_LaterlAngleCommand);
          _SFD_SET_DATA_VALUE_PTR(1U, c20_SteeringTorqueOut);
          _SFD_SET_DATA_VALUE_PTR(2U, c20_Error);
          _SFD_SET_DATA_VALUE_PTR(3U, c20_SAS_SteeringAngle);
          _SFD_SET_DATA_VALUE_PTR(4U, c20_Ready);
          _SFD_SET_DATA_VALUE_PTR(5U, c20_ErrorSum);
          _SFD_SET_DATA_VALUE_PTR(6U, c20_P1);
          _SFD_SET_DATA_VALUE_PTR(7U, c20_I1);
          _SFD_SET_DATA_VALUE_PTR(8U, c20_P2);
          _SFD_SET_DATA_VALUE_PTR(9U, c20_I2);
          _SFD_SET_DATA_VALUE_PTR(10U, c20_P3);
          _SFD_SET_DATA_VALUE_PTR(11U, c20_I3);
          _SFD_SET_DATA_VALUE_PTR(12U, c20_D);
          _SFD_SET_DATA_VALUE_PTR(13U, c20_ErrorSumMax1);
          _SFD_SET_DATA_VALUE_PTR(14U, c20_ErrorSumMax2);
          _SFD_SET_DATA_VALUE_PTR(15U, c20_ErrorSumMax3);
          _SFD_SET_DATA_VALUE_PTR(16U, c20_ErrorPre);
          _SFD_SET_DATA_VALUE_PTR(17U, c20_ErrorSumPre);
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
  return "6dwylMeag3BxaPkSFjJO3C";
}

static void sf_opaque_initialize_c20_VCU_CS75_12_27_test_log(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc20_VCU_CS75_12_27_test_logInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c20_VCU_CS75_12_27_test_log
    ((SFc20_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
  initialize_c20_VCU_CS75_12_27_test_log
    ((SFc20_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c20_VCU_CS75_12_27_test_log(void *chartInstanceVar)
{
  enable_c20_VCU_CS75_12_27_test_log
    ((SFc20_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c20_VCU_CS75_12_27_test_log(void *chartInstanceVar)
{
  disable_c20_VCU_CS75_12_27_test_log
    ((SFc20_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c20_VCU_CS75_12_27_test_log(void *chartInstanceVar)
{
  sf_gateway_c20_VCU_CS75_12_27_test_log
    ((SFc20_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c20_VCU_CS75_12_27_test_log
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c20_VCU_CS75_12_27_test_log
    ((SFc20_VCU_CS75_12_27_test_logInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c20_VCU_CS75_12_27_test_log();/* state var info */
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

extern void sf_internal_set_sim_state_c20_VCU_CS75_12_27_test_log(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c20_VCU_CS75_12_27_test_log();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c20_VCU_CS75_12_27_test_log
    ((SFc20_VCU_CS75_12_27_test_logInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c20_VCU_CS75_12_27_test_log
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c20_VCU_CS75_12_27_test_log(S);
}

static void sf_opaque_set_sim_state_c20_VCU_CS75_12_27_test_log(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c20_VCU_CS75_12_27_test_log(S, st);
}

static void sf_opaque_terminate_c20_VCU_CS75_12_27_test_log(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc20_VCU_CS75_12_27_test_logInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_VCU_CS75_12_27_test_log_optimization_info();
    }

    finalize_c20_VCU_CS75_12_27_test_log
      ((SFc20_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc20_VCU_CS75_12_27_test_log
    ((SFc20_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c20_VCU_CS75_12_27_test_log(SimStruct *S)
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
    initialize_params_c20_VCU_CS75_12_27_test_log
      ((SFc20_VCU_CS75_12_27_test_logInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c20_VCU_CS75_12_27_test_log(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_VCU_CS75_12_27_test_log_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      20);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,20,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,20,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,20);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 13, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 14, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,20,15);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,20,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 15; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,20);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3848621327U));
  ssSetChecksum1(S,(719467747U));
  ssSetChecksum2(S,(817470054U));
  ssSetChecksum3(S,(1453347691U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c20_VCU_CS75_12_27_test_log(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c20_VCU_CS75_12_27_test_log(SimStruct *S)
{
  SFc20_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc20_VCU_CS75_12_27_test_logInstanceStruct *)utMalloc(sizeof
    (SFc20_VCU_CS75_12_27_test_logInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc20_VCU_CS75_12_27_test_logInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c20_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c20_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c20_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c20_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c20_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c20_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c20_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c20_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c20_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.mdlStart = mdlStart_c20_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c20_VCU_CS75_12_27_test_log;
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

void c20_VCU_CS75_12_27_test_log_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c20_VCU_CS75_12_27_test_log(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c20_VCU_CS75_12_27_test_log(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c20_VCU_CS75_12_27_test_log(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c20_VCU_CS75_12_27_test_log_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
