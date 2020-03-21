# LeetCode5

https://leetcode-cn.com/problems/longest-palindromic-substring/

## 最长回文子串

给定一个字符串 `s`，找到 `s` 中最长的回文子串。你可以假设 `s` 的最大长度为 1000。

**示例 1：**

```
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
```

**示例 2：**

```
输入: "cbbd"
输出: "bb"
```



### 思路

#### 中心扩展算法

对字符串的每一个字符进行中心展开，找到最长的回文子串

**复杂度分析**

- 时间复杂度：O(n^2)， 由于围绕中心来扩展回文会耗去 O(n)的时间，所以总的复杂度为 O(n^2)
- 空间复杂度：O(1)。 

#### Manacher算法

**Manacher 算法的时间复杂度为 O(n)**

https://subetter.com/articles/manacher-algorithm.html



### Python

```python
# -*- coding: utf-8 -*-

# https://leetcode-cn.com/problems/longest-palindromic-substring/


def create_sample():
    return "babad"


class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        length = len(s)
        if length < 1:
            return ""
        start, end = 0, 0
        for i in range(length):
            len1 = self.expandAroundCenter(s, i, i)
            len2 = self.expandAroundCenter(s, i, i + 1)
            len3 = max(len1, len2)
            if len3 > end - start:
                start = i - (len3 - 1) // 2
                end = i + len3 // 2
        return s[start: end + 1]

    def expandAroundCenter(self, s, left, right):
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return right - left - 1

    def manacher(self, s):
        """
        Manacher算法，时间复杂度O(n)
        :param s:
        :return:
        """
        t = '%#' + '#'.join(list(s)) + '#$'
        length, sup, res = len(t), 0, 0
        li = [1] * length
        reach = pos = 0
        t += '%'
        for i in range(2, length - 1):
            if reach > i:
                if li[2 * pos - i] < reach - i:
                    li[i] = li[2 * pos - i]
                else:
                    li[i] = reach - i + 1
            while t[i + li[i]] == t[i - li[i]]:
                li[i] += 1
            if i + li[i] - 1 > reach:
                reach = i + li[i] - 1
                pos = i
            if li[i] > sup:
                sup = li[i]
                res = i
        return t[res - sup + 2: res + sup:2]

    def fastest(self, s):
        length = len(s)
        if length < 2 or s == s[::-1]:  # 长度为1或者翻转也全等
            return s
        max_len, begin = 1, 0
        for i in range(1, length):
            odd = s[i - max_len - 1:i + 1]
            even = s[i - max_len:i + 1]
            if i - max_len >= 1 and odd == odd[::-1]:
                begin = i - max_len - 1
                max_len += 2
                continue
            if i - max_len >= 0 and even == even[::-1]:
                begin = i - max_len
                max_len += 1
        return s[begin:begin + max_len]


if __name__ == '__main__':
    solution = Solution()
    ans = solution.manacher(create_sample())
    print(ans)
```



### Java

```java
package com.leetcode.rp;

class SolutionOfLeetCode7 {
    public int reverse(int x) {
        int flag = 1;
        String string;
        if (x < 0){
            flag = -1;
            string = x + "";
            string = string.substring(1, string.length());
        }
        else{
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
    public int easy(int x){
        int ans = 0;
        int yu = 0;
        while (x != 0){
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
        for (int i:x) {
            int ans = solutionOfLeetCode7.reverse(i);
            System.out.println(ans);
            System.out.println(solutionOfLeetCode7.easy(i));
        }
    }
}

```

