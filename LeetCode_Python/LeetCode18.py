# -*- coding: utf-8 -*-


class Solution:
    def fourSum(self, nums, target):
        """
        228ms
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res, dicti = set(), {}
        numLen = len(nums)
        nums.sort()
        for i in range(numLen):
            for j in range(i + 1, numLen):
                key = nums[i] + nums[j]
                if key not in dicti.keys():
                    dicti[key] = [(i, j)]
                else:
                    dicti[key].append((i, j))
        for i in range(numLen):
            for j in range(i + 1, numLen - 2):
                exp = target - nums[i] - nums[j]
                if exp in dicti.keys():
                    for tmpIndex in dicti[exp]:
                        if tmpIndex[0] > j:
                            res.add((nums[i], nums[j], nums[tmpIndex[0]], nums[tmpIndex[1]]))
        return [list(i) for i in res]

    def attempt(self, nums, target):
        """
        3516ms
        :param nums:
        :param target:
        :return:
        """
        ans = []
        if nums is None or len(nums) < 4:
            return ans
        nums.sort()
        for i in range(len(nums) - 3):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            sum3 = target - nums[i]
            for j in range(i + 1, len(nums) - 2):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                sum2 = sum3 - nums[j]
                left = j + 1
                right = len(nums) - 1
                while left < right:
                    if nums[left] + nums[right] == sum2:
                        temp = [nums[i], nums[j], nums[left], nums[right]]
                        ans.append(temp)
                        while left < right and nums[left + 1] == nums[left]:
                            left += 1
                        left += 1
                        while left < right and nums[right - 1] == nums[right]:
                            right -= 1
                        right -= 1
                    elif nums[left] + nums[right] < sum2:
                        while left < right and nums[left + 1] == nums[left]:
                            left += 1
                        left += 1
                    else:
                        while left < right and nums[right - 1] == nums[right]:
                            right -= 1
                        right -= 1
        return ans

    def fourSum_improved(self, nums, target):
        """
        92ms
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res = []
        nums.sort()
        #这种求和为了减少步骤首先是排序比较  哎哎哎
        a = nums[:4]
        if sum(nums[:4]) > target:
            return res
        for index, num in enumerate(nums[:-3]):
            target1 = target - num
            if sum(nums[index: index + 4]) > target:
                break
                #下面的条件是最后的三个数比target1还小就是在target1固定的情况下达不到目标了
                #或者是我现在的数和我上一次的数相同  确实 这种情况下不进行下一个循环就会重复
                #记住 这个条件总的就是 要么达不到 要么会重复所以跳过
            elif sum(nums[-3:]) < target1 or (index > 0 and num == nums[index - 1]):
                continue
                #在固定第一个后第二个数进行循环 因为是四个数所以截止到倒数第三个
            for j in range(index + 1, len(nums) - 2):
                target2 = target1 - nums[j]
                #同样的道理 两种情况剔除
                if nums[j + 1] + nums[j + 2] > target2:
                    break
                elif nums[-2] + nums[-1] < target2 or (j > index + 1 and nums[j] == nums[j - 1]):
                    continue
                    #再把特殊情况剔除后达到我们最后两个数的和等于目标  用双指针法  但为什么这么写会快很多啊 不是很懂 ：（
                l, r = j + 1, len(nums) - 1
                while l < r:
                    temp = nums[l] + nums[r]
                    if temp > target2:
                        r -= 1
                    elif temp < target2:
                        l += 1
                    else:
                        res.append([num, nums[j], nums[l], nums[r]])
                        while l < r and nums[l] == nums[l + 1]:
                            l += 1
                        while l < r and nums[r] == nums[r - 1]:
                            r -= 1
                        #相等之后确实两面都要移  不然会重复 因为这两个数相等的结果都有了
                        l += 1
                        r -= 1
        return res


if __name__ == '__main__':
    solution = Solution()
    nums = [1, 0, -1, 0, -2, 2]
    target = 0
    print(solution.attempt(nums, target))
