// Space O(M * N)
// public class Solution {
//     public int minPathSum(int[][] grid) {
//         int m = grid.length;
//         if(m > 0){
//             int n = grid[0].length;
//             if(n > 0){
//                 int[][] dp = new int[m][n];
                
//                 //init
//                 dp[0][0] = grid[0][0];
//                 for(int i = 1; i < n;i++){
//                     dp[0][i] = dp[0][i - 1] + grid[0][i];
//                 }
                
//                 // dp construct
//                 for(int i = 1; i < m;i++){
//                     dp[i][0] = dp[i - 1][0] + grid[i][0];
//                     for(int j = 1;j < n;j++){
//                         dp[i][j] = Math.min(dp[i - 1][j],dp[i][j - 1]) + grid[i][j];
//                     }
//                 }
//                 return dp[m - 1][n - 1];
//             }
//         }
//         return 0;
//     }
// }

// Space O(m)
public class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        if(m > 0){
            int n = grid[0].length;
            if(n > 0){
                int[] dp = new int[m];
                
                //init
                dp[0] = grid[0][0];
                for(int i = 1; i < m;i++){
                    dp[i] = dp[i - 1] + grid[i][0];
                }
                
                // dp construct
                for(int i = 1; i < n;i++){
                    dp[0] += grid[0][i];
                    for(int j = 1;j < m;j++){
                        dp[j] = Math.min(dp[j - 1],dp[j]) + grid[j][i];
                    }
                }
                return dp[m - 1];
            }
        }
        return 0;
    }
}