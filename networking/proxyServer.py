# proxyServer.py
# refs to https://gitee.com/NKU2020/Computer-Network-A-Top-Down-Approach-Answer/tree/master/Chapter-2/Socket-Programming-Assignment-4
from socket import *
import sys
import os

if len(sys.argv) <= 1:
    print('Usage: "python3 ProxyServer.py server.ip"\nserver_ip : It is the IP Address Of Proxy Server')
    sys.exit(2)

# Create a server socket, bind it to a port and start listening
tcpSerSock = socket(AF_INET, SOCK_STREAM)
tcpSerPort = int(sys.argv[1])
tcpSerSock.bind(('', tcpSerPort))
# it specifies the number of unaccepted connections that the system will allow before refusing new connections. If not specified, a default reasonable value is chosen.
tcpSerSock.listen()

while True:
    # Start receiving data from the client
    print('Ready to serve...')
    tcpCliSock, addr = tcpSerSock.accept()
    print('Received a connection from:{}'.format(addr))
    message = tcpCliSock.recv(1024).decode()    # 1024 bytes is big enough ?
    print(message)

    # Extract the filename from the given message
    filename = message.split()[1].partition("/")[2]
    fileExist = "false"
    filetouse = '/' + filename
    print('filetouse:', filetouse)

    try:
        # Check wether the file exist in the cache
        f = open("WEB/"+filetouse[1:], "rb")
        print("finded in cache.")
        outputdata = f.read()   # read up to end.
        f.close()
        fileExist = "true"

        # ProxyServer finds a cache hit and generates a response message
        tcpCliSock.send("HTTP/1.1 200 OK\r\n".encode())
        tcpCliSock.send("Content-Type:text/html\r\n\r\n".encode())
        # TODO: why not need to send data.length
        tcpCliSock.send(outputdata)

    except IOError:
        if fileExist == 'false':
            # Create a socket on the proxyserver
            c = socket(AF_INET, SOCK_STREAM)

            hostname = filename.replace("www.", "", 1)
            print('hostname:', hostname)
            try:
                # Connect to the socket to port 80
                serverName = hostname.partition("/")[0]
                serverPort = 80
                print((serverName, serverPort))  # TODO:
                c.connect((serverName, serverPort))
                askFile = ''.join(filename.partition('/')[1:])
                print("askFile:", askFile)  # TODO:
                # Create a temporary file on this socket and ask port 80 for the file requested by client
                fileobj = c.makefile('rwb', 0)  # 0 means no buffer
                headlines = "GET " + askFile + " HTTP/1.0\r\nHost: " + serverName + "\r\n\r\n"
                fileobj.write(headlines.encode())  # write means send all

                # Read the response into buffer
                serverResponse = fileobj.read() # read means receive all

                 # Create a new file in the cache for the requested file.
                 # Also send the response in the buffer to client socket and the corresponding file in the cache
                filename = "WEB/" + filename
                filesplit = filename.split('/')
                for i in range(0, len(filesplit) - 1):
                    if not os.path.exists("/".join(filesplit[0:i+1])):
                        os.makedirs("/".join(filesplit[0:i+1]))

                tmpFile = open(filename, "wb")
                print(serverResponse)
                serverResponse = serverResponse.split(
                    b'\r\n\r\n')[1]  # TODO why split??
                print(serverResponse)
                tmpFile.write(serverResponse)  # TODO: not encode()??
                tmpFile.close()
                tcpCliSock.send("HTTP/1.1 200 OK\r\n".encode())
                tcpCliSock.send("Content-Type:text/html\r\n\r\n".encode())
                tcpCliSock.send(serverResponse)
            except:
                print("Illeagl request")
            c.close()
        else:
            # HTTP response message for file not found
            print('NET ERROR')

    # Close the client and the server sockets
    tcpCliSock.close()
tcpSerSock.close()
