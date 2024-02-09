/**********************************************************************/
/*This code is not clean and OFFCOURSE will be possible do it better! */
/*this is only a group of functions to be used as independent code,   */
/*and by this way will be possible to any person can do the changes   */
/*of code and see what happen.                                        */
/*The code don't depend of any external library or extenal functions  */
/*complicated.                                                        */
/*I'm let the values to sent as binnary, this allow swap bit by bit   */
/* to is possible test segment by segment without convert to HEX      */
/**********************************************************************/
/* This code show how is possible work with the driver SN75518 Sanyo  */
/*                                                                    */
/**********************************************************************/

#define DSP_in 7  // This is the pin number 7 on Arduino UNO
#define DSP_clk 8 // This is the pin number 8 on Arduino UNO
#define DSP_en1 9 // This is the pin number 9 on Arduino UNO
#define DSP_en2 10 // This is the pin number 10 on Arduino UNO
#define DSP_en3 11 // This is the pin number 11 on Arduino UNO
#define DSP_LED1 4 // This is the pin number 4 on Arduino UNO
#define DSP_LED2 5 // This is the pin number 5 on Arduino UNO

//ATT: On the Uno and other ATMEGA based boards, unsigned ints (unsigned integers) are the same as ints in that they store a 2 byte value.
//Long variables are extended size variables for number storage, and store 32 bits (4 bytes), from -2,147,483,648 to 2,147,483,647.

uint8_t numberOfBit =0x00;                          

void send_32_without(uint32_t a){
  uint32_t data = 170; //value to transmit, binary 10101010
  uint32_t mask = 1; //our bitmask
  data = a;
  data = (data | 0x00000);
  
  for (mask = 0b10000000000000000000; mask > 0; mask >>= 1) { //iterate through bit mask
    numberOfBit++;
    digitalWrite(DSP_clk, HIGH);
    delayMicroseconds(2);
    if (data & mask) { // if bitwise AND resolves to true
      digitalWrite(DSP_in, HIGH);
      Serial.print(1);
    }
    else { //if bitwise and resolves to false
      digitalWrite(DSP_in, LOW);
     Serial.print(0);
    }
    digitalWrite(DSP_clk, LOW);// need invert the signal to allow 8 bits is is low only send 7 bits
    delayMicroseconds(2);         
  }
  if(numberOfBit == 20){
   //only to check if you reach this point
   Serial.println("Reach 20 bits!");
  }
      
Serial.println();
Serial.println(numberOfBit, DEC);
}

