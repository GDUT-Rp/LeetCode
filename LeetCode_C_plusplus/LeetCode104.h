//
// Created by Lenovo on 2020/3/22.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE104_H
#define LEETCODE_C_PLUSPLUS_LEETCODE104_H

#include <iostream>
#include <deque>
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
class Solution {
public:
    int maxDepth_bianli(TreeNode* root) {
        pair<TreeNode*, int> tmp;
        deque<pair<TreeNode*, int>> stacks;
        if (root == NULL) {
            return 0;
        }
        tmp.first = root;
        tmp.second = 1;
        stacks.push_back(tmp);

        int depth = 0;
        while (!stacks.empty()) {
            pair<TreeNode*, int> current = stacks.front();
            stacks.pop_front();
            root = current.first;
            int current_depth = current.second;
            if (root != NULL) {
                depth = max(depth, current_depth);
                tmp.first = root->left;
                tmp.second = current_depth + 1;
                stacks.push_back(tmp);
                tmp.first = root->right;
                stacks.push_back(tmp);
            }
        }
        return depth;
    }

    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int level = 1;
        return maxDepth_dfs(root, level);
    }

    int maxDepth_dfs(TreeNode* node, int level) {
        if (node == NULL) {
            return level;
        }
        int left = level, right = level;
        if (node->left != NULL) {
            left = max(left, maxDepth_dfs(node->left, level + 1));
        }
        if (node->right != NULL) {
            right = max(left, maxDepth_dfs(node->right, level + 1));
        }
        return max(left, right);
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE104_H
