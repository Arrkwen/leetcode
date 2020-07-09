#include <iostream>
#include <math.h>
#include <vector>
#include<algorithm>

using namespace std;

/* 
成绩最大的子数组
 */

class Solution 
{
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int iMax = 1;
        int iMin = 1;
        int n = nums.size();
        for (int i = 0; i < n;i++)
        {
            if(nums[i]<0)
            {
                iMax = iMax ^ iMin;
                iMin = iMax ^ iMin;
                iMax = iMax ^ iMin;
            }

            iMax = max(iMax * nums[i], nums[i]);
            iMin = min(iMin * nums[i], nums[i]);
            res = max(iMax, res);
        }
        return res;
    }
};


int main()
{
    vector<int> nums{-1,0,-2,2};
    Solution p;
    cout<<p.maxProduct(nums);
    return 0;
}