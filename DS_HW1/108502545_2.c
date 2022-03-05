#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//stack
#define Max_value 10000
char stack[Max_value];
int top=-1;
void pop();
void push(char a);

//postfix
int get_token_value(char t);
void toPostfix(char input);

//calculate stack
float cal[Max_value];
void pop_cal();
void push_cal(float a);
float operand(char op,float num1,float num2);
float calPostfix();

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

//postfix function
char result[10000];
void toPostfix(char input){
    int values[4]={1,1,2,2}; //token[4]={'+','-','*','/'}; 括號另外判斷
    //判斷(
    if(input=='('){
        push(input);
    }
    //判斷)
    else if(input==')'){
        while(stack[top]!='('){
            result[strlen(result)]=stack[top];
            pop();
        }
        pop();
    }
    //判斷數字
    else if(input>=48 && input<=57){
        result[strlen(result)]=input;
    }
    //判斷+-*/
    else{
        int isp=values[get_token_value(stack[top])];
        int icp=values[get_token_value(input)];

        if(isp>=icp){
            result[strlen(result)]=stack[top];
            pop();
        }
        else{
            push(input);
        }
    }
}

int get_token_value(char t){
    if(t=='+')return 0;
    if(t=='-')return 1;
    if(t=='*')return 2;
    if(t=='/')return 3;
}

//calculate stack function
void pop_cal(){
    if(top==-1){
        printf("stack is empty");
    }
    else{
        cal[top]='\0';
        top--;
    }
}

void push_cal(float a){
    if(top<Max_value-1){
        top++;
        cal[top]=a;
    }
    else{
        printf("stack is full");
    }
}

float calPostfix(){
    int i=0;
    for(i=0;i<strlen(result);i++){
        if(result[i]>=48 && result[i]<=57){
            push_cal(result[i]-48);
        }
        else{
            float almost_ans=operand(result[i],cal[top-1],cal[top]);
            cal[top-1]=almost_ans;
            pop_cal();
        }
    }

    return cal[0];
}

float operand(char op,float num1,float num2){
    switch(op){
        case '+':
            return num1+num2;
            break;
        case '-':
            return num1-num2;
            break;
        case '*':
            return num1*num2;
            break;
        case '/':
            return num1/num2;
            break;
    }
}

int main(){
    char string[10000];
    scanf("%s",string);
    while(string[0]!='-' && string[1]!='1' && string[2]!='\0'){
        int i=0;
        for(i=0;i<strlen(string);i++){
            toPostfix(string[i]);
        }

        int j=0;
        printf("> ");
        for(j=0;j<strlen(result);j++){
            printf("%c ",result[j]);
        }

        printf("\n");

        int final_ans;
        int plus_or_not=(int)(calPostfix()*10)%10;
        if(plus_or_not>=0 && plus_or_not<=4){
            final_ans=(int)calPostfix();
        }
        else if(plus_or_not>=5 && plus_or_not<=9){
            final_ans=(int)calPostfix()+1;
        }
        printf("> %d\n",final_ans);

        //重新初始化
        memset(result,'\0',sizeof(result));
        memset(cal,'\0',sizeof(cal));
        top=-1;
        scanf("%s",string);
     }

}
