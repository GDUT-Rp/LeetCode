package com.leetcode.rp;

class SolutionOfLeetCode27 {
    public int removeElement(int[] nums, int val) {
        int i = 0;
        for (Integer elem:nums) {
            if (elem != val){
                nums[i] = elem;
                i++;
            }
        }
        return i;
    }

    public int removeElementBySwap(int[] nums, int val) {
        int i = 0;
        int n = nums.length;
        while(i < n){
            if (nums[i] == val){
                nums[i] = nums[n-1];
                n--;
            }else{
                i++;
            }
        }
        return i;
    }

}
public class LeetCode27 {
    public static void main(String[] args) {
        int[] nums1 = {1, 2, 2, 3, 5, 2, 7, 2};
        int[] nums2 = {1, 2, 2, 3, 5, 2, 7, 2};
        SolutionOfLeetCode27 solutionOfLeetCode27 = new SolutionOfLeetCode27();
        System.out.println(solutionOfLeetCode27.removeElement(nums1, 2));
        System.out.println(solutionOfLeetCode27.removeElementBySwap(nums2, 2));
    }
}
