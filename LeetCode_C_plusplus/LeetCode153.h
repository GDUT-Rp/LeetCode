//
// Created by Lenovo on 2019/7/20.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE153_H
#define LEETCODE_C_PLUSPLUS_LEETCODE153_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode153 {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        if (nums[right] > nums[0] or nums.size() == 1) {
            return nums[0];
        }
        while (left <= right) {
//            int mid = left + (right - left) / 2;
            int mid = (left + right) >> 1;
            if (nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }
            if (nums[mid - 1] > nums[mid]) {
                return nums[mid];
            }

            if (nums[mid] > nums[0]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE153_H
