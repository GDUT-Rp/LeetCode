# Leetcode36 有效的数独

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-sudoku

## 题目：

- 判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

  数字 1-9 在每一行只能出现一次。
  数字 1-9 在每一列只能出现一次。
  数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

  ![部分填充的有效数独](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)

- 数独部分空格内已填入了数字，空白格用 `'.'` 表示。

  示例 1：

  ```python
  输入:
  [
    ["5","3",".",".","7",".",".",".","."],
    ["6",".",".","1","9","5",".",".","."],
    [".","9","8",".",".",".",".","6","."],
    ["8",".",".",".","6",".",".",".","3"],
    ["4",".",".","8",".","3",".",".","1"],
    ["7",".",".",".","2",".",".",".","6"],
    [".","6",".",".",".",".","2","8","."],
    [".",".",".","4","1","9",".",".","5"],
    [".",".",".",".","8",".",".","7","9"]
  ]
  输出: true
  ```

  

  示例 2：

  ```python
  输入:
  [
    ["8","3",".",".","7",".",".",".","."],
    ["6",".",".","1","9","5",".",".","."],
    [".","9","8",".",".",".",".","6","."],
    ["8",".",".",".","6",".",".",".","3"],
    ["4",".",".","8",".","3",".",".","1"],
    ["7",".",".",".","2",".",".",".","6"],
    [".","6",".",".",".",".","2","8","."],
    [".",".",".","4","1","9",".",".","5"],
    [".",".",".",".","8",".",".","7","9"]
  ]
  输出: false
  解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
       但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。
  ```

说明:

一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可。
给定数独序列只包含数字 1-9 和字符 '.' 。
给定数独永远是 9x9 形式的。



### 解题思路：

一个简单的解决方案是遍历该 9 x 9 数独 三 次，以确保：

行中没有重复的数字。
列中没有重复的数字。
3 x 3 子数独内没有重复的数字。
实际上，所有这一切都可以在一次迭代中完成。



### 方法一：

 首先，让我们来讨论下面两个问题：

- 如何枚举子数独？

> 可以使用 `box_index = (row / 3) * 3 + columns / 3`，其中 `/` 是整数除法。

