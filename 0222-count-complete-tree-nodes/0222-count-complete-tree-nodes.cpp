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
private: 
    void helper(TreeNode* node , int&ans){
        if(node==nullptr) return;
        helper(node->left,ans);
        ans++;
        helper(node->right,ans);
    }
public:
    int countNodes(TreeNode* root) {
        int ans=0;
        helper(root,ans);
        return ans;
    }
};