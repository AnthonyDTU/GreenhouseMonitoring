/**
 * @file motorController.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-11-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */



#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include <Servo.h>

class motorController
{
    private:
        int motorPin;
        Servo servo;

    public:
        motorController(int motorPin);
        ~motorController();

        bool initializeMotor();
        bool openWindow();
        bool closeWindow();


};




#endif