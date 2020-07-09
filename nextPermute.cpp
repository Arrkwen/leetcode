#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/* 
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

234442->244423
1254441->142445:

//思路： 同next_per但是没有只交换一次的限制，但是出现了新的限制：下一个更大的全排列。
以最后一个为例：所经过的变换为
1 从末尾开始 找到第一个破坏升序的位置pos j-1,然后向后找，找到第一个比posj-1的数大的最小位置i,
   交换二者的位置，1254441->1454421:
2 从j位置开始找到最小的字典序，即sort或者reverse。1454421->1412445
  因为posj开始的元素一定是降序排好的。
 */

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return;
        int j = n - 1;
        while (j > 0 && nums[j] <= nums[j - 1])//找到第一个破坏升序的pos后的位置j
            j--;
        if(j==0)//j=0表示全是升序为最大的数：321,不存在比321更大的排列，输出逆序
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        int i = j;
        while (i < n && nums[i] > nums[j-1])//从j位置开始找到一个比posj-1大的最小的一个数
            i++;
        i--;
        swap(nums[i], nums[j-1]);//交换二者的位置
        sort(nums.begin() + j, nums.end());//对posj之后的元素排序
    }
};

int main()
{
    Solution p;
    vector<int> nums;
    int val;
    while (1)
    {
        cin >> val;
        nums.emplace_back(val);
        if (getchar() == '\n')
            break;
    }
    p.nextPermutation(nums);
    for (int i : nums)
        cout << i << ",";
    cout << endl;
    return 0;
}
