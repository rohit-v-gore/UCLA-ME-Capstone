/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: main.c
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

#include "main.h"
#include "rtwtypes.h"

/* Named constants for Chart: '<Root>/Chart' */
#define main_IN_DROPOFFZONE            ((uint8_T)1U)
#define main_IN_DROPZONE               ((uint8_T)2U)
#define main_IN_FORWARD                ((uint8_T)3U)
#define main_IN_FORWARDDELAY           ((uint8_T)4U)
#define main_IN_FORWARDDELAY1          ((uint8_T)5U)
#define main_IN_FORWARDDELAY3          ((uint8_T)6U)
#define main_IN_FORWARDDROPOFF         ((uint8_T)7U)
#define main_IN_FOWARDDELAY2           ((uint8_T)8U)
#define main_IN_GRABBING               ((uint8_T)9U)
#define main_IN_HARDLEFT1              ((uint8_T)10U)
#define main_IN_HARDLEFT_DROPOFF       ((uint8_T)11U)
#define main_IN_HARDLEFT_PICKUP        ((uint8_T)12U)
#define main_IN_HARDLEFT_PICKUP1       ((uint8_T)13U)
#define main_IN_HARDRIGHT_DROPOFF      ((uint8_T)14U)
#define main_IN_HARDRIGHT_PICKUP       ((uint8_T)15U)
#define main_IN_HARDRIGHT_PICKUP1      ((uint8_T)16U)
#define main_IN_IDLE                   ((uint8_T)17U)
#define main_IN_LINEUPREV              ((uint8_T)18U)
#define main_IN_PAUSE                  ((uint8_T)19U)
#define main_IN_PICKUPFORWARD          ((uint8_T)20U)
#define main_IN_PICKUPZONE             ((uint8_T)21U)
#define main_IN_PICKUPZONE1            ((uint8_T)22U)
#define main_IN_PICKUPZONE2            ((uint8_T)23U)
#define main_IN_REVERSE                ((uint8_T)24U)
#define main_IN_REVERSE1               ((uint8_T)25U)
#define main_IN_STEERLEFT              ((uint8_T)26U)
#define main_IN_STEERLEFT1             ((uint8_T)27U)
#define main_IN_STEERRIGHT             ((uint8_T)28U)
#define main_IN_STEERRIGHT1            ((uint8_T)29U)
#define main_IN_STOP                   ((uint8_T)30U)
#define main_IN_STOP_PICKUP            ((uint8_T)31U)

/* Block states (default storage) */
DW_main_T main_DW;

/* External inputs (root inport signals with default storage) */
ExtU_main_T main_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_main_T main_Y;

/* Real-time model */
static RT_MODEL_main_T main_M_;
RT_MODEL_main_T *const main_M = &main_M_;

/* Forward declaration for local functions */
static void main_STOP_PICKUP(void);
static void main_DROPOFFZONE(void);
static void main_FORWARD(void);
static void ma_enter_atomic_HARDLEFT_PICKUP(void);
static void m_enter_atomic_HARDRIGHT_PICKUP(void);
static void main_HARDLEFT_PICKUP(void);
static void main_HARDRIGHT_PICKUP(void);
static void main_IDLE(void);
static void main_PICKUPFORWARD(void);
static void main_PICKUPZONE(void);
static void main_REVERSE(void);
static void main_STEERLEFT(void);
static void main_STEERLEFT1(void);
static void main_STEERRIGHT(void);
static void main_STEERRIGHT1(void);
static void main_STOP(void);

/* Function for Chart: '<Root>/Chart' */
static void main_STOP_PICKUP(void)
{
  /* Outport: '<Root>/grabbing' */
  main_Y.grabbing = 1.0;

  /* Inport: '<Root>/IR_sensor_M' incorporates:
   *  Inport: '<Root>/IR_Distance'
   *  Inport: '<Root>/IR_sensor_L'
   *  Inport: '<Root>/IR_sensor_R'
   */
  if ((main_U.IR_sensor_M > 805.0) && (main_U.IR_sensor_R > 780.0) &&
      (main_U.IR_sensor_L > 805.0)) {
    main_DW.is_c3_main = main_IN_GRABBING;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 22.0;

    /* Outport: '<Root>/motEN' */
    main_Y.motEN = 0.0;

    /* Outport: '<Root>/dirMA' */
    main_Y.dirMA = 1.0;

    /* Outport: '<Root>/dirMB' */
    main_Y.dirMB = 1.0;

    /* Outport: '<Root>/PWMA' */
    main_Y.PWMA = 0.0;

    /* Outport: '<Root>/PWMB' */
    main_Y.PWMB = 0.0;
  } else if (((main_U.IR_Distance < 900.0) && ((main_U.IR_sensor_M < 805.0) ||
               (main_U.IR_sensor_R < 780.0) || (main_U.IR_sensor_L < 805.0))) ||
             ((main_U.IR_sensor_M < 805.0) && (main_U.IR_sensor_R < 780.0) &&
              (main_U.IR_sensor_L < 805.0))) {
    main_DW.is_c3_main = main_IN_LINEUPREV;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 18.0;
  } else {
    /* Outport: '<Root>/motEN' */
    main_Y.motEN = 1.0;

    /* Outport: '<Root>/dirMA' */
    main_Y.dirMA = 1.0;

    /* Outport: '<Root>/dirMB' */
    main_Y.dirMB = 1.0;

    /* Outport: '<Root>/PWMA' */
    main_Y.PWMA = 0.0;

    /* Outport: '<Root>/PWMB' */
    main_Y.PWMB = 0.0;
  }

  /* End of Inport: '<Root>/IR_sensor_M' */
}

