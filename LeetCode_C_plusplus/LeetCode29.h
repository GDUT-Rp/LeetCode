//
// Created by Lenovo on 2019/3/5.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE29_H
#define LEETCODE_C_PLUSPLUS_LEETCODE29_H

#include <iostream>
#include <cstdio>
using namespace std;

class Solution_LeetCode29 {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        long long m = abs((long long) dividend);
        long long n = abs((long long) divisor);
        long long res = 0;                                  //  result
        int flag = (dividend < 0) ^ (divisor < 0) ? -1 : 1; //  判断正负
        while (m >= n) {
            long long n_temp = n;
            long long p = 1;
            while (m > (n_temp << 1)) {
                p <<= 1;
                n_temp <<= 1;
            }
            res += p;
            m -= n_temp;
        }
        return flag > 0 ? (int)res : (int)-res;
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE29_H
