# SMTP.py
# TODO: not work

from socket import *
import base64

# Mail content
subject = "I love computer networks!"
contentType = 'text/plain'
msg = "I love computer networks!"
endmsg = "\r\n.\r\n"

# Choose a mail server (e.g. Google mail server) and call it mailserver
mailserver = "smtp-mail.outlook.com"
mailPort = 587

# Sender and reviever
fromAddress = "321@outlook.com"
toAddress = "123@outlook.com"

# Authenticate infomation (Encode with base64)
userName = base64.b64encode(fromAddress.encode()).decode()
password = base64.b64encode("***".encode()).decode()

# Create socket called clientSocket and establish a TCP connection with mailserver
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((mailserver, mailPort))

recv = clientSocket.recv(1024)
print(recv.decode())
if recv.decode()[:3] != '220':
    print("220 reply not reveived from server.")

# Send HELLO command and print server response.
heloCommand = 'Helo chouchou\r\n'
clientSocket.send(heloCommand.encode())

recv1 = clientSocket.recv(1024)
print(recv1.decode())
if recv1.decode()[:3] != '250':
    print('250 reply not received from server.')

# Authenticate user.
clientSocket.send('AUTH LOGIN\r\n'.encode()) #todo:
recv = clientSocket.recv(1024).decode()
print(recv)
if recv[:3] != '334':
    print('334 reply not received from server')

#TODO:
# Send Mail FROM command and print server response.

# Send RCPT TO command and print server response
# .
# Send DATA TO command and print server response.

# Send message data.

# Message ends with a single period.

# Send QUIT command and get server response.

clientSocket.close()
