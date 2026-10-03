#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define MAX_RETRIES 5
int calculate_backoff(int attempt) {
    int max_slots = (1 << attempt) - 1; 
    return rand() % (max_slots + 1); 
}
int main() {
    int numNodes, channelBusy, collision;
    srand(time(NULL));
    printf("=== CSMA/CD Simulation (Ethernet LAN Collision Handling) ===\n\n");
    printf("Enter number of active stations wanting to transmit: ");
    scanf("%d", &numNodes);
    if (numNodes <= 0) {
        printf("No nodes attempting to transmit. Exiting.\n");
        return 0;
    }
    int attempts[100] = {0}; 
    int transmitted[100] = {0};
    int totalTransmitted = 0;
    while (totalTransmitted < numNodes) {
        printf("\n--- Sensing Channel ---\n");
        channelBusy = rand() % 2; 
        if (channelBusy) {
            printf("Carrier Sense: Medium is BUSY. Nodes waiting for channel to become idle...\n");
            continue;
        }
        printf("Carrier Sense: Medium is IDLE. Nodes attempting transmission...\n");
        int activeInThisRound = 0;
        int readyNodes[100];
        for (int i = 0; i < numNodes; i++) {
            if (!transmitted[i]) {
                readyNodes[activeInThisRound++] = i;
            }
        }
        if (activeInThisRound > 1) {
            printf("\n[COLLISION DETECTED!] %d nodes transmitted simultaneously.\n", activeInThisRound);
            for (int k = 0; k < activeInThisRound; k++) {
                int node = readyNodes[k];
                attempts[node]++;
                if (attempts[node] > MAX_RETRIES) {
                    printf("Node %d: Exceeded maximum retries (%d). Frame ABORTED!\n", node + 1, MAX_RETRIES);
                    transmitted[node] = 1; // Drop packet
                    totalTransmitted++;
                } else {
                    int backoff = calculate_backoff(attempts[node]);
                    printf("Node %d: Attempt %d failed. Binary Exponential Backoff delay = %d slot time(s).\n", 
                           node + 1, attempts[node], backoff);
                }
            }
        } else if (activeInThisRound == 1) {
            int node = readyNodes[0];
            printf("\n[SUCCESS] Node %d transmitted packet successfully without collision!\n", node + 1);
            transmitted[node] = 1;
            totalTransmitted++;
        }
    }
    printf("\n=======================================================\n");
    printf("All transmission attempts processed.\n");
    return 0;
}