/**
 * @file motorController.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-11-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "motorController.hpp"
#include <Arduino.h>
#include <Servo.h>



bool motorController::initialize()
{
    Serial.println("Initializing motor");
    servo.attach(motorPin);
    return true;
}


bool motorController::openWindow()
{
    Serial.println("Opening window");
    servo.write(180);
    return true;
}

bool motorController::closeWindow()
{
    Serial.println("Closing window");
    servo.write(0);
    return true;
}


motorController::motorController(int motorPin)
{
    this->motorPin = motorPin;


}

motorController::~motorController()
{
}