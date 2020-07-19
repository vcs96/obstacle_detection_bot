#define IN1 4   \\Left_motor_backward
#define IN2 5   \\Left_motor_forward
#define IN3 6   \\Right_motor_backward
#define IN4 7   \\Right_motor_forward

int trig = 2;   \\ trigger pin
int echo = 3;   \\ echo pin

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

long distance, duration;

void loop() {

  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);

  distance = duration / 52.8;   \\ calculate distance

  if (distance < 20)
  {
    digitalWrite(IN2, LOW);   \\ takes a left turn incase an object is less than 20cm in front of the ultrasonic sensor
    digitalWrite(IN1, HIGH);
    digitalWrite(IN4, LOW);
    digitalWrite(IN3, LOW);
    delay(1000);
  }
  else
  {
    digitalWrite(IN2, HIGH);    \\ moves foward
    digitalWrite(IN1, LOW);
    digitalWrite(IN4, HIGH);
    digitalWrite(IN3, LOW);

  }
}
