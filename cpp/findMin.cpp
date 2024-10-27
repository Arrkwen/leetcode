#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
/* 
旋转数组找最小值
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, mid = 0, hi = nums.size() - 1;
        while(lo<hi)
        {
            mid = (hi+lo)>>1;
            if(nums[mid]<=nums[hi])//右区间连续，都是小数，那么一定在左区间，注意是小于等于！！！！
                hi=mid;
            else                  //右区间不连续，则在左区间
                lo = mid+1;
        }
        return nums[lo];
    }
};

int main()
{
    vector<int> a{4,5,6,7,0,1,2};
    Solution p;
    cout << p.findMin(a) << endl;
    return 0;
}