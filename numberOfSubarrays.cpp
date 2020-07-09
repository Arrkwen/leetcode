/* 
给你一个整数数组?nums 和一个整数 k。

如果某个 连续 子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。

请返回这个数组中「优美子数组」的数目。

?

示例 1：

输入：nums = [1,1,2,1,1], k = 3
输出：2
解释：包含 3 个奇数的子数组是 [1,1,2,1] 和 [1,2,1,1] 。

示例 2：

输入：nums = [2,2,2,1,2,2,1,2,2,2], k = 2
输出：16

 */

/* 
思路：遍历一遍数组，记录奇数的下标
m 记录之前的非奇数个数+1；
n记录icur之后的非奇数个数；
则一次迭代，包含ipre和icur的数组数量=m*n；

 */

#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
   int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        vector<int> index{};
        index.push_back(-1);
        for (int i = 0; i < n;i++)
        {
            if(nums[i]&1)
                index.push_back(i);
        }
        index.push_back(n);
        int oddSum = index.size();
        for (int i = 1; i + k < oddSum;i++)
        {
            res += (index[i] - index[i - 1]) * (index[i + k] - index[i + k - 1]);
        }
        return res;
    }
};


int main()
{
    Solution *p = new Solution();
    vector<int> nums = {1,1,2,1,1};
    int k = 3;
    int res = p->numberOfSubarrays(nums, k);
    cout << res<<endl;
    return 0;
}
