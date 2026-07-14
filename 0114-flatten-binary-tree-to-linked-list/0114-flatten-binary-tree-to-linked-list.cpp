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
    void flatten(TreeNode* root) {
        if(root==nullptr) return;
        if(root->left==nullptr && root->right == nullptr) return;
        flatten(root->left);
        flatten(root->right); 
        //black box assume both sides flattened
        TreeNode* temp=nullptr;
        if(root->right != nullptr) temp = root->right;
        if(root->left==nullptr) return;
        root->right = root->left;
        TreeNode*curr = root->right;
        while(curr->right !=nullptr) curr=curr->right;
        curr->right = temp;
        root->left=nullptr;

    }
};