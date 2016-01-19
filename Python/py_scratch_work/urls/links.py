# pic.py
# Ronny Macmaster

# Perform an HTTP request to grab the html text from the user url
# Parse the html for all the href attribute values
# Print the list of links the website links to

import urllib
import sys
import re

# open the url

url = raw_input("Enter your url - ")
if not url.startswith("http://"): url = "http://" + url

try:
    html = urllib.urlopen(url).read()
except:
    print "Error: url not found!"
    sys.exit()


# grab the links with a regex
links = re.findall('href="http://(.*?)"', html)


# prompt save
flag = raw_input("Save to file (y/n)? ")
if(flag.startswith("y") or flag.startswith("Y")):
    flag = True
else:
    flag = False


# optional save
try:
    if flag: filename = open(raw_input("Enter savefile name: "), "w+")
except:
    if flag:
        print "Error: url could not open file!"
        sys.exit()


# print the links
for link in links:
    if flag: filename.write(link + "\n")
    print link


# close the file
if flag: filename.close()
