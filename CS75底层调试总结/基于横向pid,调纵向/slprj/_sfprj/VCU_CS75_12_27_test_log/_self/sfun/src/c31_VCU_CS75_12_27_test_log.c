/* Include files */

#include <stddef.h>
#include "blas.h"
#include "VCU_CS75_12_27_test_log_sfun.h"
#include "c31_VCU_CS75_12_27_test_log.h"
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
static const char * c31_debug_family_names[20] = { "P", "I", "ErrorSumMax",
  "PID_Torque", "nargin", "nargout", "Ready", "Acc", "AccReal", "P1", "I1", "P2",
  "I2", "ErrorSumMax1", "ErrorSumMax2", "ErrorPre", "ErrorSumPre", "TorqueOut",
  "Error", "ErrorSum" };

/* Function Declarations */
static void initialize_c31_VCU_CS75_12_27_test_log
  (SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void initialize_params_c31_VCU_CS75_12_27_test_log
  (SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void enable_c31_VCU_CS75_12_27_test_log
  (SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void disable_c31_VCU_CS75_12_27_test_log
  (SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void c31_update_debugger_state_c31_VCU_CS75_12_27_test_log
  (SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c31_VCU_CS75_12_27_test_log
  (SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void set_sim_state_c31_VCU_CS75_12_27_test_log
  (SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c31_st);
static void finalize_c31_VCU_CS75_12_27_test_log
  (SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void sf_gateway_c31_VCU_CS75_12_27_test_log
  (SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void initSimStructsc31_VCU_CS75_12_27_test_log
  (SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c31_machineNumber, uint32_T
  c31_chartNumber, uint32_T c31_instanceNumber);
static const mxArray *c31_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData);
static real_T c31_emlrt_marshallIn(SFc31_VCU_CS75_12_27_test_logInstanceStruct
  *chartInstance, const mxArray *c31_ErrorSum, const char_T *c31_identifier);
static real_T c31_b_emlrt_marshallIn(SFc31_VCU_CS75_12_27_test_logInstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId);
static void c31_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData);
static void c31_info_helper(const mxArray **c31_info);
static const mxArray *c31_emlrt_marshallOut(const char * c31_u);
static const mxArray *c31_b_emlrt_marshallOut(const uint32_T c31_u);
static const mxArray *c31_b_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData);
static int32_T c31_c_emlrt_marshallIn
  (SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c31_u, const emlrtMsgIdentifier *c31_parentId);
static void c31_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData);
static uint8_T c31_d_emlrt_marshallIn
  (SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c31_b_is_active_c31_VCU_CS75_12_27_test_log, const char_T *c31_identifier);
static uint8_T c31_e_emlrt_marshallIn
  (SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c31_u, const emlrtMsgIdentifier *c31_parentId);
static void init_dsm_address_info(SFc31_VCU_CS75_12_27_test_logInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c31_VCU_CS75_12_27_test_log
  (SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  chartInstance->c31_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c31_is_active_c31_VCU_CS75_12_27_test_log = 0U;
}

static void initialize_params_c31_VCU_CS75_12_27_test_log
  (SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c31_VCU_CS75_12_27_test_log
  (SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c31_VCU_CS75_12_27_test_log
  (SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c31_update_debugger_state_c31_VCU_CS75_12_27_test_log
  (SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c31_VCU_CS75_12_27_test_log
  (SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  const mxArray *c31_st;
  const mxArray *c31_y = NULL;
  real_T c31_hoistedGlobal;
  real_T c31_u;
  const mxArray *c31_b_y = NULL;
  real_T c31_b_hoistedGlobal;
  real_T c31_b_u;
  const mxArray *c31_c_y = NULL;
  real_T c31_c_hoistedGlobal;
  real_T c31_c_u;
  const mxArray *c31_d_y = NULL;
  uint8_T c31_d_hoistedGlobal;
  uint8_T c31_d_u;
  const mxArray *c31_e_y = NULL;
  real_T *c31_Error;
  real_T *c31_ErrorSum;
  real_T *c31_TorqueOut;
  c31_ErrorSum = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c31_Error = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c31_TorqueOut = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c31_st = NULL;
  c31_st = NULL;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_createcellmatrix(4, 1), false);
  c31_hoistedGlobal = *c31_Error;
  c31_u = c31_hoistedGlobal;
  c31_b_y = NULL;
  sf_mex_assign(&c31_b_y, sf_mex_create("y", &c31_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c31_y, 0, c31_b_y);
  c31_b_hoistedGlobal = *c31_ErrorSum;
  c31_b_u = c31_b_hoistedGlobal;
  c31_c_y = NULL;
  sf_mex_assign(&c31_c_y, sf_mex_create("y", &c31_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c31_y, 1, c31_c_y);
  c31_c_hoistedGlobal = *c31_TorqueOut;
  c31_c_u = c31_c_hoistedGlobal;
  c31_d_y = NULL;
  sf_mex_assign(&c31_d_y, sf_mex_create("y", &c31_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c31_y, 2, c31_d_y);
  c31_d_hoistedGlobal = chartInstance->c31_is_active_c31_VCU_CS75_12_27_test_log;
  c31_d_u = c31_d_hoistedGlobal;
  c31_e_y = NULL;
  sf_mex_assign(&c31_e_y, sf_mex_create("y", &c31_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c31_y, 3, c31_e_y);
  sf_mex_assign(&c31_st, c31_y, false);
  return c31_st;
}

static void set_sim_state_c31_VCU_CS75_12_27_test_log
  (SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c31_st)
{
  const mxArray *c31_u;
  real_T *c31_Error;
  real_T *c31_ErrorSum;
  real_T *c31_TorqueOut;
  c31_ErrorSum = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c31_Error = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c31_TorqueOut = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c31_doneDoubleBufferReInit = true;
  c31_u = sf_mex_dup(c31_st);
  *c31_Error = c31_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c31_u, 0)), "Error");
  *c31_ErrorSum = c31_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c31_u, 1)), "ErrorSum");
  *c31_TorqueOut = c31_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c31_u, 2)), "TorqueOut");
  chartInstance->c31_is_active_c31_VCU_CS75_12_27_test_log =
    c31_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c31_u, 3)),
    "is_active_c31_VCU_CS75_12_27_test_log");
  sf_mex_destroy(&c31_u);
  c31_update_debugger_state_c31_VCU_CS75_12_27_test_log(chartInstance);
  sf_mex_destroy(&c31_st);
}

