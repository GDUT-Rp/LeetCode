//
// Created by Lenovo on 2020/4/28.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODEMIANSHI22_H
#define LEETCODE_C_PLUSPLUS_LEETCODEMIANSHI22_H

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

class Solution_LeetCodeMianShi22 {
public:
    ListNode *getKthFromEnd(ListNode *head, int k) {
        ListNode *fast = head, *slow = head;
        while (k-- and slow != nullptr) {
            slow = slow->next;
        }
        while (slow != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODEMIANSHI22_H
