# name_crawl.py
# Ronny Macmaster

# Prompt the link position and number of iterations
# Crawl the website for the last name in the sequence

import urllib
import re

from BeautifulSoup import *

#init url
url = raw_input("Enter URL: ")
count = int(raw_input("Enter count: "))
pos = int(raw_input("Enter position: "))

while count > 0:
    try:
        html = urllib.urlopen(url).read()
        soup = BeautifulSoup(html)
    except:
        print "Error: cannot read URL"
        exit()

    # get next link
    tags = soup("a")
    tag = tags[pos-1]
    name = tag.contents[0]
    print "Name: ", name, "\t", url
    url = tag.get("href", None)

    #decrement counter
    count -= 1

# print name
print name
