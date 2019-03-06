//
// Created by Lenovo on 2019/3/6.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE35_H
#define LEETCODE_C_PLUSPLUS_LEETCODE35_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode35 {
public:
    int searchInsert(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = (left + right) >> 1;
            if (nums[mid] == target)
                return mid;
            if (left == right) {
                if (nums[mid] < target) //  此时target应该插在后一个
                    mid += 1;
                break;
            }
            if (nums[mid] > target) {
                right = mid - 1;
            }
            if (nums[mid] < target) {
                left = mid + 1;
            }
        }
        return mid;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE35_H
