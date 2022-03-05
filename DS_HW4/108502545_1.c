#include <stdio.h>
#include <stdlib.h>

void print_data(int arr[], int num){
    printf("> ");
    for(int i=0;i<num;i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

void swap(int arr[], int L, int R){
    int tmp;
    tmp=arr[R];
    arr[R]=arr[L];
    arr[L]=tmp;
}

void quick_sort(int data[], int L, int R){
    if(L>=R) return;

    int pivot=data[L];
    int left=L+1;
    int right=R;

    while(left<right){
        while(data[left]<pivot && left<=R) left++;
        while(data[right]>pivot && right>=left) right--;//judge the edge QAQ

        if(left<right) swap(data, left, right);
        else swap(data, L, right);
    }

    if(left==right){
        if(data[L]>data[R]) swap(data, L, R);// when remain only two data
    }

    quick_sort(data, L, right-1);
    quick_sort(data, right+1, R);

}

int main(){
    int num, input;
    scanf("%d", &num);

    while(num != -1){
        // input numbers
        int data[num];

        for(int i=0; i<num; i++){
            scanf("%d", &input);
            data[i]=input;
        }
        // quick sort
        quick_sort(data, 0, num-1);
        print_data(data, num);
        // next loop
        scanf("%d", &num);
        memset(data, ' ', sizeof(data));
    }
}

