//
// Created by Lenovo on 2019/11/2.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE312_H
#define LEETCODE_C_PLUSPLUS_LEETCODE312_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode312 {
public:
    int maxCoins(vector<int> &nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // dp[i][j] = maxCoins(nums[i:j+1])
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int len = 1; len <= n; ++len) {
            for (int i = 1; i <= n - len + 1; ++i) {
                int j = i + len - 1;
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = max(dp[i][j],
                                   dp[i][k - 1] + nums[i - 1] * nums[k] * nums[j + 1] + dp[k + 1][j]);
                }
            }
        }
        return dp[1][n];
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE312_H