void setup() {
  pinMode(DSP_clk, OUTPUT);
  pinMode(DSP_in, OUTPUT);
  pinMode(DSP_en1, OUTPUT);
  pinMode(DSP_en2, OUTPUT);
  pinMode(DSP_en3, OUTPUT);
  pinMode(DSP_LED1, OUTPUT);
  pinMode(DSP_LED2, OUTPUT);

  Serial.begin(115200); // only to debug
}
void clean(void){
  uint8_t t1 = 2;
    digitalWrite(DSP_en1, LOW);
    send_32_without(0x0FFFF);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en1, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en2, LOW);
    send_32_without(0x0FFFF);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en2, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en3, LOW);
    send_32_without(0x0FFFF);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en3, HIGH);
    delay(t1);
}
void test1(void){
    uint8_t t1 = 200;
    digitalWrite(DSP_en1, LOW);
    send_32_without(0xF0000);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en1, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en1, LOW);
    send_32_without(0xF1111);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en1, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en1, LOW);
    send_32_without(0xF2222);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en1, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en1, LOW);
    send_32_without(0xF3333);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en1, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en1, LOW);
    send_32_without(0xF4444);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en1, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en1, LOW);
    send_32_without(0xF5555);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en1, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en1, LOW);
    send_32_without(0xF6666);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en1, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en1, LOW);
    send_32_without(0xF7777);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en1, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en1, LOW);
    send_32_without(0xF8888);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en1, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en1, LOW);
    send_32_without(0xF9999);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en1, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en1, LOW);
    send_32_without(0xF0000);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en1, HIGH);
    delay(t1);
}
void test2(void){
  uint8_t t1 = 200;
    digitalWrite(DSP_en2, LOW);
    send_32_without(0xF0000);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en2, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en2, LOW);
    send_32_without(0xF1111);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en2, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en2, LOW);
    send_32_without(0xF2222);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en2, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en2, LOW);
    send_32_without(0xF3333);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en2, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en2, LOW);
    send_32_without(0xF4444);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en2, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en2, LOW);
    send_32_without(0xF5555);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en2, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en2, LOW);
    send_32_without(0xF6666);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en2, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en2, LOW);
    send_32_without(0xF7777);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en2, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en2, LOW);
    send_32_without(0xF8888);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en2, HIGH);
    
    delay(t1);
    digitalWrite(DSP_en2, LOW);
    send_32_without(0xF9999);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en2, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en2, LOW);
    send_32_without(0xF0000);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en2, HIGH);
    delay(t1);
}
void test3(void){
  uint8_t t1 = 200;
    digitalWrite(DSP_en3, LOW);
    send_32_without(0xF0000);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en3, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en3, LOW);
    send_32_without(0xF1111);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en3, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en3, LOW);
    send_32_without(0xF2222);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en3, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en3, LOW);
    send_32_without(0xF3333);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en3, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en3, LOW);
    send_32_without(0xF4444);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en3, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en3, LOW);
    send_32_without(0xF5555);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en3, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en3, LOW);
    send_32_without(0xF6666);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en3, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en3, LOW);
    send_32_without(0xF7777);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en3, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en3, LOW);
    send_32_without(0xF8888);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en3, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en3, LOW);
    send_32_without(0xF9999);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en3, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en3, LOW);
    send_32_without(0xF0000);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en3, HIGH);
    delay(t1);
}
void testNumbers(void){
  uint8_t t1 = 200;
    digitalWrite(DSP_en3, LOW);
    send_32_without(0x0FFF0);   //The first "0" on this group represent the decimal point!
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en3, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en3, LOW);
    send_32_without(0x0FF10);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en3, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en3, LOW);
    send_32_without(0x0F210);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en3, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en3, LOW);
    send_32_without(0x03210);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en3, HIGH);
    delay(t1);
    
    //Next group of 4 digits
    
    digitalWrite(DSP_en1, LOW);
    send_32_without(0x0FFF4);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en1, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en1, LOW);
    send_32_without(0x0FF54);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en1, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en1, LOW);
    send_32_without(0x0F654);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en1, HIGH);
     delay(t1);
     
    digitalWrite(DSP_en1, LOW);
    send_32_without(0x07654);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en1, HIGH);
    delay(t1);

    //Next group of 4 digits
    
    digitalWrite(DSP_en2, LOW);
    send_32_without(0x0FFF8);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en2, HIGH);
    delay(t1);
     
    digitalWrite(DSP_en2, LOW);
    send_32_without(0x0FF98);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en2, HIGH);
    delay(t1);
    
    digitalWrite(DSP_en2, LOW);
    send_32_without(0x0EE98);
    //send_32_without(0b10000100110000100001);
    digitalWrite(DSP_en2, HIGH);
    delay(t1);
}
void brightLED(void){
digitalWrite(DSP_LED1, HIGH);
digitalWrite(DSP_LED2, LOW);
delay(100);
digitalWrite(DSP_LED1, LOW);
digitalWrite(DSP_LED2, HIGH);
delay(100);
}
void loop() {
for (int s = 0; s < 4; s++){
  brightLED();  //This is a particular square with 2 Yellow LED present on this panel!!!
}

digitalWrite(DSP_LED1, LOW);
digitalWrite(DSP_LED2, LOW);

digitalWrite(DSP_en1, HIGH);
digitalWrite(DSP_en2, HIGH);
digitalWrite(DSP_en3, HIGH);
clean();
test3(); //Note please this order depend of your distributions of pin /EN 
test1(); //Note please this order depend of your distributions of pin /EN 
test2(); //Note please this order depend of your distributions of pin /EN 
clean();
testNumbers();

clean();
  numberOfBit =0x00;
    digitalWrite(DSP_en1, LOW);
    send_32_without(0xF4321);
    //send_32_without(0b10000100110000100001); //You can send it as binary format!
    delay(900);
    digitalWrite(DSP_en1, HIGH); 
}
