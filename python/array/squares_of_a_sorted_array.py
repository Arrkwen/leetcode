from typing import List

# https://leetcode.cn/problems/squares-of-a-sorted-array/

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        left = 0
        right = len(nums) - 1
        cur_idx = right
        result = [0]*len(nums)
        while left<= right:
            l_val = nums[left]**2
            r_val = nums[right]**2
            if l_val > r_val:
                result[cur_idx] = l_val
                left += 1
            else:
                result[cur_idx] = r_val
                right -= 1
            cur_idx -= 1
        return result
        