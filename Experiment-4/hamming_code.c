#include<stdio.h>
int main(){
    int data[4];
    int code[7];
    printf("Enter 4 bits of data(separated by space): ");
    for(int i=0;i<4;i++){
        scanf("%d",&data[i]);
    }
    code[2]=data[0];
    code[4]=data[1];
    code[5]=data[2];
    code[6]=data[3];
    code[0]=code[2]^code[4]^code[6];
    code[1]=code[2]^code[5]^code[6];
    code[3]=code[4]^code[5]^code[6];
    printf("Hamming code: ");
    for(int i=0;i<7;i++){
        printf("%d",code[i]);
    }
    printf("\n");
    return 0;
}