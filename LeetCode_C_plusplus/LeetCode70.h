//
// Created by Lenovo on 2019/3/3.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE70_H
#define LEETCODE_C_PLUSPLUS_LEETCODE70_H

#include <bits/stdc++.h>

class Solution_LeetCode70 {
public:
    int climbStairs(int n) {
        int nums[888888];
        nums[0] = 0;
        nums[1] = 1;
        nums[2] = 2;
        for (int i = 3; i <= n; ++i) {
            nums[i] = nums[i - 1] + nums[i - 2];
        }
        return nums[n];
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE70_H
