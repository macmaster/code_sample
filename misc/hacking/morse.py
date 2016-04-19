# morse.py
# 
# decode the white pixel message
# offsets between white pixels represent
# ascii chars to the message
#
# Author: Ronny Macmaster
# Date: 4/17/2016

import urllib2

img = open("img.bmp", "rb")
pic = []

while True:
    byte = img.read(3)
    if len(byte) > 0:
        pic.append(byte)
    else:
        break

for byte in pic:
    bytestr = ""
    bytestr += '{0:08b}'.format(ord(byte[0]))
    bytestr += '{0:08b}'.format(ord(byte[1]))
    bytestr += '{0:08b}'.format(ord(byte[2]))
    print bytestr
    
