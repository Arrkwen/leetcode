#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/* 
ʵ�ֻ�ȡ��һ�����еĺ������㷨��Ҫ���������������������г��ֵ�������һ����������С�

�����������һ����������У��������������г���С�����У����������У���

����ԭ���޸ģ�ֻ����ʹ�ö��ⳣ���ռ䡣

������һЩ���ӣ�����λ������У�����Ӧ���λ���Ҳ��С�
1,2,3 �� 1,3,2
3,2,1 �� 1,2,3
1,1,5 �� 1,5,1

234442->244423
1254441->142445:

//˼·�� ͬnext_per����û��ֻ����һ�ε����ƣ����ǳ������µ����ƣ���һ�������ȫ���С�
�����һ��Ϊ�����������ı任Ϊ
1 ��ĩβ��ʼ �ҵ���һ���ƻ������λ��pos j-1,Ȼ������ң��ҵ���һ����posj-1���������Сλ��i,
   �������ߵ�λ�ã�1254441->1454421:
2 ��jλ�ÿ�ʼ�ҵ���С���ֵ��򣬼�sort����reverse��1454421->1412445
  ��Ϊposj��ʼ��Ԫ��һ���ǽ����źõġ�
 */

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return;
        int j = n - 1;
        while (j > 0 && nums[j] <= nums[j - 1])//�ҵ���һ���ƻ������pos���λ��j
            j--;
        if(j==0)//j=0��ʾȫ������Ϊ��������321,�����ڱ�321��������У��������
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        int i = j;
        while (i < n && nums[i] > nums[j-1])//��jλ�ÿ�ʼ�ҵ�һ����posj-1�����С��һ����
            i++;
        i--;
        swap(nums[i], nums[j-1]);//�������ߵ�λ��
        sort(nums.begin() + j, nums.end());//��posj֮���Ԫ������
    }
};

int main()
{
    Solution p;
    vector<int> nums;
    int val;
    while (1)
    {
        cin >> val;
        nums.emplace_back(val);
        if (getchar() == '\n')
            break;
    }
    p.nextPermutation(nums);
    for (int i : nums)
        cout << i << ",";
    cout << endl;
    return 0;
}
