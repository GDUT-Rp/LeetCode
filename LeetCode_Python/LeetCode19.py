# -*- coding: utf-8 -*-
# @File   : LeetCode19.py
# @Author : Runpeng Zhang
# @Date   : 2020/4/28
# @Desc   : Leetcode19 删除链表的倒数第N个节点


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        fast, slow = head, head
        for _ in range(n):
            fast = fast.next
        if fast is None:
            return head.next
        while fast.next:
            fast = fast.next
            slow = slow.next
        slow.next = slow.next.next
        return head
