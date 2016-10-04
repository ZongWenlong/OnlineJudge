/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
// bfs
// public class Solution {
//     public void connect(TreeLinkNode root) {
//         if(root != null){
//             Queue<TreeLinkNode> bros = new LinkedList<TreeLinkNode>();
//             Queue<TreeLinkNode> nextBro = new LinkedList<TreeLinkNode>();
//             Queue<TreeLinkNode> temp;
//             bros.offer(root);
//             while(!bros.isEmpty()){
//                 TreeLinkNode cur = bros.poll();
//                 if(cur.left != null){
//                     nextBro.offer(cur.left);
//                 }
//                 if(cur.right != null){
//                     nextBro.offer(cur.right);
//                 }
//                 cur.next = bros.peek();
//                 if(bros.isEmpty()){
//                     temp = bros;
//                     bros = nextBro;
//                     nextBro = temp;
//                 }
//             }
//         }
//     }
// }

public class Solution {
    public void connect(TreeLinkNode root) {
        while(root != null && root.left != null){
            TreeLinkNode cur = root;
            do{
                cur.left.next = cur.right;
                cur.right.next = cur.next == null ? null : cur.next.left;
                cur = cur.next;
            }
            while(cur != null);
            root = root.left;
        }
    }
}