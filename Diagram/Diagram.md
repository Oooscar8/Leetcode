# Diagram

## 图论理论基础

### 图的种类

* 有向图
* 无向图
* 加权有向图
* 加权无向图

### 度

无向图中有几条边连接该节点，该节点就有几度。

在有向图中，每个节点有出度和入度。

出度：从该节点出发的边的个数。

入度：指向该节点边的个数。

### 连通图

在无向图中，任何两个节点都是可以到达的，称之为连通图 

如果有节点不能到达其他节点，则为非连通图

### 强连通图

在有向图中，**任何两个节点是可以相互到达的**，称之为强连通图。

### 连通分量

在无向图中的极大连通子图称之为该图的一个连通分量。

### 强连通分量

在有向图中极大强连通子图称之为该图的强连通分量。

### 图的构造

主要是 朴素存储、邻接表和邻接矩阵。

#### 邻接矩阵

`grid[2][5] = 6，grid[5][2] = 6`，表示节点2 与 节点5 相互连通，权值为6。

![img](https://gitee.com/OooAlex/study_note/raw/master/img/202409021542145.png)

优点：

- 表达方式简单，易于理解
- 检查任意两个顶点间是否存在边的操作非常快
- 适合稠密图，在边数接近顶点数平方的图中，邻接矩阵是一种空间效率较高的表示方法。

缺点：

- 遇到稀疏图，会导致申请过大的二维数组造成空间浪费 且遍历边的时候需要遍历整个n * n矩阵，造成时间浪费

#### 邻接表

使用数组 + 链表的方式来表示。邻接表从边的数量来表示图，有多少边才会申请对应大小的链表。

![img](https://gitee.com/OooAlex/study_note/raw/master/img/202409021549406.png)

邻接表的优点：

- 对于稀疏图的存储，只需要存储边，空间利用率高
- 遍历节点连接情况相对容易

缺点：

- 检查任意两个节点间是否存在边，效率相对低，需要 O(V)时间，V表示某节点连接其他节点的数量。
- 实现相对复杂，不易理解

### 图的遍历方式

* DFS
* BFS

### DFS理论基础

