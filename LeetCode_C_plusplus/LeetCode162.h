//
// Created by Lenovo on 2019/7/23.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE162_H
#define LEETCODE_C_PLUSPLUS_LEETCODE162_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode162 {
public:
    int findPeakElement(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (left == right){
                return left;
            }
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE162_H
