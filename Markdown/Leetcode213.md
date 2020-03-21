# Leetcode213 打家劫舍Ⅱ

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber-ii/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。



**示例 1:**

```
输入: [2,3,2]
输出: 3
解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
```



**示例 2:**

```
输入: [1,2,3,1]
输出: 4
解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。
```



### 解题思路：

### 方法一：动态规划

##### 直观想法

对去掉第一个元素和去掉最后一个元素的数组分别进行dp，

a 即不考虑最后一个元素， b 即不考虑第一个元素

    a[i] = max(a[i - 1], a[i - 2] + nums[i - 2]);
    b[i] = max(b[i - 1], b[i - 2] + nums[i - 1]);
举例：

`2 3 2`

a[2] = max(a[1], a[0] + nums[0]) = max(0,0+2)
b[2] = max(b[1], b[0] + nums[1]) = max(0,0+2)
a[3] = max(a[2], a[1] + nums[1]) = max(2,0+2)
b[3] = max(b[2], b[1] + nums[2]) = max(2,0+3)

`1 2 3 1`

a[2] = max(a[1], a[0] + nums[0]) = max(0,0+1)
b[2] = max(b[1], b[0] + nums[1]) = max(0,0+2)
a[3] = max(a[2], a[1] + nums[1]) = max(1,0+2)
b[3] = max(b[2], b[1] + nums[2]) = max(2,0+3)
a[4] = max(a[3], a[2] + nums[2]) = max(2,1+3)
b[4] = max(b[3], b[2] + nums[3]) = max(3,2+1)



#### C++

```c
class Solution {
public:
    int rob(vector<int> &nums) {
        int len = nums.size();
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> a(len + 1, 0), b(len + 1, 0);
        for (int i = 2; i < len + 1; ++i) {
            a[i] = max(a[i - 1], a[i - 2] + nums[i - 2]);
            b[i] = max(b[i - 1], b[i - 2] + nums[i - 1]);
        }
        return max(a[len], b[len]);
    }
};
```



#### Java

```java
class Solution {
    public int rob(int[] nums) {
        
    }
}
```



#### Python

```python
class Solution:
    def rob(self, nums: List[int]) -> int:
        
```

