#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9
#define LED_GREEN_PIN 6  // Green LED for adding item
#define LED_RED_PIN 7    // Red LED for removing item
#define BUZZER_PIN 3     // Buzzer connected at pin D3
#define BUTTON_PIN 4     // Push button to remove item or reset cart

MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Check your I2C address (0x27 or 0x3F)

const int NUM_TAGS = 10;
String knownUIDs[NUM_TAGS] = {
  "a33816ff", "14530104", "c1600104", "bb280004", "8c3c0004",
  "3d180004", "2e010204", "b00aface", "feed1234", "facecafe"
};
String productNames[NUM_TAGS] = {
  "Milky Bar Chocolate", "Wafers", "Dark Fantasy Chocolate", "Red Label", "Arial",
  "Little Hearts", "MoongDal", "Soda", "Apples", "Rice"
};
float productPrices[NUM_TAGS] = {
  40.00, 25.00, 45.00, 10.00, 20.00,
  5.00, 15.00, 2.00, 2.25, 5.00
};
bool itemAdded[NUM_TAGS] = {
  false, false, false, false, false,
  false, false, false, false, false
}; // Track which items are in cart

float total = 0.0;
bool removeMode = false;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  lcd.init();
  lcd.backlight();

  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Internal pull-up resistor

  lcd.setCursor(0, 0);
  lcd.print("Smart Cart");
  lcd.setCursor(0, 1);
  lcd.print("Ready to scan");
}

int findTagIndex(String uid) {
  for (int i = 0; i < NUM_TAGS; i++) {
    if (uid == knownUIDs[i]) {
      return i;
    }
  }
  return -1;
}

void blinkLED(int pin) {
  digitalWrite(pin, HIGH);
  delay(200);
  digitalWrite(pin, LOW);
}

void beepBuzzer() {
  digitalWrite(BUZZER_PIN, HIGH);
  delay(100);
  digitalWrite(BUZZER_PIN, LOW);
}

void displayCartItems() {
  int count = 0;
  for (int i = 0; i < NUM_TAGS; i++) {
    if (itemAdded[i]) count++;
  }

  if (count == 0) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Cart is Empty");
    delay(1500);
  } else {
    int shown = 0;
    for (int i = 0; i < NUM_TAGS; i++) {
      if (itemAdded[i]) {
        lcd.clear();

        // Line 1: "Item X of N"
        shown++;
        lcd.setCursor(0, 0);
        lcd.print("Item ");
        lcd.print(shown);
        lcd.print(" of ");
        lcd.print(count);

        // Line 2: "Milk   Rs.40.00"
        lcd.setCursor(0, 1);
        String line = productNames[i];
        while (line.length() < 10) line += " ";
        line += "Rs.";
        line += String(productPrices[i], 2);
        lcd.print(line);

        delay(1500);
      }
    }

    // Summary screen
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Items: ");
    lcd.print(count);
    lcd.setCursor(0, 1);
    lcd.print("Total: Rs.");
    lcd.print(total, 2);
    delay(2000);
  }

  // Return to main screen
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Total: Rs.");
  lcd.print(total, 2);
  lcd.setCursor(0, 1);
  lcd.print("Ready to scan");
}

void loop() {
  // Button check: short press = remove, long press = clear cart
  if (digitalRead(BUTTON_PIN) == LOW) {
    unsigned long pressStart = millis();
    while (digitalRead(BUTTON_PIN) == LOW) {
      if (millis() - pressStart > 2000) {
        // Long press: Clear cart
        total = 0.0;
        for (int i = 0; i < NUM_TAGS; i++) {
          itemAdded[i] = false;
        }
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Cart Cleared!");
        lcd.setCursor(0, 1);
        lcd.print("Total: Rs.0.00");
        beepBuzzer();
        blinkLED(LED_RED_PIN);
        delay(3000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Ready to scan");
        return;
      }
    }

    // Short press: Remove mode
    removeMode = true;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Remove Mode ON");
    lcd.setCursor(0, 1);
    lcd.print("Scan item...");
    delay(1000);
  }

  // RFID scan detection
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    String tagUID = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      tagUID += String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
      tagUID += String(mfrc522.uid.uidByte[i], HEX);
    }
    tagUID.toLowerCase();
    Serial.println("Scanned UID: " + tagUID);
    mfrc522.PICC_HaltA();

    beepBuzzer();

    int index = findTagIndex(tagUID);

    lcd.clear();
    lcd.setCursor(0, 0);

    if (index != -1) {
      if (removeMode && itemAdded[index]) {
        total -= productPrices[index];
        itemAdded[index] = false;
        lcd.print("Removed:");
        lcd.setCursor(0, 1);
        lcd.print(productNames[index].substring(0, 10));
        lcd.print(" Rs.-");
        lcd.print(productPrices[index], 2);
        blinkLED(LED_RED_PIN);
      } else if (!removeMode && !itemAdded[index]) {
        total += productPrices[index];
        itemAdded[index] = true;
        lcd.print("Added:");
        lcd.setCursor(0, 1);
        lcd.print(productNames[index].substring(0, 10));
        lcd.print(" Rs.");
        lcd.print(productPrices[index], 2);
        blinkLED(LED_GREEN_PIN);
      } else if (itemAdded[index] && !removeMode) {
        lcd.print("Already Added");
        lcd.setCursor(0, 1);
        lcd.print(productNames[index].substring(0, 16));
      } else if (!itemAdded[index] && removeMode) {
        lcd.print("Not in Cart");
        lcd.setCursor(0, 1);
        lcd.print(productNames[index].substring(0, 16));
      }
    } else {
      lcd.print("Unknown Card");
      lcd.setCursor(0, 1);
      lcd.print("Try Again");
    }

    delay(3000);

    // Show items and total
    displayCartItems();

    removeMode = false; // Reset mode after scan
  }
}
