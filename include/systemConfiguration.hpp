/**
 * @file systemConfiguration.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-11-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#ifndef SYSTEMCONFIGURATION_H
#define SYSTEMCONFIGURATION_H

#define MAX_SOIL_SENSORS 10

class systemConfiguration
{
    private:
        /* data */
        // System Setpints
        int tempSetpoint;
        int humidSetpoint;
        int numberOfSoilSensors;
        int soilSetpoints[MAX_SOIL_SENSORS];
        

    public:
        
        // Pin configuration
        const int DHT11Pin = 1;
        const int motorPin = 3;
        const int soilMonitorPin1 = 4;
        const int soilMonitorPin2 = 5;
        const int soilMonitorPin3 = 6;

        void setTempSetpoint(int setpoint) {
            tempSetpoint = setpoint;
        }

        void setHumidSetpoint(int setpoint) {
            humidSetpoint = setpoint;
        }

        void setSoilSetpoint(int sensorIndex, int setpoint) {
            soilSetpoints[sensorIndex] = setpoint;
        }

        void setNumberOfSoilSensors(int number) {
            numberOfSoilSensors = number;
        }

        int getTempSetpoint(){
            return tempSetpoint;
        }

        int getHumidSetpoint(){
            return humidSetpoint;
        }

        int getSoilSetpoints(int sensorIndex) {
            return soilSetpoints[sensorIndex];
        }

        int getNumberOfSoilSensors(){
            return numberOfSoilSensors;
        }


    
};


#endif