# address.py
# Ronny MacMaster


# 9.3 address.py
#
# Read through the mail log.
# Build a histogram using a dictionary to count how many messages
# have come from each email address.
# Finally, print the dictionary.


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
print emailgraph
