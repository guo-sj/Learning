#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

int main(int argc, char **argv)
{
    struct sockaddr_rc addr = { 0 };
    int s, status;
    char dest[18] = "01:23:45:67:89:AB";
    char message[100] = "";

    if (argc < 3) {
        fprintf(stderr, "usage: %s <bt_addr> <message>\n", argv[0]);
        exit(3);
    }

    strncpy(dest, argv[1], 18);
    strncpy(message, argv[2], 100);

    /* allocate a socket */
    s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);

    /* set the connection parameters (who to connect to) */
    addr.rc_family = AF_BLUETOOTH;
    addr.rc_channel = (uint8_t) 1;
    str2ba(dest, &addr.rc_bdaddr);

    /* connect to server */
    status = connect(s, (struct sockaddr *)&addr, sizeof(addr));

    /* send a message */
    if (status == 0)
        status = write(s, message, sizeof(message));

    if (status < 0) perror("uh oh");

    close(s);
    return 0;
}
