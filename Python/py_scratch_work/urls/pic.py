# pic.py
# Ronny Macmaster

# Perform an HTTP request to grab the img file from www.py4inf.com
# Python can't view images well,
# so the script writes the pic to a file.
# View laterwith local img viewer

import socket
import time

# open the socket
mysock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
mysock.connect(("www.py4inf.com", 80))
mysock.send("GET http://www.py4inf.com/cover.jpg HTTP/1.0\n\n")

## alternative (mp3)
## mysock.connect(("habboo-a.akamaihd.net", 80))
## mysock.send("GET http://habboo-a.akamaihd.net/dcr/hof_furni/mp3/sound_machine_sample_83.mp3 HTTP/1.0\n\n")

# count = size of pic, picture = pic
count = 0
picture = ""

# recv loop
while True:
    data = mysock.recv(512)
    if len(data) < 1: break
    # time.sleep(0.25) # optional slight delay
    count = count + len(data)
    print len(data), count
    picture = picture + data

# close socket
mysock.close()

# extract header (2 CRLF)
pos = picture.find("\r\n\r\n")
print "header length: ", pos
print picture[:pos]

# write to file
picture = picture[pos+4:]
##  picfile = open("stuff.mp3", "wb") # for mp3
picfile = open("stuff.jpg", "wb")
picfile.write(picture)
picfile.close()
