/* 
����һ������������ַ������������������ַ�����

�������Ϊ: k[encoded_string]����ʾ���з������ڲ��� encoded_string �����ظ� k �Ρ�ע�� k ��֤Ϊ��������

�������Ϊ�����ַ���������Ч�ģ������ַ�����û�ж���Ŀո�������ķ��������Ƿ��ϸ�ʽҪ��ġ�

���⣬�������Ϊԭʼ���ݲ��������֣����е�����ֻ��ʾ�ظ��Ĵ��� k �����粻�������?3a?��?2[4]?�����롣

ʾ��:

s = "3[a]2[bc]", ���� "aaabcbc".
s = "3[a2[c]]", ���� "accaccacc".
s = "2[abc]3[cd]ef", ���� "abcabccdcdcdef"

 */

/* 
˼·�� ׼������ջ��
һ��ջ���ѭ��������      loopStack
һ��ջ���Ҫѭ�����ַ�����strStack

loopStack ��ջ������ ��������,�Ͱ�������ջ
          ��ջ������ ������]"�ͳ�ջ

strStack  ��ջ������ ��������,�͵�ǰ�ַ�����ջ
          ��ջ������ ������]"�ͳ�ջ����ƴ���ϵ�ǰ���ַ�����ѭ��ִ������ջ�Ĵ���

 */

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        string res = "";
        //stack<string> strStack;
        //stack<int> loopStack;
        int numsRightBracket = 0; //��¼��������
        int n = s.size();
        int i = n - 1;
        string curStr = "";
        string loopCnt = "";
        while (i >= 0)
        {
            if (isalpha(s[i]))
            {
                curStr = s[i] + curStr;
            }
            else if (s[i] == ']')
            {
                numsRightBracket++;
            }
            else if (isdigit(s[i]))
            {
                loopCnt = s[i] + loopCnt;
                if (i == 0 || (i - 1 > 0 && !isdigit(s[i-1])))
                {
                    int loop = atoi(loopCnt.c_str())-1;
                    string temp = curStr;
                    while (loop--)
                    {
                        curStr += temp;
                    }
                    numsRightBracket--;
                    loopCnt = "";
                }
            }
            if (numsRightBracket == 0 && curStr.size() != 0)
            {
                res = curStr + res;
                curStr = "";
            }
            i--;
        }
        return res;
    }
};

int main()
{
    string s = "3[a]2[bc]";
    string s1 = "3[a2[c]]";
    string s2 = "2[abc]3[cd]ef";
    string s3 = "leetcode";
    string s4 = "10[leet]";
    Solution P;
    cout << P.decodeString(s1) << endl;
    return 0;
}