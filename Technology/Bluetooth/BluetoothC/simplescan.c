#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

/** 
 * A simple program that detects nearby Bluetooth devices. 
 * The program reserves system Bluetooth resources, scans 
 * for nearby Bluetooth devices, and then looks up the user 
 * friendly name for each detected device 
 **/

int main(int argc, char **argv)
{
    inquiry_info *ii = NULL;
    int max_rsp, num_rsp;
    int dev_id, sock, len, flags;
    int i;
    char addr[19] = { 0 };
    char name[248] = { 0 };

    dev_id = hci_get_route(NULL);    // retrieve the resource number of the first available Bluetooth adapter

    sock = hci_open_dev( dev_id );   // open a socket representing a connection to the microcontroller on the 
                                     // specified local Bluetooth adapter
    if (dev_id < 0 || sock < 0) {
        perror("opening socket");
        exit(1);
    }

    len = 8;
    max_rsp = 255;
    flags = IREQ_CACHE_FLUSH;
    ii = (inquiry_info *)malloc(max_rsp * sizeof(inquiry_info));

    num_rsp = hci_inquiry(dev_id, len, max_rsp, NULL, &ii, flags);    // performs a Bluetooth device discovery 
                                                                      // and returns a list of detected devices
                                                                      // and some basic information about them 
                                                                      // in the variable ii
    if (num_rsp < 0) perror("hci_inquiry");

    for (i = 0; i < num_rsp; i++) {
        ba2str(&(ii+i)->bdaddr, addr);
        memset(name, 0, sizeof(name));
        if (hci_read_remote_name(sock, &(ii+i)->bdaddr, sizeof(name), name, 0) < 0)    // determines the user-friendly names associated with those addresses
            strcpy(name, "[unknown]");
        printf("%s  %s\n", addr, name);
    }

    free(ii);
    close(sock);
    return 0;
}
