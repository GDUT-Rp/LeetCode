//
// Created by Lenovo on 2019/3/21.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE55_H
#define LEETCODE_C_PLUSPLUS_LEETCODE55_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode55 {
public:
    bool canJump(vector<int> &nums) {
        int len = nums.size();
        if (len == 1) return true;
        int index = 0;
        int i;
        vector<bool> mark(len, false);  //  标识是否能够给到达
        mark[0] = true; //  第一个围默认能到
        while (index < len - 1) {
            i = 1;
            while (mark[index] and i <= nums[index] and index + i < len) {
                mark[index + i] = true;
                i++;
            }
            index++;
            if (mark[len - 1]) {
                return true;
            }
        }
        return false;
    }

    bool dp(vector<int> &nums) {
        vector<int> dp(nums.size(), 0);
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = max(dp[i-1], nums[i-1]) - 1;
            //  dp[i]表示在第i个位置最多还能向后走几步
            if(dp[i] < 0)   return false;
        }
        return true;
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE55_H
