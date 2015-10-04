package ali;

/** 
 * 公共资源苹果箱子类 
 */  
public class AppleBox {  
    private int appleNum = 0;  
  
    /** 
     * 增加苹果 
     */  
    public synchronized void increace() {  
        while (appleNum == 5) {  
            try {  
                wait();  
            } catch (InterruptedException e) {  
                e.printStackTrace();  
            }  
        }  
        appleNum++;  
        System.out.println("增加后的苹果数量：" + appleNum);  
        notify();  
    }  
  
    /** 
     * 减少苹果 
     */  
    public synchronized void decreace() {  
        while (appleNum == 0) {  
            try {  
                wait();  
            } catch (InterruptedException e) {  
                e.printStackTrace();  
            }  
        }  
        appleNum--;  
        System.out.println("减少后的苹果数量：" + appleNum);  
        notify();  
    }  
}  