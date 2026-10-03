#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_WORDS 100
unsigned short onesComplement(unsigned short num){
    return ~num;
}
unsigned short addWithCarry(unsigned short a, unsigned short b){
    unsigned int sum=a+b;
    if(sum>>16) sum=(sum&0xFFFF)+1;
    return (unsigned short)sum;
}
int main(){
    char input[256];
    unsigned short words[MAX_WORDS];
    int c=0;
    printf("Enter 16-bit hex words(eg., 466F 726F 757A 616E), end with non-hex:\n");
    while(scanf("%hx",&words[c])==1){
        c++;
        if(c>=MAX_WORDS){
            printf("Too many input words!\n");
            return 1;
        }
    }
    unsigned short sum=0;
    for(int i=0;i<c;i++){
        sum=addWithCarry(sum,words[i]);
    }
    unsigned short checksum=onesComplement(sum);
    printf("Computed Checksum: %04X\n",checksum);
    return 0;
}