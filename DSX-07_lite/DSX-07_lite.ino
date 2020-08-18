/*  Name project : DSX Motor RC
 *  Code project : DSX-07_lite
 *  Version      : v 1.0
 *  By @ahul07
 */
 
/* Before verify/upload, don't forget to install the libraries
 * go to sketch >> Include Library >> Add .ZIP File >> Select the Downloaded ZIP fiels From the Above links 
 */
  
/*
 ************************************************************************************************************** 
 * Credit : Thanks Allah SWT., Nabi Muhammad SAW., Thanks My Mother & My Father, Thanks My Brother; and Thanks* 
 *          My Friends electrical enginneering'19 usk Syiah Kuala University                                  *
 *                                                                                                            *
 **************************************************************************************************************          
 */

#include <DSXLite.h>
#include <IRremote.h>

//ピンモーターに入る
DSX_pinMotors motors(2,3,4,5);

//IRセンサーピン宣言
#define IRsensor A0
IRrecv button_remote(IRsensor);
decode_results remote_code;

void setup() {
  motors.pinMotors(); //モーターピン宣言
  //IRリモート機能
  Serial.begin(9600);
  button_remote.enableIRIn();
  Serial.println("Enabled IRin");
  
}

void loop() {
  if (button_remote.decode(&remote_code)){
    switch (remote_code.value){
      case 551485695:
          motors.forward(); //前進する()
          break;
      case 551518335:
          motors.backward(); //後ろに移動()
          break;
      case 551534655:
          motors.turnLeft(); //左折してください()
          break;
      case 551502015:
          motors.turnRight(); //右に曲がる()
          break;
      case 551494365:
          motors.stops(); //移動停止()
          break;
    }
   
    Serial.println(remote_code.value);
    button_remote.resume();
  }

}
