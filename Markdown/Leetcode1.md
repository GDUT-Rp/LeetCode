# Leetcode1

## 1. 两数之和

给定一个整数数组和一个目标值，找出数组中和为目标值的**两个**数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

#### **示例:**

```
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
```

#### 自己代码

思路：暴力解题，时间复杂度O（n²），空间复杂度O（1）

##### Java

```java
public int[] twoSum(int[] nums, int target) {
    for (int i = 0; i < nums.length; i++) {
        for (int j = i + 1; j < nums.length; j++) {
            if (nums[j] == target - nums[i]) {
                return new int[] { i, j };
            }
        }
    }
    throw new IllegalArgumentException("No two sum solution");
}
// 24ms，战胜50%
```

##### Python

```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for index, elem in enumerate(nums):
            for jndex, jelem in enumerate(nums):
                if index == jndex:
                    continue
                elif elem + jelem == target:
                    return[index,jndex]
        return
# 6744ms，战胜5%
```

##### C

```c
int* twoSum(int* nums, int numsSize, int target){
    int i, j;
    int* ans;
    ans = (int *)malloc(sizeof(int) * 2);
    if(ans == NULL){
        printf("malloc happen error!\n");
        return;
    }
    for(i = 0; i < numsSize; i++){
        for(j = i + 1; j < numsSize; j++){
            if((nums[i] + nums[j]) == target){
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
        }
    }
    return;
}
// 84ms，战胜77%
```



#### 方法二：两遍哈希表

思路：对于运行时间复杂度进行优化，我们可以通过哈希表来保持数组中每个元素与其索引相互对应。通过空间换取时间的方式，我们可以将查找时间从O（n）降低到O（1）。因为哈希表支持以近似恒定的时间进行快速查找。“近似”是因为一旦出现冲突，查找用时可能会退化到O（n）。通过第一次迭代，把<nums[i],i>放到Map里面去，然后第二次迭代进行遍历判断是否有符合的值。

##### Java

```java
public int[] twoSum(int[] nums, int target) {
    Map<Integer, Integer> map = new HashMap<>();
    for (int i = 0; i < nums.length; i++) {
        map.put(nums[i], i);
    }
    for (int i = 0; i < nums.length; i++) {
        int complement = target - nums[i];
        if (map.containsKey(complement) && map.get(complement) != i) 		 {
            return new int[] { i, map.get(complement) };
        }
    }
    throw new IllegalArgumentException("No two sum solution");
}
// 11ms, 战胜63%
```

##### Python

```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        adict = {}
        for index, elem in enumerate(nums):
            adict[elem] = index
        for index, elem in enumerate(nums):
            complement = target - elem
            if complement in adict and index != adict[complement]:
                return [index, adict[complement]]
        return
# 28ms，战胜98%
```



#### 方法三：一遍哈希表

思路：进行一次迭代，一边加入<nums[i],i>放到Map里面去，一边进行判断是否有存在的对应解。

##### Java

```java
public int[] twoSum(int[] nums, int target) {
    Map<Integer, Integer> map = new HashMap<>();
    for (int i = 0; i < nums.length; i++) {
        int complement = target - nums[i];
        if (map.containsKey(complement)) {
            return new int[] { map.get(complement), i };
        }
        map.put(nums[i], i);
    }
    throw new IllegalArgumentException("No two sum solution");
}
// 7ms,战胜96%
```

##### Python

```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        adict = {}
        for index, elem in enumerate(nums):
            complement = target - elem
            if complement in adict and index != adict[complement]:
                return [adict[complement], index]
            adict[elem] = index
        return
# 24ms,战胜99.9%
```



##### C

```C
#define SIZE 100000

int hash(int key) {
   int r = key % SIZE;
   return r < 0 ? r + SIZE : r;
}

void insert(int *keys, int *values, int key, int value) {
    int index = hash(key);
    while (values[index]) {
        index++;
		index %= SIZE;
    }
    keys[index] = key;
    values[index] = value;
}

int search(int *keys, int *values, int key) {
    int index = hash(key);
    while (values[index]) {
        if (keys[index] == key) {
            return values[index];
        }
        index++;
        index %= SIZE;
    }
    return 0;
}

int* twoSum(int* nums, int numsSize, int target) {
    int keys[SIZE];
    int values[SIZE] = {0};
    for (int i = 0; i < numsSize; i++) {
        int complements = target - nums[i];
        int index = search(keys, values, complements);
        if (index) {
            int *indices = (int *) malloc(sizeof(int) * 2);
            indices[0] = --index;
            indices[1] = i;
            return indices;
        }
        insert(keys, values, nums[i], i + 1);
    }
    return NULL;
}
// 4ms,战胜99%
```

##### C

```c
struct my_struct {
  int val; /* key */
  int location;
  UT_hash_handle hh; /* makes this structure hashable */
};
struct my_struct *numHash = NULL;

void add_num(int num, int location) {
  struct my_struct *s;

  HASH_FIND_INT(numHash, &num, s); /* id already in the hash? */
  if (s == NULL) {
    s = (struct my_struct *)malloc(sizeof *s);
    s->val = num;
    HASH_ADD_INT(numHash, val, s); /* id: name of key field */
  }
  s->location = location;
}

void delete_all() {
  struct my_struct *current_item, *tmp;

  HASH_ITER(hh, numHash, current_item, tmp) {
    HASH_DEL(numHash, current_item); /* delete it (users advances to next) */
    free(current_item);              /* free it */
  }
}

int find_num(int id) {

  struct my_struct *s;

  HASH_FIND_INT(numHash, &id, s); /* s: output pointer */
  if (s)
    return s->location;
  else
    return -1;
}

void print_hash() {
  struct my_struct *s;

  for (s = numHash; s != NULL; s = (struct my_struct *)(s->hh.next)) {
    printf("user id %d: name %d\n", s->val, s->location);
  }
}

int *twoSum(int *nums, int numsSize, int target) {
  int i;

  int *res = (int *)malloc(2 * sizeof(int));

  for (i = 0; i < numsSize; i++) {
    int diff = target - nums[i];
    int pos = find_num(diff);

    if (pos >= 0) {
      res[0] = pos;
      res[1] = i;
      delete_all();
      return res;
    }
    add_num(nums[i], i);
    // print_hash();
  }
  free(res);
  delete_all();
  return NULL;
}
```

