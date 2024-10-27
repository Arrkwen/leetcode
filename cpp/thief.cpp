#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/* 大家击舍1 */
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> res(size, 0);
        if (size < 1)
            return 0;
        if (size < 2)
            return nums[0];
        res[0] = nums[0];
        res[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++)
        {
            res[i] = max(res[i - 1], res[i - 2] + nums[i]);
        }
        return res[size - 1];
    }
};

/* 大家击舍2 */
class Solution1
{
public:
    int rob1(vector<int> &nums, int start, int end)
    {
        int preMax = 0;
        int currMax = 0;
        for (int i = start; i < end; i++)
        {
            int temp = currMax;
            currMax = max(nums[i] + preMax, currMax);
            preMax = temp;
        }
        return currMax;
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 1)
            return 0;
        if (n < 2)
            return nums[0];
        return max(rob1(nums, 0, n - 1), rob1(nums, 1, n));
    }
};

int main()
{
    vector<int> nums{4, 1, 2, 7, 5, 3, 1};
    Solution1 p;
    cout << p.rob(nums) << endl;
    return 0;
}