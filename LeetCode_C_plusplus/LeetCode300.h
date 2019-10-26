//
// Created by Lenovo on 2019/10/25.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE300_H
#define LEETCODE_C_PLUSPLUS_LEETCODE300_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode300 {
public:
    int lengthOfLIS(vector<int> &nums) {
        int len = nums.size();
        if (len == 0) return 0;
        vector<int> dp(len, 1);
        dp[0] = 1;
        int maxans = 1;
        for (int i = 1; i < len; ++i) {
            int maxval = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    maxval = max(maxval, dp[j]);
                }
            }
            dp[i] = maxval + 1;
            maxans = max(maxans, dp[i]);
        }
        return maxans;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE300_H
