//
// Created by Lenovo on 2020/3/24.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE206_H
#define LEETCODE_C_PLUSPLUS_LEETCODE206_H

#include <iostream>

/**
 * Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution_LeetCode206 {
public:
    ListNode *reverseListDiedai(ListNode *head) {
        ListNode *prev, *curr, *next;
        prev = NULL;
        curr = head;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode *reverseList(ListNode *head) {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE206_H
