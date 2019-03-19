class LRUNode {
	var key = 0
	var value = 0
	var prev: LRUNode?
	var next: LRUNode?

	init(key: Int, value: Int) {
		self.key = key
		self.value = value
	}
}

class LRUCache {
	private let capacity: Int
	var map = [Int: LRUNode]()
	var head: LRUNode?
	var tail: LRUNode?

	init(_ capacity: Int) {
		self.capacity = capacity
	}
	
	func get(_ key: Int) -> Int {
		guard let node = map[key] else {
			return -1
		}

		if node !== head {
			remove(node)
			addToHead(node)
		}
		
		return node.value
	}
	
	func put(_ key: Int, _ value: Int) {
		if let node = map[key] {
			node.value = value
			if node !== head {
				remove(node)
				addToHead(node)
			}

			return
		}

		if map.count == capacity {
			map[tail!.key] = nil
			remove(tail!)
		}

		let newNode = LRUNode(key: key, value: value)
		map[key] = newNode
		addToHead(newNode)
		if tail == nil {
			tail = newNode
		}
	}

	private func addToHead(_ node: LRUNode) {
		node.next = head
		head?.prev = newNode
		head = newNode
	}

	private func remove(_ node: LRUNode) {
		node.prev?.next = node.next
		node.next?.prev = node.prev
		if node === tail {
			tail = node.prev
		}
	}
}