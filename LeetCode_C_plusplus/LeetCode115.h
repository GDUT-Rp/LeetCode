//
// Created by Lenovo on 2019/8/5.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE115_H
#define LEETCODE_C_PLUSPLUS_LEETCODE115_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution_LeetCode115 {
public:
    int numDistinct(string s, string t) {
        vector<vector<long long>> dp(t.length() + 1, vector<long long>(s.length() + 1, 0));
        fill(begin(dp[0]), end(dp[0]), 1);                          //  Init
        for (int i = 1; i <= t.length(); ++i) {
            for (int j = 1; j <= s.length(); ++j) {
                if (t[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];     //  dp[i - 1][j - 1]  match s[j],t[i]
                } else {                                            //  dp[i][j - 1] skip s[j]
                    dp[i][j] = dp[i][j - 1];                        //  skip s[j]
                }
            }
        }
        return int(dp[t.length()][s.length()]);
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE115_H
