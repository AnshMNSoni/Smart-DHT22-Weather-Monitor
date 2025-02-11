#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

int menubuttonpin = 7; // Red Button
int readingbuttonpin = 5; // Blue Button
bool mode1 = false;

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(menubuttonpin, INPUT_PULLUP); 
  pinMode(readingbuttonpin, INPUT_PULLUP);
  dht.begin();
  lcd.begin(16, 2);
  lcd.backlight();
  Serial.begin(9600);

  // Initial display setup
  lcd.setCursor(0, 0);
  lcd.print(">");
  lcd.setCursor(0, 1);
  lcd.print(" ");
}

void loop() {
  static bool lastButtonState = HIGH;
  bool currentButtonState = digitalRead(menubuttonpin);

  if (currentButtonState == LOW && lastButtonState == HIGH) { 
    lcd.clear();
    mode1 = !mode1; // Toggle btw mode

    // Update LCD display
    if (mode1) {
      lcd.setCursor(0, 0);
      lcd.print(">");
      lcd.setCursor(0, 1);
      lcd.print(" ");
    } else {
      lcd.setCursor(0, 0);
      lcd.print(" ");
      lcd.setCursor(0, 1);
      lcd.print(">");
    }

    lcd.setCursor(2, 0);
    lcd.print("Mode 1");
    lcd.setCursor(2, 1);
    lcd.print("Mode 2");

    delay(200);
  }
  showreadings(mode1);
  lastButtonState = currentButtonState;
}

void showreadings(bool mode) {
  bool readingButton = digitalRead(readingbuttonpin);

  if (readingButton == HIGH && mode == true) {
    lcd.clear();
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();
    String showTemperature = "Temp: " + String(temperature) + "C";
    String showHumidity = "Humidity: " + String(humidity) + "%";
    lcd.setCursor(2, 0);
    lcd.print(showTemperature);
    lcd.setCursor(2, 1);
    lcd.print(showHumidity);

    delay(500);
  } 

  if (readingButton == HIGH && mode == false) {
    lcd.clear();
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();
    String showTemperature = "Temp: " + String(temperature) + "C";
    String showHumidity = "Humidity: " + String(humidity) + "%";
    lcd.setCursor(2, 0);
    lcd.print(showTemperature);

    delay(500);
  }
}
