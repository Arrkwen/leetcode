/* 

���ַ������������������λ��

 */

#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

//����˼·��⣺https://leetcode-cn.com/problems/search-insert-position/solution/te-bie-hao-yong-de-er-fen-cha-fa-fa-mo-ban-python-/
/* 
˼·��
a���鳤��Ϊn��b���鳤��Ϊm��

���ȣ���a��b�������������е�KС��������a����ĳ��λ��i����b����ĳ��λ��j������������Ϊ��
1��i+j=k
2��a[i-1]<=b[j]&&b[j-1]<=a[i]
������KС��Ϊ��max(a[i-1],b[j-1]);


��Σ����ǾͿ�����a�����ж��ֲ���λ��i����Ӧb��λ��j=k-i������Ҫע��b��j��λ�ò���Խ��b�ı߽缴��0<=j<=m��
�������Եõ���a�����ж��ֲ��ҵķ�Χ��0<=i<=n��k-m<=i<=k��max(0,k-m)<=i<=min(k,n);
������һ��k-m<=i<=k��
ΪʲôҪi>=k-m�� ��Ϊi = k-j;��0<=j<m,����k-m<=i<=k;

���ǿ����������Χ���ö���ģ�����i��λ�á�
��󣬶����ҵ�i�������е�le��ע��߽��ж����λ��i��jǰ�涼��Ԫ�أ���kС=max(a[i-1],b[j-1]);���i=0��
��kС=b[j-1];���j=0;��kС=a[i-1];

���������������λ����Ϊ��1���������鳤��(m+n)Ϊ���������(m+n)/2+1СԪ�أ�2���������鳤��(m+n)Ϊż������
��(m+n)/2С����(m+n)/2+1С,����ƽ��ֵ��

 */
class Solution {
public:
    double findKthEle(vector<int> nums1,vector<int> nums2,int k)
    {
        int n = nums1.size();
        int m = nums2.size();
        int l1 = max(0, k - m), r1 = min(k, n);//����i�ķ�Χ
        int mid = 0, j = 0;
        while(l1<r1)//����b[j-1]<=a[i]���ֲ���i��λ�ã����ص�l1����i��λ�á�
        {
            //left = mid+1;������ȡ�������left=mid ������ȡ�� mid = (r1 - l1+1) / 2 + l1;
            mid = (r1 - l1) / 2 + l1;
            j = k - mid;
            //nums[mid]<nums2[j-1] ��Ԫ��һ�����ǽ�
            if(nums1[mid]<nums2[j-1]) 
            //��һ�ֵ��������䣺[mid+1,right]
                l1 = mid + 1;
            else
            //if����ķ���[left,mid]        
                r1 = mid;
        }
        int i = l1;
        j = k - i;
        int Nums1maxLeft = i == 0 ? INT_MIN : nums1[i - 1];
        int Nums2maxLeft = i == k ? INT_MIN : nums2[j - 1];
        return max(Nums1maxLeft, Nums2maxLeft);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size()+nums2.size();
        if((n&1)==1)
        {
            return findKthEle(nums1, nums2, (n / 2) + 1);
        }
        else
        {
            return (findKthEle(nums1, nums2, n / 2) + findKthEle(nums1, nums2, n / 2 + 1)) / 2;
        }
    }
};

int main()
{
    vector<int> nums1{1, 3};
    vector<int> nums2{2, 4, 6, 8, 9,10};
    Solution p;
    double res = p.findMedianSortedArrays(nums1, nums2);
    cout<<res<<endl;
    return 0;
}