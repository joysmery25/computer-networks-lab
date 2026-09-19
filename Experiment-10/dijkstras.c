#include<stdio.h>
#include<limits.h>
#define MAX 100
#define INF 9999

int minDistance(int dist[],int visited[],int n){
    int min=INF,minIndex=-1;
    for(int v=0;v<n;v++){
        if(!visited[v] && dist[v]<=min){
            min=dist[v];
            minIndex=v;
        }
    }
    return minIndex;
}
void dijkstra(int graph[MAX][MAX],int n,int src){
    int dist[MAX];
    int visited[MAX]={0};
    for(int i=0;i<n;i++){
        dist[i]=INF;
    }
    dist[src]=0;
    for(int count=0;count<n-1;count++){
        int u=minDistance(dist,visited,n);
        if(u==-1) break;
        visited[u]=1;
        for(int v=0;v<n;v++){
            if(!visited[v] && graph[u][v] && dist[u]!=INF && dist[u]+graph[u][v]<dist[v])
            dist[v]=dist[u]+graph[u][v];
        }
    }
    printf("\nVertex\tShortest Distance from Source %d\n",src);
    for(int i=0;i<n;i++){
        if(dist[i]==INF)  printf("%d\tINF\n",i);
        else printf("%d\t%d\n",i,dist[i]);
    }
}
int main(){
    int n,src;
    int graph[MAX][MAX];
    printf("Enter number of vertices:");
    scanf("%d",&n);
    printf("Enter the adjacency matrix (0 if no direct edge):\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
            if(i!=j && graph[i][j]==0){
                graph[i][j]=INF;
            }
        }
    }
    printf("Enter source vertex (0 to %d):",n-1);
    scanf("%d",&src);
    dijkstra(graph,n,src);
    return 0;
}