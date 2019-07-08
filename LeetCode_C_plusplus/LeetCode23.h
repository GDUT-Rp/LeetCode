//
// Created by Lenovo on 2019/7/8.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE23_H
#define LEETCODE_C_PLUSPLUS_LEETCODE23_H

#include<iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution_LeetCode23 {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0)
            return NULL;

        if (lists.size() == 1)
            return lists[0];

        if (lists.size() == 2)
            return mergeTwoLists(lists[0], lists[1]);

        int mid = lists.size() / 2;

        vector<ListNode *> v1;
        vector<ListNode *> v2;

        for (int i = 0; i <= mid; i++) {
            v1.push_back(lists[i]);
        }

        for (int i = mid + 1; i < lists.size(); i++) {
            v2.push_back(lists[i]);
        }

        ListNode *l1 = mergeKLists(v1);
        ListNode *l2 = mergeKLists(v2);

        return mergeTwoLists(l1, l2);
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode tmp(0);
        ListNode *head = &tmp;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                head->next = l1;
                l1 = l1->next;

            } else {
                head->next = l2;
                l2 = l2->next;

            }
            head = head->next;

        }

        if (l1) {
            head->next = l1;
        }
        if (l2) {
            head->next = l2;
        }

        return tmp.next;
    }

    ListNode *mergeKLists_slow(vector<ListNode *> &lists) {
        ListNode *result = new ListNode(0);
        ListNode *q = result;
        int count = 0;
        while (count < lists.size()) {
            int location = 0; // the index of lists
            int imin = INT_MAX;  // to compare the min value
            for (int i = 0; i < lists.size(); ++i) {    // each time to get the min list
                if (lists[i] == NULL) {
                    lists[i] = new ListNode(INT_MAX);
                    count++;
                    if (count == lists.size()) {
                        return result->next;
                    }
                    continue;
                }
                if (lists[i]->val < imin) {
                    imin = lists[i]->val;
                    location = i;
                }
            }
            q->next = lists[location];
            q = q->next;
            lists[location] = lists[location]->next;
        }
        return result->next;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE23_H
