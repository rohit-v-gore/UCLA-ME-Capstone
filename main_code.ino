extern "C" {
#include "main.h"
#include "main_private.h"
#include "main_types.h"
}

#include <IRremote.hpp>
#include <NewPing.h>
#include <Servo.h>

// Motor A1 connections (front left)
#define EN_A1         5
#define IN_11         30
#define IN_12         31

// Motor B1 connections (front right)
#define EN_B1         4
#define IN_13         32
#define IN_14         33

// Motor A2 connections (back left)
#define EN_A2         3
#define IN_21         34
#define IN_22         35

// Motor B2 connections (back right)
#define EN_B2         2
#define IN_23         36
#define IN_24         37

// IR sensor pins
#define IR_FARLEFT    A5
#define IR_LEFT       A4
#define IR_MIDDLE     A3
#define IR_RIGHT      A2
#define IR_FARRIGHT   A1
#define IR_DISTANCE   A0

// US sensor pins
#define ECHO_PIN      A7
#define TRIG_PIN      44
float duration, distance;

// Stepper motor pins
#define EN_STEPPER    23
#define DIR_STEPPER   25
#define STP_STEPPER   24

#define SPD_STEPPER   1000
#define PICKUP_STEPS  3000
#define CLEARANCE     500

// Servo motor positions
#define OPENED        0
#define CLOSED        70
#define OPEN          1
#define CLOSE         0

Servo servoMotor;

// Remote Pins
#define RECV_PIN      52
#define LED_PIN       53

// Input Initialization
int input1 = 0;
int input2 = 0;


// Initialize New Ping
//NewPing sonar(TRIG_PIN, ECHO_PIN);

void setup() {

  Serial.begin(115200);


  // SET ALL MOTOR CONTROL PINS TO OUTPUTS

  // Drive Motors
  pinMode(EN_A1, OUTPUT);
  pinMode(EN_B2, OUTPUT);
  pinMode(EN_B1, OUTPUT);
  pinMode(EN_B2, OUTPUT);
  pinMode(IN_11, OUTPUT);
  pinMode(IN_12, OUTPUT);
  pinMode(IN_13, OUTPUT);
  pinMode(IN_14, OUTPUT);
  pinMode(IN_21, OUTPUT);
  pinMode(IN_22, OUTPUT);
  pinMode(IN_23, OUTPUT);
  pinMode(IN_24, OUTPUT);

  // Stepper Motor
  pinMode(EN_STEPPER, OUTPUT);
  pinMode(STP_STEPPER, OUTPUT);
  pinMode(DIR_STEPPER, OUTPUT);

  // Turn off motors - Initial state
  digitalWrite(IN_11, LOW);
  digitalWrite(IN_12, LOW);
  digitalWrite(IN_13, LOW);
  digitalWrite(IN_14, LOW);
  digitalWrite(IN_21, LOW);
  digitalWrite(IN_22, LOW);
  digitalWrite(IN_23, LOW);
  digitalWrite(IN_24, LOW);
  digitalWrite(STP_STEPPER, LOW);
  digitalWrite(DIR_STEPPER, LOW);
  digitalWrite(EN_STEPPER, HIGH); // <-- this is right, pulling this pin low enables the stepper motor driver

  // Set up servo motor
  servoMotor.attach(13);
  servoMotorControl(OPEN);

  // Setup sensor pints
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(IR_FARRIGHT, INPUT);
  pinMode(IR_RIGHT, INPUT);
  pinMode(IR_MIDDLE, INPUT);
  pinMode(IR_LEFT, INPUT);
  pinMode(IR_FARLEFT, INPUT);
  pinMode(IR_DISTANCE, INPUT);

  // Setup IR receiver pins
  pinMode(RECV_PIN, INPUT);
  pinMode(LED_PIN, INPUT);

  // Initialize IR Receiver
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);

  //Initialize Input Variables
  main_U.input1 = 1;
  main_U.input2 = 6;
  main_U.fwd_spd = 100;
  main_U.turn_spd = 180;
  main_U.fwd_spd_pickup = 90;
  main_U.turn_spd_pickup = 220;


}

