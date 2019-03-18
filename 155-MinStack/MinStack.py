class MinStack:

	def __init__(self):
		"""
		initialize your data structure here.
		"""
		self.stack1 = []
		self.stack2	= []
		

	def push(self, x: int) -> None:
		if len(self.stack1) == 0 or x <= self.getMin():
			self.stack2.append(x)
			
		self.stack1.append(x)

	def pop(self) -> None:
		value = self.stack1.pop()
		if value == self.getMin():
			self.stack2.pop()

	def top(self) -> int:
		return self.stack1[-1]

	def getMin(self) -> int:
		return self.stack2[-1]
		
		
class MinStackNew:

	def __init__(self):
		"""
		initialize your data structure here.
		"""
		self.stack = []
		self.min = 0
		

	def push(self, x: int) -> None:
		if len(self.stack) == 0:
			self.min = x
		
		if x <= self.min:
			self.stack.append(self.min)
			self.min = x
			
		self.stack.append(x)
			

	def pop(self) -> None:
		if self.stack.pop() == self.min:
			self.min = self.stack.pop()
		

	def top(self) -> int:
		return self.stack[-1]
		

	def getMin(self) -> int:
		return self.min
		

stack = MinStackNew()
stack.push(0)
stack.push(-1)
stack.push(0)
x = stack.getMin()
print(x)
stack.pop()
stack.pop()
x = stack.getMin()
print(x)