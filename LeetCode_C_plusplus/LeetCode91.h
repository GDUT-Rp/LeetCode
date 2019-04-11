//
// Created by Lenovo on 2019/4/11.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE91_H
#define LEETCODE_C_PLUSPLUS_LEETCODE91_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode91 {
public:
    // 动态规划，dp[i] = dp[i-1]
    // 满足<=“26”,dp[i] += dp[i-2]
    int numDecodings(string s) {
        int len = s.length();
        if (!len) return 0;
        int dp[s.length()];
        memset(dp, 0, sizeof(dp));      //  初始化0
        dp[0] = s[0] == '0' ? 0 : 1;    //  判断0
        if (len == 1)
            return dp[0];
        dp[1] = s[0] > '2' and s[1] == '0' ? 0 : dp[0];     //  "301"
        if (s[0] != '0' and s[1] != '0')                    //  "10", "01"
            dp[1] = s[0] == '1' or (s[0] == '2' and s[1] <= '6') ? 2 : 1;   //  能否构成两种组合
        for (int i = 2; i < len; ++i) {
            if (s[i] != '0') dp[i] = dp[i - 1];
            if (s[i - 1] == '1' or (s[i - 1] == '2' and s[i] <= '6')) dp[i] += dp[i - 2];
        }
        return dp[len - 1];
    }

    // 一样的思路，写起来更简洁
    int easy(string s) {
        int cnt = 0;
        if (s.size() == 0 || (s.size() == 1 && s[0] == '0')) return 0;
        if (s.size() == 1) return 1;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < s.size(); ++i) {
            dp[i + 1] = s[i] == '0' ? 0 : dp[i];
            if (i > 0 && (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))) {
                dp[i + 1] += dp[i - 1];
            }
        }
        return dp.back();
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE91_H
