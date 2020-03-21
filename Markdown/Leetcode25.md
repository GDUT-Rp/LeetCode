# Leetcode25 K个一组反转链表



### 题目：

给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

示例 :

给定这个链表：`1->2->3->4->5`

当 k = 2 时，应当返回: `2->1->4->3->5`

当 k = 3 时，应当返回: `3->2->1->4->5`

说明 :

- 你的算法只能使用常数的额外空间。
- 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

### 解题思路：

#### 方法一：

递归法



##### C++:

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution_LeetCode23 {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *result = new ListNode(0);
        ListNode *q = result;
        int count = 0;
        while (count < lists.size()) {
            int location = 0; // the index of lists
            int imin = INT_MAX;  // to compare the min value
            for (int i = 0; i < lists.size(); ++i) {    // each time to get the min list
                if (lists[i] == NULL) {
                    lists[i] = new ListNode(INT_MAX);
                    count++;
                    if (count == lists.size()) {
                        return result->next;
                    }
                    continue;
                }
                if (lists[i]->val < imin) {
                    imin = lists[i]->val;
                    location = i;
                }
            }
            q->next = lists[location];
            q = q->next;
            lists[location] = lists[location]->next;
        }
        return result->next;
    }
};

```



#### 方法二：

链表的题先创建dummy节点，然后将其next指向head。之后遍历链表，统计出链表有多少个节点。再然后就是链表翻转部分了，这里很是经典，我也是学习了前辈的方法。个人认为这里是应该记住的，以后涉及到链表翻转的问题都可以用到。最后返回dummy->next。

##### C++

```c++

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = dummy;
        ListNode* pre = cur;
        int num = 0;
        while(cur->next){
            cur = cur->next;
            num++;
        }
        while(k <= num){
            cur = pre->next;
            for(int i = 1; i < k; i++){
                ListNode* temp = cur->next;
                cur->next = temp->next;
                temp->next = pre->next;
                pre->next = temp;
            }
            pre = cur;
            num -= k;
        }
        return dummy->next;      
    }
};
```

