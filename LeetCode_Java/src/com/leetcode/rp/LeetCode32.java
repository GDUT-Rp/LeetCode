package com.leetcode.rp;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

class SolutionOfLeetCode32 {
    public int longestValidParentheses(String s) {
        if (s == null || s.length() == 0)
            return 0;
        int start = 0;
        int maxValue = 0;
        LinkedList<Integer> linkedList = new LinkedList<Integer>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                linkedList.push(i);
            } else {
                if (linkedList.isEmpty()) {
                    start = i + 1;
                } else {
                    linkedList.pop();
                    maxValue = linkedList.isEmpty() ? Math.max(maxValue, i - start + 1) : Math.max(maxValue, i - linkedList.peek());
                }
            }
        }
        return maxValue;
    }
}

public class LeetCode32 {
    public static void main(String[] args) {
        List<String> stringList = new ArrayList<>();
        stringList.add("(()");
        SolutionOfLeetCode32 solutionOfLeetCode32 = new SolutionOfLeetCode32();
        System.out.println(solutionOfLeetCode32.longestValidParentheses(stringList.get(0)));
    }
}
