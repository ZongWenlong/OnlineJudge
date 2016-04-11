package other;


public class ThreeSort {
	public static int[] threeSort(int[] a,int second){
		int left = 0;
		int right = a.length - 1;
		int leftTemp = left,rightTemp = right;
		int temp;
		while(leftTemp < rightTemp){
			while(leftTemp < rightTemp){
				if(a[left] < second){
					left++;
				}
				else if(a[left] == second){
					temp = a[rightTemp];
					a[rightTemp] = a[left];
					a[left] = temp;
					rightTemp --;
				}
				else{
					break;
				}
				
			}
			leftTemp = left;
			
			while(leftTemp < rightTemp){
				if(a[right] > second){
					right--;
				}
				else if(a[right] == second){
					temp = a[right];
					a[right] = a[leftTemp];
					a[leftTemp] = temp;
					leftTemp ++;
				}
				else{
					break;
				}
				
			}
			
			rightTemp = right;
		}
					
	    return a;
	}
	
	public static void main(String[] args){
		int[] a = {};
		ThreeSort.threeSort(a, 2);
		for(int i =0; i< a.length;i++){
			System.out.println(a[i]);
		}
		
	}
}
