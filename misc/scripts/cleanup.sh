#!/bin/bash
# cleanup
# run as root

LOG_DIR=/var/log
cd $LOG_DIR
cat /dev/null > messages
cat /dev/null > wtmp
echo "cleaned up log files in $LOG_DIR"
exit