static void finalize_c31_VCU_CS75_12_27_test_log
  (SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c31_VCU_CS75_12_27_test_log
  (SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  real_T c31_hoistedGlobal;
  real_T c31_b_hoistedGlobal;
  real_T c31_c_hoistedGlobal;
  real_T c31_d_hoistedGlobal;
  real_T c31_e_hoistedGlobal;
  real_T c31_f_hoistedGlobal;
  real_T c31_g_hoistedGlobal;
  real_T c31_h_hoistedGlobal;
  real_T c31_i_hoistedGlobal;
  real_T c31_j_hoistedGlobal;
  real_T c31_k_hoistedGlobal;
  real_T c31_Ready;
  real_T c31_Acc;
  real_T c31_AccReal;
  real_T c31_P1;
  real_T c31_I1;
  real_T c31_P2;
  real_T c31_I2;
  real_T c31_ErrorSumMax1;
  real_T c31_ErrorSumMax2;
  real_T c31_ErrorPre;
  real_T c31_ErrorSumPre;
  uint32_T c31_debug_family_var_map[20];
  real_T c31_P;
  real_T c31_I;
  real_T c31_ErrorSumMax;
  real_T c31_PID_Torque;
  real_T c31_nargin = 11.0;
  real_T c31_nargout = 3.0;
  real_T c31_TorqueOut;
  real_T c31_Error;
  real_T c31_ErrorSum;
  real_T c31_x;
  real_T c31_b_x;
  real_T c31_y;
  real_T *c31_b_Ready;
  real_T *c31_b_TorqueOut;
  real_T *c31_b_Acc;
  real_T *c31_b_AccReal;
  real_T *c31_b_P1;
  real_T *c31_b_I1;
  real_T *c31_b_P2;
  real_T *c31_b_I2;
  real_T *c31_b_ErrorSumMax1;
  real_T *c31_b_ErrorSumMax2;
  real_T *c31_b_ErrorPre;
  real_T *c31_b_ErrorSumPre;
  real_T *c31_b_Error;
  real_T *c31_b_ErrorSum;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c31_b_ErrorSum = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c31_b_Error = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c31_b_ErrorSumPre = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c31_b_ErrorPre = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c31_b_ErrorSumMax2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c31_b_ErrorSumMax1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c31_b_I2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c31_b_P2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c31_b_I1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c31_b_P1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c31_b_AccReal = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c31_b_Acc = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c31_b_TorqueOut = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c31_b_Ready = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 23U, chartInstance->c31_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c31_b_Ready, 0U);
  chartInstance->c31_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 23U, chartInstance->c31_sfEvent);
  c31_hoistedGlobal = *c31_b_Ready;
  c31_b_hoistedGlobal = *c31_b_Acc;
  c31_c_hoistedGlobal = *c31_b_AccReal;
  c31_d_hoistedGlobal = *c31_b_P1;
  c31_e_hoistedGlobal = *c31_b_I1;
  c31_f_hoistedGlobal = *c31_b_P2;
  c31_g_hoistedGlobal = *c31_b_I2;
  c31_h_hoistedGlobal = *c31_b_ErrorSumMax1;
  c31_i_hoistedGlobal = *c31_b_ErrorSumMax2;
  c31_j_hoistedGlobal = *c31_b_ErrorPre;
  c31_k_hoistedGlobal = *c31_b_ErrorSumPre;
  c31_Ready = c31_hoistedGlobal;
  c31_Acc = c31_b_hoistedGlobal;
  c31_AccReal = c31_c_hoistedGlobal;
  c31_P1 = c31_d_hoistedGlobal;
  c31_I1 = c31_e_hoistedGlobal;
  c31_P2 = c31_f_hoistedGlobal;
  c31_I2 = c31_g_hoistedGlobal;
  c31_ErrorSumMax1 = c31_h_hoistedGlobal;
  c31_ErrorSumMax2 = c31_i_hoistedGlobal;
  c31_ErrorPre = c31_j_hoistedGlobal;
  c31_ErrorSumPre = c31_k_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 20U, 20U, c31_debug_family_names,
    c31_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_P, 0U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_I, 1U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_ErrorSumMax, 2U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_PID_Torque, 3U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_nargin, 4U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_nargout, 5U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c31_Ready, 6U, c31_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c31_Acc, 7U, c31_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c31_AccReal, 8U, c31_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c31_P1, 9U, c31_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c31_I1, 10U, c31_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c31_P2, 11U, c31_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c31_I2, 12U, c31_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c31_ErrorSumMax1, 13U, c31_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c31_ErrorSumMax2, 14U, c31_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c31_ErrorPre, 15U, c31_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c31_ErrorSumPre, 16U, c31_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_TorqueOut, 17U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_Error, 18U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_ErrorSum, 19U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 3);
  c31_Error = c31_Acc - c31_AccReal;
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 4);
  c31_x = c31_Error;
  c31_b_x = c31_x;
  c31_y = muDoubleScalarAbs(c31_b_x);
  if (CV_EML_IF(0, 1, 0, c31_y < 250.0)) {
    _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 5);
    c31_P = c31_P1;
    _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 6);
    c31_I = c31_I1;
    _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 7);
    c31_ErrorSumMax = c31_ErrorSumMax1;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 9);
    c31_P = c31_P2;
    _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 10);
    c31_I = c31_I2;
    _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 11);
    c31_ErrorSumMax = c31_ErrorSumMax2;
  }

  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 14);
  guard2 = false;
  if (CV_EML_COND(0, 1, 0, c31_Ready == 1.0)) {
    if (CV_EML_COND(0, 1, 1, c31_Acc > 0.0)) {
      CV_EML_MCDC(0, 1, 0, true);
      CV_EML_IF(0, 1, 1, true);
      _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 15);
      c31_ErrorSum = c31_ErrorSumPre + c31_Error;
    } else {
      guard2 = true;
    }
  } else {
    guard2 = true;
  }

  if (guard2 == true) {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 1, false);
    _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 17);
    c31_ErrorSum = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 21);
  if (CV_EML_IF(0, 1, 2, c31_ErrorSum > c31_ErrorSumMax)) {
    _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 22);
    c31_ErrorSum = c31_ErrorSumMax;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 23);
    if (CV_EML_IF(0, 1, 3, c31_ErrorSum < -c31_ErrorSumMax)) {
      _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 24);
      c31_ErrorSum = -c31_ErrorSumMax;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 28);
  c31_PID_Torque = c31_P * c31_Error + c31_I * c31_ErrorSum;
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 31);
  guard1 = false;
  if (CV_EML_COND(0, 1, 2, c31_Ready == 1.0)) {
    if (CV_EML_COND(0, 1, 3, c31_Acc > 0.0)) {
      CV_EML_MCDC(0, 1, 1, true);
      CV_EML_IF(0, 1, 4, true);
      _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 32);
      c31_TorqueOut = c31_PID_Torque;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 1, false);
    CV_EML_IF(0, 1, 4, false);
    _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 34);
    c31_TorqueOut = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, -34);
  _SFD_SYMBOL_SCOPE_POP();
  *c31_b_TorqueOut = c31_TorqueOut;
  *c31_b_Error = c31_Error;
  *c31_b_ErrorSum = c31_ErrorSum;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 23U, chartInstance->c31_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_VCU_CS75_12_27_test_logMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c31_b_TorqueOut, 1U);
  _SFD_DATA_RANGE_CHECK(*c31_b_Acc, 2U);
  _SFD_DATA_RANGE_CHECK(*c31_b_AccReal, 3U);
  _SFD_DATA_RANGE_CHECK(*c31_b_P1, 4U);
  _SFD_DATA_RANGE_CHECK(*c31_b_I1, 5U);
  _SFD_DATA_RANGE_CHECK(*c31_b_P2, 6U);
  _SFD_DATA_RANGE_CHECK(*c31_b_I2, 7U);
  _SFD_DATA_RANGE_CHECK(*c31_b_ErrorSumMax1, 8U);
  _SFD_DATA_RANGE_CHECK(*c31_b_ErrorSumMax2, 9U);
  _SFD_DATA_RANGE_CHECK(*c31_b_ErrorPre, 10U);
  _SFD_DATA_RANGE_CHECK(*c31_b_ErrorSumPre, 11U);
  _SFD_DATA_RANGE_CHECK(*c31_b_Error, 12U);
  _SFD_DATA_RANGE_CHECK(*c31_b_ErrorSum, 13U);
}

