[TOC]

# 二叉树

## 题目分类

![二叉树大纲](https://gitee.com/OooAlex/study_note/raw/master/img/202408292211581.png)



## 二叉树的种类

### 满二叉树

![img](https://gitee.com/OooAlex/study_note/raw/master/img/202408292212180.png)

这棵二叉树为满二叉树，也可以说深度为k，有2^k-1个节点的二叉树。

### 完全二叉树

![img](https://gitee.com/OooAlex/study_note/raw/master/img/202408292214892.png)

优先级队列是一个堆，也就是一棵完全二叉树。

### 二叉搜索树（BST)

**二叉搜索树是一个有序树**。

![img](https://gitee.com/OooAlex/study_note/raw/master/img/202408292216087.png)

### 平衡二叉搜索树（AVL树）

性质：是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树。

![image-20240829221755465](https://gitee.com/OooAlex/study_note/raw/master/img/202408292217529.png)

**C++中map、set、multimap，multiset的底层实现都是平衡二叉搜索树**，增删操作时间时间复杂度是log(n).

unordered_map、unordered_set的底层实现是哈希表。



## 二叉树的存储

**二叉树可以链式存储，也可以顺序存储。**

链式存储：
![img](https://gitee.com/OooAlex/study_note/raw/master/img/202408292222172.png)

顺序存储（用数组）：

![img](https://gitee.com/OooAlex/study_note/raw/master/img/202408292222871.png)

**如果父节点的数组下标是 i，那么它的左孩子就是 i \* 2 + 1，右孩子就是 i \* 2 + 2。**



## 二叉树的遍历

- 深度优先遍历
  - 前序遍历（递归法，迭代法）
  - 中序遍历（递归法，迭代法）
  - 后序遍历（递归法，迭代法）
- 广度优先遍历
  - 层次遍历（迭代法）



## 二叉树的定义

### 链式存储的二叉树节点

```
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```



## 二叉树的递归遍历

### 前序遍历

```
class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        vec.push_back(cur->val);    // 中
        traversal(cur->left, vec);  // 左
        traversal(cur->right, vec); // 右
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};
```

### 中序遍历

```
void traversal(TreeNode* cur, vector<int>& vec) {
    if (cur == NULL) return;
    traversal(cur->left, vec);  // 左
    vec.push_back(cur->val);    // 中
    traversal(cur->right, vec); // 右
}
```

### 后序遍历

```
void traversal(TreeNode* cur, vector<int>& vec) {
    if (cur == NULL) return;
    traversal(cur->left, vec);  // 左
    traversal(cur->right, vec); // 右
    vec.push_back(cur->val);    // 中
}
```



## Leetcode144 (easy)、94 (easy)、145 (easy) — 前中后序遍历递归实现

直接放代码，与上文几乎一致。

### TreeNode

```
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
```

### 前序遍历

```
// Using recursion.
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        preorderTraversalHelper(root, result);
        return result;
    }

private:
    void preorderTraversalHelper(TreeNode *cur, vector<int> &result)
    {
        if (cur == NULL)
            return;
        result.push_back(cur->val);
        preorderTraversalHelper(cur->left, result);
        preorderTraversalHelper(cur->right, result);
    }
};
```

### 中序遍历

```
// Using recursion.
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        inorderTraversalHelper(root, result);
        return result;
    }

private:
    void inorderTraversalHelper(TreeNode *cur, vector<int> &result)
    {
        if (cur == NULL)
            return;
        inorderTraversalHelper(cur->left, result);
        result.push_back(cur->val);
        inorderTraversalHelper(cur->right, result);
    }
};
```

### 后序遍历

```
// Using recursion.
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        postorderTraversalHelper(root, result);
        return result;
    }

private:
    void postorderTraversalHelper(TreeNode *cur, vector<int> &result)
    {
        if (cur == NULL)
            return;
        postorderTraversalHelper(cur->left, result);
        postorderTraversalHelper(cur->right, result);
        result.push_back(cur->val);
    }
};
```

很简单，直接秒杀



## 迭代遍历二叉树

### 可行性

> 递归的本质就是用栈空间保存每一次调用函数的参数、局部变量和返回地址，因此也可以直接用栈实现二叉树的前中后序遍历

### 前序遍历

思路：

1. 根节点先入栈。中间节点先出栈，后右孩子入栈，再左孩子入栈，然后重复出栈过程…

2. 空节点不入栈

```
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            // 中
            TreeNode* node = st.top();   
            st.pop();
            result.push_back(node->val);
            // 右（空节点不入栈）
            if (node->right) st.push(node->right);
            // 左（空节点不入栈）
            if (node->left) st.push(node->left);            
        }
        return result;
    }
};
```

### 中序遍历

为什么与前序遍历写法逻辑不一样？

> 中序遍历先访问中间节点，但是先处理左孩子，因此**处理顺序和访问顺序不一致**

思路：

> **先使用指针遍历到要处理的节点（最左侧）**，然后出栈，处理右侧节点

```
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) { // 指针来访问节点，访问到最底层
                st.push(cur); // 将访问的节点放进栈
                cur = cur->left;                // 左
            } else {
                cur = st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
                st.pop();
                result.push_back(cur->val);     // 中
                cur = cur->right;               // 右
            }
        }
        return result;
    }
};
```

### 后序遍历

思路：

> 前序遍历是中左右，调整一下前序遍历代码顺序变成中右左，再reverse result数组，就是左右中，也就是后序遍历

![image-20240830160449287](https://gitee.com/OooAlex/study_note/raw/master/img/202408301604479.png)

```
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->left) st.push(node->left); // 相对于前序遍历，这更改一下入栈顺序 （空节点不入栈）
            if (node->right) st.push(node->right); // 空节点不入栈
        }
        reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
        return result;
    }
};
```

### Leetcode144、94、145 — 前中后序遍历迭代实现

详见上文，此处略过。



## 二叉树的统一迭代法

### 统一思路

使用NULL标记已经访问过但还未处理的元素。也就是访问元素的同时将元素入栈，但是将要处理的元素用NULL标记。

### 中序遍历

思路：

> 首先将中间节点弹出，避免后面加入右中左节点重复操作；
>
> 依次加入右中左节点，加入中间节点后加入NULL标记该节点已被访问但还未处理；
>
> 当栈顶是NULL时，处理NULL下面的节点。

```
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop(); // 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
                if (node->right) st.push(node->right);  // 添加右节点（空节点不入栈）

                st.push(node);                          // 添加中节点
                st.push(NULL); // 中节点访问过，但是还没有处理，加入空节点做为标记。

                if (node->left) st.push(node->left);    // 添加左节点（空节点不入栈）
            } else { // 只有遇到空节点的时候，才将下一个节点放进结果集
                st.pop();           // 将空节点弹出
                node = st.top();    // 重新取出栈中元素
                st.pop();
                result.push_back(node->val); // 加入到结果集
            }
        }
        return result;
    }
};
```

### 前序遍历

仅需要改变右左中节点加入栈的顺序。

```
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();
                if (node->right) st.push(node->right);  // 右
                if (node->left) st.push(node->left);    // 左
                st.push(node);                          // 中
                st.push(NULL);
            } else {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};
```

### 后序遍历

同理，节点加入栈的顺序变为中右左

```
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();
                st.push(node);                          // 中
                st.push(NULL);

                if (node->right) st.push(node->right);  // 右
                if (node->left) st.push(node->left);    // 左

            } else {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};
```

### 注意

无论前中后序，都是中间节点入栈后加入NULL。因为中间节点都是已经访问但还未处理的节点。

