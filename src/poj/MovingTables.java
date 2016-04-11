public class MovingTables{
	/**
	* 利用房间号分割走廊，每条“子走廊”都设置一个计数器，每经过一次+1，最大的次数X10就是答案
	*/
	public static void movingTables(){
		Scanner in = new Scanner(System.in);
		int caseNum = in.nextInt();
		int[] results = new int[caseNum];

		for(int i = 0; i < caseNum; i++){
			int lineNum = in.nextInt();
			int[] rooms = new int[400];
			for(int j = 0; j < lineNum; j++){
				int left = in.nextInt();
				int right = in.nextInt();
				if (left > right){
					int temp;
					temp = right;
					right = left;
					left = temp;
				}
				if(right % 2 != 0){
					right ++;
				}
				for(int k = left - 1; k < right;k ++){
					rooms[k]++;
				}
			}
			int result = 0;
			for(int j : rooms){
				if(result < j){
					result = j;
				}
			}

			results[i] = result * 10;
		}

		for(int i : results){
			System.out.println(i);
		}
	}
	public static void main(String[] args){
		
	}


}