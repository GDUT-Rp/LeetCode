# Leetcode303 区域和检索 - 数组不可变

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-query-immutable/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

给定一个整数数组  *nums*，求出数组从索引 *i* 到 *j*  (*i* ≤ *j*) 范围内元素的总和，包含 *i,  j* 两点。



**示例 1:**

```
给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
```

**说明:**

- 你可以假设数组不可变。
- 会多次调用 *sumRange* 方法。



### 解题思路：

### 方法一：缓存

##### 直观想法

假设 sumrange 被调用 1000次，其参数完全相同。我们怎么能加快速度？
我们可以用额外的空间换取速度。通过预先计算所有的范围和可能性并将其结果存储在哈希表中，我们可以将查询加速到常量时间。

#### C++

```c
class NumArray {
public:
    pair<int, int> pairs;
    map<pair<int,int>,int> maps;

    NumArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = i; j < nums.size(); ++j) {
                sum += nums[j];
                maps[make_pair(i, j)] = sum;
            }
        }
    }

    int sumRange(int i, int j) {
        return maps[make_pair(i, j)];
    }
};
```



#### Java

```java
private Map<Pair<Integer, Integer>, Integer> map = new HashMap<>();

public NumArray(int[] nums) {
    for (int i = 0; i < nums.length; i++) {
        int sum = 0;
        for (int j = i; j < nums.length; j++) {
            sum += nums[j];
            map.put(Pair.create(i, j), sum);
        }
    }
}

public int sumRange(int i, int j) {
    return map.get(Pair.create(i, j));
}
```



#### Python

```python
class NumArray:

    def __init__(self, nums: List[int]):
        

    def sumRange(self, i: int, j: int) -> int:
        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
```



**复杂度分析**

时间复杂度：每次查询的时间 $O(1)$，$O(n^2)$时间用来预计算。在构造函数中完成的预计算需要 $O(n^2)
$时间。每个 sumrange 查询的时间复杂性是 $O(1)$ 因为哈希表的查找操作是常量时间。
空间复杂度：$O(n^2)$，所需的额外空间为 $O(n^2)$ 因为 $i$ 和 $j$ 都有 $n$ 个候选空间。



### 方法二：缓存

- 上面的方法需要很大的空间，我们可以优化它吗？
- 假设我们预先计算了从数字 $0$ 到 $k$ 的累积和。我们可以用这个信息得出 $sum(i，j)$ 吗？
- 让我们将 $sum[k]$ 定义为 $nums[0\cdots k-1] $的累积和（包括这两个值）：

$$
\operatorname{sum}[k]=\left\{\begin{array}{cc}{\sum_{i=0}^{k-1} n u m s[i]} & {, k>0} \\ {0} & {, k=0}\end{array}\right.
$$

现在，我们可以计算 sumrange 如下：
$$
sumrange（i，j）=sum[j+1]-sum[i]
$$

#### C++

```c
class NumArray {
public:
    vector<int> sum;

    NumArray(vector<int>& nums) {
        sum = vector<int> (nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            sum[i + 1] = sum[i] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
};
```



#### Java

```java
private int[] sum;

public NumArray(int[] nums) {
    sum = new int[nums.length + 1];
    for (int i = 0; i < nums.length; i++) {
        sum[i + 1] = sum[i] + nums[i];
    }
}

public int sumRange(int i, int j) {
    return sum[j + 1] - sum[i];
}
```



#### Python

```python
class NumArray:

    def __init__(self, nums: List[int]):
        

    def sumRange(self, i: int, j: int) -> int:
        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
```



**复杂度分析**

- 时间复杂度：每次查询的时间 $O(1)$，$O(N)$，预计算时间。由于累积和被缓存，每个 $sumrange$ 查询都可以用 $O(1)$ 时间计算。
- 空间复杂度：$O(n)$。