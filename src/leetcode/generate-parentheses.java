public class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> results = new LinkedList<String>();
        dfs(results,new StringBuffer(),n,n);
        return results;
    }
    private void dfs(List<String> results, StringBuffer result,int leftCount,int rightCount){
        if(leftCount == 0 && rightCount == 0){
            results.add(new String(result.toString()));
        }
        else{
            // add left parenthese
            if(leftCount > 0){
                result.append('(');
                dfs(results,result,leftCount - 1,rightCount);
                result.deleteCharAt(result.length() - 1);
            }
            // add right parenthese
            if(rightCount > leftCount && rightCount > 0){
                result.append(')');
                dfs(results,result,leftCount,rightCount - 1);
                result.deleteCharAt(result.length() - 1);
            }
        }
    }
}