#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//一个无序数组，且有重复元素，找两个数只和为target,返回下标
//两遍hash
//你能写出一遍hash的方法吗？
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int>res;
        for(int i = 0;i<n;i++)
        {
            mp[nums[i]] = i;
        }

        for(int i = 0; i<n;i++)
        {
            int val = target - nums[i];
            if(mp.count(val)&&mp[val]!=i)
            {
                res.emplace_back(i);
                res.emplace_back(mp[val]);
                break;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums{3, 3};
    Solution p;
    p.twoSum(nums, 6);
    return 0;
}