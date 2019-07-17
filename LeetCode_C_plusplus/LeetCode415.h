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
        int num;        //  存放加起来的值（包括进位）
        int max_len = max(len1, len2);

        while (index < max_len) {   //  从最后一位开始加
            if (index < len) {      //  两个相加
                num = num1[len1 - 1 - index] - '0' + num2[len2 - 1 - index] - '0' + flag;
            } else if (index < len1) {      //  num1更长一点
                num = num1[len1 - 1 - index] - '0' + flag;
            } else {                        //  num2更长一点
                num = num2[len2 - 1 - index] - '0' + flag;
            }

            flag = 0;   //  加完进位后赋值为0
            if (num <= 9) {
                ans += to_string(num);
            } else {    //  有进位
                flag = 1;
                ans += to_string(num - 10);
            }
            index++;
        }

        if (flag) {     //  最后仍有进位
            ans += "1";
        }

        reverse(ans.begin(), ans.end());    //  字符串翻转
        return ans;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE415_H
