//
// Created by Lenovo on 2019/4/2.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE22_H
#define LEETCODE_C_PLUSPLUS_LEETCODE22_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode22 {
public:
    // 回溯算法
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtravel("", ans, n, n);
        return ans;
    }

    void backtravel(string sublist, vector<string> &res, int left, int right) {
        if (left == 0 and right == 0) {
            res.push_back(sublist);
            return;
        }
        if (left > 0) {
            backtravel(sublist + "(", res, left - 1, right);
        }
        if (right > left) {
            backtravel(sublist + ")", res, left, right - 1);
        }
    }

    vector<string> generateParenthesis2(int n) {
        vector<string> ans;
        if (n == 0) ans.push_back("");
        else {
            for (int i = 0; i < n; ++i) {
                for (string left: generateParenthesis2(i))
                    for (string right: generateParenthesis2(n - 1 - i))
                        ans.push_back("(" + left + ")" + right);
            }
        }
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE22_H
