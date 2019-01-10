# -*- coding: utf-8 -*-
# https://leetcode-cn.com/problems/median-of-two-sorted-arrays/


class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """

        #   错误代码，过不了样例[1, 2], [-1, 3]

        length1 = len(nums1)
        length2 = len(nums2)
        length_all = length1 + length2
        index_nums1 = 0
        index_nums2 = 0
        middle = length_all // 2
        if length_all % 2:
            for i in range(length_all):
                if index_nums1 + index_nums2 == middle:
                    if middle == 0:
                        if length1:
                            return nums1[0]
                        else:
                            return nums2[0]
                    if length1 != 0 and length2 != 0:
                        if nums1[index_nums1] < nums2[index_nums2]:
                            return nums1[index_nums1]
                        else:
                            return nums2[index_nums2]
                    elif length1 == 0:
                        return nums2[index_nums2]
                    else:
                        return nums1[index_nums1]
                else:
                    if length1 != 0 and length2 != 0:
                        if nums1[index_nums1] < nums2[index_nums2]:
                            if length1 == 1:
                                return nums1[0]
                            if length2 == 1:
                                return nums2[0]
                            if length1 == index_nums1 + 1:
                                index_nums1 -= 1
                                index_nums2 += 1
                            index_nums1 += 1
                        else:
                            if length2 == index_nums2 + 1:
                                index_nums1 += 1
                                index_nums2 -= 1
                            index_nums2 += 1
                    elif length1 == 0:
                        index_nums2 += 1
                    else:
                        index_nums1 += 1

        else:
            for i in range(length_all):
                if index_nums1 + index_nums2 + 1 == middle:
                    if length1 == 0:
                        return (nums2[index_nums2] +
                                nums2[index_nums2 + 1]) / 2
                    if length2 == 0:
                        return (nums1[index_nums1] +
                                nums1[index_nums1 + 1]) / 2
                    return (nums1[index_nums1] + nums2[index_nums2]) / 2
                else:
                    if length1 != 0 and length2 != 0:
                        if nums1[index_nums1] < nums2[index_nums2]:
                            if length1 == index_nums1 + 1:
                                index_nums1 -= 1
                                index_nums2 += 1
                            index_nums1 += 1
                        else:
                            if length2 == index_nums2 + 1:
                                index_nums1 += 1
                                index_nums2 -= 1
                            index_nums2 += 1
                    elif length1 == 0:
                        index_nums2 += 1
                    else:
                        index_nums1 += 1

    def merge(self, nums1, nums2):
        """
        先合并，合并后取中间值返回，较慢
        :param nums1:
        :param nums2:
        :return:
        """
        nums = []
        length1 = len(nums1)
        length2 = len(nums2)
        length = length1 + length2
        index_nums1 = 0
        index_nums2 = 0
        if length1 == 0:
            nums = nums2
        elif length2 == 0:
            nums = nums1
        else:
            for index in range(length):
                if length2 <= index_nums2:
                    nums.append(nums1[index_nums1])
                    index_nums1 += 1
                elif length1 <= index_nums1:
                    nums.append(nums2[index_nums2])
                    index_nums2 += 1
                elif nums1[index_nums1] < nums2[index_nums2]:
                    nums.append(nums1[index_nums1])
                    index_nums1 += 1
                else:
                    nums.append(nums2[index_nums2])
                    index_nums2 += 1
        if length % 2:
            return nums[length // 2]
        return (nums[length // 2 - 1] + nums[length // 2]) / 2

    def answer_of_leetcode(self, A, B):
        m, n = len(A), len(B)
        if m > n:       # keep A as the longest
            A, B, m, n = B, A, n, m
        if n == 0:
            raise ValueError

        imin, imax, half_len = 0, m, (m + n + 1) / 2
        while imin <= imax:
            i = (imin + imax) // 2
            j = int(half_len - i)
            if i < m and B[j - 1] > A[i]:
                # i is too small, must increase it
                imin = i + 1
            elif i > 0 and A[i - 1] > B[j]:
                # i is too big, must decrease it
                imax = i - 1
            else:
                # i is perfect

                if i == 0:
                    max_of_left = B[j - 1]
                elif j == 0:
                    max_of_left = A[i - 1]
                else:
                    max_of_left = max(A[i - 1], B[j - 1])

                if (m + n) % 2 == 1:
                    return max_of_left

                if i == m:
                    min_of_right = B[j]
                elif j == n:
                    min_of_right = A[i]
                else:
                    min_of_right = min(A[i], B[j])

                return (max_of_left + min_of_right) / 2.0

    def faster(self, nums1, nums2):
        nums1.extend(nums2)
        if not len(nums1):
            return 0.0

        nums1.sort()
        length = len(nums1)

        if length % 2 == 0:
            return (nums1[length // 2 - 1] + nums1[length // 2]) / 2
        else:
            return nums1[length // 2]

    def fastest(self, nums1, nums2):
        nums = nums1 + nums2
        nums.sort()
        mid = (len(nums) - 1) / 2.0
        if mid == int(mid):
            return nums[int(mid)]
        else:
            return (nums[int(mid)] + nums[int(mid) + 1]) / 2.0


def create_sample():
    nums1 = [1, 3]
    nums2 = [2]
    samples = [[nums1, nums2]]
    nums1 = [1, 2]
    nums2 = [3, 4]
    samples.append([nums1, nums2])
    samples.append([[], [1]])
    samples.append([[], [2, 3]])
    samples.append([[], [1, 2, 3, 4]])
    samples.append([[], [1, 2, 3, 4, 5]])
    return samples


if __name__ == '__main__':
    samples = create_sample()
    solution = Solution()
    for elem in samples:
        print(solution.answer_of_leetcode(elem[0], elem[1]))


