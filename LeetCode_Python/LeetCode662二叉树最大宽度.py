# -*- coding: utf-8 -*-
# @File   : LeetCode662二叉树最大宽度.py
# @Author : Runpeng Zhang
# @Date   : 2020/5/16
# @Desc   : 通过层次遍历来求二叉树的宽度


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        queue = [(root, 0, 0)]
        cur_depth = left = ans = 0
        for node, depth, pos in queue:
            if node:
                queue.append((node.left, depth + 1, pos * 2))
                queue.append((node.right, depth + 1, pos * 2 + 1))
                if cur_depth != depth:
                    cur_depth = depth
                    left = pos
                ans = max(pos - left + 1, ans)
        return ans
