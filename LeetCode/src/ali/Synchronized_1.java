package ali;

public class Synchronized_1 extends Thread{
	private int val;
	public Synchronized_1(int val){
		this.val = val;
	}
	
	public  void print(){
		synchronized(Synchronized_1.class){
			while(true){
				System.out.println(val);
			}
		}
		
	}
	public void run(){
		print();
	}
	
}

class SynTest{
	public static void main(String[] args){
		Synchronized_1 thread1 = new Synchronized_1(1);

		Synchronized_1 thread2 = new Synchronized_1(3);
		thread1.start();
		thread2.start();
	}
}
