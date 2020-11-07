# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    generateur.pl                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdidier <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/23 01:20:34 by rdidier           #+#    #+#              #
#    Updated: 2015/09/23 01:25:19 by rdidier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/perl
use warnings;
use strict;

die "program x y density" unless (scalar(@ARGV) == 3);

my ($x, $y, $density) = @ARGV;

print "$y.ox\n";

for (my $i = 0; $i < $y; $i++) {
	for (my $j = 0; $j < $x; $j++) {
		if (int(rand($y) * 2) < $density) 
		{
			print "o"; }
		else { print "."; }
	}
	print "\n";
}
