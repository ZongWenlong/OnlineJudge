package ali;

 
public class AppleIO {  
	public static void main(String[] args) {  
        AppleBox appBox = new AppleBox();  
        new Thread(new Producer(appBox)).start();  
        new Thread(new Consumer(appBox)).start();  
        
    }  
}  