#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int totalFrames,i;
    int ackLost;
    printf("Enter total number of frames to send: ");
    scanf("%d",&totalFrames);
    srand(time(NULL));
    for(int i=1;i<=totalFrames;){
        printf("\nSender: Sending Frame: %d\n",i);
        ackLost=rand()%2;
        if(ackLost==0){
            printf("Receiver: ACK received for Frame %d\n",i);
            i++;
        }
        else{
            printf("Receiver: ACK lost for Frame %d\n",i);
            printf("Sender: Timeout!Resending Frame %d\n",i);
        }
    }
    printf("\nAll frames sent successfully using Stop and Wait Protocol.\n");
    return 0;
}