# Leetcode87 扰乱字符串

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/scramble-string/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

给定一个字符串 *s1*，我们可以把它递归地分割成两个非空子字符串，从而将其表示为二叉树。

下图是字符串 *s1* = `"great"` 的一种可能的表示形式。

```
    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
```

在扰乱这个字符串的过程中，我们可以挑选任何一个非叶节点，然后交换它的两个子节点。

例如，如果我们挑选非叶节点 "gr" ，交换它的两个子节点，将会产生扰乱字符串 "rgeat" 。

```
    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
```

我们将 "rgeat” 称作 "great" 的一个扰乱字符串。

同样地，如果我们继续交换节点 "eat" 和 "at" 的子节点，将会产生另一个新的扰乱字符串 "rgtae" 。

```
    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
```

我们将 `"rgtae”` 称作 `"great"` 的一个扰乱字符串。

给出两个长度相等的字符串 *s1* 和 *s2*，判断 *s2* 是否是 *s1* 的扰乱字符串。



**示例 1:**

```
输入: s1 = "great", s2 = "rgeat"
输出: true
```



**示例 2:**

```
输入: s1 = "abcde", s2 = "caebd"
输出: false
```



### 解题思路：

### 方法一：递归判断

##### 直观想法

【分析】

 题意在于判断一个字符串是否为另一个字符串“乱序”得到，这种乱序采用的方式是将一个字符串从某个位置“割开”，形成两个子串，然后对两个子串进行同样的“割开”操作，直到到达叶子节点，无法再分割。然后对非叶子节点的左右孩子节点进行交换，最后重新从左至右组合形成新的字符串，由于这个过程中存在字符位置的变化，因此，原来的字符串顺序可能会被打乱，当然也可能没有（同一个非叶子节点的左右孩子交换0次或偶数次，就无变化）。需要注意的点：

1、原字符串每次被割开的位置并不确定可能为[1,s.size()-1]，所以必然需要遍历所有可能割开的位置；

2、原字符串从第i个位置被割开（i在区间[1,s.size()-1]），形成的两个子串s.substr(0,i)和s.substr(i,s.size()-i)，如果这两个子串不全为空，则它们的母串（这里指原字符串）就是所谓的非叶子节点，这两个子串可以左右交换（按照二叉树的展开方式）；对于两个子串，可继续割裂，直到形成叶子节点。

3、可以想见，原字符串对应的“乱序”串s1，定然满足如下规律：如果将“乱序”串同样从第i个位置割开，他同样可以形成两个子串，s1.substr(0,i)和s1.substr(i,s1.size()-i)，并且满足：

  s1.substr(0,i)是s.substr(0,i)的“乱序”且s1.substr(i,s1.size()-i)是s.substr(i,s.size()-i)的“”乱序

   或者（因为左右交换的原因）

  s1.substr(0,i)是s.substr(s.size()-i)的“乱序”且s1.substr(i)是s.substr(0,s.size()-i)的“乱序”

4、如上分析，我们就可以将大问题分解成小问题，通过递归调用，便可以判断两个字符串是否互为“乱序”，还需注意一个问题就是“剪枝”操作，二叉树形式分解，层次很深，每一层都应满足（3）中的两种可能之一，如果不满足便不再继续下一层，直接返回false，这便是一种剪枝操作，可以极大的提升效率。

5、“剪枝”约束，若两个字符串s1和s2互为“乱序”，需满足s1和s2包含的字符及数量应完全相同，如果不同，则不可能构成“乱序”，因此这个条件可作为剪枝条件；

6、两个工具：判断两个字符串是否包含完全相同的字母，用到了“哈希表”；割裂形成子串用到STL函数：substr(i,n);表示获得字符串从第i个位置开始的n个字符，如果n空缺，默认为到字符串末尾。



#### C++

```c
class Solution {
public:
    bool isScramble(string s1, string s2) {
        
        if(s1.size()!=s2.size())return false;
        if(s1==s2)return true;
        vector<int> hash(26,0);
        
        for(int i=0;i<s1.size();i++)
        hash.at(s1[i]-'a')++;
        
        for(int j=0;j<s2.size();j++)
        hash.at(s2[j]-'a')--;
        
        for(int k=0;k<26;k++)
        {
            if(hash.at(k)!=0)
            return false;
        }
        
        for(int i=1;i<s1.size();i++)
        {
            if(
                (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i,s1.size()-i), s2.substr(i,s1.size()-i)))
             || (isScramble(s1.substr(0, i), s2.substr(s1.size()-i)) && isScramble(s1.substr(i), s2.substr(0, s1.size()-i)))
              )
                return true;
 
        }
        return false;
    }
};
```


