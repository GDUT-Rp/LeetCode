//
// Created by Lenovo on 2019/8/26.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE213_H
#define LEETCODE_C_PLUSPLUS_LEETCODE213_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode213 {
public:
    int rob(vector<int> &nums) {
        int len = nums.size();
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> a(len + 1, 0), b(len + 1, 0);   //  初始化
        for (int i = 2; i < len + 1; ++i) {
            //cout << "a" << "[" << i << "]" << " = max(a[" << i - 1 << "], a[" << i - 2 << "] + nums[" << i - 2 << "])"
            //     << " = max(" << a[i - 1] << "," << a[i - 2] << "+" << nums[i - 2] << ")" << endl;
            a[i] = max(a[i - 1], a[i - 2] + nums[i - 2]);   //  去掉尾部
            //cout << "b" << "[" << i << "]" << " = max(b[" << i - 1 << "], b[" << i - 2 << "] + nums[" << i - 1 << "])"
            //     << " = max(" << b[i - 1] << "," << b[i - 2] << "+" << nums[i - 1] << ")" << endl;
            b[i] = max(b[i - 1], b[i - 2] + nums[i - 1]);   //  去掉头部
        }
        return max(a[len], b[len]);     //  返回最大
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE213_H
