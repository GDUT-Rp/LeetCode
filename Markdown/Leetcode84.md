# Leetcode84 柱形图中最大的矩形

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-rectangle-in-histogram/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

给定 *n* 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/histogram.png)

以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 `[2,1,5,6,2,3]`。

![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/histogram_area.png)

图中阴影部分为所能勾勒出的最大矩形面积，其面积为 `10` 个单位。



示例 1:

```
输入: [2,1,5,6,2,3]
输出: 10
```



### 解题思路：



### 方法一：暴力

##### 直观想法

首先，我们可以想到，两个柱子间矩形的高由它们之间最矮的柱子决定。如下图所示：

![](https://pic.leetcode-cn.com/0239df28a3a9d97a96c773a4b5babc59cf55219332f815eda3fc240a7d530cda-image.png)

因此，我们可以考虑所有两两柱子之间形成的矩形面积，该矩形的高为它们之间最矮柱子的高度，宽为它们之间的距离，这样可以找到所要求的最大面积的矩形。



#### C++:

```c
//  纯暴力解法,TLE
int largestRectangleArea_baoli(vector<int> &heights) {
    int maxarea = 0;
    for (int i = 0; i < heights.size(); ++i) {
        for (int j = i; j < heights.size(); ++j) {  //  对于任意两个柱子（i, j）
            int minheight = INT_MAX;
            for (int k = i; k <= j; ++k) {           //  找到两个柱子之间的最矮柱子
                minheight = min(minheight, heights[k]);
            }
            maxarea = max(maxarea, minheight * (j - i + 1));    //  尝试更新最大面积
        }
    }
    return maxarea;
}
```



#### Java:

```java
public class Solution {
   public int largestRectangleArea(int[] heights) {
       int maxarea = 0;
       for (int i = 0; i < heights.length; i++) {
           for (int j = i; j < heights.length; j++) {
               int minheight = Integer.MAX_VALUE;
               for (int k = i; k <= j; k++)
                   minheight = Math.min(minheight, heights[k]);
               maxarea = Math.max(maxarea, minheight * (j - i + 1));
           }
       }
       return maxarea;
   }
}
```



#### Python:

```python
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        
```

**复杂性分析**

- 时间复杂度： $O(n^3)$。我们需要使用 $O(n)$ 的时间找到 $O(n^2)$ 枚举出来的所有柱子对之间的最矮柱子
- 空间复杂度 $O(1)$ 的额外空间。 



### 方法二：优化的暴力

算法

我们可以基于方法 1 进行一点点修改来优化算法。我们可以用前一对柱子之间的最低高度来求出当前柱子对间的最低高度。

用数学语言来表达，`minheight=min(minheight,heights(j))` ，其中， `heights(j)` 是第 j 个柱子的高度。



#### C++:

```c
//  优化的暴力解法,TLE
int largestRectangleArea_baoli_improved(vector<int> &heights) {
    int maxarea = 0;
    for (int i = 0; i < heights.size(); ++i) {
        int minheight = INT_MAX;
        for (int j = i; j < heights.size(); ++j) {  //  我们可以用前一对柱子之间的最低高度来求出当前柱子对间的最低高度
            minheight = min(minheight, heights[j]);
            maxarea = max(maxarea, (j - i + 1) * minheight);
        }
    }
    return maxarea;
}
```



#### Java:

```java
public class Solution {
   public int largestRectangleArea(int[] heights) {
       int maxarea = 0;
       for (int i = 0; i < heights.length; i++) {
           int minheight = Integer.MAX_VALUE;
           for (int j = i; j < heights.length; j++) {
               minheight = Math.min(minheight, heights[j]);
               maxarea = Math.max(maxarea, minheight * (j - i + 1));
           }
       }
       return maxarea;
   }
}
```



#### Python:

```python
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        
```

**复杂性分析**

- 时间复杂度： $O(n^2)$。我们需要枚举出来的所有可能的柱子。
- 空间复杂度 $O(1)$ 的额外空间。 



### 方法三：分治

算法

通过观察，可以发现，最大面积矩形存在于以下几种情况：

确定了最矮柱子以后，矩形的宽尽可能往两边延伸。

在最矮柱子左边的最大面积矩形（子问题）。

在最矮柱子右边的最大面积矩形（子问题）。

举个例子：

```
[6, 4, 5, 2, 4, 3, 9]
```

这里最矮柱子高度为 2 。以 2 为高的最大子矩阵面积是 2x8=16 。现在，我们考虑上面提到的第二种和第三种情况。我们对高度为 2 柱子的左边和右边采用同样的过程。在 2 的左边， 4 是最小的，形成区域为 4x3=12 。将左边区域再继续分，矩形的面积分别为 6x1=6 和 5x1=5 。同样的，我们可以求出右边区域的面积为 3x3=9, 4x1=4 和 9x1=9 。因此，我们得到最大面积是 16 。具体过程可参考下图：

![](https://pic.leetcode-cn.com/2013f70b237a16bcf8bae8f5873669b8b21d5300b2ed254adbddd2b9b577f02b-image.png)



#### C++:

```c
//  分治解法TLE
int largestRectangleArea_fenzhi(vector<int> &heights) {
    return calculateArea(heights, 0, heights.size() - 1);
}

int calculateArea(vector<int> heights, int start, int end) {
    if (start > end) {
        return 0;
    }
    int minindex = start;
    for (int i = start; i <= end; ++i) {
        if (heights[minindex] > heights[i]) {       //  找到最矮柱子
            minindex = i;
        }
    }
    return max(heights[minindex] * (end - start + 1),
               max(calculateArea(heights, start, minindex - 1), calculateArea(heights, minindex + 1, end)));
}
```



#### Java:

```java
public class Solution {
    public int calculateArea(int[] heights, int start, int end) {
        if (start > end)
            return 0;
        int minindex = start;
        for (int i = start; i <= end; i++)
            if (heights[minindex] > heights[i])
                minindex = i;
        return Math.max(heights[minindex] * (end - start + 1), Math.max(calculateArea(heights, start, minindex - 1), calculateArea(heights, minindex + 1, end)));
    }
    public int largestRectangleArea(int[] heights) {
        return calculateArea(heights, 0, heights.length - 1);
    }
}
```



#### Python:

```python
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        
```

**复杂性分析**

- 时间复杂度： $O(n\log n)$

  最坏情况： $O(n^2)$ 。如果数组中的数字是有序的，分治算法将没有任何优化效果。

- 空间复杂度 $O(n)$ 的额外空间。 



### 方法四：

算法

在这种方法中，我们维护一个栈。一开始，我们把 -1 放进栈的顶部来表示开始。初始化时，按照从左到右的顺序，我们不断将柱子的序号放进栈中，直到遇到相邻柱子呈下降关系，也就是 $a[i-1] > a[i]$ 。现在，我们开始将栈中的序号弹出，直到遇到 $stack[j]$ 满足$a\big[stack[j]\big] \leq a[i]$ 。每次我们弹出下标时，我们用弹出元素作为高形成的最大面积矩形的宽是当前元素与 $stack[top−1]$ 之间的那些柱子。也就是当我们弹出 $stack[top]$ 时，记当前元素在原数组中的下标为 i ，当前弹出元素为高的最大矩形面积为：
$$
(i−stack[top−1]−1)×a[stack[top]].
$$
更进一步，当我们到达数组的尾部时，我们将栈中剩余元素全部弹出栈。在弹出每一个元素是，我们用下面的式子来求面积：$ (stack[top]-stack[top-1]) \times a\big[stack[top]\big]$，其中，$stack[top]$ 表示刚刚被弹出的元素。因此，我们可以通过每次比较新计算的矩形面积来获得最大的矩形面积。

下面的例子将进一步解释：

```
[6, 7, 5, 2, 4, 5, 9, 3]
```

![](https://img-blog.csdn.net/2018041713503850?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2x2MTIyNA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

示例的过程如下：stack<int>  st
矩阵1，高度为2，入栈，栈中元素为 0
矩阵2，高度为1，弹出栈顶元素并计算当前最大面积，弹出后栈为空，当前元素索引为1，故长度为1，面积为$1*2=2$，当前元素入栈，栈中元素为 1
矩阵3，高度为5，直接入栈，栈中元素为 1,2
矩阵4，高度为6，直接入栈，栈中元素为1,2,3
矩阵5，高度为2，小于栈顶元素对应矩阵高度，弹出栈顶元素3，栈非空，栈顶元素为2，故以矩阵4为最低高度的面积最大为$6*(4-2-1)=6$，栈中元素为1,2。此时当前矩阵高度依然小于栈顶元素对应矩阵高度，继续弹出2，栈非空，栈顶元素为1，故长度为$4-1-1=2$，面积为$2*5=10$。入栈，栈中元素为1,4
矩阵6，高度为3,大于栈顶元素，入栈，栈中元素为1,4,5
此时元素遍历完，弹出栈中元素。
弹出栈顶元素5，此时栈顶元素为4，此时长度为$6-4-1=1$，面积为$1*3=3$
弹出栈顶元素4，此时栈顶元素为1，此时长度为$6-1-1=4$，面积为$4*2=8$
弹出栈顶元素1，此时栈为空，此时长度为6，面积为$1*6=6$

![](https://pic.leetcode-cn.com/eecfe2ec7c58bc2271384f6389731c655309f34cfd7dd2e91f6e6d0edf243430-image.png)



![](https://pic.leetcode-cn.com/51497dd241662feee92b2a21809fb52071b55d2f1a112e51deaf8a9b351760bd-image.png)

![](https://pic.leetcode-cn.com/12ccce1435f76e3ac852b574391430d01b8db7c8ef263cbe9d0f62759f7f0fdd-image.png)

![](https://pic.leetcode-cn.com/8b67a39213543ec0a0920ff8f98fad7cbc54950c92853231b64eecedde03ccc4-image.png)

![](https://pic.leetcode-cn.com/1608c1d682641b7aff5489e3366e4084541a0ae5f4cd51590c615a5be79addc2-image.png)

![](https://pic.leetcode-cn.com/d4cd57acfca43708c81c385a5f5137505f63cc2a270dbd7c13d78a9623dc7087-image.png)

![](https://pic.leetcode-cn.com/4a2a53007b4fbc285cf93c25f1f0df8da4ea978702943034adc8156741787eb4-image.png)

![](https://pic.leetcode-cn.com/ef8c90a70cffce8dfdda84fec2a482e0aa0c8f0701960c11e9df09fc60a9ae37-image.png)

![](https://pic.leetcode-cn.com/f079f34ac43bc1f4572ed5da638b87c013c2cb8e81f93e9521afb8f91bf69a07-image.png)

![](https://pic.leetcode-cn.com/d94d9d63b4ca55e0c7b1c14a5d0309ff22a2a363cf3b5fc66eeafc80438dc9f4-image.png)

![](https://pic.leetcode-cn.com/757cebdd7d4d2985c2c1552bbf9f71d8e4327d561c488bb62c14a5e4226d3c64-image.png)

![](https://pic.leetcode-cn.com/97ee36f0ca8ba5a61048195ce1fa3394371d1d3821939b05900faed1e1ff40fc-image.png)

![](https://pic.leetcode-cn.com/7e3fbb774a89edd8a3507c53a24669fccf13639f199e9d842c4205a9f4248c12-image.png)

.

#### C++:

```c
int largestRectangleArea_stack(vector<int> &heights) {
    int n = heights.size();
    stack<int> index;
    int area = 0;       //  ans，维护最大面积
    for (int i = 0; i < heights.size(); i++) {
        if (index.empty() || heights[index.top()] < heights[i]) {   //  栈顶元素对应的高度小于下一个高度就进栈
            index.push(i);
        } else {
            while (!index.empty() && heights[index.top()] >= heights[i]) {  //  栈非空情况下并且栈顶元素对应值大于下一个高度
                int tmp = index.top();      //  栈顶元素
                index.pop();                //  出栈
                int length = 0;
                if (index.empty()) {        //  长度即从0开始到i这里
                    length = i;
                } else {
                    length = i - index.top() - 1;   //  矩形宽
                }
                area = max(area, length * heights[tmp]);
            }
            index.push(i);  //  把高的都出栈了，现在可以把矮的这个进栈
        }
    }
    while (!index.empty()) {    //  把这个递增序列逐个出栈进行计算
        int tmp = index.top();
        index.pop();
        int length = 0;
        if (index.empty()) {
            length = n;
        } else {
            length = n - index.top() - 1;
        }
        area = max(area, length * heights[tmp]);
    }
    return area;
}
```



#### Java:

```java
public class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack < Integer > stack = new Stack < > ();
        stack.push(-1);
        int maxarea = 0;
        for (int i = 0; i < heights.length; ++i) {
            while (stack.peek() != -1 && heights[stack.peek()] >= heights[i])
                maxarea = Math.max(maxarea, heights[stack.pop()] * (i - stack.peek() - 1));
            stack.push(i);
        }
        while (stack.peek() != -1)
            maxarea = Math.max(maxarea, heights[stack.pop()] * (heights.length - stack.peek() -1));
        return maxarea;
    }
}
```



#### Python:

```python
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        
```

**复杂性分析**

- 时间复杂度： $O(n)$。n个数字每个会被压入栈弹出栈各一次。
- 空间复杂度 $O(n)$ 的额外空间，用来存放栈中元素。 