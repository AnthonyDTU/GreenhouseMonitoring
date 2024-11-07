#include <Arduino.h>
#include <stdio.h>
#include "motorController.hpp"
#include "ePaperController.hpp"
#include "LoRaController.hpp"
#include "soilMonitorController.hpp"
#include "tempHumidController.hpp"


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Hello World!");

}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(2000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(500);                      // wait for a second
  Serial.println("Hello World!");
}
