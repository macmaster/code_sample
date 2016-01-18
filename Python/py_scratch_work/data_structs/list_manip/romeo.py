# romeo.py
# Ronny MacMaster


# 8.4 romeo.py
#
# Write a program to open the file romeo.txt and read it line by line.
# For each split the line into a list of words using the split function.
# For each word, check to see if the word is already in a list.
# If the word is not in list, add it to the list.
# When the program completes, sort and print the resulting words lexographically
#
# Enter file: romeo.txt
# ['Arise', 'But', 'It', 'Juliet', 'Who', 'already',
# 'and', 'breaks', 'east', 'envious', 'fair', 'grief',
# 'is', 'kill', 'light', 'moon', 'pale', 'sick', 'soft',
# 'sun', 'the', 'through', 'what', 'window',
# 'with', 'yonder']

# open the file
try:
    fname = raw_input("Enter file: ")
    romeotxt = open(fname)
except:
    print "Error: could not open file: " + fname 
    exit()

# split each line into a list of words.
# add new words
wordlist = list()
for line in romeotxt:
    line = line.rstrip() 
    for word in line.split():
        if word not in wordlist:
            wordlist.append(word)

# sort and print the wordlist lexographically
wordlist.sort()
print wordlist

# close the file
romeotxt.close()
    
