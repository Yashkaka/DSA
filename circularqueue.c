#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int queue[MAX];
int front=-1;
int rear=-1;
void insert();
int delete();
int peek();
void display();

int main()
{
    int num,val;
    do
    {
        printf("\nEnter 1 TO INSERT ELEMENT");
        printf("\nEnter 2 TO DELETE ELEMENT");
        printf("\nEnter 3 TO PEEK ELEMENT ");
        printf("\nEnter 4 TO DISPLAY ELEMENTS ");
        printf("\nEnter 5 TO EXIT\n");
        scanf("%d",&num);
        switch(num){
        case 1:  insert();
        break;
        case 2: val=delete();
      //  if (val!=-1)
        //           printf("\n THE NUMBER DELETED IS %d  ",val);


        break;
        case 3: val=peek();
        if(val!=-1)
        printf("THE FIRST VALUE IN QUEUE IS %d",val);
        break;

        case 4:
        display();
        break;
     } }
        while(num!=5);
        return 0;
        


        
}
void insert()
{int val;
    if(front==0 && rear==MAX-1 ||front==rear+1)
    {
    
       printf("\nOVERFLOW\n");
       }
       
   else
   { 
    printf("\nENTER THE NO TO BE INSERTED  ");
    scanf("%d",&val);}

     if(front==-1&&rear==-1)
    {
        front=rear=0;
        queue[rear]=val;
    }
    else if(rear==MAX-1&&front!=0)
    {
        rear=0;
        queue[rear]=val;
    }
    else{
        rear++;
        queue[rear]=val;
    }
}
int delete()
{
    int val;
        
    if(front==-1)
    {
        printf("\nUNDERFLOW");
return -1;
    }
    
        val=queue[front];
                   printf("\n THE NUMBER DELETED IS %d  \n",val);



     if(front==rear)
    front=rear=-1;

    else
    {
        if(front==MAX-1)
        front=0;
        else 
        front++;
    }
return 0;

    }
int peek()
{
    if (front==-1&& rear==-1)
    {
        printf("UNDERFLOW");
        return -1;

    }
    else
    {
        return queue[front];
        
    }
}
void display(){
    int i;
    printf("\n");
    if(front==-1 && rear==-1)
    {
        printf("QUEUE UNDERFLOW");
    }
    else{

    
    if(front<rear)
    {
        for(i=front;i<rear;i++)
        printf("%d  ",queue[i]);
    }
    else
    {
        for(i=front;i<MAX;i++)
        printf("%d  ",queue[i]);
        for(i=0;i<=rear;i++)
        printf("%d  ",queue[i]);
    }
}
}
