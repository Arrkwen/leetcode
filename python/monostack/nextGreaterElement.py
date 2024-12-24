from typing import List

# https://leetcode.cn/problems/next-greater-element-i/description/

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result = [-1]*len(nums1)
        m = {}
        for idx, val in enumerate(nums1):
            m[val] = idx
        stack = []
        # 遍历的依旧是nums2
        for i in range(0,len(nums2)):
            while len(stack)!=0 and nums2[i]>nums2[stack[-1]]:
                # 需要判断栈顶元素是否在num1中出现
                if nums2[stack[-1]] in nums1:
                    index = m[nums2[stack[-1]]]
                    result[index]=nums2[i]
                stack.pop()  
            # 栈空，or 栈顶元素>=当前元素
            stack.append(i)
        return result

if __name__ == '__main__':
    ins = Solution()
    nums1 = [4,1,2]
    nums2 = [1,3,4,2]
    ans = ins.nextGreaterElement(nums1,nums2)
    print(ans)