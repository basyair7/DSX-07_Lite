#include <IRremote.h>

#define IRsensor A0
IRrecv button_remote(IRsensor);
decode_results remote_code;

void setup(){
    Serial.begin(9600);
    button_remote.enableIRIn();
    Serial.println("Enable IRin");

}

void loop(){
   if (button_remote.decode(&remote_code)){
      Serial.println(remote_code.value);
      button_remote.resume();
   }
}
