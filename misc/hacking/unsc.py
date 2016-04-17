# unsc.py
#
# unscrambles the input file words
# relies on the use of the wordlist file
# input: input1    has the list of words to unscramble
# Author : ronny macmaster
# date: 4/17/2016

import re

answer = ""
soup = open("input1.txt") # word scramble file
for word in soup:
    word = word.rstrip()

    # compare to words in wordlist
    with open("wordlist")as wordlist:
        for line in wordlist:
            wordfound = True
            for char in word:
                if line.find(char) == -1:
                    wordfound = False
                    break
            if wordfound:
                answer += line.rstrip() + ","
                break
print answer
            
                
                    
                
        
