/*
 *  It is critical to note the following:
 *    for analogueRead(), the pin numbers DO NOT
 *    match their pinout numbers on the board.
 *    This is ONLY TRUE FOR analogRead()/analogWrite() and
 *    this is NOT TRUE FOR digitalRead()/digitalWrite()!!!
 *    For some reason, the actual numbers for 
 *    analogRead/Write() are...
 *      1 = P2
 *      2 = P4
 *      3 = P3
 *      4 = N/A
 *      0 = P5
 *
 *    For this reason, the numbers below may seem to
 *    conflict (i.e. L3 and LED).
 *
 *  For more info: https://learn.adafruit.com/introducing-trinket/programming-with-arduino-ide
 */
int L3 = 1; // P2
int R3 = 3; // P3
int RB_A = 2; // P4   
int RB_D = 4; // P4   
int LED = 1;
int cool = 0;
bool active = false;
bool oldOn = false;

void setup() {
  /*  Don't need to setup these pins for analogue input on the Digistump ATtiny85 board
  pinMode(L3, INPUT);
  pinMode(RB, INPUT);
  pinMode(R3, INPUT);
  */
  pinMode(LED, OUTPUT);
}

void loop(){
  int L3sig = analogRead(L3);
  
  if (analogRead(L3) < 50 && analogRead(R3) < 50){
    if (oldOn == false){
      if (active == false){
        active = true;
        digitalWrite(LED, HIGH);
      }
      else{
        active = false;
        digitalWrite(LED, LOW);
      }
      oldOn = true;
      delay(500);
    }
  }
  else{
    oldOn = false;
  }
  
  pinMode(RB_D, INPUT);
  int sig = analogRead(RB_A);
    
  if (active == true){
    pinMode(RB_D, OUTPUT);
    analogWrite(RB_D, 1000);
    delay(22);
    pinMode(RB_D, INPUT);
    delay(100);
  }

  if (active == true){
    int chicken = 4;
  }
  else if (active == false){
    pinMode(RB_D, INPUT);
  }
  else if (sig > 150 || sig == 0 && active == false){
    pinMode(RB_D, INPUT);
  }
}

