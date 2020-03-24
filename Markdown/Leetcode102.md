# Leetcode102 二叉树的层次遍历

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: `[3,9,20,null,null,15,7]`,

```
    3
   / \
  9  20
    /  \
   15   7
```

返回其层次遍历结果：

```
[
  [3],
  [9,20],
  [15,7]
]
```



### 解题思路：

#### 如何遍历一棵树

有两种通用的遍历树的策略：

- *深度优先搜索*（`DFS`）

  在这个策略中，我们采用`深度`作为优先级，以便从跟开始一直到达某个确定的叶子，然后再返回根到达另一个分支。

  深度优先搜索策略又可以根据根节点、左孩子和右孩子的相对顺序被细分为`先序遍历`，`中序遍历`和`后序遍历`。

- *宽度优先搜索*（`BFS`）

  我们按照高度顺序一层一层的访问整棵树，高层次的节点将会比低层次的节点先被访问到。

下图中的顶点按照访问的顺序编号，按照 `1-2-3-4-5` 的顺序来比较不同的策略。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200321170900134.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)





### 方法一：递归算法

##### 直观想法

最简单的解法就是递归，首先确认树非空，然后调用递归函数 `helper(node, level)`，参数是当前节点和节点的层次。程序过程如下：

- 输出列表称为 `levels`，当前最高层数就是列表的长度 `len(levels)`。比较访问节点所在的层次 `level` 和当前最高层次 `len(levels)` 的大小，如果前者更大就向 `levels` 添加一个空列表。
- 将当前节点插入到对应层的列表 `levels[level]` 中。
- 递归非空的孩子节点：`helper(node.left / node.right, level + 1)`。

##### 举例

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200321171557537.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200321171610513.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200321171711826.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/2020032117172916.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/2020032117174283.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200321171755196.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200321171807814.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200321171822224.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

#### C++

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL){
            return ans;
        }
        helper(root, 0, ans);
        return ans;
    }

    void helper(TreeNode* root, int level, vector<vector<int>> &ans) {
        if (ans.size() == level) {
            ans.push_back(vector<int>());
        }

        ans[level].push_back(root->val);

        if (root->left != NULL) {
            helper(root->left, level + 1, ans);
        }
        if (root->right != NULL) {
            helper(root->right, level + 1, ans);
        }
    }
};
```



#### Java

```java
class Solution {
    List<List<Integer>> levels = new ArrayList<List<Integer>>();

    public void helper(TreeNode node, int level) {
        // start the current level
        if (levels.size() == level)
            levels.add(new ArrayList<Integer>());

         // fulfil the current level
         levels.get(level).add(node.val);

         // process child nodes for the next level
         if (node.left != null)
            helper(node.left, level + 1);
         if (node.right != null)
            helper(node.right, level + 1);
    }
    
    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null) return levels;
        helper(root, 0);
        return levels;
    }
}
```



#### Python

```python
# -*- coding: utf-8 -*-
# @File   : LeetCode102.py
# @Author : Runpeng Zhang
# @Date   : 2020/3/21
# @Desc   : 二叉树的层次遍历


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def levelOrder(self, root: TreeNode):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        levels = []
        if not root:
            return levels

        def helper(node, level):
            if len(levels) == level:
                levels.append([])

            levels[level].append(node.val)

            if node.left:
                helper(node.left, level + 1)
            if node.right:
                helper(node.right, level + 1)

        helper(root, 0)
        return levels
```

**复杂度分析**

时间复杂度：$O(n)$，因为每个节点恰好会被运算一次。
空间复杂度：$O(n)$，保存输出结果的数组包含 `N` 个节点的值。

### 方法二：迭代

##### 直观想法

上面的递归方法也可以写成迭代的形式。

我们将树上顶点按照层次依次放入*队列*结构中，队列中元素满足 FIFO（先进先出）的原则。在 Java 中可以使用[ `Queue` 接口中的 `LinkedList`](https://docs.oracle.com/javase/7/docs/api/java/util/Queue.html)实现。在 Python 中如果使用 [`Queue`](https://docs.python.org/3/library/queue.html) 结构，但因为它是为多线程之间安全交换而设计的，所以使用了锁，会导致性能不佳。因此在 Python 中可以使用 [`deque`](https://docs.python.org/3/library/collections.html#collections.deque) 的 `append()` 和 `popleft()` 函数来快速实现队列的功能。

第 0 层只包含根节点 `root` ，算法实现如下：

- 初始化队列只包含一个节点 `root` 和层次编号 `0` ： `level = 0`。
- 当队列非空的时候：
  - 在输出结果 `levels` 中插入一个空列表，开始当前层的算法。
  - 计算当前层有多少个元素：等于队列的长度。
  - 将这些元素从队列中弹出，并加入 `levels` 当前层的空列表中。
  - 将他们的孩子节点作为下一层压入队列中。
  - 进入下一层 `level++`。

#### C++

```c
#include <deque>
#include <vector>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL){
            return ans;
        }
        int level = 0;
        deque<TreeNode*> queues;
        queues.push_back(root);
        while (queues.size() > 0) {
            ans.push_back(vector<int>());
            int level_length = queues.size();
            for (int i = 0; i < level_length; i++) {
                TreeNode* node = queues.front();
                queues.pop_front();
                ans[level].push_back(node->val);
                if (node->left != NULL) {
                    queues.push_back(node->left);
                }
                if (node->right != NULL) {
                    queues.push_back(node->right);
                }
            }
            level += 1;
        }
        return ans;
    }
};
```



#### Java

```java
class Solution {
  public List<List<Integer>> levelOrder(TreeNode root) {
    List<List<Integer>> levels = new ArrayList<List<Integer>>();
    if (root == null) return levels;

    Queue<TreeNode> queue = new LinkedList<TreeNode>();
    queue.add(root);
    int level = 0;
    while ( !queue.isEmpty() ) {
      // start the current level
      levels.add(new ArrayList<Integer>());

      // number of elements in the current level
      int level_length = queue.size();
      for(int i = 0; i < level_length; ++i) {
        TreeNode node = queue.remove();

        // fulfill the current level
        levels.get(level).add(node.val);

        // add child nodes of the current level
        // in the queue for the next level
        if (node.left != null) queue.add(node.left);
        if (node.right != null) queue.add(node.right);
      }
      // go to next level
      level++;
    }
    return levels;
  }
}
```



#### Python

```python
# -*- coding: utf-8 -*-
# @File   : LeetCode102.py
# @Author : Runpeng Zhang
# @Date   : 2020/3/21
# @Desc   : 二叉树的层次遍历


from collections import deque


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def levelOrder(self, root: TreeNode):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        levels = []
        if not root:
            return levels

        level = 0
        queue = deque([root, ])
        while queue:
            # start the current level
            levels.append([])
            # number of elements in the current level
            level_length = len(queue)

            for i in range(level_length):
                node = queue.popleft()
                # fulfill the current level
                levels[level].append(node.val)

                # add child nodes of the current level
                # in the queue for the next level
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            # go to next level
            level += 1
        return levels
```

**算法复杂度**:

时间复杂度：访问每个节点恰好一次，时间复杂度为 $O(N)$ ，其中 $N$ 是节点的个数，也就是树的大小。
空间复杂度：取决于树的结构，最坏情况存储整棵树，因此空间复杂度是 $O(N)$。