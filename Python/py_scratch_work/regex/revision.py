# revision.py
# Ronny MacMaster


# 11.2 revision.py
#
# Write a program to look for lines of the form
#
# New Revision: 39772
#
# and extract the number from each of the lines using
# a regular expression and the findall() method.
# Compute the average of the numbers and print out the average.
#
#
# Enter file:mbox.txt
# 38549.7949721

import re

# open the file
try:
    mboxdata = open("mbox.txt")
except:
    print "Cannot find mbox data!"
    exit()

# read through mbox data and search for the numbers from each Revision line
# manage a list
nums = list()
for line in mboxdata:
    num = re.findall("New Revision: ([0-9]+)", line)
    if len(num) > 0:
        nums.append(float(num[0]))

# print the average
print "Average revision number: ", sum(nums)/len(nums)
