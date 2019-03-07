//
// Created by Lenovo on 2019/3/7.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE74_H
#define LEETCODE_C_PLUSPLUS_LEETCODE74_H

#include <iostream>

using namespace std;

class Solution_LeetCode74 {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() or matrix[0].empty()) return false;
        int rows = matrix.size();
        int top = 0, tail = rows - 1;
        int mid;
        while (top <= tail) {
            mid = (top + tail) >> 1;
            if (matrix[mid][0] == target) return true;
            else if (matrix[top][0] <= target and matrix[mid][0] > target) {
                if (mid - top > 1) {
                    tail = mid - 1;
                    continue;
                }
                return row_check(matrix, target, top);
            } else {
                if (tail - top > 1) {
                    top = mid;
                    continue;
                } else if (target < matrix[tail][0]) {
                    return row_check(matrix, target, top);
                } else {
                    return row_check(matrix, target, tail);
                }
            }
        }
        return false;
    }

    bool row_check(vector<vector<int>> &matrix, int target, int row) {
        int columns = matrix[0].size();
        int left = 0, right = columns - 1;
        int mid;
        while (left <= right) {
            mid = (left + right) >> 1;
            if (matrix[row][mid] == target)
                return true;
            else if (matrix[row][left] <= target and target < matrix[row][mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
    bool faster(vector<vector<int>>& matrix, int target){
        int rows = matrix.size();
        if (rows == 0)  return false;
        int columns = matrix[0].size();
        if (columns == 0)   return false;
        int i = 0, j = columns - 1;
        while (i < rows and j >= 0){
            if (target == matrix[i][j]){
                return true;
            }
            else if (target > matrix[i][j]){
                i++;
            }
            else
                j--;
        }
        return false;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE74_H
