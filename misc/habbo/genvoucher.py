# genvoucher.py
# generates a random voucher code file
#
# author: ronny macmaster

import random
import sys

# init writer variables
alpha = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
vhand = open("vouchers", "w")
print alpha

# generate n 8 digit/letter random vouchers
n = int(sys.argv[1]) 
for i in range(n):
    voucher = ""
    for j in range(8):
        r = random.randrange(0, len(alpha))
        voucher += alpha[r]
    vhand.write(voucher + "\n")

# close and write file
vhand.close()