static void initSimStructsc31_VCU_CS75_12_27_test_log
  (SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c31_machineNumber, uint32_T
  c31_chartNumber, uint32_T c31_instanceNumber)
{
  (void)c31_machineNumber;
  (void)c31_chartNumber;
  (void)c31_instanceNumber;
}

static const mxArray *c31_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData)
{
  const mxArray *c31_mxArrayOutData = NULL;
  real_T c31_u;
  const mxArray *c31_y = NULL;
  SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
  chartInstance = (SFc31_VCU_CS75_12_27_test_logInstanceStruct *)
    chartInstanceVoid;
  c31_mxArrayOutData = NULL;
  c31_u = *(real_T *)c31_inData;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", &c31_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c31_mxArrayOutData, c31_y, false);
  return c31_mxArrayOutData;
}

static real_T c31_emlrt_marshallIn(SFc31_VCU_CS75_12_27_test_logInstanceStruct
  *chartInstance, const mxArray *c31_ErrorSum, const char_T *c31_identifier)
{
  real_T c31_y;
  emlrtMsgIdentifier c31_thisId;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_y = c31_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_ErrorSum),
    &c31_thisId);
  sf_mex_destroy(&c31_ErrorSum);
  return c31_y;
}

static real_T c31_b_emlrt_marshallIn(SFc31_VCU_CS75_12_27_test_logInstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId)
{
  real_T c31_y;
  real_T c31_d0;
  (void)chartInstance;
  sf_mex_import(c31_parentId, sf_mex_dup(c31_u), &c31_d0, 1, 0, 0U, 0, 0U, 0);
  c31_y = c31_d0;
  sf_mex_destroy(&c31_u);
  return c31_y;
}

