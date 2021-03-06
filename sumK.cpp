#include <algorithm>
#include <iostream>
#include<unordered_map>
#include <vector>

using namespace std;

/* 
给定一个整数数组和一个整数?k，你需要找到该数组中和为?k?的连续的子数组的个数。

示例 1 :

输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。


 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (auto& x:nums) {
            pre += x;
            if (mp.find(pre - k) != mp.end()) count += mp[pre - k];
            mp[pre]++;
        }
        return count;
    }
};


int main()
{
    vector<int> nums{28,54,7,-70,22,65,-6};
    Solution p;
    p.subarraySum(nums, 100);
    return 0;
}