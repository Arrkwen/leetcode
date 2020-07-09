#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

/* 

给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。

单调栈
单调栈分为单调递增栈和单调递减栈
11. 单调递增栈即栈内元素保持单调递增的栈
12. 同理单调递减栈即栈内元素保持单调递减的栈

操作规则（下面都以单调递增栈为例）
21. 如果新的元素比栈顶元素大，就入栈
22. 如果新的元素较小，那就一直把栈内元素弹出来，直到栈顶比新元素小

加入这样一个规则之后，会有什么效果
31. 栈内的元素是递增的
32. 当元素出栈时，说明这个新元素是出栈元素向后找第一个比其小的元素

举个例子，配合下图，现在索引在 6 ，栈里是 1 5 6 。
接下来新元素是 2 ，那么 6 需要出栈。
当 6 出栈时，右边 2 代表是 6 右边第一个比 6 小的元素。

当元素出栈后，说明新栈顶元素是出栈元素向前找第一个比其小的元素
当 6 出栈时，5 成为新的栈顶，那么 5 就是 6 左边第一个比 6 小的元素。

结果：

当元素出栈时，以自身作为高度，然后寻找宽度，
右边界：当前要插入栈的元素是自己向后第一个元素，而他之前的都比他大，因此右边界是i-1;
左边界：自己要弹出后，新栈顶元素是出栈元素向前找第一个比其小的元素，因此左边界是st.tpop()+1;
因此：
cur = st.top();
st.pop()
left = s.top()+1;
right = i-1
s = height[cur] *( left-right+1);

 */

int largestRectangleArea(vector<int>& heights)
{
    int ans = 0;
    vector<int> st;
    heights.insert(heights.begin(), 0);
    heights.push_back(0);
    for (int i = 0; i < heights.size(); i++)
    {
        while (!st.empty() && heights[st.back()] > heights[i])
        {
            int cur = st.back();
            st.pop_back();
            int left = st.back()+1;
            int right = i-1;
            ans = max(ans, (right - left + 1) * heights[cur]);
        }
        st.push_back(i);
    }
    return ans;
}

int main()
{
    vector<int> height{2,1,2};
    int maxArea = largestRectangleArea(height);
    cout << maxArea << endl;
    return 0;
}