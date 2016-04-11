public class PartitionList{
	public ListNode partition(ListNode head, int x) {
        ListNode leftNode = null;
        ListNode rightNode = null;
        ListNode leftHeadNode = null;
        ListNode rightHeadNode = null;
        
        for(;head != null;head = head.next){
            if(head.val < x){
                if(leftNode == null){
                    leftHeadNode = head;
                    leftNode = leftHeadNode;
                }
                else{
                    leftNode.next = head;
                    leftNode = leftNode.next;
                }
            }
            else{
                if(rightNode == null){
                    rightHeadNode = head;
                    rightNode = rightHeadNode;
                }
                else{
                    rightNode.next = head;
                    rightNode = rightNode.next;
                }
            }
        }
        
        if(leftHeadNode != null){
            leftNode.next = rightHeadNode;
            if(rightHeadNode != null){
                rightNode.next = null;
            }
            return leftHeadNode;
        }
        else if(rightHeadNode != null){
            rightNode.next = null;
            return rightHeadNode;
        }
        
        return null;
        
    }
}