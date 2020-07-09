#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

//递归版本
class Solution
{
public:
    int biSearch(vector<int> nums, int start, int end, int target)
    {
        int mid = (end - start) / 2 + start;
        if (nums[mid] == target)
            return mid;
        if (end == start && nums[mid] != target)
            return -1;
        if(nums[mid]>=nums[start])//大数比较多
        {
            if(nums[mid]>target&&nums[start]<=target)// val[start]< target <val[mid]
                return biSearch(nums, start, mid, target);
            else
                return biSearch(nums, mid+1, end, target);
        }
        else                      //小数比较多
        {
            if(nums[mid]<target&&nums[end]>=target) //   val[mid]<target<val[end]
                return biSearch(nums, mid+1, end, target);    
            else
                return biSearch(nums, start, mid, target);
        }
    }
    int search(vector<int> &nums, int target)
    {
        int end = nums.size() - 1;
        if(end<0)
            return -1;
        return biSearch(nums, 0, end, target);
    }
};

//非递归版本
class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() -1;
        
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (target == nums[mid]) return mid;

            if (nums[l] <= nums[mid])
            {
                if (target >= nums[l] && target < nums[mid])
                    r = mid-1;
                else
                    l = mid+1;
            }
            else
            {
                if (target > nums[mid] && target <= nums[r])
                    l = mid +1;
                else
                    r = mid -1;
            }
        }
        return -1;
    }
};

//精简版
class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo == hi && nums[lo] == target ? lo : -1;
    }
};


int main()
{
    vector<int> a{3,1};
    Solution p;
    cout << p.search(a, 1) << endl;
    return 0;
}