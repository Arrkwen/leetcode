/* 
����һ���ַ��� S��һ���ַ��� T�������ַ��� S �����ҳ������� T ������ĸ����С�Ӵ���

ʾ����

����: S = "ADOBECODEBANC", T = "ABC"
���: "BANC"
˵����

��� S �в����������Ӵ����򷵻ؿ��ַ��� ""��
��� S �д����������Ӵ������Ǳ�֤����Ψһ�Ĵ𰸡�

 */

/* 
���ڿ�ʼ��ģ�壬ֻ��Ҫ˼�������ĸ����⣺

1�����ƶ�right���󴰿ڣ��������ַ�ʱ��Ӧ�ø�����Щ���ݣ�windows��valid

2��ʲô�����£�����Ӧ����ͣ���󣬿�ʼ�ƶ�left��С���ڣ�valid==need.size()

3�����ƶ�left��С���ڣ����Ƴ��ַ�ʱ��Ӧ�ø�����Щ���ݣ�windows��valid

4������Ҫ�Ľ��Ӧ�������󴰿�ʱ������С����ʱ���и��£���С����ʱ
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
            //��������
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
                //ֵ����
                if (right - left < len)
                {
                    len = right - left;
                    start = left;
                }
                //���ڼ�С
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