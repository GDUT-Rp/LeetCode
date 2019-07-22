//
// Created by Lenovo on 2019/7/22.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE154_H
#define LEETCODE_C_PLUSPLUS_LEETCODE154_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode154 {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low < high && nums[low] >= nums[high]){
            int mid = low + (high - low) / 2;
            if (nums[mid] < nums[low]){
                high = mid;
            }else if (nums[mid] == nums[low]){
                low++;
            }else{
                low = mid + 1;
            }
        }
        return nums[low];
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE154_H