static void c31_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData)
{
  const mxArray *c31_ErrorSum;
  const char_T *c31_identifier;
  emlrtMsgIdentifier c31_thisId;
  real_T c31_y;
  SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
  chartInstance = (SFc31_VCU_CS75_12_27_test_logInstanceStruct *)
    chartInstanceVoid;
  c31_ErrorSum = sf_mex_dup(c31_mxArrayInData);
  c31_identifier = c31_varName;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_y = c31_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_ErrorSum),
    &c31_thisId);
  sf_mex_destroy(&c31_ErrorSum);
  *(real_T *)c31_outData = c31_y;
  sf_mex_destroy(&c31_mxArrayInData);
}

const mxArray *sf_c31_VCU_CS75_12_27_test_log_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c31_nameCaptureInfo = NULL;
  c31_nameCaptureInfo = NULL;
  sf_mex_assign(&c31_nameCaptureInfo, sf_mex_createstruct("structure", 2, 3, 1),
                false);
  c31_info_helper(&c31_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c31_nameCaptureInfo);
  return c31_nameCaptureInfo;
}

static void c31_info_helper(const mxArray **c31_info)
{
  const mxArray *c31_rhs0 = NULL;
  const mxArray *c31_lhs0 = NULL;
  const mxArray *c31_rhs1 = NULL;
  const mxArray *c31_lhs1 = NULL;
  const mxArray *c31_rhs2 = NULL;
  const mxArray *c31_lhs2 = NULL;
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("abs"), "name", "name", 0);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1363717452U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c31_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c31_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 2);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1286825912U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c31_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs2), "lhs", "lhs",
                  2);
  sf_mex_destroy(&c31_rhs0);
  sf_mex_destroy(&c31_lhs0);
  sf_mex_destroy(&c31_rhs1);
  sf_mex_destroy(&c31_lhs1);
  sf_mex_destroy(&c31_rhs2);
  sf_mex_destroy(&c31_lhs2);
}

