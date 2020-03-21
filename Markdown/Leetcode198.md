# Leetcode198 打家劫舍

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

**示例 1:**

```
输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
```

**示例 2:**

```
输入: [2,7,9,3,1]
输出: 12
解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
```



### 解题思路：

### 方法一：动态规划

##### 直观想法

考虑所有可能的抢劫方案过于困难。一个自然而然的想法是首先从最简单的情况开始。记：

> f(k) = 从前 k 个房屋中能抢劫到的最大数额，$A_i$ = 第 i 个房屋的钱数。
>

首先看 $n = 1$ 的情况，显然 $f(1) = A_1$。

再看 $n = 2$，$f(2) = \max(A_1,A_2)$。

对于 $n = 3$，有两个选项:

1. 抢第三个房子，将数额与第一个房子相加。
2. 不抢第三个房子，保持现有最大数额。

显然，你想选择数额更大的选项。于是，可以总结出公式：

$$
f(k) = \max(f(k – 2) + A_k, f(k – 1))
$$
我们选择 $f(–1) = f(0) = 0$ 为初始情况，这将极大地简化代码。

答案为 $f(n)$。可以用一个数组来存储并计算结果。

不过由于每一步你只需要前两个最大值，两个变量就足够用了。



#### C++

```c
class Solution {
public:
    int rob(vector<int>& nums) {
        int prevMax = 0;
        int currMax = 0;
        for (auto num: nums){
            int temp = currMax;
            currMax = max(prevMax + num, currMax);
            prevMax = temp;
        }
        return currMax;
    }
};
```



#### Java

```java
public int rob(int[] num) {
    int prevMax = 0;
    int currMax = 0;
    for (int x : num) {
        int temp = currMax;
        currMax = Math.max(prevMax + x, currMax);
        prevMax = temp;
    }
    return currMax;
}
```



#### Python

```python
class Solution:
    def rob(self, nums: List[int]) -> int:
        prevMax = 0
        currMax = 0
        for x in nums:
            temp = currMax
            currMax = max(prevMax + x, currMax)
            prevMax = temp
        return currMax
```

