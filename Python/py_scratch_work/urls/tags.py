# tags.py
# Ronny Macmaster

#Perform an HTTP request to grab data from a user input URL
#Instead of displaying the data, count the number of paragraphs

import urllib
import re

from BeautifulSoup import *

#prompt url
url = raw_input("Enter the full url (http://www.url.com): ")
if not url.startswith("http://"): url = "http://" + url

try:
    html = urllib.urlopen(url).read()
    soup = BeautifulSoup(html)
except:
    print "Error: cannot read URL"
    exit()

tag = raw_input("Enter the tag to count: ")
print "Number of "+ tag +"s: ", len(soup(tag))
