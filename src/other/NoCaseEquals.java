package other;

public class NoCaseEquals {
	public static void main(String[] args) {
		String a = "ddddd大小的";
		String key = "DD大小";
		if(contains(a,key)){
			System.out.println("包含key");
		}
		
	}

	public static boolean contains(String a, String b) {
		if (a.toUpperCase().indexOf(b.toUpperCase()) > -1)
			return true;
		return false;
	}
}
