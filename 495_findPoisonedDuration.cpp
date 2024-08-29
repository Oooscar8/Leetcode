// timeSeries=[1 2 3 7 11 15]
// duration=3

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int TotalPoison = 0, EndPoison = 0;
        for (int i = 0; i < timeSeries.size() - 1; i++)
        {
            EndPoison = timeSeries[i] + duration; // 每循环一次更新新的中毒结束时刻

            if (timeSeries[i + 1] < EndPoison)
            {
                TotalPoison += timeSeries[i + 1] - timeSeries[i];
                continue;
            }
            // 如果下一个下毒时间在当前毒药结束时间之前，
            // 则用下一个下毒时间减去当前毒药开始时间加到总中毒时间中
            // 然后continue跳入下一个循环

            else
            {
                TotalPoison += duration;
                continue;
            }
            // 如果下一个下毒时间在当前毒药结束时间之后，
            // 则用毒药持续时间加到总中毒时间中，
            // 然后continue跳入下一个循环
        }
        TotalPoison += duration;
        return TotalPoison;
    }
};