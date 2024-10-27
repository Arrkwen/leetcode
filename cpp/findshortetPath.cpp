#include <iostream>
#include <vector>

using namespace std;

int pos[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};


int dfs(vector<vector<char>> nums, int x, int y, char d, int rowSize, int colSize, int &step, vector<vector<bool>> &visited)
{
    int res = INT_MAX;
    int new_x = 0;
    int new_y = 0;
    visited[x][y] = 1;
    if (nums[x][y] == d)
    {
        visited[x][y] = 0;
        return step;
    }
    step++;
    for (int i = 0; i < 4; i++)
    {
        new_x = x + pos[i][0];
        new_y = y + pos[i][1];
        if (0 <= new_x && new_x < rowSize && 0 <= new_y && new_y < colSize && nums[new_x][new_y] != '3' && visited[new_x][new_y] != 1)
        {
            int temp = dfs(nums, new_x, new_y, d, rowSize, colSize, step, visited);
            res = min(res, temp);
        }
    }
    step--;
    visited[x][y] = 0;
    return res;
}

int findPath(vector<vector<char>> nums, char s, char d)
{
    int res = INT_MAX;
    int rowSize = nums.size();
    if (rowSize < 1)
        return res;
    int colSize = nums[0].size();
    if (colSize < 1)
        return res;
    vector<vector<bool>> visited;
    for (int i = 0; i < rowSize; i++)
    {
        visited.emplace_back(vector<bool>(colSize, false));
    }
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            int step = 0;
            if (nums[i][j] == s)
            {
                int temp = dfs(nums, i, j, d, rowSize, colSize, step, visited);
                res = min(res, temp);
            }
        }
    }
    return res;
}

int main()
{
    vector<vector<char>> nums{{'0', '0', '0', '0', '0', '0'}, {'0', '1', '0', '0', '0', '0'}, {'0', '0', '0', '3', '3', '0'}, {'3', '0', '3', '0', '0', '0'}, {'0', '3', '0', '0', '2', '0'}, {'0', '0', '0', '0', '0', '0'}};
    int res = findPath(nums, '1', '2');
    cout << res << endl;
    return 0;
    //cout << "Hello World!" << endl;
}