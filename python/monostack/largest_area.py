from typing import List

# https://leetcode.cn/problems/largest-rectangle-in-histogram/description/
# 最大矩阵这个题目和接雨水解题思路基本一致，这儿是找单调栈中左右两边第一个小于自己的元素位置

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        ans = 0
        stack = []
        # 左右插入0， 保证第一个元素和最后一个元素的处理逻辑
        heights = [0] + heights
        heights.append(0)
        for idx, h in enumerate(heights):
            while len(stack) > 0 and h < heights[stack[-1]]:
                top = stack.pop()
                cur_h = heights[top]
                if len(stack) > 0:
                    left = stack[-1]
                    cur_w = idx - left - 1
                    ans = max(ans, cur_h * cur_w)
            stack.append(idx)
        return ans


if __name__ == '__main__':
    ins = Solution()
    hieghts =  [2,1,5,6,2,3]
    ans = ins.largestRectangleArea(hieghts)
    print(ans)
    
    hieghts =  [2,4]
    ans = ins.largestRectangleArea(hieghts)
    print(ans)