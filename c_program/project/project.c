#include <pcap.h>
#include <stdio.h>
#include <arpa/inet.h>

/* Callback function invoked by pcap for every captured packet */
void packet_handler(u_char *user_data, const struct pcap_pkthdr *pkthdr, const u_char *packet) {
    printf("Packet captured length: %d\n", pkthdr->len);
    // Additional packet analysis can be performed here
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_if_t *alldevs, *device;
    
    /* Find all devices */
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
        return 1;
    }

    /* Use the first device */
    device = alldevs;
    if (device == NULL) {
        fprintf(stderr, "No devices found\n");
        return 2;
    }

    /* Open the device for packet capture */
    pcap_t *handle = pcap_open_live(device->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", device->name, errbuf);
        pcap_freealldevs(alldevs);
        return 2;
    }

    /* Capture packets */
    pcap_loop(handle, 10, packet_handler, NULL);

    /* Close the session */
    pcap_close(handle);
    pcap_freealldevs(alldevs);
    return 0;
}
