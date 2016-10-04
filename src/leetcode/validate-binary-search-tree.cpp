/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
// inorder traversal
// public class Solution {
//     private Integer preVal = null;
//     public boolean isValidBST(TreeNode root) {
//         if(root == null){
//             return true;
//         }
//         else{
            
//             if(root.left != null){
//                 boolean isValid = isValidBST(root.left);
//                 if(isValid == false){
//                     return false;
//                 }
//             }
//             if(preVal == null){
//                 preVal = root.val;
//             }
//             else if(preVal >= root.val){
//                 return false;
//             }
//             else{
//                 preVal = root.val;
//             }
//             if(root.right != null){
//                 boolean isValid = isValidBST(root.right);
//                 if(isValid == false){
//                     return false;
//                 }
//             }
//             return true;
//         }
//     }
// }
public class Solution {
    public boolean isValidBST(TreeNode root) {
        return dfs(root,null,null);
    }
    public boolean dfs(TreeNode root,TreeNode min,TreeNode max){
        if(root == null){
            return true;
        }
        if((min != null && root.val <= min.val) || (max!= null && root.val >= max.val)){
            return false;
        }
        return dfs(root.left,min,root) && dfs(root.right,root,max);
    }
}