void loop() {

  // Remote Inputs

 // if (input1 == 0 || input2 == 0) {
 //  getInputs();

    // Pass inputs to module
    main_U.input1 = input1;
    main_U.input2 = input2;
 // }
  //else if (input1 != 0 & input2 != 0) {
    IrReceiver.end();
  //}

  // Read Sensors
  main_U.IR_sensor_M = analogRead(IR_MIDDLE);
  main_U.IR_sensor_FL = digitalRead(IR_FARLEFT);
  main_U.IR_sensor_L = analogRead(IR_LEFT);
  main_U.IR_sensor_R = analogRead(IR_RIGHT);
  main_U.IR_sensor_FR = digitalRead(IR_FARRIGHT);
  main_U.IR_Distance = analogRead(IR_DISTANCE);

  main_U.US_sensor = 100;
  // Read US Sensor
  /*distance = sonar.ping_cm();
    if (distance > 0) {
    main_U.US_sensor = distance;
    }
  */
  debug();

  if (main_Y.exitpickup_counter == 3) {
    main_U.fwd_spd = 82;
  }
  
  // Step Module
  main_step();

  // Driver Code
  driveMotorControl(main_Y.dirMA, main_Y.dirMB, main_Y.motEN, main_Y.PWMA, main_Y.PWMB);
  stepperMotorControl(main_Y.testOutput, main_Y.exitpickup_counter);
}

void blinkLED(int n) {
  // Blinks LED n times, for use with IR receiver.
  for (int i = 0; i < n; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(250);
    digitalWrite(LED_PIN, LOW);
    delay(750);
  }
}

void getInputs() {
  // Receives signal for chicken or beef, than receives a second signal for dropoff point.
  if (IrReceiver.decode()) {
    if (input1 == 0) {
      switch (IrReceiver.decodedIRData.command) {
        case 0x16:
          input1 = 1;
          break;
        case 0x19:
          input1 = 2;
          break;
      }
      if (input1 != 0) {
        blinkLED(3);
      }
      IrReceiver.decodedIRData.command = 0;
    }

    IrReceiver.resume();

    if (input2 == 0 & IrReceiver.decodedIRData.command != 0) {
      switch (IrReceiver.decodedIRData.command) {
        case 0x16:
          input2 = 1;
          break;
        case 0x19:
          input2 = 2;
          break;
        case 0xD:
          input2 = 3;
          break;
        case 0xC:
          input2 = 4;
          break;
        case 0x18:
          input2 = 5;
          break;
        case 0x5E:
          input2 = 6;
          break;
      }
      if (input2 != 0) {
        blinkLED(5);
      }
    }
  }
}

void driveMotorControl(int dirMA, int dirMB, bool motorEN, int PWMA, int PWMB) {
  // Driver code for drive motors.
  if (motorEN == true) {
    if (dirMA == 0) {
      digitalWrite(IN_11, HIGH);
      digitalWrite(IN_12, LOW);
      digitalWrite(IN_21, HIGH);
      digitalWrite(IN_22, LOW);
    }
    else {
      digitalWrite(IN_11, LOW);
      digitalWrite(IN_12, HIGH);
      digitalWrite(IN_21, LOW);
      digitalWrite(IN_22, HIGH);
    }
    if (dirMB == 0) {
      digitalWrite(IN_13, HIGH);
      digitalWrite(IN_14, LOW);
      digitalWrite(IN_23, HIGH);
      digitalWrite(IN_24, LOW);
    }
    else {
      digitalWrite(IN_13, LOW);
      digitalWrite(IN_14, HIGH);
      digitalWrite(IN_23, LOW);
      digitalWrite(IN_24, HIGH);
    }
    analogWrite(EN_A1, PWMA);
    analogWrite(EN_A2, PWMA);
    analogWrite(EN_B1, PWMB);
    analogWrite(EN_B2, PWMB);

    // Hardcoded Turns in Pickup Zone
    if (main_Y.testOutput == 8 || main_Y.testOutput == 9 || main_Y.testOutput == 7) {
      delay(700);
    }
    if (main_Y.testOutput == 70) {
      delay(400);
    }
    if (main_Y.testOutput == 16 || main_Y.testOutput == 17 || main_Y.testOutput == 20) {
      delay(700);
    }
    if (main_Y.testOutput == 19 || main_Y.testOutput == 69) {
      delay(300);
    }
  }
  else {
    digitalWrite(IN_11, LOW);
    digitalWrite(IN_12, LOW);
    digitalWrite(IN_13, LOW);
    digitalWrite(IN_14, LOW);
    digitalWrite(IN_21, LOW);
    digitalWrite(IN_22, LOW);
    digitalWrite(IN_23, LOW);
    digitalWrite(IN_24, LOW);
  }
}

