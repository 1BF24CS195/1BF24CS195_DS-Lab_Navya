#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL;

void createList(){
    int n,i,data;
    struct Node *newNode,*temp;

    printf("Enter number of nodes in list:");
    scanf("%d",&n);

    if(n<=0){
        printf("Number of nodes should be greater than 0\n");
        return;
    }

    for(i=1;i<=n;i++){
        struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));

        if(newNode==NULL){
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter data for node %d:\n",i);
        scanf("%d",&data);
        newNode->data=data;
        newNode->next=NULL;


        if(head==NULL){
            head=newNode;
        }
        else{
            temp->next=newNode;
        }
        temp=newNode;
    }
    printf("Linked List created successfully\n");
}

void insertAtBeginning(){
    int data;
    printf("Enter data for node:\n");
    scanf("%d",&data);

    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));

    newNode->data=data;
    newNode->next=head;
    head=newNode;
    printf("Node inserted at beginning.\n");
}

void insertAtEnd(){
    int data;
    printf("Enter data for node:\n");
    scanf("%d",&data);

    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));

    newNode->data=data;
    newNode->next=NULL;

    if(head==NULL){
        head=newNode;
    }
    else{
        struct Node *temp=head;

        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newNode;
    }
    printf("Node inserted at the end.\n");
}

void insertAtPosition(){
    int data,pos,i;

    printf("Enter data for node:\n");
    scanf("%d",&data);

    printf("Enter position to insert node:\n");
    scanf("%d",&pos);

    struct Node *newNode;
    struct Node *temp=head;

    if(pos<1){
        printf("Invalid position\n");
        return;
    }

    if(pos==1){
        insertAtBeginning(data);
        return;
    }

    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;

    for(i=1;i<pos-1 && temp->next!=NULL;i++){
        temp=temp->next;
    }

    if(temp==NULL){
        printf("Position out of range\n");
        free(newNode);
    }
    else{
        newNode->next=temp->next;
        temp->next=newNode;
        printf("Node inserted at position %d.\n",pos);
    }
}

void display(){
    struct Node *temp=head;
    if(head==NULL){
        printf("Empty List\n");
        return;
    }
    printf("Linked list:\n");
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    int choice;

    while(choice!=6){
        printf("\n---Singly Linked List Operations---\n");
        printf(" 1.Create\n 2.Insert at Beginning\n 3.Insert at end\n 4.Insert at any position\n 5.Display\n 6.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:createList();
            break;
            case 2:insertAtBeginning();
            break;
            case 3: insertAtEnd();
            break;
            case 4: insertAtPosition();
            break;
            case 5:display();
            break;
            case 6: printf("Exiting...");
                break;
            default:printf("Invalid Choice\n");
        }
    }
    return 0;
}