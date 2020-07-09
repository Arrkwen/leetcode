/* 
����һ����������?nums ��һ������ k��

���ĳ�� ���� ��������ǡ���� k ���������֣����Ǿ���Ϊ����������ǡ����������项��

�뷵����������С����������项����Ŀ��

?

ʾ�� 1��

���룺nums = [1,1,2,1,1], k = 3
�����2
���ͣ����� 3 ���������������� [1,1,2,1] �� [1,2,1,1] ��

ʾ�� 2��

���룺nums = [2,2,2,1,2,2,1,2,2,2], k = 2
�����16

 */

/* 
˼·������һ�����飬��¼�������±�
m ��¼֮ǰ�ķ���������+1��
n��¼icur֮��ķ�����������
��һ�ε���������ipre��icur����������=m*n��

 */

#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
   int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        vector<int> index{};
        index.push_back(-1);
        for (int i = 0; i < n;i++)
        {
            if(nums[i]&1)
                index.push_back(i);
        }
        index.push_back(n);
        int oddSum = index.size();
        for (int i = 1; i + k < oddSum;i++)
        {
            res += (index[i] - index[i - 1]) * (index[i + k] - index[i + k - 1]);
        }
        return res;
    }
};


int main()
{
    Solution *p = new Solution();
    vector<int> nums = {1,1,2,1,1};
    int k = 3;
    int res = p->numberOfSubarrays(nums, k);
    cout << res<<endl;
    return 0;
}
