unsigned char Re_buf[11], counter = 0;
unsigned char sign = 0;
float roll, pitch, yaw;

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200);
  while (true) {
    resetMPU();
    checkMPU();
    if (roll == 0 && pitch == 0 && yaw == 0) break;
  }
}

void loop() {
  checkMPU();
  Serial.print("Roll: "); Serial.print(roll);
  Serial.print(" Pitch: "); Serial.print(pitch);
  Serial.print(" Yaw: "); Serial.println(yaw);
}

void Event() {
  while (Serial2.available()) {
    Re_buf[counter] = (unsigned char)Serial2.read();
    if (counter == 0 && Re_buf[0] != 0x55) return;
    counter++;

    if (counter == 11) {
      counter = 0;
      sign = 1;
      if (Re_buf[0] != 0x55 || Re_buf[1] != 0x53) sign = 0;
    }
  }
}

void resetMPU() {
  Serial.println("RESET");
  Serial2.write(0xFF);
  Serial2.write(0xAA);
  Serial2.write(0x52);
}

void checkMPU() {
  Event();
  if (sign) {
    sign = 0;
    if (Re_buf[0] == 0x55 && Re_buf[1] == 0x53) {
      yaw = (short(Re_buf[7] << 8 | Re_buf[6])) / 32768.0 * 180;
      pitch = (short(Re_buf[3] << 8 | Re_buf[2])) / 32768.0 * 180;
      roll = (short(Re_buf[5] << 8 | Re_buf[4])) / 32768.0 * 180;
    }
  }
}
