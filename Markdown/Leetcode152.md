# Leetcode152 乘积最大子序列

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-subarray/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

给定一个整数数组 `nums` ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。



**示例 1:**

```
输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
```



**示例 2:**

```
输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
```



### 解题思路：

### 方法一：动态规划

##### 直观想法

遍历数组时计算当前最大值，不断更新
令imax为当前最大值，则当前最大值为 `imax = max(imax * nums[i], nums[i])`
由于存在负数，那么会导致最大的变最小的，最小的变最大的。因此还需要维护当前最小值imin，`imin = min(imin * nums[i], nums[i])`
当负数出现时则 `imax` 与 `imin` 进行交换再进行下一步计算
时间复杂度：$$O(n)$$

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
    public int maxProduct(int[] nums) {
        int max = Integer.MIN_VALUE, imax = 1, imin = 1;
        for(int i=0; i<nums.length; i++){
            if(nums[i] < 0){ 
              int tmp = imax;
              imax = imin;
              imin = tmp;
            }
            imax = Math.max(imax*nums[i], nums[i]);
            imin = Math.min(imin*nums[i], nums[i]);
            
            max = Math.max(max, imax);
        }
        return max;
    }
}
```



#### Python

```python
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        
```

