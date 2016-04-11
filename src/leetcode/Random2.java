package leetcode.main;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Random2 {

	public static void main(String[] args) {

	}
	

	/**
	 * 从left到right中随机打印num个不同的数字，并返回
	 * @param left  下限
	 * @param right 上限
	 * @param num  随机数个数
	 * @return num个随机数
	 */
	public List<Integer> random(int left, int right,int num){
		int [] random = new int[right - left + 1];
		List<Integer> result = new ArrayList<Integer>(); 
		for(int i = 0, j = left; i < random.length;i++,j++){
			random[i] = j;
		}
		
		Random ran = new Random();
		int each;
		for(int i = 0,max = random.length; i < num;i++,max--){
			each = ran.nextInt(max);
			result.add(random[each]);
			random[each] = random[max - 1];;
		}
		
		for(Integer i : result){
			System.out.print(i + " ");
		}
		return result;
	}
}
