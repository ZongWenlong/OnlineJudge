package leetcode.main;


public class SearchForARange {
    public int[] searchRange(int[] A, int target) {
        int [] result = new int[2];
        for(int left = 0,right = A.length - 1,middle = (right + left) / 2; left <= right; middle = (right + left) / 2){
            if(A[middle] > target){
                right = middle - 1;
            }
            else if(A[middle] < target){
                left =  middle + 1;
            }
            else{
                int leftTemp,rightTemp;
                for(leftTemp = middle; leftTemp >= 0 && A[leftTemp] == target;leftTemp--);
                for(rightTemp = middle; rightTemp < A.length && A[rightTemp] == target;rightTemp++);
                leftTemp ++;
                rightTemp --;
                result[0] = leftTemp;
                result[1] = rightTemp;
                return result;
            }
        }
       
        result[0] = -1;
        result[1] = -1;
        return result;
    }
}