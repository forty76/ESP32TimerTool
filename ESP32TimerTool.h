#pragma once

#include <Arduino.h>


namespace ESP32TimerTool
{
    class OneShotTimer
    {
    private:        
        hw_timer_t *Timerbase = NULL;
        
    public:

        OneShotTimer();
        ~OneShotTimer();

        void begin(voidFuncPtr userFunc);
        void trigger(int32_t timerdelay);
        void stop();    

        


    };
}