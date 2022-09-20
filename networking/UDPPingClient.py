# UDPPingClient.py
from socket import *
import time

serverName = '10.79.17.130'
serverPort = 12001

# Create client socket
clientSocket = socket(AF_INET, SOCK_DGRAM)

# Set Client wait up to 1 second
clientSocket.settimeout(1.0)

for i in range(10):
    try:
        # Ping sequence_number time
        sendTime = time.time()
        message = 'ping {} {}'.format(i, sendTime)
        clientSocket.sendto(message.encode(),(serverName, serverPort))
       
        recvMessage, serverAddress = clientSocket.recvfrom(1024)
        elapsedTime = time.time() - sendTime

        print(recvMessage.decode(),'RTT is {} second'.format(elapsedTime))
    
    except timeout:
        print("PING {} time out, no response message.".format(i))

clientSocket.close()