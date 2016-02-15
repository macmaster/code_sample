# xmlcount.py
# Author: Ronny Macmaster

import urllib
import xml.etree.ElementTree as et

# init url
url = "http://python-data.dr-chuck.net/comments_229962.xml"

# open url
try:
	xmldata = urllib.urlopen(url)
	xmldata = xmldata.read()
except:
	print "Could not open URL!"
	exit()

# build element tree
tree = et.fromstring(xmldata)
counts = tree.findall('.//count')

# sum the counts
nums = list()
for count in counts:
	nums.append(int(count.text))
print sum(nums)
