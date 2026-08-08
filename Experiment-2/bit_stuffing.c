#include <stdio.h>
#include <string.h>
int main(){
    char data[100],stuffed[200];
    int i,j=0,c=0;
    printf("Enter binary data(0s and 1s only): ");
    scanf("%s",data);
    for(int i=0;i<strlen(data);i++){
        stuffed[j++]=data[i];
        if(data[i]=='1'){
            c++;
            if(c==5){
                stuffed[j++]='0';
                c=0;
            }
        }
        else{
            c=0;
        }
    }
    stuffed[j]='\0';
    printf("Bit Stuffed Data: %s\n",stuffed);
    return 0;
}