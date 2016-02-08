import time
import urllib
import re
import smtplib

# poll goog every 6 secs and make a feed
# email user at certain threshold

#setup email
rcver = raw_input("receiver email: ")
email = raw_input("your gmail: ")
pword = raw_input("your password: ")
notif_period = int(raw_input("emails every (n) minutes. enter n: "))

def email_user(msg):
    #build email content
    header = "From: %s\r\n" % (email)
    header += "To: %s\r\n" % (rcver)
    header += "Subject: Google Stock Price Update\r\n\r\n"
    msg = header + msg
    try:
        mail = smtplib.SMTP('smtp.gmail.com', 587)
        mail.ehlo()
        mail.starttls()
        mail.login(email, pword)
        mail.sendmail(email, rcver, msg)
    except:
        print("Failed to send e-mail!")
    finally:
        mail.close()

# poll goog stock
try:
    txtclock = 0
    while True:
        
        # open log
        pricelog = open("goog.txt", "a")
        
        # get raw data
        htmlfile = urllib.urlopen('http://finance.yahoo.com/q?s=goog&fr=uh3_finance_web&uhb=uhb2')
        htmltext = htmlfile.read()
        
        # parse price
        regex = '<span id="yfs_l84_[^.]*">(.+?)</span>'
        pattern = re.compile(regex)
        price = re.findall(pattern, htmltext)
        price = price[0]
        
        # send email?
        if txtclock <= 0 and 675 > float(price):
            #email
            print("Google is getting cheap!\t" + "price: " + price)
            email_user("Google is getting cheap!\nprice: "+price)
            txtclock = notif_period * 10
        elif txtclock <= 0 and 680 < float(price):
            #email
            print("Google is getting expensive!\t" + "price: " + price)
            email_user("Google is getting expensive!\nprice: "+price)
            txtclock = notif_period * 10
        
        # log & delay
        pricestr = time.asctime() + "\tPrice: " + price + "\n"
        pricelog.write(pricestr)
        time.sleep(6)
        txtclock -= 1
        pricelog.close()
        
finally:
    print("hello world!")
    pricelog.close()
