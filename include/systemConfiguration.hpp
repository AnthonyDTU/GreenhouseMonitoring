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
        int soilSetpoint;
        
        

    public:
        
        // Pin configuration
        const int motorPin = 3;
        

        void setTempSetpoint(int setpoint) {
            tempSetpoint = setpoint;
        }

        int getTempSetpoint(){
            return tempSetpoint;
        }


    
};


#endif