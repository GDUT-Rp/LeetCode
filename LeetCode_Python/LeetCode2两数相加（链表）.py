# -*- coding: utf-8 -*-
# @File   : LeetCode2两数相加（链表）.py
# @Author : Runpeng Zhang
# @Date   : 2020/3/24
# @Desc   : 链表两数相加


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        sum = 0
        head = ListNode(0)  # create the head of ListNode
        result = head
        tmp = ListNode(0)
        while l1 or l2:
            if l1:
                sum += l1.val
                l1 = l1.next
            if l2:
                sum += l2.val
                l2 = l2.next
            result.next = ListNode(sum % 10)
            result = result.next
            sum = sum // 10 # Be careful, should be //
        if sum > 0:
            result.next = ListNode(sum)
        return head.next


l1 = ListNode(2)
l1.next = ListNode(4)
l1.next.next = ListNode(3)

l2 = ListNode(5)
l2.next = ListNode(6)
l2.next.next = ListNode(4)

a = Solution()
result = a.addTwoNumbers(l1, l2)
while result:
    print(result.val)
    result = result.next