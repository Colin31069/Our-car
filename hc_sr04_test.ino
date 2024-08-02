#include <Ultrasonic.h>


//超音波

//左側超音波
#define TRIG_left 51
#define ECHO_left 53

//前左超音波
#define TRIG_forward_left 47
#define ECHO_forward_left 49


//前右超音波
#define TRIG_forward_right 48
#define ECHO_forward_right 46

//右側超音波
#define TRIG_right 52
#define ECHO_right 50

void setup()
{
   //超音波針腳設定為輸出
  pinMode(TRIG_left, OUTPUT);
  pinMode(TRIG_forward_left, OUTPUT);
  pinMode(TRIG_forward_right, OUTPUT);
  pinMode(TRIG_right, OUTPUT);

  //超音波針腳設定為輸入
  pinMode(ECHO_left, INPUT);
  pinMode(ECHO_forward_left, INPUT);
  pinMode(ECHO_forward_right, INPUT);
  pinMode(ECHO_right, INPUT);


  Serial.begin(9600);
}


void loop()
{
  long distance1 = readUltrasonicDistance(TRIG_left, ECHO_left);
  long distance2 = readUltrasonicDistance(TRIG_forward_left, ECHO_forward_left);
  long distance3 = readUltrasonicDistance(TRIG_forward_right, ECHO_forward_right);
  long distance4 = readUltrasonicDistance(TRIG_right, ECHO_right);

  Serial.print("左邊距離:");
  Serial.print(distance1);
  Serial.print("CM   ");
  
  Serial.print("前左距離:");
  Serial.print(distance2);
  Serial.print("CM   ");
  
  Serial.print("前右距離:");
  Serial.print(distance3);
  Serial.print("CM   ");
  
  Serial.print("右邊距離:");
  Serial.print(distance4);
  Serial.println("CM");

  delay(100);
}




//超音波讀取距離函式
long readUltrasonicDistance(int trigPin, int echoPin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034/2;
  if(distance == 0)
  {
    Serial.print("Warning: No echo detected by sensor with trig pin");
    Serial.println(trigPin);
  }
  return distance;
}