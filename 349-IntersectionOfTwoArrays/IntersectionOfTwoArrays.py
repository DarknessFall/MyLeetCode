from typing import List

class Solution:
	def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
		newList = []
		for i in nums2:
			if i in nums1 and i not in newList:
				newList.append(i)
						
		return newList