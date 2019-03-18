//
// Created by Lenovo on 2019/3/18.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE31_H
#define LEETCODE_C_PLUSPLUS_LEETCODE31_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode31 {
public:
    void nextPermutation(vector<int> &nums) {
        int len = nums.size();
        int k = -1, l = 0, i = 0;
        for (i = len - 2; i >= 0; --i) {
            if (nums[i + 1] > nums[i]) {
                k = i;
                break;
            }
        }
        if (k == -1) {  //  整体降序
            reverse(nums.begin(), nums.end());
            return;
        }
        // 接下来找i
        for (i = len - 1; i >= 0; --i) {
            if (nums[i] > nums[k]){
                l = i;
                break;
            }
        }
        // 二者交换
        swap(nums[k], nums[l]);
        // 再反转k之后的元素(不包括nums[k])
        reverse(nums.begin() + k + 1, nums.end());
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE31_H
