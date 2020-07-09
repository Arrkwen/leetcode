#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/* 

矩阵中的最大正方形

 */

//暴力法

class Solution
{
public:
    bool allOne(vector<vector<int>> &matrix, int i, int j, int len)
    {
        int rowUpBound = i + len;
        int colUpBound = j + len;
        int flag = 1;
        for (int x = i; x < rowUpBound; x++)
        {
            for (int y = j; y < colUpBound; y++)
            {
                if (matrix[x][y] == 0)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0)
                return 0;
        }
        return 1;
    }

    int maximalSquare(vector<vector<int>> &matrix)
    {

        int possibleMaxEdge = 0;
        int rowSize = matrix.size();
        if (rowSize < 1)
            return 0;
        int colSize = matrix[0].size();
        possibleMaxEdge = min(rowSize, colSize);
        int k = 0;
        for (k = possibleMaxEdge; k >= 0; k--)
        {
            int rowUpBound = (rowSize - k + 1);
            int colUpBound = (colSize - k + 1);
            for (int i = 0; i < rowUpBound; i++)
            {
                for (int j = 0; j < colUpBound; j++)
                {
                    if (allOne(matrix, i, j, k))
                        return k * k;
                }
            }
        }
        return k * k;
    }
};

//dp
class Solution1
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        char MaxEdge = '0';
        int rowSize = matrix.size();
        if (rowSize < 1)
            return 0;
        int colSize = matrix[0].size();
        //dp的边初始化
        vector<vector<char>> dp;
        for (int i = 0; i < rowSize; i++)
            dp.emplace_back(vector<char>(colSize, '0'));
        //row[0][0]
        if (matrix[0][0] == '1')
        {
            dp[0][0] = '1';
            MaxEdge = '1';
        }
        //初始化第一行
        for (int i = 1; i < colSize; i++)
            if (matrix[0][i] == '1')
            {
                dp[0][i] = '1';
                MaxEdge = '1';
            }
        //初始化第一列    
        for (int j = 1; j < rowSize; j++)
            if (matrix[j][0] == '1')
            {
                dp[j][0] = '1';
                MaxEdge = '1';
            }
        //计算中间的。
        for (int x = 1; x < rowSize; x++)
        {
            for (int y = 1; y < colSize; y++)
            {
                if (matrix[x][y] == '1')
                {
                    dp[x][y] = min(dp[x][y - 1], dp[x - 1][y]);
                    dp[x][y] = min(dp[x][y], dp[x - 1][y - 1]);
                    dp[x][y] += 1;
                }
                MaxEdge = max(dp[x][y], MaxEdge);
            }
        }
        int res = MaxEdge - '0';
        return res * res;
    }
};

int main()
{
    vector<vector<char>> matrix{{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    Solution1 p;
    int maxEdge = p.maximalSquare(matrix);
    cout << maxEdge << endl;
    return 0;
}