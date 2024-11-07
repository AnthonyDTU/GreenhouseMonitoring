/**
 * @file soilMonitorController.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-11-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "soilMonitorController.hpp"
#include <Arduino.h>




soilMonitorController::soilMonitorController(int pinNumber)
{
    this->pinNumber = pinNumber;
}

soilMonitorController::~soilMonitorController()
{
}


bool soilMonitorController::initialize()
{
    Serial.println("Initializing soil monitor");
    pinMode(pinNumber, INPUT);
    return true;
}

int soilMonitorController::readSoilMoisture()
{
    return analogRead(pinNumber);
}


