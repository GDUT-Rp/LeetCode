//
// Created by Lenovo on 2019/7/9.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE25_H
#define LEETCODE_C_PLUSPLUS_LEETCODE25_H

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
//struct ListNode {
//    int val;
//    ListNode *next;
//
//    ListNode(int x) : val(x), next(NULL) {}
//};

class Solution_LeetCode25 {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode* pre;
        ListNode* p = head;
        ListNode* q = head;

        if(!p || k == 1) return p;
        for(int i = 1; i < k; i ++){
            if(!q->next)    return head;    // not enough
            q = q->next;                    // go to the tail of the part
        }
        pre = p;
        head = q;
        while(p->next != head){             // reverse
            q = p->next;
            p->next = p->next->next;
            q->next = pre;
            pre = q;
        }
        p->next =  reverseKGroup(head->next, k);
        head->next = pre;

        return head;
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE25_H
