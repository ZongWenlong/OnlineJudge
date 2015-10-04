package letcode.test;

import leetcode.main.BinaryTreeLevelOrderTraversalII;
import leetcode.main.ExcelSheetColumnNumber;
import leetcode.main.FactorialTrailingZeroes;
import leetcode.main.TreeNode;

import org.junit.Test;

public class LettCodeTest {

	@Test
	public void factorialTrailingZeroes() {
		FactorialTrailingZeroes factorialTrailingZeroes = new FactorialTrailingZeroes();
		System.out.println(factorialTrailingZeroes.trailingZeroes(268));
	}
	
	@Test
	public void excelSheetColumnNumber(){
		ExcelSheetColumnNumber excelSheetColumnNumber = new ExcelSheetColumnNumber();
		System.out.println(excelSheetColumnNumber.titleToNumber("Z"));
		System.out.println(excelSheetColumnNumber.convertToTitle(28));
	}
	
	@Test
	public void binaryTreeLevelOrderTraversalII(){
		BinaryTreeLevelOrderTraversalII bt = new BinaryTreeLevelOrderTraversalII();
		TreeNode treeNode = new TreeNode(1);
		treeNode.setLeft(null);
		treeNode.setRight(null);
		
		System.out.println(bt.levelOrderBottom(treeNode).size());
	}

}
