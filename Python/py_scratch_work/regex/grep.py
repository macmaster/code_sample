# grep.py
# Ronny MacMaster


# 11.1 grep.py
#
# Write a simple program to simulate the operation of the grep command
# on Unix. Ask the user to enter a regular expression and count the number of
# lines that matched the regular expression:
#
# Enter a regular expression: ^X
# mbox.txt had 14368 lines that matched ^X-

import re

# open the file
try:
    mboxdata = open("mbox.txt")
except:
    print "Cannot find mbox data!"
    exit()

# prompt the user for a regex
regex = raw_input("Enter a regular expression: ")

# read through mbox data and search for the regex lines
# manage a counter
count = 0
for line in mboxdata:
    if re.search(regex, line):
        count += 1

# print the regex line count
print "mbox.txt had %d lines that matched %s" % (count, regex)
