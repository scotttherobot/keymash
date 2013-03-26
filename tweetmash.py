import time, sys, re, os, serial

class Tweet:
	author = ''
	message = ''
	def __init__(self, a, m):
		self.author = a
		self.message = m

def main(argv):
#def printTweets(cols):
	cols = 65
	left = 20
	tweets = []
	f = open(argv[0]).read().replace('\n', ' ')
	raw = f.split()
	# Let's parse all the incoming tweets and put them in a list
	for tok in raw:
		if tok.startswith('<') and tok.endswith('>'):
			tok = '@' + tok[1:-1]
			tweets.append(Tweet(tok, ''))
		else:
			tweets[-1].message = " ".join([tweets[-1].message,tok])

	# Now to send them to the typewriter, prettified
	ser = serial.Serial(
		port=argv[1],
		baudrate=1200
	)	
	if ser.isOpen():
		for t in tweets:
			count = 0
			# Print the author's name
			for c in t.author:
				count += 1
				ser.write(c)
				time.sleep(.15)
			# Some whitespace to make a divider
			while (count < left):
				ser.write(' ')
				count +=1
				time.sleep(.15)
			
			# Now to print the actual tweet
			words = t.message.split()
			for word in words:
				proj = len(word) + count	
				if count < cols:
					for c in word:
						ser.write(c)
						time.sleep(.15)
						count += 1
				else:
					ser.write('|')
					time.sleep(1.5)
					count = 0
					while (count < left):
						ser.write(' ')
						count += 1
						time.sleep(.15)
					for c in word:
						ser.write(c)
						count += 1
						time.sleep(.15)
				ser.write(' ')
				count += 1
				time.sleep(.15)
			# After that tweet's done, go to a new line for the next
			ser.write('|')
			time.sleep(1.5)
	ser.close()

if __name__ == "__main__":
	main(sys.argv[1:])
