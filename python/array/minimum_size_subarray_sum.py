# https://leetcode.cn/problems/minimum-size-subarray-sum/
from typing import List

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        i, j, total, n = 0, 0, 0, len(nums)
        ans = n + 1
        while j < n:
            total += nums[j]
            while total >= target:
                ans = min(ans, j - i + 1)
                total -= nums[i]
                i += 1
            j += 1
        return 0 if ans == n+1 else ans