from socket import *

serverPort = 12001

serverSocket = socket(AF_INET, SOCK_STREAM)

#prepare a sever socket
serverSocket.bind(('', serverPort))
serverSocket.listen(1)

while True:
    #Establish the connection
    print('Ready to serve...')
    connectionSocket, clientAddr = serverSocket.accept()

    try:
        message = connectionSocket.recv(1024).decode()
        filename = message.split()[1]
        f = open(filename[1:])
        outputdata = f.read()

        #Send one HTTP header line into socket
        headline = ' HTTP/1.1 200 OK\nConnection:close\nContent-Type:text/html\nContent-Length:%d\n\n'.format(len(outputdata))
        connectionSocket.send(headline.encode())

        #Send the content of the requested file to the client
        for i in range(0, len(outputdata)):
            connectionSocket.send(outputdata[i].encode())
        connectionSocket.close()
    except IOError:
        #send resopnse message for file not found
        header = ' HTTP/1.1 404 Not Found\n\n'
        connectionSocket.send(header.encode())
        #close client socket
        connectionSocket.close()

serverSocket.close()