/**
 * @file tempHumidController.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-11-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef TEMPHUMIDCONTROLLER_H
#define TEMPHUMIDCONTROLLER_H

class tempHumidController
{
    private:
        int pinNumber;
    public:
        tempHumidController(int pinNumber);
        ~tempHumidController();

        bool initialize();
        int readTemperature();
        int readHumidity();
};





#endif