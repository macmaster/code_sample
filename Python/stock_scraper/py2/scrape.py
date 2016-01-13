import urllib
import re

urls=["http://www.twitter.com//", "http://nytimes.com", "http://cnn.com", "http://youtube.com"]

regex = '<title>(.+?)</title>'
pattern = re.compile(regex)

i=0
for link in urls:
    htmlfile = urllib.urlopen(link)
    htmltext = htmlfile.read().decode('utf-8')
    title = re.findall(pattern, htmltext)
    print title
    i+=1
