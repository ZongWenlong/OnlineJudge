package leetcode.main;

import java.util.ArrayList;
import java.util.List;

public class ValidParentheses {

	public static void main(String[] args) {
		System.out.println(isValid("([][][][])"));
		System.out.println(isValid("([][]])"));

	}

	public static boolean isValid(String s) {
		List<Character> string = new ArrayList<Character>();
		
		string.add('\0');

		for(int i = 0;i < s.length();i++){
			switch(s.charAt(i)){
			
			case ')':
				if(string.get(string.size() - 1).equals('(')){
					string.remove(string.size() - 1);
				}
				else{
					string.add(s.charAt(i));
				}
				break;
			
			case ']':
				if(string.get(string.size() - 1).equals('[')){
					string.remove(string.size() - 1);
				}
				else{
					string.add(s.charAt(i));
				}
				break;
				
			case '}':
				if(string.get(string.size() - 1).equals('{')){
					string.remove(string.size() - 1);
				}
				else{
					string.add(s.charAt(i));
				}
				break;
			default:
				string.add(s.charAt(i));
				break;
			}
			
		}
		
		if(string.size() == 1){
			return true;
		}
		else{
			return false;
		}
    }
}
