# address.py
# Ronny MacMaster


# 9.5 address.py
#
# Read through the mail log.
# Build a histogram using a dictionary to count how many messages
# have come from each domain name.
# print the dictionary.
# print the domain name with the most messages and print the count


# open the file
try:
    mboxdata = open("mbox.txt")
except:
    print "Cannot find mbox data!"
    exit()

# read through mbox data and search for the domain name in "From" lines
domaingraph = dict()
for line in mboxdata:
    if line.startswith("From"):
        email = line.rstrip().split()[1]
        domain = email.split("@")[1]
        domaingraph[domain] = domaingraph.get(domain, 0) + 1

# print out day dictionary
print domaingraph, "\n"

# find maximum message count
domain = ""
messages = 0
for address, count in domaingraph.items():
    if count > messages:
        domain = address
        messages = count

# print most frequent sender domain
print "%s sent the most messages (%d messages)!" % (domain, messages)
