import time, sys, os, serial

def main(argv):
	f = open(argv[0])
	if 1 == 1:
		ser = serial.Serial(
			port=argv[1],
			baudrate=9600
		)
		if ser.isOpen():
			for line in f:
            #print line
				for char in line:
					ser.write(char)
					time.sleep(.15)
				time.sleep(1.5)
			ser.write('|')
			ser.close()
	
if __name__ == "__main__":
	main(sys.argv[1:])
	
	
