from socket import *

from debugpy import connect

serverPort = 12000

serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind(('', serverPort))
serverSocket.listen(1)
print("udp server is ready to receive")

while True:
    connectionSocket, clientAddr = serverSocket.accept()
    sentence = connectionSocket.recv(1024).decode()
    modifiedSentence = sentence.upper()
    connectionSocket.send(modifiedSentence.encode())
    connectionSocket.close()