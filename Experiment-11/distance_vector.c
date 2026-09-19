#include<stdio.h>
#include<stdlib.h>
#define INFINITY 9999
#define MAX 10
typedef struct{
    int distance[MAX];
    int from[MAX];
}RoutingTable;
int main(){
    int graph[MAX][MAX];
    RoutingTable rt[MAX];
    int nodes,i,j,k;
    printf("Enter number of nodes(routes): ");
    scanf("%d",&nodes);
    printf("Enter the delay matrix(enter 9999 if no direct path):\n");
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            rt[i].distance[j]=graph[i][j];
            rt[i].from[j]=j;
        }
    }
    int updated;
    do{
        updated=0;
        for(int i=0;i<nodes;i++){
            for(int j=0;j<nodes;j++){
                for(int k=0;k<nodes;k++){
                    if(rt[i].distance[j]>graph[i][k]+rt[k].distance[j]){
                        rt[i].distance[j]=graph[i][k]+rt[k].distance[j];
                        rt[i].from[j]=k;
                        updated=1;
                    }
                }
            }
        }
    }while(updated);
    for(int i=0;i<nodes;i++){
        printf("\nRouting table for Node %d:\n",i);
        printf("Destination\tNext Hop\tCost\n");
        for(int j=0;j<nodes;j++){
            if(rt[i].distance[j]==INFINITY)
                printf("%d\t\t--\t\tINF\n",j);
            else
                printf("%d\t\t%d\t\t%d\n",j,rt[i].from[j],rt[i].distance[j]);
        }
    }
    return 0;
}