![整除](https://pic.leetcode-cn.com/2b141392e2a1811d0e8dfdf6279b1352e59fad0b3961908c6ff9412b6a7e7ccf-image.png)

如何确保行 / 列 / 子数独中没有重复项？
可以利用 value -> count 哈希映射来跟踪所有已经遇到的值。

现在，我们完成了这个算法的所有准备工作：

遍历数独。
检查看到每个单元格值是否已经在当前的行 / 列 / 子数独中出现过：
如果出现重复，返回 false。
如果没有，则保留此值以进行进一步跟踪。
返回 true。

![](https://pic.leetcode-cn.com/Figures/36/36_slide_2.png)

**复杂度分析**

- 时间复杂度：*O*(1)，因为我们只对 `81` 个单元格进行了一次迭代。
- 空间复杂度：*O*(1)。



#### C++:

```c++
// 采用哈希表极简
bool isValid(vector<vector<char>> &board) {
    vector<unordered_map<int, int>> row(9), col(9), block(9);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int bindex = (i / 3) * 3 + j / 3;
            char cur = board[i][j];
            if (cur == '.') continue;
            if (row[i].count(cur) || col[j].count(cur) || block[bindex].count(cur)) return false;
            row[i][cur] = 1;
            col[j][cur] = 1;
            block[bindex][cur] = 1;
        }
    }
    return true;
}
```



#### Java:

```java
class Solution {
  public boolean isValidSudoku(char[][] board) {
    // init data
    HashMap<Integer, Integer> [] rows = new HashMap[9];
    HashMap<Integer, Integer> [] columns = new HashMap[9];
    HashMap<Integer, Integer> [] boxes = new HashMap[9];
    for (int i = 0; i < 9; i++) {
      rows[i] = new HashMap<Integer, Integer>();
      columns[i] = new HashMap<Integer, Integer>();
      boxes[i] = new HashMap<Integer, Integer>();
    }

    // validate a board
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        char num = board[i][j];
        if (num != '.') {
          int n = (int)num;
          int box_index = (i / 3 ) * 3 + j / 3;

          // keep the current cell value
          rows[i].put(n, rows[i].getOrDefault(n, 0) + 1);
          columns[j].put(n, columns[j].getOrDefault(n, 0) + 1);
          boxes[box_index].put(n, boxes[box_index].getOrDefault(n, 0) + 1);

          // check if this value has been already seen before
          if (rows[i].get(n) > 1 || columns[j].get(n) > 1 || boxes[box_index].get(n) > 1)
            return false;
        }
      }
    }

    return true;
  }
}
```



#### Python:

```python
class Solution:
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        # init data
        rows = [{} for i in range(9)]
        columns = [{} for i in range(9)]
        boxes = [{} for i in range(9)]

        # validate a board
        for i in range(9):
            for j in range(9):
                num = board[i][j]
                if num != '.':
                    num = int(num)
                    box_index = (i // 3 ) * 3 + j // 3
                    
                    # keep the current cell value
                    rows[i][num] = rows[i].get(num, 0) + 1
                    columns[j][num] = columns[j].get(num, 0) + 1
                    boxes[box_index][num] = boxes[box_index].get(num, 0) + 1
                    
                    # check if this value has been already seen before
                    if rows[i][num] > 1 or columns[j][num] > 1 or boxes[box_index][num] > 1:
                        return False         
        return True
```



### 方法二：

1、将问题分解，就像我们人判断一样，要判断每一行是否有效，每一列是否有效，还判断每一个九宫格是否满足。

所以将问题划分成三个类型的判断，分别用三个子程序来判断。主程序只负责确定 要判断哪一行，哪一列，哪个格子。

判断格子的时候，以左上角为基准点。

2、通过一个vector来判断是否有效。如果是空，那么就不管，如果不是空，那么存入vector,单下一个非空元素来时，和vector中所有元素比较，如果相等，那么说明无效，否则有效。

3、虽然题目中给的是双引号表示的，当时毕竟是char类型。个人认为，最终程序中还是用的单引号，题目中给出的应该只是表达这道题的一个写法。我自己又在程序中试了试，和当初刚学C的时候一样，char就是要用单引号，用双引号各种错误。



##### C++

```c++
class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        int len = 9;
        for (int i = 0; i < len; ++i) {
            if (isRowVaild(i, board) == false or isColumnValid(i, board) == false)
                return false;
        }
        for (int i = 0; i < len; i+=3) {
            for (int j = 0; j < len; j+=3) {
                if (isNineValid(i, j, board) == false)
                    return false;
            }
        }
        return true;
    }

    // 判断每一行是否有效
    bool isRowVaild(int row, vector<vector<char>> &board) {
        vector<char> temp;
        for (int i = 0; i < board[0].size(); ++i) {
            if ('.' == board[row][i])
                continue;
            temp.push_back(board[row][i]);
            for (int j = 0; j < temp.size() - 1; ++j) { // 注意减一，因为最后一个就是检查的这个元素
                if (temp[j] == board[row][i])
                    return false;
            }
        }
        return true;
    }

    // 判断每一列是否有效
    bool isColumnValid(int column, vector<vector<char>> &board) {
        vector<char> temp;
        for (int i = 0; i < board[0].size(); ++i) {
            if (board[i][column] == '.')
                continue;
            temp.push_back(board[i][column]);
            for (int j = 0; j < temp.size() - 1; ++j) {
                if (temp[j] == board[i][column])
                    return false;
            }
        }
        return true;
    }

    // 判断单独一个九宫格是否有效
    bool isNineValid(int row, int column, vector<vector<char>> &board) {
        vector<char> temp;
        for (int i = row; i < row + 3; ++i) {
            for (int j = column; j < column + 3; ++j) {
                if (board[i][j] == '.')
                    continue;
                temp.push_back(board[i][j]);
                for (int k = 0; k < temp.size() - 1; ++k) {
                    if (temp[k] == board[i][j])
                        return false;
                }
            }
        }
        return true;
    }
};
```




