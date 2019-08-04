//
// Created by Lenovo on 2019/8/4.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE97_H
#define LEETCODE_C_PLUSPLUS_LEETCODE97_H

#include <iostream>
#include <vector>
#include <string>

class Solution_LeetCode97 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) {     //  长度不匹配
            return false;
        }
        bool dp[s1.length() + 1][s2.length() + 1];
        for (int i = 0; i <= s1.length(); ++i) {
            for (int j = 0; j <= s2.length(); ++j) {
                if (i == 0 and j == 0) {
                    dp[i][j] = true;
                } else if (i == 0) {
                    dp[i][j] = dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]);
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1]);
                } else {
                    dp[i][j] = (dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) ||
                               (dp[i][j - 1] && (s2[j - 1]) == s3[i + j - 1]);
                }
            }
        }
        return dp[s1.length()][s2.length()];
    }

    bool isInterleave_one(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) {     //  长度不匹配
            return false;
        }
        bool dp[s2.length() + 1];
        for (int i = 0; i <= s1.length(); ++i) {
            for (int j = 0; j <= s2.length(); ++j) {
                if (i == 0 and j == 0) {
                    dp[j] = true;
                } else if (i == 0) {
                    dp[j] = dp[j - 1] && (s2[j - 1] == s3[i + j - 1]);
                } else if (j == 0) {
                    dp[j] = dp[j] && (s1[i - 1] == s3[i + j - 1]);
                } else {
                    dp[j] = (dp[j] && (s1[i - 1] == s3[i + j - 1])) || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }
        return dp[s2.length()];
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE97_H
