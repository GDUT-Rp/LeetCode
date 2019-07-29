//
// Created by Lenovo on 2019/7/29.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE121_H
#define LEETCODE_C_PLUSPLUS_LEETCODE121_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode121 {
public:
    int maxProfit_baoli(vector<int> &prices) {
        int ans = 0;
        for (int i = 0; i < prices.size(); ++i) {
            for (int j = i; j < prices.size(); ++j) {
                ans = max(ans, prices[j] - prices[i]);
            }
        }
        return ans;
    }

    int maxProfit(vector<int> &prices) {
        int minprice = INT_MAX;
        int maxprofit = 0;
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < minprice) {
                minprice = prices[i];       //  跟新最低谷
            } else if (prices[i] - minprice > maxprofit) {
                maxprofit = prices[i] - minprice;   //  跟新相差最大值
            }
        }
        return maxprofit;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE121_H
