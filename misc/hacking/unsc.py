# unsc.py
#
# unscrambles the input file words
# relies on the use of the wordlist file
# input: input1    has the list of words to unscramble
# Author : ronny macmaster
# date: 4/17/2016

from sets import Set

# open input
answer = ""
soup = open("input1.txt") # word scramble file
for word in soup:
    
    # build scramble set
    word = word.rstrip()
    wchars = Set(word)
    
    # compare to words in wordlist
    with open("wordlist")as wordlist:
        for line in wordlist:
            # build line set
            line = line.rstrip()
            lchars = Set(line)
            wordfound = True

            # compare word sets
            if wchars <= lchars and wchars >= lchars:
                answer += line + ","
                print line
                break
            
# print csv answer
print answer.rstrip(",")
            
                
                    
                
        
