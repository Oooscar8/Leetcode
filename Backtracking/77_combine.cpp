#include <vector>;
#include <Set>;
using namespace std;

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
        if (set.size() < k) {    //剪枝优化
            return;
        }

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