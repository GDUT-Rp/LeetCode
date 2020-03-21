# Leetcode115 不同的子序列

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distinct-subsequences/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

给定一个字符串 $\mathbf{S}$ 和一个字符串 $\mathbf{T}$，计算在 $\mathbf{S}$ 的子序列中 $\mathbf{T}$ 出现的个数。

一个字符串的一个子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）



**示例 1:**

```
输入: S = "rabbbit", T = "rabbit"
输出: 3
解释:

如下图所示, 有 3 种可以从 S 中得到 "rabbit" 的方案。
(上箭头符号 ^ 表示选取的字母)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
```



**示例 2:**

```
输入: S = "babgbag", T = "bag"
输出: 5
解释:

如下图所示, 有 5 种可以从 S 中得到 "bag" 的方案。 
(上箭头符号 ^ 表示选取的字母)

babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^
```



### 解题思路：

### 方法一：动态规划

##### 直观想法

`dp[i][j]` 代表 `T` 前 `i` 字符串可以由 `S` `j` 字符串组成最多个数.

所以动态方程:

当 `S[j] == T[i]` , `dp[i][j]` = `dp[i-1][j-1]` + `dp[i][j-1]`;

当 `S[j] != T[i]` , `dp[i][j]` = `dp[i][j-1]`

举个例子,如示例的

![](https://pic.leetcode-cn.com/a3a1d30700be05cad2e60666f20ab261e7a04b85ed88b854dd1d8cb484909983-1561970400084.png)

对于第一行, `T` 为空,因为空集是所有字符串子集, 所以我们第一行都是 `1`

对于第一列, `S` 为空,这样组成 `T` 个数当然为 `0` 了

至于下面如何进行,大家可以通过动态方程,自行模拟一下!



#### C++

```c
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<long long>> dp(t.length() + 1, vector<long long>(s.length() + 1, 0));
        fill(begin(dp[0]), end(dp[0]), 1);                          //  Init
        for (int i = 1; i <= t.length(); ++i) {
            for (int j = 1; j <= s.length(); ++j) {
                if (t[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];     //  dp[i - 1][j - 1]  match s[j],t[i]
                } else {                                            //  dp[i][j - 1] skip s[j]
                    dp[i][j] = dp[i][j - 1];                        //  skip s[j]
                }
            }
        }
        return int(dp[t.length()][s.length()]);
    }
};
```



#### Java

```java
class Solution {
    public int numDistinct(String s, String t) {
        int[][] dp = new int[t.length() + 1][s.length() + 1];
        for (int j = 0; j < s.length() + 1; j++) dp[0][j] = 1;
        for (int i = 1; i < t.length() + 1; i++) {
            for (int j = 1; j < s.length() + 1; j++) {
                if (t.charAt(i - 1) == s.charAt(j - 1)) dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                else dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[t.length()][s.length()];
    }
}
```



#### Python

```python
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        n1 = len(s)
        n2 = len(t)
        dp = [[0] * (n1 + 1) for _ in range(n2 + 1)]
        for j in range(n1 + 1):
            dp[0][j] = 1
        for i in range(1, n2 + 1):
            for j in range(1, n1 + 1):
                if t[i - 1] == s[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]  + dp[i][j - 1]
                else:
                    dp[i][j] = dp[i][j - 1]
        #print(dp)
        return dp[-1][-1]
```

