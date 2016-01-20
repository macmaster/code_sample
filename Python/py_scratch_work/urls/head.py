# head.py
# Ronny Macmaster

#Perform an HTTP request to grab ONLY header data from a user input URL

import socket
import re

#prompt url
url = raw_input("Enter the full url (http://www.url.com): ")
if url.startswith("http://"): url = url[7:] #remove http
if not url.startswith("www."): url = "www." + url #add www

try:
    mysock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    mysock.connect((url, 80))
    mysock.send("GET http://"+url+" HTTP/1.0\n\n")
except:
    print "Error: cannot read URL"
    exit()

flag = True
while True:
    data = mysock.recv(512)
    if len(data) < 1: break
    if flag: print data
    if re.search("\r\n\r\n", data): flag = False
    
mysock.close()