static const mxArray *c31_emlrt_marshallOut(const char * c31_u)
{
  const mxArray *c31_y = NULL;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", c31_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c31_u)), false);
  return c31_y;
}

static const mxArray *c31_b_emlrt_marshallOut(const uint32_T c31_u)
{
  const mxArray *c31_y = NULL;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", &c31_u, 7, 0U, 0U, 0U, 0), false);
  return c31_y;
}

static const mxArray *c31_b_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData)
{
  const mxArray *c31_mxArrayOutData = NULL;
  int32_T c31_u;
  const mxArray *c31_y = NULL;
  SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
  chartInstance = (SFc31_VCU_CS75_12_27_test_logInstanceStruct *)
    chartInstanceVoid;
  c31_mxArrayOutData = NULL;
  c31_u = *(int32_T *)c31_inData;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", &c31_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c31_mxArrayOutData, c31_y, false);
  return c31_mxArrayOutData;
}

static int32_T c31_c_emlrt_marshallIn
  (SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c31_u, const emlrtMsgIdentifier *c31_parentId)
{
  int32_T c31_y;
  int32_T c31_i0;
  (void)chartInstance;
  sf_mex_import(c31_parentId, sf_mex_dup(c31_u), &c31_i0, 1, 6, 0U, 0, 0U, 0);
  c31_y = c31_i0;
  sf_mex_destroy(&c31_u);
  return c31_y;
}

static void c31_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData)
{
  const mxArray *c31_b_sfEvent;
  const char_T *c31_identifier;
  emlrtMsgIdentifier c31_thisId;
  int32_T c31_y;
  SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
  chartInstance = (SFc31_VCU_CS75_12_27_test_logInstanceStruct *)
    chartInstanceVoid;
  c31_b_sfEvent = sf_mex_dup(c31_mxArrayInData);
  c31_identifier = c31_varName;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_y = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_b_sfEvent),
    &c31_thisId);
  sf_mex_destroy(&c31_b_sfEvent);
  *(int32_T *)c31_outData = c31_y;
  sf_mex_destroy(&c31_mxArrayInData);
}

static uint8_T c31_d_emlrt_marshallIn
  (SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c31_b_is_active_c31_VCU_CS75_12_27_test_log, const char_T *c31_identifier)
{
  uint8_T c31_y;
  emlrtMsgIdentifier c31_thisId;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_y = c31_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c31_b_is_active_c31_VCU_CS75_12_27_test_log), &c31_thisId);
  sf_mex_destroy(&c31_b_is_active_c31_VCU_CS75_12_27_test_log);
  return c31_y;
}

