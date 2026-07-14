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
    long long widthOfBinaryTree(TreeNode* root) {

        
        queue<pair<TreeNode* , long long>> q;
        q.push({root , 1});
        long long ans=INT_MIN;
        while(!q.empty()){
            int s=q.size();
            long long mincurcol=INT_MAX;
            long long maxcurcol=INT_MIN;
            long long moderator = q.front().second;
            for(int i=0;i<s;i++){
                pair<TreeNode* , long long> p  = q.front();
                q.pop();
                TreeNode* node = p.first;
                long long cur_n = p.second - moderator;
                mincurcol = min(cur_n , mincurcol);
                maxcurcol = max(cur_n , maxcurcol);
                if(node->left != nullptr) q.push({node->left , 2*cur_n});
                if(node->right != nullptr ) q.push({node->right , 2*cur_n + 1});   
            }
            ans=max(ans , maxcurcol - mincurcol + 1);
            
        }
        return ans;

        
        
    }
};