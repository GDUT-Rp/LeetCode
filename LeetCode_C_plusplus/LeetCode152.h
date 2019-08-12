//
// Created by Lenovo on 2019/8/12.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE152_H
#define LEETCODE_C_PLUSPLUS_LEETCODE152_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode152 {
public:
    int maxProduct(vector<int>& nums) {
        int max_ = INT_MIN;
        int imax = 1, imin = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0){       //  由于存在负数，那么会导致最大的变最小的，最小的变最大的
                int tmp = imax;
                imax = imin;
                imin = tmp;
            }
            imax = max(imax * nums[i], nums[i]);
            imin = min(imin * nums[i], nums[i]);

            max_ = max(max_, imax);
        }
        return max_;
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE152_H
