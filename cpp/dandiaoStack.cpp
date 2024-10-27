#include <cstring>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/* 
单调栈
https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484525&amp;idx=1&amp;sn=3d2e63694607fec72455a52d9b15d4e5&source=41#wechat_redirect

 */
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

int main()
{
    vector<int> nums{2, 1, 2, 4, 3};
    vector<int> res = nextGreaterElement(nums);
    return 0;
}