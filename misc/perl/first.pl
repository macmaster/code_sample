#!/usr/bin/perl

=begin 
Good googly moogly. Can you see this?
=cut

# intro msg
print "Hello Perl!

You are pretty good at text manipulation.
";

# build the two messages

$msg1 = << "EOF";
Good Gracious, I can't believe the sight I am seeing. Are you kidding me Ronny?
Perl is such a good language for shell scripting.
I just can't believe it!.
EOF

$msg2 = << 'EOF';
Gosh Jenkins Ronny, You are really getting the hang of these multi-line comments.
Do you think that I could get your autograph?
EOF


# Do some arithmetic 
$a = 3; $b = 4;
$c = $a + $b;
print "$a + $b is $c\n";

# print the messages
print $msg1, $msg2;
