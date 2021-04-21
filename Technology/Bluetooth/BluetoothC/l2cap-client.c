#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/l2cap.h>

int main(int argc, char **argv)
{
    struct sockaddr_l2 addr = { 0 };
    int s, status;
    char message[100] = "";
    char dest[18] = "01:23:45:67:89:AB";

    if (argc < 3) {
        fprintf(stderr, "usage: %s <bt_addr> <message>\n", argv[0]);
        exit(3);
    }

    strncpy(dest, argv[1], 18);
    strncpy(message, argv[2], 100);

    /* allocate a socket */
    s = socket(AF_BLUETOOTH, SOCK_SEQPACKET, BTPROTO_L2CAP);

    /* set the connection parameters */
    addr.l2_family = AF_BLUETOOTH;
    addr.l2_psm = htobs(0x1001);
    str2ba(dest, &addr.l2_bdaddr);

    /* connect to server */
    status = connect(s, (struct sockaddr *)&addr, sizeof(addr));

    if (status == 0)
        status = write(s, message, sizeof(message));

    if (status < 0)  perror("uh oh");

    close(s);
}
