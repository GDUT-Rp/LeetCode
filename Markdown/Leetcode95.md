# Leetcode95 不同的二叉搜索树Ⅱ

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-binary-search-trees-ii/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

给定一个整数 *n*，生成所有由 1 ... *n* 为节点所组成的**二叉搜索树**。



**示例 1:**

```
输入: 3
输出:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释:
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```



### 解题思路：

### 方法一：递归

##### 直观想法

首先来计数需要构建的二叉树数量。可能的二叉搜素数数量是一个 [卡特兰数](https://baike.baidu.com/item/卡特兰数/6125746?fr=aladdin)。

我们跟随上文的逻辑，只是这次是构建具体的树，而不是计数。

##### 算法

我们从序列 `1 ..n` 中取出数字 `i`，作为当前树的树根。于是，剩余 `i - 1` 个元素可用于左子树，`n - i` 个元素用于右子树。 如 [前文所述](https://blog.csdn.net/weixin_41738030/article/details/98031286)，这样会产生 `G(i - 1)` 种左子树 和 `G(n - i)` 种右子树，其中 G 是卡特兰数。

![](https://pic.leetcode-cn.com/f709dff506c20ac970d4cd7ace0436aafca7828c67b510cdbaaa60d54f5479b3-image.png)

现在，我们对序列 `1 ... i - 1` 重复上述过程，以构建所有的左子树；然后对 `i + 1 ... n` 重复，以构建所有的右子树。

这样，我们就有了树根 `i` 和可能的左子树、右子树的列表。

最后一步，对两个列表循环，将左子树和右子树连接在根上。



### C++

```c
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> res;
        if (n == 0) {
            return res;
        }
        return generate_trees(1, n);
    }

private:
    vector<TreeNode *> generate_trees(int start, int end) {
        vector<TreeNode *> res;
        if (start > end) {
            res.push_back(NULL);
        }
        for (int i = start; i <= end; ++i) {
            vector<TreeNode *> lefts = generate_trees(start, i - 1);
            vector<TreeNode *> rights = generate_trees(i + 1, end);
            for (auto left:lefts) {
                for (auto right:rights) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
```



#### Java

```c
class Solution {
  public LinkedList<TreeNode> generate_trees(int start, int end) {
    LinkedList<TreeNode> all_trees = new LinkedList<TreeNode>();
    if (start > end) {
      all_trees.add(null);
      return all_trees;
    }

    // pick up a root
    for (int i = start; i <= end; i++) {
      // all possible left subtrees if i is choosen to be a root
      LinkedList<TreeNode> left_trees = generate_trees(start, i - 1);

      // all possible right subtrees if i is choosen to be a root
      LinkedList<TreeNode> right_trees = generate_trees(i + 1, end);

      // connect left and right trees to the root i
      for (TreeNode l : left_trees) {
        for (TreeNode r : right_trees) {
          TreeNode current_tree = new TreeNode(i);
          current_tree.left = l;
          current_tree.right = r;
          all_trees.add(current_tree);
        }
      }
    }
    return all_trees;
  }

  public List<TreeNode> generateTrees(int n) {
    if (n == 0) {
      return new LinkedList<TreeNode>();
    }
    return generate_trees(1, n);
  }
}
```



#### Python

```python
class Solution:
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        def generate_trees(start, end):
            if start > end:
                return [None,]
            
            all_trees = []
            for i in range(start, end + 1):  # pick up a root
                # all possible left subtrees if i is choosen to be a root
                left_trees = generate_trees(start, i - 1)
                
                # all possible right subtrees if i is choosen to be a root
                right_trees = generate_trees(i + 1, end)
                
                # connect left and right subtrees to the root i
                for l in left_trees:
                    for r in right_trees:
                        current_tree = TreeNode(i)
                        current_tree.left = l
                        current_tree.right = r
                        all_trees.append(current_tree)
            
            return all_trees
        
        return generate_trees(1, n) if n else []
```

