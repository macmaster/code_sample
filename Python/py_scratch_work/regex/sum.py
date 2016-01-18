# sum.py
# Ronny MacMaster


# sum.py
#
# Read the file and look for integers using the re.findall().
# Look for a regular expression of '[0-9]+'.
# Then, convert the extracted strings to integers.
# Sum up the numbers and print the result.
#
# Example data:
# Why should you learn to write programs? 7746
# 12 1929 8827
# Writing programs (or programming) is a very creative 
# 7 and rewarding activity.  You can write programs for 
# many reasons, ranging from making your living to solving
# 8837 a difficult data analysis problem to having fun to helping 128
# someone else solve a problem.  This book assumes that 
# everyone needs to know how to program ...

import re

# open the file
try:
    textdata = open(raw_input("enter the filename: "))
except:
    print "Cannot find text data!"
    exit()

# read through text data and search for the random numbers in every line
# manage a list of the values
nums = list()
for line in textdata:
    for num in re.findall("[0-9]+", line):
        nums.append(int(num))

# print the average
print "Average revision number: ", sum(nums)

# two-line version of the program:
##import re
##print sum([int(n) for n in re.findall('[0-9]+', open(raw_input("enter the filename: ")).read())])
