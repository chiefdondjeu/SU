import string
from typing import List

# returns the position of an alphabetic char in sequence 0 ~ 25
def indexOf(ch):
	if ch == '0':	# this part only used by TTH
		return 0
	return ord(ch)-ord('a')

def displayOutput(text, answer):
	print(f"\n{text}:\n{answer}")
	f = open("output.txt", "w")
	f.write(answer)
	f.close()


class Caesar:
	def __init__(self, msg, key, cipher):
		self.plaintext = msg
		self.key = int(key)	# int
		self.ciphertext = cipher
	
	def encrypt(self):
		temp = ""
		for ch in self.plaintext:
			temp += self.__encrypt(ch)

		displayOutput("ciphertext", temp)
	
	def decrypt(self):
		temp = ""
		for ch in self.ciphertext:
			temp += self.__decrypt(ch)
		
		displayOutput("plaintext", temp)
	
	def __encrypt(self, ch):
		if ch >= 'a' and ch <= 'z':
			if ord(ch)+self.key <= ord('z'):
				return chr(ord(ch)+self.key)
			else:
				return chr(ord(ch)+self.key-26)
		elif ch >= 'A' and ch <= 'Z':
			if ord(ch)+self.key <= ord('Z'):
				return chr(ord(ch)+self.key)
			else:
				return chr(ord(ch)+self.key-26)
		else:
			return ch
	
	def __decrypt(self, ch):
		if ch >= 'a' and ch <= 'z':
			if ord(ch)-self.key >= ord('a'):
				return chr(ord(ch)-self.key)
			else:
				return chr(ord(ch)-self.key+26)
		elif ch >= 'A' and ch <= 'Z':
			if ord(ch)-self.key >= ord('A'):
				return chr(ord(ch)-self.key)
			else:
				return chr(ord(ch)-self.key+26)
		else:
			return ch

class Monoalphabetic:
	def __init__(self, msg, kw, cipher):
		self.plaintext = msg
		self.key = self.__setkey(kw)
		self.ciphertext = cipher
	
	# adds missing alphabet char from key
	def __setkey(self, kw):
		map = kw
		for ch in string.ascii_lowercase:
			if ch not in kw:
				map += ch
		print(f"\ngenerated key ({map.lower()})")
		return map.lower()
	
	def encrypt(self):
		temp = ""
		for ch in self.plaintext:
			if ch >= 'a' and ch <= 'z':
				temp += self.key[indexOf(ch)]
			elif ch >= 'A' and ch <= 'Z':
				temp += chr(ord(self.key[indexOf(chr(ord(ch)+32))])-32)
			else:
				temp += ch

		displayOutput("ciphertext", temp)
	
	def decrypt(self):
		temp = ""
		for ch in self.ciphertext:
			if ch >= 'a' and ch <= 'z':
				temp += chr( self.key.index(ch)+ord('a') ) 
			elif ch >= 'A' and ch <= 'Z':
				temp += chr( self.key.index(chr(ord(ch)+32))+ord('A') )
			else:
				temp += ch

		displayOutput("plaintext", temp)

class Polyalphabetic:
	def __init__(self, msg, key, cipher):
		self.plaintext = msg
		self.key = key.lower()
		self.ciphertext = cipher
	
	def encrypt(self):
		extended_key = ""
		# make the key length longer than plaintext
		# so each character maps to a character that will be shifted
		if len(self.key) < len(self.plaintext):
			dif = len(self.plaintext) - len(self.key)
			for i in range(dif+1):
				extended_key += self.key
		else:
			extended_key = self.key
		
		temp = ""
		offset = 0
		for i in range(len(self.plaintext)):
			if self.plaintext[i].isalpha():
				temp += self.__encrypt(self.plaintext[i], indexOf(extended_key[i-offset]))
			else:
				offset += 1
				temp += self.plaintext[i]

		displayOutput("ciphertext", temp)
	
	def decrypt(self):
		extended_key = ""
		if len(self.key) < len(self.ciphertext):
			dif = len(self.ciphertext) - len(self.key)
			for i in range(dif+1):
				extended_key += self.key
		else:
			extended_key = self.key

		temp = ""
		offset = 0
		for i in range(len(self.ciphertext)):
			if self.ciphertext[i].isalpha():
				temp += self.__decrypt(self.ciphertext[i], indexOf(extended_key[i-offset]))
			else:
				offset += 1
				temp += self.ciphertext[i]

		displayOutput("plaintext", temp)

	def __encrypt(self, ch, k):
		if ch >= 'a' and ch <= 'z':
			if ord(ch)+k <= ord('z'):
				return chr(ord(ch)+k)
			else:
				return chr(ord(ch)+k-26)
		elif ch >= 'A' and ch <= 'Z':
			if ord(ch)+k <= ord('Z'):
				return chr(ord(ch)+k)
			else:
				return chr(ord(ch)+k-26)
		else:
			return ch
	
	def __decrypt(self, ch, k):
		if ch >= 'a' and ch <= 'z':
			if ord(ch)-k >= ord('a'):
				return chr(ord(ch)-k)
			else:
				return chr(ord(ch)-k+26)
		elif ch >= 'A' and ch <= 'Z':
			if ord(ch)-k >= ord('A'):
				return chr(ord(ch)-k)
			else:
				return chr(ord(ch)-k+26)
		else:
			return ch


def compression(block, total):
	current_total = total

	# ROUND 1
	for i in range(4):
		sum = 0
		for j in range(i, 16, 4):
			sum += indexOf(block[j])
		current_total[i] += sum
		current_total[i] %= 26

	# ROUND 2
	# # rotate r1 left by 1
	# matrix = block[1:4] + list(block[0])
	# # rotate r2 left by 2
	# matrix += block[6:8] + block[4:6]
	# # rotate r3 left by 3
	# matrix += list(block[-5]) + block[8:11]
	# # reverse r4
	# matrix += list(reversed(block[12:16]))

	matrix = block[1:4] + list(block[0]) + block[6:8] + block[4:6] + list(block[-5]) + block[8:11] + list(reversed(block[12:16]))

	for i in range(4):
		sum = 0
		for j in range(i, 16, 4):
			sum += indexOf(matrix[j])
		current_total[i] += sum
		current_total[i] %= 26

	return current_total

# Toy Tetragraph Hash
def TTH(msg):
	# remove non-alphas
	alpha_msg = ""
	for ch in msg:
		if ch.isalpha():
			alpha_msg += ch.lower()
	
	# divide message into blocks of 16
	blocks = [alpha_msg[i:i+16] for i in range(0, len(alpha_msg), 16)]

	# pad with zeros
	if len(blocks[-1]) < 16:
		blocks[-1] = blocks[-1] + "0" * (16 - len(blocks[-1]))
	# for i in range(len(blocks)):
	# 	if len(blocks[i]) < 16:
	# 		blocks[i] = blocks[i] + "0" * (16 - len(blocks[i]))

	total = [0,0,0,0]
	for b in blocks:
		total = compression(list(b), total)
	
	hash = ""
	for el in total:
		hash += chr(el+ord('A'))

	print(f"Hash value: {hash}")
