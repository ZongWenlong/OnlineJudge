/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }
        ListNode* tail = head;
        
        int size = 1;
        while(tail -> next != NULL){
            tail = tail -> next;
            size ++;
        }
        k = k % size;
        if(k == 0){
            return head;
        }
        else{
            tail -> next = head;
            k = size - k;
            for(int i = 0;i < k;i++){
                tail = tail -> next;
            }
            
            ListNode* newHead = tail -> next;
            tail -> next = NULL;
            return newHead;
        }
    }
};