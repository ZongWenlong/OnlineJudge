package leetcode.main;

import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class BinaryTreeLevelOrderTraversal {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
		List<List<Integer>> result = new LinkedList<List<Integer>>();
		List<Integer> rowResult = new LinkedList<Integer>();
		int currentCount,nextCount;
		
		if(root != null){
		    TreeNode currentNode = root;
    		queue.offer(root);
    		currentCount = 1;
    		nextCount = 0;
    		
    		while(queue.isEmpty() == false){
    			currentNode = queue.poll();
    			currentCount--;
    			rowResult.add(currentNode.val);
    			
    			if(currentNode.left != null){
    				queue.offer(currentNode.left);
    				nextCount ++;
    			}
    			
    			if(currentNode.right != null){
    				queue.offer(currentNode.right);
    				nextCount ++;
    			}
    			
    			if(currentCount == 0){
    				result.add(0, rowResult);
    				rowResult = new LinkedList<Integer>();
    				currentCount = nextCount;
    				nextCount = 0;
    			}
    
    			
    		}
    	}
		return result;
        
    }
}