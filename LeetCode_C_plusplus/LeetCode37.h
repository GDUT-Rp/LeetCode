//
// Created by Lenovo on 2019/7/13.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE37_H
#define LEETCODE_C_PLUSPLUS_LEETCODE37_H

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution_LeetCode37 {
public:
    void solveSudoku(vector<vector<char>> &board) {
        suDu(board, 0, 0);
    }

private:
    bool suDu(vector<vector<char>> &board, int i, int j) {
        if (i == 8 && j == 9) return true;    // 到达终点的下一个点
        if (j == 9) {    // 到了每行的末尾的下一个点
            i++;
            j = 0;
        }
        if (board[i][j] != '.') {
            if (suDu(board, i, j + 1)) {
                return true;
            }
        } else {
            int *map = getValidNum(board, i, j);
            for (int k = 1; k < 10; ++k) {
                if (map[k] == 0) {
                    board[i][j] = k + '0';
                    if (suDu(board, i, j + 1)) {
                        return true;
                    }
                    board[i][j] = '.';
                }
            }
        }
        return false;
    }

    int *getValidNum(vector<vector<char>> &board, int i, int j) {
        int *map = (int *) malloc(sizeof(int) * 10);
        memset(map, 0, sizeof(int) * 10);   //  初始化0
        for (int k = 0; k < 9; ++k) {
            if (board[i][k] != '.') {       //  对第i行进行标记已有什么数字
                map[board[i][k] - '0'] = 1;
            }
            if (board[k][j] != '.') {       //  对第j行进行标记已有什么数字
                map[board[k][j] - '0'] = 1;
            }
        }
        //  每个对9宫格的小块标记已有什么数字
        for (int k = 3 * (i / 3); k < 3 * (i / 3) + 3; ++k) {
            for (int l = 3 * (j / 3); l < 3 * (j / 3) + 3; ++l) {
                if (board[k][l] != '.') {
                    map[board[k][l] - '0'] = 1;
                }
            }
        }
        //  返回map，存放这个Int数组，这个（i, j）能有什么数字，1表示已经有这个数了
        return map;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE37_H
