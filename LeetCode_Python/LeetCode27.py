# -*- coding: utf-8 -*-
# https://leetcode-cn.com/problems/remove-element/

class Solution:
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        i = 0
        for elem in nums:
            if elem != val:
                nums[i] = elem
                i += 1
        return i

    def removeElementBySwap(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        i = 0
        n = len(nums)
        while i < n:
            if nums[i] == val:
                nums[i] = nums[n - 1]
                n -= 1
            else:
                i += 1
        return i


if __name__ == '__main__':
    nums1 = [1, 2, 2, 3, 4, 5, 7, 6, 2]
    nums2 = [1, 2, 2, 3, 4, 5, 7, 6, 2]
    solution = Solution()
    print(solution.removeElement(nums1, 2))
    print(solution.removeElementBySwap(nums2, 2))