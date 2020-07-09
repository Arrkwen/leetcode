#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/* 两个只出现一次的数字 */
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int right = nums.size()-1;
        vector<int> res(2, 0);
        int k = 0, mask = 0;
        for (int i = 0; i <= right;i++)
            k = k ^ nums[i];
        mask = k & (-k);
        for(int num:nums)
        {
            if((num&mask)==0)
                res[0] ^= num;
            else
                res[1] ^= num;
        }
        return res;
    }
};

/* 三个只出现一次的数字：
https://blog.csdn.net/sunmenggmail/article/details/8035008?depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-1&utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-1
 */
int main()
{
    vector<int> nums{4, 1,4,6};
    Solution p;
    vector<int> res = p.singleNumbers(nums);
    return 0;
}

