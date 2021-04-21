#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

#define SENDMESSAGE    "hello!\nI finally send this message successfully"

int main(int argc, char **argv)
{
    struct sockaddr_rc addr = { 0 };
    int s, status;
    //char dest[18] = "01:23:45:67:89:AB";
    char dest[18] = "A4:34:D9:1B:CD:75";    // destination device's bluetooth address

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
        status = write(s, SENDMESSAGE, sizeof(SENDMESSAGE));

    if (status < 0) perror("uh oh");

    close(s);
    return 0;
}
