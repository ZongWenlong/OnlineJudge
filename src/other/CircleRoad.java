package other;

/**
 * Բ����n���㣬��0��n-1���������ӣ�
 * ��һ���㵽�ٽ��ڵ�Ϊ1��
 * �ʣ�
 * 	��0������n���ٻص�0�����ж������߷�    
 * @author Chung
 *
 */
public class CircleRoad {
	public static int solution1(int n,int k){
		return recursion(n,k,n);
	}
	
	public static int recursion(int n,int j,int total){
		if(j == 0){
			if(n == 0){
				return 1; 
			}
			else{
				return 0;
			}
		}
		return recursion((n - 1 + total)%total ,j - 1,total) + recursion((n +1)%total,j - 1,total);
	}
	
	public static void main(String[] args){
		System.out.println(solution1(3,4));
	}
}