/* Function for Chart: '<Root>/Chart' */
static void main_DROPOFFZONE(void)
{
  /* Outport: '<Root>/dropoff_counter' incorporates:
   *  Inport: '<Root>/fwd_spd'
   *  Inport: '<Root>/input2'
   *  Inport: '<Root>/turn_spd_pickup'
   *  Outport: '<Root>/PWMA'
   *  Outport: '<Root>/PWMB'
   *  Outport: '<Root>/dirMA'
   *  Outport: '<Root>/dirMB'
   *  Outport: '<Root>/motEN'
   *  Outport: '<Root>/testOutput'
   */
  if (main_Y.dropoff_counter == main_U.input2) {
    main_DW.is_c3_main = main_IN_HARDRIGHT_DROPOFF;
    main_Y.testOutput = 20.0;
    main_Y.motEN = 1.0;
    main_Y.dirMA = 0.0;
    main_Y.dirMB = 1.0;
    main_Y.PWMA = main_U.turn_spd_pickup;
    main_Y.PWMB = 0.9 * main_U.turn_spd_pickup;
    main_DW.drop_check = 1.0;
  } else if (main_Y.dropoff_counter != main_U.input2) {
    main_DW.is_c3_main = main_IN_FORWARDDROPOFF;
    main_Y.testOutput = 15.0;
    main_Y.motEN = 1.0;
    main_Y.dirMA = 0.0;
    main_Y.dirMB = 0.0;
    main_Y.PWMA = main_U.fwd_spd;
    main_Y.PWMB = main_U.fwd_spd;
  } else {
    main_Y.testOutput = 100.0;
    main_Y.motEN = 1.0;
    main_Y.dirMA = 1.0;
    main_Y.dirMB = 1.0;
    main_Y.PWMA = 0.0;
    main_Y.PWMB = 0.0;
  }

  /* End of Outport: '<Root>/dropoff_counter' */
}

/* Function for Chart: '<Root>/Chart' */
static void main_FORWARD(void)
{
  /* Inport: '<Root>/IR_sensor_L' incorporates:
   *  Inport: '<Root>/IR_Distance'
   *  Inport: '<Root>/IR_sensor_FL'
   *  Inport: '<Root>/IR_sensor_FR'
   *  Inport: '<Root>/IR_sensor_M'
   *  Inport: '<Root>/IR_sensor_R'
   *  Outport: '<Root>/exitpickup_counter'
   */
  if ((main_U.IR_sensor_L >= 750.0) && (main_U.IR_sensor_R < 750.0) &&
      (main_U.IR_sensor_M >= 750.0)) {
    main_DW.is_c3_main = main_IN_STEERLEFT;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 2.0;
  } else if ((main_U.IR_sensor_L < 750.0) && (main_U.IR_sensor_R >= 750.0) &&
             (main_U.IR_sensor_M >= 750.0)) {
    main_DW.is_c3_main = main_IN_STEERRIGHT;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 3.0;
  } else if (main_U.IR_Distance < 825.0) {
    main_DW.is_c3_main = main_IN_STOP;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 6.0;
  } else if ((main_U.IR_sensor_FL == 0.0) && (main_U.IR_sensor_FR == 1.0) &&
             ((main_DW.left_counter == 0.0) || (main_Y.exitpickup_counter >= 3.0)))
  {
    main_DW.is_c3_main = main_IN_HARDLEFT1;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 5.0;
  } else if ((main_U.IR_sensor_FR == 0.0) && (main_Y.exitpickup_counter < 3.0))
  {
    main_DW.is_c3_main = main_IN_PICKUPZONE;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 7.0;

    /* Outport: '<Root>/motEN' */
    main_Y.motEN = 1.0;

    /* Outport: '<Root>/dirMA' */
    main_Y.dirMA = 1.0;

    /* Outport: '<Root>/dirMB' */
    main_Y.dirMB = 1.0;

    /* Outport: '<Root>/PWMA' */
    main_Y.PWMA = 0.0;

    /* Outport: '<Root>/PWMB' */
    main_Y.PWMB = 0.0;
  } else if ((main_U.IR_sensor_FR == 0.0) && (main_Y.exitpickup_counter == 3.0) &&
             (main_DW.drop_check == 0.0)) {
    main_DW.is_c3_main = main_IN_DROPOFFZONE;

    /* Outport: '<Root>/dropoff_counter' */
    main_Y.dropoff_counter++;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 19.0;

    /* Outport: '<Root>/motEN' */
    main_Y.motEN = 1.0;

    /* Outport: '<Root>/dirMA' */
    main_Y.dirMA = 1.0;

    /* Outport: '<Root>/dirMB' */
    main_Y.dirMB = 1.0;

    /* Outport: '<Root>/PWMA' */
    main_Y.PWMA = 0.0;

    /* Outport: '<Root>/PWMB' */
    main_Y.PWMB = 0.0;
  } else {
    /* Outport: '<Root>/motEN' */
    main_Y.motEN = 1.0;

    /* Outport: '<Root>/dirMA' */
    main_Y.dirMA = 0.0;

    /* Outport: '<Root>/dirMB' */
    main_Y.dirMB = 0.0;

    /* Outport: '<Root>/err' */
    main_Y.err = main_U.IR_sensor_L - main_U.IR_sensor_R;

    /* Outport: '<Root>/PWMA' incorporates:
     *  Inport: '<Root>/fwd_spd'
     *  Outport: '<Root>/err'
     */
    main_Y.PWMA = 0.3 * main_Y.err + main_U.fwd_spd;

    /* Outport: '<Root>/PWMB' incorporates:
     *  Inport: '<Root>/fwd_spd'
     *  Outport: '<Root>/err'
     */
    main_Y.PWMB = main_U.fwd_spd - 0.3 * main_Y.err;
  }

  /* End of Inport: '<Root>/IR_sensor_L' */
}

/* Function for Chart: '<Root>/Chart' */
static void ma_enter_atomic_HARDLEFT_PICKUP(void)
{
  /* Outport: '<Root>/testOutput' */
  main_Y.testOutput = 9.0;

  /* Outport: '<Root>/exitpickup_counter' incorporates:
   *  Inport: '<Root>/turn_spd_pickup'
   *  Outport: '<Root>/PWMA'
   *  Outport: '<Root>/PWMB'
   *  Outport: '<Root>/dirMA'
   *  Outport: '<Root>/dirMB'
   *  Outport: '<Root>/motEN'
   */
  if (main_Y.exitpickup_counter == 0.0) {
    main_Y.motEN = 1.0;
    main_Y.dirMA = 1.0;
    main_Y.dirMB = 0.0;
    main_Y.PWMA = 0.85 * main_U.turn_spd_pickup;
    main_Y.PWMB = main_U.turn_spd_pickup;
  } else {
    main_Y.motEN = 1.0;
    main_Y.dirMA = 1.0;
    main_Y.dirMB = 0.0;
    main_Y.PWMA = 0.75 * main_U.turn_spd_pickup;
    main_Y.PWMB = main_U.turn_spd_pickup;
  }

  /* End of Outport: '<Root>/exitpickup_counter' */
}

