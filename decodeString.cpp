/* 
给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像?3a?或?2[4]?的输入。

示例:

s = "3[a]2[bc]", 返回 "aaabcbc".
s = "3[a2[c]]", 返回 "accaccacc".
s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef"

 */

/* 
思路： 准备两个栈，
一个栈存放循环次数，      loopStack
一个栈存放要循环的字符串：strStack

loopStack 入栈条件： 遇到数字,就把数字入栈
          出栈条件： 遇到“]"就出栈

strStack  入栈条件： 遇到数字,就当前字符串入栈
          出栈条件： 遇到“]"就出栈，且拼接上当前的字符串，循环执行数字栈的次数

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
        int numsRightBracket = 0; //记录右括号数
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