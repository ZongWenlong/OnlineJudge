/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 	version 1
// class Solution {
// public:

//     TreeNode* preOrderTravel(TreeNode* root,TreeNode *treeListRoot){
//         if(root != NULL){
//             TreeNode * leftTemp = root -> left;
//             TreeNode * rightTemp = root -> right;
//             treeListRoot -> right = root;
//             treeListRoot -> left = NULL;
//             treeListRoot = treeListRoot -> right;
            
//             if(leftTemp != NULL){
//                 treeListRoot = preOrderTravel(leftTemp,treeListRoot);
//             }
//             if(rightTemp != NULL){
//                 treeListRoot = preOrderTravel(rightTemp,treeListRoot);
//             }
//             return treeListRoot;
//         }
//         return NULL;
//     }
//     void flatten(TreeNode* root) {
//         TreeNode* newRoot = new TreeNode(0);
//         newRoot = preOrderTravel(root,newRoot);
//     }
// };
// 	version 2
class Solution {
private:
   TreeNode* prev = NULL; 
public:
    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }
        flatten(root -> right);
        flatten(root -> left);
        root -> right = prev;
        root -> left = NULL;
        prev = root;
    }
};