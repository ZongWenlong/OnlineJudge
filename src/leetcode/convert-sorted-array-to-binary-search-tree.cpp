/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        if(nums == null){
            return null;
        }
        else{
            return binaryConstruct(nums,0,nums.length - 1);
        }
    }
    private TreeNode binaryConstruct(int[] nums,int left,int right){
        if(left > right){
            return null;
        }
        else{
            int mid = left + ((right - left) >> 1);
            TreeNode root = new TreeNode(nums[mid]);
            root.left = binaryConstruct(nums,left,mid - 1);
            root.right = binaryConstruct(nums,mid + 1,right);
            return root;
        }
        
    }
}