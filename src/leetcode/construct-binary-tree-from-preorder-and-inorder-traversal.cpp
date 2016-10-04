/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// version 1
// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         unordered_map<int,int> pos;
//         for(int i = 0; i < inorder.size();i++){
//             pos[inorder[i]] = i;
//         }
    
//         if(preorder.size() > 0){
//             stack<TreeNode*> roots;
//             stack<int> rootPos;
            
//             TreeNode* root = new TreeNode(preorder[0]);
//             roots.push(root);
//             rootPos.push(pos[preorder[0]]);
            
//             TreeNode * cur = root;
//             for(int i = 1;i < preorder.size();i++){
//                 int iPos = pos[preorder[i]];
//                 if(iPos < rootPos.top()){
//                     cur -> left = new TreeNode(preorder[i]);
//                     cur = cur -> left;
//                 }
//                 else{
//                     while(!rootPos.empty() && iPos > rootPos.top()){
//                         cur = roots.top();
//                         roots.pop();
//                         rootPos.pop();
//                     }
//                     cur -> right = new TreeNode(preorder[i]);
//                     cur = cur -> right;
//                 }
//                 roots.push(cur);
//                 rootPos.push(iPos);
//             }
//             return root;
//         }
//         else{
//             return NULL;
//         }
//     }
// };


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() > 0){
            int inorderIndex = 0;
            stack<TreeNode*> curs;
            TreeNode* parent = NULL;
            TreeNode* root = new TreeNode(preorder[0]);
            curs.push(root);
            for(int i = 1; i < preorder.size();){
                if(!curs.empty() && curs.top() -> val == inorder[inorderIndex]){
                    parent = curs.top();
                    curs.pop();
                    inorderIndex++;
                }
                else if(parent){
                    TreeNode* newNode = new TreeNode(preorder[i]);
                    parent -> right = newNode;
                    curs.push(newNode);
                    parent = NULL;
                    i++;
                }
                else{
                    TreeNode* newNode = new TreeNode(preorder[i]);
                    curs.top() -> left = newNode;
                    curs.push(newNode);
                    i++;
                }
            }
            return root;
        }
        else{
            return NULL;
        }
    }
};