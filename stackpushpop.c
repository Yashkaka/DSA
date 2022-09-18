#include<stdio.h>
#include<stdlib.h>
#define max 4
int stack[max];
int top=-1;
void push();
int pop();
int peek();
void display();
int main()
{
    int val,option;
    do{
        printf("\nEnter 1 for PUSH");
         printf("\nEnter 2 for POP");
        printf("\nEnter 3 for PEEK");
        printf("\nEnter 4 for DISPLAY");
        printf("\nEnter 5 for EXIT\n");
      printf("\nEnter your option : ");

        scanf("\n%d",&option);
      switch(option)
      {
          case 1: printf("\nEnter Element to be pushed in The stack :");
        
          scanf("\n %d",&val);
           push (stack,val);
          break;

          case 2:
           val=pop(stack);
           if(val!=-1)  
           printf("\nThe Element %d is been deleted \n",val);
          break;

           case 3:
            val=peek(stack);
            if(val!=-1)
            printf("\nThe value at top of stack is %d  \n",val);
          break;

            case 4:
            printf("\nThe Elements in stack are \n");
            display(stack);
            break;

      }}
      while(option!=5);
      return 0;


}
void push(int stack[],int val)
{
    if(top == max-1){
        printf("\nstack overflow\n");}
        else
        {
        top++;
stack[top]=val;
    }
}
int pop(int stack[])
{
    int val;
    if(top==-1){
        printf("\nstack underflow\n");
        return -1;
    }
    else{
        val=stack[top];
        top--;
        return val;}

}

int peek(int stack[])
{
    if(top==-1)
    {
printf("\nstack underflow\n");
return -1;
    }
    else
    {
        return stack[top];
    }
}
void display(int stack[])
{
    if(top==-1)
    {
        printf("\nstack  underflow\n");

    }
    else
    {
       for(int i=top;i>=0;i--)
       printf("\n%d",stack[i]);
       printf("\n");

    }
}