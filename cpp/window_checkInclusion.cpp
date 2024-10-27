/* 
给定两个字符串?s1?和?s2，写一个函数来判断 s2 是否包含 s1?的排列。

换句话说，第一个字符串的排列之一是第二个字符串的子串。

示例1:

输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").

思路：滑动窗口
 */

#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define INT_MAX __INT_MAX__

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for(char c:s1)
            need[c]++;
        int left = 0, right = 0;
        int valid = 0;
        int size_s1 = s1.size();
        int size_need = need.size();
        int size_s2 = s2.size();
        while(right<size_s2)
        {
            char c = s2[right];
            right++;
            //窗口右移动，更新相关值
            if(need.count(c))
            {
                window[c]++;
                if(window[c]==need[c])
                    valid++;
            }
            //判断左侧窗口是否要左移
            while(right-left>=size_s1)
            {
                //更新结果
                if(valid==size_need)
                    return true;
                //窗口左移，更新相关值
                char c = s2[left];
                left++;
                if(need.count(c))
                {
                    if(window[c]==need[c])
                        valid--;
                    window[c]--;
                }
            }
        }
        return false;
    }
};