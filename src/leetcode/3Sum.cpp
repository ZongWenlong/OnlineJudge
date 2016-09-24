class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        int n = nums.size();

        if(n >= 3){
        	sort(nums.begin(),nums.end());
	        for(int i = 0;i < n - 2;i++){
	        	if(nums[i] + nums[i + 1] + nums[i + 2] > 0){
	        		break;
	        	}
	        	if(nums[i] + nums[n - 1] + nums[n - 2] < 0){
	        		continue;
	        	}
	        	if(i > 0 && nums[i] == nums[i - 1]){
	        		continue;
	        	}
	        	int left = i + 1;
	        	int right = n - 1;
	        	while(left < right){
	        		int cur = nums[i] + nums[left] + nums[right];
	        		if(left > i + 1 && nums[left] == nums[left - 1]){
	        			left ++;
	        			continue;
	        		}
	        		if(right < n - 1 && nums[right] == nums[right + 1]){
	        			right ++;
	        			continue;
	        		}
	        		if(cur == 0){
	        			results.push_back(vector<int>{nums[i],nums[left],nums[right]});
	        			left ++;
	        			right --;
	        		}
	        		else {
	        			while(left < right && cur < 0){
	        				left++;
	        				cur = nums[i] + nums[left] + nums[right];
	        			}
	        			while(left < right && cur > 0){
	        				right--;
	        				cur = nums[i] + nums[left] + nums[right];
	        			}
	        		}
	        		
	        	}
	        }
        }
        
        return results;
    }
};