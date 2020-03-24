# Leetcode206 反转链表

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

反转一个单链表



**示例 1:**

```
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
```



### 解题思路：

### 方法一：迭代

##### 直观想法

在遍历列表时，将当前节点的 next 指针改为指向前一个元素。由于节点没有引用其上一个节点，因此必须事先存储其前一个元素。在更改引用之前，还需要另一个指针来存储下一个节点。不要忘记在最后返回新的头引用！



#### C++

```c
//
// Created by Lenovo on 2020/3/24.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE206_H
#define LEETCODE_C_PLUSPLUS_LEETCODE206_H

#include <iostream>

/**
 * Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *prev, *curr, *next;
        prev = NULL;
        curr = head;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE206_H

```



#### Java

```java
public ListNode reverseList(ListNode head) {
    ListNode prev = null;
    ListNode curr = head;
    while (curr != null) {
        ListNode nextTemp = curr.next;
        curr.next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}
```



#### Python

```python
# -*- coding: utf-8 -*-
# @File   : LeetCode206.py
# @Author : Runpeng Zhang
# @Date   : 2020/3/24
# @Desc   : 反转链表


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev = None
        curr = head
        while curr is not None:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        return prev



```

**复杂度分析**

- 时间复杂度：$O(n)$，假设 $n $是列表的长度，时间复杂度是 $O(n)。$
- 空间复杂度：$O(1)$。



### 方法一：递归

##### 直观想法

递归方法较为巧妙



#### C++

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};
```



#### Java

```java
public ListNode reverseList(ListNode head) {
    if (head == null || head.next == null) return head;
    ListNode p = reverseList(head.next);
    head.next.next = head;
    head.next = null;
    return p;
}
```



#### Python

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        p = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return p
```

**复杂度分析**

- 时间复杂度：$O(n)$，假设 $n $是列表的长度，时间复杂度是 $O(n)。$
- 空间复杂度：$O(1)$。

