//
// Created by Lenovo on 2019/3/11.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE28_H
#define LEETCODE_C_PLUSPLUS_LEETCODE28_H

#include <iostream>

using namespace std;

class Solution_LeetCode28 {
public:
    int strStr(string haystack, string needle) {
        int size1 = haystack.size(), size2 = needle.size(), i = 0, j = 0;
        if (size2 == 0) return 0;
        int *next = new int[size2];
        getNext(needle, next);
        while (i < size1) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
            if (j == size2) {
                return i - size2;
            }
        }
        return -1;
    }

    //  KMP
    void getNext(string s, int *next) {
        int j = 0, k = -1;
        next[0] = -1;
        while (j < s.size() - 1) {
            if (k == -1 || s[j] == s[k]) {
                j++;
                k++;
                next[j] = k;
            } else {
                k = next[k];
            }
        }
    }

    // 代码更简洁KMP
    int cleaner(string haystack, string needle) {
        int nSizeH = haystack.size();
        int nSizeN = needle.size();
        if (!nSizeN) return 0;
        if (nSizeH < nSizeN) return -1;
        for (int i = 0; i < nSizeH, nSizeH - i >= nSizeN; i++) {
            if (haystack[i] == needle[0]) {
                int j = 1;
                for (1; j < nSizeN; j++) {
                    if (haystack[i + j] != needle[j])
                        break;
                }
                if (j >= nSizeN) return i;
            }
        }
        return -1;
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE28_H
