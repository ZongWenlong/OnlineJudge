/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
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
    private ListNode cur;
    public TreeNode sortedListToBST(ListNode head) {
        if(head == null){
            return null;
        }
        cur = head;
        int count = -1;
        while(head != null){
            head = head.next;
            count++;
        }
        
        return inorderConstruct(0,count);
    }
    private TreeNode inorderConstruct(int start,int end){
        if(start > end){
            return null;
        }
        int mid = start + ((end - start) >> 1);
        TreeNode left = inorderConstruct(start,mid - 1);
        TreeNode root = new TreeNode(cur.val);
        root.left = left;
        // inorder travesal
        cur = cur.next;
        TreeNode right = inorderConstruct(mid + 1,end);
        root.right = right;
        return root;
    }
    
    
}