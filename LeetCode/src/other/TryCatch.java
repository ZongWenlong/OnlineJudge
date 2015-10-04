package other;

import javax.management.RuntimeErrorException;

public class TryCatch {
	public static void main(String[] args){
		int i = 9;
		try{
			i = 1;
			throw new RuntimeErrorException(new Error());
		}
		catch (Exception e){
			System.out.println(i);
		}
	}
}
