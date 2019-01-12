//
// Created by Lenovo on 2019/1/12.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE7_H
#define LEETCODE_C_PLUSPLUS_LEETCODE7_H

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class Solution_LeetCode7 {
public:
    int reverse(int x) {
        int yu = 0;
        int ans = 0;
        while (x != 0) {
            yu = x % 10;
            x /= 10;
            if (ans > INT_MAX / 10 || ans < INT_MIN / 10) return 0;
            ans = ans * 10 + yu;
        }
        return ans;
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE7_H
