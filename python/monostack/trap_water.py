from typing import List

# https://leetcode.cn/problems/trapping-rain-water/description/
# 找左右两边第一个大于自己的元素

class Solution:
    def trap(self, height: List[int])->int:
        s = []
        ans = 0
        # 单调栈计算横条， 如果是计算竖条，最后一个不好处理
        for r, h in enumerate(height):
            # 栈不空且遇到右边第一个大于栈顶的元素
            while len(s)>0 and height[s[-1]] < h:
                if len(s) > 1:
                    # 只有栈的元素超过2，才可能形成凹槽，因为栈顶的左边第一个元素就是大于等于栈顶的元素 
                    l = s[-2]
                    cur_w = r - l - 1
                    cur_h = min(height[l], height[r]) - height[s[-1]]
                    ans += cur_h*cur_w
                s.pop()
            # 栈空or当前高度小于栈顶元素
            s.append(r)
        return ans

if __name__ == '__main__':
    ins = Solution()
    height = [0,1,0,2,1,0,1,3,2,1,2,1]
    ans = ins.trap(height)
    print(ans)

    height = [4,2,0,3,2,5]
    ans = ins.trap(height)
    print(ans)
    