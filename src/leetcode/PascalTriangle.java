package leetcode.main;

import java.util.ArrayList;
import java.util.List;

public class PascalTriangle {

	public static void main(String[] args) {
		List<List<Integer>> result = generate(5);
		for(List<Integer> row : result){
			for(Integer temp : row){
				System.out.print(temp);
			}
			System.out.println("");
		}
	}

	public static List<List<Integer>> generate(int numRows) {
		List<List<Integer>> result = new ArrayList<List<Integer>>();
		List<Integer> row = new ArrayList<Integer>();
		List<Integer> preRow = null;
		
		if(numRows > 0){
			for(int rowCount = 0;rowCount < numRows;rowCount++){
				row = new ArrayList<Integer>();
				for(int columnCount = 0;columnCount <= rowCount;columnCount++){
					if(columnCount == rowCount){
						row.add(1);
						result.add(row);
					}
					else if(columnCount == 0){
						row.add(1);
					}
					else{
						preRow = result.get(rowCount - 1);
						row.add(preRow.get(columnCount) + preRow.get(columnCount - 1));
					}
				}
			}
		}
		else{
			return result;
		}
		
		return result;
	}
}
