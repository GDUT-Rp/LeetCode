//
// Created by Lenovo on 2019/7/17.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE415_H
#define LEETCODE_C_PLUSPLUS_LEETCODE415_H

#include <iostream>

using namespace std;

class Solution_LeetCode415 {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int index = 0;
        int len = min(len1, len2);
        int flag = 0;   //  进位
        string ans;
        int num;
        int max_len = max(len1, len2);

        while (index < max_len) {
            if (index < len) {
                num = num1[len1 - 1 - index] - '0' + num2[len2 - 1 - index] - '0' + flag;
            } else if (index < len1) {
                num = num1[len1 - 1 - index] - '0' + flag;
            } else {
                num = num2[len2 - 1 - index] - '0' + flag;
            }

            flag = 0;
            if (num <= 9) {
                ans += to_string(num);
            } else {
                flag = 1;
                ans += to_string(num - 10);
            }
            index++;
        }

        if (flag) {
            ans += "1";
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE415_H
