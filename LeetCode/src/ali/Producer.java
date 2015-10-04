package ali;

public class Producer implements Runnable {
	private AppleBox appleBox;  
	  
    public Producer(AppleBox appleBox) {  
        this.appleBox = appleBox;  
    }  
  
    @Override  
    public void run() {  
        for (int i = 0; true; i++) {  
            try {  
                Thread.sleep((long) (Math.random() * 1000));  
            } catch (InterruptedException e) {  
                e.printStackTrace();  
            }  
            appleBox.increace();  
        }  
    }  
}
