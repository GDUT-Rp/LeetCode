//
// Created by Lenovo on 2019/8/8.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE139_H
#define LEETCODE_C_PLUSPLUS_LEETCODE139_H

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution_LeetCode139 {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        if (s.empty()) {
            return false;
        }
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 0; i < s.length(); ++i) {
            for (int j = 0; j <= i; ++j) {
                if (dp[j]) {
                    string tmp = s.substr(j, i - j + 1);
                    if (find(wordDict.begin(), wordDict.end(), tmp) != wordDict.end()) {
                        if (i + 1 < dp.size()) {
                            dp[i + 1] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[s.length()];
    }

    bool wordBreak_(string s, vector<string> &wordDict) {

        vector<int> dp(s.size() + 1);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); i++) {
            for (auto word: wordDict) {
                if (i >= word.size() && (s.substr(i - word.size(), word.size()) == word)) {
                    dp[i] = dp[i - word.size()] || dp[i];
                }
            }
        }

        return dp.back();
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE139_H
