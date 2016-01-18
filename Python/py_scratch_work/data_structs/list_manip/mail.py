# mail.py
# Ronny MacMaster


# 8.5 mail.py
#
# Read through the mail box data.
# when you find line that starts with "From",
# split the line into words using the split function.
# We are interested in who sent the message, (the second word on the From line).
#
# parse the From line and print out the second word for each From line.
# Count the number of From (not From:) lines
# print out a count at the end.

# open the file
try:
    mboxdata = open("mbox.txt")
except:
    print "Cannot find mbox data!"
    exit()

# read through mbox data and search for "From" line
count = 0
for line in mboxdata:
    if line.startswith("From"):
        print line.rstrip().split()[1]
        count += 1

# print out a line count
print "There were %d lines in the file with From as the first word" % (count)


    

    
