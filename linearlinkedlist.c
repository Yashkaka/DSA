#include<stdio.h>
#include<stdlib.h>
//#include<malloc.h>
struct node
{
    int data;
    struct node *next;

};
struct node *start=NULL;
struct node *create();
struct node *insertbeg();
struct node *insertend();
struct node *insertbefore();
struct node *insertafter();
struct node *deletebeg(struct node*);
 struct node *deleteend();
 struct node *deleteafter();
struct node *deletelist();
struct node *deletenode();
struct node *sort();
struct node *display();

int main(){
    int val;
    do{
        printf("\n ENTER 1 TO CREATE LINKED LIST ");
        printf("\n ENTER 2 TO ADD A NODE AT BEGINNING");
        printf("\n ENTER 3 TO ADD A NODE AT END");
        printf("\n ENTER 4 TO ADD A NODE BEFORE A NODE");
        printf("\n ENTER 5 TO ADD A NODE AFTER A NODE");
        printf("\n ENTER 6 TO DELETE A NODE FROM BEGINNING");
        printf("\n ENTER 7 TO DELETE A NODE FROM END");
        printf("\n ENTER 8 TO DELETE A NODE AFTER A NODE");
        printf("\n ENTER 9 TO DELETE THE LIST");
        printf("\n ENTER 10 TO DELETE A GIVEN NODE");
        printf("\n ENTER 11 TO SORT ELEMENTS");
        printf("\n ENTER 12 TO DISPLAY");
        printf("\n ENTER 13 TO  EXIT");
        
        printf("\nENTER YOUR OPTION  ");
        scanf("%d",&val);
        switch(val)
        {
            case 1:start =create();
            break;
           case 2:start=insertbeg();
            break;
             case 3:start=insertend();
            break;
            case 4:start=insertbefore();
            break;
            case 5:start=insertafter();
            break;
            case 6:start=deletebeg(start);
            break;
            case 7:start=deleteend();
            break;
            case 8:start=deleteafter();
            break;
            case 9:start=deletelist();
            break;
            
          case 10:start=deletenode();
            break;
            case 11:start=sort();
            break;
            case 12:start=display();
            break;
        }
    }
            while(val!=13);
            return 0;
    }         

struct node *create()
{
    struct node *newnode,*ptr;
    int num;
    printf("ENTER -1 AT THE END\n");
    printf("ENTER THE DATA:  ");
    scanf("%d",&num);
    while(num!=-1)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=num;
        if(start==NULL)
        {
            newnode->next=NULL;
            start=newnode;

        }
        else
        {
            ptr =start;
            while(ptr->next!=NULL)
            ptr=ptr->next;
            ptr->next=newnode;
            newnode->next=NULL;
        
        }
        printf("ENTER THE DATA:  ");
        scanf("%d",&num);
    }
    return start;
}
struct node*insertbeg()
{
    struct node *ptr,*newnode;
    int num;
    printf("ENTER THE DATA: ");
    scanf("%d",&num);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=start;
    start=newnode;
    return start;
}
struct node* insertend()
{
    struct node*ptr,*newnode;
    int num;
    printf("ENTER THE DATA: ");
    scanf("%d",&num);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;
    ptr=start;
    while(ptr->next!=NULL)
    
        ptr=ptr->next;
        ptr->next=newnode;
        return start;

    }

struct node*insertbefore()
    {
        struct node *ptr,*newnode,*preptr;
        int num,val;
        printf("ENTER THE DATA ");
        scanf("%d",&num);
        printf("ENTER THE VALUE BEFORE YOU WANT TO INSERT ");
        scanf("%d",&val);

        newnode=(struct node*)malloc(sizeof(struct node*));
        newnode->data=num;
       // newnode->next=NULL;
        ptr = start;
        while(ptr->data!=val)
        {
            preptr=ptr;
            ptr=ptr->next;

        }
         preptr->next=newnode;
         newnode->next=ptr;   
return start;
}

struct node*insertafter()
{
    struct node *newnode,*ptr,*preptr;
    int num,val;
    printf("ENTER THE DATA: ");
        scanf("%d",&num);
        printf("ENTER THE VALUE AFTER YOU WANT TO INSERT ");
        scanf("%d",&val);
        newnode=(struct node*)malloc(sizeof(struct node*));
        newnode->data=num;
        ptr=start;
        preptr=ptr;
        while(preptr->data!=val)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=newnode;
        newnode->next=ptr;
        return start;
}
struct node*deletebeg()
{
    struct node*newnode,*ptr;
    ptr=start;
    printf("%d IS DELETED\n",start->data);
    start=start->next;
    free(ptr);
    return start;
}

struct node*deleteend()
{
struct node*newnode,*ptr,*preptr;
ptr=start;
while(ptr->next!=NULL)
{
    preptr=ptr;
    ptr=ptr->next;
}
printf("%d is DELETED",ptr->data);
preptr->next=NULL;
free(ptr);
return start;
}
struct node*deleteafter()
{
    struct node*newnode,*ptr,*preptr;
    int val;
    printf("ENTER THE NODE AFTER WHICH HAS TO BE DELETED: ");
    scanf("%d",&val);
    ptr=start;
    preptr=ptr;
    while(preptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;

    }printf(" %d IS DELETED",ptr->data);
    preptr->next=ptr->next;
    free(ptr);
    return start;
}
struct node*deletelist()
    {
        struct node*ptr;
        if(start!=NULL)
        {
            ptr=start;
            while(ptr!=NULL)
            {
                start=deletebeg(ptr);
                ptr=start;
            }
        }
        return start;
    }
    struct node *deletenode(){
        struct node*ptr,*preptr;
        int val;
        printf("\nENTER THE NODE YOU WANT TO DELETE: ");
        scanf("%d",&val);
        ptr=start;
        if(ptr->data==val)
        {
            start=deletebeg(start);
            return start;
        }
        else
        {
            while(ptr->data!=val)
            {
                preptr=ptr;
                ptr=ptr->next;
            }
            preptr->next=ptr->next;
            free(ptr);
            return start;

        }
    }

struct node*sort()
{
    struct node*ptr1,*ptr2;
    int temp;
    ptr1=start;
    while(ptr1->next!=NULL)
    {
        ptr2=ptr1->next;
        while(ptr2!=NULL)
        {
            if(ptr1->data>ptr2->data)
            {
                temp=ptr1->data;
                ptr1->data=ptr2->data;
                ptr2->data=temp;
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    return display();
}

struct node*display()
{
    struct node*ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf(" %d",ptr->data);
        ptr=ptr->next;

    }
    printf("\n");
    return start;
}