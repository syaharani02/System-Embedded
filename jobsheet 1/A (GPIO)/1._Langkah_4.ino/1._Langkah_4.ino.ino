// Job 1 A(Langkah 4)
// Rani, Ayum, Alfan

// inisialisasi pin GPIO
const int buttonPin1 = 2;   
const int buttonPin2 = 4;  
const int ledPin1 = 5;       
const int ledPin2 = 18;

// status awal push button
int buttonState = 0;
int buttonState1 = 0;

void setup() {
  Serial.begin(115200);
  // inisialisasi push button sebagai input
  pinMode(buttonPin1, INPUT); // Button pertama
  pinMode(buttonPin2, INPUT); // Button kedua
  // inisialisasi LED sebagai output
  pinMode(ledPin1, OUTPUT); // LED pertama
  pinMode(ledPin2, OUTPUT); // LED kedua
}

void loop() {
  // membaca status push button
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  Serial.println(buttonState1);
  Serial.println(buttonState2);

  if (buttonState2 == HIGH) {
    // nyalakan LED sehingga dapat menyala bergantian seperti "blink" jika push button kedua ditekan
    digitalWrite(ledPin1, HIGH); // LED pertama akan nyala
    delay(500); // LED dibiarkan tetap menyala
    digitalWrite(ledPin1, LOW); // LED pertama dimatikan
    digitalWrite(ledPin2, HIGH); // LED kedua dinyalakan
    delay(500); // LED kedua dibiarkan menyala
    digitalWrite(ledPin2, LOW); // LED kedua dimatikan
  } else if (buttonState1 == HIGH) {
    // menyalakan kedua LED bersamaan jika push button pertama ditekan
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
  } else {
    // matikan LED
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  }
}
