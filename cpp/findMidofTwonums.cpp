/* 

二分法找两个有序数组的中位数

 */

#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

//二分思路详解：https://leetcode-cn.com/problems/search-insert-position/solution/te-bie-hao-yong-de-er-fen-cha-fa-fa-mo-ban-python-/
/* 
思路：
a数组长度为n，b数组长度为m；

首先，找a和b两个有序数组中第K小，就是在a中找某个位置i，在b中找某个位置j，其满足条件为：
1、i+j=k
2、a[i-1]<=b[j]&&b[j-1]<=a[i]
这样第K小即为：max(a[i-1],b[j-1]);


其次，我们就可以在a数组中二分查找位置i，相应b中位置j=k-i，但是要注意b中j的位置不能越过b的边界即：0<=j<=m，
这样可以得到在a数组中二分查找的范围：0<=i<=n且k-m<=i<=k即max(0,k-m)<=i<=min(k,n);
：解释一下k-m<=i<=k：
为什么要i>=k-m： 因为i = k-j;而0<=j<m,所以k-m<=i<=k;

我们可以在这个范围内用二分模板查找i的位置。
最后，二分找到i即代码中的le后，注意边界判断如果位置i和j前面都有元素，第k小=max(a[i-1],b[j-1]);如果i=0，
第k小=b[j-1];如果j=0;第k小=a[i-1];

两个有序数组的中位数即为：1、两个数组长度(m+n)为奇数，求第(m+n)/2+1小元素；2、两个数组长度(m+n)为偶数，求
第(m+n)/2小、第(m+n)/2+1小,两者平均值。

 */
class Solution {
public:
    double findKthEle(vector<int> nums1,vector<int> nums2,int k)
    {
        int n = nums1.size();
        int m = nums2.size();
        int l1 = max(0, k - m), r1 = min(k, n);//锁定i的范围
        int mid = 0, j = 0;
        while(l1<r1)//利用b[j-1]<=a[i]二分查找i的位置，返回的l1就是i的位置。
        {
            //left = mid+1;采用下取整，如果left=mid 采用上取整 mid = (r1 - l1+1) / 2 + l1;
            mid = (r1 - l1) / 2 + l1;
            j = k - mid;
            //nums[mid]<nums2[j-1] 的元素一定不是解
            if(nums1[mid]<nums2[j-1]) 
            //下一轮的搜索区间：[mid+1,right]
                l1 = mid + 1;
            else
            //if区间的反面[left,mid]        
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