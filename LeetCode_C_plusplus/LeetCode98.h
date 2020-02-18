//
// Created by Lenovo on 2020/2/18.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE98_H
#define LEETCODE_C_PLUSPLUS_LEETCODE98_H

#include <iostream>
#include <vector>

using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution_LeetCode98 {
public:
    bool isValidBST(TreeNode *root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }

    bool helper(TreeNode *node, long lower, long upper) {
        if (!node) {
            return true;
        }
        if (node->val <= lower || node->val >= upper) return false;
        return helper(node->left, lower, node->val) && helper(node->right, node->val, upper);
    }

};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE98_H
