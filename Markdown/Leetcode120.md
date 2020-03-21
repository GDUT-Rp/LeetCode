# Leetcode120 三角形最小路径和

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/triangle/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

例如，给定三角形：

```
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
```

自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

说明：

如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。



### 解题思路：

### 方法一：动态规划

##### 直观想法

`dp[i][j]` 代表 第 `i` 行 第 `j` 个当前的经过该点的最小路径和.

所以动态方程:

```c
dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
```



#### C++

```c
#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode120 {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), 0));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (j == 0) {   //  每行第一个
                    dp[i][j] = triangle[i][j] + dp[i - 1][j];
                } else if (j == triangle[i].size() - 1) {   //  每行最后一个
                    dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
                } else {    
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
                }
            }
        }
        int ans = INT_MAX;  //  最后一行的最小路径和
        ans = *min_element(dp[triangle.size() - 1].begin(), dp[triangle.size() - 1].end());
        return ans;
    }
};
```


