#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// 输入：citations = [3,0,6,1,5]
// 6 5 3 1 0
// 输出：3

// 输入：citations = [1,3,1]
// 3 1 1
// 输出：1

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end(), greater<int>()); // 将citations数组按照降序排序
        int i = 1;
        for (int num : citations)
        {
            if (i < num)
                ++i;
            else
                return (i == num) ? i : i - 1;
        }
        return i - 1;
    }
};

int main() {
    Solution s1;
    vector<int> citations1 = {3,0,6,1,5};
    cout << s1.hIndex(citations1) << endl; // 输出：3

    Solution s2;
    vector<int> citations2 = {1,3,1};
    cout << s2.hIndex(citations2) << endl; // 输出：1

    return 0;
}