/* Function for Chart: '<Root>/Chart' */
static void m_enter_atomic_HARDRIGHT_PICKUP(void)
{
  /* Outport: '<Root>/testOutput' */
  main_Y.testOutput = 8.0;

  /* Outport: '<Root>/exitpickup_counter' incorporates:
   *  Inport: '<Root>/turn_spd_pickup'
   *  Outport: '<Root>/PWMA'
   *  Outport: '<Root>/PWMB'
   *  Outport: '<Root>/dirMA'
   *  Outport: '<Root>/dirMB'
   *  Outport: '<Root>/motEN'
   */
  if (main_Y.exitpickup_counter == 0.0) {
    main_Y.motEN = 1.0;
    main_Y.dirMA = 0.0;
    main_Y.dirMB = 1.0;
    main_Y.PWMA = 0.9 * main_U.turn_spd_pickup;
    main_Y.PWMB = main_U.turn_spd_pickup;
  } else {
    main_Y.motEN = 1.0;
    main_Y.dirMA = 0.0;
    main_Y.dirMB = 1.0;
    main_Y.PWMA = main_U.turn_spd_pickup;
    main_Y.PWMB = 0.8 * main_U.turn_spd_pickup;
  }

  /* End of Outport: '<Root>/exitpickup_counter' */
}

/* Function for Chart: '<Root>/Chart' */
static void main_HARDLEFT_PICKUP(void)
{
  /* Inport: '<Root>/IR_sensor_R' incorporates:
   *  Inport: '<Root>/IR_sensor_FL'
   *  Inport: '<Root>/IR_sensor_FR'
   */
  if ((main_U.IR_sensor_R > 815.0) && (main_U.IR_sensor_FR == 1.0) &&
      (main_U.IR_sensor_FL == 1.0)) {
    main_DW.is_c3_main = main_IN_PICKUPFORWARD;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 10.0;
  } else {
    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 100.0;

    /* Outport: '<Root>/exitpickup_counter' incorporates:
     *  Inport: '<Root>/turn_spd_pickup'
     *  Outport: '<Root>/PWMA'
     *  Outport: '<Root>/PWMB'
     *  Outport: '<Root>/dirMA'
     *  Outport: '<Root>/dirMB'
     *  Outport: '<Root>/motEN'
     */
    if (main_Y.exitpickup_counter == 0.0) {
      main_Y.motEN = 1.0;
      main_Y.dirMA = 1.0;
      main_Y.dirMB = 0.0;
      main_Y.PWMA = 0.85 * main_U.turn_spd_pickup;
      main_Y.PWMB = main_U.turn_spd_pickup;
    } else {
      main_Y.motEN = 1.0;
      main_Y.dirMA = 1.0;
      main_Y.dirMB = 0.0;
      main_Y.PWMA = 0.75 * main_U.turn_spd_pickup;
      main_Y.PWMB = main_U.turn_spd_pickup;
    }

    /* End of Outport: '<Root>/exitpickup_counter' */
  }

  /* End of Inport: '<Root>/IR_sensor_R' */
}

/* Function for Chart: '<Root>/Chart' */
static void main_HARDRIGHT_PICKUP(void)
{
  /* Inport: '<Root>/IR_sensor_L' incorporates:
   *  Inport: '<Root>/IR_sensor_FL'
   *  Inport: '<Root>/IR_sensor_FR'
   */
  if ((main_U.IR_sensor_L > 750.0) && (main_U.IR_sensor_FR == 1.0) &&
      (main_U.IR_sensor_FL == 1.0)) {
    main_DW.is_c3_main = main_IN_PICKUPFORWARD;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 10.0;
  } else {
    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 100.0;

    /* Outport: '<Root>/exitpickup_counter' incorporates:
     *  Inport: '<Root>/turn_spd_pickup'
     *  Outport: '<Root>/PWMA'
     *  Outport: '<Root>/PWMB'
     *  Outport: '<Root>/dirMA'
     *  Outport: '<Root>/dirMB'
     *  Outport: '<Root>/motEN'
     */
    if (main_Y.exitpickup_counter == 0.0) {
      main_Y.motEN = 1.0;
      main_Y.dirMA = 0.0;
      main_Y.dirMB = 1.0;
      main_Y.PWMA = main_U.turn_spd_pickup;
      main_Y.PWMB = main_U.turn_spd_pickup;
    } else {
      main_Y.motEN = 1.0;
      main_Y.dirMA = 0.0;
      main_Y.dirMB = 1.0;
      main_Y.PWMA = main_U.turn_spd_pickup;
      main_Y.PWMB = 0.8 * main_U.turn_spd_pickup;
    }

    /* End of Outport: '<Root>/exitpickup_counter' */
  }

  /* End of Inport: '<Root>/IR_sensor_L' */
}

/* Function for Chart: '<Root>/Chart' */
static void main_IDLE(void)
{
  /* Outport: '<Root>/grabbing' */
  main_Y.grabbing = 0.0;

  /* Inport: '<Root>/IR_sensor_M' incorporates:
   *  Inport: '<Root>/IR_sensor_FL'
   *  Inport: '<Root>/IR_sensor_FR'
   *  Inport: '<Root>/IR_sensor_L'
   *  Inport: '<Root>/input1'
   *  Inport: '<Root>/input2'
   */
  if ((main_U.IR_sensor_M >= 750.0) && (main_U.IR_sensor_L >= 750.0) &&
      (main_U.IR_sensor_L >= 750.0) && (main_U.IR_sensor_FL == 1.0) &&
      ((main_U.IR_sensor_FR == 1.0) && (main_U.input1 != 0.0) && (main_U.input2
        != 0.0))) {
    main_DW.is_c3_main = main_IN_FORWARD;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 1.0;
  } else {
    /* Outport: '<Root>/motEN' */
    main_Y.motEN = 1.0;

    /* Outport: '<Root>/dirMA' */
    main_Y.dirMA = 1.0;

    /* Outport: '<Root>/dirMB' */
    main_Y.dirMB = 1.0;

    /* Outport: '<Root>/PWMA' */
    main_Y.PWMA = 0.0;

    /* Outport: '<Root>/PWMB' */
    main_Y.PWMB = 0.0;

    /* Outport: '<Root>/exitpickup_counter' */
    main_Y.exitpickup_counter = 0.0;
    main_DW.left_counter = 0.0;

    /* Outport: '<Root>/dropoff_counter' */
    main_Y.dropoff_counter = 0.0;
    main_DW.drop_check = 0.0;
  }

  /* End of Inport: '<Root>/IR_sensor_M' */
}

