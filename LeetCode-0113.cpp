/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void dfs(TreeNode *root, int targetSum, vector<vector<int>> &result, vector<int> path, int calculated)
    {
        if (root == NULL)
            return;
        path.push_back(root->val);
        calculated += root->val;
        if (targetSum == calculated && root->left == nullptr && root->right == nullptr)
        {
            result.push_back(path);
            return;
        }

        dfs(root->left, targetSum, result, path, calculated);
        dfs(root->right, targetSum, result, path, calculated);
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> result;
        vector<int> values;
        if (root == NULL)
        {
            return result;
        }
        dfs(root, targetSum, result, values, 0);
        return result;
    }
};