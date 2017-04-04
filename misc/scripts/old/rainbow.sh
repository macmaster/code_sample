#!/bin/sh

# Rainbow.sh 
#
# Prints pretty colors on the screen
# Type reset to undo changes
#
# Author: Ronny MacMaster
# Date: 10/09/15
# 

echo "\033[30m"

c=0;
a=40;
while [ $a ]
do
   while [ $a -lt 48 ]
   do
     echo "\033[${a}m"
     a=`expr $a + 1`
   done

   a=49;

   while [ $a -gt 39 ]
   do 
     echo "\033[${a}m"
     a=`expr $a - 1`
   done

c=`expr $c + 1`
if [ $c -eq 5 ]
then
  c=0;
 sleep 0.05s
fi

done
