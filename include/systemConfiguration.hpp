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


class systemConfiguration
{
    private:
        /* data */
        // System Setpints
        int tempSetpoint;
        int humidSetpoint;
        int soilSetpoint_1;
        int soilSetpoint_2;
        int soilSetpoint_3;
        
        

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

        void setSoilSetpoint_1(int setpoint) {
            soilSetpoint_1 = setpoint;
        }

        void setSoilSetpoint_2(int setpoint) {
            soilSetpoint_2 = setpoint;
        }

        void setSoilSetpoint_3(int setpoint) {
            soilSetpoint_3 = setpoint;
        }

        int getTempSetpoint(){
            return tempSetpoint;
        }

        int getHumidSetpoint(){
            return humidSetpoint;
        }

        int getSoilSetpoint_1(){
            return soilSetpoint_1;
        }

        int getSoilSetpoint_2(){
            return soilSetpoint_2;
        }

        int getSoilSetpoint_3(){
            return soilSetpoint_3;
        }


    
};


#endif