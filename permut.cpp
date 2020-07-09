/* 
给定一个 没有重复 数字的序列，返回其所有可能的全排列。
示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

回溯法

 */

/* 
给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    void backtrace(vector<int> &path, vector<int> &chooseList,vector<bool> &visited)
    {
        int m = path.size(), n = chooseList.size();
        if (n == m)
        {
            res.push_back(path);
        }
        int i = 0;
        while (i < n)
        {
            if (i>0&&chooseList[i]==chooseList[i-1]&&visited[i-1]==0)
            {
                //剪枝
            }
            else if(visited[i]==0)
            {
                path.emplace_back(chooseList[i]);
                visited[i] = 1;
                backtrace(path, chooseList,visited);
                path.pop_back();
                visited[i] = 0;
            }
            i++;
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> path;
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), 0);
        backtrace(path, nums,visited);
        return res;
    }
};

int main()
{
    Solution *p = new Solution();
    vector<int> input{1, 1, 2};
    vector<vector<int>> res;
    res = p->permute(input);
    cout << res.size() << endl;
    return 0;
}