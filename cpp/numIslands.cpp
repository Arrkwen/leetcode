/* 
给你一个由?'1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

示例 1:
输入:
11110
11010
11000
00000
输出: 1

 */

/* 
1 dfs深度遍历
2 循环遍历每一个元素，如果其相邻元素是1  继续深度遍历其邻居，将其值标记为“2”;
如果是0,2则跳过。
3 
 */

#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int neighber[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<char>> &grid, int x, int y, int rowSize, int colSize)
    {
        int new_x = 0;
        int new_y = 0;
        grid[x][y] = 2; //自我标记,已经遍历过了。
        for (int i = 0; i < 4; i++)
        {
            new_x = x + neighber[i][0];
            new_y = y + neighber[i][1];
            if (0<=new_x && new_x<rowSize && 0<=new_y&&new_y<colSize)
                if(grid[new_x][new_y] == '1')
                    dfs(grid, new_x, new_y, rowSize, colSize);
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int cnt = 0, rowSize = 0, colSize = 0;
        rowSize = grid.size();
        if(rowSize!=0)
            colSize = grid[0].size();
        if(colSize==0)
            return 0;
        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j, rowSize, colSize);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main()
{
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    vector<vector<char>> grid1 = {{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}};
    vector<vector<char>> grid2{};
    Solution *p = new Solution();
    int res = p->numIslands(grid2);
    cout<<res<<endl;
    return 0;
}