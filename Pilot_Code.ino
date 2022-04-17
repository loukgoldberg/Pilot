#include <Wire.h>
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

void setup() {
  Wire.begin();
  Serial.begin(115200);
  Serial.println("The device started, now you can pair it with bluetooth!");
  bleKeyboard.begin();
}

// Pretty sure the below loop is awful and has to be improved a lot but it works! Probably not power efficient.

void loop() {
  Wire.requestFrom(0x08, 1);
  if (Wire.available()) { // can also use while but idk which is better
    uint8_t key_val = Wire.read();                  // receive a byte as character
    if(key_val != 0) {
      bleKeyboard.print((char)key_val);
    }
  }
  delay(10);
}
