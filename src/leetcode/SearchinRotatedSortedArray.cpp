class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        
        while(left <= right){
            int mid = left + ((right - left) >> 1);
            
            if(nums[mid] == target){
                return mid;
            }

            if(nums[left] <= nums[mid]){
                if(nums[left] <= target && target < nums[mid]){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            else{
                if(nums[mid] < target && target <= nums[right]){
                    left = mid + 1;
                } 
                else{
                    right = mid - 1;
                }
            }
        }
        return -1;

    }
    int search1(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        // find minimum value
        while(left < right){
            int mid = left + ((right - left) >> 1);
            if(nums[mid] > nums[right]){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        } 


        // find target
        int offset = left;
        left = 0;
        right = n - 1;
        while(left <= right){
            int mid = left + ((right - left) >> 1);
            int realMid = (mid + offset) % n;
            if(nums[realMid] >  target){
                right = mid - 1;
            }
            else if(nums[realMid] < target){
                left = mid + 1;
            }
            else {
                return realMid;
            }
        }
        return -1;

    }
};