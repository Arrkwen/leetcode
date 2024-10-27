#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        while (next_permutation(nums.begin(), nums.end()))
            ans.emplace_back(nums);
        return ans;
    }
};

int main()
{
    string str = "123456789";
    vector<int> nums{0, 0, 0, 1, 1, 1, 1, 1};
    Solution p;
    vector<vector<int>> restemp = p.permuteUnique(nums);
    vector<string> res;
    int rowSize = restemp.size();
    int colSize = restemp[0].size();
    string s = "";
    string temp = "";
    for(int i = 0; i < rowSize; i++)
    {
        for(int j = 0; j <= colSize; j++)
        {
            s += str[j];
            if (j < colSize && restemp[i][j] == 1)
            {
                int val = atoi(s.c_str()); //to_string(i) int->str
                if (val >= 600)
                    break;
                s += ".";
                temp += s;
                s.clear();
            }
            if(j==colSize)//遍历到字符串结尾，将满足条件的字符串存入结果中
            {
                int val = atoi(s.c_str());
                if (val >= 600)
                    break;
                temp += s;
                res.emplace_back(temp);
                s.clear();
            }
        }
        s.clear();
        temp.clear();
    }
    cout <<res.size() << endl;
    for (string val : res)
    {
        cout << val << endl;
    }
    return 0;
}