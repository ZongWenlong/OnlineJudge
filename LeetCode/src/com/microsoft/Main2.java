package com.microsoft;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main2 {

	public static void main(String[] args) throws IOException {
		 BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int num = Integer.parseInt(reader.readLine());
		int[] x = new int[num];
		int[] y = new int[num];

		for (int i = 0; i < num; i++) {
			String str = reader.readLine();
			String[] strArray = str.split(" ");
			x[i] = Integer.parseInt(strArray[0]);
			y[i] = Integer.parseInt(strArray[1]);
		}

		int[][] matrix = new int[num][num];
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				matrix[i][j] = Math.min(Math.abs(x[i] - x[j]),
						Math.abs(y[i] - y[j]));
			}
		}
		
		System.out.println(dijkstra(matrix, 0,num - 1));

	}

	public static int dijkstra(int[][] graph, int start, int end) {
		boolean[] flag = new boolean[graph[0].length];
		int[] indexs = new int[graph[0].length];
		int i_count = -1;
		int[] dist = graph[start].clone();
		int index = start;
		int presentShortest = 0;

		indexs[++i_count] = index;
		flag[index] = true;

		while (i_count < graph[0].length) {
			int min = Integer.MAX_VALUE;
			for (int i = 0; i < dist.length; i++) {
				if (!flag[i] && dist[i] != -1 && i != index) {
					
					if (dist[i] < min) {
						min = dist[i];
						index = i;
					}
				}
			}
			if (index == end) {
				break;
			}
			flag[index] = true;
			indexs[++i_count] = index;
			if (graph[indexs[i_count - 1]][index] == -1
					|| presentShortest + graph[indexs[i_count - 1]][index] > dist[index]) {
				
				presentShortest = dist[index];
			} else {
				presentShortest += graph[indexs[i_count - 1]][index];
			}

			
			for (int i = 0; i < dist.length; i++) {
				
				if (dist[i] == -1 && graph[index][i] != -1) {
					dist[i] = presentShortest + graph[index][i];
				} else if (graph[index][i] != -1
						&& presentShortest + graph[index][i] < dist[i]) {
				
					dist[i] = presentShortest + graph[index][i];
				}

			}
		}
		
		return dist[end] - dist[start];
	}

}
