from typing import List, Tuple

class Solution:
    
    def find_max_val(self, nums: List[int]) -> Tuple:
        max_val, max_index = -1, 0
        for idx, val in enumerate(nums):
            if val > max_val:
                max_val = val
                max_index = idx
        return max_index

    def bubble_sort(self, nums:List[int]) -> List[int]:
        last_idx = len(nums) - 1
        while last_idx >= 0:
            max_idx = self.find_max_val(nums[:last_idx+1])
            nums[max_idx], nums[last_idx] = nums[last_idx], nums[max_idx]
            last_idx -= 1
        return nums

if __name__ == "__main__":
    solution = Solution()
    nums = [64, 34, 25, 12, 22, 11, 90]
    print(solution.bubble_sort(nums))  # Output: [11, 12, 22, 25, 34, 64, 90]
            
            
        