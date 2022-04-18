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
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int maxLevel = -1;
        
        queue<TreeNode *> Q;
        Q.push(root);
        int level = 0;
        
        while (!Q.empty()){
            int n = Q.size();  // # of nodes at this level
            double sum = 0;    // Sum of the node values at this level
            level += 1;
            for (int i=0; i<n; i++){
                auto p = Q.front();
                Q.pop();
                sum += p->val;
                if (p->left) Q.push(p->left);
                if (p->right) Q.push(p->right);                    
            } // end-for

            if (sum > maxSum){
                maxSum = sum;
                maxLevel = level;
            } // end-if         
        } //end-while        
        
        return maxLevel;
    } // end-maxLevelSum
};