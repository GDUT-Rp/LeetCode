# Leetcode415 字符串相加

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-strings



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

给定两个字符串形式的非负整数 `num1` 和`num2` ，计算它们的和。

示例 1:

```
输入: num1 = "2", num2 = "3"
输出: "5"
```

示例 2：

```
输入: num1 = "123", num2 = "456"
输出: "579"
```

注意：

1. num1 和num2 的长度都小于 5100.
2. num1 和num2 都只包含数字 0-9.
3. num1 和num2 都不包含任何前导零。
4. 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。



### 解题思路：



### 方法一：逐个相加

##### 直观想法

从最后一位开始逐个相加，注意判断是否有进位。



#### C++:

```c
#include <iostream>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int index = 0;
        int len = min(len1, len2);
        int flag = 0;   //  进位
        string ans;
        int num;        //  存放加起来的值（包括进位）
        int max_len = max(len1, len2);

        while (index < max_len) {   //  从最后一位开始加
            if (index < len) {      //  两个相加
                num = num1[len1 - 1 - index] - '0' + num2[len2 - 1 - index] - '0' + flag;
            } else if (index < len1) {      //  num1更长一点
                num = num1[len1 - 1 - index] - '0' + flag;
            } else {                        //  num2更长一点
                num = num2[len2 - 1 - index] - '0' + flag;
            }

            flag = 0;   //  加完进位后赋值为0
            if (num <= 9) {
                ans += to_string(num);
            } else {    //  有进位
                flag = 1;
                ans += to_string(num - 10);
            }
            index++;
        }

        if (flag) {     //  最后仍有进位
            ans += "1";
        }

        reverse(ans.begin(), ans.end());    //  字符串翻转
        return ans;
    }
};
```



#### Java:

```java
class Solution {
    public String addStrings(String num1, String num2) {
        StringBuilder str = new StringBuilder();
        int i = num1.length()-1;
        int j = num2.length()-1;
        int carry = 0;
        while(i>=0 && j>=0) {
            int res = num1.charAt(i)-'0' + num2.charAt(j)-'0' + carry;
            if(res>=10) carry = 1;
            else carry = 0;
            res = res%10;
            str.append(res);
            i--;
            j--;
        }
        while(j>=0) {
            int res = num2.charAt(j)-'0' + carry;
            if(res>=10) carry = 1;
            else carry = 0;
            res = res%10;
            str.append( res );
            j--;
        }
        while(i>=0) {
            int res = num1.charAt(i)-'0' + carry;
            if(res>=10) carry = 1;
            else carry = 0;
            res = res%10;
            str.append( res );
            i--;
        }
        if(carry == 1) str.append("1");
        return  str.reverse().toString();
    }
}
```



#### Python:

```python
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        
```

**复杂性分析**

- 时间复杂度：$O(n)$。数组中的每个元素都需要向左向右扫描。
- 空间复杂度：$O(1)$ 的额外空间。 


