/* The control lines for the first mux */
int RA = 2;
int RB = 3;
int RC = 4;
/* and the other one */
int CA = 5;
int CB = 6;
int CC = 7;
/* and that one control line */
int EN = 8;
/* Okay, and the LED too */
int LED = 13;

void setup(){
 // Turn the LED on to show that setup is happening
 pinMode(LED, OUTPUT);
 digitalWrite(LED, LOW);
 // Setup the serial port to echo row/col as we mash
 // (get some serial up in here, up in here)
 Serial.begin(57600); 
 // and pull the enable pin high
 // to inhibit connections
 pinMode(EN, OUTPUT);
 digitalWrite(EN, HIGH);
 // Set the pins above up to be outputs
 // in order to control the muxes
 pinMode(RA, OUTPUT);
 pinMode(RB, OUTPUT);
 pinMode(RC, OUTPUT);
 pinMode(CA, OUTPUT);
 pinMode(CB, OUTPUT);
 pinMode(CC, OUTPUT);
 // turn the LED off to signal that everything's good.
 digitalWrite(LED, LOW);
 
 
 // Wait for some time and then mash the keys, for testing.
 delay(10000);
 mash();
}

void loop(){

  
}

touch(int row, int col){
  
  // Use a bitmask to check the "ones" bit
  // and then write it to the mux
  int w = row & B001;
  digitalWrite(RA, w);
  // Do the same for the "twos" bit and then shift it over
  // to the "ones" position so it's a binary 1
  w = (row & B010) >> 1;
  digitalWrite(RB, w);
  // And again for the "fours" bit, remembering to shift it over
  w = (row & B100) >> 2;
  digitalWrite(RC, w);
  
  // Same as the above block but for the other mux
  // so go read it there. 
  w = in & B001;
  digitalWrite(CA, w);
  w = (in & B010) >> 1;
  digitalWrite(CB, w);
  w = (in B B100) >> 2;
  digitalWrite(CC, w);
  
  // Pull the enable pin low to make the connection
  // Also, flash the LED for good measure to show that 
  // a keypress is being sent
  digitalWrite(LED, HIGH);
  digitalWrite(EN, LOW);
  // press it for 100 ms
  delay(100); 
  // Pull the EN high again to "release" the key.
  // and turn the LED off because we're donezo
  digitalWrite(EN, HIGH);
  digitalWrite(LED, LOW);
}

mash(){
 // This loops through every combo of keypresses
 // and presses them, "mashing" on the keyboard
 int r;
 int c;
 for(r = 0; r < 8; r++){
  for(c = 0; c < 8; c++){
    touch(r, c);
    Serial.println("r ");
    Serial.print(r);
    Serial.print("   c ");
    Serial.print(c);
    
    // Wait a second so you can see what's happening 
    delay(1000);
  }
 } 
  
}
