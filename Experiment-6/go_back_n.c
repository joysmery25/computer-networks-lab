#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_FRAMES 50

int main(){
    int windowSize,totalFrames,i=0,ack,j;
    printf("Enter total number of frames to send: ");
    scanf("%d",&totalFrames);
    printf("Enter window size: ");
    scanf("%d",&windowSize);
    srand(time(NULL));
    while(i<totalFrames){
        printf("\nSender: Sending frames %d to %d\n",i+1,(i+windowSize<=totalFrames)?i+windowSize:totalFrames);
        for(j=i;j<i+windowSize && j<totalFrames;j++){
            printf("Frame %d sent\n",j+1);
        }
        int ackLost=rand()%2;
        if(ackLost==1){
            printf("Receiver: ACK lost!Go-Back-N triggered.\n");
            printf("Sender:Resending window starting from frame %d\n",i+1);
        }
        else{
            printf("Receiver: ACK received for frames %d to %d\n",i+1,(i+windowSize<=totalFrames)?i+windowSize:totalFrames);
            i+=windowSize;
        }
    }
    printf("All frames sent successfully using Go-back-N ARQ");
}