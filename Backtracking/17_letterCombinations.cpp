#include <vector>;
#include <Set>;
#include <map>;
using namespace std;

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