/* Function for Chart: '<Root>/Chart' */
static void main_PICKUPFORWARD(void)
{
  /* Inport: '<Root>/IR_sensor_L' incorporates:
   *  Inport: '<Root>/IR_Distance'
   *  Inport: '<Root>/IR_sensor_M'
   *  Inport: '<Root>/IR_sensor_R'
   *  Outport: '<Root>/exitpickup_counter'
   */
  if ((main_U.IR_sensor_L < 750.0) && (main_U.IR_sensor_R >= 750.0) &&
      (main_U.IR_sensor_M >= 750.0)) {
    main_DW.is_c3_main = main_IN_STEERRIGHT1;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 12.0;
  } else if (main_U.IR_Distance < 875.0) {
    main_DW.is_c3_main = main_IN_STOP_PICKUP;

    /* Outport: '<Root>/grabbing' */
    main_Y.grabbing = 1.0;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 13.0;
  } else if ((main_U.IR_sensor_L >= 750.0) && (main_U.IR_sensor_R < 750.0) &&
             (main_U.IR_sensor_M >= 750.0)) {
    main_DW.is_c3_main = main_IN_STEERLEFT1;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 11.0;
  } else if (main_Y.exitpickup_counter == 3.0) {
    main_DW.is_c3_main = main_IN_FORWARD;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 1.0;
  } else {
    /* Outport: '<Root>/motEN' */
    main_Y.motEN = 1.0;

    /* Outport: '<Root>/dirMA' */
    main_Y.dirMA = 0.0;

    /* Outport: '<Root>/dirMB' */
    main_Y.dirMB = 0.0;

    /* Outport: '<Root>/err' */
    main_Y.err = main_U.IR_sensor_L - main_U.IR_sensor_R;

    /* Outport: '<Root>/PWMA' incorporates:
     *  Inport: '<Root>/fwd_spd_pickup'
     *  Outport: '<Root>/err'
     */
    main_Y.PWMA = 0.1 * main_Y.err + main_U.fwd_spd_pickup;

    /* Outport: '<Root>/PWMB' incorporates:
     *  Inport: '<Root>/fwd_spd_pickup'
     *  Outport: '<Root>/err'
     */
    main_Y.PWMB = main_U.fwd_spd_pickup - 0.1 * main_Y.err;
  }

  /* End of Inport: '<Root>/IR_sensor_L' */
}

/* Function for Chart: '<Root>/Chart' */
static void main_PICKUPZONE(void)
{
  /* Inport: '<Root>/input1' incorporates:
   *  Inport: '<Root>/fwd_spd_pickup'
   *  Outport: '<Root>/PWMA'
   *  Outport: '<Root>/PWMB'
   *  Outport: '<Root>/dirMA'
   *  Outport: '<Root>/dirMB'
   *  Outport: '<Root>/exitpickup_counter'
   *  Outport: '<Root>/motEN'
   *  Outport: '<Root>/testOutput'
   */
  if ((main_U.input1 == 1.0) && ((main_Y.exitpickup_counter == 0.0) ||
       (main_Y.exitpickup_counter == 2.0))) {
    main_DW.is_c3_main = main_IN_HARDLEFT_PICKUP;
    ma_enter_atomic_HARDLEFT_PICKUP();
  } else if ((main_U.input1 == 2.0) && ((main_Y.exitpickup_counter == 0.0) ||
              (main_Y.exitpickup_counter == 2.0))) {
    main_DW.is_c3_main = main_IN_HARDRIGHT_PICKUP;
    m_enter_atomic_HARDRIGHT_PICKUP();
  } else if ((main_U.input1 == 1.0) && (main_Y.exitpickup_counter == 1.0)) {
    main_DW.is_c3_main = main_IN_FORWARDDELAY3;
    main_Y.testOutput = 70.0;
    main_Y.motEN = 1.0;
    main_Y.dirMA = 0.0;
    main_Y.dirMB = 0.0;
    main_Y.PWMA = main_U.fwd_spd_pickup;
    main_Y.PWMB = main_U.fwd_spd_pickup;
  } else if ((main_U.input1 == 2.0) && (main_Y.exitpickup_counter == 1.0)) {
    main_DW.is_c3_main = main_IN_FOWARDDELAY2;
    main_Y.testOutput = 70.0;
    main_Y.motEN = 1.0;
    main_Y.dirMA = 0.0;
    main_Y.dirMB = 0.0;
    main_Y.PWMA = main_U.fwd_spd_pickup;
    main_Y.PWMB = main_U.fwd_spd_pickup;
  }

  /* End of Inport: '<Root>/input1' */
}

/* Function for Chart: '<Root>/Chart' */
static void main_REVERSE(void)
{
  /* Inport: '<Root>/IR_sensor_FR' incorporates:
   *  Inport: '<Root>/input1'
   */
  if ((main_U.IR_sensor_FR == 0.0) && (main_U.input1 == 1.0)) {
    main_DW.is_c3_main = main_IN_PICKUPZONE1;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 7.0;

    /* Outport: '<Root>/motEN' */
    main_Y.motEN = 1.0;

    /* Outport: '<Root>/dirMA' */
    main_Y.dirMA = 1.0;

    /* Outport: '<Root>/dirMB' */
    main_Y.dirMB = 1.0;

    /* Outport: '<Root>/PWMA' */
    main_Y.PWMA = 0.0;

    /* Outport: '<Root>/PWMB' */
    main_Y.PWMB = 0.0;
  } else if ((main_U.IR_sensor_FR == 0.0) && (main_U.input1 == 2.0)) {
    main_DW.is_c3_main = main_IN_PICKUPZONE2;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 7.0;

    /* Outport: '<Root>/motEN' */
    main_Y.motEN = 1.0;

    /* Outport: '<Root>/dirMA' */
    main_Y.dirMA = 1.0;

    /* Outport: '<Root>/dirMB' */
    main_Y.dirMB = 1.0;

    /* Outport: '<Root>/PWMA' */
    main_Y.PWMA = 0.0;

    /* Outport: '<Root>/PWMB' */
    main_Y.PWMB = 0.0;
  } else {
    /* Outport: '<Root>/motEN' */
    main_Y.motEN = 1.0;

    /* Outport: '<Root>/dirMA' */
    main_Y.dirMA = 1.0;

    /* Outport: '<Root>/dirMB' */
    main_Y.dirMB = 1.0;

    /* Outport: '<Root>/err' incorporates:
     *  Inport: '<Root>/IR_sensor_L'
     *  Inport: '<Root>/IR_sensor_R'
     */
    main_Y.err = main_U.IR_sensor_L - main_U.IR_sensor_R;

    /* Inport: '<Root>/fwd_spd_pickup' */
    main_Y.PWMA = 1.05 * main_U.fwd_spd_pickup;

    /* Outport: '<Root>/PWMB' */
    main_Y.PWMB = main_Y.PWMA;
  }

  /* End of Inport: '<Root>/IR_sensor_FR' */
}

