//
// Created by Lenovo on 2019/1/15.
//

#ifndef LEETCODE_C_LEETCODE27_H
#define LEETCODE_C_LEETCODE27_H

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    for (int j = 0; j < numsSize; ++j) {
        if (nums[j] != val){
            nums[i++] = nums[j];
        }
    }
    return i;
}

int removeElementBySwap(int* nums, int numsSize, int val){
    int i = 0;
    while (i < numsSize){
        if (nums[i] == val){
            nums[i] = nums[numsSize - 1];
            numsSize--;
        }
        else{
            i++;
        }
    }
    return i;
}


#endif //LEETCODE_C_LEETCODE27_H
