#include <SPI.h>
#include <LoRa.h>

const int buttonPin1 = 7;
const int buttonPin2 = 8;
const int potPin = A0;

int buttonState1 = 0;
int buttonState2 = 0;
int lastButtonState1 = LOW;
int lastButtonState2 = LOW;
bool relayState1 = false;
bool relayState2 = false;

void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");
  if (!LoRa.begin(525E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  // Lecture des boutons
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  // Bouton 1
  if (buttonState1 == HIGH && lastButtonState1 == LOW) {
    relayState1 = !relayState1;
    sendMessage(relayState1 ? "RELAY1_ON" : "RELAY1_OFF");
    delay(50);  // Éviter les rebonds
  }

  // Bouton 2
  if (buttonState2 == HIGH && lastButtonState2 == LOW) {
    relayState2 = !relayState2;
    sendMessage(relayState2 ? "RELAY2_ON" : "RELAY2_OFF");
    delay(50);
  }

  // Mise à jour des derniers états
  lastButtonState1 = buttonState1;
  lastButtonState2 = buttonState2;

  // Lecture et envoi de la position du potentiomètre
  int potValue = analogRead(potPin);
  int position = map(potValue, 0, 1023, 0, 99);
  sendMessage(String("POT:") + position);
  
  delay(100);  // Attendre avant la prochaine lecture
}

void sendMessage(String message) {
  LoRa.beginPacket();
  LoRa.print(message);
  LoRa.endPacket();
  Serial.println("Message envoyé: " + message);
}
