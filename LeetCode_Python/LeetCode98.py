# -*- coding: utf-8 -*-
# @File   : LeetCode98.py
# @Author : Runpeng Zhang
# @Date   : 2020/2/18
# @Desc   : 给定一个二叉树，判断其是否是一个有效的二叉搜索树。


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        """
        递归判断其是否是一个有效的二叉搜索树
        :rtype: bool
        """
        def helper(node, lower=float('-inf'), upper=float('inf')):
            if not node:
                return True

            val = node.val
            if val <= lower or val >= upper:
                return False

            if not helper(node.right, val, upper):
                return False
            if not helper(node.left, lower, val):
                return False
            return True

        return helper(root)
