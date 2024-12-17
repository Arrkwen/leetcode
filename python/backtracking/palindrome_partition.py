from typing import List

# https://leetcode.cn/problems/palindrome-partitioning/description/

class Solution:
    ans: List[List[str]] = [[]]
    path: List[str] = []
 
    def is_palindrome(self, s:str):
        if len(s) == 0:
            return False
        i, j = 0, len(s) - 1
        while i<j:
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1
        return True

    def batcktracking(self, s):
        # 当剩余字符串长度为0时，切割结束
        if len(s) == 0:
            self.ans.append(self.path[:])
            return
        max_split = len(s) + 1
        # for 循环是切割点的位置
        for i in range(1,max_split):
            # 切割的第一个字串，如果第一个子串都不是回文串，则跳过找下一个切割点
            # 相比于组合问题，就是增加了第一个字串的判断
            sub_str = s[0:i]
            # todo 回文串还可以做效率提升
            if self.is_palindrome(sub_str):
                self.path.append(sub_str)
                # 深度是剩余字符串的长度
                self.batcktracking(s[i:])
                self.path.pop()

    def partition(self, s: str) -> List[List[str]]:
        self.ans.clear()
        self.path.clear()
        self.batcktracking(s)
        return self.ans

if __name__ == "__main__":
    solution = Solution()
    ans = solution.partition("")
    print(ans)