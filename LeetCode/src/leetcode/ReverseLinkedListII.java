package leetcode.main;

public class ReverseLinkedListII {
	public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode leftNode = null;
        ListNode rightNode = null;
        ListNode curNode = head;
        ListNode preNode = null;
        ListNode tempNode = null;
        boolean headFlag = true;
        if(m == n){
            return head;
        }

        while(curNode != null){
            if(m > 1){
                m --;
                n--;
                preNode = curNode;
                curNode = curNode.next;
            }
            else if(m == 1){
                leftNode = preNode;
                rightNode = curNode;
                m--;
                n--;
                preNode = curNode;
                curNode = curNode.next;
                
                
            }
            else{
                if(n > 1){
                    tempNode = curNode.next;
                    curNode.next = preNode; 
                    preNode = curNode;
                    curNode = tempNode;
                    n--;
                }
                else{
                    rightNode.next = curNode.next;
                    curNode.next = preNode;
                    if(leftNode != null){
                        leftNode.next = curNode;
                        return head;
                    }
                    else{
                        return curNode;
                    }
                    
                }
            } 
        }
        return null;
    }
}
