package other;

public class QuickSort {
	
	public static void main(String[] args) {
		int a[] = {5,3,2,1};
		quickSort(a,0,3);
		for(int i :a ){
			System.out.println(i);;
		}
	}
	

	public static int partition(int[] a,int left,int right){
		int temp = a[left];
		while(left < right){
			while(left < right && a[right] >= temp){
				right--;
			}
			a[left] = a[right];
			while(left < right && a[left] <= temp){
				left++;
			}
			a[right] = a[left];
		}
		a[left] = temp;
		return left;
	}
	public static void quickSort(int []a,int left ,int right){
		if(left < right){
			int partition = partition(a,left,right);
			quickSort(a,left,partition - 1);
			quickSort(a,partition + 1,right);
		}
	}

}
