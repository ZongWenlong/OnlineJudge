public class Solution {
    private static int[][] MOVE = {{1,0},{-1,0},{0,1},{0,-1}};
    public boolean exist(char[][] board, String word) {
        int m = board.length;
        int n = board[0].length;
        boolean[][] visited = new boolean[m][n] ;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(board[i][j] == word.charAt(0)){
                    board[i][j] = '\0';
                    if(dfs(board,word,1,i,j) == true){
                        return true;
                    }
                    board[i][j] = word.charAt(0);
                }
            }
        }
        return false;
         
    }
    private boolean dfs(char[][] board, String word, int pos,int row,int col){
        if(pos == word.length()){
            return true;
        }
        else{
            int m = board.length;
            int n = board[0].length;
            for(int i = 0;i < 4;i++){
                row += MOVE[i][0];
                col += MOVE[i][1];
                if(row >= 0 && row < m && col >= 0 && col < n && board[row][col] == word.charAt(pos)){
                    board[row][col] = '\0';
                    if(dfs(board,word,pos + 1,row,col) == true){
                        return true;
                    }
                    board[row][col] = word.charAt(pos);
                }
                row -= MOVE[i][0];
                col -= MOVE[i][1];
            }
            return false;
            
        }
    }
}