//
// Created by Lenovo on 2019/3/13.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE53_H
#define LEETCODE_C_PLUSPLUS_LEETCODE53_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution_LeetCode53 {
public:
    int maxSubArray(vector<int> &nums) {
        int len = nums.size();
        if (len == 0) return 0;
        int ans = nums[0];
        int last = nums[0];
        for (int i = 1; i < len; ++i) {
            last = max(0, last) + nums[i];
            ans = max(ans, last);
        }
        return ans;
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE53_H
