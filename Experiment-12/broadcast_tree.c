#include<stdio.h>
#include<limits.h>
#define MAX 20
#define INF 9999

int main(){
    int cost[MAX][MAX],visited[MAX]={0};
    int i,j,n,edges=0,min,a=-1,b=-1,totalCost=0;
    printf("Enter the number of hosts(nodes):");
    scanf("%d",&n);
    printf("Enter the adjacency matrix(0 if no direct link,use 9999 for infinity):\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0 && i!=j){
                cost[i][j]=INF;
            }
        }
    }
    visited[0]=1;
    printf("\nEdges in the Broadcast Tree:\n");
    while(edges<n-1){
        min=INF;
        for(int i=0;i<n;i++){
            if(visited[i]){
                for(int j=0;j<n;j++){
                    if(!visited[j] && cost[i][j]<min){
                        min=cost[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }
        if(a!=-1 && b!=-1){
            printf("Host %d -> Host %d:Cost = %d\n",a,b,cost[a][b]);
            totalCost+=cost[a][b];
            visited[b]=1;
            edges++;
            a=b=-1;
        }
        else{
            printf("Disconnected graph! Broadcast tree not possible.\n");
            return 1;
        }
    }
    printf("\nTotal cost of Broadcast Tree:%d\n",totalCost);
}