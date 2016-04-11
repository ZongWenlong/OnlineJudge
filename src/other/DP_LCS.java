package other;

public class DP_LCS {
	public enum Direction {
		LEFT, UP, LEFT_UP
	}

	public static int[][] solution(String a, String b) {
		int[][] c = new int[a.length() + 1][b.length() + 1];
		Direction[][] d = new Direction[a.length()][b.length()];
		// ≥ı ºªØ
		for (int i = 0; i < a.length(); i++) {
			c[i][0] = 0;
		}
		for (int i = 0; i < b.length(); i++) {
			c[0][i] = 0;
		}

		for (int i = 1; i <= a.length(); i++) {
			for (int j = 1; j <= b.length(); j++) {
				if (a.charAt(i - 1) == b.charAt(j - 1)) {
					c[i][j] = c[i - 1][j - 1] + 1;
					d[i - 1][j - 1] = Direction.LEFT_UP;
				} else if (c[i][j - 1] > c[i - 1][j]) {
					c[i][j] = c[i][j - 1];
					d[i - 1][j - 1] = Direction.UP;
				} else {
					c[i][j] = c[i - 1][j];
					d[i - 1][j - 1] = Direction.LEFT;
				}
			}
		}

		for (int i = a.length() - 1, j = b.length() - 1; i >= 0 && j >= 0;) {
			switch (d[i][j]) {
			case LEFT:
				i--;
				break;
			case UP:
				j--;
				break;
			case LEFT_UP:
				System.out.print(a.charAt(i));
				i--;
				j--;
				break;
			}
			
		}

		System.out.println("");
		return c;
	}

	public static void main(String[] args) {
		String a = "ABCBDAB";
		String b = "BDCABA";
		int[][] c = solution(a, b);

		for (int i = 0; i < c.length; i++) {
			int[] row = c[i];
			for (int j = 0; j < row.length; j++) {
				System.out.print(row[j]);
			}
			System.out.println("");
		}

	}

}
