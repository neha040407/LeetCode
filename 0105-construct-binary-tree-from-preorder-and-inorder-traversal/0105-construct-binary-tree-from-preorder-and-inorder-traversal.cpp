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
    int preindex = 0;
    unordered_map<int,int> mp;
    
    TreeNode* build(vector<int>& preorder, int instart , int inend){
        int i;

        if(instart > inend){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preindex]);

        i = mp[preorder[preindex]];

        preindex++;

        root -> left = build(preorder , instart , i-1);
        root -> right = build(preorder , i+1 , inend);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        for(int i = 0 ; i < n ; i++){
            mp[inorder[i]] = i;
        }
        
        TreeNode* root = build(preorder , 0 , n-1);

        return root;
    }
};