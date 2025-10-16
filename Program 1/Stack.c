#include<stdio.h>

#define N 5

int stack[N];
int top=-1;

void push(){
    int x;
    printf("Enter data:");
    scanf("%d", &x);

    if (top==N-1){
        printf("Stack Overflow\n");
    }
    else{
        top++;
        stack[top]=x;
    }
}

void pop(){
    int ele;

    if(top==-1){
        printf("Stack Underflow\n");
    }
    else{
        ele=stack[top];
        printf("Element deleted is %d \n", ele);
        top--;
    }
}

void peek(){
    if(top==-1){
        printf("Stack Underflow\n");
    }
    else{
        printf("Top=%d \n", stack[top]);
    }
}

void display(){
    for(int i=0;i<=top;i++){
        printf("%d \n",stack[i]);
    }
}

int main(){
    int choice;

    while (choice!=5){
        printf("Enter operation to be performed: 1-push, 2-pop, 3-peek, 4-display, 5-exit \n");
        scanf("%d", &choice);

        switch(choice){
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: peek();
            break;
            case 4: display();
            break;
            case 5: break;

            default: printf("Invalid choice entered\n");
        }
    }
}
