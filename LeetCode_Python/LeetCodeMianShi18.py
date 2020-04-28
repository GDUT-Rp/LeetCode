# -*- coding: utf-8 -*-
# @File   : LeetCodeMianShi18.py
# @Author : Runpeng Zhang
# @Date   : 2020/4/28
# @Desc   : Leetcode面试题18 删除链表的节点


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        if not head:
            return head
        p, prev = head, head
        while p.next:
            if p.val == val:
                p.val = p.next.val
                p.next = p.next.next
                return head
            prev = p
            p = p.next
        # last one
        prev.next = p.next
        return head
