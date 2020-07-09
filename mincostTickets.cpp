#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int size = days.size();
        if (size < 1)
            return 0;
        int last = days[size - 1];
        vector<int> spend(last + 1, 0);
        int index = 0;
        for (int i = 1; i <= last; i++)
        {
            if (i == days[index])
            {
                int cost = INT_MAX;
                int oneDayAgo = i - 1 > 0 ? i - 1 : 0;
                int sevenDayAgo = i - 7 > 0 ? i - 7 : 0;
                int monthDayAgo = i - 30 > 0 ? i - 30 : 0;

                cost = min(spend[oneDayAgo] + costs[0], cost);
                cost = min(spend[sevenDayAgo] + costs[1], cost);
                cost = min(spend[monthDayAgo] + costs[2], cost);

                spend[i] = cost;
                
                index++;
            }
            else
                spend[i] = spend[i - 1];
        }
        return spend[last];
    }
};

int main()
{
    vector<int> days{1, 2, 3, 4, 5, 6, 7, 8, 10};
    vector<int> costs{2, 7, 15};
    Solution p;
    int res = p.mincostTickets(days, costs);
    cout<<res<<endl;
    return 0;
}