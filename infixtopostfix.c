#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100
char stack[MAX];
int top=-1;
void push(char stack[],char);
char pop(char stack[]);
void inftopost(char source[],char target[]);
int getPriority(char);
int main()
{
    char infix[100],postfix[100];
    printf("Enter any infix expression:\n");
    gets(infix);
    strcpy(postfix," ");
    inftopost(infix,postfix);
    printf("The postfix expression is :\n");
    puts(postfix);
    return 0;
       }

void inftopost(char source[], char target[])
{
    int i=0,j=0;
    char temp;
strcpy(target,"");
    while(source[i]!='\0')
    {
      if (source[i]=='(')
      {
         push(stack,source[i]);
         i++;
          }
           else if(source[i]==')')
            {
                while(top!=-1 &&(stack[top]!='('))
               {
                  target[j]=pop(stack);
                  j++;
    
                    }
    if(top==-1)
    {
        printf("INVALID EXPRESSION");
   //exit(1);//exit
    }

temp=pop(stack);
i++;
    }
    else if(isdigit(source[i])||isalpha(source[i]))
    {
        target[j]=source[i];
        i++;
        j++;
    }
 else if(source[i]=='+'||source[i]=='-'||source[i]=='*'||source[i]=='/'||source[i]=='%')
 {
    while(top!=-1 &&(stack[top]!='(')&&(getPriority(stack[top])>=getPriority(source[i])))
    {
        target[j]=pop(stack);
        j++;

    }
    push(stack,source[i]);
    i++;
   }
  else
  {
    printf("INCORRECT ELEMENT");
    //exit(1);//exit

   }
  }
        while((top!=-1)&&(stack[top]!='('))
     {
       target[j]=pop(stack);
       j++;
      }
        target[j]='\0';
}

     int getPriority(char op)
     {
    if(op=='/'|| op=='*'|| op=='%')
    return 1;
    else if(op=='+'|| op=='-')
return 0;
}
void push(char stack[],char val)
{
    if(top==MAX-1)
    {
        printf("stack overflow");
    }
    else
    {
        top++;
        stack[top]=val;
    }
}
char pop( char stack[])
{
    char val=' ';
    if(top==-1)
    printf("stack underflow");
    else
    {
        val=stack[top];
        top--;
    }
    return val;
}