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
        int start = 0, len = INT_MAX; //��¼�Ӵ���λ�ã����ڸ���
        int left = 0, right = 0;
        int needSize = need.size();
        while (right < n)
        {
            char c = s[right];
            //���󴰿�
            if (need.count(c))
            {
                window[c]++;
                if (window[c] == need[c])
                {
                    valid++;
                }
            }
            right++;

            //break���������������
            //��С����,����t�п���ֻ��һ���ַ�������left<=right
            while (valid == needSize)
            {
                //�ȸ��½��
                if ((right - left) < len)
                {
                    start = left;
                    len = right - left;
                }
                //��С����
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