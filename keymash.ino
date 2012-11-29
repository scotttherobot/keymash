// The control lines for the first mux 
int RA = 2;
int RB = 3;
int RC = 4;
// and the other one 
// Notice these are flipped, for cosmetic reasons on the hardware.
// I wanted the colors to line up nicely :)
int CC = 5;
int CB = 7;
int CA = 6;
// and that one control line 
int EN = 8;
// Okay, and the LED too 
int LED = 13;

// here are some function prototypes 
void touch(int row, int col);
void mash();

/////////////////////
// Keymap
////////////////////

typedef struct{
  char c;
  int row;
  int col;
}Word;

Word keys[64];





///////////////////
// The actual logic
///////////////////

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
 
 Serial.println("System ready. Starting 10 second delay.");
 // Wait for some time and then mash the keys, for testing.
 delay(10000);
 Serial.println("Starting mash(). Type a character to increment the row/col.");
 mash();
}

void loop(){

  
}

void touch(int row, int col){
  
  // Use a bitmask to check the "ones" bit
  // and then write it to the mux
  int w = row & B001;
  digitalWrite(RA, w);
  Serial.print(w);
  // Do the same for the "twos" bit and then shift it over
  // to the "ones" position so it's a binary 1
  w = (row & B010) >> 1;
  digitalWrite(RB, w);
  Serial.print(w);
  // And again for the "fours" bit, remembering to shift it over
  w = (row & B100) >> 2;
  digitalWrite(RC, w);
  Serial.print(w);
  Serial.print("  ");
  // Same as the above block but for the other mux
  // so go read it there. 
  w = col & B001;
  digitalWrite(CA, w);
  Serial.print(w);
  w = (col & B010) >> 1;
  digitalWrite(CB, w);
  Serial.print(w);
  w = (col & B100) >> 2;
  digitalWrite(CC, w);
  Serial.print(w);
  Serial.print("\n");
  
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

void mash(){
 // This loops through every combo of keypresses
 // and presses them, "mashing" on the keyboard
 // It doesn't step through the loop until you 
 // send a character over serial as a trigger.
 int r;
 int c;
 for(r = 0; r < 8; r++){
  for(c = 0; c < 8; c++){
    // here's where we wait for serial data 

    while(!Serial.available()){
    }
    Serial.read();
    // And now we actually make the connection 
    // and print a little verification
    touch(r, c);
    Serial.print("r ");
    Serial.print(r);
    Serial.print("   c ");
    Serial.print(c);
    Serial.print("\n");
    // Wait a bit so you don't send too many presses 
    delay(1000);
  }
 } 
  
}
