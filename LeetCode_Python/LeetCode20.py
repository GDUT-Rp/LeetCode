# -*- coding: utf-8 -*-


def create_sample():
    sample = "()[]{}"
    return sample


class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        length = len(s)
        if length % 2:
            return False
        else:
            stack = []
            mapping = {")": "(", "}": "{", "]": "["}
            for char in s:
                if char in mapping and stack.__len__() > 0:
                    top_element = stack.pop()
                    if mapping[char] != top_element:
                        return False
                else:
                    stack.append(char)
            return not stack


if __name__ == '__main__':
    solution = Solution()
    print(solution.isValid(create_sample()))
