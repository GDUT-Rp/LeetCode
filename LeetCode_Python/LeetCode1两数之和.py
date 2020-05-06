# -*- coding: utf-8 -*-
# @File   : LeetCode1两数之和.py
# @Author : Runpeng Zhang
# @Date   : 2020/5/6
# @Desc   : 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。


class Solution:
    def twoSum(self, nums, target: int):
        num_dict = {}
        for index, elem in enumerate(nums):
            if target - elem in num_dict:
                return [index, num_dict[target - elem]]
            else:
                num_dict[elem] = index

