#include <VirtualWire.h>
const int transmit_pin = 2;
int switch_pin1=7;
int switch_pin2=9;
int switch_pin3=8;
 void setup(){
  Serial.begin(9600);
  pinMode(switch_pin2,INPUT_PULLUP);
  pinMode(switch_pin1,INPUT_PULLUP);
  pinMode(switch_pin3,INPUT_PULLUP);
  vw_set_tx_pin(transmit_pin);
  vw_setup(2000);   // Bits per sec
 }
void loop(){
  int mode=0;
  int val1=digitalRead(switch_pin1);
  int val2=digitalRead(switch_pin2);
  int val3=digitalRead(switch_pin3);
  Serial.print(val1);
  Serial.print(",");
  Serial.print(val2);
  Serial.print(",");
  Serial.println(val3);
  if(val1!=0||val2!=0||val3!=0){
    alarm(1);
  }
  else{
    alarm(0);
  }
  delay(100);
}


void alarm(bool flag){
if(flag==true){
char *msg = "1"; 
digitalWrite(13, HIGH); // Flash a light to show transmitting
  vw_send((uint8_t *)msg,strlen (msg));
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(13, LOW);
  delay(100); 
}
if(flag==false){
 char *msg = "0"; 

  vw_send((uint8_t *)msg,strlen (msg));
  vw_wait_tx(); // Wait until the whole message is gone
 delay(100); 
  }

}
