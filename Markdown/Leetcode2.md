# Leetcode2 两数相加

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

给出两个 **非空** 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 **逆序** 的方式存储的，并且它们的每个节点只能存储 **一位** 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。



**示例 1:**

```
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
```



### 解题思路：

### 方法一：简单相加

##### 直观想法

我们使用变量来跟踪进位，并从包含最低有效位的表头开始模拟逐位相加的过程。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200324180250967.png)



#### C++

```c
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution_LeetCode2 {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *result = new ListNode(0);
        ListNode *tmp = result;
        int sum = 0;
        while (l1 || l2) {
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            tmp->next = new ListNode(sum % 10);
            sum /= 10;
            tmp = tmp->next;
        }
        if (sum)
            tmp->next = new ListNode(1);
        return result->next;
        // 牺牲头结点
    }
};

```



#### Java

```java
public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    ListNode dummyHead = new ListNode(0);
    ListNode p = l1, q = l2, curr = dummyHead;
    int carry = 0;
    while (p != null || q != null) {
        int x = (p != null) ? p.val : 0;
        int y = (q != null) ? q.val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr.next = new ListNode(sum % 10);
        curr = curr.next;
        if (p != null) p = p.next;
        if (q != null) q = q.next;
    }
    if (carry > 0) {
        curr.next = new ListNode(carry);
    }
    return dummyHead.next;
}
```



#### Python

```python
# -*- coding: utf-8 -*-
# @File   : LeetCode2.py
# @Author : Runpeng Zhang
# @Date   : 2020/3/24
# @Desc   : 链表两数相加


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        sum = 0
        head = ListNode(0)  # create the head of ListNode
        result = head
        tmp = ListNode(0)
        while l1 or l2:
            if l1:
                sum += l1.val
                l1 = l1.next
            if l2:
                sum += l2.val
                l2 = l2.next
            result.next = ListNode(sum % 10)
            result = result.next
            sum = sum // 10 # Be careful, should be //
        if sum > 0:
            result.next = ListNode(sum)
        return head.next


l1 = ListNode(2)
l1.next = ListNode(4)
l1.next.next = ListNode(3)

l2 = ListNode(5)
l2.next = ListNode(6)
l2.next.next = ListNode(4)

a = Solution()
result = a.addTwoNumbers(l1, l2)
while result:
    print(result.val)
    result = result.next
```

**复杂度分析**

时间复杂度：$O(\max(m, n))$，假设 $m$ 和 $n$ 分别表示 $l1$ 和 $l2$ 的长度，上面的算法最多重复 $\max(m, n)$ 次。

空间复杂度：$O(\max(m, n))$， 新列表的长度最多为 $\max(m,n) + 1$。


