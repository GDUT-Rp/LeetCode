//
// Created by Lenovo on 2019/8/1.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE95_H
#define LEETCODE_C_PLUSPLUS_LEETCODE95_H

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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution_LeetCode95 {
public:
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> res;
        if (n == 0) {
            return res;
        }
        return generate_trees(1, n);
    }

private:
    vector<TreeNode *> generate_trees(int start, int end) {
        vector<TreeNode *> res;
        if (start > end) {
            res.push_back(NULL);
        }
        for (int i = start; i <= end; ++i) {
            vector<TreeNode *> lefts = generate_trees(start, i - 1);
            vector<TreeNode *> rights = generate_trees(i + 1, end);
            for (auto left:lefts) {
                for (auto right:rights) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE95_H
