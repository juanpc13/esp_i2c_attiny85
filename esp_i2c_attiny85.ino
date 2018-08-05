#include <Wire.h>
#include "Attiny85_I2C_Slave.h"

Attiny85_I2c_Slave attiny85(0x0D); // Direccion 13

void setup() {
  Serial.begin(115200);
  delay(1000);  
  if(attiny85.begin()){
    Serial.println("Attiny85 I2C is OK");
  }  
}


void loop() {
  Attiny85_Data data = attiny85.getData();
  Serial.print("Input1 = ");
  Serial.print(data.input1);
  Serial.print(" | Input2 = ");
  Serial.print(data.input2);
  Serial.print(" | Analog = ");
  Serial.println(data.analog);
}

