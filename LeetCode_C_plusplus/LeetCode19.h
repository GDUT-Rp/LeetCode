//
// Created by Lenovo on 2019/3/9.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE19_H
#define LEETCODE_C_PLUSPLUS_LEETCODE19_H

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
//    ListNode(int x) : val(x), next(NULL) {}
//};

class Solution_LeetCode19 {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == nullptr || n <= 0)
            return head;
        ListNode *fast = head, *slow = head;
        while(n--)
            fast = fast->next;
        if (fast == nullptr)    // 删除头节点
            return head->next;
        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE19_H
