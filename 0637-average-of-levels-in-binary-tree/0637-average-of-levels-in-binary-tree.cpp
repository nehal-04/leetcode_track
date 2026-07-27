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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level=1;
        vector<double>ans;
        while(!q.empty()){
            int n=q.size();
            double total=0;
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                total += node->val;
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right); 
            }
            double fin = (double) total / n;
            ans.push_back(fin);
        }
        return ans;
        
    }
};