/* Function for Chart: '<Root>/Chart' */
static void main_STEERLEFT(void)
{
  /* Inport: '<Root>/IR_sensor_L' incorporates:
   *  Inport: '<Root>/IR_Distance'
   *  Inport: '<Root>/IR_sensor_FL'
   *  Inport: '<Root>/IR_sensor_FR'
   *  Inport: '<Root>/IR_sensor_M'
   *  Inport: '<Root>/IR_sensor_R'
   *  Outport: '<Root>/exitpickup_counter'
   */
  if ((main_U.IR_sensor_L >= 750.0) && (main_U.IR_sensor_R >= 750.0) &&
      (main_U.IR_sensor_M >= 750.0)) {
    main_DW.is_c3_main = main_IN_FORWARD;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 1.0;
  } else if ((main_U.IR_sensor_FL == 0.0) && (main_U.IR_sensor_FR == 1.0) &&
             ((main_DW.left_counter == 0.0) || (main_Y.exitpickup_counter >= 3.0)))
  {
    main_DW.is_c3_main = main_IN_HARDLEFT1;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 5.0;
  } else if (main_U.IR_Distance < 825.0) {
    main_DW.is_c3_main = main_IN_STOP;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 6.0;
  } else if ((main_U.IR_sensor_FR == 0.0) && (main_Y.exitpickup_counter == 3.0))
  {
    main_DW.is_c3_main = main_IN_PICKUPZONE;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 7.0;

    /* Outport: '<Root>/motEN' */
    main_Y.motEN = 1.0;

    /* Outport: '<Root>/dirMA' */
    main_Y.dirMA = 1.0;

    /* Outport: '<Root>/dirMB' */
    main_Y.dirMB = 1.0;

    /* Outport: '<Root>/PWMA' */
    main_Y.PWMA = 0.0;

    /* Outport: '<Root>/PWMB' */
    main_Y.PWMB = 0.0;
  } else {
    /* Outport: '<Root>/motEN' */
    main_Y.motEN = 1.0;

    /* Outport: '<Root>/dirMA' */
    main_Y.dirMA = 1.0;

    /* Outport: '<Root>/dirMB' */
    main_Y.dirMB = 0.0;

    /* Outport: '<Root>/PWMA' incorporates:
     *  Inport: '<Root>/turn_spd'
     */
    main_Y.PWMA = main_U.turn_spd;

    /* Outport: '<Root>/PWMB' incorporates:
     *  Inport: '<Root>/turn_spd'
     */
    main_Y.PWMB = main_U.turn_spd;
  }

  /* End of Inport: '<Root>/IR_sensor_L' */
}

/* Function for Chart: '<Root>/Chart' */
static void main_STEERLEFT1(void)
{
  /* Inport: '<Root>/IR_sensor_L' incorporates:
   *  Inport: '<Root>/IR_Distance'
   *  Inport: '<Root>/IR_sensor_M'
   *  Inport: '<Root>/IR_sensor_R'
   */
  if ((main_U.IR_sensor_L >= 750.0) && (main_U.IR_sensor_R >= 750.0) &&
      (main_U.IR_sensor_M >= 750.0)) {
    main_DW.is_c3_main = main_IN_PICKUPFORWARD;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 10.0;
  } else if (main_U.IR_Distance < 875.0) {
    main_DW.is_c3_main = main_IN_STOP_PICKUP;

    /* Outport: '<Root>/grabbing' */
    main_Y.grabbing = 1.0;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 13.0;
  } else {
    /* Outport: '<Root>/motEN' */
    main_Y.motEN = 1.0;

    /* Outport: '<Root>/dirMA' */
    main_Y.dirMA = 1.0;

    /* Outport: '<Root>/dirMB' */
    main_Y.dirMB = 0.0;

    /* Outport: '<Root>/PWMA' */
    main_Y.PWMA = 0.0;

    /* Outport: '<Root>/PWMB' incorporates:
     *  Inport: '<Root>/turn_spd_pickup'
     */
    main_Y.PWMB = 0.9 * main_U.turn_spd_pickup;
  }

  /* End of Inport: '<Root>/IR_sensor_L' */
}

/* Function for Chart: '<Root>/Chart' */
static void main_STEERRIGHT(void)
{
  /* Inport: '<Root>/IR_sensor_L' incorporates:
   *  Inport: '<Root>/IR_Distance'
   *  Inport: '<Root>/IR_sensor_FL'
   *  Inport: '<Root>/IR_sensor_FR'
   *  Inport: '<Root>/IR_sensor_M'
   *  Inport: '<Root>/IR_sensor_R'
   *  Outport: '<Root>/exitpickup_counter'
   */
  if ((main_U.IR_sensor_L >= 750.0) && (main_U.IR_sensor_R >= 750.0) &&
      (main_U.IR_sensor_M >= 750.0)) {
    main_DW.is_c3_main = main_IN_FORWARD;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 1.0;
  } else if ((main_U.IR_sensor_FL == 0.0) && (main_U.IR_sensor_FR == 1.0) &&
             ((main_DW.left_counter == 0.0) || (main_Y.exitpickup_counter >= 3.0)))
  {
    main_DW.is_c3_main = main_IN_HARDLEFT1;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 5.0;
  } else if (main_U.IR_Distance < 825.0) {
    main_DW.is_c3_main = main_IN_STOP;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 6.0;
  } else if ((main_U.IR_sensor_FR == 0.0) && (main_Y.exitpickup_counter < 3.0))
  {
    main_DW.is_c3_main = main_IN_PICKUPZONE;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 7.0;

    /* Outport: '<Root>/motEN' */
    main_Y.motEN = 1.0;

    /* Outport: '<Root>/dirMA' */
    main_Y.dirMA = 1.0;

    /* Outport: '<Root>/dirMB' */
    main_Y.dirMB = 1.0;

    /* Outport: '<Root>/PWMA' */
    main_Y.PWMA = 0.0;

    /* Outport: '<Root>/PWMB' */
    main_Y.PWMB = 0.0;
  } else {
    /* Outport: '<Root>/motEN' */
    main_Y.motEN = 1.0;

    /* Outport: '<Root>/dirMA' */
    main_Y.dirMA = 0.0;

    /* Outport: '<Root>/dirMB' */
    main_Y.dirMB = 1.0;

    /* Outport: '<Root>/PWMA' incorporates:
     *  Inport: '<Root>/turn_spd'
     */
    main_Y.PWMA = main_U.turn_spd;

    /* Outport: '<Root>/PWMB' incorporates:
     *  Inport: '<Root>/turn_spd'
     */
    main_Y.PWMB = main_U.turn_spd;
  }

  /* End of Inport: '<Root>/IR_sensor_L' */
}

