from typing import List

# https://leetcode.cn/problems/spiral-matrix-ii/description/

class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        # 四个基本走向
        max_val = n**2
        ans = [[0] * n for i in range(n)]
        i, j = 0, 0
        val = 1
        while val < max_val:
            # 1 如果右边没有走过且小于n: j++
            while j < n - 1 and ans[i][j + 1] == 0:
                ans[i][j] = val
                j += 1
                val += 1
            # 2 如果下边有路，且小于n; i++
            while i < n - 1 and ans[i + 1][j] == 0:
                ans[i][j] = val
                i += 1
                val += 1
            # 3 如果左边有路且j>0; j--
            while j > 0 and ans[i][j - 1] == 0:
                ans[i][j] = val
                j -= 1
                val += 1
            # 4 如果上边有路且i>0;i--
            while i > 0 and ans[i - 1][j] == 0:
                ans[i][j] = val
                i -= 1
                val += 1
        # 处理最后一个元素
        ans[i][j] = val
        return ans

if __name__ == "__main__":
    n = 4
    solution = Solution()
    ans = solution.generateMatrix(n)
    for i in range(n):
        print(ans[i])