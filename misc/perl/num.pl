#!/usr/bin/perl
# num.pl
# Practice using Scalars, Arrays, and Hashes
#
# Author: Ronald Macmaster
# Date: 6/10/16

# Scalars
$x = "1"; $y = 1;
print "\n", "Scalars:\n";
print "x = $x y = $y \n";
print 'x + y = ', $x + $y, "\n";
print 'x - y = ', $x - $y, "\n";
print 'x * y = ', $x * $y, "\n";
print 'x / y = ', $x / $y, "\n";

# Arrays
# you can go backwards, but it returns null past the boundary.

@arr = (0, 1, 2, 3, 4, 5);
print "\n\n", "Arrays:\n";
print "$arr[0], $arr[1], $arr[2], $arr[3], $arr[4], $arr[5]\n";
print "$arr[-1], $arr[-2], $arr[-3], $arr[-4], $arr[-5], $arr[-6]\n";
print "$arr[6] = $arr[-7]", "\n"; 

# Hashes

%hash = ("key1", "value", "key2", "value", "key3", 100);
print "\n\n", "Hashes:\n";
print "key1 value: \"$hash{'key1'}\"\n";
print "key2 value: \"$hash{'key2'}\"\n";
print "key3 value: $hash{'key3'}\n";
print "value access as key: $hash{'value'}\n";
