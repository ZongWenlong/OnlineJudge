package leetcode.main;

public class Main {

	public static void main(String[] args) {
		int[] A = new int[0];
		int[] B = new int[1];
		B[0] = 1;
		merge(A,A.length,B,B.length);
		
		System.out.println(A.length+" "+A[0]);
		
	}
	
	
	
	
	
	
	public static void merge(int A[], int m, int B[], int n) {
        int[] C = new int[m + n];
        
        int i,j,k;
        for(i = 0,j = 0,k = 0; i < m && j < n;k++){
            if(A[i] > B[j]){
                C[k] = B[j];
                j++;
            }
            else{
                C[k] = A[i];
                i++;
            }
        } 
        
        while(i < m){
            C[k] = A[i];
            k++;
            i++;
        }
        while(j < n){
            C[k] = B[j];
            k++;
            j++;
        }
        
        A = C;
    }

}
