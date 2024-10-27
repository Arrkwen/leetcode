#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int temp1 = 0, temp2 = 0;
        if(n==1)
            return 1;
        map<int, int> path;
        while(n!=1)
        {
            if(path.count(n))
                return 0;
            path[n] = 1;
            while(n!=0)
            {
                temp2 = n % 10;
                n = n / 10;
                temp1 += temp2 * temp2;
            }
            n = temp1;
            temp1 = 0;
        }
        return 1;
    }
};