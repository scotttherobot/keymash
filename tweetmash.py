import time, sys, os, serial

def main(argv):
   f = open(argv[0])
   ser = serial.Serial(
         port=argv[1],
         baudrate=1200
   )
   if ser.isOpen():
      for line in f:
         count = 0
         for char in line:
            # The typewriter doesn't have a < character,
            # So we'll replace it with the @ since it only really ever shows
            # up before a twitter handle.
            # Word wrapping: Count characters
            # TODO: Fix word wrap so it straightens out the provided sentence
            # before wrapping in order to optimize paper usage.
            count += 1
            if count is 60:
               ser.write('|')
               count = 0
               time.sleep(1.5)
               for a in range(23):
                  ser.write(' ')
                  count += 1
                  time.sleep(.15)
            if char is '<':
               char = '@'
            ser.write(char)
            time.sleep(.15)
         time.sleep(1.5)
      #ser.write('|')
      ser.close()

if __name__ == "__main__":
   main(sys.argv[1:])
