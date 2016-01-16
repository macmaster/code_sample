# mail.py
# Ronny MacMaster


# 9.2 mail.py
#
# Categorize each mail message by its day of the week.
# Look for lines that start with "From:";
# the day is the third word of the line.
# Keep a running count of each of the days of the week.
# Finally, print out the contents of the dictionary 


# open the file
try:
    mboxdata = open("mbox.txt")
except:
    print "Cannot find mbox data!"
    exit()

# read through mbox data and search for the day in "From:" lines
daylist = dict()
for line in mboxdata:
    if line.startswith("From") and not line.startswith("From:"):
        day = line.rstrip().split()[2]
        daylist[day] = daylist.get(day, 0) + 1

# print out day dictionary
print daylist


    

    
