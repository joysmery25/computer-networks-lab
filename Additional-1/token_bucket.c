#include <stdio.h>
#include <unistd.h>

int main() {
    int bucketSize, tokenRate, n, i;
    int packetSize[100];
    printf("Enter maximum bucket capacity (tokens): ");
    scanf("%d", &bucketSize);
    printf("Enter token generation rate (tokens/sec): ");
    scanf("%d", &tokenRate);
    printf("Enter number of incoming packet requests: ");
    scanf("%d", &n);
    printf("Enter size of each packet (in KB / tokens required):\n");
    for (i = 0; i < n; i++) {
        printf("Packet %d: ", i + 1);
        scanf("%d", &packetSize[i]);
    }
    int currentTokens = 0; 
    printf("\nTime(s)\tTokens Added\tTokens Available\tPacket Size\tStatus\t\tRemaining Tokens\n");
    printf("-----------------------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        currentTokens += tokenRate;
        if (currentTokens > bucketSize) {
            currentTokens = bucketSize;
        }
        int requested = packetSize[i];
        if (requested <= currentTokens) {
            currentTokens -= requested;
            printf("%d\t%d\t\t%d\t\t\t%d KB\t\tSent\t\t%d\n", i + 1, tokenRate, currentTokens + requested, requested, currentTokens);
        } else {
            printf("%d\t%d\t\t%d\t\t\t%d KB\t\tDropped/Queued\t%d\n", i + 1, tokenRate, currentTokens, requested, currentTokens);
        }
    }
    return 0;
}