import glob
# import hashlib


class MerkleTree:
	def __init__(self, value):
		self.left = None
		self.right = None
		self.value = value
		self.hash_value = TTH(value)
		# self.hash_value = hashlib.sha256(root.encode('utf-8')).hexdigest()
	
	def print_tree(self):
		if self.left:
			self.left.print_tree()
		if self.right:
			self.right.print_tree()
		print(f"{self.hash_value}")


# returns the position of an alphabetic char in sequence 0 ~ 25
def indexOf(ch):
	if ch == '0':  # this part only used by TTH
		return 0
	return ord(ch)-ord('a')

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
	matrix = block[1:4] + list(block[0]) + block[6:8] + block[4:6] + list(block[-5]) \
		+ block[8:11] + list(reversed(block[12:16]))

	for i in range(4):
		sum = 0
		for j in range(i, 16, 4):
			sum += indexOf(matrix[j])
		current_total[i] += sum
		current_total[i] %= 26

	return current_total

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

	total = [0, 0, 0, 0]
	for b in blocks:
		total = compression(list(b), total)

	hash = ""
	for el in total:
		hash += chr(el+ord('A'))
	
	return hash

# location: local or server
def build_tree(location):
	nodes, files = [], []
	if location == 'l':
		files = sorted(glob.glob('tests/local/*.txt'))
	else:
		files = sorted(glob.glob('tests/server/*.txt'))
	
	for file in files:
		with open(file) as f:
			fc = f.readlines()
		nodes.append(MerkleTree("".join(fc)))
	
	# build actual tree
	while len(nodes) != 1:
		parents = []
		for i in range(0, len(nodes), 2):
			child1 = nodes[i]
			if i+1 < len(nodes):
				child2 = nodes[i+1]
			else:
				parents.append(nodes[i])
				break
			
			combined_hash = child1.hash_value + child2.hash_value
			parent = MerkleTree(combined_hash)
			parent.left = child1
			parent.right = child2
			parents.append(parent)
		nodes = parents
	return nodes[0]
	

tree = build_tree('local')
tree.print_tree()
