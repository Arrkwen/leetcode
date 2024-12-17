from typing import List

# https://leetcode.cn/problems/subsets-ii/

class Solution:
    ans : List[List[int]] = []
    path: List[int] = []
    def batcktracking(self, choices: List[int]):
        # 细节1， 需要在判断条件前append
        self.ans.append(self.path[:])
        # 这个终止条件可以不添加，因为for循环也会推出
        # if len(choices) == 0:
        #     return
        for idx, val in enumerate(choices):
            # 如果是在同一层，则跳过
            if idx > 0 and choices[idx] == choices[idx-1]:
                continue
            self.path.append(val)
            # 细节2: append 当前值之后，可选择的列表必须是当前值之后的数据
            self.batcktracking(choices[idx+1:])
            self.path.pop()


    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        self.ans.clear()
        self.path.clear()
        # 细节3: 重复元素的子集问题需要先排序，因为集合是不关注顺序的。
        nums = sorted(nums)
        self.batcktracking(nums)
        return self.ans

if __name__ == '__main__':
    ins = Solution()
    nums = [1,2,2]
    ans = ins.subsetsWithDup(nums)
    print(ans)
    
    nums = [1]
    ans = ins.subsetsWithDup(nums)
    print(ans)
    
    nums = [1,2,2,3,3,4]
    ans = ins.subsetsWithDup(nums)
    print(ans)