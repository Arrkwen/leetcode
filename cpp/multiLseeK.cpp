#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/* 
�����ڵ�����ѭ����ˣ���¼��һ�εĽ��
�ƶ�����
��ǰ���ڳɼ�����  �ϴγɼ������Ƴ����ڵĵ�һ��ֵ��Ȼ���������ĵ�һ��ֵ
��ʱ
 */
class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int cnt = 0;
        int m = 1;
        int pre = 0;
        int last = 0;
        while (m <= n)
        {
            long long lastMulti = 1;
            long long curMulti = 1;
            int j = 0;
            for (int i = 0; i <= n - m; i++)
            {
                pre = i - 1;
                last = i + m - 1;
                if (i == 0)
                {
                    for (j = 0; j <= last; j++)
                    {
                        lastMulti *= nums[j];
                        if (lastMulti >= k)
                        {
                            j++;
                            break;
                        }
                    }
                    curMulti = lastMulti;
                }
                else
                {
                    if (pre >= 0)
                    {
                        lastMulti /= nums[pre];
                    }
                    while (j <= last)
                    {
                        curMulti = lastMulti * nums[j];
                        lastMulti = curMulti;
                        if (curMulti >= k)
                        {
                            j++;
                            break;
                        }
                        j++;
                    }
                }
                if (curMulti < k)
                {
                    cnt++;
                }
                lastMulti = curMulti;
            }
            m++;
        }
        return cnt;
    }
};

/* 
˫ָ�뷨��
*/
class Solution1 {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(k<1||n==0)
            return 0;
        int cnt = 0;
        int left = 0;
        int right = 0;
        int multi = 1;
        while(right<n)
        {
            multi*=nums[right];
            while(multi>=k&&left<=right)
            {
                multi/=nums[left];
                left++;
            }
            cnt+=right-left+1;//�൱���ĺ�����
            right++;
        }
        return cnt;
    }
};


int main()
{
    vector<int> nums{1,1,1};
    Solution1 p;
    int res = p.numSubarrayProductLessThanK(nums, 1);
    cout << res << endl;
    return 0;
}