#include <SoftwareSerial.h>

SoftwareSerial mySerial(5, 2);  // RX, TX

int DE = 3;
int RE = 4;

void setup() {
  Serial.begin(9600);
  mySerial.begin(4800);
  pinMode(DE, OUTPUT);
  pinMode(RE, OUTPUT);
  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == 'b') {
      byte queryData[]{ 0x01, 0x03, 0x00, 0x00, 0x00, 0x07, 0x04, 0x08 };
      byte receivedData[19];

      digitalWrite(DE, HIGH);
      digitalWrite(RE, HIGH);
      mySerial.write(queryData, sizeof(queryData));  // Send query to NPK sensor
      digitalWrite(DE, LOW);
      digitalWrite(RE, LOW);
      delay(1000);

      if (mySerial.available() >= sizeof(receivedData)) {
        mySerial.readBytes(receivedData, sizeof(receivedData));

        unsigned int soilHumidity = (receivedData[3] << 8) | receivedData[4];
        unsigned int soilTemperature = (receivedData[5] << 8) | receivedData[6];
        unsigned int soilConductivity = (receivedData[7] << 8) | receivedData[8];
        unsigned int soilPH = (receivedData[9] << 8) | receivedData[10];
        unsigned int nitrogen = (receivedData[11] << 8) | receivedData[12];
        unsigned int phosphorus = (receivedData[13] << 8) | receivedData[14];
        unsigned int potassium = (receivedData[15] << 8) | receivedData[16];

        Serial.print("Soil Humidity: ");
        Serial.println((float)soilHumidity / 10.0);
        Serial.print("Soil Temperature: ");
        Serial.println((float)soilTemperature / 10.0);
        Serial.print("Soil Conductivity: ");
        Serial.println(soilConductivity);
        Serial.print("Soil pH: ");
        Serial.println((float)soilPH / 10.0);
        Serial.print("Nitrogen: ");
        Serial.println(nitrogen);
        Serial.print("Phosphorus: ");
        Serial.println(phosphorus);
        Serial.print("Potassium: ");
        Serial.println(potassium);
        //Serial.println("\n\n");
      }
    }
  }
}
