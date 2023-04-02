#include <NewPing.h>

#include <Servo.h>

#define TRIGGER_PIN 12

#define ECHO_PIN 11

#define MAX_DISTANCE 200

Servo myservo;

int servoPin = 9;

int servoInitial = 90;

int servoAngle = servoInitial;

int servoMin = 0;

int servoMax = 180;

int leftMotorPin1 = 2;

int leftMotorPin2 = 3;

int rightMotorPin1 = 4;

int rightMotorPin2 = 5;

int motorSpeed = 100;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {

  myservo.attach(servoPin);

  pinMode(leftMotorPin1, OUTPUT);

  pinMode(leftMotorPin2, OUTPUT);

  pinMode(rightMotorPin1, OUTPUT);

  pinMode(rightMotorPin2, OUTPUT);

  myservo.write(servoInitial);

}

void loop() {

  int distance = sonar.ping_cm();

  if (distance > 0 && distance < 30) {

    stop();

    myservo.write(servoMin);

    delay(1000);

    myservo.write(servoMax);

    delay(1000);

    forward();

    delay(500);

    stop();

    myservo.write(servoInitial);

    delay(1000);

    backward();

    delay(500);

  } else {

    forward();

  }

}

void forward() {

  digitalWrite(leftMotorPin1, HIGH);

  digitalWrite(leftMotorPin2, LOW);

  digitalWrite(rightMotorPin1, HIGH);

  digitalWrite(rightMotorPin2, LOW);

  analogWrite(leftMotorPin1, motorSpeed);

  analogWrite(rightMotorPin1, motorSpeed);

}

void backward() {

  digitalWrite(leftMotorPin1, LOW);

  digitalWrite(leftMotorPin2, HIGH);

  digitalWrite(rightMotorPin1, LOW);

  digitalWrite(rightMotorPin2, HIGH);

  analogWrite(leftMotorPin2, motorSpeed);

  analogWrite(rightMotorPin2, motorSpeed);

}

void stop() {

  digitalWrite(leftMotorPin1, LOW);

  digitalWrite(leftMotorPin2, LOW);

  digitalWrite(rightMotorPin1, LOW);

  digitalWrite(rightMotorPin2, LOW);

}

