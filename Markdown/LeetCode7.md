# LeetCode7

### 题目



### 思路



### Python

```python
# -*- coding: utf-8 -*-
# https://leetcode-cn.com/problems/reverse-integer/
import sys


def create_sample():
    return [123, -123, 120, 21, 1534236469, -2147483648]


class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        flag = 1
        if x < 0:
            flag = -1
            x = str(x)[1:]
        else:
            x = str(x)
        x = x[::-1]
        ans = int(x) * flag
        if ans > (2 << 30) - 1 or ans < (-2 << 30):
            return 0
        else:
            return ans


if __name__ == '__main__':
    solution = Solution()
    for elem in create_sample():
        print(solution.reverse(elem))
    print(sys.maxsize)
    print((-2 << 30))
    print(pow(-2, 31))
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



### C++

```c++

```

