#include <vector>;
#include <stack>;
#include <algorithm>;
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

// Using iteration.
class Solution2
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> result;
        if (root == NULL)
            return result;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            result.push_back(node->val);
            st.pop();
            if (node->left)
                st.push(node->left);
            if (node->right)
                st.push(node->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};