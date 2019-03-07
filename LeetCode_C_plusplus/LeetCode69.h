//
// Created by Lenovo on 2019/3/7.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE69_H
#define LEETCODE_C_PLUSPLUS_LEETCODE69_H

#include <iostream>

using namespace std;

class Solution_LeetCode69 {
public:
    int mySqrt(int x) {
        int low = 1, high = x / 2 + 1;
        long long mid = 0;
        if (x == 1) return 1;
        else if (x <= 0) return 0;
        while (low <= high) {
            mid = (high + low) >> 1;
            if (mid * mid < x)
                low = mid + 1;
            else if (mid * mid > x)
                high = mid - 1;
            else
                return static_cast<int>(mid);
        }
        return (low + high) / 2;
    }

    int mySqrt_newton(int x) {
        long long guess = x / 2 + 1;
        while (true) {
            if (guess * guess <= x and (guess + 1) * (guess + 1) > x)
                return (int) guess;
            guess = (guess + x / guess) / 2;
        }
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE69_H
