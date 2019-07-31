//
// Created by Lenovo on 2019/7/31.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE87_H
#define LEETCODE_C_PLUSPLUS_LEETCODE87_H

#include <iostream>
#include <vector>

using namespace std;


class Solution_LeetCode87 {
public:
    bool isScramble(string s1, string s2) {

        if (s1.size() != s2.size())return false;
        if (s1 == s2)return true;
        vector<int> hash(26, 0);    //  用来判断是否完全相同的字母

        for (int i = 0; i < s1.size(); i++)
            hash.at(s1[i] - 'a')++;

        for (int j = 0; j < s2.size(); j++)
            hash.at(s2[j] - 'a')--;

        for (int k = 0; k < 26; k++) {
            if (hash.at(k) != 0)
                return false;
        }

        for (int i = 1; i < s1.size(); i++) {
            if (
                    (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                     isScramble(s1.substr(i, s1.size() - i), s2.substr(i, s1.size() - i)))
                    || (isScramble(s1.substr(0, i), s2.substr(s1.size() - i)) &&
                        isScramble(s1.substr(i), s2.substr(0, s1.size() - i)))
                    )
                return true;
        }
        return false;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE87_H
