package leetcode.main;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Stack;

public class BinaryTreePreorderTraversal {

	 public List<Integer> preorderTraversal(TreeNode root) {
	        Stack<TreeNode> stack = new Stack<TreeNode>();
	        List<Integer> result = new ArrayList<Integer>();
	        
	        if(root != null){
	            stack.push(root);
	          
	            TreeNode currentNode;
	            while(!stack.empty()){
	                currentNode = stack.pop();
	                result.add(currentNode.val);
	                
	                if(currentNode.right != null){
	                    stack.push(currentNode.right);
	                }
	                if(currentNode.left != null){
	                    stack.push(currentNode.left);
	                }
	            }
	        }

	        return result;
	    }
}
