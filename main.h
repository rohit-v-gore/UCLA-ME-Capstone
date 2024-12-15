/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: main.h
 *
 * Code generated for Simulink model 'main'.
 *
 * Model version                  : 1.66
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Jun 10 22:53:53 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_main_h_
#define RTW_HEADER_main_h_
#ifndef main_COMMON_INCLUDES_
#define main_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* main_COMMON_INCLUDES_ */

#include "main_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T left_counter;                 /* '<Root>/Chart' */
  real_T drop_check;                   /* '<Root>/Chart' */
  uint8_T is_c3_main;                  /* '<Root>/Chart' */
  uint8_T is_active_c3_main;           /* '<Root>/Chart' */
} DW_main_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T IR_sensor_M;                  /* '<Root>/IR_sensor_M' */
  real_T IR_sensor_L;                  /* '<Root>/IR_sensor_L' */
  real_T IR_sensor_R;                  /* '<Root>/IR_sensor_R' */
  real_T IR_sensor_FL;                 /* '<Root>/IR_sensor_FL' */
  real_T IR_sensor_FR;                 /* '<Root>/IR_sensor_FR' */
  real_T US_sensor;                    /* '<Root>/US_sensor' */
  real_T input1;                       /* '<Root>/input1' */
  real_T input2;                       /* '<Root>/input2' */
  real_T fwd_spd;                      /* '<Root>/fwd_spd' */
  real_T turn_spd;                     /* '<Root>/turn_spd' */
  real_T fwd_spd_pickup;               /* '<Root>/fwd_spd_pickup' */
  real_T turn_spd_pickup;              /* '<Root>/turn_spd_pickup' */
  real_T IR_Distance;                  /* '<Root>/IR_Distance' */
} ExtU_main_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T motEN;                        /* '<Root>/motEN' */
  real_T dirMA;                        /* '<Root>/dirMA' */
  real_T dirMB;                        /* '<Root>/dirMB' */
  real_T PWMA;                         /* '<Root>/PWMA' */
  real_T PWMB;                         /* '<Root>/PWMB' */
  real_T testOutput;                   /* '<Root>/testOutput' */
  real_T grabbing;                     /* '<Root>/grabbing' */
  real_T err;                          /* '<Root>/err' */
  real_T exitpickup_counter;           /* '<Root>/exitpickup_counter' */
  real_T dropoff_counter;              /* '<Root>/dropoff_counter' */
} ExtY_main_T;

/* Real-time Model Data Structure */
struct tag_RTM_main_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_main_T main_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_main_T main_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_main_T main_Y;

/* Model entry point functions */
extern void main_initialize(void);
extern void main_step(void);
extern void main_terminate(void);

/* Real-time Model object */
extern RT_MODEL_main_T *const main_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'main'
 * '<S1>'   : 'main/Chart'
 */
#endif                                 /* RTW_HEADER_main_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
