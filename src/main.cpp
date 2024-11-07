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
tempHumidController airSensor(systemConfig.DHT11Pin);
soilMonitorController soilSensor1(systemConfig.soilMonitorPin1);
soilMonitorController soilSensor2(systemConfig.soilMonitorPin2);
soilMonitorController soilSensor3(systemConfig.soilMonitorPin3);

// TODO: Should go into tempHumidController
int currentTemp = 25;

void setup() {
  
  Serial.begin(9600);
  motor.initialize();
  airSensor.initialize();
  soilSensor1.initialize();
  // soilSensor2.initialize();
  // soilSensor3.initialize();

  systemConfig.setTempSetpoint(30);
  systemConfig.setHumidSetpoint(50);
  systemConfig.setSoilSetpoint_1(100);
  // systemConfig.setSoilSetpoint_2(200);
  // systemConfig.setSoilSetpoint_3(300);

}

void loop() {
  
  // Window control based on temperature setpoint
  // TODO: Maybe multiple steps for opening and closing the window, not just fully open or fully closed
  currentTemp = airSensor.readTemperature();
  if (currentTemp >= systemConfig.getTempSetpoint())
  {
    motor.openWindow();
  }
  else if (currentTemp <= systemConfig.getTempSetpoint())
  {
    motor.closeWindow();
  }






}
