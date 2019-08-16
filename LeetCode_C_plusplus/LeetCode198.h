//
// Created by Lenovo on 2019/8/16.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE198_H
#define LEETCODE_C_PLUSPLUS_LEETCODE198_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode198 {
public:
    int rob(vector<int>& nums) {
        int prevMax = 0;
        int currMax = 0;
        for (auto num: nums){
            int temp = currMax;
            currMax = max(prevMax + num, currMax);
            prevMax = temp;
        }
        return currMax;
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE198_H
