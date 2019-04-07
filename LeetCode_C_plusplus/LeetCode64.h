//
// Created by Lenovo on 2019/4/7.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE64_H
#define LEETCODE_C_PLUSPLUS_LEETCODE64_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution_LeetCode64 {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int dp[rows + 1][columns + 1];
        dp[0][0] = grid[0][0];
        for (int i = 1; i < rows; ++i) {
            dp[i][0] = grid[i][0] + dp[i - 1][0];   //  得到左边一列的dp
        }
        for (int i = 1; i < columns; ++i) {
            dp[0][i] = grid[0][i] + dp[0][i - 1];   //  得到上面一列的dp
        }
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < columns; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];    //  上或左最小值
            }
        }
        return dp[rows - 1][columns - 1];
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE64_H
