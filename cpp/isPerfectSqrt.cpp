#include<iostream>
#include<math.h>

using namespace std;

/* 

二分法找平方根

 */
class Solution {
public:
    bool isPerfectSquare(int x) {
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
        return mid*mid==x;
    }
};

int main()
{
    Solution p;
    int res = p.mySqrt(2147483647);
    return 0;
}