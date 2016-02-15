import time
import urllib
import re
import smtplib

# poll goog every 6 secs and make a feed
# email user at certain threshold

#setup email
rcver = raw_input("your email: ")
email = "macmaster.stocks@gmail.com"
pword = "Physics17"
notif_period = int(raw_input("emails every (n) minutes. enter n: "))

# get bollinger band thresholds
try:
    bburl = urllib.urlopen("http://www.bollingeronbollingerbands.com/common/getjson.php?"
                            "xml=price&i=price&l1=0&ct=0&ov=0-20-2-0-0-0-0-0-0-0-0&pc=0&pp=&m=&s=GOOG&w=800&t=0&g=5&q=60")
    bbdata = bburl.read()
    bbdata = bbdata[bbdata.rfind('"date":'):] # extract today's bb data
    regex_low = '"bb_lower1":([0-9.]+)'
    regex_high = '"bb_upper1":([0-9.]+)'
    # parse bb prices
    bb_low = float(re.findall(re.compile(regex_low), bbdata)[0])
    bb_high = float(re.findall(re.compile(regex_high), bbdata)[0])
    print bb_low, bb_high
except:
    print "failled to get bollinger band data!"
    exit()
finally:
    bburl.close()


def email_user(msg):
    #build email content
    header = "From: %s\r\n" % ("Ronny's Stock Update")
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
        
        # get raw data & parse price
        stockurl = urllib.urlopen('http://download.finance.yahoo.com/d/quotes.csv?s=goog&f=l1')
        price = stockurl.read().rstrip()
        
        # send email?
        if txtclock <= 0 and bb_low > float(price):
            #email
            print("Google is getting cheap!\t" + "price: " + price)
            email_user("Google is getting cheap!\n\nprice: " + price)
            txtclock = notif_period * 10
        elif txtclock <= 0 and bb_high < float(price):
            #email
            print("Google is getting expensive!\t" + "price: " + price)
            email_user("Google is getting expensive!\n\nprice: " + price)
            txtclock = notif_period * 10
        
        # log & delay
        pricestr = time.asctime() + "\tPrice: " + price + "\n"
        pricelog.write(pricestr)
        time.sleep(6)
        txtclock -= 1
        pricelog.close()
        
finally:
    print("finished execution!")
    pricelog.close()
