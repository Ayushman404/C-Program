#include <stdio.h>
#include <stdlib.h>

typedef struct lifo{
    int value;
    struct lifo* next;
}stack;

void creatStack(stack** top){
    *top ==NULL;
}
void push(stack** top, int element){

    stack* newNode = (stack*)malloc(sizeof(stack));
    
    if(newNode==NULL){
        //space in not available
        printf("\n stack is full\n");
        exit(-1);
    }

    newNode->value = element;
    newNode->next = *top;
    *top = newNode;
}
int pop(stack** top){
    if(*top==NULL){
        printf("\nstack is empty\n");
        exit(-1);
    }
    else{
        int t = (*top)->value;
        stack* temp = *top;
        *top = (*top)->next;

        free(temp);
        temp = NULL;
        return t;
    }
}

int main(){
    stack* top;

    return 0;
}