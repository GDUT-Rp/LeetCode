# -*- coding: utf-8 -*-


class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = list()
        nums_len = len(nums)
        if nums_len < 3:
            return result
        l, r, dif = 0, 0, 0
        nums.sort()
        for i in range(nums_len - 2):
            if nums[i] > 0:
                break
            if i > 0 and nums[i - 1] == nums[i]:
                continue

            l = i + 1
            r = nums_len - 1
            dif = -nums[i]
            while l < r:
                if nums[l] + nums[r] == dif:
                    result.append([nums[l], nums[r], nums[i]])
                    while l < r and nums[l] == nums[l + 1]:
                        l += 1
                    while l < r and nums[r] == nums[r - 1]:
                        r -= 1
                    l += 1
                    r -= 1
                elif nums[l] + nums[r] < dif:
                    l += 1
                else:
                    r -= 1
        return result

    def baoli(self, nums):
        """
        Time Limited
        :param nums:
        :return:
        """
        if len(nums) < 3:
            return []
        result = []
        for i in range(len(nums)-1):
            for j in range(i+1, len(nums)):
                sum = nums[i] + nums[j]
                if -sum in nums:
                    k = nums.index(-sum)
                    if k != i and k != j:
                        temp = sorted([nums[i], nums[j], nums[k]])
                        if temp not in result:
                            result.append(temp)
        return result

    def threeSum_improved(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        dict = {}
        for ele in nums:
            if ele not in dict:
                dict[ele] = 0
            dict[ele] += 1

        if 0 in dict and dict[0] > 2:
            result = [[0, 0, 0]]
        else:
            result = []

        pos = [p for p in dict if p > 0]
        neg = [n for n in dict if n < 0]

        for p in pos:
            for n in neg:
                target = -(p + n)
                if target in dict:
                    if target == p and dict[p] > 1:
                        result.append([n, p, p])
                    elif target == n and dict[n] > 1:
                        result.append([n, n, p])
                    elif target < n or target > p or target == 0:
                        result.append([n, target, p])
        return result


if __name__ == '__main__':
    solution = Solution()
    nums = [-1, 0, 1, 2, -1, -4]
    print(solution.threeSum(nums))