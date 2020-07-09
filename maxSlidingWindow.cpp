#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <vector>
#include <queue>


using namespace std;

/* 
给定一个数组 nums，有一个大小为?k?的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k?个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

?

进阶：

你能在线性时间复杂度内解决此题吗？

?

示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 


multimap的思路： 将值作为索引,自动排序
getmax:  每次获取第一个值，便是最大值。
insert: 由于multimap支持相同键值因此可以insert<nums[left],left>
删除：要删除做左边的元素时，便要通过键值快速找到，然后删除值为left的键值对


 */
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        int left = 0;
        int right = 0;
        vector<int> res;
        multimap<int, int, greater<int>> window;
        while (right < k && right < n)
        {
            window.emplace(nums[right], right);
            right++;
        }
        auto it = window.begin();
        res.emplace_back((*it).first);
        typedef multimap<int, int>::iterator authors_it;
        while (right < n)
        {
            auto map_it = window.find(nums[left]);                                //删除nums[left]
            pair<authors_it, authors_it> pos = window.equal_range(map_it->first); //利用一对multimap<string,int>指向第一个出现(c,5)的位置和最后一个出现(c,5)的位置
            while (pos.first != pos.second)
            {
                if (pos.first->second == left) //当pos指向left时
                {
                    pos.first = window.erase(pos.first); //删除后会改变pos迭代器，故赋值给自身，指向删除后的下一个键值对
                    break;
                }
                else
                    ++pos.first; //不进行删除操作则自增
            }
            window.emplace(nums[right], right);
            it = window.begin();
            res.emplace_back((*it).first);
            left++;
            right++;
        }
        return res;
    }
};

/* 

优先级队列的思路：

将<val，pos>作为节点的值，
如果top.second是left，则删除，否则不管。
然后将top.first存入结果中
优先级队列值维护K个节点

 */

class Solution1
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        priority_queue<pair<int, int>> pque;
        int n = nums.size();
        for (int i = 0; i < n;i++)
        {
            pque.push(make_pair(nums[i], i));
            if(i-k+1>=0)
            {
                while(!pque.empty()&&(pque.top().second<i-k+1))
                    pque.pop();
                res.emplace_back(pque.top().first);
            }
        }
        return res;
    }
};


/* 
方法3： 单调队列和单调栈
单调队列：使用双端队列deque实现
https://leetcode-cn.com/problems/sliding-window-maximum/solution/dan-diao-dui-lie-by-labuladong/
 单调栈：
vector<int> nextGreaterElement(vector<int>& nums) {
    vector<int> ans(nums.size()); // 存放答案的数组
    stack<int> s;
    for (int i = nums.size() - 1; i >= 0; i--) { // 倒着往栈里放
        while (!s.empty() && s.top() <= nums[i]) { // 判定个子高矮
            s.pop(); // 矮个起开，反正也被挡着了。。。
        }
        ans[i] = s.empty() ? -1 : s.top(); // 这个元素身后的第一个高个
        s.push(nums[i]); // 进队，接受之后的身高判定吧！
    }
    return ans;
}
 */


int main()
{
    vector<int> nums{2,8,5,6,7,1,7};
    Solution1 p;
    vector<int> res = p.maxSlidingWindow(nums, 3);
    return 0;
}