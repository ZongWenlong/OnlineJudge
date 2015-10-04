package com.microsoft;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

public class Main3 {

	public static void main(String[] args) {
		Scanner sca  = new Scanner(System.in);
		
		int caseNum = sca.nextInt();
		List<List<Integer>> result = new LinkedList<List<Integer>>();
		for(int i = 0; i < caseNum;i++){
			int moduleNum = sca.nextInt();
			int initSingalNum = sca.nextInt();
			Queue<Integer> queue = new LinkedList<Integer>();
			for(int j = 0; j < initSingalNum;j++){
				queue.add(sca.nextInt());
			}
			Map<Integer,Integer> map = new HashMap<Integer,Integer>();
			Map<Integer,Set<Integer>> moduleSingal = new HashMap<Integer,Set<Integer>>();
			for(int j = 0; j < moduleNum;j++){
				map.put(sca.nextInt(),j+1);
				String str = sca.nextLine();
				String[] strArray = str.split(" ");
				Set<Integer> set = new HashSet();
				for(int k = 0;k < strArray.length;k++){
					set.add(Integer.parseInt(strArray[k]));
				}
				moduleSingal.put(j+1,set);
			}
			
			List<Integer> caseResult = new ArrayList<Integer>(moduleNum);
			for(int j = 0; j < moduleNum;j++){
				caseResult.set(j, 0);
			}
			Integer currentSing,currentModu;
			while(!queue.isEmpty()){
				currentSing = queue.poll();
				currentModu = map.get(currentSing);
				caseResult.set(currentModu - 1,caseResult.get(currentModu - 1) + 1);
				Set<Integer> tempSet = moduleSingal.get(currentModu);
				for (Integer t : tempSet) {
				      queue.add(t);
				}
			}
			
			result.add(caseResult);
		}
		
		
		for(List<Integer> list : result){
			for(Integer i : list){
				System.out.print(i + " ");
			}
			System.out.println("");
		}
	
	}

}
