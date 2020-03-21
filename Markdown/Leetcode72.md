# Leetcode72 编辑距离

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/edit-distance/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符



示例 1：

```
输入: word1 = "horse", word2 = "ros"
输出: 3
解释: 
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
```


示例 2：

```
输入: word1 = "intention", word2 = "execution"
输出: 5
解释: 
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
```



### 解题思路：

- 编辑距离算法被数据科学家广泛应用，是用作机器翻译和语音识别评价标准的基本算法。

  最简单的方法是检查所有可能的编辑序列，从中找出最短的一条。但这个序列总数可能达到指数级，但完全不需要这么多，因为我们只要找到距离最短的那条而不是所有可能的序列。

  

### 方法一：动态规划

我们的目的是让问题简单化，比如说两个单词 `horse` 和 `ros` 计算他们之间的编辑距离 `D`，容易发现，如果把单词变短会让这个问题变得简单，很自然的想到用 `D[n][m]` 表示输入单词长度为 `n` 和 `m` 的编辑距离。

具体来说，`D[i][j]` 表示 `word1` 的前 `i` 个字母和 `word2` 的前 `j` 个字母之间的编辑距离。

![](https://pic.leetcode-cn.com/b6ee3ba6350ac2d789e633dada130d64687530cf4cc2f2c2c6dbb1bed6c09056-72-1.png)

当我们获得 `D[i-1][j]`，`D[i][j-1]` 和 `D[i-1][j-1]` 的值之后就可以计算出 `D[i][j]`。

每次只可以往单个或者两个字符串中插入一个字符



`dp[i][j]` 代表 `word1` 到 `i` 位置转换成 `word2` 到 `j` 位置需要最少步数

所以，

当 word1[i] == word2[j]，`dp[i][j] = dp[i-1][j-1]`；

当 word1[i] != word2[j]，`dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1`

其中，`dp[i-1][j-1]` 表示替换操作，`dp[i-1][j]` 表示删除操作，`dp[i][j-1]` 表示插入操作。



那么递推公式很显然了

如果两个子串的最后一个字母相同，word1[i] = word2[i] 的情况下：

$$
D[i][j] = 1 + \min(D[i - 1][j], D[i][j - 1], D[i - 1][j - 1] - 1)
$$
否则，`word1[i] != word2[i]` 我们将考虑替换最后一个字符使得他们相同：

$$
D[i][j]=1+min(D[i−1][j],D[i][j−1],D[i−1][j−1])
$$
所以每一步结果都将基于上一步的计算结果，示意如下：

![](https://pic.leetcode-cn.com/5ddb125b8055b95c3698af33d1cbe6ef480d4675204f71194b386fffecaca365-72-2.png)



同时，对于边界情况，一个空串和一个非空串的编辑距离为 `D[i][0] = i` 和 `D[0][j] = j`。

综上我们得到了算法的全部流程。

![](https://pic.leetcode-cn.com/49396b8cfa17a025d2bc02f0c74c9858f974d038dfd9f9f1e09a45dc14aa68dc-image.png)

![](https://pic.leetcode-cn.com/acd1a6e5b745890c29702b94b2f4c17b23902f28b64ba6c1a9cb337b36290b59-image.png)

![](https://pic.leetcode-cn.com/70b6ced37824dce2db3033376e9bbe2eda9d2b2b95a33cfe30e148f58ec25009-image.png)

![](https://pic.leetcode-cn.com/422391e2a47057f9ee8edc483038be5358055ad4f456541e020a30fd69fa9649-image.png)

![](https://pic.leetcode-cn.com/2d82d9b03d494c16e8559174a25bc56b098d7b3d54a2c8c3accdda1027aef2ab-image.png)

![](https://pic.leetcode-cn.com/a8f28988330d08527b56ef6834577ef661560eebb26755a0dd0b316642776b72-image.png)







#### C++:

```c
#include <iostream>

using namespace std;

class Solution_LeetCode72 {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        if (n * m == 0) {
            return n + m;
        }

        int d[n + 1][m + 1];
        for (int i = 0; i < n + 1; ++i) {
            d[i][0] = i;
        }
        for (int i = 0; i < m + 1; ++i) {
            d[0][i] = i;
        }

        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < m + 1; ++j) {
                int left = d[i - 1][j] + 1;
                int down = d[i][j - 1] + 1;
                int left_down = d[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1]) {
                    left_down += 1;
                }
                d[i][j] = min(left, min(down, left_down));
            }
        }
        return d[n][m];
    }
};
```



#### Java:

```java
class Solution {
  public int minDistance(String word1, String word2) {
    int n = word1.length();
    int m = word2.length();

    // if one of the strings is empty
    if (n * m == 0)
      return n + m;

    // array to store the convertion history
    int [][] d = new int[n + 1][m + 1];

    // init boundaries
    for (int i = 0; i < n + 1; i++) {
      d[i][0] = i;
    }
    for (int j = 0; j < m + 1; j++) {
      d[0][j] = j;
    }

    // DP compute 
    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j < m + 1; j++) {
        int left = d[i - 1][j] + 1;
        int down = d[i][j - 1] + 1;
        int left_down = d[i - 1][j - 1];
        if (word1.charAt(i - 1) != word2.charAt(j - 1))
          left_down += 1;
        d[i][j] = Math.min(left, Math.min(down, left_down));

      }
    }
    return d[n][m];
  }
}
```



#### Python:

```python
class Solution:
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        n = len(word1)
        m = len(word2)
        
        # if one of the strings is empty
        if n * m == 0:
            return n + m
        
        # array to store the convertion history
        d = [ [0] * (m + 1) for _ in range(n + 1)]
        
        # init boundaries
        for i in range(n + 1):
            d[i][0] = i
        for j in range(m + 1):
            d[0][j] = j
        
        # DP compute 
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                left = d[i - 1][j] + 1
                down = d[i][j - 1] + 1
                left_down = d[i - 1][j - 1] 
                if word1[i - 1] != word2[j - 1]:
                    left_down += 1
                d[i][j] = min(left, down, left_down)
        
        return d[n][m]
```

**复杂度分析**

- 时间复杂度 ：$O(mn)$，两层循环显而易见。
- 空间复杂度 ：$O(mn)$，循环的每一步都要记录结果。



