#include<stdio.h>
#include<stdlib.h>
#define MAX 5
void breathfirstsearch(int adj[][MAX],int visited[],int start)
{
    int queue[MAX],rear=-1,front=-1,i;
    queue[++rear]=start;
    visited[start]=1;
    while(rear!=front)
    {
        start=queue[++front];
        if(start==4)
        printf("%c\t",rear+65);
        else
        printf("%c \t",start +65);
        for(i=0;i<MAX;i++)
        {
            if(adj[start][i]==1 && visited[i]==0)
            {
                queue[++rear]=i;
                visited[i]=1;
            }} }
}
int main()
{
int visited[MAX]={0};//traversal
int adj[MAX][MAX],i,j;
printf("enter the adjacency matrix\n");
for(i=0;i<MAX;i++)
    for(j=0;j<MAX;j++)
    scanf("%d",&adj[i][j]);

breathfirstsearch(adj,visited,0);
   
return 0;
}
/*
  A B C D E
A|0 1 1 0 0|        A-B
B|1 0 0 1 1|        | | \
C|1 0 0 1 0|        C-D -E
D|0 1 1 0 1|
E|0 1 0 1 0|
*/