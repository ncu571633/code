print "the total of 1..100 is " .  total(1..100) . ".\n";

sub total()
{
	my $sum = 0;
	foreach(@_)
	{
		$sum += $_;
	}
	return $sum;
}
