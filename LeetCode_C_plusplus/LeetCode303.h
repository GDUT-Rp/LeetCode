//
// Created by Lenovo on 2019/10/27.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE303_H
#define LEETCODE_C_PLUSPLUS_LEETCODE303_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class NumArray {
public:
    vector<int> sum;

    NumArray(vector<int>& nums) {
        sum = vector<int> (nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            sum[i + 1] = sum[i] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

#endif //LEETCODE_C_PLUSPLUS_LEETCODE303_H
