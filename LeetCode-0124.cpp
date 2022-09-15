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
    int path(TreeNode *root, int &sum)
    {
        if (root == NULL)
            return 0;
        int leftTree = max(0, path(root->left, sum));
        int rightTree = max(0, path(root->right, sum));
        int currSum = max(sum, leftTree + rightTree + root->val);
        return root->val + max(leftTree, rightTree);
    }
    int maxPathSum(TreeNode *root)
    {
        int sum = INT_MIN;
        path(root, sum);
        return sum;
    }
};