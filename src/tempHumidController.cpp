/**
 * @file tempHumidController.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-11-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "tempHumidController.hpp"
#include <Arduino.h>

tempHumidController::tempHumidController(int pinNumber)
{
    this->pinNumber = pinNumber;
}

tempHumidController::~tempHumidController()
{
}

bool tempHumidController::initialize()
{
    Serial.println("Initializing temperature and humidity sensor");
    return true;
}

int tempHumidController::readTemperature()
{
    return 25;
}

int tempHumidController::readHumidity()
{
    return 50;
}