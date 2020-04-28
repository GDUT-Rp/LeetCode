# -*- coding: utf-8 -*-
# @File   : LeetCodeMianShi02.py
# @Author : Runpeng Zhang
# @Date   : 2020/4/28
# @Desc   : Leetcode面试题02.删除中间节点

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        tmp = node.next
        node.val = tmp.val
        node.next = tmp.next
        del tmp