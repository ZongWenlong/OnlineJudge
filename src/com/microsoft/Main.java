package com.microsoft;

import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		int[] xyz = new int[3];
		int[] xyzTemp = new int[3];

		for (int i = 0; i < 3; i++) {
			xyz[i] = sca.nextInt();
		}

		Arrays.sort(xyz);

		String RYB = sca.next();
		int max = 0, maxTemp = 0;
		for (int i = 0, r = 0, y = 0, b = 0; i < RYB.length(); i++) {
			maxTemp++;
			switch (RYB.charAt(i)) {
			case 'R':
				r++;
				break;
			case 'B':
				b++;
				break;
			case 'Y':
				y++;
				break;
			}

			xyzTemp[0] = Math.abs(r - b);
			xyzTemp[1] = Math.abs(r - y);
			xyzTemp[2] = Math.abs(b - y);
			Arrays.sort(xyzTemp);
			
			if (maxTemp > max) {
				max = maxTemp;
			}

			if (xyz[0] == xyzTemp[0] && xyz[1] == xyzTemp[1]
					&& xyz[2] == xyzTemp[2]) {
				maxTemp = 0;
				r = 0;
				y = 0;
				b = 0;
			}

		}
		System.out.println(max);
	}

}
