# -*- coding: utf-8 -*-
# https://leetcode-cn.com/problems/reverse-integer/
import sys


def create_sample():
    return [123, -123, 120, 21, 1534236469, -2147483648]


class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        flag = 1
        if x < 0:
            flag = -1
            x = str(x)[1:]
        else:
            x = str(x)
        x = x[::-1]
        ans = int(x) * flag
        if ans > (2 << 30) - 1 or ans < (-2 << 30):
            return 0
        else:
            return ans


if __name__ == '__main__':
    solution = Solution()
    for elem in create_sample():
        print(solution.reverse(elem))
    print(sys.maxsize)
    print((-2 << 30))
    print(pow(-2, 31))