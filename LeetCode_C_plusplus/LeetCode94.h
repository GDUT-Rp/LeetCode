//
// Created by Lenovo on 2020/2/18.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE94_H
#define LEETCODE_C_PLUSPLUS_LEETCODE94_H

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

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution_LeetCode94 {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        printTree(root, ans);
        return ans;
    }

    TreeNode *createTree() {
        TreeNode *head, *node;
        head = new TreeNode(2);
        head->left = new TreeNode(1);
        head->right = new TreeNode(3);
    }

    void printTree(TreeNode *head, vector<int> &ans) {
        if (head == NULL) {
            return;
        }
        if (head->left != NULL) {
            printTree(head->left, ans);
        }
        ans.push_back(head->val);
        //cout << head->val << " ";
        if (head->right != NULL) {
            printTree(head->right, ans);
        }
        return;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE94_H
