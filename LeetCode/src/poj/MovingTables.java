public class Main{
	class Room{
		public int id;
		public Room next;
		public Room pair;
		public Room pre;
	}
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int caseNum = in.nextInt();
		int[] results = new int[caseNum];

		for(int i = 0; i < caseNum; i++){
			int lineNum = in.nextInt();
			Room start = new Room();
			start.id = 0;
			start.next = null;
			start.pair = null;
			start.pre = null;
			for(int j = 0; j < lineNum; j++){
				Room left = new Room();
				Room right = new Room();
				left.id = in.nextInt();
				right.id = in.nextInt();
				left.pair = right;
				right.pair = left;
				insert(start,left);
				insert(start,right);
			}

			int result = 0;
			while(start.next != null){
				Room cur = start.next;
				Room pre = start;
				while(cur != null){
					Room temp = cur.pair;
					if(temp.id > cur.id){
						pre.next = cur.next;
						cur.next.pre = pre;
						cur = temp;
						pre = temp.pre;
						if(cur.next == null){
							pre.next = cur.next;
						}
						else{
							pre.next = cur.next;
							cur.next.pre = pre;
						}
					}
					cur = cur.next;
				}
				result = result + 10;
			}

			results[i] = result;
		}

		for(int i : results){
			System.out.println(i);
		}
	}

	private static void insert(Room start,Room newRoom){
		Room cur = start.next;
		Room pre = start;
		while(cur != null){
			if(newRoom.id > cur.id){
				pre = cur;
				cur = cur.next;
			}
			else{
				newRoom.next = pre.next;
				newRoom.pre = pre;
				cur.pre = newRoom;
				pre.next = newRoom;
				return;
			}
		}
		newRoom.next = pre.next;
		newRoom.pre = pre;
		pre.next = newRoom;
	}
}