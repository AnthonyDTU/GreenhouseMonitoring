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

soilMonitorController soilSensors[] = {soilSensor1, soilSensor2, soilSensor3};

// TODO: Should go into tempHumidController
int currentTemp;
int currentHumid;
int currentSoilMoisture[MAX_SOIL_SENSORS];

/// @brief Setup function for the system
void setup() {
  
  Serial.begin(9600);

  // Configure system variables
  systemConfig.setTempSetpoint(30);
  systemConfig.setHumidSetpoint(50);
  systemConfig.setNumberOfSoilSensors(1);
  for (int i = 0; i < systemConfig.getNumberOfSoilSensors(); i++)
  {
    systemConfig.setSoilSetpoint(i, 100);
  }


  // Initialize components
  motor.initialize();
  airSensor.initialize();
  for (int i = 0; i < systemConfig.getNumberOfSoilSensors(); i++)
  {
    soilSensors[i].initialize();
  }
}

/// @brief Main loop of the system
void loop() {
  
  // Read sensor values
  currentTemp = airSensor.readTemperature();
  currentHumid = airSensor.readHumidity();
  for (int i = 0; i < systemConfig.getNumberOfSoilSensors(); i++)
  {
    currentSoilMoisture[i] = soilSensors[i].readSoilMoisture();
  }

  // Window control based on temperature setpoint
  // TODO: Maybe multiple steps for opening and closing the window, not just fully open or fully closed
  if (currentTemp >= systemConfig.getTempSetpoint())
  {
    motor.openWindow();
  }
  else if (currentTemp <= systemConfig.getTempSetpoint())
  {
    motor.closeWindow();
  }

  // Soil moisture control based on setpoints
  for (int i = 0; i < systemConfig.getNumberOfSoilSensors(); i++)
  {

    if (soilSensors[i].readSoilMoisture() <= systemConfig.getSoilSetpoints(i))
    {
      // TODO: Water the plant?
    }
    else if (soilSensors[i].readSoilMoisture() > systemConfig.getSoilSetpoints(i))
    {
      // TODO: Do nothing?
    }
  }

  // TODO: Add LoRa communication to send sensor values to a remote server

  // TODO: Add LoRa Downlink to receive commands and configuration values from a remote server

  // TODO: Add ePaper display to show sensor values on the device

  // TODO: Implement a sleep mode to save power when the system is not in use



}
