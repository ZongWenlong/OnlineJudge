package other;

/**
 * 圆上有n个点，从0到n-1，依次连接，
 * 从一个点到临近节点为1步
 * 问：
 * 	从0出发走n步再回到0，共有多少种走法    
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
