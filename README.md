Keymash
=======

Creating a teleterminal using a typewriter and an Arduino. Work in progress.

How It Works
------------
A set of multiplexers are connected to the column and row lines of the typewriter's
keyboard input. Keypresses are simulated by selecting a row and column and electrically
connecting them together.

Current State
-------------
This script is a diagnostic mode. It will enter a "mash" mode where it waits for a 
character over serial. Upon receipt of any data, it will press a key. When it gets 
the next byte, it presses the next key in the matrix, eventually sequencing through
all rows and columns. This is a debug mode to test the hardware design.