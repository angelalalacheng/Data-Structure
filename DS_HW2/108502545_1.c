#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//declare a queue
#define q_size 10000
typedef struct queue queue;
struct queue{
    int front, rear;
};
front=0;
rear=0;
int element[q_size];

//declare queue function
void Push(int num);
void Pop();
bool isEmpty();
bool isFull();
void getFront();
void printQueue();

//implement of queue function
void Push(int num){
    if(isFull()) return;

    else{
        element[rear]=num;
        rear++;
    }
}

void Pop(){
    if(isEmpty()) {
        printf("> %d", -3);
        return;
    }
    else front++;
}

bool isEmpty(){
    return (front==rear);
}

bool isFull(){
    return (rear+1==q_size);
}

void getFront(){
    int target;
    if(isEmpty()) {
        printf ("> %d", -2);
        return;
    }

    else {
        target=element[front];
        printf("> %d", target);
    }
}

void printQueue(){
    if(isEmpty()) return;

    int i;
    for(i=front;i<rear;i++){
        printf("%d ", element[i]);
    }
}

int main(){
    queue Q;
    int input, addNum;
    scanf("%d", &input);

    while(input!=-1){
        switch(input){
            case 1:
                scanf("%d", &addNum);
                Push(addNum);
                break;
            case 2:
                getFront();
                break;
            case 3:
                Pop();
                break;
            default:
                break;
        }

        scanf("%d", &input);
    }
}
