//
// Created by Lenovo on 2019/10/23.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE279_H
#define LEETCODE_C_PLUSPLUS_LEETCODE279_H

#include <iostream>

using namespace std;

class Solution_LeetCode279 {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = i;
            for (int j = 1; i - j * j >= 0; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE279_H
