//
// Created by Lenovo on 2019/3/31.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE12_H
#define LEETCODE_C_PLUSPLUS_LEETCODE12_H

#include <iostream>
#include <vector>
#include <string>
#include <map>

class Solution_LeetCode12 {
public:
    string intToRoman(int num) {
        string m[4] = {"", "M", "MM", "MMM"};
        string c[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string x[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string i[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return m[num / 1000] + c[num % 1000 / 100] + x[num % 100 / 10] + i[num % 10];
        // 思路：将每一位数字对应的字母存入数组中，再按位从数组中取出即可
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE12_H
