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
    public int sumNumbers(TreeNode root) {
        if(root == null){
            return 0;
        }
        else{
            int sum = 0;
            Queue<Integer> sums = new LinkedList<>();
            Queue<TreeNode> roots = new LinkedList<>();
            roots.offer(root);
            sums.offer(root.val);
            while(!roots.isEmpty()){
                TreeNode cur = roots.poll();
                int curSum = sums.poll();
                if(cur.left == null && cur.right == null){
                    sum += curSum;
                }
                else{
                    if(cur.left != null){
                        roots.offer(cur.left);
                        sums.offer(cur.left.val + curSum * 10);
                    }
                    if(cur.right != null){
                        roots.offer(cur.right);
                        sums.offer(cur.right.val + curSum * 10);
                    }
                }
            }
            return sum;
        }
    }
}