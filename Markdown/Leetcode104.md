# Leetcode104 二叉树的最大深度

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

```
    3
   / \
  9  20
    /  \
   15   7
```

返回它的最大深度 3 。



### 解题思路：

### 方法一：迭代

##### 直观想法

我们还可以在栈的帮助下将上面的递归转换为迭代。

> 我们的想法是使用 DFS 策略访问每个结点，同时在每次访问时更新最大深度。
>

所以我们从包含根结点且相应深度为 1 的栈开始。然后我们继续迭代：将当前结点弹出栈并推入子结点。每一步都会更新深度。




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
    int maxDepth(TreeNode* root) {
        pair<TreeNode*, int> tmp;
        deque<pair<TreeNode*, int>> stacks;
        if (root == NULL) {
            return 0;
        }
        tmp.first = root;
        tmp.second = 1;
        stacks.push_back(tmp);

        int depth = 0;
        while (!stacks.empty()) {
            pair<TreeNode*, int> current = stacks.front();
            stacks.pop_front();
            root = current.first;
            int current_depth = current.second;
            if (root != NULL) {
                depth = max(depth, current_depth);
                tmp.first = root->left;
                tmp.second = current_depth + 1;
                stacks.push_back(tmp);
                tmp.first = root->right;
                stacks.push_back(tmp);
            }
        }
        return depth;
    }
};
```



#### Java

```java
import javafx.util.Pair;
import java.lang.Math;

class Solution {
  public int maxDepth(TreeNode root) {
    Queue<Pair<TreeNode, Integer>> stack = new LinkedList<>();
    if (root != null) {
      stack.add(new Pair(root, 1));
    }

    int depth = 0;
    while (!stack.isEmpty()) {
      Pair<TreeNode, Integer> current = stack.poll();
      root = current.getKey();
      int current_depth = current.getValue();
      if (root != null) {
        depth = Math.max(depth, current_depth);
        stack.add(new Pair(root.left, current_depth + 1));
        stack.add(new Pair(root.right, current_depth + 1));
      }
    }
    return depth;
  }
};
```



#### Python

```python
# -*- coding: utf-8 -*-
# @File   : LeetCode104.py
# @Author : Runpeng Zhang
# @Date   : 2020/3/22
# @Desc   : 二叉树的最大深度


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        stack = [(root, 1)]
        depth = 0

        while len(stack) > 0:
            current = stack.pop(0)
            root = current[0]
            current_depth = current[1]
            if root is not None:
                depth = max(depth, current_depth)
                stack.append((root.left, current_depth + 1))
                stack.append((root.right, current_depth + 1))
        return depth
```

**复杂度分析**

时间复杂度：$\mathcal{O}(N)$，其中 N 是树的结点数，因为每个结点都访问一次。
空间复杂度：$\mathcal{O}(N)$，其中 N 是树中节点的数量。





### 方法二：递归，DFS （深度优先遍历）

##### 直观想法

也可以使用 *DFS* 实现 *BFS* 的遍历顺序。

> 在 DFS 遍历期间，将结果保存在按层数索引的全局数组中。即元素 `array[level]` 存储同一层的所有节点。然后在 DFS 的每一步更新全局数组。

![在这里插入图片描述](https://img-blog.csdnimg.cn/2020032213540437.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

与改进的 BFS 算法类似，使用双端队列保存同一层的所有节点，并交替插入方向（从首部插入或从尾部插入）得到需要的输出顺序。

**算法**

使用递归实现 DFS 算法。定义一个递归方法 `DFS(node, level)`，方法参数为当前节点 `node` 和指定层数 `level`。该方法共执行三个步骤：

- 如果是第一次访问该层的节点，即该层的双端队列不存在。那么创建一个双端队列，并添加该节点到队列中。

- 如果当前层的双端队列已存在，根据顺序，将当前节点插入队列头部或尾部。

- 最后，为每个节点调用该递归方法。



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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int level = 1;
        return maxDepth_dfs(root, level);
    }

    int maxDepth_dfs(TreeNode* node, int level) {
        if (node == NULL) {
            return level;
        }
        int left = level, right = level;
        if (node->left != NULL) {
            left = max(left, maxDepth_dfs(node->left, level + 1));
        }
        if (node->right != NULL) {
            right = max(left, maxDepth_dfs(node->right, level + 1));
        }
        return max(left, right);
    }
};
```



#### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
  public int maxDepth(TreeNode root) {
    if (root == null) {
      return 0;
    } else {
      int left_height = maxDepth(root.left);
      int right_height = maxDepth(root.right);
      return java.lang.Math.max(left_height, right_height) + 1;
    }
  }
}
```



#### Python

```python
# -*- coding: utf-8 -*-
# @File   : LeetCode104.py
# @Author : Runpeng Zhang
# @Date   : 2020/3/22
# @Desc   : 二叉树的最大深度


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        else:
            left_height = self.maxDepth(root.left)
            right_height = self.maxDepth(root.right)
            return max(left_height, right_height) + 1

```

**算法复杂度**:

时间复杂度：访问每个节点恰好一次，时间复杂度为 $O(N)$ ，其中 $N$ 是节点的个数，也就是树的大小。
空间复杂度：在最糟糕的情况下，树是完全不平衡的，例如每个结点只剩下左子结点，递归将会被调用 $N$ 次（树的高度），因此保持调用栈的存储将是 $O(N)$。但在最好的情况下（树是完全平衡的），树的高度将是 $\log(N)$。因此，在这种情况下的空间复杂度将是 $O(\log(N))$。