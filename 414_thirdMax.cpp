// 2 2 3 1
// 1

// 3 3 4 4 4
// 4

// 5 8 3 3 4 6 5 1
// 5
#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <iterator>
using namespace std;

// 使用两个栈空间，一个主栈存放排序好的元素，另一个栈作为备用栈辅助将元素按序放入主栈中
// 时间和空间复杂度很高
// 非常丑陋的代码，不忍直视
class Solution1
{
public:
    int thirdMax(vector<int> &nums)
    {
        stack<int> NumStack;
        stack<int> BackupStack;
        NumStack.push(nums[0]); // 先将数组中第一个数入栈
        int TopStack = nums[0]; // 设置栈顶元素
        for (int i = 1; i < nums.size(); ++i)
        {
            bool isNewNum = true;
            for (int k = 0; k < i; ++k)
            {                           // 判断当前的数是否已在栈中
                if (nums[i] == nums[k]) // 如果已经在栈中，
                {                       // 则设置isNewNum为false，并在后续直接跳入下一个大循环
                    isNewNum = false;
                    break;
                }
            }

            if (!isNewNum)
                continue;
            else // 如果当前的数不在栈中，则将其入栈
            {
                while (!NumStack.empty() && nums[i] < NumStack.top())
                {
                    // 获取栈顶元素
                    TopStack = NumStack.top();
                    NumStack.pop();
                    BackupStack.push(TopStack);
                }
                NumStack.push(nums[i]);
                while (!BackupStack.empty())
                {
                    TopStack = BackupStack.top();
                    BackupStack.pop();
                    NumStack.push(TopStack);
                }
            }
        }
        if (NumStack.size() < 3)
            return NumStack.top();
        else
        {
            NumStack.pop();
            NumStack.pop();
            return NumStack.top();
        }
    }
};

// 优化方案：
// 使用set集合，在遍历数组的过程中将元素逐个添加到set中
// 再使用it迭代器，指向set中倒数第三个元素，并返回其值(*it)
class Solution2
{
public:
    int thirdMax(vector<int> &nums)
    {
        // 创建一个集合numSet来存储nums中的元素，
        // 将nums中的元素自动去重，并按照升序排序
        set<int> numSet;
        for (int num : nums) // 基于范围遍历nums中的元素
            numSet.insert(num);

        if (numSet.size() < 3)
            return *numSet.rbegin(); // numSet.rbegin()返回指向最后一个元素的迭代器
        else
        {
            auto it = numSet.end(); // 使用auto自动推导迭代器的类型
            advance(it, -3);
            return *it;
        }
    }
};

int main()
{
    Solution1 s1;
    Solution2 s2;

    vector<int> vec1{2, 2, 3, 1};
    vector<int> vec2{3, 2, 1};
    cout << "thirdmax:" << s1.thirdMax(vec1) << endl;
    cout << "thirdmax:" << s1.thirdMax(vec2) << endl;
    cout << "thirdmax:" << s2.thirdMax(vec1) << endl;
    cout << "thirdmax:" << s2.thirdMax(vec2) << endl;
    system("pause");
    return 0;
}