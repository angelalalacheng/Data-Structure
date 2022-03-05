#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>

struct data{
    char alp;
    int frequence;
    struct data *next;
};
typedef struct data* data_ptr;

data_ptr createData(char what){
    data_ptr newData;
    newData= malloc(sizeof(struct data));
    newData->alp=what;
    newData->frequence=1;
    newData->next=NULL;
    return newData;
}

int num=0;
data_ptr head= NULL;
void add_data(char what){
    data_ptr current=head;
    if(head==NULL) {
        head=createData(what);
    }
    else{
        while(current->next != NULL){
            current=current->next;
        }
        current->next=createData(what);
    }
    num++;
}

void search_data(char what, data_ptr link){
    data_ptr move=link;
    while(move!=NULL){
        if(move->alp==what){
            move->frequence++;
            return;
        }
        else move=move->next;
    }
    add_data(what);
}

data_ptr sma_1=NULL;
data_ptr sma_2=NULL;
void find_small(data_ptr head){
    data_ptr original=head;
    //find the smallest
    int small=head->frequence;
    sma_1=head;
    while(head != NULL){
        if(head->frequence < small){
            small=head->frequence;
            sma_1=head;
        }
        head=head->next;
    }

    //find the second smallest
    head=original;
    small=head->frequence;
    sma_2=head;
    if(head==sma_1){
        sma_2=sma_1->next;
    }
    while(head != NULL){
        if(head->frequence <= small && head!=sma_1){
            small=head->frequence;
            sma_2=head;
        }
        head=head->next;
    }
}

int Huffman(data_ptr head){
    int preserve=0;
    while(num>1){
        data_ptr find=head;
        find_small(head);
        sma_1->frequence += sma_2->frequence;
        preserve+=sma_1->frequence;
        while(find!= NULL){
            if(sma_2==head){
                head=sma_2->next;
                free(sma_2);
                num--;
                break;
            }
            if(find->next == sma_2){
                find->next=sma_2->next;
                free(sma_2);
                num--;
                break;
            }
            find=find->next;
        }
    }
    return preserve;
}

int main(){
    char input [1000];
    fgets(input, 1000, stdin);
    while(input[0]!='-' && input[1]!='1' && input[2]!=EOF){
        for(int i=0; i<strlen(input);i++){
            if((input[i]>=65 && input[i]<=90) || (input[i]>=97 && input[i]<=122)){
                search_data(input[i], head);
            }
            else continue;
        }
        printf("> %d\n\n", Huffman(head));
        head=NULL;
        num=0;
        fgets(input, 1000, stdin);
    }
}

