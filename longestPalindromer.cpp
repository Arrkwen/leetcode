#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 
最长回文子串

思路一：中心扩散法：O(n^2),O(1)
思路二：动态规划法：O(n),O(n^2)

 */
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n <= 1)
            return s;
        int right = 0;
        int left = 0;
        int start = 0, maxLen = INT_MIN, curLen = 0;
        for (int i = 0; i < n; i++)
        {
            right = i;
            while ((right < n) && s[i] == s[right]) //向右找到第一个与当前字符不相等的字符
                right++;

            left = i;
            while ((left >= 0) && (s[i] == s[left])) //向左找到第一个与当前字符不相等的字符
                left--;

            while ((left >= 0) && (right < n) && s[left] == s[right]) //判断上面两个字符是否相等，相等就继续扩展
            {
                left--;
                right++;
            }
            //结束while循环，left和right是不相等的两个字符的下标，因此各自需要回退一步便是回文串。
            left++;
            right--;
            curLen = right - left + 1;
            if (curLen > maxLen)
            {
                maxLen = curLen;
                start = left;
            }
        }
        return s.substr(start, maxLen);
    }
};

/* 

动态规划

 */
class Solution1
{
public:
    string longestPalindrome(string s)
    {
        int len = s.length();
        if (len < 2) {
            return s;
        }
        vector<vector<bool>> dp;
        //初始化
        for (int i = 0; i < len;i++)
        {
            dp.emplace_back(vector<bool>(len, false));
        }
        int maxLen = 1;
        int start = 0;

        //[i,j]之间的区间，其中i<j；
        for (int j = 1; j < len; j++) {
            for (int i = 0; i < j; i++) {

                if (s[i] == s[j]) {
                    if (j - i < 3) {//区间长度小于3，说明区间长度为1和2，他们之间便不再有子区间，直接为true
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];//由他们的子区间决定是否为回文。
                    }
                } else {
                    dp[i][j] = false;
                }

                // 只要 dp[i][j] == true 成立，就表示子串 s[i, j] 是回文，此时记录回文长度和起始位置
                if (dp[i][j]) {
                    int curLen = j - i + 1;
                    if (curLen > maxLen) {
                        maxLen = curLen;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

int main()
{
    string s = "babcd";
    Solution1 p;
    string res = p.longestPalindrome(s);
    cout << res << endl;
    return 0;
}
