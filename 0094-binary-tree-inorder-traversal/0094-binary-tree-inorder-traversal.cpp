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
    void inorderTraversal(vector<int>&ans , TreeNode* root){
        if(root==nullptr) return;
        inorderTraversal(ans ,root->left);
        ans.push_back(root->val);
        inorderTraversal(ans,root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        inorderTraversal(ans,root);
        return ans;
                    
    }

};