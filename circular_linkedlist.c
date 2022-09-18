#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
} ;
struct node *start =NULL;
struct node *create(struct node*);
struct node *insertbeg(struct node*);
struct node *insertend(struct node*);
struct node *deletebeg(struct node*);
struct node *deleteend(struct node*);
struct node *deleteafter(struct node*);
struct node *deletelist(struct node*);
struct node *display(struct node*);

int main()
{
    int a;
    do{
        printf("\nENTER 1 TO CREATE A LIST \n");
        printf("ENTER 2 TO INSERT A NODE AT BEGINNING\n");
        printf("ENTER 3 TO INSERT A NODE AT END\n");
        printf("ENTER 4 TO DELETE A NODE AT BEGINNING\n");
        printf("ENTER 5 TO DELETE A NODE AT END\n");
        printf("ENTER 6 TO DELETE A NODE AFTER A NODE\n");
        printf("ENTER 7 TO DELETE THE ENTIRE LIST\n");
        printf("ENTER 8 TO DISPLAY THE LIST\n");
        printf("ENTER 9 TO EXIT\n");
        printf("ENTER YOUR OPTION\n");
        scanf("%d",&a);
        switch(a)
        {
            case 1: start=create(start);
            printf("\nLINKED LIST CREATED");
            break;
            case 2: start=insertbeg(start);
            break;
            case 3: start=insertend(start);
            break;
            case 4: start=deletebeg(start);
            printf("THE ELEMENT IS DELETED");
            break;
           case 5: start=deleteend(start);
                       printf("THE ELEMENT IS DELETED");

            break;
            case 6: start=deleteafter(start);
                        printf("THE ELEMENT  IS DELETED ");

            break;
            case 7: start=deletelist(start);
            printf("LIST DELETED");
            break;
            case 8: start=display(start);
            break;
 }
        }
        while(a!=9);
        return 0;
   
}

struct node*create()
{
    struct node *newnode,*ptr;
    int num;
    printf("\nENTER THE DATA");
    printf("\nADD -1 AT THE END: ");
    scanf("%d",&num);
    while(num!=-1)
    {
        newnode= (struct node*)malloc(sizeof(struct node));
        newnode->data=num;
        if(start==NULL)
        {
            newnode->next=newnode;
            start=newnode;

        }
        else
        {
            ptr=start;
            while(ptr->next!=start)
            
                ptr=ptr->next;
                ptr->next=newnode;
                newnode->next=start;
            
            

        }
        printf("ENTER THE DATA: ");
            scanf("%d",&num);
    }
    return start;
}
struct node*insertbeg()
{
    struct node *newnode ,*ptr;
    int num;
    printf("ENTER THE DATA:");
    scanf("%d",&num);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    ptr=start;
    while(ptr->next!=start)
    
        ptr=ptr->next;

    ptr->next=newnode;
    newnode->next=start;
    start=newnode;
    return start;
}
struct node* insertend(struct node *start)
{
struct node *newnode ,*ptr;
    int num;
    printf("ENTER THE DATA YOU WANT AT THE END:");
    scanf("%d",&num);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    ptr=start;
    while(ptr->next!=start)
    ptr=ptr->next;
    ptr->next=newnode;
    newnode->next=start;
    return start;
}
struct node*deletebeg()
{
    struct node *ptr;
    ptr=start;
    while(ptr->next!=start){
    ptr=ptr->next;    }  
    ptr->next=start->next;
    free(start);
    start=ptr->next;
    return start;
}
struct node *deleteend(struct node *start)
{
    struct node *ptr,*preptr;
    ptr=start;
    while(ptr->next!=start)
    {
        preptr=ptr;
        ptr=ptr->next;

    }
    preptr->next=ptr->next;
  //  if(ptr==start)
    //start=preptr->next;
    free(ptr);
    return start;
    }
    struct node*deleteafter(struct node *start)
    {
        struct node*ptr,*preptr;
        int val;
        printf("ENTER THE VALUE AFTER WHICH THE NODE HAS TO BE DELETED  ");
        scanf("%d",&val);
        ptr=start;
        preptr=ptr;
        while(preptr->data!=val)
        {
            preptr=ptr;
            ptr=ptr->next;

        }
        preptr->next=ptr->next;
        if(ptr==start)
            start=preptr->next;
            free(ptr);
            return start;
        
    }
    struct node*deletelist(struct node *start)
    {
        struct node *ptr;
        ptr=start;
        while(ptr->next!=start)
        start=deleteend(start);
        free(start);
        return start;
    }
struct node *display(struct node*start)
{
    struct node *ptr;
    ptr=start;
    while(ptr->next!=start)
    {
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d  ",ptr->data);
    return start;
}