/* Function for Chart: '<Root>/Chart' */
static void main_STEERRIGHT1(void)
{
  /* Inport: '<Root>/IR_sensor_L' incorporates:
   *  Inport: '<Root>/IR_Distance'
   *  Inport: '<Root>/IR_sensor_M'
   *  Inport: '<Root>/IR_sensor_R'
   */
  if ((main_U.IR_sensor_L >= 750.0) && (main_U.IR_sensor_R >= 750.0) &&
      (main_U.IR_sensor_M >= 750.0)) {
    main_DW.is_c3_main = main_IN_PICKUPFORWARD;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 10.0;
  } else if (main_U.IR_Distance < 875.0) {
    main_DW.is_c3_main = main_IN_STOP_PICKUP;

    /* Outport: '<Root>/grabbing' */
    main_Y.grabbing = 1.0;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 13.0;
  } else {
    /* Outport: '<Root>/motEN' */
    main_Y.motEN = 1.0;

    /* Outport: '<Root>/dirMA' */
    main_Y.dirMA = 0.0;

    /* Outport: '<Root>/dirMB' */
    main_Y.dirMB = 1.0;

    /* Inport: '<Root>/turn_spd_pickup' */
    main_Y.PWMA = 0.9 * main_U.turn_spd_pickup;

    /* Outport: '<Root>/PWMB' */
    main_Y.PWMB = main_Y.PWMA;
  }

  /* End of Inport: '<Root>/IR_sensor_L' */
}

/* Function for Chart: '<Root>/Chart' */
static void main_STOP(void)
{
  /* Inport: '<Root>/IR_Distance' */
  if (main_U.IR_Distance > 825.0) {
    main_DW.is_c3_main = main_IN_FORWARD;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 1.0;
  } else if (main_DW.drop_check == 1.0) {
    main_DW.is_c3_main = main_IN_DROPZONE;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 21.0;

    /* Outport: '<Root>/motEN' */
    main_Y.motEN = 0.0;

    /* Outport: '<Root>/dirMA' */
    main_Y.dirMA = 1.0;

    /* Outport: '<Root>/dirMB' */
    main_Y.dirMB = 1.0;

    /* Outport: '<Root>/PWMA' */
    main_Y.PWMA = 0.0;

    /* Outport: '<Root>/PWMB' */
    main_Y.PWMB = 0.0;
  } else {
    /* Outport: '<Root>/motEN' */
    main_Y.motEN = 1.0;

    /* Outport: '<Root>/dirMA' */
    main_Y.dirMA = 1.0;

    /* Outport: '<Root>/dirMB' */
    main_Y.dirMB = 1.0;

    /* Outport: '<Root>/PWMA' */
    main_Y.PWMA = 0.0;

    /* Outport: '<Root>/PWMB' */
    main_Y.PWMB = 0.0;
  }

  /* End of Inport: '<Root>/IR_Distance' */
}

