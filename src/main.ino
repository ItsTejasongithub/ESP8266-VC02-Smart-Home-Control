#include <ESP8266WiFi.h>

bool fanState = false;        
bool lightState = false;      
bool lastCommandSerial = false;  
bool previousFanSwitchState = LOW;  
bool previousLightSwitchState = LOW;
bool SwitchController = false;

void setup() {
  Serial.begin(9600);  
  pinMode(D4, OUTPUT);
  pinMode(D0, OUTPUT);
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  digitalWrite(D4, 1);
  digitalWrite(D0, 1);
}

void loop() {
  unsigned int receivedValue = 0;
  if (Serial.available()) {
    byte highByte = Serial.read();
    byte lowByte = Serial.read();
    receivedValue = (highByte << 8) | lowByte;
  }

  if (receivedValue == 41251) {  
    if (fanState == false) {
      digitalWrite(D4, LOW);
      delay(1000);
      fanState = true;
      lastCommandSerial = true; 
    }
  } else if (receivedValue == 41524) {
    if (fanState == true) {
      digitalWrite(D4, HIGH);
      delay(1000);
      fanState = false; 
      lastCommandSerial = true; 
    }
  } else if (receivedValue == 41797) {  
    if (lightState == false) {
      digitalWrite(D0, LOW);
      delay(1000);
      lightState = true;
      lastCommandSerial = true; 
    }
  } else if (receivedValue == 42343) {  
    if (lightState == true) {
      digitalWrite(D0, HIGH);
      delay(1000);
      lightState = false;
      lastCommandSerial = true; 
    }
  } else if (receivedValue == 42070) {  
    SwitchController = true;
    delay(1000);
  } else if (receivedValue == 42616) {  
    SwitchController = false;
    delay(1000);
    ESP.restart(); 
  } else {
    delay(10);
  }

  if (SwitchController == true) {
    bool fanSwitchState = digitalRead(D1);
    bool lightSwitchState = digitalRead(D2);

    if (fanSwitchState == HIGH) {
      digitalWrite(D4, LOW);
      fanState = true;
      delay(1000);
    }
    if (fanSwitchState == LOW) {
      digitalWrite(D4, HIGH);
      fanState = false;
      delay(1000);
    }

    if (lightSwitchState == HIGH) {
      digitalWrite(D0, LOW);
      lightState = true;
      delay(1000);
    }
    if (lightSwitchState == LOW) {
      digitalWrite(D0, HIGH);
      lightState = false;
      delay(1000);
    }
  }
}
