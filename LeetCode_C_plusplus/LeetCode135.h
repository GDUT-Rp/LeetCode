//
// Created by Lenovo on 2019/3/30.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE135_H
#define LEETCODE_C_PLUSPLUS_LEETCODE135_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution_LeetCode135 {
public:
    //  贪心思想
    int candy(vector<int> &ratings) {
        int len = ratings.size();
        if (len < 2) return len;
        vector<int> ans(len, 1);            //  每个都是1
        for (int i = 1; i < len; ++i) {     //  先从左边遍历一遍过去
            if (ratings[i] > ratings[i - 1])
                ans[i] = ans[i - 1] + 1;
        }
        for (int j = len - 2; j >= 0; j--) {
            if (ratings[j + 1] < ratings[j])
                ans[j] = max(ans[j], ans[j + 1] + 1);        //  防止被更新小了
        }
        int sum = 0;
        for (int k = 0; k < len; ++k) {     //  求和
            sum += ans[k];
        }
        return sum;
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE135_H
