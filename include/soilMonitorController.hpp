/**
 * @file soilMonitorController.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-11-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#ifndef SOILMONITORCONTROLLER_H
#define SOILMONITORCONTROLLER_H


class soilMonitorController
{
private:
    int pinNumber;
public:
    soilMonitorController(int pinNumber);
    ~soilMonitorController();

    bool initialize();
    int readSoilMoisture();

};






#endif