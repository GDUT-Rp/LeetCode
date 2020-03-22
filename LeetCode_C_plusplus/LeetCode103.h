//
// Created by Lenovo on 2020/3/22.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE103_H
#define LEETCODE_C_PLUSPLUS_LEETCODE103_H

#include <iostream>
#include <vector>
#include <deque>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution_LeetCode103 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        deque<TreeNode*> node_queue;
        node_queue.push_back(root);
        node_queue.push_back(NULL);

        deque<int> level_list;
        bool is_order_left = true;

        while (node_queue.size() > 0) {
            TreeNode* curr_node = node_queue.front();
            node_queue.pop_front();
            if (curr_node != NULL) {
                if (is_order_left) {
                    level_list.push_back(curr_node->val);
                } else {
                    level_list.push_front(curr_node->val);
                }
                if (curr_node->left != NULL) {
                    node_queue.push_back(curr_node->left);
                }
                if (curr_node->right != NULL) {
                    node_queue.push_back(curr_node->right);
                }
            } else {
                vector<int> tmp;
                for (int a:level_list){
                    tmp.push_back(a);
                }
                result.push_back(tmp);
                level_list.clear();
                if (node_queue.size() > 0) {
                    node_queue.push_back(NULL);
                }
                is_order_left = !is_order_left;
            }
        }
        return result;
    }

    vector<vector<int>> zigzagLevelOrderDFS(TreeNode* root) {
        vector<vector<int>> results;
        if (root == NULL) {
            return results;
        }
        zigzagLevelOrderDFS_helper(root, 0, results);
        return results;
    }

    void zigzagLevelOrderDFS_helper(TreeNode* node, int level, vector<vector<int>> & results) {
        if (level >= results.size()) {
            vector<int> new_level;
            new_level.push_back(node->val);
            results.push_back(new_level);
        } else {
            if (level % 2 == 0) {
                results[level].push_back(node->val);
            } else {
                results[level].insert(results[level].begin(), node->val);
            }
        }
        if (node->left != NULL) {
            zigzagLevelOrderDFS_helper(node->left, level + 1, results);
        }
        if (node->right != NULL) {
            zigzagLevelOrderDFS_helper(node->right, level + 1, results);
        }
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE103_H
