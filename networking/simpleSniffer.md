# a simple sniffer just like wireShark

## requirements

- sudo apt-get install libpcap-dev
- pip3 install impacket pcapy

## code 

```py
#! /usr/bin/python3

import pcapy
from impacket.ImpactDecoder import EthDecoder

dev = 'eth1'    # using ifconfig to find eth name
filter = 'arp'
decoder = EthDecoder()

# This function will be called by every packet
def handle_packet(hdr, data):
    print(decoder.decode(data))

# Open device in promisc mode
pcap = pcapy.open_live(dev, 65535, True, 100) # see below

# Set pcap filter
pcap.setfilter(filter)

# Start sniffing
pcap.loop(0, handle_packet)
```

## explain

Got error in WSL1. Not fix yet!

```bash
Traceback (most recent call last):
  File "temp.py", line 36, in <module>
    pcap = pcapy.open_live(dev, 1500, 0, 100)
pcapy.PcapError: socket for SIOCETHTOOL(ETHTOOL_GET_TS_INFO): Socket type not supported
```

**promisc mode** : instruct kernel to read in every network packet, not only those addressed to the card itself.

**filter** : PCAP filter languange, www.tcpdum.org

**open_live() api** : https://rawgit.com/CoreSecurity/pcapy/master/pcapy.html#idp1073147198592

```cpp
Reader open_live (	device,	 
 	snaplen,	 
 	promisc,	 
 	to_ms);	 
string device ; netwrork card name
int snaplen ; how many bytes of a payload should be read.
int promisc ; boolen value for setting promisc mode
int to_ms ; timeout in milliseconds
```