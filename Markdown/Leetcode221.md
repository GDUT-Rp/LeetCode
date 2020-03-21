# Leetcode221 最大正方形

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximal-square/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。



**示例 1:**

```
输入: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

输出: 4
```



### 解题思路：

在给定 $m \times n$ 的矩阵中，我们需要找到在矩阵中由 1 组成的最大正方形。
换句话说，我们需要在矩阵中找到由 1 组成最大连通的正方形，并返回其面积。



### 方法一：暴力法

##### 直观想法

最简单的方法是找出矩阵中所有可以形成的 1 正方形。现在的问题是如何做到这一点？

1. 我们用一个变量去来记录迄今为止发现的最大正方形的边长，以及用一个变量记录当前正方形的大小，两个变量都初始化为 0；
2. 从矩阵的左上角开始搜索 1，找到 0 不需要做任何操作，只要找到 1 我们就试图找到由 1 组成的最大正方形；
3. 为此我们向右和向下移动，临时增加列索引和行索引，然后用标志标记该行列是否全都为 1；
4. 如果全都为 1，则继续检索行列，如果找到 0，便停止移动，更新最大正方形的边长。然后从最初发现 1 的元素旁边遍历矩阵，直到矩阵的所有元素都被遍历。



#### C++

```c
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
    }
};
```



#### Java

```java
public class Solution {
    public int maximalSquare(char[][] matrix) {
        int rows = matrix.length, cols = rows > 0 ? matrix[0].length : 0;
        int maxsqlen = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    int sqlen = 1;
                    boolean flag = true;
                    while (sqlen + i < rows && sqlen + j < cols && flag) {
                        for (int k = j; k <= sqlen + j; k++) {
                            if (matrix[i + sqlen][k] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        for (int k = i; k <= sqlen + i; k++) {
                            if (matrix[k][j + sqlen] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        if (flag)
                            sqlen++;
                    }
                    if (maxsqlen < sqlen) {
                        maxsqlen = sqlen;
                    }
                }
            }
        }
        return maxsqlen * maxsqlen;
    }
}
```



#### Python

```python
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        
```



### 方法二：动态规划

##### 直观想法

我们用一个例子来解释这个方法：

```
0 1 1 1 0
1 1 1 1 1
0 1 1 1 1
0 1 1 1 1
0 0 1 1 1
```

1. 我们用 0 初始化另一个矩阵 `dp`，维数和原始矩阵维数相同；

2. `dp(i,j)` 表示的是由 1 组成的最大正方形的边长；

3. 从 (0,0) 开始，对原始矩阵中的每一个 1，我们将当前元素的值更新为
   $$
   \text{dp}(i,\ j) = \min \big( \text{dp}(i-1,\ j),\ \text{dp}(i-1,\ j-1),\ \
   
   \text{dp}(i,\ j-1) \big) + 1
   $$

4. 我们还用一个变量记录当前出现的最大边长，这样遍历一次，找到最大的正方形边长 $maxsqlen$，那么结果就是 $maxsqlen^2$。



可以通过下面的图来理解该工作原理：

![](https://pic.leetcode-cn.com/28657155fcebc3f210982e889ceef89f6295fb48999222bfe0e52514158c446e-image.png)



#### C++

```c
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int rows = matrix.size();
        if (!rows){
            return 0;
        }
        int cols = rows > 0 ? matrix[0].size() : 0;
        int dp[rows + 1][cols + 1];
        memset(dp, 0, sizeof(dp));
        dp[1][1] = matrix[0][0];
        int max_sqlen = 0;
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                    max_sqlen = max(max_sqlen, dp[i][j]);
                }
            }
        }
        return max_sqlen * max_sqlen;
    }
};
```



#### Java

```java
public class Solution {
    public int maximalSquare(char[][] matrix) {
        int rows = matrix.length, cols = rows > 0 ? matrix[0].length : 0;
        int[][] dp = new int[rows + 1][cols + 1];
        int maxsqlen = 0;
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if (matrix[i-1][j-1] == '1'){
                    dp[i][j] = Math.min(Math.min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                    maxsqlen = Math.max(maxsqlen, dp[i][j]);
                }
            }
        }
        return maxsqlen * maxsqlen;
    }
}
```



#### Python

```python
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        
```



**复杂度分析**

- 时间复杂度：$O(mn)$。
- 空间复杂度：$O(mn)$，用了一个大小相同的矩阵 dp。



### 方法三：动态规划优化

##### 直观想法

在前面的动态规划解法中，计算 $i^{th}$行（row）的 dp 方法中，我们只使用了上一个元素和第 $(i-1)^{th}$行，因此我们不需要二维 dp 矩阵，因为一维 dp 足以满足此要求。

我们扫描一行原始矩阵元素时，我们根据公式：$dp[j]=min(dp[j-1],dp[j],prev)$ 更新数组 dp，其中 prev 指的是 $dp[j-1]$，对于每一行，我们重复相同过程并在 dp 矩阵中更新元素。



#### C++

```c
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (!rows) {
            return 0;
        }
        int cols = rows > 0 ? matrix[0].size() : 0;
        int dp[cols + 1];
        memset(dp, 0, sizeof(dp));
        int max_sqlen = 0, prev = 0;
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                int temp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = min(min(dp[j - 1], prev), dp[j]) + 1;
                    max_sqlen = max(max_sqlen, dp[j]);
                }else{
                    dp[j] = 0;
                }
                prev = temp;
            }
        }
        return max_sqlen * max_sqlen;
    }
};
```



#### Java

```java
public class Solution {
    public int maximalSquare(char[][] matrix) {
        int rows = matrix.length, cols = rows > 0 ? matrix[0].length : 0;
        int[] dp = new int[cols + 1];
        int maxsqlen = 0, prev = 0;
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                int temp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = Math.min(Math.min(dp[j - 1], prev), dp[j]) + 1;
                    maxsqlen = Math.max(maxsqlen, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev = temp;
            }
        }
        return maxsqlen * maxsqlen;
    }
}

```

**复杂度分析**

- 时间复杂度：$O(mn)$。
- 空间复杂度：$O(n)$，用了一个大小相同的矩阵 dp。