/* Model step function */
void main_step(void)
{
  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/IR_sensor_FL'
   *  Inport: '<Root>/IR_sensor_FR'
   *  Inport: '<Root>/IR_sensor_L'
   *  Inport: '<Root>/IR_sensor_R'
   *  Inport: '<Root>/fwd_spd_pickup'
   */
  if (main_DW.is_active_c3_main == 0U) {
    main_DW.is_active_c3_main = 1U;
    main_DW.is_c3_main = main_IN_IDLE;

    /* Outport: '<Root>/testOutput' */
    main_Y.testOutput = 0.0;

    /* Outport: '<Root>/grabbing' */
    main_Y.grabbing = 0.0;
  } else {
    switch (main_DW.is_c3_main) {
     case main_IN_DROPOFFZONE:
      main_DROPOFFZONE();
      break;

     case main_IN_DROPZONE:
      main_DW.is_c3_main = main_IN_REVERSE1;

      /* Outport: '<Root>/testOutput' */
      main_Y.testOutput = 23.0;
      break;

     case main_IN_FORWARD:
      main_FORWARD();
      break;

     case main_IN_FORWARDDELAY:
      main_DW.is_c3_main = main_IN_HARDLEFT_PICKUP1;

      /* Outport: '<Root>/testOutput' */
      main_Y.testOutput = 16.0;

      /* Outport: '<Root>/motEN' */
      main_Y.motEN = 1.0;

      /* Outport: '<Root>/dirMA' */
      main_Y.dirMA = 1.0;

      /* Outport: '<Root>/dirMB' */
      main_Y.dirMB = 0.0;

      /* Outport: '<Root>/PWMA' incorporates:
       *  Inport: '<Root>/turn_spd_pickup'
       */
      main_Y.PWMA = 0.55 * main_U.turn_spd_pickup;

      /* Outport: '<Root>/PWMB' incorporates:
       *  Inport: '<Root>/turn_spd_pickup'
       */
      main_Y.PWMB = main_U.turn_spd_pickup;
      break;

     case main_IN_FORWARDDELAY1:
      main_DW.is_c3_main = main_IN_HARDRIGHT_PICKUP1;

      /* Outport: '<Root>/testOutput' */
      main_Y.testOutput = 17.0;

      /* Outport: '<Root>/motEN' */
      main_Y.motEN = 1.0;

      /* Outport: '<Root>/dirMA' */
      main_Y.dirMA = 0.0;

      /* Outport: '<Root>/dirMB' */
      main_Y.dirMB = 1.0;

      /* Outport: '<Root>/PWMA' incorporates:
       *  Inport: '<Root>/turn_spd_pickup'
       */
      main_Y.PWMA = main_U.turn_spd_pickup;

      /* Outport: '<Root>/PWMB' incorporates:
       *  Inport: '<Root>/turn_spd_pickup'
       */
      main_Y.PWMB = 0.8 * main_U.turn_spd_pickup;
      break;

     case main_IN_FORWARDDELAY3:
      main_DW.is_c3_main = main_IN_HARDLEFT_PICKUP;
      ma_enter_atomic_HARDLEFT_PICKUP();
      break;

     case main_IN_FORWARDDROPOFF:
      if (main_U.IR_sensor_FR == 1.0) {
        main_DW.is_c3_main = main_IN_FORWARD;

        /* Outport: '<Root>/testOutput' */
        main_Y.testOutput = 1.0;
      }
      break;

     case main_IN_FOWARDDELAY2:
      main_DW.is_c3_main = main_IN_HARDRIGHT_PICKUP;
      m_enter_atomic_HARDRIGHT_PICKUP();
      break;

     case main_IN_GRABBING:
      main_DW.is_c3_main = main_IN_REVERSE;

      /* Outport: '<Root>/testOutput' */
      main_Y.testOutput = 14.0;

      /* Outport: '<Root>/exitpickup_counter' */
      main_Y.exitpickup_counter++;
      break;

     case main_IN_HARDLEFT1:
      if ((main_U.IR_sensor_R > 750.0) && (main_U.IR_sensor_FR == 1.0) &&
          (main_U.IR_sensor_FL == 1.0)) {
        main_DW.is_c3_main = main_IN_FORWARD;

        /* Outport: '<Root>/testOutput' */
        main_Y.testOutput = 1.0;
      } else {
        /* Outport: '<Root>/motEN' */
        main_Y.motEN = 1.0;

        /* Outport: '<Root>/dirMA' */
        main_Y.dirMA = 1.0;

        /* Outport: '<Root>/dirMB' */
        main_Y.dirMB = 0.0;

        /* Outport: '<Root>/PWMA' incorporates:
         *  Inport: '<Root>/turn_spd'
         */
        main_Y.PWMA = main_U.turn_spd;

        /* Outport: '<Root>/PWMB' incorporates:
         *  Inport: '<Root>/turn_spd'
         */
        main_Y.PWMB = main_U.turn_spd;
        main_DW.left_counter++;
      }
      break;

     case main_IN_HARDLEFT_DROPOFF:
      if ((main_U.IR_sensor_R > 750.0) && (main_U.IR_sensor_FR == 1.0) &&
          (main_U.IR_sensor_FL == 1.0)) {
        main_DW.is_c3_main = main_IN_FORWARD;

        /* Outport: '<Root>/testOutput' */
        main_Y.testOutput = 1.0;
      } else {
        /* Outport: '<Root>/testOutput' */
        main_Y.testOutput = 100.0;

        /* Outport: '<Root>/motEN' */
        main_Y.motEN = 1.0;

        /* Outport: '<Root>/dirMA' */
        main_Y.dirMA = 1.0;

        /* Outport: '<Root>/dirMB' */
        main_Y.dirMB = 0.0;

        /* Outport: '<Root>/PWMA' incorporates:
         *  Inport: '<Root>/turn_spd_pickup'
         */
        main_Y.PWMA = 0.75 * main_U.turn_spd_pickup;

        /* Outport: '<Root>/PWMB' incorporates:
         *  Inport: '<Root>/turn_spd_pickup'
         */
        main_Y.PWMB = main_U.turn_spd_pickup;
      }
      break;

     case main_IN_HARDLEFT_PICKUP:
      main_HARDLEFT_PICKUP();
      break;

     case main_IN_HARDLEFT_PICKUP1:
      if ((main_U.IR_sensor_R > 750.0) && (main_U.IR_sensor_FR == 1.0) &&
          (main_U.IR_sensor_FL == 1.0)) {
        main_DW.is_c3_main = main_IN_FORWARD;

        /* Outport: '<Root>/testOutput' */
        main_Y.testOutput = 1.0;
      } else {
        /* Outport: '<Root>/testOutput' */
        main_Y.testOutput = 100.0;

        /* Outport: '<Root>/motEN' */
        main_Y.motEN = 1.0;

        /* Outport: '<Root>/dirMA' */
        main_Y.dirMA = 1.0;

        /* Outport: '<Root>/dirMB' */
        main_Y.dirMB = 0.0;

        /* Outport: '<Root>/PWMA' incorporates:
         *  Inport: '<Root>/turn_spd_pickup'
         */
        main_Y.PWMA = 0.55 * main_U.turn_spd_pickup;

        /* Outport: '<Root>/PWMB' incorporates:
         *  Inport: '<Root>/turn_spd_pickup'
         */
        main_Y.PWMB = main_U.turn_spd_pickup;
      }
      break;

     case main_IN_HARDRIGHT_DROPOFF:
      if ((main_U.IR_sensor_L > 750.0) && (main_U.IR_sensor_FR == 1.0) &&
          (main_U.IR_sensor_FL == 1.0)) {
        main_DW.is_c3_main = main_IN_FORWARD;

        /* Outport: '<Root>/testOutput' */
        main_Y.testOutput = 1.0;
      } else {
        /* Outport: '<Root>/testOutput' */
        main_Y.testOutput = 100.0;

        /* Outport: '<Root>/motEN' */
        main_Y.motEN = 1.0;

        /* Outport: '<Root>/dirMA' */
        main_Y.dirMA = 0.0;

        /* Outport: '<Root>/dirMB' */
        main_Y.dirMB = 1.0;

        /* Outport: '<Root>/PWMA' incorporates:
         *  Inport: '<Root>/turn_spd_pickup'
         */
        main_Y.PWMA = main_U.turn_spd_pickup;

        /* Outport: '<Root>/PWMB' incorporates:
         *  Inport: '<Root>/turn_spd_pickup'
         */
        main_Y.PWMB = 0.9 * main_U.turn_spd_pickup;
      }
      break;

     case main_IN_HARDRIGHT_PICKUP:
      main_HARDRIGHT_PICKUP();
      break;

     case main_IN_HARDRIGHT_PICKUP1:
      if ((main_U.IR_sensor_L > 750.0) && (main_U.IR_sensor_FR == 1.0) &&
          (main_U.IR_sensor_FL == 1.0)) {
        main_DW.is_c3_main = main_IN_FORWARD;

        /* Outport: '<Root>/testOutput' */
        main_Y.testOutput = 1.0;
      } else {
        /* Outport: '<Root>/testOutput' */
        main_Y.testOutput = 100.0;

        /* Outport: '<Root>/motEN' */
        main_Y.motEN = 1.0;

        /* Outport: '<Root>/dirMA' */
        main_Y.dirMA = 0.0;

        /* Outport: '<Root>/dirMB' */
        main_Y.dirMB = 1.0;

        /* Outport: '<Root>/PWMA' incorporates:
         *  Inport: '<Root>/turn_spd_pickup'
         */
        main_Y.PWMA = main_U.turn_spd_pickup;

        /* Outport: '<Root>/PWMB' incorporates:
         *  Inport: '<Root>/turn_spd_pickup'
         */
        main_Y.PWMB = 0.8 * main_U.turn_spd_pickup;
      }
      break;

     case main_IN_IDLE:
      main_IDLE();
      break;

     case main_IN_LINEUPREV:
      if ((main_U.IR_sensor_FL == 0.0) || (main_U.IR_sensor_FR == 0.0)) {
        main_DW.is_c3_main = main_IN_PICKUPFORWARD;

        /* Outport: '<Root>/testOutput' */
        main_Y.testOutput = 10.0;
      } else {
        /* Outport: '<Root>/testOutput' */
        main_Y.testOutput = 100.0;

        /* Outport: '<Root>/motEN' */
        main_Y.motEN = 1.0;

        /* Outport: '<Root>/dirMA' */
        main_Y.dirMA = 1.0;

        /* Outport: '<Root>/dirMB' */
        main_Y.dirMB = 1.0;
        main_Y.PWMA = 1.05 * main_U.fwd_spd_pickup;

        /* Outport: '<Root>/PWMB' incorporates:
         *  Inport: '<Root>/fwd_spd_pickup'
         */
        main_Y.PWMB = main_Y.PWMA;
      }
      break;

     case main_IN_PAUSE:
      main_DW.is_c3_main = main_IN_HARDLEFT_DROPOFF;

      /* Outport: '<Root>/testOutput' */
      main_Y.testOutput = 9.0;

      /* Outport: '<Root>/motEN' */
      main_Y.motEN = 1.0;

      /* Outport: '<Root>/dirMA' */
      main_Y.dirMA = 1.0;

      /* Outport: '<Root>/dirMB' */
      main_Y.dirMB = 0.0;

      /* Outport: '<Root>/PWMA' incorporates:
       *  Inport: '<Root>/turn_spd_pickup'
       */
      main_Y.PWMA = 0.75 * main_U.turn_spd_pickup;

      /* Outport: '<Root>/PWMB' incorporates:
       *  Inport: '<Root>/turn_spd_pickup'
       */
      main_Y.PWMB = main_U.turn_spd_pickup;
      break;

     case main_IN_PICKUPFORWARD:
      main_PICKUPFORWARD();
      break;

     case main_IN_PICKUPZONE:
      main_PICKUPZONE();
      break;

     case main_IN_PICKUPZONE1:
      main_DW.is_c3_main = main_IN_FORWARDDELAY1;

      /* Outport: '<Root>/testOutput' */
      main_Y.testOutput = 15.0;

      /* Outport: '<Root>/motEN' */
      main_Y.motEN = 1.0;

      /* Outport: '<Root>/dirMA' */
      main_Y.dirMA = 0.0;

      /* Outport: '<Root>/dirMB' */
      main_Y.dirMB = 0.0;

      /* Outport: '<Root>/PWMA' incorporates:
       *  Inport: '<Root>/fwd_spd_pickup'
       */
      main_Y.PWMA = main_U.fwd_spd_pickup;

      /* Outport: '<Root>/PWMB' incorporates:
       *  Inport: '<Root>/fwd_spd_pickup'
       */
      main_Y.PWMB = main_U.fwd_spd_pickup;
      break;

     case main_IN_PICKUPZONE2:
      main_DW.is_c3_main = main_IN_FORWARDDELAY;

      /* Outport: '<Root>/testOutput' */
      main_Y.testOutput = 15.0;

      /* Outport: '<Root>/motEN' */
      main_Y.motEN = 1.0;

      /* Outport: '<Root>/dirMA' */
      main_Y.dirMA = 0.0;

      /* Outport: '<Root>/dirMB' */
      main_Y.dirMB = 0.0;

      /* Outport: '<Root>/PWMA' incorporates:
       *  Inport: '<Root>/fwd_spd_pickup'
       */
      main_Y.PWMA = main_U.fwd_spd_pickup;

      /* Outport: '<Root>/PWMB' incorporates:
       *  Inport: '<Root>/fwd_spd_pickup'
       */
      main_Y.PWMB = main_U.fwd_spd_pickup;
      break;

     case main_IN_REVERSE:
      main_REVERSE();
      break;

     case main_IN_REVERSE1:
      if (main_U.IR_sensor_FR == 0.0) {
        main_DW.is_c3_main = main_IN_PAUSE;

        /* Outport: '<Root>/testOutput' */
        main_Y.testOutput = 69.0;

        /* Outport: '<Root>/motEN' */
        main_Y.motEN = 1.0;

        /* Outport: '<Root>/dirMA' */
        main_Y.dirMA = 1.0;

        /* Outport: '<Root>/dirMB' */
        main_Y.dirMB = 1.0;

        /* Outport: '<Root>/PWMA' */
        main_Y.PWMA = 0.0;

        /* Outport: '<Root>/PWMB' */
        main_Y.PWMB = 0.0;
      } else {
        /* Outport: '<Root>/motEN' */
        main_Y.motEN = 1.0;

        /* Outport: '<Root>/dirMA' */
        main_Y.dirMA = 1.0;

        /* Outport: '<Root>/dirMB' */
        main_Y.dirMB = 1.0;

        /* Outport: '<Root>/PWMA' incorporates:
         *  Inport: '<Root>/fwd_spd'
         */
        main_Y.PWMA = main_U.fwd_spd * 1.05;

        /* Outport: '<Root>/PWMB' incorporates:
         *  Inport: '<Root>/fwd_spd'
         */
        main_Y.PWMB = main_U.fwd_spd * 5.0;
      }
      break;

     case main_IN_STEERLEFT:
      main_STEERLEFT();
      break;

     case main_IN_STEERLEFT1:
      main_STEERLEFT1();
      break;

     case main_IN_STEERRIGHT:
      main_STEERRIGHT();
      break;

     case main_IN_STEERRIGHT1:
      main_STEERRIGHT1();
      break;

     case main_IN_STOP:
      main_STOP();
      break;

     default:
      /* case IN_STOP_PICKUP: */
      main_STOP_PICKUP();
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */
}

/* Model initialize function */
void main_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void main_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
