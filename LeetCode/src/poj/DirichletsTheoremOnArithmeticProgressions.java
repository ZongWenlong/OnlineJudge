

/**
* 3006
*/
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class DirichletsTheoremOnArithmeticProgressions{
		public void dtoap(){
		Scanner in = new Scanner(System.in);
		List<Integer> results = new LinkedList<Integer>();

		int a,d,n;
		a = in.nextInt();
		d = in.nextInt();
		n = in.nextInt();

		while(a != 0){
			int result = getNthPrime(a,d,n);
			results.add(result);
			a = in.nextInt();
			d = in.nextInt();
			n = in.nextInt();
		}

		for(Integer result : results){
			System.out.println(result);
		}

	}

	public int getNthPrime(int a,int d, int n){
		boolean flag = true;
		while(flag){
			if(isPrime(a) == true){
				n--;
			}
			if(n == 0){
				return a;
			}
			a = a + d;
		}
		return 0;

	}

	public boolean isPrime(int temp){
		int endFlag = (int)Math.sqrt(temp);
		for(int j = 2; j <= endFlag; j++){
			if(temp % j == 0){
				return false;
			}
		}
		return true;
	}




}