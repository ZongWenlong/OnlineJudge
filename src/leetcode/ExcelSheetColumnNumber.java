package leetcode.main;

public class ExcelSheetColumnNumber {
	public int titleToNumber(String s) {
		int num = 0;
		for (int i = s.length() - 1, index = 0; i >= 0; i--, index++) {
			num = (int) (num + Math.pow(26, i) * (s.charAt(index) - 'A' + 1));
		}
		return num;
	}

	public String convertToTitle(int n) {
		String result = "";
		for (int mod = 0; n > 0; n = n / 26) {
			mod = n % 26;
			if(mod == 0){
				mod = 26;
			}
			result = (char) (mod + 'A' - 1) + result;
			n = n - mod;

		}
		return result;
	}
}
