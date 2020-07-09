#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 
������Ӵ�

˼·һ��������ɢ����O(n^2),O(1)
˼·������̬�滮����O(n),O(n^2)

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
            while ((right < n) && s[i] == s[right]) //�����ҵ���һ���뵱ǰ�ַ�����ȵ��ַ�
                right++;

            left = i;
            while ((left >= 0) && (s[i] == s[left])) //�����ҵ���һ���뵱ǰ�ַ�����ȵ��ַ�
                left--;

            while ((left >= 0) && (right < n) && s[left] == s[right]) //�ж����������ַ��Ƿ���ȣ���Ⱦͼ�����չ
            {
                left--;
                right++;
            }
            //����whileѭ����left��right�ǲ���ȵ������ַ����±꣬��˸�����Ҫ����һ�����ǻ��Ĵ���
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

��̬�滮

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
        //��ʼ��
        for (int i = 0; i < len;i++)
        {
            dp.emplace_back(vector<bool>(len, false));
        }
        int maxLen = 1;
        int start = 0;

        //[i,j]֮������䣬����i<j��
        for (int j = 1; j < len; j++) {
            for (int i = 0; i < j; i++) {

                if (s[i] == s[j]) {
                    if (j - i < 3) {//���䳤��С��3��˵�����䳤��Ϊ1��2������֮��㲻���������䣬ֱ��Ϊtrue
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];//�����ǵ�����������Ƿ�Ϊ���ġ�
                    }
                } else {
                    dp[i][j] = false;
                }

                // ֻҪ dp[i][j] == true �������ͱ�ʾ�Ӵ� s[i, j] �ǻ��ģ���ʱ��¼���ĳ��Ⱥ���ʼλ��
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
