from typing import List

# https://leetcode.cn/problems/daily-temperatures/description/

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        st: List[int] = []
        ans = [0] * len(temperatures)
        for idx, cur_t in enumerate(temperatures):
            # 栈非空
            while len(st) > 0 and temperatures[st[-1]] < cur_t:
                histroy_idx = st.pop()
                ans[histroy_idx] = idx - histroy_idx
            # 栈空，or 栈顶元素>=当前元素
            st.append(idx)
        return ans
    
if __name__ == '__main__':
    ins = Solution()
    temperatures = [32,35,46,31,31,47]
    ans = ins.dailyTemperatures(temperatures)
    print(ans)