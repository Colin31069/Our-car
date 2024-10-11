//此版本加入超音波感測器



#include <Ultrasonic.h>




// 定義L298N模塊控制馬達的引腳（left）
const int ENA1 = 6;   // 馬達1速度控制
const int IN1 = 22;    // 馬達1轉向控制
const int IN2 = 24;    // 馬達1轉向控制
const int IN3 = 26;    // 馬達2轉向控制
const int IN4 = 28;   // 馬2轉向控制
const int ENB1 = 7;  // 馬達2速度控制

// 定義L298N模塊控制馬達的引腳（right）
const int ENA2 = 4;  // 馬達3速度控制
const int IN5 = 23;   // 馬達3轉向控制
const int IN6 = 25;   // 馬達3轉向控制
const int IN7 = 27;   // 馬達4轉向控制
const int IN8 = 29;   // 馬達4轉向控制
const int ENB2 = 5;  // 馬達4速度控制

int left_spd = 225;  //左邊PWM的速度（0~255）  左邊速度要比右邊少30
int right_spd = 255;  //右邊PWM的速度


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







int mindistance = 35; // 設定前面最小距離








void setup() {

  pinMode(ENA1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB1, OUTPUT);

  pinMode(ENA2, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);
  pinMode(ENB2, OUTPUT);


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
  moveForward();

}










//動作函式
void moveForward()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA1, left_spd);
  analogWrite(ENB1, left_spd);

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  analogWrite(ENA2, right_spd);
  analogWrite(ENB2, right_spd);
}


void turnRight()
{
  //右轉  左輪要比右輪快
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA1, left_spd);
  analogWrite(ENB1, left_spd);

  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  analogWrite(ENA2, right_spd);
  analogWrite(ENB2, right_spd);
}


void turnLeft()
{
  //左轉  右輪要往前左輪要往後
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA1, left_spd);
  analogWrite(ENB1, left_spd);

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  analogWrite(ENA2, right_spd);
  analogWrite(ENB2, right_spd);
}


void stop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA1, 0);
  analogWrite(ENB1, 0);

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, LOW);
  analogWrite(ENA2, 0);
  analogWrite(ENB2, 0);
}