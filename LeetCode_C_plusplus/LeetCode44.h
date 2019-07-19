//
// Created by Lenovo on 2019/7/19.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE44_H
#define LEETCODE_C_PLUSPLUS_LEETCODE44_H

#include <iostream>

using namespace std;

class Solution_LeetCode44 {
public:
    bool isMatch(string s, string p) {
        //  动态规划
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') {
                dp[0][i] = dp[0][i - 1];
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }

    bool isMatch_shuang(string s, string p) {
        //  双指针法
        int j = 0;
        for (int star = 0, i = 0, last = 0; i < s.length();) {
            if (j < p.size() and (s[i] == p[j] or p[j] == '?')) {
                ++i;
                ++j;
            } else if (j < p.size() and p[j] == '*') {
                last = i;
                star = ++j;
            } else if (star != 0) {
                i = ++last;
                j = star;
            } else return false;
        }
        for (; j < p.size() and p[j] == '*'; ++j);
        return j == p.size();
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE44_H
