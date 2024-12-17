from typing import List

# https://leetcode.cn/problems/letter-combinations-of-a-phone-number/

class Solution:
    digit2letter = {
        "2":["a","b","c"],
        "3":["d","e","f"],
        "4":["g","h","i"],
        "5":["j","k","l"],
        "6":["m","n","o"],
        "7":["p","q","r","s"],
        "8":["t","u","v"],
        "9":["w","x","y","z"]
    }
    ans: List[str] = []
    path: List[str] = []
    
    def backtracking(self, p_list):
        if len(p_list) == 0:
            self.ans.append("".join(self.path))
            return
        letter_list = self.digit2letter.get(p_list[0],[])
        for letter in letter_list:
            self.path.append(letter)
            self.backtracking(p_list[1:])
            self.path.pop()
        
    def letterCombinations(self, digits: str) -> List[str]:
        self.ans.clear()
        self.path.clear()
        digits = [c for c in digits]
        if len(digits) > 0:
            self.backtracking(digits)
        return self.ans

if __name__ == "__main__":
    solution = Solution()
    ans = solution.letterCombinations("2")
    print(ans)