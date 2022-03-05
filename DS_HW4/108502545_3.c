#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node{
    int* position;
    bool head;
    struct node* link;
    struct node* next;
};
typedef struct node* node_ptr;

node_ptr createNode(int* pos){
    node_ptr newNode;
    newNode= malloc(sizeof(struct node));
    newNode->position=pos;
    newNode->next=NULL;
    newNode->link=NULL;
    return newNode;
}

void BFS(node_ptr start_Pos, int flow){
    node_ptr move_right=start_Pos;
    node_ptr move_down=start_Pos;
    while(move_down!=NULL){
        if(*(move_down->position)==flow){
            move_right=move_down;
            while(move_right!=NULL){
                if(*(move_right->position)==1) *(move_right->position)=flow+1;
                move_right=move_right->next;
            }
        }
        move_down=move_down->link;
    }
    flow++;

    //condition to return
    move_down=start_Pos;
    while(move_down!=NULL){
        if(*(move_down->position)==1) break;
        if(move_down->link==NULL && *(move_down->position)!=1) return;
        move_down=move_down->link;
    }
    BFS(start_Pos, flow);
}

int main(){
    int row, column;
    scanf("%d %d", &row, &column);

    while(row!=-1 && column!=-1){
    // input water pipe map
        int waterpipe[row][column];
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                scanf("%d", &waterpipe[i][j]);
            }
        }
     // create adjacency list
     node_ptr boss;//total head
     node_ptr head_link;
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                if(waterpipe[i][j]!=0){
                    // create head
                    node_ptr point=createNode(&waterpipe[i][j]);
                    // create head_link to link the point
                    if(i==0) {
                        boss=point;
                        head_link=point;
                    }
                    else{
                        head_link->link=point;
                        head_link=head_link->link;
                    }
                    //create tail to link the neighbor
                    node_ptr tail=point;
                    // find its neighbor
                    if (j+1<=column-1 && waterpipe[i][j+1]!=0) {
                        node_ptr neighbor=createNode(&waterpipe[i][j+1]);
                        tail->next=neighbor;
                        tail=tail->next;
                    }
                    if (j-1>=0 && waterpipe[i][j-1]!=0) {
                        node_ptr neighbor=createNode(&waterpipe[i][j-1]);
                        tail->next=neighbor;
                        tail=tail->next;
                    }
                    if (i+1<=row-1 && waterpipe[i+1][j]!=0) {
                        node_ptr neighbor=createNode(&waterpipe[i+1][j]);
                        tail->next=neighbor;
                        tail=tail->next;
                    }
                    if (i-1>=0 && waterpipe[i-1][j]!=0) {
                        node_ptr neighbor=createNode(&waterpipe[i-1][j]);
                        tail->next=neighbor;
                        tail=tail->next;
                    }
                }
            }
        }
        //BFS
        *(boss->next->position)=2;
        BFS(boss, 2);
        *(boss->position)=1;
        //print answer
        for(int i=0; i<row;i++){
            printf("> ");
            for(int j=0;j<column;j++){
                printf("%d ", waterpipe[i][j]);
                if(j==(column-1)) printf("\n");
            }
        }
        printf("\n");

        //next loop
        scanf("%d %d", &row, &column);
    }
}
