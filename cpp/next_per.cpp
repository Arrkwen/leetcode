#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/* 

1.����1234 ��� 1243���������У��ҳ�һ����ֻ����һ�Σ������һ��������������ٱ���1324 �����1342
2 1359727->1359772
3 2434442->2444432
//˼·�е���ɾ��k���ַ�֮�����С�ֵ��� ��ͷ������ĩβ���ҵ�s[i]>s[i+1]��Ȼ��ɾ��s[i]���������Ƚ���ǰ���Ԫ�ء�

��������������㣺 �ҵ���һ�������������  ��һ�㣺ǿ����һ�����ڶ�ֻ��һ����

//��˱���Ҫ��ĩλ��ʼ�������ҵ���һ��s[i]<s[j]��������֮������
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
        while(i<n&&nums[j]<nums[i])//nums[i]<nums[i+1]��������3
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