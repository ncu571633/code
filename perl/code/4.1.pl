use strict;
use warnings;

sub total
{
	my $sum = 0;
	foreach (@_)
	{
		$sum += $_;
	}
	return $sum;
}

print total(1..3) . "\n";
