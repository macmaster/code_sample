# hour.py
# Ronny MacMaster


# 10.2 hour.py
#
# Count the distribution of the hour of the day for each of the messages.
# Pull the hour from the "From" line by
# finding the time string and then
# splitting that string into parts using the colon character.
# Finally, print out the hour counts, one per line, sorted by hour 

# open the file
try:
    mboxdata = open("mbox.txt")
except:
    print "Cannot find mbox data!"
    exit()

# read through mbox data and search for the e-mail address in "From" lines
timegraph = dict()
for line in mboxdata:
    if line.startswith("From") and not line.startswith("From:"):
        time = line.rstrip().split()[5]
        hour = time.split(":")[0]
        timegraph[hour] = timegraph.get(hour, 0) + 1

# print out time dictionary
# print timegraph, "\n"

# sort the timelist by hour
timelist = list()
for hour, count in timegraph.items():
    timelist.append((hour, count))
timelist.sort()


# print the hour plot
print "Hour", "Messages"
for hour, count in timelist:
    print "", hour, "\t", count
