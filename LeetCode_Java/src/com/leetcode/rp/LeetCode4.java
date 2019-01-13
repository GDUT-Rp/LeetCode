package com.leetcode.rp;

import java.util.ArrayList;
import java.util.Collections;

class SolutionLeetCode4 {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        ArrayList<Integer> arrayList = new ArrayList<>();
        Integer length1 = nums1.length;
        Integer length2 = nums2.length;
        for (Integer elem : nums1) {
            arrayList.add(elem);
        }
        for (Integer elem : nums2) {
            arrayList.add(elem);
        }
        Collections.sort(arrayList);
        Integer length = length1 + length2;
        if (length % 2 == 1) {
            return arrayList.get(length / 2);
        } else {
            double ans = arrayList.get(length / 2 - 1) + arrayList.get(length / 2);
            return ans / 2;
        }
    }

    public double AnswerOfLeetCode(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        if (m > n) { // to ensure m<=n
            int[] temp = nums1;
            nums1 = nums2;
            nums2 = temp;
            int tmp = m;
            m = n;
            n = tmp;
        }
        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
        while (iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if (i < iMax && nums2[j - 1] > nums1[i]) {
                iMin = i + 1; // i is too small
            } else if (i > iMin && nums1[i - 1] > nums2[j]) {
                iMax = i - 1; // i is too big
            } else { // i is perfect
                int maxLeft = 0;
                if (i == 0) {
                    maxLeft = nums2[j - 1];
                } else if (j == 0) {
                    maxLeft = nums1[i - 1];
                } else {
                    maxLeft = Math.max(nums1[i - 1], nums2[j - 1]);
                }
                if ((m + n) % 2 == 1) {
                    return maxLeft;
                }

                int minRight = 0;
                if (i == m) {
                    minRight = nums2[j];
                } else if (j == n) {
                    minRight = nums1[i];
                } else {
                    minRight = Math.min(nums2[j], nums1[i]);
                }

                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
}

public class LeetCode4 {

    public static void main(String[] args) {
        int[] nums1 = {1, 2};
        int[] nums2 = {3, 4};
        SolutionLeetCode4 solutionLeetCode4 = new SolutionLeetCode4();
        System.out.println(solutionLeetCode4.findMedianSortedArrays(nums1, nums2));
    }
}
