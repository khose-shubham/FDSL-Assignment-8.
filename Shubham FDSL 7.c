#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top, *temp, *newnode;

void push()
{
newnode = (struct node*)malloc(sizeof(struct node));
printf("\nEnter element: ");
scanf("%d",&newnode->data);

if (top == NULL){
    top = newnode;
    newnode->next = NULL;
    }
else{
    newnode->next = top;
    top = newnode;
    }
}

void pop()
{
if(top == NULL){
    printf("Stack Underflow!");
    }
else{
    temp = top;
    printf("\nElement Deleted: %d\n",temp->data);
    top = top->next;
    temp->next = NULL;
    free(temp);
    }
}

void display()
{
int i = 1;
temp = top;
printf("\nStack:\n");
while(temp != NULL){
    printf("node %d | Data: %d | address: %p | next_address: %p\n",i,temp->data,temp,temp->next);
    temp = temp->next;
    i++;
    }
}

void main()
{
top = NULL;

int ch = 0;
while(ch !=4){
    printf("\nEnter Choice:\n1.Push\n2.Pop\n3.Display\n4.Exit ");
    scanf("%d",&ch);
    
    if(ch == 1){
        push();
    }
    else if(ch == 2){
        pop();
    }
    else if(ch == 3){
        display();
    }
    else if(ch == 4){
        printf("Exiting program...");
        return 0;
    }
    else{
        printf("Invaild choice...");
    }
}
}