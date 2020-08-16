#include<stdio.h>
#include<stdlib.h>
int n;
void graph_color(int graph[][],int vertex,int colors[],int vertices){
    int i;
    int color=1;
    for(i=0;i<vertices;i++){
        if(graph[vertex][i] && colors[i]==color)
            color++;
    }
    colors[vertex]=color;
}

int main(){
    int i,j;
    printf("Enter the no. of vertices\n");
    scanf("%d",&n);
    int graph[n][n];
    printf("Enter the adjacency matrix for the graph\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
    }
    int colors[n];
    for(i=0;i<n;i++) colors[i]=0;
    for(i=0;i<n;i++)
        graph_color(graph,i,colors,n);
    for(i=0;i<n;i++){
        printf("Color assigned to vertex : %d is %d\n",i+1,colors[i]);
    }
    return 0;
}
