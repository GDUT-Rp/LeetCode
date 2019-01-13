//
// Created by Lenovo on 2019/1/13.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE9_H
#define LEETCODE_C_PLUSPLUS_LEETCODE9_H

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution_LeetCode9 {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        string temp = str;
        reverse(temp.begin(), temp.end());
        return strcmp(temp.c_str(), str.c_str()) == 0;
    }

    bool faster(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        int revertedNumber = 0;
        while (x > revertedNumber){
            revertedNumber = revertedNumber * 10 + x %10;
            x /= 10;
        }
        return x == revertedNumber || x == revertedNumber / 10;
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE9_H
