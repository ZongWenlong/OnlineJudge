package multithread;

/**
 * 两个线程交替打印奇、偶数
 * @author Chung
 */
public class PrintInTurn {
	//true代表打印奇数
	private boolean state = true;
	
	private int oddNum = 1;
	private int evenNum = 0;
	private int max = 100;
	
	public static void main(String[] args){
		final PrintInTurn printer = new PrintInTurn();
		
		new Thread(new Runnable(
				) {
			
			@Override
			public void run() {
				while(printer.evenNum <= printer.max){
					synchronized(printer){
						if(printer.state == false){
							try {
								printer.wait();
							} catch (InterruptedException e) {
								// TODO Auto-generated catch block
								e.printStackTrace();
							}
						}
						
						System.out.println(printer.evenNum);
						printer.evenNum =  printer.evenNum + 2;
						printer.state = false;
						printer.notify();
					}
				}
				
			}
		}).start();
		
		new Thread(new Runnable(
				) {
			
			@Override
			public void run() {
				while(printer.oddNum <= printer.max){
					synchronized(printer){
						if(printer.state == true){
							try {
								printer.wait();
							} catch (InterruptedException e) {
								// TODO Auto-generated catch block
								e.printStackTrace();
							}
						}
						
						System.out.println(printer.oddNum);
						printer.oddNum =  printer.oddNum + 2;
						printer.state = true;
						printer.notify();
					}
				}
				
			}
		}).start();
	}
	
}
