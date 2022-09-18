#include<stdio.h>
#include<stdlib.h>
#define MAX 5
void depthfirstsearch(int adj[][MAX],int visited[],int start)
{
    int stack[MAX];
    int top=-1,i;
    printf("%c\t",start +65);
    visited[start]=1;
    stack[++top]=start;
    while(top!= -1)
    {
        start= stack[top];
        for(i=0;i<MAX;i++)
        {
            if(adj[start][i]&&visited[i]==0)
            {
                stack[++top]=i;
                printf("%c\t",i + 65);
                visited[i]=1;
                break;

            }
        }
        if(i == MAX)
        top--;
    }
}

int main()
{
    int adj[MAX][MAX];
    int visited[MAX]={0},i,j;
    printf(" enter the adjacency matrix:\n");
    for(i=0;i<MAX;i++)
    for(j=0;j<MAX;j++)
    scanf("%d",&adj[i][j]);
    printf("dfs traversal : ");
    depthfirstsearch(adj,visited,0);
    printf("\n");
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