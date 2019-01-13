package com.leetcode.rp;

class SolutionOfLeetCode7 {
    public int reverse(int x) {
        int flag = 1;
        String string;
        if (x < 0) {
            flag = -1;
            string = x + "";
            string = string.substring(1, string.length());
        } else {
            string = x + "";
        }
        String newstring = new String();
        int length = string.length();
        for (int i = length - 1; i > -1; i--) {
            newstring += string.charAt(i);
        }
        try {
            x = Integer.parseInt(newstring);
        } catch (NumberFormatException e) {
            return 0;
        }
        return x * flag;
    }

    public int easy(int x) {
        int ans = 0;
        int yu = 0;
        while (x != 0) {
            yu = x % 10;
            x = x / 10;
            if (ans > Integer.MAX_VALUE / 10 || ans < Integer.MIN_VALUE / 10)
                return 0;
            ans = ans * 10 + yu;
        }
        return ans;
    }
}

public class LeetCode7 {
    public static void main(String[] args) {
        SolutionOfLeetCode7 solutionOfLeetCode7 = new SolutionOfLeetCode7();
        int[] x = {123, -123, 120, 21, 1534236469, -2147483648};
        for (int i : x) {
            int ans = solutionOfLeetCode7.reverse(i);
            System.out.println(ans);
            System.out.println(solutionOfLeetCode7.easy(i));
        }
    }
}
