#include <vector>;
using namespace std;

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