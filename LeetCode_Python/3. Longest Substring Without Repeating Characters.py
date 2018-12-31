# -*- coding: utf-8 -*-

"""
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
示例 1:
输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
"""


class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        滑动窗口方式解决，向右滑动
        时间复杂度: O(2n) = O(n)
        空间复杂度: O(min(m,n)) 取决于字符串 nn 的大小以及字符集/字母 mm 的大小
        :type s: str 输出字符串
        :rtype: int 结果
        """
        length = len(s)
        charset = set()
        ans = 0
        i = 0
        j = 0
        while i < length and j < length:
            if not charset.__contains__(s[j]):
                charset.add(s[j])
                j = j + 1
                ans = max(ans, j - i)
            else:
                charset.remove(s[i])
                i = i + 1
        return ans

    def improve_by_dict(self, s):
        """
        我们可以定义字符到索引的映射，而不是使用集合来判断一个字符是否存在
        时间复杂度: O(2n) = O(n)
        :param s:
        :return:
        """
        length = len(s)
        ans = 0
        chardict = {}
        i, j = 0, 0
        while j < length:
            if chardict.__contains__(s[j]):
                i = max(i, chardict.get(s[j]))
            ans = max(ans, j - i + 1)
            chardict[s[j]] = j + 1
            j = j + 1
        return ans


def build_sample():
    s = "abcabcbb"
    return s


if __name__ == '__main__':
    str = build_sample()
    solution = Solution()
    solution.lengthOfLongestSubstring(str)
    solution.improve_by_dict(str)