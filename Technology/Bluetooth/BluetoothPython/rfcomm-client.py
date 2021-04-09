import bluetooth

bd_addr = "01:23:45:67:89:AB"

port = 11   # RFCOMM protocol's port is 1 ~ 30

sock=bluetooth.BluetoothSocket( bluetooth.RFCOMM )
sock.connect((bd_addr, port))   # establish an outgoing connection

sock.send("hello!!")
sock.close()

# TODO
# Traceback (most recent call last):
#       File "rfcomm-client.py", line 8, in <module>
#           sock.connect((bd_addr, port))   # establish an outgoing connection
#             File "<string>", line 5, in connect
#             bluetooth.btcommon.BluetoothError: (16, 'Device or resource busy')
