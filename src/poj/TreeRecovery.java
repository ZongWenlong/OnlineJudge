
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;


public class TreeRecovery
{

	public static final void main(String[] args){
		Scanner in = new Scanner(System.in);
		List<String> results = new LinkedList<String>();
		
		while(in.hasNext()){
			String preorder = in.next();
			String inorder = in.next();
			TreeNode root = treeRecovery(preorder,inorder);
			results.add(printPostorder(root)); 
		}
		
		for(String str : results){
			System.out.println(str);
		}
	}

	public static TreeNode treeRecovery(String preorder,String inorder){
		if(preorder.length() > 0 && preorder.length() == inorder.length()){
			return recurConstract(preorder,inorder,0,0,inorder.length() - 1);
		}
		else{
			return null;
		}
	}


	public static TreeNode recurConstract(String preorder,String inorder,int preIndex,int inLeft,int inRight){		
		while(preIndex < preorder.length()){
			int nextIndex = inorder.indexOf(preorder.charAt(preIndex),inLeft);
			if(nextIndex == -1){
				preIndex ++;
			}
			else{
				TreeNode curNode = new TreeNode();
				curNode.left = null;
				curNode.right = null;
				curNode.value = preorder.charAt(preIndex);
				if(nextIndex > inLeft){
					curNode.left = recurConstract(preorder,inorder,preIndex + 1, inLeft,nextIndex - 1);	
				}
				if(nextIndex < inRight){
					curNode.right = recurConstract(preorder,inorder,preIndex + 1, nextIndex + 1,inRight);	
				}
				return curNode;
			}
		}
		return null;
	}

	private static String printPostorder(TreeNode root){
		String str = "";

		if(root.left != null){
			str = str + printPostorder(root.left);
		}
		if(root.right != null){
			str = str + printPostorder(root.right);
		}
		return str + root.value;
	}

}

class TreeNode{
	public TreeNode left;
	public TreeNode right;
	char value;
}