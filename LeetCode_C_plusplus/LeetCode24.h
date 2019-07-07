//
// Created by Lenovo on 2019/7/7.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE24_H
#define LEETCODE_C_PLUSPLUS_LEETCODE24_H

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
class Solution_LeetCode24 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while(cur->next != NULL && cur->next->next !=NULL){
            ListNode* node1 = cur->next;
            ListNode* node2 = node1->next;
            ListNode* rear = node2->next;
            cur->next = node2;
            node2->next = node1;
            node1->next = rear;
            cur = node1;
        }
        return dummyHead->next;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE24_H
