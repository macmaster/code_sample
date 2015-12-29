import urllib.request
import re

symbolsfile = open("symbols.txt")
symbolslist = symbolsfile.read()
symbolslist = symbolslist.split("\n")

#stocklist = ["aapl", "msft", "fb", "goog", "spy", "nflx"]

for i in symbolslist:
    htmlfile = urllib.request.urlopen('http://finance.yahoo.com/q?s='+i+'&fr=uh3_finance_web&uhb=uhb2')
    htmltext = htmlfile.read().decode('UTF-8')
    regex = '<span id="yfs_l84_[^.]*">(.+?)</span>'
    pattern = re.compile(regex)
    price = re.findall(pattern, htmltext)
    print("The price of ",i," is",price[0])
