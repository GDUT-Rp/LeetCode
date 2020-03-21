# Leetcode44 通配符匹配

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/wildcard-matching/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
两个字符串完全匹配才算匹配成功。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
示例 1:

```
输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
```

示例 2:

```
输入:
s = "aa"
p = ""
输出: true
解释: '' 可以匹配任意字符串。
```

示例 3:

```
输入:
s = "cb"
p = "?a"
输出: false
解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
```

示例 4:

```
输入:
s = "adceb"
p = "ab"
输出: true
解释: 第一个 '' 可以匹配空字符串, 第二个 '' 可以匹配字符串 "dce".
```

示例 5:

```
输入:
s = "acdcb"
p = "a*c?b"
输入: false
```



### 解题思路：

##### 思路一: 利用两个指针进行遍历。

在代码里解释.

时间复杂度为:$O(mn)$



##### 思路二: 动态规划

$dp[i][j]$表示`s`到`i`位置,`p`到`j`位置是否匹配!

**初始化:**

$dp[0][0]$:什么都没有,所以为`true`
第一行$dp[0][j]$,换句话说,`s`为空,与`p`匹配,所以只要`p`开始为`*`才为`true`
第一列$dp[i][0]$,当然全部为`False`
**动态方程:**

如果`(s[i] == p[j] || p[j] == "?") && dp[i-1][j-1] `,有`dp[i][j] = true`

如果`p[j] == "*" && (dp[i-1][j] = true || dp[i][j-1] = true)`有`dp[i][j] = true`

**note:**

	dp[i-1][j],表示*代表是空字符,例如ab,ab*
	dp[i][j-1],表示*代表非空任何字符,例如abcd,ab*





### 方法一：双指针

##### 直观想法



#### C++:

```c
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int j=0;
	for(int star=0,i=0, last=0;i<s.length();){
		if(j<p.size() && (s[i]==p[j] || p[j]=='?')){
			++i;
			++j;}
		else if(j<p.size() && p[j]=='*'){
			last=i;
			star=++j;}
		else if(star!=0){
			i=++last;
			j=star;}
		else return 0;
		}
		for(; j<p.size() && p[j]=='*'; ++j);
		return j==p.size();
  }
};
```



#### Java:

```java
class Solution {
    public boolean isMatch(String s, String p) {
        int sn = s.length();
        int pn = p.length();
        int i = 0;
        int j = 0;
        int start = -1;
        int match = 0;
        while (i < sn) {
            if (j < pn && (s.charAt(i) == p.charAt(j) || p.charAt(j) == '?')) {
                i++;
                j++;
            } else if (j < pn && p.charAt(j) == '*') {
                start = j;
                match = i;
                j++;
            } else if (start != -1) {
                j = start + 1;
                match++;
                i = match;
            } else {
                return false;
            }
        }
        while (j < pn) {
            if (p.charAt(j) != '*') return false;
            j++;
        }
        return true;
        
    }
}
```



#### Python:

```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        i = 0
        j = 0
        start = -1
        match = 0
        while i < len(s):
            # 一对一匹配,匹配成功一起移
            if j < len(p) and (s[i] == p[j] or p[j] == "?"):
                i += 1
                j += 1
            # 记录p的"*"的位置,还有s的位置
            elif j < len(p) and p[j] == "*":
                start = j
                match = i
                j += 1
            # j 回到 记录的下一个位置
            # match 更新下一个位置
            # 这不代表用*匹配一个字符
            elif start != -1:
                j = start + 1
                match += 1
                i = match
            else:
                return False
         # 将多余的 * 直接匹配空串
        return all(x == "*" for x in p[j:])
```





### 方法二：动态规划





#### C++

```c
bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') {
                dp[0][i] = dp[0][i - 1];
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
```



#### Java

```java
class Solution {
    public boolean isMatch(String s, String p) {
        boolean[][] dp = new boolean[s.length() + 1][p.length() + 1];
        dp[0][0] = true;
        for (int j = 1; j < p.length() + 1; j++) {
            if (p.charAt(j - 1) == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }
        for (int i = 1; i < s.length() + 1; i++) {
            for (int j = 1; j < p.length() + 1; j++) {
                if (s.charAt(i - 1) == p.charAt(j - 1) || p.charAt(j - 1) == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p.charAt(j - 1) == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }
        return dp[s.length()][p.length()];
        
    }
}
```



#### Python

```python
class Solution:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        sn = len(s)
        pn = len(p)
        dp = [[False] * (pn + 1) for _ in range(sn + 1)]
        dp[0][0] = True
        for j in range(1, pn + 1):
            if p[j - 1] == "*":
                dp[0][j] = dp[0][j - 1]

        for i in range(1, sn + 1):
            for j in range(1, pn + 1):
                if (s[i - 1] == p[j - 1] or p[j - 1] == "?"):
                    dp[i][j] = dp[i - 1][j - 1]
                elif p[j - 1] == "*":
                    dp[i][j] = dp[i - 1][j] or dp[i][j - 1]
        return dp[-1][-1]
```

