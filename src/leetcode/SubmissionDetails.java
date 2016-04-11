package leetcode.main;

public class SubmissionDetails {
    public void merge(int A[], int m, int B[], int n) {
        //µ¹×ÅÀ´
        int i,j,k;
        for(i = m - 1,j = n - 1,k = m + n - 1;i >= 0 && j >= 0;k--){
            if(A[i] > B[j]){
                A[k] = A[i];
                i--;
            }
            else{
                A[k] = B[j];
                j--;
            }
        }
        while(i >= 0){
            A[k] = A[i];
            i--;
            k--;
        }
        while(j >= 0){
            A[k] = B[j];
            j--;
            k--;
        }

    }
}