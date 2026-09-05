#include <stdio.h>
#include<string.h>
#define CRC12_POLY 0x80F
#define CRC16_POLY 0x8005
#define CRC_CCITT_POLY 0x1021
unsigned int computeCRC(unsigned char *data, int len, unsigned int poly, int crcBits){
    unsigned int crc=0;
    for(int i=0;i<len;i++){
        crc^=(data[i]<<(crcBits-8));
        for(int j=0;j<8;j++){
            if(crc & (1<<(crcBits-1))) crc=(crc<<1)^poly;
            else crc<<=1;
        }
    }
    return crc & ((1<<crcBits)-1);
}
int main(){
    unsigned char data[100];
    printf("Enter data(characters): ");
    scanf("%s",data);
    int len=strlen((char *)data);
    unsigned int crc12=computeCRC(data,len,CRC12_POLY,12);
    unsigned int crc16=computeCRC(data,len,CRC16_POLY,16);
    unsigned int crcCCITT=computeCRC(data,len,CRC_CCITT_POLY,16);
    printf("\nCRC-12: 0x%03X\n",crc12);
    printf("CRC-16: 0x%04X\n",crc16);
    printf("CRC-CCITT:0x%04X\n",crcCCITT);
    return 0;
}