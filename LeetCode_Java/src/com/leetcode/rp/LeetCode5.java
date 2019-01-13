package com.leetcode.rp;

class SolutionOfLeetCode5 {
    String longestPalindrome(String s) {
        if (s == null || s.length() < 1) return "";
        else if (s.length() < 2) return s;
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len3 = Math.max(len1, len2);
            if (len3 > end - start) {
                start = i - (len3 - 1) / 2;
                end = i + len3 / 2;
            }
        }
        return s.substring(start, end + 1);
    }

    int expandAroundCenter(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        return right - left - 1;
    }
}

public class LeetCode5 {
    public static void main(String[] args) {
        String string = "babad";
        SolutionOfLeetCode5 solutionOfLeetCode5 = new SolutionOfLeetCode5();
        string = solutionOfLeetCode5.longestPalindrome(string);
        System.out.println(string);
    }
}
