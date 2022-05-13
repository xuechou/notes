# proxyServer.py
from socket import *
import sys

if len(sys.argv) <= 1:
    print('Usage: "python ProxyServer.py server.ip"\nserver_ip : It is the IP Address Of Proxy Server')
    sys.exit(2)

# Create a server socket, bind it to a port and start listening
tcpSerSock = socket(AF_INET, SOCK_STREAM)
tcpSerSock.bind(('',8888))
tcpSerSock.listen(1)    #TODO?

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
    print(filetouse)

    try:
        # Check wether the file exist in the cache
        f = open(filetouse[1:], "r")
        outputdata = f.read()   #TODO: why use f.readlines()
        fileExist = "true"

        # ProxyServer finds a cache hit and generates a response message
        headlines="HTTP/1.1 200 OK\r\nConnection:close\r\nContext-Type:text/html\r\nContent-Length:{}\n\n".format(len(outputdata))  
        #TODO: why last delimiter is not \r\n
        print(headlines)
        tcpCliSock.send(headlines.encode())
        
        # send data
        print("Read from cache")
        for i in range(0, len(outputdata)):
            tcpCliSock.send(outputdata[i].encode())

    except IOError:
        if fileExist == 'false':
            # Create a socket on the proxyserver
            c = socket(AF_INET, SOCK_STREAM)
            
            hostname = message.split()[1].partition("/")[2].partition("/")[0]
            print('hostname:',hostname) 
            try:
                # Connect to the socket to port 80
                c.connect((hostname,80))    # example c.connect(('www.google.com',80))

                # Create a temporary file on this socket and ask port 80 for the file requested by client
                fileobj = c.makefile('r', 0)
                fileobj.write("GET"+"http://"+filename+"HTTP/1.0\n\n")
                fileobj.close()
                # Read the response into buffer
                recvMessage = c.recv(1024).decode() #TODO: enough??
                    
                # Create a new file in the cache for the requested file
                # Also send the resopnse in the buffer to client socket and the corresponding file in the cache
                tmpFile = open("./"+filename,"wb")
                for i in range(len(recvMessage)):
                    tmpFile.write(recvMessage[i])
                tmpFile.close()
                
                tmpFile = open("./"+filename,"wb")
                for i in range(len(tmpFile.read())):
                    tcpCliSock.send(tempFile[i].encode())
            except:
                print("Illeagl request")
        else:
            # HTTP response message for file not found
            # TODO:
            pass

    # Close the client and the server sockets
    tcpCliSock.close()
    #TODO: ??



