//
// Created by Lenovo on 2019/3/16.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE122_H
#define LEETCODE_C_PLUSPLUS_LEETCODE122_H

#include<iostream>
#include <vector>

using namespace std;

class Solution_LeetCode122 {
public:
    int maxProfit(vector<int> &prices) {
        int ans = 0, temp;
        for (int i = 1; i < prices.size(); ++i) {
            temp = prices[i] - prices[i - 1];
            if (temp > 0)
                ans += temp;
        }
        return ans;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE122_H
