class MyQueue:
	def __init__(self):
		self.queue = []
		
	
	def push(self, x: int) -> None:
		self.queue.append(x)
	
	
	def pop(self) -> int:
		head = self.queue[0]
		del self.queue[0]
		return head
		
		
	def top(self) -> int:
		return self.queue[0]
		
		
	def empty(self) -> bool:
		return len(self.queue) == 0
		
		
	def size(self) -> int:
		return len(self.queue)
		

class MyStack:

	def __init__(self):
		self.queue1 = MyQueue()
		self.queue2 = MyQueue()
		
		
	def push(self, x: int) -> None:
		"""
		Push element x onto stack.
		"""
		currentQueue = self.queue1
		if self.queue1.empty():
			currentQueue = self.queue2
		
		currentQueue.push(x)
		

	def pop(self) -> int:
		"""
		Removes the element on top of the stack and returns that element.
		"""
		currentQueue = self.queue1
		anotherQueue = self.queue2
		if self.queue1.empty():
			currentQueue = self.queue2
			anotherQueue = self.queue1
			
		while currentQueue.size() != 1:
			anotherQueue.push(currentQueue.pop())
			
		return currentQueue.pop()
			
		
	def top(self) -> int:
		"""
		Get the top element.
		"""
		currentQueue = self.queue1
		anotherQueue = self.queue2
		if self.queue1.empty():
			currentQueue = self.queue2
			anotherQueue = self.queue1
			
		value = 0
		while not currentQueue.empty():
			if currentQueue.size() == 1:
				value = currentQueue.top()
			anotherQueue.push(currentQueue.pop())
			
		return value
		

	def empty(self) -> bool:
		"""
		Returns whether the stack is empty.
		"""
		return self.queue1.empty() and self.queue2.empty()
		
		
		
stack = MyStack()
stack.push(1)
stack.push(2)
x = stack.top()
x = stack.pop()