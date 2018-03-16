#!/usr/bin/perl
# mail.pl
# Test out the email functionality of perl.
# 
# Author: Ronald Macmaster
# Date: 6/11/16

$to = 'RonnyMacmaster@gmail.com';
$from = 'ronny@linux.com';
$subject = 'Perl Email';
$message = << 'EOF';
Hey Ronny, Just testing out perl's email utility.
I hope everthing is going well.
How are the wife and kids?
Anyway, I will catch you later.

Best Wishes,
Ronny
EOF

open(MAIL, "|/usr/sbin/sendmail -t");

print MAIL "To: $to\n";
print MAIL "From: $from\n";
print MAIL "Subject: $subject\n";
print MAIL $message;

close(MAIL);
print "Sent the e-mail to: $to\n";
