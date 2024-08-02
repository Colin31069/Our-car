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

int spd = 255;  //PWM的速度（0~255）



void setup() {
  // put your setup code here, to run once:
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
}

void loop() {
  //左前輪
  //往前
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA1, spd);
  delay(1000);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA1, spd);
  //往後
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA1, spd);
  delay(1000);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA1, spd);
  

  //左後輪
  //往前
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB1, spd);
  delay(1000);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB1, spd);
  //往後
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB1, spd);
  delay(1000);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);


  //右前輪
  //往前
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  analogWrite(ENB2, spd);
  delay(1000);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, LOW);
  //往後
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  analogWrite(ENB2, spd);
  delay(1000);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, LOW);


  //右後輪
  //往前
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  analogWrite(ENA2, spd);
  delay(1000);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, LOW);
  //往後
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  analogWrite(ENA2, spd);
  delay(1000);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, LOW);
}
