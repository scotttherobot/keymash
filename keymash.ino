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
void printc(char c);

/////////////////////
// Keymap
////////////////////

typedef struct{
  char c;
  int row;
  int col;
}Letter;

Letter let[64];





///////////////////
// The actual logic
///////////////////

void setup(){
  /// keymap
  let[0] = (Letter) {'k', 0, 0}; //
  //let[1] = (Letter) {'y', 0, 1}; // END OF LINE
  let[2] = (Letter) {'7', 0, 2};
  //let[3] = (Letter) {'', 0, 3}; // ?????????????
  let[4] = (Letter) {'u', 0, 4}; //
  let[5] = (Letter) {'~', 0, 5}; // CAPS LOCK
  //let[6] = (Letter) {'', 0, 6}; // BEEP
  //let[7] = (Letter) {'$', 0, 7}; // SHIFT
  
  let[8] = (Letter) {'m', 1, 0}; //
  let[9] = (Letter) {'r', 1, 1}; //
  let[10] = (Letter) {'-', 1, 2}; //
  let[11] = (Letter) {'v', 1, 3}; //
  let[12] = (Letter) {'½', 1, 4}; //
  let[13] = (Letter) {'f', 1, 5}; //
  let[14] = (Letter) {'4', 1, 6}; //
  let[15] = (Letter) {' ', 1, 7}; // SPACE

  let[16] = (Letter) {';', 2, 0}; //
  let[17] = (Letter) {'w', 2, 1}; //
  let[18] = (Letter) {'9', 2, 2}; //
  let[19] = (Letter) {'x', 2, 3}; //
  let[20] = (Letter) {'o', 2, 4}; // 
  let[21] = (Letter) {'s', 2, 5}; //
  let[22] = (Letter) {'2', 2, 6}; //
  //let[23] = (Letter) {'', 2, 7}; //?????
  
  let[24] = (Letter) {'.', 3, 0}; //
  let[25] = (Letter) {'y', 3, 1}; //
 // let[26] = (Letter) {' ', 3, 2}; // BACKSPACE
  let[27] = (Letter) {'n', 3, 3}; //
  let[28] = (Letter) {'j', 3, 4}; // 
  let[29] = (Letter) {'h', 3, 5}; //
  let[30] = (Letter) {'6', 3, 6}; //
  //let[31] = (Letter) {' ', 3, 7}; // ERASE A CHAR
  
  let[32] = (Letter) {'l', 4, 0}; //
  let[33] = (Letter) {'q', 4, 1}; //
  let[34] = (Letter) {'8', 4, 2}; //
  let[35] = (Letter) {'z', 4, 3}; //
  let[36] = (Letter) {'i', 4, 4}; // 
  let[37] = (Letter) {'a', 4, 5}; //
  let[38] = (Letter) {'1', 4, 6}; //
  let[39] = (Letter) {'/', 4, 7}; //
  
  let[40] = (Letter) {',', 5, 0}; //
  let[41] = (Letter) {'t', 5, 1}; //
  let[42] = (Letter) {'=', 5, 2}; //
  let[43] = (Letter) {'b', 5, 3}; //
  let[44] = (Letter) {'|', 5, 4}; // LINE RETURN \n
  let[45] = (Letter) {'g', 5, 5}; //
  let[46] = (Letter) {'5', 5, 6}; //
  //let[47] = (Letter) {'', 5, 7}; // WORDERASE
  
  let[48] = (Letter) {'\'', 6, 0}; //
  let[49] = (Letter) {'e', 6, 1}; //
  let[50] = (Letter) {'0', 6, 2}; //
  let[51] = (Letter) {'c', 6, 3}; //
  let[52] = (Letter) {'p', 6, 4}; // 
  let[53] = (Letter) {'d', 6, 5}; //
  let[54] = (Letter) {'3', 6, 6}; //
  //let[55] = (Letter) {'$', 6, 7}; // BEEP
  
  // ASCII support for newline, carriage return
  let[55] = (Letter) {10, 5, 4};
  let[56] = (Letter) {13, 5, 4};
  // ASCII/VT100 support for Delete
  let[57] = (Letter) {127, 3, 7};
  
 // Turn the LED on to show that setup is happening
 pinMode(LED, OUTPUT);
 digitalWrite(LED, LOW);
 // Setup the serial port to echo row/col as we mash
 // (get some serial up in here, up in here)
 Serial.begin(1200); 
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
 touch(0,0);
 
 Serial.println("System ready.\n");


}

void loop(){
//mash();
char c;
while(!Serial.available()){
}
c = Serial.read();
printc(c);
}

void printc(char c){
  if(c>64 && c<91){
     printc('~');
     printc(c + 32);
     printc('~');
  }
  else{
    switch(c){
      case ':':
        printc('~');
        printc(';');
        printc('~');
        break;
      case '"':
        printc('~');
        printc('\'');
        printc('~');
        break;
      case '?':
        printc('~');
        printc('/');
        printc('~');
        break;
      case '+':
        printc('~');
        printc('=');
        printc('~');
        break;
      case '_':
        printc('~');
        printc('-');
        printc('~');
        break;
      case ')':
        printc('~');
        printc('0');
        printc('~');
        break;
      case '(':
        printc('~');
        printc('9');
        printc('~');
        break;
      case '*':
        printc('~');
        printc('8');
        printc('~');
        break;
      case '&':
        printc('~');
        printc('7');
        printc('~');
        break;
      case '^':
        printc('~');
        printc('6');
        printc('~');
        break;
      case '%':
        printc('~');
        printc('5');
        printc('~');
        break;
      case '$':
        printc('~');
        printc('4');
        printc('~');
        break;
      case '#':
        printc('~');
        printc('3');
        printc('~');
        break;
      case '@':
        printc('~');
        printc('2');
        printc('~');
        break;
      case '!':
        printc('~');
        printc('1');
        printc('~');
        break;
      default:
        int i;
        for(i=0; i < 64; i++){
         if(let[i].c == c){
          touch(let[i].row, let[i].col);
          Serial.print(c);
          break;
         } 
        }
  }
      
  }
  
  
  
  
}

void touch(int row, int col){
  
  // Use a bitmask to check the "ones" bit
  // and then write it to the mux
  int w = row & B001;
  digitalWrite(RA, w);
 // Serial.print(w);
  // Do the same for the "twos" bit and then shift it over
  // to the "ones" position so it's a binary 1
  w = (row & B010) >> 1;
  digitalWrite(RB, w);
 // Serial.print(w);
  // And again for the "fours" bit, remembering to shift it over
  w = (row & B100) >> 2;
  digitalWrite(RC, w);
 // Serial.print(w);
  //Serial.print("  ");
  // Same as the above block but for the other mux
  // so go read it there. 
  w = col & B001;
  digitalWrite(CA, w);
 // Serial.print(w);
  w = (col & B010) >> 1;
  digitalWrite(CB, w);
//  Serial.print(w);
  w = (col & B100) >> 2;
  digitalWrite(CC, w);
//  Serial.print(w);
  //Serial.print("\n");
  
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
  
  delay(20); // unpress for 20ms
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
    delay(10);
  }
 } 
  
}
