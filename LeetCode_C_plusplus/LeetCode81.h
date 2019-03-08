//
// Created by Lenovo on 2019/3/7.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE81_H
#define LEETCODE_C_PLUSPLUS_LEETCODE81_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode81 {
public:
    bool search(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right){
            mid = (left + right) >> 1;
            if (nums[mid] == target)    return true;
            else if (nums[mid] < nums[right]){
                if (nums[mid] < target and target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else if (nums[mid] > nums[right]){
                if (nums[left] <= target and target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
                right--;
        }
        return false;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE81_H
