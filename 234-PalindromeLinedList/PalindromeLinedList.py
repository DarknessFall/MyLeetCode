class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None


class Solution:
	def isPalindrome(self, head: ListNode) -> bool:
		if head == None or head.next == None:
			return True
			
		mid = self.findMidNode(head)
		mid.next = self.reverseLinkedList(mid.next)
		p1 = head
		p2 = mid.next
		while p1 != None and p2 != None and p1.val == p2.val:
			p1 = p1.next
			p2 = p2.next
		
		mid.next = self.reverseLinkedList(mid.next)
		
		return p2 == None
		
	def reverseLinkedList(self, head: ListNode) -> ListNode:
		if head == None or head.next == None:
			return head
			
		prev = None
		current = head
		theNext = None
		while current != None:
			theNext = current.next
			current.next = prev
			prev = current
			current = theNext
			
		return prev
		
		
	def findMidNode(self, head: ListNode) -> ListNode:
		if head == None or head.next == None:
			return head
		
		slow = head
		fast = head
		while fast.next != None and fast.next.next != None:
			slow = slow.next
			fast = fast.next.next
			
		return slow
		
		
node1 = ListNode(1)
node2 = ListNode(1)
node3 = ListNode(2)
node4 = ListNode(1)
node1.next = node2
node2.next = node3
node3.next = node4
solution = Solution()
x = solution.isPalindrome(node1)
print(x)