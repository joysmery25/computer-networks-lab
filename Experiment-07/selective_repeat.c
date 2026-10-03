#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_FRAMES 50
int main(){
    int totalFrames, ws;
    int i,ack[MAX_FRAMES],j;
    printf("Enter total number of frames to send: ");
    scanf("%d", &totalFrames);
    printf("Enter window size: ");
    scanf("%d", &ws);
    srand(time(NULL));
    for(i=0;i<totalFrames;i++){
        ack[i]=0;
    }
    i=0;
    while(i<totalFrames){
        printf("\nSender: Sending frames %d to %d\n", i+1, ((i+ws)<=totalFrames)?(i+ws):totalFrames);
        for(int j=i;j<i+ws && j<totalFrames;j++){
            if(ack[j]==0) printf("Frame %dsent\n",j+1);
        }
        for(j=i;j<i+ws && j<totalFrames;j++){
            if(ack[j]==0){
                int ackLost=rand()%2;
                if(ackLost==0){
                    ack[j]=1;
                    printf("Receiver: ACK received for Frame %d\n",j+1);
                }
                else printf("Receiver: ACK lost for Frame %d(will be transmitted)\n",j+1);
            }
        }
        while(ack[i]==1 && i<totalFrames) i++;
    }
    printf("\nAll frames sent successfully using Selective Repeat ARQ.\n");
    return 0;
}