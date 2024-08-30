# LinkedList

## 链表的类型

链表的入口节点称为链表的头结点也就是head。

### 单链表

![image-20240829145923372](https://gitee.com/OooAlex/study_note/raw/master/img/202408291459545.png)

### 双链表

![image-20240829145956936](https://gitee.com/OooAlex/study_note/raw/master/img/202408291459969.png)

### 循环链表

![image-20240829150017974](https://gitee.com/OooAlex/study_note/raw/master/img/202408291500022.png)



## 链表的定义

### 链表节点

```
// 单链表
struct ListNode {
    int val;  // 节点上存储的元素
    ListNode *next;  // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
};
```

如果不定义构造函数，则不能在初始化时给变量赋值。



## Leetcode203.移除链表元素

### 题目

![image-20240829163119224](https://gitee.com/OooAlex/study_note/raw/master/img/202408291631305.png)

### 我的解法

```
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *sentinel = new ListNode(0, head);
        ListNode *new_head = nullptr;
        bool newHeadExist = false;
        while (sentinel->next != nullptr)
        {
            if (sentinel->next->val == val)
            {
                sentinel->next = sentinel->next->next;
                continue;
            }
            else if (!newHeadExist)
            {
                new_head = sentinel->next;
                newHeadExist = true;
            }
            sentinel = sentinel->next;
        }
        return new_head;
    }
};
```

### 复杂度

![image-20240829170540943](https://gitee.com/OooAlex/study_note/raw/master/img/202408291705985.png)

- 时间复杂度: O(n)
- 空间复杂度: O(1)

### Better implementation

手动释放内存空间

使用dummyHead创建虚拟头节点，sentinel->next遍历链表，简洁优雅

复杂度不变

```
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *sentinel = dummyHead;
        while (sentinel->next != nullptr)
        {
            if (sentinel->next->val == val)
            {
                ListNode* tmp = sentinel->next;
                sentinel->next = sentinel->next->next;
                delete tmp;
                continue;
            }
            sentinel = sentinel->next;
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};
```

### FAQ

#### 为什么要用sentinel节点？

> 使用sentinel->next遍历链表，方便以统一格式删除链表中的节点，删除头节点不用特意处理

#### 为什么删除节点后要continue循环，而不执行sentinel = sentinel->next?

> 在删除节点时已经执行sentinel->next = sentinel->next->next迭代了

#### 为什么需要dummyHead和sentinel两个节点？

> dummyHead为创建的虚拟头节点，dummyHead->next为新的头节点，sentinel为哨兵遍历链表

#### 其他注意点？

> 永远记住当前处理的节点是sentinel->next
>
> 手动释放内存空间！
>
> 释放指针就是释放指针指向的内存地址！

### 总结

Leetcode easy题，用好sentinel节点遍历链表就可以秒杀



