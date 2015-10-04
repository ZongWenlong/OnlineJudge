package leetcode.main;

public class RemoveDuplicatesfromSortedArrayII {
	public int removeDuplicates(int[] nums) {
        if(nums.length > 0){
            int count = 0;
            boolean doubleFlag = false;
            for(int i = 1; i < nums.length;i++){
                if(nums[i] > nums[count]){
                    count ++;
                    nums[count] = nums[i];
                    doubleFlag = false;
                }
                else if(doubleFlag == false){
                    count ++;
                    nums[count] = nums[i];
                    doubleFlag = true;
                }
            }
            return count + 1;
        }
        return 0;
    }
	
	public int removeDuplicates2(int[] nums) {
        if(nums.length > 1){
            int count = 1;
            for(int i = 2; i < nums.length;i++){
                if(nums[i] > nums[count - 1]){
                    count ++;
                    nums[count] = nums[i];
                }
            }
            return count + 1;
        }
        return nums.length;
    }
}
