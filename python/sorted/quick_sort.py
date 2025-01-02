from typing import List

class Solution:
    # 每次定位一个元素的值，然后再分两头进行排序
    def quick_sort(self, nums:List[int]) -> List[int]:
        if len(nums) <= 1:
            return nums
        pivot = nums[len(nums) // 2]
        left = [x for x in nums if x < pivot]
        middle = [x for x in nums if x == pivot]
        right = [x for x in nums if x > pivot]
        return self.quick_sort(left) + middle + self.quick_sort(right)

if __name__ == "__main__":
    solution = Solution()
    nums = [64, 34, 25, 12, 22, 11, 90]
    print(solution.quick_sort(nums))  # Output: [11, 12, 22, 25, 34, 64, 90]
            
            
        