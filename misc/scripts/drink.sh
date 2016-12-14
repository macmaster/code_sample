#!/bin/sh 


# Ronny's Drink Shop
#
# Author: Ronny MacMaster
# Date: 10/09/15

# Text Color Styles
RED=`       echo  "\033[31m"`
GREEN=`     echo  "\033[32m"`
YELLOW=`    echo  "\033[33m"`
BLUE=`      echo  "\033[34m"`
MAGENTA=`   echo  "\033[35m"`
CYAN=`      echo  "\033[36m"`
GRAY=`      echo  "\033[4m"`
WHITE=`     echo  "\033[97m"`
NORMAL=`    echo    "\033[m"`

# Menu Screen
echo
echo "Welcome to Ronny's Drink Shop."
echo "Please Select a Drink:"
echo " "
echo "${NORMAL}1) ${WHITE}milk"
echo "${NORMAL}2) ${RED}coffee" 
echo "${NORMAL}3) ${GREEN}tea" 
echo "${NORMAL}4) ${YELLOW}cola" 
echo "${NORMAL}5) ${BLUE}water" 
echo "${NORMAL}6) ${MAGENTA}juice"
echo "${NORMAL}7) ${YELLOW}lemonade" 
echo "${NORMAL}8) ${CYAN}beer"
echo "${NORMAL}9) ${GRAY}none" 

echo "${NORMAL}" # Default Font Color

# Selection Output
  read drink
  case $drink in
    milk|coffee|tea)
      echo "Go to Starbucks."
	;;
    cola|water|juice)
      echo "Check the Fridge."
        ;;
    lemonade)
      echo "Check the Cooler."
        ;;
    beer)
      echo -n "Are you 21 or older? (y / n) "
      read option
      if [ $option == 'y' ]
      then 
         echo "Go to the Corner Store."
      elif [ $option == 'n' ]
      then
         echo "Wait until your 21st Birthday."
      else
         echo "Error 404: beer not found."
      fi
        ;;
    none)
        ;;
    *)
      echo "Invalid drink selection."
        ;;
  esac

echo "Thank You; Come Again." 

