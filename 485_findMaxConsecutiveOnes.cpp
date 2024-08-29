#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int ConsecutiveOnes = 0, MaxConsecutiveOnes = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 1)
                ++ConsecutiveOnes;
            else
                ConsecutiveOnes = 0;
            MaxConsecutiveOnes = max(MaxConsecutiveOnes, ConsecutiveOnes);
        }
        return MaxConsecutiveOnes;
    }
};