from typing import List
import copy
import time

# https://leetcode.cn/problems/combinations/description/
# 
class Solution:
    def backtracking(self, ans, path, k, p_list):
        if len(path) == k:
            ans.append(copy.copy(path))
            return
        # todo 剪纸优化
        for idx, val in enumerate(p_list):
            path.append(val) # 处理节点
            self.backtracking(ans, path, k, p_list[idx+1:])     
            path.pop() # 撤销节点
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans, path = [], []
        p_list = [i+1 for i in range(n)]
        self.backtracking(ans, path, k, p_list)
        return ans

class Solution_perf:
    def backtracking(self, ans, path, k, p_list):
        if len(path) == k:
            ans.append(copy.copy(path))
            return
        for idx, val in enumerate(p_list):
            path.append(val) # 处理节点
            # 剪枝
            if len(path) + len(p_list[idx+1:]) >= k:
                self.backtracking(ans, path, k, p_list[idx+1:])     
            path.pop() # 撤销节点
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans, path = [], []
        p_list = [i+1 for i in range(n)]
        self.backtracking(ans, path, k, p_list)
        return ans

if __name__ == '__main__':
    solution = Solution()
    solution_pef = Solution_perf()
    t0 = time.time()
    ans1 = solution.combine(15,12)
    t1 = time.time()
    ans2 = solution_pef.combine(15,12)
    t2 = time.time()
    assert ans1 == ans2
    print(t1-t0)
    print(t2-t1)
    