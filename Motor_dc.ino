#include <Servo.h>

Servo myservo;  // create servo object to control a servo
int pinMotor = 6;
int potenServo = 0;  // analog pin used to connect the potentiometer 0
int potenMotor = 1;  // analog pin used to connect the potentiometer 1
int valorServo;    // variable to read the value from the analog pin 0
int valorMotor;     // variable to read the value from the analog pin 1


void setup() {
  myservo.attach(9); // attaches the servo on pin 9 to the servo object
  pinMode(13, OUTPUT);
  pinMode(pinMotor, OUTPUT);
}

void loop() {
  servoMotor();
  dcMotor();
  delay(15);                           // waits for the servo to get there
}


void servoMotor() {
  valorServo = analogRead(potenServo);          // reads the value of the potentiometer (value between 0 and 1023)  print("potenciometro "+val);
  valorServo = map(valorServo, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(valorServo);                  // sets the servo position according to the scaled value
}

void dcMotor() {
  valorMotor = analogRead(potenMotor);
  valorMotor = map(valorMotor, 0, 1023, 0, 255);

  if (valorMotor >= 0 && valorMotor < 20) {
    digitalWrite(pinMotor, LOW);
    digitalWrite(13, LOW);
  }

  else if (valorMotor >= 20 && valorMotor < 255) {
    digitalWrite(pinMotor, HIGH);
    digitalWrite(13, HIGH);
  }
}

