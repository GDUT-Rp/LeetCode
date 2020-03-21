# Leetcode123 买卖股票的最佳时机Ⅲ

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。



示例 1:

```
输入: [3,3,5,0,0,3,1,4]
输出: 6
解释: 在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
```



示例 2:

```
输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。   
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
```



示例 3:

```
输入: [7,6,4,3,1] 
输出: 0 
解释: 在这个情况下, 没有交易完成, 所以最大利润为 0。
```



### 解题思路：

### 方法一：线性扫描

##### 直观想法

先从前往后扫描，并计算出只买卖一次且第 ii 天卖出的最大收益，最大收益等于第 ii 天股票的价格减去前 i−1 天股票价格的最小值。
扫描过程中用 f[i] 记录前 i 天中买卖一次的最大收益（不一定在第 i 天卖）。

然后枚举第二次交易，从后往前扫描，并计算只买卖一次且第 i 天买入的最大收益，最大收益等于第 i 天之后股票价格的最大值减去 第 i 天的价格，然后加上 f[i−1]，就是第二次交易在 i 天买入，两次交易的总收益的最大值。
枚举过程中维护总收益的最大值即可。

时间复杂度分析：整个数组总共扫描两遍，所以时间复杂度是 O(n)。



#### C++

```c
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<int> f(n, 0);
        int minv = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                f[i] = f[i - 1];
            }
            if (prices[i] > minv) {
                f[i] = max(f[i], prices[i] - minv);
            }
            minv = min(minv, prices[i]);
        }
        int res = f[n - 1];
        int maxv = INT_MIN;
        for (int i = n - 1; i > 0; --i) {
            if (prices[i] < maxv) {
                res = max(res, maxv - prices[i] + f[i - 1]);
            }
            maxv = max(maxv, prices[i]);
        }
        return res;
    }
};
```


