package com.leetcode.rp;

import java.util.ArrayList;
import java.util.HashMap;

class Solution {
    public int romanToInt(String s) {
        int ans = 0;
        HashMap<Character, Integer> hashMap = new HashMap<>();
        hashMap.put('I', 1);
        hashMap.put('V', 5);
        hashMap.put('X', 10);
        hashMap.put('L', 50);
        hashMap.put('C', 100);
        hashMap.put('D', 500);
        hashMap.put('M', 1000);
        for (int i = 0; i < s.length() - 1; i++) {
            if (hashMap.get(s.charAt(i)) < hashMap.get(s.charAt(i + 1)))
                ans -= hashMap.get(s.charAt(i));
            else
                ans += hashMap.get(s.charAt(i));
        }
        return ans + hashMap.get(s.charAt(s.length() - 1));
    }
}

public class LeetCode13 {
    public static void main(String[] args) {
        Solution solution = new Solution();
        ArrayList List = new ArrayList();
        List.add("III");
        List.add("IV");
        List.add("IX");
        List.add("LVIII");
        List.add("MCMXCIV");
        for (Object elem : List) {
            System.out.println(elem.toString());
            System.out.println(solution.romanToInt(elem.toString()));
        }
    }
}
