# Leetcode38 报数

来源：力扣（LeetCode）
链接：<https://leetcode-cn.com/problems/count-and-say>

## 题目：

报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221
       1 被读作  "one 1"  ("一个一") , 即 11。
       11 被读作 "two 1s" ("两个一"）, 即 21。
       21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。

注意：整数顺序将表示为一个字符串。

示例 1：

```python
输入: 1
输出: "1"
```

**示例 2:**

```python
输入: 4
输出: "1211"
```

### 解题思路：

解答：

这题的关键是读懂题意。如果把整个序列记为a[n]，那么a[n] = a[n - 1]中有几个连续的数字 + 那个数字是什么：

比如：

a[1] = 1；

a[2] = 11 //a[1]中有一个1；

a[3] = 21 //a[2]中有两个1；

a[4] = 1211 //a[3]中有一个2，一个1；

a[5] = 111221 //a[4]中有一个1，一个2，两个1；

由于a[n]只与a[n - 1]有关，代码中并不需要a[n]数组。



### 方法一：逐个对上一个字符串解析

#### C++:

```c++
class Solution {

public:
    string countAndSay(int n) {
        string res = "1";
        string tmp;
        for (int i = 2; i <= n; ++i) {
            tmp = res;
            res = "";
            int m = tmp.length();   //  长度
            int count = 1;  //  计数
            int j = 1;  //  index
            while (j < m) {
                if (tmp[j] == tmp[j - 1]) {
                    count++;    //  两个数相同
                } else {
                    res += to_string(count);    //  答案先加数量
                    res += tmp[j - 1];    //  答案加上什么数
                    count = 1;  //  重置计数
                }
                j++;
            }
            res += to_string(count);
            res += tmp[m - 1];
        }
        return res;
    }
};
```



#### Java:

```java
import java.util.Arrays;

public class Solution {
	 public String countAndSay(int n) {
		 String result="1";
		 for(int i=1;i<n;i++){
			 result=nextCount(result);
		 }
	     return result;
	    }
	 
	 
	 public String nextCount(String s){
		 int length=s.length();
		 StringBuilder a=new StringBuilder();
		 int i=0;
		 int num=0;
		 char prev=' ';
		 char now;
		 while(true){
			 if(prev==' '){//第一次进入循环
				 prev=s.charAt(i);
				 num++;
			 }
			 else{//普通情况
				 now=s.charAt(i);
				 if(now==prev){//这个与上一个相同
					 num++;
				 }
				 else{//这个与上一个不同
					 a.append(num);
					 a.append(prev);//结果插入几个（num)谁（prev)
					 prev=now;
					 num=1;
				 }
			 }
			 i++;
			 if(i==length){//到了最后
				 a.append(num);
				 a.append(prev);
				 break;
			 }
			 
		 }
		 return a.toString();
	 }
}
```



#### Python:

```python
class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        res="1"
        i=1
        while i<n:
            tmp=res
            res=""
            m=len(tmp)
            count=1
            for j in range(1,m):
                if tmp[j]==tmp[j-1]:
                    count+=1
                else:
                    res+=str(count)
                    res+=tmp[j-1]
                    count=1
            res+=str(count)
            res+=tmp[m-1]
            i+=1
        return res
```

##### 





