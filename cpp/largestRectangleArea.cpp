#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

/* 

���� n ���Ǹ�������������ʾ��״ͼ�и������ӵĸ߶ȡ�ÿ�����ӱ˴����ڣ��ҿ��Ϊ 1 ��
���ڸ���״ͼ�У��ܹ����ճ����ľ��ε���������

����ջ
����ջ��Ϊ��������ջ�͵����ݼ�ջ
11. ��������ջ��ջ��Ԫ�ر��ֵ���������ջ
12. ͬ�����ݼ�ջ��ջ��Ԫ�ر��ֵ����ݼ���ջ

�����������涼�Ե�������ջΪ����
21. ����µ�Ԫ�ر�ջ��Ԫ�ش󣬾���ջ
22. ����µ�Ԫ�ؽ�С���Ǿ�һֱ��ջ��Ԫ�ص�������ֱ��ջ������Ԫ��С

��������һ������֮�󣬻���ʲôЧ��
31. ջ�ڵ�Ԫ���ǵ�����
32. ��Ԫ�س�ջʱ��˵�������Ԫ���ǳ�ջԪ������ҵ�һ������С��Ԫ��

�ٸ����ӣ������ͼ������������ 6 ��ջ���� 1 5 6 ��
��������Ԫ���� 2 ����ô 6 ��Ҫ��ջ��
�� 6 ��ջʱ���ұ� 2 ������ 6 �ұߵ�һ���� 6 С��Ԫ�ء�

��Ԫ�س�ջ��˵����ջ��Ԫ���ǳ�ջԪ����ǰ�ҵ�һ������С��Ԫ��
�� 6 ��ջʱ��5 ��Ϊ�µ�ջ������ô 5 ���� 6 ��ߵ�һ���� 6 С��Ԫ�ء�

�����

��Ԫ�س�ջʱ����������Ϊ�߶ȣ�Ȼ��Ѱ�ҿ�ȣ�
�ұ߽磺��ǰҪ����ջ��Ԫ�����Լ�����һ��Ԫ�أ�����֮ǰ�Ķ�����������ұ߽���i-1;
��߽磺�Լ�Ҫ��������ջ��Ԫ���ǳ�ջԪ����ǰ�ҵ�һ������С��Ԫ�أ������߽���st.tpop()+1;
��ˣ�
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