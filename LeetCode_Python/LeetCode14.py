# -*- coding: utf-8 -*-


def create_sample():
    sample1 = ["flower", "flow", "flight"]
    sample2 = ["dog", "racecar", "car"]
    return sample2


class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        ans = ""
        if len(strs) == 0:
            return ""
        min_length = min(len(str) for str in strs)
        for index in range(min_length):
            flag = strs[0][index]
            for str in strs:
                if flag != str[index]:
                    if "".__eq__(ans):
                        return ""
                    else:
                        return ans
            ans += flag
        return ans


if __name__ == '__main__':
    solution = Solution()
    print(solution.longestCommonPrefix(create_sample()))