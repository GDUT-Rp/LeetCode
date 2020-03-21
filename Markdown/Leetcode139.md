# Leetcode139 单词拆分

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-break/



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

- 拆分时可以重复使用字典中的单词。
- 你可以假设字典中没有重复的单词。

**示例1**：

```
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
```

##### 示例2：

```
输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
```

**示例3：**

```
输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false
```



### 解题思路：

### 方法一：动态规划

##### 直观想法

本题采用的方法是动态规划，一想到动态规划，就要建立数组dp，然后寻找递推公式。数组dp定为该位置以前的子字符串是否能被拆分。本题的递推公式有些不明显，即需要对子字符串从新进行遍历检查。检查的方式很巧妙，不易想通，在这个地方需要多琢磨琢磨。




#### C++

```c
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution_LeetCode139 {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        if (s.empty()) {
            return false;
        }
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 0; i < s.length(); ++i) {
            for (int j = 0; j <= i; ++j) {
                if (dp[j]) {
                    string tmp = s.substr(j, i - j + 1);
                    if (find(wordDict.begin(), wordDict.end(), tmp) != wordDict.end()) {
                        if (i + 1 < dp.size()) {
                            dp[i + 1] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[s.length()];
    }
};
```



#### C++更简便的写法

```c
bool wordBreak_(string s, vector<string> &wordDict) {

    vector<int> dp(s.size() + 1);
    dp[0] = 1;
    for (int i = 1; i < dp.size(); i++) {
        for (auto word: wordDict) {
            if (i >= word.size() && (s.substr(i - word.size(), word.size()) == word)) {
                dp[i] = dp[i - word.size()] || dp[i];
            }
        }
    }

    return dp.back();
}
```



#### Java

```java
public class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> wordDictSet=new HashSet(wordDict);
        boolean[] dp = new boolean[s.length() + 1];
        dp[0] = true;
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && wordDictSet.contains(s.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
}
```