static uint8_T c31_e_emlrt_marshallIn
  (SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance, const mxArray
   *c31_u, const emlrtMsgIdentifier *c31_parentId)
{
  uint8_T c31_y;
  uint8_T c31_u0;
  (void)chartInstance;
  sf_mex_import(c31_parentId, sf_mex_dup(c31_u), &c31_u0, 1, 3, 0U, 0, 0U, 0);
  c31_y = c31_u0;
  sf_mex_destroy(&c31_u);
  return c31_y;
}

static void init_dsm_address_info(SFc31_VCU_CS75_12_27_test_logInstanceStruct
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

void sf_c31_VCU_CS75_12_27_test_log_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4123021829U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3821630311U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1105974058U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4232118534U);
}

mxArray *sf_c31_VCU_CS75_12_27_test_log_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Q9w3Gta4BYc6zbsudqoawE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,11,3,dataFields);

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

mxArray *sf_c31_VCU_CS75_12_27_test_log_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c31_VCU_CS75_12_27_test_log_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c31_VCU_CS75_12_27_test_log(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[15],T\"Error\",},{M[1],M[16],T\"ErrorSum\",},{M[1],M[5],T\"TorqueOut\",},{M[8],M[0],T\"is_active_c31_VCU_CS75_12_27_test_log\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c31_VCU_CS75_12_27_test_log_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc31_VCU_CS75_12_27_test_logInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _VCU_CS75_12_27_test_logMachineNumber_,
           31,
           1,
           1,
           0,
           14,
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
          _SFD_SET_DATA_PROPS(1,2,0,1,"TorqueOut");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Acc");
          _SFD_SET_DATA_PROPS(3,1,1,0,"AccReal");
          _SFD_SET_DATA_PROPS(4,1,1,0,"P1");
          _SFD_SET_DATA_PROPS(5,1,1,0,"I1");
          _SFD_SET_DATA_PROPS(6,1,1,0,"P2");
          _SFD_SET_DATA_PROPS(7,1,1,0,"I2");
          _SFD_SET_DATA_PROPS(8,1,1,0,"ErrorSumMax1");
          _SFD_SET_DATA_PROPS(9,1,1,0,"ErrorSumMax2");
          _SFD_SET_DATA_PROPS(10,1,1,0,"ErrorPre");
          _SFD_SET_DATA_PROPS(11,1,1,0,"ErrorSumPre");
          _SFD_SET_DATA_PROPS(12,2,0,1,"Error");
          _SFD_SET_DATA_PROPS(13,2,0,1,"ErrorSum");
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
        _SFD_CV_INIT_EML(0,1,1,5,0,0,0,0,0,4,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,718);
        _SFD_CV_INIT_EML_IF(0,1,0,169,188,245,309);
        _SFD_CV_INIT_EML_IF(0,1,1,311,335,385,410);
        _SFD_CV_INIT_EML_IF(0,1,2,426,451,480,510);
        _SFD_CV_INIT_EML_IF(0,1,3,480,510,-1,510);
        _SFD_CV_INIT_EML_IF(0,1,4,615,638,668,695);

        {
          static int condStart[] = { 314, 328 };

          static int condEnd[] = { 324, 335 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,314,335,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 618, 632 };

          static int condEnd[] = { 628, 638 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,618,638,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)c31_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)c31_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)c31_sf_marshallIn);

        {
          real_T *c31_Ready;
          real_T *c31_TorqueOut;
          real_T *c31_Acc;
          real_T *c31_AccReal;
          real_T *c31_P1;
          real_T *c31_I1;
          real_T *c31_P2;
          real_T *c31_I2;
          real_T *c31_ErrorSumMax1;
          real_T *c31_ErrorSumMax2;
          real_T *c31_ErrorPre;
          real_T *c31_ErrorSumPre;
          real_T *c31_Error;
          real_T *c31_ErrorSum;
          c31_ErrorSum = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c31_Error = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c31_ErrorSumPre = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
          c31_ErrorPre = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c31_ErrorSumMax2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c31_ErrorSumMax1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c31_I2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c31_P2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c31_I1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c31_P1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c31_AccReal = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c31_Acc = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c31_TorqueOut = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c31_Ready = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c31_Ready);
          _SFD_SET_DATA_VALUE_PTR(1U, c31_TorqueOut);
          _SFD_SET_DATA_VALUE_PTR(2U, c31_Acc);
          _SFD_SET_DATA_VALUE_PTR(3U, c31_AccReal);
          _SFD_SET_DATA_VALUE_PTR(4U, c31_P1);
          _SFD_SET_DATA_VALUE_PTR(5U, c31_I1);
          _SFD_SET_DATA_VALUE_PTR(6U, c31_P2);
          _SFD_SET_DATA_VALUE_PTR(7U, c31_I2);
          _SFD_SET_DATA_VALUE_PTR(8U, c31_ErrorSumMax1);
          _SFD_SET_DATA_VALUE_PTR(9U, c31_ErrorSumMax2);
          _SFD_SET_DATA_VALUE_PTR(10U, c31_ErrorPre);
          _SFD_SET_DATA_VALUE_PTR(11U, c31_ErrorSumPre);
          _SFD_SET_DATA_VALUE_PTR(12U, c31_Error);
          _SFD_SET_DATA_VALUE_PTR(13U, c31_ErrorSum);
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
  return "y6Fy0urcyzSzgY4llQpRJE";
}

