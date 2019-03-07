//
// Created by Lenovo on 2019/3/7.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE50_H
#define LEETCODE_C_PLUSPLUS_LEETCODE50_H

#include <iostream>

using namespace std;

class Solution_LeetCode50 {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        else if (n == 1) return x;
        else if (n == -1) return 1 / x;

        int t = n / 2;
        if (n < 0) {
            t = -t;
            x = 1/x;
        }

        double res = myPow(x, t);
        if (n % 2 == 0) return res * res;
        else return res * res * x;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE50_H
