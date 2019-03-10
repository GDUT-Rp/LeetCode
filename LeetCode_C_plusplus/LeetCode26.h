//
// Created by Lenovo on 2019/3/9.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE26_H
#define LEETCODE_C_PLUSPLUS_LEETCODE26_H

#include <iostream>
#include <vector>

class Solution_LeetCode26 {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty())   return 0;
        if (nums.size() == 1 or (nums[0] == nums[1] and nums.size() == 2)) return 1;
        int fast = 1;
        int slow = 0;
        int length = nums.size();
        while (fast < length){
                if (nums[fast] == nums[slow]) {
                    nums.erase(nums.begin() + fast);
                    length--;
                }
                else {
                    fast++;
                    slow++;
                }
        }
        return nums.size();
    }
    //  把第几个不同的值放在数组第几个位上
    int faster(vector<int>& nums){
        if (nums.empty())   return 0;
        int i = 1, j = 0;
        while(j < nums.size()){
            if (nums[i] == nums[j]){
                j++;
            }
            else{
                nums[++i] = nums[j];
            }
        }
        return i;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE26_H
