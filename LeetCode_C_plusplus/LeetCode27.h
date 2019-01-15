//
// Created by Lenovo on 2019/1/15.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE27_H
#define LEETCODE_C_PLUSPLUS_LEETCODE27_H

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution_LeetCode27 {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] != val){
                nums[i++] = nums[j];
            }
        }
        return i;
    }

    int removeElementBySwap(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        while (i < n){
            if (nums[i] == val){
                nums[i] = nums[n-1];
                n--;
            }
            else{
                i++;
            }
        }
        return i;
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE27_H
