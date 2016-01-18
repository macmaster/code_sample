# letter.py
# Ronny MacMaster


# 10.3 letter.py
#
# Read a file and print the letters in decreasing order of frequency.
# Convert all the input to lower case and only count the letters a-z.
# Do not count spaces, digits, punctuation,
# or anything other than the letters a-z!
# Find text samples from several different
# languages and see how letter frequency varies between languages.
# Compare the results with the tables at wikipedia.org/wiki/Letter_frequencies.

import string

# open the file
try:
    filename = raw_input("Enter the file name: ")
    textdata = open(filename)
except:
    print "Cannot find text data!"
    exit() 

# read through text data and add each letter (a-z) to the dictionary
letters = dict()
for line in textdata:
    words = line.rstrip().split()
    for word in words:
        word = word.lower() 
        for char in word:
            if char in string.letters:
                letters[char] = letters.get(char, 0) + 1



# print out letter database
print letters

# sort the letter database by count
letterbase = list()
for letter, count in letters.items():
    letterbase.append((count, letter))
letterbase.sort(reverse = True)

# print the letter query
print "Letter", "Count"
for count, letter in letterbase:
    print "", letter, "\t", count
