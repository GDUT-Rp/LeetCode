# Leetcode300 最长上升子序列

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

给定一个无序的整数数组，找到其中最长上升子序列的长度。c



**示例 1:**

```
输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
```

**说明:**

- 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
- 你算法的时间复杂度应该为 O($n^2$) 。



### 解题思路：





### 方法一：带记忆的递归

##### 直观想法

在前面的方法中，许多递归调用必须使用相同的参数进行一次又一次的调用。通过将为特定调用获得的结果存储在二维记忆数组 memo 中，可以消除这种冗余。$memo[i][j]$ 表示使用 $nums[i]$ 作为上一个被认为包含/不包含在 `lis` 中的元素的 `lis` 可能的长度，其中 $nums[j]$ 作为当前被认为包含/不包含在 `lis` 中的元素。这里，$nums$ 表示给定的数组。



#### C++

```c
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int len = nums.size();
        
    }
};
```



#### Java

```java
public class Solution {
    public int lengthOfLIS(int[] nums) {
        int memo[][] = new int[nums.length + 1][nums.length];
        for (int[] l : memo) {
            Arrays.fill(l, -1);
        }
        return lengthofLIS(nums, -1, 0, memo);
    }
    public int lengthofLIS(int[] nums, int previndex, int curpos, int[][] memo) {
        if (curpos == nums.length) {
            return 0;
        }
        if (memo[previndex + 1][curpos] >= 0) {
            return memo[previndex + 1][curpos];
        }
        int taken = 0;
        if (previndex < 0 || nums[curpos] > nums[previndex]) {
            taken = 1 + lengthofLIS(nums, curpos, curpos + 1, memo);
        }

        int nottaken = lengthofLIS(nums, previndex, curpos + 1, memo);
        memo[previndex + 1][curpos] = Math.max(taken, nottaken);
        return memo[previndex + 1][curpos];
    }
}
```



#### Python

```python
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        
```



**复杂度分析**

时间复杂度：$O(n^2)$。递归树的大小可以达到 $n^2$。
空间复杂度：$O(n^2)$，使用 $n*n$ 的 $memo$ 数组。



### 方法二：动态规划

他的方法依赖于这样一个事实，在给定数组中最长上升子序列可能达到 $i^{th}$
  独立于后面在数组中出现的元素。因此，如果我们知道 `lis` 的长度不超过 $i^{th}$，我们可以根据索引为 $j$ 的元素包括 $(i+1)^{th}$ 元素来计算 `lis` 的长度，其中 $0\leq j\leq (i + 1)$。

我们使用 $dp$ 数组来存储所需的数据。 $dp[i]$ 表示考虑到数组元素一直到 $i^{th}$ 的情况下可能的最长上升子序列的长度，必须包括 $i^{th}$ 元素。为了找出 $dp[i]$，我们需要尝试在每个可能的最长上升子序列中附加当前元素$(nums[i])$到 $(i-1)^{th}$（包括 $(i-1)^{th}$），这样通过添加当前元素形成的新序列也是一个上升子序列。因此，我们可以很容易地确定 $dp[i]$ 使用：
$$
dp[i] = \text{max}(dp[j]) + 1, \forall 0\leq j < i
$$
最后，确定最终结果的所有 $dp[i]$ 中的最大值。

$$
LIS_{length}= \text{max}(dp[i]), \forall 0\leq i < n
$$

![](https://pic.leetcode-cn.com/Figures/300_LISSlide7.PNG)

#### C++

```c
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int len = nums.size();
        if (len == 0) return 0;
        vector<int> dp(len, 1);
        dp[0] = 1;
        int maxans = 1;
        for (int i = 1; i < len; ++i) {
            int maxval = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    maxval = max(maxval, dp[j]);
                }
            }
            dp[i] = maxval + 1;
            maxans = max(maxans, dp[i]);
        }
        return maxans;
    }
};
```



#### Java

```java
public class Solution {
    public int lengthOfLIS(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        int[] dp = new int[nums.length];
        dp[0] = 1;
        int maxans = 1;
        for (int i = 1; i < dp.length; i++) {
            int maxval = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    maxval = Math.max(maxval, dp[j]);
                }
            }
            dp[i] = maxval + 1;
            maxans = Math.max(maxans, dp[i]);
        }
        return maxans;
    }
}
```



#### Python

```python
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        
```



**复杂度分析**

- 时间复杂度：$O(n^2)$。有两个 $n$的循环。
- 空间复杂度：$O(n)$，用了大小为 $n$ 的矩阵 $dp$。