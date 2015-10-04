package leetcode.main;

public class NumberOf1Bits {

	public static void main(String[] args) {
		System.out.println(hammingWeight(5));
	}
	
    public static int hammingWeight(int n) {
    	int hammingWeight = 0;
    	for(int i = n;i > 0;i = i/2){
    		hammingWeight = hammingWeight + i % 2;
    	}
        return hammingWeight;
    }
}
