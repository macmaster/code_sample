#!/bin/bash
echo "this is my first linux script"
var1="cool beans bro!"
cat << EOF
Hi there guys, 
My name is ronald.
Today, I want to talk to you about shell scripting.
Please, learn to shell script.
You won't regret it.
EOF

var2=0
for idx in `seq 0 99`
do
	echo (eval $var2 + seq)
done
echo $var1


