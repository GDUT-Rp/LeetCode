# Leetcode43 字符串相乘

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/multiply-strings



**博主Github**：<https://github.com/GDUT-Rp/LeetCode>

![](https://img-blog.csdnimg.cn/20190716111029424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTczODAzMA==,size_16,color_FFFFFF,t_70)

## 题目：

给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

```
输入: num1 = "2", num2 = "3"
输出: "6"
```

示例 2：

```
输入: num1 = "123", num2 = "456"
输出: "56088"
```


说明：

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理



### 解题思路：



### 方法一：逐个相乘

##### 直观想法

![](https://pic.leetcode-cn.com/41cfd0b1d235e669eeb090ec5eec24560440e4d34ec27c021773b96f5fc6cfac-%E5%9B%BE%E7%89%871.png)

逐个相乘，注意进位。

#### C++:

```c
#include <iostream>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string ans;
        int len1 = num1.size();
        int len2 = num2.size();
        int len = len1 + len2;              //  相乘得到的位数，可能没有这么多，所以没那么多位的最后再删
        if (num1 == "0" or num2 == "0") {    //  有一个为0
            return "0";
        }
        for (int i = 0; i < len; ++i) {     //  先占位
            ans += '0';
        }
        int flag = 0;   //  进位
        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                int tmp = (num1[len1 - 1 - i] - '0') * (num2[len2 - 1 - j] - '0') + flag + ans[i + j] - '0';
                flag = 0;
                if (tmp > 9) {  //  判断进位
                    flag = tmp / 10;
                    tmp %= 10;
                }
                ans[i + j] = '0' + tmp;
            }
            if (flag != 0) {
                ans[i + len2] = flag + '0'; //  在一个循环之后，如果还有进位就直接往前添加
                flag = 0;
            }
        }
        if (ans[len - 1] == '0') {   //  有的时候没有进位就会少一位
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());    //  最后再反转过来
        return ans;
    }
};
```



#### Java:

```java
public class Solution {
    public String multiply(String num1, String num2) {
        //字符串反转
        num1 = new StringBuilder(num1).reverse().toString();
        num2 = new StringBuilder(num2).reverse().toString();
        //两数相乘  最大位数为两者位数之和
        int[] b = new int[num1.length()+num2.length()];

        for (int i = 0;i < num1.length();i++){
            for (int j = 0;j < num2.length();j++){
                //先获取对应位相乘  不考虑进位
                b[i+j] += (num1.charAt(i) - '0') * (num2.charAt(j) - '0');

            }
        }

        for (int i = 0;i<num1.length() + num2.length();i++){
            //对进位进行处理
            if (b[i]>9){
                b[i+1] += b[i]/10;
                b[i] %= 10;
            }
        }

        StringBuilder stringBuilder = new StringBuilder();

        for (int i = num1.length()+num2.length()-1;i>=0;i--){
            stringBuilder.append(b[i]);
        }

        //去除首部的0
        while (stringBuilder.charAt(0) == '0' && stringBuilder.length()>1)  stringBuilder.deleteCharAt(0);

        return stringBuilder.toString();
    }
}
```



#### Python:

```python
class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        if num1 == '0' or num2 == '0':
            return '0'
        ans = 0
        for i, n1 in enumerate(num2[::-1]):
            pre = 0
            curr = 0
            for j, n2 in enumerate(num1[::-1]):
                multi = (ord(n1) - ord('0')) * (ord(n2) - ord('0'))
                first, second = multi // 10, multi % 10
                curr += (second + pre) * (10 ** j) 
                pre = first
            curr += pre * (10 ** len(num1))
            ans += curr * (10 ** i)
        return str(ans)
```

**复杂性分析**

- 时间复杂度： $O(MN)$。数组中的每个元素都需要向左向右扫描。
- 空间复杂度 $O(M+N)$ 的额外空间。 


