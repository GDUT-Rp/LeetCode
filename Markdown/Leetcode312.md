# Leetcode312 戳气球

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/burst-balloons/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

有 `n` 个气球，编号为 `0` 到 `n-1`，每个气球上都标有一个数字，这些数字存在数组 `nums` 中。

现在要求你戳破所有的气球。每当你戳破一个气球 `i` 时，你可以获得 `nums[left] * nums[i] * nums[right]` 个硬币。 这里的 `left` 和 `right` 代表和 i 相邻的两个气球的序号。注意当你戳破了气球 `i` 后，气球 `left` 和气球 `right` 就变成了相邻的气球。

求所能获得硬币的最大数量。

**说明**:

- 你可以假设 `nums[-1] = nums[n] = 1`，但注意它们不是真实存在的所以并不能被戳破。
- 0 ≤ `n` ≤ 500, 0 ≤ `nums[i]` ≤ 100

**示例 1:**

```
输入: [3,1,5,8]
输出: 167 
解释: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
     coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
```



### 解题思路：

### 方法一：动态规划

##### 直观想法

$dp[i][j]$ 表示戳破 $[i+1...j-1]$ 号气球的最大收益，$dp[i][j]=maxCoins(nums[i]\sim nums[j])$

假设 $k$ 号气球 $(i+1 <= k <= j-1)$ 是 $[i+1...j-1]$ 中最后一个被戳破的，则

$$dp[i][j] = max \{for\ k = range(i+1, j -1) nums[i] * nums[k] * nums[j] + dp[i][k] + dp[k][j]\}$$

![](https://img-blog.csdnimg.cn/20191102154338786.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

最后打破 $k$ 号气球，然后

#### C++

```c
class Solution {
public:
    int maxCoins(vector<int> &nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // dp[i][j] = maxCoins(nums[i:j+1])
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int len = 1; len <= n; ++len) {
            for (int i = 1; i <= n - len + 1; ++i) {
                int j = i + len - 1;
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = max(dp[i][j],
                                   dp[i][k - 1] + nums[i - 1] * nums[k] * nums[j + 1] + dp[k + 1][j]);
                }
            }
        }
        return dp[1][n];
    }
};
```



#### Java

```java
	/**
     * 解题思路：如何使最终结果最大化？动态规划保存结果
     * 1.将问题拆解成求i->j的最大值，最大的i=0,j=n
     * 2.从i->j中找一个k，拆分求解，i->k,k,k->j三个值之和的最大值
     * 3.i->k和k->j代表k的左边和右边全部戳破求解的最大值
     * 4.左右全部戳破后，k的值为num[i]*num[k]*num[j]
     * 5.动态转移方程：dp[i][j]=Math.max(dp[i][j],dp[i][k]+dp[k][j]+num[i]*num[k]*num[j]);
     *
     * @param nums
     * @return
     */
public int maxCoins(int[] nums) {
    //dp[i][j]代表i->j的最大值
    int[][] dp = new int[nums.length + 2][nums.length + 2];
    //左右+1方便操作。 nums[-1] = nums[n] = 1
    int[] newNums = new int[nums.length + 2];
    for (int i = 1; i < newNums.length - 1; i++) {
        newNums[i] = nums[i - 1];
    }
    newNums[0] = 1;
    newNums[newNums.length - 1] = 1;
    //从2开始，保证最少3个
    for (int j = 2; j < newNums.length; j++) {
        //遍历所有的可能性，0-2...0-n,1-3...1-n,...
        for (int i = 0; i < newNums.length - j; i++) {
            for (int k = i + 1; k < i + j; k++) {
                dp[i][i + j] = Math.max(dp[i][i + j], dp[i][k] + dp[k][i + j] + newNums[i] * newNums[k] * newNums[i + j]);
            }
        }
    }
    return dp[0][newNums.length - 1];
}
```



#### Python

```python
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
```



**复杂度分析**

时间复杂度：每次查询的时间 $O(n^3)$。
空间复杂度：$O(n^2)$。


