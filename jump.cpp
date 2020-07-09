#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

/*
给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。
示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
?    从下标为 0 跳到下标为 1 的位置，跳?1?步，然后跳?3?步到达数组的最后一个位置。

思路深度搜索，时间复杂度是指数级，寻找最短的跳跃步数,超时;
*/

class Solution
{
public:
    int minStep = INT_MAX;
    void dfs(vector<int> &nums, int index, int step, int n)
    {
        if (index == (n - 1) && step < minStep)
        {
            minStep = step;
            return;
        }
        if (nums[index] == 0 || index >= n)
            return;
        for (int i = 1; i <= nums[index]; i++)
        {
            index += i;
            step++;
            dfs(nums, index, step, n);
            index -= i;
            step--;
        }
    }

    int jump(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 1)
            return 0;
        dfs(nums, 0, 0, n);
        return minStep;
    }
};

/*   
时间复杂度 O（kn)，超时

1 用step[n]，记录每一个位置可达到的最短步数
2 for循环更新遍历每一个nums[i]
   2.1 如果可达到的位置的step没有更新过，便用自己的step值+1更新
   2.2 如果可达到的位置的step更新过，但是步数更大，便用自己的step值+1更新
3 遍历到最后一个时，如果step[n-1]！=0,返回。
*/
class Solution1
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> step(n, 0);
        int upLimit = 0;
        for (int i = 0; i < n-1;i++)
        {
            upLimit = nums[i];
            for (int j = 1; j <= upLimit;j++)
            {
                int k = i + j;
                if(k>=n)
                    break;
                int stepNum = step[i] + 1;
                if(step[k]==0||stepNum<step[k])
                    step[k] = stepNum;
            }
        }
        return step[n - 1];
    }
};



/* 
方法3： 贪心法： 正向搜索，获得当前位置中可以到达的最远位置，然后记录最远位置，
        当遍历到最远位置时，step++,更新，时间复杂度为O(n),空间复杂度为O(1)

如果某一个作为 起跳点 的格子可以跳跃的距离是 3，那么表示后面 3 个格子都可以作为 起跳点。
1. 可以对每一个能作为 起跳点 的格子都尝试跳一次，把 能跳到最远的距离 不断更新。
如果从这个 起跳点 起跳叫做第 1 次 跳跃，那么从后面 3 个格子起跳 都 可以叫做第 2 次 跳跃。
所以，当一次 跳跃 结束时，从下一个格子开始，到现在 能跳到最远的距离，都 是下一次 跳跃 的 起跳点。

1. 对每一次 跳跃 用 for 循环来模拟。
2. 跳完一次之后，更新下一次 起跳点 的范围。
3. 在新的范围内跳，更新 能跳到最远的距离。

记录 跳跃 次数，如果跳到了终点，就得到了结果。

 */
class Solution2
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int step = 0;
        int maxPos = 0;
        int end = 0;
        for (int i = 0; i < n - 1;i++)
        {
            maxPos = max(maxPos, i + nums[i]);//记录最远距离
            if(i==end)
            {
                if(end == maxPos&&nums[i]==0)//如果能达到的最远距离的值为0，说明达不到末尾
                    return -1;
                step++;
                end = maxPos;
            }
        }
        return step;
    }
};

int main()
{
    vector<int> nums{1,1,1,2,0,0,0,1};
    Solution2 p;
    int res = 0;
    res = p.jump(nums);
    cout << res << endl;
    return 0;
}