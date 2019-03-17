//
// Created by Lenovo on 2019/3/17.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE8_H
#define LEETCODE_C_PLUSPLUS_LEETCODE8_H

#include <iostream>
#include <string>

using namespace std;

class Solution_LeetCode8 {
public:
    int myAtoi(string str) {
        int len = str.length();
        if (len == 0 or (str[0] != '-' and str[0] != ' ' and str[0] != '+' and (str[0] < '0' or str[0] > '9')))
            return 0;
        int flag = 1;
        long long ans = 0, index = 0;
        while (str[index] == ' ') {
            index++;
        }
        if (str[index] == '-') {
            flag = -1;
            index++;
        } else if (str[index] == '+') {
            index++;
        }
        while (index < len) {
            if (str[index] >= '0' and str[index] <= '9') {
                ans *= 10;
                ans += (str[index++] - '0');
                if (ans * flag < INT_MIN or ans > INT_MAX) {
                    return flag < 0 ? INT_MIN : INT_MAX;
                }
            } else {
                break;
            }
        }
        return (int) ans * flag;
    }

    int faster(string str) {
        long long res = atol(str.c_str());
        if (res >= INT_MAX)
            return INT_MAX;
        else if (res <= INT_MIN)
            return INT_MIN;
        return int(res);
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE8_H
