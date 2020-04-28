//
// Created by Lenovo on 2020/4/28.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODEMIANSHI18_H
#define LEETCODE_C_PLUSPLUS_LEETCODEMIANSHI18_H

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
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == nullptr) {
            return head;
        }
        ListNode *p = head, *prev = head;
        while (p->next != nullptr) {
            if (p->val == val) {
                p->val = p->next->val;
                p->next = p->next->next;
                return head;
            }
            prev = p;
            p = p->next;
        }
        // 待删除的节点在最后一个节点
        prev->next = nullptr;
        return head;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODEMIANSHI18_H
