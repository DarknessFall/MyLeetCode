from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_nums = {}
        new_list = []
        for index in range(len(nums)):
            current = nums[index]
            space = target - current
            if space in hash_nums.keys():
                new_list.append(hash_nums[space])
                new_list.append(index)
            
            hash_nums[current] = index
                
        return new_list


s = Solution()
nums = [0, 6, 2, -1, 10]
result = s.twoSum(nums, 9)
print(result)