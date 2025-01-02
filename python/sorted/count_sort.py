from typing import List

class Solution:
    def count_sort(self, nums: List[int]) -> List[int]:
        max_val = max(nums)
        count_array = [0] * (max_val + 1)
        for val in nums:
            count_array[val] += 1
        i, j = 0, 0
        while i < len(count_array):
            while count_array[i] > 0:
                nums[j] = i
                count_array[i] -= 1
                j+= 1
            i += 1
        return nums

if __name__ == "__main__":
    solution = Solution()
    nums = [64, 34, 25, 12, 22, 11, 90, 22]
    print(solution.count_sort(nums))  # Output: [11, 12, 22, 22, 25, 34, 64, 90]