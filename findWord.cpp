#include <cstring>
#include <iostream>
#include <vector>

using namespace std;


/* 
二维数组找单词
 */
int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool dfs(vector<vector<char>> nums, int x, int y, vector<char> target, int &index,vector<vector<bool>> &visited);
bool findWord(vector<vector<char>> nums, vector<char> target);



int main()
{
    vector<vector<char>> nums{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    //vector<char> target{'S','E','E'};
    vector<char> target{'S','A','F'};
    //vector<char> target{'A','B','C','B'};
    //vector<char> target{'A','B','C','C','E','E'};
    int res = findWord(nums, target);
    cout << res << endl;
    return 0;
}
bool dfs(vector<vector<char>> nums, int x, int y, vector<char> target, int &index,vector<vector<bool>> &visited)
{
    int new_x = 0;
    int new_y = 0;
    int row = nums.size();
    int col = nums[0].size();
    int len = target.size();
    visited[x][y] = 1;//表明已经访问过了
    index++;
    if(index==len)
        return 1;
    for (int i = 0;i<4;i++)
    {
        new_x = x + d[i][0];
        new_y = y + d[i][1];
        if(0<=new_x&&new_x<row&&0<=new_y&&new_y<col&&nums[new_x][new_y]==target[index]&&visited[new_x][new_y]==0)
        {
            if(dfs(nums, new_x, new_y, target, index,visited))
                return 1;
        }
    }
    index--;
    visited[x][y] = 0;//由于上次的行不通，所以恢复
    return 0;
}

bool findWord(vector<vector<char>> nums, vector<char> target)
{
    int row = nums.size();
    if(row<1)
        return 0;
    int col = nums[0].size();
    if(col<1)
        return 0;
    int len = target.size();
    if(len<1)
        return 0;
    int index = 0;
    vector<vector<bool>> visited;
    for (int i = 0; i < row; ++i)
        visited.push_back(vector<bool>(col, false));
    for (int i = 0; i < row;i++)
    {
        for (int j = 0; j < col;j++)
        {
            index = 0;
            if(nums[i][j]==target[index])
            {
                if(dfs(nums, i, j, target, index,visited))
                    return 1;
            }
        }
    }
    return 0;
}