//
// Created by Lenovo on 2019/7/24.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE72_H
#define LEETCODE_C_PLUSPLUS_LEETCODE72_H

#include <iostream>

using namespace std;

class Solution_LeetCode72 {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        if (n * m == 0) {
            return n + m;
        }

        int d[n + 1][m + 1];
        for (int i = 0; i < n + 1; ++i) {
            d[i][0] = i;
        }
        for (int i = 0; i < m + 1; ++i) {
            d[0][i] = i;
        }

        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < m + 1; ++j) {
                int left = d[i - 1][j] + 1;
                int down = d[i][j - 1] + 1;
                int left_down = d[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1]) {
                    left_down += 1;
                }
                d[i][j] = min(left, min(down, left_down));
            }
        }
        return d[n][m];
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE72_H
