//
// Created by Lenovo on 2019/7/17.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE43_H
#define LEETCODE_C_PLUSPLUS_LEETCODE43_H

#include <iostream>

using namespace std;

class Solution_LeetCode43 {
public:
    string multiply(string num1, string num2) {
        string ans;
        int len1 = num1.size();
        int len2 = num2.size();
        int len = len1 + len2;              //  相乘得到的位数，可能没有这么多，所以没那么多位的最后再删
        if (num1 == "0" or num2 == "0") {    //  有一个为0
            return "0";
        }
        for (int i = 0; i < len; ++i) {     //  先占位
            ans += '0';
        }
        int flag = 0;   //  进位
        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                int tmp = (num1[len1 - 1 - i] - '0') * (num2[len2 - 1 - j] - '0') + flag + ans[i + j] - '0';
                flag = 0;
                if (tmp > 9) {  //  判断进位
                    flag = tmp / 10;
                    tmp %= 10;
                }
                ans[i + j] = '0' + tmp;
            }
            if (flag != 0) {
                ans[i + len2] = flag + '0'; //  在一个循环之后，如果还有进位就直接往前添加
                flag = 0;
            }
        }
        if (ans[len - 1] == '0') {   //  有的时候没有进位就会少一位
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());    //  最后再反转过来
        return ans;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE43_H
