import urllib

url = raw_input("enter your url: ")
stockdata = urllib.urlopen(url).read()
print stockdata

