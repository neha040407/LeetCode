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
        queue<TreeNode*> q;
        TreeNode* curr;
        int level = 0;

        vector<vector<int>> ans;
        vector<int> temp;
        int s;

        if(root == NULL){
            return ans;
        }

        q.push(root);

        while(!q.empty()){
            s = q.size();

            for(int i = 0 ; i < s ; i++){
                curr = q.front();
                temp.push_back(curr -> val);
                
                if(curr -> left != NULL){
                    q.push(curr -> left);
                }

                if(curr -> right != NULL){
                    q.push(curr -> right);
                }

                q.pop();
            }

            level++;

            if(level%2 == 0){
                reverse(temp.begin(),temp.end());
            }
            
            ans.push_back(temp);
            temp.clear();
        }

        return ans;
    }
};