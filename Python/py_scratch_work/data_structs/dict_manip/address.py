# address.py
# Ronny MacMaster


# 9.3 address.py
#
# Read through the mail log.
# Build a histogram using a dictionary to count how many messages
# have come from each email address.
# Finally, print the dictionary.
#
# 9.4 ext:
# print the email with the most messages and print the count


# open the file
try:
    mboxdata = open("mbox.txt")
except:
    print "Cannot find mbox data!"
    exit()

# read through mbox data and search for the e-mail address in "From" lines
emailgraph = dict()
for line in mboxdata:
    if line.startswith("From"):
        email = line.rstrip().split()[1]
        emailgraph[email] = emailgraph.get(email, 0) + 1

# print out day dictionary
print emailgraph, "\n"

# find maximum email count
email = ""
messages = 0
for address, count in emailgraph.items():
    if count > messages:
        email = address
        messages = count

# print most frequent sender
print "%s sent the most messages (%d messages)!" % (email, messages)
