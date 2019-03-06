//
// Created by Lenovo on 2019/3/6.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE34_H
#define LEETCODE_C_PLUSPLUS_LEETCODE34_H

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution_LeetCode34 {
public:
    // 二分法
    vector<int> searchRange(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = (left + right) >> 1;
            if (nums[mid] == target) {
                while (nums[left] != target) {
                    left++;
                }
                while (nums[right] != target) {
                    right--;
                }
                return {left, right};
            }
            if (nums[mid] < target) {
                left = mid + 1;
            }
            if (nums[mid] > target) {
                right = mid - 1;
            }
        }
        return {-1, -1};
    }

    //  双指针法
    vector<int> searchRange_other(vector<int> &nums, int target) {
        vector<int> res = {-1, -1};
        if (nums.empty()) return res;
        for (int i = 0; i < nums.size(); ++i) {
            if (target == nums[i]) {
                res[0] = i;
                break;
            }
        }
        for (int j = nums.size() - 1; j >= 0; --j) {
            if (target == nums[j]) {
                res[1] = j;
                break;
            }
        }
        return res;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE34_H
