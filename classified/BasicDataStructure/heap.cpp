#include <iostream>
using namespace std;

#define MAX_SIZE 20

int heap[MAX_SIZE];
int size = 0;

int pop(){
    if(size > 0){
        int result = heap[0];
        size --;
        if(size > 0){
            int temp = heap[size];

            int i = 0;
            while(i * 2 + 1 < size){
                int left = i * 2 + 1;
                int right = i * 2 + 2;
                if(right < size && heap[left] > heap[right]){
                    left = right;
                }
                if(heap[left] < temp){
                    heap[i] = heap[left];
                    i = left;
                }
                else{
                    break;
                }
            }
            heap[i] = temp;
        }
        return result;

    }
    else{
        return -1;
    }

}
void push(int num){
    int i = size++;
    while(i > 0){
        int par = (i -  1) /2;
        if(heap[par] > num){
            heap[i] = heap[par];
            i = par;
        }
        else{
            break;
        }
    }
    heap[i] = num;
}


int main ()
{
    int temp[] = {22,11,0,7,6,5,4,3,2,1};
    for(int i = 0; i < 10;i++){
        push(temp[i]);
    }
    for(int i = 0; i < 10;i++){
        cout<<heap[i]<<endl;
    }
    while(size > 0){
        cout<<pop()<<endl;
    }

  return 0;
}
