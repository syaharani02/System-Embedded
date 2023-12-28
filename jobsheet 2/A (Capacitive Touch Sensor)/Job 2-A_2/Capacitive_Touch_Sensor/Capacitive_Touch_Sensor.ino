// Job 2-A 2
// Rani, Ayum, Alfan

// ESP32 Touch Test
// Just test touch pin - Touch0 is T0 which is on GPIO 4.
const int ledPin = 16;
const int touchPin = 4;
void setup() {
  Serial.begin(115200);
  // delay(1000); // give me time to bring up serial monitor
  Serial.println("ESP32 Touch Test");
  pinMode (ledPin, OUTPUT);
}
void loop() {
  int touchValue = touchRead(touchPin);
  Serial.println(touchValue); // get value of Touch 0 pin = GPIO 4
  delay(500);


  if (touchValue == 0) {
    digitalWrite (ledPin, HIGH);
  } else {
    digitalWrite (ledPin, LOW);
  }
  delay(1000);
}
