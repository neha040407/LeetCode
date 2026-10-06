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
    int sum;
    int numsofar;

    void findNumber(TreeNode* root , int numsofar){
        int num = numsofar;

        if(root == NULL){
            return;
        }

        num = (num * 10) + (root -> val);

        if(root -> left == NULL && root -> right == NULL){
            sum += num;
            return;
        }

        findNumber(root -> left , num);
        findNumber(root -> right , num);

    }

    int sumNumbers(TreeNode* root) {
        findNumber(root , 0);
        return sum;
    }
};