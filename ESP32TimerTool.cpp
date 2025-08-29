#include "ESP32TimerTool.h"



namespace ESP32TimerTool
{

    OneShotTimer::OneShotTimer()
    {
    }
  
    OneShotTimer::~OneShotTimer()
    {
    }
    
    void OneShotTimer::begin(voidFuncPtr userFunc)
    {
        Timerbase = timerBegin(1000000);               
        timerAttachInterruptArg(Timerbase, (voidFuncPtrArg)userFunc,NULL);
        timerStop(Timerbase); 
        timerRestart(Timerbase);

    }


    void OneShotTimer::stop()
    {
        timerStop(Timerbase);
        timerRestart(Timerbase);
    }

    void OneShotTimer::trigger(int32_t timerdelay)
    {        
        timerStop(Timerbase);
        timerRestart(Timerbase);
        timerAlarm(Timerbase,timerdelay,false,0);        
        timerStart(Timerbase);
    }


}
