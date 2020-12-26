#include <Homie.h>

const int RELAY_PIN_1 = 5; // D1
const int RELAY_PIN_2 = 13; // D1

int buttonState = 0;
bool buttonPressed = false;

HomieNode relayNode1("relayNode1", "Relay One Name","switch");
HomieNode relayNode2("relayNode2", "Relay One Name","switch");

bool relay1Handler(HomieRange range, String value) {
  if (value == "on") {
    digitalWrite(RELAY_PIN_1, HIGH);
    Serial.println("RELAY_PIN_1 is on");
  } else if (value == "off") {
    digitalWrite(RELAY_PIN_1, LOW);
    Serial.println("RELAY_PIN_1 is off");
  } else {
    Serial.print("Something else received -");
    Serial.println(value);
    return false;
  }
  return true;
}

bool relay2Handler(HomieRange range, String value) {
  if (value == "on") {
    digitalWrite(RELAY_PIN_2, HIGH);
    Serial.println("RELAY_PIN_2 is on");
  } else if (value == "off") {
    digitalWrite(RELAY_PIN_2, LOW);
    Serial.println("RELAY_PIN_2 is off");
  } else {
    Serial.print("Something else received -");
    Serial.println(value);
    return false;
  }
  return true;
}

void setup() {
  pinMode(RELAY_PIN_1, OUTPUT);
  pinMode(RELAY_PIN_2, OUTPUT);

  Serial.begin(SERIAL_SPEED);
  Serial << endl << endl;
  Homie_setFirmware("awesome-button", "1.0.0");

  relayNode1.advertise("on").settable(relay1Handler);
  relayNode2.advertise("on").settable(relay2Handler);

  Homie.setup();
}

void loop() {
  Homie.loop();
}