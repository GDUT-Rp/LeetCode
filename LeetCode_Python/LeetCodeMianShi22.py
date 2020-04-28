# -*- coding: utf-8 -*-
# @File   : LeetCodeMianShi22.py
# @Author : Runpeng Zhang
# @Date   : 2020/4/28
# @Desc   : Leetcode面试题22.链表中倒数第k个结点


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        fast, slow = head, head
        for _ in range(k):
            fast = fast.next
        while fast:
            fast, slow = fast.next, slow.next
        return slow
