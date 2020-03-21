# -*- coding: utf-8 -*-
# @File   : LeetCode101.py
# @Author : Runpeng Zhang
# @Date   : 2020/3/21
# @Desc   : 判断两颗二叉树是否对称


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        return self.digui(root, root)

    def digui(self, left: TreeNode, right: TreeNode):
        if left is None and right is None:
            return True
        if left is None or right is None:
            return False
        return left.val == right.val and self.digui(left.left, right.right) and self.digui(left.right, right.left)

    def bianli(self, root: TreeNode) -> bool:
        list = []
        list.append(root)
        list.append(root)
        while len(list) > 0:
            t1 = list.pop(0)
            t2 = list.pop(0)
            if t1 is None and t2 is None:
                continue
            if t1 is None or t2 is None:
                return False
            if t1.val != t2.val:
                return False
            list.append(t1.left)
            list.append(t2.right)
            list.append(t1.left)
            list.append(t2.right)
        return True