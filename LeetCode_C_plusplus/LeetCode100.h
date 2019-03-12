//
// Created by Lenovo on 2019/3/12.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE100_H
#define LEETCODE_C_PLUSPLUS_LEETCODE100_H

#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution_LeetCode100 {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (nullptr == p and q == nullptr)  return true;
        if (nullptr == p || nullptr == q) return false;
        if (p->val != q->val)   return false;
        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE100_H
