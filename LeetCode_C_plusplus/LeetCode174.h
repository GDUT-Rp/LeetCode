//
// Created by Lenovo on 2019/8/15.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE174_H
#define LEETCODE_C_PLUSPLUS_LEETCODE174_H


#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode174 {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty()){
            return 0;
        }
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, INT_MAX));
        dp[m - 1][n] = dp[m][n - 1] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                if (dp[i][j] <= 0){
                    dp[i][j] = 1;
                }
            }
        }
        return dp[0][0];
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE174_H
