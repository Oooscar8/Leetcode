#include <vector>;
#include <stack>;
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        preorderTraversalHelper(root, result);
        return result;
    }

private:
    void preorderTraversalHelper(TreeNode *cur, vector<int> &result)
    {
        if (cur == NULL)
            return;
        result.push_back(cur->val);
        preorderTraversalHelper(cur->left, result);
        preorderTraversalHelper(cur->right, result);
    }
};

// Using iteration.
class Solution2
{
public:
    vector<int> preorderTraversal(TreeNode *root)
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
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }
        return result;
    }
};