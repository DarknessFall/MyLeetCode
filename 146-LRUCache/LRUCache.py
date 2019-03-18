class LRUNode:
	def __init__(self, key: int, value: int):
		self.key = key
		self.value = value
		self.prev = None
		self.next = None


class LRUCache:
	def __init__(self, capacity: int):
		self.capacity = capacity
		self.cacheHead = None
		self.cache = {}
		
	def get(self, key: int) -> int:
		if self.cache.get(key) == None:
			return -1
			
		node = self.cache[key]
		self.move(node)
		return node.value
		
		
	def put(self, key: int, value: int) -> None:
		if self.cache.get(key) != None:
			node = self.cache[key]
			node.value = value
			self.move(node)
			return
		
		if len(self.cache) == self.capacity:
			current = self.cacheHead
			while current.next != None:
				current = current.next
			prev = current.prev
			if prev != None:
				prev.next = None
			current.prev = None
			del self.cache[current.key]
			
		newNode = LRUNode(key, value)
		head = self.cacheHead
		newNode.next = head
		if head != None:
			head.prev = newNode
		self.cacheHead = newNode
		self.cache[key] = newNode
		
	
	def move(self, node: LRUNode) -> None:
		if node == self.cacheHead:
			return
		
		p = node.prev
		n = node.next
		p.next = n
		head = self.cacheHead
		node.next = head
		node.prev = None
		head.prev = node
		self.cacheHead = node
		if n != None:
			n.prev = p
					

cache = LRUCache(2)
cache.put(1, 1)
cache.put(2, 2)
x = cache.get(1)
cache.put(3, 3)
x = cache.get(2)
cache.put(4, 4)
x = cache.get(1)
x = cache.get(3)
x = cache.get(4)
print(x)