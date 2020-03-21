# Leetcode264 丑数Ⅱ

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ugly-number-ii/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

编写一个程序，找出第 `n` 个丑数。

丑数就是只包含质因数 `2, 3, 5` 的**正整数**。



**示例 1:**

```
输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
```

**说明:**  

1. `1` 是丑数。
2. `n` **不超过**1690。



### 解题思路：





### 方法一：二分查找

##### 直观想法



#### C++

```c
class Solution {
public:
    using ll = long long;
    vector<ll> p2, p3, p5;
    Solution() {
        p2 = vector<ll>(31, 1);
        for (int i = 1; i < p2.size(); ++i) {
            p2[i] = 2 * p2[i - 1];
        }
        p3 = vector<ll>(20, 1);
        for (int i = 1; i < p3.size(); ++i) {
            p3[i] = 3 * p3[i - 1];
        }
        p5 = vector<ll>(14, 1);
        for (int i = 1; i < p5.size(); ++i) {
            p5[i] = 5 * p5[i - 1];
        }
    }
    int count(int n) {
        int res = 0;
        for (int i = 0; i < 31; ++i) {
            for (int j = 0; j < 20; ++j) {
                if (p2[i] * p3[j] > n) break;
                for (int k = 0; k < 14; ++k) {
                    if (p2[i] * p3[j] * p5[k] > n) break;
                    ++res;
                }
            }
        }
        return res;
    }
    int nthUglyNumber(int n) {
        ll l = 1;
        ll r = INT_MAX;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (count(m) < n) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return r;
    }
};
```



#### Java

```java
class Solution {
    public int nthUglyNumber(int n) {
        
    }
}
```



#### Python

```python
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        
```



### 方法二：动态规划

`dp[i]` 表示第i个丑数

那么`dp[i] = min(2 * dp[l_2], 3 * dp[l_3], 5 * dp[l_5])`

这里 `l_2`,`l_3`, `l_5`是表示，指到的位置。

时间复杂度：$O(n)$



#### C++

```c
#include <iostream>

using namespace std;

class Solution_LeetCode264 {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        int i_2 = 0;
        int i_3 = 0;
        int i_5 = 0;
        for (int i = 1; i < n; ++i) {
            dp[i] = min(min(2 * dp[i_2], 3 * dp[i_3]), 5 * dp[i_5]);
            if (dp[i] >= 2 * dp[i_2]) {
                i_2++;
            }
            if (dp[i] >= 3 * dp[i_3]) {
                i_3++;
            }
            if (dp[i] >= 5 * dp[i_5]) {
                i_5++;
            }
        }
        return dp[n - 1];
    }
};
```



#### Java

```java
class Solution {
    public int nthUglyNumber(int n) {
        
    }
}
```



#### Python

```python
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        
```

