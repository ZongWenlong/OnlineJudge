package leetcode.main;

public class AddTwoNumbers {
	 public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
	        int addBit = 0;
	        int addNum = 0;
	        ListNode resultNode = null;
	        ListNode currentNode = resultNode;
	        while(l1 != null && l2 != null){
	            addNum = l1.val + l2.val + addBit;
	            ListNode newNode = null;
	            if(addNum >= 10){
	                newNode = new ListNode(addNum - 10);
	                addBit = 1;
	            }
	            else{
	                newNode = new ListNode(addNum);
	                addBit = 0;
	            }
	            l1 = l1.next;
	            l2 = l2.next;
	            if(currentNode == null){
	                resultNode = newNode;
	            }
	            else{
	                currentNode.next = newNode;
	            }
	            currentNode = newNode;
	            
	        }
	        
	        while(l1 != null){
	            addNum = l1.val + addBit;
	            ListNode newNode = null;
	            if(addNum >= 10){
	                newNode = new ListNode(addNum - 10);
	                addBit = 1;
	            }
	            else{
	                newNode = new ListNode(addNum);
	                addBit = 0;
	            }
	            if(currentNode == null){
	                resultNode = newNode;
	            }
	            else{
	                currentNode.next = newNode;
	            }
	            currentNode = newNode;
	            l1 = l1.next;
	        }
	        
	         while(l2 != null){
	            addNum = l2.val + addBit;
	            ListNode newNode = null;
	            if(addNum >= 10){
	                newNode = new ListNode(addNum - 10);
	                addBit = 1;
	            }
	            else{
	                newNode = new ListNode(addNum);
	                addBit = 0;
	            }
	            if(currentNode == null){
	                resultNode = newNode;
	            }
	            else{
	                currentNode.next = newNode;
	            }
	            currentNode = newNode;
	            l2 = l2.next;
	        }
	        
	        if(addBit == 1){
	            ListNode newNode = new ListNode(1);
	            currentNode.next = newNode;;
	            currentNode = newNode;
	        }
	        if(currentNode != null){
	            currentNode.next = null;
	        }
	        return resultNode;
	    }
}
