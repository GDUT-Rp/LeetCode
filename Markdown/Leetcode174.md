# Leetcode174 地下城游戏

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/dungeon-game/submissions/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

一些恶魔抓住了公主（**P**）并将她关在了地下城的右下角。地下城是由 M x N 个房间组成的二维网格。我们英勇的骑士（**K**）最初被安置在左上角的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主。

骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。

有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，则表示骑士将损失健康点数）；其他房间要么是空的（房间里的值为 0），要么包含增加骑士健康点数的魔法球（若房间里的值为正整数，则表示骑士将增加健康点数）。

为了尽快到达公主，骑士决定每次只向右或向下移动一步。

 

**编写一个函数来计算确保骑士能够拯救到公主所需的最低初始健康点数。**

例如，考虑到如下布局的地下城，如果骑士遵循最佳路径 `右 -> 右 -> 下 -> 下`，则骑士的初始健康点数至少为 **7**。

| -2 (K) | -3   | 3      |
| ------ | ---- | ------ |
| -5     | -10  | 1      |
| 10     | 30   | -5 (P) |

 


说明:

骑士的健康点数没有上限。

任何房间都可能对骑士的健康点数造成威胁，也可能增加骑士的健康点数，包括骑士进入的左上角房间以及公主被监禁的右下角房间。



### 解题思路：

### 方法一：动态规划

##### 直观想法

题目大意：一个骑士从左上角出发，要到达右下角拯救公主，每个格子中有正数表示可以增加的生命值，负数表示减少的生命。如果生命值为0，那么骑士就死翘翘了。你的任务是帮骑士计算到达右下角的最小生命值。

思路：DP，设`dp[i][j]`为到达(i,j)需要的最少生命值。则有：

- `dp[i][j]= max ( 1, min(dp[i+1][j],dp[i][j+1]) - dungeon[i][j])`

即，从右下角到左上角进行计算。对于dungeon为正数，那么减去，说明生命值可以少一些到达这个格子（但是不能小于等于0），对于负数，减去一个负数意味着加上这个数的绝对值，即需要的生命数增加。

为什么是右下角到左上角而不是左上到右下呢？

如果途中遇到一个很大的正数，它就会覆盖掉你之前走过的所有信息。（变为0），这样的结果是错误的。

#### C++

```c
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty()){
            return 0;
        }
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, INT_MAX));
        dp[m - 1][n] = dp[m][n - 1] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                if (dp[i][j] <= 0){
                    dp[i][j] = 1;
                }
            }
        }
        return dp[0][0];
    }
};
```



#### Java

```java
class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        
    }
}
```



#### Python

```python
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty()){
            return 0;
        }
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, INT_MAX));
        dp[m - 1][n] = dp[m][n - 1] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                if (dp[i][j] <= 0){
                    dp[i][j] = 1;
                }
            }
        }
        return dp[0][0];
    }
};
```

