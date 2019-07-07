//
// Created by Lenovo on 2019/7/7.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE21_H
#define LEETCODE_C_PLUSPLUS_LEETCODE21_H

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

class Solution_LeetCode21 {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL && l2 == NULL)
            return NULL;
        ListNode *dummyHead = new ListNode(0);
        ListNode *cur = dummyHead;
        while (l1 != NULL || l2 != NULL) {
            if (l1 == NULL || (l2 != NULL && (l1->val >= l2->val))) {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
                continue;
            }
            if (l2 == NULL || (l1 != NULL && (l1->val < l2->val))) {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
                continue;
            }
        }
        return dummyHead->next;
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE21_H
