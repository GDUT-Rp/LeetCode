//
// Created by Lenovo on 2019/11/1.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE304_H
#define LEETCODE_C_PLUSPLUS_LEETCODE304_H

#include <iostream>
#include <vector>

using namespace std;

class NumMatrix_LeetCode304 {
public:
    vector<vector<int>> dp;

    NumMatrix_LeetCode304(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return;
        }
        dp = vector<vector<int>>(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int row = 0; row < matrix.size(); ++row) {
            for (int column = 0; column < matrix[0].size(); ++column) {
                dp[row + 1][column + 1] =
                        dp[row + 1][column] + dp[row][column + 1] + matrix[row][column] - dp[row][column];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }

};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */


#endif //LEETCODE_C_PLUSPLUS_LEETCODE304_H
