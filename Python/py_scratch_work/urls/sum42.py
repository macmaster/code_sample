# tags.py
# Ronny Macmaster

#Perform an HTTP request to grab data from asum URL
#Parses the data with the beautifulsoup library
#add up all the numbers in the span tags.

import urllib
import re

from BeautifulSoup import *

#init url
url = "http://python-data.dr-chuck.net/comments_229965.html"

try:
    html = urllib.urlopen(url).read()
    soup = BeautifulSoup(html)
except:
    print "Error: cannot read URL"
    exit()

# count the tags
tags = soup("span")
nums = list()
for tag in tags:
    nums.append(int(tag.contents[0]))

# print sum
print sum(nums)
