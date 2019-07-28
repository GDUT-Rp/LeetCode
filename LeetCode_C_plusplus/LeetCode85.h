//
// Created by Lenovo on 2019/7/26.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE85_H
#define LEETCODE_C_PLUSPLUS_LEETCODE85_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode85 {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        int maxarea = 0;
        int dp[matrix.size()][matrix[0].size()];
        memset(dp, 0, sizeof(dp));  //  初始化为0

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = j == 0 ? 1 : dp[i][j - 1] + 1;           //  dp,计算宽度
                    int width = dp[i][j];

                    for (int k = i; k >= 0; k--) {
                        width = min(width, dp[k][j]);                   //  向上每次取该行向下最短宽
                        maxarea = max(maxarea, width * (i - k + 1));    //  最短宽 * 高度
                    }
                }
            }
        }
        return maxarea;
    }

    int maximalRectangle_stack(vector<vector<char>> &matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int left[n];
        int right[n];
        int height[n];

        memset(right, n, sizeof(right));
        memset(left, n, sizeof(left));
        memset(height, n, sizeof(height));

        int maxarea = 0;
        for (int i = 0; i < m; ++i) {
            int cur_left = 0, cur_right = n;
            // update height
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }
            // update left
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], cur_left);
                } else {
                    left[j] = 0, cur_left = j + 1;
                }
            }
            //  update right
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], cur_right);
                } else {
                    right[j] = n;
                    cur_right = j;
                }
            }
            //  update area
            for (int j = 0; j < n; ++j) {
                maxarea = max(maxarea, (right[j] - left[j]) * height[j]);
            }
        }
        return maxarea;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE85_H
