#include <iostream>
#include <math.h>
#include <vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        if(size<2)
            return -1;
        int maxVAL = 0, area = 0;
        int i = 0, j = size-1;
        while(i<j)
        {
            area = (j-i)*min(height[i],height[j]);
            if(area>maxVAL)
                maxVAL = area;
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return maxVAL;
    }
};

int main()
{
    vector<int> arr{1,8,6,2,5,4,8,3,7};
    Solution *p =  new Solution();
    int area = p->maxArea(arr);
    cout<<area<<endl;
    return 0;
}