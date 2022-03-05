#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//stack
#define Max_value 10000
char stack[Max_value];
int top=-1;
void pop();
void push(char a);
int judge(char j);

//stack function
void pop(){
    if(top==-1){
        printf("stack is empty");
    }

    else{
        stack[top]='\0';
        top--;
    }
}

void push(char a){
    if(top<Max_value-1){
        top++;
        stack[top]=a;
    }

    else{
        printf("stack is full");
    }
}

int judge(char j){
    switch(j){
        case ')':
            if(stack[top]=='(') {
                pop();return -1;
            }
        case ']':
            if(stack[top]=='[') {
                pop();return -1;
            }
        case '}':
            if(stack[top]=='{') {
                pop();return -1;
            }
        default:
            return 1;break;
    }

}

int main(){
    //建立字元陣列 strlen算長度
    char fake_string[10000];
    scanf("%s",fake_string);
    int break_or_not=0;

    while(fake_string[0]!='-' && fake_string[1]!='1' && fake_string[2]!='\0'){
        //判斷()[]{}的ASCii碼
        int i=0;
        for(i=0;i<strlen(fake_string);i++){
            if(fake_string[i]==40||fake_string[i]==91||fake_string[i]==123){
                push(fake_string[i]);
            }

            if(fake_string[i]==')'||fake_string[i]==']'||fake_string[i]=='}'){
                break_or_not=judge(fake_string[i]);
                if(break_or_not==1)break;
            }
        }

        if(top==-1 && break_or_not==-1) printf("> Balanced\n");
        else if(top==-1 && break_or_not==1)printf("> Unbalanced\n");
        else printf("> Unbalanced\n");

        //重新初始化
        memset(fake_string,"\0",sizeof(fake_string));
        top=-1;
        scanf("%s",fake_string);
    }
}
