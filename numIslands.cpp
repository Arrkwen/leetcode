/* 
����һ����?'1'��½�أ��� '0'��ˮ����ɵĵĶ�ά����������������е����������

�������Ǳ�ˮ��Χ������ÿ������ֻ����ˮƽ�����/����ֱ���������ڵ�½�������γɡ�

���⣬����Լ��������������߾���ˮ��Χ��

ʾ�� 1:
����:
11110
11010
11000
00000
���: 1

 */

/* 
1 dfs��ȱ���
2 ѭ������ÿһ��Ԫ�أ����������Ԫ����1  ������ȱ������ھӣ�����ֵ���Ϊ��2��;
�����0,2��������
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
        grid[x][y] = 2; //���ұ��,�Ѿ��������ˡ�
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