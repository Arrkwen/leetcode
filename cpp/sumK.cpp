#include <algorithm>
#include <iostream>
#include<unordered_map>
#include <vector>

using namespace std;

/* 
����һ�����������һ������?k������Ҫ�ҵ��������к�Ϊ?k?��������������ĸ�����

ʾ�� 1 :

����:nums = [1,1,1], k = 2
���: 2 , [1,1] �� [1,1] Ϊ���ֲ�ͬ�������


 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (auto& x:nums) {
            pre += x;
            if (mp.find(pre - k) != mp.end()) count += mp[pre - k];
            mp[pre]++;
        }
        return count;
    }
};


int main()
{
    vector<int> nums{28,54,7,-70,22,65,-6};
    Solution p;
    p.subarraySum(nums, 100);
    return 0;
}