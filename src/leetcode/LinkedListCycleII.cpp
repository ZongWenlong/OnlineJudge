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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL){
            return NULL;
        }
        else{
            ListNode* fast = head;
            ListNode* slow = head;
            while(fast != NULL && fast -> next != NULL){
                slow = slow -> next;
                fast = fast -> next -> next;
                if(slow == fast){
                    break;
                }
            }
            if(fast == NULL || fast -> next == NULL){
                return NULL;
            }
            else{
                while(head != fast){
                    head = head -> next;
                    fast = fast -> next;
                }
                return fast;
            }
        }
        
    }
};