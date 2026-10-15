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
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int instart , int inend){
        int i;

        if(instart > inend){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preindex]);

        for(i = instart ; i <= inend ; i++){
            if(inorder[i] == preorder[preindex]){
                break;
            }
        }

        preindex++;

        root -> left = build(preorder , inorder , instart , i-1);
        root -> right = build(preorder , inorder , i+1 , inend);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        TreeNode* root = build(preorder , inorder , 0 , n-1);

        return root;
    }
};