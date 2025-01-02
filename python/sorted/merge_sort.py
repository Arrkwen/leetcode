from typing import List

class Solution:
    def merge(self, num1: List[int], num2: List[int]) -> List[int]:
        nums = []
        idx1, idx2 = 0, 0
        while idx1 < len(num1) and idx2 < len(num2):
            if num1[idx1] < num2[idx2]:
                nums.append(num1[idx1])
                idx1 += 1
            else:
                nums.append(num2[idx2])
                idx2 += 1
        
        if idx1 < len(num1):
            nums += num1[idx1:]
        else:
            nums += num2[idx2:]
        
        return nums
    
    def merge_sort(self, nums: List[int]) -> List[int]:
        if len(nums) <= 1:
            return nums
        mid = len(nums) // 2
        nums1 = self.merge_sort(nums[:mid])
        nums2 = self.merge_sort(nums[mid:])
        nums = self.merge(nums1, nums2)
        return nums


if __name__ == "__main__":
    ins = Solution()
    case1 = [2,4,7,9,1,20,39,27,33]
    ans = ins.merge_sort(case1)
    print(ans)

