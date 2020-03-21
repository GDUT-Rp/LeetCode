//
// Created by Lenovo on 2020/3/21.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE102_H
#define LEETCODE_C_PLUSPLUS_LEETCODE102_H

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

/**
 * Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution_LeetCode102 {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }
        helper(root, 0, ans);
        return ans;
    }

    void helper(TreeNode *root, int level, vector<vector<int>> &ans) {
        if (ans.size() == level) {
            ans.push_back(vector<int>());
        }

        ans[level].push_back(root->val);

        if (root->left != NULL) {
            helper(root->left, level + 1, ans);
        }
        if (root->right != NULL) {
            helper(root->right, level + 1, ans);
        }
    }

    // 利用队列
    vector<vector<int>> levelOrder_queue(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL){
            return ans;
        }
        int level = 0;
        deque<TreeNode*> queues;
        queues.push_back(root);
        while (queues.size() > 0) {
            ans.push_back(vector<int>());
            int level_length = queues.size();
            for (int i = 0; i < level_length; i++) {
                TreeNode* node = queues.front();
                queues.pop_front();
                ans[level].push_back(node->val);
                if (node->left != NULL) {
                    queues.push_back(node->left);
                }
                if (node->right != NULL) {
                    queues.push_back(node->right);
                }
            }
            level += 1;
        }
        return ans;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE102_H
