class Solution {
public:
    string getPermutation(int n, int k) {
    	string result = "";

    	list<int> nums;
    	int mul = 1;
    	for(int i = 1;i < n;i++){
    		nums.push_back(i);
    		mul *= i;
    	}
    	nums.push_back(n);

    	for(int i = n - 1;i >= 1;i--){
    		int pos = (k - 1) / mul;
    		list<int>::iterator it = next(nums.begin(),pos);
    		result += to_string(*it);
    		nums.erase(it);

    		k = (k - 1) % mul + 1;
    		mul /= i;
    	}
    	result += to_string(nums.front());
    	
    	return result;
    }
};