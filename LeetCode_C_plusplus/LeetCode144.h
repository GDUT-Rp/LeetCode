//
// Created by Lenovo on 2020/2/19.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE144_H
#define LEETCODE_C_PLUSPLUS_LEETCODE144_H

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution_LeetCode144 {
public:
    vector<int> ans;

    // 利用递归遍历
    vector<int> preorderTraversal(TreeNode *root) {
        preorderHelper(root);
        return ans;
    }

    void preorderHelper(TreeNode *node) {
        if (node == NULL) {
            return;
        }
        ans.push_back(node->val);
        preorderHelper(node->left);
        preorderHelper(node->right);
    }

    // 利用栈来迭代遍历
    vector<int> preorderStackTraversal(TreeNode *root) {
        stack<TreeNode*> mystack;
        vector<int> output;
        if (root == NULL) {
            return output;
        }

        mystack.push(root);
        while (!mystack.empty()) {
            TreeNode *node = mystack.top();
            mystack.pop();
            output.push_back(node->val);
            if (node->right != NULL) {
                mystack.push(node->right);
            }
            if (node->left != NULL) {
                mystack.push(node->left);
            }
        }
        return output;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE144_H
