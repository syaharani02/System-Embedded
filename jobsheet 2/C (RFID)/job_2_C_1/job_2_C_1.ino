// Job 2-C
// Rani, Ayum, Alfan

#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 21 // ESP32 pin GIO21 
#define RST_PIN 22 // ESP32 pin GIO22
const int ledPin = 12;
const int ledPin1 = 32;
MFRC522 rfid(SS_PIN, RST_PIN);
byte keyTagUID[4] = {0x2B, 0x64, 0x06, 0x12};
void setup() {
 Serial.begin(9600);
 SPI.begin(); // init SPI bus
 rfid.PCD_Init(); // init MFRC522
 Serial.println("Tap RFID/NFC Tag on reader");
 pinMode(ledPin, OUTPUT);
 pinMode(ledPin1, OUTPUT);
}
void loop() {
 if (rfid.PICC_IsNewCardPresent()) { // new tag is available
 if (rfid.PICC_ReadCardSerial()) { // NUID has been readed
 MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
 if (rfid.uid.uidByte[0] == keyTagUID[0] &&
 rfid.uid.uidByte[1] == keyTagUID[1] &&
 rfid.uid.uidByte[2] == keyTagUID[2] &&
 rfid.uid.uidByte[3] == keyTagUID[3] ) {
 Serial.print("Akses Diterima, Silahkan Masuk : ");
 for (int i = 0; i < rfid.uid.size; i++) {
 Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
 Serial.print(rfid.uid.uidByte[i], HEX);
 }
 digitalWrite(ledPin, HIGH);
 delay (1000);
 digitalWrite(ledPin, LOW);
 Serial.println();
 }
 else
 {
 Serial.print("Akses Ditolak : ");
 for (int i = 0; i < rfid.uid.size; i++) {
 Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
 Serial.print(rfid.uid.uidByte[i], HEX);
 }
 digitalWrite(ledPin1, HIGH);
 delay (1000);
 digitalWrite(ledPin1, LOW);
 Serial.println();
 }
 rfid.PICC_HaltA(); // halt PICC
 rfid.PCD_StopCrypto1(); // stop encryption on PCD
 }
 }
}
