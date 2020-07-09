#include <cstring>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        if(right<0)
            return false;

        while(left<right)
        {
            if(s[left]==s[right])
            {
                left++;
                right--;
            }
            else
            {
                break;
            }
        }

        if(left >= right)
            return true;

        int tempL = left+1;
        int tempR = right-1;
        
        if(s[tempL]==s[right])
        {
            left = tempL;
        }
        else if(s[tempR]==s[left])
        {
            right = tempR;
        }
        
        while(left<right)
        {
            if(s[left]==s[right])
            {
                left++;
                right--;
            }
            else
            {
                break;
            }
        }

        return left>=right;
    }
};


int main()
{
    string s = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
    Solution p;
    p.validPalindrome(s);
}