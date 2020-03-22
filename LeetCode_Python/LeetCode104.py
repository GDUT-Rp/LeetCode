# -*- coding: utf-8 -*-
# @File   : LeetCode104.py
# @Author : Runpeng Zhang
# @Date   : 2020/3/22
# @Desc   : 二叉树的最大深度


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        else:
            left_height = self.maxDepth(root.left)
            right_height = self.maxDepth(root.right)
            return max(left_height, right_height) + 1

    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        stack = [(root, 1)]
        depth = 0

        while len(stack) > 0:
            current = stack.pop(0)
            root = current[0]
            current_depth = current[1]
            if root is not None:
                depth = max(depth, current_depth)
                stack.append((root.left, current_depth + 1))
                stack.append((root.right, current_depth + 1))
        return depth