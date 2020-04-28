//
// Created by Lenovo on 2020/4/28.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODEMIANSHI02_H
#define LEETCODE_C_PLUSPLUS_LEETCODEMIANSHI02_H

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *tmp = node->next;
        node->val = tmp->val;
        node->next = tmp->next;
        delete tmp;
        tmp = nullptr;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODEMIANSHI02_H
