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
    int maxpathhelper(TreeNode* node , int& maxi){
        if(node==nullptr){
            return 0;
        }
        int left_path = max(0,maxpathhelper(node->left , maxi));
        int right_path = max(0 , maxpathhelper(node->right , maxi));
        maxi = max(maxi , left_path + right_path + node->val);
        return node->val + max(left_path , right_path);
    }
public:

    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        int n=maxpathhelper(root , maxi);
        return maxi;
       
        
    }
};