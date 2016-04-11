import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class GoldbachsConjecture{
	public void goldbachsConjecture(){
		Scanner in = new Scanner(System.in);
		int even = in.nextInt();
		List<String> results = new LinkedList<String>();
		List<Integer> primes = new ArrayList<Integer>();
		while(even != 0){
			int stopFlag = even / 2 ;
			boolean findFlag = false;
			for(int i = 3,j = 0; i <= stopFlag; i++){
				int left;
				if(j < primes.size()){
					left = primes.get(j);
					j++;
				}
				else{
					left = getNextPrime(i,even - 2);
					primes.add(left);
					j++;
				}

				if(isPrime(even - left) == true){
					findFlag = true;
					String str = even + " = " + left + " + " + (even -left); 
					results.add(str);
					break;	
				}
			}
			if(findFlag == false){
				String str = "Goldbach's conjecture is wrong."; 
				results.add(str);
			}
			even = in.nextInt();
		}

		for(String str : results){
			System.out.println(str);
		}
	}

	public int getNextPrime(int start,int end){
		for(int i = start; i <= end; i++ ){
			if(isPrime(i) == true){
				return i;
			}
		}

		return 0;
	}

	public boolean isPrime(int temp){
		if(temp < 3){
			return false;
		}

		int endFlag = (int)Math.sqrt(temp);
		for(int j = 2; j <= endFlag; j++){
			if(temp % j == 0){
				return false;
			}
		}
		return true;
	}
}