#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>

struct data{
    int number;
    struct data* left;
    struct data* right;
};

typedef struct data* data_ptr;

data_ptr createData(int num){
    data_ptr newData;
    newData= malloc(sizeof(struct data));
    newData->number=num;
    newData->right=NULL;
    newData->left=NULL;
    return newData;
}

data_ptr head=NULL;
void binary_search_tree(int num){

    data_ptr current=head;

    while(1){
        if(head==NULL) {
            head=createData(num);
            break;
        }

        else if(num < current->number && current->left == NULL){
            current->left=createData(num);
            break;
        }

        else if(num>=current->number && current->right == NULL){
            current->right=createData(num);
            break;
        }

        else{
            if(num < current->number && current->left != NULL){
                current=current->left;
            }
            else{
                current=current->right;
            }
        }
    }
}

void printPreorder(data_ptr link) {
    data_ptr node=link;
    if (node == NULL) return;
    printf("%d ", node->number);
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(data_ptr link) {
    data_ptr node=link;
    if (node == NULL) return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->number);
}

int main(){
    int count, input;
    scanf("%d", &count);
    while(count!=-1){
        for(int i=0;i<count;i++){
            scanf("%d", &input);
            binary_search_tree(input);
        }
        printf("> Preorder: ");
        printPreorder(head);
        printf("\n> Postorder: ");
        printPostorder(head);
        printf("\n\n");
        head=NULL;
        scanf("%d", &count);
    }
}
