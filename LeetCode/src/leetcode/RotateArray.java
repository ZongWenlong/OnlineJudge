package leetcode.main;

public class RotateArray {

	/**
	 * @from https://oj.leetcode.com/problems/rotate-array/
	 * @param args
	 */
	public static void main(String[] args) {
		int[] nums = {1,2,3,4,5,6,7,8,9,10,11,12,13};
		int k = 17;
		rotate(nums,k);
		for(int i = 0;i < nums.length ;i++ ){
			System.out.print(nums[i] + " ");
		}
	}

	/**
	 * �㷨˼·��
	 * 		�ȷ�תǰn-k�������ٷ�ת��k������������巭ת
	 * 		��AB��BA�������ȵõ�re(A)re(B),Ȼ��õ�re(re(A)re(B))��BA
	 * @param nums
	 * @param k
	 */
	public static void rotate(int[] nums, int k) {
		k = k % nums.length;
		if(k != 0){
			reverse(nums,0,nums.length - k - 1);
			reverse(nums,nums.length - k,nums.length - 1);
			reverse(nums,0,nums.length - 1);
		}
		
    }
	public static void reverse(int[] nums, int left,int right){
		int temp;
		
		for(;left < right;left++,right--){
			temp = nums[right];
			nums[right] = nums[left];
			nums[left] = temp;
		}
	}
}
