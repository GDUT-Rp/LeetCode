# -*- coding: utf-8 -*-
# https://leetcode-cn.com/problems/reverse-integer/
# 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
import sys


def create_sample():
    return [123, -123, 120, 21, 1534236469, -2147483648]


class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        flag = 1    # 标记是否负数
        if x < 0:
            flag = -1
            x = str(x)[1:]  # 数字部分转换为字符串
        else:
            x = str(x)
        x = x[::-1]         # 反转
        ans = int(x) * flag     # 乘以flag变为奇数偶数
        if ans > (2 << 30) - 1 or ans < (-2 << 30):     # 判断是否溢出
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