//
// Created by Lenovo on 2019/7/30.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE123_H
#define LEETCODE_C_PLUSPLUS_LEETCODE123_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode123 {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<int> f(n, 0);
        int minv = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                f[i] = f[i - 1];
            }
            if (prices[i] > minv) {
                f[i] = max(f[i], prices[i] - minv);
            }
            minv = min(minv, prices[i]);
        }
        int res = f[n - 1];
        int maxv = INT_MIN;
        for (int i = n - 1; i > 0; --i) {
            if (prices[i] < maxv) {
                res = max(res, maxv - prices[i] + f[i - 1]);
            }
            maxv = max(maxv, prices[i]);
        }
        return res;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE123_H
