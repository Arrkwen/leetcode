#include <cstring>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/* 
����ջ
https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484525&amp;idx=1&amp;sn=3d2e63694607fec72455a52d9b15d4e5&source=41#wechat_redirect

 */
vector<int> nextGreaterElement(vector<int>& nums) {
    vector<int> ans(nums.size()); // ��Ŵ𰸵�����
    stack<int> s;
    for (int i = nums.size() - 1; i >= 0; i--) { // ������ջ���
        while (!s.empty() && s.top() <= nums[i]) { // �ж����Ӹ߰�
            s.pop(); // �����𿪣�����Ҳ�������ˡ�����
        }
        ans[i] = s.empty() ? -1 : s.top(); // ���Ԫ�����ĵ�һ���߸�
        s.push(nums[i]); // ���ӣ�����֮�������ж��ɣ�
    }
    return ans;
}

int main()
{
    vector<int> nums{2, 1, 2, 4, 3};
    vector<int> res = nextGreaterElement(nums);
    return 0;
}