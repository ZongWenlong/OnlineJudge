package leetcode.main;

public class ImplementstrStr{
	public int strStr(String haystack, String needle) {
        int max = haystack.length() - needle.length();
        for(int i = 0;i <= max ;i++){
            int j = 0;
            while(j < needle.length()){
                if(haystack.charAt(i + j) == needle.charAt(j)){
                    j++;
                }
                else{
                    break;
                }
            }
            if(j == needle.length()){
                return i;
            }
        }
        return -1;
    }
}