public class LongestValidParentheses{
	public int longestValidParentheses(String s) {
        Stack<Character> charStack = new Stack<Character>();
        Stack<Integer> indexStack = new Stack<Integer>();
        int max = 0;
        int gap = 0;
        
        charStack.push('\0');
        indexStack.push(-1);
        for(int i = 0; i < s.length();i++){
            if(s.charAt(i) == '('){
                charStack.push('(');
                indexStack.push(i);
            }
            else{
                if(charStack.peek() == '('){
                    charStack.pop();
                    indexStack.pop();
                }
                else{
                    charStack.push(')');
                    indexStack.push(i);
                }
            }
        }
        
        int pre = s.length() - 1;
        while(!indexStack.empty()){
            int cur = indexStack.pop();
            gap = pre - cur;
            if(gap > max){
                max = gap;
            }
            
            pre = cur;
        }
        
        return max - max % 2;
        
    }

    public int longestValidParentheses2(String s) {
        Stack<Integer> indexStack = new Stack<Integer>();
    
        int max = 0;
        int cur = 0;
        for(int i = 0; i < s.length();i++){
            if(s.charAt(i) == '('){
                indexStack.push(cur);
                cur = 0;
            }
            else{
                if(indexStack.empty()){
                     indexStack.clear();
                     cur = 0;
                }
                else{
                    cur = cur + indexStack.pop() + 2;
                    if(cur > max){
                        max = cur;
                    }
                }
            }
        }
        
        return max;
        
    }
}