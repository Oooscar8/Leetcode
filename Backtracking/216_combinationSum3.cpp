#include <vector>;
#include <Set>;
using namespace std;

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