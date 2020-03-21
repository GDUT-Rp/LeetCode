# Leetcode132 分割回文串Ⅱ

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-partitioning-ii/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

如果有题目或答案还未完整，请期待后续补齐。

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

给定一个字符串 *s*，将 *s* 分割成一些子串，使每个子串都是回文串。

返回符合要求的最少分割次数。



**示例 1:**

```
输入: "aab"
输出: 1
解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
```



### 解题思路：

### 方法一：动态规划

此题动态规划开了一个数组`list`，`list[i]`代表前i个字符需要划分几次，数组长度为`len+1`（`len`为字符串`s`的长度），
初始化为`[-1, 0, 1,..., l]`（规定前`0`个字符需要`-1`次）

然后从`i = range(l)`循环一次，每次以`s[i]`为中心寻找回文子串，当找到从`start`到`end`为回文串时，

设置`list[end+1]=min(list[start]+1, list[end+1])`
如果这是回文串，那么到这里为止的划分次数可以为这个回文串前面所需的次数+1）

比如"ggbobanabob"：

```c
[Initial] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
[Loop 0] { 0, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10} //g
[Loop 1] { 0, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10} //g
[Loop 2] { 0, 0, 1, 3, 4, 5, 6, 7, 8, 9, 10} //b
[Loop 3] { 0, 0, 1, 2, 1, 5, 6, 7, 8, 9, 10} //o
[Loop 4] { 0, 0, 1, 2, 1, 5, 6, 7, 8, 9, 10} //b
[Loop 5] { 0, 0, 1, 2, 1, 2, 6, 7, 8, 9, 10} //a
[Loop 6] { 0, 0, 1, 2, 1, 2, 3, 2, 3, 2, 1} //n
...
```



#### C++

```c
#include <iostream>
#include <vector>
#include <string>
#include <vector>

using namespace std;

class Solution_LeetCode132 {
public:
    int minCut(string s) {
        int len = s.length();
        vector<int> list(len + 1);        //  list[i]代表前i个字符需要划分几次，特别的，list[0] = 1
        for (int i = 0; i < len + 1; ++i) {
            list[i] = i - 1;
        }
        for (int i = 0; i < len; ++i) {
            list[i + 1] = min(list[i + 1], list[i] + 1);    //  初始化，最坏情况下就比左边的多划分一次
            if (i == len - 1) {  //  最后一个了
                break;
            }
            //  回文串有两种，一种偶数个的ABBA，一种奇数个的ABA
            //  先找偶数个的
            int start = i, end = i + 1;
            while (s[start] == s[end]) {                            //  认为start -- end 之间是回文串
                list[end + 1] = min(list[end + 1], list[start] + 1);//  跟新回文串下一位的最少划分次数
                if (end == len - 1 || start == 0) {
                    break;
                }
                --start, ++end;
            }
            //  再找奇数个的
            start = i - 1, end = i + 1;
            if (start < 0){
                continue;
            }
            while (s[start] == s[end]) {                            //  认为start -- end 之间是回文串
                list[end + 1] = min(list[end + 1], list[start] + 1);//  跟新回文串下一位的最少划分次数
                if (end == len - 1 || start == 0) {
                    break;
                }
                --start, ++end;
            }
            //  如果整个串都是回文串，那么就中断
            if (list[len] == 0) {
                return 0;
            }
        }
        return list[len];
    }
};
```



#### Java

```java
class Solution {
    public int minCut(String s) {
        
    }
}
```



#### Python

```python
class Solution:
    def minCut(self, s: str) -> int:
        
```

