# -*- coding: utf-8 -*-

# https://leetcode-cn.com/problems/longest-palindromic-substring/


def create_sample():
    return "babad"


class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        length = len(s)
        if length < 1:
            return ""
        start, end = 0, 0
        for i in range(length):
            len1 = self.expandAroundCenter(s, i, i)
            len2 = self.expandAroundCenter(s, i, i + 1)
            len3 = max(len1, len2)
            if len3 > end - start:
                start = i - (len3 - 1) // 2
                end = i + len3 // 2
        return s[start: end + 1]

    def expandAroundCenter(self, s, left, right):
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return right - left - 1

    def manacher(self, s):
        """
        Manacher算法，时间复杂度O(n)
        :param s:
        :return:
        """
        t = '%#' + '#'.join(list(s)) + '#$'
        length, sup, res = len(t), 0, 0
        li = [1] * length
        reach = pos = 0
        t += '%'
        for i in range(2, length - 1):
            if reach > i:
                if li[2 * pos - i] < reach - i:
                    li[i] = li[2 * pos - i]
                else:
                    li[i] = reach - i + 1
            while t[i + li[i]] == t[i - li[i]]:
                li[i] += 1
            if i + li[i] - 1 > reach:
                reach = i + li[i] - 1
                pos = i
            if li[i] > sup:
                sup = li[i]
                res = i
        return t[res - sup + 2: res + sup:2]

    def fastest(self, s):
        length = len(s)
        if length < 2 or s == s[::-1]:  # 长度为1或者翻转也全等
            return s
        max_len, begin = 1, 0
        for i in range(1, length):
            odd = s[i - max_len - 1:i + 1]
            even = s[i - max_len:i + 1]
            if i - max_len >= 1 and odd == odd[::-1]:
                begin = i - max_len - 1
                max_len += 2
                continue
            if i - max_len >= 0 and even == even[::-1]:
                begin = i - max_len
                max_len += 1
        return s[begin:begin + max_len]


if __name__ == '__main__':
    solution = Solution()
    ans = solution.manacher(create_sample())
    print(ans)