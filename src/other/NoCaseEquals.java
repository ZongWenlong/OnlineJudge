package other;

public class NoCaseEquals {
	public static void main(String[] args) {
		String a = "ddddd��С��";
		String key = "DD��С";
		if(contains(a,key)){
			System.out.println("����key");
		}
		
	}

	public static boolean contains(String a, String b) {
		if (a.toUpperCase().indexOf(b.toUpperCase()) > -1)
			return true;
		return false;
	}
}
