
#include <Arduino.h>
#include "ESP32TimerTool.h"

using namespace ESP32TimerTool;

portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

OneShotTimer timerint;
hw_timer_t *timer = NULL;
uint64_t rtime = 0;

bool th_isr = false;


void ARDUINO_ISR_ATTR TimerHandler()
{
    portENTER_CRITICAL_ISR(&timerMux);
    th_isr = true;    
    portEXIT_CRITICAL_ISR(&timerMux);
    
}

void setup() 
{
  Serial.begin(115200);
  delay(1000);
  Serial.println("Inizio setup");
  timerint.begin(&TimerHandler);


  Serial.println("Aspetto trigger");
  
}



void loop()
{
   
   if (th_isr)
   {
        Serial.printf("millis inizio  %d \n",millis());
        Serial.println("E scattato trigger");
        th_isr = false;



   } 
   if (Serial.available() > 0)
   {
     
     Serial.println("tasto premuto        attivo trigger");
     char val = Serial.read();
     if (val == 0x31)
     {
        Serial.print("val  ");
        Serial.println(val,HEX);
       timerint.stop();
       // timerbase can use read if public
       //rtime = timerReadMicros(timerint.Timerbase);
       //Serial.printf("dopo stop rtime %d \n",rtime);

     }
     else
     {
        //rtime = timerReadMicros(timerint.Timerbase);
        //Serial.printf("prima trigger rtime %d \n",rtime);
        timerint.trigger(2000000);
        Serial.printf("millis inizio  %d \n",millis());
        
     }
     

   }





}