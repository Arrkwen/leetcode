from typing import List

# https://leetcode.cn/problems/combination-sum-iii/description/

class Solution:
    ans: List[int] = []
    path: List[int] = []
    def backtracking(self,n, k, p_list):
        if len(self.path) == k and sum(self.path) == n:
            self.ans.append(self.path[:])
        
        for idx, val in enumerate(p_list):
            if sum(self.path) + val > n:
                return
            self.path.append(val)
            self.backtracking(n, k, p_list[idx+1:])
            self.path.pop()

    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        p_list = [i for i in range(1,10)]
        self.backtracking(n,k,p_list)
        return self.ans


if __name__ == '__main__':
    solution = Solution()
    ans1 = solution.combinationSum3(3,9)
    print(ans1)