from typing import List

class Solution:
    path: List[int] = []
    ans: List[int] = []
    used: List[bool] = []
    
    def backtracking(self, choices:List[int]) -> None:
        if len(self.path) == len(choices):
            self.ans.append(self.path[:])
        for idx, val in enumerate(choices):
            if self.used[idx]:
                continue
            self.used[idx] = True
            self.path.append(val)
            self.backtracking(choices)
            self.path.pop()
            self.used[idx] = False
        
    def permute(self, nums: List[int]) -> List[List[int]]:
        self.path.clear()
        self.ans.clear()
        self.used = [False] * len(nums)
        self.backtracking(nums)
        return self.ans


if __name__ == '__main__':
    ins = Solution()
    nums = [1,2,3]
    ans = ins.permute(nums)
    print(ans)