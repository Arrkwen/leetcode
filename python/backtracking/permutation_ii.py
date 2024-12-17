from typing import List

class Solution:
    path: List[int] = []
    ans: List[int] = []
    used: List[bool] = []
    
    def backtracking(self, choices:List[int]) -> None:
        if len(self.path) == len(choices):
            self.ans.append(self.path[:])
        for idx, val in enumerate(choices):
            if idx > 0 and choices[idx] == choices[idx-1] and not self.used[idx-1]:
                continue
            if self.used[idx]:
                continue
            self.used[idx] = True
            self.path.append(val)
            self.backtracking(choices)
            self.path.pop()
            self.used[idx] = False

    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        self.path.clear()
        self.ans.clear()
        self.used = [False] * len(nums)
        nums = sorted(nums)
        self.backtracking(nums)
        return self.ans


if __name__ == '__main__':
    ins = Solution()
    nums = [1,1,2]
    ans = ins.permuteUnique(nums)
    print(ans)