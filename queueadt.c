#include<stdio.h>
#define MAX 3
int queue[MAX];
int front=-1,rear=-1;
void insert();
void delete();
void peek();
void display();
int main()
{
    int num,val;
    do
    {
        printf("Enter 1 TO INSERT ELEMENT\n");
        printf("Enter 2 TO DELETE ELEMENT\n");
        printf("Enter 3 TO PEEK ELEMENT \n");
        printf("Enter 4 TO DISPLAY ELEMENTS \n");
        printf("Enter 5 TO EXIT\n");
        scanf("%d",&num);
        switch(num){
        case 1:  insert();
        break;
        case 2: delete();
                break;
         case 3:  peek();
         break;
         case 4:  display();
         break;
        }
    }while(num!=5);
        return 0;
}

void insert()
{
int val;
if(rear==MAX-1){
printf("OVERFLOW\n\n");}
else {printf("ENTER THE ELEMENT YOU WANT TO INSERT IN THE QUEUE:  ");
scanf("%d",&val);}

 if(front==-1 && rear==-1){
front = 0;rear=0;}
else{
rear=rear+1;}
queue[rear]=val;
}

void delete()
{
    int val;
    if(front == -1 || front > rear)
    {
        printf("UNDERFLOW \n\n");
    }
    else if(front==rear)
    {front=rear=-1;
    printf("UNDERFLOW\n\n");
    }
else{
   
   val=queue[front];
   front++;
   if(front>rear)
    front=rear=-1;
  
    printf("THE NUMBER  %d  IS DELETED \n\n",val);

   
}
}
void peek()
{
    if(front==-1||front>rear)
printf("QUEUE IS EMPTY\n");
else{
    printf("THE ELEMENT AT THE PEEK IS  %d\n\n",queue[front]);
}
}
void display()
{ int i,val;
if(front==-1||front>rear)
{
    printf("QUEUE IS EMPTY\n\n");
}
else
{
    for(i=front;i<rear;i++)
    {
        printf("%d  ",queue[i]);
    }
    printf("\n");

}
}