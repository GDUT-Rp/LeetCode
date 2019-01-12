//
// Created by Lenovo on 2019/1/12.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE5_H
#define LEETCODE_C_PLUSPLUS_LEETCODE5_H

#include <iostream>
#include <stdio.h>
#include <string>

class Solution_LeetCode5 {
public:
    string longestPalindrome(string s) {
        int length = s.length();
        if (length < 1)
            return "";
        else if (length == 1)
            return s;
        int start = 0, end = 0;
        for (int i = 0; i < length; ++i) {
            int len1 = expandAround(s, i, i);
            int len2 = expandAround(s, i, i + 1);
            int len = max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
    int expandAround(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE5_H