void stepperMotorControl(int state, int counter) {
  /* Stepper Directions:
     HIGH = Stepper goes up
     LOW = Stepper goes down
  */

  // Pickup
  if (state == 22) {
    digitalWrite(EN_STEPPER, LOW);

    // First disk
    if (counter == 0) {
      servoMotorControl(OPEN);
      // Lower to point of pickup
      digitalWrite(DIR_STEPPER, LOW);
      for (int x = 0; x < PICKUP_STEPS; x++) {
        digitalWrite(STP_STEPPER, HIGH);
        delayMicroseconds(SPD_STEPPER);
        digitalWrite(STP_STEPPER, LOW);
        delayMicroseconds(SPD_STEPPER);
      }

      // Pickup the first disk
      servoMotorControl(CLOSE);

      // Return to original height
      digitalWrite(DIR_STEPPER, HIGH);
      for (int x = 0; x < PICKUP_STEPS + CLEARANCE; x++) {
        digitalWrite(STP_STEPPER, HIGH);
        delayMicroseconds(SPD_STEPPER);
        digitalWrite(STP_STEPPER, LOW);
        delayMicroseconds(SPD_STEPPER);
      }
    }

    // Second Disk
    if (counter == 1) {
      // Lower to point of dropoff
      digitalWrite(DIR_STEPPER, LOW);
      for (int x = 0; x < 2 * PICKUP_STEPS / 3; x++) {
        digitalWrite(STP_STEPPER, HIGH);
        delayMicroseconds(SPD_STEPPER);
        digitalWrite(STP_STEPPER, LOW);
        delayMicroseconds(SPD_STEPPER);
      }

      // Drop first disk on top of second
      servoMotorControl(OPEN);

      // Lower to point of pickup
      digitalWrite(DIR_STEPPER, LOW);
      for (int x = 0; x < (PICKUP_STEPS / 3) + CLEARANCE; x++) {
        digitalWrite(STP_STEPPER, HIGH);
        delayMicroseconds(SPD_STEPPER);
        digitalWrite(STP_STEPPER, LOW);
        delayMicroseconds(SPD_STEPPER);
      }

      // Pickup the first and second disk
      servoMotorControl(CLOSE);

      // Return to original height
      digitalWrite(DIR_STEPPER, HIGH);
      for (int x = 0; x < PICKUP_STEPS + CLEARANCE; x++) {
        digitalWrite(STP_STEPPER, HIGH);
        delayMicroseconds(SPD_STEPPER);
        digitalWrite(STP_STEPPER, LOW);
        delayMicroseconds(SPD_STEPPER);
      }
    }

    // Third Disk
    if (counter == 2) {
      // Lower to point of dropoff
      digitalWrite(DIR_STEPPER, LOW);
      for (int x = 0; x < PICKUP_STEPS / 3; x++) {
        digitalWrite(STP_STEPPER, HIGH);
        delayMicroseconds(SPD_STEPPER);
        digitalWrite(STP_STEPPER, LOW);
        delayMicroseconds(SPD_STEPPER);
      }

      // Drop the first two disks on top of the third
      servoMotorControl(OPEN);

      // Lower to point of pickup
      digitalWrite(DIR_STEPPER, LOW);
      for (int x = 0; x < (2 * PICKUP_STEPS / 3) + CLEARANCE; x++) {
        digitalWrite(STP_STEPPER, HIGH);
        delayMicroseconds(SPD_STEPPER);
        digitalWrite(STP_STEPPER, LOW);
        delayMicroseconds(SPD_STEPPER);
      }

      // Pickup all three disks
      servoMotorControl(CLOSE);

      // Return to original height
      digitalWrite(DIR_STEPPER, HIGH);
      for (int x = 0; x < PICKUP_STEPS + CLEARANCE; x++) {
        digitalWrite(STP_STEPPER, HIGH);
        delayMicroseconds(SPD_STEPPER);
        digitalWrite(STP_STEPPER, LOW);
        delayMicroseconds(SPD_STEPPER);
      }
    }
    digitalWrite(EN_STEPPER, HIGH);
  }
  // Dropoff
  else if (state == 21) {
    digitalWrite(EN_STEPPER, LOW);

    // Lower to point of dropoff
    digitalWrite(DIR_STEPPER, LOW);
    for (int x = 0; x < PICKUP_STEPS + CLEARANCE; x++) {
      digitalWrite(STP_STEPPER, HIGH);
      delayMicroseconds(SPD_STEPPER);
      digitalWrite(STP_STEPPER, LOW);
      delayMicroseconds(SPD_STEPPER);
    }

    // Drop all three disks
    servoMotorControl(OPEN);

    // Return to original height
    digitalWrite(DIR_STEPPER, HIGH);
    for (int x = 0; x < PICKUP_STEPS + CLEARANCE; x++) {
      digitalWrite(STP_STEPPER, HIGH);
      delayMicroseconds(SPD_STEPPER);
      digitalWrite(STP_STEPPER, LOW);
      delayMicroseconds(SPD_STEPPER);
    }
    digitalWrite(EN_STEPPER, HIGH);
  }
}

