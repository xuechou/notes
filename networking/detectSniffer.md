# detect wheather the network sniffer exist

## check wheather the sniffer exist in your computer

### key point : check all network interface to see if they are set to promisc mode

#### way 1 :

```bash
ifconfig -a | grep PROMISC
```

#### way 2 :

``` bash
cat /var/log/messages | grep promisc
```

## check wheather the sniffer exist in a network

#### key point : promisc mode won't reject any packet and react on it

## refference

http://www.securityfriday.com/promiscuous_detection_01.pdf

## code 

```py
#! /usr/bin/python3

import sys
from scapy.all import promiscping

if len(sys.argv) < 2:
    print(sys.argv[0] + ' <net>')
    sys.exit()

promiscping(sys.argv[1])
```

## usage

```bash
python3 your_script.py 192.168.1.*

# or
python3 your_script.py 192.168.1.0/24
```

**not worked in WSL1** 