from typing import List

# https://leetcode.cn/problems/combination-sum-iii/description/

class Solution:
    ans: List[int] = []
    path: List[int] = []
    used: List[bool] = []
    def backtracking(self,p_list, target):
        if sum(self.path) == target:
            self.ans.append(self.path[:])
            return
        elif sum(self.path) > target:
            return

        for idx, val in enumerate(p_list):
            # 剪枝， 如果前面存在重复元素且没有使用过，说明是同一层，需要跳过，只有不同层的相同元素才能保留。
            # 比如[1,1,6]中的1，1是在不同层的元素，参考carl的同层剪枝
            if idx > 0 and p_list[idx] == p_list[idx-1] and not self.used[idx-1]:
                continue
            self.path.append(val)
            self.used[idx] = True
            self.backtracking(p_list[idx+1:], target)
            self.path.pop()
            self.used[idx] = False

    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        self.ans.clear()
        self.path.clear()
        # 去重需要先排序
        candidates = sorted(candidates)
        self.used = [False] * len(candidates)
        self.backtracking(candidates, target)
        return self.ans


if __name__ == '__main__':
    solution = Solution()
    candidates = [10,1,2,7,6,1,5]
    target = 8
    ans1 = solution.combinationSum2(candidates, target)
    print(ans1)