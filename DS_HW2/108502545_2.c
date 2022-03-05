#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//declare node
struct node{
    int data;
    struct node *next;
};
typedef struct node* node_ptr;

// declare a queue
struct queue{
    node_ptr  front, rear;
};
typedef struct queue queue;


//declare queue function
node_ptr createNode(int num);
void Push(queue* Que, int num);
void Pop(queue* Que);
bool isEmpty(queue* Que);
void getFront(queue* Que);

//implement queue function
node_ptr createNode(int num){
    node_ptr newNode;
    newNode= malloc(sizeof(struct node));
    newNode->data=num;
    newNode->next=NULL;
    return newNode;
}

void Push(queue* Que, int num){
    node_ptr New=createNode(num);

    if((Que->rear)==NULL) {
        Que->front=New;
    }
    else{
        (Que->rear)->next=New;
    }

    Que->rear=New;
}

void Pop(queue* Que){
    node_ptr p=malloc(sizeof(struct node));
    p=Que->front;

    if(isEmpty(Que)) {
        printf("> %d", -3);
        return;
    }
    else{
        Que->front=(Que->front)->next;
    }

    if(isEmpty(Que)) Que->rear=NULL;
    free(p);
}

bool isEmpty(queue* Que){
    return((Que->front)==NULL);
}

void getFront(queue* Que){
    if(isEmpty(Que)){
        printf ("> %d", -2);
        return;
    }

    else{
        printf("> %d", (Que->front)->data);
    }
}

int main(){
    queue Q;
    Q.front=NULL;
    Q.rear=NULL;

    int input, addNum;
    scanf("%d", &input);

    while(input!=-1){
        switch(input){
            case 1:
                scanf("%d", &addNum);
                Push(&Q, addNum);
                break;
            case 2:
                getFront(&Q);
                break;
            case 3:
                Pop(&Q);
                break;
            default:
                break;
        }

        scanf("%d", &input);
    }
}
