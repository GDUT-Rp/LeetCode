//
// Created by Lenovo on 2019/11/15.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE322_H
#define LEETCODE_C_PLUSPLUS_LEETCODE322_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode322 {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[coins[0]] = 1;
        int len = coins.size();
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < len; ++j) {
                if (dp[i - coins[j]] >= 0)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount];
    }


};



#endif //LEETCODE_C_PLUSPLUS_LEETCODE322_H
