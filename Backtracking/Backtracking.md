[toc]



# 回溯算法



## 题目分类

![回溯算法大纲](https://gitee.com/OooAlex/study_note/raw/master/img/202409021558407.png)



## 回溯算法的理论基础

### 回溯法解决的问题

- 组合问题：N个数里面按一定规则找出k个数的集合
- 切割问题：一个字符串按一定规则有几种切割方式
- 子集问题：一个N个数的集合里有多少符合条件的子集
- 排列问题：N个数按一定规则全排列，有几种排列方式
- 棋盘问题：N皇后，解数独等等

### 回溯算法模板框架

```
void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}
```



## Leetcode77(medium) – 组合问题

### 题目

<img src="https://gitee.com/OooAlex/study_note/raw/master/img/202409021611627.png" alt="image-20240902161100551" style="zoom:50%;" />

### My Implementation

#### 思路

<img src="https://gitee.com/OooAlex/study_note/raw/master/img/202409032245104.jpg" alt="ecb4658907259cff5b7868c9a443c43" style="zoom: 50%;" />

<img src="https://gitee.com/OooAlex/study_note/raw/master/img/202409041632393.png" alt="image-20240904163237304" style="zoom:50%;" />

首先定义两个全局变量`vector<vector<int>> result`和`vector<int> path`;

result用于存放最终的结果（所有的组合），path用于存放当前组合（路径）；

在combine函数中定义集合set来存放每个节点代表的集合；

backtracking函数则套用回溯算法模板，详见以下代码部分：

#### 代码

```
// Using Backtracking
class Solution
{
    vector<vector<int>> result;
    vector<int> path;

public:
    vector<vector<int>> combine(int n, int k)
    {
        set<int> set;
        for (int i = 1; i <= n; ++i)
        {
            set.insert(i);
        }
        backtracking(set, k);
        return result;
    }

private:
    void backtracking(set<int> set, int k)
    {
        if (k == 0)    //终止条件
        {
            result.push_back(path);    //存放结果
            return;    //return;
        }

        for (auto it = set.begin(); it != set.end(); ) {    //遍历本节点中的集合元素，也就是遍历并取一个元素放入path,然后进入下一层继续回溯
            //处理节点
            path.push_back(*it);    //将当前遍历到的元素放入path
            it = set.erase(it);    //将当前遍历到的元素从下一层节点的集合中删去

            //递归
            backtracking(set, k - 1);    //继续进入下一层回溯

            //回溯，撤销处理结果
            path.pop_back();    //撤销回溯前的处理，即将放入path的元素弹出
        }
    }
};
```

#### 结果分析

- 时间复杂度: O(n * 2^n)
- 空间复杂度: O(n)

#### 剪枝优化

![77.组合4](https://gitee.com/OooAlex/study_note/raw/master/img/202409081141508.png)

通过画图可以看出剪枝部分

在`backtracking`函数中添加代码：

```
if (set.size() < k) {    //剪枝优化
            return;
        }
```

### 总结

回溯问题套用回溯算法模版，把整个回溯问题看作一棵树

`backtracking`的for循环次数就是节点元素n的个数，也就是每个节点孩子的数量

树的深度就是`backtracking`递归的层数



## Leetcode216(medium) – 组合总和III

### 题目

```
找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：

只使用数字1到9
每个数字 最多使用一次 
返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。

 

示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
解释:
1 + 2 + 4 = 7
没有其他符合的组合了。
示例 2:

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]
解释:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
没有其他符合的组合了。
示例 3:

输入: k = 4, n = 1
输出: []
解释: 不存在有效的组合。
在[1,9]范围内使用4个不同的数字，我们可以得到的最小和是1+2+3+4 = 10，因为10 > 1，没有有效的组合。
 

提示:

2 <= k <= 9
1 <= n <= 60
```

### My Implementation

与Leetcode77题思路几乎一致，此处直接放代码：

```
// Using Backtracking
class Solution
{
    vector<vector<int>> result;
    vector<int> path;

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        set<int> set = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        backtracking(set, k, n);
        return result;
    }

    void backtracking(set<int> set, int k, int n)
    {
        if (k == 0)
        {
            if (n == 0)
            {
                result.push_back(path);
            }
            return;
        }

        if (n <= 0) {
            return;
        }

        for (auto it = set.begin(); it != set.end();)
        {
            int cur = *it;
            path.push_back(*it);
            it = set.erase(it);

            backtracking(set, k - 1, n - cur);

            path.pop_back();
        }
    }
};
```

### 注意

集合set要作为函数参数传递进`backtracking`函数，因为当`backtracking`递归返回时，需要撤销回溯处理结果，使得set回归回溯开始前的状态



## Leetcode17(medium) 电话号码的字母组合

### 题目

<img src="https://gitee.com/OooAlex/study_note/raw/master/img/202409101851531.png" alt="img" style="zoom: 150%;" />

```
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例 1：
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]

示例 2：
输入：digits = ""
输出：[]

示例 3：
输入：digits = "2"
输出：["a","b","c"]
 
提示：
0 <= digits.length <= 4
digits[i] 是范围 ['2', '9'] 的一个数字。
```

### 思路

<img src="https://gitee.com/OooAlex/study_note/raw/master/img/202409111404378.png" alt="17. 电话号码的字母组合" style="zoom:50%;" />

<img src="https://gitee.com/OooAlex/study_note/raw/master/img/202409111404830.jpg" alt="9c977ceaafd5ecf69e3edd754792a60" style="zoom: 50%;" />

假设输入“234”

则第一层遍历’2‘包含的字母`"abc"`, 第二层遍历‘3’包含的字母`“def”`，第三层遍历'4'包含的字母`"ghi"`

树的深度就是数字的个数，树的宽度是每一个数字对应的字母数量

* 如何映射数字和字母？

> 第一种：使用一个字符串数字，下标表示数字，下标对应的字符串表示字母

```
const string letterMap[10] = {
    "", // 0
    "", // 1
    "abc", // 2
    "def", // 3
    "ghi", // 4
    "jkl", // 5
    "mno", // 6
    "pqrs", // 7
    "tuv", // 8
    "wxyz", // 9
};
```

> 第二种(My choice)：使用一个map，其中key是数字，value是字母，详见代码

### My Implementation

在处理当前节点时，获取当前节点包含的第一个数字对应的字符串，然后for循环遍历该字符串

如何获取当前节点包含的第一个数字对应的字符串？

> 使用map的find函数找到数字(key)对应的字符串(value)
>
> ```
> string letters = teleMap.find(digits[0])->second;
> ```
>
> 注意：map interface的find method返回值是指向元素的迭代器，如果需要获取元素的key或value则需要用`->first/second`指向它

```
class Solution
{
    vector<string> result;
    string path;
    map<char, string> teleMap;

public:
    vector<string> letterCombinations(string digits)
    {
        teleMap.insert(make_pair('2', "abc"));
        teleMap.insert(make_pair('3', "def"));
        teleMap.insert(make_pair('4', "ghi"));
        teleMap.insert(make_pair('5', "jkl"));
        teleMap.insert(make_pair('6', "mno"));
        teleMap.insert(make_pair('7', "pqrs"));
        teleMap.insert(make_pair('8', "tuv"));
        teleMap.insert(make_pair('9', "wxyz"));

        if (digits.empty())
        {
            return result;
        }
        backtracking(digits);
        return result;
    }

    void backtracking(string digits)
    {
        if (digits.empty())
        {
            result.push_back(path);
            return;
        }

        string letters = teleMap.find(digits[0])->second;
        for (char letter : letters)
        {
            path.push_back(letter);
            char tmp = digits[0];
            digits.erase(0, 1);

            backtracking(digits);

            digits = tmp + digits;
            path.pop_back();
        }
    }
};
```

### 注意

1. for循环遍历的不是整个节点，而是遍历该节点的第一个数字对应的字符串

2. string的erase函数用法：`.erase(起始位置, 删除的数量)`

   e.g. `digits.erase(0, 1)`表示从字符串digits的第1个字符开始移除1个字符

