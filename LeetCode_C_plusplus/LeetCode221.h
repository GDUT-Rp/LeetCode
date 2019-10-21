//
// Created by Lenovo on 2019/10/20.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE221_H
#define LEETCODE_C_PLUSPLUS_LEETCODE221_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode221 {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int rows = matrix.size();
        if (!rows) {
            return 0;
        }
        int cols = rows > 0 ? matrix[0].size() : 0;
        int dp[rows + 1][cols + 1];
        memset(dp, 0, sizeof(dp));
        dp[1][1] = matrix[0][0];
        int max_sqlen = 0;
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                    max_sqlen = max(max_sqlen, dp[i][j]);
                }
            }
        }
        return max_sqlen * max_sqlen;
    }

    int maximalSquare2(vector<vector<char>> &matrix) {
        int rows = matrix.size();
        if (!rows) {
            return 0;
        }
        int cols = rows > 0 ? matrix[0].size() : 0;
        int dp[cols + 1];
        memset(dp, 0, sizeof(dp));
        int max_sqlen = 0, prev = 0;
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                int temp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = min(min(dp[j - 1], prev), dp[j]) + 1;
                    max_sqlen = max(max_sqlen, dp[j]);
                }else{
                    dp[j] = 0;
                }
                prev = temp;
            }
        }
        return max_sqlen * max_sqlen;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE221_H
