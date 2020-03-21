# Leetcode321 拼接最大数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/create-maximum-number/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

给定长度分别为 `m` 和 `n` 的两个数组，其元素由 `0-9` 构成，表示两个自然数各位上的数字。现在从这两个数组中选出 `k (k <= m + n)` 个数字拼接成一个新的数，要求从同一个数组中取出的数字保持其在原数组中的相对顺序。

求满足该条件的最大数。结果返回一个表示该最大数的长度为 `k` 的数组。

**说明**: 请尽可能地优化你算法的时间和空间复杂度。

<img src="" width = 30% height = 30% />

**示例 1:**

```
输入:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
输出:
[9, 8, 6, 5, 3]
```

**示例 2:**

```
输入:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
输出:
[6, 7, 6, 0, 4]
```

**示例 3:**

```
输入:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
输出:
[9, 8, 9]
```



### 解题思路：

### 方法一：动态规划

##### 直观想法

将这个问题分解成两个动态规划问题，题解来自 花花酱。

左边的小问题是，在一个一维数组里，选取两个数最大，那就pop一边比较一边掉其他的数。

右边的小问题是，在两个一维数组里，逐次比较，选取最大的数。

![](https://img-blog.csdnimg.cn/20191103155721832.png)

#### C++

```c
class Solution {
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<int> ans;
        const int n1 = nums1.size();
        const int n2 = nums2.size();
        for (int k1 = 0; k1 <= k; ++k1) {
            const int k2 = k - k1;
            if (k1 > n1 || k2 > n2) {
                continue;
            }
            ans = max(ans, maxNumber(maxNumber(nums1, k1), maxNumber(nums2, k2)));
        }
        return ans;
    }

private:
    vector<int> maxNumber(const vector<int> &nums, const int k) {
        if (k == 0) {
            return {};
        }
        vector<int> ans;
        int to_pop = nums.size() - k;
        for (const int num : nums) {
            while (!ans.empty() && num > ans.back() && to_pop-- > 0) {
                ans.pop_back();
            }
            ans.push_back(num);
        }
        ans.resize(k);
        return ans;
    }

    vector<int> maxNumber(const vector<int> &nums1, const vector<int> &nums2) {
        vector<int> ans;
        auto s1 = nums1.cbegin();
        auto e1 = nums1.cend();
        auto s2 = nums2.cbegin();
        auto e2 = nums2.cend();
        while (s1 != e1 || s2 != e2) {
            ans.push_back(lexicographical_compare(s1, e1, s2, e2) ? *s2++ : *s1++);
        }
        return ans;
    }
};
```



#### Java

```java
class Solution {
    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        
    }
}
```



#### Python

```python
class Solution:
    def maxNumber(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
```



**复杂度分析**

时间复杂度： $O(k(n_1+n_2)^3)$。
空间复杂度：$O(n_1 + n_2)$。


