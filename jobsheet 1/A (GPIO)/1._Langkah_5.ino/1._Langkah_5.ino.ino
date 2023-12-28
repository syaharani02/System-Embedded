// Job 1 A(Langkah 5)
// Rani, Ayum, Alfan

// inisialisasi pin GPIO
const int buttonPin1 = 2;
const int buttonPin2 = 4;
const int buttonPin3 = 15;
const int ledPin1 = 5; 
const int ledPin2 = 18;
const int ledPin3 = 19;

// array led
const int numLED = 3;
const int pinLED[numLED] = {5, 18, 19};

// status awal push button
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

void setup() {
  Serial.begin(115200);
  // inisialisasi push button sebagai input
  pinMode(buttonPin1, INPUT); // Button pertama
  pinMode(buttonPin2, INPUT); // Button kedua
  pinMode(buttonPin3, INPUT); // Button ketiga
  // inisialisasi LED sebagai output
  pinMode(ledPin1, OUTPUT); // LED pertama
  pinMode(ledPin2, OUTPUT); // LED kedua
  pinMode(ledPin3, OUTPUT); // LED ketiga
  for (int i = 0; i < 3; i++) {
    pinMode(pinLED[i], OUTPUT);
  }
}
void loop() {
  // membaca status push button
  buttonState1 = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin1);
  buttonState3 = digitalRead(buttonPin2);
  Serial.println(buttonState1);
  Serial.println(buttonState2);
  Serial.println(buttonState3);

  if (buttonState2 == HIGH) {
    // nyalakan LED sehingga dapat menyala bergantian seperti "blink" jika push button kedua ditekan
    digitalWrite(ledPin, HIGH); // LED pertama akan nyala
    delay(500); // LED dibiarkan tetap menyala
    digitalWrite(ledPin, LOW); // LED pertama dimatikan
    digitalWrite(ledPin1, HIGH); // LED kedua dinyalakan
    delay(500); // LED kedua dibiarkan menyala
    digitalWrite(ledPin1, LOW); // LED kedua dimatikan
    // digitalWrite(ledPin2, HIGH); // LED kedua dinyalakan
    // delay(500); // LED kedua dibiarkan menyala
    // digitalWrite(ledPin2, LOW); // LED kedua dimatikan
  } else if (buttonState1 == HIGH) {
    // menyalakan ketiga LED bersamaan jika push button pertama ditekan
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
  } else if (buttonState3 == HIGH) {
    // menyalakan Running LED jika push button ketiga ditekan
    for (int i = 0; i < 3; i++) {
      digitalWrite(pinLED[i], HIGH);
      delay(500);
      digitalWrite(pinLED[i], LOW);
    }
  } else {
    // matikan LED
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  }
}
