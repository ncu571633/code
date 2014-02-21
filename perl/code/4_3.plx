my @fred = above_average(1..10);
print "\@fred is @fred\n";
print "(Should be 6 7 8 9 10)\n";
my @barney = above_average(100, 1 .. 10);
print "\@barney is @barney\n";
print "(Should be just 100)\n";

sub above_average
{
	my $sum = 0;
	foreach(@_)
	{
		$sum += $_;
	}
	my $average = $sum/($#_+1);
	my @fred;
	foreach(@_)
	{
		if($average<$_)
		{
			push(@fred, $_);
		}
	}
	return @fred;
}

