import time, sys, os, serial

def main(argv):
	os.system('clear')
	print ' ____________________________ '
	print '| Welcome to the tweetmasher |'
	print ' ----------------------------\n'
	print 'The serial port you have chosen is ' + argv[0] + '\n'
	tweet = raw_input() #argv[1]
	
	ser = serial.Serial(
		port=argv[0],
		baudrate=1200
	)
	# ser.open()
	if ser.isOpen():
		mes = ser.readline()
		print 'The printer says: ' + mes
		count = 0
		for char in tweet:
			ser.write(char)
			print char
			count = count + 1
			time.sleep(.25)
			if count == 60:
				count = 0
				ser.write('|')
				time.sleep(1.5)
		ser.close()
		if ser.isOpen() == 0:
			print 'It appears the job is done. Goodbye.'
	else:
		print 'There was an error opening the port. Goodbye.'
	
if __name__ == "__main__":
	main(sys.argv[1:])
	
	
