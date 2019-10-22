//
// Created by Lenovo on 2019/10/22.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE264_H
#define LEETCODE_C_PLUSPLUS_LEETCODE264_H

#include <iostream>

using namespace std;

class Solution_LeetCode264 {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        int i_2 = 0;
        int i_3 = 0;
        int i_5 = 0;
        for (int i = 1; i < n; ++i) {
            dp[i] = min(min(2 * dp[i_2], 3 * dp[i_3]), 5 * dp[i_5]);
            if (dp[i] >= 2 * dp[i_2]) {
                i_2++;
            }
            if (dp[i] >= 3 * dp[i_3]) {
                i_3++;
            }
            if (dp[i] >= 5 * dp[i_5]) {
                i_5++;
            }
        }
        return dp[n - 1];
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE264_H
