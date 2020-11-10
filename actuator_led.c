#include <Wire.h>
#define SLAVE_ADDRESS 0x06
#define LED A2

byte z = 10;
int state = 0;
int instr_number;
void setup(void) {
  pinMode(LED, OUTPUT);
  digitalWrite(LED,LOW);
  analogWrite(A7, 255);
  analogWrite(A7, 0);
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(instrNum);
}
  
void loop(){
}
void instrNum(int byteCount){
  while(Wire.available()) {
    instr_number = Wire.read();
    Serial.print("data received: ");
    Serial.println(instr_number);
    if (instr_number == 1){
      sendType();
    }
    else if (instr_number == 2){
      on();
    }

    else if (instr_number == 3){
      off();
    }
    else if (instr_number == 4){
      Wire.onRequest(State);
    }
  }
}
void sendType() {
  int type = 2;
  Wire.write(type);
}
void on() {
  digitalWrite(LED, HIGH);
  state = 1;
  Serial.println("on");
  return state;
}
void off(){
  digitalWrite(LED, LOW);
  state = 0; 
  Serial.println("off");
  return state;
}
void State(){
  Wire.write((int)state);
}
