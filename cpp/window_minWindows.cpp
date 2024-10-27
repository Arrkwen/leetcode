/* 
给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。

示例：

输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：

如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。

 */

/* 
现在开始套模板，只需要思考以下四个问题：

1、当移动right扩大窗口，即加入字符时，应该更新哪些数据？windows和valid

2、什么条件下，窗口应该暂停扩大，开始移动left缩小窗口？valid==need.size()

3、当移动left缩小窗口，即移出字符时，应该更新哪些数据？windows和valid

4、我们要的结果应该在扩大窗口时还是缩小窗口时进行更新？缩小窗口时
 */

#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define INT_MAX __INT_MAX__

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> need, window;
        for (char c : t)
            need[c]++;
        int left = 0, right = 0, start = 0;
        int valid = 0, len = INT_MAX;
        int size_s = s.size();
        int size_need = need.size();
        while (right < size_s)
        {
            //窗口扩大
            char c = s[right];
            right++;
            if (need.count(c))
            {
                if (window[c] == need[c])
                    valid++;
                window[c]++;
            }
            while (valid == size_need)
            {
                //值更新
                if (right - left < len)
                {
                    len = right - left;
                    start = left;
                }
                //窗口减小
                char c = s[left];
                left++;
                if (need.count(c))
                {
                    if (window[c] == need[c])
                        valid--;
                    window[c]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};