/* 
外观数列
1  1
2  11
3  21
4  1211
5  111221
给一个数，这个数是1
描述上一步的数，这个数是 1 即一个1，故写作11
描述上一步的数，这个数是11即两个1，故写作21
描述上一步的数，这个数是21即一个2一个1，故写作12-11
描述上一步的数，这个数是1211即一个1一个2两个1，故写作11-12-21

给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列。
注意：整数序列中的每一项将表示为一个字符串。
 */

/* 
思路：
循环计数：1->n 不断迭代，
返回前一个数的外观数列。
 */

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void count(string &s)
    {
        string temp = "\0";
        int i = 0;
        int start = 0;
        char count[100] = {0};
        while (s[i])
        {
            if (s[i] != s[start])
            {
                sprintf(count, "%d", i - start);
                temp += count;
                temp += s[start];
                start = i;
            }
            i++;
        }
        sprintf(count, "%d", i - start);
        temp += count;
        temp += s[start];
        s = temp;
    }
    string countAndSay(int n)
    {
        string res{};
        if (n < 1)
            return res;
        res = '1';
        for (int i = 2; i <= n; i++)
        {
            count(res);
        }
        return res;
    }
};

int main()
{
    int n;
    Solution *p = new Solution();
    while (10)
    {
        cin >> n;
        string res = p->countAndSay(n);
        cout << res << endl;
    }
}

/*

显示详情
执行用时 0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :6.4 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution
{
public:
    string countAndSay(int n)
    {
        string res{};
        if (n < 1)
            return res;
        res = '1';
        for (int j = 2; j <= n; j++)
        {
            string temp = "\0";
            int i = 0;
            int start = 0;
            char count[100] = {0};
            while (res[i])
            {
                if (res[i] != res[start])
                {
                    sprintf(count, "%d", i - start);
                    temp += count;
                    temp += res[start];
                    start = i;
                }
                i++;
            }
            sprintf(count, "%d", i - start);
            temp += count;
            temp += res[start];
            res = temp;
        }
        return res;
    }
};
*/