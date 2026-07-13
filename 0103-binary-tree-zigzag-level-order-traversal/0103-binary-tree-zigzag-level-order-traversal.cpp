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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr) return {};
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        q.push(root);
        bool flag =0;
        while(!q.empty()){
            int s=q.size();
            vector<int>level(s);
            for(int i=0;i<s;i++){
                TreeNode* node=q.front();
                q.pop();
                if(flag ==1) level[s-1-i] = node->val;
                else level[i]=node->val;
                if(node->left != nullptr) q.push(node->left);
                if(node->right !=nullptr) q.push(node->right);
            }
            if(flag == 1) flag =0;
            else flag =1;
            ans.push_back(level);
        }
        return ans;
        

    }
};