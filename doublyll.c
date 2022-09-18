#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node*next;
    int data;
    struct node*prev;
};
struct node *start=NULL;
struct node *create(struct node*);
struct node *display(struct node*);
struct node *insertbeg(struct node*);
struct node *insertend(struct node*);
struct node *insertbefore(struct node*);
struct node *insertafter(struct node*);
struct node *deletebeg(struct node*);
struct node *deleteend(struct node*);
struct node *deletebefore(struct node*);
struct node *deleteafter(struct node*);
struct node*deletelist(struct node*);
int main()
{
    int a;
    do
    {
        printf("\n  MENU");
        printf("\n1. create a list");
        printf("\n2. display a list");
        printf("\n3. add a node at beginning");
        printf("\n4. add a node at end");
        printf("\n5. add a node before a given node");
        printf("\n6. add a node after a given node");
        printf("\n7. delete a node from the beginning");
        printf("\n8. delete a node from the end");
        printf("\n9. delete a node before a give node");
        printf("\n10. delete a node after a give node");
        printf("\n11. delete  the entire list");
        printf("\n12  exit");
        printf("\nenter your option :");
        scanf("%d",&a);
        switch(a)
        {
            case 1: start =create(start);
            printf("\n doubly linked list created");
            break;
            case 2: start = display(start);
            break;
            case 3: start= insertbeg(start);
            break;
            case 4: start=insertend(start);
            break;
            case 5: start=insertbefore(start);
            break;
            case 6: start=insertafter(start);
            break;
            case 7: start=deletebeg(start);
            break;
            case 8: start=deleteend(start);
            break;
            case 9: start=deletebefore(start);
            break;
            case 10: start=deleteafter(start);
            break;
            case 11: start=deletelist(start);
            printf("doubly linked list deleted");
            break;
        }
    } while (a!=12);
    return 0;
    
}

struct node*create(struct node *start)
{
    struct node *newnode ,*ptr;
    int num;
    printf("-1 at the end\n");
    printf("enter the data :");
    scanf("%d",&num);
    while(num!=-1)
    {
        if(start==NULL)
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->prev=NULL;
            newnode->data=num;
            newnode->next=NULL;
            start=newnode;

        }
        else{
            ptr=start;
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=num;
            while(ptr->next!=NULL)  
            ptr=ptr->next;
            ptr->next=newnode;
            newnode->prev=ptr;
            newnode->next=NULL;
}
printf(" enter the data :");
scanf("%d",&num);

    }
return start;
}
struct node*display(struct node *start)
{
    struct node*ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    }
    return start;
}

struct node*insertbeg(struct node*start)
{

struct node*newnode;
int num;
printf("enter the data :");
scanf("%d",&num);
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=num;
start->prev=newnode;
newnode->next=start;
newnode->prev=NULL;
start=newnode;
return start;
}
struct node *insertend(struct node*start)
{
    struct node *newnode,*ptr;
    int num;
    printf("\nenter the data :");
    scanf("%d",&num);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=newnode;
    newnode->prev=ptr;
    newnode->next=NULL;
    return start;

        }

struct node*insertbefore(struct node *start)
{
    struct node *newnode,*ptr;
    int num,val;
    printf("\n enter the data :");
    scanf("%d",&num);
    printf("\nenter the number before which num has to be inserted :");
    scanf("%d",&val);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    ptr=start;
    while(ptr->data!=val)
    {
        ptr=ptr->next;

    }
    newnode->next=ptr;
    newnode->prev=ptr->prev;
    ptr->prev->next=newnode;
    ptr->prev=newnode;
    return start;
}

struct node*insertafter(struct node *start)
{
    struct node *newnode, *ptr;
    int num,val;
    printf("\n insert the data :");
    scanf("%d",&num);
    printf("enter the value after after which data has to be inserted :");
    scanf("%d",&val);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    ptr=start;
    while(ptr->data!=val)
    ptr=ptr->next;
    newnode->prev=ptr;
    newnode->next=ptr->next;
    ptr->next->prev=newnode;
    ptr->next=newnode;
    return start;
}
struct node*deletebeg(struct node *start)
{
    struct node *ptr;
    ptr=start;
    start=start->next;
    start->prev=NULL;
    free(ptr);
    return start;
}
struct node*deleteend(struct node*start)
{
    struct node *ptr;
    ptr=start;
    start=start->next;
    start->prev=NULL;
    free(ptr);
    return start;
}
struct node *deletebefore(struct node*start){
    struct node*ptr,*temp;
    int val;
    printf("\nenter the value before which the node has to be deleted :");
    scanf("%d",&val);
    ptr=start;
    while(ptr->data!=val)
    ptr=ptr->next;
    temp=ptr->prev;
    if(temp==start)
    {
        start=deletebeg(start);
    }
    else{
        ptr->prev=temp->prev;
        temp->prev->next=ptr;

    }
    free(temp);
    return start;
}

struct node *deleteafter(struct node *start)
{
    struct node *ptr,*temp;
    int val;
    printf("\n enter the value after which the node has to be deleted :");
    scanf("%d",&val);
    ptr=start;
    while(ptr->data!=val)
    {
        ptr=ptr->next;
    }
    temp=ptr->next;
    ptr->next=temp->next;
    temp->next->prev=ptr;
    free(temp);
    return start;

}
struct node*deletelist(struct node*start)
{
while(start!=NULL)

   start =deletebeg(start);
   return start;



}