# Leetcode37 解数独

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-sudoku

## 题目：

- 编写一个程序，通过已填充的空格来解决数独问题。

  一个数独的解法需遵循如下规则：

  数字 1-9 在每一行只能出现一次。
  数字 1-9 在每一列只能出现一次。
  数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
  空白格用 '.' 表示。

![部分填充的有效数独](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)

![图解](http://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png)

- 答案被标成红色。

  **Note:**

  - 给定的数独序列只包含数字 `1-9` 和字符 `'.'` 。
  - 你可以假设给定的数独只有唯一解。
  - 给定数独永远是 `9x9` 形式的。

- 

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
  输出: 
      [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
  ```

  


### 解题思路：

### 方法 0：蛮力法

首先的想法是通过蛮力法来生成所有可能用1 到 9填充空白格的解， 并且检查合法从而保留解。这意味着共有 9^{81}9 
81
  个操作需要进行。 其中 99 是可行的数字个数，8181 是需要填充的格子数目。 因此我们必须考虑进一步优化。 



### 方法一：回溯法

 首先，让我们来讨论下面两个问题：

- 如何枚举子数独？

> 可以使用 `box_index = (row / 3) * 3 + columns / 3`，其中 `/` 是整数除法。

![整除](https://pic.leetcode-cn.com/2b141392e2a1811d0e8dfdf6279b1352e59fad0b3961908c6ff9412b6a7e7ccf-image.png)

使用的概念

了解两个编程概念会对接下来的分析有帮助。

第一个叫做 约束编程。

基本的意思是在放置每个数字时都设置约束。在数独上放置一个数字后立即 排除当前 行， 列 和 子方块 对该数字的使用。这会传播 约束条件 并有利于减少需要考虑组合的个数。

![](https://pic.leetcode-cn.com/ce5d93149307f8c4b5e3bf5d0924985f39721905ccc6537cbdf92030ad79b789-image.png)

第二个叫做 回溯。

让我们想象一下已经成功放置了几个数字 在数独上。 但是该组合不是最优的并且不能继续放置数字了。该怎么办？ 回溯。 意思是回退，来改变之前放置的数字并且继续尝试。如果还是不行，再次 回溯。

![](https://pic.leetcode-cn.com/575afd37ae93cd906adc1cd46e939bfc951af5aa1fe411c693d09ce5140f8822-image.png)

#### 算法

现在准备好写回溯函数了 backtrack(row = 0, col = 0)。

​	从最左上角的方格开始 row = 0, col = 0。直到到达一个空方格。

​	从1 到 9 迭代循环数组，尝试放置数字 d 进入 (row, col) 的格子。

​		如果数字 d 还没有出现在当前行，列和子方块中：

​			将 d 放入 (row, col) 格子中。
​			记录下 d 已经出现在当前行，列和子方块中。
​			如果这是最后一个格子row == 8, col == 8 ：
​				意味着已经找出了数独的解。
​			否则
​				放置接下来的数字。
​			如果数独的解还没找到： 将最后的数从 (row, col) 移除。

#### C++:

```c++
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution_LeetCode37 {
public:
    void solveSudoku(vector<vector<char>> &board) {
        suDu(board, 0, 0);
    }

private:
    bool suDu(vector<vector<char>> &board, int i, int j) {
        if (i == 8 && j == 9) return true;    // 到达终点的下一个点
        if (j == 9) {    // 到了每行的末尾的下一个点
            i++;
            j = 0;
        }
        if (board[i][j] != '.') {
            if (suDu(board, i, j + 1)) {
                return true;
            }
        } else {
            int *map = getValidNum(board, i, j);
            for (int k = 1; k < 10; ++k) {
                if (map[k] == 0) {
                    board[i][j] = k + '0';
                    if (suDu(board, i, j + 1)) {
                        return true;
                    }
                    board[i][j] = '.';
                }
            }
        }
        return false;
    }

    int *getValidNum(vector<vector<char>> &board, int i, int j) {
        int *map = (int *) malloc(sizeof(int) * 10);
        memset(map, 0, sizeof(int) * 10);   //  初始化0
        for (int k = 0; k < 9; ++k) {
            if (board[i][k] != '.') {       //  对第i行进行标记已有什么数字
                map[board[i][k] - '0'] = 1;
            }
            if (board[k][j] != '.') {       //  对第j行进行标记已有什么数字
                map[board[k][j] - '0'] = 1;
            }
        }
        //  每个对9宫格的小块标记已有什么数字
        for (int k = 3 * (i / 3); k < 3 * (i / 3) + 3; ++k) {
            for (int l = 3 * (j / 3); l < 3 * (j / 3) + 3; ++l) {
                if (board[k][l] != '.') {
                    map[board[k][l] - '0'] = 1;
                }
            }
        }
        //  返回map，存放这个Int数组，这个（i, j）能有什么数字，1表示已经有这个数了
        return map;
    }
};
```



#### Java:

```java
class Solution {
  // box size
  int n = 3;
  // row size
  int N = n * n;

  int [][] rows = new int[N][N + 1];
  int [][] columns = new int[N][N + 1];
  int [][] boxes = new int[N][N + 1];

  char[][] board;

  boolean sudokuSolved = false;

  public boolean couldPlace(int d, int row, int col) {
    /*
    Check if one could place a number d in (row, col) cell
    */
    int idx = (row / n ) * n + col / n;
    return rows[row][d] + columns[col][d] + boxes[idx][d] == 0;
  }

  public void placeNumber(int d, int row, int col) {
    /*
    Place a number d in (row, col) cell
    */
    int idx = (row / n ) * n + col / n;

    rows[row][d]++;
    columns[col][d]++;
    boxes[idx][d]++;
    board[row][col] = (char)(d + '0');
  }

  public void removeNumber(int d, int row, int col) {
    /*
    Remove a number which didn't lead to a solution
    */
    int idx = (row / n ) * n + col / n;
    rows[row][d]--;
    columns[col][d]--;
    boxes[idx][d]--;
    board[row][col] = '.';
  }

  public void placeNextNumbers(int row, int col) {
    /*
    Call backtrack function in recursion
    to continue to place numbers
    till the moment we have a solution
    */
    // if we're in the last cell
    // that means we have the solution
    if ((col == N - 1) && (row == N - 1)) {
      sudokuSolved = true;
    }
    // if not yet
    else {
      // if we're in the end of the row
      // go to the next row
      if (col == N - 1) backtrack(row + 1, 0);
        // go to the next column
      else backtrack(row, col + 1);
    }
  }

  public void backtrack(int row, int col) {
    /*
    Backtracking
    */
    // if the cell is empty
    if (board[row][col] == '.') {
      // iterate over all numbers from 1 to 9
      for (int d = 1; d < 10; d++) {
        if (couldPlace(d, row, col)) {
          placeNumber(d, row, col);
          placeNextNumbers(row, col);
          // if sudoku is solved, there is no need to backtrack
          // since the single unique solution is promised
          if (!sudokuSolved) removeNumber(d, row, col);
        }
      }
    }
    else placeNextNumbers(row, col);
  }

  public void solveSudoku(char[][] board) {
    this.board = board;

    // init rows, columns and boxes
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        char num = board[i][j];
        if (num != '.') {
          int d = Character.getNumericValue(num);
          placeNumber(d, i, j);
        }
      }
    }
    backtrack(0, 0);
  }
}
```



#### Python:

```python
from collections import defaultdict
class Solution:
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        def could_place(d, row, col):
            """
            Check if one could place a number d in (row, col) cell
            """
            return not (d in rows[row] or d in columns[col] or \
                    d in boxes[box_index(row, col)])
        
        def place_number(d, row, col):
            """
            Place a number d in (row, col) cell
            """
            rows[row][d] += 1
            columns[col][d] += 1
            boxes[box_index(row, col)][d] += 1
            board[row][col] = str(d)
            
        def remove_number(d, row, col):
            """
            Remove a number which didn't lead 
            to a solution
            """
            del rows[row][d]
            del columns[col][d]
            del boxes[box_index(row, col)][d]
            board[row][col] = '.'    
            
        def place_next_numbers(row, col):
            """
            Call backtrack function in recursion
            to continue to place numbers
            till the moment we have a solution
            """
            # if we're in the last cell
            # that means we have the solution
            if col == N - 1 and row == N - 1:
                nonlocal sudoku_solved
                sudoku_solved = True
            #if not yet    
            else:
                # if we're in the end of the row
                # go to the next row
                if col == N - 1:
                    backtrack(row + 1, 0)
                # go to the next column
                else:
                    backtrack(row, col + 1)
                
                
        def backtrack(row = 0, col = 0):
            """
            Backtracking
            """
            # if the cell is empty
            if board[row][col] == '.':
                # iterate over all numbers from 1 to 9
                for d in range(1, 10):
                    if could_place(d, row, col):
                        place_number(d, row, col)
                        place_next_numbers(row, col)
                        # if sudoku is solved, there is no need to backtrack
                        # since the single unique solution is promised
                        if not sudoku_solved:
                            remove_number(d, row, col)
            else:
                place_next_numbers(row, col)
                    
        # box size
        n = 3
        # row size
        N = n * n
        # lambda function to compute box index
        box_index = lambda row, col: (row // n ) * n + col // n
        
        # init rows, columns and boxes
        rows = [defaultdict(int) for i in range(N)]
        columns = [defaultdict(int) for i in range(N)]
        boxes = [defaultdict(int) for i in range(N)]
        for i in range(N):
            for j in range(N):
                if board[i][j] != '.': 
                    d = int(board[i][j])
                    place_number(d, i, j)
        
        sudoku_solved = False
        backtrack()
```

##### 复杂性分析

这里的时间复杂性是常数由于数独的大小是固定的，因此没有 N 变量来衡量。 但是我们可以计算需要操作的次数：$(9!)^9$。我们考虑一行，即不多于 $9$ 个格子需要填。 第一个格子的数字不会多于$9$ 种情况， 两个格子不会多于 $9 \times 8$ 种情况， 三个格子不会多于 $9 \times 8 \times 7$ 种情况等等。 总之一行可能的情况不会多于 $9!$ 种可能， 所有行不会多于$ (9!)^9$种情况。比较一下：

$9^{81}
  = 196627050475552913618075908526912116283103450944214766927315415537966391196809 $为蛮力法，
而 $(9!)^{9}
  = 109110688415571316480344899355894085582848000000000$为回溯法， 即数字的操作次数减少了 $10^{27}$倍！
空间复杂性：数独大小固定，空间用来存储数独，行，列和子方块的结构，每个有 $81$ 个元素。



