#include <Servo.h>

int ServoPin=9;
int echoPin=10;
int trigPin=13;
int pos=0;
Servo s;
int t;

void setup()
{
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  s.attach(ServoPin);
  Serial.begin(9600);
}
void loop()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin,LOW);
  t=pulseIn(echoPin,HIGH);
  pos=map(t,0,3500,0,180);
  s.write(pos);
  Serial.println(pos);
  delay(500);
}

