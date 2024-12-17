from typing import List

# https://leetcode.cn/problems/combination-sum-iii/description/

class Solution:
    results : List[str] = []
    path: List[str] = []
    def batcktracking(self,pick_str:str):
        if len(self.path) == 4 and len(pick_str) == 0:
            self.results.append(".".join(self.path))
            return
        need_cnt = 4 - len(self.path)
        for i in range(1,len(pick_str)+1):
            i_val = pick_str[:i]
            # 减枝
            if need_cnt > 4 or need_cnt < 0 or len(pick_str[i:]) > 3 * need_cnt:
                break
            # 前导0
            if len(i_val) > 1 and i_val[0] == '0':
                break
            # 【0，255】
            if int(i_val) < 0 or int(i_val) > 255:
                break
            
            self.path.append(i_val)
            self.batcktracking(pick_str[i:])
            self.path.pop()

    def restoreIpAddresses(self, s: str) -> List[str]:
        self.path.clear()
        self.results.clear()
        self.batcktracking(s)
        return self.results

if __name__ == "__main__":
    solution = Solution()
    ans = solution.restoreIpAddresses("25525511135")
    print(ans)