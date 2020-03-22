# -*- coding: utf-8 -*-
# @File   : LeetCode112.py
# @Author : Runpeng Zhang
# @Date   : 2020/3/22
# @Desc   : 路径总和


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if root is None:
            return False
        if root.left is None and root.right is None and sum == 0:
            return True
        return self.hasPathSum(root.left, sum - root.val) or self.hasPathSum(root.right - root.val)

    def hasPathSum_diedai(self, root: TreeNode, sum: int) -> bool:
        if not root:
            return False

        de = [(root, sum - root.val), ]
        while de:
            node, curr_sum = de.pop()
            if not node.left and not node.right and curr_sum == 0:
                return True
            if node.right:
                de.append((node.right, curr_sum - node.right.val))
            if node.left:
                de.append((node.left, curr_sum - node.left.val))
        return False
