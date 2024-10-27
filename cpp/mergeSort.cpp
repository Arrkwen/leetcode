/* 
https://www.jianshu.com/p/1683cf5cc0c9: 大数据处理
*/

#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &a, int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int *pL = new int[n1+1]();
        int *pR = new int[n2+1]();
        int i = 0, j = 0, k = 0;
        for (i = 0; i <n1; i++)
        {
            pL[i] = a[left + i];
        }
        for (j = 0; j < n2; j++)
        {
            pR[j] = a[mid+1+j];
        }
        i = 0;
        j = 0;
        k = left;
        while(i<n1&&j<n2)
        {
            if(pL[i]<pR[j])
            {
                a[k++] = pL[i++];
            }
            else
            {
                a[k++] = pR[j++];
            }
        }
        while(i<n1)
        {
            a[k++] = pL[i++];
        }
        while(j<n2)
        {
            a[k++] = pR[j++];
        }
        delete[] pL;
        delete[] pR;
        pL = nullptr;
        pR = nullptr;
    }

    void mergeSort(vector<int> &a, int left, int right)
    {
        if (left < right)
        {
            int mid = (right - left) / 2 + left;
            mergeSort(a, left, mid);
            mergeSort(a, mid + 1, right);
            merge(a, left, mid, right);
        }
    }
};

int main()
{

    vector<int> a{2, 4, 3, 1, 10, 8, 7};
    Solution *p = new Solution();
    p->mergeSort(a, 0, 6);
    for (int val : a)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}