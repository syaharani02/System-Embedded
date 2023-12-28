// Job 3-F
// Rani, Ayum, Alfan

#include <WiFi.h>
#include <EEPROM.h>
#include <ESPAsyncWebServer.h>

const char *apSSID = "ESP32_AP";
const char *apPassword = "";

char ssid[32];
char password[64];

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);
  EEPROM.begin(512);

  // Step a: Membaca SSID dan Password dari EEPROM
  readSSIDAndPassword();

  // Step b: Mencoba terhubung ke jaringan WiFi yang telah dikonfigurasi
  if (!connectToWiFi()) {
    // Step b: Jika gagal, ESP32 berubah menjadi mode Access Point
    createAccessPoint();
    // Step c: Membuka konfigurasi melalui web server
    setupWebServer();
  } else {
    // Step e: Berhasil terhubung ke jaringan WiFi
    Serial.println("Connected to WiFi Successfully.");
  }
}

void loop() {
  // Langkah d: ESP32 akan mencoba terhubung ke jaringan WiFi yang telah dikonfigurasi sebelumnya.
  if (!WiFi.isConnected()) {
    Serial.println("Failed to connect to WiFi.");
    // Step f: Jika gagal, ESP32 akan masuk ke mode Access Point untuk konfigurasi ulang
    createAccessPoint();
  }
}

void readSSIDAndPassword() {
  EEPROM.get(0, ssid);
  EEPROM.get(32, password);
}

void writeSSIDAndPassword() {
  EEPROM.put(0, ssid);
  EEPROM.put(32, password);
  EEPROM.commit();
}

bool connectToWiFi() {
  WiFi.begin(ssid, password);
  int attempt = 0;
  while (WiFi.status() != WL_CONNECTED && attempt < 10) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
    attempt++;
  }
  return WiFi.status() == WL_CONNECTED;
}

void createAccessPoint() {
  WiFi.mode(WIFI_AP);
  WiFi.softAP(apSSID, apPassword);
  Serial.println("Access Point Mode - IP Address: " + WiFi.softAPIP().toString());
}

void setupWebServer() {
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    String html = "<html><body>";
    html += "<h1>ESP32 WiFi Configuration</h1>";
    html += "<form method='post' action='/save'>";
    html += "<label for='ssid'>SSID:</label><br>";
    html += "<input type='text' id='ssid' name='ssid' value='" + String(ssid) + "'><br><br>";
    html += "<label for='password'>Password:</label><br>";
    html += "<input type='password' id='password' name='password' value='" + String(password) + "'><br><br>";
    html += "<input type='submit' value='Save'>";
    html += "</form></body></html>";
    request->send(200, "text/html", html);
  });

  server.on("/save", HTTP_POST, [](AsyncWebServerRequest *request){
    String newSsid = request->arg("ssid");
    String newPassword = request->arg("password");

    newSsid.toCharArray(ssid, 32);
    newPassword.toCharArray(password, 64);

    writeSSIDAndPassword();
    
    request->send(200, "text/plain", "Configuration saved. ESP32 will reboot.");
    ESP.restart();
  });

  server.begin();
}
