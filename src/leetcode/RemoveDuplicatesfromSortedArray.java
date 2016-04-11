package leetcode.main;

public class RemoveDuplicatesfromSortedArray {
	public int removeDuplicates(int[] nums) {
        if(nums.length > 0){
            int count = 0;
            for(int i = 1; i < nums.length;i++){
                if (nums[i] > nums[count]){
                    count++;
                    nums[count] = nums[i];
                }
            }
            return count + 1;
        }
        else{
            return 0;
        }
        
    }
}
