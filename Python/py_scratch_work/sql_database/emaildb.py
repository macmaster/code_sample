#############################################
# emaildb.py
# Create an email database from mbox.txt
# Read the emeail counts from the db.
# 
# Author: Ronny Macmaster
# Date: 3/15/16
##############################################

import sqlite3

# connection and cursor
conn = sqlite3.connect('email.sqlite')
c = conn.cursor()

# Create email table
c.execute('''
DROP TABLE IF EXISTS Counts''')

c.execute('''
CREATE TABLE Counts (org TEXT, count INTEGER)''')

try:
	# Open mbox file for reading
	mbox = open("mbox.txt")
	
	# build email database
	for line in mbox:

		# read email domain
		if not line.startswith("From: "): continue
		email = line.split()[1]
		org = email.split("@")[1]
		
		# update domain count
		c.execute('''
		SELECT count FROM Counts WHERE org = ?''', (org, ))
		count = c.fetchone()
		if count is None:
			c.execute('''
			INSERT INTO Counts (org, count) VALUES (?, ?)''', (org, 1))
		else:
			c.execute('''
			UPDATE Counts SET count=count+1 WHERE org = ?''', (org, ))
	
	# commit updates
	conn.commit()	

	# print top 10 email domains
	sqlstr = "SELECT * FROM Counts ORDER BY count DESC LIMIT 10"
	for row in c.execute(sqlstr):
		print row[0], row[1]

except IOError:
	print "Could not access mbox.txt file."
finally:
	mbox.close()

c.close()
