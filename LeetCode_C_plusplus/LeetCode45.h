//
// Created by Lenovo on 2019/3/22.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE45_H
#define LEETCODE_C_PLUSPLUS_LEETCODE45_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode45 {
public:
    int jump(vector<int> &nums) {
        int len = nums.size();
        if (len <= 1) return 0;
        int p = 0, index = 0, ans = 0;
        while (p < len) {
            if (nums[p] + p >= len - 1)
                return p + 1 == len ? ans : ans + 1;
            int _max = -1;
            for (int i = p + 1; i <= nums[p] + p; ++i) {
                if (_max < i + nums[i]) {
                    _max = i + nums[i];
                    index = i;
                }
            }
            ans++;  //  step
            p = index;
        }
        return ans;
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE45_H
