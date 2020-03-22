//
// Created by Lenovo on 2020/3/22.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE112_H
#define LEETCODE_C_PLUSPLUS_LEETCODE112_H

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
class Solution_LeetCode112 {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }
        if (root->left == NULL && root->right == NULL && root->val == sum) {
            return true;
        }
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }

    bool hasPathSum_diedai(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }
        vector<TreeNode*> node_stack;
        vector<int> sum_stack;
        node_stack.push_back(root);
        sum_stack.push_back(sum - root->val);

        TreeNode* node;
        int curr_sum;
        while (!node_stack.empty()) {
            node = node_stack.back();
            node_stack.pop_back();
            if ((node->right == NULL) && (node->left == NULL) && (curr_sum == 0)) {
                return true;
            }
            if (node->right != NULL) {
                node_stack.push_back(node->right);
                sum_stack.push_back(curr_sum - node->left->val);
            }
        }
        return false;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE112_H
