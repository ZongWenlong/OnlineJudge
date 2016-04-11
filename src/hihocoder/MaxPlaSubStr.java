package hihocoder;

import java.util.Scanner;

/**
 * 最长回文子串
 * @author Chung
 *
 */
public class MaxPlaSubStr {
	public static void main(String[] args){
        Scanner sca = new Scanner(System.in);
        int strNum = sca.nextInt();
        int[] result = new int[strNum];
        
        for(int i = 0; i < strNum;i++){
            result[i] = maxPalSubStr1(sca.next());
        }
        for(int i = 0; i < strNum;i++){
            System.out.println(result[i]);
        }
    }
    
    public static int maxPalSubStr1(String str){
        int max = 1;
        for(int i = 0;i < str.length();i++){
            int temp = 1;
            for(int left = i - 1,right = i + 1; left >= 0 && right < str.length();left --,right ++){
                if(str.charAt(left) == str.charAt(right)){
                    temp = temp + 2;
                }
            } 
            if(temp > max){
               max = temp; 
            }
        }
        
        return max;
    }
}
