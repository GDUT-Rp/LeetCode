//
// Created by Lenovo on 2019/3/5.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE33_H
#define LEETCODE_C_PLUSPLUS_LEETCODE33_H

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution_LeetCode33 {
public:
    int search(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = (left + right) >> 1;
            if (nums[mid] == target)    return mid;
            if (nums[left] <= nums[mid]){
                if (nums[left] <= target and target < nums[mid])    //  判断是否在左边的连续有序空间
                    right = mid - 1;
                else left = mid + 1;
            }
            if (nums[mid] <= nums[right]){
                if (nums[mid] < target and target <= nums[right])   //  判断是否在右边的连续有序空间
                    left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE33_H
