//
// Created by Lenovo on 2019/7/11.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE36_H
#define LEETCODE_C_PLUSPLUS_LEETCODE36_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode36 {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        int len = 9;
        for (int i = 0; i < len; ++i) {
            if (isRowVaild(i, board) == false or isColumnValid(i, board) == false)
                return false;
        }
        for (int i = 0; i < len; i += 3) {
            for (int j = 0; j < len; j += 3) {
                if (isNineValid(i, j, board) == false)
                    return false;
            }
        }
        return true;
    }

    // 判断每一行是否有效
    bool isRowVaild(int row, vector<vector<char>> &board) {
        vector<char> temp;
        for (int i = 0; i < board[0].size(); ++i) {
            if ('.' == board[row][i])
                continue;
            temp.push_back(board[row][i]);
            for (int j = 0; j < temp.size() - 1; ++j) { // 注意减一，因为最后一个就是检查的这个元素
                if (temp[j] == board[row][i])
                    return false;
            }
        }
        return true;
    }

    // 判断每一列是否有效
    bool isColumnValid(int column, vector<vector<char>> &board) {
        vector<char> temp;
        for (int i = 0; i < board[0].size(); ++i) {
            if (board[i][column] == '.')
                continue;
            temp.push_back(board[i][column]);
            for (int j = 0; j < temp.size() - 1; ++j) {
                if (temp[j] == board[i][column])
                    return false;
            }
        }
        return true;
    }

    // 判断单独一个九宫格是否有效
    bool isNineValid(int row, int column, vector<vector<char>> &board) {
        vector<char> temp;
        for (int i = row; i < row + 3; ++i) {
            for (int j = column; j < column + 3; ++j) {
                if (board[i][j] == '.')
                    continue;
                temp.push_back(board[i][j]);
                for (int k = 0; k < temp.size() - 1; ++k) {
                    if (temp[k] == board[i][j])
                        return false;
                }
            }
        }
        return true;
    }

    // 采用哈希表极简
    bool isValid(vector<vector<char>> &board) {
        vector<unordered_map<int, int>> row(9), col(9), block(9);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                int bindex = (i / 3) * 3 + j / 3;
                char cur = board[i][j];
                if (cur == '.') continue;
                if (row[i].count(cur) || col[j].count(cur) || block[bindex].count(cur)) return false;
                row[i][cur] = 1;
                col[j][cur] = 1;
                block[bindex][cur] = 1;
            }
        }
        return true;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE36_H