static void sf_opaque_initialize_c31_VCU_CS75_12_27_test_log(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc31_VCU_CS75_12_27_test_logInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c31_VCU_CS75_12_27_test_log
    ((SFc31_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
  initialize_c31_VCU_CS75_12_27_test_log
    ((SFc31_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c31_VCU_CS75_12_27_test_log(void *chartInstanceVar)
{
  enable_c31_VCU_CS75_12_27_test_log
    ((SFc31_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c31_VCU_CS75_12_27_test_log(void *chartInstanceVar)
{
  disable_c31_VCU_CS75_12_27_test_log
    ((SFc31_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c31_VCU_CS75_12_27_test_log(void *chartInstanceVar)
{
  sf_gateway_c31_VCU_CS75_12_27_test_log
    ((SFc31_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c31_VCU_CS75_12_27_test_log
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c31_VCU_CS75_12_27_test_log
    ((SFc31_VCU_CS75_12_27_test_logInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c31_VCU_CS75_12_27_test_log();/* state var info */
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

extern void sf_internal_set_sim_state_c31_VCU_CS75_12_27_test_log(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c31_VCU_CS75_12_27_test_log();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c31_VCU_CS75_12_27_test_log
    ((SFc31_VCU_CS75_12_27_test_logInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c31_VCU_CS75_12_27_test_log
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c31_VCU_CS75_12_27_test_log(S);
}

static void sf_opaque_set_sim_state_c31_VCU_CS75_12_27_test_log(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c31_VCU_CS75_12_27_test_log(S, st);
}

static void sf_opaque_terminate_c31_VCU_CS75_12_27_test_log(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc31_VCU_CS75_12_27_test_logInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_VCU_CS75_12_27_test_log_optimization_info();
    }

    finalize_c31_VCU_CS75_12_27_test_log
      ((SFc31_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc31_VCU_CS75_12_27_test_log
    ((SFc31_VCU_CS75_12_27_test_logInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c31_VCU_CS75_12_27_test_log(SimStruct *S)
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
    initialize_params_c31_VCU_CS75_12_27_test_log
      ((SFc31_VCU_CS75_12_27_test_logInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c31_VCU_CS75_12_27_test_log(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_VCU_CS75_12_27_test_log_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      31);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,31,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,31,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,31);
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,31,11);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,31,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 11; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,31);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3368285056U));
  ssSetChecksum1(S,(3683900332U));
  ssSetChecksum2(S,(246914415U));
  ssSetChecksum3(S,(2799167010U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c31_VCU_CS75_12_27_test_log(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c31_VCU_CS75_12_27_test_log(SimStruct *S)
{
  SFc31_VCU_CS75_12_27_test_logInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc31_VCU_CS75_12_27_test_logInstanceStruct *)utMalloc(sizeof
    (SFc31_VCU_CS75_12_27_test_logInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc31_VCU_CS75_12_27_test_logInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c31_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c31_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c31_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c31_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c31_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c31_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c31_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c31_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c31_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.mdlStart = mdlStart_c31_VCU_CS75_12_27_test_log;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c31_VCU_CS75_12_27_test_log;
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

void c31_VCU_CS75_12_27_test_log_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c31_VCU_CS75_12_27_test_log(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c31_VCU_CS75_12_27_test_log(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c31_VCU_CS75_12_27_test_log(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c31_VCU_CS75_12_27_test_log_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
