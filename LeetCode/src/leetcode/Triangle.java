package leetcode.main;

import java.util.List;

public class Triangle {
	//triangle.size() >= 1
	public int minimumTotal(List<List<Integer>> triangle) {
        int[] result = new int[triangle.size()];
        result[0] = triangle.get(0).get(0);
        int left,right;
        for(int i = 1; i < triangle.size();i++ ){
            List<Integer> row = triangle.get(i);
            for(int j = row.size() - 1 ;j >= 0;j--){
                if(j == 0){
                    result[j] = result[j] + row.get(j);
                }
                else if(j == row.size() - 1){
                    result[j] = result[j-1] + row.get(j);
                }
                else{
                    left = result[j] + row.get(j);
                    right = result[j-1] + row.get(j);
                    result[j] = left > right ? right : left;
                }
            }
        }
        
        int min = result[0];
        for(int i = 1; i < result.length;i++){
            if(min > result[i]){
                min = result[i];
            }
        }
        return min;
}
}
