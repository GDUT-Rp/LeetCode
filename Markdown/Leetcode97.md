# Leetcode97 交错字符串

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/interleaving-string/submissions/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

给定三个字符串 *s1*, *s2*, *s3*, 验证 *s3* 是否是由 *s1* 和 *s2* 交错组成的。

**示例 1:**

```
输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出: true
```



**示例 2:**

```
输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出: false
```



### 解题思路：

### 方法一：使用二维动态规划

##### 直观想法

上面提到的回溯方法包含每次从 $s1$ 或者 $s2$ 中选择一个字符并调用递归函数去检查 $s1$ 和 $s2$ 剩余部分能否形成 $s3$ 剩余部分的交错字符串。在现在这种方法中，我们用另一种思路来考虑同样的问题。这里我们考虑用 $s1$ 和 $s2$ 的某个前缀是否能形成 $s3$ 的一个前缀。

这个方法的前提建立于：判断一个 $s3$ 的前缀（用下标 $k$ 表示），能否用 $s1$ 和 $s2$ 的前缀（下标分别为 $i$ 和 $j$），仅仅依赖于 $s1$ 前 $i$ 个字符和 $s2$ 前 $j$ 个字符，而与后面的字符无关。

为了实现这个算法， 我们将使用一个 2D 的布尔数组 $dp$ 。$dp[i][j]$ 表示用 $s1$ 的前 $(i+1)$ 和 $s2$ 的前 $(j+1)$ 个字符，总共 $(i+j+2)$ 个字符，是否交错构成 $s3$ 的前缀。为了求出 $dp[i][j]$ ，我们需要考虑 $2$ 种情况：

$s1$ 的第 $i$ 个字符和 $s2$ 的第 $j$ 个字符都不能匹配 $s3$ 的第 $k$ 个字符，其中 $k=i+j+1$ 。这种情况下，$s1$ 和 $s2$ 的前缀无法交错形成 $s3$ 长度为 $k+1$ 的前缀。因此，我们让 $dp[i][j]$ 为 $False$。

$s1$ 的第 $i$ 个字符或者 $s2$ 的第 $j$ 个字符可以匹配 $s3$ 的第 $k$ 个字符，其中 $k=i+j+1$ 。假设匹配的字符是 $x$ 且与 $s1$ 的第 $i$ 个字符匹配，我们就需要把 $x$ 放在已经形成的交错字符串的最后一个位置。此时，为了我们必须确保 $s1$ 的前 $(i-1)$ 个字符和 $s2$ 的前 $j$ 个字符能形成 $s3$ 的一个前缀。类似的，如果我们将 $s2$ 的第 $j$ 个字符与 $s3$ 的第 $k$ 个字符匹配，我们需要确保 $s1$ 的前 $i$ 个字符和 $s2$ 的前 $(j-1)$ 个字符能形成 $s3$ 的一个前缀，我们就让 $dp[i][j]$为 $True$ 。

可以用下面的例子进行说明：



#### C++

```c
#include <iostream>
#include <vector>
#include <string>

class Solution_LeetCode97 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) {     //  长度不匹配
            return false;
        }
        bool dp[s1.length() + 1][s2.length() + 1];
        for (int i = 0; i <= s1.length(); ++i) {
            for (int j = 0; j <= s2.length(); ++j) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                } else if (i == 0) {
                    dp[i][j] = dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]);
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1]);
                } else {
                    dp[i][j] = (dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) ||
                               (dp[i][j - 1] && (s2[j - 1]) == s3[i + j - 1]);
                }
            }
        }
        return dp[s1.length()][s2.length()];
    }
};
```



#### Java

```java
public class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        if (s3.length() != s1.length() + s2.length()) {
            return false;
        }
        boolean dp[][] = new boolean[s1.length() + 1][s2.length() + 1];
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                } else if (i == 0) {
                    dp[i][j] = dp[i][j - 1] && s2.charAt(j - 1) == s3.charAt(i + j - 1);
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] && s1.charAt(i - 1) == s3.charAt(i + j - 1);
                } else {
                    dp[i][j] = (dp[i - 1][j] && s1.charAt(i - 1) == s3.charAt(i + j - 1)) || (dp[i][j - 1] && s2.charAt(j - 1) == s3.charAt(i + j - 1));
                }
            }
        }
        return dp[s1.length()][s2.length()];
    }
}
```



##### 复杂度分析

时间复杂度：$O(m \cdot n)$ 。计算 $dp$ 数组需要 $m*n$ 的时间。

空间复杂度：$O(m \cdot n)$。2 维的 $dp$ 数组需要 $(m+1)*(n+1)$ 的空间。 $m$ 和 $n$ 分别是 $s1$ 和 $s2$ 字符串的长度。



### 方法二：使用一维动态规划

##### 直观想法

这种方法与前一种方法基本一致，除了我们仅使用一维 $dp$ 数组去储存前缀结果。我们利用 $dp[i-1]$ 的结果和 $dp[i]$ 之前的结果来计算 $dp[i]$ ，即滚动数组。



#### C++

```c
bool isInterleave_one(string s1, string s2, string s3) {
    if (s3.length() != s1.length() + s2.length()) {     //  长度不匹配
        return false;
    }
    bool dp[s2.length() + 1];
    for (int i = 0; i <= s1.length(); ++i) {
        for (int j = 0; j <= s2.length(); ++j) {
            if (i == 0 and j == 0) {
                dp[j] = true;
            } else if (i == 0) {
                dp[j] = dp[j - 1] && (s2[j - 1] == s3[i + j - 1]);
            } else if (j == 0) {
                dp[j] = dp[j] && (s1[i - 1] == s3[i + j - 1]);
            } else {
                dp[j] = (dp[j] && (s1[i - 1] == s3[i + j - 1])) || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
    }
    return dp[s2.length()];
}
```



#### Java

```java
public class Solution {
   public boolean isInterleave(String s1, String s2, String s3) {
       if (s3.length() != s1.length() + s2.length()) {
           return false;
       }
       boolean dp[] = new boolean[s2.length() + 1];
       for (int i = 0; i <= s1.length(); i++) {
           for (int j = 0; j <= s2.length(); j++) {
               if (i == 0 && j == 0) {
                   dp[j] = true;
               } else if (i == 0) {
                   dp[j] = dp[j - 1] && s2.charAt(j - 1) == s3.charAt(i + j - 1);
               } else if (j == 0) {
                   dp[j] = dp[j] && s1.charAt(i - 1) == s3.charAt(i + j - 1);
               } else {
                   dp[j] = (dp[j] && s1.charAt(i - 1) == s3.charAt(i + j - 1)) || (dp[j - 1] && s2.charAt(j - 1) == s3.charAt(i + j - 1));
               }
           }
       }
       return dp[s2.length()];
   }
}
```



##### 复杂度分析

时间复杂度：$O(m \cdot n)$ 。计算 $dp$ 数组需要 $m*n$ 的时间。

空间复杂度：$O(n)$。*n* 是字符串 $s1$的长度

