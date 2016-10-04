class Solution {
public:
    int numTrees(int n) {
        if(n <= 0){
            return 0;
        }
        else if(n == 1){
            return 1;
        }
        else{
            vector<int> dp(n + 1, 0);
            dp[0] = 1;
            dp[1] = 1;
            for(int i = 2;i <= n; i++){
                int left = 0,right = i - 1;
                for(;left < right;left ++,right--){
                    dp[i] += 2 * (dp[left] * dp[right]);
                }
                if(left == right){
                    dp[i] += (dp[left] * dp[right]);
                }
            }
            
            return dp[n];
        }
        
        
    }
};