#include <VirtualWire.h>
const int receive_pin = 2;
const int relay=3;
bool relayState =false;
void setup()
{   
    pinMode(relay,OUTPUT);
    Serial.begin(9600);  // Debugging only
    Serial.println("setup");
    vw_set_rx_pin(receive_pin);
    
    vw_setup(2000);  // Bits per sec

    vw_rx_start();       // Start the receiver PLL running
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
(relayState==true)?(digitalWrite(13,HIGH)):(digitalWrite(13,LOW));
(relayState==true)?(digitalWrite(relay,LOW)):(digitalWrite(relay,HIGH));
      
    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
  
      Serial.println(buf[0]);
      
      if(buf[0]==49){
        relayState=false;
        }
       else if(buf[0]==48){
          relayState=true;
        }
      }
    

}
