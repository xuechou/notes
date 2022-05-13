# SMTP.smtplib.py
# TODO: not work

import smtplib
import email.utils
from email.mime.text import MIMEText

# Create the message
msg = MIMEText('This is the body of the message.')
msg['To'] = email.utils.formataddr(('Recipient', '***@outlook.com'))
msg['From'] = email.utils.formataddr(('Author', '***@outlook.com'))
msg['Subject'] = 'send by python'

server = smtplib.SMTP('smtp-mail.outlook.com',587)
server.set_debuglevel(True)

try:
    #TODO
    server.sendmail('***@outlook.com', ['***@outlook.com'], msg.as_string())
finally:
    server.quit()
