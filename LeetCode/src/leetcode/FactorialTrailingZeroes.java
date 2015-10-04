package leetcode.main;

public class FactorialTrailingZeroes {
	public static int trailingZeroes(int n) {
		
		int count = n / 5;
		for(long power = 1, i = 25,temp;i <= n;i = i * 5,power ++){
			temp = n / i;
			temp = temp - temp / 5;
			count = (int) (count + temp * power);
		}
		return count;
	
	}
	
	public static void main(String[] args) {
		
		System.out.println(trailingZeroes(100));
		
	}
}
