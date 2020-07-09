#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

/*
����һ���Ǹ��������飬�����λ������ĵ�һ��λ�á�
�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�
���Ŀ����ʹ�����ٵ���Ծ����������������һ��λ�á�
ʾ��:

����: [2,3,1,1,4]
���: 2
����: �������һ��λ�õ���С��Ծ���� 2��
?    ���±�Ϊ 0 �����±�Ϊ 1 ��λ�ã���?1?����Ȼ����?3?��������������һ��λ�á�

˼·���������ʱ�临�Ӷ���ָ������Ѱ����̵���Ծ����,��ʱ;
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
ʱ�临�Ӷ� O��kn)����ʱ

1 ��step[n]����¼ÿһ��λ�ÿɴﵽ����̲���
2 forѭ�����±���ÿһ��nums[i]
   2.1 ����ɴﵽ��λ�õ�stepû�и��¹��������Լ���stepֵ+1����
   2.2 ����ɴﵽ��λ�õ�step���¹������ǲ������󣬱����Լ���stepֵ+1����
3 ���������һ��ʱ�����step[n-1]��=0,���ء�
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
����3�� ̰�ķ��� ������������õ�ǰλ���п��Ե������Զλ�ã�Ȼ���¼��Զλ�ã�
        ����������Զλ��ʱ��step++,���£�ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1)

���ĳһ����Ϊ ������ �ĸ��ӿ�����Ծ�ľ����� 3����ô��ʾ���� 3 �����Ӷ�������Ϊ �����㡣
1. ���Զ�ÿһ������Ϊ ������ �ĸ��Ӷ�������һ�Σ��� ��������Զ�ľ��� ���ϸ��¡�
�������� ������ ���������� 1 �� ��Ծ����ô�Ӻ��� 3 ���������� �� ���Խ����� 2 �� ��Ծ��
���ԣ���һ�� ��Ծ ����ʱ������һ�����ӿ�ʼ�������� ��������Զ�ľ��룬�� ����һ�� ��Ծ �� �����㡣

1. ��ÿһ�� ��Ծ �� for ѭ����ģ�⡣
2. ����һ��֮�󣬸�����һ�� ������ �ķ�Χ��
3. ���µķ�Χ���������� ��������Զ�ľ��롣

��¼ ��Ծ ����������������յ㣬�͵õ��˽����

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
            maxPos = max(maxPos, i + nums[i]);//��¼��Զ����
            if(i==end)
            {
                if(end == maxPos&&nums[i]==0)//����ܴﵽ����Զ�����ֵΪ0��˵���ﲻ��ĩβ
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