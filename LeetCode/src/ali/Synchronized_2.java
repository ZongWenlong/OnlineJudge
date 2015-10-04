package ali;

public class Synchronized_2{

	
	public  void printClass(String name){
		synchronized(Synchronized_2.class){
			while(true){
				System.out.println(name + "--class");
			}
		}
		
	}
	public  void printThis(String name){
		synchronized(this){
			while(true){
				System.out.println(name + "--this");
			}
		}
		
	}
	public  void print(String name){
		while(true){
			System.out.println(name + "--ok");
		}
	}

	public static void main(String[] args){
		Synchronized_2 print = new Synchronized_2();
		Synchronized_2 print2 = new Synchronized_2();
		Thread printThread1 = new PrintThread(1, print,"1");
		Thread printThread2 = new PrintThread(1, print2,"2");
		Thread printThread3 = new PrintThread(1, print,"3");
		Thread printThread4 = new PrintThread(1, print2,"4");
		Thread printThread5 = new PrintThread(1, print,"5");
		printThread1.start();
		printThread2.start();
		printThread3.start();
		printThread4.start();
		printThread5.start();
		
	}
	
}

class PrintThread extends Thread{
	int type;
	Synchronized_2 print;
	String name;
	public PrintThread(int type ,Synchronized_2 print,String name){
		this.type  = type;
		this.print = print;
		this.name = name;
		
	}

	@Override
	public void run() {
		switch(type){
		case 1:
			print.printClass(name);
			break;
		case 2:
			print.printThis(name);
			break;
		case 3:
			print.print(name);
			break;
		}
	}
	
	
}

