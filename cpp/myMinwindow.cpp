#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> need, window;
        for (char c : t)
        {
            need[c]++;
        }
        int n = s.size(), valid = 0;
        int start = 0, len = INT_MAX; //记录子串的位置，用于更新
        int left = 0, right = 0;
        int needSize = need.size();
        while (right < n)
        {
            char c = s[right];
            //扩大窗口
            if (need.count(c))
            {
                window[c]++;
                if (window[c] == need[c])
                {
                    valid++;
                }
            }
            right++;

            //break出来，有两种情况
            //缩小窗口,由于t中可能只有一个字符，所以left<=right
            while (valid == needSize)
            {
                //先更新结果
                if ((right - left) < len)
                {
                    start = left;
                    len = right - left;
                }
                //缩小窗口
                char c = s[left];
                if (need.count(c))
                {
                    if (window[c] == need[c])
                        valid--;
                    window[c]--;
                }
                left++;
            }
        }
        return len != INT_MAX ? s.substr(start, len) : "";
    }
};

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    Solution p;
    string res = p.minWindow(s, t);
    cout << res << endl;
    return 0;
}