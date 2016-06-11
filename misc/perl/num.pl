#!/usr/bin/perl
# num.pl
# Practice using Scalars, Arrays, and Hashes
#
# Author: Ronald Macmaster
# Date: 6/10/16

# Scalars
$x = "1"; $y = 1;
print "x = $x y = $y \n";
print 'x + y = ', $x + $y, "\n";
print 'x - y = ', $x - $y, "\n";
print 'x * y = ', $x * $y, "\n";
print 'x / y = ', $x / $y, "\n";

# Arrays

@arr = (0, 1, 2, 3, 4, 5);
print "$arr[0], $arr[1], $arr[2], $arr[3], $arr[4], $arr[5]\n";
print "$arr[-1], $arr[-2], $arr[-3], $arr[-4], $arr[-5], $arr[-6]\n";
print "$arr[6] = $arr[-7]", "\n"; # you can go backwards, but it returns null at the boundary.

