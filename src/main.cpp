/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-11-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <Arduino.h>
#include "systemConfiguration.hpp"
#include "motorController.hpp"
#include "ePaperController.hpp"
#include "LoRaController.hpp"
#include "soilMonitorController.hpp"
#include "tempHumidController.hpp"


systemConfiguration systemConfig = systemConfiguration();
motorController motor(systemConfig.motorPin);



void setup() {
  
  Serial.begin(9600);
  motor.initializeMotor();
  systemConfig.setTempSetpoint(30);


}

void loop() {

  // Window control based on temperature setpoint
  if (systemConfig.getTempSetpoint() > 30)
  {
    motor.openWindow();
  }
  else if (systemConfig.getTempSetpoint() < 25)
  {
    motor.closeWindow();
  }

  motor.openWindow();

  delay(5000);
  motor.closeWindow();
  delay(5000);




}
