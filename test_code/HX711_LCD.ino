#include "HX711.h"
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x27);  // 設定i2c位址，一般情況就是0x27和0x3F兩種

// 接線
const int DT_PIN = 6;
const int SCK_PIN = 5;

const int scale_factor = -697; //比例參數，從校正程式中取得

HX711 scale;

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing the scale");

  scale.begin(DT_PIN, SCK_PIN);
  lcd.begin(16, 2); // 初始化LCD
  lcd.setBacklight(255);
  lcd.clear();

  Serial.println("Before setting up the scale:"); 
  
  Serial.println(scale.get_units(5), 0);  //未設定比例參數前的數值

  scale.set_scale(scale_factor);       // 設定比例參數
  scale.tare();               // 歸零

  Serial.println("After setting up the scale:"); 

  Serial.println(scale.get_units(5), 0);  //設定比例參數後的數值

  Serial.println("Readings:");  //在這個訊息之前都不要放東西在電子稱上
}

void loop() {
  
  Serial.println(scale.get_units(10), 0); 
  lcd.clear();
  lcd.setCursor(0, 0);  //設定游標位置 (字,行)
  lcd.print("Weight: ");
  lcd.setCursor(9, 0);
  float weight = scale.get_units(10);
  //避免出現負數
  if(weight<=0){
    weight = 0;
  }
  lcd.print(weight,0);
  lcd.setCursor(13, 0);
  lcd.print("g");
  scale.power_down();             // 進入睡眠模式
  delay(500);
  scale.power_up();               // 結束睡眠模式
}
