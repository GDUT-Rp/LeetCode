//
// Created by Lenovo on 2019/8/6.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE120_H
#define LEETCODE_C_PLUSPLUS_LEETCODE120_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode120 {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), 0));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (j == 0) {   //  每行第一个
                    dp[i][j] = triangle[i][j] + dp[i - 1][j];
                } else if (j == triangle[i].size() - 1) {   //  每行最后一个
                    dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
                }
            }
        }
        int ans = INT_MAX;  //  最后一行的最小路径和
        ans = *min_element(dp[triangle.size() - 1].begin(), dp[triangle.size() - 1].end());
        return ans;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE120_H
