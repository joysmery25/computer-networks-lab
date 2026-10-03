#include <stdio.h>

int main() {
    int bucketSize, outputRate, n, i;
    int inputPacketSize[100];
    printf("Enter bucket size (in KB): ");
    scanf("%d", &bucketSize);
    printf("Enter output rate (in KB/sec): ");
    scanf("%d", &outputRate);
    printf("Enter number of incoming packets: ");
    scanf("%d", &n);
    printf("Enter size of each packet (in KB):\n");
    for (i = 0; i < n; i++) {
        printf("Packet %d: ", i + 1);
        scanf("%d", &inputPacketSize[i]);
    }
    int currentBucketSize = 0;
    printf("\nTime\tIncoming\tBucket\tSent\tDropped\n");
    for (i = 0; i < n; i++) {
        int incoming = inputPacketSize[i];
        int sent = 0;
        int dropped = 0;
        if (incoming + currentBucketSize <= bucketSize) {
            currentBucketSize += incoming;
            if (currentBucketSize > outputRate) {
                sent = outputRate;
                currentBucketSize -= outputRate;
            } else {
                sent = currentBucketSize;
                currentBucketSize = 0;
            }
            printf("%d\t%d KB\t\t%d KB\t%d KB\t%d KB\n", i + 1, incoming, currentBucketSize, sent, dropped);
        } else {
            dropped = (incoming + currentBucketSize) - bucketSize;
            sent = 0;
            printf("%d\t%d KB\t\tOverflow\t%d KB\t%d KB\n", i + 1, incoming, sent, dropped);
        }
    }
    int time = n + 1;
    while (currentBucketSize > 0) {
        int sent = 0;
        if (currentBucketSize > outputRate) {
            sent = outputRate;
            currentBucketSize -= outputRate;
        } else {
            sent = currentBucketSize;
            currentBucketSize = 0;
        }
        printf("%d\t0 KB\t\t%d KB\t%d KB\t0 KB\n", time, currentBucketSize, sent);
        time++;
    }
    return 0;
}