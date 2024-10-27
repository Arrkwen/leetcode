#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
/* 
��ת��������Сֵ
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, mid = 0, hi = nums.size() - 1;
        while(lo<hi)
        {
            mid = (hi+lo)>>1;
            if(nums[mid]<=nums[hi])//����������������С������ôһ���������䣬ע����С�ڵ��ڣ�������
                hi=mid;
            else                  //�����䲻����������������
                lo = mid+1;
        }
        return nums[lo];
    }
};

int main()
{
    vector<int> a{4,5,6,7,0,1,2};
    Solution p;
    cout << p.findMin(a) << endl;
    return 0;
}