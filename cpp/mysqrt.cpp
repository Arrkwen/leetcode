#include<iostream>
#include<math.h>

using namespace std;

/* 

二分法找平方根

 */
class Solution {
public:
    int mySqrt(int x) {
        if(x==0||x==1)
            return x;
        int left = 0;
        int right = x/2 >= 46340?46340:x/2;
        int mid = 0;
        while(left<right)
        {
            mid = (right - left + 1) / 2 + left;
            //不满足条件
            if(mid<46341&&mid*mid>x)
                right = mid-1;
            else
                left = mid;
        }
        return left;
    }
};

class Solution1 {
public:
    int mySqrt(int x) {
        if(x<=0)
            return 0;
        if(x<4)
            return 1;
        int i = 1;
        int mul = 0;
        for(;i<46341;i++)
        {
            mul = i*i;
            if(mul>x)
                break;
        }
        if(mul>x)
        {
            i--;
            return i;
        }
        else
            return 46340;
    }
};

int main()
{
    Solution p;
    int res = p.mySqrt(2147483647);
    return 0;
}