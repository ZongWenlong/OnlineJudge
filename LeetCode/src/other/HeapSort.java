package other;

public class HeapSort {
	public static void makeHeap(int[] a,int start,int n){
		int temp;
		for(int i = start,child = i * 2 + 1; i < n/2 ;i = child){
			child = i * 2 + 1;
			if(child < n - 1 && a[child] > a[child + 1]){
				child ++;
			}
			
			if(a[i] > a[child]){
				temp = a[child];
				a[child] = a[i];
				a[i] = temp;
			}
			
		}
	}
	public static void heapSort(int []a){
		//创建小根堆
		for(int i = a.length/2 - 1;i >= 0;i--){
			makeHeap(a,i,a.length);
		}
			
		for(int i = 0; i < a.length;){
			System.out.print(a[0] + " ");
			int temp = a[a.length - i - 1];
			a[a.length - i - 1] = a[0];
			a[0] = temp;
			i++;
			makeHeap(a,0,a.length - i);
		}
	}
	
	public static void main(String[] args){
		int a[] = {8,22,1,89,25,99,5,4,9,6,3,10};
		heapSort(a);
	}
}
