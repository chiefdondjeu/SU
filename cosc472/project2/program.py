import os
from cryptography import Caesar, Monoalphabetic, Polyalphabetic, TTH


def encrypt():
	try:
		file_name = input("\nenter file name: ")
		if not os.path.exists(file_name):
			raise Exception(f"Error: could not open {file_name}")
		if os.stat(file_name).st_size == 0:
			raise Exception(f"Error: {file_name} is empty")

	except Exception as E:
		print(E.args[0])
	
	else:
		with open(file_name) as f:
			file_content = f.readlines()
		f.close()

		fc = "".join(file_content)
		print(f"\n\"{file_name}\" content:\n{fc}")
		input("\nPress Enter to continue...")

		while True:
			try:
				option = input(f"\nEncrypt '{file_name}' with ↓\nc - caesor\nm - monoalphabetic\np - polyalphabetic\nq - go back ←" + '\t'*5 + ":")
				if option not in ['c', 'm', 'p', 'q']:
					raise Exception("\nError: invalid input")

			except Exception as E:
				print(E.args[0])
				input("Press Enter to continue...")

			else:
				if option == 'c':
					print("\nCaesar encrypt", end="")
					while True:
						try:
							key = int(input("\nenter valid key: "))
							Caesar(fc, key, "").encrypt()
							input("\nPress Enter to continue...")
							break
						except ValueError:
							print("Error: key must be an integer")
				elif option == 'm':
					print("\nMonoalphabetic encrypt", end="")
					while True:
						try:
							key = input("\nenter valid keyword: ")
							# dict.fromkeys() removes dups and keep order
							kw = "".join(dict.fromkeys(key))
							if len(kw) > 26:
								raise Exception("Error: key too long")
							if False in [ch.isalpha() for ch in key]:
								raise Exception("Error: key cannot contain nonalphabetic character")
							Monoalphabetic(fc, kw, "").encrypt()
							input("\nPress Enter to continue...")
							break
						except Exception as E:
							print(E.args[0])
				elif option == 'p':
					print("\nPolyalphabetic encrypt", end="")
					while True:
						try:
							key = input("\nenter valid keyword: ")
							if False in [ch.isalpha() for ch in key]:
								raise Exception("Error: key cannot contain nonalphabetic character")
							Polyalphabetic(fc, key, "").encrypt()
							input("\nPress Enter to continue...")
							break
						except Exception as E:
							print(E.args[0])
				elif option == 'q':
					return

def decrypt():
	try:
		file_name = input("\nenter file name: ")
		if not os.path.exists(file_name):
			raise Exception(f"Error: could not open {file_name}")
		if os.stat(file_name).st_size == 0:
			raise Exception(f"Error: {file_name} is empty")

	except Exception as E:
		print(E.args[0])
	
	else:
		with open(file_name) as f:
			file_content = f.readlines()
		f.close()

		fc = "".join(file_content)
		print(f"\n\"{file_name}\" content:\n{fc}")
		input("\nPress Enter to continue...")

		while True:
			try:
				option = input(f"\nDecrypt '{file_name}' with ↓\nc - caesor\nm - monoalphabetic\np - polyalphabetic\nq - go back ←" + '\t'*5 + ":")
				if option not in ['c', 'm', 'p', 'q']:
					raise Exception("\nError: invalid input")
			
			except Exception as E:
				print(E.args[0])
				input("Press Enter to continue...")
			
			else:
				if option == 'c':
					print("\nCaesar decrypt", end="")
					while True:
						try:
							key = int(input("\nenter valid key: "))
							Caesar("", key, fc).decrypt()
							input("\nPress Enter to continue...")
							break
						except ValueError:
							print("Error: key must be an integer")
				elif option == 'm':
					print("\nMonoalphabetic decrypt", end="")
					while True:
						try:
							key = input("\nenter valid keyword: ")
							kw = "".join(dict.fromkeys(key))
							if len(kw) > 26:
								raise Exception("Error: key too long")
							if False in [ch.isalpha() for ch in key]:
								raise Exception("Error: key cannot contain non-alphabetic character")
							Monoalphabetic("", kw, fc).decrypt()
							input("\nPress Enter to continue...")
							break
						except Exception as E:
							print(E.args[0])
				elif option == 'p':
					print("\nPolyalphabetic decrypt", end="")
					while True:
						try:
							key = input("\nenter valid keyword: ")
							if False in [ch.isalpha() for ch in key]:
								raise Exception("Error: key cannot contain nonalphabetic character")
							Polyalphabetic("", key, fc).decrypt()
							input("\nPress Enter to continue...")
							break
						except Exception as E:
							print(E.args[0])
				elif option == 'q':
					return

def hash():
	try:
		file_name = input("\nenter file name: ")
		if not os.path.exists(file_name):
			raise Exception(f"Error: could not open {file_name}")
		if os.stat(file_name).st_size == 0:
			raise Exception(f"Error: {file_name} is empty")

	except Exception as E:
		print(E.args[0])

	else:
		with open(file_name) as f:
			file_content = f.readlines()
		f.close()

		fc = "".join(file_content)
		print(f"\n\"{file_name}\" content:\n{fc}")
		TTH(fc)
		input("\nPress Enter to continue...")


if __name__ == "__main__":
	while True:
		try:
			option = input("\nMenu ↓\ne - encrypt\nd - decrypt\nh - hash\nq - quit" + '\t'*5 + ":")
			if option not in ['e', 'd', 'h', 'q']:
				raise Exception("\nError: Invalid input")
	
		except Exception as E:
			print(E.args[0])
			input("Press Enter to continue...")
		
		else:
			if option == 'e':
				encrypt()
			elif option == 'd':
				decrypt()
			elif option == 'h':
				hash()
			elif option == 'q':
				print("Program terminated. Good day!")
				quit()
