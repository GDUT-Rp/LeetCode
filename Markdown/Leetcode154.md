# Leetcode154 寻找旋转排序数组中的最小值Ⅱ

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

注意数组中可能存在重复的元素。

示例 1：

```
输入: [1,3,5]
输出: 1
```


示例 2：

```
输入: [2,2,2,0,1]
输出: 0
```


说明：

这道题是 寻找旋转排序数组中的最小值 的延伸题目。
允许重复会影响算法的时间复杂度吗？会如何影响，为什么？



### 解题思路：

- 旋转排序数组`nums`可以被拆分为2个排序数组`nums1`, `nums2`，并且`nums1`所有元素>=`nums2`所有元素；
- 因此，考虑二分法寻找值`nums[i]`；
- 设置`left`,`right`指针在`nums`数组两端，mid为中点：
  - 当`nums[mid] > nums[right]`时，一定满足`mid < i <= right`，因此`left = mid + 1`；
  - 当`nums[mid] < nums[right]`时，一定满足`left < i <= mid`，因此`right = mid`；
  - 当`nums[mid] == nums[right]`时，是此题对比153题的难点（原因是此题中数组的元素可重复，相等就难以判断最小值的指针区间）；先说结果：采用`right = right - 1`，下面证明：
    - 首先，此操作不会使数组越界，因为`right > left > 0`；
    - 其次，此操作不会使最小值丢失，证明：假设'nums[right]'是最小值，有两种情况：
      - 若`nums[right]`是唯一最小值：那就不可能满足判断条件`nums[mid] == nums[right]`，因为`left != right`且`mid = left + right // 2 < right`（向下取整）；
      - 若有其他元素和`nums[right]`同为最小值：还有最小值存在于`[left, right -1]`间，不会丢失最小值。
- 以上是理论分析，可以用以下数组辅助思考：
  - `[1, 2, 3]`
  - `[1, 1, 0, 1]`
  - `[1, 0, 1, 1, 1]`
  - `[1, 1, 1, 1]`



### 方法一：二分查找



#### C++:

```c
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low < high && nums[low] >= nums[high]){
            int mid = low + (high - low) / 2;
            if (nums[mid] < nums[low]){
                high = mid;
            }else if (nums[mid] == nums[low]){
                low++;
            }else{
                low = mid + 1;
            }
        }
        return nums[low];
    }
};
```



#### Java:

```java
class Solution {
    public int findMin(int[] nums) {
        int left = 0, right = nums.length - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right]) left = mid + 1;
            else if (nums[mid] < nums[right]) right = mid;
            else right = right - 1;
        }
        return nums[left];
    }
}
```



#### Python:

```python
class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        while left < right:
            mid = (left + right) // 2
            if nums[mid] > nums[right]: left = mid + 1
            elif nums[mid] < nums[right]: right = mid
            else: right = right - 1 # key
        return nums[left]
```

- **复杂度分析**
  - 时间复杂度：和二分搜索一样 $O(\log N)$
  - 空间复杂度：$O(1)$


