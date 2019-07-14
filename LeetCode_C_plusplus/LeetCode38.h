//
// Created by Lenovo on 2019/7/14.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE38_H
#define LEETCODE_C_PLUSPLUS_LEETCODE38_H

#include <iostream>

using namespace std;

class Solution_LeetCode38 {
public:
    string countAndSay(int n) {
        string res = "1";
        string tmp;
        for (int i = 2; i <= n; ++i) {
            tmp = res;
            res = "";
            int m = tmp.length();   //  长度
            int count = 1;  //  计数
            int j = 1;  //  index
            while (j < m) {
                if (tmp[j] == tmp[j - 1]) {
                    count++;    //  两个数相同
                } else {
                    res += to_string(count);    //  答案先加数量
                    res += tmp[j - 1];    //  答案加上什么数
                    count = 1;  //  重置计数
                }
                j++;
            }
            res += to_string(count);
            res += tmp[m - 1];
        }
        return res;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE38_H
