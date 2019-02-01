# -*- coding: utf-8 -*-
"""
LeetCode32
https://leetcode-cn.com/problems/longest-valid-parentheses/
"""


class Solution:
    def longestValidParentheses(self, s):
        if len(s) == 0:
            return 0
        stack = []
        start = 0
        max_value = 0
        for index, elem in enumerate(s):
            if elem == '(':
                stack.append(index)
            else:
                if len(stack) == 0:
                    start = index + 1
                else:
                    stack.pop()
                    if len(stack) == 0:
                        max_value = max(max_value, index - start + 1)
                    else:
                        max_value = max(max_value, index - stack[-1])
        return max_value


def create_sample():
    alist = ['(()', ')()())', "()(())", "()(()", "()(()((("]
    return alist


if __name__ == '__main__':
    solution = Solution()
    for elem in create_sample():
        print(solution.longestValidParentheses(elem))