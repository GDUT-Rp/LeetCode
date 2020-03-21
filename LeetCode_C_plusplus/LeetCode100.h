//
// Created by Lenovo on 2019/3/12.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE100_H
#define LEETCODE_C_PLUSPLUS_LEETCODE100_H

#include <iostream>
#include <deque>

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

class Solution_LeetCode100 {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (nullptr == p and q == nullptr) return true;
        if (nullptr == p || nullptr == q) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }

    bool queueIsSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL and q == NULL) return true;
        if (!check(p, q)) return false;

        // init deuqes
        deque<TreeNode *> deqP, deqQ;
        deqP.push_back(p);
        deqQ.push_back(q);

        while (!deqP.empty()) {
            p = deqP.front();
            deqP.pop_front();
            q = deqQ.front();
            deqQ.pop_front();

            if (!check(p, q)) return false;
            if (p != NULL) {
                if (!check(p->left, q->left)) return false;
                if (p->left != NULL) {
                    deqP.push_back(p->left);
                    deqQ.push_back(q->left);
                }
                if (!check(p->right, q->right)) return false;
                if (p->right != NULL) {
                    deqP.push_back(p->right);
                    deqQ.push_back(q->right);
                }
            }
        }
        return true;
    }

    bool check(TreeNode *p, TreeNode *q) {
        if (p == NULL and q == NULL) return true;
        if (p == NULL or q == NULL) return false;
        if (p->val != q->val) return false;
        return true;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE100_H
