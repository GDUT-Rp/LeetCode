//
// Created by Lenovo on 2019/7/15.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE41_H
#define LEETCODE_C_PLUSPLUS_LEETCODE41_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode41 {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int>::iterator it;
        it = find(nums.begin(), nums.end(), 1);
        if (it == nums.end()){
            return 1;
        }   //  没有1直接返回
        int len = nums.size();
        for (int i = 0; i < len; ++i) {     //  小于0或大于n直接替换为1
            if (nums[i] <= 0 or nums[i] > len){
                nums[i] = 1;
            }
        }
        // 全都是正数了
        for (int i = 0; i < len; ++i) {
            int a = abs(nums[i]);
            if (a == len){
                nums[0] = -abs(nums[0]);    //  用序号为0的位置来判断是否有len的值
            }else{
                nums[a] = -abs(nums[a]);    //  存在的值都将其索引值置为负数
            }
        }

        for (int i = 1; i < len; ++i) {
            if (nums[i] > 0){   //  有正数证明为缺失值
                return i;
            }
        }

        if (nums[0] > 0){   //  没有len的值，证明len是最小的了
            return len;
        }

        return len + 1; //  没有缺失值
    }
};



#endif //LEETCODE_C_PLUSPLUS_LEETCODE41_H
