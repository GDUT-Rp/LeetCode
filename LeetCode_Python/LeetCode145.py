# -*- coding: utf-8 -*-
# @File   : LeetCode145.py
# @Author : Runpeng Zhang
# @Date   : 2020/2/19
# @Desc   : 二叉树的前序遍历


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def postorderTraversal(self, root: TreeNode):
        """
        二叉树的后序遍历
        :rtype: 二叉树的后序遍历结果列表
        """
        ans = []
        self.postorderHelper(root, ans)
        return ans

    def postorderHelper(self, root: TreeNode, ans):
        """
        二叉树的后序遍历的递归方法
        """
        if not root:
            return
        self.postorderHelper(root.left, ans)
        self.postorderHelper(root.right, ans)
        ans.append(root.val)

    def postorderStackTraversal(self, root: TreeNode):
        """
        利用栈结构进行后序排序，每次先压左孩子，再压右孩子
        :rtype: 二叉树的后序遍历结果数组
        """
        ans = []
        stack = []
        if root is not None:
            stack.append(root)
        while len(stack) > 0:
            root = stack.pop()
            ans.insert(0, root.val)

            if root.left is not None:
                stack.append(root.left)
            if root.right is not None:
                stack.append(root.right)

        return ans