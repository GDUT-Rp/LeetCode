//
// Created by Lenovo on 2019/3/20.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE6_H
#define LEETCODE_C_PLUSPLUS_LEETCODE6_H

#include <iostream>

using namespace std;

class Solution_LeetCode6 {
public:
    string convert(string s, int numRows) {
        int x = 1, len = s.length(), index;
        if (numRows == 1) return s;
        string ans;
        int flag = 0;
        while (x <= numRows) {
            index = x - 1;
            if (x == 1 or x == numRows) {
                while (index < len) {
                    ans.push_back(s.at(index));
                    index += (numRows * 2 - 2); // numRows == 1 会死循环
                }
            } else {
                flag = 1;       //  增加步长交替
                while (index < len) {
                    ans.push_back(s.at(index));
                    if (flag) {
                        index += (2 * (numRows - x));
                        flag = 0;
                    } else {
                        index += (2 * (x - 1));
                        flag = 1;
                    }
                }
            }
            x++;
        }
        return ans;
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE6_H
