/* 
�������
1  1
2  11
3  21
4  1211
5  111221
��һ�������������1
������һ��������������� 1 ��һ��1����д��11
������һ���������������11������1����д��21
������һ���������������21��һ��2һ��1����д��12-11
������һ���������������1211��һ��1һ��2����1����д��11-12-21

����һ�������� n��1 �� n �� 30�������������С�
ע�⣺���������е�ÿһ���ʾΪһ���ַ�����
 */

/* 
˼·��
ѭ��������1->n ���ϵ�����
����ǰһ������������С�
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

��ʾ����
ִ����ʱ 0 ms, ������ C++ �ύ�л�����100.00%���û�
�ڴ����� :6.4 MB, ������ C++ �ύ�л�����100.00%���û�

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