# -*- coding: utf-8 -*-


class Solution:
    def romanToInt(self, s):
        """
        152ms, has passed 89.77% codes
        :type s: str
        :rtype: int
        """
        dic = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        num = 0
        for i in range(len(s) - 1):
            if dic[s[i]] < dic[s[i + 1]]:
                num -= dic[s[i]]
            else:
                num += dic[s[i]]
        return num + dic[s[len(s) - 1]]

    def myself(self, s):
        """
        160ms, has passed 75.99% codes
        :type s: str
        :rtype: int
        """
        if len(s) == 0:
            return 0
        adict = {}
        adict['I'] = 1
        adict['V'] = 5
        adict['X'] = 10
        adict['L'] = 50
        adict['C'] = 100
        adict['D'] = 500
        adict['M'] = 1000
        ans = 0
        flag_jump = False
        if len(s) == 1:
            return adict[s]
        for index in range(0, len(s) - 1):
            if flag_jump:
                flag_jump = False
                continue
            temp = adict[s[index + 1]] - adict[s[index]]
            if temp > 0:
                ans += temp
                flag_jump = True
            else:
                ans += adict[s[index]]
                flag_jump = False
        if not flag_jump:  # the last char
            ans += adict[s[-1]]
        return ans


def make_sample():
    samples = ['III', 'IV', 'IX', 'LVIII', 'MCMXCIV']
    return samples


if __name__ == '__main__':
    solution = Solution()
    for i in make_sample():
        print(solution.romanToInt(i))
