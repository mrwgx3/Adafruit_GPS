// Test code for Ultimate GPS Using Hardware Serial
// (e.g. GPS for Leonardo, Flora or FeatherWing)
//
// This code shows how to test a passthru between USB and hardware serial
//
// Tested and works great with the Adafruit GPS FeatherWing
// ------> https://www.adafruit.com/products/3133
// or Flora GPS
// ------> https://www.adafruit.com/products/1059
// but also works with the shield, breakout
// ------> https://www.adafruit.com/products/1272
// ------> https://www.adafruit.com/products/746
// 
// Pick one up today at the Adafruit electronics shop
// and help support open source hardware & software! -ada


// If you're a using a Huzzah32-ESP32 Feather board and
// GPS module with combination with: 
//    a) Stackable headers on the feather board, or a
//    b) 'Doubler' or 'Tripler' Prototyping Add-on,
//
// replace the code snippet defining 'GPSSerial' with
// one of the following options (start with 'a'):
//
//   #define GPSSerial Serial2    // a) 'Serial2' already defined
//             or
//   HardwareSerial GPSSerial(2); // b) 'Serial2' is undefined


// what's the name of the hardware serial port?
#define GPSSerial Serial1


void setup() {
  // wait for hardware serial to appear
  while (!Serial);

  // make this baud rate fast enough to we aren't waiting on it
  Serial.begin(115200);

  // 9600 baud is the default rate for the Ultimate GPS
  GPSSerial.begin(9600);
}

     
void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    GPSSerial.write(c);
  }
  if (GPSSerial.available()) {
    char c = GPSSerial.read();
    Serial.write(c);
  }
}
