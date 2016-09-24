
// accessing mapped values
#include <iostream>
#include <map>
#include <string>
#include <list>
using namespace std;


 struct RandomListNode {
     int label;
   RandomListNode *next, *random;
   RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

  RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return NULL;
        RandomListNode *newHead = NULL;
        RandomListNode *preNode = NULL,*curNode = NULL;
        RandomListNode *headTemp = head;
        map<int,RandomListNode *> newListMap;
        map<RandomListNode *,int> oldListMap;
        int count = 0;

        // deep copy of the list with next pointer information
        while(headTemp != NULL){
            curNode = new RandomListNode(headTemp -> label);
            oldListMap[headTemp] = count;
            newListMap[count] = curNode;

            if(newHead == NULL){
                newHead = curNode;
            }
            else{
                preNode -> next = curNode;
            }
            preNode = curNode;
            headTemp = headTemp -> next;
        }
        curNode -> next = NULL;

        // copy the random pointer information
        curNode = newHead;
        while(head != NULL){
            curNode -> random = newListMap[oldListMap[head]];
            head = head -> next;
            curNode = curNode -> next;
        }

        return newHead;

    }

    int main()
    {
        RandomListNode * head = new RandomListNode(-1);
          RandomListNode * headTemp = copyRandomList(head);
          if(headTemp == NULL){
            cout<<"----";
          }
        return 0;
    }
