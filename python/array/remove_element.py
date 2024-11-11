
from typing import List

# https://leetcode.cn/problems/remove-element/

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        cur_idx = len(nums) - 1
        last_idx = len(nums) - 1
        while cur_idx >= 0:
            if nums[cur_idx] == val:
                nums[cur_idx], nums[last_idx] = nums[last_idx], nums[cur_idx]
                last_idx -= 1
            cur_idx -= 1
        return last_idx + 1