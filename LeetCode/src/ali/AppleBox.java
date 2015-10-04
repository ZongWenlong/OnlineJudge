package ali;

/** 
 * ������Դƻ�������� 
 */  
public class AppleBox {  
    private int appleNum = 0;  
  
    /** 
     * ����ƻ�� 
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
        System.out.println("���Ӻ��ƻ��������" + appleNum);  
        notify();  
    }  
  
    /** 
     * ����ƻ�� 
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
        System.out.println("���ٺ��ƻ��������" + appleNum);  
        notify();  
    }  
}  