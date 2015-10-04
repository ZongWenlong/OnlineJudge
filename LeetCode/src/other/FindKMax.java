package other;

/**
 * 查找第K大的数值
 * @author Chung
 *
 */
public class FindKMax {
	public static int partation(int a[],int left,int right){
		int key = a[left];
		while(left < right){
			while(left < right && key <= a[right]){
				right --;
			}
			a[left] = a[right];
			while(left < right && key >= a[left]){
				left ++;
			}
			a[right] = a[left];
		}
		
		a[left] = key;
		return left;
	}
	
	public static int kMax(int a[],int left,int right,int k){
		int mid;
		if(left <= right){
			mid = partation(a,left,right);
			if(mid == k - 1){
				return a[mid];
			}
			else if(mid < k){
				return kMax(a,mid + 1,right,k);
			}
			else{
				return kMax(a,left,mid - 1,k);
			}	
		}
		
		return -1;
	}
	
	public static void main(String[] args){
		int[] a = {3,2,5,4,7,1,9,6,8};
		System.out.println(kMax(a,0,a.length - 1,7));
	}
}
