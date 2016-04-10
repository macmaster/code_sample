@echo off
gcc -o msg hexmsg.c
msg %1 > msg
rm msg.exe
notepad msg
rm msg