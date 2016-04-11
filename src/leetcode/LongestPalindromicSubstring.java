package leetcode.main;

public class LongestPalindromicSubstring {
	/**
	 * ÖÐÐÄÀ©É¢·¨
	 * 
	 * @param s
	 * @return
	 */
	public static String Solution1(String s) {
		if (s != null && !s.isEmpty()) {
			char[] sTemp = new char[s.length() * 2 + 1];
			for (int i = 0; i < sTemp.length - 1; i = i + 2) {
				sTemp[i] = '#';
				sTemp[i + 1] = s.charAt(i / 2);
			}
			sTemp[sTemp.length - 1] = '#';

			int left = 0, right = 0;
			int leftTemp, rightTemp;
			for (int i = 0; i < sTemp.length; i++) {
				for (leftTemp = i, rightTemp = i; leftTemp >= 0
						&& rightTemp < sTemp.length;) {
					if (sTemp[leftTemp] == sTemp[rightTemp]) {
						leftTemp--;
						rightTemp++;
					} 
				}
				leftTemp++;
				rightTemp--;
				
				if (rightTemp - leftTemp > right - left) {
					right = rightTemp;
					left = leftTemp;
				}
			}
			
			left = left / 2;
			right = (right- 1) / 2;

			return s.substring(left, right + 1);
		} else {
			return s;
		}
	}

	public static void main(String[] args) {
		System.out.println(Solution1("a"));
	}
}
