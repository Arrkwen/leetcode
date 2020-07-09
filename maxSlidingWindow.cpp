#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <vector>
#include <queue>


using namespace std;

/* 
����һ������ nums����һ����СΪ?k?�Ļ������ڴ������������ƶ�����������Ҳࡣ��ֻ���Կ����ڻ��������ڵ� k?�����֡���������ÿ��ֻ�����ƶ�һλ��

���ػ��������е����ֵ��

?

���ף�

����������ʱ�临�Ӷ��ڽ��������

?

ʾ��:

����: nums = [1,3,-1,-3,5,3,6,7], �� k = 3
���: [3,3,5,5,6,7] 
����: 


multimap��˼·�� ��ֵ��Ϊ����,�Զ�����
getmax:  ÿ�λ�ȡ��һ��ֵ���������ֵ��
insert: ����multimap֧����ͬ��ֵ��˿���insert<nums[left],left>
ɾ����Ҫɾ������ߵ�Ԫ��ʱ����Ҫͨ����ֵ�����ҵ���Ȼ��ɾ��ֵΪleft�ļ�ֵ��


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
            auto map_it = window.find(nums[left]);                                //ɾ��nums[left]
            pair<authors_it, authors_it> pos = window.equal_range(map_it->first); //����һ��multimap<string,int>ָ���һ������(c,5)��λ�ú����һ������(c,5)��λ��
            while (pos.first != pos.second)
            {
                if (pos.first->second == left) //��posָ��leftʱ
                {
                    pos.first = window.erase(pos.first); //ɾ�����ı�pos���������ʸ�ֵ������ָ��ɾ�������һ����ֵ��
                    break;
                }
                else
                    ++pos.first; //������ɾ������������
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

���ȼ����е�˼·��

��<val��pos>��Ϊ�ڵ��ֵ��
���top.second��left����ɾ�������򲻹ܡ�
Ȼ��top.first��������
���ȼ�����ֵά��K���ڵ�

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
����3�� �������к͵���ջ
�������У�ʹ��˫�˶���dequeʵ��
https://leetcode-cn.com/problems/sliding-window-maximum/solution/dan-diao-dui-lie-by-labuladong/
 ����ջ��
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
 */


int main()
{
    vector<int> nums{2,8,5,6,7,1,7};
    Solution1 p;
    vector<int> res = p.maxSlidingWindow(nums, 3);
    return 0;
}