void up() {
  digitalWrite(DIR_STEPPER, HIGH);
  digitalWrite(STP_STEPPER, HIGH);
  delayMicroseconds(SPD_STEPPER);
  digitalWrite(STP_STEPPER, LOW);
  delayMicroseconds(SPD_STEPPER);
}

void down() {
  digitalWrite(DIR_STEPPER, LOW);
  digitalWrite(STP_STEPPER, HIGH);
  delayMicroseconds(SPD_STEPPER);
  digitalWrite(STP_STEPPER, LOW);
  delayMicroseconds(SPD_STEPPER);
}

void down(int steps) {
  digitalWrite(DIR_STEPPER, LOW);
  for (int x = 0; x < steps; x++) {
    digitalWrite(STP_STEPPER, HIGH);
    delayMicroseconds(SPD_STEPPER);
    digitalWrite(STP_STEPPER, LOW);
    delayMicroseconds(SPD_STEPPER);
  }
}

void up(int steps) {
  digitalWrite(DIR_STEPPER, HIGH);
  for (int x = 0; x < steps; x++) {
    digitalWrite(STP_STEPPER, HIGH);
    delayMicroseconds(SPD_STEPPER);
    digitalWrite(STP_STEPPER, LOW);
    delayMicroseconds(SPD_STEPPER);
  }
}

void servoMotorControl(int action) {
  // Close the grabber
  if (action == CLOSE) {
    servoMotor.write(CLOSED);
  }
  // Open the grabber
  else if (action == OPEN) {
    servoMotor.write(OPENED);
  }
  delay(1000);
}

void debug() {
  
    Serial.println("IR sensors read the following values:");
    Serial.println(main_U.IR_sensor_FL);
    Serial.println(main_U.IR_sensor_L);
    Serial.println(main_U.IR_sensor_M);
    Serial.println(main_U.IR_sensor_R);
    Serial.println(main_U.IR_sensor_FR);

    //Serial.println("Ultrasonic sensor reads the following distance:");
    // Serial.println(distance);

    //Serial.println("Currently in the following state:");
  
  //Serial.println(main_Y.dropoff_counter);
  //Serial.println(main_Y.testOutput);
  //Serial.println(main_U.IR_Distance);

}
