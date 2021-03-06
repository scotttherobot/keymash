import time, sys, os, serial

def main(argv):
	os.system('clear')
	print ' __________________________ '
	print '| Welcome to the keymasher |'
	print ' --------------------------\n'
	print 'The input file you have chosen is ' + argv[0] + '\n'
	print 'The serial port you have chosen is ' + argv[1] + '\n'
	print 'BAUD RATE IS 9600!!'
	f = open(argv[0])
	print 'If the file is greater than 60 columns wide, there may be trouble.'
	#print 'Please press the inhibit button to prevent garbage being printed as the port opens.'
	print 'Print? [y/n]'
	if raw_input("> ") == 'y':
		# Open a serial port
		ser = serial.Serial(
			port=argv[1],
			baudrate=9600
		)
		# ser.open()
		if ser.isOpen():
			print 'The port was opened successfully.'
			#mes = ser.readline()
			#print 'The printer says: ' + mes
			#print 'Print? [press any key]'
			#m = raw_input("> ")
			for line in f:
				print line
				for char in line:
					ser.write(char)
					time.sleep(.15)
				#ser.write('|')
				#print '\n'
				time.sleep(1.5)
			ser.write('|')
			ser.close()
			if not ser.isOpen():
				print 'It appears the job is done. Goodbye.'
		else:
			print 'There was an error opening the port. Goodbye.'
	else:
		print 'Okay.... Bye then.'
	
if __name__ == "__main__":
	main(sys.argv[1:])
	
	
