from typing import List

# https://leetcode.cn/problems/non-decreasing-subsequences/

class Solution:
    path: List[int] = []
    ans: List[int] = []

    def backtracking(self, choices:List[int]) -> None:
        if len(self.path) > 1:
            self.ans.append(self.path[:])
        used = set()
        for idx, val in enumerate(choices):
            # 数层减枝桠
            if val in used:
                continue
            if len(self.path) > 0 and val < self.path[-1]:
                break
            used.add(val)
            self.path.append(val)
            self.backtracking(choices[idx+1:])
            self.path.pop()

        
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        self.path.clear()
        self.ans.clear()
        self.backtracking(nums)
        return self.ans

if __name__ == '__main__':
    ins = Solution()
    nums = [4,6,7, 7]
    ans = ins.findSubsequences(nums)
    print(ans)
    
    
