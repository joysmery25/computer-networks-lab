#include <stdio.h>
#include <string.h>
#define MAX 100
int main(){
    char data[MAX], stuffedData[MAX];
    char startFlag='D',endFlag='F',esc='E';
    int i,j=0;
    printf("Enter data to send(no spaces): ");
    scanf("%s",data);
    stuffedData[j++]=startFlag;
    for(int i=0;i<strlen(data);i++){
        if(data[i]==startFlag || data[i]==endFlag || data[i]==esc){
            stuffedData[j++]=esc;
        }
        stuffedData[j++]=data[i];
    }
    stuffedData[j++]=endFlag;
    stuffedData[j]='\0';
    printf("Stuffed Data: %s\n",stuffedData);
    return 0;
}