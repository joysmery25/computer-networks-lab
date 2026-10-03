#include <stdio.h>
#include <string.h>
struct ARPTable {
    char ip[20];
    char mac[20];
};
int main() {
    struct ARPTable network[10] = {
        {"192.168.1.1", "00:1A:2B:3C:4D:5E"},
        {"192.168.1.2", "00:1A:2B:3C:4D:5F"},
        {"192.168.1.3", "00:1A:2B:3C:4D:60"},
        {"192.168.1.4", "00:1A:2B:3C:4D:61"},
        {"192.168.1.5", "00:1A:2B:3C:4D:62"}
    };
    int numNodes = 5;
    char targetIP[20];
    int found = 0;
    printf("=== ARP (Address Resolution Protocol) Simulation ===\n\n");
    printf("ARP Table / Network Database:\n");
    printf("-----------------------------------\n");
    printf("IP Address\t\tMAC Address\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < numNodes; i++) {
        printf("%s\t\t%s\n", network[i].ip, network[i].mac);
    }
    printf("-----------------------------------\n\n");
    printf("Enter Destination IP Address to resolve MAC: ");
    scanf("%s", targetIP);

    printf("\n[Source] Broadcasting ARP Request: Who has IP %s? Tell me.\n", targetIP);
    for (int i = 0; i < numNodes; i++) {
        if (strcmp(network[i].ip, targetIP) == 0) {
            printf("[Node %s] IP Matched! Sending Unicast ARP Reply...\n", network[i].ip);
            printf("\n>>> ARP Reply Received <<<\n");
            printf("Resolved MAC Address for IP %s is: %s\n", targetIP, network[i].mac);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\n[Error] ARP Request Failed: IP %s not found in the local network.\n", targetIP);
    }
    return 0;
}