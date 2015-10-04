package leetcode.main;	
public class ValidPalindrome{
	public boolean isPalindrome(String s) {
        if(s == null){
            return true;
        }
        else{
            int left = 0;
            int right = s.length() - 1;
            while(left < right){
                if(isAlphanumeric(s.charAt(left))){
                    if(isAlphanumeric(s.charAt(right))){
                        if(toLowerCase(s.charAt(left)) == toLowerCase(s.charAt(right))){
                            left++;
                            right--;
                        }
                        else{
                            return false;
                        }
                    }
                    else{
                        right --;
                    }
                }
                else{
                    left++;
                }
            }
            return true;
        }
    }
    public boolean isAlphanumeric(char c){
        return Character.isLetter(c) || Character.isDigit(c);
    }
    public char toLowerCase(char c){
        if(c >= 'A' && c <='Z'){
            return (char)(c - ('A' - 'a'));
        }
        return c;
    }
}