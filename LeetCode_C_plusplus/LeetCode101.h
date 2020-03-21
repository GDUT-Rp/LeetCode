//
// Created by Lenovo on 2020/3/21.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE101_H
#define LEETCODE_C_PLUSPLUS_LEETCODE101_H

#include <iostream>
#include <deque>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution_LeetCode101 {
public:
    bool isSymmetric(TreeNode* root) {
        return checkSame(root, root);
    }

    bool checkSame(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) return true;	// 均为空
        if (left == NULL || right == NULL) return false;	// 在非均空的条件下存在有一空
        if (left->val != right->val) return false;
        return checkSame(left->left, right->right) && checkSame(left->right, right->left);
    }

    bool isSymmetric_bianli(TreeNode* root) {
        deque<TreeNode*> list;
        list.push_front(root);
        list.push_front(root);
        while (list.size() > 0) {
            TreeNode* t1 = list.front();
            list.pop_front();
            TreeNode* t2 = list.front();
            list.pop_front();
            if (t1 == NULL && t2 == NULL) continue;
            if (t1 == NULL || t2 == NULL) return false;
            if (t1->val != t2->val) return false;
            list.push_front(t1->left);
            list.push_front(t2->right);
            list.push_front(t1->right);
            list.push_front(t2->left);
        }
        return true;
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE101_H
