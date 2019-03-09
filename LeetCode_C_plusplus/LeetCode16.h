//
// Created by Lenovo on 2019/3/8.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE16_H
#define LEETCODE_C_PLUSPLUS_LEETCODE16_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution_LeetCode16 {
public:
    // n^2
    int threeSumClosest(vector<int>& nums, int target) {
        int result = 0;
        int diff = INT_MAX;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int left, right;
        for (int i = 0; i < len; ++i) {
            left = i + 1;
            right = len - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(sum - target) < diff){
                    diff = abs(sum - target);
                    result = sum;
                }
                if (sum < target)
                    left++;
                else
                    right--;
            }
        }
        return result;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE16_H
