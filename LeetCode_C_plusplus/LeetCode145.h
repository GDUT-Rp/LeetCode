//
// Created by Lenovo on 2020/2/19.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE145_H
#define LEETCODE_C_PLUSPLUS_LEETCODE145_H

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution_LeetCode145 {
public:
    vector<int> ans;

    // 利用递归遍历
    vector<int> postorderTraversal(TreeNode *root) {
        postorderHelper(root);
        return ans;
    }

    void postorderHelper(TreeNode *node) {
        if (node == NULL) {
            return;
        }
        postorderHelper(node->left);
        postorderHelper(node->right);
        ans.push_back(node->val);
    }

    // 利用栈来迭代遍历
    vector<int> postorderStackTraversal(TreeNode *root) {
        stack<TreeNode *> mystack;
        vector<int> output;
        if (root == NULL) {
            return output;
        }

        mystack.push(root);
        while (!mystack.empty()) {
            TreeNode *node = mystack.top();
            mystack.pop();
            output.insert(output.begin(), node->val);
            if (node->left != NULL) {
                mystack.push(node->left);
            }
            if (node->right != NULL) {
                mystack.push(node->right);
            }
        }
        return output;
    }

};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE145_H
