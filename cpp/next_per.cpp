#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/* 

1.输入1234 输出 1243，从新排列，找出一个数只交换一次，输出第一个比他大的数。再比如1324 输出，1342
2 1359727->1359772
3 2434442->2444432
//思路有点像删除k个字符之后的最小字典序： 从头遍历到末尾：找到s[i]>s[i+1]，然后删除s[i]，并继续比较他前面的元素。

但本题两个特殊点： 找到第一个比他大的数：  第一点：强调第一个，第二只找一个。

//因此遍历要从末位开始遍历，找到第一个s[i]<s[j]，将其与之交换，
 */

class Solution
{
public:
    int next_per(string &nums)
    {
        int n = nums.size();
        if(n<2)
            return -1;
        int j = n - 2;
        while(j>=0)
        {
            if(nums[j]>=nums[j+1])
                j--;
            else
                break;
        }
        if(j<0)
        {
            return -1;
        }
        int i = j+1;
        while(i<n&&nums[j]<nums[i])//nums[i]<nums[i+1]，看例子3
            i++;
        i--;
        swap(nums[i], nums[j]);
        return 0;
    }
};

int main()
{
    string nums;
    cin >> nums;
    Solution p;
    int res = p.next_per(nums);
    if(res==-1)
    {
        reverse(nums.begin(), nums.end());
    }
    cout << nums<<endl;
    return 0;
}