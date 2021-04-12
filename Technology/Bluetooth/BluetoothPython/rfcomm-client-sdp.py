import sys
import bluetooth

uuid = "1e0ca4ea-299d-4335-93eb-27fcfe7fa848"
service_matches = bluetooth.find_service( uuid = uuid )

if len(service_matches) == 0:
    print "couldn't find the FooBar service"
    sys.exit(0)

first_matches = service_matches[0] # returned a dictionary
port = first_matches["port"]
name = first_matches["name"]
host = first_matches["host"]

print "connecting to \"%s\" on %s" % (name, host)

sock = bluetooth.BluetoothSocket( bluetooth.RFCOMM )
sock.connect((host, port))
socket.send("hello!!")
sock.close()
