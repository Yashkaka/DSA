#include<stdio.h>
#include<stdlib.h>
struct node
{
    int num;
    int coeff;
    struct node *next;
};
struct node *start1=NULL;
struct node *start2=NULL;
struct node *start3=NULL;
struct node *start4=NULL;
struct node *last=NULL;
struct node *create(struct node*);
struct node *display(struct node*);
struct node *add(struct node*,struct node*,struct node*);
struct node *sub(struct node*,struct node*,struct node*);
struct node * addnode(struct node*,int,int);
int main()
{
    int a;
   do
   {
       printf("\n  *******MENU*******");
       printf("\n1. ENTER THE FIRST POLYNOMIAL");
       printf("\n2. DISPLAY THE FIRST POLYNOMIAL");
       printf("\n3. ENTER THE SECOND POLYNOMIAL");
       printf("\n4. DISPLAY THE SECOND POLYNOMIAL");
       printf("\n5. ADD THE POLYNOMIALS ");
       printf("\n6. DISPLAY THE RESULT ");
       printf("\n7. SUBTRACT THE POLYNOMIAL ");
       printf("\n8. DISPLAY THE RESULT ");
       printf("\n9. EXIT ");
       printf("\nENTER YOUR OPTION: ");
       scanf("%d",&a);
       switch(a)
       {
           case 1: start1=create(start1);
           break;
           case 2: start1=display(start1);
           break;
           case 3: start2= create(start2);
           break;
           case 4: start2= display(start2);
           break;
           case 5: start3=add(start1,start2,start3);
           printf("\n POLYNOMIALS ARE ADDED");
           break;
           case 6: printf("THE ADDITION OF POYNOMIALS ARE:\n");
           start3=display(start3);
           break;
           case 7: start4=sub(start1,start2,start4);
           printf("\n POLYNOMIALS ARE SUBTRACTED");
           break;
           case 8: printf("THE SUBTRACTION OF POYNOMIALS ARE:\n");
           start4=display(start4);
           break;
       }

   } while (a!=9);
   return 0;
}
struct node *create(struct node*start)
{
struct node *newnode,*ptr;
int n,c;
printf("ENTER THE NUMBER :");
scanf("%d",&n);
printf("ENTER THE COEFFICIENT :");
scanf("%d",&c);
while(n!=-1)
{
    if(start==NULL)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->num=n;
        newnode->coeff=c;
        newnode->next=NULL;
        start =newnode;
    }
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;

        }
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->num=n;
        newnode->coeff=c;
        newnode->next=NULL;
        ptr->next=newnode;
    }
    printf("ENTER THE NUMBER :");
    scanf("%d",&n);
    if(n==-1)
    break;
    printf("ENTER THE COEFFICIENT :");
    scanf("%d",&c);
    }
    return start;
}
struct node *display(struct node *start)
{
    struct node*ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%dx^%d\t",ptr->num,ptr->coeff);
        ptr=ptr->next;
    }
    return start;
}

struct node*add(struct node*start1,struct node*start2,struct node*start3)
{
    struct node *ptr1,*ptr2;
    int sum,c;
    ptr1=start1;
    ptr2=start2;
    while(ptr1!=NULL &&ptr2!=NULL)
    {
        if(ptr1->coeff==ptr2->coeff)
        {
        sum=ptr1->num+ptr2->num;
        start3=addnode(start3,sum,ptr1->coeff);
        ptr1=ptr1->next;
        ptr2=ptr2->next;
        }
        else if(ptr1->coeff>ptr2->coeff){
            start3=addnode(start3,ptr1->num,ptr1->coeff);
            ptr1=ptr1->next;
        }
        else if(ptr1->coeff<ptr2->coeff)
        {
            start3=addnode(start3,ptr2->num,ptr2->coeff);
            ptr2=ptr2->next;
        }
    }
    if(ptr1==NULL)
    {
        while(ptr2!=NULL)
        {
            start3=addnode(start3,ptr2->num,ptr2->coeff);
            ptr2=ptr2->next;

        }
    }
    if(ptr2==NULL)
    {
        while(ptr1!=NULL)
        {
            start3=addnode(start3,ptr1->num,ptr1->coeff);
            ptr1=ptr1->next;
        }
    }
    return start3;
}
struct node*sub(struct node*start1,struct node*start2,struct node*start4)
{
struct node*ptr1,*ptr2;
int subs,c;
ptr1=start1,ptr2=start2;
do
{
if(ptr1->coeff==ptr2->coeff)
{
    subs=ptr1->num-ptr2->num;
    start4=addnode(start4,subs,ptr1->coeff);
    ptr1=ptr1->next;
    ptr2=ptr2->next;

}
else if(ptr1->coeff>ptr2->coeff)
{
    start4=addnode(start4,ptr1->num,ptr1->coeff);
    ptr1=ptr1->next;
}
else if(ptr1->coeff<ptr2->coeff)
{
    start4=addnode(start4,ptr2->num,ptr2->coeff);
    ptr2=ptr2->next;
}
}
 while (ptr1!=NULL ||ptr2!=NULL);
 if(ptr1==NULL)
 {
    while(ptr2!=NULL)
    {
        start4=addnode(start4,ptr2->num,ptr2->coeff);
        ptr2=ptr2->next;

    }
 }
 if(ptr2==NULL){
     while(ptr1!=NULL){
             
                start4=addnode(start4,ptr1->num,ptr1->coeff);
                  ptr1=ptr1->next;
            
 }
 }
 return start4;
}
struct node*addnode(struct node *start,int n,int c)
{
    struct node*ptr,*newnode;
    if(start==NULL)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->num=n;
        newnode->coeff=c;
        newnode->next=NULL;
        start=newnode;
    }                                  
    else{
       ptr= start;
       while(ptr->next!=NULL)
       {
           ptr=ptr->next;
       }
       newnode=(struct node*)malloc(sizeof(struct node));
       newnode->num=n;
       newnode->coeff=c;
       newnode->next=NULL;
       ptr->next=newnode;
       }
       return start;
}