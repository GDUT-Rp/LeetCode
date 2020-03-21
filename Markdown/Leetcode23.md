# Leetcode23 合并K个排序链表



### 题目：

合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

```
输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
```



### 解题思路：

#### 方法一：

暴力法，每次遍历list中的每一个头结点，找出最小值加入到结果链表中，并将该元素从lists中删除，当lists中没有元素的知识后，归并排序完毕。



### C++:

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

采用归并排序的思想，每次选择两个链表进行归并排序，一次排序之后，待归并排序的链表的个数变为原来的1／2，最后还有一个链表的时候，排序结束，得到的就是排好序的链表。 

```c++
ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0)
            return NULL;

        if (lists.size() == 1)
            return lists[0];

        if (lists.size() == 2)
            return mergeTwoLists(lists[0], lists[1]);

        int mid = lists.size() / 2;

        vector<ListNode *> v1;
        vector<ListNode *> v2;

        for (int i = 0; i <= mid; i++) {
            v1.push_back(lists[i]);
        }

        for (int i = mid + 1; i < lists.size(); i++) {
            v2.push_back(lists[i]);
        }

        ListNode *l1 = mergeKLists(v1);
        ListNode *l2 = mergeKLists(v2);

        return mergeTwoLists(l1, l2);
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode tmp(0);
        ListNode *head = &tmp;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                head->next = l1;
                l1 = l1->next;

            } else {
                head->next = l2;
                l2 = l2->next;

            }
            head = head->next;

        }

        if (l1) {
            head->next = l1;
        }
        if (l2) {
            head->next = l2;
        }

        return tmp.next;
    }
```

