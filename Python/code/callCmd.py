# coding=utf-8

import os
import subprocess

command = 'dir ' + r'"d:\坚果云"'

logData = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE)
data = logData.communicate()[0].decode('GBK')
print(data)
pass